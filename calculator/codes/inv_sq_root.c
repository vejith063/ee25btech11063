#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

double fast_inv_sqrt(double input_x){
    float x = (float) input_x;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = x * 0.5F;
    y  = x;

    // Union used for safe type-punning on GCC
    union {
      float f;
      int i;
    } u;

    u.f = y;
    // Magic number calculation with 32-bit int
    u.i = 0x5f3759df - ( u.i >> 1 );
    y = u.f;

    y = y * ( threehalfs - ( x2 * y * y ) );

    return (double) y;
}
