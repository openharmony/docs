# 公共通信子系统NFC JS API变更Changelog

OpenHarmony 3.2.10.2(Mr)版本相较于OpenHarmony 3.2.beta4版本，分布式数据管理子系统的API变更如下

## cl.nfc.1 接口变更
NFC部分API6到API8部分JS接口不支持抛出错误码，需要删除废弃，然后使用新的API9替换。

开发者需要根据以下说明对应用进行适配。

 **变更影响**

影响部分API6到API8部分JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| api/@ohos.nfc.cardEmulation.d.ts        | cardEmulation         | FeatureType  | 废弃     |
| api/@ohos.nfc.cardEmulation.d.ts        | cardEmulation         | isSupported  | 废弃     |
| api/@ohos.nfc.cardEmulation.d.ts        | cardEmulation         | hasHceCapability  | 新增     |
| api/@ohos.nfc.controller.d.ts        | nfcController         | isNfcAvailable  | 废弃     |
| api/@ohos.nfc.controller.d.ts        | nfcController         | openNfc  | 废弃     |
| api/@ohos.nfc.controller.d.ts        | nfcController         | closeNfc  | 废弃     |
| api/@ohos.nfc.controller.d.ts        | nfcController         | enableNfc  | 新增     |
| api/@ohos.nfc.controller.d.ts        | nfcController         | disableNfc  | 新增     |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcATag  | 废弃     |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcBTag  | 废弃     |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcFTag  | 废弃     |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcVTag  | 废弃     |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcA  | 新增     |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcB  | 新增     |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcF  | 新增     |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcV  | 新增     |
| api/tag/tagSession.d.ts        | TagSession          | getTagInfo  | 废弃     |
| api/tag/tagSession.d.ts        | TagSession          | connectTag  | 废弃     |
| api/tag/tagSession.d.ts        | TagSession          | reset  | 废弃     |
| api/tag/tagSession.d.ts        | TagSession          | isTagConnected  | 废弃     |
| api/tag/tagSession.d.ts        | TagSession          | setSendDataTimeout  | 废弃     |
| api/tag/tagSession.d.ts        | TagSession          | getSendDataTimeout  | 废弃     |
| api/tag/tagSession.d.ts        | TagSession          | sendData  | 废弃     |
| api/tag/tagSession.d.ts        | TagSession          | getMaxSendLength  | 废弃     |
| api/tag/tagSession.d.ts        | TagSession          | connect  | 新增     |
| api/tag/tagSession.d.ts        | TagSession          | resetConnection  | 新增     |
| api/tag/tagSession.d.ts        | TagSession          | isConnected  | 新增     |
| api/tag/tagSession.d.ts        | TagSession          | setTimeout  | 新增     |
| api/tag/tagSession.d.ts        | TagSession          | getTimeout  | 新增     |
| api/tag/tagSession.d.ts        | TagSession          | transmit  | 新增     |
| api/tag/tagSession.d.ts        | TagSession          | getMaxTransmitSize  | 新增     |

**适配指导**

查看API开发指南：
[cardEmulation-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-cardEmulation.md)

[nfcController-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-nfcController.md)

[tag-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-nfcTag.md)

[TagSession-API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-tagSession.md)
```

