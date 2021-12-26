__kernel void loop_voyager(unsigned int size, __global double* output)
{
    unsigned int i1 = get_global_id(0);
    unsigned int i2 = get_global_id(1);
    unsigned int i3 = get_global_id(2);
	
    int const max = 10;
    double towns[10][10] = {	{0, 1, 28, 10, 40, 29, 24, 18, 44, 41},
							 {37, 0, 9, 43, 35, 26, 15, 1, 5, 18},
							 {8, 9, 0, 49, 22, 6, 1, 1, 19, 27},
							 {28, 30, 30, 0, 9, 33, 23, 18, 3, 30},
							 {39, 40, 26, 15, 0, 43, 36, 47, 46, 27},
							 {7, 23, 12, 43, 11, 0, 39, 42, 49, 49},
							 {30, 20, 14, 15, 42, 2, 0, 19, 5, 34},
							 {3, 1, 46, 14, 14, 29, 34, 0, 42, 36},
							 {24, 11, 37, 23, 23, 47, 37, 6, 0, 30},
							 {19, 37, 30, 29, 18, 8, 12, 21, 40, 0} 
						};
    
    
    double min_path = 10000;

    

    //__private int ibeg1 = (i1 * max) / size;
    //__private int iend1 = (i1 + 1) * max / size;
    


   
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
                                               
                                                if  (towns[i1][i2] + towns[i2][i3] + towns[i3][i4] +
                                                        towns[i4][i5] + towns[i5][i6] + towns[i6][i7] +
                                                        towns[i7][i8] + towns[i8][i9] + towns[i9][i10] < min_path)
                                                {
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
   
    
    

        output[i1*10*10+i2*10+i3] = min_path;
        

}