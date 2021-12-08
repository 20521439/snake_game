#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;
void gotoxy(int column, int line);
struct Point {
    int x, y;
};
class CONRAN {
public:
    struct Point A[800];
    struct Point Moi;
    int DoDai, DoKho, Level, LevelUnlock;
    char LastDirection;

    CONRAN() {
        Moi.x = 0; Moi.y = 0;
        DoDai = 3; DoKho = 2; Level = 1; LevelUnlock = 1;
        LastDirection = 'd';
    }
    void VeTuongVaCNV() {
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
        switch (Level)                                                      //Vẽ chướng ngại vật theo độ khó
        {
        case 1: break;
        case 2: VeChuongNgaiVatLevel2();  break;
        case 3: VeChuongNgaiVatLevel3();  break;
        case 4: VeChuongNgaiVatLevel4();  break;
        case 5: VeChuongNgaiVatLevel5();  break;
        case 6: VeChuongNgaiVatLevel6();  break;
        default:
            break;
        }
    }
    void VeRanVaMoi() {
        for (int i = 0; i < DoDai; i++) {                                   //Vẽ rắn
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
        gotoxy(Moi.x, Moi.y);                                               //Xóa mồi
        cout << " ";
        gotoxy(Moi.x, Moi.y);                                               //Vẽ mồi
        cout << "X";
        gotoxy(45, 9);                                                      //Ghi điểm
        printf("Scores: %d", (DoDai - 3) * DoKho);
    }
    void XoaRan() {
        for (int i = 0; i <= DoDai; i++) {                                   //Vẽ rắn
            gotoxy(A[i].x, A[i].y);
            cout << " ";
        }
    }
    void DiChuyen(int Huong) {
        for (int i = DoDai; i > 0; i--)
            A[i] = A[i - 1];
        if (Huong == 0) A[0].x = A[0].x + 1;
        if (Huong == 1) A[0].y = A[0].y + 1;
        if (Huong == 2) A[0].x = A[0].x - 1;
        if (Huong == 3) A[0].y = A[0].y - 1;
        if (A[0].x == Moi.x && A[0].y == Moi.y) {
            DoDai++;                                                            //Tăng độ dài
            switch (Level)
            {
            case 1: TaoMoiLevel1(); break;
            case 2: TaoMoiLevel2(); break;
            case 3: TaoMoiLevel3(); break;
            case 4: TaoMoiLevel4(); break;
            case 5: TaoMoiLevel5(); break;
            case 6: TaoMoiLevel6(); break;
            default:
                break;
            }

        }
        if (A[0].x == 0 || A[0].x == 41 || A[0].y == 0 || A[0].y == 21) {   //Tông tường = die
            Die();
        }
        switch (Level)                                                      //Die vì chướng ngại vật theo độ khó
        {
        case 1: break;
        case 2: ChuongNgaiVatLevel2(); break;
        case 3: ChuongNgaiVatLevel3(); break;
        case 4: ChuongNgaiVatLevel4(); break;
        case 5: ChuongNgaiVatLevel5(); break;
        case 6: ChuongNgaiVatLevel6(); break;
        default:
            break;
        }
        for (int i = DoDai - 1; i > 3; i--) {                               //Cắn cơ thể = die
            if (A[0].x == A[i].x && A[0].y == A[i].y) {
                Die();
            }
        }

    }
    void TaoMoiLevel1() {                                                         //Tạo mồi
        srand(time(NULL));
        Moi.x = rand() % 40 + 1;
        Moi.y = rand() % 20 + 1;
    };
    void VeChuongNgaiVatLevel2() {
        for (int i = 6; i < 16; i++) {
            gotoxy(11, i);
            cout << "X";
            gotoxy(30, i);
            cout << "X";
        }
    }
    void ChuongNgaiVatLevel2() {
        if ((A[0].x == 11 || A[0].x == 30) && A[0].y >= 6 && A[0].y < 16) {
            Die();
        }
    }
    void TaoMoiLevel2() {
        bool check;
        do {
            srand(time(NULL));
            Moi.x = rand() % 40 + 1;
            Moi.y = rand() % 20 + 1;
            if ((Moi.x == 11 || Moi.x == 30) && Moi.y >= 6 && Moi.y < 16)
                check = 1;
            else check = 0;
        } while (check);
    }
    void VeChuongNgaiVatLevel3() {
        for (int i = 11; i < 31; i++) {
            gotoxy(i, 6);
            cout << "X";
            gotoxy(i, 15);
            cout << "X";
        }
    }
    void ChuongNgaiVatLevel3() {
        if ((A[0].y == 6 || A[0].y == 15) && A[0].x >= 11 && A[0].x < 31) {
            Die();
        }
    }
    void TaoMoiLevel3() {
        bool check;
        do {
            srand(time(NULL));
            Moi.x = rand() % 40 + 1;
            Moi.y = rand() % 20 + 1;
            if ((Moi.y == 6 || Moi.y == 15) && Moi.x >= 11 && Moi.x < 31)
                check = 1;
            else check = 0;
        } while (check);
    }
    void VeChuongNgaiVatLevel4() {
        for (int i = 6; i < 18; i++) {
            gotoxy(i, 6);
            cout << "X";
            gotoxy(i, 15);
            cout << "X";
            gotoxy(i + 18, 6);
            cout << "X";
            gotoxy(i + 18, 15);
            cout << "X";
        }
    }
    void ChuongNgaiVatLevel4() {
        if ((A[0].y == 6 || A[0].y == 15) && ((A[0].x >= 6 && A[0].x < 18) || (A[0].x >= 24 && A[0].x < 36))) {
            Die();
        }
    }
    void TaoMoiLevel4() {
        bool check;
        do {
            srand(time(NULL));
            Moi.x = rand() % 40 + 1;
            Moi.y = rand() % 20 + 1;
            if ((Moi.y == 6 || Moi.y == 15) && ((Moi.x >= 6 && Moi.x < 18) || (Moi.x >= 24 && Moi.x < 36)))
                check = 1;
            else check = 0;
        } while (check);
    }
    void VeChuongNgaiVatLevel5() {
        for (int i = 6; i < 18; i++) {
            gotoxy(i, 5);
            cout << "X";
            gotoxy(i, 16);
            cout << "X";
            gotoxy(i + 18, 5);
            cout << "X";
            gotoxy(i + 18, 16);
            cout << "X";
        }
        for (int i = 6; i < 9; i++) {
            gotoxy(6, i);
            cout << "X";
            gotoxy(35, i);
            cout << "X";
            gotoxy(6, i + 7);
            cout << "X";
            gotoxy(35, i + 7);
            cout << "X";
        }
    }
    void ChuongNgaiVatLevel5() {
        if (((A[0].y == 5 || A[0].y == 16) && ((A[0].x >= 6 && A[0].x < 18) || (A[0].x >= 24 && A[0].x < 36)))
            || ((A[0].x == 6 || A[0].x == 35) && ((A[0].y >= 6 && A[0].y < 9) || (A[0].y >= 13 && A[0].y < 16)))) {
            Die();
        }
    }
    void TaoMoiLevel5() {
        bool check;
        do {
            srand(time(NULL));
            Moi.x = rand() % 40 + 1;
            Moi.y = rand() % 20 + 1;
            if (((A[0].y == 5 || A[0].y == 16) && ((A[0].x >= 6 && A[0].x < 18) || (A[0].x >= 24 && A[0].x < 36)))
                || ((A[0].x == 6 || A[0].x == 35) && ((A[0].y >= 6 && A[0].y < 9) || (A[0].y >= 13 && A[0].y < 16))))
                check = 1;
            else check = 0;
        } while (check);
    }
    void VeChuongNgaiVatLevel6() {
        for (int i = 11; i < 31; i++) {
            gotoxy(i, 5);
            cout << "X";
            gotoxy(i, 16);
            cout << "X";
        }
        for (int i = 6; i < 16; i++) {
            gotoxy(7, i);
            cout << "X";
            gotoxy(34, i);
            cout << "X";
        }
    }
    void ChuongNgaiVatLevel6() {
        if (((A[0].y == 5 || A[0].y == 16) && A[0].x >= 11 && A[0].x < 31) || ((A[0].x == 7 || A[0].x == 34) && A[0].y >= 6 && A[0].y < 16)) {
            Die();
        }
    }
    void TaoMoiLevel6() {
        bool check;
        do {
            srand(time(NULL));
            Moi.x = rand() % 40 + 1;
            Moi.y = rand() % 20 + 1;
            if (((A[0].y == 5 || A[0].y == 16) && A[0].x >= 11 && A[0].x < 31) || ((A[0].x == 7 || A[0].x == 34) && A[0].y >= 6 && A[0].y < 16))
                check = 1;
            else check = 0;
        } while (check);
    }
    void Start() {                                                          //Xử lý chính
        int Huong = 0;
        char t;
        ChooseLevel();
        switch (Level)                                                      //Tạo mồi theo Level
        {
        case 1: TaoMoiLevel1(); break;
        case 2: TaoMoiLevel2(); break;
        case 3: TaoMoiLevel3(); break;
        case 4: TaoMoiLevel4(); break;
        case 5: TaoMoiLevel5(); break;
        case 6: TaoMoiLevel6(); break;
        default:
            break;
        }
        system("cls");
        VeTuongVaCNV();
        gotoxy(45, 11);                                                     //Hiển thị độ khó
        printf("Difficult: %d", DoKho);
        while (1) {
            if (_kbhit()) {
                t = _getch();
                if (t == 'a' && LastDirection != 'd') { Huong = 2; LastDirection = t; }
                if (t == 'w' && LastDirection != 's') { Huong = 3; LastDirection = t; }
                if (t == 'd' && LastDirection != 'a') { Huong = 0; LastDirection = t; }
                if (t == 's' && LastDirection != 'w') { Huong = 1; LastDirection = t; }
            }
            XoaRan();
            VeRanVaMoi();
            DiChuyen(Huong);
            gotoxy(52, 9);
            Sleep(320 / DoKho);
        }
    }
    void Die() {
        gotoxy(15, 9);
        printf("GAME OVER!");
        gotoxy(14, 10);
        printf("Your score: %d.", (DoDai - 3) * DoKho);
        gotoxy(10, 11);
        if ((DoDai - 3) * DoKho >= DoKho * 10 + 2 * Level) printf("You was unlock level %d.", ++LevelUnlock);
        Sleep(3000);
        Menu();                              //Trở về Menu chính
    }
    void ChooseLevel() {                    //Chọn màn chơi
        do {
            system("cls");
            printf("CHOOSE A LEVEL:\n1.Level 1.\n");
            for (int i = 2; i < 9; i++) {
                if (i <= LevelUnlock) printf("%d.Level %d.", i, i);
                else {
                    printf("%d.Level %d. LOCKED ", i, i);
                    if (i == LevelUnlock + 1) printf("- Reach %d point at Level %d to unlock!", DoKho * 10 + 2 * i, i - 1);
                }
                cout << endl;
            }
            cout << "Choose level to play :";
            cin >> Level;
        } while (Level > LevelUnlock || Level < 1);
    };
    void Setting() {
        system("cls");
        printf("SETTING\nCurrent difficult: %d\nDifficult selection (1 -> 8): ", DoKho);
        do {
            cin >> DoKho;
        } while (DoKho > 8 || DoKho < 1);
    };
    void Menu() {
        DoDai = 3; LastDirection = 'd';
        A[0].x = 19; A[0].y = 10;
        A[1].x = 20; A[1].y = 10;
        A[2].x = 21; A[2].y = 10;
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
    r.Menu();
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