////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

#include <math.h>
#include <unistd.h>
#include <stdio.h>

#define at 245			    //attenuation
#define da 0.2			    //de-scaling
#define ts 360			    //initial timescale
#define mts 0               //minimum timescale
#define delay 10000		    //frame time

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

#define ed 0.0000000001
#define pi 3.14159

int main(){
    double lts = ts;
    char cha = '#';
    char chb = ':';
    double alpha, beta = 0;
    _Bool swap = 0;
    int x = 0;
	while(1){
        
        x++;
        if(x >= 360) x = 0;
		
        alpha = (at/2)+             sin((pi*x*(360/lts))/180)                  *(at/2);
        beta = (at/2)-             sin((pi*x*(360/lts))/180)                  *(at/2)+ed;
        
        if(alpha >= 100){
            printf("");
            printf("%.5f", alpha);
        }
        else if(alpha >= 10){
            printf("0");
            printf("%.5f", alpha);
        }
		else if(alpha >= 1){
            printf("00");
            printf("%.5f", alpha);
        }
        else if(alpha >= 0){
            printf("00");
            printf("%.5f", alpha);
        }
        else if(alpha < 0){
            printf("WHOA THERE, IT'S AN ERROR!");
        }
        
		for(int i = 0; i <= 4; i++) printf(" ");
		
		for(int i = 0; i < alpha; i++){
			printf("%c", cha);
		}
		for(int i = 0; i < beta; i++){
            printf("%c", chb);
        }
		
        for(int i = 0; i <= 4; i++) printf(" ");
        if(lts >= 100){
            printf("");
            printf("%.1f", lts);
        }
        else if(lts >= 10){
            printf("0");
            printf("%.1f", lts);
        }
		else if(lts >= 1){
            printf("00");
            printf("%.1f", lts);
        }
        else if(lts >= 0){
            printf("00");
            printf("%.1f", lts);
        }
        else if(lts < 0){
            printf("WHOA THERE, IT'S AN ERROR!");
        }
        
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