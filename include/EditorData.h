#ifndef EDITOR_DATA_H
#define EDITOR_DATA_H

class EditorData{
public:
    char getSymbol() const { return _currentSymbol; }
    char getColor()  const { return _currentColor; }
    bool getSolid()  const { return _isSolid; }
    bool getEnemy()  const { return _isEnemy; }

    void setSymbol(char s) { _currentSymbol = s; }
    void setColor(short c) { _currentColor = c; }
    void setSolid(bool s)  { _isSolid = s; }
    void setEnemy(bool e)  { _isEnemy = e; }

private:
    char  _currentSymbol;
    short _currentColor;
    bool  _isSolid;
    bool  _isEnemy;
};

#endif // EDITOR_DATA_H