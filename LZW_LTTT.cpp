#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

vector<int> Encode(const string& input) {
    map<string, int> dictionary;
    int dict_Size = 256;
    for (int i = 0; i < dict_Size; i++) {
        string ch = "";
        ch += char(i);
        dictionary[ch] = i;
    }
    string entry, box;
    entry = box = "";
    entry = entry + input[0];
    vector<int> result;
    for (int i = 0; i < input.length(); i++) {
        if (i != input.length() - 1) {
            box = box + input[i + 1];
        }
        if (dictionary.find(entry + box) != dictionary.end()) {
            entry += box;
        }
        else {
            result.emplace_back(dictionary[entry]);
            dictionary[entry + box] = dict_Size++;
            entry = box;
        }
        box = "";
    }
    result.emplace_back(dictionary[entry]);
    return result;
}

void Decode(const vector<int>& input) {
    map<int, string> dictionary;
    int dict_Size = 256;
    for (int i = 0; i < dict_Size; i++) {
        string ch = "";
        ch += char(i);
        dictionary[i] = ch;
    }
    string result, box;
    int x, y;
    x = input[0];
    result = x;
    cout << result;
    box += result[0];
    for (int i = 0; i < input.size() - 1; i++) {
        y = input[i + 1];
        if (dictionary.find(y) == dictionary.end()) {
            result = dictionary[x];
            result += box;
        }
        else {
            result = dictionary[y];
        }
        cout << result;
        box = "";
        box += result[0];
        dictionary[dict_Size] = dictionary[x] + box;
        dict_Size++;
        x = y;
    }
}

int Sum_bit(vector<int> v) {
    for (auto val : v) {
        if (val > 255) {
            return v.size() * 9;
            break;
        }
    }
    return v.size() * 8;
}

double Comp_ratio(string str, double lzw) {
    return (str.length() * 8) / lzw;
}

