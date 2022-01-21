// Write C program to find union intersection and difference, complement and cartesian product of two sets.
//
#include <stdio.h>

#define N1 5
#define N2 4
#define U3 11

// Prototypes
int union_set(int A[], int B[], int R[]);
int intersection_set(int A[], int B[], int R[]);
int difference_set(int A[], int B[], int R[], int A_SZ, int B_SZ);
int complement_set(int A[], int R[], int U[], int A_SZ, int U_SZ);
void cartesian_product(int A[], int B[]);
void print_set(int a[], int n);


int main(){
	int R[N1+N2+U3];
	int A[] = {1, 2, 3, 4, 5};
	int B[] = {2, 3, 4, 0};
	int i_size = intersection_set(A, B, R);
	print_set(R, i_size);

	int u_size = union_set(A, B, R);
	print_set(R, u_size);

	int d_size = difference_set(A, B, R, N1, N2);
	print_set(R, d_size);

	int U[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int c_size = complement_set(A, R, U, N1, U3);
	print_set(R, c_size);

	cartesian_product(A, B);

	return 0;
}

int intersection_set(int A[], int B[], int R[]){
	int k = 0;
	for(int i=0; i<N1; i++){
		for(int j=0; j<N2; j++){
			if(A[i] == B[j]){
				R[k++] = A[i];
			}
		}
	}
	return k;
}

int union_set(int A[], int B[], int R[]){
	int k = 0;
	for(int i=0; i<N1; i++){
		R[k++] = A[i];
	}
	for(int i=0; i<N2; i++){
		int flag = 0;
		for(int j=0; j<N1; j++){
			if(B[i] == A[j]){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			R[k++] = B[i];
		}
	}
	return k;
}

int difference_set(int A[], int B[], int R[], int A_SZ, int B_SZ){
	int k = 0;
	for(int i=0; i<A_SZ; i++){
		int flag = 0;
		for(int j=0; j<B_SZ; j++){
			if(A[i] == B[j]){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			R[k++] = A[i];
		}
	}
	return k;
}

int complement_set(int A[], int R[], int U[], int A_SZ, int U_SZ){
	int d_size = difference_set(U, A, R, U_SZ, A_SZ);
	return d_size;
}

void cartesian_product(int A[], int B[]){
	printf("{\n");
	for(int i=0; i<N1; i++){
		printf("\t");
		for(int j=0; j<N2; j++){
			printf("(%d, %d), ", A[i], B[j]);
		}
		printf("\n");
	}
	printf("}\n");
}

void print_set(int A[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}


