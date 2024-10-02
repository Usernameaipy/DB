#include "begin.h"

void create(void) {
  char name_db[100] = {0};
  int exit;
  sqlite3 *db;
  printf("Введите имя новой таблицы: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Ошиббка при создании таблицы: %s\n", sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "Таблица успешно создана\n");
  }
  sqlite3_close(db);
}