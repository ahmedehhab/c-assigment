#include "../header/base_type.h"
#include <cctype>
bool isdigit(char c){
    return (c>='0'&&c<='9');
}

Integer::Integer(int v) : val(v) {}
Float::Float(float v) : val(v) {}
Character::Character(char v) : val(v) {}
String::String(string v) : val(v) {}
Boolean::Boolean(bool v) : val(v) {}


bool isInteger(const string& s) {
    if (s.empty()) return false;
    int i = 0;
    if (s[0] == '-' || s[0] == '+') i++;
    for (; i < (int)s.size(); i++)
        if (!isdigit(s[i])) return false;
    return true;
}

bool isFloat(const string& s) {
    int dot = 0, digits = 0, i = 0;

    if (s[0] == '-' || s[0] == '+') i++;

    for (; i < (int)s.size(); i++) {
        if (s[i] == '.') dot++;
        else if (isdigit(s[i])) digits++;
        else return false;
    }

    return dot == 1 && digits > 0;
}



basetype* detectType(const string& input) {
    if (input == "true" || input == "false")
        return new Boolean(input == "true");

    if (input.size() == 1 && !isdigit(input[0]))
        return new Character(input[0]);

    if (isInteger(input))
        return new Integer(stoi(input));

    if (isFloat(input))
        return new Float(stof(input));

    return new String(input);
}



ostream& operator<<(ostream& os, basetype& b) {
    b.print();
    return os;
}
