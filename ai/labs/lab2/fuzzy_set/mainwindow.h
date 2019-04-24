#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ratingfuzzyset.h"

#define MAP_ROW 2
#define MAP_COL 7
#define COL_WIDTH 50

#define MTX_ROW MAP_COL
#define MTX_COL MAP_COL

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initValuesMap(void);
    void fillValuesMap(void);

    void initMtxTable(void);
    void findMtxVl(void);

    void initBlngTable(void);
    void fillBlngTable(void);

private slots:
    void on_pushButton_FillMatrix_clicked();

    void on_pushButton_Calculate_clicked();

    void on_pushButton_BuildGraph_clicked();

private:
    Ui::MainWindow *ui;
    RatingFuzzySet fsRating;
};
#endif // MAINWINDOW_H
