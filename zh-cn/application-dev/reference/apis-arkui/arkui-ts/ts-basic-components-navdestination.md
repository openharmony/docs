# NavDestination

作为子页面的根容器，用于显示[Navigation](ts-basic-components-navigation.md)的内容区。

> **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 该组件从API Version 11开始默认支持安全区避让特性(默认值为：expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.TOP, SafeAreaEdge.BOTTOM]))，开发者可以重写该属性覆盖默认行为，API Version 11之前的版本需配合[expandSafeArea](ts-universal-attributes-expand-safe-area.md)属性实现安全区避让。
>
> NavDestination组件必须配合Navigation使用，作为Navigation目的页面的根节点，单独使用只能作为普通容器组件，不具备路由相关属性能力。
>
> 如果页面栈中间页面的生命周期发生变化，跳转之前的栈顶Destination的生命周期(onWillShow, onShown, onHidden, onWillDisappear)与跳转之后的栈顶Destination的生命周期(onWillShow, onShown, onHidden, onWillDisappear)均在最后触发。

## 子组件

> **说明：**
>
> - 子组件类型：系统组件和自定义组件，支持渲染控制类型（[if/else](../../../quick-start/arkts-rendering-control-ifelse.md)、[ForEach](../../../quick-start/arkts-rendering-control-foreach.md)和[LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)）。
> - 子组件个数：多个。


## 接口

NavDestination()

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## 属性

支持[通用属性](ts-universal-attributes-size.md)。

不推荐设置位置、大小等布局相关属性，可能会造成页面显示异常。

### title

title(value: string | CustomBuilder | NavDestinationCommonTitle | NavDestinationCustomTitle, options?: NavigationTitleOptions)

