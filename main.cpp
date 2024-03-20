#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showTheirChoices(char choice);
char findWinner(char player, char computer);

using namespace std;

int main()
{

  char player;
  char computer;
  int playerWins = 0;
  int computerWins = 0;
  int playTimes = 0;

  while (playerWins < 3 && computerWins < 3)
  {
    player = getUserChoice();
    cout << "Player's choice : ";
    showTheirChoices(player);
    cout << endl;

    computer = getComputerChoice();
    cout << "Computer's choice  : ";
    showTheirChoices(computer);
    char result = findWinner(player, computer);

    if (result == 'p')
    {
      cout << "\nPlayer win this round!!!\n"
           << endl;
      playerWins++;
    }
    else if (result == 'c')
    {
      cout << "\nComputer win this round!!!\n"
           << endl;
      computerWins++;
    }
    else
    {
      cout << "\nIt'a tie";
    }

    if (playerWins == 3 && computerWins == 1)
    {
      cout << "Player beat computer with 3-1";
    }
    else if (playerWins == 3 && computerWins == 0)
    {
      cout << "Player beat computer with 3-0";
    }
    else if (playerWins == 3 && computerWins == 2)
    {
      cout << "Player beat computer with 3-2";
    }
    else if (computerWins == 3 && playerWins == 1)
    {
      cout << "Computer beat you with 3-1";
    }
    else if (computerWins == 3 && playerWins == 0)
    {
      cout << "Computer beat you with 3-0";
    }
    else if (computerWins == 3 && playerWins == 2)
    {
      cout << "Computer beat you with 3-2";
    }

    playTimes++;
  }
}

char getUserChoice()
{
  char choice;
  do
  {
    cout << "\nWelcome to the Rock, Paper and Scissor game!!!\n";
    cout << "**********************************************\n";
    cout << "Choose one (Rock or r , Paper for p and Scissor for s) : ";
    cin >> choice;
  } while (choice != 'r' && choice != 'p' && choice != 's');

  return choice;
}

char getComputerChoice()
{
  srand(time(0));
  int randT = rand() % 3 + 1;
  switch (randT)
  {
  case 1:
    return 'r';
    break;
  case 2:
    return 'p';
    break;
  case 3:
    return 's';
    break;
  }
}

void showTheirChoices(char choice)
{
  switch (choice)
  {
  case 'r':
    cout << "Rock!";
    break;
  case 'p':
    cout << "Paper!";
    break;
  case 's':
    cout << "Scissor!";
    break;
  }
}

char findWinner(char player, char computer)
{
  if (player == 'r' && computer == 's' ||
      player == 'p' && computer == 'r' ||
      player == 's' && computer == 'p')
  {
    return 'p';
  }
  else if (computer == 'r' && player == 's' ||
           computer == 'p' && player == 'r' ||
           computer == 's' && player == 'p')
  {
    return 'c';
  }
  else
  {
    return 't';
  }
}