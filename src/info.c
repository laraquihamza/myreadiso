#include "header.h"
void info(char *arg, struct iso_prim_voldesc *a){
    if (strcmp(arg,"\0")!=0){
        fprintf(stderr,"my_read_iso: info: command must take an argument\n");
    }
    else{
        printf("System Identifier: %.*s\n",ISO_SYSIDF_LEN,a->syidf);
        printf("Volume Identifier: %.*s\n",ISO_VOLIDF_LEN,a->vol_idf);
        printf("Block count: %d\n",a->vol_blk_count.le);
        printf("Block size: %d\n",a->vol_blk_size.le);
        printf("Creation date: %.*s\n",ISO_LDATE_LEN,a->date_creat);
        printf("Application Identifier: %.*s\n",ISO_APP_LEN  ,a->app_idf);
    }
}
