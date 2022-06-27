#include "wrapper.hpp"

const QListWidget *WrapperStyleListWidget::getListWidget() const
{
    return mListWidget;
}

const QString &WrapperStyleListWidget::getStyleSheet() const
{
    return StyleListWidget::getStyleSheet();
}

const QString &WrapperStyleListWidget::getStyleSheetCopy() const
{
    return StyleListWidget::getPreviousStyleSheet();
}
