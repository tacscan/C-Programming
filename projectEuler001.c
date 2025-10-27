#include <stdio.h>

int main(void){

        int answer=0;

        for(int limit=0; limit<1000; limit++){
                if(limit%3==0 || limit%5==0){
                        answer+=limit;
                }
        }

        printf("The answer is %d\n", answer);

}
