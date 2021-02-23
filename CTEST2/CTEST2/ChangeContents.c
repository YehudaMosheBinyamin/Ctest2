#include <stdio.h>
void ChangeContents(char fileName[])
{
        FILE* fp;
        fopen_s(&fp, fileName, "w");
        if (fp == NULL)//file couldn't open 
        {
            printf("This file doesn't exist or is inaccessible: %s\n",fileName);
            return;
        }
        char name[2000]="Hello,";
        fgets(name, 2000, fp);
        char  helloMessage[2000] = "Hello,";
        strcat(helloMessage, name);
        strcat(helloMessage,"!");
        int successOrFailure = fputs(helloMessage, fp);
        if (successOrFailure < 0)//fputs returns negative value if failed
        {
            printf("There has been an error writing to file : %s", fileName);
            return;
        }
        fclose(fp);
}
