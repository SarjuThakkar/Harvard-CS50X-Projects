#include <stdio.h>
#include <cs50.h>

int main(void){
    printf("Height: ");
    int height = get_int();
    while(true){
        if(height < 0 || height > 23){
            printf("Height: ");
            height = get_int();
        }
        else{
            for(int n = 1; n < height + 1; n++){
                for(int spaces = height - n; spaces > 0; spaces--){
                    printf(" ");
                }
                for(int hashes = 0; hashes < n; hashes ++){
                    printf("#");
                }
                printf("  ");
                for(int secondHashes = 0; secondHashes < n; secondHashes ++){
                    printf("#");
                }
                printf("\n");
            }
        return false;
        }
    }
}