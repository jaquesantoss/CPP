#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    cout << "***************************************" << endl;
    cout <<"* BEM-VINDOS AO JOGO DA ADVINHACAO *" << endl;
    cout <<"***************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade" << endl;
    cout << "Facil (F), Medio (M) e Dificil (D)" <<endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_tentativas;

    if (dificuldade == 'F'){
        numero_tentativas = 15;
    } else if (dificuldade == 'M'){
        numero_tentativas = 10;
    } else {
        numero_tentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    int chances = 0;
    bool naoacertou = true;
    double pontos = 1000.0;

    for(chances = 1; chances <= numero_tentativas; chances ++){
        int tentativa;
        cout << "Tentativa " << chances << endl;
        cout << "Qual sua tentativa?";
        cin >> tentativa;
        cout << "O valor da sua tentativa eh:" << tentativa << endl;

        bool acertou = tentativa == NUMERO_SECRETO;
        bool maior = tentativa >= NUMERO_SECRETO;

        double pontos_perdidos = abs(tentativa - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;

        if (acertou){
            cout << "Parabens, vc acertou!" << endl;
            naoacertou = false;
            break;
        }
        else if (maior){
            cout << "Numero acima!" << endl;
        }
        else {
            cout<< "Numero abaixo!" << endl;
        } 
    }
    cout << "Fim de jogo!" << endl;

    if(naoacertou){
        cout << "Voce perdeu! Tente novamente!" << endl;
    } else {
    cout << "Vc acertou o numero secreto em " << chances << " tentativas" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuacao foi de " << pontos << " pontos" <<endl;
    }
}


