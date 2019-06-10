#include "header.h"
void get_arg(char *src, char *dst){
    size_t i=0;
    size_t j=0;
    while (src[i]==' ')
        i++;
    for(; src[i]!=' ' && src[i]; i++);
    for(; src[i]==' ' && src[i]; i++);
    for(;src[i] && src[i]!='\n'; i++){
        dst[j]=src[i];
        j++;
    }
    dst[j]=0;
}
