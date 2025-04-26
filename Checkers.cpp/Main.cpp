#include <iostream> 
#include <cstdlib>
#include "game.h"
#include "player.h"
using namespace std;


int main() {

    Game game;
    Player player;

    game.initialize();
    game.show();

    cout << endl << "It's White's turn." << endl;

    int fromRow, fromCol, toRow, toCol;

    while (true) {

        if (game.getW_Count() == 12) {
            cout << "\033[34m" << "Game over, Blue won!" << "\033[0m" << endl;
            break;
        }

        if (game.getB_Count() == 12) {
            cout << endl << "Game over, White won!" << endl;
            break;
        }

        cout << endl << "Enter coordinates: ";
        cin >> fromRow >> fromCol >> toRow >> toCol;

        Position from(fromRow, fromCol);
        Position to(toRow, toCol);

        if (game.IsValidMove(from, to, player.getCurrentPlayer(), player.getCurrentQueen())) {

            if (!game.WillEat(from, to)) {
                if (player.getCurrentPlayer() == WHITE) {
                    game.WhiteIsFuk(to);
                    game.WhiteQueenIsFuk(to);
                }
                else if (player.getCurrentPlayer() == BLUE) {
                    game.BlueIsFuk(to);
                    game.BlueQueenIsFuk(to);
                }
            }

            if (game.HasEaten(from, to)) {
                game.set_coord(to);
            }
            cout << endl << game.get_coord_r() << ", " << game.get_coord_c() << endl;

            game.move(from, to);
            system("cls");  
            game.show();

            if (player.getCurrentPlayer() == WHITE || player.getCurrentQueen() == WHITE_QUEEN) {
                if (game.HasEaten(from, to) && game.WhiteCanEat() || game.HasEaten(from, to) && game.WhiteQueenCanEat()) {
                    cout << endl << "It's White's turn, White should eat one more time." << endl;
                }
                else {
                    player.switchPlayers();
                }
            }

            else if (player.getCurrentPlayer() == BLUE || player.getCurrentQueen() == BLUE_QUEEN) {
                if (game.HasEaten(from, to) && game.BlueCanEat() || game.HasEaten(from, to) && game.BlueQueenCanEat()) {
                    cout << endl << "It's Blue's turn, Blue should eat one more time." << endl;
                }
                else {
                    player.switchPlayers();
                }
            }

            cout << "White has " << 12 - game.getW_Count() << " pieces" << endl;
            cout << "Blue has " << 12 - game.getB_Count() << " pieces" << endl;

        }

        else {
            cout << endl << "Invalid move." << endl;

            if (player.getCurrentPlayer() == WHITE) {
                cout << "It's White's turn" << endl;
            }
            else if (player.getCurrentPlayer() == BLUE) {
                cout << "It's Blue's turn" << endl;
            }
        }

    }

    return 0;

}
