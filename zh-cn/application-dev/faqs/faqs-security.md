# 安全基础能力开发常见问题

## HUKS中AES GCM模式加密，单次最多可对多少字节数据加密

适用于：OpenHarmony 3.1 Beta5 API 9

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

## 在CryptoFramework中，打印Md的digest接口返回结果为乱码

适用于：OpenHarmony 3.1 Beta5 API 9

**问题现象**

在CryptoFramework中，打印Md的digest接口返回结果显示为乱码，无法识别。

**解决措施**

digest接口返回的Md计算结果DataBlob是Uint8Array类型，需要转成十六进制字符串再打印，也可以用网页在线版MD5加密工具验证结果。

