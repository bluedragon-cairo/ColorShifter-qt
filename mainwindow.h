#pragma once

#include <QMainWindow>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QFile>
#include <QPainter>
#include <QStyledItemDelegate>

#include "colorTools.h"
#include "palette.h"

#define PALETTE_MAX_PALETTES 30

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_previewColorCheckbox_stateChanged(int arg1);

    void on_hueRedSlider_valueChanged(int position);

    void on_satGreenSlider_valueChanged(int position);

    void on_valueBlueSlider_valueChanged(int position);

    void on_alphaSlider_valueChanged(int position);

    void on_hsvRadio_toggled(bool checked);

    void on_rgbRadio_toggled(bool checked);

    void on_randomizeColorButton_clicked();

    void on_removeColorButton_clicked();

    void on_addColorButton_clicked();

    void on_colorTable_itemSelectionChanged();

    void on_quitButton_clicked();

    void on_overrideCheckbox_toggled(bool checked);

    void on_balanceBox_valueChanged(int arg1);

    void on_loadPalettesButton_clicked();

    void on_savePalettesButton_clicked();

    void on_paletteTable_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    DwmColor initialDwmColor;
    int4 currentARGB;
    table <Palette> palettes;
    int n_palettes;

    void refreshDwmColor(void);

    void loadPalettes(QString loadFileName);
    void loadPalettesFromJSON(QJsonObject json);
    void savePalettes(QString saveFileName);
    QJsonObject savePalettesToJSON(void);

    void clearPaletteTable(void);
    void addAtPaletteTable(int row);
    void updateAtPaletteTable(int row);

    void clearColorTable(void);
    void fillColorTable(int index);
    void updateAtColorTable(int row);




public:
    void updateColorTableDragDrop(int dest, int src);
    void updatePaletteTableDragDrop(int dest, int src);


};

class TableBorderSelection : public QStyledItemDelegate
{
public:
    explicit TableBorderSelection(QObject *parent = 0) : QStyledItemDelegate(parent)
    {
    }

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        // keep background of colors
        QVariant background = index.data(Qt::BackgroundRole);
        if (background.canConvert<QBrush>()) {
            painter->fillRect(option.rect, background.value<QBrush>());
        }

        const QRect rect(option.rect);

        if(option.state & QStyle::State_Selected) {
            painter->save();
            QPen pen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
            painter->setPen(pen);
            painter->drawLine(rect.topLeft(), rect.topRight());
            painter->drawLine(rect.bottomLeft(), rect.bottomRight());

            if (index.column() == 0) { // leftmost
                painter->drawLine(rect.topLeft(), rect.bottomLeft());
            }
            if (index.column() == index.model()->columnCount()-1) {
                painter->drawLine(rect.topRight(), rect.bottomRight());
            }
            painter->restore();
        }

        QStyledItemDelegate::paint(painter, option, index);
    }
};
