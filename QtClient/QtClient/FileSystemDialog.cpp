#include "FileSystemDialog.h"

FileSystemDialog::FileSystemDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QString path = "C:/";
	QStringList filters = QStringList() << "*.txt";
	dirmodel = new QFileSystemModel(this);
	filemodel = new QFileSystemModel(this);

	dirmodel->setRootPath(path);
	dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
	ui.dirView->setModel(dirmodel);

	filemodel->setRootPath(path);
	filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
	filemodel->setNameFilters(filters);
	ui.fileView->setModel(filemodel);

	connect(ui.dirView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(showFiles(const QModelIndex &)));
	connect(ui.fileView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(setPath(const QModelIndex &)));
	connect(ui.selectButton, SIGNAL(clicked()), this, SLOT(getPath()));
		
}

FileSystemDialog::~FileSystemDialog()
{
}


void FileSystemDialog::showFiles(const QModelIndex & index)
{

	QString spath = dirmodel->fileInfo(index).absoluteFilePath();
	ui.fileView->setRootIndex(filemodel->setRootPath(spath));

}

QString FileSystemDialog::getPath()
{	
	if (WarriorFile != 0l)
		return WarriorFile;
	else
		return "";
}

void FileSystemDialog::setPath(const QModelIndex & index)
{

	WarriorFile = filemodel->fileInfo(index).absoluteFilePath();

}