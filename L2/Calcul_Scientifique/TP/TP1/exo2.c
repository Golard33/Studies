#include <stdio.h>
#include <math.h>
#include "interpolation.h"

int main () {
    double x [4] = {25, 40, 50, 60};
    double y [4] = { 95, 75, 63, 54};

    printf("30 °C : %lf\n", eval_p(30, x, y, 3));
    printf("45 °C : %lf\n", eval_p(45, x, y, 3));
    printf("70 °C : %lf\n", eval_p(70, x, y, 3));

return 0;
}