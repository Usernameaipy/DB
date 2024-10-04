#include "start.h"

void start(void) {
  char name_db[100] = {0};
  char table_name[100] = {0};
  int exit;
  int id;
  sqlite3 *db;
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
      printf("Введите имя базы данных в которой храниться таблица: ");
      scanf("%99s", name_db);
      exit = sqlite3_open(name_db, &db);
      if (exit) {
        fprintf(stderr, "Ошибка при открытии базы данных: %s\n",
                sqlite3_errmsg(db));
      } else {
        fprintf(stderr, "База данных успешно открыта!\n");
        printf("Введите имя таблицы для заполнения: ");
        scanf("%100s", table_name);
        insert(table_name, db);
      }
      sqlite3_close(db);
      break;
    case 4:
      printf("Введите имя базы данных, в которой храниться таблица: ");
      scanf("%99s", name_db);
      exit = sqlite3_open(name_db, &db);
      if (exit) {
        fprintf(stderr, "Ошибка при открытии базы данных: %s\n",
                sqlite3_errmsg(db));
      } else {
        fprintf(stderr, "База данных успешно открыта!\n");
        printf("Введите имя таблицы, которую вы хотите вывести: ");
        scanf("%100s", table_name);
        output(table_name, db);
      }
      sqlite3_close(db);
      break;
    case 5:
      printf("Введите имя базы данных, в которой храниться таблица: ");
      scanf("%99s", name_db);
      exit = sqlite3_open(name_db, &db);
      if (exit) {
        fprintf(stderr, "Ошибка при открытии базы данных: %s\n",
                sqlite3_errmsg(db));
      } else {
        fprintf(stderr, "База данных успешно открыта!\n");
        printf("Введите имя таблицы из которой вы хотите удалить элемент: ");
        scanf("%100s", table_name);
        printf("Введите ID, которая подлежит удалению: ");
        scanf("%d", &id);
        delete_elem(table_name, db, id);
      }
      sqlite3_close(db);
      break;
    case 6:
      printf("Введите имя базы данных, в которой храниться таблица: ");
      scanf("%99s", name_db);
      exit = sqlite3_open(name_db, &db);
      if (exit) {
        fprintf(stderr, "Ошибка при открытии базы данных: %s\n",
                sqlite3_errmsg(db));
      } else {
        fprintf(stderr, "База данных успешно открыта!\n");
        printf("Введите имя таблицы, которую желаете удалить: ");
        scanf("%100s", table_name);
        delete_table(table_name, db);
      }
      sqlite3_close(db);
      break;
    case 7:
      printf("Введите имя базы данных, которую желаете удалить: ");
      scanf("%99s", name_db);
      delete_db(name_db);
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
  printf("Для вывода баз данных нажмите 8.\n");
  printf("Для вывода таблиц хранимых в базе данных нажмите 9.\n");
  printf("Для выхожа нажмите 0.\n");
}