#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <algorithm>
//#include <windows.h>
#include <time.h>
#include "Base.hpp"

#define LEARN 1

using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");

    PrintLogo();
    cout << "�������������..." << endl;

    ifstream base("base.txt");
    if (base == NULL) {
        cout << "������: ���������� ��������� ���� ����. ��������� ����� �������..." << endl;
        getchar();
        return 100;
    }
    base.close();
    //CopyFile("base.txt", "base.bak", false);
    cout << "���� ���� ������� ��������!" << endl << endl;
    CurrentFlag = 0;

    if (LEARN) cout << "��������! ������� ����� ��������. �� ������ ���� ������." << endl << endl;

    while (true) {
        string msg, answer;
        cout << "������� ���������: ";
        getline(std::cin, msg);
        transform(msg.begin(), msg.end(), msg.begin(), ::tolower);

        if(msg == "cls") system("cls");
        if (RemoveSigns(msg) == "�����") {
            cout << "����!" << endl;
            return 0;
        }

        answer = Get_Answer(msg);
        if (answer == "") {
            if (LEARN) {
                cout << "��� ������. ��� ��������? ����� ��������� ���������,\n����������� ������ (�����;�����;������;)" << endl;
                cout << "���� ��������: ";
                string newl;
                getline(std::cin, newl);
                cout << "������, � ������ ��� � ����." << endl;
                ofstream wbase("base.txt", ios::app);
                wbase << "\n" << RemoveSigns(msg) << ";{" << newl << "}";
                wbase.close();
            }
            else cout << "RLogic ������ �� �������..." << endl;
        }
        else
            cout << "RLogic: " << answer << endl;
    }
    return 1;
}
