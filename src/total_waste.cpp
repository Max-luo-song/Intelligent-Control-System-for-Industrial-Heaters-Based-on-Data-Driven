#include "total_waste.h"
#include "ui_total_waste.h"

Total_waste::Total_waste(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Total_waste)
{
    ui->setupUi(this);
    this->setWindowTitle("总用电量数据统计");
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    QBarSet *set0 = new QBarSet("正常总用电量");
    QBarSet *set1 = new QBarSet("处理后总用电量");
    *set0 <<3327<< 	3182<< 	3059<< 	2987<< 	2843<< 	2780<< 	2698<< 	2873<< 	2960<<	3069<< 	3191<< 	3286;

    *set1 <<2828<<	2705<<	2600<<	2539<<	2417<<	2363<<	2293<<	2442<<	2516<<	2609<<	2712<<	2793;


    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("一年中总用电量对比图");
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

Total_waste::~Total_waste()
{
    delete ui;
}
