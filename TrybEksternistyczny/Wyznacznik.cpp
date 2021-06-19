#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

long long int Determinant ( long long int tab[][32], int tab_size){

    if (tab_size==1){
        return (tab[0][0]);
    }
    else if(tab_size==2){
        return ((tab[0][0]*tab[1][1])-(tab[0][1]*tab[1][0]));
    }
    else{

        int negative=-1;
        long long int component=0;

        for(int i=0; i< tab_size; i++){

            long long int tab_small[tab_size][32];

            if(tab[0][i]!=0){
                for (int a=1; a<tab_size; a++){
                    //if(a==i) continue;
                    int check=0;

                    for (int b=0; b<tab_size; b++){

                        if(i==b){
                            check=1;
                        }
                        else{
                            tab_small[a-1][b-check]=tab[a][b];
                        }
                    }
                }
                if((i%2==0)){
                    component+=Determinant(tab_small, tab_size-1)*tab[0][i];
                }
                else{
                    component+=Determinant(tab_small, tab_size-1)*tab[0][i]*negative;
                }
            }
        }
        return component;
    }
}


int main (){

    int length=3;
    int matrix[length][32]={{3,2,1,6,7},
                        {2,3,2,2,2},
                        {3,4,2,7,3},
                        {2,3,2,2,2},
                        {2,3,2,2,2}};
    cout<< Determinant(matrix, length)<< endl;

return 0;
}
