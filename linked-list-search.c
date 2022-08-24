#include <stdio.h>
#include <stdlib.h>

struct digit {
	int num;
	struct digit * next;
};

int thankYou();
struct digit * createDigit(int dig);
struct digit * append(struct digit * end, struct digit * newDigitPtr);
void printDigits(struct digit *);
void freeDigits(struct digit * start);
struct digit * readDigits();
struct digit * searchDigit(struct digit * start, int num);

int main(void) {

	struct digit *start;
	
	start = readDigits();

	printDigits(start);

	int searchDig;
	printf("Please enter a digit for search.\n> ");
	scanf("%d", &searchDig);
	printf("\nSearching struct digit{%d}\n", searchDig);
	struct digit * ptr = searchDigit(start, searchDig);
	if (ptr!=NULL) {
		printf("Found struct digit{%d} at location %p.\n", searchDig, ptr);
	} else {
		printf("struct digit{%d} not found.\n", searchDig);
	}

	freeDigits(start);

	return thankYou();
}

int thankYou() {
	printf("\nThank you for using ThankYou-Bot!\n\n");
	return 0;
}

struct digit * createDigit(int dig) {
	struct digit * ptr;
	ptr = (struct digit *) malloc(sizeof(struct digit));
	ptr->num = dig;
	ptr->next = NULL;
	return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigitPtr) {
	end->next = newDigitPtr;
	end = newDigitPtr;
	return end;
}

void printDigits(struct digit * start) {
	struct digit * ptr = start;
	int index = 1;
	printf("\nPrinting Linked digit Structure\n");
	while (ptr!=NULL) {
		printf("%3d. struct digit{%d};\n", index, ptr->num);
		ptr = ptr->next;
		index++;
	}
}

void freeDigits(struct digit * start) {
	struct digit * ptr = start;
	struct digit * tmp;
	while (ptr!=NULL) {
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}

struct digit * readDigits(){
	char cDig;
	int dig;
	int asciiDig = 48;
	struct digit * start, * end, * newPtr;
	start = NULL;

	printf("Please enter an integer.\n> ");
	scanf("%c", &cDig);
	while (cDig!='\n') {
		dig = cDig - asciiDig;
		newPtr = createDigit(dig);
		if (start == NULL) {
			start = newPtr;
			end = start;
		} else {
			end = append(end, newPtr);
		}
		scanf("%c", &cDig);
	}
	return start;
}

struct digit * searchDigit(struct digit * start, int num) {
	struct digit * ptr = start;
	while (ptr!=NULL && ptr->num!=num) {
		ptr = ptr->next;
	}
	return ptr;
}
