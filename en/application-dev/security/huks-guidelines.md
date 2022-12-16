# HUKS Development

OpenHarmony Universal KeyStore (HUKS) provides KeyStore (KS) capabilities for applications, including key management and key cryptography operations. HUKS also provides APIs for applications to import or generate keys.

> **NOTE**<br>
>
> This document is based on API version 9 and applies only to ArkTS development.

### **Prerequisites**

The HUKS module must have been imported.

```ts
import huks from '@ohos.security.huks'
```

### Generating a Key

Generate a key for an application by specifying the alias and key parameters.

> **NOTE**
>
> 1. When a key is used if the parameters passed in does not comply with the parameters passed in during the key generation, the parameter verification will fail. 
>
> 2. If an optional parameter required by the algorithm is not passed in during the key generation process, it must be passed in when the key is used.

**Supported Key Types**

The following lists the mandatory parameters for key generation, including the key algorithm, key length, and key usage.

| HUKS_ALG_ALGORITHM | HUKS_ALG_KEY_SIZE                                            | HUKS_ALG_PURPOSE                                             |
| ------------------ | :----------------------------------------------------------- | ------------------------------------------------------------ |
| HUKS_ALG_RSA       | HUKS_RSA_KEY_SIZE_512 HUKS_RSA_KEY_SIZE_768  HUKS_RSA_KEY_SIZE_1024  HUKS_RSA_KEY_SIZE_2048  HUKS_RSA_KEY_SIZE_3072 HUKS_RSA_KEY_SIZE_4096 | HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY |
| HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128 HUKS_AES_KEY_SIZE_192 HUKS_AES_KEY_SIZE_256 | HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT HUKS_KEY_PURPOSE_DERIVE |
| HUKS_ALG_ECC       | HUKS_ECC_KEY_SIZE_224, HUKS_ECC_KEY_SIZE_256, HUKS_ECC_KEY_SIZE_384, HUKS_ECC_KEY_SIZE_521| HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY               |
| HUKS_ALG_X25519    | HUKS_CURVE25519_KEY_SIZE_256                                 | HUKS_KEY_PURPOSE_AGREE                                       |
| HUKS_ALG_ED25519   | HUKS_CURVE25519_KEY_SIZE_256                                 | HUKS_KEY_PURPOSE_SIGN   HUKS_KEY_PURPOSE_VERIFY              |
| HUKS_ALG_DSA       | HUKS_RSA_KEY_SIZE_1024                                       | HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY               |
| HUKS_ALG_DH        | HUKS_DH_KEY_SIZE_2048, HUKS_DH_KEY_SIZE_3072, HUKS_DH_KEY_SIZE_4096| HUKS_KEY_PURPOSE_AGREE                                       |
| HUKS_ALG_ECDH      | HUKS_ECC_KEY_SIZE_224, HUKS_ECC_KEY_SIZE_256, HUKS_ECC_KEY_SIZE_384, HUKS_ECC_KEY_SIZE_521| HUKS_KEY_PURPOSE_AGREE                                       |
| HUKS_ALG_SM2       | HUKS_SM2_KEY_SIZE_256                                        | HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY               |
| HUKS_ALG_SM4       | HUKS_SM4_KEY_SIZE_128                                        | HUKS_KEY_PURPOSE_ENCRYPT or HUKS_KEY_PURPOSE_DECRYPT          |

Before you get started, understand the following variables:

| Parameter          | Type       | Mandatory| Description                                                        |
| ---------------- | ----------- | ---- | ------------------------------------------------------------ |
| genKeyAlias      | string      | Yes  | Alias of the key generated.                                            |
| genKeyProperties | HuksOptions | Yes  | Tags required for generating the key. The key algorithm, key usage, and key length are mandatory.|

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

```ts
/* Generate an ECC key of 256 bits. */
let keyAlias = 'keyAlias';
let properties = new Array();
// Mandatory parameter.
properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ECC
};
// Mandatory parameter.
properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
};
// Mandatory parameter.
properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value:
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
};
// Optional parameter.
properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
};
let options = {
    properties: properties
};
try {
    huks.generateKeyItem(keyAlias, options, function (error, data) {
        if (error) {
            console.error(`callback: generateKeyItem failed, code: ${error.code}, msg: ${error.message}`);
        } else {
            console.info(`callback: generateKeyItem key success`);
        }
    });
} catch (error) {
    console.error(`callback: generateKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
}
```



### Key Import and Export

The **HUKS** module allows the public key of its own asymmetric key (public and private key pair) to be exported based on the key alias.

The **HUKS** module also supports import of external keys. Except the public keys of asymmetric keys, the keys imported into the HUKS cannot be exported in their lifecycle. If the alias of the key to be imported already exists in HUKS, the newly imported key will overwrite the existing one.

The development procedure is as follows:

1. Generate a key.
2. Export the key.
3. Import the key.

**Supported Types of Keys to Import**

AES128, AES192, AES256, RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, HmacSHA1, HmacSHA224, HmacSHA256, HmacSHA384, HmacSHA512, ECC224, ECC256, ECC384, ECC521, Curve25519, DSA, SM2, SM3, SM4

**Supported Types of Keys to Export**

RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, ECC224, ECC256, ECC384, ECC521, Curve25519, DSA, SM2

> **NOTE**<br>
>
> The key alias cannot exceed 64 bytes.

Before you get started, understand the following variables:

| Parameter        | Type       | Mandatory| Description                    |
| -------------- | ----------- | ---- | ------------------------ |
| exportKeyAlias | string      | Yes  | Alias of the key to generate.          |
| importKeyAlias | string      | Yes  | Alias of the key to import.          |
| huksOptions    | HuksOptions | Yes  | Tags required for generating the key.|
| encryptOptions | HuksOptions | Yes  | Tags required for importing the key.|

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

```ts
/* Export an RSA512 key and import DH2048, RSA512, x25519, and ECC256 keys.*/
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData) {
    let dataString = '';
    for (let i = 0; i < fileData.length; i++) {
        dataString += String.fromCharCode(fileData[i]);
    }
    return dataString;
}

function Uint32ToUint8(value) {
    let arr = new Uint8Array(4 * value.length);
    for (let i = 0, j = value.length; i < j; i++) {
        arr[i * 4+3] = (value[i] >> 24) & 0xFF;
        arr[i * 4+2] = (value[i] >> 16) & 0xFF;
        arr[i * 4+1] = (value[i] >> 8) & 0xFF;
        arr[i*4] = (value[i]) & 0xFF;
    }
    return arr;
}

async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
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

function generateKeyItem(keyAlias: string, huksOptions: huks.HuksOptions) {
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
            throw (error);
        }
    });
}

async function publicExportKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter callback export`);
    try {
        await exportKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: exportKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: exportKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: exportKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function exportKeyItem(keyAlias: string, huksOptions: huks.HuksOptions): Promise<huks.HuksReturnResult> {
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
            throw (error);
        }
    });
}

async function publicImportKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter promise importKeyItem`);
    try {
        await importKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: importKeyItem success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: importKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: importKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function importKeyItem(keyAlias: string, huksOptions: huks.HuksOptions) {
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
            throw (error);
        }
    });
}

