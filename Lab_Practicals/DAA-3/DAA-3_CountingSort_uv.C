#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int CountingSort(int data[],int max_data,int num_data){
    int i,j,arr[15000];
    for(i=0;i<=max_data;i++){
        arr[i]=0;
    }
    for(i=0;i<num_data;i++){
        arr[data[i]]++;
    }

    i=0,j=0;
    while(j!=max_data+1){
        if(arr[j]==0){
            j++;
        }
        if(arr[j]!=0){
            data[i]=j;
            i++;
            arr[j]--;
        }
    }
    return 0;
}
int Max_in_data(int data[],int num_data){
    int max=data[0],i;
    for(i=1;i<num_data;i++){
	if(data[i]>max){
	    max=data[i];
	}
    }
    return max;
}
int main(){
    int num_data,max_data;
    int i,j;
    int data[15000]={0,3,5,2,4,6,8,9,10,7};
    FILE *rd;
    clock_t starttime,endtime;
    //clrscr();
    printf("Code by utsav vachhani(uv)");
    printf("\nThis code of Counting Sort.");
    printf("\nHow many data in your Problem: ");
    scanf("%d",&num_data);
    if(num_data>15000){
	printf("\nData size is Higher then 15000");
	return 0;
    }

    rd=fopen("counting_input.txt","w");
    i=0,j=0;
    while(i!=num_data){
	fprintf(rd,"%d\t",data[i]);
	data[i+9]=data[i];
	i++;
	if(i%10==0){
	    data[i]=data[i]+1;
	    fprintf(rd,"\t--%d\n",j);
	    j++;
	}
    }
    for(i=num_data;i<=num_data+5;i++){
	data[i]=0;
    }
   // fclose(rd);
    printf("\nData are successfully write in counting_input.txt");

    max_data=Max_in_data(data,num_data);
    printf("\n%d is maximum data of input",max_data);
    starttime=clock();
    CountingSort(data,max_data,num_data);
    endtime=clock();

    rd=fopen("counting_output.txt","w");
    i=0,j=0;
    while(i!=num_data){
	fprintf(rd,"%d\t",data[i]);
	i++;
	if(i%10==0){
	    fprintf(rd,"\t--%d\n",j);
	    j++;
	}
    }
    printf("\nSorted Data are successfully write in counting_output.txt");
    printf("\n\nTime=%f\n",(endtime-starttime)/CLOCKS_PER_SEC);
    fclose(rd);    
    return 0;
}