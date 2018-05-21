#include <stdio.h>

// Keep it clean and consistent
typedef struct User {
    int id;
    char *name;
} User;

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
            .name="Suzy Programmer"
    };

    printf("myUser.id=%d\n", myUser.id);
    printf("myUser.name=%s\n", myUser.name);

    return 0;
}