async function publicDeleteKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
    console.info(`enter callback deleteKeyItem`);
    try {
        await deleteKeyItem(keyAlias, huksOptions)
            .then((data) => {
                console.info(`callback: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
            })
            .catch(error => {
                console.error(`callback: deleteKeyItem failed, code: ${error.code}, msg: ${error.message}`);
            });
    } catch (error) {
        console.error(`callback: deleteKeyItem input arg invalid, code: ${error.code}, msg: ${error.message}`);
    }
}

function deleteKeyItem(keyAlias: string, huksOptions: huks.HuksOptions) {
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
            throw (error);
        }
    });
}

// Export the RSA key.
async function testExportRsa() {
    let exportKeyAlias = 'export_rsa_key';
    /* Configure the parameters for generating the key. */
    let exportProperties = new Array();
    exportProperties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA
    }
    exportProperties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value:
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
        huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
    }
    exportProperties[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512
    }
    exportProperties[3] = {
        tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
        value: huks.HuksCipherMode.HUKS_MODE_ECB
    }
    exportProperties[4] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5
    }
    exportProperties[5] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    }
    let huksOptions = {
        properties: exportProperties,
        inData: new Uint8Array(new Array())
    }

    /* Generate a key. */
    await publicGenKeyFunc(exportKeyAlias, huksOptions);

    /* Export the key. */
    await publicExportKeyFunc(exportKeyAlias, huksOptions);
    await publicDeleteKeyFunc(exportKeyAlias, huksOptions);
}

// DH key
let g_dhPubData = new Uint8Array([
    0x8a, 0xbf, 0x16, 0x67, 0x1b, 0x92, 0x4b, 0xf2, 0xe0, 0x02, 0xc5, 0x1f, 0x84, 0x00, 0xf8, 0x93,
    0x0f, 0x74, 0xe7, 0x0f, 0xba, 0x78, 0x30, 0xa8, 0x2d, 0x92, 0xef, 0x9b, 0x80, 0xeb, 0x76, 0xea,
    0x26, 0x74, 0x72, 0x63, 0x6a, 0x27, 0xc3, 0x8f, 0xcf, 0xbe, 0x82, 0xa2, 0x8b, 0xdc, 0x65, 0x58,
    0xe3, 0xff, 0x29, 0x97, 0xad, 0xb3, 0x4a, 0x2c, 0x50, 0x08, 0xb5, 0x68, 0xe1, 0x90, 0x5a, 0xdc,
    0x48, 0xb3, 0x6b, 0x7a, 0xce, 0x2e, 0x81, 0x3d, 0x38, 0x35, 0x59, 0xdc, 0x39, 0x8a, 0x97, 0xfe,
    0x20, 0x86, 0x20, 0xdb, 0x55, 0x38, 0x23, 0xca, 0xb5, 0x5b, 0x61, 0x00, 0xdc, 0x45, 0xe2, 0xa1,
    0xf4, 0x1e, 0x7b, 0x01, 0x7a, 0x84, 0x36, 0xa4, 0xa8, 0x1c, 0x0d, 0x3d, 0xde, 0x57, 0x66, 0x73,
    0x4e, 0xaf, 0xee, 0xb0, 0xb0, 0x69, 0x0c, 0x13, 0xba, 0x76, 0xff, 0x2e, 0xb6, 0x16, 0xf9, 0xfc,
    0xd6, 0x09, 0x5b, 0xc7, 0x37, 0x65, 0x84, 0xd5, 0x82, 0x8a, 0xd7, 0x5b, 0x57, 0xe3, 0x0e, 0x89,
    0xbe, 0x05, 0x05, 0x55, 0x2e, 0x9f, 0x94, 0x8a, 0x53, 0xdc, 0xb7, 0x00, 0xb2, 0x6a, 0x7b, 0x8e,
    0xdf, 0x6e, 0xa4, 0x6d, 0x13, 0xb6, 0xbc, 0xaa, 0x8e, 0x44, 0x11, 0x50, 0x32, 0x91, 0x56, 0xa2,
    0x22, 0x3f, 0x2f, 0x08, 0xbb, 0x4d, 0xbb, 0x69, 0xe6, 0xb1, 0xc2, 0x70, 0x79, 0x15, 0x54, 0xad,
    0x4a, 0x29, 0xef, 0xa9, 0x3e, 0x64, 0x8d, 0xf1, 0x90, 0xf4, 0xa7, 0x93, 0x8c, 0x7a, 0x02, 0x4d,
    0x38, 0x1f, 0x58, 0xb8, 0xe4, 0x7c, 0xe1, 0x66, 0x1c, 0x72, 0x30, 0xf3, 0x4c, 0xf4, 0x24, 0xd1,
    0x2d, 0xb7, 0xf1, 0x5a, 0x0f, 0xb8, 0x20, 0xc5, 0x90, 0xe5, 0xca, 0x45, 0x84, 0x5c, 0x08, 0x08,
    0xbf, 0xf9, 0x69, 0x41, 0xf5, 0x49, 0x85, 0x31, 0x35, 0x14, 0x69, 0x12, 0x57, 0x9c, 0xc8, 0xb7]);
let g_dhPriData = new Uint8Array([
    0x01, 0xbc, 0xa7, 0x42, 0x25, 0x79, 0xc5, 0xaf, 0x0f, 0x9c, 0xde, 0x00, 0x3b, 0x58, 0x5c, 0xd1,
    0x1d, 0x7b, 0xcf, 0x66, 0xcd, 0xa9, 0x10, 0xae, 0x92, 0x2d, 0x3c, 0xb7, 0xf3]);
let g_dhX509PubData = new Uint8Array([
    0x30, 0x82, 0x02, 0x29, 0x30, 0x82, 0x01, 0x1b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d,
    0x01, 0x03, 0x01, 0x30, 0x82, 0x01, 0x0c, 0x02, 0x82, 0x01, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xad, 0xf8, 0x54, 0x58, 0xa2, 0xbb, 0x4a, 0x9a, 0xaf, 0xdc, 0x56, 0x20,
    0x27, 0x3d, 0x3c, 0xf1, 0xd8, 0xb9, 0xc5, 0x83, 0xce, 0x2d, 0x36, 0x95, 0xa9, 0xe1, 0x36, 0x41,
    0x14, 0x64, 0x33, 0xfb, 0xcc, 0x93, 0x9d, 0xce, 0x24, 0x9b, 0x3e, 0xf9, 0x7d, 0x2f, 0xe3, 0x63,
    0x63, 0x0c, 0x75, 0xd8, 0xf6, 0x81, 0xb2, 0x02, 0xae, 0xc4, 0x61, 0x7a, 0xd3, 0xdf, 0x1e, 0xd5,
    0xd5, 0xfd, 0x65, 0x61, 0x24, 0x33, 0xf5, 0x1f, 0x5f, 0x06, 0x6e, 0xd0, 0x85, 0x63, 0x65, 0x55,
    0x3d, 0xed, 0x1a, 0xf3, 0xb5, 0x57, 0x13, 0x5e, 0x7f, 0x57, 0xc9, 0x35, 0x98, 0x4f, 0x0c, 0x70,
    0xe0, 0xe6, 0x8b, 0x77, 0xe2, 0xa6, 0x89, 0xda, 0xf3, 0xef, 0xe8, 0x72, 0x1d, 0xf1, 0x58, 0xa1,
    0x36, 0xad, 0xe7, 0x35, 0x30, 0xac, 0xca, 0x4f, 0x48, 0x3a, 0x79, 0x7a, 0xbc, 0x0a, 0xb1, 0x82,
    0xb3, 0x24, 0xfb, 0x61, 0xd1, 0x08, 0xa9, 0x4b, 0xb2, 0xc8, 0xe3, 0xfb, 0xb9, 0x6a, 0xda, 0xb7,
    0x60, 0xd7, 0xf4, 0x68, 0x1d, 0x4f, 0x42, 0xa3, 0xde, 0x39, 0x4d, 0xf4, 0xae, 0x56, 0xed, 0xe7,
    0x63, 0x72, 0xbb, 0x19, 0x0b, 0x07, 0xa7, 0xc8, 0xee, 0x0a, 0x6d, 0x70, 0x9e, 0x02, 0xfc, 0xe1,
    0xcd, 0xf7, 0xe2, 0xec, 0xc0, 0x34, 0x04, 0xcd, 0x28, 0x34, 0x2f, 0x61, 0x91, 0x72, 0xfe, 0x9c,
    0xe9, 0x85, 0x83, 0xff, 0x8e, 0x4f, 0x12, 0x32, 0xee, 0xf2, 0x81, 0x83, 0xc3, 0xfe, 0x3b, 0x1b,
    0x4c, 0x6f, 0xad, 0x73, 0x3b, 0xb5, 0xfc, 0xbc, 0x2e, 0xc2, 0x20, 0x05, 0xc5, 0x8e, 0xf1, 0x83,
    0x7d, 0x16, 0x83, 0xb2, 0xc6, 0xf3, 0x4a, 0x26, 0xc1, 0xb2, 0xef, 0xfa, 0x88, 0x6b, 0x42, 0x38,
    0x61, 0x28, 0x5c, 0x97, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x02, 0x01, 0x02, 0x02,
    0x02, 0x00, 0xe1, 0x03, 0x82, 0x01, 0x06, 0x00, 0x02, 0x82, 0x01, 0x01, 0x00, 0x8a, 0xbf, 0x16,
    0x67, 0x1b, 0x92, 0x4b, 0xf2, 0xe0, 0x02, 0xc5, 0x1f, 0x84, 0x00, 0xf8, 0x93, 0x0f, 0x74, 0xe7,
    0x0f, 0xba, 0x78, 0x30, 0xa8, 0x2d, 0x92, 0xef, 0x9b, 0x80, 0xeb, 0x76, 0xea, 0x26, 0x74, 0x72,
    0x63, 0x6a, 0x27, 0xc3, 0x8f, 0xcf, 0xbe, 0x82, 0xa2, 0x8b, 0xdc, 0x65, 0x58, 0xe3, 0xff, 0x29,
    0x97, 0xad, 0xb3, 0x4a, 0x2c, 0x50, 0x08, 0xb5, 0x68, 0xe1, 0x90, 0x5a, 0xdc, 0x48, 0xb3, 0x6b,
    0x7a, 0xce, 0x2e, 0x81, 0x3d, 0x38, 0x35, 0x59, 0xdc, 0x39, 0x8a, 0x97, 0xfe, 0x20, 0x86, 0x20,
    0xdb, 0x55, 0x38, 0x23, 0xca, 0xb5, 0x5b, 0x61, 0x00, 0xdc, 0x45, 0xe2, 0xa1, 0xf4, 0x1e, 0x7b,
    0x01, 0x7a, 0x84, 0x36, 0xa4, 0xa8, 0x1c, 0x0d, 0x3d, 0xde, 0x57, 0x66, 0x73, 0x4e, 0xaf, 0xee,
    0xb0, 0xb0, 0x69, 0x0c, 0x13, 0xba, 0x76, 0xff, 0x2e, 0xb6, 0x16, 0xf9, 0xfc, 0xd6, 0x09, 0x5b,
    0xc7, 0x37, 0x65, 0x84, 0xd5, 0x82, 0x8a, 0xd7, 0x5b, 0x57, 0xe3, 0x0e, 0x89, 0xbe, 0x05, 0x05,
    0x55, 0x2e, 0x9f, 0x94, 0x8a, 0x53, 0xdc, 0xb7, 0x00, 0xb2, 0x6a, 0x7b, 0x8e, 0xdf, 0x6e, 0xa4,
    0x6d, 0x13, 0xb6, 0xbc, 0xaa, 0x8e, 0x44, 0x11, 0x50, 0x32, 0x91, 0x56, 0xa2, 0x22, 0x3f, 0x2f,
    0x08, 0xbb, 0x4d, 0xbb, 0x69, 0xe6, 0xb1, 0xc2, 0x70, 0x79, 0x15, 0x54, 0xad, 0x4a, 0x29, 0xef,
    0xa9, 0x3e, 0x64, 0x8d, 0xf1, 0x90, 0xf4, 0xa7, 0x93, 0x8c, 0x7a, 0x02, 0x4d, 0x38, 0x1f, 0x58,
    0xb8, 0xe4, 0x7c, 0xe1, 0x66, 0x1c, 0x72, 0x30, 0xf3, 0x4c, 0xf4, 0x24, 0xd1, 0x2d, 0xb7, 0xf1,
    0x5a, 0x0f, 0xb8, 0x20, 0xc5, 0x90, 0xe5, 0xca, 0x45, 0x84, 0x5c, 0x08, 0x08, 0xbf, 0xf9, 0x69,
    0x41, 0xf5, 0x49, 0x85, 0x31, 0x35, 0x14, 0x69, 0x12, 0x57, 0x9c, 0xc8, 0xb7]);

// X25519 key
let g_x25519PubData = new Uint8Array([
    0x9c, 0xf6, 0x7a, 0x8d, 0xce, 0xc2, 0x7f, 0xa7, 0xd9, 0xfd, 0xf1, 0xad, 0xac, 0xf0, 0xb3, 0x8c,
    0xe8, 0x16, 0xa2, 0x65, 0xcc, 0x18, 0x55, 0x60, 0xcd, 0x2f, 0xf5, 0xe5, 0x72, 0xc9, 0x3c, 0x54]);
// X25519 public key
let g_x25519PriData = new Uint8Array([
    0x20, 0xd5, 0xbb, 0x54, 0x6f, 0x1f, 0x00, 0x30, 0x4e, 0x33, 0x38, 0xb9, 0x8e, 0x6a, 0xdf, 0xad,
    0x33, 0x6f, 0x51, 0x23, 0xff, 0x4d, 0x95, 0x26, 0xdc, 0xb0, 0x74, 0xb2, 0x5c, 0x7e, 0x85, 0x6c]);

// RSA key
let g_nData = new Uint8Array([
    0xb6, 0xd8, 0x9b, 0x33, 0x78, 0xa2, 0x63, 0x21, 0x84, 0x47, 0xa1, 0x72, 0  x3d, 0x73, 0x10, 0xbd,
    0xe9, 0x5d, 0x78, 0x44, 0x3d, 0x80, 0x18, 0x12, 0x60, 0xed, 0x29, 0x3e, 0xc7, 0x23, 0x0d, 0x3f,
    0x02, 0x59, 0x28, 0xe2, 0x8f, 0x83, 0xdf, 0x37, 0x4b, 0x77, 0xce, 0x5f, 0xb6, 0xcd, 0x61, 0x72,
    0xee, 0x01, 0xe2, 0x37, 0x4d, 0xfd, 0x4f, 0x39, 0xcf, 0xbd, 0xff, 0x84, 0x57, 0x44, 0xa5, 0x03]);
let g_eData = new Uint8Array([0x01, 0x00, 0x01]);
let g_dData = new Uint8Array([
    0x35, 0x63, 0x89, 0xed, 0xbd, 0x8b, 0xac, 0xe6, 0x5c, 0x79, 0x8d, 0xea, 0x8d, 0x86, 0xcb, 0x9c,
    0xa8, 0x47, 0x62, 0x96, 0x8a, 0x5e, 0x9c, 0xa8, 0xc1, 0x24, 0x7e, 0xa6, 0x95, 0xfe, 0xe6, 0x1e,
    0xc0, 0xf3, 0x29, 0x76, 0xbb, 0x4d, 0xe4, 0xbc, 0x78, 0x64, 0xe1, 0x79, 0xcd, 0x8a, 0x45, 0xac,
    0x5c, 0x88, 0xea, 0xb4, 0x10, 0xd8, 0x90, 0x65, 0x7b, 0x94, 0xe8, 0x87, 0x30, 0x2a, 0x04, 0x01]);
let g_pubData = new Uint8Array([
    0x30, 0x5c, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05,
    0x00, 0x03, 0x4b, 0x00, 0x30, 0x48, 0x02, 0x41, 0x00, 0x9e, 0x93, 0x57, 0xc4, 0xab, 0xde, 0x30,
    0xc5, 0x3f, 0x3b, 0x33, 0xa6, 0xdc, 0x4a, 0xdb, 0xbf, 0x12, 0x9e, 0x5d, 0xc4, 0xba, 0x0e, 0x15,
    0x06, 0x41, 0xd8, 0x96, 0x43, 0xca, 0xc5, 0xea, 0x9f, 0xdd, 0xa0, 0x2a, 0xf1, 0x53, 0x46, 0x14,
    0x36, 0x7a, 0xab, 0xbc, 0x92, 0x1b, 0x07, 0xc6, 0x9a, 0x7d, 0x0c, 0xd0, 0xa0, 0x0f, 0x31, 0xd5,
    0x38, 0x84, 0x6c, 0x08, 0xcb, 0x9b, 0x10, 0xa6, 0x4d, 0x02, 0x03, 0x01, 0x00, 0x01]);

// ECC key
let g_eccXData = new Uint8Array([
    0xa5, 0xb8, 0xa3, 0x78, 0x1d, 0x6d, 0x76, 0xe0, 0xb3, 0xf5, 0x6f, 0x43, 0x9d, 0xcf, 0x60, 0xf6,
    0x0b, 0x3f, 0x64, 0x45, 0xa8, 0x3f, 0x1a, 0x96, 0xf1, 0xa1, 0xa4, 0x5d, 0x3e, 0x2c, 0x3f, 0x13]);
let g_eccYData = new Uint8Array([
    0xd7, 0x81, 0xf7, 0x2a, 0xb5, 0x8d, 0x19, 0x3d, 0x9b, 0x96, 0xc7, 0x6a, 0x10, 0xf0, 0xaa, 0xbc,
    0x91, 0x6f, 0x4d, 0xa7, 0x09, 0xb3, 0x57, 0x88, 0x19, 0x6f, 0x00, 0x4b, 0xad, 0xee, 0x34, 0x35]);
let g_eccZData = new Uint8Array([
    0xfb, 0x8b, 0x9f, 0x12, 0xa0, 0x83, 0x19, 0xbe, 0x6a, 0x6f, 0x63, 0x2a, 0x7c, 0x86, 0xba, 0xca,
    0x64, 0x0b, 0x88, 0x96, 0xe2, 0xfa, 0x77, 0xbc, 0x71, 0xe3, 0x0f, 0x0f, 0x9e, 0x3c, 0xe5, 0xf9]);
let g_eccPubData = new Uint8Array([
    0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a,
    0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0xa5, 0xb8, 0xa3, 0x78, 0x1d,
    0x6d, 0x76, 0xe0, 0xb3, 0xf5, 0x6f, 0x43, 0x9d, 0xcf, 0x60, 0xf6, 0x0b, 0x3f, 0x64, 0x45, 0xa8,
    0x3f, 0x1a, 0x96, 0xf1, 0xa1, 0xa4, 0x5d, 0x3e, 0x2c, 0x3f, 0x13, 0xd7, 0x81, 0xf7, 0x2a, 0xb5,
    0x8d, 0x19, 0x3d, 0x9b, 0x96, 0xc7, 0x6a, 0x10, 0xf0, 0xaa, 0xbc, 0x91, 0x6f, 0x4d, 0xa7, 0x09,
    0xb3, 0x57, 0x88, 0x19, 0x6f, 0x00, 0x4b, 0xad, 0xee, 0x34, 0x35]);

// Import the DH2048 key.
async function ImportDhTest(alg, keyType) {
    let importKeyAlias = 'import_dh_key';
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_DH
    }
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
    }
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_2048
    }
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_IMPORT_KEY_TYPE,
        value: huks.HuksImportKeyType.HUKS_KEY_TYPE_PUBLIC_KEY
    }
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    }
    let huksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }
    huksOptions.properties[0].value = alg;
    huksOptions.properties[3].value = keyType;

    // Compare the key types.
    if (huksOptions.properties[3].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR) {
        /* Concatenate the huksOptions.inData field with a non-public key in the following format:
         * keyAlg type (4 bytes) + key_dh length (4 bytes) +
         * g_dhPubData length (4 bytes) + g_dhPriData length (4 bytes) +
         * Reserved size (4 bytes) + g_dhPubData + g_dhPriData
         */
        // Key pair
        let Material = new Uint32Array([huks.HuksKeyAlg.HUKS_ALG_DH, huks.HuksKeySize.HUKS_DH_KEY_SIZE_2048, g_dhPubData.length, g_dhPriData.length, 0]);
        let u8Material = Uint32ToUint8(Material);
        let strMaterial = Uint8ArrayToString(u8Material);

        let strXData = strMaterial.concat(Uint8ArrayToString(g_dhPubData));
        let strData = strXData.concat(Uint8ArrayToString(g_dhPriData));
        huksOptions.inData = StringToUint8Array(strData);
    } else if (huksOptions.properties[3].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_PRIVATE_KEY) {
        // Private key
        let Material = new Uint32Array([huks.HuksKeyAlg.HUKS_ALG_DH, huks.HuksKeySize.HUKS_DH_KEY_SIZE_2048, 0, g_dhPriData.length, 0]);
        let u8Material = Uint32ToUint8(Material);
        let strMaterial = Uint8ArrayToString(u8Material);

        let strData = strMaterial.concat(Uint8ArrayToString(g_dhPriData));
        huksOptions.inData = StringToUint8Array(strData);
    } else if (huksOptions.properties[3].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_PUBLIC_KEY) {
        // Public key
        huksOptions.inData = g_dhX509PubData;
    }

    await publicImportKeyFunc(importKeyAlias, huksOptions);
    await publicDeleteKeyFunc(importKeyAlias, huksOptions);
}

// Import the ECC256 key.
async function ImportEccTest(alg, keyType) {
    let importKeyAlias = 'import_ecc_key';
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_ECC
    }
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
    }
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
    }
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_IMPORT_KEY_TYPE,
        value: huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR
    }
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    }
    let huksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }
    huksOptions.properties[0].value = alg;
    huksOptions.properties[3].value = keyType;

    // Compare the key types.
    if (huksOptions.properties[3].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR) {
        /* Concatenate the huksOptions.inData field with a non-public key in the following format:
         * keyAlg type (4 bytes) + key_ecc length (4 bytes) +
         * g_eccXData length (4 bytes) + g_eccYData length (4 bytes) +
         * g_eccZData length (4 bytes) + g_eccXData +
         * g_eccYData + g_eccZData
         */
        // Key pair
        let Material = new Uint32Array([huks.HuksKeyAlg.HUKS_ALG_ECC, huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256, g_eccXData.length, g_eccYData.length, g_eccZData.length]);
        let u8Material = Uint32ToUint8(Material);
        let strMaterial = Uint8ArrayToString(u8Material);

        let strXData = strMaterial.concat(Uint8ArrayToString(g_eccXData));
        let strYData = strXData.concat(Uint8ArrayToString(g_eccYData));
        let strData = strYData.concat(Uint8ArrayToString(g_eccZData));
        huksOptions.inData = StringToUint8Array(strData);
    } else if (huksOptions.properties[3].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_PRIVATE_KEY) {
        // Private key
        huksOptions.properties[3].value == huks.HuksImportKeyType.HUKS_KEY_TYPE_PRIVATE_KEY
        let Material = new Uint32Array([huks.HuksKeyAlg.HUKS_ALG_ECC, huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256, 0, 0, g_eccZData.length]);
        let u8Material = Uint32ToUint8(Material);
        let strMaterial = Uint8ArrayToString(u8Material);

        let strData = strMaterial.concat(Uint8ArrayToString(g_eccZData));
        huksOptions.inData = StringToUint8Array(strData);
    } else if (huksOptions.properties[3].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_PUBLIC_KEY) {
        // Public key
        huksOptions.inData = g_eccPubData;
    }

    await publicImportKeyFunc(importKeyAlias, huksOptions);
    await publicDeleteKeyFunc(importKeyAlias, huksOptions);
}

// Import the RSA512 key.
async function ImportRsaTest(alg, keyType) {
    let importKeyAlias = 'import_rsa_key';
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_RSA
    }
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
    }
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    }
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_PADDING,
        value: huks.HuksKeyPadding.HUKS_PADDING_PSS
    }
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512
    }
    properties[5] = {
        tag: huks.HuksTag.HUKS_TAG_IMPORT_KEY_TYPE,
        value: huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR
    }
    let huksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }
    huksOptions.properties[0].value = alg;
    huksOptions.properties[3].value = keyType;

    // Compare the key types.
    if (huksOptions.properties[5].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR) {
        /* Concatenate the huksOptions.inData field with a non-public key in the following format:
         * keyAlg type (4 bytes) + key_rsa length (4 bytes) +
         * g_nData length (4 bytes) + g_eData length (4 bytes) +
         * g_dData length (4 bytes) + g_nData +
         * g_eData + g_dData
         */
        // Key pair
        let Material = new Uint32Array([huks.HuksKeyAlg.HUKS_ALG_RSA, huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512, g_nData.length, g_eData.length, g_dData.length]);
        let u8Material = Uint32ToUint8(Material);
        let strMaterial = Uint8ArrayToString(u8Material);
        let strNData = strMaterial.concat(Uint8ArrayToString(g_nData));
        let strEData = strNData.concat(Uint8ArrayToString(g_eData));
        let strData = strEData.concat(Uint8ArrayToString(g_dData));
        huksOptions.inData = StringToUint8Array(strData);
    } else if (huksOptions.properties[5].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_PRIVATE_KEY) {
        // Private key
        let Material = new Uint32Array([huks.HuksKeyAlg.HUKS_ALG_RSA, huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512, g_nData.length, 0, g_dData.length]);
        let u8Material = Uint32ToUint8(Material);
        let strMaterial = Uint8ArrayToString(u8Material);
        let strNData = strMaterial.concat(Uint8ArrayToString(g_nData));
        let strData = strNData.concat(Uint8ArrayToString(g_dData));
        huksOptions.inData = StringToUint8Array(strData);
    } else if (huksOptions.properties[5].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_PUBLIC_KEY) {
        // Public key
        huksOptions.inData = g_pubData;
    }
    await publicImportKeyFunc(importKeyAlias, huksOptions);
    await publicDeleteKeyFunc(importKeyAlias, huksOptions);
}

// Import the X25519 key.
async function ImportX25519Test(alg, keyType) {
    let importKeyAlias = 'import_x25519_key';
    let properties = new Array();
    properties[0] = {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_X25519
    }
    properties[1] = {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE
    }
    properties[2] = {
        tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
        value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256
    }
    properties[3] = {
        tag: huks.HuksTag.HUKS_TAG_IMPORT_KEY_TYPE,
        value: huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR
    }
    properties[4] = {
        tag: huks.HuksTag.HUKS_TAG_DIGEST,
        value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
    }
    let huksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }
    huksOptions.properties[0].value = alg;
    huksOptions.properties[3].value = keyType;

    // Compare the key types.
    if (huksOptions.properties[3].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR) {
        /* Concatenate the huksOptions.inData field with a non-public key in the following format:
         * keyAlg type (4 bytes) + key_x25519 length (4 bytes) +
         * g_x25519PubData length (4) + g_x25519PriData length (4) +
         * Reserved size (4 bytes) + g_x25519PubData +
         * g_x25519PriData
         */
        // Key pair
        let Material = new Uint32Array([huks.HuksKeyAlg.HUKS_ALG_X25519, huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256, g_x25519PriData.length, g_x25519PubData.length, 0]);
        let u8Material = Uint32ToUint8(Material);
        let strMaterial = Uint8ArrayToString(u8Material);
        let strXData = strMaterial.concat(Uint8ArrayToString(g_x25519PubData));
        let strData = strXData.concat(Uint8ArrayToString(g_x25519PriData));
        huksOptions.inData = StringToUint8Array(strData);
    } else if (huksOptions.properties[3].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_PRIVATE_KEY) {
        // Private key
        huksOptions.inData = g_x25519PriData;
    } else if (huksOptions.properties[3].value === huks.HuksImportKeyType.HUKS_KEY_TYPE_PUBLIC_KEY) {
        // Public key
        huksOptions.inData = g_x25519PubData;
    }
    await publicImportKeyFunc(importKeyAlias, huksOptions);
    await publicDeleteKeyFunc(importKeyAlias, huksOptions);
}

@Entry
@Component
struct Index {
    build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
            Button() {
                Text('testExportRsa')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
                }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(() => {
                testExportRsa();
            })

            Button() {
                Text('testImportDh')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(() => {
                ImportDhTest(huks.HuksKeyAlg.HUKS_ALG_DH, huks.HuksImportKeyType.HUKS_KEY_TYPE_PRIVATE_KEY);
            })

            Button() {
                Text('testImportRsa')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(() => {
                ImportRsaTest(huks.HuksKeyAlg.HUKS_ALG_RSA, huks.HuksImportKeyType.HUKS_KEY_TYPE_KEY_PAIR);
            })

            Button() {
                Text('testImportX25519')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(() => {
                ImportX25519Test(huks.HuksKeyAlg.HUKS_ALG_X25519, huks.HuksImportKeyType.HUKS_KEY_TYPE_PRIVATE_KEY);
            })

            Button() {
                Text('testImportEcc')
                    .fontSize(30)
                    .fontWeight(FontWeight.Bold)
            }.type(ButtonType.Capsule)
            .margin({
                top: 20
            })
            .backgroundColor('#0D9FFB')
            .onClick(() => {
                ImportEccTest(huks.HuksKeyAlg.HUKS_ALG_ECC, huks.HuksImportKeyType.HUKS_KEY_TYPE_PUBLIC_KEY);
            })  
        }
        .width('100%')
        .height('100%')
    }
}
```

### Secure Key Import

The service invoker and HUKS negotiate a shared symmetric key to encrypt and decrypt the intermediate key and the key to be imported. After the encrypted key is imported, it is decrypted and saved in HUKS. The keys in plaintext can be processed in HUKS only.

The development procedure is as follows:

1.   Generate a key pair in HUKS. The key pair is used to encrypt the key to import.
2.  Export the public key of the key pair and obtain a shared secret through key agreement.
3.  Generate intermediate key materials to encrypt the key.
4.  Import the key.

**Supported Key Types**

AES128, AES192, AES256, RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, HmacSHA1, HmacSHA224, HmacSHA256, HmacSHA384, HmacSHA512, ECC224, ECC256, ECC384, ECC521, Curve25519, DSA, SM2, SM3, SM4

> **NOTICE**
>
> - When generating a public key, set **HUKS_TAG_PURPOSE = HUKS_KEY_PURPOSE_UNWRAP**.
> - Set **HUKS_TAG_IMPORT_KEY_TYPE = HUKS_KEY_TYPE_KEY_PAIR**.
> - When importing a key in secure mode, add **HUKS_TAG_UNWRAP_ALGORITHM_SUITE** with value set to **HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING** or **HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING**.
> - The key alias cannot exceed 64 bytes.

Before you get started, understand the following variables:

| Parameter        | Type       | Mandatory| Description                            |
| -------------- | ----------- | ---- | -------------------------------- |
| importAlias    | string      | Yes  | Alias of the key to import.                      |
| wrapAlias      | string      | Yes  | Alias of the key.                      |
| genWrapOptions | HuksOptions | Yes  | Tags required for generating the key.|
| importOptions  | HuksOptions | Yes  | Tags required for importing the encrypted key.    |

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

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

let importAlias = "importAlias";
let wrapAlias = "wrappingKeyAlias";
let exportKey;

let inputEccPair = new Uint8Array([
    0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00, 0xa5, 0xb8, 0xa3, 0x78, 0x1d, 0x6d, 0x76, 0xe0, 0xb3, 0xf5, 0x6f, 0x43,
    0x9d, 0xcf, 0x60, 0xf6, 0x0b, 0x3f, 0x64, 0x45, 0xa8, 0x3f, 0x1a, 0x96, 0xf1, 0xa1, 0xa4, 0x5d,
    0x3e, 0x2c, 0x3f, 0x13, 0xd7, 0x81, 0xf7, 0x2a, 0xb5, 0x8d, 0x19, 0x3d, 0x9b, 0x96, 0xc7, 0x6a,
    0x10, 0xf0, 0xaa, 0xbc, 0x91, 0x6f, 0x4d, 0xa7, 0x09, 0xb3, 0x57, 0x88, 0x19, 0x6f, 0x00, 0x4b,
    0xad, 0xee, 0x34, 0x35, 0xfb, 0x8b, 0x9f, 0x12, 0xa0, 0x83, 0x19, 0xbe, 0x6a, 0x6f, 0x63, 0x2a,
    0x7c, 0x86, 0xba, 0xca, 0x64, 0x0b, 0x88, 0x96, 0xe2, 0xfa, 0x77, 0xbc, 0x71, 0xe3, 0x0f, 0x0f,
    0x9e, 0x3c, 0xe5, 0xf9]);

let properties = new Array();
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
let huksOptions = {
    properties: properties,
    inData: inputEccPair
};

let importProperties = new Array();
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
let importOptions = {
    properties: importProperties,
    inData: new Uint8Array(new Array())
};

async function importWrappedKeyItemTest() {

    console.info(`enter ImportWrapKey test`);
    await publicImportKeyFunc(wrapAlias, huksOptions);

    await publicExportKeyFunc(wrapAlias, huksOptions);

    /* The following operation does not involve calling of HUKS APIs, and the specific implementation is not provided here.
     * For example, import keyA.
     * 1. Use ECC to generate a public and private key pair named keyB. The public key is keyB_pub, and the private key is keyB_pri.
     * 2. Use keyB_pri and the public key obtained from wrappingAlias to negotiate the shared key share_key.
     * 3. Randomly generate a key kek to encrypt keyA using AES-GCM. During the encryption, record nonce1, aad1, ciphertext keyA_enc, and encrypted tag1.
     * 4. Use share_key to encrypt kek using AES-GCM. During the encryption, record nonce2, aad2, ciphertext kek_enc, and encrypted tag2. 
     * 5. Generate the **importOptions.inData** field in the following format:
     * keyB_pub length (4 bytes) + keyB_pub + aad2 length (4 bytes) + aad2 +
     * nonce2 length (4 bytes) + nonce2 + tag2 length (4 bytes) + tag2 +
     * kek_enc length (4 bytes) + kek_enc + aad1 length (4 bytes) + aad1 +
     * nonce1 length (4 bytes) + nonce1 + tag1 length (4 bytes) + tag1 +
     * Memory occupied by the keyA length (4 bytes) + keyA length + keyA_enc length (4 bytes) + keyA_enc
     */
    let inputKey = new Uint8Array([
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

### Key Encryption and Decryption

Use the symmetric or asymmetric key stored in HUKS to encrypt or decrypt data based on the specified alias. The keys in plaintext must be in a secure environment during the encryption and decryption process.

The development procedure is as follows:

1. Generate a key.
2. Encrypt the key.
3. Decrypt the key.

**Supported key types**:

| HUKS_ALG_ALGORITHM                                           | HUKS_TAG_PURPOSE                                   | HUKS_TAG_DIGEST                                              | HUKS_TAG_PADDING                                             | HUKS_TAG_BLOCK_MODE                         | HUKS_TAG_IV |
| ------------------------------------------------------------ | -------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------- | ----------- |
| HUKS_ALG_SM4 (supported key length: HUKS_SM4_KEY_SIZE_128)| HUKS_KEY_PURPOSE_ENCRYPT or HUKS_KEY_PURPOSE_DECRYPT| Optional                                                  | HUKS_PADDING_NONE                                            | HUKS_MODE_CTR  HUKS_MODE_ECB  HUKS_MODE_CBC | Mandatory   |
| HUKS_ALG_SM4 (supported key length: HUKS_SM4_KEY_SIZE_128)| HUKS_KEY_PURPOSE_ENCRYPT or HUKS_KEY_PURPOSE_DECRYPT| Optional                                                  | HUKS_PADDING_PKCS7                                           | HUKS_MODE_ECB  HUKS_MODE_CBC                | Mandatory   |
| HUKS_ALG_RSA (supported lengths: HUKS_RSA_KEY_SIZE_512, HUKS_RSA_KEY_SIZE_768, HUKS_RSA_KEY_SIZE_1024, HUKS_RSA_KEY_SIZE_2048, HUKS_RSA_KEY_SIZE_3072, HUKS_RSA_KEY_SIZE_4096)| HUKS_KEY_PURPOSE_ENCRYPT or HUKS_KEY_PURPOSE_DECRYPT| HUKS_DIGEST_SHA1 HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 | HUKS_PADDING_NONE  HUKS_PADDING_PKCS1_V1_5  HUKS_PADDING_OAEP | HUKS_MODE_ECB                               | Optional |

| HUKS_ALG_ALGORITHM                                           | HUKS_TAG_PURPOSE         | HUKS_TAG_PADDING                      | HUKS_TAG_BLOCK_MODE          | HUKS_TAG_IV | HUKS_TAG_NONCE | HUKS_TAG_ASSOCIATED_DATA | HUKS_TAG_AE_TAG |
| ------------------------------------------------------------ | ------------------------ | ------------------------------------- | ---------------------------- | ----------- | -------------- | ------------------------ | --------------- |
| HUKS_ALG_AES (supported key lengths: HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256)| HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_NONE, HUKS_PADDING_PKCS7| HUKS_MODE_CBC                | Mandatory   | Optional    | Optional              | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CCM  HUKS_MODE_GCM | Optional | Mandatory      | Mandatory                | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CTR                | Mandatory   | Optional    | Optional              | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_PKCS7  HUKS_PADDING_NONE | HUKS_MODE_ECB                | Mandatory   | Optional    | Optional              | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE, HUKS_PADDING_PKCS7| HUKS_MODE_CBC                | Mandatory   | Optional    | Optional              | Mandatory       |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CCM  HUKS_MODE_GCM | Optional | Mandatory      | Mandatory                | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CTR                | Mandatory   | Optional    | Optional              | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE, HUKS_PADDING_PKCS7| HUKS_MODE_ECB                | Mandatory   | Optional    | Optional              | Optional     |

> **NOTE**<br>
>
> The key alias cannot exceed 64 bytes.

Before you get started, understand the following variables:

| Parameter        | Type       | Mandatory| Description                    |
| -------------- | ----------- | ---- | ------------------------ |
| srcKeyAlias    | string      | Yes  | Alias of the key.              |
| huksOptions    | HuksOptions | Yes  | Tags required for generating the key.|
| encryptOptions | HuksOptions | Yes  | Tags required for encrypting the key.|
| decryptOptions | HuksOptions | Yes  | Tags required for decrypting the key.|

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example 1:**

```ts
/* The cipher operation supports RSA, AES, and SM4 keys.
 *
 * The following uses the Promise() operation of an SM4 128-bit key as an example.
 */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData) {
    let dataString = '';
    for (let i = 0; i < fileData.length; i++) {
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

let IV = '0000000000000000';
let cipherInData = 'Hks_SM4_Cipher_Test_101010101010101010110_string';
let srcKeyAlias = 'huksCipherSm4SrcKeyAlias';
let encryptUpdateResult = new Array();
let handle;
let updateResult = new Array();
let finishOutData;

async function testSm4Cipher() {
    /* Integrate the key generation parameter set and key encryption parameter set. */
    let properties = new Array();
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
    let huksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }

    let propertiesEncrypt = new Array();
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
    let encryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* Generate a key. */
    await publicGenKeyFunc(srcKeyAlias, huksOptions);

    /* Encrypt the key. */
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

    /* Modify the key encryption parameter set to the decryption parameter set. */
    propertiesEncrypt.splice(1, 1, {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
    });
    let decryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* Decrypt the key. */
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

**Example 2:**

```ts
/* The cipher operation supports RSA, AES, and SM4 keys.
 *
 * The following uses the Promise() operation of an AES128 GCM key as an example.
 */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData) {
    let dataString = '';
    for (let i = 0; i < fileData.length; i++) {
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

let AAD = '0000000000000000';
let NONCE = '000000000000';
let AEAD = '0000000000000000';
let cipherInData = 'Hks_AES_Cipher_Test_00000000000000000000000000000000000000000000000000000_string';
let srcKeyAlias = 'huksCipherSm4SrcKeyAlias';
let updateResult = new Array();
let encryptUpdateResult = new Array();
let decryptUpdateResult = new Array();
let handle;
let finishOutData;

async function testAesCipher() {
    /* Integrate the key generation parameter set and key encryption parameter set. */
    let properties = new Array();
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
    let huksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }

    let propertiesEncrypt = new Array();
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
    let encryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* Generate a key. */
    await publicGenKeyFunc(srcKeyAlias, huksOptions);

    /* Encrypt the key. */
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

    /* Modify the key encryption parameter set to the decryption parameter set. */
    propertiesEncrypt.splice(1, 1, {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
    });
    propertiesEncrypt.splice(8, 1, {
        tag: huks.HuksTag.HUKS_TAG_AE_TAG,
        value: new Uint8Array(encryptUpdateResult.splice(encryptUpdateResult.length - 16,encryptUpdateResult.length))
    });
    let decryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* Decrypt the key. */
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

### Signing and Signature Verification

The data to be sent can be signed with a unique signature for security purposes. Then, the receiver needs to verify the signature when receiving the data.

The development procedure is as follows:

1. Generate a key.
2. Use the key to sign the data to be sent.
3. Export the signature key.
4. Import the signature key.
5. Verify the signature.

**Supported key types**:

Only **HksInit()** has requirements on parameters in **paramSet**. The other Init-Update-Finish APIs have no requirements on **paramSet**.

| HUKS_ALG_ALGORITHM | HUKS_ALG_KEY_SIZE                                            | HUKS_ALG_PURPOSE                               | HUKS_ALG_PADDING        | HUKS_TAG_DIGEST                                              |
| ------------------ | ------------------------------------------------------------ | ---------------------------------------------- | ----------------------- | ------------------------------------------------------------ |
| HUKS_ALG_RSA       | HUKS_RSA_KEY_SIZE_512, HUKS_RSA_KEY_SIZE_768, HUKS_RSA_KEY_SIZE_1024,  HUKS_RSA_KEY_SIZE_2048, HUKS_RSA_KEY_SIZE_3072, HUKS_RSA_KEY_SIZE_4096| HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY | HUKS_PADDING_PKCS1_V1_5 | HUKS_DIGEST_MD5, HUKS_DIGEST_NONE, HUKS_DIGEST_SHA1, HUKS_DIGEST_SHA224, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512|
| HUKS_ALG_RSA       | HUKS_RSA_KEY_SIZE_512, HUKS_RSA_KEY_SIZE_768, HUKS_RSA_KEY_SIZE_1024,  HUKS_RSA_KEY_SIZE_2048, HUKS_RSA_KEY_SIZE_3072, HUKS_RSA_KEY_SIZE_4096| HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY | HUKS_PADDING_PSS        | HUKS_DIGEST_SHA1, HUKS_DIGEST_SHA224, HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512|
| HUKS_ALG_DSA       | HUKS_RSA_KEY_SIZE_1024                                       | HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY | Optional             | HUKS_DIGEST_SHA1, HUKS_DIGEST_SHA224, HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512|
| HUKS_ALG_ECC       | HUKS_ECC_KEY_SIZE_224, HUKS_ECC_KEY_SIZE_256, HUKS_ECC_KEY_SIZE_384, HUKS_ECC_KEY_SIZE_521| HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY | Optional             | HUKS_DIGEST_NONE, HUKS_DIGEST_SHA1, HUKS_DIGEST_SHA224, HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512|

The signing and signature verification using Ed25519 involves a hash operation in the algorithm engine. Therefore, the Init-Update-Finish processing is special.

In the **update()** process, **inData** is sent to HUKS Core and recorded in a .ctx file, without performing hash operation. The signing and signature verification calculations are performed on the combined **inData** in the **finish()** operation.

| HUKS_ALG_ALGORITHM | HUKS_ALG_KEY_SIZE            | HUKS_ALG_PURPOSE                                |
| ------------------ | ---------------------------- | ----------------------------------------------- |
| HUKS_ALG_ED25519   | HUKS_CURVE25519_KEY_SIZE_256 | HUKS_KEY_PURPOSE_SIGN   HUKS_KEY_PURPOSE_VERIFY |

> **NOTE**<br>
>
> The key alias cannot exceed 64 bytes.

Before you get started, understand the following variables:

| Parameter           | Type       | Mandatory| Description                    |
| ----------------- | ----------- | ---- | ------------------------ |
| generateKeyAlias  | string      | Yes  | Alias of the key to generate.          |
| importKeyAlias    | string      | Yes  | Alias of the key imported.          |
| genrateKeyOptions | HuksOptions | Yes  | Tags required for generating the key.|
| signOptions       | HuksOptions | Yes  | Tags required for signing.|
| verifyOptions     | HuksOptions | Yes  | Tags required for verifying the signature.|

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

```ts
/*The Sign() and Verify() operations support RSA, ECC, SM2, ED25519, and DSA keys.
 *
 * The following uses an SM2 key in callback-based APIs as an example. 
 */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
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

let signVerifyInData = 'signVerifyInDataForTest';
let generateKeyAlias = 'generateKeyAliasForTest';
let importKeyAlias = 'importKeyAliasForTest';
let handle;
let exportKey;
let finishOutData;

/* Configure the parameters for generating the key. */
let generateKeyProperties = new Array();
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
let genrateKeyOptions = {
    properties: generateKeyProperties,
    inData: new Uint8Array(new Array())
}

/* Configure the parameters for signing. */
let signProperties = new Array();
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
let signOptions = {
    properties: signProperties,
    inData: new Uint8Array(new Array())
}

/* Configure the parameters for signature verification. */
let verifyProperties = new Array();
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
let verifyOptions = {
    properties: verifyProperties,
    inData: new Uint8Array(new Array())
}

async function testSm2SignVerify() {
    /* Generate a key. */
    await publicGenKeyFunc(generateKeyAlias, genrateKeyOptions);

    /* Generate a signature. */
    let signHandle;
    let signFinishOutData;
    await publicInitFunc(generateKeyAlias, signOptions);

    signHandle = handle;
    signOptions.inData = StringToUint8Array(signVerifyInData)
    await publicUpdateFunc(signHandle, signOptions);

    signOptions.inData = new Uint8Array(new Array());
    await publicFinishFunc(signHandle, signOptions);
    signFinishOutData = finishOutData;

    /* Export the key. */
    await publicExportKeyFunc(generateKeyAlias, genrateKeyOptions);

    /* Import the key. */
    verifyOptions.inData = exportKey;
    await publicImportKeyFunc(importKeyAlias, verifyOptions);

    /* Verify the signature. */
    let verifyHandle;
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

### Key Agreement

Two or more objects communicate with each other based on the same session key.

The development procedure is as follows:

1. Generate two keys.
2. Export the keys separately.
3. Perform key agreement.

**Supported key types**:

The **HksInit()** and **HksFinish()** APIs have requirements on **paramSet**. The **HksUpdate()** API has no requirements on **paramSet**.

Requirements of **HksInit()** for **paramSet**:

| HUKS_ALG_ALGORITHM | HUKS_ALG_KEY_SIZE                                            | HUKS_ALG_PURPOSE       |
| ------------------ | ------------------------------------------------------------ | ---------------------- |
| HUKS_ALG_ECDH      | HUKS_ECC_KEY_SIZE_224, HUKS_ECC_KEY_SIZE_256, HUKS_ECC_KEY_SIZE_384, HUKS_ECC_KEY_SIZE_521| HUKS_KEY_PURPOSE_AGREE |
| HUKS_ALG_DH        | HUKS_DH_KEY_SIZE_2048, HUKS_DH_KEY_SIZE_3072, HUKS_DH_KEY_SIZE_4096| HUKS_KEY_PURPOSE_AGREE |
| HUKS_ALG_X25519    | HUKS_CURVE25519_KEY_SIZE_256                                 | HUKS_KEY_PURPOSE_AGREE |

Requirements of **HksFinish()** for **paramSet**:

The derived key is used as a symmetric key.

| HUKS_TAG_KEY_STORAGE_FLAG      | HUKS_TAG_KEY_ALIAS | HUKS_TAG_IS_KEY_ALIAS | HUKS_TAG_ALGORITHM | HUKS_TAG_KEY_SIZE                                            | HUKS_TAG_PURPOSE                                   | HUKS_TAG_PADDING   | HUKS_TAG_DIGEST                                              | HUKS_TAG_BLOCK_MODE                         |
| ------------------------------ | ------------------ | --------------------- | ------------------ | ------------------------------------------------------------ | -------------------------------------------------- | ------------------ | ------------------------------------------------------------ | ------------------------------------------- |
| **HUKS_STORAGE_TEMP** or not set| Not required            | TRUE                  | Not required            | Not required                                                      | Not required                                            | Not required            | Not required                                                      | Not required                                     |
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256| HUKS_KEY_PURPOSE_ENCRYPT or HUKS_KEY_PURPOSE_DECRYPT| HUKS_PADDING_PKCS7 | Optional                                                  | HUKS_MODE_CCM  HUKS_MODE_GCM  HUKS_MODE_CTP |
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256| HUKS_KEY_PURPOSE_DERIVE                            | Optional        | HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512  | Optional                                 |
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_HMAC      | Multiple of 8, in bits                                        | HUKS_KEY_PURPOSE_MAC                               | Optional        | HUKS_DIGEST_SHA1, HUKS_DIGEST_SHA224, HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512| Optional                                 |

> **NOTE**<br>
>
> The length of the key after agreement (converted into bits) must be greater than or equal to the selected **HUKS_TAG_KEY_SIZE**.
>
> The key alias cannot exceed 64 bytes.

Before you get started, understand the following variables:

| Parameter             | Type       | Mandatory| Description                                  |
| ------------------- | ----------- | ---- | -------------------------------------- |
| srcKeyAliasFirst    | string      | Yes  | Alias of the key generated.                        |
| srcKeyAliasSecond   | string      | Yes  | Alias of key 2 generated.          |
| huksOptions         | HuksOptions | Yes  | Tags required for generating the key.              |
| finishOptionsFrist  | HuksOptions | Yes  | Tags required for key agreement.              |
| finishOptionsSecond | HuksOptions | Yes  | Tags required for key agreement.|

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

```ts
/* The agree() operation supports ECDH, DH, and X25519 keys.
 *
 * The following uses the Promise() operation of an X25519 256-bit TEMP key as an example.
 */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
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

let srcKeyAliasFirst = "AgreeX25519KeyFirstAlias";
let srcKeyAliasSecond = "AgreeX25519KeySecondAlias";
let agreeX25519InData = 'AgreeX25519TestIndata';
let handle;
let exportKey;
let exportKeyFrist;
let exportKeySecond;

async function testAgree() {
    /* Configure the parameters for generating the key. */
    let properties = new Array();
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
    let HuksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }

    /* 1. Generate two keys and export them. */
    await publicGenKeyFunc(srcKeyAliasFirst, HuksOptions);
    await publicGenKeyFunc(srcKeyAliasSecond, HuksOptions);

    await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
    exportKeyFrist = exportKey;
    await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
    exportKeySecond = exportKey;

    /* Configure parameters for the first key agreement. */
    let finishProperties = new Array();
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
    let finishOptionsFrist = {
        properties: finishProperties,
        inData: StringToUint8Array(agreeX25519InData)
    }

    /* Obtain the first agreed key. */
    await publicInitFunc(srcKeyAliasFirst, HuksOptions);
    HuksOptions.inData = exportKeySecond;
    await publicUpdateFunc(handle, HuksOptions);
    await publicFinishFunc(handle, finishOptionsFrist);

    /* Configure parameters for the second key agreement. */
    let finishOptionsSecond = {
        properties: finishProperties,
        inData: StringToUint8Array(agreeX25519InData)
    }
    finishOptionsSecond.properties.splice(6, 1, {
        tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
        value: StringToUint8Array(srcKeyAliasSecond + 'final'),
    })

    /* Obtain the second agreed key. */
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

### Key Derivation

Derive one or more keys from a key.

The development procedure is as follows:

1. Generate a key.
2. Derive a key.

**Supported key types**:

The **HksInit()** and **HksFinish()** APIs have requirements on **paramSet**. The **HksUpdate()** API has no requirements on **paramSet**.

Requirements of **HksInit()** for **paramSet**:

| HUKS_TAG_ALGORITHM                                           | HUKS_TAG_PURPOSE        | HUKS_TAG_DIGEST                                            | HUKS_TAG_DERIVE_KEY_SIZE |
| ------------------------------------------------------------ | ----------------------- | ---------------------------------------------------------- | ------------------------ |
| HUKS_ALG_HKDF (supported key lengths: HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256)| HUKS_KEY_PURPOSE_DERIVE | HUKS_DIGEST_SHA256 HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512  | Mandatory                |
| HUKS_ALG_PBKDF2 (supported key lengths: HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256)| HUKS_KEY_PURPOSE_DERIVE | HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512| Mandatory                |

Requirements of **HksFinish()** for **paramSet**:

The derived key is used as a symmetric key.

| HUKS_TAG_KEY_STORAGE_FLAG      | HUKS_TAG_KEY_ALIAS | HUKS_TAG_IS_KEY_ALIAS | HUKS_TAG_ALGORITHM | HUKS_TAG_KEY_SIZE                                            | HUKS_TAG_PURPOSE                                   | HUKS_TAG_PADDING                      | HUKS_TAG_DIGEST                                              | HUKS_TAG_BLOCK_MODE                         |
| ------------------------------ | ------------------ | --------------------- | ------------------ | ------------------------------------------------------------ | -------------------------------------------------- | ------------------------------------- | ------------------------------------------------------------ | ------------------------------------------- |
| **HUKS_STORAGE_TEMP** or not set| Not required            | TRUE                  | Not required            | Not required                                                      | Not required                                            | Not required                               | Not required                                                      | Not required                                     |
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256| HUKS_KEY_PURPOSE_ENCRYPT or HUKS_KEY_PURPOSE_DECRYPT| HUKS_PADDING_NONE, HUKS_PADDING_PKCS7| Optional                                                  | HUKS_MODE_CBC  HUKS_MODE_ECB                |
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256| HUKS_KEY_PURPOSE_ENCRYPT or HUKS_KEY_PURPOSE_DECRYPT| HUKS_PADDING_NONE                     | Optional                                                  | HUKS_MODE_CCM, HUKS_MODE_GCM, HUKS_MODE_CTR|
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256| HUKS_KEY_PURPOSE_DERIVE                            | Optional                           | HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512  | Optional                                 |
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_HMAC      | Multiple of 8, in bits                                        | HUKS_KEY_PURPOSE_MAC                               | Optional                           | HUKS_DIGEST_SHA1, HUKS_DIGEST_SHA224, HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512| Optional                                 |

> **NOTE**<br>
>
> The length of the derived key (converted into bits) must be greater than or equal to the selected **HUKS_TAG_KEY_SIZE**.
>
> The key alias cannot exceed 64 bytes.

Before you get started, understand the following variables:

| Parameter       | Type       | Mandatory| Description            |
| ------------- | ----------- | ---- | ---------------- |
| srcKeyAlias   | string      | Yes  | Alias of the key generated.  |
| huksOptions   | HuksOptions | Yes  | Parameters for generating the key.|
| finishOptions | HuksOptions | Yes  | Parameters for deriving a key.|

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

```ts
/*The derive() operation supports HKDF and pbdkf keys.
 *
 * The following uses the Promise() operation of an HKDF256 key as an example.
 */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
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

let deriveHkdfInData = "deriveHkdfTestIndata";
let srcKeyAlias = "deriveHkdfKeyAlias";
let handle;
let HuksKeyDeriveKeySize = 32;

async function testDerive() {
    /* Configure the parameters for generating the key. */
    let properties = new Array();
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
    let huksOptions = {
        properties: properties,
        inData: new Uint8Array(new Array())
    }

    /* Generate a key. */
    await publicGenKeyFunc(srcKeyAlias, huksOptions);

    /* Modify the parameter set for init(). */
    huksOptions.properties.splice(0, 1, {
        tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
        value: huks.HuksKeyAlg.HUKS_ALG_HKDF,
    });
    huksOptions.properties.splice(3, 1, {
        tag: huks.HuksTag.HUKS_TAG_DERIVE_KEY_SIZE,
        value: HuksKeyDeriveKeySize,
    });

    let finishProperties = new Array();
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
    let finishOptions = {
        properties: finishProperties,
        inData: new Uint8Array(new Array())
    }

    /* Derive a key. */
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

### Key MAC

A message authentication code (MAC) is a hash-based value used for authenticating a message. It is used to check whether the message comes from the stated sender and has not been changed.

The development procedure is as follows:

1. Generate a key.
2. Generate a MAC.

**Supported key types**:

Only **HksInit()** has requirements on parameters in **paramSet**. The other Init-Update-Finish APIs have no requirements on **paramSet**.

| HUKS_TAG_ALGORITHM | HUKS_TAG_KEY_SIZE | HUKS_TAG_PURPOSE    | HUKS_TAG_DIGEST                                              | HUKS_TAG_PADDING | HUKS_TAG_BLOCK_MODE |
| ------------ | ---------- | ------------------- | ------------------------------------------------------------ | ---------- | ---------- |
| HUKS_ALG_HMAC | Optional| HUKS_KEY_PURPOSE_MAC | HUKS_DIGEST_SHA1, HUKS_DIGEST_SHA224, HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512| Optional| Optional|
| HUKS_ALG_SM3 | Optional| HUKS_KEY_PURPOSE_MAC | HUKS_DIGEST_SM3                                              | Optional| Optional|

> **NOTE**<br>
>
> The key alias cannot exceed 64 bytes.

Before you get started, understand the following variables:

| Parameter     | Type       | Mandatory| Description          |
| ----------- | ----------- | ---- | -------------- |
| srcKeyAlias | string      | Yes  | Alias of the key generated.|
| huksOptions | HuksOptions | Yes  | Key parameter set.  |

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

```ts
/*The mac() operation supports HMAC and SM3 keys.
 *
 * The following uses the Promise() operation of an SM3 256-bit key as an example.
 */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
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

let srcKeyAlias = "sm3KeyAlias";
let hmacInData = 'sm3TestIndata';
let handle;

async function testMac() {
    /* Configure the parameters for generating the key. */
    let properties = new Array();
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
    let huksOptions = {
        properties:properties,
        inData:new Uint8Array(new Array())
    }

    /* Generate a key. */
    await publicGenKeyFunc(srcKeyAlias, huksOptions);

    /* Modify the parameter set for init() and perform the mac operation. */
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

After an application generates an asymmetric key, the certificate chain can be obtained through ID attestation. ID attestation supports the following device: brand, device, product, serial number, IMEI, MEID, manufacturer, model, SOC ID, and UDID.

The application can also obtain the certificate chain through key attestation.

ID attestation and key attestation are available only for devices in a trusted execution Environment (TEE).

The development procedure is as follows:

1. Generate a certificate.
2. Obtain certificate information.

**Supported key types**:

RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, ECC224, ECC256, ECC384, ECC521, X25519

> **NOTE**<br>
>
> The key alias cannot exceed 64 bytes.

Before you get started, understand the following variables:

| Parameter  | Type       | Mandatory| Description                                |
| -------- | ----------- | ---- | ------------------------------------ |
| keyAlias | string      | Yes  | Alias of the key. The certificate to be obtained stores the key.|
| options  | HuksOptions | Yes  | Parameters and data required for obtaining the certificate.  |

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

```ts
/* The following is an example of ID attestation. */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
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

let securityLevel = StringToUint8Array('sec_level');
let challenge = StringToUint8Array('challenge_data');
let versionInfo = StringToUint8Array('version_info');
let udid = StringToUint8Array('udid');
let serial = StringToUint8Array('serial');
let deviceId = StringToUint8Array('device_id');
let idAliasString = "id attest";

async function testAttestId() {
    let aliasString = idAliasString;
    let aliasUint8 = StringToUint8Array(aliasString);

    /* Configure parameters and generate a key. */
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
    await publicGenKeyFunc(aliasString, options);

    /* Configure the certificate parameter set. */
    let attestProperties = new Array();
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
    let huksOptions = {
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

After an application generates an asymmetric key, the certificate chain can be obtained by key attestation. You can also use ID attestation to obtain the certificate chain. The public certificate contains information such as the device ID.

ID attestation and key attestation are available only for devices in a trusted execution Environment (TEE).

The development procedure is as follows:

1. Generate a certificate.
2. Obtain certificate information.

**Supported key types**:

RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, ECC224, ECC256, ECC384, ECC521, X25519

> **NOTE**<br>
>
> The key alias cannot exceed 64 bytes.

Before you get started, understand the following variables:

| Parameter  | Type       | Mandatory| Description                                |
| -------- | ----------- | ---- | ------------------------------------ |
| keyAlias | string      | Yes  | Alias of the key. The certificate to be obtained stores the key.|
| options  | HuksOptions | Yes  | Parameters and data required for obtaining the certificate.  |

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

```ts
/* The following is an example of AttestKey. */
import huks from '@ohos.security.huks';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
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

let securityLevel = StringToUint8Array('sec_level');
let challenge = StringToUint8Array('challenge_data');
let versionInfo = StringToUint8Array('version_info');
let keyAliasString = "key attest";

async function testAttestKey() {
    let aliasString = keyAliasString;
    let aliasUint8 = StringToUint8Array(aliasString);

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
    await publicGenKeyFunc(aliasString, options);

    /* Configure the certificate parameter set. */
    let attestProperties = new Array();
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
    let huksOptions = {
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
