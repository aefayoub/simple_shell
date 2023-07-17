#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFFER_SIZE 1024

char *_strConcatenate(char *dest, const char *src);
char *_strCopy(char *dest, char *src);
int _strCompares(char *s1, char *s2);
char *_strCharacterLocator(char *s, char c);
int _strLength(char *s, char *accept);



#endif /* MAIN_H */
