

#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>
#include<ctime>



using namespace std;

int monopoli[40][2];
char player1[50],player2[50];
int X,Y;

int Player1_Pos = 1;
int Player2_Pos = 1;

void init(){
    int i,j;
    for(i = 0; i< 40; i++)
        for(j = 0; j < 40; j++)
        monopoli[i][j] = 0;
}

string P(int i, int j){
    if(j == 0)
        if(monopoli[i][j] == 1)
            return "X";
        else
            return " ";
    else if(j == 1)
        if(monopoli[i][j] == 1)
            return "Y";
        else
            return " ";
    else
        return " ";
}



struct Nod
{
    int pozitie;
    Nod *next,*befor;
};


typedef struct DLCircularList
{
    struct Nod* first, *last;


} DLCircularList;


void inserareInceputulListei(DLCircularList *l, int val)
{
    Nod *tmp;
    tmp=(Nod*)malloc(sizeof(Nod));
    tmp->pozitie=val;
    if(l->first != NULL){
        tmp->next = l->first->next;
        tmp->befor = l->first->befor;
    }else{
        l->first = tmp;
        l->last = tmp;
    }

    l->first->next = l->last;
    l->first->befor = tmp;
    l->first=tmp;


}

void AfisareLista(DLCircularList l)
{
    Nod*temp=l.first;

    cout<<temp->pozitie<<endl;
    temp=temp->next;

    while(temp!=l.first)//cat timp temp nu este Null sau cat timp nu ajunge la sf listei
    {
        cout<<temp->pozitie<<endl;
        temp=temp->next;
    }
}

void inserareSfarsitulListei(DLCircularList *l, int val)
{
    Nod *sfarsit=new Nod;
    sfarsit->pozitie=val;

    if(l->first==NULL)
        inserareInceputulListei(l, val);
    else{
        sfarsit->next=l->first;
        sfarsit->befor=l->last;
        l->last->next = sfarsit;
        l->last = sfarsit;
    }

}

Nod* CautarePozitie(DLCircularList l ,int pozitie)
{

    Nod *temp = l.first;
    while(temp->pozitie != pozitie){
        temp = temp->next;
        if(temp == l.first)
            return NULL;
    }
    return temp;
}


DLCircularList *initList(){
    DLCircularList *l = new DLCircularList;
    l->first = NULL;
    l->last = NULL;
}


void Afisare(){
    cout <<"  ----------------------------------------------------------------------------" << endl;
    cout <<"  ||||||  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |  11 ||||||"<< endl;
    cout <<"  |---------------------------------------------------------------------------|"<< endl;
    cout <<"  | 1  | " << P(1, 0) << " " << P(1,1) <<  " | " << P(2, 0) << " " << P(2,1) <<  " | " << P(3, 0) << " " << P(3,1) <<  " | " << P(4, 0) << " " << P(4,1) <<  " | " << P(5, 0) << " " << P(5,1) <<  " | " << P(6, 0) << " " << P(6,1) <<  " | " << P(7, 0) << " " << P(7,1) <<  " | " << P(8, 0) << " " << P(8,1) <<  " | " << P(9, 0) << " " << P(9,1) <<  " | " << P(10, 0) << " " << P(10,1) <<  " | " << P(11, 0) << " " << P(11,1) <<  " | 11 |"<< endl;
    cout <<"  |----------------------------------------------------------------------|----|"<< endl;
    cout <<"  | 40 | " << P(40, 0) << " " << P(40,1) <<  " |     __________                                      | " << P(12, 0) << " " << P(12,1) <<  " | 12 |"<< endl;
    cout <<"  |----|-----|    | Carti de |                                     |-----|----|"<< endl;
    cout <<"  | 39 | " << P(39, 0) << "  " << P(39,1) <<  "|    |  noroc   |                                     | " << P(13, 0) << " " << P(13,1) <<  " | 13 |"<< endl;
    cout <<"  |----|-----|    |__________|                                     |-----|----|"<< endl;
    cout <<"  | 38 | " << P(38, 0) << " " << P(38,1) <<  " |                                                     | " << P(14, 0) << " " << P(14,1) <<  " | 14 |"<< endl;
    cout <<"  |----|-----|                                                     |-----|----|"<< endl;
    cout <<"  | 37 | " << P(37, 0) << " " << P(37,1) <<  " |                                                     | " << P(15, 0) << " " << P(15,1) <<  " | 15 |"<< endl;
    cout <<"  |----|-----|                      MONOPOLY                       |-----|----|"<< endl;
    cout <<"  | 36 | " << P(36, 0) << " " << P(36,1) <<  " |                                                     | " << P(16, 0) << " " << P(16,1) <<  " | 16 |"<< endl;
    cout <<"  |----|-----|                                                     |-----|----|"<< endl;
    cout <<"  | 35 | " << P(35, 0) << " " << P(35,1) <<  " |                                                     | " << P(17, 0) << " " << P(17,1) <<  " | 17 |"<< endl;
    cout <<"  |----|-----|                                                     |-----|----|"<< endl;
    cout <<"  | 34 | " << P(34, 0) << " " << P(34,1) <<  " |                                      __________     | " << P(18, 0) << " " << P(18,1) <<  " | 18 |"<< endl;
    cout <<"  |----|-----|                                     | Carti ale|    |-----|----|"<< endl;
    cout <<"  | 33 | " << P(33, 0) << " " << P(33,1) <<  " |                                     |counitati |    | " << P(19, 0) << " " << P(19,1) <<  " | 19 |"<< endl;
    cout <<"  |----|-----|                                     |__________|    |-----|----|"<< endl;
    cout <<"  | 32 | " << P(32, 0) << " " << P(32,1) <<  " |                                                     | " << P(20, 0) << " " << P(20,1) <<  " | 20 |"<< endl;
    cout <<"  |----------------------------------------------------------------------|----|"<< endl;
    cout <<"  | 31 | " << P(31, 0) << " " << P(31,1) <<  " | " << P(30, 0) << " " << P(30,1) <<  " | " << P(29, 0) << " " << P(29,1) <<  " | " << P(28, 0) << " " << P(28,1) <<  " | " << P(27, 0) << " " << P(27,1) <<  " | " << P(26, 0) << " " << P(26,1) <<  " | " << P(25, 0) << " " << P(25,1) <<  " | " << P(24, 0) << " " << P(24,1) <<  " | " << P(23, 0) << " " << P(23,1) <<  " | " << P(22, 0) << " " << P(22,1) <<  " | " << P(21, 0) << " " << P(21,1) <<  " | 21 |"<< endl;
    cout <<"  |---------------------------------------------------------------------------|"<< endl;
    cout <<"  |||||| 31  | 30  | 29  | 28  | 27  | 26  | 25  | 24  | 23  | 22  |  21 ||||||"<< endl;
    cout <<"  -----------------------------------------------------------------------------"<<endl;
}

