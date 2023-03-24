#include "low_waste.h"
#include "ui_low_waste.h"

Low_waste::Low_waste(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Low_waste)
{
    ui->setupUi(this);
    this->setWindowTitle("非高峰用电量数据统计");
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    QBarSet *set0 = new QBarSet("非高峰正常");
    QBarSet *set1 = new QBarSet("非高峰处理后");
    *set0 <<2225<< 	2129<< 	2046<< 	1998<< 	1902<< 	1860<< 	1805<< 	1922<< 	1980<< 	2053<< 	2135<< 	2198;


    *set1 <<1892<<	1809<<	1739<<	1698<<	1616<<	1581<<	1534<<	1634<<	1683<<	1745<<	1814<<	1868;



    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("一年中非高峰用电量对比图");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //设置x,y轴坐标轴名字
    //QValueAxis *axisx = new QValueAxis;

    //axisx->setTitleText("月份");

    //chart->setAxisX(axisx, series);

    QValueAxis *axisy = new QValueAxis;

    axisy->setTitleText("耗电量(KWH)");

    chart->setAxisY(axisy,series);

//![3]

//![4]
    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "July" << "Aug" << "Sept" << "Ocr" <<"Nove" << "Dec";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
    chart->setAxisX(axis, series);//设置坐标轴
//![4]

//![5]
    chart->legend()->setVisible(true); //设置图例为显示状态
    chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部

    chart->setTheme(QChart::ChartThemeBlueCerulean);//设置背景
//![5]

//![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    this->setCentralWidget(chartView);
    this->resize(800, 600);
}

Low_waste::~Low_waste()
{
    delete ui;
}
