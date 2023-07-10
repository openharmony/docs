# ArkUI子系统ChangeLog

## cl.arkui.1 uiAppearance部分谓词由公共接口变更为系统接口

命名空间uiAppearance及其内部DarkMode枚举谓词由公共接口变更为系统接口。

**变更影响**

无影响。规范性整改，命名空间uiAppearance及其内部DarkMode枚举类型修改前后均只被系统接口使用

**关键接口/组件变更**

如下接口添加系统接口systemapi说明：

- declare namespace uiAppearance

- enum DarkMode

- ALWAYS_DARK = 0

- ALWAYS_LIGHT = 1