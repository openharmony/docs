# 分布式文件子系统Changelog

## file-access-across-devices 接口行为变更

**访问级别**

公开接口

**变更原因**

针对分布式场景的同WIFI下设备间会自动建链，不同WIFI下设备间无法自动建链的功能。
该功能的规格受限于同WIFI场景，和全场景不符合，并且存在功耗大的问题。

**变更影响**

变更后需要应用通过主动调用接口触发建链，适用于同WIFI和不同WIFI的场景。


**起始 API Level**

API11

**变更发生版本**

从OpenHarmony SDK 5.0.0.39版本开始。

**变更的接口/组件**

| 名称              | 描述        |
|-----------------|-----------|
| file-access-across-devices | 跨设备文件访问能力 |

**适配指导**

分布式组网和访问跨设备文件参考代码如下
https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/file-management/file-access-across-devices.md


