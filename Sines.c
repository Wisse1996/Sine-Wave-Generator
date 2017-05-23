#include <math.h>
#include <unistd.h>
#include <stdio.h>

#define at 239			    //attenuation
#define da 0.2			    //de-scaling
#define ts 360			    //initial timescale
#define mts 0               //minimum timescale
#define pi 3.14159		    //PI
#define delay 00000		    //frame time
#define ed 0.0000000001		//evil floating-point math error

double lts = ts;

char cha = '#';
char chb = ':';

int x = 0;
double alpha, beta = 0;
_Bool swap = 0;

int main(){
	while(1){
        
        if(swap) x++;
        else x--;
         
        alpha = (at/2)+sin(		(  (x*pi)/180  )*(360/lts)    )*(at/2);
        beta = (at/2)-sin(      (  (x*pi)/180  )*(360/lts)    )*(at/2)+ed;
		
        if(alpha >= 100) printf("%.6f", alpha);
        else if(alpha >= 10) printf("%.7f", alpha);
		else if(alpha >= 1) printf("%.8f", alpha);
        else if(alpha >= 0) printf("%.8f", alpha);
        else if(alpha < 0) printf("WHOA THERE, IT'S AN ERROR!");
        
		for(int i = 0; i <= 4; i++) printf(" ");
		
		for(int i = 0; i < alpha; i++){
			printf("%c", cha);
		}
		for(int i = 0; i < beta; i++){
            printf("%c", chb);
        }
		
        for(int i = 0; i <= 4; i++) printf(" ");
        if(lts >= 100) printf("%.6f", lts);
        else if(lts >= 10) printf("%.7f", lts);
		else if(lts >= 1) printf("%.8f", lts);
        else if(lts >= 0) printf("%.8f", lts);
        else if(lts < 0) printf("WHOA THERE, IT'S AN ERROR!");
        
		printf("\n");
        
		usleep(delay);
		
		if(lts > da+mts && !swap){
            lts -= da;
        }
        else if(!swap){
            swap = 1;
        };
        
        if(lts < (ts - da) && swap){
            lts += da;
        }
        else if(swap){
            swap = 0;
        };
        
	}
}
