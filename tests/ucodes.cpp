#include <cstdio>
#include "ucenv.h"

extern "C" {

void c_init(int val, OutputDF &df) {
        df.setValue(val);
        printf("c_init: %d, size: %d\n", val, (int)df.getSize());
}
}

