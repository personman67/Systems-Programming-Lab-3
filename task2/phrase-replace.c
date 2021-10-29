#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* phraselist_old[20]={"Inferno","In dark woods","those woods",
    "to enter","crest","Below a hill","shoulders","planet","dante"};

char* phraselist_new[20]={"Paradisio","using Windows 8.1",
"Windows 8.1","to use 8.1","screen","Before a monitor","GUI","UNIX",
"Shakespeare"};
/*creates 2 arrays storing old values to be replaced and new values
to replace old values*/




/*
Function that takes line, word_old and word_new as arguments. 
Replaces all occurences of word_old in line with word_new and returns
line
*/
char*wordReplace(char*line, char*word_old, char*word_new){

    char*res;
    int i=0;
    int count=0;
    int wordlength_new = strlen(word_new);
    int wordlength_old = strlen(word_old);
    //variable and array declarations

    for(i=0;line[i]!='\0';i++){ //loops through line

        if(strstr(&line[i],word_old)==&line[i]){
            
            count++;
            //increments count if word_old found

            i=i + wordlength_old - 1;
            //Jumps forward by length of word_old

        }
    }

    res= (char*)malloc(i+count*(wordlength_new - wordlength_old)+1);
    //allocates space for result

    i=0;
    while(*line){ //reads through line

        if(strstr(line,word_old)==line){

            strcpy(&res[i],word_new);
            //if word_old is present replaces with word_new

            i+=wordlength_new;
            //increments i by wordlength_new

            line+=wordlength_old;
            //increments line by wordlength_old
        }
        else{

            res[i++]=*line++;
            //if word_old is not found copies *line to result
        }

    }

    res[i]='\0';
    return res;
    //adds termination char to result at EOF
}



/*
Function that takes line as input and replace all old phrases with
new phrases then returns modified line
*/
char*allReplace(char*line){

    for(int i=0;i<9;i++){

        line=wordReplace(line,phraselist_old[i],phraselist_new[i]);
        //calls wordReplace function to replace old phrases with new
    }

    return line;
}




int main() {

    char line[100];

    FILE *fptin = fopen("Input.txt","r");
    //creates input file pointer in read only mode
    if(!fptin){
        printf("Error: Input.txt file not found\n");
        return 0;
    }
    //displays error message if file is not found

    FILE *fptout=fopen("Dante.txt","w");
    //creates output file pointer in write only mode
    if(!fptout){
        printf("Error: Heaven.txt file not found\n");
        return 0;

    }
    //displays error message if file is not found

    char*res=NULL;

    while(fgets(line,sizeof(line),fptin)!=NULL){//reads line from input

        res=allReplace(line);
        printf("%s",res);
        //calls allReplace function to replace all old words

        fputs(res,fptout);
        //writes new words to output file

    }

    fclose(fptin);
    fclose(fptout);
    //closes all files
    
   return 0;
}