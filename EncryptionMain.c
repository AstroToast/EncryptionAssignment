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
    char *renamefilepointer, renamefilearray[100], inputStream;
    int fileNameLocation, encryptOrNot, sizeOfFile;
    FILE *in, *out;
    
    
    if (argc-1) {
        fileNameLocation = 1;
    } else {
        if (strstr(argv[1], "-") == NULL) {
            fileNameLocation = 1;
        } else {
            fileNameLocation = 2;
        }
    }

    printf("%i\n", fileNameLocation);


    if (strstr(argv[1], "-d") != NULL|| ((argc > 0) && (strstr(argv[2], "-d") != NULL))) { // decrypting
    printf("decrypting \n");
        
        strcpy(renamefilearray, argv[fileNameLocation]);
        renamefilepointer = strtok(renamefilearray, ".");
        rename(argv[fileNameLocation], strcat(renamefilepointer, ".txt"));
        encryptOrNot = 0;


    } else { // encrypt
    printf("Here \n");
        strcpy(renamefilearray, argv[fileNameLocation]);
        encryptOrNot = 1;
    }

    
    in = fopen(renamefilepointer, "r");
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
        }
        fprintf(out, "%s", encrypt(fgetc(in)));
        }
    }



    fclose(in);
    fclose(out);
    
    if (!encryptOrNot) { // decrypt
        rename("tempFile.txt", renamefilearray);
    } else { // incrypt
        renamefilepointer = strtok(renamefilearray, ".");
        rename(argv[fileNameLocation], strcat(renamefilepointer, ".crp"));
        remove(argv[fileNameLocation]); // deletes the .txt file
    }




    return 0;
}

char* encrypt(char input){
    char temp[2];
    char *item = temp;


    if (input == 9) {
        return "TT";
    } else if (input == 13) {
        return "\n";
    } else {
        input-=16;
        if (input<32) {
            input = (input-32 + 144);
        }
        temp[0] = input/16 + 48;
        temp[1] = input%16;
        if (temp[1] > 9) {
            temp[1]+=55;
        } else {
            temp[1] +=48;
        }

    
    }
    return item;
    
}