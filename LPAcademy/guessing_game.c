#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int guess, tries = 5;

    // Generating random number
    time_t t;
    srand((unsigned) time(&t));
    int randomNumber = rand() % 21;

    //Game starting output
    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20 which you must guess.\n");

    while (tries != 0) {
        printf("You have %d tr%s left.\n", tries, tries == 1 ? "y" : "ies");
        printf("Enter a guess: ");
        scanf("%d", &guess);

        if (guess < 0 || guess > 20) {
            printf("Invalid Guess.\n");
        } else if (guess < randomNumber) {
            printf("Sorry, %d is wrong. My number is greater than that.\n", guess);
        } else if (guess > randomNumber) {
            printf("Sorry, %d is wrong. My number is less than that.\n", guess);
        } else {
            printf("\nCongratulations. You guessed it!");
            return 0;
        }

        printf("\n");
        tries--;

    } 

    printf("\nYou had 5 tries. You failed.\n");
    return 0;
}