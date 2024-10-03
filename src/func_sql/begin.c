#include "begin.h"

void create(void) {
  char name_db[100] = {0};
  int exit;
  sqlite3 *db;
  printf("Введите имя новой базы данных: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Ошиббка при создании базы данных: %s\n",
            sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "База данных успешно создана\n");
  }
  sqlite3_close(db);
}

void create_table(void) {
  const char *sql = "CREATE TABLE IF NOT EXISTS Users ("
                    "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "Name TEXT NOT NULL,"
                    "Age INTEGER NOT NULL);";
  char name_db[100] = {0};
  char *errMsg = 0;
  int exit;
  sqlite3 *db;
  int flag;
  printf("Введите имя базы данных: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Ошибка при открытии базы данных: %s\n",
            sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "База данныз успешно открыта!\n");
  }
  flag = sqlite3_exec(db, sql, 0, 0, &errMsg);
  if (flag != SQLITE_OK) {
    fprintf(stderr, "Ошибка при создании таблицы: %s\n", errMsg);
  } else {
    printf("Таблица успешно создана!\n");
  }
  sqlite3_close(db);
}