#include "func.h"

#define  SWAP(a,b){int tem;tem=a;a=b;b=tem;} 

int bubble_sort(int* arr,int size){
    for(int i=size-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                SWAP(arr[j],arr[j+1]);
            }
        };
    };
    return 1;
};

int selection_sort(int* arr,int size){
    int index;
    for(int i=0;i<size;i++){
        index=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[index]){
                index=j;
            };
        };
        SWAP(arr[i],arr[index]);
    };
};

int insertion_sort(int* arr,int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j]<arr[j-1]){
                SWAP(arr[j],arr[j-1]);
            }else{
                break;
            };
        };
    };
};

int shell_sort(int* arr,int size){
    for(int gap=size/2;gap>0;gap/=2){
        for(int i=0;i<size-gap;i++){
            for(int j=i+gap;j-gap>=0;j-=gap){
                if(arr[j-gap]>arr[j]){
                    SWAP(arr[j-gap],arr[j]);
                }else{
                    break;
                }
            }
        }
    };
};

void merge_sort_recursive(int * arr,int* res,int ps,int pe){
    if(ps==pe){
        return;
    };
    int mid=(pe-ps+1)>>1;
    int start1=ps;
    int end1=ps+mid-1;
    int start2=ps+mid;
    merge_sort_recursive(arr,res,start1,end1);
    merge_sort_recursive(arr,res,start2,pe);
    int i=ps;
    while(start1<=end1 && start2<=pe){
        if(arr[start1]<arr[start2]){
            res[i++]=arr[start1++];
        }else{
            res[i++]=arr[start2++];
        };
    };
    while(start1<=end1){
        res[i++]=arr[start1++];
    };
     while(start2<=pe){
        res[i++]=arr[start2++];
    };
    for (i=ps;i<=pe;i++){
      arr[i]=res[i];
    };
};



void merge_sort(int* arr,int size){
  int res[size];
  merge_sort_recursive(arr,res,0,size-1);

};

void merge_sort_iteration(int* arr, int size){
    int *beforeArray=arr;
    int *afterArray=(int*)malloc(sizeof(int)*size);
    int *afterArray2=afterArray;
    for(int seg=2;seg<size*2;seg=seg*2){
        for(int start=0;start<size;start+=seg){
            int mid=seg/2;
            int i=start;
            int start1=start;
            int end1=start+mid>size?size:start+mid;
            int start2=start+mid>size?size:start+mid;
            int end2=start+seg>size?size:start+seg;

            while(start1<end1&& start2<end2){
                if(beforeArray[start1]>beforeArray[start2]){
                    afterArray[i++]=beforeArray[start2++];
                }else{
                    afterArray[i++]=beforeArray[start1++];
                };
            };
             while(start1<end1){
                afterArray[i++]=beforeArray[start1++];
            };
             while(start2<end2){
                afterArray[i++]=beforeArray[start2++];
            };
        };
        int *temp=beforeArray;
            beforeArray=afterArray;
            afterArray=temp;
    };
    if(arr!=beforeArray){
         for(int i=0;i<size;i++){
            arr[i]=beforeArray[i];
        };
    };
   
    free(afterArray2);
};



int partition(int* arr,int left, int right){
    int storeIndex=left;
    for(int i=left; i<right;i++){
        if(arr[i]<arr[right]){
            SWAP(arr[i],arr[storeIndex]);
            storeIndex++;
        };  
    };
    SWAP(arr[right],arr[storeIndex]);
    return storeIndex;
};

//快排
void quick_sort_process(int* arr,int left, int right){
    if(right>left){
        int mid=partition(arr,left,right);
        quick_sort_process(arr,left, mid-1);
        quick_sort_process(arr,mid+1, right);
    };
};
void quick_sort(int* arr, int size){                                                                                                                                                                                                                                         
    quick_sort_process(arr,0, size-1);
};



void adjustHeap(int* arr,int i,int size){
    
    for(int k=2*i+1;k<size;k+=2*i+1){
        int k=2*i+1;
        if( k+1<size && arr[k]<arr[k+1]){
            k++;
        };
        if(arr[k]>arr[i]){
            SWAP(arr[k],arr[i]);
            i=k;
        };

    };
};


void heap_sort(int* arr,int size){
    if(size<2){
        return;
    };
    for(int i=size/2-1;i>=0;i--){
        for(int k=2*i+1;k<size;k+=2*i+1){
            int k=2*i+1;
            if( k+1<size && arr[k]<arr[k+1]){
                k++;
            };
            if(arr[k]>arr[i]){
                SWAP(arr[k],arr[i]);
                i=k;
            };

        };
    };
    
    SWAP(arr[0],arr[size-1]);

    for(int j=size-1;j>0;j--){
        adjustHeap(arr,0,j);
        SWAP(arr[0],arr[j-1]);
    }
};