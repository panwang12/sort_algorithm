#include "func.h"
#include <time.h>

#define N 10

int main()
{
    int start;
    int end;
    int arr[N];
    srand(time(0));
    for(int i=0;i<N;i++){
        arr[i]=rand()% 100;
    };
    for(int i=0;i<N;i++){
        printf(" %d",arr[i]);
        
    };
    printf("\n");
    start=clock();
    //冒泡排序
    // bubble_sort(arr,N);
    //选择排序
    // selection_sort(arr,N);
    //插入排序
    // insertion_sort(arr,N);
    //希尔排序
    // shell_sort(arr,N);
    //归并
    merge_sort(arr,N);
    // merge_sort_iteration(arr,N);
    //快速
    // quick_sort(arr,N);
    // heap_sort(arr,N);
    end=clock();
    // printf("开始时间＝%lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    for(int i=0;i<N;i++){
        printf(" %d",arr[i]);
    };
    printf("\n");
    return 1;
}
