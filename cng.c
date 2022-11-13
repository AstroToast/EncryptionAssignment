#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(){
char encData[50][120], cData[50][240], hexD[2];
int placeholder, numLine = 0, outChar, strL;




while(fgets(encData[numLine], 120, inputfile)){ //inputfile is for the initial file 
    strL - strlen(encData[numLine]);
    for (int i = 0; i < strL; i ++){
        placeholder = encData[numLine][i];
        outChar = placeholder - 16;
        if (placeholder == 9){
            strcat(cData[numLine + 1], "TT");
        }
        else if (placeholder == 13 || placeholder == 10){
            strcat(cData[numLine + 1], "\n"); 
        }
        else if (outChar < 32){
            outChar = (outChar - 32) + 144;
            sprintf(hexD, "%02X", outChar);
            strcat(cData[numLine], hexD);
        }
        else{
            sprintf(hexD, "%02X", outChar);
            strcat(cData[numLine + 1], hexD);
        }
    }
    fputs (cData[numLine + 1], outputfile); //outputfile is for the encrypted file 
    numLine++;
}

}