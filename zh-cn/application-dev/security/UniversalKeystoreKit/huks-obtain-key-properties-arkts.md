# 获取密钥属性(ArkTS)

HUKS提供了接口供业务获取指定密钥的相关属性。在获取指定密钥属性前，需要确保已在HUKS中生成或导入持久化存储的密钥。
>**说明：**
> 轻量级设备不支持获取密钥属性功能。

## 开发步骤

1. 指定待查询的密钥别名keyAlias，密钥别名最大长度为128字节。

2. 调用接口[getKeyItemProperties](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgetkeyitemproperties9)，传入参数keyAlias和options。
   options为预留参数，当前可传入空。

3. 返回值为[HuksReturnResult](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksreturnresult9)类型对象，获取的属性集在properties字段中。

```ts
import { huks } from '@kit.UniversalKeystoreKit';

/* 1. 设置密钥别名 */
let keyAlias = 'keyAlias';
/* option对象传空 */
let emptyOptions: huks.HuksOptions = {
  properties: []
};
try {
  /* 2. 获取密钥属性 */
  huks.getKeyItemProperties(keyAlias, emptyOptions, (error, data) => {
    if (error) {
      console.error(`callback: getKeyItemProperties failed, ` + JSON.stringify(error));
    } else {
      console.info(`callback: getKeyItemProperties success, data = ${JSON.stringify(data)}`);
    }
  });
} catch (error) {
  console.error(`callback: getKeyItemProperties input arg invalid, ` + JSON.stringify(error));
}
```
