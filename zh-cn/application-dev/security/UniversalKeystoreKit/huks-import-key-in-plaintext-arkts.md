# 明文导入密钥(ArkTS)


以导入AES256密钥为例，具体的场景介绍及支持的算法规格，请参考[密钥导入的支持的算法](huks-key-import-overview.md#支持的算法)。


## 开发步骤

1. 指定密钥别名keyAlias。
   密钥别名的最大长度为64字节。

2. 封装密钥属性集和密钥材料。
   - 密钥属性集同样与密钥生成中指定的密钥属性一致，须包含[HuksKeyAlg](../../reference/apis/js-apis-huks.md#hukskeyalg)、[HuksKeySize](../../reference/apis/js-apis-huks.md#hukskeysize)、[HuksKeyPurpose](../../reference/apis/js-apis-huks.md#hukskeypurpose)属性。
   - 密钥材料须符合[HUKS密钥材料格式](huks-concepts.md#密钥材料格式)，并以Uint8Array形式赋值给[HuksOptions](../../reference/apis/js-apis-huks.md#huksoptions)的inData字段。

3. 调用[huks.importKeyItem](../../reference/apis/js-apis-huks.md#huksimportkeyitem9)，传入密钥别名和密钥属性集，即可导入密钥。

```ts
/* 以下以导入AES256密钥的Callback操作使用为例 */
import huks from '@ohos.security.huks'
/* 密钥材料 */
let plainTextSize32 = new Uint8Array([
    0xfb, 0x8b, 0x9f, 0x12, 0xa0, 0x83, 0x19, 0xbe, 0x6a, 0x6f, 0x63, 0x2a, 0x7c, 0x86, 0xba, 0xca,
    0x64, 0x0b, 0x88, 0x96, 0xe2, 0xfa, 0x77, 0xbc, 0x71, 0xe3, 0x0f, 0x0f, 0x9e, 0x3c, 0xe5, 0xf9
]);
/* 1.确定密钥别名 */
let keyAlias = 'AES256Alias_sample';
/* 2.封装密钥属性集和密钥材料 */
class propertyType {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose = huks.HuksKeyAlg.HUKS_ALG_RSA;
}
let properties: propertyType[] = [
    {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value:huks.HuksKeyAlg.HUKS_ALG_AES
    },
    {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
    },
    {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
    },
]
let options: huks.HuksOptions = {
    properties: properties,
    inData: plainTextSize32
};
/* 3.明文导入密钥 */
try {
    huks.importKeyItem(keyAlias, options, (error, data) => {
        if (error) {
            console.error(`callback: importKeyItem failed` + error);
        } else {
            console.info(`callback: importKeyItem success`);
        }
    });
} catch (error) {
    console.error(`callback: importKeyItem input arg invalid` + error);
}
```


## 调测验证

调用[huks.isKeyItemExist](../../reference/apis/js-apis-huks.md#huksiskeyitemexist9)验证密钥是否存在，如密钥存在即表示密钥导入成功。

```ts
import huks from '@ohos.security.huks';
let keyAlias = 'AES256Alias_sample';
let isKeyExist = false;
class keyPropertyType {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
    value: huks.HuksKeyAlg = huks.HuksKeyAlg.HUKS_ALG_RSA;
}
let keyProperties: keyPropertyType[] = [
    {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_AES
    },
]
let huksOptions: huks.HuksOptions = {
    properties: keyProperties, // 非空填充
    inData: new Uint8Array(new Array()) // 非空填充
}
try {
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
