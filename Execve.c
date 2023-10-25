//Child.c

#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>

int bisearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            printf("x found %d \n", x);
            return 0;
        } else if (x < arr[mid]) {
            return bisearch(arr, l, mid - 1, x);
        } else {
            return bisearch(arr, mid + 1, r, x);
        }
    }

    printf("x not found \n");
    return -1;
}

int main(int argc,char *argv[]){
	int i, arr[5],count,search;
    count =1;
    for (i = 1; i < 6; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
    printf("\nelements are: ");
	for(int i=0;i<5;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n enter the element to search::");
	scanf("%d",&search);
	bisearch(arr,0,4,search);
}


//parent.c

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    int n;
    printf("Enter the number of elements you want: ");
    scanf("%d", &n);

    int element[n];

    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element[i]);
    }

    printf("\nArray elements are: ");
    for(int i = 0; i < n; i++){
        printf("%d\t", element[i]);
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(element[j] > element[j + 1]){
                int temp = element[j];
                element[j] = element[j + 1];
                element[j + 1] = temp;
            }
        }
    }

    printf("\nSorted array elements are: ");
    for(int i = 0; i < n; i++){
        printf("%d\t", element[i]);
    }

    char *arr[n + 2];
    arr[0] = "./small";
    arr[n + 1] = NULL;

    for(int i = 0; i < n; i++){
        arr[i + 1] = (char *)malloc(20); 
        sprintf(arr[i + 1], "%d", element[i]);
    }

    int ret = fork();

    if (ret == 0){
        printf("\nChild process id is: %d\n", getpid());
        execve(arr[0], arr, NULL);
    }
    else{
        wait(NULL);
        printf("\nParent process id is: %d\n", getpid());
    }

    for(int i = 0; i < n; i++){
        free(arr[i + 1]);
    }

    return 0;
}
