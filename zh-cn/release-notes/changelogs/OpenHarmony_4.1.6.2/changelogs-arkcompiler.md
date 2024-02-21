# arkcompiler子系统变更说明

## cl.arkcompiler.1 arkcompiler AOT使能方式变更
**引入版本**

OpenHarmony_4.1.6.2

**变更原因**

AOT使能方式适配user版本

**变更影响**

该变更不属于非兼容性变更，新增对user版本使能AOT的方法

- 变更前：仅对root版本的ROM镜像支持AOT功能
- 变更后：新增对user版本的ROM镜像支持AOT功能

**API Level**

不涉及

**变更发生版本**

OpenHarmony_4.1.6.2

**变更的接口/组件**

arkcompiler AOT使能方式

**适配指导**

参见[AOT编译使用指南](https://gitee.com/openharmony/arkcompiler_ets_runtime/blob/master/docs/aot-guide_zh.md)