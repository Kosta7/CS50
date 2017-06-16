#include <stdio.h>		// printf();
#include <cs50.h>		// get_char();
#include <string.h>		// strlen();
#include <ctype.h>		// isalpha(); isupper(); islower(); toupper(); tolower();
#define N 26			// alphabet length

// encrypting messages using Vigenere’s cipher
// the first argument is keyword
int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("keyword needed\n");
        return 1;
    }
    for (int j = 0, n = strlen(argv[1]); j < n; j++)							// iterate over characters in argv[1]
    {
        if (isalpha(argv[1][j]) == false)	// check if character non-alphabetical
        {
            printf("alphabetical keyword needed\n");
            return 1;
        }
    }
    
    printf("plaintext: ");
    string s = get_string();				// getting plaintext array from user
    printf("ciphertext: ");
    for (int i = 0, j = 0, n = strlen(s), m = strlen(argv[1]); i < n; i++)		// iterate over characters in plaintext
    {
        if (isalpha(s[i]))					// check if character alphabetical
        {
            if (isupper(s[i]))				// check if character uppercase
            {
                printf("%c", 'A' + (s[i] + toupper(argv[1][j]) - 2*'A') % N);	// print uppercase character encrypted using current key
            }
            else							// otherwise character is lowercase
            {
                printf("%c", 'a' + (s[i] + tolower(argv[1][j]) - 2*'a') % N);	// print lowercase character encrypted using current key
            }
            j = (j + 1) % m;				// shift to the next key
        }
        else								// otherwise a character is non-alphabetical
        {
            printf("%c", s[i]);				// print a character unchanged
        }
    }
    printf("\n");
    return 0;
}
