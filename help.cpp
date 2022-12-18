#include "help.h"
#include "ui_help.h"
#include <QtWidgets>

Help::Help(const QString &strPath, const QString &fileName, QWidget *parent) : QWidget(parent), ui(new Ui::Help)
{
    ui->setupUi(this);
    QPushButton *pcmdBack = new QPushButton("<<");
    QPushButton *pcmdHome = new QPushButton("Home");
    QPushButton *pcmdForward = new QPushButton(">>");
    QTextBrowser *ptxtBrowser = new QTextBrowser;

    connect(pcmdBack,SIGNAL(clicked()),ptxtBrowser,SLOT(backward()));
    connect(pcmdHome,SIGNAL(clicked()),ptxtBrowser,SLOT(home()));
    connect(pcmdForward,SIGNAL(clicked()),ptxtBrowser,SLOT(forward()));
    connect(ptxtBrowser,SIGNAL(backwardAvailable(bool)),pcmdBack,SLOT(setEnabled(bool)));
    connect(ptxtBrowser,SIGNAL(forwardAvailable(bool)),pcmdForward,SLOT(setEnabled(bool)));

    ptxtBrowser->setSearchPaths(QStringList() << strPath);
    ptxtBrowser->setSource(QString(fileName));

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    QHBoxLayout *phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(pcmdBack);
    phbxLayout->addWidget(pcmdHome);
    phbxLayout->addWidget(pcmdForward);
    pvbxLayout->addLayout(phbxLayout);
    pvbxLayout->addWidget(ptxtBrowser);
    setLayout(pvbxLayout);
    setProperty("window",true);
}

Help::~Help()
{
    delete ui;
}
