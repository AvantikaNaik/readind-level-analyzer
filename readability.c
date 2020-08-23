#include <math.h>
#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

float average_per_100(int a, int b);

int main(void)
{
    // Get text from user
    string text = get_string("Text:");

    // Initialize Variable for letters in text
    int letters = 0;

    // Loop through the chars in the string and increment letters if it is a valid letter
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    // Initialize variable for words in text
    int words = 1;

    // Loop through chars in string looking for space symbol and incrementing words for each
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }

    // Initializes variables to count sentences
    int sentences = 0;
    
    // Counts number of endin puncutation by incrementing sentences for each mention

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            sentences++;
        }

    }

    // Prep L and S for sentences
    
    float L = average_per_100(letters, words);
    float S = average_per_100(sentences, words);
    
    //Coleman - Liau index
    float index = (0.0588 * L - 0.296 * S - 15.8);
    
    int grade = (int) round(index);
    
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");

    }
    else 
    {
        printf("Grade %i\n", grade);

    }
}

float average_per_100(int a, int b)
{
    float average = (float) a / b;
    float final = average * 100;
    return final;
}
