#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int loadEnvironment() {
  char* soji_dir = getenv("SOJI_DIR");
  char* soji_notes_dir = getenv("SOJI_NOTES_DIR");
  if(soji_dir == NULL || soji_notes_dir == NULL) {
    char* home_dir = getenv("HOME");
    char rc_path[500];
    strcpy(rc_path, home_dir);
    strcat(rc_path, "/.config/soji/sojirc");

    FILE *rc_file = fopen(rc_path, "r");
    while(!feof(rc_file)) {
      char buff[500];
      fgets(buff, 500, rc_file);
      if(strstr(buff, "SOJI_DIR") && soji_dir == NULL) {
        char* value = strchr(buff, '=') + 1;
        setenv("SOJI_DIR", value, 1);
      }
      if(strstr(buff, "SOJI_NOTES_DIR") && soji_notes_dir == NULL) {
        char* value = strchr(buff, '=') + 1;
        setenv("SOJI_NOTES_DIR", value, 1);
      }
    }
  }
}
