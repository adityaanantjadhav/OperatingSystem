
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	int n,r;
	
	printf("enter the no. of resources::");
	scanf("%d",&r);
	int resource[r];
	printf("enter the amount of resources::\n");
	for(int i=0;i<r;i++){
		printf("%d::",i+1);
		scanf("%d",&resource[i]);
	}
	printf("enter the no. of processes::");
	scanf("%d",&n);
	
	int alloc[n][r],max[n][r], need[n][r],available[r],executed[n],route[n];
	
	for(int i=0;i<n;i++){
		printf("enter the process %d\n",i+1);
		for(int j=0;j<r;j++){
			printf("p%d allocated resource %d:",i+1,j+1);
			scanf("%d",&alloc[i][j]);
		}
		for(int j=0;j<r;j++){
			printf("p%d max resource %d:",i+1,j+1);
			scanf("%d",&max[i][j]);
		}
		 executed[i]=0;
	}
	
	
	
	for(int i=0;i<r;i++){
		for(int j=0;j<n;j++){
			if(j==0)
				available[i]=alloc[j][i];
			else
				available[i]+=alloc[j][i];
		}
	}
	
	
	printf("\navailable resources are:\n");
	for(int i=0;i<r;i++){
		available[i]=resource[i]-available[i];
		printf("%d\t",available[i]);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<r;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}	
	
	printf("\nproc. allocated\t\tmax\t  need\n");
	for(int i=0;i<n;i++){
		printf("p%d   :",i+1);
		for(int j=0;j<r;j++){
			printf("%d  ",alloc[i][j]);
		}printf(" : ");
		for(int j=0;j<r;j++){
			printf("%d  ",max[i][j]);
		}printf(" : ");
		for(int j=0;j<r;j++){
			printf("%d  ",need[i][j]);
		}
		printf("\n");
	}
	
	int i=0,p=0;
    while (p != n)
    {
        int flag = 0;
        if (i == n)
            i = 0;
        if (executed[i] == 0)
        {
            for (int j = 0; j < r; j++)
            {
                if (available[j] < need[i][j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                printf("p%d cannot be executed:\n", i + 1);
            }
            else
            {
                printf("\np%d can be executed:\navailable are:", i + 1);
                route[p] = i + 1;
                for (int j = 0; j < r; j++)
                {
                    available[j] = alloc[i][j] + available[j];
                    printf("%d  ", available[j]);
                    executed[i] = 1;
                }
                p++;
            }
        }
        i++;
    }
	printf("\nroute is::");
    for(int k=0;k<n;k++){
		printf("%d -> ",route[k]);
	}
}
