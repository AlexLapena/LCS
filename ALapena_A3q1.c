/*
	Alex Lapena
	0844071
	A3q1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 9999
#define LIST 100

/*Declare global variables*/
int a,b, t = 0;
int size;
int intArr[MAX+1][LIST+1], array[LIST];
int intArr2[MAX+1][LIST+1];

void order(int intArr2[][LIST+1],int x[],int i,int j);

int main(int argc, char *argv[]){
	FILE * fp;
	int arr[MAX+1];
	char string[MAX];
	int ele,i,j,t;
	
	fp = fopen("List.txt","r");
	//Checks first line for Number of elements
	fgets(string, MAX, fp);
    ele = atoi(string); 
	a = MAX+1;
    b = ele+1;
    int arr2[ele+1];

	/*Gets the index of the number in the list and stores them into
		the array to be checked*/
    for(t = 0; t < ele; t++){
    	fgets(string, MAX, fp);
    	arr2[t] = atoi(string);
    }
   	for(t = 0; t < MAX ; t++){	
   		arr[t] = t + 1;
   	}
   	
   	/*Resets rows and columns for recursive calls*/   
     for(i = 0; i < b; i++){ 
      	intArr[i][0] = 0;
	 }   
     for(i = 0; i < a; i++){
    	intArr[0][i] = 0;
	 }
     
     for(i = 1; i < a; i++){     
	 	for(j = 1; j < b; j++){
			// Left upper bound
			if(arr[i-1] == arr2[j-1]){
		  	 	intArr[i][j]= intArr[i-1][j-1] + 1; 
		  		intArr2[i][j] = 0;  
		  	}
		  	// Same or larger
		 	else if(intArr[i-1][j] >= intArr[i][j-1]){
		      	intArr[i][j] = intArr[i-1][j];
		     	intArr2[i][j] = 1; 
		    }
		    //Left most number
			else{
		    	intArr[i][j] = intArr[i][j-1];
		     	intArr2[i][j] = 2; 
		    }
		} 
	}	
	size = intArr[MAX][LIST];
	//Calls to find the proper order, recursively
    order(intArr2, arr, a, b);

   	fclose(fp);
   	return 0;
}

void order(int intArr2[][LIST+1],int arr[],int i,int j){
	int count;

	//Ends recursive step
	if(i == 0 || j == 0){
		printf("\nThere are %d numbers in the sequence.\n", size);
		printf("Longest sequence of increasing numbers: \n\n");
   	
		//Counts to 10 to print in rows of 10 maximum
		count = 1;
		for(t = size - 1; t >= 0; t--){
			printf("%d ", array[t]);
			if(count == 10){
				printf("\n");
				count = 0;
			}
			count++;
		}	
		printf("\n\n");
      	return;
	}
	
	//Adds into the array
    if(intArr2[i-1][j-1] == 0){
      	 array[t] = arr[i+1];
      	 t++;
	     order(intArr2,arr,i-1,j-1);  
	 }
	 //Swaps for larger number
     else if(intArr2[i-1][j-1] == 1){
      	 order(intArr2,arr,i-1,j);
     }
     //Swap
     else{
		 order(intArr2,arr,i,j-1);
	 }
} 
