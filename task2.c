#include <stdio.h>
int main(){

FILE *fp ;
char ch;
 fp = fopen("task2test.txt","r");
 if( fp == NULL){
 	printf("file not found !");
 	return 1;
 }
   int  characters =0;
   int  words = 0;
   int   lines = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;

        // Check new line 
        if (ch == '\n' || ch == '\0')
            lines++;

        // Check words 
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }

    // Increment words and lines for last word
    if (characters > 0)
    {


        words++;
        lines++;
    }


    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);

//while((ch = fgetc(fp)) != EOF){
//	printf("%c", ch);
//}

fclose(fp);



return 0;
}