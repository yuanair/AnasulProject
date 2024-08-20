//
// Created by admin on 2024/8/20.
//

#pragma once

#include <QMainWindow>

namespace Anasul
{
	QT_BEGIN_NAMESPACE
	namespace Ui { class MainWindow; }
	QT_END_NAMESPACE
	
	class MainWindow : public QMainWindow
	{
		Q_OBJECT
	
	public:
		explicit MainWindow(QWidget *parent = nullptr);
		
		~MainWindow() override;
	
	private:
		Ui::MainWindow *ui;
	};
} // Anasul
