/********************************************************************************
** Form generated from reading UI file 'recipeviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIPEVIEWER_H
#define UI_RECIPEVIEWER_H

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

class Ui_RecipeViewer
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *photoLabel;
    QVBoxLayout *verticalLayout;
    QLabel *recipeNameLabel;
    QLabel *recipeDescriptionLabel;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QVBoxLayout *ingredientsList;
    QSpacerItem *verticalSpacer;
    QPushButton *toStepsViewerButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *recipeEditButton;
    QPushButton *recipeDeleteButton;

    void setupUi(QWidget *RecipeViewer)
    {
        if (RecipeViewer->objectName().isEmpty())
            RecipeViewer->setObjectName(QStringLiteral("RecipeViewer"));
        RecipeViewer->resize(645, 440);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RecipeViewer->sizePolicy().hasHeightForWidth());
        RecipeViewer->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(RecipeViewer);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        photoLabel = new QLabel(RecipeViewer);
        photoLabel->setObjectName(QStringLiteral("photoLabel"));
        photoLabel->setMinimumSize(QSize(150, 150));
        photoLabel->setMaximumSize(QSize(150, 150));
        photoLabel->setFrameShape(QFrame::Panel);
        photoLabel->setAlignment(Qt::AlignCenter);
        photoLabel->setMargin(0);

        horizontalLayout->addWidget(photoLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        recipeNameLabel = new QLabel(RecipeViewer);
        recipeNameLabel->setObjectName(QStringLiteral("recipeNameLabel"));

        verticalLayout->addWidget(recipeNameLabel);

        recipeDescriptionLabel = new QLabel(RecipeViewer);
        recipeDescriptionLabel->setObjectName(QStringLiteral("recipeDescriptionLabel"));
        sizePolicy.setHeightForWidth(recipeDescriptionLabel->sizePolicy().hasHeightForWidth());
        recipeDescriptionLabel->setSizePolicy(sizePolicy);
        recipeDescriptionLabel->setWordWrap(true);

        verticalLayout->addWidget(recipeDescriptionLabel);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_4 = new QLabel(RecipeViewer);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setPointSize(11);
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        ingredientsList = new QVBoxLayout();
        ingredientsList->setObjectName(QStringLiteral("ingredientsList"));

        verticalLayout_2->addLayout(ingredientsList);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        toStepsViewerButton = new QPushButton(RecipeViewer);
        toStepsViewerButton->setObjectName(QStringLiteral("toStepsViewerButton"));

        verticalLayout_2->addWidget(toStepsViewerButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        recipeEditButton = new QPushButton(RecipeViewer);
        recipeEditButton->setObjectName(QStringLiteral("recipeEditButton"));

        horizontalLayout_2->addWidget(recipeEditButton);

        recipeDeleteButton = new QPushButton(RecipeViewer);
        recipeDeleteButton->setObjectName(QStringLiteral("recipeDeleteButton"));

        horizontalLayout_2->addWidget(recipeDeleteButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(RecipeViewer);

        QMetaObject::connectSlotsByName(RecipeViewer);
    } // setupUi

    void retranslateUi(QWidget *RecipeViewer)
    {
        RecipeViewer->setWindowTitle(QApplication::translate("RecipeViewer", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\261\320\273\321\216\320\264\320\260", nullptr));
        photoLabel->setText(QApplication::translate("RecipeViewer", "\320\244\320\276\321\202\320\276 \321\200\320\265\321\206\320\265\320\277\321\202\320\260", nullptr));
        recipeNameLabel->setText(QApplication::translate("RecipeViewer", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\200\320\265\321\206\320\265\320\277\321\202\320\260", nullptr));
        recipeDescriptionLabel->setText(QApplication::translate("RecipeViewer", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \321\200\320\265\321\206\320\265\320\277\321\202\320\260", nullptr));
        label_4->setText(QApplication::translate("RecipeViewer", "\320\230\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\213", nullptr));
        toStepsViewerButton->setText(QApplication::translate("RecipeViewer", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \320\277\321\200\320\270\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\216", nullptr));
        recipeEditButton->setText(QApplication::translate("RecipeViewer", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        recipeDeleteButton->setText(QApplication::translate("RecipeViewer", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecipeViewer: public Ui_RecipeViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIPEVIEWER_H
