#include<stdio.h>
#include<stdlib.h>

int readcount =0;
int mutex = 1;

void showread(){
    printf("\n%d readers are Reading\n",readcount);
}

void reader(){
    int n;
    if(readcount==0){
    mutex--;
    readcount++;
    showread();
    mutex++;
    }
    mutex--;
    do{
        if(readcount>0){
        printf("\n1.Add reader\n2.Remove reader\n3.Write\n");
        scanf("%d",&n);
        switch(n){
        case 1: readcount++; showread(); break;
        case 2: readcount--; showread(); break;
        case 3: printf("\ncant write cuz readers are present!!");
        default: showread();

        }
    }
    else{
        printf("\n Reader/writer can enter!");
        break;
    }
    }while(n>0);
    mutex++;
    //printf("\n%d",mutex);
    
}

void writer(int x){
    if(x==0){
    printf("\nWriter is Writing\n");
    mutex--;
    }
    else if(x==1){
         printf("\nWriter finished writing");
        mutex++;
    }
}



int main(void){
    int n,x;
    do{
    printf("\n1.Read\n2.write\n3.Exit\n");
    scanf("%d",&n);
    switch(n){
        case 1: if(mutex==1)
                    reader();
                else{
                    printf("\nCant Read!! Writer is writing\nWant writing to finish?\n1.yes\n2.No\n");
                    scanf("%d",&x);
                    if(x==1)
                        writer(1);
                    
                }

                break;
        case 2: if(mutex==1)
                    writer(0);
                else{
                    printf("writer is already present!!\n");
                    printf("\nWant writing to finish?\n1.yes\n2.No\n");
                    scanf("%d",&x);
                    if(x==1)
                        writer(1);
                }
                break;
        default: exit(0);
    }
    }while(n>0);

}