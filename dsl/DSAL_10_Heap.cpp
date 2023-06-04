#include<iostream>
using namespace std;

class heap {
    int *ptr;

public:
    heap(int n) {
        ptr = new int[(n + 1)];
        int i = 0;
        int *temp = ptr;
        *(temp + i) = n;
        i++;
        while (i < (n + 1)) {
            *(temp + i) = -1;
            i++;
        }
    }

    static int retPar(int i) {
        if (i % 2 == 0) {
            return (i / 2);
        } else {
            return ((i - 1) / 2);
        }
    }

    void creatHeap(int arr[], int n); // create maxHeap
    void adjustHeap(int j); // adjust maxHeap

    friend class onlnMark;
};

class onlnMark {
private:
    int arr[50];
    int n;

public:
    void input(int n);
    void heapSort();
    void display();
};

void onlnMark::input(int n) {
    this->n = n;

    for (int i = 0; i < n; i++) {
        cout << "Enter marks of " << (i + 1) << "th student: ";
        cin >> arr[i];
    }
}

void heap::creatHeap(int arr[], int n) {
    int i = 0;
    int j = 1;
    *(ptr + j) = arr[i];
    i++; // i=1, j=1
    int k = -1;
    while (i < n) {
        if (*(ptr + (2 * j)) == -1) {
            *(ptr + (2 * j)) = arr[i];
            i++;
            k = 2 * j;
        } else if (*(ptr + ((2 * j) + 1)) == -1) {
            *(ptr + (2 * j + 1)) = arr[i];
            k = 2 * j + 1;
            i++;
            j++;
        }
        // placed entry from array to heap's leaf node
        int p = heap::retPar(k);
        while (p != 0) {
            if (*(ptr + p) > *(ptr + k)) {
                break;
            } else {
                int temp = *(ptr + k);
                *(ptr + k) = *(ptr + p);
                *(ptr + p) = temp;
                k = p;
                p = heap::retPar(k);
            }
        }
    }
}

void heap::adjustHeap(int j) {
    if (2 * j >= (*(ptr + 0))) {
        return;
    }
    if ((*(ptr + 2 * j) < *(ptr + j)) && (*(ptr + 2 * j + 1) < *(ptr + j))) {
        return;
    } else {
        int temp = -1;
        if (*(ptr + 2 * j) > *(ptr + 2 * j + 1)) {
            temp = *(ptr + 2 * j);
            *(ptr + 2 * j) = *(ptr + j);
            *(ptr + j) = temp;
            this->adjustHeap((2 * j));
        } else {
            temp = *(ptr + 2 * j + 1);
            *(ptr + 2 * j + 1) = *(ptr + j);
            *(ptr + j) = temp;
            this->adjustHeap((2 * j + 1));
        }
    }
}

void onlnMark::heapSort() {
    heap max(this->n);
    max.creatHeap(this->arr, this->n);
    int *temp = max.ptr;
    for (int i = 0; i < (n + 1); i++) {
        cout << "\t" << *(temp + i);
    }
    cout << endl;
    temp = max.ptr;
    for (int i = 0, j = i + 1; i < n; i++) {
        arr[i] = *(temp + j);
        *(temp + j) = -1;
        int li = *(temp + 0); // index of last element of heap
        *(temp + j) = *(temp + li);
        *(temp + li) = -1;
        (*(temp + 0))--;
        max.adjustHeap(j);
    }
}

void onlnMark::display() {
    cout << endl;
    cout << "#Marks in descending order: " << endl;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    cout << "#Highest score is of " << arr[0] << " & Lowest score is of " << arr[(n - 1)] << "." << endl;
}

int main() {
    onlnMark obj;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    obj.input(n);
    obj.heapSort();
    obj.display();
    
    return 0;
}
