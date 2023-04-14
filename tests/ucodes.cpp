#include <cstdio>
#include "ucenv.h"

extern "C" {

void c_init(int val, OutputDF &df) {
        df.setValue(val);
        printf("c_init: %d, size: %d\n", val, (int)df.getSize());
}

void c_print(InputDF& i) {
        printf("%d\n", i.getValue<int>());
}

void c_func(int val, double d, OutputDF &df, InputDF& i) {
        printf("c_func\n"); 
        df.setValue(val);
}

void c_func1(int val, double d, OutputDF &df, InputDF& i) {
        printf("c_func1\n"); 
        df.setValue(val);
}

}

