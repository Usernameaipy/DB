#include "start.h"

void start(void) {
  int choise;
  char name_db[100] = {0};
  int exit;
  sqlite3 *db;
  while (choise != 0) {
    menu();
    scanf("%d", &choise);
    switch (choise) {
    case 1:
      printf("Введите имя новой таблицы: ");
      scanf("%99s", name_db);
      exit = sqlite3_open(name_db, &db);
      if (exit) {
        fprintf(stderr, "Ошиббка при создании таблицы: %s\n",
                sqlite3_errmsg(db));
        continue;
      } else {
        fprintf(stderr, "Таблица успешно создана\n");
      }
      sqlite3_close(db);
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