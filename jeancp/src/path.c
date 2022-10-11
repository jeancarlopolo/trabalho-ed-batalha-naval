#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getFileName(char *fullPath, char *fileName, int lenFileName)
{
    char *ponteirochar = strrchr(fullPath, '/');
    if(*ponteirochar != '\0' && ponteirochar != NULL)
    {
        ponteirochar++;
        strncpy(fileName, ponteirochar, lenFileName);
        ponteirochar = '\0';
    };
}

void getPath(char *fullPath, char *path, int lenPath)
{
    char *ponteirochar = strrchr(fullPath, '/');
    if(*ponteirochar != '\0' && ponteirochar != NULL)
    {
        strncpy(path, fullPath, lenPath);
        ponteirochar = '\0';
    };
}


void normalizePath(char *path, char *normPath, int lenNormPath)
{
    if (path[strlen(path) - 1] == '/')
    {
        lenNormPath = strlen(path) - 1;
    };
    strncpy(normPath, path, lenNormPath);
}

void splitPath(char *fullPath, char *path, int lenPath, char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq)
{
    char *ponteirochar = strrchr(fullPath, '.');
    extArq = strncpy(extArq, ponteirochar, lenExtArq);
    if (extArq == NULL)
    {
        extArq = "";
    }
    getPath(fullPath, path, lenPath);
    getFileName(fullPath, nomeArq, lenNomeArq);
}

void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath)
{
    char *aux = (char *)malloc(sizeof(char) * (strlen(path) + strlen(fileName) + 1));
    char *barra = (char *)malloc(sizeof(char) * 2);
    barra[0] = '/';
    normalizePath(path, aux, strlen(aux));
    strncpy(fullPath, aux, lenFullPath);
    if (fullPath[0] != '\0')
    {
        strcat(fullPath, barra);
    }
    strncat(fullPath, fileName, lenFullPath - strlen(fullPath));
    free(aux);
    free(barra);
}

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenFullPath)
{
    joinFilePath(path, fileName, fullPath, lenFullPath);
    strcat(fullPath, ext);
}