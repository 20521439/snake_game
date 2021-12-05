#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;
void Menu();
void gotoxy(int column, int line);
struct Point {
    int x, y;
};
class CONRAN {
public:
    struct Point A[100];
    struct Point Moi;
    int DoDai, DoKho;

    CONRAN() {
        Moi.x = 0; Moi.y = 0;
        DoDai = 3; DoKho = 1;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
    void Ve() {
        for (int j = 0; j < 42; j++) {                                      //Vẽ tường
            gotoxy(j, 0);
            cout << "X";
            gotoxy(j, 21);
            cout << "X";
        }
        for (int j = 1; j < 21; j++) {
            gotoxy(0, j);
            cout << "X";
            gotoxy(41, j);
            cout << "X";
        }
        for (int i = 0; i < DoDai; i++) {                                   //Vẽ rắn
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
        gotoxy(Moi.x, Moi.y);                                               //Vẽ mồi
        cout << "X";
        gotoxy(45, 9);                                                      //Ghi điểm
        printf("Scores: %d", DoDai*DoKho);
        gotoxy(45, 11);
        printf("Level: %d", DoKho);
    }
    void DiChuyen(int Huong) {
        for (int i = DoDai ; i > 0; i--)
            A[i] = A[i - 1];
        if (Huong == 0) A[0].x = A[0].x + 1;
        if (Huong == 1) A[0].y = A[0].y + 1;
        if (Huong == 2) A[0].x = A[0].x - 1;
        if (Huong == 3) A[0].y = A[0].y - 1;
        if (A[0].x == Moi.x && A[0].y == Moi.y) {
            DoDai++;
            taoMoi();
        }
        if (A[0].x == 0 || A[0].x == 41 || A[0].y == 0 || A[0].y == 21) {   //Tông tường = die
           // system("cls");
            gotoxy(15, 9);
            printf("GAME OVER!");
            gotoxy(14, 10);
            printf("Your score: %d.", DoDai*DoKho);
            Sleep(3000);
            menu();                                                         //Trở về menu chính
        }

    }
    void taoMoi() {                                                         //Tạo mồi
        srand(time(NULL));
        Moi.x = rand() % 40 + 1;
        Moi.y = rand() % 20 + 1;
    };
    void Start() {                                                          //Xử lý chính
        int Huong = 0;
        char t;
        taoMoi();
        while (1) {
            if (_kbhit()) {
                t = _getch();
                if (t == 'a') Huong = 2;
                if (t == 'w') Huong = 3;
                if (t == 'd') Huong = 0;
                if (t == 's') Huong = 1;
            }
            system("cls");
            Ve();
            DiChuyen(Huong);
            Sleep(320/DoKho);
        }
    }
    void Setting() {
        system("cls");
        printf("SETTING\nCurrent level: %d\nLevel selection (1 -> 8): ", DoKho);
        do {
            cin >> DoKho;
        } while (DoKho > 8 || DoKho < 1);
    };
    void menu() {
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
        char choice;
        do {
            system("cls");
            printf("SNAKE\n1.Start\n2.Setting\n3.Quit game\nType you choose (1->3): ");
            do {
                cin >> choice;
            } while (choice != '1' && choice != '2' && choice != '3');
            switch (choice)
            {
            case '1': Start(); break;
            case '2': Setting(); break;
            case '3': exit(0); break;
            }
        } while (1);
    }
};

int main()
{
    CONRAN r;
    r.menu(); 
    return 0;
}


void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}
