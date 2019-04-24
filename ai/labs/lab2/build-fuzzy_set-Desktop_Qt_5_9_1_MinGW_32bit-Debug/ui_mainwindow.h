/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_Buttons;
    QTableWidget *tableWidget_BelongValues;
    QPushButton *pushButton_FillMatrix;
    QPushButton *pushButton_Calculate;
    QPushButton *pushButton_BuildGraph;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_Matrix;
    QTableWidget *tableWidget_Matrix;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_ValuesMap;
    QTableWidget *tableWidget_ValuesMap;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(698, 548);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 400, 691, 101));
        horizontalLayout_Buttons = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_Buttons->setSpacing(6);
        horizontalLayout_Buttons->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_Buttons->setObjectName(QStringLiteral("horizontalLayout_Buttons"));
        horizontalLayout_Buttons->setContentsMargins(0, 0, 0, 0);
        tableWidget_BelongValues = new QTableWidget(horizontalLayoutWidget);
        tableWidget_BelongValues->setObjectName(QStringLiteral("tableWidget_BelongValues"));

        horizontalLayout_Buttons->addWidget(tableWidget_BelongValues);

        pushButton_FillMatrix = new QPushButton(horizontalLayoutWidget);
        pushButton_FillMatrix->setObjectName(QStringLiteral("pushButton_FillMatrix"));

        horizontalLayout_Buttons->addWidget(pushButton_FillMatrix);

        pushButton_Calculate = new QPushButton(horizontalLayoutWidget);
        pushButton_Calculate->setObjectName(QStringLiteral("pushButton_Calculate"));

        horizontalLayout_Buttons->addWidget(pushButton_Calculate);

        pushButton_BuildGraph = new QPushButton(horizontalLayoutWidget);
        pushButton_BuildGraph->setObjectName(QStringLiteral("pushButton_BuildGraph"));

        horizontalLayout_Buttons->addWidget(pushButton_BuildGraph);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 110, 691, 281));
        verticalLayout_Matrix = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_Matrix->setSpacing(6);
        verticalLayout_Matrix->setContentsMargins(11, 11, 11, 11);
        verticalLayout_Matrix->setObjectName(QStringLiteral("verticalLayout_Matrix"));
        verticalLayout_Matrix->setContentsMargins(0, 0, 0, 0);
        tableWidget_Matrix = new QTableWidget(verticalLayoutWidget);
        tableWidget_Matrix->setObjectName(QStringLiteral("tableWidget_Matrix"));

        verticalLayout_Matrix->addWidget(tableWidget_Matrix);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 10, 691, 91));
        verticalLayout_ValuesMap = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_ValuesMap->setSpacing(6);
        verticalLayout_ValuesMap->setContentsMargins(11, 11, 11, 11);
        verticalLayout_ValuesMap->setObjectName(QStringLiteral("verticalLayout_ValuesMap"));
        verticalLayout_ValuesMap->setContentsMargins(0, 0, 0, 0);
        tableWidget_ValuesMap = new QTableWidget(verticalLayoutWidget_2);
        tableWidget_ValuesMap->setObjectName(QStringLiteral("tableWidget_ValuesMap"));
        tableWidget_ValuesMap->setAutoScroll(false);

        verticalLayout_ValuesMap->addWidget(tableWidget_ValuesMap);

        MainWindow->setCentralWidget(centralWidget);
        horizontalLayoutWidget->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        tableWidget_ValuesMap->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 698, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_FillMatrix->setText(QApplication::translate("MainWindow", "Fill Matrix", Q_NULLPTR));
        pushButton_Calculate->setText(QApplication::translate("MainWindow", "Calculate", Q_NULLPTR));
        pushButton_BuildGraph->setText(QApplication::translate("MainWindow", "Build Graph", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
