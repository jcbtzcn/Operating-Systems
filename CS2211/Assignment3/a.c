// This program approximates an euler number.
#include <stdio.h>
#include <stdbool.h>
int main(){
    //Assigning numbers and initializing 
    //n is the user input. e is the euler number to check.
    double e=1, n;
    printf("Enter an integer: ");
    scanf("%lf", &n);
    // value is the number of loops program will iterate to reach the inputted number.
    // 1/n! will be less than the input number n. The program will quit after this.
    int value=1;
    int bakctrack;
    double factorial;
    bool boolTrue = true;
    while (boolTrue){
        //it starts at 1 since 1!=1.
        if(value==1)
            factorial=1;
        //this statement increments the value while doing the factorial calculation.
        else{
            bakctrack = value;
            factorial=value;
            //Calculation of the factorial;
            while(bakctrack>0){
                factorial = factorial * bakctrack;
                //Decrements each time.
                bakctrack--;
            }
        } 
        //fact is the result of 1/factorial which is 1/n!.
        double fact;
        fact = 1 / factorial;
        //checks if the inputted number is larger than the fact.
        if (fact < n)
            break;
        //Adds one more loops and continues of fact is still larger than n.
        value++;
        //Calculates euler number.
        e +=fact;       
    }
    printf("Number is: %.13lf with %d loop.", e, value);
}
