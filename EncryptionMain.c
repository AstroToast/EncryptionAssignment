/*

This program takes in a file as either a .txt or .crp file and encrypts or decrypts the file
Written by: Nicholas Grigg and Jaccob Pierog

*/

// how to convert from hexidecimal:
// let x be a digit and y be the second digit so the num is xy
// y*16^0 + x*16^1


// how to convert from hexidecimal:
// let x be a digit and y be the second digit so the hexidecimal is xy
// if y is a letter, convert to the corresponding number 
// then do y*16^0+ x*16^1


#include <stdio.h>
#include <string.h>
char* encrypt(char);
char decrypt(char[]);


int main(int argc, char *argv[]) {
    
    char *renamefilepointer, renamefilearray[100], inputStreamEn, *temp, inputStreamDe[2];
    int fileNameLocation, encryptOrNot, sizeOfFile, EnDeLocation;
    FILE *in, *out;
    
    
    
    if (argc == 2) {
        fileNameLocation = 1;
        encryptOrNot = 1;
    } else {
        encryptOrNot = 0;
        if (strstr(argv[1], "-") == NULL) {
            fileNameLocation = 1;
            EnDeLocation = 2;
        } else {
            fileNameLocation = 2;
            EnDeLocation = 1;
        }
    }

    strcpy(renamefilearray, argv[fileNameLocation]);
    
    if (!encryptOrNot && strstr(argv[EnDeLocation], "-d") != NULL) { // decrypting
    

        
        encryptOrNot = 0;

    
    } else { // encrypt
        encryptOrNot = 1;
    }
    
    
    in = fopen(argv[fileNameLocation], "r");
    if (in == NULL) {
        printf("The given file doesn't exist \n");
        fclose(in);
        fclose(out);
        remove("tempFile.txt");
        return 0;
    }
    

    out = fopen("tempFile.txt", "w"); // used to tempererarely write to and then will be renamed to replace the in file

    
    if (!encryptOrNot) { // decrypt

        while (1) {
        
        inputStreamDe[0] = fgetc(in);
        
        if (inputStreamDe[0] == EOF) {
            break;
        } else if (inputStreamDe[0] == '\n') {
            fprintf(out, "\n");
            continue;
        }
        

        inputStreamDe[1] = fgetc(in);



        fprintf(out, "%c", decrypt(inputStreamDe));
        
    }


    } else { // encrypt
        while (1) {
            
        
        inputStreamEn = fgetc(in);
        
        
        if (inputStreamEn == EOF) {
            break;
        } else if (inputStreamEn == '\n') {
            fprintf(out, "%c", '\n');
        }

        temp = encrypt(inputStreamEn);
        fprintf(out, "%c%c", temp[0], temp[1]);
        }
    }



    fclose(in);
    fclose(out);
    if (!encryptOrNot) { // decrypt
        renamefilepointer = strtok(renamefilearray, ".");
        remove(argv[fileNameLocation]);
        rename("tempFile.txt", strcat(renamefilepointer, ".txt"));
    } else { // encrypt
        renamefilepointer = strtok(renamefilearray, ".");
        remove(argv[fileNameLocation]);
        rename("tempFile.txt", strcat(renamefilepointer, ".crp"));
        
    }




    return 0;
}

char* encrypt(char input){
    char temp[2];
    char *item = temp;
    int holder;


    if (input == 9) {
        return "TT";
    } else {
        holder = input-16;
        
        if (holder<32) {
            holder = (holder + 112);
        }
        
        temp[0] = holder/16 + 48;
        
        temp[1] = holder%16;
        if (temp[1] > 9) {
            temp[1]+=55;
            
        } else {
            temp[1] +=48;
        }

    
    }
    return item;
    
}

char decrypt(char input[2]){ 
    char tester; 
    int x, y, outChar = 0;


    if (input[0] == 'T' && input[1] == 'T'){
        return('\t'); 
    } else{
    
        if (input[1] >57) {
            y = input[1]-55;
        } else {
            y = input[1] - 48;
        }
    
        x = input[0] - 48;
        outChar = ((x * 16) + y) + 16;
        if(outChar > 127){
            outChar = ((outChar - 144) + 32);
            return outChar;
        }
        else{
        return outChar;
        }
    }
}
