#include "notebook.h"
#include "./ui_notebook.h"

NoteBook::NoteBook(QWidget *parent) : QMainWindow(parent), ui(new Ui::NoteBook)
{
    ui->setupUi(this);
}

NoteBook::~NoteBook()
{
    delete ui;
}
