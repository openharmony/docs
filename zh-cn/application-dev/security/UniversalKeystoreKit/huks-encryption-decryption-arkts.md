# 加解密(ArkTS)

以AES 128密钥为例，完成加解密。具体的场景介绍及支持的算法规格，请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。

## 开发步骤

**生成密钥**

1. 指定密钥别名。

2. 初始化密钥属性集。

3. 调用[generateKeyItem](../../reference/apis/js-apis-huks.md#huksgeneratekeyitem9)生成密钥，具体请参考[密钥生成](huks-key-generation-overview.md)。

除此之外，开发者也可以参考[密钥导入](huks-key-import-overview.md)，导入已有的密钥。

**加密**

1. 获取密钥别名。

2. 获取待加密的数据。

3. 获取加密[算法参数配置](../../reference/apis/js-apis-huks.md#huksparam)。
   在下方示例中，使用算法AES进行加密时，必须要选择其对应分组模式以及填充模式，用例中选取的分组模式为CBC、填充模式为PKCS7，此时必须要填参数IV。

4. 调用[initSession](../../reference/apis/js-apis-huks.md#huksinitsession9)初始化密钥会话，并获取会话的句柄handle。

5. 调用[finishSession](../../reference/apis/js-apis-huks.md#huksfinishsession9)结束密钥会话，获取加密后的密文。

**解密**

1. 获取密钥别名。

2. 获取待解密的密文。

3. 获取解密[算法参数配置](../../reference/apis/js-apis-huks.md#huksparam)。
   不同的解密算法需写入不同的参数配置，具体请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。

   在下方示例中，使用算法AES进行解密时，必须要选择其对应分组模式以及填充模式，用例中选取的分组模式为CBC、填充模式为PKCS7，此时必须要填参数IV。

4. 调用[initSession](../../reference/apis/js-apis-huks.md#huksinitsession9)初始化密钥会话，并获取会话的句柄handle。

5. 调用[finishSession](../../reference/apis/js-apis-huks.md#huksfinishsession9)结束密钥会话，获取解密后的数据。

**删除密钥**

当密钥废弃不用时，需要调用[deleteKeyItem](../../reference/apis/js-apis-huks.md#huksdeletekeyitem9)删除密钥，具体请参考[密钥删除](huks-delete-key-arkts.md)。

```ts
/*
 * 以下以AES 128密钥的Promise操作使用为例
 */
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';
let aesKeyAlias = 'test_aesKeyAlias';
let handle:number;
let plainText = '123456';
let IV = '001122334455';
let cipherData:Uint8Array;
function StringToUint8Array(str: String) {
    let arr:number[]=new Array();
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}
function Uint8ArrayToString(fileData:Uint8Array) {
    let dataString = '';
    for (let i = 0; i < fileData.length; i++) {
        dataString += String.fromCharCode(fileData[i]);
    }
    return dataString;
}
function GetAesGenerateProperties() {
    let properties: Array<huks.HuksParam> = new Array();
    let index = 0;
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_AES
    };
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
    };
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
    }
    return properties;
}
function GetAesEncryptProperties() {
    let properties: Array<huks.HuksParam> = new Array();
    let index = 0;
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_AES
    };
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
    };
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
    }
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
    }
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_CBC
    }
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_IV,
        value: StringToUint8Array(IV)
    }
    return properties;
}
function GetAesDecryptProperties() {
    let properties: Array<huks.HuksParam> = new Array();
    let index = 0;
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_AES
    };
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
    };
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
    }
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
    }
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_CBC
    }
    properties[index++] = {
        tag: huks.HuksTag.HUKS_TAG_IV,
        value: StringToUint8Array(IV)
    }
    return properties;
}
async function GenerateAesKey() {
    /*
    * 模拟生成密钥场景
    * 1. 确定密钥别名
    */
    /*
    * 2. 获取生成密钥算法参数配置
    */
    let genProperties = GetAesGenerateProperties();
    let options: huks.HuksOptions = {
        properties: genProperties
    }
    /*
    * 3. 调用generateKeyItem
    */
    await huks.generateKeyItem(aesKeyAlias, options)
    .then((data) => {
        console.info(`promise: generate AES Key success, data = ${JSON.stringify(data)}`);
    }).catch((error: BusinessError)=>{
        console.error(`promise: generate AES Key failed` + error);
    })
}
async function EncryptData() {
    /*
    * 模拟加密场景
    * 1. 获取密钥别名
    */
    /*
    * 2. 获取待加密的数据
    */
    /*
    * 3. 获取加密算法参数配置
    */
    let encryptProperties = GetAesEncryptProperties();
    let options: huks.HuksOptions = {
        properties: encryptProperties,
        inData: StringToUint8Array(plainText)
    }
    /*
    * 4. 调用initSession获取handle
    */
    await huks.initSession(aesKeyAlias, options)
    .then((data) => {
        handle = data.handle;
    }).catch((error: BusinessError)=>{
        console.error(`promise: init encryptdata failed` + error);
    })
    /*
    * 5. 调用finishSession获取加密后的密文
    */
    await huks.finishSession(handle, options)
    .then((data) => {
        console.info(`promise: encrypt data success, data is `+ Uint8ArrayToString(data.outData as Uint8Array));
        cipherData = data.outData as Uint8Array;
    }).catch((error: BusinessError)=>{
        console.error(`promise: encrypt data failed` + error);
    })
}
async function DecryptData() {
    /*
    * 模拟解密场景
    * 1. 获取密钥别名
    */
    /*
    * 2. 获取待解密的密文
    */
    /*
    * 3. 获取解密算法参数配置
    */
    let decryptOptions = GetAesDecryptProperties()
    let options: huks.HuksOptions = {
        properties: decryptOptions,
        inData: cipherData
    }
    /*
    * 4. 调用initSession获取handle
    */
    await huks.initSession(aesKeyAlias, options)
    .then((data) => {
        handle = data.handle;
    }).catch((error: BusinessError)=>{
        console.error(`promise: init decryptdata failed` + error);
    })
    /*
    * 5. 调用finishSession获取解密后的数据
    */
    await huks.finishSession(handle, options)
    .then((data) => {
        console.info(`promise: decrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((error: BusinessError)=>{
        console.error(`promise: decrypt data failed` + error);
    })
}
async function DeleteKey() {
    /*
    * 模拟删除密钥场景
    * 1. 获取密钥别名
    */
    let emptyOptions: huks.HuksOptions = {
        properties: []
    }
    /*
    * 2. 调用deleteKeyItem删除密钥
    */
    await huks.deleteKeyItem(aesKeyAlias, emptyOptions)
    .then((data) => {
        console.info(`promise: delete data success`);
    }).catch((error: BusinessError)=>{
        console.error(`promise: delete data failed` + error);
    })
}
```
