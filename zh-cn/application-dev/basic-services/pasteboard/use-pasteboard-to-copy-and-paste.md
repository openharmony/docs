# 使用剪贴板进行复制粘贴
<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @guo867-->
<!--Tester: @maxiaorong-->
<!--Adviser: @fang-jinxu-->

## 场景介绍

[剪贴板](../../reference/apis-basic-services-kit/js-apis-pasteboard.md)为开发者提供数据的复制粘贴能力。当需要使用复制粘贴等功能时，例如：复制文字内容到备忘录中粘贴，复制图库照片到文件管理粘贴，就可以通过剪贴板来完成。

## 约束限制

- 剪贴板内容包含剪贴板系统服务元数据和应用设置的数据，总大小上限默认为128MB，PC/2in1设备可通过系统配置修改上限，有效范围为1MB~2GB。
- 为保证剪贴板数据的准确性，同一时间只能支持一个复制操作。
- API version 12及之后，系统为提升用户隐私安全保护能力，剪贴板读取接口增加[权限管控](get-pastedata-permission-guidelines.md)。

## 剪贴板接入原理介绍

- 剪贴板为应用提供应用数据的复制粘贴能力，支持在应用内或应用间共享复制或剪切的应用数据。剪贴板默认支持文本、HTML富文本、文件URI、PixelMap通用数据格式类型数据，同时也支持应用自定义扩展类型数据处理。

- 剪贴板数据定义对应PasteData，复制应用通过向剪贴板服务写入PasteData实现数据复制，粘贴应用通过读取剪贴板服务的PasteData实现数据粘贴，PasteData整体结构示意如下：

![pasteboard](figures/pastedata.png)

- Record对应复制数据的不同内容片段； </br>
- Entry对应同一份数据的不同格式； </br>
- pasteDataProperty定义了剪贴板中数据内容的属性，包含时间戳、数据类型、可粘贴范围以及一些附加数据等。

为了复制应用和粘贴应用对剪贴板数据内容理解一致，更好地实现不同应用间的复制粘贴体验，应用适配剪贴板时需按如下原则处理：

**应用复制时向剪贴板写入数据**

- 复制数据内容只使用一个Record携带，对于复制数据内容的不同格式，使用同一Record的不同Entry携带。 </br>
- 如果存在一个Record无法携带所有数据的场景，比如多文件复制时的多个uri，此时使用多Record携带复制数据内容的不同部分。 </br>
- 应用将支持的所有剪贴板数据格式都写入剪贴板，以保证复制数据可以在所有可能粘贴的场景被粘贴。

**应用粘贴时通过剪贴板读取数据**

- 剪贴板数据属于个人数据，读取剪贴板数据需要支持剪贴板读取权限授权，剪贴板提供了安全控件和用户授权ohos.permission.READ_PASTEBOARD权限两种授权方式。 </br>
- 复制应用写入剪贴板的数据可能包含多种格式数据，粘贴应用需根据当前粘贴页面和场景选择最合适的格式进行粘贴显示。

- 剪贴板同时提供了TS API和NDK API，应用按需选择合适的API支持复制粘贴功能。

## 使用基础数据类型进行复制粘贴

剪贴板支持使用基础数据类型进行复制粘贴，当前支持的基础数据类型有文本、HTML、URI、Want、PixelMap。ArkTS接口与NDK接口支持数据类型不完全一致，使用时须匹配接口支持类型。

新开发的应用建议使用本方案实现复制粘贴功能。

### ArkTS接口与NDK接口数据类型对应关系
| ArkTS数据类型 | NDK数据类型                                                                                                                                        |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| MIMETYPE_PIXELMAP : "pixelMap" | UDMF_META_OPENHARMONY_PIXEL_MAP : "openharmony.pixel-map" |
| MIMETYPE_TEXT_HTML : "text/html" | UDMF_META_HTML : "general.html" |
| MIMETYPE_TEXT_PLAIN : "text/plain" | UDMF_META_PLAIN_TEXT : "general.plain-text" |
| MIMETYPE_TEXT_URI : "text/uri" | UDMF_META_GENERAL_FILE_URI : "general.file-uri" |
| MIMETYPE_TEXT_WANT : "text/want" | NDK接口不支持该数据类型。 |

ArkTS数据类型对应剪贴板类型，详见[ohos.pasteboard](../../reference/apis-basic-services-kit/js-apis-pasteboard.md)。NDK数据类型对应统一数据管理框架，详见[UDMF](../../reference/apis-arkdata/capi-udmf.md)。

### 接口说明

