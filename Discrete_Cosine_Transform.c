#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.142857

int main() {
	srand(time(NULL));
	int m,i,k;
	scanf("%d",&m);
	float matd[m],dct[m];
	float ci,dct1,sum;
	for(i=0;i<m;i++) {
		matd[i]=(rand()%256)-128;
	}

	for(i=0;i<m;i++) {
		printf("%f\t",matd[i]);
	}

	for(i=0;i<m;i++) {
		if(i==0)
			ci=1/sqrt(m);
		else
			ci=sqrt(2)/sqrt(m);
		sum=0;
		for(k=0;k<m;k++) {
			dct1 =  matd[k] * cos((2*k+1)*i*pi/(2*m));
			sum = sum+dct1;
		}
		dct[i]=ci* sum;
	}

	printf("\n\n");
	for(i=0;i<m;i++) {
		printf("%f\t",dct[i]);
	}
	return 0;
}
