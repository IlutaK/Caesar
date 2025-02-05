#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool is_digit(string s);
string caesar_cipher(string plaintext, int key);
int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Make sure every character in argv[1] is a digit
    if (!is_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt the user for plaintext input
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext using the cipher function
    string ciphertext = caesar_cipher(plaintext, key);

    // Print ciphertext
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
bool is_digit(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
// Function to apply Caesar cipher
string caesar_cipher(string plaintext, int key)
{
    int n = strlen(plaintext);
    // Iterate over each character in the plaintext
    for (int i = 0; i < n; i++)
    {
        // Check if the character is an uppercase letter
        if (isupper(plaintext[i]))
        {
            // Shift it by the key, wrapping around if necessary
            plaintext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
        // Check if the character is a lowercase letter
        else if (islower(plaintext[i]))
        {
            // Shift it by the key, wrapping around if necessary
            plaintext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
    }
    return plaintext;
}
