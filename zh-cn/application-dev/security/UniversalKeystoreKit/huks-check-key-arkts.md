# 查询密钥是否存在(ArkTS)


HUKS提供了接口供应用查询指定密钥是否存在。


## 开发步骤

1. 指定密钥别名keyAlias，密钥别名最大长度为64字节。

2. 初始化密钥属性集。用于查询时指定密钥的属性TAG，比如查询的密钥范围(全量/单个)，当查询单个时，TAG字段可传空。

3. 调用接口[isKeyItemExist](../../reference/apis/js-apis-huks.md#huksiskeyitemexist9)，查询密钥是否存在。

```ts
import huks from '@ohos.security.huks';
/* 1.确定密钥别名 */
let keyAlias = 'test_key';
let isKeyExist: Boolean;
/* 2.构造空对象 */
let huksOptions:huks.HuksOptions = {
  properties: []
}
try {
  /* 3.判断密钥是否存在 */
  huks.isKeyItemExist(keyAlias, huksOptions, (error, data) => {
    if (error) {
      console.error(`callback: isKeyItemExist failed` + error);
    } else {
      if (data !== null && data.valueOf() !== null) {
        isKeyExist = data.valueOf();
        console.info(`callback: isKeyItemExist success, isKeyExist = ${isKeyExist}`);
      }
    }
  });
} catch (error) {
  console.error(`callback: isKeyItemExist input arg invalid` + error);
}
```
