# ComposeListItem


列表包含一系列相同宽度的列表项。适合连续、多行呈现同类数据，例如图片和文本。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { ComposeListItem } from "@ohos.arkui.advanced.ComposeListItem"
```


## 子组件

无


## 接口

ComposeListItem({contentItem?: ContentItem, operateItem?: OperateItem})

**装饰器类型：**\@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：**


| 参数名 | 参数类型 | 必填 | 装饰器类型 | 参数描述 | 
| -------- | -------- | -------- | -------- | -------- |
| contentItem | [ContentItem](#contentitem) | 否 | \@Prop | 定义左侧以及中间元素。 | 
| operateItem | [OperateItem](#operateitem) | 否 | \@Prop | 定义右侧元素。 | 


## ContentItem

| 名称 | 值 | 必填 | 描述 | 
| -------- | -------- | -------- | -------- |
| iconStyle | [IconType](#icontype枚举说明) | 否 | 左侧元素-图标样式。 | 
| icon | [ResourceStr](ts-types.md#resourcestr) | 否 | 左侧元素-图标。 | 
| primaryText | [ResourceStr](ts-types.md#resourcestr) | 否 | 中间元素-标题内容。 | 
| secondaryText | [ResourceStr](ts-types.md#resourcestr) | 否 | 中间元素-副标题内容。 | 
| description | [ResourceStr](ts-types.md#resourcestr) | 否 | 中间元素-描述内容。 | 


## IconType枚举说明

| 名称 | 描述 | 
| -------- | -------- |
| BADGE | 左侧图标为badge类型，图标大小为8\*8dp。 | 
| NORMAL_ICON | 左侧图标为小图标类型，图标大小为16\*16dp。 | 
| SYSTEM_ICON | 左侧图标为系统图标类型，图标大小为24\*24dp。 | 
| HEAD_SCULPTURE | 左侧图标为头像类型，图标大小为40\*40dp。 | 
| APP_ICON | 左侧图标为应用图标类型，图标大小为64\*64dp。 | 
| PREVIEW | 左侧图标为预览图类型，图标大小为96\*96dp。 | 
| LONGITUDINAL | 左侧图标为横向特殊比例（宽比高大），保持最长边为96dp。 | 
| VERTICAL | 左侧图标为竖向特殊比例（高比宽大），保持最长边为96dp。 | 


## OperateItem

| 名称 | 值 | 必填 | 描述 | 
| -------- | -------- | -------- | -------- |
| arrow | [OperateIcon](#operateicon) | 否 | 右侧元素-箭头，大小为12\*24dp。 | 
| icon | [OperateIcon](#operateicon) | 否 | 右侧元素-第一个图标，大小为24\*24dp。 | 
| subIcon | [OperateIcon](#operateicon) | 否 | 右侧元素-第二个图标，大小为24\*24dp。 | 
| button | [OperateButton](#operatebutton) | 否 | 右侧元素-按钮。 | 
| switch | [OperateCheck](#switchcheckboxradio-operatecheck) | 否 | 右侧元素-开关。 | 
| checkbox | [OperateCheck](#switchcheckboxradio-operatecheck) | 否 | 右侧元素-多选框，大小为24\*24dp。 | 
| radio | [OperateCheck](#switchcheckboxradio-operatecheck) | 否 | 右侧元素-单选，大小为24\*24dp。 | 
| image | [ResourceStr](ts-types.md#resourcestr) | 否 | 右侧元素-图片，大小为48\*48dp。 | 
| text | [ResourceStr](ts-types.md#resourcestr) | 否 | 右侧元素-文字。 | 


## OperateIcon

| 名称 | 值 | 必填 | 描述 | 
| -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | 是 | 右侧元素-图标/箭头。 | 
| action | ()=&gt;void | 否 | 右侧元素-图标/箭头点击事件。 | 


## OperateButton

| 名称 | 值 | 必填 | 描述 | 
| -------- | -------- | -------- | -------- |
| text | [ResourceStr](ts-types.md#resourcestr) | 否 | 右侧元素-按钮文字。 | 


## Switch/CheckBox/Radio-OperateCheck

| 名称 | 值 | 必填 | 描述 | 
| -------- | -------- | -------- | -------- |
| isCheck | boolean | 否 | 右侧元素-右侧Switch/CheckBox/Radio选中状态。 | 
| onChange | (value:&nbsp;boolean)=&gt;void | 否 | 右侧元素-右侧Switch/CheckBox/Radio选中状态改变时触发回调。 | 


## 示例1-纯文本

```ts
import { ComposeListItem } from '@ohos.arkui.advanced.ComposeListItem';

@Entry
@Component
struct ComposeListItemExample {
  build() {
    Column() {
      List() {
        ListItem(){
          ComposeListItem({
            contentItem: ({
              primaryText: '单行列表'
            })
          })
        }
      }
    }
  }
}
```


![示例1-纯文本](figures/zh-cn_image_2023072903.PNG)


## 示例2-左侧元素+文本

```ts
import { ComposeListItem } from '@ohos.arkui.advanced.ComposeListItem';
import { IconType } from '@ohos.arkui.advanced.ComposeListItem';

@Entry
@Component
struct ComposeListItemExample {
  build() {
    Column() {
      List() {
        ListItem(){
          ComposeListItem({
            contentItem: ({
              iconStyle: IconType.NORMAL_ICON,
              icon: $r('sys.media.ohos_app_icon'),
              primaryText: '双行列表',
              secondaryText: '辅助文字'
            })
          })
        }
      }
    }
  }
}
```


![示例2-左侧元素+文本](figures/zh-cn_image_2023072904.PNG)


## 示例3-右侧元素

```ts
import { ComposeListItem } from '@ohos.arkui.advanced.ComposeListItem';
import promptAction from '@ohos.promptAction'

@Entry
@Component
struct ComposeListItemExample {
  build() {
    Column() {
      List() {
        ListItem() {
          ComposeListItem({
            operateItem: ({
              icon: {
                value: $r('sys.media.ohos_app_icon'),
                action: () => {
                  promptAction.showToast({ message: 'icon' })
                } 
              },
              text: '右侧文本'
            })
          })
        }
      }
    }
  }
}
```


![示例3-右侧元素](figures/zh-cn_image_2023072905.PNG)


## 示例4-左右元素+文本

```ts
import { ComposeListItem } from '@ohos.arkui.advanced.ComposeListItem';
import { IconType } from '@ohos.arkui.advanced.ComposeListItem';
import promptAction from '@ohos.promptAction'

@Entry
@Component
struct ComposeListItemExample {
  build() {
    Column() {
      List() {
        ListItem() {
          ComposeListItem({
            contentItem: ({
              iconStyle: IconType.NORMAL_ICON,
              icon: $r('sys.media.ohos_app_icon'),
              primaryText: '双行列表',
              secondaryText: '辅助文字'
            }),
            operateItem: ({
              icon: {
                value: $r('sys.media.ohos_app_icon'),
                action: () => {
                  promptAction.showToast({ message: 'icon' })
                } },
              text: '右侧文本'
            })
          })
        }
      }
    }
  }
}
```

![示例4-左右元素+文本](figures/zh-cn_image_2023072906.PNG)
