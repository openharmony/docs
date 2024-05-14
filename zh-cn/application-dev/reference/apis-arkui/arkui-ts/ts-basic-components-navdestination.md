# NavDestination

作为子页面的根容器，用于显示[Navigation](ts-basic-components-navigation.md)的内容区。

> **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 该组件从API Version 11开始默认支持安全区避让特性(默认值为：expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM]))，开发者可以重写该属性覆盖默认行为，API Version 11之前的版本需配合[expandSafeArea](ts-universal-attributes-expand-safe-area.md)属性实现安全区避让。
>
> NavDestination组件必须配合Navigation使用，作为Navigation目的页面的根节点。
>
> 如果页面栈中间页面的生命周期发生变化，跳转之前的栈顶Destination的生命周期(onWillShow, onShown, onHidden, onWillDisappear)与跳转之后的栈顶Destination的生命周期(onWillShow, onShown, onHidden, onWillDisappear)均在最后触发。

## 子组件

> **说明：**
>
> - 子组件类型：系统组件和自定义组件，支持渲染控制类型（[if/else](../../../quick-start/arkts-rendering-control-ifelse.md)、[ForEach](../../../quick-start/arkts-rendering-control-foreach.md)和[LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)）。
> - 子组件个数：多个。


## 接口

NavDestination()

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

## 属性

仅支持[backgroundColor](ts-universal-attributes-background.md#backgroundcolor)通用属性。

### title

title(value: string | CustomBuilder | NavDestinationCommonTitle | NavDestinationCustomTitle, options?: NavigationTitleOptions)

设置页面标题。使用NavigationCustomTitle类型设置height高度时，titleMode属性不会生效。字符串超长时，如果不设置副标题，先缩小再换行2行后以...截断。如果设置副标题，先缩小后以...截断。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明       |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| value  | string&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8)&nbsp;\|&nbsp;[NavigationCommonTitle](ts-basic-components-navigation.md#navigationcommontitle9类型说明)&nbsp;\|&nbsp;[NavigationCustomTitle](ts-basic-components-navigation.md#navigationcustomtitle9类型说明) | 是   | 页面标题。 |
| options<sup>12+</sup> | [NavigationTitleOptions](ts-basic-components-navigation.md#navigationtitleoptions11类型说明) | 否   | 标题栏选项。 |

### hideTitleBar

hideTitleBar(value: boolean)

设置是否隐藏标题栏。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 是否隐藏标题栏。<br/>默认值：false<br/>true:&nbsp;隐藏标题栏。<br/>false:&nbsp;显示标题栏。 |

### mode <sup>11+</sup>

mode(value: NavDestinationMode)

设置NavDestination类型。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                 | 必填 | 说明                                                         |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [NavDestinationMode](#navdestinationmode枚举说明-11) | 是   | NavDestination类型。<br/>默认值: NavDestinationMode.STANDARD |

### backButtonIcon<sup>11+</sup>

backButtonIcon(value: ResourceStr | PixelMap)

设置标题栏返回键图标。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | [ResourceStr](ts-types.md#resourcestr)&nbsp;\|&nbsp;[PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) | 是   | 标题栏返回键图标。 |

### menus<sup>12+</sup>

menus(value: Array&lt;NavigationMenuItem&gt; | CustomBuilder)

设置页面右上角菜单。不设置时不显示菜单项。使用Array<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem类型说明)&gt; 写法时，竖屏最多支持显示3个图标，横屏最多支持显示5个图标，多余的图标会被放入自动生成的更多图标。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | Array<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem类型说明)&gt;&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8) | 是   | 页面右上角菜单。 |

## NavDestinationMode枚举说明 <sup>11+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称   | 描述                                       |
| ---- | ---------------------------------------- |
| STANDARD | 标准模式的NavDestination。                       |
| DIALOG | 默认透明，进出页面栈不影响下层NavDestination的生命周期，不支持系统转场动画。    |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持如下事件：

### onShown<sup>10+</sup>

onShown(callback:&nbsp;()&nbsp;=&gt;&nbsp;void)

当该NavDestination页面显示时触发此回调。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onHidden<sup>10+</sup>

onHidden(callback:&nbsp;()&nbsp;=&gt;&nbsp;void)

当该NavDestination页面隐藏时触发此回调。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onWillAppear<sup>12+</sup>

onWillAppear(callback:&nbsp;()&nbsp;=&gt;&nbsp;void)

当该Destination挂载之前触发此回调。在该回调中允许修改页面栈，当前帧生效。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onWillShow<sup>12+</sup>

onWillShow(callback:&nbsp;()&nbsp;=&gt;&nbsp;void)

当该Destination显示之前触发此回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onWillHide<sup>12+</sup>

onWillHide(callback:&nbsp;()&nbsp;=&gt;&nbsp;void)

当该Destination隐藏之前触发此回调。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onWillDisappear<sup>12+</sup>

onWillDisappear(callback:&nbsp;()&nbsp;=&gt;&nbsp;void)

当该Destination卸载之前触发的生命周期(有转场动画时，在转场动画开始之前触发)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onBackPressed<sup>10+</sup>

当与Navigation绑定的页面栈中存在内容时，此回调生效。当点击返回键时，触发该回调。

返回值为true时，表示重写返回键逻辑，返回值为false时，表示回退到上一个页面。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onReady<sup>11+</sup>

onReady(callback:&nbsp;[Callback](../../apis-basic-services-kit/js-apis-base.md#callback)<[NavDestinationContext](#navdestinationcontext11类型说明)>)

当NavDestination即将构建子组件之前会触发此回调。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## NavDestinationContext<sup>11+</sup>类型说明

| 名称   | 类型     | 描述     |
| ---- | ------ | ------ |
| pathInfo | [NavPathInfo](ts-basic-components-navigation.md#navpathinfo10) | 跳转NavDestination时指定的参数。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| pathStack  | [NavPathStack](ts-basic-components-navigation.md#navpathstack10) | 当前NavDestination所处的页面栈。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |

### getConfigInRouteMap<sup>12+</sup>

getConfigInRouteMap(): RouteMapConfig |undefined

**返回值**

| 类型 | 说明 |
| --- | --- |
| [RouteMapConfig](#routemapconfig12类型说明) | 当前页面路由配置信息。 |
| undefined | 当该页面不是通过路由表配置时返回undefined。 |

## RouteMapConfig<sup>12+</sup>类型说明

| 名称   | 类型   | 描述 |
| ----  | ---   | ----- |
| name  | string | 页面名称。|
| pageSourceFile| string | 页面在当前包中的路径。|
| data | object | 页面自定义字段信息。|

## 示例

NavDestination用法可参考[Navigation示例](ts-basic-components-navigation.md#示例1)。
