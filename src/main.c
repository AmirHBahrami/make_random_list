#ifndef __STRBUFF_H
  #include "../hdr/strbuff.h"
#endif

#ifndef __MKRND_H
  #include "../hdr/mkrnd.h"
#endif

#ifndef __STDIO_H
  #include <stdio.h>
#endif

#ifndef BUFF_SIZE
  #define BUFF_SIZE 64
#endif

extern char *buff[BUFF_SIZE];
void clrbuff(void); /* for some reason this header in strbuff won't get included automatically */

/* strcomp: checks if two strings are the same */
int strcomp(char *s1,char *s2);

/* atoint: makes an integer from a string */
int atoint(char *s);

/* printh: prints help*/
void printh(void);


// TODO add support for string separator
// TODO last outputs are troublesome : 1. when the tik isn't reached 2. the last entry has a seperator after it (printf("\r") needed)
/* main: runs this bloody bloody! */
int main(int argc,char **argv){

  char rs='\n',ws='\n',endr='\n';
  int tik=1,len,n=10;

  /* processing and setting arguments */
  while(*argv){

    if(**argv =='-'){
      ++(*argv);

      if ( **argv=='h' || strcomp(*argv,"-help")){
        printh();
        return 0;
      }

      else if ( **argv=='e'){
        ++argv;
        endr=**argv;
      }
      
      else if ( **argv=='t'){
        ++argv;
        tik=atoint(*argv);
      }

      else if ( **argv=='n' ){
        ++argv;
        n=atoint(*argv);
      }

      else if( strcomp(*argv,"sp")){
        ++argv;
        rs=**argv;
        ws=**argv;
      }

      else if ( strcomp(*argv,"rs")){
        ++argv;
        rs=**argv;
      }

      else if ( strcomp(*argv,"rw")){
        ++argv;
        ws=**argv;
      }

    }

    ++argv;
  }
  
  /* reading and buffering inputs */
  rall(rs);

  /* ouput */
  if((len=buflen() )>0)
    prnd_rw(buff,len,n,ws,tik,endr);

  else{
    printf("buffer empty!\n");
    return 1;
  }
  
  
  return 0;
}

void printh(void){
  
  printf("\nabmrl - usage: abmrl [-options] < [filepath] \n\n\t-h\t--help\t: shows this help\n\t-n\t[int]\t: number of elments you want\n\t-rs\t[char]\t: read seperator; separator for reading the names which are to be randomized\n\t-rw\t[char]\t: write seperator; separator for when writing the output\n\t-sp\t[char]\t: separator for both reading and writing\n\t-e\t[char]\t: end-row character; placed at the end of each generated row\n\t-t\t[int]\t: tik; after each tik values written, an end-row character will be inserted (useful for custom formats)\n\tdefault options\t: -n 10 -sp '\\n'  -e '\\n'\nif -e and -rw are given, -e replaces rw\n\n");

}

int strcomp(char *s1, char *s2){
  
  while(*s1 && *s2 && *s1==*s2){
    ++s1;
    ++s2;
  }

  return !(*s1) && !(*s2); 
}

int atoint(char *s){

  int i=0;
  for(;*s && *s>='0' && *s<='9';s++)
    i=((i*10)+(*s-'0'));
  return i;
}
