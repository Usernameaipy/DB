#ifndef STDIO_STRING_SQLITE_H
#define STDIO_STRING_SQLITE_H
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#endif
#ifndef BEGIN_H
#define BEGIN_H
void create(void);
void create_table(void);
void insert(char *, sqlite3 *);
#endif