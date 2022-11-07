#pragma once
#ifdef CURSOR_EXPORTS
#define CURSOR_API _declspec(dllexport)
#else
#define CURSOR_API _declspec(dllimport)
#endif

#include <string>

typedef unsigned int  uint;
typedef unsigned char uchar;

enum CursorType {
    Horizontal,
    Vertical
};

class CURSOR_API Cursor {
public:
    Cursor();
    Cursor(uint x, uint y);
    Cursor(uint x, uint y, CursorType ct);
    Cursor(uint x, uint y, CursorType ct, uchar size);

    uint getX();
    uint getY();

    void setX(uint x);
    void setY(uint y);

    void move(uint x, uint y);

    CursorType getType();
    void       setType(CursorType type);

    uchar getSize();
    void  setSize(uchar size);

    void show();
    void hide();

    void setShown(bool shown);
    void setHidden(bool hidden);

    bool isShown();
    bool isHidden();

    void read();
    void display();

    std::string toString();

    void operator++ (int);
    void operator-- (int);

    void operator++ ();
    void operator-- ();

    bool operator== (const Cursor& other);
private:
    uint x, y;
    uchar size;
    CursorType type;
    bool visible;
};