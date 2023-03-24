#include "money_waste.h"
#include "ui_money_waste.h"

Money_waste::Money_waste(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Money_waste)
{
    ui->setupUi(this);
    this->setWindowTitle("总用电量花费数据统计");
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    QBarSet *set0 = new QBarSet("正常总电量花费");
    QBarSet *set1 = new QBarSet("处理后总电量花费");
    *set0 <<2247.298581	<<2149.355<<	2066.271824<<	2017.63777<<	1920.369662<<	1877.814865<<	1822.426081<<	1940.633851<<	1999.4<<	2073.026554<<	2155.434257<<	2219.604189;
    *set1 <<1910.203794<<	1826.95175<<	1756.331051<<	1714.992105<<	1632.314213<<	1596.142635<<	1549.062169<<	1649.538774<<	1699.49<<	1762.072571<<	1832.119118<<	1886.663561;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("一年中电量价格对比图");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //设置x,y轴坐标轴名字
    //QValueAxis *axisx = new QValueAxis;

    //axisx->setTitleText("月份");

    //chart->setAxisX(axisx, series);

    QValueAxis *axisy = new QValueAxis;

    axisy->setTitleText("元");

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

Money_waste::~Money_waste()
{
    delete ui;
}
