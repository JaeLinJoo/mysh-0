#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "commands.h"

int do_cd(int argc, char** argv) {

  if (!validate_cd_argv(argc, argv))
    return -1;
  
  else 
      return chdir(argv[1]);
}

int do_pwd(int argc, char** argv) {
 
    if (!validate_pwd_argv(argc, argv))
      return -1;

char *cmd;
if((cmd=getcwd(NULL,8096))!=0){
  printf("%s\n",cmd);
  return 0;
 }
 else
return -1;
}

int validate_cd_argv(int argc, char** argv) {

     if(strcmp(argv[0],"cd")==0&&argc==2)
	 return 1;
     else
        return 0;

}

int validate_pwd_argv(int argc, char** argv) {
 
  if(strcmp(argv[0],"pwd")==0&&argc==1)
     return 1;

  else 
   return 0;
}
