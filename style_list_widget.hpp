#ifndef STYLE_LIST_WIDGET_HPP
#define STYLE_LIST_WIDGET_HPP

#include <QListWidget>
#include <QDebug>

namespace e0fe {

    namespace styles {

    class StyleListWidget {
    protected:
        QListWidget *mListWidget;
        QString mStyleSheet;
        QString mStyleSheetCopy;
    private:
        void replaceStyleSheet(QRegularExpression &regex, QString str);
        void setMargins(QRegularExpression &regex, const QMargins &margin);
    public:
        StyleListWidget() = default;
        StyleListWidget(QListWidget *listWidget);
        void setStyleSheetBlue();
        void setListWidgetBackground(const QColor &color);
        void setListWidgetItemBackground(const QColor &color);
        void setListWidgetItemSelectedBorderColor(const QColor &color);

        void setListWidgetBorderWidth(uint64_t px);
        void setListWidgetItemBorderWidth(uint64_t px);

        void setListWidgetMargin(const QMargins &margin);
        void setListWidgetItemMargin(const QMargins &margin);

        void setStyleSheetWidgetInside(const QString &styleSheet);

        void apply();

    };




    }  // end of styles

}      // end of e0fe


#endif // STYLE_LIST_WIDGET_HPP
