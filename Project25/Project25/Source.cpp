#include <iostream>
#include <memory>

int main(void) {
	int integer1 = 0;
	int integer2 = 0;
	int array1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int array2[] = { 11,12,13,14,15,16,17,18,19,20 };
	int array3[20];
	
	for (int i = 0; i < 20; i += 2) {
		array3[i] = array1[integer1];
		integer1++;
	}
	for (int i = 1; i < 20; i += 2) {
		array3[i] = array2[integer2];
		integer2++;
	}
	for (int i = 0; i < 20; i++) {
		std::cout << array3[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}