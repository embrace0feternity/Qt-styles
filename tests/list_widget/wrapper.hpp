#ifndef STYLE_LIST_WIDGET_WRAPPER_HPP
#define STYLE_LIST_WIDGET_WRAPPER_HPP

#include "../../style_list_widget.hpp"

class WrapperStyleListWidget : public e0fe::styles::StyleListWidget {
public:

    WrapperStyleListWidget(QListWidget *listWidget): e0fe::styles::StyleListWidget(listWidget) {

    }

    const QListWidget* getListWidget() const;

    const QString& getStyleSheet() const;

    const QString& getStyleSheetCopy() const;
};


#endif
