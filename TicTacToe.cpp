#include <iostream>
#include <cstdlib>
using namespace std;

int skorP1=0, skorP2=0, skorKom=0;
string namaP1="", namaP2="";
char papan[25];
char player = 'X';

int pilKom(int tingkat){
    int pilihan;
    do{
        if(tingkat == 3){
            pilihan = rand()%9;
        } else if(tingkat == 4){
            pilihan = rand()%16;
        } else{
            pilihan = rand()%25;
        }
    } while(papan[pilihan] == 'X' || papan[pilihan] == 'O');
    return pilihan+1;
}

void ulangPapan(){
    for(int i = 0; i < 25; ++i){
        papan[i] = ' ';
    }
}

int tingkatPermainan(){
    system("cls");
    int tingkat;
    cout << "\n================Tingkatan Permainan===============" << endl;
    cout << "[3] 3x3\n[4] 4x4\n[5] 5x5" << endl;
    cout << "Silahkan pilih tingkatan permainan(3/4/5) : "; 
    cin >> tingkat;

    if (tingkat == 3 || tingkat == 4 || tingkat == 5){
        return tingkat;
    } else {
        cout << "Maaf, input salah. Silahkan ulangi." << endl;
        return tingkatPermainan();
    }
}

void cetakPapan(int tingkat){
    if(tingkat == 3){
        for(int i = 0; i < 3; ++i){
            cout << "     |     |     " << endl;
            for(int j = 0; j < 3; ++j){
                if(j != 2){
                    cout << "  " << papan[(i * 3) + j] << "  |";
                } else{
                    cout << "  " << papan[(i * 3) + j] << "  " << endl;
                }
            } if(i != 2){
                cout << "_____|_____|_____" << endl;
            } else{
                cout << "     |     |     " << endl;
            }
        }
    } else if(tingkat == 4){
        for(int i = 0; i < 4; ++i){
            cout << "       |       |       |       " << endl;
            for(int j = 0; j < 4; ++j){
                if(j != 3){
                    cout << "   " << papan[(i * 4) + j] << "   |";
                } else{
                    cout << "   " << papan[(i * 4) + j] << "   " << endl;
                }
            } if(i != 3){
                cout << "_______|_______|_______|_______" << endl;
            } else{
                cout << "       |       |       |       " << endl;
            }
        }
    } else if(tingkat == 5){
        for(int i = 0; i < 5; ++i){
            cout << "         |         |         |         |         " << endl;
            for(int j = 0; j < 5; ++j){
                if(j != 4){
                    cout << "    " << papan[(i * 5) + j] << "    |";
                } else{
                    cout << "    " << papan[(i * 5) + j] << "    " << endl;
                }
            } if(i != 4){
                cout << "_________|_________|_________|_________|_________" << endl;
            } else{
                cout << "         |         |         |         |         " << endl;
            }
        }
    }
}

void aturNama(int mode){
    system("cls");
    if(mode == 1){
        cout << "\n==============Mode Pemain VS Komputer=============" << endl;
        cout << "Masukkan nama pemain : ";
        cin >> namaP1;
    } else if(mode==2){
        cout << "\n=============Mode Pemain 1 VS Pemain 2============" << endl;
        cout << "Masukkan nama pemain 1 : ";
        cin >> namaP1;
        cout << "Masukkan nama pemain 2 : ";
        cin >> namaP2;
    }
}

void input(int tingkat, int mode){
    int a;
    string salah = "Kotak sudah digunakan, pilih yang lain";

    if(mode == 1 && player == 'O'){
        a = pilKom(tingkat);
        cout << "Giliran " << ((player == 'X') ? namaP1 : "Komputer") << " (" << player << "), memilih kotak " << a << endl;
    } else{
        cout << "Giliran " << ((player == 'X') ? namaP1 : namaP2) << " (" << player << "), masukkan pilihan nomor kotak : "; 
        cin >> a;
    }

    if(a < 1 || a > 25){
        cout << "Input diluar rentang yang valid." << endl;
        input(tingkat, mode);
        return;
    }
    if(papan[a - 1] == 'X' || papan[a - 1] == 'O'){
        cout << salah << endl;
        input(tingkat, mode);
        return;
    }
    papan[a - 1] = player;
}

void gantiPemain(){
    if(player == 'X'){
        player = 'O';
    } else{
        player = 'X';
    }
}

