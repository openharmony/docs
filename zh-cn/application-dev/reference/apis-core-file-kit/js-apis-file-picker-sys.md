# @ohos.file.picker (选择器)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @yangwei_814916-->
<!--Designer: @hwzhangchuang; @Dyylll-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->

Picker（选择器）是一个封装DocumentViewPicker、AudioViewPicker、PhotoViewPicker的API模块，具有选择与保存的能力。通过Picker拉起系统文件选择界面，用户可在安全可控的环境下选择或保存文件，应用无需申请权限即可使用该接口。应用可以选择使用以下API来实现文件的选择和保存的功能。该类接口需要应用在UIAbility界面中调用，否则无法拉起FilePicker应用、AudioPicker应用或PhotoPicker应用。
> **说明：**
>
> - 本模块接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.file.picker (选择器)](js-apis-file-picker.md)。

## 导入模块

```ts
import { picker } from '@kit.CoreFileKit';
```

## DocumentSelectOptions

文档选择选项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                                         | 只读  | 可选  | 说明                                     |
| :---------------------- |---------------------------------------------| ---- | ---- |------------------------------------------|
| themeColor<sup>18+</sup>     | [CustomColors](../apis-arkui/js-apis-arkui-theme.md#customcolors) |  否  |  是 |主题色参数，默认为空，跟随FilePicker应用颜色。当themeColor设置为特定的主题色属性（[brand, fontPrimary, compBackgroundEmphasize, iconFourth](../apis-arkui/js-apis-arkui-theme.md#colors)）时，被拉起的FilePicker应用将按照传入的主题色参数显示对应的界面配色；设置为其他属性时，不产生适配效果，仍跟随FilePicker应用默认颜色。<br> **设备行为差异**：该参数在Phone设备上可正常生效，在其他设备上设置不产生视觉效果（不影响选择器本身的正常调用）。开发者可通过deviceInfo.deviceType获取设备类型进行判断。 |

## DocumentSaveOptions

文档保存选项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                                          |  只读  | 可选  |说明                                       |
| :---------------------- |---------------------------------------------| ----- |--------| ------------------------------------------|
| themeColor<sup>18+</sup>     | [CustomColors](../apis-arkui/js-apis-arkui-theme.md#customcolors) |  否   | 是 | 主题色参数，默认为空，跟随FilePicker应用颜色。当themeColor设置为特定的主题色属性（[fontEmphasize, compBackgroundEmphasize](../apis-arkui/js-apis-arkui-theme.md#colors)）时，被拉起的FilePicker应用将按照传入的主题色参数显示对应的界面配色；设置为其他属性时，不产生适配效果，仍跟随FilePicker应用默认颜色。<br> **设备行为差异**：该参数在Phone设备上可正常生效，在其他设备上设置不产生视觉效果（不影响选择器本身的正常调用）。开发者可通过deviceInfo.deviceType获取设备类型进行判断。 |
