#include<stdio.h>

int checkpagefault(int page,int frame[],int f){
    for(int j=0;j<f;j++){
        if(page==frame[j]){
            return 1;
        }
    }
    return 0;
}

int FIFO(int page[],int frame[],int n,int f){
    int pagefault=0;
    int k=0;
    for(int i=0;i<n;i++){
        int flag=0;
        flag=checkpagefault(page[i],frame,f);
        if(flag==0){
            pagefault++;
            if(k==f){
                k=0;
            }
            frame[k]=page[i];
            k++;
        }
        for(int m=0;m<f;m++){
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
    
    printf("\nfifo frames are::\n");
    printf("\npage faults in FIFO are ::%d\n",FIFO(page,frame,n,f));

}