#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void splitPath(char *fullPath, char *path, int lenPath, char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq)
{
    getPath(fullPath, path, lenPath);
    getFileName(fullPath, nomeArq, lenNomeArq);
    int i = 0;
    int j = 0;
    int k = 0;
    while (nomeArq[i] != '\0')
    {
        if (nomeArq[i] == '.')
        {
            j = i;
        }
        i++;
    };
    while (nomeArq[j] != '\0')
    {
        extArq[k] = nomeArq[j];
        j++;
        k++;
    };
    extArq[k] = '\0';
    lenExtArq = k;
};

void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath)
{
    char *aux = (char *)malloc(sizeof(char) * strlen(path));
    normalizePath(path, aux, strlen(aux));
    strcpy(fullPath, aux);
    if (fullPath[0] != '\0')
    {
        strcat(fullPath, '/');
    }
    strcat(fullPath, fileName);
    lenFullPath = strlen(fullPath);
    free(aux);
};

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenFullPath)
{
    joinFilePath(path, fileName, fullPath, lenFullPath);
    strcat(fullPath, ext);
    lenFullPath = strlen(fullPath);
};

void getFileName(char *fullPath, char *fileName, int lenFileName)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (fullPath[i] != '\0')
    {
        if (fullPath[i] == '/')
        {
            j = i + 1;
        }
        i++;
    };
    while (fullPath[j] != '\0')
    {
        fileName[k] = fullPath[j];
        j++;
        k++;
    };
    fileName[k] = '\0';
    lenFileName = k;
};

void getPath(char *fullPath, char *path, int lenPath)
{
    int i = 0;
    int j = 0;
    while (fullPath[i] != '\0')
    {
        if (fullPath[i] == '/')
        {
            j = i;
        }
        i++;
    };
    strncpy(path, fullPath, j);
    path[j] = '\0';
    lenPath = j;
};

void normalizePath(char *path, char *normPath, int lenNormPath)
{
    if (path[strlen(path) - 1] == '/')
    {
        lenNormPath = strlen(path) - 1;
    };
    strncpy(normPath, path, lenNormPath);
};
