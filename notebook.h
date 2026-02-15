#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class NoteBook;
}
QT_END_NAMESPACE

class NoteBook : public QMainWindow
{
    Q_OBJECT

public:
    NoteBook(QWidget *parent = nullptr);
    ~NoteBook();
    void init();

private slots:
    void handleBtnOpen();
    void handleBtnClose();
    void handleBtnSave();
    void handleBtnNew();

private:
    Ui::NoteBook *ui;
};
#endif // NOTEBOOK_H
