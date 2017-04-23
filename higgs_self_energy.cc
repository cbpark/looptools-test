#include <cstdio>
#include "clooptools.h"

const double MH2 = 126.0 * 126.0;
const double MZ2 = 91.188 * 91.188;
const double MW2 = 80.4 * 80.4;
const double ALPHA = 1 / 137.0359895;
const double PI = 3.14159265358979;
const double SW2 = 1.0 - MW2 / MZ2;

ComplexType SigmaH(const double k2) {
    return ALPHA / (32 * PI * SW2 * MW2) *
           (3 * MH2 * A0(MH2) + 9 * MH2 * MH2 * B0(k2, MH2, MH2) +
            2 * (MH2 * MH2 - 4 * MW2 * (k2 - 3 * MW2)) * B0(k2, MW2, MW2) +
            2 * (6 * MW2 + MH2) * A0(MW2) - 24 * MW2 * MW2 +
            (MH2 * MH2 - 4 * MZ2 * (k2 - 3 * MZ2)) * B0(k2, MZ2, MZ2) +
            (6 * MZ2 + MH2) * A0(MZ2) - 12 * MZ2 * MZ2);
}

int main() {
    ltini();
    for (RealType s = 100; s <= 1000; s += 50) {
        ComplexType sig = SigmaH(s);
        std::printf("%g\t%g%+gi\n", s, Re(sig), Im(sig));
    }
}
