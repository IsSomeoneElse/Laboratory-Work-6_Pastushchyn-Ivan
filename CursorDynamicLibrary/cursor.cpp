#include "cursor.h"
#include "pch.h"

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

uint Cursor::getX() {
    return x;
}

uint Cursor::getY() {
    return y;
}

void Cursor::setX(uint _x) {
    x = _x;
}

void Cursor::setY(uint _y) {
    y = _y;
}

void Cursor::move(uint _x, uint _y) {
    setX(_x);
    setY(_y);
}

CursorType Cursor::getType() {
    return type;
}

void Cursor::setType(CursorType _type) {
    type = _type;
}

uchar Cursor::getSize() {
    return size;
}

void  Cursor::setSize(uchar _size) {
    size = _size;
}

void Cursor::show() {
    setShown(true);
}

void Cursor::hide() {
    setHidden(true);
}

void Cursor::setShown(bool shown) {
    visible = shown;
}

void Cursor::setHidden(bool hidden) {
    visible = !hidden;
}

bool Cursor::isShown() {
    return visible;
}

bool Cursor::isHidden() {
    return !visible;
}

Cursor::Cursor() {
    x = 0;
    y = 0;
    type = CursorType::Horizontal;
    size = 6;
    visible = true;
}

Cursor::Cursor(uint _x, uint _y) {
    x = _x;
    y = _y;
}

Cursor::Cursor(uint _x, uint _y, CursorType ct) : Cursor(_x, _y) {
    type = ct;
}

Cursor::Cursor(uint _x, uint _y, CursorType ct, uchar s) : Cursor(_x, _y, ct) {
    size = s;
}

void Cursor::operator++ (int) {
    operator++();
}

void Cursor::operator-- (int) {
    operator--();
}

void Cursor::operator++ () {
    size++;
}

void Cursor::operator-- () {
    size--;
}

bool Cursor::operator== (const Cursor& other) {
    return x == other.x &&
        y == other.y &&
        size == other.size &&
        type == other.type;
}

void Cursor::read() {
    int _type = 0;
    cout << "Input coordinate x of the cursor:\t";
    cin >> x;
    cout << "Input coordinate y of the cursor:\t";
    cin >> y;
    cout << "Input cursor size in the range from 0 to 15\t";
    int s;
    cin >> s;
    size = (uchar)s;
    cout << "Input cursor type (0 - horizontal or 1 - vertical):\t";
    cin >> _type;
    cout << "Input cursor visibility (0 - invisible ot 1 - visible):\t";
    cin >> visible;
    type = (CursorType)_type;
}

void Cursor::display() {
    cout << toString() << endl;
}

std::string Cursor::toString() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"
        + " Size: " + std::to_string(size)
        + " Type: " + (type == Horizontal ? "Horizontal" : "Vertical")
        + " Visible: " + (visible ? "Yes" : "No");
}