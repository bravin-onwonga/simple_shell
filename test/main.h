#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int getkeylen(char *s);
char *_getenv(char *var);

#endif /* MAIN_H */