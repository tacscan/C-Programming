#include <stdio.h>

int main(void){
        int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};   //Number of days per month 
        int lmonths[] = {31,29,31,30,31,30,31,31,30,31,30,31};  //Number of days per month (leap year)
        int days[366];                                          //Array to hold the days of the week for a year
        int dow = 2;                                            //Day of the Week tracker
        int index = 0;                                          //index for the days per month
        int sundays = 0;                                        //Sunday tracker

        for(int ctr=1901; ctr<2001; ctr++){                     //Start at the year 1901 and go through 2000
                if(ctr%4 == 0 && ctr!=2000){                    //Is this a leap year?
                        for(int ctr=0; ctr<367; ctr++){         //Yes? Loop through 366 days 
                                days[ctr]=dow;                  //for each day assign a Day of the Week 0-6
                                dow++;                          //increment the Day of the Week
                                if(dow==7)                      //if we get to seven, reset to zero
                                        dow=0;
                        }

                        for(int ctr=0; ctr<12; ctr++){          //After all the days have been assigned, loop through
                                if(days[index]==0)              //each month and see if the first day is 0 (Sunday)
                                        { sundays++;}
                                index+=lmonths[ctr];
                        }

                        dow = days[365] + 1;
                        if(dow==7)
                                dow=0;
                        index=0;
                } 
                else{
                        for(int ctr=0; ctr<366; ctr++){
                                days[ctr]=dow;
                                dow++;
                                if(dow==7)
                                        dow=0;
                        }

                        for(int ctr=0; ctr<12; ctr++){
                                if(days[index]==0)
                                        { sundays++;}
                                index+=months[ctr];
                        }

                        dow = days[364] + 1;
                        if(dow==7)
                                dow=0;
                        index=0;
                } 
        }
        printf("The total number of sundays is %d\n", sundays);
}
