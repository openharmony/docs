# 网络管理子系统Changelog

## cl.network.1 http.request接口新增2300998错误码

**访问级别**

公开接口

**变更原因**

为规范元服务请求域名范围，提升元服务上架审核效率和平台合规经营安全性，当用户使用元服务时，将根据该元服务的域名配置进行域名访问；若是访问未配置域名，则request接口会返回该错误码。

**变更影响**

该变更为不兼容变更。

API version 11及以下元服务应用访问未配置域名，request接口不会有任何影响。

API version
12开始，元服务应用访问未配置域名，request接口抛出该错误码，详情见docs仓[接口文档](../../../application-dev/reference/apis-network-kit/js-apis-http.md)。

**起始 API Level**

6

**变更发生版本**

从OpenHarmony SDK 5.0.0.25 开始。

**变更的接口/组件**

| 接口文件                                                                                                     |
|----------------------------------------------------------------------------------------------------------|
| [ohos.net.http.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.net.http.d.ts) |

**适配指导**

开发者在进行元服务应用开发时，涉及http请求，先到[AppGallery Connect](https://developer.huawei.com/consumer/cn/service/josp/agc/index.html)
完成服务器域名相关配置，可参考此[指导文档](https://developer.huawei.com/consumer/cn/doc/atomic-guides-V5/agc-help-harmonyos-server-domain-V5)
进行配置。

开发者在进行元服务应用开发时，若遇到http请求接口失败，请用catch捕获错误；若http请求接口失败错误码是2300998，可以到[AppGallery Connect](https://developer.huawei.com/consumer/cn/service/josp/agc/index.html)完成服务器域名相关配置，可参考此[指导文档](https://developer.huawei.com/consumer/cn/doc/atomic-guides-V5/agc-help-harmonyos-server-domain-V5)。

## cl.network.2 http.requestInStream接口新增2300998错误码

**访问级别**

公开接口

**变更原因**

为规范元服务请求域名范围，提升元服务上架审核效率和平台合规经营安全性，当用户使用元服务时，将根据该元服务的域名配置进行域名访问；若是访问未配置域名，则requestInStream接口会返回该错误码。

**变更影响**

该变更为不兼容变更。

API version 11及以下元服务应用访问未配置域名，requestInStream接口不会有任何影响。

API version
12开始，元服务应用访问未配置域名，requestInStream接口抛出该错误码，详情见docs仓[接口文档](../../../application-dev/reference/apis-network-kit/js-apis-http.md)。

**起始 API Level**

6

**变更发生版本**

从OpenHarmony SDK 5.0.0.25 开始。

**变更的接口/组件**

| 接口文件                                                                                                     |
|----------------------------------------------------------------------------------------------------------|
| [ohos.net.http.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.net.http.d.ts) |

**适配指导**

开发者在进行元服务应用开发时，涉及http流式请求，先到[AppGallery Connect](https://developer.huawei.com/consumer/cn/service/josp/agc/index.html)
完成服务器域名相关配置，可参考此[指导文档](https://developer.huawei.com/consumer/cn/doc/atomic-guides-V5/agc-help-harmonyos-server-domain-V5)
进行配置。

开发者在进行元服务应用开发时，若遇到http流式请求接口失败，请用catch捕获错误；若http流式请求接口失败错误码是2300998，可以到[AppGallery Connect](https://developer.huawei.com/consumer/cn/service/josp/agc/index.html)完成服务器域名相关配置，可参考此[指导文档](https://developer.huawei.com/consumer/cn/doc/atomic-guides-V5/agc-help-harmonyos-server-domain-V5)。
