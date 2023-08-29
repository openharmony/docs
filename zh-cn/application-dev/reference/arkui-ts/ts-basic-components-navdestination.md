# NavDestination

作为NavRouter组件的子组件，用于显示导航内容区。

> **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

> **说明：**
>
> - 子组件类型：系统组件和自定义组件，支持渲染控制类型（[if/else](../../quick-start/arkts-rendering-control-ifelse.md)、[ForEach](../../quick-start/arkts-rendering-control-foreach.md)和[LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)）。
> - 子组件个数：多个。


## 接口

NavDestination()


## 属性

仅支持[backgroundColor](ts-universal-attributes-background.md)通用属性。

| 名称         | 参数类型                                                     | 描述                                                         |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| title        | string&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8)&nbsp;\|&nbsp;[NavigationCommonTitle](ts-basic-components-navigation.md#navigationcommontitle类型说明)&nbsp;\|&nbsp;[NavigationCustomTitle](ts-basic-components-navigation.md#navigationcustomtitle类型说明) | 页面标题。<br/>**说明：** <br/>使用NavigationCustomTitle类型设置height高度时，titleMode属性不会生效。<br/>字符串超长时，如果不设置副标题，先缩小再换行2行后以...截断。如果设置副标题，先缩小后以...截断。 |
| hideTitleBar | boolean                                                      | 是否显示标题栏。<br/>默认值：false<br/>true:&nbsp;隐藏标题栏。<br/>false:&nbsp;显示标题栏。 |

## 事件

支持[通用事件](ts-universal-events-click.md)。