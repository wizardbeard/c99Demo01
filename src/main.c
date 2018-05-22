#include <stdio.h>
#include <stdint.h>
#include "pkg/user/user.c"


/**
 * This will be called from inside another function.
 */
void some_other_work() {
    printf("It's just me; doing some other work...\n");
}

/**
 * Let's demonstrate some inline x86 ASM.  Why?  Why not? =)
 * Cf. https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html#Extended-Asm
 */
void inline_demo() {
    uint64_t msr;

    // Let's dip into x86 assembler:
    asm volatile (
    "rdtsc\n\t"             // Returns the time in EDX:EAX.
    "shl $32, %%rdx\n\t"    // Shift the upper bits left.
    "or %%rdx, %0"          // 'Or' in the lower bits.
    : "=a" (msr)
    :
    : "rdx");

    printf("msr: %llx\n", msr);

    // Do other work...
    some_other_work();

    // Reprint the timestamp
    asm volatile (
    "rdtsc\n\t"             // Returns the time in EDX:EAX.
    "shl $32, %%rdx\n\t"    // Shift the upper bits left.
    "or %%rdx, %0"          // 'Or' in the lower bits.
    : "=a" (msr)
    :
    : "rdx");

    printf("msr: %llx\n", msr);
}

/**
 * A simple application that greets the world and initializes a User struct.
 *
 * @return
 */
int main() {
    printf("Hello, World!\n");

    // Initialize a User struct
    User myUser = {
            .id = 0,
            .name = "Suzy Programmer"
    };

    printf("myUser.id=%d\n", myUser.id);
    printf("myUser.name=%s\n", myUser.name);

    if (myUser.name == "Suzy Programmer") {
        printf("Hello, %s!\n", myUser.name);
    }

    // Let's call some inline assembly.
    inline_demo();

    return 0;
}