// Sample program using segfault-preventor.h (if you couldn't tell already)
#include "segfault_preventor.h"
#include <stdio.h>

int main() {
    prevent_segfaults();
    // Oh noes D:
    int* ptr = 0;
    printf("%d", *ptr);
    return 0;
}