设置页面标题。使用NavigationCustomTitle类型设置height高度时，[titleMode](ts-basic-components-navigation.md#titlemode)属性不会生效。字符串超长时，如果不设置副标题，先缩小再换行2行后以...截断。如果设置副标题，先缩小后以...截断。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明       |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| value  | string&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8)&nbsp;\|&nbsp;[NavDestinationCommonTitle](#navdestinationcommontitle)&nbsp;\|&nbsp;[NavDestinationCustomTitle](#navdestinationcustomtitle)  | 是   | 页面标题。 |
| options<sup>12+</sup> | [NavigationTitleOptions](ts-basic-components-navigation.md#navigationtitleoptions11) | 否   | 标题栏选项。 |

### hideTitleBar

hideTitleBar(value: boolean)

设置是否隐藏标题栏。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 是否隐藏标题栏。<br/>默认值：false<br/>true:&nbsp;隐藏标题栏。<br/>false:&nbsp;显示标题栏。 |

### hideTitleBar<sup>13+</sup>

hideTitleBar(hide: boolean, animated: boolean)

设置是否隐藏标题栏，设置是否使用动画显隐标题栏。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| hide  | boolean | 是   | 是否隐藏标题栏。<br/>默认值：false<br/>true: 隐藏标题栏。<br/>false: 显示标题栏。 |
| animated  | boolean | 是   | 设置是否使用动画显隐标题栏。<br/>默认值：false<br/>true: 使用动画显示隐藏标题栏。<br/>false: 不使用动画显示隐藏标题栏。 |

### toolbarConfiguration<sup>14+</sup>

toolbarConfiguration(toolbarParam: Array&lt;ToolbarItem&gt; | CustomBuilder, options?: NavigationToolbarOptions)

设置工具栏内容。未调用本接口时不显示工具栏。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| toolbarParam | &nbsp;Array&lt;[ToolbarItem](ts-basic-components-navigation.md#toolbaritem10)&gt; &nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8) | 是   | 工具栏内容。<br/>使用Array&lt;[ToolbarItem](ts-basic-components-navigation.md#toolbaritem10)&gt;写法设置的工具栏有如下特性：<br/>-工具栏所有选项均分底部工具栏，在每个均分内容区布局文本和图标。<br/>-文本超长时，若工具栏选项个数小于5个，优先拓展选项的宽度，工具栏最大宽度与屏幕等宽，其次逐级缩小，缩小之后换行，最后...截断。<br/>-竖屏最多支持显示5个图标，多余的图标会被放入自动生成的更多图标中，点击更多图标，可以展示剩余内容。横屏时，如果为[Split](ts-basic-components-navigation.md#navigationmode9枚举说明)模式，仍按照竖屏规则显示，如果为[Stack](ts-basic-components-navigation.md#navigationmode9枚举说明)模式需配合menus属性的Array&lt;[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)&gt;使用，底部工具栏会自动隐藏，同时底部工具栏所有选项移动至页面右上角菜单。<br/>使用[CustomBuilder](ts-types.md#custombuilder8)写法为用户自定义工具栏选项，除均分底部工具栏外不具备以上功能。 |
| options      | [NavigationToolbarOptions](ts-basic-components-navigation.md#navigationtoolbaroptions11) | 否   | 工具栏选项。                                                 |

> **说明：**
>
> 不支持通过SymbolGlyphModifier对象的fontSize属性修改图标大小、effectStrategy属性修改动效、symbolEffect属性修改动效类型。

### hideToolBar<sup>13+</sup>

hideToolBar(hide: boolean, animated?: boolean)

设置是否隐藏工具栏，设置是否使用动画显隐工具栏。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| hide  | boolean | 是   | 是否隐藏工具栏。<br/>默认值：false<br/>true: 隐藏工具栏。<br/>false: 显示工具栏。 |
| animated  | boolean | 否   | 设置是否使用动画显隐工具栏。<br/>默认值：false<br/>true: 使用动画显示隐藏工具栏。<br/>false: 不使用动画显示隐藏工具栏。 |

### mode <sup>11+</sup>

mode(value: NavDestinationMode)

设置NavDestination类型，不支持动态修改。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                 | 必填 | 说明                                                         |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [NavDestinationMode](#navdestinationmode枚举说明-11) | 是   | NavDestination类型。<br/>默认值: NavDestinationMode.STANDARD |

### backButtonIcon<sup>11+</sup>

backButtonIcon(value: ResourceStr | PixelMap | SymbolGlyphModifier)

> **说明：**
>
> 不支持通过SymbolGlyphModifier对象的fontSize属性修改图标大小、effectStrategy属性修改动效、symbolEffect属性修改动效类型。


设置标题栏返回键图标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | [ResourceStr](ts-types.md#resourcestr)&nbsp;\|&nbsp;[PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7)&nbsp;\|&nbsp;[SymbolGlyphModifier<sup>12+</sup>](ts-universal-attributes-attribute-modifier.md)  | 是   | 标题栏返回键图标。 |

### menus<sup>12+</sup>

menus(value: Array&lt;NavigationMenuItem&gt; | CustomBuilder)

> **说明：**
>
> 不支持通过SymbolGlyphModifier对象的fontSize属性修改图标大小、effectStrategy属性修改动效、symbolEffect属性修改动效类型。


设置页面右上角菜单。不设置时不显示菜单项。使用Array<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)&gt; 写法时，竖屏最多支持显示3个图标，横屏最多支持显示5个图标，多余的图标会被放入自动生成的更多图标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | Array<[NavigationMenuItem](ts-basic-components-navigation.md#navigationmenuitem)&gt;&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8) | 是   | 页面右上角菜单。 |

### ignoreLayoutSafeArea<sup>12+</sup>

ignoreLayoutSafeArea(types?: Array&lt;LayoutSafeAreaType&gt;, edges?: Array&lt;LayoutSafeAreaEdge&gt;)

控制组件的布局，使其扩展到非安全区域

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                               | 必填 | 说明                                                         |
| ------ | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| types  | Array <[LayoutSafeAreaType](ts-types.md#layoutsafeareatype12)> | 否   | 配置扩展安全区域的类型。<br />默认值: <br />[LayoutSafeAreaType.SYSTEM] |
| edges  | Array <[LayoutSafeAreaEdge](ts-types.md#layoutsafeareaedge12)> | 否   | 配置扩展安全区域的方向。<br /> 默认值: <br />[LayoutSafeAreaEdge.TOP, LayoutSafeAreaEdge.BOTTOM]。|

>  **说明：**
>   
>  组件设置LayoutSafeArea之后生效的条件为：   
>  设置LayoutSafeAreaType.SYSTEM时，组件的边界与非安全区域重合时组件能够延伸到非安全区域下。例如：设备顶部状态栏高度100，组件在屏幕中纵向方位的绝对偏移需要在0到100之间。  
>   
>  若组件延伸到非安全区域内，此时在非安全区域里触发的事件（例如：点击事件）等可能会被系统拦截，优先响应状态栏等系统组件。

### systemBarStyle<sup>12+</sup>

systemBarStyle(style: Optional&lt;SystemBarStyle&gt;)

当Navigation中显示当前NavDestination时，设置对应系统状态栏的样式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型         | 必填 | 说明               |
| ------ | -------------- | ---- | ------------------ |
| style  | Optional&lt;[SystemBarStyle](../js-apis-window.md#systembarstyle12)&gt; | 是   | 系统状态栏样式。 |

> **说明：**
>
> 1. 必须配合Navigation使用，作为其Navigation目的页面的根节点时才能生效。
> 2. 其他使用限制请参考Navigation对应的[systemBarStyle](ts-basic-components-navigation.md#systembarstyle12)属性说明。

## NavDestinationMode枚举说明 <sup>11+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 说明                                     |
| ---- | ---------------------------------------- |
| STANDARD | 标准模式的NavDestination。                       |
| DIALOG | 默认透明，进出页面栈不影响下层NavDestination的生命周期，不支持系统转场动画。    |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持如下事件：

### onShown<sup>10+</sup>

onShown(callback:&nbsp;()&nbsp;=&gt;&nbsp;void)

当该NavDestination页面显示时触发此回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onHidden<sup>10+</sup>

onHidden(callback:&nbsp;()&nbsp;=&gt;&nbsp;void)

当该NavDestination页面隐藏时触发此回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onWillAppear<sup>12+</sup>

onWillAppear(callback: Callback\<void>)

当该Destination挂载之前触发此回调。在该回调中允许修改页面栈，当前帧生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onWillShow<sup>12+</sup>

onWillShow(callback: Callback\<void>)

当该Destination显示之前触发此回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onWillHide<sup>12+</sup>

onWillHide(callback: Callback\<void>)

当该Destination隐藏之前触发此回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onWillDisappear<sup>12+</sup>

onWillDisappear(callback: Callback\<void>)

当该Destination卸载之前触发的生命周期(有转场动画时，在转场动画开始之前触发)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onBackPressed<sup>10+</sup>

onBackPressed(callback:&nbsp;()&nbsp;=&gt;&nbsp;boolean)

当与Navigation绑定的页面栈中存在内容时，此回调生效。当点击返回键时，触发该回调。

返回值为true时，表示重写返回键逻辑，返回值为false时，表示回退到上一个页面。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onReady<sup>11+</sup>

onReady(callback:&nbsp;[Callback](../../apis-basic-services-kit/js-apis-base.md#callback)<[NavDestinationContext](#navdestinationcontext11)>)

当NavDestination即将构建子组件之前会触发此回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## NavDestinationCommonTitle

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型     | 必填   | 说明     |
| ---- | ------ | ---- | ------ |
| main | string | 是    | 设置主标题。 |
| sub  | string | 是    | 设置副标题。 |

## NavDestinationCustomTitle

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                                       | 必填   | 说明       |
| ------- | ---------------------------------------- | ---- | -------- |
| builder | [CustomBuilder](ts-types.md#custombuilder8) | 是    | 设置标题栏内容。 |
| height  | [TitleHeight](ts-appendix-enums.md#titleheight9) \| [Length](ts-types.md#length) | 是    | 设置标题栏高度。 |

## NavDestinationContext<sup>11+</sup>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型     | 必填   |  说明     |
| ---- | ------ | ----- | ------ |
| pathInfo | [NavPathInfo](ts-basic-components-navigation.md#navpathinfo10) | 是 | 跳转NavDestination时指定的参数。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| pathStack  | [NavPathStack](ts-basic-components-navigation.md#navpathstack10) | 是 | 当前NavDestination所处的页面栈。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| navDestinationId<sup>12+</sup> | string | 否 | 当前NavDestination的唯一ID，由系统自动生成，和组件通用属性id无关。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

### getConfigInRouteMap<sup>12+</sup>

getConfigInRouteMap(): RouteMapConfig |undefined

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值**

| 类型 | 说明 |
| --- | --- |
| [RouteMapConfig](#routemapconfig12) | 当前页面路由配置信息。 |
| undefined | 当该页面不是通过路由表配置时返回undefined。 |

## RouteMapConfig<sup>12+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   |必填 | 说明 |
| ----  | ---   | ---- |----- |
| name  | string | 是 | 页面名称。|
| pageSourceFile| string | 是 | 页面在当前包中的路径。|
| data | Object | 是 | 页面自定义字段信息。|

## 示例

NavDestination用法可参考[Navigation示例](ts-basic-components-navigation.md#示例1)。
