#include <iostream>
//#include <windows.h>
#include <limits>

struct Queen {
  int x;
  int y;
  char symbol;
};

struct Grid {
  int size;

  void render (Queen white, Queen black)
  {
   for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        if (white.x == j && white.y == i)
        {
          std::cout << white.symbol << " ";
        }
        else if (black.x == j && black.y == i)
        {
          std::cout << black.symbol << " ";
        }
        else
        std::cout << ", ";
      }
      std::cout << std::endl;  
    } 
  }
};

bool valid (Queen white, Queen black)
{
  int k = abs(white.x-black.x);
  if ((white.x == black.x && white.y != black.y) || (white.x != black.x && white.y == black.y)) 
  {
    return true;
  }
  else if (abs(white.y - black.y) == k)
  {
    return true;
  }
  else
    return false;
};

int main ()
{
  system("clear");

  char replay = 'Y';
  std::cout << "Use coordinates 0-7. With (0, 0) being the top left of the board." << std::endl;
  system("pause");
  system("clear");

  while (replay == 'Y' || replay == 'y')
{
  Grid board{8};
  Queen white{};
  white.symbol = 'W';
  white.x = 7;
  white.y = 3;
  Queen black;
  black.symbol = 'B';
  black.x = 0;
  black.y = 3;

  std::cout << "Enter x coordinate for white queen" << std::endl;
    //std::cin >> white.x;
    while (!(std::cin >> white.x) || (white.x > 7 || white.x < 0)) {
        system("clear");
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter white x coordinate.\n";
    }
    system("clear");  

    std::cout << "Enter y coordinate for white queen" << std::endl;
    //std::cin >> white.y;
    while (!(std::cin >> white.y) || (white.y > 7 || white.y < 0)) {
        system("clear");
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter white y coordinate.\n";
    }
    system("clear"); 

    std::cout << "Enter x coordinate for black queen" << std::endl;
    //std::cin >> black.x;
    while (!(std::cin >> black.x) || (black.x > 7 || black.x < 0)) {
        system("clear");
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter black x coordinate.\n";
    }
    system("clear");

    std::cout << "Enter y coordinate for black queen" << std::endl;
    //std::cin >> black.y;
    while (!(std::cin >> black.x) || (black.x > 7 || black.x < 0)) {
        system("clear");
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter. black y coordinate\n";
    }

    system("clear");
    board.render(white, black);

    if (valid(white, black))
    {
      std::cout << "The queens are attacking each other" << std::endl;
    }
    else
    {
      std::cout << "The queens are not attacking each other" << std::endl;
    }
    system("pause");
    system("clear");

    std::cout << "Would you like to play again? (Y/N)" << std::endl;
    std::cin >> replay;
    system("clear");
}
  return 0;
}
