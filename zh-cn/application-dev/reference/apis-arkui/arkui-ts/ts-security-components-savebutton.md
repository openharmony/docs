# SaveButton


安全控件的保存控件，用户通过点击该保存按钮，可以临时获取存储权限，而不需要权限弹框授权确认。


> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

不支持。


## 接口

### SaveButton
SaveButton()

默认创建带有图标、文本、背景的保存按钮。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

### SaveButton
SaveButton(option:SaveButtonOptions)

创建包含指定元素的保存按钮。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| option | [SaveButtonOptions](#savebuttonoptions) | 否 | 创建包含指定元素的保存按钮。 |

## SaveButtonOptions

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| icon | [SaveIconStyle](#saveiconstyle枚举说明) | 否 | 设置保存按钮的图标风格<br/>不传入该参数表示没有图标，icon和text至少存在一个。 |
| text | [SaveDescription](#savedescription枚举说明) | 否 | 设置保存按钮的文本描述<br/>不传入该参数表示没有文字描述，icon和text至少存在一个。 |
| buttonType | [ButtonType](ts-basic-components-button.md#buttontype枚举说明) | 否 | 设置保存按钮的背景样式<br/>不传入该参数表示没有背景。 |


## SaveIconStyle枚举说明

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 名称 | 枚举值 | 描述 |
| -------- | -------- | -------- |
| FULL_FILLED | 0 | 保存按钮展示填充样式图标。 |
| LINES | 1 | 保存按钮展示线条样式图标。 |


## SaveDescription枚举说明

| 名称 | 枚举值 | 描述 |
| -------- | -------- | -------- |
| DOWNLOAD | 0 | 保存按钮的文字描述为“下载”。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。|
| DOWNLOAD_FILE | 1 | 保存按钮的文字描述为“下载文件”。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。|
| SAVE | 2 | 保存按钮的文字描述为“保存”。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。|
| SAVE_IMAGE | 3 | 保存按钮的文字描述为“保存图片”。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。|
| SAVE_FILE | 4 | 保存按钮的文字描述为“保存文件”。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。|
| DOWNLOAD_AND_SHARE | 5 | 保存按钮的文字描述为“下载分享”。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。|
| RECEIVE | 6 | 保存按钮的文字描述为“接收”。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。|
| CONTINUE_TO_RECEIVE | 7 | 保存按钮的文字描述为“继续接收”。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。|
| SAVE_TO_GALLERY<sup>12+</sup> | 8 | 保存按钮的文字描述为“保存到图库”。 <br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。|


## SaveButtonOnClickResult枚举说明

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 名称 | 枚举值 | 描述 |
| -------- | -------- | -------- |
| SUCCESS | 0 | 保存按钮点击成功。 |
| TEMPORARY_AUTHORIZATION_FAILED | 1 | 保存按钮点击后权限授权失败。 |


## 属性

不支持通用属性，仅继承[安全控件通用属性](ts-securitycomponent-attributes.md#属性)。


## 事件

不支持通用事件，仅支持以下事件：

### onClick

onClick(event: (event: ClickEvent, result: SaveButtonOnClickResult) =&gt; void)

点击动作触发该回调

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                   | 必填 | 说明                   |
|------------|------|-------|---------|
| event  | [ClickEvent](ts-universal-events-click.md#clickevent对象说明) |是 |见ClickEvent对象说明|
| result | [SaveButtonOnClickResult](#savebuttononclickresult枚举说明)| 是 | 存储权限的授权结果，授权时长为10秒，即触发点击后，可以在10秒之内不限制次数的调用特定媒体库接口，超出10秒的调用会鉴权失败。|


## 示例

```
// xxx.ets
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { fileIo } from '@kit.CoreFileKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column({space:10}) {
        // 默认参数下，图标、文字、背景都存在
        SaveButton().onClick(async (event:ClickEvent, result:SaveButtonOnClickResult) => {
          if (result == SaveButtonOnClickResult.SUCCESS) {
            try {
              const context = getContext(this);
              let helper = photoAccessHelper.getPhotoAccessHelper(context);
              // onClick触发后10秒内通过createAsset接口创建图片文件，10秒后createAsset权限收回。
              let uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'png');
              // 使用uri打开文件，可以持续写入内容，写入过程不受时间限制
              let file = await fileIo.open(uri, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
              // 写入文件
              await fileIo.write(file.fd, "context");
              // 关闭文件
              await fileIo.close(file.fd);
            } catch (error) {
              console.error("error is "+ JSON.stringify(error));
            }
          }
        })
        // 传入参数即表示元素存在，不传入的参数表示元素不存在，例如：只显示图标
        SaveButton({icon:SaveIconStyle.FULL_FILLED})
        // 只显示图标+背景
        SaveButton({icon:SaveIconStyle.FULL_FILLED, buttonType:ButtonType.Capsule})
        // 图标、文字、背景都存在
        SaveButton({icon:SaveIconStyle.FULL_FILLED, text:SaveDescription.DOWNLOAD, buttonType:ButtonType.Capsule})
      }.width('100%')
    }.height('100%')
  }
}
```

![zh-cn_image_0000001643320073](figures/zh-cn_image_0000001643320073.png)
