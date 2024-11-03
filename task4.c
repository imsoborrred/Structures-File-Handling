#include <stdio.h>
#include <ctype.h>

void decrypt(char text[]);
void encrypt(char text[]);

int main() {
    char text[500];
    char choice;
    char data;

    printf("Do you want to perform (E)ncryption or (D)ecryption? ");
    scanf(" %c", &choice);
    printf("Do you want to encrypt data from a (F)ile or enter a (S)tring? ");
    scanf(" %c", &data);

    if ((choice == 'E' || choice == 'D') && (data == 'S' || data == 'F')) {
        if (data == 'S') {
            printf("Please enter text: ");
            scanf(" %499[^\n]", text);
        } else if (data == 'F') {
            char filename[100];
            printf("Please enter the filename: ");
            scanf(" %99s", filename);

            
            FILE *file = fopen(filename, "r");
            if (file == NULL) {
                printf("Error: Could not open file %s\n", filename);
                return 1;
            }

    
            if (fgets(text, sizeof(text), file) == NULL) {
                printf("Error: Could not read from file %s\n", filename);
                fclose(file);
                return 1;
            }
            fclose(file);
        }

        if (choice == 'E') {
            encrypt(text);
            printf("Encrypted text: %s\n", text);
        } else if (choice == 'D') {
            decrypt(text);
            printf("Decrypted text: %s\n", text);
        }
    } else {
        printf("Invalid choice or data input.\n");
    }

    return 0;
}

void encrypt(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (islower(ch)) {
            ch = (ch - 'a' - 3) % 26 + 'a';
        } else if (isupper(ch)) {
            ch = (ch - 'A' - 3) % 26 + 'A';
        }
        text[i] = ch;
    }
}

void decrypt(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (islower(ch)) {
            ch = (ch - 'a' + 3 + 26) % 26 + 'a';
        } else if (isupper(ch)) {
            ch = (ch - 'A' + 3 + 26) % 26 + 'A';
        }
        text[i] = ch;
    }
}

