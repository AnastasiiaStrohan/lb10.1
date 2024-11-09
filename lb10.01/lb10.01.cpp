#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ��������� ��� ��������� ���������� ��� ��������
struct Student {
    int id;
    string lastName;
    int course;
    string specialty;
    double physicsGrade;
    double mathGrade;
    double informaticsGrade;
};

// ������� ��� �������� ����� ��������
static void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "\nStudent #" << i + 1 << ":\n";
        students[i].id = i + 1;

        cout << "Enter last name: ";
        cin >> students[i].lastName;

        cout << "Enter course: ";
        cin >> students[i].course;

        cout << "Enter specialty: ";
        cin >> students[i].specialty;

        cout << "Enter grade in Physics: ";
        cin >> students[i].physicsGrade;

        cout << "Enter grade in Math: ";
        cin >> students[i].mathGrade;

        cout << "Enter grade in Informatics: ";
        cin >> students[i].informaticsGrade;
    }
}

// ������� ��� ��������� ������� ��������
static void displayStudents(const Student students[], int n) {
    cout << "\nStudent List:\n";
    cout << left << setw(5) << "No" << setw(15) << "Last Name" << setw(8) << "Course"
        << setw(15) << "Specialty" << setw(8) << "Physics" << setw(8) << "Math"
        << setw(12) << "Informatics" << endl;
    cout << string(70, '-') << endl;

    for (int i = 0; i < n; ++i) {
        cout << left << setw(5) << students[i].id << setw(15) << students[i].lastName
            << setw(8) << students[i].course << setw(15) << students[i].specialty
            << setw(8) << students[i].physicsGrade << setw(8) << students[i].mathGrade
            << setw(12) << students[i].informaticsGrade << endl;
    }
}

// ������� ��� ��������� �������� �� ������� ����� ����� �� 4.5
static int countHighAverageStudents(const Student students[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        double average = (students[i].physicsGrade + students[i].mathGrade + students[i].informaticsGrade) / 3.0;
        if (average > 4.5) {
            count++;
        }
    }
    return count;
}

// ������� ��� ���������� ���������� ���� ��� ������� ��������
static void calculateAverageGrades(const Student students[], int n, double& avgPhysics, double& avgMath, double& avgInformatics) {
    double sumPhysics = 0, sumMath = 0, sumInformatics = 0;
    for (int i = 0; i < n; ++i) {
        sumPhysics += students[i].physicsGrade;
        sumMath += students[i].mathGrade;
        sumInformatics += students[i].informaticsGrade;
    }
    avgPhysics = sumPhysics / n;
    avgMath = sumMath / n;
    avgInformatics = sumInformatics / n;
}

// ������� ��� ���������� �������� � �������� ������� �����
static string findHighestAverageSubject(double avgPhysics, double avgMath, double avgInformatics) {
    if (avgPhysics >= avgMath && avgPhysics >= avgInformatics) {
        return "Physics";
    }
    else if (avgMath >= avgPhysics && avgMath >= avgInformatics) {
        return "Math";
    }
    else {
        return "Informatics";
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    // ���������� ���������� ������ ��������
    Student students[100]; // ����������� ������� �������� �������� 100

    if (n > 100) {
        cout << "Error: Number of students exceeds the maximum allowed (100)." << endl;
        return 1;
    }

    inputStudents(students, n);            // �������� ����� ��������
    displayStudents(students, n);          // ��������� ������� ��������

    int highAverageCount = countHighAverageStudents(students, n);
    cout << "\nNumber of students with an average grade higher than 4.5: " << highAverageCount << endl;

    double avgPhysics, avgMath, avgInformatics;
    calculateAverageGrades(students, n, avgPhysics, avgMath, avgInformatics);
    string highestSubject = findHighestAverageSubject(avgPhysics, avgMath, avgInformatics);

    cout << "Average grade for Physics: " << avgPhysics << endl;
    cout << "Average grade for Math: " << avgMath << endl;
    cout << "Average grade for Informatics: " << avgInformatics << endl;
    cout << "Subject with the highest average grade: " << highestSubject << endl;

    return 0;
}
