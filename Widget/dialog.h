#ifndef DIALOG_H
#define DIALOG_H
#include <QColorDialog>
#include <QDebug>
#include <QDialog>
#include <QFrame>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QtGui>
class Dialog : public QDialog {
    Q_OBJECT
  public:
    Dialog(QWidget *parent=0);//z合格地方必须等于0，不然会报错
    ~Dialog();
  private:
    QPushButton *colorBtn;
    QFrame *colorFrame;
    QGridLayout *mainLayout;
  public slots:
    QColor showColor();
  public:
    static QColor bridge(QColor tra);
};
#endif // DIALOG_H
