#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Rus");
    
    if(argc < 3)
    {
        printf("Вы забыли ввести матрицу. \n");
        return 0;
    }
    
    const char *mat1 = argv[1];
    printf("Искомое слово: %s\n", mat1);
    
    FILE *TextFile;
    TextFile = fopen(argv[1], "r");
    
    if (TextFile == NULL)
    {
        printf("Файл не существует\n");
        return 0;
    }
    
    const int max_size = 100;
    char str[max_size];
    
    int line = 0;
    int row = 0;
    
    int i = 0;
    while (i < 2 && fgets(str, max_size, TextFile) ) {
        if(i == 0) {
            line =  atoi(&str[0]);
        }
        else {
            row =  atoi(&str[0]);
        }
        i++;
    }
    
    printf("Искомое слово: %i\n", line);
    printf("Искомое слово: %i\n", row);
    
    float array[line][row];
    i = 0;
    while (fgets(str, max_size, TextFile)) {
        puts(str);

        char *pch = strtok(str, " ");
        int j = 0;
        while (pch != NULL)
        {
            array[i][j] = atof(pch);
            pch = strtok(NULL, " ");
            j++;
        }
        i++;
    }
    return 0;
}
