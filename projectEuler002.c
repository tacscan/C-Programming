#include <stdio.h>

int main(void){
        int fib[] = {1,2,0};                    //first two numbers in the sequence
        int curFib = 0;                         //holding variable for the current Fibonacci number
        int sum = 2;                            //running total of added values

        while(curFib<4000000){                  //while the current Fibonacci number is less than 4,000,000
                fib[2]=fib[1]+fib[0];           //get the next Fibonacci number
                curFib = fib[2];                //hold it in the test condition variable

                if(fib[2]%2==0)                 //see if it's an even number
                        {sum += fib[2];}        //yes? add it to the running total

                fib[0]=fib[1];                  //set up the array for the next Fibonacci number calculation
                fib[1]=fib[2];                  //move index 1 to 0, index 2 to 1, and clear index 2
                fib[2]=0;                       //next iteration will be just like the first
        }

        printf("The sum of all even Fibonacci numbers under 4 million: %d\n", sum);

        return 0;                               //return exit success
}
