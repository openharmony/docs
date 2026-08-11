# Panel

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

<!--deprecated_code_no_check-->
可滑动面板，提供一种轻量的内容展示窗口，方便在不同尺寸中切换。

>  **说明：**
>
>  从API version 12开始，该组件不再维护，推荐使用通用属性[bindSheet](ts-universal-attributes-sheet-transition.md#bindsheet)。
>
>  该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含子组件。

>  **说明：**
>
>  子组件类型：系统组件和自定义组件，支持渲染控制类型（[if/else](../../../ui/rendering-control/arkts-rendering-control-ifelse.md)、[ForEach](../../../ui/rendering-control/arkts-rendering-control-foreach.md)和[LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md)）。


## 接口

Panel(show: boolean)

滑动面板组件。

> **说明：**
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[bindSheet](./ts-universal-attributes-sheet-transition.md#bindsheet)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| show | boolean | 是 | 控制Panel显示或隐藏，true表示显示面板，false表示隐藏面板。<br>**说明：** <br>如果设置为false时，则不占位隐藏。[Visibility](ts-appendix-enums.md#visibility).None或show之间有一个生效时，都会生效不占位隐藏。<br>属性show的优先级高于此参数，当属性show被设置时，本参数可能不生效。 |

## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性：

### type

type(value: PanelType)

可滑动面板的类型。type属性值制约其他属性的使用：当type为Minibar时，PanelMode.Half不生效；当type为Temporary时，PanelMode.Mini不生效；当type为CUSTOM时，不支持尺寸切换效果，需配合customHeight属性使用；当type为Foldable时，所有PanelMode值均可用，可配合fullHeight、halfHeight、miniHeight属性设置各状态高度。

> **说明：**
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的preferType替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | [PanelType](#paneltype枚举说明) | 是   | 设置可滑动面板的类型。<br>默认值：PanelType.Foldable |

### mode

mode(value: PanelMode)

可滑动面板的初始状态。

> **说明：**
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的preferType替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | [PanelMode](#panelmode枚举说明) | 是   | 设置可滑动面板的初始状态。<br>Minibar类型默认值：PanelMode.Mini；其余类型默认值：PanelMode.Half<br>从API version 10开始，该属性支持[$$](../../../ui/state-management/arkts-two-way-sync.md)双向绑定变量。 |

### dragBar

dragBar(value: boolean)

设置是否存在控制条。

> **说明：**
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的dragBar替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | boolean | 是   | 设置是否存在控制条，true表示存在，false表示不存在。<br>默认值：true |

### customHeight<sup>10+</sup>

customHeight(value: Dimension | PanelHeight)

指定PanelType.CUSTOM状态下的高度。此属性仅在[type](#type)设置为PanelType.CUSTOM时生效，使用PanelHeight.WRAP_CONTENT时高度自适应内容，使用Dimension值时设置固定高度。

> **说明：**
>
> 从API version 10开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的height替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | [Dimension](ts-types.md#dimension10)&nbsp;\|&nbsp;[PanelHeight](#panelheight10枚举说明) | 是   | 指定PanelType.CUSTOM状态下的高度。<br>默认值：0<br>**说明：** <br>不支持设置百分比，传入百分比时不生效。传入负数时不生效。 |

### fullHeight

fullHeight(value: number | string)

指定PanelMode.Full状态下的高度。

> **说明：**
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的height替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                       | 必填 | 说明                                                         |
| ------ | -------------------------- | ---- | ------------------------------------------------------------ |
| value  | number&nbsp;\|&nbsp;string | 是   | 指定PanelMode.Full状态下的高度。<br>默认值：当前组件主轴大小减去8vp空白区<br>单位：vp<br>**说明：** <br>不支持设置百分比。 |

### halfHeight

halfHeight(value: number | string)

指定PanelMode.Half状态下的高度。

> **说明：**
>
> 此属性仅在type为Foldable或Temporary时生效。当type为Minibar时，Half模式不生效，halfHeight设置无效。
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的height替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                       | 必填 | 说明                                                         |
| ------ | -------------------------- | ---- | ------------------------------------------------------------ |
| value  | number&nbsp;\|&nbsp;string | 是   | 指定PanelMode.Half状态下的高度。<br>默认值：当前组件主轴大小的一半。<br>单位：vp<br>**说明：** <br>不支持设置百分比。 |

### miniHeight

miniHeight(value: number | string)

指定PanelMode.Mini状态下的高度。

> **说明：**
>
> 此属性仅在type为Minibar或Foldable时生效。当type为Temporary时，Mini模式不生效，miniHeight设置无效。
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的height替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                       | 必填 | 说明                                                         |
| ------ | -------------------------- | ---- | ------------------------------------------------------------ |
| value  | number&nbsp;\|&nbsp;string | 是   | 指定PanelMode.Mini状态下的高度。<br>默认值：48<br>单位：vp<br>**说明：** <br>不支持设置百分比。 |

### show

show(value: boolean)

当滑动面板弹出时调用。

> **说明：**
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#bindsheet)中的isShow替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | boolean | 是   | 当滑动面板弹出时调用，true显示面板，false不显示面板。 <br>默认值：true<br>**说明：** <br>该属性的优先级高于参数show。 |

### backgroundMask<sup>9+</sup>

backgroundMask(color: ResourceColor)

指定Panel的背景蒙层。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的maskColor替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| color   | [ResourceColor](ts-types.md#resourcecolor) | 是   | 指定Panel的背景蒙层。<br>默认值：'#08182431' |

### showCloseIcon<sup>10+</sup>

showCloseIcon(value: boolean)

设置是否显示关闭图标。

> **说明：**
>
> 从API version 10开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的showClose替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | boolean | 是   | 设置是否显示关闭图标，true表示显示，false表示不显示。<br>默认值：false |

## PanelType枚举说明

> **说明：**
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[SheetSize](./ts-universal-attributes-sheet-transition.md#sheetsize枚举说明)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| Minibar | 0 | 提供Minibar和类全屏展示切换效果。 |
| Foldable | 1 | 内容始终展示，提供大（类全屏）、中（类半屏）、小三种尺寸展示切换效果。 |
| Temporary | 2 | 内容临时展示，提供大（类全屏）、中（类半屏）两种尺寸展示切换效果。 |
| CUSTOM<sup>10+</sup> | 3 | 配置自适应内容高度，不支持尺寸切换效果。 |

## PanelMode枚举说明

> **说明：**
>
> 从API version 7开始支持，从API version 12开始废弃。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| Mini |0| 类型为Minibar和Foldable时，为最小状态；类型为Temporary，则不生效。|
| Half | 1 | 类型为Foldable和Temporary时，为类半屏状态；类型为Minibar，则不生效。 |
| Full |2  | 类型为Minibar、Foldable和Temporary时，为类全屏状态；类型为CUSTOM，则不生效。 |

## PanelHeight<sup>10+</sup>枚举说明

> **说明：**
>
> 从API version 10开始支持，从API version 12开始废弃。建议使用[SheetSize](./ts-universal-attributes-sheet-transition.md#sheetsize枚举说明)替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| WRAP_CONTENT | 'wrapContent' | [PanelType](#paneltype枚举说明)的类型为CUSTOM时，自适应内容高度。 |

## 事件

除支持[通用事件](ts-component-general-events.md)外，还支持以下事件：

### onChange

onChange(event:&nbsp;(width:&nbsp;number,&nbsp;height:&nbsp;number,&nbsp;mode:&nbsp;PanelMode)&nbsp;=&gt;&nbsp;void)

当可滑动面板发生状态变化时触发。与onHeightChange的区别：onChange在面板模式切换时触发，返回宽高和模式信息；onHeightChange在面板高度变化时触发，仅返回高度值。需要感知模式切换时使用onChange，仅需感知高度变化时使用onHeightChange。

> **说明：**
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的onTypeDidChange替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型        | 必填 | 说明                                                                                  |
| --------- | ---------  | ---- | ------------------------------------------------------------------------------------ |
| width     | number     | 是   | 内容区的宽度值，单位：vp。                                                                     |
| height    | number     | 是   | 内容区的高度值，单位：vp。<br>当dragBar属性为true时，Panel本身的高度值为dragBar高度加上内容区高度。 |
| mode      | [PanelMode](#panelmode枚举说明)  | 是   | 面板的状态。                                                                           |

### onHeightChange<sup>9+</sup>

onHeightChange(callback: (value: number) => void)

当可滑动面板发生高度变化时触发。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃。建议使用[SheetOptions](./ts-universal-attributes-sheet-transition.md#sheetoptions)中的onHeightDidChange替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型                                                | 必填 | 说明       |
| --------- | --------------------------------------------------- | ---- | ---------- |
| value     | number  | 是   | 内容区的高度值，默认返回值单位为px。<br>当dragBar属性为true时，Panel本身的高度值为dragBar高度加上内容区高度。<br>因用户体验设计原因，Panel最高只能滑到fullHeight-8vp。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct PanelExample {
  @State show: boolean = false

  build() {
    Column() {
      Text('2021-09-30    Today Calendar: 1.afternoon......Click for details')
        .width('90%')
        .height(50)
        .borderRadius(10)
        .backgroundColor(0xFFFFFF)
        .padding({ left: 20 })
        .onClick(() => {
          this.show = !this.show;
        })
      Panel(this.show) { // 展示日程
        Column() {
          Text('Today Calendar')
          Divider()
          Text('1. afternoon 4:00 The project meeting')
        }
      }
      .type(PanelType.Foldable)
      .mode(PanelMode.Half)
      .dragBar(true) // 默认开启
      .halfHeight(500) // 设置半屏高度为500，默认为当前组件主轴大小的一半
      .showCloseIcon(true) // 显示关闭图标
      .onChange((width: number, height: number, mode: PanelMode) => {
        console.info(`width:${width},height:${height},mode:${mode}`);
      })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![panel](figures/panel.gif)
