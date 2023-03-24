/*
 * 读取txt文档参考博客：https://blog.csdn.net/weixin_42692504/article/details/96917841
 */
#include "learn_self.h"
#include "ui_learn_self.h"

float a[5225];

Learn_self::Learn_self(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Learn_self)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowTitle("自学习炉温-时间曲线图");
    QChartView * _chart_view = new QChartView;

       this->setCentralWidget(_chart_view);

        //自定义背景
       //_chart_view->chart()->setBackgroundVisible(false);
       //setStyleSheet(R"(QGraphicsView{ background-image:url(:/tubiao/33.png);})");
       /* 以下代码完成曲线添加 */

       QLineSeries *seriesx = new QLineSeries();
       getData();
       for(int i=1;i<=5223;i=i+1) {

          seriesx->append(i,a[i]);

       }
       _chart_view->chart()->addSeries(seriesx);


      //chart的背景和ui文件的背景不同
       _chart_view->chart()->setTheme(QChart::ChartThemeBlueCerulean);
       //_chart_view->chart()->setTheme(QChart::Ch)

       seriesx->setName("炉温点");

       _chart_view->chart()->setTitle("自学习炉温-时间变化图");

       //设置x,y轴坐标轴名字
       QValueAxis *axisx = new QValueAxis;

       axisx->setTitleText("时间S(s)");

       _chart_view->chart()->setAxisX(axisx, seriesx);

       QValueAxis *axisy = new QValueAxis;

       axisy->setTitleText("炉温T(℃)");

       _chart_view->chart()->setAxisY(axisy,seriesx);

       _chart_view->chart()->legend()->setVisible(true);

       _chart_view->chart()->legend()->setAlignment(Qt::AlignBottom);//将线名放于底部
       this->resize(800, 600);
}

Learn_self::~Learn_self()
{
    delete ui;
}

void Learn_self::getData()
{
    int i = 1;
    QFile file("/home/loongson/桌面/heatcold.txt");    //文件路径,如果上板子要更换成另外操作系统的数据路径
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
          qDebug()<<"Can't open the file!";
          return;
     }
     QTextStream in(&file);  //文件流
     QString line = in.readLine() ;   //读取一行
     while (!line.isNull())
     {
         line = in.readLine();
         a[i] = line.toFloat();
         i = i+1;
     }
}
