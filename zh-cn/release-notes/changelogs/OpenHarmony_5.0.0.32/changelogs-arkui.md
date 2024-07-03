## cl.arkui.1 UIExtensionComponent以及CreateModalUIExtension增加使用约束

**访问级别**

系统接口

**变更原因**

UIExtensionComponent以及CreateModalUIExtension增加使用约束

**变更影响**

该变更为非兼容性变更。

UIExtensionComponent增加系统应用访问校验

CreateModalUIExtension增加禁止其他组件遮挡的校验逻辑

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

UIExtensionComponent以及CreateModalUIExtension

**适配指导**

使用UIExtensionComponent的必须为系统应用

CreateModalUIExtension禁止其他组件遮挡
