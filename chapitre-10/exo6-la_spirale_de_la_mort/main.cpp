#include <cstdio>

long long vider(long long* seau, long long pas)
{
    long long faits = 0;
    if (pas > 0 && *seau >= pas)
    {
        faits = *seau / pas;
        *seau = *seau - faits * pas;
    }
    return faits;
}

int main()
{
    long long pas = 0;
    long long plafond = 0;
    int n = 0;
    long long seauAvec = 0;
    long long seauSans = 0;
    long long totalAvec = 0;
    long long totalSans = 0;
    int plafonnages = 0;

    if (scanf("%lld", &pas) != 1) pas = 0;
    if (scanf("%lld", &plafond) != 1) plafond = 0;
    if (scanf("%d", &n) != 1) n = 0;

    for (int i = 1; i <= n; i++)
    {
        long long duree = 0;
        if (scanf("%lld", &duree) != 1) break;

        long long dureeAvec = duree;
        if (duree > plafond)
        {
            dureeAvec = plafond;
            plafonnages++;
        }

        seauAvec = seauAvec + dureeAvec;
        seauSans = seauSans + duree;

        long long pasAvec = vider(&seauAvec, pas);
        long long pasSans = vider(&seauSans, pas);
        totalAvec = totalAvec + pasAvec;
        totalSans = totalSans + pasSans;

        printf("%d %lld %lld\n", i, pasAvec, pasSans);
    }

    printf("AVEC %lld\n", totalAvec);
    printf("SANS %lld\n", totalSans);
    printf("PLAFONNAGES %d\n", plafonnages);
    printf("DETTE %lld\n", seauSans);
    return 0;
}
