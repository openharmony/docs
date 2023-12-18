# @ohos.arkui.advanced.ImageTextEditableComponent（网格对象的编辑排序组件）

ImageTextEditableComponent是用于网格对象的编辑排序组件。

>  **说明：**
>
>  该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```ets
import { 
	ImageTextEditableComponent, 
	ImageTextEditableComponentItem, 
	ImageTextEditableComponentOptions, 
	ImageTextEditableComponentType,
} from '@ohos.arkui.advanced.ImageTextEditableComponent';
```

##  子组件

无

## Component

**装饰器类型：**@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**组件能力**：编辑、拖动排序、新增、删除

**参数**：

| 名称     | 类型                             | 装饰器类型 | 必填 | 说明         |
| -------- | -------------------------------- | ---------- | ---- | ------------ |
| options  | ImageTextEditableComponentOptions     | @Prop      | 是   | 组件配置信息 |
| dataList | Array<ImageTextEditableComponentItem> | -     | 是   | 传入的元数据，最大长度为50，数据长度超过50，只会取前50的数据 |

##  ImageTextEditableComponentOptions

ImageTextEditableComponentOptions定义ImageTextEditableComponent组件的类型及参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型                      | 必填 | 说明                                                   |
| -------------- | ------------------------- | ---- | ------------------------------------------------------ |
| type           | ImageTextEditableComponentType | 否   | 组件展示形态：文字\|图片+文字，默认：ImageTextEditableComponentType.text |
| imageSize      | number                    | 否   | 图片的尺寸，默认：56                                   |
| title          | ResourceStr    | 否   | 未编辑状态下显示的标题，默认：频道                     |
| firstSubtitle  | ResourceStr    | 否   | 第一个子标题，默认：长按拖动排序                       |
| secondSubtitle | ResourceStr    | 否   | 第二个子标题，默认：点击添加                           |
| editTitle      | ResourceStr    | 否   | 编辑状态下头部标题显示，默认：编辑                     |

## ImageTextEditableComponentType 

ImageTextEditableComponentType 定义ImageTextEditableComponentOptions组件的枚举类型及参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型   | 值           | 说明         |
| -------- | ------ | ------------ | ------------ |
| IMAGE_TE | string | 'image_text' | 图片文字类型 |
| TEXT     | string | 'text'       | 文字类型     |

## ImageTextEditableComponentItem

ImageTextEditableComponentItem定义ImageTextEditableComponent的元数据。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型             | 必填 | 说明                                                         |
| ----- | ---------------- | ---- | ------------------------------------------------------------ |
| id    | string \| number | 是   | 数据id序号，不可重复                                         |
| text  | ResourceStr      | 是   | 显示文本信息                                                 |
| state | boolean          | 是   | 是否已经被添加，添加：true，未添加：false                    |
| url   | ResourceStr      | 否   | ImageTextEditableComponentType类型为IMAGE_TEXT时，需要传入图片地址 |
| order | number           | 是   | 顺序序号                                                     |

##  事件

| 名称                                                         | 功能描述                                 |
| :----------------------------------------------------------- | ---------------------------------------- |
| onSave: (select: Array<ImageTextEditableComponentItem>, unselect: Array<ImageTextEditableComponentItem>) =>  void | 保存编辑排序的回调函数，返回编辑后的数据 |
| onCancel: () => void                                         | 取消保存数据时的回调                     |

## 示例1

### 示例1：文本形态

```ets
import { 
	ImageTextEditableComponent, 
	ImageTextEditableComponentItem, 
	ImageTextEditableComponentOptions, 
	ImageTextEditableComponentType, 
} from '@ohos.arkui.advanced.ImageTextEditableComponent';
import router from '@ohos.router'

@Entry
@Component
struct Index {
  @State dataList: ImageTextEditableComponentItem[] = [
    {
      id: 0,
      text: 'facebook',
      state: true,
      order: 3
    },
    {
      id: 1,
      text: 'google',
      state: true,
      order: 9
    },
    {
      id: 2,
      text: 'instagram',
      state: false,
      order: 1
    },
    {
      id: 3,
      text: 'linkedin',
      state: true,
      order: 4
    },
    {
      id: 4,
      text: 'pinterestST',
      state: false,
      order: 5
    },
    {
      id: 5,
      text: 'Twitter',
      state: true,
      order: 6
    },
    {
      id: 6,
      text: 'youtube',
      state: true,
      order: 7
    },
    {
      id: 7,
      text: 'tumber',
      state: true,
      order: 8
    },
    {
      id: 8,
      text: 'vk',
      state: false,
      order: 9
    },
    {
      id: 9,
      text: 'whatsapp',
      state: true,
      order: 10
    }
  ]

  // 该option中的选项都是非必传项
  @State option: ImageTextEditableComponentOptions = {
    type: ImageTextEditableComponentType.TEXT,
    imageSize: 56,
    title: 'test001',
    editTitle: 'test002',
    firstSubtitle: "长按拖动排序",
    secondSubtitle: "点击添加",
  }

  build() {
    Column() {
      ImageTextEditableComponent({
      		options: this.option, 
      		dataList: this.dataList, 
      		onSave: (select: Array<ImageTextEditableComponentItem>, unselect: Array<ImageTextEditableComponentItem>) => {
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



### 示例2：图文形态

```ets
import { 
	ImageTextEditableComponent, 
	ImageTextEditableComponentItem, 
	ImageTextEditableComponentOptions, 
	ImageTextEditableComponentType, 
} from '@ohos.arkui.advanced.ImageTextEditableComponent';
import router from '@ohos.router'

@Entry
@Component
struct Index {
  @State dataList: ImageTextEditableComponentItem[] = [
    {
      id: 0,
      url: $r('app.media.facebook'),
      text: 'facebook',
      state: true,
      order: 3
    },
    {
      id: 1,
      url: $r('app.media.google'),
      text: 'google',
      state: true,
      order: 9
    },
    {
      id: 2,
      url: $r('app.media.instagram'),
      text: 'instagram',
      state: false,
      order: 1
    },
    {
      id: 3,
      url: $r('app.media.linkedin'),
      text: 'linkedin',
      state: true,
      order: 4
    },
    {
      id: 4,
      url: $r('app.media.pinterestST'),
      text: 'pinterestST',
      state: false,
      order: 5
    },
    {
      id: 5,
      url: $r('app.media.Twitter'),
      text: 'Twitter',
      state: true,
      order: 6
    },
    {
      id: 6,
      url: $r('app.media.youtube'),
      text: 'youtube',
      state: true,
      order: 7
    },
    {
      id: 7,
      url: $r('app.media.tumber'),
      text: 'tumber',
      state: true,
      order: 8
    },
    {
      id: 8,
      url: $r('app.media.vk'),
      text: 'vk',
      state: false,
      order: 9
    },
  ]

  @State option: ImageTextEditableComponentOptions = {
    type: ImageTextEditableComponentType.IMAGETEXT,
    imageSize: 68,
    title: '',
    editTitle: '',
    firstSubtitle: "长按拖动排序",
    secondSubtitle: "点击添加",
  }
  
  build() {
    Column() {
      ImageTextEditableComponent({
      		options: this.option, 
      		dataList: this.dataList, 
      			onSave: (select: Array<ImageTextEditableComponentItem>, unselect: Array<ImageTextEditableComponentItem>) => {
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

![ImageTextEditableComponent](figures/ImageTextEditableComponent.gif)