#include "header.h"
char check_iso(struct iso_prim_voldesc *  a){
    char temp[6];
    int i=0;
    for ( ; i<5 ; i++){
        temp[i]=a->std_identifier[i];
    }
    temp[5]='\0';
    return strcmp(temp,"CD001");
}
