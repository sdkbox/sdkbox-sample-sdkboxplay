#ifndef __PluginSdkboxPlayJS_h__
#define __PluginSdkboxPlayJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginSdkboxPlayJS_PluginSdkboxPlay(JSContext *cx, JS::HandleObject global);
void register_all_PluginSdkboxPlayJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginSdkboxPlayJS_PluginSdkboxPlay(JSContext *cx, JSObject* global);
void register_all_PluginSdkboxPlayJS(JSContext* cx, JSObject* obj);
#endif
#endif

