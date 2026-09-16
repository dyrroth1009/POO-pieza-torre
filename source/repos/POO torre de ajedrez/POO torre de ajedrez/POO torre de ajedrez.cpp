#include <iostream>
#include <string>

using namespace std;

class Rook {
private:
    int row;
    int column;
    bool isBlack;

    bool validateMovement(int newRow, int newCol) {
        if (newRow == row && newCol != column) {
            return true;
        }
        if (newCol == column && newRow != row) {
            return true;
        }
        return false;
    }

public:
    Rook(int r, int c, bool negra) {
        row = r;
        column = c;
        isBlack = negra;
    }

    void move(int newRow, int newCol) {
        if (newRow < 1 || newRow > 8 || newCol < 1 || newCol > 8) {
            cout << "Error: Fuera del tablero" << endl;
            return;
        }

        if (validateMovement(newRow, newCol)) {
            row = newRow;
            column = newCol;
        }
        else {
            cout << "Error: Movimiento diagonal u opcional no valido" << endl;
        }
    }

    string draw() {
        if (isBlack) {
            return "[##]";
        }
        else {
            return "[TT]";
        }
    }

    void printState() {
        if (isBlack) {
            cout << draw() << " Negra en Fila: " << row << ", Col: " << column << endl;
        }
        else {
            cout << draw() << " Blanca en Fila: " << row << ", Col: " << column << endl;
        }
    }
};

int main() {
    Rook t1(1, 1, false);
    Rook t2(8, 8, true);

    t1.printState();
    t2.printState();

    t1.move(2, 2);

    int f, c;
    cout << "Ingresa fila y columna para mover la torre negra: ";
    cin >> f >> c;

    t2.move(f, c);
    t2.printState();

    return 0;
}