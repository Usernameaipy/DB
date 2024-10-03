#ifndef STDIO_STRING_SQLITE_H
#define STDIO_STRING_SQLITE_H
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#endif
#ifndef BEGIN_H
#define BEGIN_H
#include "../func_for_sql/callback.h"
void create(void);
void create_table(void);
void insert(char*, sqlite3 *);
void output(char*, sqlite3 *);
#endif