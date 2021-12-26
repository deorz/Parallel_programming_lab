#include <iostream>
#include<ctime>
#include <fstream>
#include <thread>
#include <future>
#include <mutex>

using namespace std;
mutex m;

#define NUM_THREADS 10


int k = NUM_THREADS;


int RangedRand(int range_min, int range_max)
{
    // Generate random numbers in the interval [range_min, range_max], inclusive.

    int r = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    return r;

}


void loop_voyager(int size, int rank, int &min_path)
{

    int const max = 10;
    int calculated_path[max];
    int most_short_path[max];
    int towns[max][max];

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

    int ibeg = (rank * max) / size;
    int iend = (rank + 1) * max / size;



    for (int i1 = ibeg; i1 < iend; i1++)
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
                                                m.lock();
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
                                                m.unlock();
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

    if (rank == 0)
    {
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
}



int main(int argc, char** argv)
{

    int const k = NUM_THREADS;
    thread* threads = new thread[k];
    setlocale(LC_ALL, "RUS");
    const int max = 10;
    int towns[max][max];
    int min_path = 10000;
    int* path = new int[k];


    float start_time = clock();

    for (int i = 0; i < k; i++)
    {
        threads[i] = thread(loop_voyager,k, i, ref(min_path));
    }
    for (int i = 0; i < k; i++)
    {
        threads[i].join();
        path[i] = min_path;

    }
    for (int i = 0; i < k; i++)
    {
        if (path[i] < min_path)
        {
            min_path = path[i];
        }

    }

    cout << "Самый короткий путь имеет длину маршрута: " << min_path << endl;

    float end_time = clock();
    float exec_time = (end_time - start_time) / 1000;


    cout << "Время выполнения программы: " << exec_time << " сек" << endl;
}