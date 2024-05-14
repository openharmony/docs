# @ohos.arkui.advanced.FormMenu (应用内添加卡片到桌面菜单的高级组件API)

本高级组件API封装了一个“添加到桌面”菜单，用于实现应用内长按组件生成“添加到桌面”菜单，点击该菜单，触发卡片添加到桌面操作。通过桌面访问该组件快捷卡片，可以直接访问该组件功能。该API能满足开发者需求，在应用使用过程中，吸引用户将功能快捷添加到桌面，作为留存和复访入口。

API支持：
应用内支持长按菜单快捷添加卡片到桌面：

1） 提供API给开发者，开发者将卡片数据以及应用内功能组件ID传给卡片框架

2） 点击事件会根据组件ID获取应用内功能组件的快照和位置，用于添加到桌面时的过渡动效

3） 卡片框架通过将加桌数据通知给桌面，触发卡片添加到桌面操作


> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { AddFormMenuItem } from '@ohos.arkui.advanced.FormMenu'
```


## 子组件

无

## 属性
不支持[通用属性](ts-universal-attributes-size.md)

## AddFormMenuItem 

```
export declare function AddFormMenuItem(
  want: Want,
  componentId: string,
  options?: AddFormOptions
): void;
```

**装饰器类型：**\@Component

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称           | 子参数名称      | 参数类型                        | 必填 | 装饰器类型 | 说明                                                             |
| -------------- | --------------- | ------------------------------- | ---- | ---------- | ---------------------------------------------------------------- |
| want           |                 | [Want](../../reference/apis-ability-kit/js-apis-app-ability-want.md)                            | 是   | \@Prop     | 待发布功能组件的want信息                                         |
| componentId    |                 | string                          | 是   | -          | 应用内功能组件ID，组件ID对应的界面应该与待添加的服务卡片界面相似 |
| AddFormOptions | [formBindingData](../../reference/apis-form-kit/js-apis-app-form-formBindingData.md#formbindingdata) | formBindingData.FormBindingData | 否   | -          | 卡片数据                                                         |
|                | callback        | AsyncCallback<string>           | 否   | -          | 用于回调通知添加的卡片ID                                         |
|                | style           | FormMenuItemStyle               | 否   | -          | 菜单自定义样式信息                                               |

## 

## 事件
支持菜单点击事件

## 示例

```ts
import { AddFormMenuItem } from '@kit.ArkUI';
import { formBindingData } from '@kit.FormKit';


@Entry
@Component
struct Index {
  @State message: string = 'Long press show menu';
  private compId: string = 'addformsd46313145';



  @Builder
  MyMenu() {
    Menu() {
      AddFormMenuItem(
        {
          bundleName: 'com.example.myapplication', // 包名
          abilityName: 'EntryFormAbility', // 模块ability名称
          parameters: {
            'ohos.extra.param.key.form_dimension': 2,
            'ohos.extra.param.key.form_name': 'widget',
            'ohos.extra.param.key.module_name': 'entry'
          },
        },
        this.compId,
        {
          formBindingData: formBindingData.createFormBindingData({}),
          callback:
          (formId) => {
            console.log("AddFormMenuItem on click call back successful, and formId = " + formId);
          },
          // style: {
          //   options: {
          //     startIcon: $r("app.media.icon"), // 菜单图标,可以自己提供。系统默认采用"sys.media.ohos_ic_public_add"
          //     content: "添加到桌面",  // 菜单内容，可以自己提供。默认使用"sys.string.ohos_add_form_to_desktop"
          //     endIcon: $r("app.media.icon") // 菜单图标，可以自己提供
          //   }
          // }
        }
      )
    }
  }

  build() {
    Row() {
      Column() {
        Button(this.message)
          .fontSize(30)
          .id(this.compId)
          .fontWeight(FontWeight.Bold)
          .bindContextMenu(this.MyMenu, ResponseType.LongPress)
      }
      .width('80%')
      .height('80%')
      .border({ width: 1 })
    }
    .height('80%')
  }
}
```
![zh-cn_image_0000001616959836](figures/zh-cn_image_add_form_to_desktop.jpeg)