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
    cout << "Инициализация..." << endl;

    ifstream base("base.txt");
    if (base == NULL) {
        cout << "Ошибка: невозможно загрузить файл базы. Программа будет закрыта..." << endl;
        getchar();
        return 100;
    }
    base.close();
    //CopyFile("base.txt", "base.bak", false);
    cout << "Файл базы успешно загружен!" << endl << endl;
    CurrentFlag = 0;

    if (LEARN) cout << "ВНИМАНИЕ! Включен режим обучения. Не пишите боту ерунду." << endl << endl;

    while (true) {
        string msg, answer;
        cout << "Введите сообщение: ";
        getline(std::cin, msg);
        transform(msg.begin(), msg.end(), msg.begin(), ::tolower);

        if(msg == "cls") system("cls");
        if (RemoveSigns(msg) == "выход") {
            cout << "Пока!" << endl;
            return 0;
        }

        answer = Get_Answer(msg);
        if (answer == "") {
            if (LEARN) {
                cout << "Нет ответа. Что отвечать? Можно несколько вариантов,\nразделенных знаком (арбуз;лимон;ананас;)" << endl;
                cout << "Ваши варианты: ";
                string newl;
                getline(std::cin, newl);
                cout << "Хорошо, я запишу это в базу." << endl;
                ofstream wbase("base.txt", ios::app);
                wbase << "\n" << RemoveSigns(msg) << ";{" << newl << "}";
                wbase.close();
            }
            else cout << "RLogic ничего не ответил..." << endl;
        }
        else
            cout << "RLogic: " << answer << endl;
    }
    return 1;
}
