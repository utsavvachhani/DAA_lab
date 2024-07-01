#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Power_fun(int i){
    int power=10,j;
    for(j=1;j<i;j++){
        power*=10;
    }
    return power;
}
int divfun(int in){
    int i,re=1;
    for(i=1;i<in;i++){
	re*=10;
    }
    return re;
}
int RadixSort(int data[],int Num_of_Data,int index){
    int i,x,y,j,k,temp;
    for(i=1;i<=index;i++){
	x=Power_fun(i);
	y=divfun(i);
	printf("\nx=%d\ty=%d\n",x,y);
	for(j=0;j<Num_of_Data;j++){
	    for(k=0;k<Num_of_Data;k++){
		//printf("(%d,%d)",(data[j]%x)/y,(data[k]%x)/y);
		if((data[k]%x)/y>(data[k+1]%x)/y){
		    //if(k>j){
		    //printf("swap(%d,%d)",data[j],data[k]);
		    temp=data[k];
		    data[k]=data[k+1];
		    data[k+1]=temp;
		    //}
		}
	    }
	}
    }
    return 0;
}
int main(){
    int Num_of_Data,index,Diff=9;
    int data[15000]={12345,23006,23020,17895,31452};
    int i,power,j;
    FILE *rd;
    clock_t starttime,endtime;
    
    printf("\nCode by utsav vachhani(uv)\n");
    printf("This code of Radix Sort.");
    printf("How Many number is Your data (Max Size of Data is 15000): ");
    scanf("%d",&Num_of_Data);
    if(Num_of_Data>15000){
        printf("\nData Size is Larger then 15000");
        return 0;
    }
    printf("\nWhat is the Lenth Of data. \n(Like 1500=4 or 123=3) \nNote: Max size of index is 5. \n");
    scanf("%d",&index);
    if(index>5){
        printf("\nIndex is Higher then 5.");    
        return 0;
    }

    power=Power_fun(index);
    for(i=0;i<5;i++){
        data[i]=data[i]%power;
    }

    rd=fopen("radix_input.txt","w");
    i=0,j=1;
    while(i!=Num_of_Data){
        fprintf(rd,"%d\t",data[i]);
        data[i+5]=(data[i]+Diff)%power;
        i++;
        if(i%10==0){
            fprintf(rd,"\t--%d\n",j);
            j++;
        }
    }
    printf("\nData are successfully write in radix_input.txt");

    starttime=clock();
    RadixSort(data,Num_of_Data,index);
    endtime=clock();

    rd=fopen("radix_output.txt","w");
    i=0,j=1;
    while(i!=Num_of_Data){
        fprintf(rd,"%d\t",data[i]);
        i++;
        if(i%10==0){
            fprintf(rd,"\t--%d\n",j);
            j++;
        }
    }
    printf("\nSorted Data are successfully write in radix_output.txt");
    printf("\n\nTime=%f\n",(endtime-starttime)/CLOCKS_PER_SEC);
    return 0;
}