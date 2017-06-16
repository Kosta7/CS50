/* command:
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow {name.c} -lcrypt -lcs50 -lm -o {name}
*/

#define _XOPEN_SOURCE // for crypt function
#include <unistd.h> // for crypt function

#include <stdio.h> // printf();
#include <cs50.h> // for string variables
#include <math.h> // pow();

#define N 26 // latin alphabet length
#define M 4 // max password length

void word_forming (int x, int m, char s[]);
char num_to_char(int k);

// cracks up-to-4-alphabetical-characters passwords using DES-based algorithm
int main (int argc, string argv[])
{
    if (argc != 2) // checking if there're only two arguments
    {
        printf("correct password required\n");
        return 1;
    }
    
    // creating the list of all possible characters in passwords
    char alph[2 * N];
    for (int i = 0; i < N; i++)
    {
        alph[i] = 'A' + i;
    }
    for (int i = N; i < 2 * N; i++)
    {
        alph[i] = 'a' + i - N;
    }
    
    bool equal;                                 // true if the given hashed password is equal to an element in a following enumeration
    string hashed;                              // string where hashed passwords will be placed in
    for (int length = 1; length <= M; length++) // length is the length of the enumerated passwords
    {
        int total_num = pow(2 * N, length);     // total_num is the total number of enumerated passwords of a certain length
        char word[length];                      // array where enumerated passwords will be placed in
        for (int x = 0; x < total_num; x++)     // word[x] is a x'th character of an enumerated password
        {
            word_forming(x, length - 1, word);  // calling a function that forms a password
            hashed = crypt(word, "50");
            equal = true;
            for (int j = 0; j < 13; j++)        // enumerating characters of the formed password
            {
                if (hashed[j] != argv[1][j])    // checking if the selected character of the hashed formed password is equal to the hashed password given from the function argument
                {
                    equal = false;
                    break;
                }
            }
            if (equal == true)
            {
                printf("%s\n", word);           // printing the actual password

                return 0;                       // quitting the main function
            }
        }
    }
    printf("something went wrong\n");           // (just in case)
}

// this recursive function translates numbers from the decimal numeral system (variable x) to the [A..z] numeral system (variable s)
void word_forming (int x, int m, char s[])
{
    if (m >= 0)
    {
        s[m] = num_to_char(x % (2 * N));        // writing the appropriate character into the m'th position of the array s
        word_forming (x / (2 * N), m - 1, s);
    }
}

// translates a number to an alphabetical character
char num_to_char(int k)
{
    if (k < N)
    {
        return 'A' + k;
    }
    else
    {
        return 'a' + k - N;
    }
}
