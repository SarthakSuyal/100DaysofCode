/*
Q147: Store employee data in a binary file using fwrite() and read using fread().

Sample Test Cases:
Input 1:
Employee details entered and stored in file.
Output 1:
Displays employee data read from file.

Explanation 1:
Demonstrates writing and reading structures using binary file handling functions.
*/

#include <stdio.h>

struct Employee {
    char name[100];
    int id;
    float salary;
};

int main() {
    struct Employee e, readEmp;
    FILE *fp;

    printf("Enter employee name: ");
    scanf("%s", e.name);
    printf("Enter employee ID: ");
    scanf("%d", &e.id);
    printf("Enter employee salary: ");
    scanf("%f", &e.salary);

    fp = fopen("employee.dat", "wb");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    fwrite(&e, sizeof(struct Employee), 1, fp);
    fclose(fp);

    fp = fopen("employee.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fread(&readEmp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("\nEmployee Data from File:\n");
    printf("Name: %s\n", readEmp.name);
    printf("ID: %d\n", readEmp.id);
    printf("Salary: %.2f\n", readEmp.salary);

    return 0;
}