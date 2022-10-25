#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getFileName(char *fullPath, char *fileName, int lenFileName)
{
    char *pointerchar = strrchr(fullPath, '/');
    if (*pointerchar != '\0' && pointerchar != NULL)
    {
        pointerchar++;
        strncpy(fileName, pointerchar, lenFileName);
        pointerchar = '\0';
    };
}

void getPath(char *fullPath, char *path, int lenPath)
{
    char *pointerchar = strrchr(fullPath, '/');
    if (*pointerchar != '\0' && pointerchar != NULL)
    {
        strncpy(path, fullPath, lenPath);
        pointerchar = '\0';
    };
}

void normalizePath(char *path, char *normPath, int lenNormPath)
{
    char *pointerchar = strrchr(path, '/');
    if (*pointerchar != '\0' && pointerchar != NULL)
    {
        pointerchar = '\0';
    };
    strncpy(normPath, path, lenNormPath);
}

void splitPath(char *fullPath, char *path, int lenPath, char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq)
{
    char *pointerchar = strrchr(fullPath, '.');
    extArq = strncpy(extArq, pointerchar, lenExtArq);
    if (extArq == NULL)
    {
        extArq = "";
    }
    getPath(fullPath, path, lenPath);
    getFileName(fullPath, nomeArq, lenNomeArq);
}

void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath)
{
    char aux[200];
    char barra[] = "/";
    normalizePath(path, aux, lenFullPath);
    strncpy(fullPath, aux, lenFullPath);
    if (fullPath[0] != '\0')
    {
        strcat(fullPath, barra);
    }
    strncat(fullPath, fileName, lenFullPath);
}

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenFullPath)
{
    char *pointerchar = strrchr(fileName, '.');
    if (pointerchar == NULL)
    {
        joinFilePath(path, fileName, fullPath, lenFullPath);
        strcat(fullPath, ext);
    }
    else
    {
        *pointerchar = '\0';
        joinFilePath(path, fileName, fullPath, lenFullPath);
        strcat(fullPath, ext);
    }
}