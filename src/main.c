#include "header.h"
int main(int argc, char **argv){
    if (argc!=2){
        fprintf(stderr,"usage: ./myreadiso FILE\n"); 
        return 1;
    }
    struct iso_prim_voldesc *a;
    int fd=open_iso(argv[1],&a);
    if (fd<0){
        return 1;
    }
    struct iso_prim_voldesc *tmp=mv(a,MIN_SIZE);

    if (check_iso(tmp)!=0){
        fprintf(stderr,"my_read_iso: %s: invalid ISO9660 file\n", argv[1]);
        return 1;

    }
    char line [LEN_MAX]={0};
    char arg [LEN_MAX]={0};
    char cmd [LEN_MAX]={0};
    struct iso_dir *dir= mv(tmp, tmp->root_dir.data_blk.le * ISO_BLOCK_SIZE - MIN_SIZE);
    while (isatty(0) && putchar('>')){
        fgets(line,LEN_MAX,stdin);
        get_cmd(line,cmd);
        get_arg(line,arg);
        action(cmd,arg,tmp,&dir, fd);
    }
    while(fgets(line,LEN_MAX,stdin)!=NULL){
        get_cmd(line,cmd);
        get_arg(line,arg);
        action(cmd,arg,tmp,&dir,fd);
    }
    close(fd);
    return 0;
}
