#include "callback.h"

int callback(void *data, int argc, char **argv, char **azColName) {
  void *tmp = data;
  tmp = data;
  data = tmp;
  for (int i = 0; i < argc; i++) {
    printf("%s=%s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}