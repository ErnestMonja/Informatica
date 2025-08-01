#include <iostream>
#include <iomanip>
using namespace std;

const int N = 5;

bool verificarVector(int vec[N])
{
    bool unImparMay0 = false;
    
    for(int i=0; i<N; i++)
    {
        if(vec[i]%2!=0 && vec[i]>=0)
        {
            unImparMay0 = true;
            break;
        }
    }
    return unImparMay0;
}

void llenarMatriz(int mat[N][N])
{
    int diagtest[N];
    
    for(int h=0; h<N; h++)
    {
        do
        {
            cin >> diagtest[h];
        }   while ((diagtest[h]<=-100)||(diagtest[h]%5!=0)); 
    }
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i==j)
            {
                mat[i][j] = diagtest[i];
            }
            else
            {
                mat[i][j] = 0;
            }
        }
    }
}

void extraerFila(int mat[N][N], int vec[N])
{
    int may = mat[0][0];
    int filmay = 0;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(mat[i][j]>may)
            {
                may = mat[i][j];
                filmay = i;
            }
        }
    }
    
    for(int h=0; h<N; h++)
    {
        vec[h] = mat[filmay][h];
    }
}

void mostrarMatriz(int mat[N][N], char marca)
{
    for(int i=0; i<N; i++)
    {
        cout << marca;
        for(int j=0; j<N; j++)
        {
            cout << setw(5) << mat[i][j] ;  
        }
        cout << marca << endl;
    }
}

void NuevaMatriz(int mat[N][N], int nueva[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i==j)
            {
                nueva[i][j] = mat[i][j];
            }
            else if(i<j)
            {
                nueva[i][j] = (nueva[i][j-1])+1;
            }
        }
    }
}

int main()
{
    //Punto 1
    int M[N][N]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int NUEVA[N][N]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int V[N]={0,0,0,0,0};
    bool estado;
    char car;

    //Punto 2
    llenarMatriz(M);

    //Punto 3
    NuevaMatriz(M,NUEVA);

    //Punto 4
    extraerFila(NUEVA, V);
 
    //Punto 5
    estado = verificarVector(V);

    //Punto 6
    cout << "Ingrese un caracter: " << endl;
    cin >> car;

    //Punto 7
    cout << "Matriz diagonal" << endl;
    cout << endl;
    mostrarMatriz(M, car);
    
    cout << "Matriz triangular " << endl;
    cout << endl;
    mostrarMatriz(NUEVA, car);

    //Punto 8
    if(estado==true)
    {
        for(int i=0; i<N; i++)
        {
            cout << V[i] << endl;
        }
    }
    else
    {
        for(int r=0; r<N; r++)
        {
            cout << V[r] << " ";
        }
    }
}