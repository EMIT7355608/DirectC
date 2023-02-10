#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameObject.h"
#include "GameManager.h"
#include "ObjectList/Generator.h"

void testFile() {
    FILE* fp;
    fp = fopen("Chapter0.cpt", "w+"); 

    fprintf(fp, "default 0 500 500\n");
    fclose(fp);
}


void LoadChapter(int index) {
    testFile();
    char path[20]={0};
    sprintf(path, "Chapter%d.cpt",index);
    FILE* file=fopen(path,"r");
    char buf[50], c;
    char pin[20]={0};
    if (file == NULL)
    {
        printf("Flie missing!");
        return;
    }
    int i, j, r_n = 0;
    while (!feof(file))
    {
        c = fgetc(file);
        if (c == '\n')
            r_n++;
    }
    rewind(file);
    for (i = 0; i < r_n; i++)
    {
        fgets(buf, 50, file);
        j = sscanf(buf, "%s", pin);
        if (strcmp(pin, "default") == 0) {
            int index = 0; int x=0; int y=0;
            j = sscanf(buf, "%s %d %d %d", pin, &index, &x, &y);
            Generate(Default, index, x, y);
        }
    }
}