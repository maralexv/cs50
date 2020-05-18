// Takes a string as an input and returns readibility index
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    long l = 0;
    long w = 0;
    long s = 0;
    // Prompt user for a string
    string text = get_string("Text: ");
    // Count the number of sentences, words and letters in the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
        }
        else if (text[i] == 32)
        {
            w++;
        }
        else if (isalpha(text[i]))
        {
            l++;
        }
    }
    // Add 1 to the count of words since there is no space at the end of string
    w++;
    // Calculate number of latters and numbert of sentences per 100 words
    float al = l * 100 / w;
    float as = s * 100 / w;
    // Calculate Coleman-Liau index
    float index = 0.0588 * al - 0.296 * as - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index > 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade: %0.0f", index);
    }

    printf("\n");
    return index;
}