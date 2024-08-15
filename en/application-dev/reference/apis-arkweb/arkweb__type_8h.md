# arkweb_type.h


## Overview

The **arkweb_type.h** file defines the public Native types of ArkWeb.

**Library**: libohweb.so

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) | Defines a struct for the JavaScript Bridge data. | 
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptObject](_ark_web___java_script_object.md) | Defines a struct for the JavaScript object. | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyMethod](_ark_web___proxy_method.md) | Defines a struct for the proxy method. | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyObject](_ark_web___proxy_object.md) | Defines a struct for the proxy object. | 
| struct&nbsp;&nbsp;[ArkWeb_ControllerAPI](_ark_web___controller_a_p_i.md) | Defines a struct for the controller APIs. | 
| struct&nbsp;&nbsp;[ArkWeb_ComponentAPI](_ark_web___component_a_p_i.md) | Defines a struct for the component APIs. | 


### Macros

| Name| Description| 
| -------- | -------- |
| [ARKWEB_MEMBER_EXISTS](_web.md#arkweb_member_exists)(s, f)&nbsp;&nbsp;&nbsp;&nbsp;((intptr_t) &amp; ((s)-&gt;f) - (intptr_t)(s) + sizeof((s)-&gt;f) &lt;= \*reinterpret_cast&lt;size_t\*&gt;(s)) | Checks whether the member variable exists in the struct. | 
| [ARKWEB_MEMBER_MISSING](_web.md#arkweb_member_missing)(s, f)&nbsp;&nbsp;&nbsp;(\![ARKWEB_MEMBER_EXISTS](_web.md#arkweb_member_exists)(s, f) \|\| !((s)-&gt;f)) | If the member variable exists in the struct, false is returned. Otherwise, true is returned. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(\* [ArkWeb_OnJavaScriptCallback](_web.md#arkweb_onjavascriptcallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*data, void \*userData) | Defines a callback used when the injected JavaScript is executed. | 
| typedef void(\* [ArkWeb_OnJavaScriptProxyCallback](_web.md#arkweb_onjavascriptproxycallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*dataArray, size_t arraySize, void \*userData) | Defines a callback used when the Proxy method is executed. | 
| typedef void(\* [ArkWeb_OnComponentCallback](_web.md#arkweb_oncomponentcallback)) (const char \*webTag, void \*userData) | Defines a callback used to return component event notification. | 
