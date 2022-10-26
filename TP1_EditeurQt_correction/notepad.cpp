#include "notepad.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif // QT_CONFIG(printdialog)
#include <QPrinter>
#endif // QT_CONFIG(printer)
#endif // QT_PRINTSUPPORT_LIB
#include <QFont>
#include <QFontDialog>
#include <QColorDialog>
#include <QCloseEvent>
#include <QFileInfo>
#include <QtGlobal> // for QT_VERSION

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    textChanged(false)
{
    ui.setupUi(this);
    this->setCentralWidget(ui.textEdit);

    connect(ui.actionNew, &QAction::triggered, this, &Notepad::newDocument);
    connect(ui.actionOpen, &QAction::triggered, this, &Notepad::open);
    connect(ui.actionSave, &QAction::triggered, this, &Notepad::save);
    connect(ui.actionSaveAs, &QAction::triggered, this, &Notepad::saveAs);
    connect(ui.actionPrint, &QAction::triggered, this, &Notepad::print);
    connect(ui.actionExit, &QAction::triggered, this, &Notepad::exit);
    connect(ui.actionCopy, &QAction::triggered, this, &Notepad::copy);
    connect(ui.actionCut, &QAction::triggered, this, &Notepad::cut);
    connect(ui.actionPaste, &QAction::triggered, this, &Notepad::paste);
    connect(ui.actionUndo, &QAction::triggered, this, &Notepad::undo);
    connect(ui.actionRedo, &QAction::triggered, this, &Notepad::redo);
    connect(ui.actionColor, &QAction::triggered, this, &Notepad::setColor);
    connect(ui.actionFont, &QAction::triggered, this, &Notepad::selectFont);
    connect(ui.actionBold, &QAction::triggered, this, &Notepad::setFontBold);
    connect(ui.actionUnderline, &QAction::triggered, this, &Notepad::setFontUnderline);
    connect(ui.actionItalic, &QAction::triggered, this, &Notepad::setFontItalic);
    connect(ui.actionAbout, &QAction::triggered, this, &Notepad::about);

//    connect(ui.textEdit, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
    connect(ui.textEdit, &QTextEdit::textChanged, this, &Notepad::onTextChanged);

    // Adding a colored square as icon
    QPixmap pix(16, 16);
    pix.fill(ui.textEdit->textColor());
    ui.actionColor->setIcon(pix);

// Disable menu actions for unavailable features
#if !QT_CONFIG(printer)
    ui.actionPrint->setEnabled(false);
#endif

#if !QT_CONFIG(clipboard)
    ui.actionCut->setEnabled(false);
    ui.actionCopy->setEnabled(false);
    ui.actionPaste->setEnabled(false);
#endif
}

Notepad::~Notepad()
{ }

void Notepad::newDocument() {
    currentFile.clear();
    ui.textEdit->setText(QString());
}

void Notepad::open() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui.textEdit->setText(text);

    file.close();
}

void Notepad::save() {
    QString fileName;

    if (textChanged) // save only if needed
    {    // If we don't have a filename from before, get one.
        if (currentFile.isEmpty()) {
            fileName = QFileDialog::getSaveFileName(this, "Save");
            currentFile = fileName;
        } else {
            fileName = currentFile;
        }

        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }

        QString text;
        QFileInfo fileInfo(fileName);
        if (fileInfo.suffix() == "html" || fileInfo.suffix() == "htm" ) {
            text = ui.textEdit->toHtml();
        } else if (fileInfo.suffix() == "md" ) {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
            text = ui.textEdit->toMarkdown(); // since 5.15
#else
            QMessageBox::warning(this, tr("Saving as Markdown"),
                                 tr("Markdown only available since Qt 5.14 ...<br>"
                                    "Saving to <strong>PlainText</strong> instead!"));
            text = ui.textEdit->toPlainText();
#endif
        } else {
            text = ui.textEdit->toPlainText();
        }

        setWindowTitle(fileName);
        QTextStream out(&file);
        out << text;

        file.close();
        textChanged=false;
    }
}

void Notepad::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui.textEdit->toPlainText();
    out << text;
    file.close();
    textChanged=false;
}

void Notepad::print() {

#if QT_CONFIG(printer)
    QPrinter printDev;
#if QT_CONFIG(printdialog)
    QPrintDialog dialog(&printDev, this);
    if (dialog.exec() == QDialog::Rejected)
        return;
#endif // QT_CONFIG(printdialog)
    ui.textEdit->print(&printDev);
#endif // QT_CONFIG(printer)
}

void Notepad::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn;
    if (textChanged) {
         resBtn = QMessageBox::question( this, tr("Quit Notepad?"),
                                                                    tr("<strong>Text has changed</strong>, Quit anyway?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::Discard | QMessageBox::Save,
                                                                    QMessageBox::Save);
         //todo add button to save...
    } else {
        resBtn = QMessageBox::question( this, tr("Quit Notepad?"),
                                                                    tr("Are you sure?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
    }
    if (resBtn != QMessageBox::Yes && resBtn != QMessageBox::Discard) {
        event->ignore();
    } else {
        event->accept();
    }
}

void Notepad::exit() {
    QEvent event(QEvent::Close);
    QApplication::sendEvent(this, &event);
    if (event.isAccepted())
        QCoreApplication::quit();
}

void Notepad::copy()
{
#if QT_CONFIG(clipboard)
    ui.textEdit->copy();
#endif
}

void Notepad::cut()
{
#if QT_CONFIG(clipboard)
    ui.textEdit->cut();
#endif
}

void Notepad::paste()
{
#if QT_CONFIG(clipboard)
    ui.textEdit->paste();
#endif
}

void Notepad::undo()
{
     ui.textEdit->undo();
}

void Notepad::redo()
{
    ui.textEdit->redo();
}

void Notepad::selectFont()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
        ui.textEdit->setCurrentFont(font);
}

void Notepad::setFontUnderline(bool underline)
{
    ui.textEdit->setFontUnderline(underline);
}

void Notepad::setFontItalic(bool italic)
{
    ui.textEdit->setFontItalic(italic);
}

void Notepad::setColor()
{
    QColor col = QColorDialog::getColor(ui.textEdit->textColor(), this);
    if (!col.isValid())
        return;
    ui.textEdit->setTextColor(col);

    // changing the icon color
    QPixmap pix(16, 16);
    pix.fill(col);
    ui.actionColor->setIcon(pix);
}

void Notepad::setFontBold(bool bold)
{
    bold ? ui.textEdit->setFontWeight(QFont::Bold) :
           ui.textEdit->setFontWeight(QFont::Normal);
}

void Notepad::about()
{
   QMessageBox::about(this, tr("About MDI"),
                tr("The <strong>Notepad</strong> example demonstrates how to code a basic "
                   "text editor using QtWidgets"));

}

void Notepad::onTextChanged()
{
    textChanged=true;
}
