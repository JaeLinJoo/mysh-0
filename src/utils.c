#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv){

  int count = 0;
  char* cmdCpy;
  cmdCpy=(char*)malloc(2048);
 
  strcpy(cmdCpy,command);
 
  char* tok=strtok(cmdCpy,"' '\t\n");

  (*argv)=(char**)malloc(sizeof(char*)*1000);
  (*argv)[count]=(char*)malloc(sizeof(char)*1000);

  if(tok==NULL){
  *argc=1;
  strcpy((*argv)[0],"");
  return;
  }

  while(tok!=NULL){
    strcpy((*argv)[count],tok);
      tok=strtok(NULL,"' ',\t,\n");
      count++;
      (*argv)[count]=(char*)malloc(sizeof(char)*1000);
  }

  *argc = count;
  free(cmdCpy);
    // TODO: Fill this!
}
