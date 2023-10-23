
# 通用密钥库开发指导(ArkTS)

> **说明**
>
> 本开发指导需使用API version 9及以上版本SDK。

## 生成新密钥

HUKS提供为业务安全随机生成密钥的能力。通过HUKS生成的密钥，密钥的全生命周期明文不会出安全环境，能保证任何人都无法接触获取到密钥的明文。即使生成密钥的业务自身，后续也只能通过HUKS提供的接口请求执行密钥操作，获取操作结果，但无法接触到密钥自身。

**开发步骤**

生成密钥时使用[huks.generateKeyItem(keyAlias,options,callback)](../reference/apis/js-apis-huks.md#huksgeneratekeyitem9)方法，传入keyAlias作为密钥别名，传入options包含该密钥的属性集，传入callback用于回调异步结果。关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

1. 确定密钥别名；
2. 初始化密钥属性集：通过[HuksParam](../reference/apis/js-apis-huks.md#huksparam)封装密钥属性，搭配Array组成密钥属性集，并赋值给[HuksOptions](../reference/apis/js-apis-huks.md#huksoptions)（properties字段），其中必须包含[HuksKeyAlg](../reference/apis/js-apis-huks.md#hukskeyalg),[HuksKeySize](../reference/apis/js-apis-huks.md#hukskeysize),[HuksKeyPurpose](../reference/apis/js-apis-huks.md#hukskeypurpose)属性；
3. 将密钥别名与密钥参数集作为参数传入，生成密钥。

> **说明**
>
> 存储的 keyAlias 密钥别名最大为64字节

**代码示例：**

```ts
/*
 * 以下以生成DH密钥的Callback操作使用为例
 */
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';

class HuksProperties {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
    value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest = huks.HuksKeyAlg.HUKS_ALG_ECC;
}

/*
 * 确定密钥别名和封装密钥属性参数集
 */
let keyAlias = 'dh_key';
let properties1: HuksProperties[] = [
    {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_DH
    },
    {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
    },
    {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_2048
    },
    {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    }
];

let huksOptions: huks.HuksOptions = {
    properties: properties1,
    inData: new Uint8Array(new Array())
}

/*
 * 生成密钥
 */
function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions){
    return new Promise<void>((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, (error, data) => {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw (error as Error);
        }
    });
}

async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
        .then((data) => {
            console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
        })
        .catch((error: BusinessError) => {
            console.error(`callback: generateKeyItem failed`);
        });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid`);
    }
}

async function TestGenKey() {
    await publicGenKeyFunc(keyAlias, huksOptions);
}
```

## 导入外部密钥

如果密钥是在HUKS外部生成（比如应用间协商生成、服务器端生成），应用可以将密钥导入到HUKS托管。HUKS支持直接将密钥明文导入到HUKS，但是明文导入会导致密钥暴露在REE内存中，一般适用于轻量级设备或低安业务。对于高安敏感业务，HUKS还提供了安全导入密钥的能力，允许业务自己生成密钥，并通过与处于安全环境中的HUKS建立端到端的加密传输通道，将密钥安全加密导入到HUKS中，确保导入传入过程中密钥不被泄露。

与生成密钥一样，密钥一旦导入到HUKS中，密钥的生命周期明文不出安全环境，同样能保证任何人都无法接触获取到密钥的明文。

### 明文导入

导入明文密钥时使用[huks.importKeyItem(keyAlias,options,callback)](../reference/apis/js-apis-huks.md#huksimportkeyitem9)方法，传入keyAlias作为密钥别名，传入options，其中必须包含密钥材料和密钥属性集，传入callback用于回调异步结果。关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

1. 确定密钥别名；
2. 封装密钥材料和密钥属性集：密钥材料须符合[HUKS密钥材料格式](./huks-appendix.md#密钥材料格式)并以Uint8Array形式赋值给[HuksOptions](../reference/apis/js-apis-huks.md#huksoptions)的inData字段；另外，通过[HuksParam](../reference/apis/js-apis-huks.md#huksparam)封装密钥属性，搭配Array组成密钥属性集赋值给properties字段，属性集中必须包含[HuksKeyAlg](../reference/apis/js-apis-huks.md#hukskeyalg),[HuksKeySize](../reference/apis/js-apis-huks.md#hukskeysize),[HuksKeyPurpose](../reference/apis/js-apis-huks.md#hukskeypurpose)属性；
3. 导入密钥。

**代码示例：**

```ts
import huks from '@ohos.security.huks'

/*
 * 以导入AES256密钥为例
 */

/* 密钥 */
let plainTextSize32 = new Uint8Array([
    0xfb, 0x8b, 0x9f, 0x12, 0xa0, 0x83, 0x19, 0xbe, 0x6a, 0x6f, 0x63, 0x2a, 0x7c, 0x86, 0xba, 0xca,
    0x64, 0x0b, 0x88, 0x96, 0xe2, 0xfa, 0x77, 0xbc, 0x71, 0xe3, 0x0f, 0x0f, 0x9e, 0x3c, 0xe5, 0xf9
]);

/*
 * 确定密钥别名
 */
let keyAlias = 'AES256Alias_sample';

/*
 * 封装密钥属性集和密钥材料
 */
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

/*
 * 导入密钥
 */
try {
    huks.importKeyItem(keyAlias, options, (error, data) => {
         if (error) {
            console.error(`callback: importKeyItem failed`);
        } else {
            console.info(`callback: importKeyItem success`);
        }
    });
} catch (error) {
    console.error(`callback: importKeyItem input arg invalid`);
}
```

**调测验证**

验证时查询密钥是否存在，如密钥存在即表示生成密钥成功。

**代码示例：**

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
            console.error(`callback: isKeyItemExist failed`);
        } else {
            if (data !== null && data.valueOf() !== null) {
                isKeyExist = data.valueOf();
                console.info(`callback: isKeyItemExist success, isKeyExist = ${isKeyExist}`);
            }
        }
    });
} catch (error) {
    console.error(`callback: isKeyItemExist input arg invalid`);
}
```

### 加密导入

相比明文导入，加密导入步骤更多，密钥材料更复杂，此章节将展示开发过程中关键的开发流程和密钥材料数据结构。下图是加密导入的基本开发流程。

**图2** 加密导入开发流程

![huks_import_wrapped_key](figures/huks_import_wrapped_key.png)

**接口说明**

根据开发流程，在导入加密密钥过程中，需要依次调用HUKS的生成密钥、导出公钥、导入加密密钥、删除密钥接口。

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

**表1** 加密导入的接口介绍

| 接口名                      | 描述                 |
| -------------------------------------- | ----------------------------|
|generateKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>) : void| 生成新密钥|
|exportKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>) : void| 导出密钥对的公钥|
|importWrappedKeyItem(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>) : void|导入加密密钥|
|deleteKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<void>) : void|删除密钥|

需要注意的是，导出密钥接口返回的公钥明文材料是按照**X.509**格式封装，导入加密密钥接口中的密钥材料需满足**Length<sub>Data</sub>-Data** 的格式封装。具体，应用需要申请一个Uint8Array按照以下表格中的顺序依次封装。

**表2** 加密密钥材料格式

| 内容 | 业务公钥长度L<sub>pk2</sub> | 业务公钥pk2 | k2加密参数AAD2长度L<sub>AAD2</sub> | k2加密参数AAD2 |  k2加密参数Nonce2长度L<sub>Nonce2</sub> | k2加密参数Nonce2 |
| :--: |:----:|:----: |:----: | :----:  | :----:|:----:|
|长度| 4字节 |L<sub>pk2</sub>字节| 4字节 | L<sub>AAD2</sub>字节 | 4字节 | L<sub>Nonce2</sub>字节 |
| 内容 | k2加密参数AEAD2长度L<sub>AEAD2</sub> | k2加密参数AEAD2 | k3密文长度L<sub>k3_enc</sub> | k3密文k3_enc |  k3加密参数AAD3长度L<sub>AAD3</sub> | k3加密参数AAD3 |
|长度| 4字节 |L<sub>AEAD2</sub>字节| 4字节 | L<sub>k3_enc</sub>字节 | 4字节 | L<sub>AAD3</sub>字节 |
| 内容| k3加密参数Nonce3长度L<sub>Nonce3</sub> | k3加密参数Nonce3 | k3加密参数AEAD3长度L<sub>AEAD3</sub> | k3加密参数AEAD3 |  **密钥明文材料长度** 的长度L<sub>k1'_size</sub> | 密钥明文材料长度k1'_size |
|长度| 4字节 |L<sub>Nonce3</sub>字节| 4字节 | L<sub>AEAD3</sub>字节 | 4字节 | L<sub>k1'_size</sub>字节 |
|内容|k1'密文长度L<sub>k1'_enc</sub>| k1'密文k1'_enc| | | | |
|长度| 4字节 |L<sub>k1'_enc</sub>字节| | | | |

**开发步骤**

这里主要展示涉及调用HUKS的开发样例（使用ECDH密钥协商套件），部分在业务本地执行的步骤不在这里展示详细样例。

1. 生成加密导入用途的密钥Caller_Key和Wrapping_Key
2. 导出公钥材料
3. 生成一个对称密钥Caller_Kek
4. 使用Caller_Key和Wrapping_Key的公钥，协商出Agree_Key
5. 使用Caller_Kek加密待导入密钥
6. 使用Agree_Key加密Caller_Kek
7. 封装加密导入密钥材料
8. 导入封装的加密密钥材料
9. 删除用于加密导入的密钥

**代码示例：**

