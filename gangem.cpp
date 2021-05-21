#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class casse
{public:

    int v;

public:
    casse(){
    v=0;



    };
   /* int comparer_valeur(int v1){
        if (v==v1)
        {c='g' ;
        return 1;

        }
        else {
            c='r';
            return 0;
        }
    }*/
    void changer_valeur(){
        int n;
        cin >> n ;
        while (1) {
            if (n<10 && n>0) {
                v=n;
                break;
            }

        }

    }

    void setvaleur(int v1){
        v=v1;



    }
    int getvaleur(){
        return v;

    }
    void printv(){
        cout<< v << " " ;
    }
};


class sudoku {
    private:


    casse grid[9][9];
    public:
    sudoku(){
        int j=0;
        int tab[9]={1,2,3,4,5,6,7,8,9};
        while (j<9){
                srand(time(NULL));
                int x=(rand()%9)+1;
                for(int i=0;i<9;i++){
                    if (tab[i] == x){
                        tab[i]=0;
                        grid[0][j].setvaleur(x);
                        j++;
                    }
                }


     //ligne 2:
        for (j=0;j<3;j++){
            grid[1][j+6].setvaleur(grid[0][j].getvaleur());
        }
        for (j=3;j<6;j++){
                grid[1][j-3].setvaleur(grid[0][j].getvaleur());
        }
        for (j=6;j<9;j++){
            grid[1][j-3].setvaleur(grid[0][j].getvaleur());
        }
        //ligne3:
        for(j=3;j<9;j++){
                grid[2][j-3].setvaleur(grid[1][j].getvaleur());
        }
        for(j=0;j<3;j++){
            grid[2][j+6].setvaleur(grid[1][j].getvaleur());
        }
        //ligne 4:
        for(j=1;j<9;j++){
                grid[3][j-1].setvaleur(grid[2][j].getvaleur());

        }
        grid[3][8].setvaleur(grid[2][0].getvaleur());
        //ligne5:
        for(j=0;j<3;j++){
            grid[4][j+6].setvaleur(grid[3][j].getvaleur());
        }
        for(j=3;j<9;j++){
            grid[4][j-3].setvaleur(grid[3][j].getvaleur());
        }
        //ligne6:
        for(j=3;j<9;j++){
            grid[5][j-3].setvaleur(grid[4][j].getvaleur());
        }
        for(j=0;j<3;j++){
            grid[5][j+6].setvaleur(grid[4][j].getvaleur());
        }
        //ligne7:
           for(j=1;j<9;j++){
                grid[6][j-1].setvaleur(grid[5][j].getvaleur());

        }
        grid[6][8].setvaleur(grid[5][0].getvaleur());
        //ligne 8:
          for(j=0;j<3;j++){
            grid[7][j+6].setvaleur(grid[6][j].getvaleur());
        }
        for(j=3;j<9;j++){
            grid[7][j-3].setvaleur(grid[6][j].getvaleur());
        }
        //ligne9:
        for(j=3;j<9;j++){
            grid[8][j-3].setvaleur(grid[7][j].getvaleur());
        }
        for(j=0;j<3;j++){
            grid[8][j+6].setvaleur(grid[7][j].getvaleur());
        }

    }
    //constructeur de recopie

sudoku(sudoku const& a)
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          grid[i][j].v=a.grid[i][j].v;
        }
    }
}
    void print() {
    for (int i = 0; i < 9; i++) {
		cout <<endl<<"*******************************"<<endl;
		for (int j = 0; j < 9; j++) {
			cout << grid[i][j].getvaleur()<<" | ";
		}
	}

    }
 /*sudoku generer(){
     int j=0;
     int nb=0;
     while (j<50){
        sudoku a=(*this);
        srand(time(NULL));
        int i=rand()%9;
        int j=rand()%9;
        int v=grid[i][j].getvaleur();
        grid[i][j].setvaleur(0);
        bool k=(*this).solvesuduko(i,j);
        if (grid[i][j].getvaleur() == v){
            grid[i][j].setvaleur(0);
            j++;
        }
        else{
            grid[i][j].setvaleur(v);
        }
        nb++;
        if (nb>100){break;}
     }



return (*this);
 }*/

    int isSafe( int i,int j, int num)
{

    // Check if we find the same num
    // in the similar row , we
    // return 0
    for (int x = 0; x < 9; x++)
        if (grid[i][x].getvaleur() == num)
            return 0;

    // Check if we find the same num in
    // the similar column , we
    // return 0
    for (int x = 0; x <= 8; x++)
        if (grid[x][j].getvaleur() == num)
            return 0;

    // Check if we find the same num in
    // the particular 3*3 matrix,
    // we return 0
    int startRow = i - i % 3,startCol = j - j % 3;

    for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++)
            if (grid[k + startRow][l +startCol].getvaleur() == num)
                return 0;

    return 1;
}
/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
protected:
    bool solveSuduko(int i, int j)
{
    // Check if we have reached the 8th
    // row and 9th column (0
    // indexed matrix) , we are
    // returning true to avoid
    // further backtracking
    if (i == 8 && j == 9)
        return true;

    // Check if column value  becomes 9 ,
    // we move to next row and
    //  column start from 0
    if (j == 9) {
        i++;
        j = 0;
    }

    // Check if the current position of
    // the grid already contains
    // value >0, we iterate for next column
    if (grid[i][j].getvaleur() > 0)
        return this->solveSuduko( i, j + 1);

    for (int num = 1; num <= 9; num++)
    {

        // Check if it is safe to place
        // the num (1-9)  in the
        // given row ,col  ->we
        // move to next column
        if (this->isSafe(i, j, num))
        {

           /* Assigning the num in
              the current (row,col)
              position of the grid
              and assuming our assined
              num in the position
              is correct     */
            grid[i][j].setvaleur(num);

            //  Checking for next possibility with next
            //  column
            if (this->solveSuduko(i, j + 1))
                return true;
        }

        // Removing the assigned num ,
        // since our assumption
        // was wrong , and we go for
        // next assumption with
        // diff num value
        grid[i][j].setvaleur(0);
    }
    return false;

    };




int main()
{
    sudoku a;
    a.print();
    cout<<endl;
     cout<<endl;


//a.generer().print();

}