int main() {
    int choose;
        system("color 0B");
        cout << R"(
                    <+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>
          _      _______        __   ____                                               _
         | |    |__  /\ \      / /  / ___| ___   _ __ ___   _ __   _ __  ___  ___  ___ (_)  ___   _ __
         | |      / /  \ \ /\ / /  | |    / _ \ | '_ ` _ \ | '_ \ | '__|/ _ \/ __|/ __|| | / _ \ | '_ \
         | |___  / /_   \ V  V /   | |___| (_) || | | | | || |_) || |  |  __/\__ \\__ \| || (_) || | | |
         |_____|/____|   \_/\_/     \____|\___/ |_| |_| |_|| .__/ |_|   \___||___/|___/|_| \___/ |_| |_|
                                                           |_|

                    <+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>
                 ______  ____
                /_  __/ / __/___ _ ___  ___ _
                 / /_  _\ \ / _ `// _ \/ _ `/      /\/\
                /_/(_)/___/ \_,_//_//_/\_, /      / /  \
                                      /___/      / / /\ \      ______  ___
                                                 \ \/ / /     /_  __/ / _ \ __ __ ___   ___  ___ _
                                                  \  / /       / /_  / // // // // _ \ / _ \/ _ `/
                                                   \/\/       /_/(_)/____/ \_,_/ \___//_//_/\_, /
                                                                                           /___/
    )" << endl;
    while (true) {
        cout << "What do you want to do??" << endl;
        cout << "1: Encode something!" << endl;
        cout << "2: Decode something!" << endl;
        cout << "3: Both of them!" << endl;
        cout << "Enter your choice: ";
        cin >> choose;
        if (choose == 1) {
            string str;
            cin.ignore();
            cout << "Enter a string you wanna encode: ";
            getline(cin, str);
            vector<int> encoded = Encode(str);
            cout << "Casting magic spells in the background please wait (*^_^*)" << endl;
            cout << endl;
            streamsize prev_precision = cout.precision();
            for (double i = 0; i < 10; i++) {
                cout << "\33[2K\r"
                    << "[" << string(6 * i, char(219)) << string(6 * (10 - i), '-') << "]    " << 10 * i << "%  |  " << showpoint << setprecision(2) << "ETA: 00:00:0" << 5 - 0.5 * i;
                usleep(500000);
            }
            cout << "\33[2K\r"
                << "[" << string(60, char(219)) << "]    "
                << "100%  |  "
                << "Completed";
            usleep(500000);
            cout << noshowpoint << setprecision(prev_precision);
            cout << endl;
            cout << endl;
            cout << "Encode result: ";
            for (auto c : encoded) {
                cout << c << " ";
            }
            cout << endl;
            double sum = Sum_bit(encoded);
            double ratio = Comp_ratio(str, sum);
            cout << "Memory usage: " << sum << "bits" << endl;
            cout << "Compression ratio: " << ratio << endl;
        }
        if (choose == 2) {
            vector<int> in;
            int len, encoded_str;
            cout << "Enter the length of the code you want to encode: ";
            cin >> len;
            cout << "Enter your number or copy all of them: ";
            for (int i = 0; i < len; i++) {
                cin >> encoded_str;
                in.push_back(encoded_str);
            }
            cout << "Casting magic spells in the background please wait (*^_^*)" << endl;
            cout << endl;
            streamsize prev_precision = cout.precision();
            for (double i = 0; i < 10; i++) {
                cout << "\33[2K\r"
                    << "[" << string(6 * i, char(219)) << string(6 * (10 - i), '-') << "]    " << 10 * i << "%  |  " << showpoint << setprecision(2) << "ETA: 00:00:0" << 5 - 0.5 * i;
                usleep(500000);
            }
            cout << "\33[2K\r"
                << "[" << string(60, char(219)) << "]    "
                << "100%  |  "
                << "Completed";
            usleep(500000);
            cout << noshowpoint << setprecision(prev_precision);
            cout << endl;
            cout << endl;
            cout << "Decode result: ";
            Decode(in);
            cout << endl;
        }
        if (choose == 3) {
            string str;
            cin.ignore();
            cout << "Enter a string you wanna encode: ";
            getline(cin, str);
            vector<int> encoded = Encode(str);
            cout << "Casting magic spells in the background please wait (*^_^*)" << endl;
            cout << endl;
            streamsize prev_precision = cout.precision();
            for (double i = 0; i < 10; i++) {
                cout << "\33[2K\r"
                    << "[" << string(6 * i, char(219)) << string(6 * (10 - i), '-') << "]    " << 10 * i << "%  |  " << showpoint << setprecision(2) << "ETA: 00:00:0" << 5 - 0.5 * i;
                usleep(500000);
            }
            cout << "\33[2K\r"
                << "[" << string(60, char(219)) << "]    "
                << "100%  |  "
                << "Completed";
            usleep(500000);
            cout << noshowpoint << setprecision(prev_precision);
            cout << endl;
            cout << endl;
            cout << "Encode result: ";
            for (auto c : encoded) {
                cout << c << " ";
            }
            cout << endl;
            double sum = Sum_bit(encoded);
            double ratio = Comp_ratio(str, sum);
            cout << "Memory usage: " << sum << "bits" << endl;
            cout << "Compression ratio: " << ratio << endl;
            cout << "Decode result: ";
            Decode(encoded);
            cout << endl;
        }
        cout << endl;
        cout << "Do you want to continue? (Y/N): ";
        string ans;
        cin >> ans;
        if (ans == "y" || ans == "Yes" || ans == "YES" || ans == "yes") {
            continue;
        }
        if (ans == "n" || ans == "No" || ans == "NO" || ans == "no") {
            break;
        }
    }
    cout << "Press any key to exit (#^.^#)";
    system("pause > nul");
    cout << "\33[2K\rAlright see you next time (^-^)/";
    sleep(2);
    system("color 0F");
}