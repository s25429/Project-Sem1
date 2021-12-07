#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

#include "templates/screens.cpp"
#include "api/sga.cpp"


#ifdef __linux__
  #include "utils/linux.cpp"
#else
  #include "utils/win32.cpp"
#endif


char updateDirection(int user_input, char old_dir) {
  //* Assigns new direction based on given imput and movement constrains

  char new_dir = 'u';

  switch (user_input) {
    case KEY_UP[KEY_LEN - 1]:     new_dir = 'u'; break;
    case KEY_DOWN[KEY_LEN - 1]:   new_dir = 'd'; break;
    case KEY_LEFT[KEY_LEN - 1]:   new_dir = 'l'; break;
    case KEY_RIGHT[KEY_LEN - 1]:  new_dir = 'r'; break;
  }

  switch (old_dir) {
    case 'u': if (new_dir == 'd') new_dir = old_dir; break;
    case 'd': if (new_dir == 'u') new_dir = old_dir; break;
    case 'l': if (new_dir == 'r') new_dir = old_dir; break;
    case 'r': if (new_dir == 'l') new_dir = old_dir; break;
  }

  return new_dir;
}

int getKey() {
  int input;
  for (size_t i = 0; i < KEY_LEN; i++) {
    input = _getch();

    if (i + 1 != KEY_LEN) {
      if (input != KEY_UP[i]) break;
      continue;
    }
  }

  if (sga::DEBUG) std::cout << "[" << input << "]" << std::endl;
  return input;
}

int getRand(int arg_min, int arg_max) {
  //* Returns random integer in range [arg_min, arg_max]

  std::random_device rd;
  std::uniform_int_distribution<int> rand_int(arg_min, arg_max);
  return rand_int(rd);
}


int main() {
  sga::randfunc rand_func = &getRand;

  auto app =        sga::App{ 100, 3 };
  auto tui =        sga::TUI{};
  auto board =      sga::Board{ '*', 25, 25 };
  auto snake =      sga::Snake{ '@', '#', 3 };
  auto apple =      sga::Apple{ 'X', 1 };
  auto config =     sga::Config{};
  auto scoreboard = sga::Scoreboard{ 16 };


  sga::loadConfig(config);


  // First show main menu and manage further instructions after key input
  do {
    // Display menu - this is the value of state by default
    while (tui.state == sga::State::MENU && app.running) {
      sga::showScreen(Screens::Menu, system, SYS_CLEAR);

      app.user_input = getKey();

      switch (app.user_input) {
        case (int)'1': tui.state = sga::State::GAME;       break;
        case (int)'2': tui.state = sga::State::OPTIONS;    break;
        case (int)'3': tui.state = sga::State::SCOREBOARD; break;
        case (int)'4': tui.state = sga::State::CREDITS;    break;
        case (int)'5': app.running = false;                break;
      }

    };

    // Run game
    while (tui.state == sga::State::GAME && app.running) {
      sga::initBoard(board);
      sga::initSnake(snake, board);

      app.tick = 0;
      app.score = 0;

      apple.pos = -1;
      sga::spawnApple(board, apple, rand_func);
      sga::drawBoard(board, system, SYS_CLEAR);

      while (tui.state != sga::State::FAIL && app.running) {
        // Key hit detection and movement
        if (_kbhit()) {
          app.user_input = getKey();
          snake.dir.curr = updateDirection(app.user_input, snake.dir.old);
        }

        // Game logic that has to be constrained on tick value
        if (app.tick == 0) {
          if (apple.pos == snake.pos_arr[0]) {
            app.score += apple.score;
            apple.pos = -1;
            sga::E_X_P_A_N_D__S_N_E_K(snake);
            sga::spawnApple(board, apple, rand_func);
          }

          sga::updateSnakeOnBoard(snake, board);

          // Game over
          if (sga::hitDetection(board, snake)) 
            tui.state = sga::State::FAIL;

          sga::drawBoard(board, system, SYS_CLEAR);
          std::cout << app.score << ", " << apple.score << std::endl;
          snake.dir.old = snake.dir.curr;
        }

        // Manage game function keys
        if (app.user_input == 'q' || app.user_input == 'Q') 
          tui.state = sga::State::FAIL;

        // Other game logic
        app.tick = (app.tick + 1) % app.tick_cap;
        std::this_thread::sleep_for(std::chrono::milliseconds(app.refresh_speed));
      }
    };

    // Display on game over
    while (tui.state == sga::State::FAIL && app.running) {
      sga::overrideScreen(Screens::Fail, 10, 53, 5, std::to_string(app.score));
      sga::showScreen(Screens::Fail, system, SYS_CLEAR);

      app.user_input = getKey();

      switch (app.user_input) {
        case (int)'1': tui.state = sga::State::GAME; break;
        case (int)'2': tui.state = sga::State::MENU; break;
      }
    }

    // Display options
    while (tui.state == sga::State::OPTIONS && app.running) {
      system(SYS_CLEAR);
      std::cout << "Options are not supported yet. Press 1 to go back to the main menu." << std::endl;

      app.user_input = getKey();

      switch (app.user_input) {
        case (int)'1': tui.state = sga::State::MENU; break;
      }
    };

    // Display scoreboard
    while (tui.state == sga::State::SCOREBOARD && app.running) {
      sga::loadScoreboard(scoreboard);
      sga::overrideScreenN(Screens::Scoreboard, 5, scoreboard.scores);
      sga::showScreen(Screens::Scoreboard, system, SYS_CLEAR);

      app.user_input = getKey();

      switch (app.user_input) {
        case (int)'1': tui.state = sga::State::MENU; break;
      }
    };

    // Display credits
    while (tui.state == sga::State::CREDITS && app.running) {
      sga::showScreen(Screens::Credits, system, SYS_CLEAR);
      
      app.user_input = getKey();

      switch (app.user_input) {
        case (int)'1': tui.state = sga::State::MENU; break;
      }
    };

  } while (app.running);

  return 0;
}
