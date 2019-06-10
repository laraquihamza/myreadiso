#include "header.h"

void ls(char *arg,struct iso_dir * dir){
    if (strcmp(arg,"\0")==0){
        strcpy(arg,".");
    }

    int i=0;
    int j=0;
    char *c;
    while(dir->idf_len >0 ){
        if((dir->type & (1<<1))==0){
            printf("-");
        }
        else
            printf("d");
        if((dir->type & 1)==0)
            printf("- ");
        else
            printf("h ");
        printf("%9u ",dir->file_size.le);
        printf("%.4d/%.2d/%.2d %.2d:%.2d ", 1900+dir->date[0], dir->date[1],dir->date[2], dir->date[3], dir->date[4]);
        if (i==0)
            printf(".");
    
        else if(i==1)
            printf("..");
        else {
            c=(char *)dir +sizeof(struct iso_dir);
            for (j=0; j< dir->idf_len && c[j]!= ';' ; j++){
                printf("%c", c[j]);
            }

        }
        printf("\n");
        dir=mv( dir,dir->dir_size);
        i++;
    }  
}
