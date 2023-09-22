#include<stdio.h>
#include<math.h>
typedef unsigned float_bits;
/* Compute -f. If f is NaN, then return f. */
float_bits float_absval(float_bits f) {
        /* Decompose bit representation into parts */
        unsigned isNaN = !((f & 0x7F800000) ^ 0X7F800000) && (f & 0x007FFFFF);
        // Test:printf("%d\n", !((f & 0x7F800000) ^ 0x7F800000) && 1);
        // Test:printf("%d\n", (f & 0x007FFFFF) && 1);
        // Test:printf("%d\n", isNaN);
        if (isNaN) {
                return f;
        }
        else {
                return 0x00000000 | (f & 0x7FFFFFFF);
        }
}
float_bits float_absval_official(float_bits f) {
        if (isnan((float)f)) {
                return f;
        }
        else {
                return 0x00000000 | (f & 0x7FFFFFFF);
        }
}
int test() {
        for (float_bits i = 0x00000000; i <= 0xFFFFFFFF; i++) {
                if (float_absval(i) != float_absval_official(i)) {
                        printf("Error\n");
                }
                printf("%x\n", i);
        }
        return 0;
}
int main(int argc, char *argv[]) {
        test();
        return 0;
}
