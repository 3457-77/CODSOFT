

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Player {
private:
    string name;
    char op;
public:
    Player() {
    }

    Player(string name, char op) {
        this->name = name;
        this->op = op;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    char getOp() {
        return op;
    }

    void setOp(char op) {
        this->op = op;
    }

};

class Board {
    char arr[3][3] = { {'1','2','3'},
                      {'4','5','6'},
                      {'7','8','9'} };
public:
    Board() {
       
    }
    int getRow(int index) {
        return ((index - 1) / 3);
    }
    int getCol(int index) {
        return ((index - 1) % 3);
    }


    bool isEmpty(int index) {
        int row, col;
        row = getRow(index);
        col = getCol(index);
        if (arr[row][col] == 'x' || arr[row][col] == 'o' || arr[row][col] == 'X' || arr[row][col] == 'O')
        {
            return false;
        }
        else { return true; }
    }

    bool ReplaceChar(int index, Player p) {
        int row, col;
        row = getRow(index);
        col = getCol(index);
        if (isEmpty(index)) {
            arr[row][col] = p.getOp();
            return true;
        }
        return false;
    }

    bool isFull() {
        for (int i = 0; i < 3; i++)
        {
            for (int y = 0; y < 3; y++) {
                if (arr[i][y] != 'x' && arr[i][y] != 'o') {
                    return false;
                }
            }
        }
        return true;
    }

    void draw() {
        cout << "-----------\n";
        for (int i = 0; i < 3; i++) {
            for (int y = 0; y < 3; y++) {
                cout << (arr[i][y]);
                cout << ('|');

            }
            cout << endl;
            cout << "-----------\n";
        }

    }

    bool isWin(Player p) {

        if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]) {
            return true;
        }
        if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]) {
            return true;
        }
        if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2]) {
            return true;
        }
        if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0]) {
            return true;
        }
        if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1]) {
            return true;
        }
        if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2]) {
            return true;
        }
        if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
            return true;
        }
        if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
            return true;
        }
        return false;
    }
};

class Game {
private:
    Board b;
    Player p1;
    Player p2;
    int count = 0;

public:
    void ReadPlayersData() {
        cout << "Welcome to XO Game ...\n";
        cout << "Enter Player 1 data \n";
        string name1;
        cout << "Name: ";
        cin >> name1;
        char c1;
        cout << "Operator: ";
        cin >> c1;;
        p1.setOp(c1);
        cout << "Enter Player 2 data \n";
        string name2;
        cout << "Name: ";
        cin >> name2;
        if (c1 == 'x')
            p2.setOp('o');
        else  p2.setOp('x');
        char c2 = p2.getOp();

        cout << "Player 1 data: " << endl;
        cout << "Name: " << name1 << endl;
        cout << "Operator: " << c1 << endl;
        cout <<"Player 2 data: " << endl;
        cout <<"Name: " << name2 << endl;
        cout << "Operator: " << c2 << endl;
    }

    void play() {
        ReadPlayersData();
        b.draw();

        while (!b.isFull()) {
            if (count % 2 == 0) {
                cout << "Player 1 .. Choose place "<< endl;
                int r;
                cin >> r;
                if (b.ReplaceChar(r, p1)) {
                    b.draw();
                    if (b.isWin(p1)) {
                        cout << "Congrats, Player 1 wins\n";
                        return;
                    }
                }
                else { continue; }
            }
            else if (count % 2 != 0) {
                cout << "Player 2 .. Choose place \n";
                int r;
                cin >> r;
                if (b.ReplaceChar(r, p2)) {
                    b.draw();
                    if (b.isWin(p2)) {
                        cout << "Congrats, Player 2 wins" << endl;
                        return;

                    }
                }
                else { continue; }
            }
            count++;
            if ((b.isFull())) {
                cout << "Game is Draw..." << endl;
            }

        }
    }

};




int main() {


    Game xo;
    xo.play();
}

