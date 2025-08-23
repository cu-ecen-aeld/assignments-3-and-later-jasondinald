#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
  openlog(NULL,0,LOG_USER);
  if (argc <3 ){
	  syslog(LOG_ERR, "Invalid Numbers of arguments: %d", argc);
	  printf("Invalid Numbers of arguments: %d", argc);
	  return 1;
  }
  char writefile[50];
  strcpy(writefile,argv[1]);
  char writestr[100];
  strcpy(writestr,argv[2]);
  FILE * filestr;
  filestr=fopen( writefile, "w");
  if (filestr == NULL){
	  printf("Error: %s\n", strerror(errno));
	  syslog(LOG_ERR, "Error: %s\n", strerror(errno));
	  return 1;
  }

  syslog(LOG_DEBUG, "Writing %s to %s",writestr,writefile);
  fprintf(filestr, "%s\n",writestr);
  fclose(filestr);
  closelog();
  return 0;
}

