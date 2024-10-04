#ifndef STDIO_STRING_SQLITE_LIB_H
#define STDIO_STRING_SQLITE_LIB_H
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif
#ifndef BEGIN_H
#define BEGIN_H
#include "../func_for_sql/callback.h"
void create(void);
void create_table(void);
void insert(char *, sqlite3 *);
void output(char *, sqlite3 *);
void delete_elem(char *, sqlite3 *, int);
void delete_table(char *, sqlite3 *);
void delete_db(char *);
#endif