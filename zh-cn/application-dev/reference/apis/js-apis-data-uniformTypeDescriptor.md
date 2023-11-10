# @ohos.data.uniformTypeDescriptor (标准化数据定义与描述)

本模块对OpenHarmony标准化数据类型进行了抽象定义与描述。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
```

## UniformDataType

OpenHarmony标准化数据类型的枚举定义。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称                         | 值                            | 说明        |
|----------------------------|------------------------------|-----------|
| TEXT                       | 'general.text'                   | 文本类型。     |
| PLAIN_TEXT                 | 'general.plain-text'             | 纯文本类型。    |
| HYPERLINK                  | 'general.hyperlink'              | 超链接类型。    |
| HTML                       | 'general.html'                   | 富文本类型。    |
| FILE                       | 'general.file'                   | 文件类型。     |
| IMAGE                      | 'general.image'                  | 图片类型。     |
| VIDEO                      | 'general.video'                  | 视频类型。     |
| AUDIO                      | 'general.audio'                  | 音频类型。     |
| FOLDER                     | 'general.folder'                 | 文件夹类型。    |
| OPENHARMONY_FORM           | 'openharmony.form'               | 卡片类型。     |
| OPENHARMONY_APP_ITEM       | 'openharmony.app-item'           | 图标类型。     |
| OPENHARMONY_PIXEL_MAP      | 'openharmony.pixel-map'          | 二进制图片类型。  |