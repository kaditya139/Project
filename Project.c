#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define max 1000001
#define pi 3.142857
typedef unsigned long long ll;
int prime[max];
int main() {
	srand(time(NULL));
	int i,j,l,d,res,k=2,p[max/3],m,n;
	ll c=0,a,p2[2],product,seed1,seed,res1;
	scanf ("%d%d",&m,&n);
	float b1,b2,num,denum,coef,arr[n];
	float mat[m][n],mat1[m][n],transform[m][n];
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
	i=0;k=2;
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
	k=1;
	while(k) {
		seed1 = ((rand())%product)+2;
		if((seed1%p2[0])!=0 && (seed1%p2[1])!=0) {		// Product and Seed generated
			seed=seed1;
			k--;
		}
	}
	//printf("%lld\t%lld\t",product,seed);
	d=(m*n);
	j=0;
	for(i=1;i<=d;i++) {
		res1=(seed*seed)%product;		// Generating Random number by using function Xi+1=(Xi*Xi)%product;
		seed=res1;
		res=res1%2;				// Random Binary Number Generated
		//printf("%d  ",res);
		arr[j]=res;
		j++;
	}



	//Now we will perform Gram - Schmidt Orthonormal Transformation to that generated random Numbers

	k=0;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			mat[i][j]=arr[k];			// Storing generated random binary number into matrix of size m X n
			k++;
		}
	}



	printf("\nGenerated random matrix using blum blum shub method are :-\n\n");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			printf("%f\t",mat[i][j]);		// Printing Random matrix
		}
		printf("\n");
	}
	printf("\n");


	for(i=0;i<m;i++){
		mat1[i][0]=mat[i][0];
	}
	for(j=0;j<n;j++) {
		for(k=0;k<j;k++) {
			num=0;denum=0;
			for(l=0;l<m;l++){
				num=num+mat[l][j]*mat1[l][k];
				denum=denum+mat1[l][k]*mat1[l][k];
			}
			coef=num/denum;
			if(denum==0){
				coef=0;
			}
			for(l=0;l<m;l++){
				mat1[l][j]=mat[l][j]-coef*mat1[l][k];
			}
			for(l=0;l<m;l++){
				mat[l][j]=mat1[l][j];
			}
		}
		b1=0;
		for(i=0;i<m;i++) {
			b1=b1+((mat1[i][j])*(mat1[i][j]));
		}
		b2=sqrt(b1);					// Variable b2 contains distance of vectors
		for(i=0;i<m;i++) {
			if(b2==0) {
				transform[i][j]=0;
				//mat1[i][j]=0;
			}
			else {
				transform[i][j]=(mat1[i][j])/b2;
			}
		}
	}

	printf("\nGenerated Matrix after Grahm Smith Orthogonalisation are :-\n\n");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			printf("%f\t",(transform[i][j]));
		}
		printf("\n");
	}



	// Now we will perform discrete cosine transformation on taking a random matrix


	float matd[m],dct[m];
	float ci,dct1,sum;
	for(i=0;i<m;i++) {
		matd[i]=(rand()%256)-128;
	}

	printf("\nRandom Marix on which we have to perform discrete cosine transform are :-\n\n");
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

	printf("\nMatrix After Discrete Cosine Transform are :-\n\n");
	for(i=0;i<m;i++) {
		printf("%f\t",dct[i]);
	}


	// Now we will take the inner product of generated dct coefficient and matrix obtained after gram smith orthogonalisation

	float hash[n],biohash[n],preset;
	for(j=0;j<n;j++) {
		sum=0;
		for(i=0;i<m;i++) {
			sum=sum+ ( transform[i][j] * dct[i] );
		}
		hash[j]=sum;
	}

	printf("\nMatrix after calculating inner product of DCT Coefficient and Orthogonalised Matrix are :-\n\n");
	for(i=0;i<n;i++) {
		printf("%f\t",hash[i]);
	}
	printf("\n");

	// Now we will generate biohash matrix with having zero as preset threshhold value

	printf("Enter Preset threshhold value :\t");
	scanf("%f",&preset);
	for(i=0;i<n;i++) {
		if(hash[i]>=preset)
			biohash[i]=1;
		else
			biohash[i]=0;
	}

	printf("\nBinary Matrix obtained after comparing with preset threshold value are :-\n\n");
	for(i=0;i<n;i++) {
		printf("%f\t",biohash[i]);
	}
	printf("\n");
		
	return 0;
}
