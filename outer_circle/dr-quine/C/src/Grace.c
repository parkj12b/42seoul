#include <stdio.h>
#define X "#include <stdio.h>%1$c#define X %2$c%3$s%2$c%1$c#define FT() int main(){FILE *f=fopen(%2$cGrace_kid.c%2$c,%2$cw+%2$c);fprintf(f,X,10,34,X);fclose(f);}%1$c#define Z FT()%1$cZ%1$c/*%1$c    Since you want a comment so bad :(%1$c*/"
#define FT() int main(){FILE *f=fopen("Grace_kid.c","w+");fprintf(f,X,10,34,X);fclose(f);}
#define Z FT()
Z
/*
    Since you want a comment so bad :(
*/