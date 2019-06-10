#include "header.h"
void get_cmd(char *src, char *dst){
    size_t i=0;
    while (src[i]==' ')
        i++;
    size_t j=0;
    for(; src[i]!=' ' && src[i] && src[i]!='\n'; i++){
        dst[j]=src[i];
        j++;
    }
    dst[j]=0;
}
