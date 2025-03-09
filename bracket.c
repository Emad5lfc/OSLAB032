#include "types.h"
#include "user.h"
#include "fcntl.h"

int checkBrackets(char *str) {
    int count = 0;
    while (*str) {
        if (*str == '{') 
        count++;
        else if (*str == '}') {
            if (count == 0) 
            return 0;
            count--;
        }
        str++;
    }
    return count == 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf(1, "Usage: app_name \"{string}\"\n");
        exit();
    }

    int fd = open("result.txt", O_CREATE | O_WRONLY);
    if (fd < 0) {
        printf(1, "Error: Cannot open result.txt\n");
        exit();
    }

    if (checkBrackets(argv[1])) {
        write(fd, "Right\n", 6);
    } else {
        write(fd, "Wrong\n", 6);
    }

    close(fd);
    exit();
}