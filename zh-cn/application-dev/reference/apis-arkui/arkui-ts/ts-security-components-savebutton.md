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

为避免控件样式不合法导致授权失败，请开发者先了解安全控件样式的[约束与限制](../../../security/AccessToken/security-component-overview.md#约束与限制)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### SaveButton

SaveButton(options:SaveButtonOptions)

创建包含指定元素的保存按钮。

为避免控件样式不合法导致授权失败，请开发者先了解安全控件样式的[约束与限制](../../../security/AccessToken/security-component-overview.md#约束与限制)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [SaveButtonOptions](#savebuttonoptions) | 是 | 创建包含指定元素的保存按钮。 |

## SaveButtonOptions

用于指定保存按钮的图标、文本等指定元素。

> **说明：**
>
> - icon或text需至少传入一个。<br>
> - 如果icon、text都不传入，[SaveButton](#savebutton-1)中的options参数不起效，创建的SaveButton为默认样式，默认样式：
>
>   SaveIconStyle默认样式为FULL_FILLED；
>
>   SaveDescription默认样式为DOWNLOAD；
>
>   ButtonType默认样式为Capsule。
> - icon、text、buttonType不支持动态修改。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| icon | [SaveIconStyle](#saveiconstyle枚举说明) | 否 | 设置保存按钮的图标风格<br/>不传入该参数表示没有图标。 |
| text | [SaveDescription](#savedescription枚举说明) | 否 | 设置保存按钮的文本描述<br/>不传入该参数表示没有文字描述。 |
| buttonType | [ButtonType](ts-securitycomponent-attributes.md#buttontype枚举说明) | 否 | 设置保存按钮的背景样式<br/>不传入该参数，系统默认提供Capsule类型按钮。 |

## SaveIconStyle枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| FULL_FILLED | 0 | 保存按钮展示填充样式图标。 |
| LINES | 1 | 保存按钮展示线条样式图标。 |

## SaveDescription枚举说明

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| DOWNLOAD | 0 | 保存按钮的文字描述为“下载”。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| DOWNLOAD_FILE | 1 | 保存按钮的文字描述为“下载文件”。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| SAVE | 2 | 保存按钮的文字描述为“保存”。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| SAVE_IMAGE | 3 | 保存按钮的文字描述为“保存图片”。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| SAVE_FILE | 4 | 保存按钮的文字描述为“保存文件”。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| DOWNLOAD_AND_SHARE | 5 | 保存按钮的文字描述为“下载分享”。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| RECEIVE | 6 | 保存按钮的文字描述为“接收”。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| CONTINUE_TO_RECEIVE | 7 | 保存按钮的文字描述为“继续接收”。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| SAVE_TO_GALLERY<sup>12+</sup> | 8 | 保存按钮的文字描述为“保存至图库”。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| EXPORT_TO_GALLERY<sup>12+</sup> | 9 | 保存按钮的文字描述为“导出”。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| QUICK_SAVE_TO_GALLERY<sup>12+</sup> | 10 | 保存按钮的文字描述为“快速保存图片”。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| RESAVE_TO_GALLERY<sup>12+</sup> | 11 | 保存按钮的文字描述为“重新保存”。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| SAVE_ALL<sup>16+</sup> | 12 | 保存按钮的文字描述为“全部保存”。 <br/>**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。|

## SaveButtonOnClickResult枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| SUCCESS | 0 | 保存按钮点击成功。 |
| TEMPORARY_AUTHORIZATION_FAILED | 1 | 保存按钮点击后权限授权失败。 |

## SaveButtonCallback

SaveButtonCallback = (event: ClickEvent, result: SaveButtonOnClickResult, error?: BusinessError&lt;void&gt;) =&gt; void

点击保存按钮触发该回调。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名 | 类型                   | 必填 | 说明                   |
|------------|------|-------|---------|
| event | [ClickEvent](ts-universal-events-click.md#clickevent对象说明) |是 |见ClickEvent对象说明|
| result | [SaveButtonOnClickResult](#savebuttononclickresult枚举说明)| 是 | 存储权限的授权结果，授权时长为10秒，即触发点击后，可以在10秒之内不限制次数的调用特定媒体库接口，超出10秒的调用会鉴权失败。|
| error | BusinessError&lt;void&gt; | 否 | 点击按钮时的错误码和错误信息。<br>错误码0表示保存按钮点击成功。<br>错误码1表示系统内部错误。<br>错误码2表示属性设置错误，包括但不限于：<br>1. 字体或图标设置过小。<br>2. 字体或图标与背托颜色相近。<br>3. 字体或图标颜色过于透明。<br>4. padding为负值。<br>5. 按钮被其他组件或窗口遮挡。<br>6. 文本超出背托范围。<br>7. 按钮超出窗口或屏幕。<br>8. 按钮整体尺寸过大。<br>9. 按钮文本被截断，显示不全。<br>10. 相关属性设置影响安全控件显示。|

## 属性

不支持通用属性，仅继承[安全控件通用属性](ts-securitycomponent-attributes.md#属性)。

## 事件

不支持通用事件，仅支持以下事件：

### onClick

onClick(event: SaveButtonCallback)

点击动作触发该回调

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                   | 必填 | 说明                   |
|------------|------|-------|---------|
| event | [SaveButtonCallback](#savebuttoncallback) |是 |见SaveButtonCallback|

## 示例

```ts
// xxx.ets
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  handleSaveButtonClick: SaveButtonCallback = async (event: ClickEvent, result: SaveButtonOnClickResult, error: BusinessError<void>) => {
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
    } else {
      console.info("errCode: " + error.code);
      console.info("errMessage: " + error.message);
    }
  };

  build() {
    Row() {
      Column({ space: 10 }) {
        // 默认参数下，图标、文字、背景都存在
        SaveButton().onClick((this.handleSaveButtonClick))
        // 传入参数即表示元素存在，不传入的参数表示元素不存在，如果不传入buttonType，会默认添加ButtonType.Capsule配置，显示图标+背景。
        SaveButton({ icon: SaveIconStyle.FULL_FILLED })
        // 只显示图标+背景，如果设置背景色高八位的α值低于0x1A，则会被系统强制调整为0xFF
        SaveButton({ icon: SaveIconStyle.FULL_FILLED, buttonType: ButtonType.Capsule })
          .backgroundColor(0x10007dff)
        // 图标、文字、背景都存在，如果设置背景色高八位的α值低于0x1A，则会被系统强制调整为0xFF
        SaveButton({ icon: SaveIconStyle.FULL_FILLED, text: SaveDescription.DOWNLOAD, buttonType: ButtonType.Capsule })
        // 图标、文字、背景都存在，如果设置宽度小于当前属性组合下允许的最小宽度时，宽度仍为设置值，此时按钮文本信息会自动换行，以保证安全控件显示的完整性。
        SaveButton({ icon: SaveIconStyle.FULL_FILLED, text: SaveDescription.DOWNLOAD, buttonType: ButtonType.Capsule })
          .fontSize(16)
          .width(30)
        // 图标、文字、背景都存在，如果设置宽度小于当前属性组合下允许的最小宽度时，宽度仍为设置值，此时按钮文本信息会自动换行，以保证安全控件显示的完整性。
        SaveButton({ icon: SaveIconStyle.FULL_FILLED, text: SaveDescription.DOWNLOAD, buttonType: ButtonType.Capsule })
          .fontSize(16)
          .size({ width: 30, height: 30 })
        // 图标、文字、背景都存在，如果设置宽度小于当前属性组合下允许的最小宽度时，宽度仍为设置值，此时按钮文本信息会自动换行，以保证安全控件显示的完整性。
        SaveButton({ icon: SaveIconStyle.FULL_FILLED, text: SaveDescription.DOWNLOAD, buttonType: ButtonType.Capsule })
          .fontSize(16)
          .constraintSize({ minWidth: 0, maxWidth: 30, minHeight: 0, maxHeight: 30 })
      }.width('100%')
    }.height('100%')
  }
}
```

![zh-cn_image_0000001643320073](figures/zh-cn_image_0000001643320073.png)
