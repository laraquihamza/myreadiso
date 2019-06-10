#include "header.h"

int is_spaces(char *s){
    for(size_t i=0;s[i]; i++){
        if (s[i]!=' ' && s[i]!='\t' && s[i]!='\n' ){
            return 1;
        }
    }
    return 0;
}

            
void action (char * cmd, char *arg, struct iso_prim_voldesc *a,
             struct iso_dir **dir, int fd){
    if(strcmp(cmd,"help")==0){
        help(arg);
    }
    else if (strcmp(cmd,"info")==0){
        info(arg, a);
    }
    else if (strcmp(cmd, "ls")==0){
        ls(arg, *dir);
    }
    else if(strcmp(cmd, "cat")==0){
        cat(a , *dir,arg);
    }
    else if (strcmp(cmd, "cd")==0){
        cd(a, dir, arg);
    }
    else if (strcmp(cmd, "quit")==0){
        quit(arg, fd);
    }
    else if (strcmp(cmd, "get")==0){
        get(a, *dir, arg);
    }
    else if( is_spaces(cmd)==0){

    }
    else{
        fprintf(stderr,"my_read_iso: %s: unknown command\n",cmd);
    }
}
