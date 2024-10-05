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
  printf("To create a database, press 1.\n");
  printf("To create a table, press 2.\n");
  printf("To add to the table, press 3.\n");
  printf("To display the table, press 4.\n");
  printf("To delete from the table, press 5.\n");
  printf("To delete a table, press 6.\n");
  printf("To delete the database, press 7.\n");
  printf("To display the tables stored in the database, press 8.\n");
  printf("To exit, press 0.\n");
}