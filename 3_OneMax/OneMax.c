#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MODEL_NUMBER 10
#define DNA_LEN 5
#define GENERATION 40
#define MUTATION 15
#define ADAPTIVE (pow(2, DNA_LEN) - 1)

bool GA[MODEL_NUMBER][DNA_LEN];
float GA_fitness_Array[MODEL_NUMBER];

int Dec_to_Bin(bool a[DNA_LEN])
{
    int b = 0;
    for (int i = 0; i < DNA_LEN; i++)
        b += (a[i] * pow(2, i));

    return b;
}

void Sort()
{
    for (int i = 0; i < MODEL_NUMBER; i++) {
        for (int j = MODEL_NUMBER - 1; j > i; j--) {
            if (GA_fitness_Array[j] < GA_fitness_Array[j - 1]) {
                float tmp_0 = GA_fitness_Array[j];
                GA_fitness_Array[j] = GA_fitness_Array[j - 1];
                GA_fitness_Array[j - 1] = tmp_0;

                bool tmp_1[DNA_LEN];
                for (int n = 0; n < DNA_LEN; n++) {
                    tmp_1[n] = GA[j][n];
                    GA[j][n] = GA[j - 1][n];
                    GA[j - 1][n] = tmp_1[n];
                }
            }
        }
    }

    return;
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < MODEL_NUMBER; i++)
        for (int j = 0; j < DNA_LEN; j++)
            GA[i][j] = rand() % 2;
    for (int i = 0; i < GENERATION; i++) {
        for (int i = 0; i < MODEL_NUMBER; i++) {
            GA_fitness_Array[i] = (float)Dec_to_Bin(GA[i]) / ADAPTIVE;
        }

        Sort();

        for (int i = 0; i < 2; i++) {
            bool _A = rand() % 2;
            bool _B = rand() % 2;

            bool a[DNA_LEN];
            bool b[DNA_LEN];
            for (int i = 0; i < DNA_LEN; i++) {
                a[i] = GA[MODEL_NUMBER - 1 - _A][i];
                b[i] = GA[MODEL_NUMBER - 1 - _B][i];
            }

            if (rand() % MUTATION == 1) {
                int rand_1 = rand() % DNA_LEN;
                int rand_2 = rand() % DNA_LEN;

                a[rand_1] = !a[rand_1];
                b[rand_2] = !b[rand_2];
            }

            int a_position = rand() % DNA_LEN - (DNA_LEN / 2);
            int b_position = rand() % DNA_LEN / 2;

            bool tmp[DNA_LEN];
            for (int i = 0; i < a_position; i++) {
                tmp[i] = a[i];
            }
            for (int i = 0; i < a_position; i++) {
                a[i] = b[b_position - i];
            }
            for (int i = 0; i < a_position; i++) {
                b[b_position - i] = tmp[i];
            }

            for (int n = 0; n < 5; n++) {
                GA[_A][n] = a[n];
                GA[_B][n] = b[n];
            }
        }

        float f = 0;
        printf("Generation:%d ", i);
        for (int i = 0; i < MODEL_NUMBER; i++) {
            printf("%f ", GA_fitness_Array[i]);
            f += GA_fitness_Array[i];
        }
        printf("Avg:%f \n", f / MODEL_NUMBER);
    }
}