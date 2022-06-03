#ifndef __STRBUFF_H
  #define __STRBUFF_H 1
#endif

/* puts: puts one string into buffer */
int putstr(char *s);

/* rall: reads words from inputstream separated by sep */
void rall(char sep);

/* gets: gets one string in queue order */
char *gets();

/* buflen: gets buffer's length */
int buflen();

/* clrbuff: clears and empties buffer while resetting all pointers and state */
void clrbuff(void);
