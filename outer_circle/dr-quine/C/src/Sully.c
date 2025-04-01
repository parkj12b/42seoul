#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FMT "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$c#define FMT %2$c%3$s%2$c%1$cint main() {%1$c    int i = %4$d;%1$c    char filename[50];%1$c    if (i <= 0)%1$c        return 0;%1$c    i--;%1$c    snprintf(filename, sizeof(filename), %2$cSully_%%d.c%2$c, i);%1$c    FILE *file = fopen(filename, %2$cw+%2$c);%1$c    if (!file) {%1$c        perror(%2$cFailed to create file%2$c);%1$c        return 1;%1$c    }%1$c    fprintf(file, FMT, 10, 34, FMT, i);%1$c    fclose(file);%1$c    char command[100];%1$c    snprintf(command, sizeof(command), %2$cgcc %%s -o Sully_%%d%2$c, filename, i);%1$c    system(command);%1$c    snprintf(command, sizeof(command), %2$c./Sully_%%d%2$c, i);%1$c    system(command);%1$c}%1$c"
int main() {
    int i = 5;
    char filename[50];
    if (i <= 0)
        return 0;
    i--;
    snprintf(filename, sizeof(filename), "Sully_%d.c", i);
    FILE *file = fopen(filename, "w+");
    if (!file) {
        perror("Failed to create file");
        return 1;
    }
    fprintf(file, FMT, 10, 34, FMT, i);
    fclose(file);
    char command[100];
    snprintf(command, sizeof(command), "gcc %s -o Sully_%d", filename, i);
    system(command);
    snprintf(command, sizeof(command), "./Sully_%d", i);
    system(command);
}