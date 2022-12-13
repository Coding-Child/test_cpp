#pragma warning(disable:4996)    // 경고 메시지 생략 
#include <iostream>
#include <string>

using namespace std;

#define Line1 cout << "-------------------------------------\n";
#define Line2 cout << "=====================================\n";



void formatC(char* num)
{
    int len = strlen(num);

    cout << ">>이자 = ";

    for (int i = len; i > 0;) {
        cout << *num++;
        --i;
        if (i > 0 && (i % 3) == 0)
            cout << ",";
    }

    cout << "원\n";
}


int main()
{
    double total, rate, month, money, save;
    char cnt;
    char buf[20];

    Line1;
    cout << "    금융 이자(만기) 계산 프로그램" << endl;
    Line1;
    cout << "1. 단리 2: 복리(월단위) exit/x: 종료" << endl;

    while (true) {

        cout << "번호 선택 (1, 2, exit 또는 x) : ";
        cin >> cnt;

        if (sizeof(cnt) == 1 && cnt != 'x') {
            Line1;
            cout << "원 금 : ";
            cin >> money;
            cout << "이자율 : ";
            cin >> rate;
            cout << "기간(월) : ";
            cin >> month;

            switch (cnt) {
            case '1':
                total = money + (money * (rate / 12) * month);
                save = total - money;
                break;
            case '2':
                total = money * pow(1 + (rate / 12), month);
                save = total - money;
                break;
            default:
                total = 0;
                save = 0;
            }
        }

        else {
            Line1;
            cout << ">>프로그램 종료" << endl;
            exit(0);
        }
        Line2;

        string ss = to_string((int)save);
        strcpy(buf, ss.c_str());
        formatC(buf);
        Line2;

    }
    return 0;
}