```ts
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';

let IV = '0000000000000000';
let AAD = "abababababababab";
let NONCE = "hahahahahaha";
let TAG_SIZE = 16;
let FILED_LENGTH = 4;
let importedAes192PlainKey = "The aes192 key to import";
let callerAes256Kek = "The is kek to encrypt aes192 key";

let callerKeyAlias = "test_caller_key_ecdh_aes192";
let callerKekAliasAes256 = "test_caller_kek_ecdh_aes256";
let callerAgreeKeyAliasAes256 = "test_caller_agree_key_ecdh_aes256";
let importedKeyAliasAes192 = "test_import_key_ecdh_aes192";

let huksPubKey: Uint8Array;
let callerSelfPublicKey: Uint8Array;
let outSharedKey: Uint8Array;
let outPlainKeyEncData: Uint8Array;
let outKekEncData: Uint8Array;
let outKekEncTag: Uint8Array;
let outAgreeKeyEncTag: Uint8Array;

let mask = [0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000];
function subUint8ArrayOf(arrayBuf: Uint8Array, start: number, end: number) {
    let arr: number[] = [];
    for (let i = start; i < end && i < arrayBuf.length; ++i) {
        arr.push(arrayBuf[i]);
    }
    return new Uint8Array(arr);
}

function stringToUint8Array(str: string) {
    let arr: number[] = [];
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

function assignLength(length: number, arrayBuf: Uint8Array, startIndex: number) {
    let index = startIndex;
    for (let i = 0; i < 4; i++) {
        arrayBuf[index++] = (length & mask[i]) >> (i * 8);
    }
    return 4;
}

function assignData(data: Uint8Array, arrayBuf: Uint8Array, startIndex: number) {
    let index = startIndex;
    for (let i = 0; i < data.length; i++) {
        arrayBuf[index++] = data[i];
    }
    return data.length;
}


let genWrappingKeyParams:huks.HuksOptions = {
    properties: new Array<huks.HuksParam>(
        {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_ECC
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_UNWRAP
        },
        {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_NONE
        }
    )
}

let genCallerEcdhParams:huks.HuksOptions = {
    properties: new Array<huks.HuksParam>(
        {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_ECC
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
        },
        {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256
        }
    )
}

let importParamsCallerKek: huks.HuksOptions = {
    properties: new Array<huks.HuksParam>(
        {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_AES
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
        },
        {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_NONE
        },
        {
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
            value: huks.HuksCipherMode.HUKS_MODE_GCM
        },
        {
            tag: huks.HuksTag.HUKS_TAG_DIGEST,
            value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
        },
        {
            tag: huks.HuksTag.HUKS_TAG_IV,
            value: stringToUint8Array(IV)
        }
    ),
    inData: stringToUint8Array(callerAes256Kek)
}

let importParamsAgreeKey: huks.HuksOptions = {
    properties: new Array<huks.HuksParam>(
        {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_AES
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
        },
        {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_NONE
        },
        {
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
            value: huks.HuksCipherMode.HUKS_MODE_GCM
        },
        {
            tag: huks.HuksTag.HUKS_TAG_DIGEST,
            value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
        },
        {
            tag: huks.HuksTag.HUKS_TAG_IV,
            value: stringToUint8Array(IV)
        }
    ),
}

let callerAgreeParams: huks.HuksOptions = {
    properties: new Array<huks.HuksParam>(
        {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_ECDH
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
        },
        {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256
        }
    )
}

let encryptKeyCommonParams: huks.HuksOptions = {
    properties: new Array<huks.HuksParam>(
        {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_AES
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
        },
        {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_NONE
        },
        {
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
            value: huks.HuksCipherMode.HUKS_MODE_GCM
        },
        {
            tag: huks.HuksTag.HUKS_TAG_NONCE,
            value: stringToUint8Array(NONCE)
        },
        {
            tag: huks.HuksTag.HUKS_TAG_ASSOCIATED_DATA,
            value: stringToUint8Array(AAD)
        }
    ),
}

let importWrappedAes192Params: huks.HuksOptions = {
    properties: new Array<huks.HuksParam>(
        {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_AES
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
            huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
        },
        {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_192
        },
        {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_NONE
        },
        {
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
            value: huks.HuksCipherMode.HUKS_MODE_CBC
        },
        {
            tag: huks.HuksTag.HUKS_TAG_DIGEST,
            value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
        },
        {
            tag: huks.HuksTag.HUKS_TAG_UNWRAP_ALGORITHM_SUITE,
            value: huks.HuksUnwrapSuite.HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING
        },
        {
            tag: huks.HuksTag.HUKS_TAG_IV,
            value: stringToUint8Array(IV)
        }
    )
}

async function publicGenerateItemFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter promise generateKeyItem`);
    try {
        await huks.generateKeyItem(keyAlias, huksOptions)
        .then(data => {
            console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
        })
        .catch((err: BusinessError) => {
            console.error(`callback: generateKeyItem failed`);
        })
    } catch (err) {
        console.error(`callback: generateKeyItem invalid`);
    }
}

async function publicImportKeyItemFunc(keyAlias: string, HuksOptions: huks.HuksOptions) {
    console.info(`enter promise importKeyItem`);
    try {
        await huks.importKeyItem(keyAlias, HuksOptions)
        .then(data => {
            console.info(`promise: importKeyItem success, data = ${JSON.stringify(data)}`);
        }).catch((err: BusinessError) => {
            console.error(`promise: importKeyItem failed`);
        })
    } catch (err) {
        console.error(`promise: importKeyItem input arg invalid`);
    }
}

