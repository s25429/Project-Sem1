#include <vector>
#include <string>

namespace Screens {
  std::vector<std::string> Menu = {
    "   _!!!!!!!!!!   _!!      _!!   _!!!!!!!!!!   _!!   __!!                                            ",
    "  | !!!!!!!!!!  | !!!    | !!  | !!!!!!!!!!  | !!  / !!         *********             ************  ",
    "  | **_____ **  | ****   | **  | **  _____|  | ** / **        *************          ************** ",
    "  | **     \\_|  | ** **  | **  | ** |        | **/ **        ***        ***          **          ** ",
    "  \\ ########    | ##  ## | ##  | #######     | #####                     **          ***         ** ",
    "   \\  ########  | ##\\  ##| ##  | #######     | #####                    ###          ## #        ## ",
    "   _\\_____  $$  | $$ \\  $$ $$  | $$  __|     | $$  $$                   ##           ##  #       ## ",
    "  | $$    | $$  | $$  \\  $$$$  | $$ |        | $$\\  $$                ###            ##   #      ## ",
    "  | @@@@@@@@@@  | @@   \\  @@@  | @@@@@@@@@@  | @@ \\  @@           #####              ##    #     ## ",
    "  | @@@@@@@@@@  | @@    \\  @@  | @@@@@@@@@@  | @@  \\  @@         $$$$$               $$     $    $$ ",
    "  \\__________|  |__|     \\__|  |__________|  |__|   \\__\\       $$$                   $$      $   $$ ",
    "                                                              $$                     $$       $  $$ ",
    "  _____   _   _   ____    _____   _____   ___  ___   ____    $$$                     $$        $ $$ ",
    " |_   _| | | | | | ___|  | ____| | ___ | |   \\/   | | ___|   @@                      @@         @@@ ",
    "   | |   | |_| | ||__    ||  __  ||   || | |\\  /| | ||__     @@                      @@          @@ ",
    "   | |   |  _  | | __|   || |_ | ||___|| | | \\/ | | | __|    @@@@@@@@@@@@@@    @@    @@@@@@@@@@@@@@ ",
    "   | |   | | | | ||___   ||__| | |  _  | | |    | | ||___    @@@@@@@@@@@@@@    @@     @@@@@@@@@@@@  ",
    "   |_|   |_| |_| |____|  |_____| |_| |_| |_|    |_| |____|                                          ",
    "                                                                                                    ",
    "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~",
    ".._________......._______________......._____________________.......______________......._________..",
    ",/  [ 1 ]  \\,,,,,/     [ 2 ]     \\,,,,,/        [ 3 ]        \\,,,,,/     [ 4 ]    \\,,,,,/  [ 5 ]  \\,",
    "|  P L A Y  |---|  O P T I O N S  |---|  S C O R E B O A R D  |---|  C R E D I T S |---|  Q U I T  |",
    "~\\_________/~~~~~\\_______________/~~~~~\\_____________________/~~~~~\\______________/~~~~~\\_________/~",
    "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::",
  };

