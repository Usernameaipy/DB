#include "case.h"

void case_three(void) {
  char name_db[100] = {0};
  char table_name[100] = {0};
  int exit;
  sqlite3 *db;
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
}

void case_four(void) {
  char name_db[100] = {0};
  char table_name[100] = {0};
  int exit;
  sqlite3 *db;
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
}

void case_five(void) {
  char name_db[100] = {0};
  char table_name[100] = {0};
  int exit;
  int id;
  sqlite3 *db;
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
}

void case_six(void) {
  char name_db[100] = {0};
  char table_name[100] = {0};
  int exit;
  sqlite3 *db;
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
}

void case_seven(void) {
  char name_db[100] = {0};
  printf("Введите имя базы данных, которую желаете удалить: ");
  scanf("%99s", name_db);
  delete_db(name_db);
}

void case_eight(void) {
  char name_db[100] = {0};
  int exit;
  sqlite3 *db;
  printf("Введите имя базы данных содержимое, которой хотите вывести: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Ошибка при открытии базы данных: %s\n",
            sqlite3_errmsg(db));
  } else {
    printf("База данных успешно открыта!\n");
    table_ls(db);
  }
  sqlite3_close(db);
}