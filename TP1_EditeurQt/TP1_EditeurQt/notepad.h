#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QTextCharFormat>
#include "ui_notepad.h"

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();
private:
    void colorChanged(const QColor &c);
    void closeEvent (QCloseEvent *event) override;

private slots:

    void newDocument();

    void open();

    void save();

    void saveAs();

    void print();

    void exit();

    void copy();

    void cut();

    void paste();

    void undo();

    void redo();

    void selectFont();

    void setColor();

    void setFontBold(bool bold);

    void setFontUnderline(bool underline);

    void setFontItalic(bool italic);

    void about();

    void onTextChanged();

private:
    Ui::Notepad ui;
    QString currentFile;
    bool textChanged;
};
#endif // NOTEPAD_H
