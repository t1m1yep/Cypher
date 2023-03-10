#include <stdio.h>
#include <cs50.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("result.txt", "w");
    string plaintext = get_string("Enter text: ");
    string ciphertext;
    srand(time(NULL));
    int newkey = ( rand() % 91 ) + 65;
    for(int i = 0; i < strlen(plaintext); i++)
    {
            if(isupper(plaintext[i]))
            {
                ciphertext[i] = (((plaintext[i]+newkey)-65)%26)+65;
            }
            else if(islower(plaintext[i]))
            {
                ciphertext[i] = (((plaintext[i]+newkey)-97)%26)+97;
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
    }
    fprintf(fp, "text - %s key - %d", ciphertext, newkey);
    fclose(fp);
    return 0;
}