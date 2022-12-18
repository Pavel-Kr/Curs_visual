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
    QLabel *numberLabel;
    QLabel *descLabel;
    QLabel *photoLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextButton;

    void setupUi(QWidget *StepsViewer)
    {
        if (StepsViewer->objectName().isEmpty())
            StepsViewer->setObjectName(QStringLiteral("StepsViewer"));
        StepsViewer->resize(596, 419);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ico/ico/recipe book.png"), QSize(), QIcon::Normal, QIcon::Off);
        StepsViewer->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(StepsViewer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        numberLabel = new QLabel(StepsViewer);
        numberLabel->setObjectName(QStringLiteral("numberLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numberLabel->sizePolicy().hasHeightForWidth());
        numberLabel->setSizePolicy(sizePolicy);
        numberLabel->setMinimumSize(QSize(30, 30));
        numberLabel->setStyleSheet(QStringLiteral(""));
        numberLabel->setAlignment(Qt::AlignCenter);
        numberLabel->setMargin(10);

        horizontalLayout_2->addWidget(numberLabel);

        descLabel = new QLabel(StepsViewer);
        descLabel->setObjectName(QStringLiteral("descLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(descLabel->sizePolicy().hasHeightForWidth());
        descLabel->setSizePolicy(sizePolicy1);
        descLabel->setMinimumSize(QSize(0, 30));
        descLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        descLabel->setWordWrap(true);
        descLabel->setMargin(10);

        horizontalLayout_2->addWidget(descLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        photoLabel = new QLabel(StepsViewer);
        photoLabel->setObjectName(QStringLiteral("photoLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(photoLabel->sizePolicy().hasHeightForWidth());
        photoLabel->setSizePolicy(sizePolicy2);
        photoLabel->setFrameShape(QFrame::Panel);
        photoLabel->setPixmap(QPixmap(QString::fromUtf8(":/ico/ico/camera.png")));
        photoLabel->setScaledContents(false);
        photoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(photoLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        prevButton = new QPushButton(StepsViewer);
        prevButton->setObjectName(QStringLiteral("prevButton"));

        horizontalLayout->addWidget(prevButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        nextButton = new QPushButton(StepsViewer);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout->addWidget(nextButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(StepsViewer);

        QMetaObject::connectSlotsByName(StepsViewer);
    } // setupUi

    void retranslateUi(QWidget *StepsViewer)
    {
        StepsViewer->setWindowTitle(QApplication::translate("StepsViewer", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\277\321\200\320\270\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        numberLabel->setText(QApplication::translate("StepsViewer", "1", nullptr));
        descLabel->setText(QApplication::translate("StepsViewer", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        photoLabel->setText(QString());
        prevButton->setText(QApplication::translate("StepsViewer", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \321\210\320\260\320\263", nullptr));
        nextButton->setText(QApplication::translate("StepsViewer", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271 \321\210\320\260\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StepsViewer: public Ui_StepsViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEPSVIEWER_H
