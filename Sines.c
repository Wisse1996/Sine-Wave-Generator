#include <math.h>
#include <unistd.h>
#include <stdio.h>

#define at 113			//attenuation
#define da 0			//deattenuation
#define ts 90			//timescale
#define pi 3.14159		//PI
#define delay 20000		//frame time
#define ed 0.0000000001		//evil decimal math error

double lts = ts;

char cha = '#';
char chb = ':';

int x = 0;
int main(){
	while(1){
	x += 1;
		printf("%#-10g", lts);
		
		for(int i = 0; i < at+sin(		(  (x*pi)/180  )*(360/lts)    )*at; i++){
			printf("%c", cha);
		}
		for(int i = 0; i < at-sin(              (  (x*pi)/180  )*(360/lts)    )*at+ed; i++){
                        printf("%c", chb);
                }
		printf("\n");
		usleep(delay);
		
		if(lts > da) lts -= da;
		else lts = ts;
	}
}


