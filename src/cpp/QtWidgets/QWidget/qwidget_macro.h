#pragma once

#include "src/cpp/QtWidgets/QLayout/qlayout_wrap.h"
#include "src/cpp/core/YogaWidget/yogawidget_macro.h"
#include "src/cpp/core/Events/eventwidget_macro.h"
#include "src/cpp/core/Component/component_macro.h"
#include <QSize>
/*

    This macro adds common QWidgets exported methods 
    The exported methods are taken into this macro to avoid writing them in each and every widget we export.
 */

#ifndef QWIDGET_WRAPPED_METHODS_DECLARATION
#define QWIDGET_WRAPPED_METHODS_DECLARATION \
\
YOGAWIDGET_WRAPPED_METHODS_DECLARATION \
EVENTWIDGET_WRAPPED_METHODS_DECLARATION \
\
Napi::Value show(const Napi::CallbackInfo& info) { \
    Napi::Env env = info.Env(); \
    Napi::HandleScope scope(env); \
    this->instance->show(); \
    return env.Null(); \
} \
\
Napi::Value resize(const Napi::CallbackInfo& info) { \
    Napi::Env env = info.Env(); \
    Napi::HandleScope scope(env); \
    Napi::Number width = info[0].As<Napi::Number>(); \
    Napi::Number height = info[1].As<Napi::Number>(); \
    this->instance->resize(width.Int32Value(), height.Int32Value()); \
    return env.Null(); \
} \
\
Napi::Value close(const Napi::CallbackInfo& info) { \
    Napi::Env env = info.Env(); \
    Napi::HandleScope scope(env); \
    bool hasClosed = this->instance->close(); \
    return Napi::Boolean::New(env, hasClosed); \
} \
\
Napi::Value setLayout(const Napi::CallbackInfo& info){ \
    Napi::Env env = info.Env(); \
    Napi::HandleScope scope(env); \
    Napi::Object layoutObject = info[0].As<Napi::Object>(); \
    QLayoutWrap* layoutWrap = Napi::ObjectWrap<QLayoutWrap>::Unwrap(layoutObject); \
    this->instance->setLayout(layoutWrap->getInternalInstance()); \
    return env.Null(); \
} \
\
Napi::Value setStyleSheet(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  Napi::String text = info[0].As<Napi::String>(); \
  std::string style = text.Utf8Value(); \
  this->instance->setStyleSheet(style.c_str()); \
  return env.Null(); \
} \
Napi::Value styleSheet(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  QString stylesheet = this->instance->styleSheet(); \
  return Napi::String::New(env, stylesheet.toStdString()); \
} \
Napi::Value hide(const Napi::CallbackInfo& info) { \
    Napi::Env env = info.Env(); \
    Napi::HandleScope scope(env); \
    this->instance->hide(); \
    return env.Null(); \
} \
\
Napi::Value setObjectName(const Napi::CallbackInfo& info){ \
    Napi::Env env = info.Env(); \
    Napi::HandleScope scope(env); \
    Napi::String objectName = info[0].As<Napi::String>(); \
    this->instance->setObjectName(QString::fromStdString(objectName.Utf8Value())); \
    return env.Null(); \
} \
Napi::Value objectName(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  QString objectName = this->instance->objectName(); \
  return Napi::String::New(env, objectName.toStdString()); \
} \
Napi::Value setMouseTracking(const Napi::CallbackInfo& info){ \
    Napi::Env env = info.Env(); \
    Napi::HandleScope scope(env); \
    Napi::Boolean isMouseTracked = info[0].As<Napi::Boolean>(); \
    this->instance->setMouseTracking(isMouseTracked.Value()); \
    return env.Null(); \
} \
Napi::Value setEnabled(const Napi::CallbackInfo& info){ \
    Napi::Env env = info.Env(); \
    Napi::HandleScope scope(env); \
    Napi::Boolean enabled = info[0].As<Napi::Boolean>(); \
    this->instance->setEnabled(enabled.Value()); \
    return env.Null(); \
} \
Napi::Value setFixedSize(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  int width = info[0].As<Napi::Number>().Int32Value(); \
  int height = info[1].As<Napi::Number>().Int32Value(); \
  this->instance->setFixedSize(width, height); \
  return env.Null(); \
} \
Napi::Value setMaximumSize(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  int width = info[0].As<Napi::Number>().Int32Value(); \
  int height = info[1].As<Napi::Number>().Int32Value(); \
  this->instance->setMaximumSize(width, height); \
  return env.Null(); \
} \
Napi::Value setMinimumSize(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  int width = info[0].As<Napi::Number>().Int32Value(); \
  int height = info[1].As<Napi::Number>().Int32Value(); \
  this->instance->setMinimumSize(width, height); \
  return env.Null(); \
} \
Napi::Value repaint(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  this->instance->repaint(); \
  return env.Null(); \
} \
Napi::Value update(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  this->instance->update(); \
  return env.Null(); \
} \
Napi::Value updateGeometry(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  this->instance->updateGeometry(); \
  return env.Null(); \
} \
Napi::Value size(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  QSize size = this->instance->size(); \
  Napi::Object sizeObj = Napi::Object::New(env); \
  sizeObj.Set("width", size.width()); \
  sizeObj.Set("height", size.height()); \
  return sizeObj; \
} \
Napi::Value setAttribute(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  int attributeId = info[0].As<Napi::Number>().Int32Value(); \
  bool switchOn = info[1].As<Napi::Boolean>().Value(); \
  this->instance->setAttribute(static_cast<Qt::WidgetAttribute>(attributeId), switchOn); \
  return env.Null(); \
} \
Napi::Value testAttribute(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  int attributeId = info[0].As<Napi::Number>().Int32Value(); \
  bool isOn = this->instance->testAttribute(static_cast<Qt::WidgetAttribute>(attributeId)); \
  return Napi::Boolean::New(env, isOn); \
} \
Napi::Value setWindowOpacity(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  float opacity = info[0].As<Napi::Number>().FloatValue(); \
  this->instance->setWindowOpacity(opacity); \
  return env.Null(); \
} \
Napi::Value setWindowFlag(const Napi::CallbackInfo& info){ \
  Napi::Env env = info.Env(); \
  Napi::HandleScope scope(env); \
  int windowType = info[0].As<Napi::Number>().Int32Value(); \
  bool switchOn = info[1].As<Napi::Boolean>().Value(); \
  this->instance->setWindowFlag(static_cast<Qt::WindowType>(windowType), switchOn); \
  return env.Null(); \
} \

