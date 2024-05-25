# DownloadFileButton

下载控件，用户通过点击该下载按钮，可以获取到当前应用所属的存储路径。


> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

##  导入模块

```
import DownloadFileButton from '@ohos.arkui.advanced.DownloadFileButton';
```



## 子组件

不支持。

## 接口

### DownloadFileButton

Downloadbutton()

默认创建带有图标、文本、背景的保存按钮。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名        | 参数类型                                        | 必填 | 参数描述                         |
| ------------- | ----------------------------------------------- | ---- | -------------------------------- |
| contentOption | [DownloadContentOption](#DownloadContentOption) | 否   | 创建包含指定元素内容的下载按钮。 |
| styleOption   | [DownloadStyleOption](#DownloadStyleOption)     | 否   | 创建包含指定元素样式的下载按钮。 |



## DownloadContentOption

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称 | 类型                                                | 必填 | 描述                                                         |
| ---- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| icon | [DownloadIconStyle](#DownloadIconStyle枚举说明)     | 否   | 设置下载按钮的图标风格<br/>不传入该参数表示没有图标，icon和text至少存在一个。 |
| text | [DownloadDescription](#DownloadDescription枚举说明) | 否   | 设置下载按钮的文本描述<br/>不传入该参数表示没有文字描述，icon和text至少存在一个。 |



## DownloadStyleOption

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称            | 类型                                                        | 必填 | 描述                                                         |
| --------------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| iconSize        | Dimension                                                   | 否   | 下载控件上图标的尺寸。<br/>默认值：16vp                      |
| layoutDirection | [DownloadLayoutDirection](#DownloadLayoutDirection枚举说明) | 否   | 下载控件上图标和文字分布的方向。<br/>默认值：DownloadLayoutDirection.HORIZONTAL |
| fontSize        | Dimension                                                   | 否   | 下载控件上文字的尺寸。<br/>默认值：16fp                      |
| fontStyle       | FontStyle                                                   | 否   | 下载控件上文字的样式。<br/>默认值：FontStyle.Normal          |
| fontWeight      | number \| FontWeight \| string                              | 否   | 下载控件上文字粗细。<br/>默认值：FontWeight.Medium           |
| fontFamily      | string \| Resource                                          | 否   | 下载控件上文字的字体。<br/>默认字体：'HarmonyOS Sans'        |
| fontColor       | ResourceColor                                               | 否   | 下载控件上文字的颜色。<br/>默认值：#ffffffff                 |
| iconColor       | ResourceColor                                               | 否   | 下载控件上图标的颜色。<br/>默认值：#ffffffff                 |
| textIconSpace   | Dimension                                                   | 否   | 下载控件中图标和文字的间距。<br/>默认值：4vp                 |



## DownloadIconStyle枚举说明

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称        | 枚举值 | 描述                       |
| ----------- | ------ | -------------------------- |
| FULL_FILLED | 0      | 下载按钮展示填充样式图标。 |
| LINES       | 1      | 下载按钮展示线条样式图标。 |



## DownloadDescription枚举说明

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称                | 枚举值 | 描述                                                         |
| ------------------- | ------ | ------------------------------------------------------------ |
| DOWNLOAD            | 0      | 下载按钮的文字描述为“下载”。 **元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| DOWNLOAD_FILE       | 1      | 下载按钮的文字描述为“下载文件”。 **元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| SAVE                | 2      | 下载按钮的文字描述为“保存”。 **元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| SAVE_IMAGE          | 3      | 下载按钮的文字描述为“保存图片”。 **元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| SAVE_FILE           | 4      | 下载按钮的文字描述为“保存文件”。 **元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| DOWNLOAD_AND_SHARE  | 5      | 下载按钮的文字描述为“下载分享”。 **元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| RECEIVE             | 6      | 下载按钮的文字描述为“接收”。 **元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| CONTINUE_TO_RECEIVE | 7      | 下载按钮的文字描述为“继续接收”。 **元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |



## DownloadLayoutDirection枚举说明

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称       | 枚举值 | 描述                                       |
| ---------- | ------ | ------------------------------------------ |
| HORIZONTAL | 0      | 下载控件上图标和文字分布的方向为水平排列。 |
| VERTICAL   | 1      | 下载控件上图标和文字分布的方向为垂直排列。 |



##  示例

```
import picker from '@ohos.file.picker';
import { BusinessError } from '@kit.BasicServicesKit';
import DownloadFileButton from '@ohos.arkui.advanced.DownloadFileButton';

@Entry
@Component
struct Index {
  build() {
    Column() {
      DownloadFileButton({
        contentOption: {
          // icon: DownloadIconStyle.FULL_FILLED,
          // text: DownloadDescription.DOWNLOAD
        },
        styleOption: {
          iconSize: '16vp',
          layoutDirection: DownloadLayoutDirection.HORIZONTAL,
          fontSize: '16vp',
          fontStyle: FontStyle.Normal,
          fontWeight: FontWeight.Medium,
          fontFamily: 'HarmonyOS Sans',
          fontColor: '#ffffffff',
          iconColor: '#ffffffff',
          textIconSpace: '4vp'
        }
      })
        .backgroundColor('#007dff')
        .borderStyle(BorderStyle.Dotted)
        .borderWidth(0)
        .borderColor('')
        .borderRadius('24vp')
        .position({ x: 0, y: 0 })
        .markAnchor({ x: 0, y: 0 })
        .offset({ x: 0, y: 0 })
        .constraintSize({})
        .padding({
          top: '12vp',
          bottom: '12vp',
          left: '24vp',
          right: '24vp'
        })
        .onClick(() => {
          this.downloadAction();
        })
    }
  }

  downloadAction() {
    try {
      const document = new picker.DocumentSaveOptions();
      document.pickerMode = picker.DocumentPickerMode.DOWNLOAD;
      new picker.DocumentViewPicker().save(document, (err: BusinessError, result: Array<string>) => {
        if (err) {
          return;
        }
        console.info(`downloadAction result:  ${JSON.stringify(result)}`);
      });
    } catch (e) {
    }
  }
}



...
  contentOption: {
           text: DownloadDescription.DOWNLOAD
        }
...


...
  contentOption: {
         icon: DownloadIconStyle.FULL_FILLED
        }
        ..
 styleOption: {
        iconColor: '#007dff'
        }
        ..
         // .backgroundColor('#007dff')
...
```



