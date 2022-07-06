#include <cstdlib>
#include <cstdio>
#include <cctype>

// When testing: Realize that "Enter" puts a newline character that gets read as well but you don't see it

int main() {
    int bytesCounter = 0;
    int wordsCounter = 0;
    int linesCounter = 0;
    int previosWordFlag = 0; // if there was a previous word before encountering the current word. A word is defined as a character(or a serious of characters) with whitespace around it
    int spaceFlag = 0; // if the last read character is a space character
    int input = fgetc(stdin);
    while (input != EOF) {
        input = fgetc(stdin);
        if (input == 10) {
            linesCounter++;
        }
        if (isspace(input) && spaceFlag == 0) {
            spaceFlag = 1;
            if (previosWordFlag) {
                wordsCounter++;
            }
        } else if (spaceFlag == 1 && isspace(input)) {
            spaceFlag = 0;
            previosWordFlag = 1;
        }
        bytesCounter++;
    }
    fprintf(stdout, "%d %d %d", linesCounter, wordsCounter, bytesCounter);
    exit(0);
}