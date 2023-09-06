#include <stdio.h>
#include <string.h>

struct Student {
    char id[20];
    char name[50];
    int age;
    float cgpa;
    char address[100];
    char contactNo[15];
};

void addStudent(struct Student students[], int *numStudents) {

    struct Student newStudent;

    printf("\tAdd Student\n");

    printf("\nEnter ID: ");
    scanf(" %s", newStudent.id);

    printf("Enter Name: ");
    scanf(" %[^\n]s", newStudent.name);

    printf("Enter Age: ");
    scanf("%d", &newStudent.age);

    float newCgpa;
    do {
        printf("Enter CGPA: ");
        scanf("%f", &newCgpa);
        if (newCgpa < 0 || newCgpa > 4) {
            printf("Invalid CGPA. Please enter a value between 0 and 4.\n");
        }
    } while (newCgpa < 0 || newCgpa > 4);
    newStudent.cgpa = newCgpa;

    printf("Enter Address: ");
    scanf(" %[^\n]s", newStudent.address);

    printf("Enter Contact No: ");
    scanf(" %[^\n]s", newStudent.contactNo);

    students[*numStudents] = newStudent;
    (*numStudents)++;

    printf("Student added successfully!\n");
}

void removeStudent(struct Student students[], int *numStudents, const char idToRemove[]) {
    int foundIndex = -1;
    for (int i = 0; i < *numStudents; i++) {
        if (strcmp(students[i].id, idToRemove) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < *numStudents - 1; i++) {
            students[i] = students[i + 1];
        }
        (*numStudents)--;
        printf("Student with ID %s removed.\n", idToRemove);
    } else {
        printf("Student with ID %s not found.\n", idToRemove);
    }
}

void displayStudents(struct Student students[], int numStudents) {
    printf("\nStudents:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: %s\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("CGPA: %.2f\n", students[i].cgpa);
        printf("Address: %s\n", students[i].address);
        printf("Contact No: %s\n\n", students[i].contactNo);
    }
}

int searchStudent(struct Student students[], int numStudents, const char searchId[]) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].id, searchId) == 0) {
            printf("Student found:\n");
            displayStudents(&students[i], 1);
            return i;
        }
    }
    printf("Student with ID %s not found.\n", searchId);
    return -1;
}

void updateStudent(struct Student students[], int indexToUpdate) {
    int choice;

    while (choice != 6) {
        printf("\nSelect field to update:\n");
        printf("1. Name\n");
        printf("2. Age\n");
        printf("3. CGPA\n");
        printf("4. Address\n");
        printf("5. Contact No\n");
        printf("6. Go back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter updated name: ");
                scanf(" %[^\n]s", students[indexToUpdate].name);
                break;
            case 2:
                printf("Enter updated age: ");
                scanf("%d", &students[indexToUpdate].age);
                break;
            case 3: {
                float newCgpa;
                do {
                    printf("Enter updated CGPA: ");
                    scanf("%f", &newCgpa);
                    if (newCgpa < 0 || newCgpa > 4) {
                        printf("Invalid CGPA. Please enter a value between 0 and 4.\n");
                    }
                } while (newCgpa < 0 || newCgpa > 4);
                students[indexToUpdate].cgpa = newCgpa;
                break;
            }
            case 4:
                printf("Enter updated address: ");
                scanf(" %[^\n]s", students[indexToUpdate].address);
                break;
            case 5:
                printf("Enter updated contact no: ");
                scanf(" %[^\n]s", students[indexToUpdate].contactNo);
                break;
            case 6:
                printf("Going back to the main menu.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    }

    printf("Student information updated!\n");
}

void generateResultSheet(struct Student students[], int numStudents) {
    // TODO: Implement sorting based on CGPA in descending order
    printf("\nResult Sheet:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("ID: %s, Name: %s, CGPA: %.2f\n", students[i].id, students[i].name, students[i].cgpa);
    }
}

int main() {
    struct Student students[100];
    int numStudents = 0;

    int choice;
    char id[10];

    while (choice != 7) {
        printf("Student Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display Students\n");
        printf("4. Search Student\n");
        printf("5. Update Student\n");
        printf("6. Generate Result Sheet\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                printf("\tRemove Student\n");
                printf("\nEnter student ID to remove: ");
                scanf(" %s", id);
                removeStudent(students, &numStudents, id);
                break;
            case 3:
                printf("\tDisplay Students\n");
                displayStudents(students, numStudents);
                break;
            case 4:
                printf("\tSearch Student\n");
                printf("\nEnter student ID to search: ");
                scanf(" %s", id);
                searchStudent(students, numStudents, id);
                break;
            case 5: {
                printf("\tUpdate Student\n");
                printf("\nEnter student ID to update: ");
                scanf(" %s", id);
                int index = searchStudent(students, numStudents, id);
                if (index != -1) {
                    updateStudent(students, index);
                }
                break;
            }
            case 6:
                printf("\tResult Sheet\n");
                generateResultSheet(students, numStudents);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}