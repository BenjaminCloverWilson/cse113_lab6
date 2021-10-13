#include <stdio.h>
#include <stdlib.h>

int main()
{
    char in[16];
    char a[3];
    int num;

    printf("Enter:\n");
    fgets(in, 16, stdin);
    num = atoi(in);
    printf("%d\n", num);

    a[0] = in[3];
    a[1] = in[4];
    num = atoi(a);
    printf("%d\n", num);

    a[0] = in[6];
    a[1] = in[7];
    num = atoi(a);
    printf("%d\n", num);

    for(int i = 0; i < 16; i++){
        printf("%c", in[i]);
    }

    return 0;
}