#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 1000001
typedef unsigned long long ll;
int prime[max];
int main() {
	srand(time(NULL));
	int i,j,d,k=2,p[max/3],res;
	ll c=0,a,p2[2],product,seed,seed1,res1;
	prime[0]=prime[1]=1;
	for(i=2;i<=max;i++) {
		if(!prime[i]) {
			p[c]=i;
			c++;				// C is used as a counter to keep track on the number of prime number generated
			for(j=i+i;j<=max;j+=i) {
				prime[j]=1;
			}
		}
	}
	ll p1[c];
	for(i=0;i<c;i++) {
		p1[i]=p[i];			// Array p1 will store all the prime number
	}
	for(i=0;i<c;i++) {
		//printf("%lld\t",p1[i]);
	}
	i=0;
	while(k) {
		a=(rand())%c;
		if((p1[c-a]%4)==3) {
			p2[i]=p1[c-a];		// Choosing two prime number using generated random array index
			i++;
			k--;
		}
	}

	//printf("\n");
	product = p2[0]*p2[1];
	printf("%lld  ",product);
	k=1;
	while(k) {
		seed1 = ((rand())%product)+2;
		if((seed1%p2[0])!=0 && (seed1%p2[1])!=0) {		// Product and Seed generated
			seed=seed1;
			k--;
		}
	}
	//printf("%lld\t%lld\t",product,seed);
	scanf ("%d",&d);
	for(i=1;i<=d;i++) {
		res1=(seed*seed)%product;		// Random Binary Number Generated
		seed=res1;
		res=res1%2;
		//printf("%lld  ",res1);
		//printf("%d  ",res);
	}

	return 0;
}


