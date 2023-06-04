#include<iostream>
#include<iomanip>
using namespace std;

class graph {
public:
    int mat[50][50];
    string str[50];
    int n;
    int inf;

    graph(int no) {
        inf = 0;
        n = no;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
            str[i] = "xyz";
    }

    void creat();
    void display();
    void minCost(int a, int b);
};

void graph::creat() {
    for (int i = 0; i < n; i++) {
        cout << "\n\nEnter name of " << (i + 1) << "th office: ";
        cin >> str[i];
        if (i == 0) {
            continue;
        } else {
            int j = i - 1;
            for (; j != -1; j--) {
                cout << "Enter cost to connect " << str[i] << " office to " << str[j] << " office: ";
                cin >> mat[i][j];
                inf = inf + mat[i][j];
                mat[j][i] = mat[i][j];
            }
        }
    }
    inf++;
}

void graph::display() {
    cout << "\n " << left << setw(10) << " ";
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << str[i];
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << i << ") " << left << setw(10) << str[i];
        for (int j = 0; j < n; j++) {
            cout << left << setw(10) << mat[i][j];
        }
        cout << "\n";
    }
    cout << "\nFigure indicates cost of connection between two cities." << endl;
}

void graph::minCost(int a, int b) {
    int vistd[n];
    int count = n;
    int len[n];
    for (int i = 0; i < n; i++) {
        if (i == a) {
            vistd[i] = 1;
            len[i] = mat[a][i];
            count--;
        } else {
            vistd[i] = 0;
            if (mat[a][i] == 0)
                len[i] = inf;
            else
                len[i] = mat[a][i];
        }
    }
    while (count >= 0) {
        int min = inf;
        int p = 0;
        for (int i = 0; i < n; i++) {
            if ((vistd[i] == 0) && (len[i] < min)) {
                min = len[i];
                p = i;
            }
        }
        vistd[p] = 1;
        count--;
        for (int i = 0; i < n; i++) {
            int wid;
            if (mat[p][i] == 0) {
                wid = inf;
            } else {
                wid = mat[p][i];
            }
            if ((len[p] + wid) < len[i]) {
                len[i] = len[p] + wid;
            }
        }
    }
    cout << "Minimum cost of connection between " << str[a] << " to " << str[b] << " is " << len[b] << endl;
}

int main() {
    int no;
    cout << "How many offices do you have? ";
    cin >> no;
    graph telNet(no);
    cout << "\n#Creating network to connect your offices:" << endl;
    telNet.creat();
    cout << "\n\n#Connection cost for different connections is as follows:" << endl;
    telNet.display();
    int slct;
    do {
        cout << "#Menu:\n\t1. Display cost chart.\n\t2. Find minimum cost of connection between two offices.\n\t3. Exit" << endl;
        cout << "#Select --> ";
        cin >> slct;
        switch (slct) {
            case 1:
                telNet.display();
                break;
            case 2:
                int a, b;
                cout << "From: ";
                cin >> a;
                cout << "To: ";
                cin >> b;
                cout << endl;
                telNet.minCost(a, b);
                break;
            case 3:
                return 0;
        }
    } while (1);
}
