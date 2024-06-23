#include<stdio.h>
#include<stdlib.h>

int input(int a[], int frame_size){
    printf("\n--------INPUT--------\n");
    for(int i=1;i<=frame_size;i++){
        printf("Enter value for frame[%d] : ", i);
        scanf("%d", &a[i]);
    }
    return 1;
}

int display(int a[], int frame_size){
    printf("\n--------DISPLAY--------\n");
    for(int i=1;i<=frame_size;i++)
        printf("Frame[%d] : %d\n", i, a[i]);
    printf("\n");
    return 1;
}

int selective_repeat(int frames[], int window_size, int frame_size){
    int nt = 0;
    int k = 0;
    int left[10000] = {-1};
    int i;
    for(i=1;i<=frame_size;i++){
        int flag = rand()%2;
        if(flag){
            printf("Frame[%d] with value %d Acknowledged !!\n", i, frames[i]);
            nt++;
        }
        else{
            printf("Frame[%d] with value %d Not Acknowledged !!\n", i, frames[i]);
            left[k++] = frames[i];
            nt++;
        }
        if(i%window_size == 0){
            for(int x=0;x<k;x++){
                printf("Frame[%d] with value %d Retransmitted !!\n", x, left[x]);
                nt++;
                printf("Frame[%d] with value %d Acknowledged on second attempt !!\n", x, left[x]);
            }
            k=0;
        }
    }
    for(i=0;i<k;i++){
        printf("Frame[%d] with value %d Retransmitted !!\n", i, left[i]);
        nt++;
        printf("Frame[%d] with value %d Acknowledged on second attempt !!\n", i, left[i]);
    }
    printf("Total Transmission : %d\n", nt);
    return 0;
}

int main(){
    int frames[50];
    int window_size;
    int frame_size;

    printf("\n----SELECTIVE REPEAT----\n");
    printf("Enter Window size : ");
    scanf("%d", &window_size);
    printf("Enter number of frames to be transmitted : ");
    scanf("%d",&frame_size);
    input(frames, frame_size);
    display(frames, frame_size);
    selective_repeat(frames, window_size, frame_size);
    return 0;
}
