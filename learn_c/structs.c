#include<stdio.h>

struct candidat
{
    char *name;
    int num;
};

int
main(void)
{
    struct candidat cnd[2];
    cnd[0].name = "Alex";
    cnd[0].num = 1;
    cnd[1].name = "Sveta";
    cnd[1].num = 2;

    printf("%s, - %d votes\n", cnd[0].name, cnd[0].num);
    printf("%s, - %d votes\n", cnd[1].name, cnd[1].num);

    return 0;
}
