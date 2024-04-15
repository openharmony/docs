# ArkUI子系统Changelog

## cl.arkui.1  Image组件按照syncLoad来同步/异步加载PixelMap格式图片

**访问级别**

公开接口

**变更原因**

应用侧的某些实现场景需要Image组件支持异步加载pixelMap。

**变更影响**

该变更为非兼容性变更。

API version 11及以前，Image组件加载PixelMap始终为同步加载。

API version 12及以后，Image组件按照syncLoad来同步/异步加载PixelMap格式图片，若没有设置则按照syncLoad为false进行异步加载。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**示例：**

无

**变更的接口/组件**

Image组件

**适配指导**

若应用侧需要Image组件同步加载pixelmap，则需要设置syncLoad为true。

## cl.arkui.2 bindMenu新增指向性菜单样式

**访问级别**

公开接口

**变更原因**

UX规格增强

**变更影响**

该变更为非兼容性变更。

变更前：在bindMenu的MenuOptions中将enableArrow属性设为true时，不展示指向性菜单样式。

变更后：在bindMenu的MenuOptions中将enableArrow属性设为true且菜单的大小和位置足以放置箭头时，会展示指向性菜单样式。

**API Level**

enableArrow、arrowOffset属性的起始支持版本为API version 10。

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**适配指导**

如果不需要bindMenu展示指向性菜单样式，在bindMenu的MenuOptions中不设置enableArrow属性或将enableArrow属性设置为false；
如果需要bindMenu展示指向性菜单样式，在bindMenu的MenuOptions中将enableArrow属性设置为true，并根据需要决定是否设置arrowOffset属性值。

## cl.arkui.3 应用可获焦的默认行为变更

**访问级别**

公开接口

**变更原因**

优化默认走焦行为。

**变更影响**

该变更为非兼容性变更。

变更前：有获焦能力但默认不可获焦的组件，需要通过配置属性`.focusable(true)`使得自身可获焦，且走焦时没有默认焦点框，需要配置焦点态样式。

变更后：注册了onClick或者单指单击手势的组件默认可获焦，走焦时无需配置焦点态样式也能显示默认焦点框。

**API Level**

该特性变更起始支持版本为 API 12。

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**适配指导**

可点击组件不希望参与走焦，需要显示配置`.focusable(false)`；

