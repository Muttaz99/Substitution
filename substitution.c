#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    //checking how many arguments AND how many char in the key
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }


    for (int i = 0; i < 26; i++)
    {
        //cheking if the key is only letters
        if (argv[1][i] < 'A' && argv[1][i] > 'Z' && argv[1][i] < 'a' && argv[1][i] > 'z')
        {
            printf("invalid key (use only letters!)\n");
            return 1;
        }

        //cheking if the key has duplicate letters
        for (int j = i + 1; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j] || argv[1][i] == argv[1][j] + 32 || argv[1][i] == argv[1][j] - 32)
            {
                printf("invalid key(don't duplicate a letter)\n");
                return 1;
            }
        }
    }

    //getting users input
    string plaintext = get_string("plaintext: ");

    //making caps and small arrays
    char cap[26];
    char small[26];
    
    for (int i = 0; i < 26; i++)
    {
        if (argv[1][i] <= 'Z')
        {
            cap[i] = argv[1][i];
            small[i] = argv[1][i] + 32;
        }

        else
        {
            small[i] = argv[1][i];
            cap[i] = argv[1][i] - 32;
        }
    }

    //converting the plaintext into a ciphertext
    for (int i = 0; plaintext[i] != 0; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = cap[plaintext[i] - 'A'];
        }

        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            plaintext[i] = small[plaintext[i] - 'a'];
        }
    }

    //printing the ciphertext
    printf("ciphertext: %s\n", plaintext);
    
    return 0;
}