/********************************************************************************
** Form generated from reading UI file 'stepsviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEPSVIEWER_H
#define UI_STEPSVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StepsViewer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QWidget *StepsViewer)
    {
        if (StepsViewer->objectName().isEmpty())
            StepsViewer->setObjectName(QStringLiteral("StepsViewer"));
        StepsViewer->resize(732, 496);
        verticalLayout = new QVBoxLayout(StepsViewer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(StepsViewer);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setMargin(10);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(StepsViewer);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 100));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(StepsViewer);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFrameShape(QFrame::Panel);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(StepsViewer);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(StepsViewer);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(StepsViewer);

        QMetaObject::connectSlotsByName(StepsViewer);
    } // setupUi

    void retranslateUi(QWidget *StepsViewer)
    {
        StepsViewer->setWindowTitle(QApplication::translate("StepsViewer", "Form", nullptr));
        label->setText(QApplication::translate("StepsViewer", "1", nullptr));
        label_2->setText(QApplication::translate("StepsViewer", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        label_3->setText(QApplication::translate("StepsViewer", "\320\244\320\276\321\202\320\276", nullptr));
        pushButton->setText(QApplication::translate("StepsViewer", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \321\210\320\260\320\263", nullptr));
        pushButton_2->setText(QApplication::translate("StepsViewer", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271 \321\210\320\260\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StepsViewer: public Ui_StepsViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEPSVIEWER_H
