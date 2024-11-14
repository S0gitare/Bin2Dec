#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn_0, &QPushButton::clicked, this, &MainWindow::inserir_bin);
    connect(ui->btn_1, &QPushButton::clicked, this, &MainWindow::inserir_bin);

    connect(ui->backspace, &QPushButton::clicked, this, &MainWindow::backspace);

    connect(ui->converter, &QPushButton::clicked, this, &MainWindow::resultado);

    connect(ui->btn_clear, &QPushButton::clicked, this, &MainWindow::clear);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inserir_bin(){
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button){
        QString numero_anterior = ui->painel_binario->text();
        numero_anterior = numero_anterior + button->text();
        ui->painel_binario->setText(numero_anterior);
    }
}
void MainWindow::backspace(){
    QString numero_anterior = ui->painel_binario->text();
    if (!numero_anterior.isEmpty()){
        numero_anterior.chop(1);
        ui->painel_binario->setText(numero_anterior);
    }
}
void MainWindow::clear(){
    ui->painel_binario->clear();
    ui->painel_decimal->clear();
}
void MainWindow::resultado(){

    QString binario = ui->painel_binario->text();
    int resultado = 0;
    int i;
    int base = 1;

    for (i=binario.size() - 1; i>=0; i--){
        if (binario[i] == '1'){
            resultado = resultado + base;
        }
        base = base * 2;
    }

    ui->painel_decimal->setText(QString::number(resultado));
}







