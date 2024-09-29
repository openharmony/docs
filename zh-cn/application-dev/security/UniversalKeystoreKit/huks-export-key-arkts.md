# 密钥导出(ArkTS)


业务需要获取持久化存储的非对称密钥的公钥时使用，当前支持ECC/RSA/ED25519/X25519/SM2的公钥导出。
>**说明：**
> 轻量级设备仅支持RSA公钥导出。


## 开发步骤

1. 指定密钥别名keyAlias，密钥别名最大长度为64字节。

2. 调用接口[exportKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksexportkeyitem9)，传入参数keyAlias和options。
   options为预留参数，当前可传入空。

3. 返回值为[HuksReturnResult](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksreturnresult9)类型对象，获取的公钥明文在outData字段中，以标准的X.509规范的DER格式封装，具体请参考[公钥材料格式](huks-concepts.md#公钥材料格式)。

```ts
import { huks } from '@kit.UniversalKeystoreKit';

/* 1. 设置密钥别名 */
let keyAlias = 'keyAlias';
/* option对象传空 */
let emptyOptions: huks.HuksOptions = {
  properties: []
};
try {
  /* 2. 导出密钥 */
  huks.exportKeyItem(keyAlias, emptyOptions, (error, data) => {
    if (error) {
      console.error(`callback: exportKeyItem failed, ` + error);
    } else {
      console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  console.error(`callback: exportKeyItem input arg invalid, ` + JSON.stringify(error));
}
```
