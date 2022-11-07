#include "cursor.h"

#include <iostream>
using namespace std;

int main() {
    Cursor cursor;

    Cursor curs1(20, 45);
    Cursor curs2(24, 50, CursorType::Vertical);
    Cursor curs3(54, 34, CursorType::Horizontal, 14);
    cout << "Results with Init() method:" << endl;
    cursor.display();
    cout << endl;
    cout << "Results with additional constructors:" << endl;
    curs1.display();
    curs2.display();
    curs3.display();
    cout << endl;

    cout << "Results with operation overload:" << endl;
    cursor++;
    cursor.display();
    cursor--;
    cursor.display();

    cursor.read();
    cout << "Results with Read() method:" << endl;
    cursor.display();

    system("PAUSE");
    return 0;
}