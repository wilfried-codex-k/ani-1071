#include <cstdio>

int main()
{
    long long pas = 0;
    int n = 0;
    long long seau = 0;
    long long total = 0;

    if (scanf("%lld", &pas) != 1) pas = 0;
    if (scanf("%d", &n) != 1) n = 0;

    for (int i = 1; i <= n; i++)
    {
        long long duree = 0;
        if (scanf("%lld", &duree) != 1) break;

        seau = seau + duree;

        long long faits = 0;
        if (pas > 0 && seau >= pas)
        {
            faits = seau / pas;
            seau = seau - faits * pas;
        }
        total = total + faits;

        printf("%d %lld %lld\n", i, faits, seau);
    }

    printf("PAS TOTAL %lld\n", total);
    printf("RESTE FINAL %lld\n", seau);
    return 0;
}
