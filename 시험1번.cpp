#pragma warning(disable:4996)    // ��� �޽��� ���� 
#include <iostream>
#include <string>

using namespace std;

#define Line1 cout << "-------------------------------------\n";
#define Line2 cout << "=====================================\n";



void formatC(char* num)
{
    int len = strlen(num);

    cout << ">>���� = ";

    for (int i = len; i > 0;) {
        cout << *num++;
        --i;
        if (i > 0 && (i % 3) == 0)
            cout << ",";
    }

    cout << "��\n";
}


int main()
{
    double total, rate, month, money, save;
    char cnt;
    char buf[20];

    Line1;
    cout << "    ���� ����(����) ��� ���α׷�" << endl;
    Line1;
    cout << "1. �ܸ� 2: ����(������) exit/x: ����" << endl;

    while (true) {

        cout << "��ȣ ���� (1, 2, exit �Ǵ� x) : ";
        cin >> cnt;

        if (sizeof(cnt) == 1 && cnt != 'x') {
            Line1;
            cout << "�� �� : ";
            cin >> money;
            cout << "������ : ";
            cin >> rate;
            cout << "�Ⱓ(��) : ";
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
            cout << ">>���α׷� ����" << endl;
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