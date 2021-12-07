#include <iostream>
#include <vector>
#include <string>
#include <fstream>


namespace sga {
  constexpr bool DEBUG = true;
  typedef int(*randfunc)(int, int);
  typedef int(*cli)(const char*);
  typedef const char* cmnd;


  enum State : unsigned char {
    MENU = 0, GAME, OPTIONS, SCOREBOARD, CREDITS, FAIL
  };


  //* Data Structures
  // =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=

  struct Dir {
    char curr;
    char old;
  };

  struct App {
    int refresh_speed;
    int tick_cap;
    int tick = 0;
    int user_input = 0;
    int score = 0;
    bool running = true;
  };

  struct TUI {
    unsigned char state = State::MENU;
  };

  struct Board {
    char wall_char;
    int width;
    int height;
    int size = width * height;
    std::vector<char> arr = {};
    std::vector<int> walls = {};
  };

  struct Snake {
    char head_char;
    char body_char;
    size_t len;
    Dir dir = { 'u', 'u' };
    std::vector<int> pos_arr = {};
  };

  struct Apple {
    char symbol;
    int score;
    int pos = -1;
  };

  struct Config {
    bool use_ascii_extended = false;
    std::vector<bool> flags = {};
  };

  struct Scoreboard {
    size_t limit;
    std::vector<std::string> scores = {};
  };


  //* Snake Functions
  // =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=

  void initSnake(Snake& snake, Board& board) {
    //* Initializes snake's body vector and immediately draws snake onto the board

    if (snake.pos_arr.size() > 0) {
      snake.pos_arr.clear();
      snake.dir.curr = 'u';
      snake.dir.old = 'u';
    }

    int pos = board.size * 0.5;

    for (size_t i = 0; i < snake.len; i++) {
      int new_pos = pos + i * board.width;
      snake.pos_arr.push_back(new_pos);
      board.arr[new_pos] = (i == 0 ? snake.head_char : snake.body_char);
    }
  }

  void E_X_P_A_N_D__S_N_E_K(Snake& snake) {
    //* Increases snake's length

    int last_pos = snake.pos_arr[snake.pos_arr.size() - 1];
    snake.pos_arr.push_back(last_pos);
  }

  void updateSnakeOnBoard(Snake& snake, Board& board) {
    //* Cleans the board from previous position of the snake, calculates the next positions and draws new snake's position onto the board

    for (size_t i = 0; i < snake.pos_arr.size(); i++) {
      board.arr[snake.pos_arr[i]] = ' ';
    }

    for (size_t i = snake.pos_arr.size() - 1; i > 0; i--) {
      snake.pos_arr[i] = snake.pos_arr[i - 1];
    }

    // get new position of snake head based on next direction
    switch (snake.dir.curr) {
      case 'u': snake.pos_arr[0] -= board.width;  break;
      case 'd': snake.pos_arr[0] += board.width;  break;
      case 'l': snake.pos_arr[0] -= 1;            break;
      case 'r': snake.pos_arr[0] += 1;            break;
    }

    for (size_t i = 0; i < snake.pos_arr.size(); i++) {
      // Same line as the 3rd line in forloop in initSnake function
      board.arr[snake.pos_arr[i]] = (i == 0 ? snake.head_char : snake.body_char);
    }
  }


  //* Board Functions
  // =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=

  void initBoard(Board& board) {
    //* Populates board vector and walls vector. Walls vector is populated with positions of walls for easy collision detection. Main board vector is for drawing only

    if (board.arr.size() > 0) {
      board.arr.clear();
      board.walls.clear();
    }

    for (int i = 0; i < board.size; i++) {
      board.arr.push_back(' ');
    }

    int col = board.width;
    int row = board.height;
    int size = board.size;

    for (int i = 0; i < col; i++) {
      int j = size - 1 - i;

      board.arr[i] = board.wall_char;
      board.arr[j] = board.wall_char;

      board.walls.push_back(i);
      board.walls.push_back(j);
    }

    for (int i = 1; i < row - 1; i++) {
      int left = col * i;
      int right = (col * i) + (col - 1);

      board.arr[left] = board.wall_char;
      board.arr[right] = board.wall_char;

      board.walls.push_back(left);
      board.walls.push_back(right);
    }
  }

  void drawBoard(Board& board, cli func, cmnd arg) {
    //* Draws the board - needs to be already updated with everything (snake, apples, etc)

    func(arg);
    for (int i = 0; i < board.size; i++) {
      if (i != 0 && i % board.width == 0) std::cout << std::endl;
      std::cout << board.arr[i] << " ";
    }
    std::cout << std::endl;
  }

  bool hitDetection(Board& board, Snake& snake) {
    //* Detects collisions on walls and snake's own body

    // Using walls vector increases lookup speed slightly compared to looking up proper char in main board array, but requires more space the more there is wall segments
    for (size_t i = 0; i < board.walls.size(); i++) {
      if (board.walls[i] == snake.pos_arr[0]) return true;
    }

    // Skip to 4th element because snake's head is not able to hit earlier body parts
    if (snake.pos_arr.size() < 4) return false;

    for (size_t i = 4; i < snake.pos_arr.size(); i++) {
      if (snake.pos_arr[i] == snake.pos_arr[0]) return true;
    }

    return false;
  }


  //* Options Functions
  // =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=

  void spawnApple(Board& board, Apple& apple, randfunc getRand) {
    //* Spawns an apple in random free place on the board and draws it on the board already

    if (apple.pos != -1) return;

    do {
      apple.pos = getRand(0, board.size - 1);
    } while (board.arr[apple.pos] != ' ');

    board.arr[apple.pos] = apple.symbol;
  }


  //* Screen Functions
  // =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=

  void overrideScreen(std::vector<std::string>& screen, size_t row, size_t col, size_t size, std::string replacement) {
    size_t rep_len = replacement.length();

    if (rep_len < size) replacement.append(size - rep_len, ' ');
    if (rep_len > size) replacement.erase(size, rep_len - size);

    screen[row].replace(col, size, replacement);
  }

  void overrideScreenN(std::vector<std::string>& screen, size_t n_pos, std::vector<std::string>& vect) {
    size_t max_len = 0;
    size_t left_margin = 0;

    for (const std::string& line : vect) {
      if (line.length() > max_len) max_len = line.length();
    }
    left_margin = (100 + max_len) / 2 - max_len;

    for (size_t i = n_pos, j = 0; j < vect.size(); i++, j++) {
      screen[i].replace(left_margin, vect[j].length(), vect[j]);
    }
  }

  void showScreen(const std::vector<std::string>& screen, cli func, cmnd arg) {
    func(arg);
    for (size_t i = 0; i < screen.size(); i++) {
      std::cout << screen[i] << std::endl;
    }
  }


  //* Options Functions
  // =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=

  void loadConfig(Config& cnfg) {
    std::ifstream file("config.txt"); // exception
    std::string line;

    while (std::getline(file, line)) {
      if (line.find("1") != std::string::npos) 
        cnfg.flags.push_back(true);
      else
        cnfg.flags.push_back(false);
    }
    file.close();

    cnfg.use_ascii_extended = cnfg.flags[0];

    cnfg.flags.clear();
  }


  //* Scoreboard Functions
  // =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=

  void loadScoreboard(Scoreboard& scrbrd) {
    std::ifstream file("scoreboard.txt");
    std::string line;
    size_t limiter = 0;

    while (std::getline(file, line)) {
      scrbrd.scores.push_back(line);
      if (++limiter >= scrbrd.limit) break;
    }
    file.close();
  }
}