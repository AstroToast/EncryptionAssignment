#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(char ivalue){ 
char decrypt[2], evalue; 
char x=6, y='A';

decrypt[0] = x;
decrypt[1] = y;
if (x == 'T' && y == 'T'){
    printf("\t"); //printf will become return
}
else{
if (y == 'A'){
    y = -6;
}else if (y == 'B'){
    y = -5;
}else if (y == 'C'){
    y = -4;
}else if (y == 'D'){
    y = -3;
}else if (y == 'E'){
    y = -2;
}else if (y == 'F'){
    y = -1;
}
printf("x = %d\n", x);
printf("y = %d\n", y);
evalue = ((x*16) + y);
evalue += 16;
printf("e val = %d which is %d x + %d y\n", evalue, x, y);
if(evalue > 127){
evalue = (evalue - 144) + 32;
}
printf("%c", evalue);
}
//return 0;
}