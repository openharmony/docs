# GridObjectSortComponent


网格对象的编辑排序是用于网格对象的编辑、拖动排序、新增和删除。


>  **说明：**
>
>  该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```ts
import { GridObjectSortComponent, GridObjectSortComponentItem, GridObjectSortComponentOptions, GridObjectSortComponentType } from '@kit.ArkUI'
```

##  子组件

无

## 属性

支持[通用属性](ts-universal-attributes-size.md)

## GridObjectSortComponent

GridObjectSortComponent({options: GridObjectSortComponentOptions, dataList: Array\<GridObjectSortComponentItem>, onSave: (select: Array\<GridObjectSortComponentItem>, unselect: Array\<GridObjectSortComponentItem>) => void, onCancel: () => void })

**装饰器类型：**\@Component

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：


| 名称     | 类型                             | 装饰器类型 | 必填 | 说明         |
| -------- | -------------------------------- | ---------- | ---- | ------------ |
| options  | [GridObjectSortComponentOptions](#gridobjectsortcomponentoptions) | @Prop      | 是   | 组件配置信息。 |
| dataList | Array<[GridObjectSortComponentItem](#gridobjectsortcomponentitem)> | -     | 是   | 传入的数据，最大长度为50，数据长度超过50，只会取前50的数据。 |
| onSave | (select: Array<[GridObjectSortComponentItem](#gridobjectsortcomponentitem)>, unselect: Array<[GridObjectSortComponentItem](#gridobjectsortcomponentitem)>)  => void | - | 是 | 保存编辑排序的回调函数，返回编辑后的数据。 |
| onCancel | () => void | - | 是 | 取消保存数据的回调。 |

##  GridObjectSortComponentOptions

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型                      | 必填 | 说明                                                   |
| -------------- | ------------------------- | ---- | ------------------------------------------------------ |
| type           | [GridObjectSortComponentType](#gridobjectsortcomponenttype) | 否   | 组件展示形态：文字\|图片+文字。<br />默认：GridObjectSortComponentType.text。 |
| imageSize      | number \| [Resource](ts-types.md#resource) | 否   | 图片的尺寸。<br />默认值：56。                          |
| normalTitle | [ResourceStr](ts-types.md#resourcestr)     | 否   | 未编辑状态下显示的标题。<br />默认：频道。            |
| showAreaTitle | [ResourceStr](ts-types.md#resourcestr)     | 否   | 展示区域标题，第一个子标题。<br />默认：长按拖动排序。 |
| addAreaTitle | [ResourceStr](ts-types.md#resourcestr)     | 否   | 添加区域标题，第二个子标题。<br />默认：点击添加。            |
| editTitle      | [ResourceStr](ts-types.md#resourcestr)     | 否   | 编辑状态下头部标题显示。<br />默认：编辑。             |

## GridObjectSortComponentType 

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 值    | 说明           |
| -------- | ----- | -------------- |
| IMAGE_TEXT | 'image_text' | 图片文字类型。 |
| TEXT     | 'text'       | 文字类型。     |

## GridObjectSortComponentItem

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| id       | number&nbsp;\|&nbsp;string             | 是   | 数据id序号，不可重复。                                       |
| text     | [ResourceStr](ts-types.md#resourcestr) | 是   | 显示文本信息。                                               |
| selected | boolean                                | 是   | 是否已经被添加，添加：true，未添加：false。                  |
| url      | [ResourceStr](ts-types.md#resourcestr) | 否   | GridObjectSortComponentType类型为IMAGE_TEXT时，需要传入图片地址。 |
| order    | number                                 | 是   | 顺序序号。                                                   |

##  事件

不支持[通用事件](ts-universal-events-click.md)。

## 示例

```ts
import { GridObjectSortComponent, GridObjectSortComponentItem, GridObjectSortComponentOptions, GridObjectSortComponentType } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @State dataList: GridObjectSortComponentItem[] = [
    {
      id: 0,
      url: $r('app.media.ic_controlcenter_location_filled'),
      text: '位置信息',
      selected: true,
      order: 3
    },
    {
      id: 1,
      url: $r('app.media.ic_controlcenter_mobiledata_filled'),
      text: '移动数据',
      selected: true,
      order: 9
    },
    {
      id: 2,
      url: $r('app.media.ic_controlcenter_nfc_filled'),
      text: 'NFC',
      selected: false,
      order: 1
    },
    {
      id: 3,
      url: $r('app.media.ic_controlcenter_ring_off_filled'),
      text: '响铃关闭',
      selected: true,
      order: 4
    },
    {
      id: 4,
      url: $r('app.media.ic_controlcenter_ring_on_filled'),
      text: '响铃',
      selected: false,
      order: 5
    },
    {
      id: 5,
      url: $r('app.media.ic_controlcenter_ultra_power_saver_filled'),
      text: '低电量模式',
      selected: true,
      order: 6
    },
    {
      id: 6,
      url: $r('app.media.ic_controlcenter_screenshot_filled'),
      text: '截屏',
      selected: true,
      order: 7
    },
    {
      id: 7,
      url: $r('app.media.ic_controlcenter_screen_recording_filled'),
      text: '屏幕录制',
      selected: true,
      order: 8
    },
    {
      id: 8,
      url: $r('app.media.ic_controlcenter_super_power_saver_filled'),
      text: '超级省电',
      selected: false,
      order: 9
    },
  ]

  @State option: GridObjectSortComponentOptions = {
    type: GridObjectSortComponentType.IMAGE_TEXT,
    imageSize: 45,
    normalTitle: '菜单',
    editTitle: '编辑',
    showAreaTitle: '长按拖动排序',
    addAreaTitle: '点击添加'
  }

  build() {
    Column() {
      GridObjectSortComponent({
        options: this.option,
        dataList: this.dataList,
        onSave: (
          select: Array<GridObjectSortComponentItem>,
          unselect: Array<GridObjectSortComponentItem>
        ) => {
          // save ToDo
        },
        onCancel: () =>{
          // cancel ToDo
        }
      })
    }
  }
}
```

![GridObjectSortComponent](figures/GridObjectSortComponent.gif)