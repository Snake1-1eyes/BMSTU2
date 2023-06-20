#include <iostream>
using namespace std;

class ChessPiece {
protected:
    string color;
    string position;

public:
    ChessPiece(string _color, string _position) {
        color = _color;
        position = _position;
    }

    void print() {
        cout << "This " << color << " piece is at " << position << endl;
    }

    string checkColorMatch(string _color) {
        if (color == _color) {
            return "Yes";
        }
        else {
            return "Not";
        }
    }
};

class Bishop : public ChessPiece {
public:
    Bishop(string _color, string _position) : ChessPiece(_color, _position) {}

    string isUnderAttack(string _position) { // проверка на удар
        int dx = abs(_position[0] - position[0]);
        int dy = abs(_position[1] - position[1]);

        if (dx == dy) {
            return "Under Attack";
        }
        else {
            return "Not Under Attack";
        }
    }
};

int main() {
    Bishop b1("white", "c1");
    b1.print();
    cout << "Is position e4 under attack? " << b1.isUnderAttack("e4") << endl;
    cout << "Does the bishop match the color white? " << b1.checkColorMatch("white") << endl;

    return 0;
}