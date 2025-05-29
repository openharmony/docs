# ArkWeb_CookieManagerAPI


## 概述

定义了ArkWeb的CookieManager接口。在调用接口之前，建议使用ARKWEB_MEMBER_MISSING检查函数结构体是否有对应的函数指针，避免SDK与设备ROM不匹配导致崩溃。

**起始版本：** 12

**相关模块：**[Web](_web.md)

**所在头文件：** [arkweb_type.h](arkweb__type_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| size_t [size](#size) | 结构体的大小。  | 
| [ArkWeb_ErrorCode](_web.md#arkweb_errorcode)(\* [fetchCookieSync](#fetchcookiesync) )(const char \*url, bool incognito, bool includeHttpOnly, char \*\*cookieValue) | 获取指定URL对应的cookie值。  | 
| [ArkWeb_ErrorCode](_web.md#arkweb_errorcode)(\* [configCookieSync](#configcookiesync) )(const char \*url, const char \*cookieValue, bool incognito, bool includeHttpOnly) | 设置指定URL的cookie值。  | 
| bool(\* [existCookies](#existcookies) )(bool incognito) | 检查Cookie是否存在。  | 
| void(\* [clearAllCookiesSync](#clearallcookiessync) )(bool incognito) | 清除所有cookies。  | 
|  void(\* clearSessionCookiesSync )() | 清除所有会话Cookies。  | 


## 结构体成员变量说明


### clearAllCookiesSync

```
void(* ArkWeb_CookieManagerAPI::clearAllCookiesSync) (bool incognito)
```
**描述：**

清除所有cookies。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| incognito | true表示清除隐私模式下的所有cookies，false表示清除非隐私模式下的所有cookies。  | 


### configCookieSync

```
ArkWeb_ErrorCode(* ArkWeb_CookieManagerAPI::configCookieSync) (const char *url, const char *cookieValue, bool incognito, bool includeHttpOnly)
```
**描述：**

设置指定URL的cookie值。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| url | 指定cookie所属的URL，建议填写完整的URL。  | 
| cookieValue | 要设置的cookie的值。  | 
| incognito | true表示在隐私模式下设置对应URL的Cookie，talse表示以非隐私模式设置对应URL的cookie。  | 
| includeHttpOnly | 如果为true，则标记为HTTP-Only的cookie也可以被覆盖。  | 

**返回：**

返回值错误码。 [ARKWEB_SUCCESS](_web.md#arkweb_errorcode-1) 设置cookie成功。 [ARKWEB_INVALID_URL](_web.md#arkweb_errorcode-1) 设置的URL无效。 [ARKWEB_INVALID_COOKIE_VALUE](_web.md#arkweb_errorcode-1) cookieValue参数无效。


### existCookies

```
bool(* ArkWeb_CookieManagerAPI::existCookies) (bool incognito)
```
**描述：**

检查Cookie是否存在。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| incognito | true表示隐私模式下是否存在cookie，false表示非隐私模式下是否存在cookie。  | 

**返回：**

true表示cookie存在，false表示cookie不存在。


### fetchCookieSync

```
ArkWeb_ErrorCode(* ArkWeb_CookieManagerAPI::fetchCookieSync) (const char *url, bool incognito, bool includeHttpOnly, char **cookieValue)
```
**描述：**

获取指定URL对应的cookie值。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| url | 要获取的cookie所属的URL，建议使用完整的URL。  | 
| incognito | true表示获取隐私模式下webview的内存cookie，false表示获取非隐私模式下的cookie。  | 
| includeHttpOnly | 如果为true，则标记为HTTP-Only属性的cookie也将包含在cookieValue中，false则不包含。  | 
| cookieValue | 获取与URL对应的cookie值。  | 

**返回：**

返回值错误码。 [ARKWEB_SUCCESS](_web.md#arkweb_errorcode-1) 获取cookie成功。 [ARKWEB_INVALID_URL](_web.md#arkweb_errorcode-1) 设置的URL无效。 [ARKWEB_INVALID_PARAM](_web.md#arkweb_errorcode-1) cookieValue参数无效。


### size

```
size_t ArkWeb_CookieManagerAPI::size
```
**描述：**

结构体的大小。
