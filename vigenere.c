#include <stdio.h> // printf();
#include <cs50.h> // get_char();
#include <string.h> // strlen();
#include <ctype.h> // isalpha(); isupper(); islower(); toupper(); tolower();
#define N 26 // alphabet length

// encrypting messages using Vigenere’s cipher
// the first argument is keyword
int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("keyword needed\n");
        return 1;
    }
    // iterate over characters in argv[1]
    for (int j = 0, n = strlen(argv[1]); j < n; j++)
    {
        // check if character non-alphabetical
        if (isalpha(argv[1][j]) == false)
        {
            printf("alphabetical keyword needed\n");
            return 1;
        }
    }
    
    printf("plaintext: ");
    // getting plaintext array from user
    string s = get_string();
    printf("ciphertext: ");
    // iterate over characters in plaintext
    for (int i = 0, j = 0, n = strlen(s), m = strlen(argv[1]); i < n; i++)
    {
        // check if character alphabetical
        if (isalpha(s[i]))
        {
            // check if character uppercase
            if (isupper(s[i]))
            {
                // print uppercase character encrypted using current key
                printf("%c", 'A' + (s[i] + toupper(argv[1][j]) - 2*'A') % N);
            }
            // otherwise character is lowercase
            else
            {
                // print lowercase character encrypted using current key
                printf("%c", 'a' + (s[i] + tolower(argv[1][j]) - 2*'a') % N);
            }
            // shift to the next key
            j = (j + 1) % m;
        }
        // otherwise a character is non-alphabetical
        else
        {
            // print a character unchanged
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}
