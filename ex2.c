/******************
Name: Aviv Atzmon
ID: 323012799
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int choice;
	while (choice != 7) {
		// the menu is in while loop to match the exact output u got in the mission requirements
		printf("Choose an option:\n");
		printf("\t1. Happy Face\n");
		printf("\t2. Balanced Number\n");
		printf("\t3. Generous Number\n");
		printf("\t4. Circle Of Joy\n");
		printf("\t5. Happy Numbers\n");
		printf("\t6. Festival Of Numbers\n");
		printf("\t7. Exit\n");
		scanf("%d", &choice);
		if (choice > 7 || choice < 1) {
			printf("This option is not available, please try again.\n"); // Checks for correct input from user
			continue;
		}
		int num1, sum1 = 0, sum2 = 0, tempNum;
		switch (choice) {
			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			* n = 3:
			* 0   0
			*   o
			* \___/
			*/
			case 1: {
				char firstChar, secondChar, thirdChar;
				int faceSize;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &firstChar, &secondChar, &thirdChar);
				printf("Enter face size:\n");
				scanf("%d", &faceSize);
				while (faceSize < 1 || faceSize % 2 == 0) {
					//checks for correct input from user
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &faceSize);
				}
				printf("%c", firstChar); //First row Start
				for (int i = 0; i < faceSize; i++) {
					printf(" ");
				}
				printf("%c\n", firstChar); //First Row End
				for (int i = 0; i < (faceSize / 2) + 1; i++) {
					//Second row start
					printf(" ");
				}
				printf("%c\n", secondChar); // Second row End
				printf("\\"); //Third row star
				for (int i = 0; i < faceSize; i++) {
					printf("_");
				}
				printf("/\n"); //Third row end
				continue;
			}
			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not blanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/
			case 2: {
				printf("Enter a number:\n");
				scanf(" %d", &num1);
				while (num1 < 1) {       //checks for correct input from user
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num1);
				}
				tempNum = num1;
				int numSize = 0;
				while (1) {             // counts the number of digits in the number
					if (tempNum >= 10) {
						numSize++;
						tempNum /= 10;
					} else {
						numSize++;
						break;
					}
				}
				for (int i = 0; i < numSize / 2; i++) { // sums up the first half
					sum1 += num1 % 10;
					num1 /= 10;
				}
				for (int i = 0; i < numSize / 2; i++) { // sums up the second half
					sum2 += num1 % 10;
					num1 /= 10;
				}
				if (sum1 == sum2) {
					printf("This number is balanced and brings harmony!\n");
				} else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
				continue;
			}
			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/
			case 3: {
				printf("Enter a number:\n");
				scanf(" %d", &num1);
				while (num1 < 1) { //checks for correct input from user
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num1);
				}
				for (int i = 1; i <= (num1 / 2); i++) {
					if (num1 % i == 0) {
						sum1 += i;
					}
				}
				if (sum1 > num1) {
					printf("This number is generous!\n");
				} else {
					printf("This number does not share.\n");
				}
				continue;
			}
			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/
			case 4: {
				printf("Enter a number:\n");
				scanf(" %d", &num1);
				while (num1 < 1) { //checks for correct input from user
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num1);
				}
				tempNum = num1;
				int reverseNum = 0;
				while (tempNum != 0) {
					reverseNum = reverseNum * 10 + (tempNum % 10); // Add the last digit to reversed
					tempNum /= 10; // Remove the last digit
				}
				for (int i = 2; i <= num1 / 2; i++) {
					//Checking if the original number is a prime number
					if (num1 % i == 0) {
						sum1 += i; //Using the sum1 as a flag
					}
				}
				for (int i = 2; i <= reverseNum / 2; i++) {
					//Checking if the reversed number is a prime number
					if (reverseNum % i == 0) {
						sum2 += i; //Using the sum2 as a flag
					}
				}
				if (sum1 == 0 && sum2 == 0) {
					printf("This number completes the circle of joy!\n");
				} else {
					printf("The circle remains incomplete.\n");
				}
				continue;
			}
			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/
			case 5: {
				printf("Enter a number:\n");
				scanf(" %d", &num1);
				while (num1 < 1) { //checks for correct input from user
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num1);
				}
				printf("Between 1 and %d only these numbers bring happiness: ", num1);
				for (int i = 1; i <= num1; i++) {
					tempNum = i;
					int iteration_count = 0; // Track iterations to prevent infinite loops
					// Check if the number is happy
					while (tempNum != 1 && iteration_count < 100) { // Stop after 100 iterations to prevent infinite loops
						int sum = 0;
						// Calculate the sum of the squares of the digits
						while (tempNum > 0) {
							int digit = tempNum % 10;
							sum += digit * digit;
							tempNum /= 10;
						}
						tempNum = sum; // Update current to the sum of squares
						iteration_count++;
					}
					// If the number ends at 1, it's a happy number
					if (tempNum == 1) {
						printf("%d ", i);
					}
				}
				printf("\n");
				continue;
			}
			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/
			case 6: {
				int numSmile = 0, numCheer = 0;
				printf("Enter a smile and cheer number:\n");
				scanf("smile: %d, cheer: %d", &numSmile, &numCheer);
				while (numCheer == numSmile || numCheer < 1 || numSmile < 1) { //checks for correct input from the user
					scanf("%*c");
					// clears the buffer -  I cleared the buffer multiple times because if i wont the print in this while would print multiple times for some reason I couldnt figure out
					scanf("%*c"); // clears the buffer
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					scanf("smile: %d, cheer: %d", &numSmile, &numCheer);
					scanf("%*[^\n]");
				}
				printf("Enter maximum number for the festival: \n");
				scanf(" %d", &num1);
				while (num1 < 1) {
					//checks for correct input from user
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num1);
				}
				for (int i = 1; i <= num1; i++) {
					if (i % numSmile == 0 && i % numCheer == 0) {
						//checks if the number is divider of both cheer and smile number
						printf("Festival!\n");
					} else if (i % numCheer == 0) {
						// checks if the number is a divider by the chosen cheer number
						printf("Cheer!\n");
					} else if (i % numSmile == 0) {
						// checks if the number is a divider by the chosen smile number
						printf("Smile!\n");
					} else {
						// prints the number itself
						printf("%d\n", i);
					}
				}
				continue;
			}
			case 7: {
				printf("Thank you for your journey through Numeria!\n");
				break;
			}
		}
	}
	return 0;
}
