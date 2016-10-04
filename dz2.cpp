#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <assert.h>

#define MAX_SIZE 100

float **get_matrix(const char *name_file) {
    FILE *TextFile;
    TextFile = fopen(name_file, "r");
    
    assert(TextFile != NULL);
    
    char str[MAX_SIZE];
    
    int line = 0;
    int column = 0;
    
    int i = 0;
    while (i < 2 && fgets(str, MAX_SIZE, TextFile) ) {
        if(i == 0) {
            line =  atoi(&str[0]);
        }
        else {
            column =  atoi(&str[0]);
        }
        i++;
    }
    
    float **matrix = (float**) malloc(line * sizeof(float*));
    for (i = 0; i < line; i++) {
        matrix[i] = (float*) malloc(column * sizeof(float));
    }
    

    i = 0;
    while (fgets(str, MAX_SIZE, TextFile)) {
        char *current_number = strtok(str, " ");
        int j = 0;
        while (current_number != NULL) {
            matrix[i][j] = atof(current_number);
            current_number = strtok(NULL, " ");
            j++;
        }
        i++;
    }
    
    return matrix;
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Rus");
    
    if(argc < 3) {
        printf("Вы забыли ввести матрицу. \n");
        return 0;
    }
    
    float **matrix1 = get_matrix(argv[1]);
    float **matrix2 = get_matrix(argv[2]);
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%5f ", matrix1[i][j]);
        }
        printf("\n");
        free(matrix1[i]);
    }
    free(matrix1);
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%5f ", matrix2[i][j]);
        }
        printf("\n");
        free(matrix2[i]);
    }
    free(matrix2);

    return 0;
}
