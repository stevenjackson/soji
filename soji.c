#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  loadEnvironment();
  char *soji_dir = getenv("SOJI_DIR");
  char *command = "";
  strcat(command, soji_dir);
  strcat(command, "/subcommands");
  strcat(command, "/");
  strcat(command, argv[1]);
  for(int i = 1; i < argc ; i++) {
    strcat(command, " \"");
    strcat(command, argv[i]);
    strcat(command, "\"");
  }
  printf("%s", command);


  return 0;
}
