#include <iostream>
#include <cstdlib> // For system()
#include <fstream>
#include <string>

using namespace std;

void listFiles(const string& path) {
    string command = "dir " + path; // For Windows
    system(command.c_str()); // Executes the command in the terminal
}

void viewFile(const string& path) {
    ifstream file(path.c_str());
    if (!file) {
        cout << "Error: Cannot open file.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

int main() {
    string command, arg;

    cout << "Simple File Manager\n";
    cout << "Commands: list <path>, view <file>, exit\n";

    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "list") {
            cin >> arg;
            listFiles(arg);
        } else if (command == "view") {
            cin >> arg;
            viewFile(arg);
        } else if (command == "exit") {
            cout << "Exiting File Manager. Goodbye!\n";
            break;
        } else {
            cerr << "Unknown command. Try again.\n";
        }
    }

    return 0;
}
