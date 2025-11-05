//Program for File Handling - Reading, Processing, and Writing Integers
/*
Name: Alex Mwangi Mwihia
Reg No: CT100/G/26203/25
Description:
A program that reads 10 integers from the user, stores them in a file named "input.txt",
calculates their sum and average, writes the results to "output.txt",
and displays both files in a formatted manner with proper error handling.
*/

#include <stdio.h>
#include <stdlib.h>

void writeInputFile() {
    FILE *fptr;
    int i, num;

    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening input.txt for writing!\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fptr, "%d\n", num);
    }

    fclose(fptr);
    printf("\n✅ Data successfully written to input.txt\n\n");
}

void processFile() {
    FILE *fptr, *outptr;
    int num, count = 0, sum = 0;
    float avg;

    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("Error opening input.txt for reading!\n");
        exit(1);
    }

    while (fscanf(fptr, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(fptr);

    if (count == 0) {
        printf("No data found in input.txt!\n");
        return;
    }

    avg = (float) sum / count;

    outptr = fopen("output.txt", "w");
    if (outptr == NULL) {
        printf("Error opening output.txt for writing!\n");
        exit(1);
    }

    fprintf(outptr, "Sum: %d\nAverage: %.2f\n", sum, avg);
    fclose(outptr);

    printf("✅ Sum and average successfully written to output.txt\n\n");
}

void displayFiles() {
    FILE *fptr;
    char ch;

    printf("📄 Contents of input.txt:\n-------------------------\n");
    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("Error opening input.txt!\n");
        return;
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);

    printf("\n\n📄 Contents of output.txt:\n--------------------------\n");
    fptr = fopen("output.txt", "r");
    if (fptr == NULL) {
        printf("Error opening output.txt!\n");
        return;
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);

    printf("\n\n✅ Display completed successfully.\n");
}

int main() {
    writeInputFile();
    processFile();
    displayFiles();
    return 0;
}
