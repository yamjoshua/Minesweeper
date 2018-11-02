
//
//  Created by Joshua Yam on 2/9/18.
//  Copyright © 2018 Joshua Yam. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Block {
    bool visible = false;
    //random generator to determine if the block is a bomb or not
    bool isBomb = false;
    //count number of neighbor bombs this block has
    int bombNeighbors = 0;
    int row_block;
    int column_block;
    
};
class Minesweeper {
    
public:
    Minesweeper() {//MINESWEEPER constructor
        srand(time(NULL));//Random Seed
        for (int i = 0; i < max; ++i) {
            vector<Block> cols;
            for (int j = 0; j < max; ++j) {//2D Vector to create grid
                Block block;
                block.row_block=i;
                block.column_block=j;
                int rint = rand() % 10;
                if (rint < 3) {
                    block.isBomb = true;
                }
                cols.push_back(block);
            }
            rows.push_back(cols);
        }
        for (int i = 0; i < max; ++i) {
            for (int j = 0; j < max; ++j) {
                if ((i == 0) && (j == 0)){
                    //top corner left
                    if (rows[i][j + 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i+1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i+1][j+1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                }
                else if ((i == 0) && (j == max-1)) {
                    //top corner right
                    if (rows[i][j - 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i + 1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i+1][j-1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                }
                else if ((i == max-1) && (j == 0)) {
                    //bottom corner left
                    if (rows[i][j + 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i - 1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i-1][j+1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                }
                else if ((i == max-1) && (j == max-1)) {
                    //bottom corner right
                    if (rows[i][j - 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i - 1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i - 1][j-1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                }
                else if (i == 0) {
                    //top border
                    if (rows[i][j-1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i][j + 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i + 1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i + 1][j+1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i + 1][j-1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                }
                else if (i == max-1) {
                    //bottom border
                    if (rows[i][j - 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i][j + 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i - 1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i - 1][j-1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i - 1][j+1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                }
                else if (j == 0) {
                    //left border
                    if (rows[i - 1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i + 1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i][j + 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i+1][j + 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i-1][j + 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                }
                else if (j == max-1) {
                    //right border
                    if (rows[i - 1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i + 1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i][j - 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i+1][j - 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i-1][j - 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                }
                else {
                    //everything else in the middle
                    if (rows[i - 1][j-1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i -1][j].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i-1][j + 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i][j - 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i][j+1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i+1][j - 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i+1][j ].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                    if (rows[i+1][j + 1].isBomb) {
                        rows[i][j].bombNeighbors++;
                    }
                }
            }
        }
    }
    

    
    void display(const bool& showBomb) {
        //Takes boolean. If False, prints without showing the bombs. If true, prints with bombs.
       
        if (!showBomb) {
            cout << "   ";
            for (int i = 0; i < max; ++i) {
                cout << i << "  ";
            }
            cout<<endl;
            for (int i = 0; i < max; ++i) {
                cout<< i << " ";
                for (int j = 0; j < max; ++j) {
                    if (rows[i][j].visible) {
                        if (rows[i][j].isBomb) {
                            cout << " ! ";
                        }
                        else {
                            cout << " " << rows[i][j].bombNeighbors<<" ";
                        }
                    }
                    else {
                        cout << " # ";
                    
                    }
                }
                cout << endl;
                cout << endl;
            }
        }
        else{
            cout << "   ";
            for (int i = 0; i < max; ++i) {
                cout << i << "  ";
            }
            cout<<endl;
            for (int i = 0; i < max; ++i) {
                cout<< i << " ";
                for (int j = 0; j < max; ++j) {
                    if (rows[i][j].isBomb) {
                        cout << " ! ";
                    }
                    else {
                        cout << " " << rows[i][j].bombNeighbors<<" ";
                    }
                }
                cout << endl;
                cout << endl;
            }
        }
    }
    
    bool done() {
        //returns TRUE if game is over, otherwise FALSE
        return false;
    }
    
    bool validRow(const int& row) {
        //Returns true if row is valid
        if (row < max) {
            return true;
        }
        return false;
    }
    
    bool validCol(const int& column) {
        //Returns true if column is valid
        if (column < max) {
            return true;
        }
        return false;
    }
    
    bool isVisible(const int& row, const int& column) {
        //Returns true if Block is visible
        if (rows[row][column].visible) {
            return true;
        }
        return false;
    }
    
    bool play(int& row, int& column) {
        //Takes a row number and a column number, changing the state of the board as appropriate for this move.
        //Returns FALSE if the move results in an explosion.
        //While loop appends surrounding block if it has no surrounding bombs.
        if (rows[row][column].isBomb){
            return false;
        }
        rows[row][column].visible = true;
        
        if (rows[row][column].bombNeighbors == 0){
            adjacent.push_back(rows[row][column]);
        }
        while (adjacent.size() != 0){
            if ((row == 0) && (column == 0)){
                cout<<"PROBLEM 1"<<endl;
                adjacent.pop_back();
               
                //top corner left
                if (rows[row][column + 1].bombNeighbors==0 && rows[row][column+1].visible==false) {
                    adjacent.push_back(rows[row][column+1]);
                }
                if (rows[row+1][column].bombNeighbors==0 && rows[row + 1][column].visible==false) {
                    adjacent.push_back(rows[row+1][column]);
                }
                if (rows[row+1][column+1].bombNeighbors==0 && rows[row + 1][column+1].visible==false) {
                    adjacent.push_back(rows[row+1][column+1]);
                }
                rows[row][column + 1].visible=true;
                rows[row+1][column].visible=true;
                rows[row+1][column+1].visible=true;
            }
            else if ((row == 0) && (column == max-1)) {
                //top corner right
                cout<<"PROBLEM 2"<<endl;
                adjacent.pop_back();
                if (rows[row][column - 1].bombNeighbors==0 && rows[row][column-1].visible==false) {
                    adjacent.push_back(rows[row][column - 1]);
                }
                if (rows[row + 1][column].bombNeighbors==0 && rows[row +1][column].visible==false) {
                    adjacent.push_back(rows[row+1][column]);
                }
                if (rows[row+1][column-1].bombNeighbors==0 && rows[row + 1][column-1].visible==false) {
                    adjacent.push_back(rows[row+1][column-1]);
                }
                rows[row][column - 1].visible=true;
                rows[row + 1][column].visible=true;
                rows[row+1][column-1].visible=true;
            }
            else if ((row == max-1) && (column == 0)) {
                //bottom corner left
                cout<<"PROBLEM 3"<<endl;
                adjacent.pop_back();
                
                if (rows[row][column + 1].bombNeighbors==0 && rows[row][column+1].visible==false) {
                    adjacent.push_back(rows[row][column + 1]);
                }
                if (rows[row - 1][column].bombNeighbors==0 && rows[row - 1][column].visible==false) {
                    adjacent.push_back(rows[row-1][column]);
                }
                if (rows[row-1][column+1].bombNeighbors==0 && rows[row - 1][column+1].visible==false) {
                    adjacent.push_back(rows[row-1][column + 1]);
                }
                rows[row][column + 1].visible=true;
                rows[row - 1][column].visible=true;
                rows[row-1][column+1].visible=true;
            }
            else if ((row == max-1) && (column == max-1)) {
                //bottom corner right
                cout<<"PROBLEM 4"<<endl;
                adjacent.pop_back();
                if (rows[row][column - 1].bombNeighbors==0 && rows[row][column-1].visible==false) {
                    adjacent.push_back(rows[row][column - 1]);
                }
                if (rows[row - 1][column].bombNeighbors==0 && rows[row - 1][column].visible==false) {
                    adjacent.push_back(rows[row-1][column]);
                }
                if (rows[row - 1][column-1].bombNeighbors==0 && rows[row - 1][column-1].visible==false) {
                    adjacent.push_back(rows[row-1][column - 1]);
                }
                rows[row][column - 1].visible=true;
                rows[row - 1][column].visible=true;
                rows[row - 1][column-1].visible=true;
            }
            else if (row == 0) {
                cout<<"PROBLEM 5"<<endl;
                adjacent.pop_back();
                //top border
                if (rows[row][column-1].bombNeighbors==0 && rows[row][column-1].visible==false) {
                    adjacent.push_back(rows[row][column - 1]);
                }
                if (rows[row][column + 1].bombNeighbors==0 && rows[row][column+1].visible==false) {
                    adjacent.push_back(rows[row][column + 1]);
                }
                if (rows[row + 1][column].bombNeighbors==0 && rows[row +1][column].visible==false) {
                    adjacent.push_back(rows[row + 1][column]);
                }
                if (rows[row + 1][column+1].bombNeighbors==0 && rows[row +1][column+1].visible==false) {
                    adjacent.push_back(rows[row + 1][column+1]);
                }
                if (rows[row + 1][column-1].bombNeighbors==0 && rows[row + 1][column - 1].visible==false) {
                    adjacent.push_back(rows[row + 1][column-1]);
                }
                rows[row][column-1].visible=true;
                rows[row][column + 1].visible=true;
                rows[row + 1][column].visible=true;
                rows[row + 1][column+1].visible=true;
                rows[row + 1][column-1].visible=true;
            }
            else if (row == max-1) {
                cout<<"PROBLEM 6"<<endl;
                adjacent.pop_back();
                //bottom border
                if (rows[row][column - 1].bombNeighbors==0 && rows[row][column-1].visible==false) {
                    adjacent.push_back(rows[row][column - 1]);
                }
                if (rows[row][column + 1].bombNeighbors==0 && rows[row][column+1].visible==false) {
                    adjacent.push_back(rows[row][column + 1]);
                }
                if (rows[row - 1][column].bombNeighbors==0 && rows[row - 1][column].visible==false) {
                    adjacent.push_back(rows[row-1][column]);
                }
                if (rows[row - 1][column-1].bombNeighbors==0 && rows[row - 1][column-2].visible==false) {
                    adjacent.push_back(rows[row-1][column - 1]);
                }
                if (rows[row - 1][column+1].bombNeighbors==0 && rows[row - 1][column+1].visible==false) {
                    adjacent.push_back(rows[row-1][column + 1]);
                }
                rows[row][column - 1].visible=true;
                rows[row][column + 1].visible=true;
                rows[row - 1][column].visible=true;
                rows[row - 1][column-1].visible=true;
                rows[row - 1][column+1].visible=true;
            }
            else if (column == 0) {
                cout<<"PROBLEM 7"<<endl;
                adjacent.pop_back();
                //left border
                if (rows[row - 1][column].bombNeighbors==0 && rows[row - 1][column].visible==false) {
                     adjacent.push_back(rows[row - 1][column]);
                }
                if (rows[row + 1][column].bombNeighbors==0 && rows[row + 1][column].visible==false) {
                    adjacent.push_back(rows[row + 1][column]);
                }
                if (rows[row][column + 1].bombNeighbors==0 && rows[row][column + 1].visible==false) {
                    adjacent.push_back(rows[row][column+1]);
                }
                if (rows[row+1][column + 1].bombNeighbors==0 && rows[row + 1][column+1].visible==false) {
                    adjacent.push_back(rows[row + 1][column+1]);
                }
                if (rows[row-1][column + 1].bombNeighbors==0 && rows[row - 1][column+1].visible==false) {
                    adjacent.push_back(rows[row - 1][column + 1]);
                }
                rows[row -1][column].visible=true;
                rows[row-1][column + 1].visible=true;
                rows[row][column + 1].visible=true;
                rows[row+1][column ].visible=true;
                rows[row+1][column+ 1].visible=true;
            }
            else if (column == max-1) {
                //right border
                cout<<"PROBLEM 9"<<endl;
                adjacent.pop_back();
                if (rows[row - 1][column].bombNeighbors==0 && rows[row - 1][column].visible==false) {
                   adjacent.push_back(rows[row - 1][column]);
                }
                if (rows[row + 1][column].bombNeighbors==0 && rows[row + 1][column].visible==false) {
                   adjacent.push_back(rows[row + 1][column]);
                }
                if (rows[row][column - 1].bombNeighbors==0 && rows[row][column-1].visible==false) {
                   adjacent.push_back(rows[row][column - 1]);
                }
                if (rows[row+1][column - 1].bombNeighbors==0 && rows[row + 1][column-1].visible==false) {
                   adjacent.push_back(rows[row+1][column - 1]);
                }
                if (rows[row-1][column- 1].bombNeighbors==0 && rows[row - 1][column-1].visible==false) {
                   adjacent.push_back(rows[row-1][column - 1]);
                }
                rows[row - 1][column].visible=true;
                rows[row + 1][column].visible=true;
                rows[row][column - 1].visible=true;
                rows[row+1][column - 1].visible=true;
                rows[row-1][column - 1].visible=true;
            }
            else {
                cout<<"PROBLEM 10"<<endl;
                adjacent.pop_back();
                //everything else in the middle
                if ((rows[row - 1][column-1]).bombNeighbors==0 && rows[row - 1][column-1].visible==false) {
                   adjacent.push_back(rows[row - 1][column-1]);
                }
                if ((rows[row -1][column]).bombNeighbors==0 && rows[row - 1][column].visible==false) {
                   adjacent.push_back(rows[row -1][column]);
                }
                if ((rows[row-1][column + 1]).bombNeighbors==0 && rows[row - 1][column+1].visible==false) {
                   adjacent.push_back(rows[row -1][column+1]);
                }
                if ((rows[row][column - 1]).bombNeighbors==0 && rows[row][column-1].visible==false) {
                   adjacent.push_back(rows[row][column-1]);
                }
                if ((rows[row][column + 1]).bombNeighbors==0 && rows[row ][column+1].visible==false) {
                   adjacent.push_back(rows[row][column+1]);
                }
                if ((rows[row+1][column - 1]).bombNeighbors==0 && rows[row + 1][column-1].visible==false) {
                   adjacent.push_back(rows[row +1][column-1]);
                }
                if ((rows[row+1][column]).bombNeighbors==0 && rows[row + 1][column].visible==false) {
                   adjacent.push_back(rows[row +1][column]);
                }
                if ((rows[row+1][column+ 1]).bombNeighbors==0 && rows[row + 1][column+1].visible==false) {
                   adjacent.push_back(rows[row +1][column+1]);
                }
                rows[row - 1][column-1].visible=true;
                rows[row -1][column].visible=true;
                rows[row-1][column + 1].visible=true;
                rows[row][column - 1].visible=true;
                rows[row][column + 1].visible=true;
                rows[row+1][column - 1].visible=true;
                rows[row+1][column ].visible=true;
                rows[row+1][column+ 1].visible=true;
            }
            row=adjacent.back().row_block;
            column=adjacent.back().column_block;
  
        }
        return true;
    }
private:
    vector<vector<Block>> rows;
    int max = 10;
    vector<Block> adjacent;//Vector of blocks that have no bombs surrounding cell.
};

int main() {
    Minesweeper sweeper;
    // Continue until the only invisible cells are bombs
    while (!sweeper.done()) {
        sweeper.display(false); // display the board without bombs
        
        int row_sel = -1, col_sel = -1;
        while (row_sel == -1) {
            // Get a valid move
            int r, c;
            cout << "row? ";
            cin >> r;
            if (!sweeper.validRow(r)) {
                cout << "Row out of bounds\n";
                continue;
            }
            cout << "col? ";
            cin >> c;
            if (!sweeper.validCol(c)) {
                cout << "Column out of bounds\n";
                continue;
            }
            if (sweeper.isVisible(r, c)) {
                cout << "Square already visible\n";
                continue;
            }
            row_sel = r;
            col_sel = c;
        }
        if (!sweeper.play(row_sel, col_sel)) {
            cout << "BOOM!!!\n";
            cout<<endl;
            sweeper.display(true);
            exit(0);
        }
    }
    cout << "You won!!!!\n";
    sweeper.display(true); // Final board with bombs shown
    
}
