#include "wrapper.hpp"

const QListWidget *WrapperStyleListWidget::getListWidget() const
{
    return mListWidget;
}

const QString &WrapperStyleListWidget::getStyleSheet() const
{
    return mStyleSheet;
}

const QString &WrapperStyleListWidget::getStyleSheetCopy() const
{
    return mStyleSheetCopy;
}
