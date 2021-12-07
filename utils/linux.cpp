#include <sys/ioctl.h>
#include <termios.h>

#define SYS_CLEAR "clear"

#define KEY_LEN 3
// constexpr int KEY_LEN = 3; // Length of keycode
constexpr int KEY_UP[] =    { 27, 91, 65 };
constexpr int KEY_DOWN[] =  { 27, 91, 66 };
constexpr int KEY_LEFT[] =  { 27, 91, 68 };
constexpr int KEY_RIGHT[] = { 27, 91, 67 };


/*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 * Hey! Hold yer horses there, partner! 
 * Venturing down into this code is quite a doozey. Take it slowly, bucko!
 * After seeing this, you might yee your last haw, cowboy. Stay safe!
=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

static struct termios old, newp;

bool _kbhit() {
  // Credits to PBS
  // https://stackoverflow.com/a/45067593
  tcgetattr(0, &old);

  newp = old;
  newp.c_lflag &= ~ICANON;
  tcsetattr(0, TCSANOW, &newp);

  int byteswaiting;
  ioctl(0, FIONREAD, &byteswaiting);

  tcsetattr(0, TCSANOW, &old);

  return byteswaiting > 0;
}

int _getch() {
  // Credits to ionutvmi
  // https://gist.github.com/ionutvmi/5708845
  int ch;
  tcgetattr(0, &old);

  newp = old;
  newp.c_lflag &= ~ICANON;
  newp.c_lflag &= ECHO;
  tcsetattr(0, TCSANOW, &newp);

  ch = getchar();
  tcsetattr(0, TCSANOW, &old);

  return ch;
}