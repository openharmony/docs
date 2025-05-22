# 查询密钥是否存在(ArkTS)

HUKS提供了接口供应用查询指定密钥是否存在。

## 开发步骤

1. 指定密钥别名keyAlias，密钥别名最大长度为128字节。

2. 初始化密钥属性集。用于查询时指定[密钥的属性TAG](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukstag)，当查询单个密钥时，TAG字段可传空。

3. 调用接口[hasKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukshaskeyitem11)，查询密钥是否存在。

```ts
import { huks } from '@kit.UniversalKeystoreKit';

/* 1.确定密钥别名 */
let keyAlias = 'test_key';
let isKeyExist: Boolean;
/* 2.构造空对象 */
let huksOptions: huks.HuksOptions = {
  properties: []
}
try {
  /* 3.判断密钥是否存在 */
  huks.hasKeyItem(keyAlias, huksOptions, (error, data) => {
    if (error) {
      console.error(`callback: hasKeyItem failed, ` + JSON.stringify(error));
    } else {
      if (data !== null && data.valueOf() !== null) {
        isKeyExist = data.valueOf();
        console.info(`callback: hasKeyItem success, isKeyExist = ${isKeyExist}`);
      }
    }
  });
} catch (error) {
  console.error(`callback: hasKeyItem input arg invalid, ` + JSON.stringify(error));
}
```
