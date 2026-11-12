#include <cstdio>

int main()
{
    char format[4096];
    long long args[10];
    int n = 0;
    int remplaces = 0;
    int manquants = 0;

    for (int i = 0; i < 10; i++) args[i] = 0;

    if (fgets(format, 4096, stdin) == NULL) format[0] = '\0';

    int len = 0;
    while (format[len] != '\0') len++;
    while (len > 0 && (format[len - 1] == '\n' || format[len - 1] == '\r'))
    {
        format[len - 1] = '\0';
        len--;
    }

    if (scanf("%d", &n) != 1) n = 0;
    for (int i = 0; i < n; i++)
    {
        long long v = 0;
        if (scanf("%lld", &v) != 1) break;
        if (i < 10) args[i] = v;
    }

    int i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '{' && format[i + 1] >= '0' && format[i + 1] <= '9' && format[i + 2] == '}')
        {
            int num = format[i + 1] - '0';
            if (num < n)
            {
                printf("%lld", args[num]);
                remplaces++;
            }
            else
            {
                printf("{%d}", num);
                manquants++;
            }
            i += 3;
        }
        else
        {
            printf("%c", format[i]);
            i++;
        }
    }
    printf("\n");

    printf("REMPLACES %d\n", remplaces);
    printf("MANQUANTS %d\n", manquants);
    return 0;
}
