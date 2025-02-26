#pragma once
#include "src/cpp/core/YogaWidget/yogawidget.h"
#include "src/cpp/core/Events/eventwidget_macro.h"

// class to unify all the custom features + add extra features if needed
class NodeWidget : public YogaWidget, public EventWidget {

};



#ifndef NODEWIDGET_IMPLEMENTATIONS
#define NODEWIDGET_IMPLEMENTATIONS(BaseWidgetName) \
\
Q_OBJECT \
public: \
    SET_YOGA_WIDGET_Q_PROPERTIES \
    EVENTWIDGET_IMPLEMENTATIONS(BaseWidgetName) \

#endif //NODEWIDGET_IMPLEMENTATIONS

    