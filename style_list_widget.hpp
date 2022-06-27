#ifndef STYLE_LIST_WIDGET_HPP
#define STYLE_LIST_WIDGET_HPP

#include <QListWidget>
#include <QDebug>
#include <QFile>
#include <QStringView>
#include <QString>

namespace e0fe {

    namespace styles {

    class StyleListWidget {
    protected:
        QListWidget *mListWidget;
        QString mStyleSheet;
        QString mStyleSheetCopy;
    private:
        void replaceStyleSheet(QRegularExpression &regex, QStringView searh, const QString &replacedStr);

        void setMargins(QRegularExpression &regex, const QMargins &margin);
    public:
        StyleListWidget(QListWidget *listWidget);
        void setListWidgetBackground(const QColor &color);
        void setListWidgetItemBackground(const QColor &color);
        void setListWidgetItemSelectedBackground(const QColor &color);
        void setListWidgetItemSelectedActiveBackground(const QColor &color);
        void setListWidgetItemSelectedNoActiveBackground(const QColor &color);

        void setListWidgetBorderWidth(uint64_t px);
        void setListWidgetItemBorderWidth(uint64_t px);

        void setListWidgetMargin(const QMargins &margin);
        void setListWidgetItemMargin(const QMargins &margin);
        void setListWidgetItemSelectedMargin(const QMargins &margin);
        void setListWidgetItemSelectedActiveMargin(const QMargins &margin);
        void setListWidgetItemSelectedNoActiveMargin(const QMargins &margin);

        void apply();

        inline QString& getStyleSheet() {
            return mStyleSheet;
        }

        inline const QString& getStyleSheet() const {
            return mStyleSheet;
        }

        inline QString& getPreviousStyleSheet() {
            return mStyleSheetCopy;
        }

        inline const QString& getPreviousStyleSheet() const {
            return mStyleSheetCopy;
        }


    };




    }  // end of styles

}      // end of e0fe


#endif // STYLE_LIST_WIDGET_HPP
