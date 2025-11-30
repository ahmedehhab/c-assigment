#ifndef TEXTBUFFER_H
#define TEXTBUFFER_H

struct TextBuffer {
    char** lines;
    int* lineLen;
    int lineCount;
};

void initBuffer(TextBuffer&);
void freeBuffer(TextBuffer&);

void insertChar(TextBuffer&, int line, int col, char c);
void deleteChar(TextBuffer&, int line, int col);

void splitLine(TextBuffer&, int line, int col);
void mergeLineUp(TextBuffer&, int line);

void appendLine(TextBuffer&, const char*);

#endif
