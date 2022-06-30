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
        void checkBorderWidth(QRegularExpression &regex, uint64_t px);
        void setPadding(QRegularExpression &regex, uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);

    public:
        StyleListWidget(QListWidget *listWidget);
        void setBackground(const QColor &color);
        void setItemBackground(const QColor &color);
        void setItemSelectedBackground(const QColor &color);
        void setItemSelectedActiveBackground(const QColor &color);
        void setItemSelectedNoActiveBackground(const QColor &color);

        void setBorderWidth(uint64_t px);
        void setItemBorderWidth(uint64_t px);
        void setItemSelectedBorderWidth(uint64_t px);
        void setItemSelectedActiveBorderWidth(uint64_t px);
        void setItemSelectedNoActiveBorderWidth(uint64_t px);

        void setBorderRadius(uint64_t px);
        void setItemBorderRadius(uint64_t px);
        void setItemSelectedBorderRadius(uint64_t px);
        void setItemSelectedActiveBorderRadius(uint64_t px);
        void setItemSelectedNoActiveBorderRadius(uint64_t px);

        void setMargin(const QMargins &margin);
        void setMargin(uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);
        void setItemMargin(const QMargins &margin);
        void setItemMargin(uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);
        void setItemSelectedMargin(const QMargins &margin);
        void setItemSelectedMargin(uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);
        void setItemSelectedActiveMargin(const QMargins &margin);
        void setItemSelectedActiveMargin(uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);
        void setItemSelectedNoActiveMargin(const QMargins &margin);
        void setItemSelectedNoActiveMargin(uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);

        void setPadding(uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);
        void setItemPadding(uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);
        void setItemPaddingSelected(uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);
        void setItemPaddingSelectedActive(uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);
        void setItemPaddingSelectedNoActive(uint64_t top, uint64_t left, uint64_t bottom, uint64_t right);

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
