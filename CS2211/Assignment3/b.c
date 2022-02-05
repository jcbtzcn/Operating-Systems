#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main(){
    const char arr[10][4][4]={
        {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},  //shape for 0. done
        {{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},  //shape for 1. done
        {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},  //shape for 2. done
        {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},  //shape for 3. done
        {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},  //shape for 4. done
        {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},  //shape for 5. done
        {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},  //shape for 6. done
        {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},  //shape for 7. done
        {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},  //shape for 8. done
        {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}   //shape for 9. done
        //{{' ', ' ', ' '}, {' ', '_', ' '}, {' ', ' ', ' '}}   //shape for minus. done
    };
    // shapes.
    while(true){
        char n;
        printf("Enter an integer: ");
        scanf(" %c", &n);
        char array[10]; 
        int i=0;
        int size=0;
        while(n!='\n'){
            size++;
            array[i]=n;
            scanf("%c", &n);
            i++;
        }
        char ar[size];
        int x;
        for(int s=0;s<size;s++){
            x=array[s]-'0';
            ar[s]=x;
        }
        char n1;
        printf("Enter the sign of the integer: ");
        scanf("%c", &n1);
    /*
    */
    //Now we know how many numbers are inputted and they are stored in the array.
    //Seven segment display for digits from 0-9.
        if (n1=='-'){
            printf("  -\n");
        }
        for(int k=0;k<size;k++){
            for(int j=0;j<10;j++){
                if(ar[k]==j){
                    printf("%s\n%s\n%s\n", arr[j][0], arr[j][1], arr[j][2]);
                }
            }
        }
        char inputUser;
        printf("Do you want to continue to enter values? (Y(Yes)/N(No))");
        printf("\nInput: ");
        scanf("%s", &inputUser);
        if(inputUser!='Y'){
            break;
        }
    }
}
