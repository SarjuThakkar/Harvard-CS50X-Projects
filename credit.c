#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    long long ccnumber = 0;
    do{
    ccnumber = get_long_long("Number: ");
    }
    while(ccnumber <= 0);
    long long ccnumbercount = ccnumber;
    int count = 0;
    for(int forcount = 1; ccnumbercount > 0; forcount++){
        ccnumbercount = ccnumbercount/10;
        count = forcount;
    }
    int checksum = 0;
    int firstdigit = 0;
    int seconddigit = 0;
    for(double digit = 2.0; digit <= count; digit += 2.0){
        int digitvalue = (int)(((ccnumber%((long long)pow(10.0 ,digit)))/((long long)pow(10.0,(digit-1.0))))*2.0);
        if(count == digit){
            firstdigit = digitvalue/2;
        }
        else if(digit == count-1){
            seconddigit = digitvalue/2;
        }
        if(digitvalue >= 10){
            int doubledigitvalue = (digitvalue%10) + ((digitvalue%100)/10);
            checksum += doubledigitvalue;
        }
        else{
            checksum += digitvalue;
        }
    }
    for(double digits = 1.0; digits <= count; digits += 2.0){
        int digitsvalue = (int)((ccnumber%((long long)pow(10.0 ,digits)))/((long long)pow(10.0,(digits-1.0))));
        if(count == digits){
            firstdigit = digitsvalue;
        }
        else if(digits == count - 1){
            seconddigit = digitsvalue;
        }
        checksum += digitsvalue;
    }
    if((checksum % 10 == 0) && (firstdigit == 3) && ((seconddigit == 4) || (seconddigit == 7))){
        printf("AMEX\n");
    }
    else if((checksum % 10 == 0) && (firstdigit == 5) && ((seconddigit >= 1) && (seconddigit <= 5))){
        printf("MASTERCARD\n");
    }
    else if((checksum % 10 == 0) && (firstdigit == 4)){
        printf("VISA\n");
    }
    else{
        printf("INVALID\n");
    }
    return 0;
}