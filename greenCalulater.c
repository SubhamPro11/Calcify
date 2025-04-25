#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

double getNumber(const char* prompt) {
    double num;
    char input[100];
    
    while (1) {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) != NULL) {
            char* endptr;
            num = strtod(input, &endptr);
            
            // Check if conversion was successful and input is valid
            if (endptr != input && (*endptr == '\n' || *endptr == '\0')) {
                return num;
            }
        }
        printf("Invalid input. Please enter a valid number.\n");
    }
}

int main() {
    char choice;
    double num1, num2, result;
    int running = 1;
    
    printf("===== Advanced Calculator =====\n");
    
    while (running) {
        printf("\nOperations:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Power (^)\n");
        printf("6. Square Root (√)\n");
        printf("7. Modulus (%%)\n");
        printf("8. Sin(x) - in radians\n");
        printf("9. Cos(x) - in radians\n");
        printf("0. Exit\n");
        printf("Enter your choice (0-9): ");
        
        choice = getchar();
        clearInputBuffer();
        
        switch (choice) {
            case '0':
                printf("Thank you for using the calculator. Goodbye!\n");
                running = 0;
                break;
                
            case '1': // Addition
                num1 = getNumber("Enter first number: ");
                num2 = getNumber("Enter second number: ");
                result = num1 + num2;
                printf("Result: %.4lf\n", result);
                break;
                
            case '2': // Subtraction
                num1 = getNumber("Enter first number: ");
                num2 = getNumber("Enter second number: ");
                result = num1 - num2;
                printf("Result: %.4lf\n", result);
                break;
                
            case '3': // Multiplication
                num1 = getNumber("Enter first number: ");
                num2 = getNumber("Enter second number: ");
                result = num1 * num2;
                printf("Result: %.4lf\n", result);
                break;
                
            case '4': // Division
                num1 = getNumber("Enter numerator: ");
                num2 = getNumber("Enter denominator: ");
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed!\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.4lf\n", result);
                }
                break;
                
            case '5': // Power
                num1 = getNumber("Enter base: ");
                num2 = getNumber("Enter exponent: ");
                result = pow(num1, num2);
                printf("Result: %.4lf\n", result);
                break;
                
            case '6': // Square Root
                num1 = getNumber("Enter number: ");
                if (num1 < 0) {
                    printf("Error: Cannot calculate square root of a negative number!\n");
                } else {
                    result = sqrt(num1);
                    printf("Result: %.4lf\n", result);
                }
                break;
                
            case '7': // Modulus
                num1 = getNumber("Enter dividend: ");
                num2 = getNumber("Enter divisor: ");
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed!\n");
                } else {
                    result = fmod(num1, num2);
                    printf("Result: %.4lf\n", result);
                }
                break;
                
            case '8': // Sine
                num1 = getNumber("Enter angle in radians: ");
                result = sin(num1);
                printf("Sin(%.4lf) = %.4lf\n", num1, result);
                break;
                
            case '9': // Cosine
                num1 = getNumber("Enter angle in radians: ");
                result = cos(num1);
                printf("Cos(%.4lf) = %.4lf\n", num1, result);
                break;
                
            default:
                printf("Invalid choice! Please select a valid option (0-9).\n");
        }
    }
    
    return 0;
}
