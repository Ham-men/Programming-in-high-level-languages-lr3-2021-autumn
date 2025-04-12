#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
 
#define ERROR_FILE_OPEN -3
 
 /* 
 21. Массив целых чисел записать в текстовый файл. 
 Переписать текстовый файл в бинарный. Запросить параметры для поиска. 
 Найти, сложить и вывести на экран исходные значения и результат. 
 */
void main() {
    FILE *output = NULL;
    FILE *input = NULL;
    int number=0, number2=0, res=0, i=1;
    unsigned counter;
    char line[30];
    
 	input=fopen("output.txt","a");
    output = fopen("output.bin", "wb");
    if (output == NULL) {
        printf("Error opening file");
        getch();
        exit(ERROR_FILE_OPEN);
    }
 

 for (i=0;i<4;i++)	//запись в два файла
 {
 	scanf("%s", &line);
    number=atoi(line);
    fputs (line,input);
    fputs ("\n",input);
   // fwrite(&number, sizeof(int), 1, output);
    fwrite(&number, sizeof(int), 1, output);
 }
   
 	
    fclose(output);
	fclose(input);
	
	
    
   // int number;
 
    input = fopen("output.bin", "rb");
    if (input == NULL) {
        printf("Error opening file");
        getch();
        exit(ERROR_FILE_OPEN);
    }
   
   	printf("\n vvedite col elementov = ");
   	scanf ("%d",&counter);
    
	printf("\n vvedite element dlia poiska = ");	//до какого числа будет считать
   	scanf ("%d",&number2);
   

    for (i = 0; i < counter; i++) 	//читает бинарный файл
	{		
        fread(&number, sizeof(int), 1, input);
        //printf("fr = %d\n", number);
        res+=number;
        if (number2==number)
        	break;
    }
 	printf("\n res = %d", res);
    fclose(input);
    
}
