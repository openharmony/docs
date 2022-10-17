# HUKS开发指导

HUKS（OpenHarmony Universal KeyStore，OpenHarmony通用密钥库系统）向应用提供密钥库能力，包括密钥管理及密钥的密码学操作等功能。HUKS所管理的密钥可以由应用导入或者由应用调用HUKS接口生成。 

> **说明**
>
> 本开发指导基于API version 9，仅适用于eTS语言开发

### **前提条件**

在使用HUKS的接口开发前，需要引入HUKS模块

```ts
import huks from '@ohos.security.huks'
```

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
/* 以导出RSA512密钥及导入ECC256密钥为例 */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicExportKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback export`);
    try {
        await exportKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);
                if (data.outData !== null) {
                    exportKey = data.outData;
                }
            })
            .catch(error => {
                console.error(`callback: exportKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: exportKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function exportKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.exportKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicImportKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter promise importKeyItem`);
    try {
        await importKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: importKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: importKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: importKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function importKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.importKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

var srcKeyAlias = 'hukRsaKeyAlias';
var srcKeyAliasSecond = 'huksRsaKeyAliasSecond';
var exportKey;
var inputEccPair = new Uint8Array([
    0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00, 0xa5, 0xb8, 0xa3, 0x78, 0x1d, 0x6d, 0x76, 0xe0, 0xb3, 0xf5, 0x6f, 0x43,
    0x9d, 0xcf, 0x60, 0xf6, 0x0b, 0x3f, 0x64, 0x45, 0xa8, 0x3f, 0x1a, 0x96, 0xf1, 0xa1, 0xa4, 0x5d,
    0x3e, 0x2c, 0x3f, 0x13, 0xd7, 0x81, 0xf7, 0x2a, 0xb5, 0x8d, 0x19, 0x3d, 0x9b, 0x96, 0xc7, 0x6a,
    0x10, 0xf0, 0xaa, 0xbc, 0x91, 0x6f, 0x4d, 0xa7, 0x09, 0xb3, 0x57, 0x88, 0x19, 0x6f, 0x00, 0x4b,
    0xad, 0xee, 0x34, 0x35, 0xfb, 0x8b, 0x9f, 0x12, 0xa0, 0x83, 0x19, 0xbe, 0x6a, 0x6f, 0x63, 0x2a,
    0x7c, 0x86, 0xba, 0xca, 0x64, 0x0b, 0x88, 0x96, 0xe2, 0xfa, 0x77, 0xbc, 0x71, 0xe3, 0x0f, 0x0f,
    0x9e, 0x3c, 0xe5, 0xf9]);

async function testImportExport() {
    /* 集成生成密钥参数集 */
    var exportProperties = new Array();
    exportProperties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA,
    }
    exportProperties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value:
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
    }
    exportProperties[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
    }
    exportProperties[3] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB,
    }
    exportProperties[4] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
    }
    exportProperties[5] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
    }
    var huksOptions = {
        properties: exportProperties,
        inData: new Uint8Array(new Array())
    }

    /* 生成密钥 */
    await publicGenKeyFunc(srcKeyAlias, huksOptions);

    /* 导出密钥 */
    await publicExportKeyFunc(srcKeyAlias, huksOptions);

    /* 集成导入密钥参数集 */
    var importProperties = new Array();
    importProperties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_ECC
    };
    importProperties[1] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
    };
    importProperties[2] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_UNWRAP
    };
    importProperties[3] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    };
    importProperties[4] = {
        tag: huks.HuksTag.HUKS_TAG_IMPORT_KEY_TYPE,
        value: huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR,
    };
    var importOptions = {
        properties: importProperties,
        inData: inputEccPair
    };

    /* 导入密钥 */
    await publicImportKeyFunc(srcKeyAliasSecond, importOptions);

    await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
    await publicDeleteKeyFunc(srcKeyAliasSecond, importOptions);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('testImportExport')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(()=>{
                testImportExport();
            })
        }
        .width('100%')
        .height('100%')
    }
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
import huks from '@ohos.security.huks';

async function publicExportKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback export`);
    try {
        await exportKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);
                if (data.outData !== null) {
                    exportKey = data.outData;
                }
            })
            .catch(error => {
                console.error(`callback: exportKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: exportKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function exportKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.exportKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicImportKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter promise importKeyItem`);
    try {
        await importKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: importKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: importKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: importKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function importKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.importKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicImportWrappedKey(keyAlias:string, wrappingKeyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback importWrappedKeyItem`);
    try {
        await importWrappedKeyItem(keyAlias, wrappingKeyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: importWrappedKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: importWrappedKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: importWrappedKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function importWrappedKeyItem(keyAlias:string, wrappingKeyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.importWrappedKeyItem(keyAlias, wrappingKeyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

var importAlias = "importAlias";
var wrapAlias = "wrappingKeyAlias";
var exportKey;

var inputEccPair = new Uint8Array([
    0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00, 0xa5, 0xb8, 0xa3, 0x78, 0x1d, 0x6d, 0x76, 0xe0, 0xb3, 0xf5, 0x6f, 0x43,
    0x9d, 0xcf, 0x60, 0xf6, 0x0b, 0x3f, 0x64, 0x45, 0xa8, 0x3f, 0x1a, 0x96, 0xf1, 0xa1, 0xa4, 0x5d,
    0x3e, 0x2c, 0x3f, 0x13, 0xd7, 0x81, 0xf7, 0x2a, 0xb5, 0x8d, 0x19, 0x3d, 0x9b, 0x96, 0xc7, 0x6a,
    0x10, 0xf0, 0xaa, 0xbc, 0x91, 0x6f, 0x4d, 0xa7, 0x09, 0xb3, 0x57, 0x88, 0x19, 0x6f, 0x00, 0x4b,
    0xad, 0xee, 0x34, 0x35, 0xfb, 0x8b, 0x9f, 0x12, 0xa0, 0x83, 0x19, 0xbe, 0x6a, 0x6f, 0x63, 0x2a,
    0x7c, 0x86, 0xba, 0xca, 0x64, 0x0b, 0x88, 0x96, 0xe2, 0xfa, 0x77, 0xbc, 0x71, 0xe3, 0x0f, 0x0f,
    0x9e, 0x3c, 0xe5, 0xf9]);

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
var huksOptions = {
    properties: properties,
    inData: inputEccPair
};

var importProperties = new Array();
importProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
};
importProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
};
importProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
};
importProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
};
importProperties[4] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
};
importProperties[5] = {
    tag: huks.HuksTag.HUKS_TAG_UNWRAP_ALGORITHM_SUITE,
    value: huks.HuksUnwrapSuite.HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING
};
var importOptions = {
    properties: importProperties,
    inData: new Uint8Array(new Array())
};

async function importWrappedKeyItemTest() {

    console.info(`enter ImportWrapKey test`);
    await publicImportKeyFunc(wrapAlias, huksOptions);

    await publicExportKeyFunc(wrapAlias, huksOptions);

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
        0x5b, 0x00, 0x00, 0x00, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x02,
        0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0xc0,
        0xfe, 0x1c, 0x67, 0xde, 0x86, 0x0e, 0xfb, 0xaf, 0xb5, 0x85, 0x52, 0xb4, 0x0e, 0x1f, 0x6c, 0x6c,
        0xaa, 0xc5, 0xd9, 0xd2, 0x4d, 0xb0, 0x8a, 0x72, 0x24, 0xa1, 0x99, 0xaf, 0xfc, 0x3e, 0x55, 0x5a,
        0xac, 0x99, 0x3d, 0xe8, 0x34, 0x72, 0xb9, 0x47, 0x9c, 0xa6, 0xd8, 0xfb, 0x00, 0xa0, 0x1f, 0x9f,
        0x7a, 0x41, 0xe5, 0x44, 0x3e, 0xb2, 0x76, 0x08, 0xa2, 0xbd, 0xe9, 0x41, 0xd5, 0x2b, 0x9e, 0x10,
        0x00, 0x00, 0x00, 0xbf, 0xf9, 0x69, 0x41, 0xf5, 0x49, 0x85, 0x31, 0x35, 0x14, 0x69, 0x12, 0x57,
        0x9c, 0xc8, 0xb7, 0x10, 0x00, 0x00, 0x00, 0x2d, 0xb7, 0xf1, 0x5a, 0x0f, 0xb8, 0x20, 0xc5, 0x90,
        0xe5, 0xca, 0x45, 0x84, 0x5c, 0x08, 0x08, 0x10, 0x00, 0x00, 0x00, 0x43, 0x25, 0x1b, 0x2f, 0x5b,
        0x86, 0xd8, 0x87, 0x04, 0x4d, 0x38, 0xc2, 0x65, 0xcc, 0x9e, 0xb7, 0x20, 0x00, 0x00, 0x00, 0xf4,
        0xe8, 0x93, 0x28, 0x0c, 0xfa, 0x4e, 0x11, 0x6b, 0xe8, 0xbd, 0xa8, 0xe9, 0x3f, 0xa7, 0x8f, 0x2f,
        0xe3, 0xb3, 0xbf, 0xaf, 0xce, 0xe5, 0x06, 0x2d, 0xe6, 0x45, 0x5d, 0x19, 0x26, 0x09, 0xe7, 0x10,
        0x00, 0x00, 0x00, 0xf4, 0x1e, 0x7b, 0x01, 0x7a, 0x84, 0x36, 0xa4, 0xa8, 0x1c, 0x0d, 0x3d, 0xde,
        0x57, 0x66, 0x73, 0x10, 0x00, 0x00, 0x00, 0xe3, 0xff, 0x29, 0x97, 0xad, 0xb3, 0x4a, 0x2c, 0x50,
        0x08, 0xb5, 0x68, 0xe1, 0x90, 0x5a, 0xdc, 0x10, 0x00, 0x00, 0x00, 0x26, 0xae, 0xdc, 0x4e, 0xa5,
        0x6e, 0xb1, 0x38, 0x14, 0x24, 0x47, 0x1c, 0x41, 0x89, 0x63, 0x11, 0x04, 0x00, 0x00, 0x00, 0x20,
        0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x0b, 0xcb, 0xa9, 0xa8, 0x5f, 0x5a, 0x9d, 0xbf, 0xa1,
        0xfc, 0x72, 0x74, 0x87, 0x79, 0xf2, 0xf4, 0x22, 0x0c, 0x8a, 0x4d, 0xd8, 0x7e, 0x10, 0xc8, 0x44,
        0x17, 0x95, 0xab, 0x3b, 0xd2, 0x8f, 0x0a
    ]);

    importOptions.inData = inputKey;
    await publicImportWrappedKey(importAlias, wrapAlias, importOptions);

    await publicDeleteKeyFunc(wrapAlias, huksOptions);
    await publicDeleteKeyFunc(importAlias, importOptions);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('importWrappedKeyItemTest')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(()=>{
                importWrappedKeyItemTest();
            })
        }
        .width('100%')
        .height('100%')
    }
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
| HUKS_ALG_RSA                 （支持长度：  HUKS_RSA_KEY_SIZE_512  HUKS_RSA_KEY_SIZE_768  HUKS_RSA_KEY_SIZE_1024  HUKS_RSA_KEY_SIZE_2048  HUKS_RSA_KEY_SIZE_3072  HUKS_RSA_KEY_SIZE_4096） | HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT | HUKS_DIGEST_SHA1 HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 | HUKS_PADDING_NONE  HUKS_PADDING_PKCS1_V1_5  HUKS_PADDING_OAEP | HUKS_MODE_ECB                               | 【非必选】  |

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
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData) {
    var dataString = '';
    for (var i = 0; i < fileData.length; i++) {
        dataString += String.fromCharCode(fileData[i]);
    }
    return dataString;
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicInitFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter promise doInit`);
    try {
        await huks.initSession(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
                handle = data.handle;
            })
            .catch(error => {
                console.error(`promise: doInit key failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`promise: doInit input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

async function publicUpdateFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doUpdate`);
    try {
        await updateSession(handle, huksOptions)
            .then ((data) => {
                console.info(`callback: doUpdate success, data = ${JSON.stringify(data)}`);
                updateResult = Array.from(data.outData);
            })
            .catch(error => {
                console.error(`callback: doUpdate failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doUpdate input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function updateSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.updateSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicFinishFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doFinish`);
    try {
        await finishSession(handle, huksOptions)
            .then ((data) => {
                finishOutData = Uint8ArrayToString(new Uint8Array(updateResult));
                console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: doFinish failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doFinish input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function finishSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.finishSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

var IV = '0000000000000000';
var cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string';
var srcKeyAlias = 'huksCipherSm4SrcKeyAlias';
var encryptUpdateResult = new Array();
var handle;
var updateResult = new Array();
var finishOutData;

async function testSm4Cipher() {
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
        value: StringToUint8Array(IV),
    }
    var encryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* 生成密钥 */
    await publicGenKeyFunc(srcKeyAlias, huksOptions);

    /* 进行密钥加密操作 */
    await publicInitFunc(srcKeyAlias, encryptOptions);
    
    encryptOptions.inData = StringToUint8Array(cipherInData);
    await publicUpdateFunc(handle, encryptOptions);
    encryptUpdateResult = updateResult;

    encryptOptions.inData = new Uint8Array(new Array());
    await publicFinishFunc(handle, encryptOptions);
    if (finishOutData === cipherInData) {
        console.info('test finish encrypt err ');
    } else {
        console.info('test finish encrypt success');
    }

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
    await publicInitFunc(srcKeyAlias, decryptOptions);

    decryptOptions.inData = new Uint8Array(encryptUpdateResult);
    await publicUpdateFunc(handle, decryptOptions);

    decryptOptions.inData = new Uint8Array(new Array());
    await publicFinishFunc(handle, decryptOptions);
    if (finishOutData === cipherInData) {
        console.info('test finish decrypt success ');
    } else {
        console.info('test finish decrypt err');
    }

    await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('testSm4Cipher')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(()=>{
                testSm4Cipher();
            })
        }
        .width('100%')
        .height('100%')
    }
}
```

**示例2：**

```ts
/* Cipher操作支持RSA、AES、SM4类型的密钥。
 *
 * 以下以AES128 GCM密钥的Promise操作使用为例
 */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData) {
    var dataString = '';
    for (var i = 0; i < fileData.length; i++) {
        dataString += String.fromCharCode(fileData[i]);
    }
    return dataString;
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicInitFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter promise doInit`);
    try {
        await huks.initSession(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
                handle = data.handle;
            })
            .catch(error => {
                console.error(`promise: doInit key failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`promise: doInit input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

async function publicUpdateFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doUpdate`);
    try {
        await updateSession(handle, huksOptions)
            .then ((data) => {
                console.info(`callback: doUpdate success, data = ${JSON.stringify(data)}`);
                updateResult = Array.from(data.outData);
            })
            .catch(error => {
                console.error(`callback: doUpdate failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doUpdate input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function updateSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.updateSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicFinishFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doFinish`);
    try {
        await finishSession(handle, huksOptions)
            .then ((data) => {
                updateResult = updateResult.concat(Array.from(data.outData));
                console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: doFinish failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doFinish input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function finishSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.finishSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

var AAD = '0000000000000000';
var NONCE = '000000000000';
var AEAD = '0000000000000000';
var cipherInData = 'Hks_AES_Cipher_Test_00000000000000000000000000000000000000000000000000000_string';
var srcKeyAlias = 'huksCipherSm4SrcKeyAlias';
var updateResult = new Array();
var encryptUpdateResult = new Array();
var decryptUpdateResult = new Array();
var handle;
var finishOutData;

async function testAesCipher() {
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
    var huksOptions = {
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
        value: StringToUint8Array(AAD),
    }
    propertiesEncrypt[7] = {
        tag: huks.HuksTag.HUKS_TAG_NONCE,
        value: StringToUint8Array(NONCE),
    }
    propertiesEncrypt[8] = {
        tag: huks.HuksTag.HUKS_TAG_AE_TAG,
        value: StringToUint8Array(AEAD),
    }
    var encryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* 生成密钥 */
    await publicGenKeyFunc(srcKeyAlias, huksOptions);

    /* 进行密钥加密操作 */
    await publicInitFunc(srcKeyAlias, encryptOptions);

    encryptOptions.inData = StringToUint8Array(cipherInData.slice(0,64));
    await publicUpdateFunc(handle, encryptOptions);
    encryptUpdateResult = updateResult;

    encryptOptions.inData = StringToUint8Array(cipherInData.slice(64,80));
    await publicFinishFunc(handle, encryptOptions);
    encryptUpdateResult = updateResult;
    finishOutData = Uint8ArrayToString(new Uint8Array(encryptUpdateResult));
    if (finishOutData === cipherInData) {
        console.info('test finish encrypt err ');
    } else {
        console.info('test finish encrypt success');
    }

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
    await publicInitFunc(srcKeyAlias, decryptOptions);

    decryptOptions.inData = new Uint8Array(encryptUpdateResult.slice(0,64));
    await publicUpdateFunc(handle, decryptOptions);
    decryptUpdateResult = updateResult;

    decryptOptions.inData = new Uint8Array(encryptUpdateResult.slice(64,encryptUpdateResult.length));
    await publicFinishFunc(handle, decryptOptions);
    decryptUpdateResult = updateResult;
    finishOutData = Uint8ArrayToString(new Uint8Array(decryptUpdateResult));
    if (finishOutData === cipherInData) {
        console.info('test finish decrypt success ');
    } else {
        console.info('test finish decrypt err');
    }

    await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('testAesCipher')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(()=>{
                testAesCipher();
            })
        }
        .width('100%')
        .height('100%')
    }
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

| 参数名            | 类型        | 必填 | 说明                     |
| ----------------- | ----------- | ---- | ------------------------ |
| generateKeyAlias  | string      | 是   | 生成密钥别名。           |
| importKeyAlias    | string      | 是   | 导入密钥别名。           |
| genrateKeyOptions | HuksOptions | 是   | 用于存放生成key所需TAG。 |
| signOptions       | HuksOptions | 是   | 用于存放签名key所需TAG。 |
| verifyOptions     | HuksOptions | 是   | 用于存放验签key所需TAG。 |

关于接口的具体信息，可在[API参考文档](../reference/apis/js-apis-huks.md)中查看。

**示例：**

```ts
/* Sign/Verify操作支持RSA、ECC、SM2、ED25519、DSA类型的密钥。
 *
 * 以下以SM2密钥的Callback操作使用为例
 */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicInitFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doInit`);
    try {
        await initSession(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback1: doInit success, data = ${JSON.stringify(data)}`);
                handle = data.handle;
            })
            .catch((error) => {
                console.error(`callback1: doInit failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doInit input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function initSession(keyAlias:string, huksOptions:huks.HuksOptions) : Promise<huks.HuksSessionHandle> {
    return new Promise((resolve, reject) => {
        try {
            huks.initSession(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicUpdateFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doUpdate`);
    try {
        await updateSession(handle, huksOptions)
            .then ((data) => {
                console.info(`callback: doUpdate success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: doUpdate failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doUpdate input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function updateSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.updateSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicFinishFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doFinish`);
    try {
        await finishSession(handle, huksOptions)
            .then ((data) => {
                finishOutData = data.outData;;
                console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: doFinish failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doFinish input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function finishSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.finishSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicExportKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback export`);
    try {
        await exportKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);
                exportKey = data.outData;
            })
            .catch(error => {
                console.error(`callback: exportKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: exportKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function exportKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.exportKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicImportKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter promise importKeyItem`);
    try {
        await importKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: importKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: importKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: importKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function importKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.importKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

var signVerifyInData = 'signVerifyInDataForTest';
var generateKeyAlias = 'generateKeyAliasForTest';
var importKeyAlias = 'importKeyAliasForTest';
var handle;
var exportKey;
var finishOutData;

/* 集成生成密钥参数集 */
var generateKeyProperties = new Array();
generateKeyProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2,
}
generateKeyProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY,
}
generateKeyProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256,
}
generateKeyProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3,
}
var genrateKeyOptions = {
    properties: generateKeyProperties,
    inData: new Uint8Array(new Array())
}

/* 集成签名参数集 */
var signProperties = new Array();
signProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2,
}
signProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
}
signProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3,
}
signProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256,
}
var signOptions = {
    properties: signProperties,
    inData: new Uint8Array(new Array())
}

/* 集成验签参数集 */
var verifyProperties = new Array();
verifyProperties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2,
}
verifyProperties[1] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
}
verifyProperties[2] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3,
}
verifyProperties[3] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256,
}
var verifyOptions = {
    properties: verifyProperties,
    inData: new Uint8Array(new Array())
}

async function testSm2SignVerify() {
    /* 生成密钥 */
    await publicGenKeyFunc(generateKeyAlias, genrateKeyOptions);

    /* 签名 */
    var signHandle;
    var signFinishOutData;
    await publicInitFunc(generateKeyAlias, signOptions);

    signHandle = handle;
    signOptions.inData = StringToUint8Array(signVerifyInData)
    await publicUpdateFunc(signHandle, signOptions);

    signOptions.inData = new Uint8Array(new Array());
    await publicFinishFunc(signHandle, signOptions);
    signFinishOutData = finishOutData;

    /* 导出密钥 */
    await publicExportKeyFunc(generateKeyAlias, genrateKeyOptions);

    /* 导入密钥 */
    verifyOptions.inData = exportKey;
    await publicImportKeyFunc(importKeyAlias, verifyOptions);

    /* 验证签名 */
    var verifyHandle;
    await publicInitFunc(importKeyAlias, verifyOptions);

    verifyHandle = handle;

    verifyOptions.inData = StringToUint8Array(signVerifyInData)
    await publicUpdateFunc(verifyHandle, verifyOptions);

    verifyOptions.inData = signFinishOutData;
    await publicFinishFunc(verifyHandle, verifyOptions);

    await publicDeleteKeyFunc(generateKeyAlias, genrateKeyOptions);
    await publicDeleteKeyFunc(importKeyAlias, genrateKeyOptions);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('testSm2SignVerify')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(()=>{
                testSm2SignVerify();
            })
        }
        .width('100%')
        .height('100%')
    }
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
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicInitFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doInit`);
    try {
        await initSession(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback1: doInit success, data = ${JSON.stringify(data)}`);
                handle = data.handle;
            })
            .catch((error) => {
                console.error(`callback1: doInit failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doInit input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function initSession(keyAlias:string, huksOptions:huks.HuksOptions) : Promise<huks.HuksSessionHandle> {
    return new Promise((resolve, reject) => {
        try {
            huks.initSession(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicUpdateFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doUpdate`);
    try {
        await updateSession(handle, huksOptions)
            .then ((data) => {
                console.info(`callback: doUpdate success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: doUpdate failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doUpdate input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function updateSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.updateSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicFinishFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doFinish`);
    try {
        await finishSession(handle, huksOptions)
            .then ((data) => {
                console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: doFinish failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doFinish input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function finishSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.finishSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicExportKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback export`);
    try {
        await exportKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);
                exportKey = data.outData;
            })
            .catch(error => {
                console.error(`callback: exportKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: exportKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function exportKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.exportKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

var srcKeyAliasFirst = "AgreeX25519KeyFirstAlias";
var srcKeyAliasSecond = "AgreeX25519KeySecondAlias";
var agreeX25519InData = 'AgreeX25519TestIndata';
var handle;
var exportKey;
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
    await publicGenKeyFunc(srcKeyAliasFirst, HuksOptions);
    await publicGenKeyFunc(srcKeyAliasSecond, HuksOptions);

    await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
    exportKeyFrist = exportKey;
    await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
    exportKeySecond = exportKey;

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
    var finishOptionsFrist = {
        properties: finishProperties,
        inData: StringToUint8Array(agreeX25519InData)
    }

    /* 对第一个密钥进行协商 */
    await publicInitFunc(srcKeyAliasFirst, HuksOptions);
    HuksOptions.inData = exportKeySecond;
    await publicUpdateFunc(handle, HuksOptions);
    await publicFinishFunc(handle, finishOptionsFrist);

    /* 集成第二个协商参数集 */
    var finishOptionsSecond = {
        properties: finishProperties,
        inData: StringToUint8Array(agreeX25519InData)
    }
    finishOptionsSecond.properties.splice(6, 1, {
        tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
        value: StringToUint8Array(srcKeyAliasSecond + 'final'),
    })

    /* 对第二个密钥进行协商 */
    await publicInitFunc(srcKeyAliasSecond, HuksOptions);
    HuksOptions.inData = exportKeyFrist;
    await publicUpdateFunc(handle, HuksOptions);
    await publicFinishFunc(handle, finishOptionsSecond);


    await publicDeleteKeyFunc(srcKeyAliasFirst, HuksOptions);
    await publicDeleteKeyFunc(srcKeyAliasSecond, HuksOptions);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('testAgree')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(()=>{
              testAgree();
            })
        }
        .width('100%')
        .height('100%')
    }
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
> HUKS_ALG_AES的SIZE需要满足：派生后的密钥长度（转换成bit）>=选择的HUKS_TAG_KEY_SIZE
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
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicInitFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter promise doInit`);
    try {
        await huks.initSession(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
                handle = data.handle;
            })
            .catch(error => {
                console.error(`promise: doInit key failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`promise: doInit input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

async function publicUpdateFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doUpdate`);
    try {
        await updateSession(handle, huksOptions)
            .then ((data) => {
                console.info(`callback: doUpdate success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: doUpdate failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doUpdate input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function updateSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.updateSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicFinishFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doFinish`);
    try {
        await finishSession(handle, huksOptions)
            .then ((data) => {
                console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: doFinish failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doFinish input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function finishSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.finishSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
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
    await publicGenKeyFunc(srcKeyAlias, huksOptions);

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
    var finishOptions = {
        properties: finishProperties,
        inData: new Uint8Array(new Array())
    }

    /* 进行派生操作 */
    await publicInitFunc(srcKeyAlias, huksOptions);

    huksOptions.inData = StringToUint8Array(deriveHkdfInData);
    await publicUpdateFunc(handle, huksOptions);
    await publicFinishFunc(handle, finishOptions);

    huksOptions.properties.splice(0, 1, {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_AES,
    });
    huksOptions.properties.splice(3, 1, {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
    });

    await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('testDerive')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(()=>{
                testDerive();
            })
        }
        .width('100%')
        .height('100%')
    }
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
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicInitFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doInit`);
    try {
        await initSession(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback1: doInit success, data = ${JSON.stringify(data)}`);
                handle = data.handle;
            })
            .catch((error) => {
                console.error(`callback1: doInit failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doInit input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function initSession(keyAlias:string, huksOptions:huks.HuksOptions) : Promise<huks.HuksSessionHandle> {
    return new Promise((resolve, reject) => {
        try {
            huks.initSession(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicUpdateFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doUpdate`);
    try {
        await updateSession(handle, huksOptions)
            .then ((data) => {
                console.info(`callback: doUpdate success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: doUpdate failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doUpdate input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function updateSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.updateSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicFinishFunc(handle:number, huksOptions:huks.HuksOptions) {
    console.info(`enter callback doFinish`);
    try {
        await finishSession(handle, huksOptions)
            .then ((data) => {
                console.info(`callback: doFinish success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: doFinish failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: doFinish input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function finishSession(handle:number, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult> {
    return new Promise((resolve, reject) => {
        try {
            huks.finishSession(handle, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
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
    await publicGenKeyFunc(srcKeyAlias, huksOptions);

    /* 修改init时的参数集并进行mac操作 */
    huksOptions.properties.splice(3, 3);
    await publicInitFunc(srcKeyAlias, huksOptions);
    huksOptions.inData = StringToUint8Array(hmacInData);
    await publicUpdateFunc(handle, huksOptions);
    huksOptions.inData = new Uint8Array(new Array());
    await publicFinishFunc(handle, huksOptions);
    
    huksOptions.properties.splice(1, 0, {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
    });
    await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('testMac')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(()=>{
                testMac();
            })
        }
        .width('100%')
        .height('100%')
    }
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
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicAttestKey(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback attestKeyItem`);
    try {
        await attestKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: attestKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: attestKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: attestKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function attestKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult>{
    return new Promise((resolve, reject) => {
        try {
            huks.attestKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

var securityLevel = StringToUint8Array('sec_level');
var challenge = StringToUint8Array('challenge_data');
var versionInfo = StringToUint8Array('version_info');
var udid = StringToUint8Array('udid');
var serial = StringToUint8Array('serial');
var deviceId = StringToUint8Array('device_id');
var idAliasString = "id attest";

async function testAttestId() {
    var aliasString = idAliasString;
    var aliasUint8 = StringToUint8Array(aliasString);

    /* 集成生成密钥参数集 & 生成密钥 */
    var properties = new Array();
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
    var options = {
        properties: properties
    };
    await publicGenKeyFunc(aliasString, options);

    /* 集成证书参数集 */
    var attestProperties = new Array();
    attestProperties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,
        value: securityLevel
    };
    attestProperties[1] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,
        value: challenge
    };
    attestProperties[2] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,
        value: versionInfo
    };
    attestProperties[3] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,
        value: aliasUint8
    };
    attestProperties[4] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_UDID,
        value: udid
    };
    attestProperties[5] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SERIAL,
        value: serial
    };
    attestProperties[6] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_DEVICE,
        value: deviceId
    };
    var huksOptions = {
        properties: attestProperties
    };

    await publicAttestKey(aliasString, huksOptions);

    await publicDeleteKeyFunc(aliasString, options);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('testAttestId')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(()=>{
                testAttestId();
            })
        }
        .width('100%')
        .height('100%')
    }
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
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

async function publicGenKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback generateKeyItem`);
    try {
        await generateKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: generateKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function generateKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.generateKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicAttestKey(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback attestKeyItem`);
    try {
        await attestKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: attestKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: attestKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: attestKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function attestKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) : Promise<huks.HuksReturnResult>{
    return new Promise((resolve, reject) => {
        try {
            huks.attestKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias:string, huksOptions:huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then ((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias:string, huksOptions:huks.HuksOptions) {
    return new Promise((resolve, reject) => {
        try {
            huks.deleteKeyItem(keyAlias, huksOptions, function (error, data) {
                if (error) {
                    reject(error);
                } else {
                    resolve(data);
                }
            });
        } catch (error) {
            throw(error);
        }
    });
}

var securityLevel = StringToUint8Array('sec_level');
var challenge = StringToUint8Array('challenge_data');
var versionInfo = StringToUint8Array('version_info');
var keyAliasString = "key attest";

async function testAttestKey() {
    var aliasString = keyAliasString;
    var aliasUint8 = StringToUint8Array(aliasString);

    var properties = new Array();
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
    var options = {
        properties: properties
    };
    await publicGenKeyFunc(aliasString, options);

    /* 集成证书参数集 */
    var attestProperties = new Array();
    attestProperties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO,
        value: securityLevel
    };
    attestProperties[1] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_CHALLENGE,
        value: challenge
    };
    attestProperties[2] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_VERSION_INFO,
        value: versionInfo
    };
    attestProperties[3] = {
        tag: huks.HuksTag.HUKS_TAG_ATTESTATION_ID_ALIAS,
        value: aliasUint8
    };
    var huksOptions = {
        properties: attestProperties
    };

    await publicAttestKey(aliasString, huksOptions);

    await publicDeleteKeyFunc(aliasString, options);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('testAttestKey')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(()=>{
                testAttestKey();
            })
        }
        .width('100%')
        .height('100%')
    }
}
```


