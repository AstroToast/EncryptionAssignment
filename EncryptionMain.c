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


int main(int argc, char *argv[]) {
    
    char *renamefilepointer, renamefilearray[100], inputStream, *temp;
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
        
        inputStream = fgetc(in);
        if (inputStream == EOF) {
            break;
        }
        
        // decrypt(inputStream);
        // need to write what is returned to the file
    }


    } else { // encrypt
        while (1) {
            
        
        inputStream = fgetc(in);
        
        
        if (inputStream == EOF) {
            break;
        } else 

        temp = encrypt(inputStream);
        fprintf(out, "%c%c", temp[0], temp[1]);
        }
    }



    fclose(in);
    fclose(out);
    if (!encryptOrNot) { // decrypt
        rename("tempFile.txt", renamefilearray);
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
    } else if (input == '\n') {
        return "\n";
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