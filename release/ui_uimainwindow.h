/********************************************************************************
** Form generated from reading UI file 'uimainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIMAINWINDOW_H
#define UI_UIMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIMainWindow
{
public:
    QWidget *centralWidget;
    QSplitter *splitter;
    QSplitter *top;
    QLabel *Display;
    QGroupBox *checkGroup;
    QSplitter *buttom;
    QPushButton *browseButton;
    QPushButton *saveButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UIMainWindow)
    {
        if (UIMainWindow->objectName().isEmpty())
            UIMainWindow->setObjectName(QStringLiteral("UIMainWindow"));
        UIMainWindow->resize(961, 577);
        centralWidget = new QWidget(UIMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 0, 931, 511));
        splitter->setOrientation(Qt::Vertical);
        top = new QSplitter(splitter);
        top->setObjectName(QStringLiteral("top"));
        top->setOrientation(Qt::Horizontal);
        Display = new QLabel(top);
        Display->setObjectName(QStringLiteral("Display"));
        Display->setMinimumSize(QSize(800, 400));
        Display->setMaximumSize(QSize(800, 600));
        top->addWidget(Display);
        checkGroup = new QGroupBox(top);
        checkGroup->setObjectName(QStringLiteral("checkGroup"));
        top->addWidget(checkGroup);
        splitter->addWidget(top);
        buttom = new QSplitter(splitter);
        buttom->setObjectName(QStringLiteral("buttom"));
        buttom->setOrientation(Qt::Horizontal);
        browseButton = new QPushButton(buttom);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        buttom->addWidget(browseButton);
        saveButton = new QPushButton(buttom);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        buttom->addWidget(saveButton);
        splitter->addWidget(buttom);
        UIMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UIMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 961, 19));
        UIMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UIMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        UIMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UIMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        UIMainWindow->setStatusBar(statusBar);

        retranslateUi(UIMainWindow);

        QMetaObject::connectSlotsByName(UIMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UIMainWindow)
    {
        UIMainWindow->setWindowTitle(QApplication::translate("UIMainWindow", "ImageConcat", Q_NULLPTR));
        Display->setText(QString());
        checkGroup->setTitle(QApplication::translate("UIMainWindow", "Options", Q_NULLPTR));
        browseButton->setText(QApplication::translate("UIMainWindow", "Browse", Q_NULLPTR));
        saveButton->setText(QApplication::translate("UIMainWindow", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UIMainWindow: public Ui_UIMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIMAINWINDOW_H