void skorInGame(int mode){
    if(mode == 1){
        cout << "\nSkor Saat Ini : " << endl;
        cout << "--Skor " << namaP1 << " : " << skorP1 << endl;
        cout << "--Skor Komputer : " << skorKom << endl;
    } else if(mode == 2){
        cout << "\nSkor Saat Ini : " << endl;
        cout << "--Skor " << namaP1 << " : " << skorP1 << endl;
        cout << "--Skor " << namaP2 << " : " << skorP2 << endl;
    }
    
}

char menang(int tingkat){
    if(tingkat == 3){
        char p = '/';
        for(int i = 0; i < 9; i += 3){
            // Cek baris
            if (papan[i] == papan[i + 1] && papan[i + 1] == papan[i + 2])
                return papan[i];
        }
        for(int i = 0; i < 3; ++i){
            // Cek kolom
            if (papan[i] == papan[i + 3] && papan[i + 3] == papan[i + 6])
                return papan[i];
        }
        // Cek diagonal
        if ((papan[0] == papan[4] && papan[4] == papan[8]) ||
            (papan[2] == papan[4] && papan[4] == papan[6]))
            return papan[4];
        return p;
    } else if(tingkat == 4){
        char p = '/';
        for(int i = 0; i < 16; i += 4){
            // Cek baris
            if (papan[i] == papan[i + 1] && papan[i + 1] == papan[i + 2] && papan[i + 2] == papan[i + 3])
                return papan[i];
        }
        for(int i = 0; i < 4; ++i){
            // Cek kolom
            if (papan[i] == papan[i + 4] && papan[i + 4] == papan[i + 8] && papan[i + 8] == papan[i + 12])
                return papan[i];
        }
        // Cek diagonal
        if ((papan[0] == papan[5] && papan[5] == papan[10] && papan[10] == papan[15]) ||
            (papan[3] == papan[6] && papan[6] == papan[9] && papan[9] == papan[12]))
            return papan[5];
        return p;

    } else if(tingkat == 5){
        char p = '/';
        for(int i = 0; i < 25; i += 5){
            // Cek baris
            if (papan[i] == papan[i + 1] && papan[i + 1] == papan[i + 2] && papan[i + 2] == papan[i + 3] && papan[i + 3] == papan[i + 4])
                return papan[i];
        }
        for(int i = 0; i < 5; ++i){
            // Cek kolom
            if (papan[i] == papan[i + 5] && papan[i + 5] == papan[i + 10] && papan[i + 10] == papan[i + 15] && papan[i + 15] == papan[i + 20])
                return papan[i];
        }
        // Cek diagonal
        if ((papan[0] == papan[6] && papan[6] == papan[12] && papan[12] == papan[18] && papan[18] == papan[24]) ||
            (papan[4] == papan[8] && papan[8] == papan[12] && papan[12] == papan[16] && papan[16] == papan[20]))
            return papan[12];
        return p;
    } else{
        return '/';
    }
}

void cekSkor(){
    system ("cls");
    char kembali;
    do{
        cout << "\n=====================Menu Skor====================" << endl;
        string pemain1 = namaP1 + " (Pemain 1)";
        string pemain2 = namaP2 + " (Pemain 2)";
        string komputer = "Komputer";

        int skorP1Temp = skorP1;
        int skorP2Temp = skorP2;
        int skorKomputerTemp = skorKom;

        if (skorP1Temp < skorP2Temp){
            swap(skorP1Temp, skorP2Temp);
            swap(pemain1, pemain2);
        }
        if (skorP1Temp < skorKomputerTemp){
            swap(skorP1Temp, skorKomputerTemp);
            swap(pemain1, komputer);
        }
        if (skorP2Temp < skorKomputerTemp){
            swap(skorP2Temp, skorKomputerTemp);
            swap(pemain2, komputer);
        }
    
        cout << "Skor Saat Ini (Diurutkan berdasarkan skor tertinggi):" << endl;
        cout << "1. " << pemain1 << " : " << skorP1Temp << endl;
        cout << "2. " << pemain2 << " : " << skorP2Temp << endl;
        cout << "3. " << komputer << " : " << skorKomputerTemp << endl;

        cout << "Ketik 'y' untuk kembali : \n";
        cin >> kembali;
        system("cls");

        if(kembali == 'y' || kembali == 'Y'){
            break;
        }
    } while(true);
}

void resetSkor(){
    system ("cls");
    cout << "\n==================Menu Reset Skor=================" << endl;
    char reset;
    cout << "Apakah anda yakin ingin mereset skor? (y/n)";
    cin >> reset;
    system("cls");

    if(reset == 'y'|| reset == 'Y'){
        skorP1 = 0;
        skorP2 = 0;
        skorKom = 0;

        cout << "Skor telah direset.\n" << endl;
    } else{
        cout << "Skor batal direset.\n" << endl;
    }
}

