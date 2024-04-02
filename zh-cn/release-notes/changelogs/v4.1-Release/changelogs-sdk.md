# SDK子系统Changelog

## cl.sdk.1 api接口对于syscap值校验规则变更

**变更原因**

需要对开发者使用不完全兼容设备syscap集合的接口给出告警提示。

针对单设备场景，使用在设备syscap集合之外的API抛出告警。

针对一多场景，使用在各设备syscap集合交集之外的API抛出告警。

**变更影响**

该变更发生后，在开发者使用不合理的接口时，将出现告警提示，提示内容如下：

"The default system capabilities of devices `<deviceTypes>` do not include system capability of '`<apiName>`'. Configure the capabilities in syscap.json. It may cause your application crush in some devices. Attention: Such illegal interface call will lead to compilation error in the future version!"

表示使用了允许范围之外的API，这部分API在某些设备上可能不支持。在未来的版本中，此类用法将被拦截。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.7 版本开始。

**变更的接口/组件**

只包含编译结果的改变。

**适配指导**

需要使用满足设备系统能力集的接口，且使用的接口需要满足当前应用支持的所有设备。
