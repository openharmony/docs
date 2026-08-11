# Class (FileSelectorParam)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

FileSelectorParam是ArkWeb组件中的文件选择器参数类，用于获取Web页面中`<input type="file">`触发文件选择请求时的相关参数信息，包括文件选择模式、文件过滤类型、MIME类型、建议文件名、默认起始路径等，帮助开发者高效构建符合HTML规范的自定义文件选择器。

当Web页面发起文件选择请求时，开发者通过FileSelectorParam获取前端传递的完整参数信息，据此构建与前端需求匹配的自定义文件选择器，确保文件选择的模式、类型过滤、命名等行为与HTML规范一致。

在Web组件中需要自定义处理文件上传请求的场景下使用。注册`onShowFileSelector`回调以拦截文件选择请求；从回调事件的`fileSelector`属性获取FileSelectorParam实例；读取参数后构建对应的系统文件选择器（如DocumentViewPicker、PhotoViewPicker等）；通过FileSelectorResult返回选择结果至Web组件。

示例代码参考[onShowFileSelector](./arkts-basic-components-web-events.md#onshowfileselector9)。

> **说明：**
>
> - 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 9开始支持。
>
> - 示例效果请以真机运行为准。

## constructor<sup>9+</sup>

constructor()

FileSelectorParam的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## getTitle<sup>9+</sup>

getTitle(): string

获取文件选择器标题。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 返回文件选择器标题字符串，表示当前文件选择器在界面上显示的标题文本。 |

## getMode<sup>9+</sup>

getMode(): FileSelectorMode

获取文件选择器的模式。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明          |
| ---------------------------------------- | ----------- |
| [FileSelectorMode](./arkts-basic-components-web-e.md#fileselectormode9) | 返回文件选择器的模式。 |

## getAcceptType<sup>9+</sup>

> **说明：**
>
> 与getMimeTypes和getAcceptableFileTypes的对应关系：getAcceptType和getMimeTypes对应HTML input标签的accept属性，getAcceptableFileTypes对应HTML showOpenFilePicker、showDirectoryPicker、showSaveFilePicker接口参数options的types属性。根据HTML规范，accept属性与types属性为互斥关系，不应同时使用。

getAcceptType(): Array\<string\>

获取文件过滤类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明        |
| --------------- | --------- |
| Array\<string\> | 返回文件过滤类型数组，包含用于限制文件选择器可选文件范围的类型信息。元素为扩展名（如'.png'），对应HTML accept属性。 |

## isCapture<sup>9+</sup>

isCapture(): boolean

获取是否调用多媒体能力。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明           |
| ------- | ------------ |
| boolean | 返回是否调用多媒体能力。<br>true表示需要调用摄像头或麦克风等多媒体设备来获取文件（如拍照或录音），false表示仅从存储设备中选择已有文件。对应HTML input标签的capture属性。|

## getMimeTypes<sup>18+</sup>

getMimeTypes(): Array\<string\>

获取文件MIME类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明        |
| --------------- | --------- |
| Array\<string\> | 原样返回HTML input标签的accept属性的值，包含指定允许选择的文件的MIME类型和扩展名信息。 |

## getSuggestedName<sup>23+</sup>

getSuggestedName(): string

获取建议选择的文件名。对应HTML里[option](../../web/web-file-upload.md#自定义处理js接口拉起的文件请求)中的`suggestedName`。若前端未设置suggestedName，返回空字符串。开发者可在构建文件选择器时使用该返回值作为默认文件名，与[getDefaultPath](#getdefaultpath23)配合使用可预设完整的文件路径和名称。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 返回建议选择的文件名字符串，表示建议用于文件选择器的默认文件名。 |

## getDefaultPath<sup>23+</sup>

getDefaultPath(): string

获取文件选择器默认起始路径。对应HTML里[option](../../web/web-file-upload.md#自定义处理js接口拉起的文件请求)中的`startIn`。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明         |
| ------ | ---------- |
| string | 返回默认起始路径。<br>当前端startIn设置为公共目录`downloads`、`pictures`时，要注意应分别转化为OpenHarmony系统下的`download`和`images`，请参考[获取并使用公共目录](../../file-management/request-dir-permission.md)。 |

## getDescriptions<sup>23+</sup>

getDescriptions(): Array\<string\>

获取允许的各组文件类型的可选描述。对应HTML里[option](../../web/web-file-upload.md#自定义处理js接口拉起的文件请求)中的`description`。返回的描述数组与getAcceptableFileTypes返回的文件类型组一一对应。开发者可在构建文件选择器时使用这些描述作为每组文件类型的显示文本，帮助用户理解可选择的文件类型。若前端未设置description，返回空字符串。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明        |
| --------------- | --------- |
| Array\<string\> | 返回文件类型的描述字符串数组，包含各组文件类型的可选描述文本。 |

## isAcceptAllOptionExcluded<sup>23+</sup>

isAcceptAllOptionExcluded(): boolean

获取文件选择器是否排除选项（\*\/\*），即所有文件。对应HTML里[option](../../web/web-file-upload.md#自定义处理js接口拉起的文件请求)中的`excludeAcceptAllOption`。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明           |
| ------- | ------------ |
| boolean | 返回是否排除“所有文件类型”选项。<br>true表示排除（不包含“所有文件类型”选项），false表示包含（开发者应确保文件选择器中包含“所有文件类型”选项）。 |

## getAcceptableFileTypes<sup>23+</sup>

getAcceptableFileTypes(): Array\<Array\<AcceptableFileType\>>

获取文件类型信息。对应HTML里[option](../../web/web-file-upload.md#自定义处理js接口拉起的文件请求)中的`types`。返回值为二维数组，每个子数组代表一组允许的文件类型。开发者应在构建文件选择器时使用该返回值设置文件类型过滤规则，确保用户只能选择符合前端要求的文件。该参数与getAcceptType和getMimeTypes的区别在于types支持更精细的文件类型控制，可按MIME类型或扩展名分组设置。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型              | 说明        |
| --------------- | --------- |
| Array\<Array\<[AcceptableFileType](./arkts-basic-components-web-i.md#acceptablefiletype23)\>> | 返回文件类型信息，为二维数组结构，包含多组可选文件类型的详细信息。对应HTML option的types属性。 |