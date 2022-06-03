#ifndef __MKRND_H
  #define __MKRND_H 1
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef __TIME_H
  #include <time.h>
#endif

#ifndef __STDLIB_H
  #include <stdlib.h>
#endif

void prnd_rw(char **src,int len,int num,char sep,int tik,char endr){
 
  srand(time(0));
  int t=1;
  for(int i;num>0;num--){

    if(num==1 && t!=tik)
      sep=endr;

    i=(rand()%len)+1; // lower limit is 0
    if(tik>0 && tik==t){
      t=0;
      printf("%s%c",src[i],endr);
    }
    else
      printf("%s%c",src[i],sep);
    ++t;

  }

  /* cleaning the last output */
  // problem : it leaves a ^M at the end of each file (or output)
  // printf("\r");
}

void prnd(char **src,int len,int num,char sep){

  /* just a modified version of function above */
  prnd_rw(src,len,num,sep,0,sep);
}

