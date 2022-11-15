#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(char ivalue){ 
char decrypt[2], evalue, tester; 
int x = 8, y = 1, outChar = 0;


decrypt[0] = x;
decrypt[1] = y;
if (x == 'T' && y == 'T'){
    printf("\t"); //printf will become return
}
else if ((x == 1 && y == 0) || (x== 1 && y == 3)){
    printf("\n");
}
else{
if (y == 'A'){
    y = 10;
}else if (y == 'B'){
    y = 11;
}else if (y == 'C'){
    y = 12;
}else if (y == 'D'){
    y = 13;
}else if (y == 'E'){
    y = 14;
}else if (y == 'F'){
    y = 15;
}
outChar = ((x * 16) + y) + 16;
if(outChar > 127){
outChar = ((outChar - 144) + 32);
printf("'%c'", outChar);
}
else{
    printf("'%c'", outChar);
}
}
}