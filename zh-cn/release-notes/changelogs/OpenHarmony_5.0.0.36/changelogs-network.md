# 网络管理子系统Changelog

## cl.network.1 webSocket.connect接口新增2302998错误码

**访问级别**

公开接口

**变更原因**

为规范元服务请求域名范围，提升元服务上架审核效率和平台合规经营安全性，当用户使用元服务时，将根据该元服务的域名配置进行域名访问；若是访问未配置域名，则connect接口会返回该错误码。

**变更影响**

该变更为不兼容变更。

API version 11及以下元服务应用访问未配置域名，connect接口不会有任何影响。

API version
12开始，元服务应用访问未配置域名，connect接口抛出该错误码，详情见docs仓[接口文档](../../../application-dev/reference/apis-network-kit/js-apis-webSocket.md)。

**起始 API Level**

6

**变更发生版本**

从OpenHarmony SDK 5.0.0.36 开始。

**变更的接口/组件**

| 接口文件                                                                                                               |
|--------------------------------------------------------------------------------------------------------------------|
| [ohos.net.webSocket.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.net.webSocket.d.ts) |

**适配指导**

开发者在进行元服务应用开发时，涉及webSocket.connect接口建立连接是，先到[AppGallery Connect](https://developer.huawei.com/consumer/cn/service/josp/agc/index.html)
完成服务器域名相关配置，可参考此[指导文档](https://developer.huawei.com/consumer/cn/doc/atomic-guides-V5/agc-help-harmonyos-server-domain-V5)
进行配置。

开发者在进行元服务应用开发时，若遇到webSocket.connect接口失败，请用catch捕获错误；若webSocket.connect接口失败错误码是2302998，可以到[AppGallery Connect](https://developer.huawei.com/consumer/cn/service/josp/agc/index.html)完成服务器域名相关配置，可参考此[指导文档](https://developer.huawei.com/consumer/cn/doc/atomic-guides-V5/agc-help-harmonyos-server-domain-V5)

