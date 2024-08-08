#include <iostream>
#include <string>
using namespace std;

class student {
private:
    int Rollno;
    string name;
    int marks;
public:
    void getdata();
    void showdata() const;
    int getroll() const {
        return Rollno;
    }
    int getmarks() const {
        return marks;
    }
    string getname() const {
        return name;
    }
};

void student::getdata() {
    cin >> Rollno >> name >> marks;
}

void student::showdata() const {
    cout << Rollno << " - " << name << " - " << marks << endl;
}

void insertionsort(student s[], int n) {
    for (int i = 1; i < n; i++) {
        student val = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].getroll() > val.getroll()) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = val;
    }
}

int main() {
    student s[5];
    char x;
    int choice;
   do {
        cout << "Do you want to continue? (y/n): ";
        cin >> x;

        if (x != 'y' && x != 'n') {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            continue;
        }

        if (x == 'y') {
            cout << "1. Get details\n2. Show details\n3. Sort\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter Details: " << endl;
                    for (int i = 0; i < 3; i++) {
                        s[i].getdata();
                    }
                    break;
                case 2:
                    cout << "Show Details: " << endl;
                    for (int i = 0; i < 3; i++) {
                        s[i].showdata();
                    }
                    break;
                case 3:
                    insertionsort(s, 3);
                    cout << "Sorted details: " << endl;
                    for (int i = 0; i < 3; i++) {
                        s[i].showdata();
                    }
                    break;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                    break;
            }
        }
    } while (x == 'y');
    return 0;
}
