#include "header.h"
int open_iso(char *path,struct iso_prim_voldesc **a){
    int fd = open(path, O_RDONLY);
    if (fd<0){
        fprintf(stderr, "my_read_iso: %s: No such file or directory\n", path);
        return -1;
    }
    struct stat l;
    fstat(fd,&l);
    if (l.st_size< MIN_SIZE){
        close(fd);
       fprintf(stderr,"my_read_iso: %s: invalid ISO9660 file\n", path);
        return -1;
    }
    *a=mmap(NULL,l.st_size,PROT_READ,MAP_PRIVATE,fd,0);
    if (*a==MAP_FAILED)
        return -1;
    return fd;
}
