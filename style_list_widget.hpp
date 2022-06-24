#ifndef STYLE_LIST_WIDGET_HPP
#define STYLE_LIST_WIDGET_HPP

#include <QListWidget>
#include <QDebug>
#include <QFile>

namespace e0fe {

    namespace styles {

    class StyleListWidget {
    protected:
        QListWidget *mListWidget;
        QString mStyleSheet;
        QString mStyleSheetCopy;
        QFile file{"../styles/style_list_widget.qss"};
    private:
        void replaceStyleSheet(QRegularExpression &regex, QString str) {
            qDebug() << "str = " << str;
            auto i = regex.match(mStyleSheet).capturedEnd();
            auto j = i;

            for (; mStyleSheet[i] != ';'; ++i);

            mStyleSheet.replace(j, i-j, str);
            mStyleSheetCopy = mStyleSheet;
            apply();
        }

        void setMargins(QRegularExpression &regex, const QMargins &margin) {
            QString temp = QString::number(margin.left()) + " " +
                    QString::number(margin.top()) + " " +
                    QString::number(margin.right()) + " " +
                    QString::number(margin.bottom());

            replaceStyleSheet(regex, temp);
        }
    public:
        StyleListWidget(QListWidget *listWidget): mListWidget(listWidget) {
            file.open(QFile::ReadOnly);
            mListWidget->setStyleSheet(file.readAll());
        };
        void setListWidgetBackground(const QColor &color) {
            QRegularExpression reListWidgetBackground( "QListWidget\\ ([{a-z0-9:-;]*)background:\\ " );
            replaceStyleSheet(reListWidgetBackground, color.name());
        }

        void setListWidgetItemBackground(const QColor &color) {
            QRegularExpression reListWidgetBackground( "QListWidget::item\\ ([{a-z0-9:-;]*)background:\\ " );
            replaceStyleSheet(reListWidgetBackground, color.name());
        }

        void setListWidgetItemSelectedBorderColor(const QColor &color) {
            QRegularExpression reListWidgetBorder( "QListWidget::item:selected\\ ((.)*)selection-background-color:\\ " );
            replaceStyleSheet(reListWidgetBorder, color.name());
        }

        void setListWidgetBorderWidth(uint64_t px) {
            QString boardWidth = QString::number(px);
            QRegularExpression reListWidgetBorderWidth( "QListWidget\\ ((.)*)border-width:\\ " );
            replaceStyleSheet(reListWidgetBorderWidth, boardWidth);
        }
        void setListWidgetItemBorderWidth(uint64_t px) {
            QString boardWidth = QString::number(px);
            QRegularExpression reListWidgetBorderWidth( "QListWidget\\ ((.)*)border-width:\\ " );
            replaceStyleSheet(reListWidgetBorderWidth, boardWidth);
        }

        void setListWidgetMargin(const QMargins &margin) {
            QRegularExpression reListWidgetMargin( "QListWidget\\ ((.)*)margin:\\ " );
            setMargins(reListWidgetMargin, margin);
        }

        void setListWidgetItemMargin(const QMargins &margin) {
            QRegularExpression reListWidgetMargin( "QListWidget::item\\ ((.)*)margin:\\ " );
            setMargins(reListWidgetMargin, margin);
        }

        inline void setStyleSheetWidgetInside(const QString &styleSheet) {
            mStyleSheet = mStyleSheetCopy;
            mStyleSheet += styleSheet;
        }

        inline void apply() {
            mListWidget->setStyleSheet(mStyleSheet);
        }

    };

    }  // end of styles

}      // end of e0fe


#endif // STYLE_LIST_WIDGET_HPP
