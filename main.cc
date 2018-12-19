#include <fstream>
#include <string>
#include <iostream>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cout << "Enter an argument to use as filename.\n";
		return 1;
	}

	const std::string filename = argv[1];

	// open the file
	std::ifstream buffer;
	buffer.open(filename, std::ifstream::in);

	// make sure the file could be opened before proceeding
	if (!buffer.is_open()) {
		std::cout << "Failed reading from the given file.\n";
		return 1;
	}

	// create an array to store the numbers read from the file
	size_t numbersCount = 1;
	int* numbers = new int[numbersCount];

	int totalSum = 0; // stores the total sum of read numbers

	// read from the buffer
	int number = 0;
	int counter = 0;
	while (buffer >> number) {
		counter++;
		// int number = std::stoi(str);
		if (counter > numbersCount) { // if we don't have space for another one allocate more
			int* tempNumbers = new int[counter]; // allocate new memory
			for (int i = 0; i < numbersCount; ++i) { // copy over the values from old array
				tempNumbers[i] = numbers[i];
			}
			numbersCount = counter; // update new array count
			delete[] numbers; // free old memory
			numbers = tempNumbers; // change what block of memory the pointer points to
		}
		numbers[counter - 1] = number; // add the number to the array
		totalSum += number; // add value to the total sum
	}

	const int average = totalSum / (int)numbersCount; // calculate the average of all the values

	// print out the numbers in the array
	std::cout << "Values: ";
	for (int i = 0; i < numbersCount; ++i)
		std::cout << numbers[i] << " ";

	std::cout << "\nAverage is: " << average << std::endl;

	// print all the numbers in the array that are above it's average
	std::cout << "Above average: ";
	for (int i = 0; i < numbersCount; ++i)
		if (numbers[i] > average) std::cout << numbers[i] << " ";

	delete[] numbers; // free up the allocated memory
	return 0;
}