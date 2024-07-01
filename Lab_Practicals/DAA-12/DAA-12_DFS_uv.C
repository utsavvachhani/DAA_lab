//making of graph
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int visited[150];
int DFS_output[150],z=0;
void DFS(int i,int Node,int a[165][165]){
		int j;
		DFS_output[z]=i;
		z++;
		printf("%d ",i);
		visited[i]=1;
		for(j=0;j<Node;j++)
		{
			if(a[i][j]==1 && !visited[j])
			{
				DFS(j,Node,a);
			}
		}
	}

int main(){
	int a[165][165];
	int i,j,n=150,Node;
	int ch,x;
	clock_t starttime,endtime;
	FILE *rd=fopen("graph.txt","r");
	FILE *wr=fopen("graphinput.txt","w");
	FILE *ou=fopen("DFS.txt","w");

	printf("Code bu utsav vachhani(uv)");
	printf("\nthis is Program of Death First Search(DFS) using Dynamially taken Value from txt file.");
	printf("\nHow many node in your Graph (Max size of node is 150):");
	scanf("%d",&Node);
	if(Node<=150){
	n=Node;
	i=0,j=0;
	ch=getc(rd);
	while(ch!=EOF){
	//printf("%d",ch);
		x=ch;
		if(x==48 || x==49){
			a[i][j]=x-48;
			//i++;
			j++;
		}
		if(ch==10){
			j=0;
			i++;
		}
		if(i==n){
			//printf("Break the loop");
			break;
		}
		ch=getc(rd);
	}
	printf("\nData are read!!!");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fprintf(wr,"%d ",a[i][j]);
		}
		fprintf(wr,"\t--%d\n",i);
	}
	/*For printing the array.
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	} */
	/*for(i=n;i<Node;i++){
		for(j=n;j<Node;j++){
			a[i][j]=0;
		}
	} */
	printf("\nData are write Successfully ! \nyour taken data of graph in graphinp.txt");
	for(i=0;i<Node;i++){
			visited[i]=0;
	}
	printf("\n\nDFS is \n");
	starttime=clock();
	DFS(1,Node,a);
	endtime=clock();
	for(i=0;i<z;i++){
		fprintf(ou,"%d-->",DFS_output[i]);
		if(i%10==0){
			fprintf(ou,"\n");
		}
	}
	printf("\n\nYour Output of data store in DFS_uv.txt");
	printf("\ntime=%f",(endtime-starttime)/CLOCKS_PER_SEC);	}
	else{
		printf("Your Entering data is Larger then Given number of Node.");
	}
	fclose(ou);
	fclose(wr);
	fclose(rd);
	return 0;
}