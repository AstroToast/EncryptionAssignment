/*

This program takes in a file as either a .txt or .crp file and encrypts or decrypts the file
Written by: Nicholas Grigg and Jaccob Pierog

*/

// how to convert to hexidecimal:
// let x be a digit and y be the second digit so the num is xy
// y*16^0 + x*16^1


// how to convert from hexidecimal:
// let x be a digit and y be the second digit so the hexidecimal is xy
// if y is a letter, convert to the corresponding number 
// then do y*16^0+ x*16^1

#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
    char *renamefilepointer, renamefilearray[100];
    int decryptlocation;
    if (strstr(argv[1], "-d") != NULL|| strstr(argv[2], "-d") != NULL) { // decrypting
        if (strstr(argv[1], "-d") == NULL) {
            decryptlocation = 1;
        } else {
            decryptlocation = 2;
        }
        strcpy(renamefilearray, argv[decryptlocation]);
        renamefilepointer = strtok(renamefilearray, ".");
        rename(argv[decryptlocation], strcat(renamefilepointer, ".txt"));



    } else { // encrypt
        if (strstr(argv[2], "-e") == NULL) {
            decryptlocation = 2;
        } else {
            decryptlocation = 1;
        }
        strcpy(renamefilearray, argv[decryptlocation]);
        renamefilepointer = strtok(renamefilearray, ".");
        rename(argv[decryptlocation], strcat(renamefilepointer, ".txt"));
    }

    return 0;
}