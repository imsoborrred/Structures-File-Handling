#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;                 
    int byteValue = 0;   
    int bitCount = 0;   
    FILE *fp = fopen("bitstream.bit", "r");
    FILE *fp2 = fopen("bitstream.hex", "w");

    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    if (fp2 == NULL) {
        printf("Cannot open file bitstream.hex\n");
        fclose(fp);
        return 1;
    }

        while ((num = fgetc(fp)) != EOF) {
        if (num == '0' || num == '1') {

             int bitValue = (num - '0') << bitCount;
            byteValue = byteValue + bitValue;  
            bitCount++;

           
            if (bitCount == 8) {
                fprintf(fp2, "%02X\n", byteValue);
                bitCount = 0;     
                byteValue = 0;   
            }
        }
    }
    if (bitCount > 0) {
      fprintf(fp2, "%02X\n", byteValue);
    }

    printf("Contents copied to bitstream.hex\n");

    fclose(fp);
    fclose(fp2);

    return 0;
}
