# 安全基础能力开发常见问题


## HUKS中AES GCM模式加密，单次最多可对多少字节数据加密(API 9)

**解决措施**

HUKS中AES GCM模式加密时，单次最多可对64字节的数据进行加密。

**代码示例**

```
/* 进行密钥加密操作 */
await huks.init(srcKeyAlias, encryptOptions).then((data) => {
 console.info(`test init data: ${JSON.stringify(data)}`);
 handle = data.handle;
}).catch((err) => {
 console.info('test init err information: ' + JSON.stringify(err));
});
encryptOptions.inData = aesCipherStringToUint8Array(cipherInData.slice(0,64)); // 截取64字节
await huks.update(handle, encryptOptions).then(async (data) => {
 console.info(`test update data ${JSON.stringify(data)}`);
 encryptUpdateResult = Array.from(data.outData);
}).catch((err) => {
 console.info('test update err information: ' + err);
});
encryptOptions.inData = aesCipherStringToUint8Array(cipherInData.slice(64,80)); // 剩余数据
```


## 在CryptoFramework中，打印Md的digest接口返回结果为乱码(API 9)

**问题现象**

在CryptoFramework中，打印Md的digest接口返回结果显示为乱码，无法识别。

**解决措施**

digest接口返回的Md计算结果DataBlob是Uint8Array类型，需要转成十六进制字符串再打印，也可以用网页在线版MD5加密工具验证结果。

## 如何自定义申请权限时的选项文本，例如申请定位权限时，如何自定义弹出的选项文本(API 10)

**解决方案**

只允许自定义reason，自定义reason在权限弹框时会显示，但不允许自定义弹出选项文本。

**参考资料**

[权限申请](../security/AccessToken/determine-application-mode.md)

## @ohos.security.cryptoFramework都是异步方法，是否有同步的加密方法，若无，后续是否会提供同步的加密方式(API 10)

**解决方案**

1. cryptoFramework当前JS接口都为异步调用方式。

2. 后续版本cryptoFramework会提供同步的加密解密接口。

## 如何使用安全控件SaveButton进行图片的快速保存，保存控件可以用于哪些场景，区别于使用filepicker方式有什么优势(API 10)

**解决方案**

1. 应用集成SaveButton并注册onClick回调，当用户点击后，应用可以在回调中调用媒体库接口快速创建图片文件，此过程不需要弹窗授权、选择目录之类的操作。
2. 保存控件可用于需要快速存储图片、视频到媒体库的场景。
3. 如果使用filepicker，需要拉起系统picker，并选择保存路径等操作，交互流程比较长，用户体验不好。

**参考资料**

[安全控件概述](../security/AccessToken/security-component-overview.md)

[SaveButton](../reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md)