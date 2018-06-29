#ifndef UTIL_H
#define UTIL_H
enum class Colour {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    BBLACK,
    BRED,
    BGREEN,
    BYELLOW,
    BBLUE,
    BMAGENTA,
    BCYAN,
    BWHITE,
    DEFAULT
};
struct KB {
    int a;
    int b;
    int c;
    KB(int a, int b, int c) : a(a), b(b), c(c) {
    }
    KB() {
    }
};
class Utilities {
   public:
    static void print(char c);
    static void print(char const* c);
    static void gotoxy(int x, int y);
    static int randomMovement();
    static void setColour(Colour fg, Colour bg);
    static void hideCursor();
    static KB getUserInput();
};

#endif
