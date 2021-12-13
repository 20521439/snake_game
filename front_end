#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
void set_color ( int code ) 
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , code );
}
struct Point {
    int x, y;
};

class GAME {
public:
    struct Point A[800];
    struct Point Moi;
    int DoDai, DoKho, Level, LevelUnlocked, DieStatus;
    char LastDirection;
	GAME() {
        DoKho = 2; LevelUnlocked = 1;
        DoDai = 3; Level = 0; DieStatus = 0;
    }
    void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE),
            coord
        );
    }
    void VeTuongVaCNV()
	{
		set_color(16*11+4);
       for (int j = 1; j < 42; j++)
        {
            gotoxy(j, 0);
            cout << char(219);
            gotoxy(j, 21);
            cout << char(219);
        }
        
        for (int j = 0; j < 22; j++)
        {
            gotoxy(0, j);
            cout << char(222);
            gotoxy(41, j);
            cout << char(221);
    	
		}
        switch (Level)                                                    
        {
        case 1: break;
        case 2: VeChuongNgaiVatLevel2();  break;
        case 3: VeChuongNgaiVatLevel3();  break;
        case 4: VeChuongNgaiVatLevel4();  break;
        case 5: VeChuongNgaiVatLevel5();  break;
        case 6: VeChuongNgaiVatLevel6();  break;
        case 7: VeChuongNgaiVatLevel7();  break;
        case 8: VeChuongNgaiVatLevel8();  break;
        default:
            break;
        }
    }
    void VeRanVaMoi() 
	{
		set_color(16*11+3);
        for (int i = 0; i < DoDai; i++) 
		{                                  
            gotoxy(A[i].x, A[i].y);
            cout <<char(254);
        }
        gotoxy(Moi.x, Moi.y);                                               //V? m?i
        cout<<char(254);
    }
    void XoaRan() {                                 //Xóa r?n
        gotoxy(A[DoDai].x, A[DoDai].y);
        cout << " ";
    }
    void DiChuyen(int Huong) {
        for (int i = DoDai; i > 0; i--)
            A[i] = A[i - 1];

        if (Huong == 0) A[0].x = A[0].x + 1;
        if (Huong == 1) A[0].y = A[0].y + 1;
        if (Huong == 2) A[0].x = A[0].x - 1;
        if (Huong == 3) A[0].y = A[0].y - 1;

        if (A[0].x == Moi.x && A[0].y == Moi.y) {
            DoDai++;                                                            //Tang d? dài
            gotoxy(45, 9);                                                      //C?p nh?t di?m 
            printf("Your score: %d", (DoDai - 3) * DoKho);
            switch (Level)
            {
            case 1: TaoMoiLevel1(); break;
            case 2: TaoMoiLevel2(); break;
            case 3: TaoMoiLevel3(); break;
            case 4: TaoMoiLevel4(); break;
            case 5: TaoMoiLevel5(); break;
            case 6: TaoMoiLevel6(); break;
            case 7: TaoMoiLevel7(); break;
            case 8: TaoMoiLevel8(); break;
            default:
                break;
            }
        }
        if (A[0].x == 0 || A[0].x == 41 || A[0].y == 0 || A[0].y == 21) {       //Tông tu?ng = die
            Die();
        }
        switch (Level)                                                          //Tông chu?ng ng?i v?t = die
        {
        case 1: break;
        case 2: ChuongNgaiVatLevel2(); break;
        case 3: ChuongNgaiVatLevel3(); break;
        case 4: ChuongNgaiVatLevel4(); break;
        case 5: ChuongNgaiVatLevel5(); break;
        case 6: ChuongNgaiVatLevel6(); break;
        case 7: ChuongNgaiVatLevel7(); break;
        case 8: ChuongNgaiVatLevel8(); break;
        default:
            break;
        }
        for (int i = DoDai - 1; i > 3; i--) {                                   //C?n co th? = die
            if (A[0].x == A[i].x && A[0].y == A[i].y) {
                Die();
            }
        }

    }
    void Die() {
        int l = 1;
        char t = 't';
        gotoxy(6, 8);
        printf("                          ");
        gotoxy(6, 9);
        printf("                          ");
        gotoxy(6, 10);
        printf("                          ");
        gotoxy(6, 11);
        printf("                          ");
        gotoxy(6, 12);
        printf("                          ");
        gotoxy(14, 9);
        printf("  GAME OVER! ");
        gotoxy(12, 10);
        printf("  Your score: %d. ", (DoDai - 3) * DoKho);
        gotoxy(8, 11);
        if ((DoDai - 3) * DoKho >= DoKho * 10 + 2 * Level)
            if (LevelUnlocked == 8) printf(" Congratulations! You won this game!.");
            else printf(" You unlocked level %d. ", ++LevelUnlocked);
        do {
            gotoxy(7, 14);
            printf("  Press Spacebar to continue ");
            if (l == 1) {
                gotoxy(5, 15);
                printf(" .----------------------------. ");
                gotoxy(5, 16);
                printf(" |____________________________| ");
            }
            else {
                gotoxy(5, 15);
                printf("                                ");
                gotoxy(5, 16);
                printf(" .----------------------------. ");
            }
            if (_kbhit()) {
                t = _getch();
                if (t == ' ') break;
            }
            l = -l;
            Sleep(350);
        } while (1);
        DieStatus = 1;                            //Tr? v? Menu chính
    }

    void VeChuongNgaiVatLevel2() {
        for (int i = 6; i < 16; i++) {
            gotoxy(11, i);
            cout << "X";
            gotoxy(30, i);
            cout << "X";
        }
    }
    void VeChuongNgaiVatLevel3() {
        for (int i = 11; i < 31; i++) {
            gotoxy(i, 6);
            cout << "X";
            gotoxy(i, 15);
            cout << "X";
        }
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
    void VeChuongNgaiVatLevel7() {
        for (int i = 5; i < 18; i++) {
            gotoxy(i, 4);
            cout << "X";
            gotoxy(i, 17);
            cout << "X";
        }
        for (int i = 24; i < 37; i++) {
            gotoxy(i, 4);
            cout << "X";
            gotoxy(i, 17);
            cout << "X";
        }
        for (int i = 10; i < 32; i++) {
            gotoxy(i, 8);
            cout << "X";
            gotoxy(i, 13);
            cout << "X";
        }
        for (int i = 5; i < 10; i++) {
            gotoxy(5, i);
            cout << "X";
            gotoxy(36, i);
            cout << "X";
        }
        for (int i = 12; i < 17; i++) {
            gotoxy(5, i);
            cout << "X";
            gotoxy(36, i);
            cout << "X";
        }
    }
    void VeChuongNgaiVatLevel8() {
        for (int i = 4; i < 18; i++) {
            gotoxy(5, i);
            cout << "X";
            gotoxy(36, i);
            cout << "X";
        }
        for (int i = 13; i < 37; i++) {
            gotoxy(i, 4);
            cout << "X";
            gotoxy(i - 8, 17);
            cout << "X";
        }
        for (int i = 5; i < 13; i++) {
            gotoxy(13, i);
            cout << "X";
            gotoxy(18, i);
            cout << "X";
            gotoxy(23, i + 4);
            cout << "X";
            gotoxy(28, i + 4);
            cout << "X";
        }
    }

    void ChuongNgaiVatLevel2() {
        if ((A[0].x == 11 || A[0].x == 30) && A[0].y >= 6 && A[0].y < 16) {
            Die();
        }
    }
    void ChuongNgaiVatLevel3() {
        if ((A[0].y == 6 || A[0].y == 15) && A[0].x >= 11 && A[0].x < 31) {
            Die();
        }
    }
    void ChuongNgaiVatLevel4() {
        if ((A[0].y == 6 || A[0].y == 15) && ((A[0].x >= 6 && A[0].x < 18) || (A[0].x >= 24 && A[0].x < 36))) {
            Die();
        }
    }
    void ChuongNgaiVatLevel5() {
        if (((A[0].y == 5 || A[0].y == 16) && ((A[0].x >= 6 && A[0].x < 18) || (A[0].x >= 24 && A[0].x < 36)))
            || ((A[0].x == 6 || A[0].x == 35) && ((A[0].y >= 6 && A[0].y < 9) || (A[0].y >= 13 && A[0].y < 16)))) {
            Die();
        }
    }
    void ChuongNgaiVatLevel6() {
        if (((A[0].y == 5 || A[0].y == 16) && A[0].x >= 11 && A[0].x < 31) || ((A[0].x == 7 || A[0].x == 34) && A[0].y >= 6 && A[0].y < 16)) {
            Die();
        }
    }
    void ChuongNgaiVatLevel7() {
        if (((A[0].y == 4 || A[0].y == 17) && ((A[0].x >= 5 && A[0].x < 18) || (A[0].x >= 24 && A[0].x < 37)))
            || ((A[0].x == 5 || A[0].x == 36) && ((A[0].y >= 5 && A[0].y < 10) || (A[0].y >= 12 && A[0].y < 17)))
            || ((A[0].y == 8 || A[0].y == 13) && ((A[0].x >= 10 && A[0].x < 32)))) {
            Die();
        }
    }
    void ChuongNgaiVatLevel8() {
        if ((A[0].y == 4 && A[0].x >= 13 && A[0].x < 37) || (A[0].y == 17 && A[0].x >= 5 && A[0].x < 29)
            || ((A[0].x == 5 || A[0].x == 36) && (A[0].y >= 4 && A[0].y < 18))
            || ((A[0].x == 13 || A[0].x == 18) && (A[0].y >= 5 && A[0].y < 13))
            || ((A[0].x == 23 || A[0].x == 28) && (A[0].y >= 9 && A[0].y < 17))) {
            Die();
        }
    }

    void TaoMoiLevel1() {                                                       //T?o m?i
        srand(time(NULL));
        Moi.x = rand() % 40 + 1;
        Moi.y = rand() % 20 + 1;
    };
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
    void TaoMoiLevel5() {
        bool check;
        do {
            srand(time(NULL));
            Moi.x = rand() % 40 + 1;
            Moi.y = rand() % 20 + 1;
            if (((Moi.y == 5 || Moi.y == 16) && ((Moi.x >= 6 && Moi.x < 18) || (Moi.x >= 24 && Moi.x < 36)))
                || ((Moi.x == 6 || Moi.x == 35) && ((Moi.y >= 6 && Moi.y < 9) || (Moi.y >= 13 && Moi.y < 16))))
                check = 1;
            else check = 0;
        } while (check);
    }
    void TaoMoiLevel6() {
        bool check;
        do {
            srand(time(NULL));
            Moi.x = rand() % 40 + 1;
            Moi.y = rand() % 20 + 1;
            if (((Moi.y == 5 || Moi.y == 16) && Moi.x >= 11 && Moi.x < 31) || ((Moi.x == 7 || Moi.x == 34) && Moi.y >= 6 && Moi.y < 16))
                check = 1;
            else check = 0;
        } while (check);
    }
    void TaoMoiLevel7() {
        bool check;
        do {
            srand(time(NULL));
            Moi.x = rand() % 40 + 1;
            Moi.y = rand() % 20 + 1;
            if (((Moi.y == 4 || Moi.y == 17) && ((Moi.x >= 5 && Moi.x < 18) || (Moi.x >= 24 && Moi.x < 37)))
                || ((Moi.x == 5 || Moi.x == 36) && ((Moi.y >= 5 && Moi.y < 10) || (Moi.y >= 12 && Moi.y < 17)))
                || ((Moi.y == 8 || Moi.y == 13) && ((Moi.x >= 10 && Moi.x < 32))))
                check = 1;
            else check = 0;
        } while (check);
    }
    void TaoMoiLevel8() {
        bool check;
        do {
            srand(time(NULL));
            Moi.x = rand() % 40 + 1;
            Moi.y = rand() % 20 + 1;
            if ((Moi.y == 4 && Moi.x >= 13 && Moi.x < 37) || (Moi.y == 17 && Moi.x >= 5 && Moi.x < 19)
                || ((Moi.x == 5 || Moi.x == 36) && (Moi.y >= 4 && Moi.y < 18))
                || ((Moi.x == 13 || Moi.x == 18) && (Moi.y >= 5 && Moi.y < 13))
                || ((Moi.x == 23 || Moi.x == 28) && (Moi.y >= 9 && Moi.y < 17)))
                check = 1;
            else check = 0;
        } while (check);
    }

    void Menu() {
        char choice;
        do {
            system("cls");
            printf("SNAKE\n1.Start\n2.Setting\n3.Quit game\nType your choice (1->3): ");
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

    void Start() {                                                          //X? lý chính
        DoDai = 3; LastDirection = 'd'; DieStatus = 0;
        A[0].x = 18; A[0].y = 19;
        A[1].x = 17; A[1].y = 19;
        A[2].x = 16; A[2].y = 19;
        int Huong = 0;
        char t;
        ChooseLevel();
        switch (Level)                                                      //T?o m?i theo Level
        {
        case 1: TaoMoiLevel1(); break;
        case 2: TaoMoiLevel2(); break;
        case 3: TaoMoiLevel3(); break;
        case 4: TaoMoiLevel4(); break;
        case 5: TaoMoiLevel5(); break;
        case 6: TaoMoiLevel6(); break;
        case 7: TaoMoiLevel7(); break;
        case 8: TaoMoiLevel8(); break;
        default:
            break;
        }
        system("cls");
        VeTuongVaCNV();
        gotoxy(45, 9);                                                      //Ghi di?m 
        printf("Your score: 0");
        gotoxy(45, 11);                                                     //Hi?n th? d? khó
        printf("Difficulty: %d", DoKho);
        do {
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
            gotoxy(45, 13);
            Sleep(320 / DoKho);
        } while (DieStatus == 0);
    }

    void ChooseLevel() {                    //Ch?n màn choi
        do {
            system("cls");
            printf("CHOOSE A LEVEL:\n1.Level 1.\n");
            for (int i = 2; i < 9; i++) {
                if (i <= LevelUnlocked) printf("%d.Level %d.", i, i);
                else {
                    printf("%d.Level %d. LOCKED ", i, i);
                    if (i == LevelUnlocked + 1) printf("- Reach %d Point at Level %d to unlock!", DoKho * 10 + 2 * i, i - 1);
                }
                cout << endl;
            }
            cout << "Choose level to play : ";
            cin >> Level;
        } while (Level > LevelUnlocked || Level < 1);
    };

    void Setting() {
        system("cls");
        printf("SETTINGS\nCurrent difficulty: %d\nDifficulty selection (1 -> 8): ", DoKho);
        do {
            cin >> DoKho;
        } while (DoKho > 8 || DoKho < 1);
    };

};

void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void MainMenu(int& n)                                                                      //Menu phía ngoài tru?c khi vào game
{
    cout << "\t\t\tCHAO MUNG CAC BAN DEN VOI TRO CHOI CON RAN\n";
    cout << "\t\t\tWELCOME TO SNAKE GAME\n";
    cout << "\t\t\tVUI LONG CHON NGON NGU\n";
    cout << "\t\t\tPLEASE SELECT LANGUAGE\n";
    cout << "\t\t\t1.Tieng Viet\n";
    cout << "\t\t\t2.English\n";
    do
    {
        cout << "\t\t\tMoi ban chon ngon ngu/Please choose your language:";
        cin >> n;
    } while (n != 1 && n != 2);
    system("cls");
    if (n == 1)
    {
        cout << "\t\t\tCAM ON SU LUA CHON CUA BAN\n"; Sleep(2500);
        cout << "\t\t\tCHUC BAN CO MOT KHOANG THOI GIAN VUI VE\n"; Sleep(2500);
        cout << "\t\t\tTRO CHOI CON RAN-DUOC PHAT TRIEN TU NHOM 3K1T\n"; Sleep(2500);
        cout << "\t\t\t---HUONG DAN CHOI---\n";
        cout << "\t\t\t -Phim W di len-\n";
        cout << "\t\t\t -Phim S di xuong-\n";
        cout << "\t\t\t -Phim A sang trai-\n";
        cout << "\t\t\t -Phim D sang phai-\n";
        Sleep(2500);
        cout << "\t\t\tCho trong giay lat..."; Sleep(2500);
        system("cls");
    }
    else
    {
        cout << "\t\t\tTHANK YOU FOR YOUR CHOICE\n"; Sleep(2500);
        cout << "\t\t\tHAVE A NICE TIME!!!\n"; Sleep(2500);
        cout << "\t\t\tSNAKE GAME-DEVELOPED BY 3K1T GROUP\n"; Sleep(2500);
        cout << "\t\t\t---HOW TO PLAY---\n";
        cout << "\t\t\t-Press W -Up-\n";
        cout << "\t\t\t-Press S -Down-\n";
        cout << "\t\t\t-Press A -Left-\n";
        cout << "\t\t\t-Press D -Right-\n";
        Sleep(2500);
        cout << "\t\t\tWait for a minute..."; Sleep(2500);
        system("cls");
    }
}
int main()
{
    int n;
    system("color b4");
    MainMenu(n);
    SetWindowSize(60, 22);
    GAME Game;
    Game.Menu();
    return 0;
}
