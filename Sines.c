#include <math.h>
#include <unistd.h>
#include <stdio.h>

#define at 113			//attenuation
#define da 0			//deattenuation
#define ts 90			//timescale
#define pi 3.14159		//PI
#define delay 20000		//timing parameter
#define ed 0.0000000001		//evil decimal math error


int x = 0;
double lts = ts;

int main(){
	while(1){
	x += 1;
		printf("%#-10g", lts);
		
		for(int i = 0; i < at+sin(		(  (x*pi)/180  )*(360/lts)    )*at; i++){
			printf("#");
		}
		for(int i = 0; i < at-sin(              (  (x*pi)/180  )*(360/lts)    )*at+ed; i++){
                        printf(" ");
                }
		printf("\n");
		usleep(delay);
		
		if(lts > da) lts -= da;
		else lts = ts;
	}
}


