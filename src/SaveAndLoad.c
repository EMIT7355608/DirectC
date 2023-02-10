#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PlayerManager.h"

void Save() {
    FILE* fp;
    fp = fopen("abc.sav", "w+");

    fprintf(fp, "%s %d", "HP",5);
    fclose(fp);

}

void Load() {
    FILE* file;
    int i, j, r_n = 0;
    char buf[50], c;
    char pin[10];
    file = fopen("abc.sav", "r");
    if (file == NULL)
    {
        return;
    }
    while (!feof(file))
    {
        c = fgetc(file);
        if (c == '\n')
            r_n++;
    }
    rewind(file);
    for (i = 0; i <= r_n; i++)
    {
        fgets(buf, 50, file);    
        sscanf(buf, "%s", pin);
        if (strcmp(pin, "HP") == 0) {
            float sc=0;
            sscanf(buf,"%s %f", pin, &sc);
            playerManager.HP = sc;
        }
    }
    fclose(file);

}
