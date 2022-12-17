#include <iostream>
#include <string.h>
using namespace std;

char m[3][3];
char player = 'X';
int n;

// display the box
void display()
{
    system("cls");
    // initialize the game
    cout << "******************************************************************\n";
    cout << "\t\t\tTIC TAC TOE\n";
    cout << "\t\t\tVersion 1.0\n";
    cout << "******************************************************************\n\n";
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            cout << "\t" << m[k][l];
        }
        cout << endl;
    }
}

// check if anyone won the game
char check_win()
{
    for (int i = 0; i < 3; i++)
    {
        if ((m[0][2] == player) && (m[1][1] == player) && (m[2][0] == player))
        {
            return player;
        }
        else if ((m[i][i] == player) && (m[i + 1][i + 1] == player) && (m[i + 2][i + 2] == player))
        {
            return player;
        }
        else if ((m[i][0] == player) && (m[i][1] == player) && (m[i][2] == player))
        {
            return player;
        }
        else if ((m[0][i] == player) && (m[1][i] == player) && (m[2][i] == player))
        {
            return 'X';
        }
    }
    return '/';
}

// toggle player
void toggle_player()
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

// set new value
void change(char no)
{
    int flag = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m[i][j] == no)
            {
                m[i][j] = player;
                flag = 1;
                return;
            }
        }
    }
    if (flag == 0)
    {
        cout << "\nwrong field chosen... try again\n";
        char n1;
        cout << "Enter a field of your choice : ";
        cin >> n1;
        change(n1);
    }
}

int main()
{
    char to_con = 'y';
    while (to_con == 'y')
    {
        n = 0;
        m[0][0] = '1';m[0][1] = '2';m[0][2] = '3';m[1][0] = '4';
        m[1][1] = '5';m[1][2] = '6';m[2][0] = '7';m[2][1] = '8';m[2][2] = '9';
        while (n <= 9)
        {
            if (n == 9)
            {
                cout << "******************************************************************\n";
                cout << "\n \t\t\tGAME IS DRAW\n\n";
                cout << "******************************************************************\n";
                n++;
            }
            else
            {

                display();
                cout << "\n\nIt is player " << player << "'s turn\n";
                cout << "enter your choice of field : ";
                char choice;
                cin >> choice;
                change(choice);
                char res = check_win();
                if (res != '/')
                {
                    display();
                    cout << "******************************************************************\n";
                    cout << "\n \t\tcongratulations!!! player " << player << " won the set\n\n";
                    cout << "******************************************************************\n";
                    break;
                }
                else
                {
                    toggle_player();
                    n++;
                }
            }
        }
        cout << "Do you want to play another match(y/n) : ";
        cin >> to_con;
    }
    return 0;
}