#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int direction[165][165];
int LRC[165][165];
int max_size=0;
char answer[165];
int n;
/*Note:
    1  for  left
    2  for  above
    3  for  cross
*/
int LRC_print(char y[],int i,int j){
    if(i!=-1 && j!=-1){
        if(direction[i][j]==3){
            //printf("(%d,%d)-->%c\t",i,j,y[j]);
            answer[n]=y[j];
            n++;
            LRC_print(y,i-1,j-1);
        }
        else if (direction[i][j]==2)
        {
            LRC_print(y,i-1,j);
        }
        else{
            LRC_print(y,i,j-1);
        }
    }
    return 0;
}
int LRC_function(char x[],char y[],int x_size,int y_size){
    int i,j,k;
    j=0;
    for(i=0;i<=x_size;i++){
        LRC[i][j]=0;
        direction[i][j]=0;
    }   
    i=0;
    for(j=0;j<=y_size;j++){
        LRC[i][j]=0;
        direction[i][j]=0;
    } 

    printf("\n\n\nans is :\t");
    for(j=1;j<=y_size;j++){
        printf("%c\t",y[j]);
    }
    printf("\n----------------------------------------------------------------------------------------------");
    printf("\n");
    for(i=1;i<=x_size;i++){
        printf("%c\t|\t",x[i]);
        for(j=1;j<=y_size;j++){
            if(x[i]==y[j]){
                LRC[i][j]=LRC[i-1][j-1]+1;
                if(LRC[i][j]>max_size){
                    max_size=LRC[i][j];
                }
                direction[i][j]=3;
            }
            else{
                if(LRC[i-1][j]>=LRC[i][j-1]){
                    LRC[i][j]=LRC[i-1][j];
                    direction[i][j]=2;
                }
                else{
                    LRC[i][j]=LRC[i][j-1];
                    direction[i][j]=1;
                }
            }
            printf("%d[%d]\t",LRC[i][j],direction[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=x_size;i++){
        for(j=1;j<=y_size;j++){
            if(LRC[i][j]==max_size){
                if(direction[i][j]==3){
                    printf("\n");
                    n=0;
                    LRC_print(y,i,j);
                    printf("\nLongest Common Sub-sequence\n");
                    for(k=n+18;k>=0;k--) printf("-");
                    printf("\n|\t");
                    for(k=n-1;k>=0;k--){
                        printf("%c",answer[k]);
                    }
                    printf("\t\t|\n");
                    for(k=n+18;k>=0;k--) printf("-");
                }
            }
        }
    }
    return 0;
}
int main(){
    char x[165],y[165];
    int x_size,y_size;
    int i,j;
    int ch;
    FILE *fp;
    printf("Code by utsav vachhani(uv).");
    printf("\nthis code of Longest Common Sub-sequence problem using dynamic programming.");
    printf("\nWhat is size of sequence-1 :");
    scanf("%d",&x_size);
    if(x_size>165){
        printf("\n----------------------------------------\n|\tSize is higher then 165.\t|\n----------------------------------------");
        return 0;
    }
    printf("\nWhat is size of sequence-2 :");
    scanf("%d",&y_size);
    if(y_size>165){
        printf("\n----------------------------------------\n|\tSize is higher then 165.\t|\n----------------------------------------");
        return 0;
    }
    fp=fopen("x_LRC_input.txt","r");
    ch=getc(fp);
    i=1;
    while(ch!=EOF){
        if(ch>=65 || ch<=91 || ch>=97 || ch<=122){
            x[i]=(ch);
            i++;
            if(i==x_size+1){
                break;
            }
        }
        ch=getc(fp);
    }
    for(i=1;i<=x_size;i++){
        printf("%c",x[i]);
    }
    fp=fopen("y_LRC_input.txt","r");
    ch=getc(fp);
    i=1;
    while(ch!=EOF){
        if(ch>=65 || ch<=91 || ch>=97 || ch<=122){
            y[i]=ch;
            i++;
            if(i==y_size+1){
                break;
            }
        }
        ch=getc(fp);
    }
    printf("\nSequence y is : \n");
    for(i=1;i<=y_size;i++){
        printf("%c",y[i]);
    }

    LRC_function(x,y,x_size,y_size);
    return 0;
}