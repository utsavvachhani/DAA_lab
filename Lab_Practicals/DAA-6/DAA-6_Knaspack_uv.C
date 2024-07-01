//DAA_pr-6_uv
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Print_data(int num_item,float Weight[],float Value[],float Ratio[],float knsp_rank[]) {
	int i;
	printf("\nWeight  \tValue     \tRatio    \tknsp_rank");
	for(i=0;i<num_item;i++){
		printf("\n%f\t%f\t%f\t%f",Weight[i],Value[i],Ratio[i],knsp_rank[i]);
	}

}
int Sorting_data(int num_item,float Weight[],float Value[],float Ratio[],float find[]){
	int i,j;
	float temp;
	for(i=0;i<num_item;i++){
		for(j=i+1;j<num_item;j++){
			if(find[i]<find[j]){
				temp=Weight[i];
				Weight[i]=Weight[j];
				Weight[j]=temp;

				temp=Value[i];
				Value[i]=Value[j];
				Value[j]=temp;

				temp=Ratio[i];
				Ratio[i]=Ratio[j];
				Ratio[j]=temp;
			}
		}
	}
	return 0;
}
int Knaspack(int num_item,float capacity,float Weight[],float Value[],float knsp_rank[]){
	float knsp_value=0.0;
	int i;
	for(i=0;i<num_item;i++){
		knsp_rank[i]=0.0;
	}

	for(i=0;i<num_item;i++){
		if(Weight[i]>capacity){
			break;
		}
		else {
			knsp_rank[i]=1.0;
			knsp_value+=Value[i];
			capacity-=Weight[i];
		}
	}
	if(i<num_item){
		knsp_rank[i]=capacity/Weight[i];
		knsp_value+=knsp_rank[i]*Value[i];
	}
	return knsp_value;
}
int main(){
	int i;
	float Weight[20];
	float Value[20];
	float Ratio[20];
	float knsp_rank[20];
	float Capacity_of_weight,knsp_value;
	int num_item;
	printf("Code by utsav vachhani(UV).\n");
	printf("This code is \n Fractional Knapsack Problem using Greedy technoque.");

	//Input the values
	printf("\nEnter the Capacity of Wight : ");
	scanf("%f",&Capacity_of_weight);
	printf("How many item in your Problem : ");
	scanf("%d",&num_item);
	for(i=0;i<num_item;i++){
		knsp_rank[i]=0.0;
	}
	for(i=0;i<num_item;i++){
		printf("Weight[%d] = \t",i);
		scanf("%f",&Weight[i]);
		printf("Value[%d] = \t",i);
		scanf("%f",&Value[i]);
		Ratio[i]=Value[i]/Weight[i];
	}

	printf("\nYour Enter data with ther Ratio.  ");
	Print_data(num_item,Weight,Value,Ratio,knsp_rank);

	printf("\nUsing ratio Decrement");
	Sorting_data(num_item,Weight,Value,Ratio,Ratio);
	printf("\n\nAfter Sorting data");
	Print_data(num_item,Weight,Value,Ratio,knsp_rank);
	knsp_value=Knaspack(num_item,Capacity_of_weight,Weight,Value,knsp_rank);
	printf("\n\nAfte use of Knspack ALgorithm.");
	Print_data(num_item,Weight,Value,Ratio,knsp_rank);
	printf("\nValue is %f",knsp_value);

	printf("\n\n");
	scanf("%d",&i);
	printf("\nUsing weight Decrement");
	Sorting_data(num_item,Weight,Value,Ratio,Weight);
	printf("\nAfter Sorting data");
	Print_data(num_item,Weight,Value,Ratio,knsp_rank);
	knsp_value=Knaspack(num_item,Capacity_of_weight,Weight,Value,knsp_rank);
	printf("\n\nAfte use of Knspack ALgorithm.");
	Print_data(num_item,Weight,Value,Ratio,knsp_rank);
	printf("\nValue is %f",knsp_value);

	printf("\n\n");
	scanf("%d",&i);
	printf("\nUsing Valueh Decrement");
	Sorting_data(num_item,Weight,Value,Ratio,Value);
	printf("\nAfter Sorting data");
	Print_data(num_item,Weight,Value,Ratio,knsp_rank);
	knsp_value=Knaspack(num_item,Capacity_of_weight,Weight,Value,knsp_rank);
	printf("\n\nAfte use of Knspack ALgorithm.");
	Print_data(num_item,Weight,Value,Ratio,knsp_rank);
	printf("\nValue is %f",knsp_value);
	return 0;
}