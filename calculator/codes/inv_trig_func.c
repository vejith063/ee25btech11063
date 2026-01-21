#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

double fast_inv_sqrt(double input_x) {
    float x = (float) input_x;
    float x2 = x * 0.5F;
    float y = x;
    const float threehalfs = 1.5F;

    // Fixed for GCC/PC: 
    // 1. Used 'int' (32-bit) instead of 'long' (which is 64-bit on x64 GCC).
    // 2. Used union to avoid strict-aliasing violation.
    union {
        float f;
        int i;
    } u;

    u.f = y;
    u.i = 0x5f3759df - (u.i >> 1);
    y = u.f;

    y = y * (threehalfs - (x2 * y * y));

    return (double) y;
}

double arctan(double x_target) {
    int sign = 1;
    if (x_target < 0) {
        sign = -1;
        x_target = -x_target;
    }

    if (x_target > 1.0) {
        double val = arctan(1.0 / x_target);
        return sign * (PI / 2 - val);
    }

    double x = 0.0;
    double y = 0.0;
    double h = 0.01;

    while (x < x_target) {
        if (x + h > x_target) {
            h = x_target - x;
        }

        double k1 = h / (1.0 + x * x);

        double x_mid = x + h / 2.0;
        double k2 = h / (1.0 + x_mid * x_mid);
        double k3 = h / (1.0 + x_mid * x_mid);

        double x_end = x + h;
        double k4 = h / (1.0 + x_end * x_end);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x += h;
    }

    return sign * y;
}

double arcsin(double x_target) {
    if (x_target < -1.0 || x_target > 1.0) return 0;

    if (x_target >= 0.9999) return PI / 2;
    if (x_target <= -0.9999) return -1 * (PI / 2);

    int sign = 1;
    if (x_target < 0) {
        sign = -1;
        x_target = -x_target;
    }

    double x = 0.0;
    double y = 0.0;
    double h = 0.01;

    while (x < x_target) {
        if (x + h > x_target) {
            h = x_target - x;
        }

        double k1 = h * fast_inv_sqrt(1 - x * x);
        double x_mid = x + h / 2.0;
        double k2 = h * fast_inv_sqrt(1 - x_mid * x_mid);
        double k3 = h * fast_inv_sqrt(1 - x_mid * x_mid);
        double x_end = x + h;
        double k4 = h * fast_inv_sqrt(1 - x_end * x_end);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x += h;
    }

    return sign * y;
}

double arccos(double x) {
    return ((PI / 2) - arcsin(x));
}