  std::vector<std::string> Fail = {
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
    "@@@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$@@@@@@",
    "@@@$$$$######################################################################################$$$$@@@",
    "@@$$###*****|  ___|**|  _  |**|  ****  |**| ____|*****| ___ |**| |*| |**| ____|**|  ___\\*****###$$@@",
    "@@$##***!!!!| |!!!!!!| |!| |!!| |\\!!/| |!!| !!!!!!!!!!| !!! |!!| \\!/ |!!| !!!!!!!| |!!!|!!!!***##$@@",
    "@@$#**!!!===| |=|_|==| |=| |==| |=\\/=| |==| ___|======| === |===\\ | /===| ___|===|    _|===!!!**#$@@",
    "@$$#*!!===;;| |;;||;;|  _  |;;| |;;;;| |;;| ;;;;;;;;;;| ;;; |;;;| | |;;;| ;;;;;;;| |\\ \\;;;===!!*#$$@",
    "@$#**!==;;::|_____|::| |:| |::| |::::| |::|_____|:::::|_____|::::\\_/::::|_____|::|_|:\\_\\::;;==!**#$@",
    "@$#*!!=;:::~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~:::;=!!*#$@",
    "@$#*!==;:~~~----------------------------------------------------------------------------~~~:;==!*#$@",
    "@$#*!=;::~--,,,,,,,,,,,,,,,,,,,,,,,,,| S C O R E  =  score |,,,,,,,,,,,,,,,,,,,,,,,,,,,,--~::;=!*#$@",
    "@$#*!=;:~~-,............................................................................,-~~:;=!*#$@",
    "@$#*!=;:~-,.                                _____________                               .,-~:;=!*#$@",
    "@$#*!=;:~~-,.............................../             \\..............................,-~~:;=!*#$@",
    "@$#*!=;::~--,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,|  R E T R Y ?  |,,,,,,,,,,,,,,,,,,,,,,,,,,,,,--~::;=!*#$@",
    "@$#*!==;:~~~-------------------------..___.\\_____________/.___..------------------------~~~:;==!*#$@",
    "@$#*!!=;:::~~~~~~~~~~~~~~~~~~~~~~~~~~/ [1] \\             / [2] \\~~~~~~~~~~~~~~~~~~~~~~~~~:::;=!!*#$@",
    "@$#**!==;;:::::::::::::::::::::::::::\\_YES_/.............\\_N_O_/::::::::::::::::::::::::::;;==!**#$@",
    "@$$#*!!===;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;===!!*#$$@",
    "@@$#**!!!==================================================================================!!!**#$@@",
    "@@$##***!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!***##$@@",
    "@@$$###**************************************************************************************###$$@@",
    "@@@$$$$######################################################################################$$$$@@@",
    "@@@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$@@@@@@",
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
  };

  std::vector<std::string> Credits = {
    " +------------------------------------------------------------------------------------------------+ ",
    " |                                                                                                | ",
    " |    Snek - The Game 2.0 created by Cezary Cislak.                                               | ",
    " |                                                                                                | ",
    " |    Game was created as an university project at Polsko Japonska                                | ",
    " |    Akademia Technik Komputerowych w Warszawie Filia Gdansk.                                    | ",
    " |                                                                                                | ",
    " |    It is named 2.0, because I have already made a snake game in the past, so it's a sequel!    | ",
    " |                                                                                                | ",
    " +------------------------------------------------------------------------------------------------+ ",
    " |                                                                                                | ",
    " |    If you want to see my other projects, here are my links:                                    | ",
    " |      - School Github page - https://github.com/s25429                                          | ",
    " |      - Personal Github page - https://github.com/ThatHoracy                                    | ",
    " |                                                                                                | ",
    " +------------------------------------------------------------------------------------------------+ ",
    " |                                                                                                | ",
    " |                                                                                                | ",
    " |                                          Lorem ipsum                                           | ",
    " |                                                                                                | ",
    " |                                                                                                | ",
    " +------------------------------------------------------------------------------------------------+ ",
    "                                 \\                               /                                  ",
    "                                  \\  [ 1 ] Return to Main Menu  /                                   ",
    "                                   \\___________________________/                                    ",
  };

  std::vector<std::string> Scoreboard = {
    " +------------------------------------------------------------------------------------------------+ ",
  " |                            ,-. ,-. ,-. ,-. ,-. ,-. ,-. ,-. ,-. ,-,                             | ",
  " |                            `-. |   | | |_/ |-  |_| | | |_| |_/ | |                             | ",
  " |                            `-' `-' `-' | \\ `-' |_/ `-' | | | \\ |_/                             | ",
  " +------------------------------------------------------------------------------------------------+ ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " |                                                                                                | ",
  " +------------------------------------------------------------------------------------------------+ ",
  "                                 \\                               /                                  ",
  "                                  \\  [ 1 ] Return to Main Menu  /                                   ",
  "                                   \\___________________________/                                    ",
  };
}