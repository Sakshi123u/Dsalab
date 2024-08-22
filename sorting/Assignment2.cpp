#include<iostream>
using namespace std;

class employee {
private:
    int emp_id;
    string name;
    float salary;

public:
    void getdata();
    void showdata();
    int getid() const {
        return emp_id;
    }
    string getname() const {
        return name;
    }
};

void employee::getdata() {
    cin >> emp_id >> name >> salary;
}

void employee::showdata() {
    cout << emp_id << " - " << name << " - " << salary << endl;
}

void quicksort(employee e[], int n, int f, int l) {
    if (f < l) {
        int i = f + 1;
        int j = l;
        int pivot = e[f].getid();

        while (i <= j) {
            while (i <= l && e[i].getid() < pivot) i++;
            while (j >= f && e[j].getid() > pivot) j--;

            if (i < j) {
                employee temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }

        employee temp = e[f];
        e[f] = e[j];
        e[j] = temp;

        quicksort(e, n, f, j - 1);
        quicksort(e, n, j + 1, l);
    }
}
void merge(employee e[],int l,int mid,int h){
    int i=l;
    int j=mid+1;
     int k = l;
    employee *B = new employee[h - l + 1];
    while(i<=mid && j<=h){
        if(e[i].getname()<e[j].getname()){
            B[k++]=e[i++];
        }
        else{
            B[k++]=e[j++];
        }
    }
    while(i<=mid){
        B[k++]=e[i++];
    }
    while(j<=h){
        B[k++]=e[j++];
    }
    for (int p = 0; p < k; p++) {
        e[l + p] = B[p];
    }

    delete[] B;
}
void mergesort(employee e[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(e,l,mid);
        mergesort(e,mid+1,h);
        merge(e,l,mid,h);
    }
}
int main() {
    int n;
    cout<<"Enter size:"<<endl;
    cin>>n;
    employee e[n];
    int choice;
    cout << "Enter employee ID, name, and salary: " << endl;
    for (int i = 0; i < n; i++) {
        e[i].getdata();
    }
    do{
        cout<<"Choose a sorting technique :\n";
        cout<<"1.Quick_sort_by_id\n";
        cout<<"2.Merge_sort_by_name\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                quicksort(e, n, 0, n-1); 
                cout<<"Sorted data by employee_id"<<endl;
            break;
            case 2:
                mergesort(e,0,n-1);
                cout<<"Sorted data by employee_name"<<endl;
            break;
            case 3:
                cout<<"Exit the program"<<endl;
            break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        for (int i = 0; i <3; i++) {
            e[i].showdata();
        }
    }while (choice!=3);
    return 0;
}
