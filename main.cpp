#include <cstdlib>
#include <iostream>

using namespace std;

void print(int numbers[], int size);
void countingSort(int numbers[], int size);

int main(int argc, char *argv[]) {
    int numbers[] = {1, 4, 1, 2, 7, 5, 2};
    int size = sizeof(numbers) / sizeof(*numbers);

    print(numbers, size);
    countingSort(numbers, size);
    print(numbers, size);
    
    system("read");
    return EXIT_SUCCESS;
}

void print(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

void countingSort(int numbers[], int size) {
    int max = numbers[0];
	for( int i=1; i<size; i++){
		if( max < numbers[i]) max = numbers[i];
	}

	int* values = new int[max+1];
	int* sorted = new int[size];

	for(int i=0; i<max; i++){
		values[numbers[i]]++;
	}

	for(int i=1; i<=max; i++){
		values[i] += values[i-1];
	}

	for(int i=0; i<size; i++){
		sorted[values[numbers[i]]-1] = numbers[i];
        --values[numbers[i]]; 

	}
	for(int i=0; i<size; i++){
		numbers[i] = sorted[i];
	}
}
