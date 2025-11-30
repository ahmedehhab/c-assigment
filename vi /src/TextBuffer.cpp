#include "../header/TextBuffer.h"
#include <cstring>
#include <cstdlib>

void initBuffer(TextBuffer& b) {
    b.lineCount = 1;
    b.lines = (char**)malloc(sizeof(char*));
    b.lineLen = (int*)malloc(sizeof(int));

    b.lines[0] = (char*)malloc(1);
    b.lines[0][0] = '\0';
    b.lineLen[0] = 0;
}

void freeBuffer(TextBuffer& b) {
    for (int i = 0; i < b.lineCount; i++)
        free(b.lines[i]);
    free(b.lines);
    free(b.lineLen);
}

// dynamic expand helper
static void resizeLines(TextBuffer& b, int newSize) {
    b.lines = (char**)realloc(b.lines, newSize * sizeof(char*));
    b.lineLen = (int*)realloc(b.lineLen, newSize * sizeof(int));
}

// insert character
void insertChar(TextBuffer& b, int line, int col, char c) {
    int len = b.lineLen[line];

    b.lines[line] = (char*)realloc(b.lines[line], len + 2);

    memmove(&b.lines[line][col + 1], &b.lines[line][col], len - col);

    b.lines[line][col] = c;
    b.lineLen[line]++;
    b.lines[line][b.lineLen[line]] = '\0';
}

void deleteChar(TextBuffer& b, int line, int col) {
    if (col <= 0) return;
    int len = b.lineLen[line];

    memmove(&b.lines[line][col - 1], &b.lines[line][col], len - col);

    b.lineLen[line]--;
    b.lines[line] = (char*)realloc(b.lines[line], b.lineLen[line] + 1);
    b.lines[line][b.lineLen[line]] = '\0';
}

// split line at cursor
void splitLine(TextBuffer& b, int line, int col) {
    char* right = strdup(&b.lines[line][col]);
    b.lines[line][col] = '\0';
    b.lineLen[line] = col;

    resizeLines(b, b.lineCount + 1);

    for (int i = b.lineCount; i > line + 1; i--) {
        b.lines[i] = b.lines[i - 1];
        b.lineLen[i] = b.lineLen[i - 1];
    }

    b.lines[line + 1] = right;
    b.lineLen[line + 1] = strlen(right);
    b.lineCount++;
}

void mergeLineUp(TextBuffer& b, int line) {
    int above = line - 1;

    int newLen = b.lineLen[above] + b.lineLen[line];
    b.lines[above] = (char*)realloc(b.lines[above], newLen + 1);

    strcpy(&b.lines[above][b.lineLen[above]], b.lines[line]);

    free(b.lines[line]);

    for (int i = line; i < b.lineCount - 1; i++) {
        b.lines[i] = b.lines[i + 1];
        b.lineLen[i] = b.lineLen[i + 1];
    }

    b.lineCount--;
}

void appendLine(TextBuffer& b, const char* str) {
    int n = b.lineCount;
    resizeLines(b, n + 1);

    b.lines[n] = strdup(str);
    b.lineLen[n] = strlen(str);
    b.lineCount++;
}
