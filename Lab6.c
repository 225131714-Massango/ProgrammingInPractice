#include <stdio.h>
#include <string.h>

/* ---- Part A: Employee Salaries ---- */
void partA() {
    float salaries[50];
    float total = 0, highest, lowest, average;
    float searchSalary;
    int found = 0;

    printf("\n===== PART A: Employee Salaries =====\n");

    /* Capture 50 salaries */
    for (int i = 0; i < 50; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
        total = total + salaries[i];

        if (i == 0) {
            highest = salaries[0];
            lowest = salaries[0];
        } else {
            if (salaries[i] > highest) {
                highest = salaries[i];
            }
            if (salaries[i] < lowest) {
                lowest = salaries[i];
            }
        }
    }

    average = total / 50;

    /* Display all salaries */
    printf("\n--- All Employee Salaries ---\n");
    for (int i = 0; i < 50; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    /* Display summary */
    printf("\n--- Salary Summary ---\n");
    printf("Total salary expenditure: %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    /* Search for a particular salary */
    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);
    found = 0;
    for (int i = 0; i < 50; i++) {
        if (salaries[i] == searchSalary) {
            printf("Salary %.2f found at position %d (Employee %d)\n",
                   searchSalary, i, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Salary %.2f not found.\n", searchSalary);
    }

    /* Sort salaries from lowest to highest (bubble sort) */
    float temp;
    for (int i = 0; i < 50 - 1; i++) {
        for (int j = 0; j < 50 - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    /* Display sorted salaries */
    printf("\n--- Salaries Sorted (Lowest to Highest) ---\n");
    for (int i = 0; i < 50; i++) {
        printf("%d: %.2f\n", i + 1, salaries[i]);
    }
}

/* ---- Part B: Department Budgets ---- */
void partB() {
    float budgets[10];
    float total = 0, average;
    float temp;

    printf("\n===== PART B: Department Budgets =====\n");

    /* Capture 10 department budgets */
    for (int i = 0; i < 10; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
        total = total + budgets[i];
    }

    average = total / 10;

    /* Display all budgets */
    printf("\n--- All Department Budgets ---\n");
    for (int i = 0; i < 10; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    /* Display summary */
    printf("\n--- Budget Summary ---\n");
    printf("Total municipal budget: %.2f\n", total);
    printf("Average department budget: %.2f\n", average);

    /* Sort budgets from lowest to highest (bubble sort) */
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    /* Display sorted budgets */
    printf("\n--- Budgets Sorted (Lowest to Highest) ---\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %.2f\n", i + 1, budgets[i]);
    }
}

/* ---- Part C: Vehicle Registration Numbers ---- */
void partC() {
    char registrations[20][20];
    char searchReg[20];
    int found = 0;

    printf("\n===== PART C: Vehicle Registration Numbers =====\n");

    /* Capture 20 registration numbers */
    for (int i = 0; i < 20; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    /* Display all registration numbers */
    printf("\n--- All Vehicle Registrations ---\n");
    for (int i = 0; i < 20; i++) {
        printf("Vehicle %d: %s\n", i + 1, registrations[i]);
    }

    /* Search for a particular registration number */
    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchReg);
    found = 0;
    for (int i = 0; i < 20; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            printf("Registration \"%s\" found at position %d (Vehicle %d)\n",
                   searchReg, i, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Registration \"%s\" not found.\n", searchReg);
    }
}

/* ---- Main: Run all three parts ---- */
int main() {
    printf("MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n");
    printf("======================================\n");

    partA();  /* Employee Salaries */
    partB();  /* Department Budgets */
    partC();  /* Vehicle Registration Numbers */

    printf("\nAll parts completed.\n");
    return 0;
}
