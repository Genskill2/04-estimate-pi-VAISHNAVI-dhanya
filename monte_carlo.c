#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float mc_pi(int n)

{ /*float a = frandom();
   printf("%f", a);*/
  float pi;
  int circle=0;
  int sqr=0;
  for( int i=1;i<=n;i++)
     {
       
       long int q = random();
       float x = (float)q/(float)RAND_MAX;
       long int p = random();
       float y = (float)p/(float)RAND_MAX;
       /*x=frandom();
       y=frandom();*/
       if((x*x)+(y*y)<=1)
        {
         circle=circle+1;
        }
        else
        {
          sqr=sqr+1;
        }
      }
    pi=(float)4*circle/(sqr+circle);
    return pi;
 } 
    
float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}



