#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
void calculateAverages(const string names[], const int scores[][5], double averages[], char grades[], int size);
char determineGrade(double avg);
void displayResults(const string names[], const double averages[], const char grades[], int size);

int main() {
    const int NUM_STUDENTS = 6;
    const int NUM_TESTS = 5;

    // Parallel arrays
    string names[NUM_STUDENTS] = { "Aaliyah", "Briana", "Devon", "Javier", "Johnathan", "Vanessa" };
    int scores[NUM_STUDENTS][NUM_TESTS] = {
        {82, 72, 91, 74, 82},
        {87, 97, 82, 92, 94},
        {92, 98, 91, 100, 85},
        {85, 82, 72, 84, 85},
        {78, 60, 63, 79, 81},
        {74, 91, 77, 74, 80}
    };

    double averages[NUM_STUDENTS];
    char grades[NUM_STUDENTS];

    // Calculate averages and letter grades
    calculateAverages(names, scores, averages, grades, NUM_STUDENTS);

    // Display results
    displayResults(names, averages, grades, NUM_STUDENTS);

    return 0;
}

// Function to calculate the averages and determine letter grades
void calculateAverages(const string names[], const int scores[][5], double averages[], char grades[], int size) {
    for (int i = 0; i < size; i++) {
        int total = 0;
        for (int j = 0; j < 5; j++) {
            total += scores[i][j];
        }
        averages[i] = static_cast<double>(total) / 5;
        grades[i] = determineGrade(averages[i]);
    }
}

// Function to determine letter grade based on average score
char determineGrade(double avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

// Function to display the results
void displayResults(const string names[], const double averages[], const char grades[], int size) {
    cout << fixed << setprecision(2);
    cout << "\nGrade Book Results:\n";
    cout << "-----------------------------------\n";
    cout << left << setw(12) << "Student" << "Average" << "  Grade" << endl;
    cout << "-----------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << left << setw(12) << names[i] << averages[i] << "    " << grades[i] << endl;
    }
}
