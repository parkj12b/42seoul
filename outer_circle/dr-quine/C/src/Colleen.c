#include <stdio.h>

void    call_me_maybe() {
}

/*
    hello world
*/
int main() {
/*
    hello main
*/

    char *str = "%s";
    char *tabs = "    ";
    char *program[] = {
        "#include <stdio.h>%c",
        "%c",
        "void    call_me_maybe() {%c",
        "}%c",
        "%c",
        "/*%c",
        "    hello world%c",
        "*/%c",
        "int main() {%c",
        "/*%c",
        "    hello main%c",
        "*/%c",
        "%c",
        "char *str = %c%s%c;%c",
        "char *tabs = %c    %c;%c",
        "    char *program[] = {%c",
        "%c",
        "    };%c",
        "    for (int i = 0; i < 13; i++)%c",
        "        printf(program[i], 10);%c",
        "    printf(tabs);%c",
        "    printf(program[13], 34, str, 34, 10);%c",
        "    printf(tabs);%c",
        "    printf(program[14], 34, 34, 10);%c",
        "    printf(program[15], 10);%c",
        "    for (int i = 0; i < (int) (sizeof(program) / sizeof(program[0])); i++) {%c",
        "        printf(tabs);%c",
        "        printf(tabs);%c",
        "        printf(program[1], 34);%c",
        "        printf(str, program[i]);%c",
        "        printf(program[1], 34);%c",
        "        printf(program[1], 44);%c",
        "        printf(program[1], 10);%c",
        "    }%c",
        "%c",
        "    for (int i = 17; i < (int) (sizeof(program) / sizeof(program[0])); i++) {%c",
        "        printf(program[i], 10);%c",
        "    }%c",
        "    call_me_maybe();%c",
        "}%c",
    };
    for (int i = 0; i < 13; i++)
        printf(program[i], 10);
    printf(tabs);
    printf(program[13], 34, str, 34, 10);
    printf(tabs);
    printf(program[14], 34, 34, 10);
    printf(program[15], 10);
    for (int i = 0; i < (int) (sizeof(program) / sizeof(program[0])); i++) {
        printf(tabs);
        printf(tabs);
        printf(program[1], 34);
        printf(str, program[i]);
        printf(program[1], 34);
        printf(program[1], 44);
        printf(program[1], 10);
    }

    for (int i = 17; i < (int) (sizeof(program) / sizeof(program[0])); i++) {
        printf(program[i], 10);
    }
    call_me_maybe();
}
