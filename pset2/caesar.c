// Encrypts messages using Caesar’s cipher
#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(int argc, string argv[])
{
    // Get user input
    string ptext = get_string("plaintext: ");
    // Encript user input 
    string ctext;
    for (int i = 0, n = strlen(ptext); i < n; i++)
    {
        if (isalpha(ptext[i]))
        {
            ctext[i] = (ptext[i] + (int) argv[1]) % 26;
        }
        else
        {
            ctext[i]=ptext[i];
        }
    }
    // Output encripted (ciphered) text
    printf("ciphertext: %s\n", ctext); 
    return 0;
}