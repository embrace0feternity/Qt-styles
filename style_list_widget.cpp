#include "style_list_widget.hpp"

namespace e0fe {

    namespace styles {

        void StyleListWidget::replaceStyleSheet(QRegularExpression &regex,
                                                QStringView search,
                                                const QString &replacedStr) {

            mStyleSheetCopy = mStyleSheet;
            QRegularExpressionMatch match = regex.match(mStyleSheet);
            auto start = match.capturedEnd(0);

            qsizetype searchPosition = mStyleSheet.indexOf(search, start, Qt::CaseSensitive) + search.size();

            auto goOn = searchPosition;
            for (; mStyleSheet[goOn] != ';'; ++goOn);

            mStyleSheet.replace(searchPosition, goOn-searchPosition, replacedStr);
            apply();
        }

        StyleListWidget::StyleListWidget(QListWidget *listWidget) : mListWidget(listWidget) {
            QFile file{"style_list_widget.qss"};
            file.open(QFile::ReadOnly);
            mStyleSheet = mStyleSheetCopy = file.readAll();
            mListWidget->setStyleSheet(mStyleSheet);
        }

        void StyleListWidget::setListWidgetBackground(const QColor &color) {
            QRegularExpression reListWidgetBackground( "QListWidget {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            QString search = "background: ";
            replaceStyleSheet(reListWidgetBackground, search, color.name());
        }

        void StyleListWidget::setListWidgetItemBackground(const QColor &color) {
            QRegularExpression reListWidgetBackground( "QListWidget::item {(.)(\\ ){4}",
                                                       QRegularExpression::DotMatchesEverythingOption);
            QString search = "background: ";
            replaceStyleSheet(reListWidgetBackground, search, color.name());
        }

        void StyleListWidget::setListWidgetItemSelectedBackground(const QColor &color) {
            QRegularExpression reListWidgetSelectedBackground( "QListWidget::item:selected {(.)(\\ ){4}",
                                                               QRegularExpression::DotMatchesEverythingOption);
            QString search = "background: ";
            replaceStyleSheet(reListWidgetSelectedBackground, search, color.name());
        }

        void StyleListWidget::setListWidgetItemSelectedActiveBackground(const QColor &color)
        {
            QRegularExpression reListWidgetItemSelectedActive( "QListWidget::item:selected:active {(.)(\\ ){4}",
                                                               QRegularExpression::DotMatchesEverythingOption);
            QString search = "background: ";
            replaceStyleSheet(reListWidgetItemSelectedActive, search, color.name());
        }

        void StyleListWidget::setListWidgetItemSelectedNoActiveBackground(const QColor &color)
        {
            QRegularExpression reListWidgetItemSelectedActive( "QListWidget::item:selected:!active {(.)(\\ ){4}",
                                                               QRegularExpression::DotMatchesEverythingOption);
            QString search = "background: ";
            replaceStyleSheet(reListWidgetItemSelectedActive, search, color.name());
        }

        void StyleListWidget::setListWidgetBorderWidth(uint64_t px) {
            QString boardWidth = QString::number(px);
            QRegularExpression reListWidgetBorderWidth( "QListWidget {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            QString search = "border-width: ";
            replaceStyleSheet(reListWidgetBorderWidth, search, boardWidth);
        }

        void StyleListWidget::setListWidgetItemBorderWidth(uint64_t px) {
            QString boardWidth = QString::number(px);
            QRegularExpression reListWidgetBorderWidth( "QListWidget::item {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            QString search = "border-width: ";
            replaceStyleSheet(reListWidgetBorderWidth, search, boardWidth);
        }

        void StyleListWidget::setMargins(QRegularExpression &regex, const QMargins &margin) {
            QString temp = QString::number(margin.left()) + " " +
                    QString::number(margin.top()) + " " +
                    QString::number(margin.right()) + " " +
                    QString::number(margin.bottom());

            QString search = "margin: ";
            replaceStyleSheet(regex, search, temp);
        }

        void StyleListWidget::setListWidgetMargin(const QMargins &margin) {
            QRegularExpression reListWidgetMargin( "QListWidget {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setMargins(reListWidgetMargin, margin);
        }

        void StyleListWidget::setListWidgetItemMargin(const QMargins &margin) {
            QRegularExpression reListWidgetMargin( "QListWidget::item {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setMargins(reListWidgetMargin, margin);
        }

        void StyleListWidget::setListWidgetItemSelectedMargin(const QMargins &margin)
        {
            QRegularExpression reListWidgetMargin( "QListWidget::item:selected {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setMargins(reListWidgetMargin, margin);
        }

        void StyleListWidget::setListWidgetItemSelectedActiveMargin(const QMargins &margin)
        {
            QRegularExpression reListWidgetMargin( "QListWidget::item:selected:active {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setMargins(reListWidgetMargin, margin);
        }

        void StyleListWidget::setListWidgetItemSelectedNoActiveMargin(const QMargins &margin)
        {
            QRegularExpression reListWidgetMargin( "QListWidget::item:selected:!active {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setMargins(reListWidgetMargin, margin);
        }


        void StyleListWidget::apply() {
            mListWidget->setStyleSheet(mStyleSheet);
        }

    }  // end of styles

}  // end of e0fe

