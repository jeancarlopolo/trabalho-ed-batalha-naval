#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getFileName(char *fullPath, char *fileName, int lenFileName)
{
    char *ponteirochar = strrchr(fullPath, '/');
    if (*ponteirochar != '\0' && ponteirochar != NULL)
    {
        ponteirochar++;
        strncpy(fileName, ponteirochar, lenFileName);
        ponteirochar = '\0';
    };
}

void getPath(char *fullPath, char *path, int lenPath)
{
    char *ponteirochar = strrchr(fullPath, '/');
    if (*ponteirochar != '\0' && ponteirochar != NULL)
    {
        strncpy(path, fullPath, lenPath);
        ponteirochar = '\0';
    };
}

void normalizePath(char *path, char *normPath, int lenNormPath)
{
    char *ponteirochar = strrchr(path, '/');
    if (*ponteirochar != '\0' && ponteirochar != NULL)
    {
        ponteirochar = '\0';
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
    joinFilePath(path, fileName, fullPath, lenFullPath);
    strcat(fullPath, ext);
}