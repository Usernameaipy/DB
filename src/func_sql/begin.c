#include "begin.h"

void create(void) {
  char name_db[100] = {0};
  int exit;
  sqlite3 *db;
  printf("Enter the name of the new database: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Error creating the database: %s\n",
            sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "The database has been successfully created\n");
  }
  sqlite3_close(db);
}

void create_table(void) {
  const char *sql_template = "CREATE TABLE IF NOT EXISTS %s ("
                             "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                             "Name TEXT NOT NULL,"
                             "Age INTEGER NOT NULL);";
  char name_db[100] = {0};
  char table_name[100] = {0};
  char *errMsg = 0;
  int exit;
  char sql[256] = {0};
  sqlite3 *db;
  int flag;
  printf("Enter the name of the database: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Error opening the database: %s\n",
            sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "The database has been successfully opened!\n");
    printf("Enter the name of the table you are creating: ");
    scanf("%100s", table_name);
    snprintf(sql, sizeof(sql), sql_template, table_name);
    flag = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (flag != SQLITE_OK) {
      fprintf(stderr, "Error creating the table: %s\n", errMsg);
    } else {
      printf("The table has been created successfully!\n");
    }
    sqlite3_close(db);
  }
}

void insert(char *table_name, sqlite3 *db) {
  sqlite3_stmt *stmt;
  int rc;
  char sql[256] = {0};
  int column_1;
  char column_2[100];
  int column_3;
  printf("Enter a value for the ID (INTEGER): ");
  scanf("%d", &column_1);
  printf("Enter a value for Name (TEXT): ");
  scanf("%100s", column_2);
  printf("Enter a value for Age (INTEGER): ");
  scanf("%d", &column_3);
  snprintf(sql, sizeof(sql), "INSERT INTO %s (ID, Name, Age) VALUES (?, ?, ?);",
           table_name);
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error in preparing the SQL query: %s\n",
            sqlite3_errmsg(db));
    return;
  }
  sqlite3_bind_int(stmt, 1, column_1);
  sqlite3_bind_text(stmt, 2, column_2, -1, SQLITE_STATIC);
  sqlite3_bind_int(stmt, 3, column_3);
  rc = sqlite3_step(stmt);
  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Error when executing SQL query: %s\n",
            sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "Data successfully added to the table %s\n", table_name);
  }
  sqlite3_finalize(stmt);
}

void output(char *table_name, sqlite3 *db) {
  char *errMsg = 0;
  char sql[256] = {0};
  int rc;
  snprintf(sql, sizeof(sql), "SELECT * FROM %s;", table_name);
  rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error when executing a database query: %s\n",
            errMsg);
    sqlite3_free(errMsg);
  }
  printf("The data has been successfully output.\n");
}

void delete_elem(char *table_name, sqlite3 *db, int id) {
  sqlite3_stmt *stmt;
  int exit;
  char sql[256] = {0};
  snprintf(sql, sizeof(sql), "DELETE FROM %s WHERE ID = ?;", table_name);
  exit = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
  if (exit != SQLITE_OK) {
    fprintf(stderr, "Error in preparing the SQL query: %s\n", sqlite3_errmsg(db));
    return;
  }

  sqlite3_bind_int(stmt, 1, id);
  exit = sqlite3_step(stmt);
  if (exit != SQLITE_DONE) {
    fprintf(stderr, "Error when deleting an item from the table: %s\n",
            sqlite3_errmsg(db));
  } else {
    printf("The entry with ID = %d has been successfully deleted!\n", id);
  }
  sqlite3_finalize(stmt);
}

void delete_table(char *table_name, sqlite3 *db) {
  char sql[256] = {0};
  int rc;
  sqlite3_stmt *stmt;
  snprintf(sql, sizeof(sql), "DROP TABLE IF EXISTS %s;", table_name);
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error in preparing the SQL query: %s\n",
            sqlite3_errmsg(db));
    return;
  }
  rc = sqlite3_step(stmt);
  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Error when executing SQL query: %s\n",
            sqlite3_errmsg(db));
  } else {
    printf("Table %s has been successfully deleted!\n", table_name);
  }
  sqlite3_finalize(stmt);
}

void delete_db(char *name_db) {
  if (remove(name_db) == 0) {
    printf("The database has been successfully deleted!\n");
  } else {
    perror("An error occurred when deleting the database.\n");
  }
}

void table_ls(sqlite3 *db) {
  int rc;
  char *errMsg = 0;
  const char *sql = "SELECT name FROM sqlite_master WHERE type='table';";
  rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error when executing SQL query: %s\n", errMsg);
    sqlite3_free(errMsg);
  }
}