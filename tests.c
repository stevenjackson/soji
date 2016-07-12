#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void testPassed();
void testLoadEnvironment();

int main() {

  char *testSojiDir = getenv("SOJI_DIR");
  char *testSojiNotesDir = getenv("SOJI_NOTES_DIR");

  printf("Running C unit tests -- env: %s %s \n", testSojiDir, testSojiNotesDir);

  testLoadEnvironment();
  testPassed();
}

void testLoadEnvironment() {

  char *testSojiDir = NULL;
  char *tempEnvVar = NULL;
  if (tempEnvVar = getenv("SOJI_DIR")) {
    testSojiDir = tempEnvVar;
  }
  char *testSojiNotesDir = NULL;
  if (tempEnvVar = getenv("SOJI_NOTES_DIR")) {
    testSojiNotesDir = tempEnvVar;
  }

  unsetenv("SOJI_DIR");
  unsetenv("SOJI_NOTES_DIR");
  int ret = loadEnvironment();
  assert(getenv("SOJI_DIR"));
  assert(getenv("SOJI_NOTES_DIR"));

  if(testSojiDir) {
    setenv("SOJI_DIR", testSojiDir, 1);
  }
  if(testSojiNotesDir) {
    setenv("SOJI_NOTES_DIR", testSojiNotesDir, 1);
  }
}

void testPassed() {
  printf(".");
}


