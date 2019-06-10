#ifndef HEAD
#define HEAD
#include <string.h>
#include <stdio.h>
#include <sys/mman.h>
#include <err.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "iso9660.h"
#define LEN_MAX 4095
#define MIN_SIZE (ISO_PRIM_VOLDESC_BLOCK * ISO_BLOCK_SIZE )
int open_iso(char *path,struct iso_prim_voldesc **a);
char check_iso(struct iso_prim_voldesc *  a);
void * mv(void *a , int dec);
void get_arg(char *src, char *dst);
void get_cmd(char *src, char *dst);
void action (char * cmd, char *arg, struct iso_prim_voldesc *a,
             struct iso_dir **dir, int fd);
void help(char *arg);
void info(char *arg, struct iso_prim_voldesc *a);
void ls(char *arg,struct iso_dir * dir);
void cat(struct iso_prim_voldesc *a , struct iso_dir *dir, char * arg);
void cd(struct iso_prim_voldesc *a, struct iso_dir **dir, char *arg);
void quit(char *arg, int fd);
void get(struct iso_prim_voldesc *a , struct iso_dir *dir, char * arg);
#endif
