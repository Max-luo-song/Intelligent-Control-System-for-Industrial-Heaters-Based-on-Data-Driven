#include "high_waste.h"
#include "ui_high_waste.h"

High_waste::High_waste(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::High_waste)
{
    ui->setupUi(this);
    this->setWindowTitle("高峰用电量数据统计");
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    QBarSet *set0 = new QBarSet("高峰正常");
    QBarSet *set1 = new QBarSet("高峰处理后");
    *set0 <<1102<< 	1054<< 	1013<< 	989<< 	941<< 	920<< 	893<< 	951<< 	980<< 	1016<< 	1056 <<1088;
    *set1 <<936<<	895<<	861<<	841<<	800<<	782<<	759<<	809<<	833<<	864<<	898<< 925;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("一年中高峰用电量对比图");
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

High_waste::~High_waste()
{
    delete ui;
}
