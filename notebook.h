#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QMainWindow>

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

private:
    Ui::NoteBook *ui;
};
#endif // NOTEBOOK_H
