#include "style_list_widget.hpp"

namespace e0fe {

namespace styles {

    void StyleListWidget::replaceStyleSheet(QRegularExpression &regex, QString str)
    {
        qDebug() << "str = " << str;
        auto i = regex.match(mStyleSheet).capturedEnd();
        auto j = i;

        for (; mStyleSheet[i] != ';'; ++i);

        mStyleSheet.replace(j, i-j, str);
        mStyleSheetCopy = mStyleSheet;
        apply();
    }

    void StyleListWidget::setMargins(QRegularExpression &regex, const QMargins &margin)
    {
        QString temp = QString::number(margin.left()) + " " +
                QString::number(margin.top()) + " " +
                QString::number(margin.right()) + " " +
                QString::number(margin.bottom());

        replaceStyleSheet(regex, temp);
    }

    StyleListWidget::StyleListWidget(QListWidget *listWidget): mListWidget(listWidget)
    {

    }

    void StyleListWidget::setStyleSheetBlue()
    {
        QColor colorListWidgetBackground(0x78,0x72,0xD8);
        QColor colorListWidgetItemBackground(0x43,0x7D,0xD4);
        QColor colorListWidgetItemSelectedBorder(0x00,0x63,0x63);

        mStyleSheet = QString{"QListWidget {"
                                  "background: %1;"
                                  "margin: 10 5 10 5;"
                              "}"
                              "QListWidget::item {"
                                  "background: %2;"
                                  "border-width: none;"
                                  "border-radius: 5;"
                                  "margin: 5 20 5 20;"
                                  "padding: 2 3 2 3;"
                              "}"
                              "QListWidget::item:selected {"
                                  "show-decoration-selected: 1;"
                                  "selection-background-color: %3;"
                                  "border-width: 12"
                                  "border-style: solid;"
                                  "border-radius: 0;"
                              "}"
        }.arg(colorListWidgetBackground.name(),
              colorListWidgetItemBackground.name(),
              colorListWidgetItemSelectedBorder.name());

        mStyleSheetCopy = mStyleSheet;

        apply();
    }

    void StyleListWidget::setListWidgetBackground(const QColor &color)
    {
        QRegularExpression reListWidgetBackground( "QListWidget\\ ([{a-z0-9:-;]*)background:\\ " );
        replaceStyleSheet(reListWidgetBackground, color.name());
    }

    void StyleListWidget::setListWidgetItemBackground(const QColor &color)
    {
        QRegularExpression reListWidgetBackground( "QListWidget::item\\ ([{a-z0-9:-;]*)background:\\ " );
        replaceStyleSheet(reListWidgetBackground, color.name());
    }

    void StyleListWidget::setListWidgetItemSelectedBorderColor(const QColor &color)
    {
        QRegularExpression reListWidgetBorder( "QListWidget::item:selected\\ ((.)*)selection-background-color:\\ " );
        replaceStyleSheet(reListWidgetBorder, color.name());
    }

    void StyleListWidget::setListWidgetBorderWidth(uint64_t px)
    {
        QString boardWidth = QString::number(px);
        QRegularExpression reListWidgetBorderWidth( "QListWidget\\ ((.)*)border-width:\\ " );
        replaceStyleSheet(reListWidgetBorderWidth, boardWidth);
    }

    void StyleListWidget::setListWidgetItemBorderWidth(uint64_t px)
    {
        QString boardWidth = QString::number(px);
        QRegularExpression reListWidgetBorderWidth( "QListWidget::item\\ ((.)*)border-width:\\ " );
        replaceStyleSheet(reListWidgetBorderWidth, boardWidth);
    }

    void StyleListWidget::setListWidgetMargin(const QMargins &margin)
    {
        QRegularExpression reListWidgetMargin( "QListWidget\\ ((.)*)margin:\\ " );
        setMargins(reListWidgetMargin, margin);
    }

    void StyleListWidget::setListWidgetItemMargin(const QMargins &margin)
    {
        QRegularExpression reListWidgetMargin( "QListWidget::item\\ ((.)*)margin:\\ " );
        setMargins(reListWidgetMargin, margin);
    }

    void StyleListWidget::setStyleSheetWidgetInside(const QString &styleSheet)
    {
        mStyleSheet = mStyleSheetCopy;
        mStyleSheet += styleSheet;
    }

    void StyleListWidget::apply()
    {
        mListWidget->setStyleSheet(mStyleSheet);
    }

}  // end of styles

}  // end of e0fe

