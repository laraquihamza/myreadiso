#include "header.h"
void get(struct iso_prim_voldesc *a , struct iso_dir *dir, char * arg){
  int i=0;
  char *c;
  int delta=0;
  char *disp;
  FILE * new;
  i=0;
  int k=0;
  if (strcmp(arg,"\0")==0){
      fprintf(stderr,"my_read_iso: get: command must take an argument\n");
      return;
  }
  while(dir->idf_len>0){
    if (i>=2){
      c=(char*)dir +sizeof(struct iso_dir);
      for(k=0; c[k]!=';' && k< dir ->idf_len;k++){
          
      }
      if (strncmp(arg,c,k)==0){
	if( (dir->type & (1<<1))==0){
            new=fopen(arg,"w");
            if( new==NULL)
              return;
	  disp=mv(a,dir->data_blk.le * ISO_BLOCK_SIZE - MIN_SIZE);
	  fwrite(disp,sizeof(char),dir->file_size.le,new);
	  fclose(new);
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
  }
  fprintf(stderr,"my_read_iso: unable to find \'%s\' entry\n",arg);
  return;

}
