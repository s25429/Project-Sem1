#include <conio.h> // Included for _kbhit() and _getch()

#define SYS_CLEAR "cls"

constexpr int KEY_LEN = 2; // Length of keycode
constexpr int KEY_UP[] =    { 224, 72 };
constexpr int KEY_DOWN[] =  { 224, 80 };
constexpr int KEY_LEFT[] =  { 224, 75 };
constexpr int KEY_RIGHT[] = { 224, 77 };