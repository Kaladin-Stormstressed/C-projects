#include <iostream>
#include <math.h>
using namespace std;


void citirepuncte(int n, int punct[100][2] )

{
    int  i, j;

    //urmatoarele doua sunt pentru citire si afisare
    for (i = 1; i <= n; i++)
    {
        cout << "punctul " << i << " " << endl;
        for (j = 0; j < 2; j++)
        {
            cin >> punct[i][j];
        }

    }

    cout << endl;
    cout << "x y"<<endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << punct[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

void calcululdistantelor(int n, int punct[100][2])
{
    float distanta[1000], maxL, X, Y, D, x1, x2, y1, y2;
    int i, j, pozitie[1000][4];
    cout << "matricea punctelor" << endl;

    //acest for face fiecare combinatie posibila de puncte si le scade.
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= n; j++)
        {
            x1 = punct[i][0];
            x2 = punct[j][0];
            y1 = punct[i][1];
            y2 = punct[j][1];
            X = x1 - x2;
            Y = y1 - y2;
            D = pow(X, 2) + pow(Y, 2);

            distanta[i * j] = sqrt(D);
            pozitie[i * j][0] = x1;
            pozitie[i * j][1] = x2;
            pozitie[i * j][2] = y1;
            pozitie[i * j][3] = y2;

            cout << i << j << " ";
        }
        cout << endl;
    }





    //afisarea distantelor si cautarea maximului.
    cout << "distantele sunt:" << endl;
    maxL = distanta[0];

    int LeBaguette=0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {

            cout << distanta[i * j] << " ";
            if (maxL < distanta[i * j])
            {
                maxL = distanta[i * j];
                LeBaguette = i * j; 
            }

           
        }
        cout << endl;
    }


    cout << endl << "distanta cea mai mare dintre doua puncte este:" << maxL << endl;
    cout << "pozitiile celor doua puncte sunt:" << endl;
    cout << "punctul 1 are x=" << pozitie[LeBaguette][0] << " si y=" << pozitie[LeBaguette][2] << endl;
    cout << "punctul 2 are x=" << pozitie[LeBaguette][1] << " si y=" << pozitie[LeBaguette][3] << endl<<endl;
   
}

int main()
{

    // n este numarul de puncte, X este scaderea dintre x a doua puncte, Y este scaderea a y din doua puncte, D^2=X^2+Y^2;
    int n;
    int punct[100][2];
    




    cout << "numarul de puncte dorit" << endl;
    cin >> n;

    citirepuncte(n, punct);
    calcululdistantelor(n, punct);

    

}
