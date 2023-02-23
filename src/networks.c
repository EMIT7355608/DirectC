//
// Created by yiyan on 23/2/2023.
//
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#pragma packed
SOCKET init_networks(char* ip){
    WSADATA wsadata;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);

    if (iResult != 0) {
        fprintf(stderr,"WSAStartup failed: %d\n", iResult);
        exit(1);
    }

    struct addrinfo *result, *ptr, hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

//127.0.0.1是特殊地址，指向当前主机，也可写作localhost，端口与服务器端口相对应
    iResult = getaddrinfo(ip, "8080", &hints, &result);
    if (iResult != 0) {
        fprintf(stderr,"getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        exit(1);
    }
    SOCKET server_socket = INVALID_SOCKET;
    ptr = result;
    server_socket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

    if (server_socket == INVALID_SOCKET) {
        fprintf(stderr,"socket() failed: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }
/*
    MethodName: connect
    @mannual: https://learn.microsoft.com/zh-cn/windows/win32/api/winsock2/nf-winsock2-connect
    connect函数建立与指定套接字的连接
*/
    if (connect(server_socket, ptr->ai_addr, (int)ptr->ai_addrlen) ==
        SOCKET_ERROR) {
        printf("connect() failed.\n");
        system("pause");
        freeaddrinfo(result);
        closesocket(server_socket);
        WSACleanup();
        exit(1);
    }

    freeaddrinfo(result);
    return server_socket;
}
void sending(void* ptr//struct to record sending packages
             ,size_t sizes//size of the package
             ,SOCKET socket//server socket
             ,void (*func)(char* stream)//Losing-connection UI;stream: output of the stderr
             ){
    char* buf= malloc(sizes);
    memcpy(buf,ptr,sizes);
    int iresult= send(socket,buf,sizes,0);
            if(iresult==0){
                closesocket(socket);
                WSACleanup();
                (*func)("SIGNAL LOST");
            }
            if(iresult<0){
                closesocket(socket);
                WSACleanup();
                char* p;
                sprintf(p,"ERROR!\nEXIT CODE:%d",WSAGetLastError());
                (*func)(p);
            }
}
void receiving(void* ptr//struct to record receiving packages
        ,size_t sizes//size of the package
        ,SOCKET socket//server-socket
        ,void (*func)(char* stream)//Losing-connection UI;stream: output of the stderr
){
    char* buf= malloc(sizes);
    int iresult= recv(socket,buf,sizes,0);
    if(iresult>0){
        memcpy(ptr,buf,sizes);
    }
    if(iresult==0){
        closesocket(socket);
        WSACleanup();
        (*func)("SIGNAL LOST");
    }
    if(iresult<0){
        closesocket(socket);
        WSACleanup();
        char* p;
        sprintf(p,"ERROR!\nEXIT CODE:%d",WSAGetLastError());
        (*func)(p);
    }
}

