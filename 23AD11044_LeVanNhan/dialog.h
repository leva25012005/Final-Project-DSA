#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <qgraphicsview.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QGraphicsView* graphicsView;  // QGraphicsView để hiển thị biểu đồ
    QGraphicsScene* scene;        // Scene để chứa đồ họa
};

#endif // DIALOG_H
