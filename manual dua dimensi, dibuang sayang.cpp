#include <iostream>
using namespace std;

int skorP1=0, skorP2=0, skorKom=0, n=0;
string namaP1="", namaP2="";
char papan[5][5] = {'1','2','3','4','5',
                    '6','7','8','9','A',
                    'B','C','D','E','F',
                    'G','H','I','J','K',
                    'L','M','N','O','P'};
char player = 'X';

void ulangPapan() {
    char huruf = '1';
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            papan[i][j] = huruf++;
        }
    }
}
int tingkatPermainan(){
    //system("cls");
    int tingkat;
    cout << "\n================Tingkatan Permainan===============" << endl;
    cout << "[1] 3x3\n[2] 4x4\n[3] 5x5" << endl;
    cout << "Silahkan pilih tingkatan permainan(1/2/3) : "; 
    cin >> tingkat;

    if (tingkat == 1 || tingkat == 2 || tingkat == 3) {
        return tingkat;
    }
    else {
        cout << "Maaf, input salah. Silahkan ulangi." << endl;
        return tingkatPermainan();
    }
}

void cetakPapan(int tingkat){
    if(tingkat==1){
        cout << "     |     |     " << endl;
        cout << "  " << papan[0][0] << "  |  " << papan[0][1] << "  |  " << papan[0][2] << endl;

        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;

        cout << "  " << papan[0][3] << "  |  " << papan[0][4] << "  |  " << papan[1][0] << endl;
        cout << "_____|_____|_____" << endl;    
        cout << "     |     |     " << endl;
        cout << "  " << papan[1][1] << "  |  " << papan[1][2] << "  |  " << papan[1][3] << endl;
        cout << "     |     |     " << endl;
    } else if(tingkat==2){
        cout << "       |       |       |" << endl;
        cout << "   " << papan[0][0] << "   |   " << papan[0][1] << "   |   " << papan[0][2] << "   |   " << papan[0][3] << endl;
        cout << "_______|_______|_______|_______" << endl;
        cout << "       |       |       |       " << endl;
        cout << "   " << papan[0][4] << "   |   " << papan[1][0] << "   |   " << papan[1][1] << "   |   " << papan[1][2] << endl;
        cout << "_______|_______|_______|_______" << endl;
        cout << "       |       |       |       " << endl;
        cout << "   " << papan[1][3] << "   |   " << papan[1][4] << "   |   " << papan[2][0] << "   |   " << papan[2][1] << endl;
        cout << "_______|_______|_______|_______" << endl;
        cout << "       |       |       |       " << endl;
        cout << "   " << papan[2][2] << "   |   " << papan[2][3] << "   |   " << papan[2][4] << "   |   " << papan[3][1] << endl;
        cout << "       |       |       |       " << endl;
    } else if(tingkat==3){
        cout << "         |         |         |         |         " << endl;
        cout << "    " << papan[0][0] << "    |    " << papan[0][1] << "    |    " << papan[0][2] << "    |    " << papan[0][3] << "    |    " << papan[0][4] << endl;
        cout << "_________|_________|_________|_________|_________" << endl;
        cout << "         |         |         |         |         " << endl;
        cout << "    " << papan[1][0] << "    |    " << papan[1][1] << "    |    " << papan[1][2] << "    |    " << papan[1][3] << "    |    " << papan[1][4] << endl;
        cout << "_________|_________|_________|_________|_________" << endl;
        cout << "         |         |         |         |         " << endl;
        cout << "    " << papan[2][0] << "    |    " << papan[2][1] << "    |    " << papan[2][2] << "    |    " << papan[2][3] << "    |    " << papan[2][4] << endl;
        cout << "_________|_________|_________|_________|_________" << endl;
        cout << "         |         |         |         |         " << endl;
        cout << "    " << papan[3][0] << "    |    " << papan[3][1] << "    |    " << papan[3][2] << "    |    " << papan[3][3] << "    |    " << papan[3][4] << endl;
        cout << "_________|_________|_________|_________|_________" << endl;
        cout << "         |         |         |         |         " << endl;
        cout << "    " << papan[4][0] << "    |    " << papan[4][1] << "    |    " << papan[4][2] << "    |    " << papan[4][3] << "    |    " << papan[4][4] << endl;
        cout << "         |         |         |         |         " << endl;
    }
}

