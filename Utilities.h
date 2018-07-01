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
    DEFAULT
};
class Utilities {
   public:
    static void print(char c);
    static void print(char const* c);
    static void gotoxy(int x, int y);
    static int randomMovement();
    static void setColour(Colour fg, Colour bg);
    static void hideCursor();
    static char getUserInput();
};

#endif
