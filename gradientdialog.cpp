#include "gradientdialog.h"
#include "ui_gradientdialog.h"
#include "gradientmodel.h"
#include "colordelegate.h"
#include "stopdelegate.h"
#include "gradientscene.h"
#include <QLocale>

GradientDialog::GradientDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GradientDialog)
{
    ui->setupUi(this);
    init();
    setup();
    exampleGradient();
}

GradientDialog::~GradientDialog()
{
    delete ui;
}

QLinearGradient GradientDialog::gradient(double w, double h) const
{
    return m_gradientModel->gradient(w, h);
}

void GradientDialog::on_add_pushButton_clicked()
{
    m_gradientModel->addStop(0.0, Qt::black);
}

void GradientDialog::on_remove_pushButton_clicked()
{
    m_gradientModel->removeStop(ui->tableView->currentIndex().row());
}

void GradientDialog::on_buttonBox_accepted()
{
    accept();
}

void GradientDialog::on_buttonBox_rejected()
{
    reject();
}

void GradientDialog::init()
{
    m_gradientScene = new GradientScene(this);
    m_gradientModel = new GradientModel(this);
    m_colorDelegate = new ColorDelegate(this);
    m_stopDelegate = new StopDelegate(this);
}

void GradientDialog::setup()
{
    ui->resolution_comboBox->addItem("10x10", QSize(10, 10));
    ui->resolution_comboBox->addItem("25x25", QSize(25, 25));
    ui->resolution_comboBox->addItem("50x50", QSize(50, 50));
    ui->resolution_comboBox->addItem("100x100", QSize(100, 100));
    ui->resolution_comboBox->addItem("320x200", QSize(320, 200));
    ui->resolution_comboBox->addItem("320x240", QSize(320, 240));
    ui->resolution_comboBox->addItem("640x480", QSize(640, 480));
    ui->resolution_comboBox->addItem("768x576", QSize(768, 576));
    ui->resolution_comboBox->addItem("800x480", QSize(800, 480));
    ui->resolution_comboBox->addItem("800x600", QSize(800, 600));
    ui->resolution_comboBox->addItem("854x480", QSize(854, 480));
    ui->resolution_comboBox->addItem("1024x600", QSize(1024, 600));
    ui->resolution_comboBox->addItem("1024x768", QSize(1024, 768));
    m_gradientScene->setGradientModel(m_gradientModel);
    m_gradientScene->setResolutionComboBox(ui->resolution_comboBox);
    ui->graphicsView->setScene(m_gradientScene);
    ui->tableView->setModel(m_gradientModel);
    ui->tableView->setItemDelegateForColumn(0, m_stopDelegate);
    ui->tableView->setItemDelegateForColumn(1, m_colorDelegate);
    ui->tableView->setLocale(QLocale(QLocale::English));
}

void GradientDialog::exampleGradient()
{
    m_gradientModel->addStop(0.0, Qt::black);
    m_gradientModel->addStop(0.1, Qt::white);
    m_gradientModel->addStop(0.2, Qt::darkGray);
    m_gradientModel->addStop(0.3, Qt::lightGray);
    m_gradientModel->addStop(0.4, Qt::red);
    m_gradientModel->addStop(0.5, Qt::green);
    m_gradientModel->addStop(0.6, Qt::blue);
    m_gradientModel->addStop(0.7, Qt::cyan);
    m_gradientModel->addStop(0.8, Qt::magenta);
    m_gradientModel->addStop(0.9, Qt::yellow);
    m_gradientModel->addStop(1.0, Qt::darkYellow);
}

