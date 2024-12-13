# ArkWeb子系统Changelog

## cl.arkweb.1 onErrorReceive接口在首次加载woff等在线字体资源不再触发的行为变更

**访问级别**

公开接口

**变更原因**

woff等在线字体资源首次加载时不再指定仅从缓存中读取。

**变更影响**

该变更为兼容性变更。

变更前：首次加载woff等在线字体资源时，会触发错误码为-400（ERR_CACHE_MISS）的onErrorReceive回调。

变更后：首次加载woff等在线字体资源时，不再触发错误码为-400（ERR_CACHE_MISS）的onErrorReceive回调。


**起始API Level**

API 8。

**变更发生版本**

从OpenHarmony SDK 5.0.0.53 版本开始。

**变更的接口/组件**

web.d.ts的onErrorReceive接口。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。