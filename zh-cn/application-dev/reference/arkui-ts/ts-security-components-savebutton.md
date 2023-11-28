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

### SaveButton
SaveButton(option:{icon?: SaveIconStyle, text?: SaveDescription, buttonType?: ButtonType})

创建包含指定元素的保存按钮。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| icon | [SaveIconStyle](#saveiconstyle枚举说明) | 否 | 设置保存按钮的图标风格<br/>不传入该参数表示没有图标，icon和text至少存在一个。 |
| text | [SaveDescription](#savedescription枚举说明) | 否 | 设置保存按钮的文本描述<br/>不传入该参数表示没有文字描述，icon和text至少存在一个。 |
| buttonType | [ButtonType](ts-basic-components-button.md#ButtonType枚举说明) | 否 | 设置保存按钮的背景样式<br/>不传入该参数表示没有背景。 |


## SaveIconStyle枚举说明

| 名称 | 描述 |
| -------- | -------- |
| FULL_FILLED | 保存按钮展示填充样式图标。 |
| LINES | 保存按钮展示线条样式图标。 |


## SaveDescription枚举说明

| 名称 | 描述 |
| -------- | -------- |
| DOWNLOAD | 保存按钮的文字描述为“下载”。 |
| DOWNLOAD_FILE | 保存按钮的文字描述为“下载文件”。 |
| SAVE | 保存按钮的文字描述为“保存”。 |
| SAVE_IMAGE | 保存按钮的文字描述为“保存图片”。 |
| SAVE_FILE | 保存按钮的文字描述为“保存文件”。 |
| DOWNLOAD_AND_SHARE | 保存按钮的文字描述为“下载分享”。 |
| RECEIVE | 保存按钮的文字描述为“接收”。 |
| CONTINUE_TO_RECEIVE | 保存按钮的文字描述为“继续接收”。 |


## SaveButtonOnClickResult枚举说明

| 名称 | 描述 |
| -------- | -------- |
| SUCCESS | 保存按钮点击成功。 |
| TEMPORARY_AUTHORIZATION_FAILED | 保存按钮点击后权限授权失败。 |


## 属性

不支持通用属性，仅继承[安全控件通用属性](ts-securitycomponent-attributes.md#属性)。


## 事件

不支持通用事件，仅支持以下事件：

| 名称 | 功能描述 |
| -------- | -------- |
| onClick(event: (event: [ClickEvent](ts-universal-events-click.md#clickevent对象说明)), result: [SaveButtonOnClickResult](#savebuttononclickresult枚举说明)) =&gt; void) | 点击动作触发该回调。<br/>result：存储权限的授权结果，授权时长为10秒，即触发点击后，可以在10秒之内不限制次数的调用特定媒体库接口，超出10秒的调用会鉴权失败。<br/>event：见ClickEvent对象说明。 |


## 示例

```
// xxx.ets
import photoAccessHelper from '@ohos.file.photoAccessHelper';
import fs from '@ohos.file.fs';

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
              let file = await fs.open(uri, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
              // 写入文件
              await fs.write(file.fd, "context");
              // 关闭文件
              await fs.close(file.fd);
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
