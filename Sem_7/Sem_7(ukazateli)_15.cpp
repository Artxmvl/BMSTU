#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct Command {
    string name;
    int value;
};

void parseCommand(const char* input, vector<Command>& buffer) {
    const char* p = input;

    Command cmd;

    //чтение команды
    while (*p != ' ' && *p != '\0') {
        cmd.name += *p;
        p++;
    }
    cmd.value = 0;
    if (*p == ' ') {
        p++;
        cmd.value = 0;
        while (*p >= '0' && *p <= '9') {
            cmd.value = cmd.value * 10 + (*p - '0');
            p++;
        }
    }


    buffer.push_back(cmd);
}



int main()
{
    setlocale(LC_ALL, "RU");
    char str[50];
    vector <Command> buffer;
    cout << "Введите команду и значение(через пробел):";
    cin.getline(str, 50);
    parseCommand(str, buffer);

    
    for (int i = 0;i < buffer.size();i++) {
        cout << "Название команды: " << buffer[i].name << "  , Значение: " << buffer[i].value << endl;
    }

    return 0;
}

