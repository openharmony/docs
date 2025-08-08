# @ohos.file.picker (Picker) (System API)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--SE: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--TSE: @liuhonggang123; @yue-ye2; @juxiaopang-->

The **Picker** module encapsulates APIs such as **PhotoViewPicker**, **DocumentViewPicker**, and **AudioViewPicker** to provide capabilities of selecting and saving files of different types. An application can select the API as required. The APIs of this module must be called in UIAbility. Otherwise, the **photoPicker** or **FilePicker** cannot be started.
> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.file.picker (Picker)](js-apis-file-picker.md).

## Modules to Import

```ts
import  { picker } from '@kit.CoreFileKit';
```

## DocumentSelectOptions

Defines the options for selecting documents.

**Atomic service API**: This API can be used in atomic services since API version 12.<br>

**System capability**: SystemCapability.FileManagement.UserFileService<br>

### Properties

| Name                   | Type                                        | Read-Only | Optional | Description                                    |
| :---------------------- |---------------------------------------------| ---- | ---- |------------------------------------------|
| themeColor<sup>18+</sup>     | [CustomColors](../apis-arkui/js-apis-arkui-theme.md#customcolors) |  No |  Yes|Theme color parameter. By default, it is left empty and follows the color settings of the **FilePicker**. When it is set to specific theme color properties, such as [brand, fontPrimary, compBackgroundEmphasize, and iconFourth](../apis-arkui/js-apis-arkui-theme.md#colors), the launched **FilePicker** will adapt to the theme color accordingly.<br> **System capability**: SystemCapability.FileManagement.UserFileService. Only mobile phones are supported.|

## DocumentSaveOptions

Defines the options for saving documents.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

### Properties

| Name                   | Type                                         |  Read-Only | Optional |Description                                      |
| :---------------------- |---------------------------------------------| ----- |--------| ------------------------------------------|
| themeColor<sup>18+</sup>     | [CustomColors](../apis-arkui/js-apis-arkui-theme.md#customcolors) |  No  | Yes| Theme color parameter. By default, it is left empty and follows the color settings of the **FilePicker**. When it is set to specific theme color properties, such as [fontEmphasize and compBackgroundEmphasize](../apis-arkui/js-apis-arkui-theme.md#colors), the launched **FilePicker** will adapt to the theme color accordingly.<br> **System capability**: SystemCapability.FileManagement.UserFileService. Only mobile phones are supported.|
