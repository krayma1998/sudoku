#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class casse
{
private:

    int v;

public:
    casse(){v=0;}
    void setvaleur(int v1){v=v1;}
    int getvaleur(){return v;}
    void printv(){cout<< v << " " ;}
};


class sudoku
{
private:
    int d;
    casse grid[9][9];
public:
   sudoku();
   sudoku(sudoku const& );
   void print();

    sudoku generer();
bool isSafe( int row, int col, int num);

bool solveSuduko( int row, int col);
int sudoget(int i,int j);
 void sudoset(int i,int j,int v);
 void setd(int d1);

};

sudoku::sudoku()
    {
        d=1;
        int j=0;
        int tab[9]= {1,2,3,4,5,6,7,8,9};
        while (j<9)
        {
            srand(time(NULL));
            int x=(rand()%9)+1;
            for(int i=0; i<9; i++)
            {
                if (tab[i] == x)
                {
                    tab[i]=0;
                    grid[0][j].setvaleur(x);
                    j++;
                }
            }
        }

        //ligne 2:
        for (j=0; j<3; j++)
        {
            grid[1][j+6].setvaleur(grid[0][j].getvaleur());
        }
        for (j=3; j<6; j++)
        {
            grid[1][j-3].setvaleur(grid[0][j].getvaleur());
        }
        for (j=6; j<9; j++)
        {
            grid[1][j-3].setvaleur(grid[0][j].getvaleur());
        }
        //ligne3:
        for(j=3; j<9; j++)
        {
            grid[2][j-3].setvaleur(grid[1][j].getvaleur());
        }
        for(j=0; j<3; j++)
        {
            grid[2][j+6].setvaleur(grid[1][j].getvaleur());
        }
        //ligne 4:
        for(j=1; j<9; j++)
        {
            grid[3][j-1].setvaleur(grid[2][j].getvaleur());

        }
        grid[3][8].setvaleur(grid[2][0].getvaleur());
        //ligne5:
        for(j=0; j<3; j++)
        {
            grid[4][j+6].setvaleur(grid[3][j].getvaleur());
        }
        for(j=3; j<9; j++)
        {
            grid[4][j-3].setvaleur(grid[3][j].getvaleur());
        }
        //ligne6:
        for(j=3; j<9; j++)
        {
            grid[5][j-3].setvaleur(grid[4][j].getvaleur());
        }
        for(j=0; j<3; j++)
        {
            grid[5][j+6].setvaleur(grid[4][j].getvaleur());
        }
        //ligne7:
        for(j=1; j<9; j++)
        {
            grid[6][j-1].setvaleur(grid[5][j].getvaleur());

        }
        grid[6][8].setvaleur(grid[5][0].getvaleur());
        //ligne 8:
        for(j=0; j<3; j++)
        {
            grid[7][j+6].setvaleur(grid[6][j].getvaleur());
        }
        for(j=3; j<9; j++)
        {
            grid[7][j-3].setvaleur(grid[6][j].getvaleur());
        }
        //ligne9:
        for(j=3; j<9; j++)
        {
            grid[8][j-3].setvaleur(grid[7][j].getvaleur());
        }
        for(j=0; j<3; j++)
        {
            grid[8][j+6].setvaleur(grid[7][j].getvaleur());
        }

    }

sudoku::sudoku(sudoku const& a)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j]=a.grid[i][j];
            }
        }
    }

     void sudoku::print()
    {
        for (int i = 0; i < 9; i++)
        {
            cout <<endl<<"***********************************"<<endl;
            for (int j = 0; j < 9; j++)
            {
                cout << grid[i][j].getvaleur()<<" | ";
            }
        }

    }

    sudoku sudoku::generer()
    {
        int m=0;
        int nb=0;
        int r;
        sudoku b=(*this);
        if (d=1)
        {
            r=30;
        }
        if (d=2)
        {
            r=40;
        }
       else
        {
            r=50;
        }
        while (m<r)
        {



            int i=rand()%9;
            int j=rand()%9;

            int v=grid[i][j].getvaleur();
            grid[i][j].setvaleur(0);
            if ((solveSuduko(0,0)) && (grid[i][j].getvaleur() == v))
            {
                b.grid[i][j].setvaleur(0);
                m++;
            }
            else
            {
                grid[i][j].setvaleur(v);
            }
            nb++;



        }



        return b;
    }

    bool sudoku::isSafe( int row, int col, int num)
    {


        for (int x = 0; x <= 8; x++)
            if (grid[row][x].getvaleur() == num)
                return false;

        for (int x = 0; x <= 8; x++)
            if (grid[x][col].getvaleur() == num)
                return false;

        int startRow = row - row % 3,
            startCol = col - col % 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[i + startRow][j +startCol].getvaleur() == num)
                    return false;

        return true;
    }


    bool sudoku::solveSuduko( int row, int col)
    {

        if (row == 8 && col == 9)
            return true;


        if (col == 9)
        {
            row++;
            col = 0;
        }


        if (grid[row][col].getvaleur() > 0)
            return solveSuduko(row, col + 1);

        for (int num = 1; num <= 9; num++)
        {


            if (isSafe(row, col, num))
            {

                grid[row][col].setvaleur(num);

                if (solveSuduko(row, col + 1))
                    return true;
            }

            grid[row][col].setvaleur(0);
        }
        return false;
    }
    int sudoku::sudoget(int i,int j)
    {
        return grid[i][j].getvaleur();

    }
    void sudoku::sudoset(int i,int j, int v)
    {
        grid[i][j].setvaleur(v);

    }

    void sudoku::setd(int d1)
    {
        d=d1;
    }

int main()
{
    while (true)
    {
        cout<<"Choisissez la difficulte:"<<endl;
        cout<<"Easy:1"<<endl;
        cout<<"Medium:2"<<endl;
        cout<<"Hard:3"<<endl;
        int d;
        do{
            cin>>d;
        }while(d!=1 && d!=2 && d!=3);

        sudoku a;
        a.setd(d);
        sudoku g = a.generer();
        sudoku k(g);
        g.print();
        cout<<endl;
        while (true)
        {
            int i,j;
            cout<<endl;
            cout<<"-----------------------------------";
            cout<<endl;
            cout<<"choisir la ligne:";
            cin>>i;
            cout<<"choisir la colonne:";
            cin>>j;
            if(k.sudoget(i,j) != 0)
            {
                continue;
            }
            else
            {
                cout<<"entrer une valeur entre 1 et 9:";
                int x;
                cin>>x;
                g.sudoset(i,j,x);
                system("cls");
                g.print();
                cout<<endl;
                cout<<"verifier votre reponse?"<< "si oui entrez 1 sinon entrez 0:";
                int y;
                cin>>y;
                if (y==0)
                {
                    continue;
                }
                if(y==1)
                {
                    int n=1;
                    for (int k=0; k<9; k++)
                    {
                        for(int l=0; l<9; l++)
                        {
                            if (g.sudoget(i,j) != a.sudoget(i,j))
                            {
                                n=0;
                                break;
                            }
                        }
                    }
                    if(n==1)
                    {
                        cout<<"felicitations";
                    }
                    if(n==0)
                    {
                        cout<<"votre reponse est incorrecte";
                    }


                }

            }


        }


    }



}
