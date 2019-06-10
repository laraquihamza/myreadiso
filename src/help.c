#include "header.h"
void help(char *arg){
    if (strcmp(arg,"\0")!=0){
        fprintf(stderr,"my_read_iso: help: command does not take an argument\n");
    }
    else{
        printf("help: display command help\n");
        printf("info: display volume info\n");
        printf("ls: display the content of a directory\n");
        printf("cd: change current directory\n");
        printf("tree: display the tree of a directory\n");
        printf("get: copy file to local directory\n");
        printf("cat: display file content\n");
        printf("pwd: print current path\n");
        printf("quit: program exit\n");
    }
}
