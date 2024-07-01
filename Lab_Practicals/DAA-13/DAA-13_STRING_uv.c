
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#define d 10

int rabinKarp(char pattern[], char text[], int q,int m,int n) {
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++){
    h = (h * d) % q;
  }

  for (i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == m)
        printf("\nPattern is found at position:  %d \n", i + 1);
        return i+1;
    }
    

    if (i < n - m) {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
  return 0;
}
int main(){
    char pattern[15000];
    char text[15000];
    int m,n,q;
    int i,j;
    char ch;
    FILE *fp;
    clock_t starttime,endtime;

    printf("Code by utsav vachhai.");
    printf("\nthis progaram of String Matching using Rabin-Karp Algorithm.");
    printf("\nWhat is value of q :");
    scanf("%d",&q);
    printf("What is Size of pattren :");
    scanf("%d",&m);
    printf("What is Size of Text :");
    scanf("%d",&n);
    if(m>15000||n>15000){
        printf("Data size is highr then 15000.");
        return 0;
    }
    fp=fopen("13_pattern.txt","r");
    for(i=0;i<m;i++){
        ch=getc(fp);
        pattern[i]=ch;
    }
    printf("\nYour pattern is :\n");
    for(i=0;i<m;i++){
        printf("%c",pattern[i]);
    }

    fp=fopen("13_text.txt","r");
    for(i=0;i<n;i++){
        ch=getc(fp);
        text[i]=ch;
    }
    printf("\nYour txt is :\n");
    for(i=0;i<n;i++){
        printf("%c",text[i]);
    }
    starttime=clock();
    i=rabinKarp(pattern,text,q,m,n);
    endtime=clock();
    if(i==0){
        printf("\nNo match String is find.");
    }
    printf("\n\n-------------------------\n|\tTime=%f\t|\n-------------------------",(endtime-starttime)/CLOCKS_PER_SEC);
    return 0;
}