# HUKS开发指导

## 场景介绍

 HUKS（OpenHarmony Universal KeyStore，OpenHarmony通用密钥库系统）向应用提供密钥库能力，包括密钥管理及密钥的密码学操作等功能。HUKS所管理的密钥可以由应用导入或者由应用调用HUKS接口生成。 

## 基于JS的开发指导

1. 引入HUKS模块

   ```js
   import huks from '@ohos.security.huks'
   ```

2. 使用generateKey接口生成密钥。

   keyAlias为生成的密钥别名，options为生成密钥时使用到的参数，需根据具体需要到的算法设定options中的参数。

   generateKey接口会返回密钥的生成是否成功。

   ```js
   var alias = 'testAlias';
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_ECC
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_224
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[3] = {
     tag: huks.HuksTag.HUKS_TAG_DIGEST,
     value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
   };
   var options = {
     properties: properties
   }
   var resultA = huks.generateKey(alias, options);
   ```

3. 使用Init接口进行init操作。

   Alias为初始化密钥的别名，options为初始化密钥用的参数集合，需根据具体需要到的算法设定options中的参数。

   init接口会返回init操作是否成功。

   ```js
   var alias = 'test001'
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   huks.init(alias, options, function(err, data) {
       if (err.code !== 0) {
           console.log("test init err information: " + JSON.stringify(err));
       } else {
           console.log(`test init data: ${JSON.stringify(data)}`);
       }
   })
   ```

4. 使用Update接口进行update操作。

   handle为更新密钥的session id，options为更新密钥用的参数集合，需根据具体需要到的算法设定options中的参数。

   update接口会返回update操作是否成功。

   ```js
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   var result = huks.update(handle, options)
   ```

5. 使用Finish接口进行finish操作。

   handle为 结束密钥的session id，options为结束密钥用的参数集合，需根据具体需要到的算法设定options中的参数。

   finish接口会返回finish操作是否成功。

   ```js
   var properties = new Array();
   properties[0] = {
     tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
     value: huks.HuksKeyAlg.HUKS_ALG_DH
   };
   properties[1] = {
     tag: huks.HuksTag.HUKS_TAG_PURPOSE,
     value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
   };
   properties[2] = {
     tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
     value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_4096
   };
   var options = {
     properties: properties
   };
   var result = huks.finish(handle, options) 
   ```

## 基于TS的开发指导

### 密钥导入导出

HUKS支持非对称密钥的公钥导出能力，开发者可以通过密钥别名导出应用自己密钥对的公钥，只允许导出属于应用自己的密钥对的公钥。

HUKS支持密钥从外部导入的能力。密钥导入后全生命周期存在HUKS中，不能再被导出（非对称密钥的公钥除外）。 如果该别名的密钥已经存在，新导入的密钥将覆盖已经存在的密钥。 

开发步骤如下：

1. 生成密钥。
2. 导出密钥。
3. 导入密钥。

**支持导入的密钥类型：**

AES128, AES192, AES256, RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, HmacSHA1, HmacSHA224, HmacSHA256, HmacSHA384, HmacSHA512, ECC224, ECC256, ECC384, ECC521, Curve25519, DSA, SM2, SM3, SM4.

**支持导出的密钥类型：**

RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, ECC224, ECC256, ECC384, ECC521, Curve25519, DSA, SM2.

> **说明**
>
> 存储的 keyAlias 密钥别名最大为64字节

在使用示例前，需要先了解几个预先定义的变量： 

| 参数名            | 类型        | 必填 | 说明                     |
| ----------------- | ----------- | ---- | ------------------------ |
| srcKeyAlias       | string      | 是   | 生成密钥别名。           |
| srcKeyAliasSecond | string      | 是   | 导入密钥别名。           |
| huksOptions       | HuksOptions | 是   | 用于存放生成key所需TAG。 |
| encryptOptions    | HuksOptions | 是   | 用于存放导入key所需TAG。 |

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

**示例：**

