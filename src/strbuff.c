#ifndef __STRBUFF_H
  #include "../hdr/strbuff.h"
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef BUFF_SIZE
  #define BUFF_SIZE 1024
#endif

#ifndef STR_SIZE
  #define STR_SIZE 64
#endif

/* buffer is public for easier work*/
char *buff[BUFF_SIZE];
static char **p=buff;
static char **rp=buff; /* queue reading */

int putstr(char *s){
  
  if(p-buff >= BUFF_SIZE){
    *p=NULL; /* end buffer with null ptr! */
    return 1; /* going with convention */
  }
  
  *p=s;
  ++p;
  return 0;
}

/* rs: read one string ended before sep */
static int rs(char sep){

  
  char *s=(char *) malloc(sizeof(char) * STR_SIZE);
  char *start=s;

  char c;
  while( (c=getchar())!=EOF && c!=sep  ){
    *s=c;
    ++s;
  }

  if(*start)
    putstr(start);

  return c!=EOF;

}

void rall(char sep){
  while(rs(sep));

  *p=NULL; /* ending buffer with null ptr! */
}

char *gets(){
  
  char *s=*rp;
  ++rp;
  return s;
}

int buflen(){
  return p-buff-1;
}

void clrbuff(){

  if(p==buff)
    return;

  do{
    /* if anything is read, p is buff+1 and points to an empty slot */
    free(*p);
    --p;
  }while(p!=buff && *p);

}