async function publicDeleteKeyItemFunc(KeyAlias: string, HuksOptions: huks.HuksOptions) {
    console.info(`enter promise deleteKeyItem`);
    try {
        await huks.deleteKeyItem(KeyAlias, HuksOptions)
        .then(data => {
            console.info(`promise: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
        })
        .catch((err: BusinessError) => {
            console.error(`promise: deleteKeyItem failed`);
        })
    } catch (err) {
        console.error(`promise: deleteKeyItem input arg invalid`);
    }
}

function importWrappedKeyItem(keyAlias: string, wrappingKeyAlias: string, huksOptions: huks.HuksOptions) {
    return new Promise<void>((resolve, reject) => {
        try {
            huks.importWrappedKeyItem(keyAlias, wrappingKeyAlias, huksOptions, (error, data) => {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
        }
    });
}

async function publicImportWrappedKeyFunc(keyAlias: string, wrappingKeyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter callback importWrappedKeyItem`);
    for (let i = 0; i < huksOptions.inData!.length; i++) {
        console.error(`${i}: ${huksOptions.inData![i]}`);
    }
    try {
        await importWrappedKeyItem(keyAlias, wrappingKeyAlias, huksOptions)
        .then((data) => {
            console.info(`callback: importWrappedKeyItem success, data = ${JSON.stringify(data)}`);
        })
        .catch((error: BusinessError) => {
            console.error(`callback: importWrappedKeyItem failed`);
        });
    } catch (error) {
        console.error(`callback: importWrappedKeyItem input arg invalid`);
    }
}

async function publicImportWrappedKeyPromise(keyAlias: string, wrappingKeyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter callback importWrappedKeyItem`);
    try {
        await huks.importWrappedKeyItem(keyAlias, wrappingKeyAlias, huksOptions)
        .then((data) => {
            console.info(`callback: importWrappedKeyItem success, data = ${JSON.stringify(data)}`);
        })
        .catch((error: BusinessError) => {
            console.error(`callback: importWrappedKeyItem failed`);
        });
    } catch (error) {
        console.error(`callback: importWrappedKeyItem input arg invalid`);
    }
}

async function publicInitFunc(srcKeyAlias: string, HuksOptions: huks.HuksOptions) {
    let handle: number = 0;
    console.info(`enter promise doInit`);
    try {
        await huks.initSession(srcKeyAlias, HuksOptions)
        .then((data) => {
            console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
            handle = data.handle;
        })
        .catch((error: BusinessError) => {
            console.error(`promise: doInit key failed`);
        });
    } catch (error) {
        console.error(`promise: doInit input arg invalid`);
    }
    return handle;
}

async function publicUpdateSessionFunction(handle: number, HuksOptions: huks.HuksOptions) {
    const maxUpdateSize = 64;
    const inData = HuksOptions.inData!;
    const lastInDataPosition = inData.length - 1;
    let inDataSegSize = maxUpdateSize;
    let inDataSegPosition = 0;
    let isFinished = false;
    let outData: number[] = [];
    
    while (inDataSegPosition <= lastInDataPosition) {
        if (inDataSegPosition + maxUpdateSize > lastInDataPosition) {
            isFinished = true;
            inDataSegSize = lastInDataPosition - inDataSegPosition + 1;
            console.error(`enter promise doUpdate`);
            break;
        }
        HuksOptions.inData = new Uint8Array(
           Array.from(inData).slice(inDataSegPosition, inDataSegPosition + inDataSegSize)
        );
        console.error(`enter promise doUpdate`);
        try {
            await huks.updateSession(handle, HuksOptions)
            .then((data) => {
                console.error(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
                outData = outData.concat(Array.from(data.outData!));
            })
            .catch((error: BusinessError) => {
                console.error(`promise: doUpdate failed`);
            });
        } catch (error) {
            console.error(`promise: doUpdate input arg invalid`);
        }
        if ((!isFinished) && (inDataSegPosition + maxUpdateSize > lastInDataPosition)) {
            console.log(`update size invalid isFinished = ${isFinished}`);
            console.log(`inDataSegPosition = ${inDataSegPosition}`);
            console.log(`lastInDataPosition = ${lastInDataPosition}`);
            return;
        }
        inDataSegPosition += maxUpdateSize;
    }
    return outData;
}

async function publicFinishSession(handle: number, HuksOptions: huks.HuksOptions, inData: number[]) {
    let outData: number[] = [];
    console.info(`enter promise doFinish`);
    try {
        await huks.finishSession(handle, HuksOptions)
        .then((data) => {
            console.info(`promise: doFinish success, data = ${JSON.stringify(data)}`);
            outData = inData.concat(Array.from(data.outData!));
        })
        .catch((error: BusinessError) => {
            console.error(`promise: doFinish key failed`);
        });
    } catch (error) {
        console.error(`promise: doFinish input arg invalid`);
    }
    return new Uint8Array(outData);
}

async function cipherFunction(keyAlias: string, HuksOptions: huks.HuksOptions) {
    let handle = await publicInitFunc(keyAlias, HuksOptions);
    let tmpData = await publicUpdateSessionFunction(handle, HuksOptions);
    let outData = await publicFinishSession(handle, HuksOptions, tmpData!);
    return outData;
}

async function agreeFunction(keyAlias: string, HuksOptions: huks.HuksOptions, huksPublicKey: Uint8Array) {
    let handle = await publicInitFunc(keyAlias, HuksOptions);
    let outSharedKey: Uint8Array = new Uint8Array;
    HuksOptions.inData = huksPublicKey;
    console.error(`enter promise doUpdate`);
    try {
        await huks.updateSession(handle, HuksOptions)
        .then((data) => {
            console.error(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
        })
        .catch((error: BusinessError) => {
            console.error(`promise: doUpdate failed`);
        });
    } catch (error) {
        console.error(`promise: doUpdate input arg invalid`);
    }
    console.info(`enter promise doInit`);
    try {
        await huks.finishSession(handle, HuksOptions)
        .then((data) => {
            console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
            outSharedKey = data.outData as Uint8Array;
        })
        .catch((error: BusinessError) => {
            console.error(`promise: doInit key failed`);
        });
    } catch (error) {
        console.error(`promise: doInit input arg invalid`);
    }
    return outSharedKey;
}

async function ImportKekAndAgreeSharedSecret(callerKekAlias: string, importKekParams: huks.HuksOptions, callerKeyAlias: string, huksPublicKey: Uint8Array, agreeParams: huks.HuksOptions) {
    await publicImportKeyItemFunc(callerKekAlias, importKekParams);
    outSharedKey = await agreeFunction(callerKeyAlias, agreeParams, huksPublicKey);

    importParamsAgreeKey.inData = outSharedKey;
    await publicImportKeyItemFunc(callerAgreeKeyAliasAes256, importParamsAgreeKey);
}

async function generateAndExportPublicKey(keyAlias: string, HuksOptions: huks.HuksOptions, caller: Boolean) {
    await publicGenerateItemFunc(keyAlias, HuksOptions);
    try {
        await huks.exportKeyItem(keyAlias, HuksOptions)
        .then((data) => {
            console.info(`promise: exportKeyItem success, data = ${JSON.stringify(data)}`);
            if (caller) {
                callerSelfPublicKey = data.outData as Uint8Array;
            } else {
                huksPubKey = data.outData as Uint8Array;
            }
        })
        .catch((error: BusinessError) => {
            console.error(`promise: exportKeyItem failed`);
        });
    } catch (e) {
        console.error(`promise: generate pubKey failed`);
    }
}

async function EncryptImportedPlainKeyAndKek(keyAlias: string) {
    encryptKeyCommonParams.inData = stringToUint8Array(keyAlias)
    let plainKeyEncData = await cipherFunction(callerKekAliasAes256, encryptKeyCommonParams);
    outKekEncTag = subUint8ArrayOf(plainKeyEncData, plainKeyEncData.length - TAG_SIZE, plainKeyEncData.length)
    outPlainKeyEncData = subUint8ArrayOf(plainKeyEncData, 0, plainKeyEncData.length - TAG_SIZE)

    encryptKeyCommonParams.inData = stringToUint8Array(callerAes256Kek)
    let kekEncData = await cipherFunction(callerAgreeKeyAliasAes256, encryptKeyCommonParams)
    outAgreeKeyEncTag = subUint8ArrayOf(kekEncData, kekEncData.length - TAG_SIZE, kekEncData.length)
    outKekEncData = subUint8ArrayOf(kekEncData, 0, kekEncData.length - TAG_SIZE)
}

async function BuildWrappedDataAndImportWrappedKey(plainKey: string) {
    let plainKeySizeBuff = new Uint8Array(4);
    assignLength(plainKey.length, plainKeySizeBuff, 0);

    let wrappedData = new Uint8Array(
        FILED_LENGTH + huksPubKey.length +
        FILED_LENGTH + AAD.length +
        FILED_LENGTH + NONCE.length +
        FILED_LENGTH + TAG_SIZE +
        FILED_LENGTH + outKekEncData.length +
        FILED_LENGTH + AAD.length +
        FILED_LENGTH + NONCE.length +
        FILED_LENGTH + TAG_SIZE +
        FILED_LENGTH + plainKeySizeBuff.length +
        FILED_LENGTH + outPlainKeyEncData.length
    );
    let index = 0;
    let AADUint8Array = stringToUint8Array(AAD);
    let NonceArray = stringToUint8Array(NONCE);

    index += assignLength(callerSelfPublicKey.length, wrappedData, index);  // 4
    index += assignData(callerSelfPublicKey, wrappedData, index); // 91
    index += assignLength(AADUint8Array.length, wrappedData, index); // 4
    index += assignData(AADUint8Array, wrappedData, index); // 16
    index += assignLength(NonceArray.length, wrappedData, index); // 4
    index += assignData(NonceArray, wrappedData, index); // 12
    index += assignLength(outAgreeKeyEncTag.length, wrappedData, index); // 4
    index += assignData(outAgreeKeyEncTag, wrappedData, index); // 16
    index += assignLength(outKekEncData.length, wrappedData, index); // 4
    index += assignData(outKekEncData, wrappedData, index); // 32
    index += assignLength(AADUint8Array.length, wrappedData, index); // 4
    index += assignData(AADUint8Array, wrappedData, index); // 16
    index += assignLength(NonceArray.length, wrappedData, index); // 4
    index += assignData(NonceArray, wrappedData, index); // 12
    index += assignLength(outKekEncTag.length, wrappedData, index); // 4
    index += assignData(outKekEncTag, wrappedData, index); // 16
    index += assignLength(plainKeySizeBuff.length, wrappedData, index); // 4
    index += assignData(plainKeySizeBuff, wrappedData, index); // 4
    index += assignLength(outPlainKeyEncData.length, wrappedData, index); // 4
    index += assignData(outPlainKeyEncData, wrappedData, index); // 24

    return wrappedData;
}

async function ImportWrappedKey() {
    const srcKeyAliesWrap = 'HUKS_Basic_Capability_Import_0200';
    /*
     * 生成、导出加密导入用途的、用于协商的密钥密钥Caller_Key和Wrapping_Key
     */
    await generateAndExportPublicKey(srcKeyAliesWrap, genWrappingKeyParams, false);
    await generateAndExportPublicKey(callerKeyAlias, genCallerEcdhParams, true);

    /**
     * 生成一个对称密钥Caller_Kek
     * 使用Caller_Key和Wrapping_Key的公钥，协商出Agree_Key
     */
    await ImportKekAndAgreeSharedSecret(callerKekAliasAes256, importParamsCallerKek, callerKeyAlias, huksPubKey, callerAgreeParams);

    /**
     * 使用Caller_Kek加密待导入密钥
     * 使用Agree_Key加密Caller_Kek
     */
    await EncryptImportedPlainKeyAndKek(importedAes192PlainKey);

    /**
     * 封装加密导入的材料
     */
    let wrappedData = await BuildWrappedDataAndImportWrappedKey(importedAes192PlainKey);
    importWrappedAes192Params.inData = wrappedData;

    /**
     * 导入封装的加密密钥材料
     */
    await publicImportWrappedKeyFunc(importedKeyAliasAes192, srcKeyAliesWrap, importWrappedAes192Params);

    /**
     * 删除用于加密导入的密钥
     */
    await publicDeleteKeyItemFunc(srcKeyAliesWrap, genWrappingKeyParams);
    await publicDeleteKeyItemFunc(callerKeyAlias, genCallerEcdhParams);
    await publicDeleteKeyItemFunc(importedKeyAliasAes192, importWrappedAes192Params);
    await publicDeleteKeyItemFunc(callerKekAliasAes256, callerAgreeParams);
}
```

**调测验证**

验证时查询密钥是否存在，如密钥存在即表示生成密钥成功。

**代码示例：**

```ts
import huks from '@ohos.security.huks';

/*
 * 确定密钥别名和封装密钥属性参数集
 */
let keyAlias = 'test_import_key_ecdh_aes192';
let isKeyExist:Boolean;

let keyProperties: Array<huks.HuksParam> = new Array();
keyProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
}
let huksOptions:huks.HuksOptions = {
    properties: keyProperties, // 非空填充
    inData: new Uint8Array(new Array()) // 非空填充
}
try {
    huks.isKeyItemExist(keyAlias, huksOptions, (error, data)=> {
        if (error) {
            console.error(`callback: isKeyItemExist failed`);
        } else {
            if (data !== null && data.valueOf() !== null) {
                isKeyExist = data.valueOf();
                console.info(`callback: isKeyItemExist success, isKeyExist = ${isKeyExist}`);
            }
        }
    });
} catch (error) {
    console.error(`callback: isKeyItemExist input arg invalid`);
}
```

## 常见密钥操作

**场景概述**

为了实现对数据机密性、完整性等保护，在生成/导入密钥后，需要对数据进行密钥操作，比如加密解密、签名验签、密钥协商、密钥派生等，本章节提供了常用的密钥操作的示例。本章节提供的示例都没有设置二次身份访问控制，如设置了密钥访问控制请参考[密钥访问控制](#密钥访问控制)用法。

**通用开发流程**

HUKS基于密钥会话来操作数据，使用密钥时基于以下流程：

1. **初始化密钥会话[huks.initSession()](../reference/apis/js-apis-huks.md#huksinitsession9)：** 传入密钥别名和密钥操作参数，初始化一个密钥会话并获取会话句柄。其中密钥操作参数中必须包含对应密码算法所必须的参数，包括密码算法、密钥大小、密钥目的、工作模式、填充模式、散列模式、IV、Nonce、AAD等。如果密钥设置了访问控制属性，还需要其他参数具体[密钥访问控制](#密钥访问控制)。此步骤必选！
2. **分段操作数据[huks.updateSession()](../reference/apis/js-apis-huks.md#huksupdatesession9)：** 如数据过大（超过100K）或密码算法的要求需要对数据进行分段操作，反之可跳过此步。此步骤可选！
3. **结束密钥会话[huks.finishSession()](../reference/apis/js-apis-huks.md#huksfinishsession9)：** 操作最后一段数据并结束密钥会话，如过程中发生错误或不需要此次密钥操作数据，必须取消会话[huks.abortSession()](../reference/apis/js-apis-huks.md#huksabortsession9)。此步骤必选！

### 加密解密

```ts
/*
 * 以下以AES 128密钥的Callback操作使用为例
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
    let genProperties = GetAesGenerateProperties();
    let options: huks.HuksOptions = {
        properties: genProperties
    }
    await huks.generateKeyItem(aesKeyAlias, options)
    .then((data) => {
        console.info(`callback: generate AES Key success, data = ${JSON.stringify(data)}`);
    }).catch((error: BusinessError)=>{
        console.error(`callback: generate AES Key failed`);
    })
}


async function EncryptData() {
    let encryptProperties = GetAesEncryptProperties();
    let options: huks.HuksOptions = {
        properties: encryptProperties,
        inData: StringToUint8Array(plainText)
    }
    await huks.initSession(aesKeyAlias, options)
    .then((data) => {
        handle = data.handle;
    }).catch((error: BusinessError)=>{
        console.error(`callback: init encryptdata failed`);
    })
    await huks.finishSession(handle, options)
    .then((data) => {
        console.info(`callback: encrypt data success, data is `+ Uint8ArrayToString(data.outData as Uint8Array));
        cipherData = data.outData as Uint8Array;
    }).catch((error: BusinessError)=>{
        console.error(`callback: encrypt data failed`);
    })
}

async function DecryptData() {
    let decryptOptions = GetAesDecryptProperties()
    let options: huks.HuksOptions = {
        properties: decryptOptions,
        inData: cipherData
    }
    await huks.initSession(aesKeyAlias, options)
    .then((data) => {
        handle = data.handle;
    }).catch((error: BusinessError)=>{
        console.error(`callback: init decryptdata failed`);
    })
    await huks.finishSession(handle, options)
    .then((data) => {
        console.info(`callback: decrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((error: BusinessError)=>{
        console.error(`callback: decrypt data failed`);
    })
}

async function DeleteKey() {
    let emptyOptions: huks.HuksOptions = {
        properties: []
    }
    await huks.deleteKeyItem(aesKeyAlias, emptyOptions)
    .then((data) => {
        console.info(`callback: delete data success`);
    }).catch((error: BusinessError)=>{
        console.error(`callback: delete data failed`);
    })
}
```

### 密钥协商

应用在协商密钥时建议传入[HuksKeyStorageType](../reference/apis/js-apis-huks.md#hukskeystoragetype)中定义的类型；从API10开始应用只能选择存储(HUKS_STORAGE_ONLY_USED_IN_HUKS)，或者选择导出(HUKS_STORAGE_KEY_EXPORT_ALLOWED)，若不传入，则默认同时支持存储和导出，存在安全问题，不推荐业务使用。

```ts
/*
 * 以下以X25519 256 TEMP密钥的Callback操作使用为例
 */
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';

/*
 * 确定密钥别名和封装密钥属性参数集
 */
let srcKeyAliasFirst = "AgreeX25519KeyFirstAlias";
let srcKeyAliasSecond = "AgreeX25519KeySecondAlias";
let agreeX25519InData = 'AgreeX25519TestIndata';
let finishOutData : Uint8Array;
let handle: number;
let exportKey : Uint8Array;
let exportKeyFrist: Uint8Array;
let exportKeySecond : Uint8Array;

/* 集成生成密钥参数集 */
let properties : Array<huks.HuksParam> = new Array();
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_X25519,
}
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE,
}
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256,
}
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
}
properties[4] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}
properties[5] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC,
}
properties[6] = {
    tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
}
let HuksOptions : huks.HuksOptions = {
    properties: properties,
    inData: new Uint8Array(new Array())
}

/* 集成第一个协商参数集 */
let finishProperties : Array<huks.HuksParam> = new Array();
finishProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
}
finishProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS,
    value: true
}
finishProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
}
finishProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
}
finishProperties[4] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
}
finishProperties[5] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
}
finishProperties[6] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
    value: StringToUint8Array(srcKeyAliasFirst+ 'final'),
}
finishProperties[7] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}
finishProperties[8] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB,
}
let finishOptionsFrist : huks.HuksOptions = {
    properties: finishProperties,
    inData: StringToUint8Array(agreeX25519InData)
}
/* 集成第二个协商参数集 */
let finishOptionsSecond : huks.HuksOptions = {
    properties: finishProperties,
    inData: StringToUint8Array(agreeX25519InData)
}
finishOptionsSecond.properties!.splice(6, 1, {
    tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
    value: StringToUint8Array(srcKeyAliasSecond + 'final'),
})

