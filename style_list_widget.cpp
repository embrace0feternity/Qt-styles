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

        void StyleListWidget::checkBorderWidth(QRegularExpression &regex, uint64_t px)
        {
            QString borderWidth = "none";
            if (px)
            {
                QString borderWidth = QString::number(px);
            }
            QString search = "border-width: ";
            replaceStyleSheet(regex, search, borderWidth);
        }

        void StyleListWidget::setPadding(QRegularExpression &regex, uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QString temp = QString::number(left) + " " +
                    QString::number(top) + " " +
                    QString::number(right) + " " +
                    QString::number(bottom);

            QString search = "padding: ";
            replaceStyleSheet(regex, search, temp);
        }

        void StyleListWidget::setMargins(QRegularExpression &regex, const QMargins &margin) {
            QString temp = QString::number(margin.left()) + " " +
                    QString::number(margin.top()) + " " +
                    QString::number(margin.right()) + " " +
                    QString::number(margin.bottom());

            QString search = "margin: ";
            replaceStyleSheet(regex, search, temp);
        }

        StyleListWidget::StyleListWidget(QListWidget *listWidget) : mListWidget(listWidget) {
            QFile file{"style_list_widget.qss"};
            file.open(QFile::ReadOnly);
            mStyleSheet = mStyleSheetCopy = file.readAll();
            mListWidget->setStyleSheet(mStyleSheet);
        }

        void StyleListWidget::setBackground(const QColor &color) {
            QRegularExpression reListWidget( "QListWidget {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            QString search = "background: ";
            replaceStyleSheet(reListWidget, search, color.name());
        }

        void StyleListWidget::setItemBackground(const QColor &color) {
            QRegularExpression reListWidget( "QListWidget::item {(.)(\\ ){4}",
                                                       QRegularExpression::DotMatchesEverythingOption);
            QString search = "background: ";
            replaceStyleSheet(reListWidget, search, color.name());
        }

        void StyleListWidget::setItemSelectedBackground(const QColor &color) {
            QRegularExpression reListWidget( "QListWidget::item:selected {(.)(\\ ){4}",
                                                               QRegularExpression::DotMatchesEverythingOption);
            QString search = "background: ";
            replaceStyleSheet(reListWidget, search, color.name());
        }

        void StyleListWidget::setItemSelectedActiveBackground(const QColor &color)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:active {(.)(\\ ){4}",
                                                               QRegularExpression::DotMatchesEverythingOption);
            QString search = "background: ";
            replaceStyleSheet(reListWidget, search, color.name());
        }

        void StyleListWidget::setItemSelectedNoActiveBackground(const QColor &color)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:!active {(.)(\\ ){4}",
                                                               QRegularExpression::DotMatchesEverythingOption);
            QString search = "background: ";
            replaceStyleSheet(reListWidget, search, color.name());
        }

        void StyleListWidget::setBorderWidth(uint64_t px) {
            QRegularExpression reListWidget( "QListWidget {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            checkBorderWidth(reListWidget, px);
        }

        void StyleListWidget::setItemBorderWidth(uint64_t px) {
            QRegularExpression reListWidget( "QListWidget::item {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            checkBorderWidth(reListWidget, px);
        }

        void StyleListWidget::setItemSelectedBorderWidth(uint64_t px)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            checkBorderWidth(reListWidget, px);
        }

        void StyleListWidget::setItemSelectedActiveBorderWidth(uint64_t px)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:active {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            checkBorderWidth(reListWidget, px);
        }

        void StyleListWidget::setItemSelectedNoActiveBorderWidth(uint64_t px)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:!active {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            checkBorderWidth(reListWidget, px);
        }

        void StyleListWidget::setBorderRadius(uint64_t px)
        {
            QRegularExpression reListWidget( "QListWidget {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            QString search = "border-radius: ";
            replaceStyleSheet(reListWidget, search, QString::number(px));
        }

        void StyleListWidget::setItemBorderRadius(uint64_t px)
        {
            QRegularExpression reListWidget( "QListWidget::item {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            QString search = "border-radius: ";
            replaceStyleSheet(reListWidget, search, QString::number(px));
        }

        void StyleListWidget::setItemSelectedBorderRadius(uint64_t px)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            QString search = "border-radius: ";
            replaceStyleSheet(reListWidget, search, QString::number(px));
        }

        void StyleListWidget::setItemSelectedActiveBorderRadius(uint64_t px)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:active {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            QString search = "border-radius: ";
            replaceStyleSheet(reListWidget, search, QString::number(px));
        }

        void StyleListWidget::setItemSelectedNoActiveBorderRadius(uint64_t px)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:!active {(.)(\\ ){4}",
                                                        QRegularExpression::DotMatchesEverythingOption);
            QString search = "border-radius: ";
            replaceStyleSheet(reListWidget, search, QString::number(px));
        }

        void StyleListWidget::setMargin(const QMargins &margin) {
            QRegularExpression reListWidget( "QListWidget {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setMargins(reListWidget, margin);
        }

        void StyleListWidget::setMargin(uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QRegularExpression reListWidget( "QListWidget {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            QMargins margin(left, top, right, bottom);
            setMargins(reListWidget, margin);
        }

        void StyleListWidget::setItemMargin(const QMargins &margin) {
            QRegularExpression reListWidget( "QListWidget::item {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setMargins(reListWidget, margin);
        }

        void StyleListWidget::setItemMargin(uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QRegularExpression reListWidget( "QListWidget::item {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            QMargins margin(left, top, right, bottom);
            setMargins(reListWidget, margin);
        }

        void StyleListWidget::setItemSelectedMargin(const QMargins &margin)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setMargins(reListWidget, margin);
        }

        void StyleListWidget::setItemSelectedMargin(uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            QMargins margin(left, top, right, bottom);
            setMargins(reListWidget, margin);
        }

        void StyleListWidget::setItemSelectedActiveMargin(const QMargins &margin)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:active {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setMargins(reListWidget, margin);
        }

        void StyleListWidget::setItemSelectedActiveMargin(uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:active {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            QMargins margin(left, top, right, bottom);
            setMargins(reListWidget, margin);
        }

        void StyleListWidget::setItemSelectedNoActiveMargin(const QMargins &margin)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:!active {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setMargins(reListWidget, margin);
        }

        void StyleListWidget::setItemSelectedNoActiveMargin(uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:!active {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            QMargins margin(left, top, right, bottom);
            setMargins(reListWidget, margin);
        }

        void StyleListWidget::setPadding(uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QRegularExpression reListWidget( "QListWidget {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setPadding(reListWidget, left, top, right, bottom);
        }

        void StyleListWidget::setPaddingItem(uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QRegularExpression reListWidget( "QListWidget::item {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setPadding(reListWidget, left, top, right, bottom);
        }

        void StyleListWidget::setPaddingItemSelected(uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setPadding(reListWidget, left, top, right, bottom);
        }

        void StyleListWidget::setPaddingItemSelectedActive(uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:active {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setPadding(reListWidget, left, top, right, bottom);
        }

        void StyleListWidget::setPaddingItemSelectedNoActive(uint64_t left, uint64_t top, uint64_t right, uint64_t bottom)
        {
            QRegularExpression reListWidget( "QListWidget::item:selected:!active {(.)(\\ ){4}",
                                                   QRegularExpression::DotMatchesEverythingOption);
            setPadding(reListWidget, left, top, right, bottom);
        }

        void StyleListWidget::apply() {
            mListWidget->setStyleSheet(mStyleSheet);
        }

    }  // end of styles

}  // end of e0fe

