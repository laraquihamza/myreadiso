#include "header.h"
void cat(struct iso_prim_voldesc *a , struct iso_dir *dir, char * arg){
    int i=0;
    int j=0;
    char *c;
    int cmp=0;
    int delta=0;
    char *disp;
    i=0;
    if(strcmp(arg,"\0")==0){
        fprintf(stderr,"my_read_iso: cat: command must take an argument\n");
            return ;
    };
    while(dir->idf_len>0){
        if (i>=2){
            c=(char*)dir +sizeof(struct iso_dir);
            for(j=0; j<dir->idf_len && c[j]!=';'; j++){
                if(c[j]!=arg[j]){
                    cmp=1;
                    break;
                }
            }
            if (cmp==0){
                if( (dir->type & (1<<1))==0){
                    disp=mv(a,dir->data_blk.le * ISO_BLOCK_SIZE - MIN_SIZE);
                    fwrite(disp,1,dir->file_size.le,stdout);
                    return;
                }
                else {
                    fprintf(stderr,"it's a directory\n");
                    return;
                }
            }
        }
        if(dir->idf_len%2==0)
            delta=1;
        else
            delta=0;
        dir = mv(dir,sizeof(struct iso_dir)+dir->idf_len + delta);
        i++;
        cmp=0;

    }
    fprintf(stderr,"my_read_iso: unable to find '%s' entry\n",arg);
    return;

}
