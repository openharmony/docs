# @ohos.file.PhotoPickerComponent（photo picker组件）

应用可将该组件嵌入自己的布局界面中，该组件会拉起系统图片选择界面，供应用选择图片和视频。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```
import { PhotoPickerComponent, PickerController, PickerOptions, DataType } from '@ohos.file.PhotoPickerComponent'
```

## PhotoPickerComponent

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名                      | 参数类型                               | 必填  | 参数描述                                       |
|--------------------------|------------------------------------|-----|--------------------------------------------|
| pickerOptions            | [PickerOptions](#PickerOptions)    | 否   | picker参数信息。                                |
| onSelect:(uri： string)   | void                               | 否   | 用户在picker组件中勾选图片是产生的回调事件，将图片uri给到应用。       |
| onDeselect:(uri： string) | void                               | 否   | 用户在picker组件中取消勾选图片是产生的回调事件，同时也会将图片uri给到应用。 |
| pickerController         | [PickerController](#PickerController) | 否   | 应用可通过PickerController向picker组件发送数据         |

## PickerOptions

PickerOptions继承于BaseSelectOptions。具体信息详见[BaseSelectOptions说明](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#BaseSelectOptions)

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 参数名                     | 参数类型    | 必填  | 参数描述                 |
|-------------------------|---------|-----|----------------------|
| checkBoxColor           | string  | 否   | 支持应用配置勾选框的背景色        |
| backgroundColor         | string  | 否   | 支持应用配置picker宫格页面背景色。 |
| isRepeatSelectSupported | boolean | 否   | 支持应用配置是否支持单张图片重复选择。  |

## PickerController

应用可通过PickerController向picker组件发送数据。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 参数名                                   | 参数类型 | 必填  | 参数描述                                                                  |
|---------------------------------------|------|-----|-----------------------------------------------------------------------|
| setData(type: DataType, data: Object) | void | 否   | 应用可通过该接口向picker组件发送数据，并通过[DataType](#DataType)来区分具体发送什么类型的数据。 |


## DataType

枚举，PickerController向picker组件发送数据的数据类型。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值      | 说明                                                                                                                        |
|-------------------|--------|---------------------------------------------------------------------------------------------------------------------------|
| SET_SELECTED_URIS | 1      | 发送已选择的数据列表，通知picker组件勾选状态刷新，需要传入string数组类型。例如：应用在自己的页面中删除某张图片后，需要把剩下的已选择的数据列表通过setData接口通知到picker组件，从而触发picker组件勾选框状态刷新正确 |

## 示例

```ts
// xxx.ets
import { PhotoPickerComponent, PickerController, PickerOptions, DataType } from '@ohos.file.PhotoPickerComponent'
import photoAccessHelper from '@ohos.file.photoAccessHelper'

@Entry
@Component
struct PickerDemo {
  pickerOptions: PickerOptions = new PickerOptions();
  @State pickerController: PickerController = new PickerController();
  @State selectUris: Array<string> = new Array<string>();

  aboutToAppear() {
    this.pickerOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
    this.pickerOptions.maxSelectNumber = 10;
    this.pickerOptions.isSearchSupported = false;
    this.pickerOptions.isPhotoTakingSupported = false;
    // 其他属性.....
  }
  
  private onSelect(uri: string): void {
    // 添加
    if (uri) {
      this.selectUris.push(uri);
    }
  }

  private onDeselect(uri: string): void {
    // 移除
    if (uri) {
      this.selectUris = this.selectUris.filter((item: string) => {
        return item != uri;
      })
    }
  }

  build() {
    Stack() {
      PhotoPickerComponent({
        pickerOptions: this.pickerOptions,
        onSelect:(uri: string): void => this.onSelect(uri),
        onDeselect:(uri: string): void => this.onDeselect(uri),
        pickerController: this.pickerController,
      }).height('100%').width('100%')


      // 这里模拟应用侧底部的选择栏
      Row() {
        ForEach(this.selectUris, (uri: string) => {
          Image(uri).height('10%').width('10%').onClick(() => {
            // 点击事件模拟删除操作，通过pickerController向picker组件发送已选择的数据列表，触发picker组件勾选框刷新
            this.selectUris = this.selectUris.filter((item: string) => {
              return item != uri;
            })
            this.pickerController.setData(DataType.SET_SELECTED_URIS, this.selectUris);
          })
        }, (uri: string) => JSON.stringify(uri))
      }
    }
  }
}
