//binary search
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
int binarysearch(int arr[],int left,int right,int find){
	int mid;
	if(left<=right){
		mid=(left+right)*0.5;
			if(arr[mid]==find)
			{
				printf("Your Enter number in location is %d.",mid);
				return 0;
			}
			else if(arr[mid]<find)
			{
				binarysearch(arr,mid+1,right,find);
			}
			else
			{
				binarysearch(arr,left,mid-1,find);
			}
	}
	else
	{
		printf("Your Search number is not Founded.");
	}
	return -1;
}
void bubbleSort(int arr[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr[i]<arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void main(){
	FILE *fp=fopen("C:\\TURBOC3\\BIN\\project\\data.txt","r");
	int ch,j,x=0;
	clock_t starttime,endtime;
	int arr[5000];
	int i=0,n,find;
	FILE *uv=fopen("C:\\TURBOC3\\BIN\\project\\bininput.txt","w");
	FILE *wr=fopen("C:\\TURBOC3\\BIN\\project\\binoutput.txt","w");

	clrscr();
	printf("code bu utsav vachhani(uv)");
	printf("\nthis code is the binary search using taken value from user by '.txt' file ,");
	printf("\nYour data size is maximum 5000");
	printf("\nHow many data you went to Sort?:");
	scanf("%d",&n);
	if(n<=5000){
	ch=getc(fp);
	while(ch!=EOF){
		if(ch>=48 && ch<=57){
				x=(x*10)+(ch-48);
		}
		else{
			i++;
			arr[i-1]=x;
			x=0;
			if(i==n){
				break;
			}
		}
		ch=getc(fp);
	}
	if(ch==EOF){
		i++;
		arr[i-1]=x;
	}
	printf("\n");
	//making the input file of data
	j=0,i=1;
	while(j!=n){
	    fprintf(uv,"%d\t",arr[j]);
	    j++;
	    if(j%10==0){
		fprintf(uv,"\t---%d\n",i++);
	    }
	}
	printf("Inputing data are store in bubinput.txt");

	//callling bubblesort function
	bubbleSort(arr,n);

	//makng sorting file of data
	j=0,i=1;
	while(j!=n){
	    fprintf(wr,"%d\t",arr[j]);
	    j++;
	    if(j%10==0){
		fprintf(wr,"\t---%d\n",i++);
	    }
	}
	printf("\nOutput means sorting data store in buboutput.txt");
	printf("\nNote : last colum of input/output show the index of row.");

	printf("\n\nEnter the nember wich you find out ?  ");
	scanf("%d",&find);
	starttime=clock();
	binarysearch(arr,0,n,find);
	endtime=clock();


	printf("\n\ntime=%f",(endtime-starttime)/CLK_TCK);

	}
	else{
		printf("\n\nooooppppppssss!!!!!\nYour data is higher then 5000");
	}
	fclose(wr);
	fclose(uv);
	fclose(fp);
	getch();

}