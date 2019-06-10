#include "header.h"
void cd(struct iso_prim_voldesc *a, struct iso_dir **dir, char *arg){
    int i=0;
    char *c;
    int delta=0;
    struct iso_dir *temp= *dir;
    if (strcmp(arg,".")==0 || strcmp(arg,"\0")==0){
        return;
    }
    if (strcmp(arg,"..")==0){
        *dir = mv(*dir,sizeof(struct iso_dir)+(*dir)->idf_len + delta);
        *dir=mv(a,(*dir)->data_blk.le * ISO_BLOCK_SIZE - MIN_SIZE);
        return;
    }
  
    i=0;
    while(temp->idf_len>0){
        if (i>1){
            c=(char*)temp +sizeof(struct iso_dir);
            if (strncmp(c,arg,temp->idf_len)==0){
                if( (temp->type & (1<<1))==2){
                    printf("Changing to \'%s\' directory\n",arg );
                    *dir=mv(a,temp->data_blk.le * ISO_BLOCK_SIZE - MIN_SIZE);
                    return;
                }
                else {
                    fprintf(stderr,"it's a file\n");
                    return;
                }
            }
        }
        if(temp->idf_len %2 ==0)
            delta=1;
        else{
            delta=0;
        }
        temp = mv(temp,sizeof(struct iso_dir)+temp->idf_len + delta);
        i++;
    }
    fprintf(stderr,"my_read_iso: unable to find '%s' directory entry\n",arg);
    return;
}
