//Searching and Sorting
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Question--->>>Consider a student database of SEIT class (at least 3 records). 
Database contains different fields of every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA,then print list of all students having same SGPA.
e) Search a particular student according to name using binary search without recursion. (all the student records having the presence of search key should be displayed)
(Note: Implement either Bubble sort or Insertion Sort.)
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstring>

using namespace std;

struct Student {
    unsigned int rollno;
    char name[50];
    float SGPA;
};

class SDB {
private:
    Student s[3];
    int n;

public:
    SDB() {
        n = 3;
    }
    void accept_data();
    void display_data();
    void bubblesort();
    void insertionSortByName();
    void quickSortBySGPA(int low, int high);
    int partitionBySGPA(int low, int high);
    void searchBySGPA(float sgpa);
    int linearSearchByName(const char* name);
};

void SDB::accept_data() {
    cout << "Enter Details for Student DataBase:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter Roll Number:";
        cin >> s[i].rollno;
        cout << "Enter Name:";
        cin >> s[i].name;
        cout << "Enter SGPA:";
        cin >> s[i].SGPA;
    }
}

void SDB::display_data() {
    cout << "---------------------------------" << endl;
    cout << "RollNo\tName\tSGPA" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\t" << s[i].rollno << "\t" << s[i].name << "\t" << s[i].SGPA << endl;
    }
    cout << "---------------------------------" << endl;
}

void SDB::bubblesort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].rollno > s[j + 1].rollno) {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

void SDB::insertionSortByName() {
    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

int SDB::partitionBySGPA(int low, int high) {
    float pivot = s[high].SGPA;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (s[j].SGPA > pivot) {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return i + 1;
}

void SDB::quickSortBySGPA(int low, int high) {
    if (low < high) {
        int pi = partitionBySGPA(low, high);
        quickSortBySGPA(low, pi - 1);
        quickSortBySGPA(pi + 1, high);
    }
}

void SDB::searchBySGPA(float sgpa) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s[i].SGPA == sgpa) {
            cout << "RollNo: " << s[i].rollno << ", Name: " << s[i].name << ", SGPA: " << s[i].SGPA << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with SGPA: " << sgpa << endl;
    }
}

int SDB::linearSearchByName(const char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(s[i].name, name) == 0) {
            cout << "RollNo: " << s[i].rollno << ", Name: " << s[i].name << ", SGPA: " << s[i].SGPA << endl;
        }
    }
    return -1;
}

int main() {
    SDB s;
    int val;
    int num;
    char name[50];
    float sgpa;

    s.accept_data();
    
    // Sorting by Roll Number using Bubble Sort
    cout << "\nSorted by Roll Number (Bubble Sort):" << endl;
    s.bubblesort();
    s.display_data();
    
    // Sorting by Name using Insertion Sort
    cout << "\nSorted by Name (Insertion Sort):" << endl;
    s.insertionSortByName();
    s.display_data();

    // Sorting by SGPA using Quick Sort and displaying top Students
    cout << "\nTop 3 students sorted by SGPA (Quick Sort):" << endl;
    s.quickSortBySGPA(0, 2);
    s.display_data();
    
    // Searching students by SGPA
    cout << "\nEnter SGPA to search: ";
    cin >> sgpa;
    s.searchBySGPA(sgpa);

    // Searching students by name using Linear Search
    cout << "\nEnter name to search: ";
    cin >> name;
    s.linearSearchByName(name);

    return 0;
}

//******************************************************************************
//Output
/*
Enter Details for Student DataBase:
Enter Roll Number:2
Enter Name:harsh
Enter SGPA:9
Enter Roll Number:1
Enter Name:rupesh
Enter SGPA:10
Enter Roll Number:3
Enter Name:baabya
Enter SGPA:9

Sorted by Roll Number (Bubble Sort):
---------------------------------
RollNo	Name	SGPA
	1	rupesh	10
	2	harsh	9
	3	baabya	9
---------------------------------

Sorted by Name (Insertion Sort):
---------------------------------
RollNo	Name	SGPA
	3	baabya	9
	2	harsh	9
	1	rupesh	10
---------------------------------

Top 3 students sorted by SGPA (Quick Sort):
---------------------------------
RollNo	Name	SGPA
	1	rupesh	10
	3	baabya	9
	2	harsh	9
---------------------------------

Enter SGPA to search: 9
RollNo: 3, Name: baabya, SGPA: 9
RollNo: 2, Name: harsh, SGPA: 9

Enter name to search: harsh
RollNo: 2, Name: harsh, SGPA: 9


=== Code Execution Successful ===
*/
