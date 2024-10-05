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
    case 2:
      create_table();
      break;
    case 3:
      case_three();
      break;
    case 4:
      case_four();
      break;
    case 5:
      case_five();
      break;
    case 6:
      case_six();
      break;
    case 7:
      case_seven();
      break;
    case 8:
      case_eight();
      break;
    }
  }
}

void menu(void) {
  printf("Для создания базы данных нажмите 1.\n");
  printf("Для создания таблицы нажмите 2.\n");
  printf("Для добавления в таблицу нажмите 3.\n");
  printf("Для вывода таблицы нажмите 4.\n");
  printf("Для удаления из таблицы нажмите 5.\n");
  printf("Для удаления таблицы нажмите 6.\n");
  printf("Для удаления базы данных нажмите 7.\n");
  printf("Для вывода таблиц хранимых в базе данных нажмите 8.\n");
  printf("Для выхожа нажмите 0.\n");
}