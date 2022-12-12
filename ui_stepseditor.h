/********************************************************************************
** Form generated from reading UI file 'stepseditor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEPSEDITOR_H
#define UI_STEPSEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StepsEditor
{
public:
    QGridLayout *gridLayout;
    QPushButton *addStepButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *stepList;
    QSpacerItem *verticalSpacer;
    QPushButton *saveButton;

    void setupUi(QWidget *StepsEditor)
    {
        if (StepsEditor->objectName().isEmpty())
            StepsEditor->setObjectName(QStringLiteral("StepsEditor"));
        StepsEditor->resize(738, 517);
        gridLayout = new QGridLayout(StepsEditor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        addStepButton = new QPushButton(StepsEditor);
        addStepButton->setObjectName(QStringLiteral("addStepButton"));

        gridLayout->addWidget(addStepButton, 1, 0, 1, 1);

        scrollArea = new QScrollArea(StepsEditor);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 718, 439));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stepList = new QVBoxLayout();
        stepList->setObjectName(QStringLiteral("stepList"));

        verticalLayout->addLayout(stepList);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        saveButton = new QPushButton(StepsEditor);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        gridLayout->addWidget(saveButton, 2, 0, 1, 1);


        retranslateUi(StepsEditor);

        QMetaObject::connectSlotsByName(StepsEditor);
    } // setupUi

    void retranslateUi(QWidget *StepsEditor)
    {
        StepsEditor->setWindowTitle(QApplication::translate("StepsEditor", "Form", nullptr));
        addStepButton->setText(QApplication::translate("StepsEditor", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\210\320\260\320\263", nullptr));
        saveButton->setText(QApplication::translate("StepsEditor", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StepsEditor: public Ui_StepsEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEPSEDITOR_H
