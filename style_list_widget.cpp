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
                                            "padding: 3px 3px 3px 3px;"
                                       "}"
                                       "QListView::item:selected {"
                                            "border: 10px solid %3;"
                                            "border-radius: 0px;"
                                       "}"
                                }.arg(colorListWidgetBackground.name(),
                                      colorListWidgetItemBackground.name(),
                                      colorListWidgetItemSelectedBorder.name());
            apply();

        }

        void StyleListWidget::setListWidgetBackground(const QColor &color)
        {
            qDebug() << "Color name is " << color.name();
            QRegularExpression reListWidgetBackground( "QListWidget\\ ([{a-z0-9:-]+)background:\\ " );

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

