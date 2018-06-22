#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QButtonGroup>
#include <QDialog>
#include <QGridLayout>
#include <QList>
#include <QListWidget>
#include <QPainter>
#include <QPushButton>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QToolButton>
#include <QWidget>

#include "atombutton.h"
#include "defines.h"
#include "drawingcanvas.h"
#include "drawinginfo.h"

class Preferences : public QDialog
{
    Q_OBJECT

  public:
    Preferences(DrawingCanvas *d, int s);

    static QMap<QString, QVariant> _colorChanges;

  public slots:
    void savePreferences();
    void restoreDefaults();
    void revert();

  protected:
    int _drawingStyle;
    DrawingCanvas *_canvas;

    QWidget *_periodicTable;
    QList<QToolButton *> _atomButtons;

    QListWidget *_listWidget;
    QStackedWidget *_stackedWidget;
    QPushButton *_applyButton;
    QPushButton *_closeButton;
    QPushButton *_revertButton;

    QWidget *createPeriodicTable();
    QToolButton *makeAtomButton(const char *label);
};

#endif /* PREFERENCES_H */
