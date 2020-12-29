#include <stdio.h>
#include <math.h>

int i,j,car, slot, masuk, keluar, array[1010], check=0;
int main()
{
    scanf("%d %d",&car,&slot);
    for(i=0;i<car;i++){
        scanf("%d %d",&masuk,&keluar);
        for(j=masuk;j<=keluar;j++){
            array[j]++;
            if(array[j]>slot){
                check=1;
                break;
            }
        }
        if(check==1)
            break;
    }
    if(check==0) 
        printf("Lancar\n");
    if(check==1) 
        printf("Macet\n");
}