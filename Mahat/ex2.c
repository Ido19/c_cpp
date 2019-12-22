#include <stdio.h>
#include <malloc.h>
#include <string.h>

int *func(char *str);

int *func(char *str){
    int i = 0;
    int count = 0;
    int flag  = 0;
    for(i ; i < strlen(str); i++){
        if((int)str[i] < 'A' || (int)str[i] > 'z'){
            if((int)str[i] != ' '){
            int *x = malloc(sizeof(int));
            *x = -1;
            return x;
            }
            else{
                count++;
            }
        }
    }//end of for
    int* arr;
    arr = (int *)malloc(sizeof(int)*(count+1));

    for(i=0; i < sizeof(arr); i++){
        arr[i] = 0;
    }

    int j = 0;
    int z = 0;
    i = 0;
    for(i ; i < strlen(str); i++){
        // if((int)str[i] != ' ' && i != strlen(str)-1)
        //     j++;
        // else// else if((int)str[i] == ' ' || i == strlen(str)-1)
        // {
        //     arr[z] = j;
        //     z++;
        //     j=0;
        // }
        if(i == strlen(str)-1){
            j++;
            arr[z] = j;
        }
        else if((int)str[i] == ' '){
            arr[z] = j;
            z++;
            j=0;
        }
        else{
            j++;
        }
    }
    arr[count+1] = -1;

    for (i = 0; i < sizeof(arr); i++)
    {
        printf("%d\n", arr[i]);
    }
    

    return arr;
}


int main(){
    int *x;
    x = func("Eyal Ben-Gad");
    printf("Value of x= %d", *x);
    return 0;
}