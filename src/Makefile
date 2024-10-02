CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
BUILDDIR = ../build/

all : DataBase

DataBase : main.o start.o begin.o
	$(CC) $(CFLAGS) main.o start.o begin.o -o $(BUILDDIR)DataBase -lsqlite3

main.o : starts/main.c starts/main.h
	$(CC) $(CFLAGS) -c starts/main.c -o main.o

start.o : starts/start.c starts/start.h
	$(CC) $(CFLAGS) -c starts/start.c -o start.o

begin.o : func_sql/begin.c func_sql/begin.h
	$(CC) $(CFLAGS) -c func_sql/begin.c -o begin.o

clean : 
	rm -rf *.o
	rm -rf $(BUILDDIR)*

rebuild : clean all