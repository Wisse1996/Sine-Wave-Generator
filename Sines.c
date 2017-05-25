////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

#include <math.h>
#include <unistd.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

#define sine sin((180/pi)*(((pi*lts)/(180))))    // master function
#define at 245			                // attenuation
#define da 0.1			                // de-attenuation
#define ts 100   		                // initial timescale
#define mts 0                           // minimum timescale
#define delay 5000		                // frametime

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int main(){
    const double ed = 0.0000000001;
    const double pi = 3.141592653589793;
    double lts = ts;
    char cha = '#';
    char chb = ':';
    double alpha, beta = 0;
    _Bool swap = 0;
	while(1){
        
        alpha = (at/2)+sine*(at/2)+ed;
        beta = (at/2)-sine*(at/2)+ed;
        
        if(alpha >= 100){
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
        else{
            printf("00");
            printf("%.5f", alpha);
        }
        
		printf(" == ");
		
        
        
        
        
        
        
        
        
		for(int i = 0; i < alpha; i++){
			printf("%c", cha);
		}
		for(int i = 0; i < beta; i++){
            printf("%c", chb);
        }
		
        
        
        
        
        
        
        printf(" == ");
        
        if(lts >= 100-ed){
            printf("%.1f", lts);
        }
        else if(lts >= 10-ed){
            printf("0");
            printf("%.1f", lts);
        }
		else if(lts >= 1-ed){
            printf("00");
            printf("%.1f", lts);
        }
        else{
            printf("00");
            printf("%.1f", lts);
        }
        
        
        
        
        
        
        
		printf("\n");
        
		usleep(delay);
		
		if(lts >= mts+da && !swap){
            lts -= da;
        }
        else if(!swap){
            swap = 1;
        };
        
        if(lts <= ts-da && swap){
            lts += da;
        }
        else if(swap){
            swap = 0;
        };
	}
}