function StringToUint8Array(str:string) {
    let arr: number[] = new Array();
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
return new Uint8Array(arr);
}
class throwObject {
    isThrow: boolean = false
}
function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<void>((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, (error, data) => {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    let throwObject :throwObject = {isThrow: false};
    try {
        await generateKeyItem(keyAlias, huksOptions, throwObject)
        .then((data) => {
            console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
        })
        .catch((error : BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: generateKeyItem failed`);
            }
        });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid`);
    }
}

function initSession(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<huks.HuksSessionHandle>((resolve, reject) => {
        try {
            huks.initSession(keyAlias, huksOptions, (error, data) => {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicInitFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doInit`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await initSession(keyAlias, huksOptions, throwObject)
        .then ((data) => {
            console.info(`callback: doInit success, data = ${JSON.stringify(data)}`);
            handle = data.handle;
        })
        .catch((error : BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: doInit failed`);
            }
        });
    } catch (error) {
        console.error(`callback: doInit input arg invalid`);
    }
}

function updateSession(handle:number, huksOptions:huks.HuksOptions, throwObject:throwObject)  {
    return new Promise<huks.HuksReturnResult>((resolve, reject) => {
        try {
            huks.updateSession(handle, huksOptions, (error, data) => {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicUpdateFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doUpdate`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await updateSession(handle, huksOptions, throwObject)
        .then ((data) => {
            console.info(`callback: doUpdate success, data = ${JSON.stringify(data)}`);
        })
        .catch((error : BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: doUpdate failed`);
            }
        });
    } catch (error) {
        console.error(`callback: doUpdate input arg invalid`);
    }
}

function finishSession(handle:number, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<huks.HuksReturnResult>((resolve, reject) => {
        try {
            huks.finishSession(handle, huksOptions, (error, data) =>{
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicFinishFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doFinish`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await finishSession(handle, huksOptions, throwObject)
        .then ((data) => {
            finishOutData = data.outData as Uint8Array;
            console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
        })
        .catch((error : BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: doFinish failed`);
            }
        });
    } catch (error) {
        console.error(`callback: doFinish input arg invalid`);
    }
}

function exportKeyItem(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<huks.HuksReturnResult>((resolve, reject) => {
        try {
            huks.exportKeyItem(keyAlias, huksOptions, (error, data) => {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicExportKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback export`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await exportKeyItem(keyAlias, huksOptions, throwObject)
        .then ((data) => {
            console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);
            exportKey = data.outData as Uint8Array;
        })
        .catch((error : BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: exportKeyItem failed`);
            }
        });
    } catch (error) {
        console.error(`callback: exportKeyItem input arg invalid`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<void>((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, (error, data) => {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    let throwObject : throwObject = {isThrow: false};
    try {
        await deleteKeyItem(keyAlias, huksOptions, throwObject)
        .then ((data) => {
           console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
        })
        .catch((error :BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: deleteKeyItem failed`);
            }
        });
    } catch (error) {
        console.error(`callback: deletKeeyItem input arg invalid`);
    }
}

async function testAgree() {
    /* 1.生成两个密钥并导出 */
    await publicGenKeyFunc(srcKeyAliasFirst, HuksOptions);
    await publicGenKeyFunc(srcKeyAliasSecond, HuksOptions);

    await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
    exportKeyFrist = exportKey;
    await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
    exportKeySecond = exportKey;

    /* 对第一个密钥进行协商 */
    await publicInitFunc(srcKeyAliasFirst, HuksOptions);
    HuksOptions.inData = exportKeySecond;
    await publicUpdateFunc(handle, HuksOptions);
    await publicFinishFunc(handle, finishOptionsFrist);

    /* 对第二个密钥进行协商 */
    await publicInitFunc(srcKeyAliasSecond, HuksOptions);
    HuksOptions.inData = exportKeyFrist;
    await publicUpdateFunc(handle, HuksOptions);
    await publicFinishFunc(handle, finishOptionsSecond);

    await publicDeleteKeyFunc(srcKeyAliasFirst, HuksOptions);
    await publicDeleteKeyFunc(srcKeyAliasSecond, HuksOptions);
}
```

### 密钥派生

应用在派生密钥时建议传入[HuksKeyStorageType](../reference/apis/js-apis-huks.md#hukskeystoragetype)中定义的类型；从API10开始应用只能选择存储(HUKS_STORAGE_ONLY_USED_IN_HUKS)，或者选择导出(HUKS_STORAGE_KEY_EXPORT_ALLOWED)，若不传入，则默认同时支持存储和导出，存在安全问题，不推荐业务使用。

```ts
/*
 * 以下以HKDF256密钥的Promise操作使用为例
 */
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';

/*
 * 确定密钥别名和封装密钥属性参数集
 */
let srcKeyAlias = "hkdf_Key";
let deriveHkdfInData = "deriveHkdfTestIndata";
let handle:number;
let finishOutData:Uint8Array;
let HuksKeyDeriveKeySize = 32;

/* 集成生成密钥参数集 */
let properties:Array<huks.HuksParam> = new Array();
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
}
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DERIVE,
}
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
}
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
}
properties[4] = {
    tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
}
let huksOptions:huks.HuksOptions = {
    properties: properties,
    inData: new Uint8Array(new Array())
}

/* 集成init时密钥参数集 */
let initProperties:Array<huks.HuksParam> = new Array();
initProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_HKDF,
}
initProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DERIVE,
}
initProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
}
initProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DERIVE_KEY_SIZE,
    value: HuksKeyDeriveKeySize,
}
let initOptions:huks.HuksOptions = {
    properties: initProperties,
    inData: new Uint8Array(new Array())
}

/* 集成finish时密钥参数集 */
let finishProperties:Array<huks.HuksParam> = new Array();
finishProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
}
finishProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS,
    value: true,
}
finishProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
}
finishProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
}
finishProperties[4] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
}
finishProperties[5] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
}
finishProperties[6] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
    value: StringToUint8Array(srcKeyAlias),
}
finishProperties[7] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}
finishProperties[8] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB,
}
let finishOptions:huks.HuksOptions = {
    properties: finishProperties,
    inData: new Uint8Array(new Array())
}

function StringToUint8Array(str:String) {
    let arr:number[]=new Array();
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

class throwObject{
    isThrow=false;
}

function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<void>((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, (error, data)=> {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await generateKeyItem(keyAlias, huksOptions, throwObject)
        .then((data) => {
            console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
        })
        .catch((error:BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: generateKeyItem failed`);
            }
        });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid`);
    }
}

function initSession(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<huks.HuksSessionHandle>((resolve, reject) => {
        try {
            huks.initSession(keyAlias, huksOptions, (error, data)=> {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicInitFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doInit`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await initSession(keyAlias, huksOptions, throwObject)
        .then ((data) => {
            console.info(`callback: doInit success, data = ${JSON.stringify(data)}`);
            handle = data.handle;
        })
        .catch((error:BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: doInit failed`);
            }
        });
    } catch (error) {
        console.error(`callback: doInit input arg invalid`);
    }
}

function updateSession(handle:number, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<huks.HuksOptions>((resolve, reject) => {
        try {
            huks.updateSession(handle, huksOptions, (error, data)=> {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicUpdateFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doUpdate`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await updateSession(handle, huksOptions, throwObject)
        .then ((data) => {
            console.info(`callback: doUpdate success, data = ${JSON.stringify(data)}`);
        })
        .catch((error:BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: doUpdate failed`);
            }
        });
    } catch (error) {
        console.error(`callback: doUpdate input arg invalid`);
    }
}

function finishSession(handle:number, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<huks.HuksReturnResult>((resolve, reject) => {
        try {
            huks.finishSession(handle, huksOptions, (error, data)=> {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicFinishFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doFinish`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await finishSession(handle, huksOptions, throwObject)
        .then ((data) => {
            finishOutData = data.outData as Uint8Array;
            console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
        })
        .catch((error:BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: doFinish failed`);
            }
        });
    } catch (error) {
        console.error(`callback: doFinish input arg invalid`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
    return new Promise<void>((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, (error, data)=> {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    let throwObject:throwObject = {isThrow: false};
    try {
        await deleteKeyItem(keyAlias, huksOptions, throwObject)
        .then ((data) => {
            console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
        })
        .catch((error:BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: deleteKeyItem failed`);
            }
        });
    } catch (error) {
        console.error(`callback: deletKeeyItem input arg invalid`);
    }
}

async function testDerive() {
    /* 生成密钥 */
    await publicGenKeyFunc(srcKeyAlias, huksOptions);

    /* 进行派生操作 */
    await publicInitFunc(srcKeyAlias, initOptions);

    initOptions.inData = StringToUint8Array(deriveHkdfInData);
    await publicUpdateFunc(handle, initOptions);
    await publicFinishFunc(handle, finishOptions);

    await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
}
```

## 密钥访问控制

HUKS提供了全面完善的密钥访问控制能力，确保存储在HUKS中的密钥被合法正确的访问。

首先，业务只能访问属于自己的密钥，即只能访问通过HUKS生成或导入的密钥。
其次，支持密钥的用户身份认证访问控制，对于高安敏感的业务密钥，需要在使用密钥的时候，再次要求用户即时的验证锁屏密码或生物特征，验证通过后，才能使用业务密钥。
除此之外，HUKS还支持严格限制密钥的使用用途，如支持只允许AES密钥进行加密解密，只允许RSA密钥进行签名验签。

### 用户身份认证访问控制

生成或导入密钥时，可以指定密钥必须经过用户身份认证后才能使用。您可以指定用于解锁设备锁屏的凭据（锁屏密码、指纹、人脸）的子集进行身份认证。在生成/导入密钥后，即使应用进程被攻击也不会导致未经用户授权的密钥访问，一般用于高敏感且高级别安全保护的场景，比如免密登录、免密支付、自动填充密码保护场景。

除用户身份认证外，应用还须将密钥的授权访问类型（即失效条件）设置为以下两种类型之一：

- **清除锁屏密码后密钥永久无效。** 设置此模式的前提是当前用户已经设置了锁屏密码，在生成/导入密钥后，一旦清除了锁屏密码，此类密钥将永久失效。注意，修改密码不会导致失效情况发生。此模式适合那些需要锁屏密码授权访问或用户强相关的数据保护的场景。
- **用户新录入生物特征后永久无效。** 此模式需要当前用户至少录入了一个生物特征（如指纹）才能生效，在生成/导入密钥后，一旦录入新的生物特征，这些密钥将永久失效。注意，仅删除生物特征不会导致失效情况发生。如果您不希望新录入的生物特征后，用户还可以授权访问原有数据（密钥保护的数据），那么可以使用此模式，如免密登录，免密支付等场景。

此外，为了保证密钥使用时用户认证结果的有效性（不可重放），HUKS支持挑战值校验：在身份认证前，需要从HUKS获取挑战值（调用[huks.initSession()](../reference/apis/js-apis-huks.md#huksinitsession9)返回的[HuksSessionHandle](../reference/apis/js-apis-huks.md#hukssessionhandle9)中）传给用户身份认证方法（userIAM_userAuth.getAuthInstance），然后在密钥操作时校验认证令牌的挑战值。

**开发流程**

设置了二次用户身份认证的密钥，需要先初始化密钥会话并获取挑战值，然后将HUKS生成的挑战值传至用户身份认证方法进行用户身份认证，认证通过后获取一个认证令牌，将认证令牌传至HUKS进行密钥操作。

![huks_key_user_auth_work_flow](./figures/huks_key_user_auth_work_flow.png)

**接口说明**

1. 生成或导入密钥时，在密钥属性集中需指定三个参数：用户认证类型[HuksUserAuthType](../reference/apis/js-apis-huks.md#huksuserauthtype9)、授权访问类型[HuksAuthAccessType](../reference/apis/js-apis-huks.md#huksauthaccesstype9)、挑战值类型[HuksChallengeType](../reference/apis/js-apis-huks.md#hukschallengetype9)。

   **表3** 用户认证类型：三种类型的子集
   | 名称            | 值  | 说明                      |
   | ------------------------------- |---|------------------------ |
   | HUKS_USER_AUTH_TYPE_FINGERPRINT |0x0001  | 用户认证类型为指纹，允许和人脸、锁屏密码同时设置  |
   | HUKS_USER_AUTH_TYPE_FACE     |0x0002   | 用户认证类型为人脸 ，允许和指纹、锁屏密码同时设置 |
   | HUKS_USER_AUTH_TYPE_PIN      |0x0004  | 用户认证类型为锁屏密码，允许和人脸、指纹同时设置 |

   **表4** 安全访问类型：二选一
   | 名称                                    | 值   | 说明             |
   | --------------------------------------- | ---- | ------------------------------------------------ |
   | HUKS_AUTH_ACCESS_INVALID_CLEAR_PASSWORD | 1    | 清除锁屏密码后密钥无法访问。       |
   | HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL | 2    | 新录入生物特征后密钥无法访问，用户认证类型须包含生物认证类型。 |

   **表5** 挑战值类型：三选一
   | 名称                            | 值   | 说明                        |
   | ------------------------------- | ---- | ------------------------------ |
   | HUKS_CHALLENGE_TYPE_NORMAL | 0    | 普通类型，每次密钥的使用需要独立的一次用户认证 |
   | HUKS_CHALLENGE_TYPE_CUSTOM        | 1    | 自定义类型，支持和多个密钥共享一次用户认证|
   | HUKS_CHALLENGE_TYPE_NONE         | 2    | 无挑战值类型，用户认证时不需要挑战值 |

   > **注意**
   >
   > 当指定挑战值类型为**HUKS_CHALLENGE_TYPE_NONE** 时，不需要传递挑战值，但是存在新的限制：在用户身份认证后，一段时间内允许访问该密钥，超时后不能访问，需要重新认证才能访问。因此应用需要额外指定超时时间**HUKS_TAG_AUTH_TIMEOUT**属性（最大60秒）。

2. 使用密钥时，先初始化密钥会话，然后根据密钥生成/导入阶段指定的挑战值类型属性是否需要获取挑战值，或组装新的挑战值。

   **表6** 使用密钥的接口介绍
   | 接口名                      | 描述                 |
   | -------------------------------------- | ----------------------------|
   |initSession(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksSessionHandle>) : void| 初始化密钥会话，获取挑战值|
   |updateSession(handle: number, options: HuksOptions, token: Uint8Array, callback: AsyncCallback\<HuksReturnResult>) : void| 分段操作数据，传递认证令牌|
   |finishSession(handle: number, options: HuksOptions, token: Uint8Array, callback: AsyncCallback\<HuksReturnResult>) : void| 结束密钥会话，传递认证令牌|

**开发步骤**

1. 生成密钥并指定指纹访问控制和相关属性

   ```ts
   import huks from '@ohos.security.huks';
   import { BusinessError } from '@ohos.base';

   /*
    * 确定密钥别名和封装密钥属性参数集
    */
   let keyAlias = 'dh_key_fingerprint_access';
   let properties : Array<huks.HuksParam> = new Array();
   properties[0] = {
       tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
       value: huks.HuksKeyAlg.HUKS_ALG_SM4,
   }
   properties[1] = {
       tag: huks.HuksTag.HUKS_TAG_PURPOSE,
       value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
   }
   properties[2] = {
       tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
       value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
   }
   properties[3] = {
       tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
       value: huks.HuksCipherMode.HUKS_MODE_CBC,
   }
   properties[4] = {
       tag: huks.HuksTag.HUKS_TAG_PADDING,
       value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
   }
   // 指定密钥身份认证的类型：指纹
   properties[5] = {
       tag: huks.HuksTag.HUKS_TAG_USER_AUTH_TYPE,
       value: huks.HuksUserAuthType.HUKS_USER_AUTH_TYPE_FINGERPRINT
   }
   // 指定密钥安全授权的类型（失效类型）：新录入生物特征（指纹）后无效
   properties[6] = {
       tag: huks.HuksTag.HUKS_TAG_KEY_AUTH_ACCESS_TYPE,
       value: huks.HuksAuthAccessType.HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL
   }
   // 指定挑战值的类型：默认类型
   properties[7] = {
       tag: huks.HuksTag.HUKS_TAG_CHALLENGE_TYPE,
       value: huks.HuksChallengeType.HUKS_CHALLENGE_TYPE_NORMAL
   }
   let huksOptions : huks.HuksOptions = {
       properties: properties,
       inData: new Uint8Array(new Array())
   }

   /*
    * 生成密钥
    */
   class throwObject {
       isThrow:boolean = false
   }
   function generateKeyItem(keyAlias : string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
       return new Promise<void>((resolve, reject) => {
           try {
               huks.generateKeyItem(keyAlias, huksOptions, (error, data) => {
                   if (error) {
                       reject(error);
                   } else {
                       resolve(data);
                   }
               });
           } catch (error) {
               throwObject.isThrow = true;
               throw(error as Error);
           }
       });
   }

   async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
       console.info(`enter callback generateKeyItem`);
       let throwObject : throwObject = {isThrow: false};
       try {
           await generateKeyItem(keyAlias, huksOptions, throwObject)
           .then((data) => {
               console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
           })
           .catch((error : BusinessError) => {
               if (throwObject.isThrow) {
                   throw(error as Error);
               } else {
                   console.error(`callback: generateKeyItem failed`);
               }
           });
       } catch (error) {
           console.error(`callback: generateKeyItem input arg invalid`);
       }
   }

   async function TestGenKeyForFingerprintAccessControl() {
       await publicGenKeyFunc(keyAlias, huksOptions);
   }
   ```

2. 初始化密钥会话获取挑战值并发起指纹认证获取认证令牌

   ```ts
   import huks from '@ohos.security.huks';
   import userIAM_userAuth from '@ohos.userIAM.userAuth';
   import { BusinessError } from '@ohos.base';

   /*
    * 确定密钥别名和封装密钥属性参数集
    */
   let srcKeyAlias = 'sm4_key_fingerprint_access';
   let handle : number;
   let challenge : Uint8Array;
   let fingerAuthToken : Uint8Array;
   let authType = userIAM_userAuth.UserAuthType.FINGERPRINT;
   let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

   /* 集成生成密钥参数集 & 加密参数集 */
   let properties : Array<huks.HuksParam> = new Array();
   properties[0] = {
       tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
       value: huks.HuksKeyAlg.HUKS_ALG_SM4,
   }
   properties[1] = {
       tag: huks.HuksTag.HUKS_TAG_PURPOSE,
       value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
   }
   properties[2] = {
       tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
       value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
   }
   properties[3] = {
       tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
       value: huks.HuksCipherMode.HUKS_MODE_CBC,
   }
   properties[4] = {
       tag: huks.HuksTag.HUKS_TAG_PADDING,
       value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
   }
   let huksOptions : huks.HuksOptions = {
       properties: properties,
       inData: new Uint8Array(new Array())
   }

   class throwObject {
       isThrow:boolean=false
   }

   function initSession(keyAlias:string, huksOptions:huks.HuksOptions, throwObject:throwObject) {
       return new Promise<huks.HuksSessionHandle>((resolve, reject) => {
           try {
               huks.initSession(keyAlias, huksOptions, (error, data) =>{
                   if (error) {
                       reject(error);
                   } else {
                       resolve(data);
                   }
               });
           } catch (error) {
               throwObject.isThrow = true;
               throw(error as Error);
           }
       });
   }

   async function publicInitFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
       console.info(`enter callback doInit`);
       let throwObject : throwObject = {isThrow: false};
       try {
           await initSession(keyAlias, huksOptions, throwObject)
           .then ((data) => {
               console.info(`callback: doInit success, data = ${JSON.stringify(data)}`);
               handle = data.handle;
               challenge = data.challenge as Uint8Array;
           })
           .catch((error : BusinessError) => {
               if (throwObject.isThrow) {
                   throw(error as Error);
               } else {
                   console.error(`callback: doInit failed`);
               }
           });
       } catch (error) {
           console.error(`callback: doInit input arg invalid`);
       }
   }

   function userIAMAuthFinger(huksChallenge:Uint8Array) {
       // 获取认证对象
       let auth : userIAM_userAuth.AuthInstance;
       try {
           auth = userIAM_userAuth.getAuthInstance(huksChallenge, authType, authTrustLevel);
           console.log("get auth instance success");
       } catch (error) {
           console.log("get auth instance failed" + error);
           return;
       }

       // 订阅认证结果
       try {
           auth.on("result", {
               callback: (result:userIAM_userAuth.AuthResultInfo) => {
               /* 认证成功获取认证令牌 */
               fingerAuthToken = result.token as Uint8Array;
           }
       });
           console.log("subscribe authentication event success");
       } catch (error) {
           console.log("subscribe authentication event failed " + error);
       }

       // 开始认证
       try {
           auth.start();
           console.info("authV9 start auth success");
       } catch (error) {
           console.info("authV9 start auth failed, error = " + error);
       }
   }

   async function testInitAndAuthFinger() {
       /* 初始化密钥会话获取挑战值 */
       await publicInitFunc(srcKeyAlias, huksOptions);
       /* 调用userIAM进行身份认证 */
       userIAMAuthFinger(challenge);
   }
   ```

3. 传入认证令牌进行数据操作

   ```ts
   /*
   * 以下以SM4 128密钥的Callback操作使用为例
   */
   import huks from '@ohos.security.huks';
   import { BusinessError } from '@ohos.base';
   
   /*
   * 确定密钥别名和封装密钥属性参数集
   */
   let srcKeyAlias = 'sm4_key_fingerprint_access';
   let IV = '1234567890123456';
   let cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string';
   let handle: number;
   let fingerAuthToken: Uint8Array;
   let finishOutData: Uint8Array;
   
   class throwObject {
       isThrow: boolean = false;
   }
   
   /* 集成生成密钥参数集 & 加密参数集 */
   class propertyEncryptType {
       tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
       value: huks.HuksKeyAlg | huks.HuksKeyPurpose | huks.HuksKeySize | huks.HuksKeyPadding | huks.HuksCipherMode
           | Uint8Array = huks.HuksKeyAlg.HUKS_ALG_SM4;
   }
   
   let propertiesEncrypt: propertyEncryptType[] = [
       {
           tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
           value: huks.HuksKeyAlg.HUKS_ALG_SM4,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_PURPOSE,
           value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
           value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_PADDING,
           value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
           value: huks.HuksCipherMode.HUKS_MODE_CBC,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_IV,
           value: StringToUint8Array(IV),
       }
   ]
   
   let encryptOptions: huks.HuksOptions = {
       properties: propertiesEncrypt,
       inData: new Uint8Array(new Array())
   }
   
   function StringToUint8Array(str: string) {
       let arr: number[] = [];
       for (let i = 0, j = str.length; i < j; ++i) {
           arr.push(str.charCodeAt(i));
       }
       return new Uint8Array(arr);
   }
   
   function updateSession(handle: number, huksOptions: huks.HuksOptions, token: Uint8Array, throwObject: throwObject) {
       return new Promise<huks.HuksReturnResult>((resolve, reject) => {
           try {
               huks.updateSession(handle, huksOptions, token, (error, data) => {
                   if (error) {
                       reject(error);
                   } else {
                       resolve(data);
                   }
               });
           } catch (error) {
               throwObject.isThrow = true;
               throw(error as Error);
           }
       });
   }
   
   async function publicUpdateFunc(handle: number, token: Uint8Array, huksOptions: huks.HuksOptions) {
       console.info(`enter callback doUpdate`);
       let throwObject: throwObject = {isThrow: false};
       try {
           await updateSession(handle, huksOptions, token, throwObject)
           .then ((data) => {
               console.info(`callback: doUpdate success, data = ${JSON.stringify(data)}`);
           })
           .catch((error: BusinessError) => {
               if (throwObject.isThrow) {
                   throw(error as Error);
               } else {
                   console.error(`callback: doUpdate failed`);
               }
           });
       } catch (error) {
           console.error(`callback: doUpdate input arg invalid`);
       }
   }
   
   function finishSession(handle: number, huksOptions: huks.HuksOptions, token: Uint8Array, throwObject: throwObject) {
       return new Promise<huks.HuksReturnResult>((resolve, reject) => {
           try {
               huks.finishSession(handle, huksOptions, token, (error, data) => {
                   if (error) {
                       reject(error);
                   } else {
                       resolve(data);
                   }
               });
           } catch (error) {
               throwObject.isThrow = true;
               throw(error as Error);
           }
       });
   }
   
   async function publicFinishFunc(handle: number, token: Uint8Array, huksOptions: huks.HuksOptions) {
       console.info(`enter callback doFinish`);
       let throwObject: throwObject = {isThrow: false};
       try {
           await finishSession(handle, huksOptions, token, throwObject)
           .then ((data) => {
               finishOutData = data.outData as Uint8Array;
               console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
           })
           .catch((error: BusinessError) => {
               if (throwObject.isThrow) {
                   throw(error as Error);
               } else {
                   console.error(`callback: doFinish failed`);
               }
           });
       } catch (error) {
           console.error(`callback: doFinish input arg invalid`);
       }
   }
   
   async function testSm4Cipher() {
       encryptOptions.inData = StringToUint8Array(cipherInData);
       /* 传入认证令牌 */
       await publicUpdateFunc(handle, fingerAuthToken, encryptOptions);
       encryptOptions.inData = new Uint8Array(new Array());
       /* 传入认证令牌 */
       await publicFinishFunc(handle, fingerAuthToken, encryptOptions);
       if (finishOutData === StringToUint8Array(cipherInData)) {
           console.info('test finish encrypt err ');
       } else {
           console.info('test finish encrypt success');
       }
   }
   ```

### 细粒度用户身份认证访问控制

该功能是基于已有[密钥访问控制](#密钥访问控制)能力的扩展，提供了基于生物特征和锁屏密码二次身份认证的细粒度访问控制能力，允许设置密钥在加密、解密、签名、验签、密钥协商、密钥派生的单个或多个场景时是否需要进行身份验证。比如，业务需要使用HUKS密钥加密保存帐号密码信息等数据，要求在加密的时候不进行指纹等身份认证，解密的时候需要进行指纹等身份认证，这是就需要依赖HUKS提供细粒度的二次身份认证访问控制机制。

**开发流程**

1. 基于用户身份认证访问控制的流程，在密钥生成阶段，通过额外指定用于细粒度用户身份认证访问控制的HuksTag：[HUKS_TAG_KEY_AUTH_PURPOSE](../reference/apis/js-apis-huks.md#hukstag)值，来指定在某种算法用途的情况下需要使用用户身份认证访问控制能力。
2. 基于用户身份认证访问控制的流程，在密钥使用阶段，业务无需再次指定HUKS_TAG_KEY_AUTH_PURPOSE值，同用户身份认证访问控制的开发流程。

**接口说明**

新增用于细粒度用户身份认证访问控制的HuksTag：[HUKS_TAG_KEY_AUTH_PURPOSE](../reference/apis/js-apis-huks.md#hukstag)，该Tag值取值范围为枚举类[HuksKeyAlg](../reference/apis/js-apis-huks.md#hukskeyalg)。

**表7** 细粒度用户身份认证访问控制Tag类型介绍
| 名称                      | 描述                 |
| -------------------------------------- | ----------------------------|
|HUKS_TAG_KEY_AUTH_PURPOSE| 表示密钥认证用途的tag，用于设置某种算法用途下需要用户身份认证访问控制|

**注意**

1. 当业务未指定用户认证类型[HuksUserAuthType](../reference/apis/js-apis-huks.md#huksuserauthtype9)时表示默认都不需要用户身份认证访问控制能力，则此时设置HUKS_TAG_KEY_AUTH_PURPOSE是默认无效的; 当业务指定了[HuksUserAuthType](../reference/apis/js-apis-huks.md#huksuserauthtype9)时表示需要用户身份认证访问控制能力，此时若不设置HUKS_TAG_KEY_AUTH_PURPOSE值，则生成密钥阶段指定的算法用途在密钥使用时都默认需要进行用户身份认证访问控制。
2. 当指定的算法是对称算法AES和SM4时，且同时指定用于加解密用途，则只允许设置CBC模式，其它模式不支持细粒度用户身份认证访问控制能力。

**开发步骤**

示例场景：密钥生成阶段，生成用于加解密的密钥并指定只有解密的时候需要用户身份认证访问控制；密钥使用阶段，加密时不需要用户身份认证访问控制，解密时需要用户身份认证访问控制

1. 生成密钥并指定指纹访问控制和相关属性，以及HUKS_TAG_KEY_AUTH_PURPOSE值

   ```ts
   import huks from '@ohos.security.huks';
   import { BusinessError } from '@ohos.base';

   /*
    * 确定密钥别名和封装密钥属性参数集
    */
   let keyAlias = 'dh_key_fingerprint_access';

   class throwObject {
       isThrow: boolean = false;
   }

   class propertyType {
       tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
       value: huks.HuksKeyAlg | huks.HuksKeyPurpose | huks.HuksKeySize | huks.HuksCipherMode | huks.HuksKeyPadding
           | huks.HuksUserAuthType | huks.HuksAuthAccessType | huks.HuksChallengeType = huks.HuksKeyAlg.HUKS_ALG_SM4
   }
   let properties: propertyType[] = [
       {
           tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
           value: huks.HuksKeyAlg.HUKS_ALG_SM4,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_PURPOSE,
           value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
           value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
           value: huks.HuksCipherMode.HUKS_MODE_CBC,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_PADDING,
           value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_USER_AUTH_TYPE,
           value: huks.HuksUserAuthType.HUKS_USER_AUTH_TYPE_FINGERPRINT
       },
       {
           tag: huks.HuksTag.HUKS_TAG_KEY_AUTH_ACCESS_TYPE,
           value: huks.HuksAuthAccessType.HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL
       },
       {
           tag: huks.HuksTag.HUKS_TAG_CHALLENGE_TYPE,
           value: huks.HuksChallengeType.HUKS_CHALLENGE_TYPE_NORMAL
       },
       {
           tag: huks.HuksTag.HUKS_TAG_KEY_AUTH_PURPOSE,
           value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
       }
   ]

   let huksOptions: huks.HuksOptions = {
       properties: properties,
       inData: new Uint8Array(new Array())
   }

   /*
    * 生成密钥
    */
   async function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
       return new Promise<void>((resolve, reject) => {
           try {
               huks.generateKeyItem(keyAlias, huksOptions, (error, data) => {
                   if (error) {
                       reject(error);
                   } else {
                       resolve(data);
                   }
               });
           } catch (error) {
               throwObject.isThrow = true;
               throw(error as Error);
           }
       });
   }

   async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
       console.info(`enter callback generateKeyItem`);
       let throwObject: throwObject = {isThrow: false};
       try {
           await generateKeyItem(keyAlias, huksOptions, throwObject)
           .then((data) => {
               console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
           })
           .catch((error: BusinessError) => {
               if (throwObject.isThrow) {
                   throw(error as Error);
               } else {
                   console.error(`callback: generateKeyItem failed`);
               }
           });
       } catch (error) {
           console.error(`callback: generateKeyItem input arg invalid`);
       }
   }

   async function TestGenKeyForFingerprintAccessControl() {
       await publicGenKeyFunc(keyAlias, huksOptions);
   }
   ```

2. 使用密钥-加密场景-加密时不需要进行用户身份认证访问控制

   ```ts
   import huks from '@ohos.security.huks';
   import { BusinessError } from '@ohos.base';

   class HuksProperties {
       tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
       value: huks.HuksKeyAlg | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyPadding | huks.HuksCipherMode 
           | Uint8Array = huks.HuksKeyAlg.HUKS_ALG_ECC;
   }

   /*
    * 确定密钥别名和封装密钥属性参数集
    */
   let srcKeyAlias = 'sm4_key_fingerprint_access';
   let cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string'; // 明文数据
   let IV = '1234567890123456';
   let handle = 0;
   let cipherText: Uint8Array; // 加密后的密文数据

   function StringToUint8Array(str: string) {
       let arr: number[] = [];
       for (let i = 0, j = str.length; i < j; ++i) {
           arr.push(str.charCodeAt(i));
       }
       return new Uint8Array(arr);
   }

   /* 集成生成密钥参数集 & 加密参数集 */
   let propertiesEncrypt: HuksProperties[] = [
       {
           tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
           value: huks.HuksKeyAlg.HUKS_ALG_SM4,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_PURPOSE,
           value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
           value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_PADDING,
           value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
           value: huks.HuksCipherMode.HUKS_MODE_CBC,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_IV,
           value: StringToUint8Array(IV),
       }
   ];
   let encryptOptions: huks.HuksOptions = {
       properties: propertiesEncrypt,
       inData: new Uint8Array(new Array())
   }
   class throwObject1{
       isThrow: boolean = false;
   }
   function initSession(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject1) {
       return new Promise<huks.HuksSessionHandle>((resolve, reject) => {
           try {
               huks.initSession(keyAlias, huksOptions, (error, data) => {
                   if (error) {
                       reject(error);
                   } else {
                       resolve(data);
                   }
               });
           } catch (error) {
               throwObject.isThrow = true;
               throw (error as Error);
           }
       });
   }

   async function publicInitFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
       console.info(`enter callback doInit`);
       let throwObject: throwObject1 = { isThrow: false };
       try {
           await initSession(keyAlias, huksOptions, throwObject)
           .then((data) => {
               console.info(`callback: doInit success, data = ${JSON.stringify(data)}`);
               handle = data.handle as number;
           })
           .catch((error: BusinessError) => {
               if (throwObject.isThrow) {
                   throw (error as Error);
               } else {
                   console.error(`callback: doInit failed`);
               }
           });
       } catch (error) {
           console.error(`callback: doInit input arg invalid`);
       }
   }

   function finishSession(handle: number, huksOptions: huks.HuksOptions, throwObject: throwObject1) {
       return new Promise<huks.HuksReturnResult>((resolve, reject) => {
           try {
               huks.finishSession(handle, huksOptions, (error, data) => {
                   if (error) {
                       reject(error);
                   } else {
                       resolve(data);
                   }
               });
           } catch (error) {
               throwObject.isThrow = true;
               throw (error as Error);
           }
       });
   }

   async function publicFinishFunc(handle: number, huksOptions: huks.HuksOptions) {
       console.info(`enter callback doFinish`);
       let throwObject: throwObject1 = { isThrow: false };
       try {
           await finishSession(handle, huksOptions, throwObject)
           .then((data) => {
               cipherText = data.outData as Uint8Array;
               console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
           })
           .catch((error: BusinessError) => {
               if (throwObject.isThrow) {
                   throw (error as Error);
               } else {
                   console.error(`callback: doFinish failed`);
               }
           });
       } catch (error) {
           console.error(`callback: doFinish input arg invalid`);
       }
   }

   async function testSm4Cipher() {
       /* 初始化密钥会话获取挑战值 */
       await publicInitFunc(srcKeyAlias, encryptOptions);
       
       /* 加密 */
       encryptOptions.inData = StringToUint8Array(cipherInData);
       await publicFinishFunc(handle, encryptOptions);
   }
   ```

3. 使用密钥-解密场景-解密时需要进行用户身份认证访问控制

   ```ts
   import huks from '@ohos.security.huks';
   import userIAM_userAuth from '@ohos.userIAM.userAuth';
   import { BusinessError } from '@ohos.base';
   
   /*
    * 确定密钥别名和封装密钥属性参数集
    */
   let srcKeyAlias = 'sm4_key_fingerprint_access';
   let cipherText = 'r56ywtTJUQC6JFJ2VV2kZw=='; // 加密时得到的密文数据, 业务需根据实际加密结果修改
   let IV = '1234567890123456';
   let handle: number;
   let finishOutData: Uint8Array; // 解密后的明文数据
   let fingerAuthToken: Uint8Array;
   let challenge: Uint8Array;
   let authType = userIAM_userAuth.UserAuthType.FINGERPRINT;
   let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
   
   class throwObject {
       isThrow: boolean = false;
   }
   
   function StringToUint8Array(str: string) {
       let arr: number[] = [];
       for (let i = 0, j = str.length; i < j; ++i) {
           arr.push(str.charCodeAt(i));
       }
       return new Uint8Array(arr);
   }
   
   /* 集成生成密钥参数集 & 加密参数集 */
   class propertyDecryptType {
       tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM
       value: huks.HuksKeyAlg | huks.HuksKeyPurpose | huks.HuksKeySize | huks.HuksKeyPadding | huks.HuksCipherMode
           | Uint8Array = huks.HuksKeyAlg.HUKS_ALG_SM4
   }
   
   let propertiesDecrypt: propertyDecryptType[] = [
       {
           tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
           value: huks.HuksKeyAlg.HUKS_ALG_SM4,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_PURPOSE,
           value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
           value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_PADDING,
           value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
           value: huks.HuksCipherMode.HUKS_MODE_CBC,
       },
       {
           tag: huks.HuksTag.HUKS_TAG_IV,
           value: StringToUint8Array(IV),
       }
   ]
   
   let decryptOptions: huks.HuksOptions = {
       properties: propertiesDecrypt,
       inData: new Uint8Array(new Array())
   }
   
   function initSession(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
       return new Promise<huks.HuksSessionHandle>((resolve, reject) => {
           try {
               huks.initSession(keyAlias, huksOptions, (error, data) => {
                   if (error) {
                       reject(error);
                   } else {
                       resolve(data);
                   }
               });
           } catch (error) {
               throwObject.isThrow = true;
               throw(error as Error);
           }
       });
   }
   
   async function publicInitFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
       console.info(`enter callback doInit`);
       let throwObject: throwObject = {isThrow: false};
       try {
           await initSession(keyAlias, huksOptions, throwObject)
           .then ((data) => {
               console.info(`callback: doInit success, data = ${JSON.stringify(data)}`);
               handle = data.handle;
               challenge = data.challenge as Uint8Array;
           })
           .catch((error: BusinessError) => {
               if (throwObject.isThrow) {
                   throw(error as Error);
               } else {
                   console.error(`callback: doInit failed`);
               }
           });
       } catch (error) {
           console.error(`callback: doInit input arg invalid`);
       }
   }
   
   function userIAMAuthFinger(huksChallenge: Uint8Array) {
       // 获取认证对象
       let auth: userIAM_userAuth.AuthInstance ;
       try {
           auth = userIAM_userAuth.getAuthInstance(huksChallenge, authType, authTrustLevel);
           console.log("get auth instance success");
       } catch (error) {
           console.log("get auth instance failed" + error);
           return;
       }
   
       // 订阅认证结果
       try {
           auth.on("result", {
               callback: (result) => {
                   /* 认证成功获取认证令牌 */
                   fingerAuthToken = (result as userIAM_userAuth.AuthResultInfo).token as Uint8Array;
               }
           });
           console.log("subscribe authentication event success");
       } catch (error) {
           console.log("subscribe authentication event failed " + error);
       }
   
       // 开始认证
       try {
           auth.start();
           console.info("authV9 start auth success");
       } catch (error) {
           console.info("authV9 start auth failed, error = " + error);
       }
   }
   
   function finishSession(handle: number, huksOptions: huks.HuksOptions, token: Uint8Array, throwObject: throwObject) {
       return new Promise<huks.HuksReturnResult>((resolve, reject) => {
           try {
               huks.finishSession(handle, huksOptions, token, (error, data) => {
                   if (error) {
                       reject(error);
                   } else {
                       resolve(data);
                   }
               });
           } catch (error) {
               throwObject.isThrow = true;
               throw(error as Error);
           }
       });
   }
   
   async function publicFinishFunc(handle: number, token: Uint8Array, huksOptions: huks.HuksOptions) {
       console.info(`enter callback doFinish`);
       let throwObject: throwObject = {isThrow: false};
       try {
           await finishSession(handle, huksOptions, token, throwObject)
           .then ((data) => {
               finishOutData = data.outData as Uint8Array;
               console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
           })
           .catch((error: BusinessError) => {
               if (throwObject.isThrow) {
                   throw(error as Error);
               } else {
                   console.error(`callback: doFinish failed`);
               }
           });
       } catch (error) {
           console.error(`callback: doFinish input arg invalid`);
       }
   }
   
   async function testSm4Cipher() {
       /* 初始化密钥会话获取挑战值 */
       await publicInitFunc(srcKeyAlias, decryptOptions);
   
       /* 调用userIAM进行身份认证 */
       userIAMAuthFinger(challenge);
   
       /* 认证成功后进行解密, 需要传入Auth获取到的authToken值 */
       decryptOptions.inData = StringToUint8Array(cipherText);
       await publicFinishFunc(handle, fingerAuthToken, decryptOptions);
   }
   ```

## 密钥证明

HUKS为密钥提供合法性证明能力，主要应用于非对称密钥的公钥的证明。基于PKI证书链技术，HUKS可以为存储在HUKS中的非对称密钥对的公钥签发证书，证明其公钥的合法性。业务可以通过OpenHarmony提供的根CA证书，逐级验证HUKS签发的密钥证明证书，来确保证书中的公钥以及对应的私钥，确实来自合法的硬件设备，且存储管理在HUKS中。

**开发流程**

1. 指定密钥别名和需要证明的密钥属性的标签传入HUKS。
2. 调用HUKS为应用生成一个依次由根CA证书、设备CA证书、设备证书、密钥证书组成的X.509证书链。
3. 将证书链传输至受信任的服务器，并在服务器上解析和验证证书链的有效性和单个证书是否吊销。

**接口说明**

**表8** 密钥认证接口介绍
| 接口名                      | 描述                 |
| -------------------------------------- | ----------------------------|
|attestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult>) : void| 密钥认证|

**开发步骤**

```ts
/*
 * 以下以attestKey Callback接口操作验证为例
 */
import huks from '@ohos.security.huks';
import { BusinessError } from '@ohos.base';

/*
 * 确定密钥别名和封装密钥属性参数集
 */
let keyAliasString = "key attest";
let aliasString = keyAliasString;
let aliasUint8 = StringToUint8Array(keyAliasString);
let securityLevel = StringToUint8Array('sec_level');
let challenge = StringToUint8Array('challenge_data');
let versionInfo = StringToUint8Array('version_info');
let attestCertChain: Array<string>;

class throwObject {
    isThrow: boolean = false;
}

class genKeyPropertyType {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ALGORITHM;
    value: huks.HuksKeyAlg | huks.HuksKeyStorageType | huks.HuksKeySize | huks.HuksKeyPurpose | huks.HuksKeyDigest
        | huks.HuksKeyPadding | huks.HuksKeyGenerateType | huks.HuksCipherMode = huks.HuksKeyAlg.HUKS_ALG_RSA
}

let genKeyProperties: genKeyPropertyType[] = [
    {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA
    },
    {
        tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
        value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT
    },
    {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
    },
    {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
    },
    {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    },
    {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PSS
    },
    {
        tag: huks.HuksTag.HUKS_TAG_KEY_GENERATE_TYPE,
        value: huks.HuksKeyGenerateType.HUKS_KEY_GENERATE_TYPE_DEFAULT
    },
    {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB
    }
]

let genOptions: huks.HuksOptions = {
    properties: genKeyProperties
};

class attestKeypropertyType {
    tag: huks.HuksTag = huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO;
    value: Uint8Array = securityLevel;
}

let attestKeyproperties: attestKeypropertyType[] = [
    {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,
        value: securityLevel
    },
    {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,
        value: challenge
    },
    {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,
        value: versionInfo
    },
    {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,
        value: aliasUint8
    }
]

let huksOptions: huks.HuksOptions = {
    properties: attestKeyproperties
};

function StringToUint8Array(str: string) {
    let arr: number[] = [];
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
    return new Promise<void>((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, (error, data) => {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    let throwObject: throwObject = {isThrow: false};
    try {
        await generateKeyItem(keyAlias, huksOptions, throwObject)
        .then((data) => {
            console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
        })
        .catch((error: BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: generateKeyItem failed`);
            }
        });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid`);
    }
}

function attestKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
    return new Promise<huks.HuksReturnResult>((resolve, reject) => {
        try {
            huks.attestKeyItem(keyAlias, huksOptions, (error, data) => {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throwObject.isThrow = true;
            throw(error as Error);
        }
    });
}

async function publicAttestKey(keyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter callback attestKeyItem`);
    let throwObject: throwObject = {isThrow: false};
    try {
        await attestKeyItem(keyAlias, huksOptions, throwObject)
        .then ((data) => {
            console.info(`callback: attestKeyItem success, data = ${JSON.stringify(data)}`);
            if (data !== null && data.certChains !== null) {
                attestCertChain = data.certChains as string[];
            }
        })
        .catch((error: BusinessError) => {
            if (throwObject.isThrow) {
                throw(error as Error);
            } else {
                console.error(`callback: attestKeyItem failed`);
            }
        });
    } catch (error) {
        console.error(`callback: attestKeyItem input arg invalid`);
    }
}

async function AttestKeyTest() {
    await publicGenKeyFunc(aliasString, genOptions);

    await publicAttestKey(aliasString, huksOptions);
    console.info('attest certChain data: ' + attestCertChain)
}
```

**常见问题**

1. Cannot find name 'huks'.

   不能找到huks，使用了接口函数但没导入security.huks.d.ts，添加import huks from '@ohos.security.huks';即可。

2. Property 'finishSession' does not exist on type 'typeof huks'. Did you mean 'finish'?

   不能在huks库中找到finishSession，finishSession是API9版本的，请更新SDK版本或替换新版本的security.huks.d.ts文件。

## 相关实例

针对通用密钥库开发，有以下相关实例可供参考：

- [`Huks`：通用密钥库系统（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/Huks)