// Encrypts messages using Caesar’s cipher
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string cipher(string txt, int k, int pl);

int main(int argc, string argv[])
{
    // Check whether user provided encription key
    if (argc < 2)
    {
        printf("./caesar key\n");
        return 1;
    }
    int key = atol(argv[1]);
    // Get user input
    string plaintext = get_string("plaintext: ");
    int plaintext_len = strlen(plaintext);
    // Ecript user input
    string ciphertext = cipher(plaintext, key, plaintext_len);
    // Output encripted (ciphered) text
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Encript string passed to the function
string cipher(string txt, int k, int pl)
{
    for (int i = 0; i < pl; i++)
    {
        if (isalpha(txt[i]) && isupper(txt[i]))
        {
            txt[i] = (txt[i] - 65 + k) % 26 + 65;
        }
        else if (isalpha(txt[i]) && islower(txt[i]))
        {
            txt[i] = (txt[i] - 97 + k) % 26 + 97;
        }
    }
    return txt;
}