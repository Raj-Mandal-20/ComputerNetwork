
//Sambit 

#include<stdio.h>
int main(){
    int framesize, sent = 0, ack, i;
    printf("Enter the frame size: ");
    scanf("%d", &framesize);
    while(sent < framesize) {
        printf("Frame %d sent\n", sent);
        printf("Waiting for acknowledgement...\n");
        scanf("%d", &ack);
        if(ack == sent) {
            printf("Acknowledgement received for frame %d\n", sent);
            sent++;
        }
        else {
            printf("Acknowledgement not received for frame %d\n", sent);
        }
    }
}