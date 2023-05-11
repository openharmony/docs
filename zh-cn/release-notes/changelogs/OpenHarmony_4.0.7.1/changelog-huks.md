# HUKS子系统ChangeLog

## cl.huks.1 HUKS支持可选设置rsa_pss_salt_length类型

变更之前，应用在签名/验签时，HUKS默认使用RSA_PSS_SALT_LEN_MAX进行处理；

变更之后，应用在签名/验签需传入HuksRsaPssSaltLenType中定义的类型。若不传入，则默认使用RSA_PSS_SALT_LEN_MAX进行处理。

**变更影响**

影响已发布的JS接口，接口行为发生变更。

**关键的接口/组件变更**

发布的JS接口不变， 传入接口的参数集合发生变更。

**适配指导**

以RSA签名为例，示例代码如下：

```js
import huks from '@ohos.security.huks';

let keyAlias = 'rsa_Key';
let inData = new Uint8Array(
    0x4B, 0x1E, 0x22, 0x64, 0xA9, 0x89, 0x60, 0x1D, 0xEC, 0x78, 0xC0, 0x5D, 0xBE, 0x46, 0xAD, 0xCF,
    0x1C, 0x35, 0x16, 0x11, 0x34, 0x01, 0x4E, 0x9B, 0x7C, 0x00, 0x66, 0x0E, 0xCA, 0x09, 0xC0, 0xF3,
);
/* 签名参数 */
let signProperties = new Array();
signProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA,
}
signProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
}
signProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048,
}
signProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PSS,
}
signProperties[4] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA1,
}
signProperties[5] = {
    tag: huks.HuksTag.HUKS_TAG_RSA_PSS_SALT_LEN_TYPE,
    value: huks.HuksRsaPssSaltLenType.HUKS_RSA_PSS_SALT_LEN_MAX,
}
let signOptions = {
    properties: signProperties,
    inData: inData
}

huks.initSession(keyAlias, signOptions);
```

更多接口的示例代码可参考[HUKS-guidelines](../../../application-dev/security/huks-guidelines.md)和[HUKS API](../../../application-dev/reference/apis/js-apis-huks.md)。

## cl.huks.2 HUKS解决派生密钥/协商密钥的存储/导出问题

变更之前，派生密钥/协商密钥既支持存储，又支持导出，存在安全风险；

变更之后，应用在派生密钥/协商密钥时需传入HuksKeyStorageType中定义的类型。应用只能选择存储，或者选择导出。若不传入，则默认同时支持存储和导出，存在安全问题，不推荐业务使用。

**变更影响**

影响已发布的JS接口，接口行为发生变更。

**关键的接口/组件变更**

发布的JS接口不变， 传入接口的参数集合发生变更。

**适配指导**

接口使用的示例代码可参考[HUKS-guidelines](../../../application-dev/security/huks-guidelines.md)和[HUKS API](../../../application-dev/reference/apis/js-apis-huks.md)。

## cl.huks.3 新增用于细粒度用户身份访问控制的Tag

新增用于细粒度用户身份访问控制的HuksTag: HUKS_TAG_KEY_AUTH_PURPOSE，业务可在原有用户身份访问控制能力上，选择某种特定算法用途下需要用户身份访问控制能力。

**变更影响**

新增的HuksTag，不影响已有的接口。

**关键的接口/组件变更**

只新增了HuksTag: HUKS_TAG_KEY_AUTH_PURPOSE, 用于支持细粒度用户身份访问控制。

**适配指导**

接口使用的示例代码可参考[密钥访问控制_细粒度用户身份认证访问控制](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/huks-guidelines.md#%E5%AF%86%E9%92%A5%E8%AE%BF%E9%97%AE%E6%8E%A7%E5%88%B6)，接口定义参考[HuksTag](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-huks.md#hukstag)。