#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a patient
struct Patient {
    int id;
    char name[100];
    char dob[12];
    char gender[10];
    char address[200];
    char phone[15];
};

// Define a structure to represent an appointment
struct Appointment {
    int id;
    int patientId;
    char date[12];
    char time[10];
    char doctor[100];
};

// Global arrays to store patient and appointment records
struct Patient patients[100];
struct Appointment appointments[100];
int patientCount = 0;
int appointmentCount = 0;

// Function to add a new patient
void addPatient() {
    struct Patient patient;

    printf("Enter patient name: ");
    scanf("%s", patient.name);
    printf("Enter patient date of birth (DD-MM-YYYY): ");
    scanf("%s", patient.dob);
    printf("Enter patient gender: ");
    scanf("%s", patient.gender);
    printf("Enter patient address: ");
    scanf("%s", patient.address);
    printf("Enter patient phone number: ");
    scanf("%s", patient.phone);

    patient.id = patientCount + 1;
    patients[patientCount++] = patient;

    printf("Patient added successfully!\n");
}

// Function to schedule a new appointment
void scheduleAppointment() {
    struct Appointment appointment;

    printf("Enter patient ID: ");
    scanf("%d", &appointment.patientId);
    printf("Enter appointment date (DD-MM-YYYY): ");
    scanf("%s", appointment.date);
    printf("Enter appointment time (HH:MM AM/PM): ");
    scanf("%s", appointment.time);
    printf("Enter doctor's name: ");
    scanf("%s", appointment.doctor);

    appointment.id = appointmentCount + 1;
    appointments[appointmentCount++] = appointment;

    printf("Appointment scheduled successfully!\n");
}

// Function to display patient records
void displayPatients() {
    printf("Patient Records:\n");
    printf("ID\tName\t\tDOB\t\tAddress\t\tPhone\n");

    for (int i = 0; i < patientCount; i++) {
        struct Patient patient = patients[i];
        printf("%d\t%s\t%s\t%s\t%s\t%s\n", patient.id, patient.name, patient.dob, patient.gender, patient.address, patient.phone);
    }
}

// Function to display appointment records
void displayAppointments() {
    printf("Appointment Records:\n");
    printf("ID\tPatient ID\tDate\tTime\tDoctor\n");

    for (int i = 0; i < appointmentCount; i++) {
        struct Appointment appointment = appointments[i];
        printf("%d\t%d\t%s\t%s\t%s\n", appointment.id, appointment.patientId, appointment.date, appointment.time, appointment.doctor);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Schedule Appointment\n");
        printf("3. Display Patients\n");
        printf("4. Display Appointments\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                scheduleAppointment();
                break;
            case 3:
                displayPatients();
                break;
            case 4:
                displayAppointments();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