```ts
/* 以生成RSA512密钥为例 */
var srcKeyAlias = 'hukRsaKeyAlias';
var srcKeyAliasSecond = 'huksRsaKeyAliasSecond';
var exportKey;

async function testImportExport() {
    /* 集成生成密钥参数集 */
    var properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA,
    }
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value:
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
    }
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
    }
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB,
    }
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
    }
    properties[5] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
    }
    var huksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }

    /* 生成密钥 */
    await huks.generateKey(srcKeyAlias, huksOptions).then((data) => {
        console.info(`test generateKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test generateKey err information: ' + JSON.stringify(err));
    });

    /* 导出密钥 */
    await huks.exportKey(srcKeyAlias, huksOptions).then((data) => {
        console.info(`test ExportKey data: ${JSON.stringify(data)}`);
        exportKey = data.outData;
    }).catch((err) => {
        console.info('test ImportKey err information: ' + JSON.stringify(err));
    });

    /* 集成导入密钥参数集 */
    var propertiesEncrypt = new Array();
    propertiesEncrypt[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA,
    }
    propertiesEncrypt[1] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
    }
    propertiesEncrypt[2] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
    }
    propertiesEncrypt[3] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB,
    }
    propertiesEncrypt[4] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
    }
    propertiesEncrypt[5] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
    }
    var encryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* 导入密钥 */
    encryptOptions.inData = exportKey;
    await huks.importKey(srcKeyAliasSecond, encryptOptions).then((data) => {
        console.info(`test ImportKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test ImportKey err information: ' + JSON.stringify(err));
    });
}
```

### 安全导入

基于密钥协商和中间密钥二次加密的方式，业务调用方和HUKS各自协商出共享的对称密钥来对中间密钥、待导入密钥进行加解密。从而实现密文导入后，在HUKS中对导入密钥进行解密再保存。对明文密钥的处理仅在HUKS 安全环境中，保证密钥明文生命周期内不出安全环境。 

开发步骤如下：

1.   huks中生成用于加密导入协商的密钥。
2.  导出该密钥的公钥，协商出共享密钥。
3.  生成中间密钥材料并加密密钥。
4.  导入密钥。 

**支持的密钥类型：**

AES128, AES192, AES256, RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, HmacSHA1, HmacSHA224, HmacSHA256, HmacSHA384, HmacSHA512, ECC224, ECC256, ECC384, ECC521, Curve25519, DSA, SM2, SM3, SM4.

> **注意**
>
> - 生成公共密钥时，要设置参数HUKS_TAG_PURPOSE = HUKS_KEY_PURPOSE_UNWRAP
> - 参数HUKS_TAG_IMPORT_KEY_TYPE = HUKS_KEY_TYPE_KEY_PAIR
> - 安全导入密钥时，参数集须加上参数HUKS_TAG_UNWRAP_ALGORITHM_SUITE, 值为HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING或者HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING
> - 存储的 keyAlias 密钥别名最大为64字节

在使用示例前，需要先了解几个预先定义的变量： 

| 参数名         | 类型        | 必填 | 说明                             |
| -------------- | ----------- | ---- | -------------------------------- |
| importAlias    | string      | 是   | 密钥别名。                       |
| wrapAlias      | string      | 是   | 密钥别名。                       |
| genWrapOptions | HuksOptions | 是   | 用于存放生成加密协商key所需TAG。 |
| importOptions  | HuksOptions | 是   | 用于存放导入加密key所需TAG。     |

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。 

**示例：**

```ts
var inputEccPair = new Uint8Array([
    0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00,
    0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xa5, 0xb8,
    0xa3, 0x78, 0x1d, 0x6d, 0x76, 0xe0, 0xb3, 0xf5, 0x6f, 0x43, 0x9d,
    0xcf, 0x60, 0xf6, 0x0b, 0x3f, 0x64, 0x45, 0xa8, 0x3f, 0x1a, 0x96,
    0xf1, 0xa1, 0xa4, 0x5d, 0x3e, 0x2c, 0x3f, 0x13, 0xd7, 0x81, 0xf7,
    0x2a, 0xb5, 0x8d, 0x19, 0x3d, 0x9b, 0x96, 0xc7, 0x6a, 0x10, 0xf0,
    0xaa, 0xbc, 0x91, 0x6f, 0x4d, 0xa7, 0x09, 0xb3, 0x57, 0x88, 0x19,
    0x6f, 0x00, 0x4b, 0xad, 0xee, 0x34, 0x35, 0xfb, 0x8b, 0x9f, 0x12,
    0xa0, 0x83, 0x19, 0xbe, 0x6a, 0x6f, 0x63, 0x2a, 0x7c, 0x86, 0xba,
    0xca, 0x64, 0x0b, 0x88, 0x96, 0xe2, 0xfa, 0x77, 0xbc, 0x71, 0xe3,
    0x0f, 0x0f, 0x9e, 0x3c, 0xe5, 0xf9]);

var exportWrappingKey;
var importAlias = "importAlias";
var wrapAlias = "wrappingKeyAlias";

async function TestGenFunc(alias, options) {
    await genKey(alias, options).then((data) => {
        console.log(`test genKey data: ${JSON.stringify(data)}`);
    })
    .catch((err) => {
        console.log('test genKey err information: ' + JSON.stringify(err));
    });
}

function genKey(alias, options) {
    return new Promise((resolve, reject) => {
        huks.importKey(alias, options, function (err, data) {
            console.log(`test genKey data: ${JSON.stringify(data)}`);
            if (err.code !== 0) {
                console.log('test genKey err information: ' + JSON.stringify(err));
                reject(err);
            } else {
                resolve(data);
            }
        });
    });
}

async function TestExportFunc(alias, options) {
    await exportKey(alias, options).then((data) => {
        console.log(`test exportKey data: ${JSON.stringify(data)}`);
    })
    .catch((err) => {
        console.log('test exportKey err information: ' + JSON.stringify(err));
    });
}

function exportKey(alias, options) {
    return new Promise((resolve, reject) => {
        huks.exportKey(alias, options, function (err, data) {
            console.log(`test exportKey data: ${JSON.stringify(data)}`);
            if (err.code !== 0) {
                console.log('test exportKey err information: ' + JSON.stringify(err));
                reject(err);
            } else {
                exportWrappingKey = data.outData;
                resolve(data);
            }
        });
    });
}

async function TestImportWrappedFunc(alias, wrappingAlias, options) {
    var result = await huks.importWrappedKey(alias, wrappingAlias, options);
    if (result.errorCode === 0) {
        console.error('test importWrappedKey success');
    } else {
        console.error('test importWrappedKey fail');
    }
}

async function TestImportWrappedKeyFunc(
    importAlias,
    wrappingAlias,
    genOptions,
    importOptions
) {
    await TestGenFunc(wrappingAlias, genOptions);
    await TestExportFunc(wrappingAlias, genOptions);

    /* 以下操作不需要调用HUKS接口，此处不给出具体实现。
     * 假设待导入的密钥为keyA
     * 1.生成ECC公私钥keyB，公钥为keyB_pub, 私钥为keyB_pri
     * 2.使用keyB_pri和wrappingAlias密钥中获取的公钥进行密钥协商，协商出共享密钥share_key
     * 3.随机生成密钥kek，用于加密keyA，采用AES-GCM加密，加密过程中需要记录：nonce1/aad1/加密后的密文keyA_enc/加密后的tag1。
     * 4.使用share_key加密kek，采用AES-GCM加密，加密过程中需要记录：nonce2/aad2/加密后的密文kek_enc/加密后的tag2。
     * 5.拼接importOptions.inData字段，满足以下格式:
     * keyB_pub的长度（4字节） + keyB_pub的数据 + aad2的长度（4字节） + aad2的数据 +
     * nonce2的长度（4字节）   + nonce2的数据   + tag2的长度（4字节） + tag2的数据 +
     * kek_enc的长度（4字节）  + kek_enc的数据  + aad1的长度（4字节） + aad1的数据 +
     * nonce1的长度（4字节）   + nonce1的数据   + tag1的长度（4字节） + tag1的数据 +
     * keyA长度占用的内存长度（4字节）  + keyA的长度     + keyA_enc的长度（4字节） + keyA_enc的数据
     */
    var inputKey = new Uint8Array([
    0x5b, 0x00, 0x00, 0x00, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a,
    0x86, 0x48, 0xce, 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48,
    0xce, 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0xc0, 0xfe,
    0x1c, 0x67, 0xde, 0x86, 0x0e, 0xfb, 0xaf, 0xb5, 0x85, 0x52, 0xb4,
    0x0e, 0x1f, 0x6c, 0x6c, 0xaa, 0xc5, 0xd9, 0xd2, 0x4d, 0xb0, 0x8a,
    0x72, 0x24, 0xa1, 0x99, 0xaf, 0xfc, 0x3e, 0x55, 0x5a, 0xac, 0x99,
    0x3d, 0xe8, 0x34, 0x72, 0xb9, 0x47, 0x9c, 0xa6, 0xd8, 0xfb, 0x00,
    0xa0, 0x1f, 0x9f, 0x7a, 0x41, 0xe5, 0x44, 0x3e, 0xb2, 0x76, 0x08,
    0xa2, 0xbd, 0xe9, 0x41, 0xd5, 0x2b, 0x9e, 0x10, 0x00, 0x00, 0x00,
    0xbf, 0xf9, 0x69, 0x41, 0xf5, 0x49, 0x85, 0x31, 0x35, 0x14, 0x69,
    0x12, 0x57, 0x9c, 0xc8, 0xb7, 0x10, 0x00, 0x00, 0x00, 0x2d, 0xb7,
    0xf1, 0x5a, 0x0f, 0xb8, 0x20, 0xc5, 0x90, 0xe5, 0xca, 0x45, 0x84,
    0x5c, 0x08, 0x08, 0x10, 0x00, 0x00, 0x00, 0x43, 0x25, 0x1b, 0x2f,
    0x5b, 0x86, 0xd8, 0x87, 0x04, 0x4d, 0x38, 0xc2, 0x65, 0xcc, 0x9e,
    0xb7, 0x20, 0x00, 0x00, 0x00, 0xf4, 0xe8, 0x93, 0x28, 0x0c, 0xfa,
    0x4e, 0x11, 0x6b, 0xe8, 0xbd, 0xa8, 0xe9, 0x3f, 0xa7, 0x8f, 0x2f,
    0xe3, 0xb3, 0xbf, 0xaf, 0xce, 0xe5, 0x06, 0x2d, 0xe6, 0x45, 0x5d,
    0x19, 0x26, 0x09, 0xe7, 0x10, 0x00, 0x00, 0x00, 0xf4, 0x1e, 0x7b,
    0x01, 0x7a, 0x84, 0x36, 0xa4, 0xa8, 0x1c, 0x0d, 0x3d, 0xde, 0x57,
    0x66, 0x73, 0x10, 0x00, 0x00, 0x00, 0xe3, 0xff, 0x29, 0x97, 0xad,
    0xb3, 0x4a, 0x2c, 0x50, 0x08, 0xb5, 0x68, 0xe1, 0x90, 0x5a, 0xdc,
    0x10, 0x00, 0x00, 0x00, 0x26, 0xae, 0xdc, 0x4e, 0xa5, 0x6e, 0xb1,
    0x38, 0x14, 0x24, 0x47, 0x1c, 0x41, 0x89, 0x63, 0x11, 0x04, 0x00,
    0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x0b,
    0xcb, 0xa9, 0xa8, 0x5f, 0x5a, 0x9d, 0xbf, 0xa1, 0xfc, 0x72, 0x74,
    0x87, 0x79, 0xf2, 0xf4, 0x22, 0x0c, 0x8a, 0x4d, 0xd8, 0x7e, 0x10,
    0xc8, 0x44, 0x17, 0x95, 0xab, 0x3b, 0xd2, 0x8f, 0x0a]);

    importOptions.inData = inputKey;
    await TestImportWrappedFunc(importAlias, wrappingAlias, importOptions);
}

function makePubKeyOptions() {
    var properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_ECC
    };
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
    };
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_UNWRAP
    };
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    };
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_IMPORT_KEY_TYPE,
        value: huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR,
    };
    var options = {
        properties: properties,
        inData: inputEccPair
    };
    return options;
}

function makeImportOptions() {
    var properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_AES
    };
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
    };
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value:
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
    };
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_CBC
    };
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_NONE
    };
    properties[5] = {
        tag: huks.HuksTag.HUKS_TAG_UNWRAP_ALGORITHM_SUITE,
        value: huks.HuksUnwrapSuite.HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING
    };
    var options = {
        properties: properties
    };
    return options;
}

function huksImportWrappedKey() {
    var genOptions = makePubKeyOptions();
    var importOptions = makeImportOptions();
    TestImportWrappedKeyFunc(
        importAlias,
        wrapAlias,
        genOptions,
        importOptions
    );
}
```

### 密钥加解密

通过指定别名的方式，使用HUKS中存储的对称或非对称密钥对数据进行加密或解密运算，运算过程中密钥明文不出安全环境。

开发步骤如下：

1. 生成密钥。
2. 密钥加密。
3. 密钥解密。

**支持的密钥类型：**

| HUKS_ALG_ALGORITHM                                           | HUKS_TAG_PURPOSE                                   | HUKS_TAG_DIGEST                                              | HUKS_TAG_PADDING                                             | HUKS_TAG_BLOCK_MODE                         | HUKS_TAG_IV |
| ------------------------------------------------------------ | -------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------- | ----------- |
| HUKS_ALG_SM4                  （支持长度：  HUKS_SM4_KEY_SIZE_128） | HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT | 【非必选】                                                   | HUKS_PADDING_NONE                                            | HUKS_MODE_CTR  HUKS_MODE_ECB  HUKS_MODE_CBC | 【必选】    |
| HUKS_ALG_SM4                  （支持长度：  HUKS_SM4_KEY_SIZE_128） | HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT | 【非必选】                                                   | HUKS_PADDING_PKCS7                                           | HUKS_MODE_ECB  HUKS_MODE_CBC                | 【必选】    |
| HUKS_ALG_RSA                 （支持长度：  HUKS_SM4_KEY_SIZE_512  HUKS_SM4_KEY_SIZE_768  HUKS_SM4_KEY_SIZE_1024  HUKS_SM4_KEY_SIZE_2048  HUKS_SM4_KEY_SIZE_3072  HUKS_SM4_KEY_SIZE_4096） | HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT | HUKS_DIGEST_SHA1 HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 | HUKS_PADDING_NONE  HUKS_PADDING_PKCS1_V1_5  HUKS_PADDING_OAEP | HUKS_MODE_ECB                               | 【非必选】  |

| HUKS_ALG_ALGORITHM                                           | HUKS_TAG_PURPOSE         | HUKS_TAG_PADDING                      | HUKS_TAG_BLOCK_MODE          | HUKS_TAG_IV | HUKS_TAG_NONCE | HUKS_TAG_ASSOCIATED_DATA | HUKS_TAG_AE_TAG |
| ------------------------------------------------------------ | ------------------------ | ------------------------------------- | ---------------------------- | ----------- | -------------- | ------------------------ | --------------- |
| HUKS_ALG_AES                 （支持长度：  HUKS_AES_KEY_SIZE_128  HUKS_AES_KEY_SIZE_192  HUKS_AES_KEY_SIZE_256） | HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_NONE  HUKS_PADDING_PKCS7 | HUKS_MODE_CBC                | 【必选】    | 【非必选】     | 【非必选】               | 【非必选】      |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CCM  HUKS_MODE_GCM | 【非必选】  | 【必选】       | 【必选】                 | 【非必选】      |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CTR                | 【必选】    | 【非必选】     | 【非必选】               | 【非必选】      |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_PKCS7  HUKS_PADDING_NONE | HUKS_MODE_ECB                | 【必选】    | 【非必选】     | 【非必选】               | 【非必选】      |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE  HUKS_PADDING_PKCS7 | HUKS_MODE_CBC                | 【必选】    | 【非必选】     | 【非必选】               | 【必选】        |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CCM  HUKS_MODE_GCM | 【非必选】  | 【必选】       | 【必选】                 | 【非必选】      |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CTR                | 【必选】    | 【非必选】     | 【非必选】               | 【非必选】      |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE  HUKS_PADDING_PKCS7 | HUKS_MODE_ECB                | 【必选】    | 【非必选】     | 【非必选】               | 【非必选】      |

> **说明**
>
> 存储的 keyAlias 密钥别名最大为64字节

在使用示例前，需要先了解几个预先定义的变量： 

| 参数名         | 类型        | 必填 | 说明                     |
| -------------- | ----------- | ---- | ------------------------ |
| srcKeyAlias    | string      | 是   | 密钥别名。               |
| huksOptions    | HuksOptions | 是   | 用于存放生成key所需TAG。 |
| encryptOptions | HuksOptions | 是   | 用于存放加密key所需TAG。 |
| decryptOptions | HuksOptions | 是   | 用于存放解密key所需TAG。 |

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。 

**示例1：**

```ts
/* Cipher操作支持RSA、AES、SM4类型的密钥。
 *
 * 以下以SM4 128密钥的Promise操作使用为例
 */
function sm4CipherStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}
function sm4CipherUint8ArrayToString(fileData) {
    var dataString = '';
    for (var i = 0; i < fileData.length; i++) {
        dataString += String.fromCharCode(fileData[i]);
    }
    return dataString;
}

var handle;
var IV = '0000000000000000';
var cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string';
var srcKeyAlias = 'huksCipherSm4SrcKeyAlias';
var encryptUpdateResult = new Array();
var decryptUpdateResult = new Array();

async function testCipher() {
    /* 集成生成密钥参数集 & 加密参数集 */
    var properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_SM4,
    }
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value:
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
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
    var huksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }

    var propertiesEncrypt = new Array();
    propertiesEncrypt[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_SM4,
    }
    propertiesEncrypt[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
    }
    propertiesEncrypt[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_SM4_KEY_SIZE_128,
    }
    propertiesEncrypt[3] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
    }
    propertiesEncrypt[4] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_CBC,
    }
    propertiesEncrypt[5] = {
        tag: huks.HuksTag.HUKS_TAG_IV,
        value: sm4CipherStringToUint8Array(IV),
    }
    var encryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* 生成密钥 */
    await huks.generateKey(srcKeyAlias, huksOptions).then((data) => {
        console.info(`test generateKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test generateKey err information: ' + JSON.stringify(err));
    });

    /* 进行密钥加密操作 */
    await huks.init(srcKeyAlias, encryptOptions).then((data) => {
        console.info(`test init data: ${JSON.stringify(data)}`);
        handle = data.handle;
    }).catch((err) => {
        console.info('test init err information: ' + JSON.stringify(err));
    });
    encryptOptions.inData = sm4CipherStringToUint8Array(cipherInData);
    await huks.update(handle, encryptOptions).then(async (data) => {
        console.info(`test update data ${JSON.stringify(data)}`);
        encryptUpdateResult = Array.from(data.outData);
    }).catch((err) => {
        console.info('test update err information: ' + err);
    });
    encryptOptions.inData = new Uint8Array(new Array());
    await huks.finish(handle, encryptOptions).then((data) => {
        console.info(`test finish data: ${JSON.stringify(data)}`);
        var finishData = sm4CipherUint8ArrayToString(new Uint8Array(encryptUpdateResult));
        if (finishData === cipherInData) {
            console.info('test finish encrypt err ');
        } else {
            console.info('test finish encrypt success');
        }
    }).catch((err) => {
        console.info('test finish err information: ' + JSON.stringify(err));
    });

    /* 修改加密参数集为解密参数集 */
    propertiesEncrypt.splice(1, 1, {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
    });
    var decryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* 进行解密操作 */
    await huks.init(srcKeyAlias, decryptOptions).then((data) => {
        console.info(`test init data: ${JSON.stringify(data)}`);
        handle = data.handle;
    }).catch((err) => {
        console.info('test init err information: ' + JSON.stringify(err));
    });
    decryptOptions.inData = new Uint8Array(encryptUpdateResult);
    await huks.update(handle, decryptOptions).then(async (data) => {
        console.info(`test update data ${JSON.stringify(data)}`);
        decryptUpdateResult = Array.from(data.outData);
    }).catch((err) => {
        console.info('test update err information: ' + err);
    });
    decryptOptions.inData = new Uint8Array(new Array());
    await huks.finish(handle, decryptOptions).then((data) => {
        console.info(`test finish data: ${JSON.stringify(data)}`);
        var finishData = sm4CipherUint8ArrayToString(new Uint8Array(decryptUpdateResult));
        if (finishData === cipherInData) {
            console.info('test finish decrypt success ');
        } else {
            console.info('test finish decrypt err');
        }
    }).catch((err) => {
        console.info('test finish err information: ' + JSON.stringify(err));
    });

    await huks.deleteKey(srcKeyAlias, huksOptions).then((data) => {
        console.info(`test deleteKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test deleteKey err information: ' + JSON.stringify(err));
    });
}
```

**示例2：**

```ts
/* Cipher操作支持RSA、AES、SM4类型的密钥。
 *
 * 以下以AES128 GCM密钥的Promise操作使用为例
 */
function aesCipherStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}
function aesCipherUint8ArrayToString(fileData) {
    var dataString = '';
    for (var i = 0; i < fileData.length; i++) {
        dataString += String.fromCharCode(fileData[i]);
    }
    return dataString;
}

async function aesCipher() {
    var handle;
    var AAD = '0000000000000000';
    var NONCE = '000000000000';
    var AEAD = '0000000000000000';
    var cipherInData = 'Hks_AES_Cipher_Test_00000000000000000000000000000000000000000000000000000_string';
    var srcKeyAlias = 'huksCipherAesSrcKeyAlias';
    var encryptUpdateResult = new Array();
    var decryptUpdateResult = new Array();
    /* 集成生成密钥参数集 & 加密参数集 */
    var properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_AES,
    }
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value:
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
    }
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
    }
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_GCM,
    }
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
    }
    var HuksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }

    var propertiesEncrypt = new Array();
    propertiesEncrypt[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_AES,
    }
    propertiesEncrypt[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
    }
    propertiesEncrypt[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
    }
    propertiesEncrypt[3] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
    }
    propertiesEncrypt[4] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_GCM,
    }
    propertiesEncrypt[5] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
    }
    propertiesEncrypt[6] = {
        tag: huks.HuksTag.HUKS_TAG_ASSOCIATED_DATA,
        value: aesCipherStringToUint8Array(AAD),
    }
    propertiesEncrypt[7] = {
        tag: huks.HuksTag.HUKS_TAG_NONCE,
        value: aesCipherStringToUint8Array(NONCE),
    }
    propertiesEncrypt[8] = {
        tag: huks.HuksTag.HUKS_TAG_AE_TAG,
        value: aesCipherStringToUint8Array(AEAD),
    }
    var encryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* 生成密钥 */
    await huks.generateKey(srcKeyAlias, HuksOptions).then((data) => {
        console.info(`test generateKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test generateKey err information: ' + JSON.stringify(err));
    });

    /* 进行密钥加密操作 */
    await huks.init(srcKeyAlias, encryptOptions).then((data) => {
        console.info(`test init data: ${JSON.stringify(data)}`);
        handle = data.handle;
    }).catch((err) => {
        console.info('test init err information: ' + JSON.stringify(err));
    });
    encryptOptions.inData = aesCipherStringToUint8Array(cipherInData.slice(0,64));
    await huks.update(handle, encryptOptions).then(async (data) => {
        console.info(`test update data ${JSON.stringify(data)}`);
        encryptUpdateResult = Array.from(data.outData);
    }).catch((err) => {
        console.info('test update err information: ' + err);
    });
    encryptOptions.inData = aesCipherStringToUint8Array(cipherInData.slice(64,80));
    await huks.finish(handle, encryptOptions).then((data) => {
        console.info(`test finish data: ${JSON.stringify(data)}`);
        encryptUpdateResult = encryptUpdateResult.concat(Array.from(data.outData));
        var finishData = aesCipherUint8ArrayToString(new Uint8Array(encryptUpdateResult));
        if (finishData === cipherInData) {
            console.info('test finish encrypt err ');
        } else {
            console.info('test finish encrypt success');
        }
    }).catch((err) => {
        console.info('test finish err information: ' + JSON.stringify(err));
    });

    /* 修改加密参数集为解密参数集 */
    propertiesEncrypt.splice(1, 1, {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
    });
    propertiesEncrypt.splice(8, 1, {
        tag: huks.HuksTag.HUKS_TAG_AE_TAG,
        value: new Uint8Array(encryptUpdateResult.splice(encryptUpdateResult.length - 16,encryptUpdateResult.length))
    });
    var decryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* 进行解密操作 */
    await huks.init(srcKeyAlias, decryptOptions).then((data) => {
        console.info(`test init data: ${JSON.stringify(data)}`);
        handle = data.handle;
    }).catch((err) => {
        console.info('test init err information: ' + JSON.stringify(err));
    });
    decryptOptions.inData = new Uint8Array(encryptUpdateResult.slice(0,64));
    await huks.update(handle, decryptOptions).then(async (data) => {
        console.info(`test update data ${JSON.stringify(data)}`);
        decryptUpdateResult = Array.from(data.outData);
    }).catch((err) => {
        console.info('test update err information: ' + err);
    });
    decryptOptions.inData = new Uint8Array(encryptUpdateResult.slice(64,encryptUpdateResult.length));
    await huks.finish(handle, decryptOptions).then((data) => {
        console.info(`test finish data: ${JSON.stringify(data)}`);
        decryptUpdateResult = decryptUpdateResult.concat(Array.from(data.outData));
        var finishData = aesCipherUint8ArrayToString(new Uint8Array(decryptUpdateResult));
        if (finishData === cipherInData) {
            console.info('test finish decrypt success ');
        } else {
            console.info('test finish decrypt err');
        }
    }).catch((err) => {
        console.info('test finish err information: ' + JSON.stringify(err));
    });

    await huks.deleteKey(srcKeyAlias, HuksOptions).then((data) => {
        console.info(`test deleteKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test deleteKey err information: ' + JSON.stringify(err));
    });
}
```

### 密钥签名验签

签名：给我们将要发送的数据，做上一个唯一签名；验签： 对发送者发送过来的签名进行验证 。

开发步骤如下：

1. 生成密钥。
2. 密钥签名。
3. 导出签名密钥。
4. 导入签名密钥。
5. 密钥验签。

**支持的密钥类型：**

仅HksInit对paramSet中参数有要求，其他三段式接口对paramSet无要求

| HUKS_ALG_ALGORITHM | HUKS_ALG_KEY_SIZE                                            | HUKS_ALG_PURPOSE                               | HUKS_ALG_PADDING        | HUKS_TAG_DIGEST                                              |
| ------------------ | ------------------------------------------------------------ | ---------------------------------------------- | ----------------------- | ------------------------------------------------------------ |
| HUKS_ALG_RSA       | HUKS_RSA_KEY_SIZE_512  HUKS_RSA_KEY_SIZE_768  HUKS_RSA_KEY_SIZE_1024  HUKS_RSA_KEY_SIZE_2048  HUKS_RSA_KEY_SIZE_3072  HUKS_RSA_KEY_SIZE_4096 | HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY | HUKS_PADDING_PKCS1_V1_5 | HUKS_DIGEST_MD5  HUKS_DIGEST_NONE  HUKS_DIGEST_SHA1  HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 |
| HUKS_ALG_RSA       | HUKS_RSA_KEY_SIZE_512  HUKS_RSA_KEY_SIZE_768  HUKS_RSA_KEY_SIZE_1024  HUKS_RSA_KEY_SIZE_2048  HUKS_RSA_KEY_SIZE_3072  HUKS_RSA_KEY_SIZE_4096 | HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY | HUKS_PADDING_PSS        | HUKS_DIGEST_SHA1  HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 |
| HUKS_ALG_DSA       | HUKS_RSA_KEY_SIZE_1024                                       | HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY | 【非必选】              | HUKS_DIGEST_SHA1  HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 |
| HUKS_ALG_ECC       | HUKS_ECC_KEY_SIZE_224  HUKS_ECC_KEY_SIZE_256  HUKS_ECC_KEY_SIZE_384  HUKS_ECC_KEY_SIZE_521 | HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY | 【非必选】              | HUKS_DIGEST_NONE  HUKS_DIGEST_SHA1  HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 |

Ed25519的签名验签是在算法引擎中做的HASH操作，因此该算法的三段式接口处理较特殊：

Update过程只将inData发送到Core中记录在ctx中，不进行Hash计算，最后在finish操作时，对inData组合后的数据进行签名、验签计算.

| HUKS_ALG_ALGORITHM | HUKS_ALG_KEY_SIZE            | HUKS_ALG_PURPOSE                                |
| ------------------ | ---------------------------- | ----------------------------------------------- |
| HUKS_ALG_ED25519   | HUKS_CURVE25519_KEY_SIZE_256 | HUKS_KEY_PURPOSE_SIGN   HUKS_KEY_PURPOSE_VERIFY |

> **说明**
>
> 存储的 keyAlias 密钥别名最大为64字节

在使用示例前，需要先了解几个预先定义的变量： 

| 参数名               | 类型        | 必填 | 说明                     |
| -------------------- | ----------- | ---- | ------------------------ |
| srcRsaKeyAliasSign   | string      | 是   | 生成密钥别名。           |
| srcRsaKeyAliasVerify | string      | 是   | 导入密钥别名。           |
| rsaSignOptions       | HuksOptions | 是   | 用于存放生成key所需TAG。 |
| rsaSignOptionsSecond | HuksOptions | 是   | 用于存放签名key所需TAG。 |
| rsaVerifyOptions     | HuksOptions | 是   | 用于存放验签key所需TAG。 |

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

**示例：**

```ts
/* Sign/Verify操作支持RSA、ECC、SM2、ED25519、DSA类型的密钥。
 *
 * 以下以RSA512密钥的Promise操作使用为例
 */
function rsaSignVerifyStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

var rsaSignHandle;
var rsaSignVerifyInData = 'signVerifyInData';
var srcRsaKeyAliasSign = 'huksSignVerifySrcKeyAliasSign';
var srcRsaKeyAliasVerify = 'huksSignVerifySrcKeyAliasVerify';
var finishRsaSignData;
var rsaExportSignKey;

async function testSignVerify() {
    /* 集成生成密钥参数集 & 签名参数集 & 验签参数集 */
    var rsaSignProperties = new Array();
    rsaSignProperties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA,
    }
    rsaSignProperties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN,
    }
    rsaSignProperties[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
    }
    rsaSignProperties[3] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_MD5,
    }
    rsaSignProperties[4] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
    }
    var rsaSignOptions = {
        properties: rsaSignProperties,
        inData: new Uint8Array(new Array())
    }

    var rsaPropertiesSign = new Array();
    rsaPropertiesSign[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA,
    }
    rsaPropertiesSign[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value:
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
    }
    rsaPropertiesSign[2] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_MD5,
    }
    rsaPropertiesSign[3] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
    }
    rsaPropertiesSign[4] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
    }
    var rsaSignOptionsSecond = {
        properties: rsaPropertiesSign,
        inData: new Uint8Array(new Array())
    }

    var rsaPropertiesVerify = new Array();
    rsaPropertiesVerify[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA,
    }
    rsaPropertiesVerify[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
    }
    rsaPropertiesVerify[2] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_MD5,
    }
    rsaPropertiesVerify[3] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
    }
    rsaPropertiesVerify[4] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
    }
    var rsaVerifyOptions = {
        properties: rsaPropertiesVerify,
        inData: new Uint8Array(new Array())
    }

    /* 生成密钥 */
    await huks.generateKey(srcRsaKeyAliasSign, rsaSignOptions).then((data) => {
        console.info(`test generateKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test generateKey err information: ' + JSON.stringify(err));
    });

    /* 对密钥进行签名操作 */
    await huks.init(srcRsaKeyAliasSign, rsaSignOptionsSecond).then((data) => {
        console.info(`test init data: ${JSON.stringify(data)}`);
        rsaSignHandle = data.handle;
    }).catch((err) => {
        console.info('test init err information: ' + JSON.stringify(err));
    });
    rsaSignOptionsSecond.inData = rsaSignVerifyStringToUint8Array(rsaSignVerifyInData)
    await huks.update(rsaSignHandle, rsaSignOptionsSecond).then(async (data) => {
        console.info(`test update data ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test update err information: ' + err);
    });
    rsaSignOptionsSecond.inData = new Uint8Array(new Array());
    await huks.finish(rsaSignHandle, rsaSignOptionsSecond).then((data) => {
        console.info(`test finish data: ${JSON.stringify(data)}`);
        finishRsaSignData = data.outData;
    }).catch((err) => {
        console.info('test finish err information: ' + JSON.stringify(err));
    });

    /* 通过导出导入模拟获取一段密钥数据 */
    await huks.exportKey(srcRsaKeyAliasSign, rsaSignOptions).then((data) => {
        console.info(`test exportKey data: ${JSON.stringify(data)}`);
        rsaExportSignKey = data.outData;
    }).catch((err) => {
        console.info('test exportKey err information: ' + JSON.stringify(err));
    });
    rsaVerifyOptions.inData = rsaExportSignKey;
    await huks.importKey(srcRsaKeyAliasVerify, rsaVerifyOptions).then((data) => {
        console.info(`test ImportKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test exportKey err information: ' + JSON.stringify(err));
    });

    /* 对密钥进行验签 */
    await huks.init(srcRsaKeyAliasVerify, rsaVerifyOptions).then((data) => {
        console.info(`test init data: ${JSON.stringify(data)}`);
        rsaSignHandle = data.handle;
    }).catch((err) => {
        console.info('test init err information: ' + JSON.stringify(err));
    });
    rsaVerifyOptions.inData = rsaSignVerifyStringToUint8Array(rsaSignVerifyInData);
    await huks.update(rsaSignHandle, rsaVerifyOptions).then(async (data) => {
        console.info(`test update data ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test update err information: ' + err);
    });
    rsaVerifyOptions.inData = finishRsaSignData;
    await huks.finish(rsaSignHandle, rsaVerifyOptions).then((data) => {
        console.info(`test finish data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test finish err information: ' + JSON.stringify(err));
    });

    await huks.deleteKey(srcRsaKeyAliasVerify, rsaVerifyOptions).then((data) => {
        console.info(`test deleteKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test deleteKey err information: ' + JSON.stringify(err));
    });

    await huks.deleteKey(srcRsaKeyAliasSign, rsaSignOptions).then((data) => {
        console.info(`test deleteKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test deleteKey err information: ' + JSON.stringify(err));
    });
}
```

### 密钥协商

两个或多个对象生成会话密钥，通过会话密钥进行交流 。

开发步骤如下：

1. 生成两个密钥。
2. 分别导出密钥。
3. 交叉进行密钥协商。

**支持的密钥类型：**

仅HksInit和HksFinish接口对paramSet参数有要求，HksUpdate接口对paramSet无要求

HksInit对paramSet中参数的要求

| HUKS_ALG_ALGORITHM | HUKS_ALG_KEY_SIZE                                            | HUKS_ALG_PURPOSE       |
| ------------------ | ------------------------------------------------------------ | ---------------------- |
| HUKS_ALG_ECDH      | HUKS_ECC_KEY_SIZE_224  HUKS_ECC_KEY_SIZE_256 HUKS_ECC_KEY_SIZE_384 HUKS_ECC_KEY_SIZE_521 | HUKS_KEY_PURPOSE_AGREE |
| HUKS_ALG_DH        | HUKS_DH_KEY_SIZE_2048 HUKS_DH_KEY_SIZE_3072 HUKS_DH_KEY_SIZE_4096 | HUKS_KEY_PURPOSE_AGREE |
| HUKS_ALG_X25519    | HUKS_CURVE25519_KEY_SIZE_256                                 | HUKS_KEY_PURPOSE_AGREE |

HksFinish对paramSet中参数的要求：

派生后的密钥作为对称密钥进行使用

| HUKS_TAG_KEY_STORAGE_FLAG      | HUKS_TAG_KEY_ALIAS | HUKS_TAG_IS_KEY_ALIAS | HUKS_TAG_ALGORITHM | HUKS_TAG_KEY_SIZE                                            | HUKS_TAG_PURPOSE                                   | HUKS_TAG_PADDING   | HUKS_TAG_DIGEST                                              | HUKS_TAG_BLOCK_MODE                         |
| ------------------------------ | ------------------ | --------------------- | ------------------ | ------------------------------------------------------------ | -------------------------------------------------- | ------------------ | ------------------------------------------------------------ | ------------------------------------------- |
| 未设置 或者  HUKS_STORAGE_TEMP | 不需要             | TRUE                  | 不需要             | 不需要                                                       | 不需要                                             | 不需要             | 不需要                                                       | 不需要                                      |
| HUKS_STORAGE_PERSISTENT        | 【必选】最大64字节 | TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128   HUKS_AES_KEY_SIZE_192  HUKS_AES_KEY_SIZE_256 | HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_PKCS7 | 【非必选】                                                   | HUKS_MODE_CCM  HUKS_MODE_GCM  HUKS_MODE_CTP |
| HUKS_STORAGE_PERSISTENT        | 【必选】最大64字节 | TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128   HUKS_AES_KEY_SIZE_192  HUKS_AES_KEY_SIZE_256 | HUKS_KEY_PURPOSE_DERIVE                            | 【非必选】         | HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512   | 【非必选】                                  |
| HUKS_STORAGE_PERSISTENT        | 【必选】最大64字节 | TRUE                  | HUKS_ALG_HMAC      | 8的倍数（单位：bit）                                         | HUKS_KEY_PURPOSE_MAC                               | 【非必选】         | HUKS_DIGEST_SHA1  HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384 HUKS_DIGEST_SHA512 | 【非必选】                                  |

> **说明**
>
> HUKS_ALG_AES的SIZE需要满足：协商后的密钥长度（转换成bit）>=选择的HUKS_TAG_KEY_SIZE
>
> 存储的 keyAlias 密钥别名最大为64字节

在使用示例前，需要先了解几个预先定义的变量： 

| 参数名              | 类型        | 必填 | 说明                                   |
| ------------------- | ----------- | ---- | -------------------------------------- |
| srcKeyAliasFirst    | string      | 是   | 生成密钥别名。                         |
| srcKeyAliasSecond   | string      | 是   | 生成密钥别名，用于结果对比。           |
| huksOptions         | HuksOptions | 是   | 用于存放生成key所需TAG。               |
| finishOptionsFrist  | HuksOptions | 是   | 用于存放协商key所需TAG。               |
| finishOptionsSecond | HuksOptions | 是   | 用于存放协商key所需TAG，用于结果对比。 |

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

**示例：**

```ts
/* agree操作支持ECDH、DH、X25519类型的密钥。
 *
 * 以下以X25519 256 TEMP密钥的Promise操作使用为例
 */
function AgreeStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

var srcKeyAliasFirst = "AgreeX25519KeyFirstAlias";
var srcKeyAliasSecond = "AgreeX25519KeySecondAlias";
var agreeX25519InData = 'AgreeX25519TestIndata';
var exportKeyFrist;
var exportKeySecond;

async function testAgree() {
    /* 集成生成密钥参数集 */
    var properties = new Array();
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
    var HuksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }

    /* 1.生成两个密钥并导出 */
    await huks.generateKey(srcKeyAliasFirst, HuksOptions).then((data) => {
        console.info('test generateKey data = ' + JSON.stringify(data));
    }).catch((err) => {
        console.info(`test generateKey err: " + ${JSON.stringify(err)}`);
    });
    await huks.generateKey(srcKeyAliasSecond, HuksOptions).then((data) => {
        console.info('test generateKey data = ' + JSON.stringify(data));
    }).catch((err) => {
        console.info(`test generateKey err: " + ${JSON.stringify(err)}`);
    });
    await huks.exportKey(srcKeyAliasFirst, HuksOptions).then((data) => {
        console.info('test exportKey data = ' + JSON.stringify(data));
        exportKeyFrist = data.outData;
    }).catch((err) => {
        console.info(`test exportKey err: " + ${JSON.stringify(err)}`);
    });
    await huks.exportKey(srcKeyAliasSecond, HuksOptions).then((data) => {
        console.info('test exportKey data = ' + JSON.stringify(data));
        exportKeySecond = data.outData;
    }).catch((err) => {
        console.info(`test exportKey err: " + ${JSON.stringify(err)}`);
    });

    /* 集成第一个协商参数集 */
    var finishProperties = new Array();
    finishProperties[0] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
        value: huks.HuksKeyStorageType.HUKS_STORAGE_TEMP,
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
        value: AgreeStringToUint8Array(srcKeyAliasFirst+ 'final'),
    }
    finishProperties[7] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
    }
    finishProperties[8] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB,
    }
    var finishOptionsFrist = {
        properties: finishProperties,
        inData: AgreeStringToUint8Array(agreeX25519InData)
    }
    
    /* 对第一个密钥进行协商 */
    await huks.init(srcKeyAliasFirst, HuksOptions).then((data) => {
        console.info(`test init data: ${JSON.stringify(data)}`);
        handle = data.handle;
    }).catch((err) => {
        console.info(`test init err: " + ${JSON.stringify(err)}`);
    });
    HuksOptions.inData = exportKeySecond;
    await huks.update(handle, HuksOptions).then((data) => {
        console.info(`test update data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info(`test update err: " + ${JSON.stringify(err)}`);
    });
    await huks.finish(handle, finishOptionsFrist).then((data) => {
        console.info(`test finish data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test finish err information: ' + JSON.stringify(err));
    });

    /* 集成第二个协商参数集 */
    var finishOptionsSecond = {
        properties: finishProperties,
        inData: AgreeStringToUint8Array(agreeX25519InData)
    }
    finishOptionsSecond.properties.splice(6, 1, {
        tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
        value: AgreeStringToUint8Array(srcKeyAliasSecond + 'final'),
    })
    
    /* 对第二个密钥进行协商 */
    await huks.init(srcKeyAliasSecond, HuksOptions).then((data) => {
        console.info(`test init data: ${JSON.stringify(data)}`);
        handle = data.handle;
    }).catch((err) => {
        console.info(`test init err: " + ${JSON.stringify(err)}`);
    });
    HuksOptions.inData = exportKeyFrist;
    await huks.update(handle, HuksOptions).then((data) => {
        console.info(`test update data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info(`test update err: " + ${JSON.stringify(err)}`);
    });
    await huks.finish(handle, finishOptionsSecond).then((data) => {
        console.info(`test finish data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test finish err information: ' + JSON.stringify(err));
    });

    await huks.deleteKey(srcKeyAliasFirst, huksOptions).then((data) => {
        console.info(`test deleteKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test deleteKey err information: ' + JSON.stringify(err));
    });
    await huks.deleteKey(srcKeyAliasSecond, huksOptions).then((data) => {
        console.info(`test deleteKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test deleteKey err information: ' + JSON.stringify(err));
    });
}
```

### 密钥派生

从一个密钥产生出一个或者多个密钥。 

开发步骤如下：

1. 生成密钥。
2. 进行密钥派生。

**支持的密钥类型：**

仅HksInit和HksFinish接口对paramSet参数有要求，HksUpdate接口对paramSet无要求

HksInit对paramSet中参数的要求

| HUKS_TAG_ALGORITHM                                           | HUKS_TAG_PURPOSE        | HUKS_TAG_DIGEST                                            | HUKS_TAG_DERIVE_KEY_SIZE |
| ------------------------------------------------------------ | ----------------------- | ---------------------------------------------------------- | ------------------------ |
| HUKS_ALG_HKDF  （支持长度：  HUKS_AES_KEY_SIZE_128 HUKS_AES_KEY_SIZE_192 HUKS_AES_KEY_SIZE_256） | HUKS_KEY_PURPOSE_DERIVE | HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 | 【必选】                 |
| HUKS_ALG_PBKDF2  （支持长度：  HUKS_AES_KEY_SIZE_128 HUKS_AES_KEY_SIZE_192 HUKS_AES_KEY_SIZE_256） | HUKS_KEY_PURPOSE_DERIVE | HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 | 【必选】                 |

HksFinish对paramSet中参数的要求：

派生后的密钥作为对称密钥进行使用

| HUKS_TAG_KEY_STORAGE_FLAG      | HUKS_TAG_KEY_ALIAS | HUKS_TAG_IS_KEY_ALIAS | HUKS_TAG_ALGORITHM | HUKS_TAG_KEY_SIZE                                            | HUKS_TAG_PURPOSE                                   | HUKS_TAG_PADDING                      | HUKS_TAG_DIGEST                                              | HUKS_TAG_BLOCK_MODE                         |
| ------------------------------ | ------------------ | --------------------- | ------------------ | ------------------------------------------------------------ | -------------------------------------------------- | ------------------------------------- | ------------------------------------------------------------ | ------------------------------------------- |
| 未设置 或者  HUKS_STORAGE_TEMP | 不需要             | TRUE                  | 不需要             | 不需要                                                       | 不需要                                             | 不需要                                | 不需要                                                       | 不需要                                      |
| HUKS_STORAGE_PERSISTENT        | 【必选】最大64字节 | TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128  HUKS_AES_KEY_SIZE_192  HUKS_AES_KEY_SIZE_256 | HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE  HUKS_PADDING_PKCS7 | 【非必选】                                                   | HUKS_MODE_CBC  HUKS_MODE_ECB                |
| HUKS_STORAGE_PERSISTENT        | 【必选】最大64字节 | TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128  HUKS_AES_KEY_SIZE_192  HUKS_AES_KEY_SIZE_256 | HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE                     | 【非必选】                                                   | HUKS_MODE_CCM  HUKS_MODE_GCM  HUKS_MODE_CTR |
| HUKS_STORAGE_PERSISTENT        | 【必选】最大64字节 | TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128  HUKS_AES_KEY_SIZE_192  HUKS_AES_KEY_SIZE_256 | HUKS_KEY_PURPOSE_DERIVE                            | 【非必选】                            | HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512   | 【非必选】                                  |
| HUKS_STORAGE_PERSISTENT        | 【必选】最大64字节 | TRUE                  | HUKS_ALG_HMAC      | 8的倍数（单位：bit）                                         | HUKS_KEY_PURPOSE_MAC                               | 【非必选】                            | HUKS_DIGEST_SHA1  HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 | 【非必选】                                  |

> **说明**
>
> HUKS_ALG_AES的SIZE需要满足：协商后的密钥长度（转换成bit）>=选择的HUKS_TAG_KEY_SIZE
>
> 存储的 keyAlias 密钥别名最大为64字节

在使用示例前，需要先了解几个预先定义的变量： 

| 参数名        | 类型        | 必填 | 说明             |
| ------------- | ----------- | ---- | ---------------- |
| srcKeyAlias   | string      | 是   | 生成密钥别名。   |
| huksOptions   | HuksOptions | 是   | 生成密钥参数集。 |
| finishOptions | HuksOptions | 是   | 派生密钥参数集。 |

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

**示例：**

```ts
/* derive操作支持HKDF、pbdkf类型的密钥。
 *
 * 以下以HKDF256密钥的Promise操作使用为例
 */
function hkdfStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

var deriveHkdfInData = "deriveHkdfTestIndata";
var srcKeyAlias = "deriveHkdfKeyAlias";
var handle;
var HuksKeyDeriveKeySize = 32;

async function testDerive() {
    /* 集成生成密钥参数集 */
    var properties = new Array();
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
    var huksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }

    /* 生成密钥 */
    await huks.generateKey(srcKeyAlias, huksOptions).then((data) => {
        console.info('test generateKey data = ' + JSON.stringify(data));
    }).catch((err) => {
        console.info(`test init err: " + ${JSON.stringify(err)}`);
    });

    /* 调整init时的参数集 */
    huksOptions.properties.splice(0, 1, {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_HKDF,
    });
    huksOptions.properties.splice(3, 1, {
        tag: huks.HuksTag.HUKS_TAG_DERIVE_KEY_SIZE,
        value: HuksKeyDeriveKeySize,
    });

    var finishProperties = new Array();
    finishProperties[0] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
        value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT,
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
        value: hkdfStringToUint8Array(srcKeyAlias),
    }
    finishProperties[7] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
    }
    finishProperties[8] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB,
    }
    var finishOptions = {
        properties: finishProperties,
        inData: new Uint8Array(new Array())
    }

    /* 进行派生操作 */
    await huks.init(srcKeyAlias, huksOptions).then((data) => {
        console.log(`test init data: ${JSON.stringify(data)}`);
        handle = data.handle;
    }).catch((err) => {
        console.log(`test init err: " + ${JSON.stringify(err)}`);
    });
    huksOptions.inData = hkdfStringToUint8Array(deriveHkdfInData);
    await huks.update(handle, huksOptions).then((data) => {
        console.log(`test update data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.log(`test update err: " + ${JSON.stringify(err)}`);
    });
    await huks.finish(handle, finishOptions).then((data) => {
        console.log(`test finish data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.log('test finish err information: ' + JSON.stringify(err));
    });

    huksOptions.properties.splice(0, 1, {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_AES,
    });
    huksOptions.properties.splice(3, 1, {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
    });

    await huks.deleteKey(srcKeyAlias, huksOptions).then((data) => {
        console.log(`test deleteKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.log('test deleteKey err information: ' + JSON.stringify(err));
    });
}
```

### 密钥mac

基于密钥数据进行mac摘要所获得的一个哈希值。 

开发步骤如下：

1. 生成密钥。
2. 密钥mac。

**支持的密钥类型：**

HksInit对paramSet中参数的要求，其他三段式接口对paramSet无要求

| HUKS_TAG_ALGORITHM | HUKS_TAG_KEY_SIZE | HUKS_TAG_PURPOSE    | HUKS_TAG_DIGEST                                              | HUKS_TAG_PADDING | HUKS_TAG_BLOCK_MODE |
| ------------ | ---------- | ------------------- | ------------------------------------------------------------ | ---------- | ---------- |
| HUKS_ALG_HMAC | 【非必选】 | HUKS_KEY_PURPOSE_MAC | HUKS_DIGEST_SHA1  HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 | 【非必选】 | 【非必选】 |
| HUKS_ALG_SM3 | 【非必选】 | HUKS_KEY_PURPOSE_MAC | HUKS_DIGEST_SM3                                              | 【非必选】 | 【非必选】 |

> **说明**
>
> 存储的 keyAlias 密钥别名最大为64字节

在使用示例前，需要先了解几个预先定义的变量： 

| 参数名      | 类型        | 必填 | 说明           |
| ----------- | ----------- | ---- | -------------- |
| srcKeyAlias | string      | 是   | 生成密钥别名。 |
| huksOptions | HuksOptions | 是   | 密钥参数集。   |

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

**示例：**

```ts
/* mac操作支持HMAC、SM3类型的密钥。
 *
 * 以下以SM3 256密钥的Promise操作使用为例
 */
function macStringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

var srcKeyAlias = "sm3KeyAlias";
var hmacInData = 'sm3TestIndata';
var handle;

async function testMac() {
    /* 集成生成密钥参数集 */
    var properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_SM3,
    }
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_MAC,
    }
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SM3,
    }
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
    }
    var huksOptions = {
        properties:properties,
        inData:new Uint8Array(new Array())
    }

    /* 生成密钥 */
    await huks.generateKey(srcKeyAlias, huksOptions).then((data) => {
        console.info('test generateKey data = ' + JSON.stringify(data));
    }).catch((err) => {
        console.info(`test init err: " + ${JSON.stringify(err)}`);
    });

    /* 修改init时的参数集并进行mac操作 */
    huksOptions.properties.splice(3, 3);
    await huks.init(srcKeyAlias, huksOptions).then((data) => {
        console.info(`test init data: ${JSON.stringify(data)}`);
        handle = data.handle;
    }).catch((err) => {
        console.info(`test init err: " + ${JSON.stringify(err)}`);
    });
    huksOptions.inData = macStringToUint8Array(hmacInData);
    await huks.update(handle, huksOptions).then((data) => {
        console.info(`test init data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info(`test init err: " + ${JSON.stringify(err)}`);
    });
    huksOptions.inData = new Uint8Array(new Array());
    await huks.finish(handle, huksOptions).then((data) => {
        console.info(`test update data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test update err information: ' + JSON.stringify(err));
    });

    huksOptions.properties.splice(1, 0, {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
    });

    await huks.deleteKey(srcKeyAlias, huksOptions).then((data) => {
        console.info(`test deleteKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test deleteKey err information: ' + JSON.stringify(err));
    });
}
```

### AttestID

应用生成非对称密钥后，可以通过id attestation获取证书链，ID Attestation包含支持如下设备信息: BRAND, DEVICE, PRODUCT, SERIAL, IMEI, MEID, MANUFACTURER, MODEL, SOCID, UDID。

应用还可以通过key attestation获取证书链。

ID Attestation和Key Attestation只有拥有TEE环境的设备才具备该功能。

开发步骤如下：

1. 生成证书。
2. 获取证书信息。

**支持的密钥类型：**

RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, ECC224, ECC256, ECC384, ECC521, X25519

> **说明**
>
> 存储的 keyAlias 密钥别名最大为64字节

在使用示例前，需要先了解几个预先定义的变量： 

| 参数名   | 类型        | 必填 | 说明                                 |
| -------- | ----------- | ---- | ------------------------------------ |
| keyAlias | string      | 是   | 密钥别名，存放待获取证书密钥的别名。 |
| options  | HuksOptions | 是   | 用于获取证书时指定所需参数与数据。   |

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

**示例：**

```ts
/* 证书AttestID操作示例如下*/
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    var tmpUint8Array = new Uint8Array(arr);
    return tmpUint8Array;
}

function printLog(...data) {
    console.error(data.toString());
}

let securityLevel = stringToUint8Array('sec_level');
let challenge = stringToUint8Array('challenge_data');
let versionInfo = stringToUint8Array('version_info');
let udid = stringToUint8Array('udid');
let serial = stringToUint8Array('serial');
let deviceId = stringToUint8Array('device_id');
let idAliasString = "id attest";

/* 集成生成密钥参数集 & 生成密钥 */
function generateKey(alias) {
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA
    };
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
        value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT
    };
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
    };
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
    };
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    };
    properties[5] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PSS
    };
    properties[6] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_GENERATE_TYPE,
        value: huks.HuksKeyGenerateType.HUKS_KEY_GENERATE_TYPE_DEFAULT
    };
    properties[7] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB
    };
    let options = {
        properties: properties
    };
    huks.generateKey(alias, options);
}