int main(){
    system("cls");
    int menu;
    cout << "====================KELOMPOK 2====================" << endl;
    cout << "\nNama : \t-Gathan Rafii Manaf\t\t(NIM = 3337220117)" << endl;
    cout << "\t-Andiko Ramadani\t\t(NIM : 3337230003)\n\t-Fadly Difak Al Fatah\t\t(NIM = 3337230004)" << endl;
    cout << "\t-Royhan Muhammad Al Biruni\t(NIM = 3337230021)\n\t-Ananta Pramudya Alfaritz\t(NIM : 3337230035)" << endl;
    cout << "\t-Ariqoh Nur Azza \t\t(NIM = 3337230096)\n\nProdi : Informatika (C)\nMata Kuliah : Dasar-dasar Pemrograman\n" << endl;
    
    do{
        cout << "====================TIC TAC TOE====================" << endl;
        cout << "Selamat Datang di Game Tic Tac Toe\nDaftar Menu : " << endl;
        cout << "[1] Mulai Permainan" << endl;
        cout << "[2] Lihat Skor" << endl;
        cout << "[3] Reset Skor" << endl;
        cout << "[4] Keluar Program" << endl;
        cout << "Silahkan Pilih Menu (1/2/3/4/5) : "; 
        cin >> menu;

        if(menu == 1){
            system("cls");
            int mode;
            char lagi;
            do{
                cout << "\n===============Daftar Mode Permainan==============" << endl;
                cout << "Daftar Mode Permainan : " << endl;
                cout << "1. Pemain 1 vs Komputer" << endl;
                cout << "2. Pemain 1 vs Pemain 2" << endl;
                cout << "3. Kembali ke Menu Utama" << endl;
                cout << "Masukkan pilihan (1/2/3) : "; 
                cin >> mode;
            
                if(mode == 1){
                    system("cls");
                    int n=0;
                    aturNama(mode);
                    int tingkat = tingkatPermainan();
                    ulangPapan();
                    while(1){
                        system("cls");
                        n++;
                        cetakPapan(tingkat);
                        input(tingkat, mode);
                        if(menang(tingkat) == 'X'){
                            cout << namaP1 << "(X) menang" << endl;
                            skorP1++;
                            break;;
                        } else if(menang(tingkat) == 'O'){
                            cout << "Komputer(O) menang" << endl;
                            skorKom++;
                            break;;
                        } else if(menang(tingkat) == '/' && n == tingkat*tingkat){
                            cout << "Hasil Seri" << endl;
                            break;;
                        } gantiPemain();
                    } 
                    cetakPapan(tingkat);
                    skorInGame(mode);
                    cout << "Ingin bermain lagi? (y/n) : ";
                    cin >> lagi;
                    system("cls");
                    if(lagi == 'n' || lagi == 'N'){
                        break;
                    }
                } else if(mode == 2){
                    system("cls");
                    int n=0;
                    aturNama(mode);
                    int tingkat = tingkatPermainan();
                    ulangPapan();
                    while(1){
                        system("cls");
                        n++;
                        cetakPapan(tingkat);
                        input(tingkat, mode);
                        if(menang(tingkat) == 'X'){
                            cout << "Player X menang" << endl;
                            skorP1++;
                            break;
                        } else if(menang(tingkat) == 'O'){
                            cout << "Player O menang" << endl;
                            skorP2++;
                            break;
                        } else if(menang(tingkat) == '/' && n == tingkat*tingkat){
                            cout << "Hasil Seri" << endl;
                            break;
                        } gantiPemain();
                    } 
                    cetakPapan(tingkat);
                    skorInGame(mode);
                    cout << "Ingin bermain lagi? (y/n) : ";
                    cin >> lagi;
                    system("cls");
                    if(lagi == 'n' || lagi == 'N'){
                        break;
                    }
                } else if(mode == 3){
                    break;
                } else{
                    cout << "Mode yang anda pilih tidak valid." << endl;
                }
            } while(mode!=3);
        } else if(menu == 2){
            cekSkor();
        } else if(menu == 3){
            resetSkor();
        } else if(menu == 4){
            cout << "\nPermainan selesai, program telah diakhiri" << endl;
            return 0;
        } else{
            cout << "Menu yang anda pilih tidak valid." << endl;
        }
    } while(menu!=5);
}
