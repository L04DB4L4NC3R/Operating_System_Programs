// HAMMING CODE FOR 4 BIT WORD

#include <stdio.h>
#include <stdbool.h>

void Print(bool arr[]) {
	printf("\n");
	for(int i=0; i<7; i++) {
		printf("%d", arr[i]);
	}

}


void Sender(bool arr[]) {


	printf("\nEnter the 4 bit word: ");
	scanf("%d", &arr[0]);
	scanf("%d", &arr[1]);
    scanf("%d", &arr[2]);
    scanf("%d", &arr[4]);

	// Calculate even parity
	arr[6] = arr[0]^arr[2]^arr[4];
	arr[5] = arr[0]^arr[1]^arr[4];
	arr[3] = arr[0]^arr[1]^arr[2];
	Print(arr);
}


void Receiver(bool arr[]) {

	bool c1, c2, c3, c;
	
	c1 = arr[6]^arr[0]^arr[2]^arr[4];
	c2 = arr[5]^arr[0]^arr[1]^arr[4];
	c3 = arr[3]^arr[0]^arr[1]^arr[2];
	c = 4*c3 + 2*c2 + c1;

	if(c==0) {
		printf("\nNo error\n");
	} else {
		printf("\nError occurred at position: %d\n", c);
	}

}

void main() {

	bool arr[20];
	Sender(arr);
	Receiver(arr);
}
