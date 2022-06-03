#ifndef __MKRND_H
  #define __MKRND_H 1
#endif

/* prnd: prints random chars from src into outputstream */
void prnd(char **src,int len,int num,char sep,char endl);

/* prnrd_rw: same but prints a row with custom end character (good for custom formats) */
void prnd_rw(char **src,int len,int num,char sep,int tik,char endr);

