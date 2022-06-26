// WAP a C program to find union intersection difference and complement of two
// sets using bit string notation
#include <stdio.h>

void union_bits(int *U_A_B, int *A, int *B, int U_SZ) ;
void intersection_bits(int *I_A_B, int *A, int *B, int U_SZ) ;
void difference_bits(int *D_A_B, int *A, int *B, int U_SZ) ;
void complement_bits(int *C_A, int *A, int U_SZ) ;
void print_bits(int *A, int *U, int U_SZ);

int main() {
	int U[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int U_SZ = sizeof(U) / sizeof(int);
	
	// bit string representation of U
	char U_BSTR[U_SZ];
	for (int i = 0; i < U_SZ; i++) {
		U_BSTR[i] = U[i];
	}

	// Bit string representation of A = [1,2,3,4,5]
	int A[] = {0, 1, 1, 1, 1, 1, 0, 0, 0, 0};
	// Bit string representation of B = [5, 6, 7, 8, 9]
	int B[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};

	// Union of A and B
	int U_A_B[U_SZ];
	union_bits(U_A_B, A, B, U_SZ);
	printf("Union of A and B\n");
	print_bits(U_A_B, U, U_SZ);

	// Intersection of A and B
	int I_A_B[U_SZ];
	intersection_bits(I_A_B, A, B, U_SZ);
	printf("Intersection of A and B\n");
	print_bits(I_A_B, U, U_SZ);


	// Difference of A and B
	int D_A_B[U_SZ];
	difference_bits(D_A_B, A, B, U_SZ);
	printf("Difference of A and B\n");
	print_bits(D_A_B, U, U_SZ);

	// Complement of A
	int C_A[U_SZ];
	complement_bits(C_A, A, U_SZ);
	printf("Complement of A\n");
	print_bits(C_A, U, U_SZ);

}

void union_bits(int *U_A_B, int *A, int *B, int U_SZ) {
	for (int i = 0; i < U_SZ; i++) {
		U_A_B[i] = A[i] | B[i];
	}
}

void intersection_bits(int *I_A_B, int *A, int *B, int U_SZ) {
	for (int i = 0; i < U_SZ; i++) {
		I_A_B[i] = A[i] & B[i];
	}
}

void difference_bits(int *D_A_B, int *A, int *B, int U_SZ) {
	for (int i = 0; i < U_SZ; i++) {
		if (A[i]){
		D_A_B[i] = A[i] & B[i]?0:1;
		}
	}
}

void complement_bits(int *C_A, int *A, int U_SZ) {
	for (int i = 0; i < U_SZ; i++) {
		C_A[i] = A[i]?0:1;
	}
}

void print_bits(int *A, int *U, int U_SZ) {
	printf("{");
	for (int i = 0; i < U_SZ; i++) {
		if (A[i] == 1) {
			printf("%d, ", U[i]);
		}
	}
	printf("}\n");
}
