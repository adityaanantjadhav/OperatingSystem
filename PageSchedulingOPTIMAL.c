#include<stdio.h>

int checkpagefault(int page,int frame[],int f){
    for(int j=0;j<f;j++){
        if(page==frame[j]){
            return 1;
        }
    }
    return 0;
} 

int OPTIMAL(int page[],int frame[],int n,int f){
    int pagefault=0;
    for(int i=0;i<n;i++){
        int flag;
        flag=checkpagefault(page[i],frame,f);
        if(flag==0){
            pagefault++;
            if(i<f){
                frame[i]=page[i];
            }
            else{
                int opt=0;
                int optframe=0;
                for(int j=0;j<f;j++){
                    int k;
                    for(k=i+1;k<n;k++){
                        if(page[k]==frame[j]){
                            if(k>opt){
                                opt=k;
                                optframe=j;
                            }
                            break;
                        }
                    }
                    if(k==n){   
                        optframe=j;
                        break;
                    }
                }
                frame[optframe]=page[i];
            }
        }for(int m=0;m<f;m++){
            printf("%d\t",frame[m]);
        }printf("\n");
    }
    return pagefault;
}

int main(){
    int n,f;
    /*printf("enter the no of frames::");  
    scanf("%d",&f);
    printf("enter the no of pages::");
    scanf("%d",&n);
    int page[n];
    int frame[f];
    for(int i=0;i<n;i++){
        scanf("%d",&page[i]);
    }
    */
   
    int page[]={ 6, 1, 1, 2, 0, 3, 4, 6, 0, 2, 1, 2, 1, 2, 0, 3, 2, 1, 2, 0};    //comment these 4 lines if you want dynamin input
    int frame[]={999,999,999};                                                     //uncomment above ten lines then
    n=20;
    f=3;


    printf("\noptimal frames are::\n");
    printf("\npage faults in OPTIMAL are ::%d\n",OPTIMAL(page,frame,n,f));

}