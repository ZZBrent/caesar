#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2) {
        printf("That input was incorrect!  Please rerun and try again.");
        return 1;
    }
    int a = atoi(argv[1]);
    printf("plaintext: ");
    char * message = get_string();
    char encryptedMessage[10];
    while(strlen(message) > 0) {
        if(strncmp(&message[0], " ", 1) == 0) {
            strcat(encryptedMessage, " ");
            message = message+1;
        }
        else {
            int length = strlen(encryptedMessage);

            int n = -1;

            if (message[0] >= 'A' && message[0] <= 'Z') {
                static const char * const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                char *p = strchr(alphabet, message[0]);

                if (p)
                {
                    n = p - alphabet;
                }

                n = (n+a)%26;
                encryptedMessage[length] = alphabet[n];
            }
            else if (message[0] >= 'a' && message[0] <= 'z') {
                static const char * const alphabet = "abcdefghijklmnopqrstuvwxyz";
                char *p = strchr(alphabet, message[0]);

                if (p)
                {
                    n = p - alphabet;
                }

                n = (n+a)%26;
                encryptedMessage[length] = alphabet[n];
            }


            encryptedMessage[length+1] = '\0';
            message = message+1;
        }
    }
    printf("ciphertext: %s\n", encryptedMessage);
    return 0;
}