#include"function_bywk.h"

int sum_bywk(int num1, int num2){
    int sum = num1 + num2;
    return sum;
}

void pointer(int *point1, int*point2){
    cout << "指针1： " << *point1 << "  指针2： "<< *point2 << endl;
    return ;
}
void bubbleSort(int *arr, int length){
    for(int i=0; i < length - 1 ; i++){
        for(int j=0; j < length - 1 - i; j++){
            // swap(j, j+1)
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        
    }
}