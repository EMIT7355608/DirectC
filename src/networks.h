//
// Created by yiyan on 23/2/2023.
//

#ifndef MAIN_C_NETWORKS_H
#define MAIN_C_NETWORKS_H
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#pragma packed
/*
 * 这里只有客户端的代码
 * 服务端由于功能不同
 * 由您自己编写类型：多线程、双向通信、状态同步。。。。。。
 */
/*
 * 采用TCP/IP协议，IPv4，64位windows环境
 * */
SOCKET init_networks();
/*
 * 向函数中传入一个结构体指针和大小，便可以发送
 * */
void sending(void* ptr//struct to record sending packages
        ,size_t sizes//size of the package
        ,SOCKET socket//server socket
        ,void (*func)(char* stream)//Losing-connection UI;stream: output of the stderr
);
/*
 * 向函数中传入一个结构体指针和其大小，便可以接受
 * */
void receiving(void* ptr//struct to record receiving packages
        ,size_t sizes//size of the package
        ,SOCKET socket//server-socket
        ,void (*func)(char* stream)//Losing-connection UI;stream: output of the stderr
);

char online_game_id='0';
/*zero means single game mode!
 * */
bool isonline=false;
#endif //MAIN_C_NETWORKS_H
