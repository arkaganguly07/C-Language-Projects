/*
Write a programme that generates a random number and asks the player to guess it.
If the player's guess is higher than the actual number, the program displays "LOWER NUMBER PLEASE".
Similarly if the user's guess is too low, the programme prints "HIGHER NUMBER PLEASE".

When the user guesses the correct number, the programme displays the number of guesses the player used to arrive at the number.

HINT: 
-> Use LOOPS
-> Use a RANDOM NUMBER GENERATOR
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // The rand() & srand() function lies in the <stdlib.h> header file
    // The time() function lies in the <time.h> header file

    int number, guess;
    int num_guesses = 1;
    
    srand(time(0));
    /*
    srand()-> gives the random function a new seed, 
    a starting point (usually random numbers are calculated by taking the previous number (or the seed)
    and then do many operations on that number to generate the next).

    time(0)-> gives the time in seconds since the Unix epoch,
    which is a pretty good "unpredictable" seed (you're guaranteed your seed will be the same only once,
    unless you start your program multiple times within the same second).
    */
    
    number = rand() % 100 + 1; // Generates a number between 1 to 100
    /*
    rand()-> used to generate a series of random numbers. 
    The random number is generated by using an algorithm that gives a series of non-related numbers whenever this function is called.
    
    rand()-> gives a random number between 0 and RAND_MAX, inclusive (RAND_MAX might be something like 65536, depending on your compiler).

    rand() % 100-> then takes the remainder of this number when you divide by 100 (otherwise known as "modulus").
    In other words, it produces a number between [0, 99], inclusive.
    For example, 124 % 100 == 24, 99 % 100 == 99, 100 % 100 == 0.

    rand() % 100 + 1-> takes the previous result, and adds 1 to it, giving you an range of [1, 100], inclusive.
    */
    
    // Keep a loop running until the number is guessed
    do
    {
        printf("Guess the number between 1 to 100 \n");
        scanf("%d", &guess);

        if (guess > number)
        {
            printf("LOWER NUMBER PLEASE \n");
        }
        else if (guess < number)
        {
            printf("HIGHER NUMBER PLEASE \n");
        }
        else
        {
            printf("CORRECT NUMBER\n");
            printf("You guessed the number in %d attempts", num_guesses);
        }
        
        ++num_guesses;
        
    } while (number != guess);
    
    return 0;
}
