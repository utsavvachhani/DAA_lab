#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int m[165][165]={0},s[165][165]={0};
int MATRIX_CHAIN_TABLE(int p[],int n){
    int i,l,j,k,q;
    for(i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            m[i][j]=150000;
            for(k=i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                //printf("(%d,%d)=%d",i,k,q);
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                    //printf("%d\t",m[i][j]);
                }
            }
        }
    }
    return 0;
}
int main(){
    int n;
    int p[165];
    int ch,x,i,j;
    FILE *fp;
    clock_t starttime,endtime;
    printf("Code by utsav vachhani(uv)");
    printf("\nChained Matrix Multiplication using dynamic programming.");
    printf("\nHowmany matrix in your Problem : ");
    scanf("%d",&n);
    if(n>=165){
        printf("Data size is higher then 165.");
        return 0;
    }
    fp=fopen("11_data.txt","r");
    i=0,x=0;
    ch=getc(fp);
    while(ch!=EOF){
        //printf("%d ",ch);
        if(ch>=48 && ch<=57){
            x=(x*10)+(ch-48);
        }
        else if(x!=0){
            p[i]=x;
            x=0;
            i++;
            if(i==n+2){
                break;
            }
        }
        ch=getc(fp);
    }
    if(ch==EOF){
        p[i]=x;
    }
    printf("\nRanges are \n");
    for(i=0;i<n;i++){
        printf("%d\t%d\n",p[i],p[i+1]);
    }
    starttime=clock();
    MATRIX_CHAIN_TABLE(p,n);
    endtime=clock();
    
    fp=fopen("11_output.txt","w");
    printf("\n\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            fprintf(fp,"%d[%d]\t",m[i][j],s[i][j]);
            printf("%d[%d]\t",m[i][j],s[i][j]);
        }
        fprintf(fp,"\n");
        printf("\n");
    }
    printf("\n\n-------------------------\n|\tTime=%f\t|\n-------------------------",(endtime-starttime)/CLOCKS_PER_SEC);
    return 0;
}