#include "case.h"

void case_three(void) {
  char name_db[100] = {0};
  char table_name[100] = {0};
  int exit;
  sqlite3 *db;
  printf("Enter the name of the database where the table is stored: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Error opening the database: %s\n",
            sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "The database has been successfully opened!\n");
    printf("Enter the name of the table to fill in: ");
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
  printf("Enter the name of the database where the table is stored: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Error opening the database: %s\n",
            sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "The database has been successfully opened!\n");
    printf("Enter the name of the table you want to output: ");
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
  printf("Enter the name of the database where the table is stored: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Error opening the database: %s\n",
            sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "The database has been successfully opened!\n");
    printf("Enter the name of the table from which you want to delete the item: ");
    scanf("%100s", table_name);
    printf("Enter the ID to be deleted: ");
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
  printf("Enter the name of the database where the table is stored: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Error opening the database: %s\n",
            sqlite3_errmsg(db));
  } else {
    fprintf(stderr, "The database has been successfully opened!\n");
    printf("Enter the name of the table you want to delete: ");
    scanf("%100s", table_name);
    delete_table(table_name, db);
  }
  sqlite3_close(db);
}

void case_seven(void) {
  char name_db[100] = {0};
  printf("Enter the name of the database you want to delete: ");
  scanf("%99s", name_db);
  delete_db(name_db);
}

void case_eight(void) {
  char name_db[100] = {0};
  int exit;
  sqlite3 *db;
  printf("Enter the name of the database whose contents you want to output: ");
  scanf("%99s", name_db);
  exit = sqlite3_open(name_db, &db);
  if (exit) {
    fprintf(stderr, "Error opening the database: %s\n",
            sqlite3_errmsg(db));
  } else {
    printf("The database has been successfully opened!\n");
    table_ls(db);
  }
  sqlite3_close(db);
}