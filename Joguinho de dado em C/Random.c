
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jogar_dado(int lados)
{
    return 1 + rand() % lados;
}

int main()
{
    int i, num, f1, f2, f3, f4, f5, f6;
    f1 = f2 = f3 = f4 = f5 = f6 = 0;

    srand(time(NULL));

    for (i = 1; i <= 3; i++)
    {
        num = jogar_dado(6);
        switch(num)
        {
        case 1:
            f1++;
            break;
        case 2:
            f2++;
            break;
        case 3:
            f3++;
            break;
        case 4:
            f4++;
            break;
        case 5:
            f5++;
            break;
        case 6:
            f6++;
            break;
        }
    }

    printf("f1 = %d.\n", f1);
    printf("f2 = %d.\n", f2);
    printf("f3 = %d.\n", f3);
    printf("f4 = %d.\n", f4);
    printf("f5 = %d.\n", f5);
    printf("f6 = %d.\n", f6);

    return 0;
}
