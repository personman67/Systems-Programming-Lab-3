#include <stdio.h>
int main() {

    FILE *fptin = fopen("Input.txt","r");
    //creates input file pointer in read only mode

    if(!fptin){
        printf("Error: Input.txt file not found\n");
        return 0;

    }
    //displays error message if file is not found

    char buff[1000];
    int index =0;
    char c;
    //creates buffer array and index

    while(fscanf(fptin,"%c",&c)==1){
        if(c=='a'){
            c='b';
        }

        buff[index]=c;
        index++;
    }
    //loops as long as a valid character can be read

    fclose(fptin);
    //closes input file

    FILE *fptout=fopen("Heaven.txt","w");
    //creates output file pointer in write only mode

    if(!fptout){
        printf("Error: Heaven.txt file not found\n");
        return 0;

    }
    //displays error message if file is not found

    for(int i=0;i<index;i++){

        fprintf(fptout,"%c",buff[i]);
    }
    //loops through buffer and prints each character to output file

    fclose(fptout);
    //closes output file and saves changes

   return 0;
}