使用剪贴板getData接口获取到uri类型数据之后，请使用文件管理的[fileIo.copy](../../reference/apis-core-file-kit/js-apis-file-fs.md#fileiocopy11)接口获取文件。

| 名称 | 说明                                                                                                                                        |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| [setData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#setdata9) | 将数据写入系统剪贴板，使用callback异步回调。 |
| [setData(data: PasteData): Promise&lt;void&gt;](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#setdata9-1) | 将数据写入系统剪贴板，使用Promise异步回调。 |
| [getData(callback: AsyncCallback&lt;PasteData&gt;): void](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getdata9) | 读取系统剪贴板内容，使用callback异步回调。 |
| [getData(): Promise&lt;PasteData&gt;](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getdata9-1) | 读取系统剪贴板内容，使用Promise异步回调。 |
| [getDataSync(): PasteData](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getdatasync11) | 读取系统剪贴板内容，此接口为同步接口，不能与SetData同线程调用。 |

### 示例代码

<!-- @[pasteboard_usedata](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/pasteboard/pasteboard_arkts_sample/entry/src/main/ets/pages/PasteboardModel.ets) -->

``` TypeScript
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
// ...
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// ...
  export async function setPlainData(content: string): Promise<void> {
    try {
      let pasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, content);
      await systemPasteboard.setData(pasteData);
      hilog.info(0xFF00, '[Sample_pasteboard]', 'Set data to pasteboard successfully');
    } catch (error) {
      hilog.error(0xFF00, '[Sample_pasteboard]', `Failed to set data to pasteboard, error: ${error}`);
    }
  }
  export async function getPlainData(type: string): Promise<string> {
    try {
      // 从系统剪贴板中读取数据
      let data = await systemPasteboard.getData();
      // 从剪贴板数据中获取条目数量
      let recordCount = data.getRecordCount();
      // 从剪贴板数据中获取对应条目信息
      let result = '';
      for (let i = 0; i < recordCount; i++) {
        let record = data.getRecord(i).toPlainText();
        hilog.info(0xFF00, '[Sample_pasteboard]', `Get data success, record: ${record}`);
        result = record;
      }
      return result;
    } catch (error) {
      hilog.error(0xFF00, '[Sample_pasteboard]', `Failed to get data from pasteboard, error: ${error}`);
      return '';
    }
  }
```


## 使用统一数据类型进行复制粘贴

为了方便剪贴板与其他应用间进行数据交互，减少数据类型适配的工作量，剪贴板支持使用统一数据对象进行复制粘贴。详细的统一数据对象请见[标准化数据通路](../../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md)文档介绍。

剪贴板支持使用基础数据类型进行复制粘贴，当前支持的基础数据类型有文本、HTML。ArkTS接口与NDK接口支持的数据类型不完全一致，使用时需匹配对应接口所支持的类型。

### 接口说明

| 名称 | 说明                                                                                                   |
| -------- |---------------------------------------------------------------------------------------------------|
| [setUnifiedData(data: unifiedDataChannel.UnifiedData): Promise\<void\>](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#setunifieddata12) | 将统一数据对象的数据写入系统剪贴板。                   |
| [setUnifiedDataSync(data: unifiedDataChannel.UnifiedData): void](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#setunifieddatasync12) | 将统一数据对象的数据写入系统剪贴板，此接口为同步接口。          |
| [getUnifiedData(): Promise\<unifiedDataChannel.UnifiedData\>](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getunifieddata12) | 从系统剪贴板中读取统一数据对象的数据。                           |
| [getUnifiedDataSync(): unifiedDataChannel.UnifiedData](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getunifieddatasync12) | 从系统剪贴板中读取统一数据对象的数据，此接口为同步接口。                  |

### 示例代码

<!-- @[pasteboard_useudc](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/pasteboard/pasteboard_arkts_sample/entry/src/main/ets/pages/PasteboardModel.ets) -->

``` TypeScript
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { unifiedDataChannel, uniformDataStruct, uniformTypeDescriptor } from '@kit.ArkData';
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// ...
  // 1.构造一条PlainText数据
  export async function handleUniformData() {
    let plainText: uniformDataStruct.PlainText = {
      uniformDataType: uniformTypeDescriptor.UniformDataType.PLAIN_TEXT,
      textContent: 'PLAINTEXT_CONTENT',
      abstract: 'PLAINTEXT_ABSTRACT',
    }

    let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainText);
    let data = new unifiedDataChannel.UnifiedData();
    data.addRecord(record);
    // 2.向系统剪贴板中存入一条PlainText数据
    systemPasteboard.setUnifiedData(data).then((data: void) => {
      hilog.info(0xFF00, '[Sample_pasteboard]', 'Succeeded in setting UnifiedData.');
      // 存入成功，处理正常场景
    }).catch((err: BusinessError) => {
      hilog.error(0xFF00, '[Sample_pasteboard]', `Failed to set UnifiedData. Cause: ${err.message}`);
      // 处理异常场景
    });
    // 3.从系统剪贴板中读取这条text数据
    systemPasteboard.getUnifiedData().then((data) => {
      let records: unifiedDataChannel.UnifiedRecord[] = data.getRecords();
      for (let j = 0; j < records.length; j++) {
        if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
          let text = records[j].getValue() as uniformDataStruct.PlainText;
          hilog.info(0xFF00, '[Sample_pasteboard]', `${j + 1}.${text.textContent}`);
        }
      }
    }).catch((err: BusinessError) => {
      hilog.error(0xFF00, '[Sample_pasteboard]', `Failed to get UnifiedData. Cause: ${err.message}`);
      // 处理异常场景
    });
  }
```


<!--RP1-->
<!--RP1End-->