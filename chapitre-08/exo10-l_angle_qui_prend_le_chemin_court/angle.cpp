#include <cstdio>
#include <cmath>

const double pi = 3.14159265358979323846;

double enRadians(double deg) { return deg * pi / 180.0; }
double enDegres(double rad) { return rad * 180.0 / pi; }

double lerp(double a, double b, double t)
{
    return a + (b - a) * t;
}

double lerpAngle(double a, double b, double t)
{
    double d = b - a;
    while (d > pi) d -= 2.0 * pi;
    while (d < -pi) d += 2.0 * pi;
    return a + d * t;
}

// Ramene un angle en degres dans [0, 360[
double ramener360(double deg)
{
    double r = fmod(deg, 360.0);
    if (r < 0.0) r += 360.0;
    r = floor(r * 1000000.0 + 0.5) / 1000000.0;   // arrondi pour l'affichage
    if (r >= 360.0) r -= 360.0;
    return r;
}

void transition(double debut, double fin)
{
    printf("De %.0f vers %.0f degres\n", debut, fin);
    printf("   t    lerp   lerpAngle\n");
    for (int i = 0; i <= 10; i++)
    {
        double t = i / 10.0;
        double l1 = lerp(debut, fin, t);
        double l2 = enDegres(lerpAngle(enRadians(debut), enRadians(fin), t));
        printf(" %.1f  %6.1f  %6.1f\n", t, ramener360(l1), ramener360(l2));
    }
}

int main()
{
    transition(350.0, 10.0);
    transition(10.0, 350.0);
    transition(0.0, 180.0);

    printf("Camera derriere une voiture qui tourne\n");
    printf("pas   cap    lerp  lerpAngle\n");
    double cap = 340.0;
    double cam1 = 340.0;
    double cam2 = enRadians(340.0);
    printf(" %2d  %5.1f  %5.1f  %5.1f\n", 0, cap, cam1, ramener360(enDegres(cam2)));
    for (int pas = 1; pas <= 12; pas++)
    {
        cap = ramener360(cap + 4.0);
        cam1 = lerp(cam1, cap, 0.3);
        cam2 = lerpAngle(cam2, enRadians(cap), 0.3);
        printf(" %2d  %5.1f  %5.1f  %5.1f\n", pas, cap, ramener360(cam1), ramener360(enDegres(cam2)));
    }
    return 0;
}
