#include "start.h"

void start(void) {
  int choise = 3;
  while (choise != 0) {
    menu();
    scanf("%d", &choise);
    switch (choise) {
    case 1:
      create();
      break;
    }
  }
}

void menu(void) {
  printf("Для создания базы таблицы нажмите 1.\n");
  printf("Для добавления в таблицу нажмите 2.\n");
  printf("Для вывода таблицы нажмите 3.\n");
  printf("Для удаления из таблицы нажмите 4.\n");
  printf("Для удаления таблицы нажмите 5.\n");
  printf("Для выхожа нажмите 6.\n");
}