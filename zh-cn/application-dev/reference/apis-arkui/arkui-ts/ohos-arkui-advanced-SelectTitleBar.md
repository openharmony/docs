# SelectTitleBar


下拉菜单标题栏包含一个下拉菜单，可用于页面之间的切换；可用于一级页面、二级及其以上界面（配置返回键）。


> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { SelectTitleBar } from '@kit.ArkUI'
```


## 子组件

无

## 属性
不支持[通用属性](ts-universal-attributes-size.md)

## SelectTitleBar

SelectTitleBar({selected: number, options: Array&lt;SelectOption&gt;, menuItems?: Array&lt;SelectTitleBarMenuItem&gt;, subtitle?: ResourceStr, badgeValue?: number, hidesBackButton?: boolean, onSelected?: (index: number) =&gt; void})

**装饰器类型：**\@Component

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称 | 参数类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| selected | number | 是 | \@Prop | 当前选中项目的索引。<br>第一项的索引为0。如果不设置该属性，则默认值为0。 |
| options | Array&lt;[SelectOption](ts-basic-components-select.md#selectoption对象说明)&gt; | 是 | - | 下拉菜单中的项目。 |
| menuItems | Array&lt;[SelectTitleBarMenuItem](#selecttitlebarmenuitem)&gt;              | 否 | - | 右侧菜单项目列表，定义标题栏右侧的菜单项目。 |
| subtitle | [ResourceStr](ts-types.md#resourcestr)                                      | 否 | - | 子标题。 |
| badgeValue | number                                                                      | 否 | - | 新事件标记。<br>取值范围：[-2147483648,2147483647]，超出范围时会加上或减去4294967296，使得值仍在范围内，非整数时会舍去小数部分取整数部分，如5.5取5。<br>**说明：** 小于等于0时不显示信息标记。<br>最大消息数99，超过最大消息时仅显示99+。超大数值属于异常值，不显示信息标记。 |
| hidesBackButton | boolean                                                                     | 否 | - | 是否隐藏左侧的返回箭头。<br>默认值：false。true：隐藏，false：显示。|
| onSelected | (index:&nbsp;number)&nbsp;=&gt;&nbsp;void                                   | 否 | - | 下拉菜单项目选中触发的回调函数，传入选中项的索引。 |

> **说明：**
> 
> 入参对象不可为undefined，即`SelectTitleBar(undefined)`。

## SelectTitleBarMenuItem

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | 是 | 图标资源。 |
| isEnabled | boolean | 否 | 是否启用。<br>默认值：false。true：启用，false：禁用。 |
| action | ()&nbsp;=&gt;&nbsp;void | 否 | 触发时的动作闭包。 |

## 事件
不支持[通用事件](ts-universal-events-click.md)

## 示例

该示例实现了简单的下拉菜单标题栏，带有返回箭头的下拉菜单标题栏和带有右侧菜单项目列表的下拉菜单标题栏。

```ts
import { SelectTitleBar, promptAction } from '@kit.ArkUI'

interface menuItems {
  value: Resource;
  isEnabled?: boolean;
  action?: () => void
}  

@Entry
@Component
struct Index {
  //定义右侧菜单项目列表
  private  menuItems:Array<menuItems> =
  [
    {
      //菜单图片资源
      value:$r('app.media.ic_public_save'),
      //启用图片
      isEnabled:true,
      //点击菜单时触发事件
      action:() => promptAction.showToast({ message: "show toast index 1" })
    },
    {
      value:$r('app.media.ic_public_reduce'),
      isEnabled:true,
      action:() => promptAction.showToast({ message: "show toast index 2" })
    },
    {
      value:$r('app.media.ic_public_edit'),
      isEnabled:true,
      action:() => promptAction.showToast({ message: "show toast index 3" })
    },
    {
      value:$r('app.media.ic_public_reduce'),
      isEnabled:true,
      action:() => promptAction.showToast({ message: "show toast index 4" })
    }
  ]

  build() {
    Row() {
      Column() {
		Divider().height(2).color(0xCCCCCC)
        SelectTitleBar({
          //定义下拉列表选项
          options: [
            { value: '所有照片' },
            { value: '本地（设备）' },
            { value: '本地本地本地本地本地（储存卡）' }
          ],
          //初始选择第一个下拉选项
          selected: 0,
          //选中时触发函数
          onSelected: (index) => promptAction.showToast({ message: 'page index ' + index }),
          //隐藏左侧返回箭头
          hidesBackButton: true
        })
        Divider().height(2).color(0xCCCCCC)
        SelectTitleBar({
          options: [
            { value: '所有照片' },
            { value: '本地（设备）' },
            { value: '本地本地本地本地本地（储存卡）' }
          ],
          selected: 0,
          onSelected: (index) => promptAction.showToast({ message: 'page index ' + index }),
          hidesBackButton: false
        })
        Divider().height(2).color(0xCCCCCC)
        SelectTitleBar({
          options: [
            { value: '所有照片' },
            { value: '本地（设备）' },
            { value: '本地本地本地本地本地（储存卡）' }
          ],
          selected: 1,
          onSelected: (index) => promptAction.showToast({ message: 'page index ' + index }),
          subtitle: "example@example.com"
        })
        Divider().height(2).color(0xCCCCCC)
        SelectTitleBar({
          options: [
            { value: '所有照片' },
            { value: '本地（设备）' },
            { value: '本地本地本地本地本地（储存卡）' }
          ],
          selected: 1,
          onSelected: (index) => promptAction.showToast({ message: 'page index ' + index }),
          subtitle: "example@example.com",
          menuItems: [{ isEnabled: true, value: $r('app.media.ic_public_save'),
            action: () => promptAction.showToast({ message: "show toast index 1" })
          }]
        })
        Divider().height(2).color(0xCCCCCC)
        SelectTitleBar({
          options: [
            { value: '所有照片' },
            { value: '本地（设备）' },
            { value: '本地本地本地本地本地（储存卡）' }
          ],
          selected: 0,
          onSelected: (index) => promptAction.showToast({ message: 'page index ' + index }),
          subtitle: "example@example.com",
          menuItems: this.menuItems,
          badgeValue: 99,
          hidesBackButton: true
        })
        Divider().height(2).color(0xCCCCCC)
      }.width('100%')
    }.height('100%')
  }
}
```

![zh-cn_image_0000001616959836](figures/zh-cn_image_0000001616959836.jpg)
