# @ohos.file.picker (选择器)(系统接口)

选择器(Picker)是一个封装PhotoViewPicker、DocumentViewPicker、AudioViewPicker等API模块，具有选择与保存的能力。应用可以自行选择使用哪种API实现文件选择和文件保存的功能。该类接口，需要应用在界面UIAbility中调用，否则无法拉起photoPicker应用或FilePicker应用。
> **说明：**
>
> - 本模块接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.file.picker (选择器)](js-apis-file-picker.md)。

## 导入模块

```ts
import  { picker } from '@kit.CoreFileKit';
```

## DocumentSelectOptions

文档选择选项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。<br>

**系统能力**：SystemCapability.FileManagement.UserFileService<br> 

### 属性

| 名称                    | 类型                                         | 只读  | 可选  | 说明                                     |
| :---------------------- |---------------------------------------------| ---- | ---- |------------------------------------------|
| themeColor<sup>18+</sup>     | [CustomColors](../apis-arkui/js-apis-arkui-theme.md#customcolors) |  否  |  是 |主题色参数, 默认为空，跟随FilePicker应用颜色。当themeColor设置为特定的主题色属性（[brand, fontPrimary, compBackgroundEmphasize, iconFourth](../apis-arkui/js-apis-arkui-theme.md#colors)时，被拉起的FilePicker应用将适配传入的主题色参数的效果。<br> **系统能力**：SystemCapability.FileManagement.UserFileService，仅支持手机设备。 |

## DocumentSaveOptions

文档保存选项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

### 属性

| 名称                    | 类型                                          |  只读  | 可选  |说明                                       |
| :---------------------- |---------------------------------------------| ----- |--------| ------------------------------------------|
| themeColor<sup>18+</sup>     | [CustomColors](../apis-arkui/js-apis-arkui-theme.md#customcolors) |  否   | 是 | 主题色参数, 默认为空，跟随FilePicker应用颜色。当themeColor设置为特定的主题色属性（[fontEmphasize, compBackgroundEmphasize](../apis-arkui/js-apis-arkui-theme.md#colors)时，被拉起的FilePicker应用将适配传入的主题色参数的效果。<br> **系统能力**：SystemCapability.FileManagement.UserFileService，仅支持手机设备。|
