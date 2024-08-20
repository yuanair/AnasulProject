//
// Created by admin on 2024/8/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.hpp"
#include "ui_MainWindow.h"

namespace Anasul
{
	MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::MainWindow)
	{
		ui->setupUi(this);
	}
	
	MainWindow::~MainWindow()
	{
		delete ui;
	}
} // Anasul
