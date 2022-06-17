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
    public:
        StyleListWidget(QListWidget *listWidget);
        void setStyleSheetBlue();
        void setListWidgetBackground(const QColor &color);
        void setListWidgetItemBackground(const QColor &color);
        void setListWidgetItemSelectedBorderColor(const QColor &color);
        void apply();
    };




    }  // end of styles

}      // end of e0fe


#endif // STYLE_LIST_WIDGET_HPP
