# ArkWeb子系统Changelog

## cl.arkweb.1 fileAccess接口行为变更

**访问级别**

公开接口

**变更原因**

API version 11及之前，fileAccess为false的时候，应用使用file协议依然可以加载部分可读可写目录，造成注入攻击的安全问题。同时将fileAccess默认值变更为false，提高应用安全性。

**变更影响**

从API version 12开始，fileAccess的默认值变为false，如果应用不手动设置fileAccess属性，则默认ArkWeb不允许file协议的加载，应用只读资源目录/data/storage/el1/bundle/entry/resources/resfile除外。

**起始API Level**

起始版本API 8，变更版本为API 12。

**变更发生版本**

从OpenHarmony SDK 5.0.0.29 版本开始。

**变更的接口/组件**

变更前接口行为

| 名称             | 默认值               | 描述                   |
| -------------- | ---------------- | -------------------- |
| fileAccess  | true | 默认允许file协议访问，同时当fileAccess设置为false的时候，应用沙箱路径/data/storage/el2/base和/data/storage/el1/bundle目录下的文件依然可以用file协议访问。 |

变更后接口行为

| 名称             | 默认值               | 描述                   |
| -------------- | ---------------- | -------------------- |
| fileAccess  | false | 默认不允许file协议访问，同时当fileAccess设置为false的时候，仅应用沙箱路径/data/storage/el1/bundle/entry/resources/resfile目录下的文件依然可以用file协议访问。 |

**适配指导**

影响应用使用ArkWeb加载本地file协议资源。如果需要使用file协议加载本地资源（以下方法任选其一）：

1.设置fileAccess为true。

2.使用资源拦截的方式加载本地文件，具体参考[解决Web组件本地资源跨域问题](../../../application-dev/web/web-cross-origin.md)。