int random_nr(){

    int x,y,k;
    cout<<"Dati cu zarul pentru a muta pionul"<<"\n";

//    srand(time(0));
    for(int i = 0; i < 1; i++){
        int count = 0;
        x=1+(rand() % 6);
        y=1+(rand() % 6);
        cout << " Ai dat: " << x <<" si"<< " " << y <<"\t";
       while(x == y && count < 3)
       {
           cout<<"\nMai dai o data:"<<endl;
           count++;
            x=1+(rand() % 6);
            y=1+(rand() % 6);
           cout << " Ai dat: " << x <<" si"<< " " << y << "\t" ;
       }
       cout << endl;
    }
   if(k==12)
    {
        cout<<"Ai dat:";
       cout<<(rand()%12)<<endl;
    }

   return x+y;
}

int main(){
    init();
    DLCircularList lc0;

    srand (time(NULL));

    int x,y,k;

    cout<<"Dati numele primului player1: ";
    std::cin>>player1;
    cout<<"Dati numele player2: ";
    std::cin>>player2;

    monopoli[Player1_Pos][0] = 1;
    monopoli[Player2_Pos][1] = 1;

    char work = 'O';
    int player1_zar = 0;
    int player2_zar = 0;
    int finish = 0;


    while(work == 'O' || work == 'o'){
        system("cls");
        cout << " " << player1<<"  este cu X"<<endl;
        cout << " " << player2<<"  este cu Y"<<endl;

        Afisare();



        player1_zar = random_nr();
        cout << " " << player1<<" muta "<< player1_zar <<" casute"<< endl;

        player2_zar = random_nr();
        cout << " " << player2 <<" muta "<< player2_zar <<" casute" << endl;

        monopoli[Player1_Pos][0] = 0;
        monopoli[Player2_Pos][1] = 0;

        Player1_Pos = (Player1_Pos + player1_zar)%40;
        if (Player1_Pos == 0)
            Player1_Pos =40;


        Player2_Pos = (Player2_Pos + player2_zar)%40;
        if (Player2_Pos == 0)
            Player2_Pos =40;

        if(Player1_Pos >= 40){
            Player1_Pos = 40;
            finish = 1;
        }
        if(Player2_Pos >= 40){
            Player2_Pos = 40;
            finish = 2;
        }
        if(Player1_Pos >= 40 && Player2_Pos >= 40){
            Player1_Pos = 40;
            Player2_Pos = 40;
            finish = 3;

        }

        monopoli[Player1_Pos][0] = 1;
        monopoli[Player2_Pos][1] = 1;
        if(finish == 0){
            do{
                cout << "Press 'O' for continue or 'X' for exit: ";
                cin >> work;
            }while(work != 'O' && work != 'X' && work != 'o' && work != 'x');
        }else{
            work = 'x';
        }
    }


   return 0;

}


