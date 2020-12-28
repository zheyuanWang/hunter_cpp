void Conv2(int** filter, int** arr, int** res, int filterW, int filterH, int arrW, int arrH)  
{  
    int temp;  

    for (int i=0; i<filterH+arrH-1; i++)  //尺寸确定
    {  
        for (int j=0; j<filterW+arrW-1; j++)  
        {  
            temp = 0;  
            for (int m=0; m<filterH; m++)  
            {  
                for (int n=0; n<filterW; n++)  
                {  
                    if ((i-m)>=0 && (i-m)<arrH && (j-n)>=0 && (j-n)<arrW)  //防止出界
                    {  
                        temp += filter[m][n]*arr[i-m][j-n];  
                    }  
                }  
            }  
            res[i][j] = temp;  
        }  
    }  
} 