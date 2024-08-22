#include<iostream>
#include<string>
using namespace std;

class Student {
private:
    int Rollno;
    string name;
    int marks;

public:
    void getdata();

    void showdata() const;

    int getRollno() const {
        return Rollno;
    }

    string getName() const {
        return name;
    }
};

void Student::getdata() {
    cin >> Rollno >> name >> marks;
}

void Student::showdata() const {
    cout << Rollno << "-" << name << "-" << marks << endl; // Added endl for better readability
}

// Insertion Sort by Roll Number
void insertionSortByRollNo(Student s[], int n) {
    for (int i = 1; i < n; i++) {
        Student val = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].getRollno() > val.getRollno()) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = val;
    }
}

// Insertion Sort by Name
void insertionSortByName(Student s[], int n) {
    for (int i = 1; i < n; i++) {
        Student val = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].getName() > val.getName()) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = val;
    }
}

// Shell Sort by Roll Number
void shellSort(Student s[], int n) {
    int gap = n / 2;
    while (gap >= 1) {
        for (int j = gap; j < n; j++) {
            Student temp = s[j];
            int i;
            for (i = j - gap; i >= 0 && s[i].getRollno() > temp.getRollno(); i -= gap) {
                s[i + gap] = s[i];
            }
            s[i + gap] = temp;
        }
        gap /= 2;
    }
}

// Shell Sort by Name
void shellSortbyname(Student s[], int n) {
    int gap = n / 2;
    while (gap >= 1) {
        for (int j = gap; j < n; j++) {
            Student temp = s[j];
            int i;
            for (i = j - gap; i >= 0 && s[i].getName() > temp.getName(); i -= gap) {
                s[i + gap] = s[i];
            }
            s[i + gap] = temp;
        }
        gap /= 2;
    }
}
int main() {
    Student s[5];
    int choice;

    // Input data for students
    cout << "Enter Roll Number, Name, and Marks for 5 students:" << endl;
    for (int i = 0; i < 5; i++) {
        s[i].getdata();
    }

    do {
        // User selects sorting method
        cout << "\nChoose a sorting method:\n";
        cout << "1. Insertion Sort by Roll Number\n";
        cout << "2. Insertion Sort by Name\n";
        cout << "3. Shell Sort by Roll Number\n";
        cout << "4. Shell Sort by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insertionSortByRollNo(s, 5);
            cout << "\nSorted Data (by Roll Number using Insertion Sort):" << endl;
            break;

        case 2:
            insertionSortByName(s, 5);
            cout << "\nSorted Data (by Name using Insertion Sort):" << endl;
            break;

        case 3:
            shellSort(s, 5);
            cout << "\nSorted Data (by Roll Number using Shell Sort):" << endl;
            break;

        case 4:
            shellSortbyname(s, 5);
            cout << "\nSorted Data (by Name using Shell Sort):" << endl;
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

        // Display the sorted data after each sorting
        for (int i = 0; i < 5; i++) {
            s[i].showdata();
        }

    } while (choice != 5);  // Continue until the user chooses to exit

    return 0;
}
