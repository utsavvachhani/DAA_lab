#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int MAX_HEAPIFY(int data[],int i,int n){
    int l=i*2;
    int r=(i*2)+1;
    int larger,temp;
    if(l<=n & data[l]>data[i]){
        larger=l;
    }
    else{
        larger=i;
    }
    if(r<=n & data[r]>data[larger]){
        larger=r;
    }

    if(larger!=i){
        temp=data[i];
        data[i]=data[larger];
        data[larger]=temp;
       // printf("Swap(%d,%d)",data[i],data[larger]);
    }
    i--;
    if(i>0){
        MAX_HEAPIFY(data,i,n);
    }
    return 0;
}
int BUILD_MAX_HEAP(int data[],int n){
    int i;
    for(i=n/2;i>=1;i--){
        MAX_HEAPIFY(data,i,n);
    }
    return 0;
}
int heapsort_fun(int data[],int n){
    int i,j=1,temp;
    BUILD_MAX_HEAP(data,n);
    for(i=n;i>=2;i--){
        temp=data[1];
        data[1]=data[n];
        data[n]=temp;
        printf("%d\t",data[n]);
        j++;
        if(j%10==0){
            printf("  --%d\n",j/10);
        }
        n--;
        BUILD_MAX_HEAP(data,n);
    }
    return 0;
}
int main(){
    int number_data,data[15000]={0,4,10,3,5,1,2,9,15,20,6};
    int i,j;
    FILE *rd;
    clock_t starttime,endtime;
    printf("Code by utsav vachhani(uv).");
    printf("\nThis is code of Heap Sort.");
    printf("\nHow many data in your Problem(MAX SIZE IS 15000) :");
    scanf("%d",&number_data);
    if(number_data>=15000){
        printf("\n---------------------------------\n|Data Size is Higher then 15000.|\n---------------------------------");
        return 0;
    }
    
    j=1;
    printf("Data are :\n");
    rd=fopen("heap_input.txt","w");
    for(i=1;i<=number_data;i++){
        fprintf(rd,"%d\t",data[i]);
        printf("%d\t",data[i]);
        data[i+10]=(data[i]+9)%32000;
        if((i)%10==0){
            fprintf(rd,"--%d\n",j);
            j++;
        }
    }
    printf("\nData are write successfuly in heap_input.txt\n");
    
    printf("\nData are removed :");
    starttime=clock();
    heapsort_fun(data,number_data);
    endtime=clock();
    j=1;
    rd=fopen("heap_output.txt","w");
    for(i=1;i<=number_data;i++){
        fprintf(rd,"%d\t",data[i]);
        if((i)%10==0){
            fprintf(rd,"--%d\n",j);
            j++;
        }
    }
    printf("\nSorted Data are write successfuly in heap_output.txt");
    printf("\n\n-------------------------\n|\tTime=%f\t|\n-------------------------",(endtime-starttime)/CLK_TCK);
    return 0;
}