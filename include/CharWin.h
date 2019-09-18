#ifndef CHAR_WIN_H
#define CHAR_WIN_H

#include "Window.h"
#include "EditorData.h"
#include <vector>

#define MAX_SYMBOLS 93

class CharWin : public Window{
public:
    CharWin(int width, int height, int startX, int startY);
    ~CharWin();

    void drawWin();
    void inputWin(int input);

    const EditorData& getData() const { return _ed; }

private:
    std::vector<char> _symbols;

    EditorData _ed;
};

#endif // CHAR_WIN_H