void aturNama(int mode){
    if(mode==1){
        cout << "\n==============Mode Pemain VS Komputer=============" << endl;
        cout << "Masukkan nama pemain: ";
        cin >> namaP1;
    } else if(mode==2){
        cout << "\n=============Mode Pemain 1 VS Pemain 2============" << endl;
        cout << "Masukkan nama pemain 1: ";
        cin >> namaP1;
        cout << "Masukkan nama pemain 2: ";
        cin >> namaP2;
    }
}

void input(int tingkat){
    int a;
    string salah = "Kotak sudah digunakan, pilih yang lain";
    cout << "giliran " << player << ", " << "masukkan pilihan nomor kotak : "; cin >> a;

    /*if (a < 1 || a > 25) {
        cout << "Input diluar rentang yang valid." << endl;
        input(tingkat);
        return;
    } */

    if(tingkat==1){
        if(a==1){
            if(papan[0][0] == '1'){
                papan[0][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==2){
            if(papan[0][1] == '2'){
                papan[0][1] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==3){
            if(papan[0][2] == '3'){
                papan[0][2] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==4){
            if(papan[0][3] == '4'){
                papan[0][3] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==5){
            if(papan[0][4] == '5'){
                papan[0][4] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==6){
            if(papan[1][0] == '6'){
                papan[1][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==7){
            if(papan[1][1] == '7'){
                papan[1][1] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==8){
            if(papan[1][2] == '8'){
                papan[1][2] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==9){
            if(papan[1][3] == '9'){
                papan[1][3] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        }
    }
    
    if(tingkat==2){
        if(a==1){
            if(papan[0][0] == '1'){
                papan[0][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==2){
            if(papan[0][1] == '2'){
                papan[0][1] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==3){
            if(papan[0][2] == '3'){
                papan[0][2] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==4){
            if(papan[0][3] == '4'){
                papan[0][3] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==5){
            if(papan[0][4] == '5'){
                papan[0][4] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==6){
            if(papan[1][0] == '6'){
                papan[1][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==7){
            if(papan[1][1] == '7'){
                papan[1][1] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==8){
            if(papan[1][2] == '8'){
                papan[1][2] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==9){
            if(papan[1][3] == '9'){
                papan[1][3] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='A'){
            if(papan[1][4] == 'A'){
                papan[1][4] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='B'){
            if(papan[2][0] == 'B'){
                papan[2][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='C'){
            if(papan[2][1] == 'C'){
                papan[2][1] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='D'){
            if(papan[2][2] == 'D'){
                papan[2][2] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='E'){
            if(papan[2][3] == 'E'){
                papan[2][3] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='F'){
            if(papan[2][4] == 'F'){
                papan[2][4] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='G'){
            if(papan[3][0] == 'G'){
                papan[3][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else{
                cout << salah << endl;
                input(tingkat);
            }
    } else if(tingkat==3){
        if(a==1){
            if(papan[0][0] == '1'){
                papan[0][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==2){
            if(papan[0][1] == '2'){
                papan[0][1] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==3){
            if(papan[0][2] == '3'){
                papan[0][2] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==4){
            if(papan[0][3] == '4'){
                papan[0][3] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==5){
            if(papan[0][4] == '5'){
                papan[0][4] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==6){
            if(papan[1][0] == '6'){
                papan[1][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==7){
            if(papan[1][1] == '7'){
                papan[1][1] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==8){
            if(papan[1][2] == '8'){
                papan[1][2] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a==9){
            if(papan[1][3] == '9'){
                papan[1][3] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='A'){
            if(papan[1][4] == 'A'){
                papan[1][4] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='B'){
            if(papan[2][0] == 'B'){
                papan[2][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='C'){
            if(papan[2][1] == 'C'){
                papan[2][1] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='D'){
            if(papan[2][2] == 'D'){
                papan[2][2] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='E'){
            if(papan[2][3] == 'E'){
                papan[2][3] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='F'){
            if(papan[2][4] == 'F'){
                papan[2][4] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='G'){
            if(papan[3][0] == 'G'){
                papan[3][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='H'){
            if(papan[3][1] == 'H'){
                papan[3][1] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='I'){
            if(papan[3][2] == 'I'){
                papan[3][2] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='J'){
            if(papan[3][3] == 'J'){
                papan[3][3] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='K'){
            if(papan[3][4] == 'K'){
                papan[3][4] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='L'){
            if(papan[4][0] == 'L'){
                papan[4][0] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='M'){
            if(papan[4][1] == 'M'){
                papan[4][1] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='N'){
            if(papan[4][2] == 'N'){
                papan[4][2] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='O'){
            if(papan[4][3] == 'O'){
                papan[4][3] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else if(a=='P'){
            if(papan[4][4] == 'P'){
                papan[4][4] = player;
            } else{
                cout << salah << endl;
                input(tingkat);
            }
        } else{
                cout << salah << endl;
                input(tingkat);
            }
    }
}


void gantiPemain(){
    if(player == 'X'){
        player = 'O';
    } else{
        player = 'X';
    }
}

void skorInGame(int mode){
    if(mode==1){
        cout << "\nSkor Saat Ini: " << endl;
        cout << "Skor " << namaP1 << ": " << skorP1 << endl;
        cout << "Skor Komputer: " << skorKom << endl;
    } else if(mode==2){
        cout << "\nSkor Saat Ini: " << endl;
        cout << "Skor " << namaP1 << ": " << skorP1 << endl;
        cout << "Skor " << namaP2 << ": " << skorP2 << endl;
    }
    
}

char menang(int tingkat){
    if(tingkat==1){
        if(papan[0][0] == 'X' && papan[0][1] == 'X' && papan[0][2] == 'X'){
            return 'X';
        } else if(papan[0][3] == 'X' && papan[0][4] == 'X' && papan[1][0] == 'X'){
            return 'X';
        } else if(papan[1][1] == 'X' && papan[1][2] == 'X' && papan[1][3] == 'X'){
            return 'X';
        } else if(papan[0][0] == 'X' && papan[0][3] == 'X' && papan[1][1] == 'X'){
            return 'X';
        } else if(papan[0][1] == 'X' && papan[0][4] == 'X' && papan[1][2] == 'X'){
            return 'X';
        } else if(papan[0][2] == 'X' && papan[1][0] == 'X' && papan[1][3] == 'X'){
            return 'X';
        } else if(papan[0][0] == 'X' && papan[0][4] == 'X' && papan[1][3] == 'X'){
            return 'X';
        } else if(papan[0][2] == 'X' && papan[0][4] == 'X' && papan[1][1] == 'X'){
            return 'X';
        }

        if(papan[0][0] == 'O' && papan[0][1] == 'O' && papan[0][2] == 'O'){
            return 'O';
        } else if(papan[0][3] == 'O' && papan[0][4] == 'O' && papan[1][0] == 'O'){
            return 'O';
        } else if(papan[1][1] == 'O' && papan[1][2] == 'O' && papan[1][3] == 'O'){
            return 'O';
        } else if(papan[0][0] == 'O' && papan[0][3] == 'O' && papan[1][1] == 'O'){
            return 'O';
        } else if(papan[0][1] == 'O' && papan[0][4] == 'O' && papan[1][2] == 'O'){
            return 'O';
        } else if(papan[0][2] == 'O' && papan[1][0] == 'O' && papan[1][3] == 'O'){
            return 'O';
        } else if(papan[0][0] == 'O' && papan[0][4] == 'O' && papan[1][3] == 'O'){
            return 'O';
        } else if(papan[0][2] == 'O' && papan[0][4] == 'O' && papan[1][1] == 'O'){
            return 'O';
        } else{
            return '/';
        } 
    } else if(tingkat==2){
        if(papan[0][0] == 'X' && papan[0][1] == 'X' && papan[0][2] == 'X' && papan[0][3] == 'X'){
            return 'X';
        } else if(papan[0][4] == 'X' && papan[1][0] == 'X' && papan[1][1] == 'X' && papan[1][2] == 'X'){
            return 'X';
        } else if(papan[1][3] == 'X' && papan[1][4] == 'X' && papan[2][0] == 'X' && papan[2][1] == 'X'){
            return 'X';
        } else if(papan[2][2] == 'X' && papan[2][3] == 'X' && papan[2][4] == 'X' && papan[3][0] == 'X'){
            return 'X';
        } else if(papan[0][0] == 'X' && papan[0][4] == 'X' && papan[1][3] == 'X' && papan[2][2] == 'X'){
            return 'X';
        } else if(papan[0][1] == 'X' && papan[1][0] == 'X' && papan[1][4] == 'X' && papan[2][3] == 'X'){
            return 'X';
        } else if(papan[0][2] == 'X' && papan[1][1] == 'X' && papan[2][0] == 'X' && papan[2][4] == 'X'){
            return 'X';
        } else if(papan[0][3] == 'X' && papan[1][2] == 'X' && papan[2][1] == 'X' && papan[3][0] == 'X'){
            return 'X';
        } else if(papan[0][0] == 'X' && papan[1][0] == 'X' && papan[2][0] == 'X' && papan[3][0] == 'X'){
            return 'X';
        } else if(papan[0][3] == 'X' && papan[1][1] == 'X' && papan[1][4] == 'X' && papan[2][2] == 'X'){
            return 'X';
        } 

        if(papan[0][0] == 'O' && papan[0][1] == 'O' && papan[0][2] == 'O' && papan[0][3] == 'O'){
            return 'O';
        } else if(papan[0][4] == 'O' && papan[1][0] == 'O' && papan[1][1] == 'O' && papan[1][2] == 'O'){
            return 'O';
        } else if(papan[1][3] == 'O' && papan[1][4] == 'O' && papan[2][0] == 'O' && papan[2][1] == 'O'){
            return 'O';
        } else if(papan[2][2] == 'O' && papan[2][3] == 'O' && papan[2][4] == 'O' && papan[3][0] == 'O'){
            return 'O';
        } else if(papan[0][0] == 'O' && papan[0][4] == 'O' && papan[1][3] == 'O' && papan[2][2] == 'O'){
            return 'O';
        } else if(papan[0][1] == 'O' && papan[1][0] == 'O' && papan[1][4] == 'O' && papan[2][3] == 'O'){
            return 'O';
        } else if(papan[0][2] == 'O' && papan[1][1] == 'O' && papan[2][0] == 'O' && papan[2][4] == 'O'){
            return 'O';
        } else if(papan[0][3] == 'O' && papan[1][2] == 'O' && papan[2][1] == 'O' && papan[3][0] == 'O'){
            return 'O';
        } else if(papan[0][0] == 'O' && papan[1][0] == 'O' && papan[2][0] == 'O' && papan[3][0] == 'O'){
            return 'O';
        } else if(papan[0][3] == 'O' && papan[1][1] == 'O' && papan[1][4] == 'O' && papan[2][2] == 'O'){
            return 'O';
        } else{
            return '/';
        } 

    } else if(tingkat==3){
        if(papan[0][0] == 'X' && papan[0][1] == 'X' && papan[0][2] == 'X' && papan[0][3] == 'X' && papan[0][4] == 'X'){
            return 'X';
        } else if(papan[1][0] == 'X' && papan[1][1] == 'X' && papan[1][2] == 'X' && papan[1][3] == 'X' && papan[1][4] == 'X'){
            return 'X';
        } else if(papan[2][0] == 'X' && papan[2][1] == 'X' && papan[2][2] == 'X' && papan[2][3] == 'X' && papan[2][4] == 'X'){
            return 'X';
        } else if(papan[3][0] == 'X' && papan[3][1] == 'X' && papan[3][2] == 'X' && papan[3][3] == 'X' && papan[3][4] == 'X'){
            return 'X';
        } else if(papan[4][0] == 'X' && papan[4][1] == 'X' && papan[4][2] == 'X' && papan[4][3] == 'X' && papan[4][4] == 'X'){
            return 'X';
        } else if(papan[0][0] == 'X' && papan[1][0] == 'X' && papan[2][0] == 'X' && papan[3][0] == 'X' && papan[4][0] == 'X'){
            return 'X';
        } else if(papan[0][1] == 'X' && papan[1][1] == 'X' && papan[2][1] == 'X' && papan[3][1] == 'X' && papan[4][1] == 'X'){
            return 'X';
        } else if(papan[0][2] == 'X' && papan[1][2] == 'X' && papan[2][2] == 'X' && papan[3][2] == 'X' && papan[4][2] == 'X'){
            return 'X';
        } else if(papan[0][3] == 'X' && papan[1][3] == 'X' && papan[2][3] == 'X' && papan[3][3] == 'X' && papan[4][3] == 'X'){
            return 'X';
        } else if(papan[0][4] == 'X' && papan[1][4] == 'X' && papan[2][4] == 'X' && papan[3][4] == 'X' && papan[4][4] == 'X'){
            return 'X';
        } else if(papan[0][0] == 'X' && papan[1][1] == 'X' && papan[2][2] == 'X' && papan[3][3] == 'X' && papan[4][4] == 'X'){
            return 'X';
        } else if(papan[0][4] == 'X' && papan[1][3] == 'X' && papan[2][2] == 'X' && papan[3][1] == 'X' && papan[4][0] == 'X'){
            return 'X';
        } 

        if(papan[0][0] == 'O' && papan[0][1] == 'O' && papan[0][2] == 'O' && papan[0][3] == 'O' && papan[0][4] == 'O'){
            return 'O';
        } else if(papan[1][0] == 'O' && papan[1][1] == 'O' && papan[1][2] == 'O' && papan[1][3] == 'O' && papan[1][4] == 'O'){
            return 'O';
        } else if(papan[2][0] == 'O' && papan[2][1] == 'O' && papan[2][2] == 'O' && papan[2][3] == 'O' && papan[2][4] == 'O'){
            return 'O';
        } else if(papan[3][0] == 'O' && papan[3][1] == 'O' && papan[3][2] == 'O' && papan[3][3] == 'O' && papan[3][4] == 'O'){
            return 'O';
        } else if(papan[4][0] == 'O' && papan[4][1] == 'O' && papan[4][2] == 'O' && papan[4][3] == 'O' && papan[4][4] == 'O'){
            return 'O';
        } else if(papan[0][0] == 'O' && papan[1][0] == 'O' && papan[2][0] == 'O' && papan[3][0] == 'O' && papan[4][0] == 'O'){
            return 'O';
        } else if(papan[0][1] == 'O' && papan[1][1] == 'O' && papan[2][1] == 'O' && papan[3][1] == 'O' && papan[4][1] == 'O'){
            return 'O';
        } else if(papan[0][2] == 'O' && papan[1][2] == 'O' && papan[2][2] == 'O' && papan[3][2] == 'O' && papan[4][2] == 'O'){
            return 'O';
        } else if(papan[0][3] == 'O' && papan[1][3] == 'O' && papan[2][3] == 'O' && papan[3][3] == 'O' && papan[4][3] == 'O'){
            return 'O';
        } else if(papan[0][4] == 'O' && papan[1][4] == 'O' && papan[2][4] == 'O' && papan[3][4] == 'O' && papan[4][4] == 'O'){
            return 'O';
        } else if(papan[0][0] == 'O' && papan[1][1] == 'O' && papan[2][2] == 'O' && papan[3][3] == 'O' && papan[4][4] == 'O'){
            return 'O';
        } else if(papan[0][4] == 'O' && papan[1][3] == 'O' && papan[2][2] == 'O' && papan[3][1] == 'O' && papan[4][0] == 'O'){
            return 'O';
        } else{
            return '/';
        } 
    } else{
        return '/';
    }
}

void cekSkor(){
    //system ("cls");
    char kembali;
    cout << "\n=====================Menu Skor====================" << endl;
    do{
        string pemain1 = namaP1 + " (Pemain 1)";
        string pemain2 = namaP2 + " (Pemain 2)";
        string komputer = "Komputer";

        int skorP1Temp = skorP1;
        int skorP2Temp = skorP2;
        int skorKomputerTemp = skorKom;

        if (skorP1Temp < skorP2Temp) {
            swap(skorP1Temp, skorP2Temp);
            swap(pemain1, pemain2);
        }
        if (skorP1Temp < skorKomputerTemp) {
            swap(skorP1Temp, skorKomputerTemp);
            swap(pemain1, komputer);
        }
        if (skorP2Temp < skorKomputerTemp) {
            swap(skorP2Temp, skorKomputerTemp);
            swap(pemain2, komputer);
        }
    
        cout << "Skor Saat Ini (Diurutkan berdasarkan skor tertinggi):" << endl;
        cout << "1. " << pemain1 << " : " << skorP1Temp << endl;
        cout << "2. " << pemain2 << " : " << skorP2Temp << endl;
        cout << "3. " << komputer << " : " << skorKomputerTemp << endl;

        cout << "Ketik 'y' untuk kembali: \n";
        cin >> kembali;

        if(kembali=='y' || kembali=='Y'){
            break;
        }
    }while(true);
}

void resetSkor(){
    //system ("cls");
    cout << "\n==================Menu Reset Skor=================" << endl;
    char reset;
    cout << "Apakah anda yakin ingin mereset skor? (y/n)";
    cin >> reset;

    if(reset == 'y'|| reset == 'Y'){
        skorP1 = 0;
        skorP2 = 0;
        skorKom = 0;

        cout << "Skor telah direset.\n" << endl;
    } 
    
    else{
        cout << "Skor batal direset.\n" << endl;
    }
}

int main(){
    //system("cls");
    int menu;
    cout << "\nKelompok 2\nNama : \t-Gathan Rafii Manaf\t\t(NIM = 3337220117)" << endl;
    cout << "\t-Andiko Ramadani\t\t(NIM : 3337230003)\n\t-Fadly Difak Al Fatah\t\t(NIM = 3337230004)" << endl;
    cout << "\t-Royhan Muhammad Al Biruni\t(NIM = 3337230021)\n\t-Ananta Pramudya Alfaritz\t(NIM : 3337230035)" << endl;
    cout << "\t-Ariqoh Nur Azza \t\t(NIM = 3337230096)\nProdi:  Informatika (C)\nMata Kuliah : Dasar-dasar Pemrograman" << endl;
    
    do{
        cout << "====================TIC TAC TOE====================" << endl;
        cout << "Selamat Datang di Game Tic Tac Toe\nDaftar Menu: " << endl;
        cout << "[1] Mulai Permainan" << endl;
        cout << "[2] Lihat Skor" << endl;
        cout << "[3] Reset Skor" << endl;
        cout << "[4] Keluar Program" << endl;
        cout << "Silahkan Pilih Menu : "; 
        cin >> menu;

        if(menu==1){
            //system("cls");
            int mode;
            do{
                cout << "\n===============Daftar Mode Permainan==============" << endl;
                cout << "Daftar Mode Permainan: " << endl;
                cout << "1. Pemain 1 vs Komputer" << endl;
                cout << "2. Pemain 1 vs Pemain 2" << endl;
                cout << "3. Kembali ke Menu Utama" << endl;
                cout << "Masukkan pilihan (1/2/3): "; 
                cin >> mode;
            
                if(mode==1){
                    aturNama(mode);
                    int tingkat = tingkatPermainan();
                    ulangPapan();
                    while(1){
                        n++;
                        cetakPapan(tingkat);
                        input(tingkat);
                        if(menang(tingkat) == 'X'){
                            cout << "Player X menang" << endl;
                            skorP1++;
                            skorInGame(mode);
                            break;
                        } else if(menang(tingkat) == 'O'){
                            cout << "Player O menang" << endl;
                            skorP2++;
                            skorInGame(mode);
                            break;
                        } else if(menang(tingkat) == '/' && n == 9){
                            cout << "Hasil Seri" << endl;
                            skorInGame(mode);
                            break;
                        }
                        gantiPemain();
                    }
                } else if(mode==2){
                    aturNama(mode);
                    int tingkat = tingkatPermainan();
                    ulangPapan();
                    while(1){
                        n++;
                        cetakPapan(tingkat);
                        input(tingkat);
                        if(menang(tingkat) == 'X'){
                            cout << "Player X menang" << endl;
                            skorP1++;
                            skorInGame(mode);
                            break;
                        } else if(menang(tingkat) == 'O'){
                            cout << "Player O menang" << endl;
                            skorP2++;
                            skorInGame(mode);
                            break;
                        } else if(menang(tingkat) == '/' && n == 9){
                            cout << "Hasil Seri" << endl;
                            skorInGame(mode);
                            break;
                        }
                        gantiPemain();
                    }
                } else if(mode==3){
                    break;
                } else{
                    cout << "Mode yang anda pilih tidak valid." << endl;
                }
            }while(mode!=3);
        } else if(menu==2){
            cekSkor();
        } else if(menu==3){
            resetSkor();
        } else if(menu==4){
            return 0;
        } else{
            cout << "Menu yang anda pilih tidak valid." << endl;
        }
    }while(menu!=5);
}
