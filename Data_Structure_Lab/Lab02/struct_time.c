#include <stdio.h>

struct Time{
    int hours;
    int minutes;
    int seconds;
};

int main(){
    struct Time time1, time2, result;

    // Input time1
    printf("Input the first time (hours minutes seconds): ");
    scanf("%d %d %d", &time1.hours, &time1.minutes, &time1.seconds);

    // Input time2
    printf("Input the second time (hours minutes seconds): ");
    scanf("%d %d %d", &time2.hours, &time2.minutes, &time2.seconds);

    printf("1)Add\n2)Subtract\n");
    int ch;
    printf("Enter your choice(1/2)");
    scanf("%d", &ch);

    // Add the two times
    if(ch==1){
        result.seconds = time1.seconds + time2.seconds;
        result.minutes = time1.minutes + time2.minutes + result.seconds / 60;
        result.hours = time1.hours + time2.hours + result.minutes / 60;
    }

    // Subtract the two times
    if(ch==2){
        result.seconds = time1.seconds - time2.seconds;
        result.minutes = time1.minutes - time2.minutes + result.seconds / 60;
        result.hours = time1.hours - time2.hours + result.minutes / 60;
    }

    // Adjust minutes and seconds
    result.minutes %= 60;
    result.seconds %= 60;

    // Display the result
    printf("\nResultant Time: %d:%d:%d\n", result.hours, result.minutes, result.seconds);

    return 0;
}
