//Practical-9 Implementation and Time analysis of 0/1 Knapsack Problem using Dynamic Programming.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int v[165][165];
int knsap(int W,int n,int Wi[],int Vi[]){
    int i,j;
    for(i=0;i<=n;i++){
        v[i][0]=0;
    }
    for(i=1;i<=W;i++){
        v[0][i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=W;j++){
            if(j-Wi[i]<0){
                v[i][j]=v[i-1][j];
            }
            else{
                if(v[i-1][j]>Vi[i]+v[i][j-Wi[i]]){
                    v[i][j]=v[i-1][j];
		}
		else{
		    v[i][j]=Vi[i]+v[i][j-Wi[i]];
		}
	    }
	}
    }
    return v[n][W];
}
int main(){
    int W,knsap_value;
    int n,i,j,z;
    int Vi[165],Wi[165];
    int x,ch;
    clock_t starttime,endtime;
	FILE *wr=fopen("C:\\TURBOC3\\BIN\\project\\knasp_output.txt","w");
	FILE *fp=fopen("C:\\TURBOC3\\BIN\\project\\knasp_input.txt","r");
   //clrscr();
    printf("Code by utsav vachhani(uv)");
    printf("\nCode of 0/1 Knapsack Problem using Dynamic Programming");
    printf("\nMax size of all data are 165");
    printf("\nWhat is the Capcity Of Weight : ");
    scanf("%d",&W);
    if(W>165){
	printf("Data size is highr then 165!!");
	return 0;
    }
    printf("Enter the value of n :");
    scanf("%d",&n);
    if(n>165){
	printf("Data size is highr then 165!!");
	return 0;
    }

	i=1,j=1,z=1,x=0;
	ch=getc(fp);
	while(ch!=EOF){
		if(ch>=48 && ch<=57){
				x=(x*10)+(ch-48);
		}
		else if(x!=0) {
			i++;
			if((i-1)%2!=0){
		j++;
		Wi[j-1]=x;
	    }
	    else{
		z++;
		Vi[z-1]=x;
	    }
	    x=0;
			if(i==n*2+1){
				break;
			}
		}
		ch=getc(fp);
	}
	if(ch==EOF){
		i++;
		Wi[i-1]=x;
	}

	printf("\nValues are copy Sucessful from knasp_input.txt \n");

    starttime=clock();
    knsap_value=knsap(W,n,Wi,Vi);
	endtime=clock();

    printf("Array of v[][] is \n");
     for(i=1;i<=n;i++){
		 	fprintf(wr,"\n%d |\t%d |\t",Wi[i],Vi[i]);
	    	//printf("\n%d |\t%d |",Wi[i],Vi[i]);
	    for(j=1;j<=W;j++){
			fprintf(wr,"%d\t",v[i][j]);
	    	//printf("%d\t",v[i][j]);
	    }
    }

    printf("\n\nOutput array v[][] is write successfully in knasp_output.txt ");
    printf("\n\nknasp_Value is %d",knsap_value);

    printf("\n\nTime=%f\n",(endtime-starttime)/CLK_TCK);
    fclose(fp);
    fclose(wr);
    return 0;
}