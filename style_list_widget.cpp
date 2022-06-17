#include "style_list_widget.hpp"

namespace e0fe {

    namespace styles {

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
                                           "margin: 10px 5px 10px 5px;"
                                       "}"
                                       "QListWidget::item {"
                                            "background: %2;"
                                            "border-width: none;"
                                            "border-radius: 5px;"
                                            "margin: 5px 20px 5px 20px;"
                                            "padding: 2px 3px 2px 3px;"
                                       "}"
                                       "QListView::item:selected {"
                                            "show-decoration-selected: 1;"
                                            "selection-background-color: %3;"
                                            "border-width: 12px"
                                            "border-style: solid;"
                                            "border-radius: 0px;"
                                            "margin: 30px 5px 30px 5px;"
                                       "}"
                                }.arg(colorListWidgetBackground.name(),
                                      colorListWidgetItemBackground.name(),
                                      colorListWidgetItemSelectedBorder.name());
            apply();

        }

        void StyleListWidget::setListWidgetBackground(const QColor &color)
        {
            qDebug() << "Color name is " << color.name();
            QRegularExpression reListWidgetBackground( "QListWidget\\ ([{a-z0-9:-;]*)background:\\ " );

            auto i = reListWidgetBackground.match(mStyleSheet).capturedEnd();
            auto j = i;

            for (; mStyleSheet[i] != ';'; ++i);

            mStyleSheet.replace(j, i-j, color.name());
            apply();
        }

        void StyleListWidget::setListWidgetItemBackground(const QColor &color)
        {
            qDebug() << "Color name is " << color.name();
            QRegularExpression reListWidgetBackground( "QListWidget::item\\ ([{a-z0-9:-;]*)background:\\ " );

            auto i = reListWidgetBackground.match(mStyleSheet).capturedEnd();
            auto j = i;

            for (; mStyleSheet[i] != ';'; ++i);

            mStyleSheet.replace(j, i-j, color.name());
            apply();
        }

        void StyleListWidget::setListWidgetItemSelectedBorderColor(const QColor &color)
        {
            qDebug() << "Color name is " << color.name();
            QRegularExpression reListWidgetBackground( "QListView::item:selected\\ ((.)*)selection-background-color:\\ " );

            auto i = reListWidgetBackground.match(mStyleSheet).capturedEnd();
            auto j = i;

            for (; mStyleSheet[i] != ';'; ++i);

            mStyleSheet.replace(j, i-j, color.name());
            apply();
        }

        void StyleListWidget::apply()
        {
            mListWidget->setStyleSheet(mStyleSheet);
        }

    }
}

