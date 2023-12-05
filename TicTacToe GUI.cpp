#include <windows.h>
#include <iostream>

using namespace std;

char papan[]={'a','b','c','d','e','f','g','h','i'};
char simbol = 'X';
char pemenang = 'L';

#define tic1 1
#define tic2 2
#define tic3 3

#define tic4 4
#define tic5 5
#define tic6 6

#define tic7 7
#define tic8 8
#define tic9 9

HWND hwnd, t1,t2,t3,t4,t5,t6,t7,t8,t9;

LRESULT CALLBACK WindowBuilder(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst , LPSTR args, int ncmdshow){
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW ;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowBuilder;

    if(!RegisterClassW(&wc))
        return -1;
    
    CreateWindowW(L"myWindowClass",L"Tic-Tac-Toe",WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100,100, 520,540, NULL,NULL,NULL,NULL);

    MSG msg = {0};

    while( GetMessage(&msg,NULL,0,0) ){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WindowBuilder(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp){
    switch ( msg){
        case WM_DESTROY:
            PostQuitMessage(643);
            break;
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);

        case WM_CREATE:{
            t1 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 100,100, 100,100, hWnd,(HMENU) tic1,NULL,NULL);
            t2 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 200,100, 100,100, hWnd,(HMENU) tic2,NULL,NULL);
            t3 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 300,100, 100,100, hWnd,(HMENU) tic3,NULL,NULL);
            t4 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 100,200, 100,100, hWnd,(HMENU) tic4,NULL,NULL);
            t5 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 200,200, 100,100, hWnd,(HMENU) tic5,NULL,NULL);
            t6 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 300,200, 100,100, hWnd,(HMENU) tic6,NULL,NULL);
            t7 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 100,300, 100,100, hWnd,(HMENU) tic7,NULL,NULL);
            t8 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 200,300, 100,100, hWnd,(HMENU) tic8,NULL,NULL);
            t9 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 300,300, 100,100, hWnd,(HMENU) tic9,NULL,NULL);

            break;
        }

        case WM_COMMAND:{
            if(simbol == 'X'){
                if(LOWORD(wp) == tic1 && papan[0] != 'X' && papan[0] != '0'){
                    papan[0] = 'X';
                    simbol = '0';
                    DestroyWindow(t1);
                    t1 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 100,100, 100,100, hWnd,(HMENU) tic1,NULL,NULL);
                }
                else if(LOWORD(wp) == tic2 && papan[1] != 'X' && papan[1] != '0'){
                    papan[1] = 'X';
                    simbol = '0';
                    DestroyWindow(t2);
                    t2 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 200,100, 100,100, hWnd,(HMENU) tic2,NULL,NULL);
                }
                else if(LOWORD(wp) == tic3 && papan[2] != 'X' && papan[2] != '0'){
                    papan[2] = 'X';
                    simbol = '0';
                    DestroyWindow(t3);
                    t3 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 300,100, 100,100, hWnd,(HMENU) tic3,NULL,NULL);
                }
                else if(LOWORD(wp) == tic4 && papan[3] != 'X' && papan[3] != '0'){
                    papan[3] = 'X';
                    simbol = '0';
                    DestroyWindow(t4);
                    t4 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 100,200, 100,100, hWnd,(HMENU) tic4,NULL,NULL);
                }
                else if(LOWORD(wp) == tic5 && papan[4] != 'X' && papan[4] != '0'){
                    papan[4] = 'X';
                    simbol = '0';
                    DestroyWindow(t5);
                    t5 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 200,200, 100,100, hWnd,(HMENU) tic5,NULL,NULL);
                }
                else if(LOWORD(wp) == tic6 && papan[5] != 'X' && papan[5] != '0'){
                    papan[5] = 'X';
                    simbol = '0';
                    DestroyWindow(t6);
                    t6 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 300,200, 100,100, hWnd,(HMENU) tic6,NULL,NULL);
                }
                else if(LOWORD(wp) == tic7 && papan[6] != 'X' && papan[6] != '0'){
                    papan[6] = 'X';
                    simbol = '0';
                    DestroyWindow(t7);
                    t7 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 100,300, 100,100, hWnd,(HMENU) tic7,NULL,NULL);
                }
                else if(LOWORD(wp) == tic8 && papan[7] != 'X' && papan[7] != '0'){
                    papan[7] = 'X';
                    simbol = '0';
                    DestroyWindow(t8);
                    t8 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 200,300, 100,100, hWnd,(HMENU) tic8,NULL,NULL);
                }
                else if(LOWORD(wp) == tic9 && papan[8] != 'X' && papan[8] != '0'){
                    papan[8] = 'X';
                    simbol = '0';
                    DestroyWindow(t9);
                    t9 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 300,300, 100,100, hWnd,(HMENU) tic9,NULL,NULL);
                }
                
            }

            else{
                if(LOWORD(wp) == tic1 && papan[0] != 'X' && papan[0] != '0'){
                    papan[0] = '0';
                    simbol = 'X';
                    DestroyWindow(t1);
                    t1 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 100,100, 100,100, hWnd,(HMENU) tic1,NULL,NULL);
                }
                else if(LOWORD(wp) == tic2 && papan[1] != 'X' && papan[1] != '0'){
                    papan[1] = '0';
                    simbol = 'X';
                    DestroyWindow(t2);
                    t2 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 200,100, 100,100, hWnd,(HMENU) tic2,NULL,NULL);
                }
                else if(LOWORD(wp) == tic3 && papan[2] != 'X' && papan[2] != '0'){
                    papan[2] = '0';
                    simbol = 'X';
                    DestroyWindow(t3);
                    t3 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 300,100, 100,100, hWnd,(HMENU) tic3,NULL,NULL);
                }
                else if(LOWORD(wp) == tic4 && papan[3] != 'X' && papan[3] != '0'){
                    papan[3] = '0';
                    simbol = 'X';
                    DestroyWindow(t4);
                    t4 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 100,200, 100,100, hWnd,(HMENU) tic4,NULL,NULL);
                }
                else if(LOWORD(wp) == tic5 && papan[4] != 'X' && papan[4] != '0'){
                    papan[4] = '0';
                    simbol = 'X';
                    DestroyWindow(t5);
                    t5 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 200,200, 100,100, hWnd,(HMENU) tic5,NULL,NULL);
                }
                else if(LOWORD(wp) == tic6 && papan[5] != 'X' && papan[5] != '0'){
                    papan[5] = '0';
                    simbol = 'X';
                    DestroyWindow(t6);
                    t6 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 300,200, 100,100, hWnd,(HMENU) tic6,NULL,NULL);
                }
                else if(LOWORD(wp) == tic7 && papan[6] != 'X' && papan[6] != '0'){
                    papan[6] = '0';
                    simbol = 'X';
                    DestroyWindow(t7);
                    t7 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 100,300, 100,100, hWnd,(HMENU) tic7,NULL,NULL);
                }
                else if(LOWORD(wp) == tic8 && papan[7] != 'X' && papan[7] != '0'){
                    papan[7] = '0';
                    simbol = 'X';
                    DestroyWindow(t8);
                    t8 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 200,300, 100,100, hWnd,(HMENU) tic8,NULL,NULL);
                }
                else if(LOWORD(wp) == tic9 && papan[8] != 'X' && papan[8] != '0'){
                    papan[8] = '0';
                    simbol = 'X';
                    DestroyWindow(t9);
                    t9 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 300,300, 100,100, hWnd,(HMENU) tic9,NULL,NULL);
                }
            }
            break;
        }
    }

