#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initValuesMap();
    initMtxTable();
    initBlngTable();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMtxTable()
{
    ui->tableWidget_Matrix->setRowCount(MTX_ROW);
    ui->tableWidget_Matrix->setColumnCount(MTX_COL);
    QStringList hzHeaders = QStringList()<<"Rating"<<
                                                   "50"<<
                                                   "60"<<
                                                   "70"<<
                                                   "80"<<
                                                   "90"<<
                                                   "100";
    QStringList vtHeaders = QStringList()<<"Rating"<<
                                                    "50"<<
                                                    "60"<<
                                                    "70"<<
                                                    "80"<<
                                                    "90"<<
                                                    "100";
    ui->tableWidget_Matrix->setHorizontalHeaderLabels(hzHeaders);
    ui->tableWidget_Matrix->setVerticalHeaderLabels(vtHeaders);
//    ui->tableWidget_Matrix->setItem(0, 0, new QTableWidgetItem("Rating"));
}

void MainWindow::findMtxVl()
{

}

void MainWindow::initBlngTable()
{
    ui->tableWidget_BelongValues->setRowCount(MAP_ROW);
    ui->tableWidget_BelongValues->setColumnCount(MAP_COL);
    int iWidth = 446/7;//ui->tableWidget_BelongValues->width()/MAP_COL;
    for(int i = 1; i<MAP_COL; ++i){
        ui->tableWidget_BelongValues->setColumnWidth(i, iWidth);
    }
    QStringList hzHeaders = QStringList()<<"Rating"<<
                                                   "50"<<
                                                   "60"<<
                                                   "70"<<
                                                   "80"<<
                                                   "90"<<
                                                   "100";
    ui->tableWidget_BelongValues->setHorizontalHeaderLabels(hzHeaders);
}

void MainWindow::initValuesMap()
{
   // ui->tableWidget_ValuesMap->columnWidth(COL_WIDTH);
    ui->tableWidget_ValuesMap->setRowCount(MAP_ROW);
    ui->tableWidget_ValuesMap->setColumnCount(MAP_COL);
    ui->tableWidget_ValuesMap->setItem(0, 0, new QTableWidgetItem("Rating"));
    ui->tableWidget_ValuesMap->setItem(1, 0, new QTableWidgetItem("Assesment"));
}

void MainWindow::fillValuesMap()
{
    initValuesMap();
    map<eRating, eAdvantages> tempMap = fsRating.getMapValues();
    map<eRating, eAdvantages>::iterator it = tempMap.begin();

    for(int i = 1; i<MAP_COL; ++i){
        ui->tableWidget_ValuesMap->setItem(0,i,
           new QTableWidgetItem(QString::number( it->first )));
        ui->tableWidget_ValuesMap->setItem(1,i,
           new QTableWidgetItem(QString::number( it->second )));
        ui->tableWidget_ValuesMap->setColumnWidth(i, ui->tableWidget_ValuesMap->width()/MAP_COL-3);
        if(it == tempMap.end())
            break;
        else
            it++;
    }
}

void MainWindow::on_pushButton_FillMatrix_clicked()
{
    array<array<float, ELEMENTS>, ELEMENTS> arrMtx = fsRating.calculateMtxVls();
    for(int i = 0; i<ELEMENTS; ++i){
        for(int j = 0; j<ELEMENTS; ++j){
            ui->tableWidget_Matrix->setItem(i+1, j+1,
                                            new QTableWidgetItem(QString::number(arrMtx[i][j])));
        }
    }
}

void MainWindow::on_pushButton_Calculate_clicked()
{
    map<eRating, float> mapBlngVls = fsRating.calculateBlngValues();
    map<eRating, float>::iterator it = mapBlngVls.begin();
    float fMaxVal = mapBlngVls[MAXIMAL];
    for(int i = 0; i<ELEMENTS; ++i){
        ui->tableWidget_BelongValues->setItem(0, i+1,
                                new QTableWidgetItem(QString::number(it->second)));
        ui->tableWidget_BelongValues->setItem(1, i+1,
                                new QTableWidgetItem(QString::number(
                                                    (it->second)/fMaxVal)
                                                     )
                                              );
        ++it;
    }
}



void MainWindow::on_pushButton_BuildGraph_clicked()
{
    QCustomPlot *qCustomPlot = new QCustomPlot();
    qCustomPlot->setFixedWidth(600);
    qCustomPlot->setFixedHeight(500);
    map<eRating, float> mapBlngsVls = fsRating.calculateBlngValues();
    QVector<double> vecX, vecY;
    map<eRating, float>::iterator it = mapBlngsVls.begin();
    for(int i = 0; i<ELEMENTS; ++i){
        vecX.push_back(it->first);
        vecY.push_back(it->second);
        ++it;
    }
    qCustomPlot->addGraph();
    qCustomPlot->graph(0)->setPen(QPen(Qt::blue));
    qCustomPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    qCustomPlot->graph(0)->setScatterStyle(
                QCPScatterStyle(
                    QCPScatterStyle::ssCircle,
                    QPen(Qt::black, 1.5),
                    QBrush(Qt::white), 9)
                );
    qCustomPlot->graph()->addData(vecX, vecY);
    qCustomPlot->replot();
    qCustomPlot->show();
    // give the axes some labels:
    qCustomPlot->xAxis->setLabel("Rating");
    qCustomPlot->yAxis->setLabel("Belong function value");
    // set axes ranges, so we see all data:
    qCustomPlot->xAxis->setRange(0, 100);
    qCustomPlot->yAxis->setRange(0, 1);
    qCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}
