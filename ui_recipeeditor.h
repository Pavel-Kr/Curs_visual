/********************************************************************************
** Form generated from reading UI file 'recipeeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIPEEDITOR_H
#define UI_RECIPEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "droplabel.h"

QT_BEGIN_NAMESPACE

class Ui_RecipeEditor
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    DropLabel *photoLabel;
    QVBoxLayout *verticalLayout;
    QLineEdit *recipeNameEdit;
    QPlainTextEdit *descriptionEdit;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *ingredientsList;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addIngredientButton;
    QPushButton *stepsEditButton;

    void setupUi(QWidget *RecipeEditor)
    {
        if (RecipeEditor->objectName().isEmpty())
            RecipeEditor->setObjectName(QStringLiteral("RecipeEditor"));
        RecipeEditor->resize(680, 517);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ico/ico/recipe book.png"), QSize(), QIcon::Normal, QIcon::Off);
        RecipeEditor->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(RecipeEditor);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        photoLabel = new DropLabel(RecipeEditor);
        photoLabel->setObjectName(QStringLiteral("photoLabel"));
        photoLabel->setMinimumSize(QSize(150, 100));
        photoLabel->setMaximumSize(QSize(150, 125));
        photoLabel->setAcceptDrops(true);
        photoLabel->setFrameShape(QFrame::Panel);
        photoLabel->setPixmap(QPixmap(QString::fromUtf8(":/ico/ico/camera.png")));
        photoLabel->setAlignment(Qt::AlignCenter);
        photoLabel->setMargin(0);

        horizontalLayout->addWidget(photoLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        recipeNameEdit = new QLineEdit(RecipeEditor);
        recipeNameEdit->setObjectName(QStringLiteral("recipeNameEdit"));

        verticalLayout->addWidget(recipeNameEdit);

        descriptionEdit = new QPlainTextEdit(RecipeEditor);
        descriptionEdit->setObjectName(QStringLiteral("descriptionEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(descriptionEdit->sizePolicy().hasHeightForWidth());
        descriptionEdit->setSizePolicy(sizePolicy);
        descriptionEdit->setBaseSize(QSize(0, 0));

        verticalLayout->addWidget(descriptionEdit);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        label_2 = new QLabel(RecipeEditor);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        scrollArea = new QScrollArea(RecipeEditor);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 660, 310));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        ingredientsList = new QVBoxLayout();
        ingredientsList->setObjectName(QStringLiteral("ingredientsList"));

        gridLayout->addLayout(ingredientsList, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addIngredientButton = new QPushButton(RecipeEditor);
        addIngredientButton->setObjectName(QStringLiteral("addIngredientButton"));

        verticalLayout_2->addWidget(addIngredientButton);

        stepsEditButton = new QPushButton(RecipeEditor);
        stepsEditButton->setObjectName(QStringLiteral("stepsEditButton"));

        verticalLayout_2->addWidget(stepsEditButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(RecipeEditor);

        QMetaObject::connectSlotsByName(RecipeEditor);
    } // setupUi

    void retranslateUi(QWidget *RecipeEditor)
    {
        RecipeEditor->setWindowTitle(QApplication::translate("RecipeEditor", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        photoLabel->setText(QString());
        recipeNameEdit->setPlaceholderText(QApplication::translate("RecipeEditor", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\200\320\265\321\206\320\265\320\277\321\202\320\260", nullptr));
        descriptionEdit->setPlaceholderText(QApplication::translate("RecipeEditor", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \321\200\320\265\321\206\320\265\320\277\321\202\320\260", nullptr));
        label_2->setText(QApplication::translate("RecipeEditor", "\320\230\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\213", nullptr));
        addIngredientButton->setText(QApplication::translate("RecipeEditor", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202", nullptr));
        stepsEditButton->setText(QApplication::translate("RecipeEditor", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270 \320\277\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \320\277\321\200\320\270\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecipeEditor: public Ui_RecipeEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIPEEDITOR_H
