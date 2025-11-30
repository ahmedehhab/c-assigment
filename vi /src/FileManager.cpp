#include "../header/FileManager.h"
#include <fstream>

bool loadFile(const std::string& name, TextBuffer& buf) {
    std::ifstream in(name);
    if (!in.is_open()) return false;

    char line[2048];
    while (in.getline(line, 2048)) {
        appendLine(buf, line);
    }
    return true;
}

bool saveFile(const std::string& name, const TextBuffer& buf) {
    std::ofstream out(name);
    if (!out.is_open()) return false;

    for (int i = 0; i < buf.lineCount; i++)
        out << buf.lines[i] << "\n";

    return true;
}

std::string readAll(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) return "File not found.";

    std::string out, tmp;
    while (getline(in, tmp)) out += tmp + "\n";
    return out;
}
