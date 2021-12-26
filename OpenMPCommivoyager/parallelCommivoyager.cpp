#include <iostream>
#include<ctime>
#include <fstream>
#include <omp.h>
using namespace std;

int RangedRand(int range_min, int range_max)
{
    // Generate random numbers in the interval [range_min, range_max], inclusive.

    int r = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    return r;

}

const int Number_Of_Threads = 10; // 

int main()
{

    //srand(time(NULL));
    
    setlocale(LC_ALL, "RUS");

    omp_set_num_threads(Number_Of_Threads); //

    const int max = 10;
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i = 0, j = 0;
    int towns[max][max];
    int calculated_path[max];
    int most_short_path[max];
    int counter = 0;
    int min_path = 10000;
    int min_path_index;

    float start_time = clock();

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (i == j)
            {
                towns[i][j] = 0;
            }
            else
            {
                towns[i][j] = RangedRand(1, 50);
            }
        }
    }
    #pragma omp parallel for 
    for (int i1 = 0; i1 < max; i1++)
    {
        for (int i2 = 0; i2 < max; i2++)
        {
            for (int i3 = 0; i3 < max; i3++)
            {
                for (int i4 = 0; i4 < max; i4++)
                {
                    for (int i5 = 0; i5 < max; i5++)
                    {
                        for (int i6 = 0; i6 < max; i6++)
                        {
                            for (int i7 = 0; i7 < max; i7++)
                            {
                                for (int i8 = 0; i8 < max; i8++)
                                {
                                    for (int i9 = 0; i9 < max; i9++)
                                    {
                                        for (int i10 = 0; i10 < max; i10++)
                                        {
                                            if ((i1 != i2) && (i1 != i3) && (i1 != i4) && (i1 != i5) && (i1 != i6) && (i1 != i7) && (i1 != i8) && (i1 != i9) && (i1 != i10) &&
                                                (i2 != i3) && (i2 != i4) && (i2 != i5) && (i2 != i6) && (i2 != i7) && (i2 != i8) && (i2 != i9) && (i2 != i10) &&
                                                (i3 != i4) && (i3 != i5) && (i3 != i6) && (i3 != i7) && (i3 != i8) && (i3 != i9) && (i3 != i10) &&
                                                (i4 != i5) && (i4 != i6) && (i4 != i7) && (i4 != i8) && (i4 != i9) && (i4 != i10) &&
                                                (i5 != i6) && (i5 != i7) && (i5 != i8) && (i5 != i9) && (i5 != i10) &&
                                                (i6 != i7) && (i6 != i8) && (i6 != i9) && (i6 != i10) &&
                                                (i7 != i8) && (i7 != i9) && (i7 != i10) &&
                                                (i8 != i9) && (i8 != i10) &&
                                                (i9 != i10))
                                            {
                                                calculated_path[0] = i1 + 1;
                                                calculated_path[1] = i2 + 1;
                                                calculated_path[2] = i3 + 1;
                                                calculated_path[3] = i4 + 1;
                                                calculated_path[4] = i5 + 1;
                                                calculated_path[5] = i6 + 1;
                                                calculated_path[6] = i7 + 1;
                                                calculated_path[7] = i8 + 1;
                                                calculated_path[8] = i9 + 1;
                                                calculated_path[9] = i10 + 1;

                                                if (towns[i1][i2] + towns[i2][i3] + towns[i3][i4] +
                                                    towns[i4][i5] + towns[i5][i6] + towns[i6][i7] +
                                                    towns[i7][i8] + towns[i8][i9] + towns[i9][i10] < min_path)
                                                {
                                                    for (int i = 0; i < max; i++)
                                                    {
                                                        most_short_path[i] = calculated_path[i];
                                                    }
                                                    min_path = (towns[i1][i2] + towns[i2][i3] + towns[i3][i4] +
                                                        towns[i4][i5] + towns[i5][i6] + towns[i6][i7] +
                                                        towns[i7][i8] + towns[i8][i9] + towns[i9][i10]);
                                                }

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    float end_time = clock();
    float exec_time = (end_time - start_time) / 1000;


    cout << "Самый короткий путь имеет длину маршрута: " << min_path << endl;
    cout << "Время выполнения программы: " << exec_time << " сек" << endl;
    cout << "Исходные данные:" << endl;

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            cout << towns[i][j] << " ";
        }
        cout << "" << endl;
    }

}


