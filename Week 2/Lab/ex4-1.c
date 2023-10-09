/*
create a C program that makes real-time decisions for the robot based on the sensor data
*/

#include <stdio.h>

int main(){
    int distanceToObstacle;

    puts("Enter the distance to the obstacle: ");
    scanf("%d", &distanceToObstacle);

    if (distanceToObstacle <= 20){
        printf("Stop moving!");
    }else if(distanceToObstacle <= 50 ){
        printf("Slow down and proceed with caution");

    }else{
        printf("Proceed at current speed");
    }
}