//practical-1	factorial program--- (a)Iterative (b)Recursive  method
#include<stdio.h>
#include<time.h>
float iterative_Factorial(int n){
	float factorial_iterative=1;
	while(n!=1){
		factorial_iterative*=n;
		n--;
	}
	return factorial_iterative;
}
float recursive_Factorial(int n){
		if(n>=1){
		return n*recursive_Factorial(n-1);
	}
	else return 1;
}
int main(){
	int n;
	float factorial_iterative,factorial_recursive;
	printf("Code by Utsav vachhani(uv)");
	printf("\nEnter the number which you make Factorial :");
	scanf("%d",&n);
	factorial_iterative=iterative_Factorial(n);
	printf("Factorial of %d using \nIterative Method is %f",n,factorial_iterative);
	factorial_recursive=recursive_Factorial(n);
	printf("\nRecursive method is %f",factorial_recursive);
	return 0;
}
