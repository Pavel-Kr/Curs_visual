/********************************************************************************
** Form generated from reading UI file 'recipebook.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIPEBOOK_H
#define UI_RECIPEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecipeBook
{
public:
    QAction *helpAction;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchBar;
    QHBoxLayout *horizontalLayout;
    QRadioButton *searchByNameRB;
    QRadioButton *searchByIngredientRB;
    QListWidget *recipeList;
    QPushButton *addRecipeButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RecipeBook)
    {
        if (RecipeBook->objectName().isEmpty())
            RecipeBook->setObjectName(QStringLiteral("RecipeBook"));
        RecipeBook->resize(655, 510);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ico/ico/recipe book.png"), QSize(), QIcon::Normal, QIcon::Off);
        RecipeBook->setWindowIcon(icon);
        RecipeBook->setStyleSheet(QStringLiteral(""));
        helpAction = new QAction(RecipeBook);
        helpAction->setObjectName(QStringLiteral("helpAction"));
        centralWidget = new QWidget(RecipeBook);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        searchBar = new QLineEdit(centralWidget);
        searchBar->setObjectName(QStringLiteral("searchBar"));

        verticalLayout->addWidget(searchBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        searchByNameRB = new QRadioButton(centralWidget);
        searchByNameRB->setObjectName(QStringLiteral("searchByNameRB"));

        horizontalLayout->addWidget(searchByNameRB);

        searchByIngredientRB = new QRadioButton(centralWidget);
        searchByIngredientRB->setObjectName(QStringLiteral("searchByIngredientRB"));

        horizontalLayout->addWidget(searchByIngredientRB);


        verticalLayout->addLayout(horizontalLayout);

        recipeList = new QListWidget(centralWidget);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(255, 189, 55, 255));
        brush1.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(recipeList);
        __qlistwidgetitem->setBackground(brush1);
        __qlistwidgetitem->setForeground(brush);
        recipeList->setObjectName(QStringLiteral("recipeList"));
        recipeList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        recipeList->setIconSize(QSize(150, 125));
        recipeList->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        recipeList->setWordWrap(false);

        verticalLayout->addWidget(recipeList);

        addRecipeButton = new QPushButton(centralWidget);
        addRecipeButton->setObjectName(QStringLiteral("addRecipeButton"));
        addRecipeButton->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(addRecipeButton);

        RecipeBook->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RecipeBook);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 655, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        RecipeBook->setMenuBar(menuBar);
        statusBar = new QStatusBar(RecipeBook);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RecipeBook->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(helpAction);

        retranslateUi(RecipeBook);

        QMetaObject::connectSlotsByName(RecipeBook);
    } // setupUi

    void retranslateUi(QMainWindow *RecipeBook)
    {
        RecipeBook->setWindowTitle(QApplication::translate("RecipeBook", "\320\234\320\276\320\270 \321\200\320\265\321\206\320\265\320\277\321\202\321\213", nullptr));
        helpAction->setText(QApplication::translate("RecipeBook", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
#ifndef QT_NO_SHORTCUT
        helpAction->setShortcut(QApplication::translate("RecipeBook", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        searchBar->setPlaceholderText(QApplication::translate("RecipeBook", "\320\237\320\276\320\270\321\201\320\272...", nullptr));
        searchByNameRB->setText(QApplication::translate("RecipeBook", "\320\237\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216", nullptr));
        searchByIngredientRB->setText(QApplication::translate("RecipeBook", "\320\237\320\276 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\203", nullptr));

        const bool __sortingEnabled = recipeList->isSortingEnabled();
        recipeList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = recipeList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("RecipeBook", "Test\n"
"\n"
"Test desc", nullptr));
        recipeList->setSortingEnabled(__sortingEnabled);

        addRecipeButton->setText(QApplication::translate("RecipeBook", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        menu->setTitle(QApplication::translate("RecipeBook", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecipeBook: public Ui_RecipeBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIPEBOOK_H
