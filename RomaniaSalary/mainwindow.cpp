#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator Salariu Romania 2018");}

MainWindow::~MainWindow()
{
    delete ui;
}

//Geters
 double MainWindow:: mGetWage() const
 {
     QString snap = this->ui->salariuInsert->text();
     double salariu = snap.toDouble();
     return salariu;
 }
double MainWindow::mGetAsigurareSanatate() const
{
    return mAsigurareSanatate;
}
double MainWindow:: mGetAsigurareSociala() const
{
    return mAsigurareSociala;
}
double MainWindow:: mGetImpozitVenit() const
{
    return mImpozitVenit;
}
double MainWindow:: mGetSalariuNet() const
{
    return mSalariuNet;
}
double MainWindow:: mGetDeducerePersoane() const
{
    return mDeducerePersoane;
}

//Seters

void MainWindow:: mSetWage(double k)
{
    mWage = k;
}


void MainWindow:: mSetAsigurareSanatate()
{
    mAsigurareSanatate = mWage * 0.1;
}

void MainWindow:: mSetAsigurareSociala()
{
    mAsigurareSociala = mWage * 0.25;
}

void MainWindow:: mSetImpozitVenit()
{
    mImpozitVenit = mWage * 0.1;
}







void MainWindow::on_pushButtonCalculeaza_clicked()
{
    QString salary = this->ui->salariuInsert->text();
    mWage =salary.toDouble();
    QString persons;
    if( !this->ui->spinNumarPersoane->text().isNull())
    {
        persons = this->ui->spinNumarPersoane->text();
        mNumberofPersons =persons.toInt();
    }
    double mWageAlias = mWage;

    mAsigurareSanatate = mWageAlias * 0.1;
    mAsigurareSociala = mWageAlias * 0.25;
    mImpozitVenit = mWageAlias * 0.1;

   if(mNumberofPersons > 4 && !this->ui->spinNumarPersoane->text().isNull())
       mDeducerePersoane = 650;
        else{
    switch (mNumberofPersons)
  {
    case 0:
      mDeducerePersoane=250;
      break;

    case 1:
       mDeducerePersoane=350;
        break;

    case 2:
        mDeducerePersoane=450;
        break;

    case 3:
        mDeducerePersoane=550;
        break;

    case 4:
        mDeducerePersoane=650;
        break;



   default:
       break;
   }
}
     mDeducereSpeciala = mDeducerePersoane*(1-(mWage - 1000 )/2000);

    if(mWage < 1000 )
    {
        mSalariuNet = mWage - mAsigurareSanatate - mAsigurareSociala - mImpozitVenit + mDeducerePersoane;
    }

    else if(mWage >= 1000 && mWage <= 3000){
        mSalariuNet =mWage - mAsigurareSanatate - mAsigurareSociala - mImpozitVenit + mDeducereSpeciala;
    }
    else if(mWage > 3000)
        mSalariuNet = mWage - mAsigurareSanatate - mAsigurareSociala - mImpozitVenit;

  //Create table

        ui->tableWidget->setColumnCount(2);
        ui->tableWidget->setRowCount(6);




        QStringList titleHorizontal, titleVertical;
        titleHorizontal<<"Procent"<<"RON";
        titleVertical<<"Salariu Brut"<<"Asigurare Sanatate"<<"Asigurare Sociala(CAS)"<<"Impozit pe venit"<<"Deducere persoanala"<<"Salariu NET";
        ui->tableWidget->setHorizontalHeaderLabels(titleHorizontal);
        ui->tableWidget->setVerticalHeaderLabels(titleVertical);

        ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString ::number(mWage)));

        ui->tableWidget->setItem(1,0,new QTableWidgetItem("10%"));
        ui->tableWidget->setItem(1,1,new QTableWidgetItem(QString ::number(mAsigurareSanatate)));

        ui->tableWidget->setItem(2,0,new QTableWidgetItem("25%"));
        ui->tableWidget->setItem(2,1,new QTableWidgetItem(QString ::number(mAsigurareSociala)));

        ui->tableWidget->setItem(3,0,new QTableWidgetItem("10%"));
        ui->tableWidget->setItem(3,1,new QTableWidgetItem(QString ::number(mImpozitVenit)));

        if(this->ui->spinNumarPersoane->text().isNull()){
           ui->tableWidget->setItem(4,1,new QTableWidgetItem('-'));
           ui->tableWidget->setItem(4,0,new QTableWidgetItem('-'));
        }
         else{
            if(mWage >= 1000 && mWage <= 3000)
                ui->tableWidget->setItem(4,1,new QTableWidgetItem(QString ::number(mDeducereSpeciala)));
            else if(mWage > 3000)
               ui->tableWidget->setItem(4,1,new QTableWidgetItem("0"));
            else
                ui->tableWidget->setItem(4,1,new QTableWidgetItem(QString ::number(mDeducerePersoane)));
        }
        ui->tableWidget->setItem(5,1,new QTableWidgetItem(QString ::number(mSalariuNet)));

}









