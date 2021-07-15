#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exece_clicked()
{       MainWindow::setWindowTitle("Processing.");
        QString filename1 = ui->fname->text();
        QByteArray xcs = filename1.toLocal8Bit();
        const char *filename = xcs.data();
        QString str = ui->sizef->text();
        bool ok;
        int size = str.toInt(&ok);
        int kbsize;
        int x;
        char cmd[1000];
        FILE * diskfile;
        diskfile = fopen (filename, "w");
        char none[255] = " ";
        kbsize = size * 13000;
        for(x=1;x != 0; x++) {
            if (x!=0) {
                fprintf(diskfile,  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");
            }
            if (x == kbsize) {
                fclose(diskfile);
                MainWindow::setWindowTitle("Done!");
                if (ui->fmat->isChecked() == true) {
                    MainWindow::setWindowTitle("Formating.");
                    if (ui->ext3->isChecked() != true) {
                    ui->ext4->setChecked(true);
                    }
                    if (ui->ext4->isChecked() == true){
                    strcpy (cmd, "mkfs.ext4");
                    }else if (ui->ext3->isChecked() == true) {
                    strcpy(cmd, "mkfs.ext3");
}
                    strcat (cmd, none);
                    strcat (cmd, filename);
                    system(cmd);
                    MainWindow::setWindowTitle("Done!");
                    return void(0);
                } else {
return void(0);
}


            }

        }

}