if(papan[0] == papan[1] && papan[1] == papan[2] ||
    papan[3] == papan[4] && papan[4] == papan[5] ||
    papan[6] == papan[7] && papan[7] == papan[8] ||
    papan[0] == papan[3] && papan[3] == papan[6] ||
    papan[1] == papan[4] && papan[4] == papan[7] ||
    papan[2] == papan[5] && papan[5] == papan[8] ||
    papan[0] == papan[4] && papan[4] == papan[8] ||
    papan[2] == papan[4] && papan[4] == papan[6]){
    
    if(simbol == '0' && pemenang == 'L'){
        pemenang = 'W';
        CreateWindowW(L"Static",L"Pemain 1 Menang",WS_VISIBLE | WS_CHILD, 200,40, 100,50, hWnd,NULL,NULL,NULL);
    } else if(simbol == 'X' && pemenang == 'L'){
        pemenang = 'W';
        CreateWindowW(L"Static",L"Pemain 2 Menang",WS_VISIBLE | WS_CHILD, 200,40, 100,50, hWnd,NULL,NULL,NULL);
    }
    return 0;
}

for (int i=0; i<9; i++){
    if(papan[i] != 'X' && papan[i] != '0'){
        break;
    }

    if(i == 8 && pemenang == 'L'){+
        CreateWindowW(L"Static",L"Hasil Seri",WS_VISIBLE | WS_CHILD, 200,40, 150,50, hWnd,NULL,NULL,NULL);
    }
}
return DefWindowProcW(hWnd, msg, wp, lp);
}