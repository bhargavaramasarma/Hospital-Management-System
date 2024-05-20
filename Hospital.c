#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    char gender;
    char disease[NAME_LENGTH];
} Patient;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char specialization[NAME_LENGTH];
    int experience; // in years
} Doctor;

Patient patients[MAX_RECORDS];
Doctor doctors[MAX_RECORDS];

int patientCount = 0;
int doctorCount = 0;

// Function declarations
void addPatient();
void viewPatients();
void deletePatient();
void addDoctor();
void viewDoctors();
void deleteDoctor();
void searchPatient();
void searchDoctor();
void saveRecords();
void loadRecords();

int main() {
    loadRecords();
    int choice;
    do {
        printf("\nPES University Hospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Delete Patient\n");
        printf("4. Add Doctor\n");
        printf("5. View Doctors\n");
        printf("6. Delete Doctor\n");
        printf("7. Search Patient\n");
        printf("8. Search Doctor\n");
        printf("9. Save Records\n");
        printf("10. Load Records\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: deletePatient(); break;
            case 4: addDoctor(); break;
            case 5: viewDoctors(); break;
            case 6: deleteDoctor(); break;
            case 7: searchPatient(); break;
            case 8: searchDoctor(); break;
            case 9: saveRecords(); break;
            case 10: loadRecords(); break;
            case 11: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 11);

    return 0;
}

void addPatient() {
    if (patientCount >= MAX_RECORDS) {
        printf("Cannot add more patients. Storage full.\n");
        return;
    }
    Patient p;
    p.id = patientCount + 1;
    printf("Enter patient name: ");
    scanf(" %[^\n]%*c", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter gender (M/F): ");
    scanf(" %c", &p.gender);
    printf("Enter disease: ");
    scanf(" %[^\n]%*c", p.disease);

    patients[patientCount++] = p;
    printf("Patient added successfully!\n");
}

void viewPatients() {
    if (patientCount == 0) {
        printf("No patient records found.\n");
        return;
    }
    for (int i = 0; i < patientCount; i++) {
        printf("\nPatient ID: %d\nName: %s\nAge: %d\nGender: %c\nDisease: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].disease);
    }
}

void deletePatient() {
    int id;
    printf("Enter patient ID to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            printf("Patient record deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Patient ID not found.\n");
    }
}

void addDoctor() {
    if (doctorCount >= MAX_RECORDS) {
        printf("Cannot add more doctors. Storage full.\n");
        return;
    }
    Doctor d;
    d.id = doctorCount + 1;
    printf("Enter doctor name: ");
    scanf(" %[^\n]%*c", d.name);
    printf("Enter specialization: ");
    scanf(" %[^\n]%*c", d.specialization);
    printf("Enter experience (in years): ");
    scanf("%d", &d.experience);

    doctors[doctorCount++] = d;
    printf("Doctor added successfully!\n");
}

void viewDoctors() {
    if (doctorCount == 0) {
        printf("No doctor records found.\n");
        return;
    }
    for (int i = 0; i < doctorCount; i++) {
        printf("\nDoctor ID: %d\nName: %s\nSpecialization: %s\nExperience: %d years\n", doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].experience);
    }
}

void deleteDoctor() {
    int id;
    printf("Enter doctor ID to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == id) {
            found = 1;
            for (int j = i; j < doctorCount - 1; j++) {
                doctors[j] = doctors[j + 1];
            }
            doctorCount--;
            printf("Doctor record deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Doctor ID not found.\n");
    }
}

void searchPatient() {
    int choice;
    printf("Search patient by:\n1. Name\n2. ID\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char name[NAME_LENGTH];
        printf("Enter patient name: ");
        scanf(" %[^\n]%*c", name);
        int found = 0;
        for (int i = 0; i < patientCount; i++) {
            if (strcmp(patients[i].name, name) == 0) {
                printf("\nPatient ID: %d\nName: %s\nAge: %d\nGender: %c\nDisease: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].disease);
                found = 1;
            }
        }
        if (!found) {
            printf("Patient not found.\n");
        }
    } else if (choice == 2) {
        int id;
        printf("Enter patient ID: ");
        scanf("%d", &id);
        int found = 0;
        for (int i = 0; i < patientCount; i++) {
            if (patients[i].id == id) {
                printf("\nPatient ID: %d\nName: %s\nAge: %d\nGender: %c\nDisease: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].disease);
                found = 1;
            }
        }
        if (!found) {
            printf("Patient not found.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
}

void searchDoctor() {
    int choice;
    printf("Search doctor by:\n1. Name\n2. ID\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char name[NAME_LENGTH];
        printf("Enter doctor name: ");
        scanf(" %[^\n]%*c", name);
        int found = 0;
        for (int i = 0; i < doctorCount; i++) {
            if (strcmp(doctors[i].name, name) == 0) {
                printf("\nDoctor ID: %d\nName: %s\nSpecialization: %s\nExperience: %d years\n", doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].experience);
                found = 1;
            }
        }
        if (!found) {
            printf("Doctor not found.\n");
        }
    } else if (choice == 2) {
        int id;
        printf("Enter doctor ID: ");
        scanf("%d", &id);
        int found = 0;
        for (int i = 0; i < doctorCount; i++) {
            if (doctors[i].id == id) {
                printf("\nDoctor ID: %d\nName: %s\nSpecialization: %s\nExperience: %d years\n", doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].experience);
                found = 1;
            }
        }
        if (!found) {
            printf("Doctor not found.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
}

void saveRecords() {
    FILE *fp;
    fp = fopen("patients.dat", "wb");
    if (fp == NULL) {
        printf("Error saving patient records.\n");
        return;
    }
    fwrite(&patientCount, sizeof(int), 1, fp);
    fwrite(patients, sizeof(Patient), patientCount, fp);
    fclose(fp);

    fp = fopen("doctors.dat", "wb");
    if (fp == NULL) {
        printf("Error saving doctor records.\n");
        return;
    }
    fwrite(&doctorCount, sizeof(int), 1, fp);
    fwrite(doctors, sizeof(Doctor), doctorCount, fp);
    fclose(fp);

    printf("Records saved successfully.\n");
}

void loadRecords() {
    FILE *fp;
    fp = fopen("patients.dat", "rb");
    if (fp != NULL) {
        fread(&patientCount, sizeof(int), 1, fp);
        fread(patients, sizeof(Patient), patientCount, fp);
        fclose(fp);
        printf("Patient records loaded successfully.\n");
    } else {
        printf("Error: Unable to load patient records.\n");
    }

    fp = fopen("doctors.dat", "rb");
    if (fp != NULL) {
        fread(&doctorCount, sizeof(int), 1, fp);
        fread(doctors, sizeof(Doctor), doctorCount, fp);
        fclose(fp);
        printf("Doctor records loaded successfully.\n");
    } else {
        printf("Error: Unable to load doctor records.\n");
    }
}

