#pragma warning(disable:4996)    // 경고 메시지 생략 

#include <iostream>

#include <string>

using namespace std;

 

#define Line1 cout << "-------------------------------------\n";

#define Line2 cout << "====================\n";

 

void formatC(char* num)   

{

    int len = strlen(num);  

 

    cout << ">>원금+이자 = ";

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

    double total, rate, month, money;

    int cnt;

    char buf[20];

 

    cin >> cnt;

 

    while (true) {

          //...

          switch (cnt) {

                  case 1:

                      total = money + (money * (rate / 12) * month);

                      break;

                  case 2:

                      total = money * pow(1 + (rate / 12), month);

                      break;

                  case 0:

                      exit(0);

                  default:

                      total = 0;

          }

          Line2;

          string ss = to_string((int)total);  

          strcpy(buf, ss.c_str());    

          formatC(buf);

          Line2;

    }

    return 0;

}