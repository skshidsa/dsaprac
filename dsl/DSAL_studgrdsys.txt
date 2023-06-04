#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class student {
private:
    int rollno;
    char name[20];
    char branch[4];
    float marks;
    char grade;

public:
    void getdata() {
        cout << "Rollno: ";
        cin >> rollno;
        cout << "Name: ";
        cin >> name;
        cout << "Branch: ";
        cin >> branch;
        cout << "Marks: ";
        cin >> marks;

        if (marks >= 75) {
            grade = 'A';
        }
        else if (marks >= 60) {
            grade = 'B';
        }
        else if (marks >= 50) {
            grade = 'C';
        }
        else if (marks >= 40) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }
    }

    void putdata() {
        cout << "Rollno: " << rollno << "\tName: " << name << "\n";
        cout << "Marks: " << marks << "\tGrade: " << grade << "\n";
    }

    int getrno() {
        return rollno;
    }

    void modify();
};

void student::modify() {
    cout << "Rollno: " << rollno << "\n";
    cout << "Name: " << name << "\tBranch: " << branch << "\tMarks: " << marks << "\n";
    cout << "Enter new details.\n";

    char nam[20] = "";
    char br[4] = "";
    float mks;

    cout << "New name (Enter '.' to retain old one): ";
    cin >> nam;
    cout << "New branch (Press '.' to retain old one): ";
    cin >> br;
    cout << "New marks (Press -1 to retain old one): ";
    cin >> mks;

    if (strcmp(nam, ".") != 0) {
        strcpy(name, nam);
    }

    if (strcmp(br, ".") != 0) {
        strcpy(branch, br);
    }

    if (mks != -1) {
        marks = mks;

        if (marks >= 75) {
            grade = 'A';
        }
        else if (marks >= 60) {
            grade = 'B';
        }
        else if (marks >= 50) {
            grade = 'C';
        }
        else if (marks >= 40) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }
    }
}

int main() {
    fstream fio("marks.dat", ios::in | ios::out | ios::binary);
    char ans = 'y';

    while (ans == 'y' || ans == 'Y') {
        student stud1;
        stud1.getdata();
        fio.write(reinterpret_cast<char*>(&stud1), sizeof(stud1));
        cout << "Record added to the file.\n";
        cout << "\nWant to enter more? (y/n): ";
        cin >> ans;
    }

    int rno;
    long pos;
    bool found = false;

    cout << "Enter rollno of student whose record is to be modified: ";
    cin >> rno;

    fio.seekg(0);

    student stud1;

    while (fio.read(reinterpret_cast<char*>(&stud1), sizeof(stud1))) {
        pos = fio.tellg();

        if (stud1.getrno() == rno) {
            stud1.modify();
            fio.seekp(pos - sizeof(stud1));
            fio.write(reinterpret_cast<char*>(&stud1), sizeof(stud1));
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nRecord not found in the file.\n";
        cout << "Press any key to exit...\n";
        cin.ignore();
        cin.get();
        exit(2);
    }

    fio.seekg(0);

    cout << "Now the file contains:\n";

    while (fio.read(reinterpret_cast<char*>(&stud1), sizeof(stud1))) {
        stud1.putdata();
    }

    fio.close();

    return 0;
}
