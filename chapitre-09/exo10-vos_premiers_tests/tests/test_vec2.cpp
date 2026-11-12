#include <NKTest/NkTest.h>

int Clamp(int x, int bas, int haut)
{
    if (x < bas) return bas;
    if (x > haut) return haut;
    return x;
}

double Milieu(double a, double b)
{
    return (a + b) / 2.0;
}

TEST_CASE(Clamp, GardeUneValeurDejaDansLIntervalle)
{
    ASSERT_EQUAL(3, Clamp(3, 0, 5));
}

TEST_CASE(Clamp, RameneUneValeurTropHauteAuBordHaut)
{
    ASSERT_EQUAL(5, Clamp(12, 0, 5));
}

TEST_CASE(Clamp, RameneUneValeurTropBasseAuBordBas)
{
    ASSERT_EQUAL(0, Clamp(-3, 0, 5));
}

TEST_CASE(Clamp, LaisseLeBordBasInchange)
{
    ASSERT_EQUAL(0, Clamp(0, 0, 5));
}

TEST_CASE(Clamp, LaisseLeBordHautInchange)
{
    ASSERT_EQUAL(5, Clamp(5, 0, 5));
}

TEST_CASE(Clamp, IntervalleReduitAUnSeulPoint)
{
    ASSERT_EQUAL(2, Clamp(7, 2, 2));
    ASSERT_EQUAL(2, Clamp(-1, 2, 2));
    ASSERT_EQUAL(2, Clamp(2, 2, 2));
}

TEST_CASE(Clamp, FonctionneAvecDesBornesNegatives)
{
    ASSERT_EQUAL(-5, Clamp(-9, -5, -1));
    ASSERT_EQUAL(-1, Clamp(4, -5, -1));
}

TEST_CASE(Milieu, LeMilieuDeDeuxDecimauxEstProcheDuResultatAttendu)
{
    // ASSERT_EQUAL(0.15, Milieu(0.1, 0.2));
    ASSERT_NEAR(0.15, Milieu(0.1, 0.2), 1e-9);
}
