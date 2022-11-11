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


int main(int argc, char *argv[]) {
    char *renamefilepointer, renamefilearray[100], inputStream;
    int fileNameLocation, encryptOrNot, sizeOfFile;
    FILE *in, *out;
    

    if (strstr(argv[1], "-d") != NULL|| strstr(argv[2], "-d") != NULL) { // decrypting
        if (strstr(argv[1], "-d") == NULL) {
            fileNameLocation = 1;
        } else {
            fileNameLocation = 2;
        }
        strcpy(renamefilearray, argv[fileNameLocation]);
        renamefilepointer = strtok(renamefilearray, ".");
        rename(argv[fileNameLocation], strcat(renamefilepointer, ".txt"));
        encryptOrNot = 0;


    } else { // encrypt
        if (strstr(argv[2], "-e") == NULL) {
            fileNameLocation = 2;
        } else {
            fileNameLocation = 1;
        }
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
        // decrypt(inputStream);
        // need to write what is returned to the file
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