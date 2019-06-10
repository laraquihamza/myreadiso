#include "header.h"
void quit(char *arg, int fd){
    if (strcmp(arg,"\0")!=0){
        fprintf(stderr,"my_read_iso: quit: command does not take an argument\n");
        return;
    }
    close(fd);
    exit(0);
}
