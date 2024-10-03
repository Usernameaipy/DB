#include "begin.h"

void create(void) {
  char name_db[100] = {0};
  int exit;
  sqlite3 *db;
  printf("Введите имя новой базы данных: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Ошибка при создании базы данных: %s\n",
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
    fprintf(stderr, "База данных успешно открыта!\n");
    flag = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (flag != SQLITE_OK) {
      fprintf(stderr, "Ошибка при создании таблицы: %s\n", errMsg);
    } else {
      printf("Таблица успешно создана!\n");
    }
    sqlite3_close(db);
  }
}

void insert(char *name_db, sqlite3 *db) {
  sqlite3_stmt *stmt;
  int rc;
  char sql[256] = {0};
  int column_1;
  char column_2[100];
  int column_3;
  printf("Введите значение для ID (INTEGER): ");
  scanf("%d", &column_1);
  printf("Введите значение для Name (TEXT): ");
  scanf("%100s", column_2);
  printf("Введите значение для Age (INTEGER): ");
  scanf("%d", &column_3);
  snprintf(sql, sizeof(sql), "INSERT INTO %s (ID, Name, Age) VALUES (?, ?, ?);",
           name_db);
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Ошибка при подготовке SQL запроса: %s\n",
            sqlite3_errmsg(db));
    return;
  }
  sqlite3_bind_int(stmt, 1, column_1);
  sqlite3_bind_text(stmt, 2, column_2, -1, SQLITE_STATIC);
  sqlite3_bind_int(stmt, 3, column_3);
  rc = sqlite3_step(stmt);
  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Ошибка при выполнении SQL запроса: %s\n",
            sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "Данные успешно добавленный в таблицу %s\n", name_db);
  }
  sqlite3_finalize(stmt);
}

void output(char* name_db, sqlite3* db){
  char *errMsg = 0;
  char sql[256] = {0};
  int rc;
  snprintf(sql, sizeof(sql), "SELECT * FROM %s;", name_db);
  rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
  if(rc!=SQLITE_OK) {
    fprintf(stderr, "Ошибка при выполнении запроса к базе данных: %s\n", errMsg);
    sqlite3_free(errMsg);
  }
  printf("Данные успешно выведены.\n");
}