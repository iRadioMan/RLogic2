#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
//#include <windows.h>
#include <vector>
#include <iterator>
#include "LineOps.hpp"

using namespace std;

#ifndef BASE_WORKER
#define BASE_WORKER

const string version = "0.2.1";

#define DEBUG 0

string CommandInterpreter(string line) {
    if (line == ":d" || line == ")" || line == ")))")
        return ":D";
    if (line == ":3" || line == ":3")
        return ":3";
    if (line == "))" || line == ";D")
        return ";D";
    if (line == "#disablebot")
        return "Иди в пизду)";
    if (line == "null" || line == "null;")
        return "ААА! А! ОШИБКА СТОП 0x0000001!";
    return "0";
}

char ANS_START = '{',
    END_OF_LINE = '}';

static int CurrentFlag;

string Get_Answer(string q) {
    ifstream base("base.txt");
    if (base == NULL)
        return "Я базу не могу прочитать. Что за ерунда?";

    //команды со знаками
    if (CommandInterpreter(q) != "0")
        return CommandInterpreter(q);

    q = RemoveSigns(q);
    if (q == "") return "Ошибка 228.";

    string line;
    if (DEBUG) cout << endl << "-- DEBUG --" << endl << "Your message: " << q << endl;

    while (!base.eof()) {
        getline(base, line);
        string svariants = "";
        string sanswers = "";
        size_t i = 0;
        for(i = 0; line[i] != ANS_START; ++i) svariants += line[i];
        for(i += 1; line[i] != END_OF_LINE; ++i) sanswers += line[i];

        vector<string> variants = GetWords(svariants, ';');
        vector<string> answers = GetWords(sanswers, ';');
        if (DEBUG) cout << "Answers size: " << answers.size() << endl;

        for (vector<string>::iterator itr = variants.begin(); itr != variants.end(); ++itr) {
            if (DEBUG) cout << "Variant from base: " << *itr << endl;
            if (LineContains(line, q) && q == *itr) {
                if (GetFlag(variants) == CurrentFlag || GetFlag(variants) == 0) {
                    CurrentFlag = GetFlag(answers);
                    if (CurrentFlag != 0) {
                        if (CurrentFlag == -1) CurrentFlag = 0;
                        return answers[rand() % (answers.size() - 1) + 1];
                    }
                    else return answers[rand() % answers.size()];
                }
            }
        }
    }
    cout << endl;
    return "";
}

void PrintLogo() {
    cout << "-------------------------" << endl;
    cout << "     RLogic 2 v" << version << "     " << endl;
    cout << "       by RadioMan       " << endl;
    cout << "    vk.com/id226606031   " << endl;
    cout << "-------------------------" << endl;
}

#endif // BASE_WORKER
