#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int BucketSort(int data[],int num_data){
    int bucket[10][2950];
    int bucket_index[10]={0};
    int i,index_b,key,k,j;

    for(i=0;i<num_data;i++){
        index_b=data[i]/10;
        bucket[index_b][bucket_index[index_b]]=data[i];
        bucket_index[index_b]++;   
        if(bucket_index[index_b]==2950){
            printf("Index is higher then in %d",index_b);
            break;
        }
    }

    for (i = 0; i < 10; i++) {
        for (j = 1; j < bucket_index[i]; j++) {
            key = bucket[i][j];
            k = j - 1;
            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = key;
        }
    }

    k = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < bucket_index[i]; j++) {
            data[k] = bucket[i][j];
            k++;
        }
    }

    return 0;
}
int main(){
    int num_data,data[15000]={12300,23406,30875,13654,16328,19324,06325,23498,30000,20461},num_baket=100;
    FILE *rd;
    int i,j;
    clock_t starttime,endtime;
    //clrscr();
    printf("code by utsav vachhani(uv)");
    printf("\nThis code of Sorting data using Bucket Sort. ");
    printf("\nHow many data in your Practical(Max size os 15000) : ");
    scanf("%d",&num_data);
    if(num_data>15000){
        printf("Your data is hoghr then 15000.");
        return 0;
    }


    i=0,j=1;
    rd=fopen("bucket_input.txt","w");
    while(i!=num_data){
        if(i<=10){
            data[i]=data[i]%num_baket;
        }
            data[i+10]=(data[i]+9)%num_baket;
        fprintf(rd,"%d\t",data[i]);
        i++;
        if(i%10==0){
            fprintf(rd,"\t--%d\n",j);
            j++;
        }
    }
    printf("\nData are Writte successfully in bucket_intput.txt");

    starttime=clock();
    BucketSort(data,num_data);
    endtime=clock();
    printf("\nData are sorted!!1");
    
    rd=fopen("bucket_output.txt","w");
    i=0,j=0;
    while(i!=num_data){
        fprintf(rd,"%d\t",data[i]);
        //printf("%d\t",data[i]);
        i++;
        if(i%10==0){
            fprintf(rd,"\t--%d\n",j);
           // printf("\t--%d\n",j);
            j++;
        }
    }

    printf("\nSorted Data are Writte successfully in bucket_output.txt");
    printf("\n\nTime=%f\n",(endtime-starttime)/CLOCKS_PER_SEC);

    return 0;
}