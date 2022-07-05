#include <cstdlib>
#include <cstdio>

// When testing: Realize that "Enter" puts a newline character that gets read as well but you don't see it

int main() {
    int numberOfBytes = 0;
    int input = fgetc(stdin);
    while (input != EOF) {
        input = fgetc(stdin);
        numberOfBytes++;
    }
    fprintf(stdout, "%d", numberOfBytes);
    exit(0);
}