async function attestId() {
    let aliasString = idAliasString;
    let aliasUint8 = stringToUint8Array(aliasString);

    /* 集成证书参数集 */
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,
        value: securityLevel
    };
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,
        value: challenge
    };
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,
        value: versionInfo
    };
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,
        value: aliasUint8
    };
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_UDID,
        value: udid
    };
    properties[5] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SERIAL,
        value: serial
    };
    properties[6] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_DEVICE,
        value: deviceId
    };
    let options = {
    properties: properties
    };

    generateKey(aliasString);
    huks.attestKey(aliasString, options, function (err, data) {
        printLog(`key attest result : ${JSON.stringify(data)}`);
    });
}
```

### AttestKey

应用生成非对称密钥后，可以通过Key attestation获取证书链。应用还可以通过id attestation获取证书链，其中公证书带有设备id等信息。

ID Attestation和Key Attestation只有拥有TEE环境的设备才具备该功能。

开发步骤如下：

1. 生成证书。
2. 获取证书信息。

**支持的密钥类型：**

RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, ECC224, ECC256, ECC384, ECC521, X25519

> **说明**
>
> 存储的 keyAlias 密钥别名最大为64字节

在使用示例前，需要先了解几个预先定义的变量： 

| 参数名   | 类型        | 必填 | 说明                                 |
| -------- | ----------- | ---- | ------------------------------------ |
| keyAlias | string      | 是   | 密钥别名，存放待获取证书密钥的别名。 |
| options  | HuksOptions | 是   | 用于获取证书时指定所需参数与数据。   |

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

**示例：**

```ts
/* 证书AttestKey操作示例如下*/
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    var tmpUint8Array = new Uint8Array(arr);
    return tmpUint8Array;
}

function printLog(...data) {
    console.error(data.toString());
}

let securityLevel = stringToUint8Array('sec_level');
let challenge = stringToUint8Array('challenge_data');
let versionInfo = stringToUint8Array('version_info');
let keyAliasString = "key attest";

/* 集成生成密钥参数集 & 生成密钥 */
function generateKey(alias) {
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA
    };
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
        value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT
    };
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
    };
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
    };
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    };
    properties[5] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PSS
    };
    properties[6] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_GENERATE_TYPE,
        value: huks.HuksKeyGenerateType.HUKS_KEY_GENERATE_TYPE_DEFAULT
    };
    properties[7] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB
    };
    let options = {
        properties: properties
    };
    huks.generateKey(alias, options);
}

async function attestKey() {
    let aliasString = keyAliasString;
    let aliasUint8 = stringToUint8Array(aliasString);

    /* 集成证书参数集 */
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,
        value: securityLevel
    };
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,
        value: challenge
    };
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,
        value: versionInfo
    };
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,
        value: aliasUint8
    };
        let options = {
        properties: properties
    };
    generateKey(aliasString);
    huks.attestKey(aliasString, options, function (err, data) {
        printLog(`key attest result : ${JSON.stringify(data)}`);
    });
}
```


