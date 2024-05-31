# 剪贴板使用统一数据对象进行复制粘贴


## 场景介绍

[剪贴板服务](../../reference/apis-basic-services-kit/js-apis-pasteboard.md)主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。

为了方便剪贴板与其他应用间进行数据交互，减少数据类型适配的工作量，剪贴板支持使用统一数据对象进行复制粘贴。详细的统一数据对象请见[标准化数据通路](../../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md)文档介绍。


## 接口说明

详细接口见[接口文档](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getunifieddata12)。

| 名称 | 说明                                                                                                                                        |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| setUnifiedData(data: udc.UnifiedData): Promise\<void\> | 将统一数据对象的数据写入系统剪贴板。 
| setUnifiedDataSync(data: udc.UnifiedData): void | 将统一数据对象的数据写入系统剪贴板，此接口为同步接口。                                                                                                                          |
| getUnifiedData(): Promise\<udc.UnifiedData\> | 从系统剪贴板中读取统一数据对象的数据。                                                                                                                          |
| getUnifiedDataSync(): udc.UnifiedData | 从系统剪贴板中读取统一数据对象的数据，此接口为同步接口。                                                                                                                   |


## 开发步骤

1. 导入`@ohos.pasteboard.d.ts`,`@ohos.data.unifiedDataChannel`和`@ohos.data.uniformTypeDescriptor`模块。
```ts
import {unifiedDataChannel, uniformTypeDescriptor} from '@kit.ArkData';
import {BusinessError, pasteboard} from '@kit.BasicServicesKit';
```

2. 构造一条PlainText数据记录。
```ts
let plainTextData = new unifiedDataChannel.UnifiedData();
let plainText = new unifiedDataChannel.PlainText();
plainText.details = {
    Key: 'Plaintext',
    Value: 'Plaintext',
};
plainText.textContent = 'TextContent';
plainText.abstract = 'TextContent';
plainTextData.addRecord(plainText);
```

3. 向系统剪贴板中存入一条PlainText数据。
```ts
plainTextData.properties.shareOptions = unifiedDataChannel.ShareOptions.CROSS_APP;
// 跨应用使用时设置为CROSS_APP，本应用内使用时设置为IN_APP
pasteboard.getSystemPasteboard().setUnifiedData(plainTextData).then(()=>{
// 存入成功，处理正常场景
}).catch((error: BusinessError) => {
// 处理异常场景
});
```

4. 从系统剪贴板中读取这条text数据。
```ts
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
```