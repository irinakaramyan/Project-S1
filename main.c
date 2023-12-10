/**
 * @file hospital_management.c
 * @brief Implementation of a Hospital Management System (HMS) in C.
 * @details This program allows users to interact with a simplified HMS,
 * including functionalities for adding patients, displaying patient information,
 * searching for patients, modifying patient details, and exiting the system.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct Patient
 * @brief Structure representing a patient in the Hospital Management System.
 * @details The Patient structure encapsulates essential information about a patient,
 * including their ID, name, age, gender, address, and diagnosed disease.
 */
struct Patient {
    int id; /**< Unique identifier for the patient */
    char name[50]; /**< Name of the patient */
    int age; /**< Age of the patient */
    char gender; /**< Gender of the patient */
    char address[100]; /**< Address of the patient */
    char disease[50]; /**< Diagnosed disease of the patient */
};

/**
 * @brief Function to generate a unique patient ID.
 * @return Returns a unique patient ID.
 */
int generatePatientID() {
    static int idCounter = 1;
    return idCounter++;
}

/**
 * @brief Function to add a new patient to the HMS.
 * @param[in,out] patients An array of Patient structures representing the patient database.
 * @param[in,out] patientCount A pointer to the current count of patients in the system.
 */
void addPatient(struct Patient patients[], int *patientCount) {
    printf("Enter patient details:\n");

    patients[*patientCount].id = generatePatientID();

    printf("Name: ");
    scanf("%s", patients[*patientCount].name);

    printf("Age: ");
    scanf("%d", &patients[*patientCount].age);

    printf("Gender (M/F): ");
    scanf(" %c", &patients[*patientCount].gender);

    printf("Address: ");
    scanf("%s", patients[*patientCount].address);

    printf("Disease: ");
    scanf("%s", patients[*patientCount].disease);

    printf("Patient added successfully! Patient ID: %d\n", patients[*patientCount].id);

    (*patientCount)++;
}

/**
 * @brief Function to display information about all patients in the HMS.
 * @param[in] patients An array of Patient structures representing the patient database.
 * @param[in] patientCount The current count of patients in the system.
 */
void displayPatients(struct Patient patients[], int patientCount) {
    if (patientCount == 0) {
        printf("No patients to display.\n");
    } else {
        printf("List of Patients:\n");

        for (int i = 0; i < patientCount; i++) {
            printf("Patient ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %c\n", patients[i].gender);
            printf("Address: %s\n", patients[i].address);
            printf("Disease: %s\n", patients[i].disease);
            printf("\n");
        }
    }
}

/**
 * @brief Function to search for a patient by ID in the HMS.
 * @param[in] patients An array of Patient structures representing the patient database.
 * @param[in] patientCount The current count of patients in the system.
 */
void searchPatient(struct Patient patients[], int patientCount) {
    if (patientCount == 0) {
        printf("No patients to search.\n");
        return;
    }

    int searchID;
    printf("Enter the Patient ID to search: ");
    scanf("%d", &searchID);

    int found = 0;
    for (int i = 0; i < patientCount; i++) {
        if (searchID == patients[i].id) {
            printf("Patient found!\n");
            printf("Patient ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %c\n", patients[i].gender);
            printf("Address: %s\n", patients[i].address);
            printf("Disease: %s\n", patients[i].disease);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }
}

/**
 * @brief Function to modify patient details in the HMS.
 * @param[in,out] patients An array of Patient structures representing the patient database.
 * @param[in] patientCount The current count of patients in the system.
 */
void modifyPatient(struct Patient patients[], int patientCount) {
    if (patientCount == 0) {
        printf("No patients to modify.\n");
        return;
    }

    int modifyID;
    printf("Enter the Patient ID to modify: ");
    scanf("%d", &modifyID);

    int found = 0;
    for (int i = 0; i < patientCount; i++) {
        if (modifyID == patients[i].id) {
            printf("Enter new details for Patient ID %d:\n", patients[i].id);

            printf("Name: ");
            scanf("%s", patients[i].name);

            printf("Age: ");
            scanf("%d", &patients[i].age);

            printf("Gender (M/F): ");
            scanf(" %c", &patients[i].gender);

            printf("Address: ");
            scanf("%s", patients[i].address);

            printf("Disease: ");
            scanf("%s", patients[i].disease);

            printf("Patient details modified successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }
}

/**
 * @brief Main function of the HMS program.
 * @return Returns 0 upon successful execution.
 */
int main() {
    struct Patient patients[100]; // Assuming a maximum of 100 patients
    int patientCount = 0;
    int choice;

    do {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Modify Patient Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(patients, &patientCount);
                break;
            case 2:
                displayPatients(patients, patientCount);
                break;
            case 3:
                searchPatient(patients, patientCount);
                break;
            case 4:
                modifyPatient(patients, patientCount);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
