#include "notebook.h"
#include "./ui_notebook.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

NoteBook::NoteBook(QWidget *parent) : QMainWindow(parent), ui(new Ui::NoteBook)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    init();
}

NoteBook::~NoteBook()
{
    delete ui;
}

void NoteBook::init()
{
    connect(ui->btnOpen, &QPushButton::clicked, this, &NoteBook::handleBtnOpen);
    connect(ui->btnClose, &QPushButton::clicked, this, &NoteBook::handleBtnClose);
    connect(ui->btnSave, &QPushButton::clicked, this, &NoteBook::handleBtnSave);
    connect(ui->btnNew, &QPushButton::clicked, this, &NoteBook::handleBtnNew);
}

void NoteBook::handleBtnOpen()
{
    QString filter = "文本文件 (*.txt)";

    // 打开文件对话框，获取用户选择的文件路径
    // 参数: 父窗口, 对话框标题, 默认打开的目录, 过滤器
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "选择一个文件",  // 标题
                                                    QDir::homePath(), // 默认打开用户目录
                                                    filter);          // 过滤器

    // 检查用户是否选择了文件 (如果没有选择或点击取消，返回的字符串为空)
    if (!fileName.isEmpty()) {
        // 在这里处理选中的文件，例如显示路径或打开文件
        qDebug() << "选中的文件:" << fileName;
        // 可以进一步用 QFile 操作该文件
    } else {
        qDebug() << "用户取消了选择";
        return;
    }

    // 2. 打开文件
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("错误"),
                             tr("无法打开文件：%1").arg(file.errorString()));
        return;
    }

    // 3. 读取内容（自动处理换行符）
    QTextStream stream(&file);
    QString content = stream.readAll();
    file.close();

    // 4. 显示到 QTextEdit
    ui->textEdit->setPlainText(content); // 如果是纯文本
}

void NoteBook::handleBtnClose()
{

}

void NoteBook::handleBtnSave()
{

}

void NoteBook::handleBtnNew()
{

}
