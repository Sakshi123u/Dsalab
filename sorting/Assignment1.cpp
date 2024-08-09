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
        while (j >= 0 && s[j].getname() > val.getname()) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = val;
    }
}
void insertionsortbyname(student s[], int n) {
    for (int i = 1; i < n; i++) {
        student val = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].getname() > val.getname()) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = val;
    }
}
void shellsort(student s[],int n){
    int gap=n/2;
    while(gap>=1){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i=i-gap){
                if(s[i+gap].getroll()>s[i].getroll()){
                    break;
                }else{
                    student temp=s[i+gap];
                    s[i+gap]=s[i];
                    s[i]=temp;
                }
            }
        }
        gap=gap/2;
    }
}
void shellsortbyname(student s[],int n){
    int gap=n/2;
    while(gap>=1){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i=i-gap){
                if(s[i+gap].getname()>s[i].getname()){
                    break;
                }else{
                    student temp=s[i+gap];
                    s[i+gap]=s[i];
                    s[i]=temp;
                }
            }
        }
        gap=gap/2;
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
            cout << "1. Get details\n2. Show details\n3. insertionSort\n4. shellsort\n5.shellsortbyname\n6.insertionSortbyname\n ";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter Details: " << endl;
                    for (int i = 0; i < 5; i++) {
                        s[i].getdata();
                    }
                    break;
                case 2:
                    cout << "Show Details: " << endl;
                    for (int i = 0; i < 5; i++) {
                        s[i].showdata();
                    }
                    break;
                case 3:
                    insertionsort(s, 5);
                    cout << "Sorted details: " << endl;
                    for (int i = 0; i < 5; i++) {
                        s[i].showdata();
                    }
                    break;
                case 4:
                    shellsort(s, 5);
                    cout << "Sorted details: " << endl;
                    for (int i = 0; i < 5; i++) {
                        s[i].showdata();
                    }
                    break;
                case 5:
                    shellsortbyname(s, 5);
                    cout << "Sorted details: " << endl;
                    for (int i = 0; i < 5; i++) {
                        s[i].showdata();
                    }
                    break;
                case 6:
                    insertionsort(s, 5);
                    cout << "Sorted details: " << endl;
                    for (int i = 0; i < 5; i++) {
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