#endif //QWIDGET_WRAPPED_METHODS_DECLARATION

#ifndef QWIDGET_WRAPPED_METHODS_EXPORT_DEFINE
#define QWIDGET_WRAPPED_METHODS_EXPORT_DEFINE(WidgetWrapName)  \
\
 YOGAWIDGET_WRAPPED_METHODS_EXPORT_DEFINE(WidgetWrapName) \
 EVENTWIDGET_WRAPPED_METHODS_EXPORT_DEFINE(WidgetWrapName) \
 COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE \
 InstanceMethod("show", &WidgetWrapName::show),  \
 InstanceMethod("resize",&WidgetWrapName::resize), \
 InstanceMethod("close",&WidgetWrapName::close), \
 InstanceMethod("setLayout",&WidgetWrapName::setLayout), \
 InstanceMethod("setStyleSheet",&WidgetWrapName::setStyleSheet), \
 InstanceMethod("styleSheet",&WidgetWrapName::styleSheet), \
 InstanceMethod("hide",&WidgetWrapName::hide), \
 InstanceMethod("setObjectName",&WidgetWrapName::setObjectName), \
 InstanceMethod("objectName",&WidgetWrapName::objectName), \
 InstanceMethod("setMouseTracking",&WidgetWrapName::setMouseTracking), \
 InstanceMethod("setEnabled",&WidgetWrapName::setEnabled), \
 InstanceMethod("setFixedSize",&WidgetWrapName::setFixedSize), \
 InstanceMethod("setMaximumSize",&WidgetWrapName::setMaximumSize), \
 InstanceMethod("setMinimumSize",&WidgetWrapName::setMinimumSize), \
 InstanceMethod("repaint",&WidgetWrapName::repaint), \
 InstanceMethod("update",&WidgetWrapName::update), \
 InstanceMethod("updateGeometry",&WidgetWrapName::updateGeometry), \
 InstanceMethod("size",&WidgetWrapName::size), \
 InstanceMethod("setAttribute",&WidgetWrapName::setAttribute), \
 InstanceMethod("testAttribute",&WidgetWrapName::testAttribute), \
 InstanceMethod("setWindowOpacity",&WidgetWrapName::setWindowOpacity), \
 InstanceMethod("setWindowFlag",&WidgetWrapName::setWindowFlag), \

#endif // QWIDGET_WRAPPED_METHODS_EXPORT_DEFINE
