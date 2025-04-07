# 使用剪贴板进行复制粘贴

## 场景介绍

[剪贴板](../../reference/apis-basic-services-kit/js-apis-pasteboard.md)为开发者提供数据的复制粘贴能力。
当需要使用复制粘贴等功能时，例如：复制文字内容到备忘录中粘贴，复制图库照片到文件管理粘贴，就可以通过剪贴板来完成。

## 约束限制

- 剪贴板内容包含剪贴板系统服务元数据和应用设置的数据，总大小上限默认为128MB，PC/2in1设备可通过系统配置修改上限，有效范围为128MB~2GB。
- 为保证剪贴板数据的准确性，同一时间只能支持一个复制操作。
- API version 12及之后，系统为提升用户隐私安全保护能力，剪贴板读取接口增加[权限管控](get-pastedata-permission-guidelines.md)。

## 使用基础数据类型进行复制粘贴

剪贴板支持使用基础数据类型进行复制粘贴，当前支持的基础数据类型有文本、HTML、URI、Want、PixelMap。ArkTS接口与NDK接口支持数据类型不完全一致，使用时须匹配接口支持类型。

新开发的应用建议使用本方案实现复制粘贴功能。

### ArkTS接口与NDK接口数据类型对应关系
| ArkTS数据类型 | NDK数据类型                                                                                                                                        |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| MIMETYPE_PIXELMAP : "pixelMap" | UDMF_META_OPENHARMONY_PIXEL_MAP : "openharmony.pixle-map" |
| MIMETYPE_TEXT_HTML : "text/html" | UDMF_META_HTML : "general.html" |
| MIMETYPE_TEXT_PLAIN : "text/plain" | UDMF_META_PLAIN_TEXT : "general.plain-text" |
| MIMETYPE_TEXT_URI : "text/uri" | UDMF_META_GENERAL_FILE_URI : "general.file-uri" |
| MIMETYPE_TEXT_WANT : "text/want" | NDK接口不支持该数据类型。 |

ArkTS数据类型对应剪贴板类型，详见[ohos.pasteboard](../../reference/apis-basic-services-kit/js-apis-pasteboard.md)。NDK数据类型对应统一数据管理框架，详见[UDMF](../../reference/apis-arkdata/_u_d_m_f.md)。

### 接口说明

详细接口见[接口文档](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getdata9)。

使用剪贴板getData接口获取到uri类型数据之后，请使用文件管理的[fs.copy](../../reference/apis-core-file-kit/js-apis-file-fs.md#fscopy11)接口获取文件。

| 名称 | 说明                                                                                                                                        |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| setData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void | 将数据写入系统剪贴板，使用callback异步回调。 |
| setData(data: PasteData): Promise&lt;void&gt; | 将数据写入系统剪贴板，使用Promise异步回调。 |
| getData( callback: AsyncCallback&lt;PasteData&gt;): void | 读取系统剪贴板内容，使用callback异步回调。 |
| getData(): Promise&lt;PasteData&gt; | 读取系统剪贴板内容，使用Promise异步回调。 |
| getDataSync(): PasteData | 读取系统剪贴板内容, 此接口为同步接口，不能与SetData同线程调用。 |

### 示例代码
```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  async onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): Promise<void> {
    // 获取系统剪贴板对象
    let text = "test";
    // 创建一条纯文本类型的剪贴板内容对象
    let pasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, text);
    // 将数据写入系统剪贴板
    let systemPasteboard = pasteboard.getSystemPasteboard();
    await systemPasteboard.setData(pasteData);
    //从系统剪贴板中读取数据
    systemPasteboard.getData().then((data) => {
      let outputData = data;
      // 从剪贴板数据中获取条目数量
      let recordCount = outputData.getRecordCount();
      // 从剪贴板数据中获取对应条目信息
      for (let i = 0; i < recordCount; i++) {
        let record = outputData.getRecord(i).toPlainText();
        console.log('Get data success, record:' + record);
      }
    }).catch((error: BusinessError) => {
      // 处理异常场景
    })
  }
}
```

## 使用统一数据类型进行复制粘贴

为了方便剪贴板与其他应用间进行数据交互，减少数据类型适配的工作量，剪贴板支持使用统一数据对象进行复制粘贴。详细的统一数据对象请见[标准化数据通路](../../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md)文档介绍。

剪贴板支持使用基础数据类型进行复制粘贴，当前支持的基础数据类型有文本、HTML。ArkTS接口与NDK接口支持数据类型不完全一致，使用时须匹配接口支持类型。

### 接口说明

详细接口见[接口文档](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getunifieddata12)。

| 名称 | 说明                                                                                                                                        |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| setUnifiedData(data: udc.UnifiedData): Promise\<void\> | 将统一数据对象的数据写入系统剪贴板。
| setUnifiedDataSync(data: udc.UnifiedData): void | 将统一数据对象的数据写入系统剪贴板，此接口为同步接口。                                                                                                                          |
| getUnifiedData(): Promise\<udc.UnifiedData\> | 从系统剪贴板中读取统一数据对象的数据。                                                                                                                          |
| getUnifiedDataSync(): udc.UnifiedData | 从系统剪贴板中读取统一数据对象的数据，此接口为同步接口。

### 示例代码
```ts
import {unifiedDataChannel, uniformTypeDescriptor} from '@kit.ArkData';
import {BusinessError, pasteboard} from '@kit.BasicServicesKit';

// 构造一条PlainText数据,并书写获取延时数据的函数。
let plainTextData = new unifiedDataChannel.UnifiedData();
let GetDelayPlainText = ((dataType:string) => {
  let plainText = new unifiedDataChannel.PlainText();
  plainText.details = {
    Key: 'delayPlaintext',
    Value: 'delayPlaintext',
  };
  plainText.textContent = 'delayTextContent';
  plainText.abstract = 'delayTextContent';
  plainTextData.addRecord(plainText);
  return plainTextData;
});

// 向系统剪贴板中存入一条PlainText数据。
let SetDelayPlainText = (() => {
  plainTextData.properties.shareOptions = unifiedDataChannel.ShareOptions.CROSS_APP;
  // 跨应用使用时设置为CROSS_APP，本应用内使用时设置为IN_APP
  plainTextData.properties.getDelayData = GetDelayPlainText;
  pasteboard.getSystemPasteboard().setUnifiedData(plainTextData).then(()=>{
    // 存入成功，处理正常场景
  }).catch((error: BusinessError) => {
    // 处理异常场景
  });
})

// 从系统剪贴板中读取这条text数据
let GetPlainTextUnifiedData = (() => {
  pasteboard.getSystemPasteboard().getUnifiedData().then((data) => {
    let outputData = data;
    let records = outputData.getRecords();
    if (records[0].getType() == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
      let record = records[0] as unifiedDataChannel.PlainText;
      console.log('GetPlainText success, type:' + records[0].getType + ', details:' +
      JSON.stringify(record.details) + ', textContent:' + record.textContent + ', abstract:' + record.abstract);
    } else {
      console.log('Get Plain Text Data No Success, Type is: ' + records[0].getType());
    }
  }).catch((error: BusinessError) => {
    //处理异常场景
  })
})
```

<!--RP1-->
<!--RP1End-->