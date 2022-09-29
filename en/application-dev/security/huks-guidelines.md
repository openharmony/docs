# HUKS Development

## When to Use

 OpenHarmony Universal KeyStore (HUKS) provides KeyStore (KS) capabilities for applications, including key management and key cryptography operations. HUKS also provides APIs for applications to import or generate keys.

## JS-based Development

1. Import the HUKS module.

   ```js
   import huks from '@ohos.security.huks'
   ```

2. Call **generateKey()** to generate a key.

   **keyAlias** indicates the alias of the key generated. **options** indicates the parameters used for generating the key. Set **options** based on the algorithms to be used.

   The return value indicates whether the key is successfully generated.

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

3. Call **Init()** to initialize data for a key operation.

   **Alias** indicates the alias of the key, and **options** indicates the parameters used for initialization. Set **options** based on the algorithms to be used.

   The return value indicates whether the **Init** operation is successful.

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

4. Call **update()** to add data for the key operation by segment.

   **handle** indicates the session ID for the **update** operation. **options** indicates the parameters used for the **update** operation. Set **options** based on the algorithms to be used.

   The return value indicates whether the **update** operation is successful.

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

5. Call **finish()** to complete the operation.

   **handle** indicates the session ID of the **finish** operation. **options** indicates the parameters used for this operation. Set **options** based on the algorithms to be used.

   The return value indicates whether the **finish** operation is successful.

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

## TS-based Development

### Key Import and Export

The **HUKS** module allows an application to export the public key of its own asymmetric keys (public/private key pairs) based on the key alias.

The **HUKS** module also supports import of external keys. Except the public keys of asymmetric keys, the keys imported into the HUKS cannot be exported in their lifecycle. If the alias of the key to be imported already exists in HUKS, the newly imported key will overwrite the existing one.

The development procedure is as follows:

1. Generate a key.
2. Export the key.
3. Import the key.

**Supported types of keys to import**

AES128, AES192, AES256, RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, HmacSHA1, HmacSHA224, HmacSHA256, HmacSHA384, HmacSHA512, ECC224, ECC256, ECC384, ECC521, Curve25519, DSA, SM2, SM3, SM4

**Supported types of keys to export**

RSA512, RSA768, RSA1024, RSA2048, RSA3072, RSA4096, ECC224, ECC256, ECC384, ECC521, Curve25519, DSA, SM2

> **NOTE**<br>
>
> The key alias cannot exceed 64 bytes.

Before you get started, understand the following variables:

| Parameter           | Type       | Mandatory| Description                    |
| ----------------- | ----------- | ---- | ------------------------ |
| srcKeyAlias       | string      | Yes  | Alias of the key generated.          |
| srcKeyAliasSecond | string      | Yes  | Alias of the key imported.          |
| huksOptions       | HuksOptions | Yes  | Tags required for generating the key.|
| encryptOptions    | HuksOptions | Yes  | Tags required for importing the key.|

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

```ts
/* Generate an RSA512 key. */
var srcKeyAlias = 'hukRsaKeyAlias';
var srcKeyAliasSecond = 'huksRsaKeyAliasSecond';
var exportKey;

async function testImportExport() {
    /* Configure the parameters for generating the key. */
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

    /* Generate a key. */
    await huks.generateKey(srcKeyAlias, huksOptions).then((data) => {
        console.info(`test generateKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test generateKey err information: ' + JSON.stringify(err));
    });

    /* Export the key. */
    await huks.exportKey(srcKeyAlias, huksOptions).then((data) => {
        console.info(`test ExportKey data: ${JSON.stringify(data)}`);
        exportKey = data.outData;
    }).catch((err) => {
        console.info('test ImportKey err information: ' + JSON.stringify(err));
    });

    /* Configure parameters for importing the key. */
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

    /* Import the key. */
    encryptOptions.inData = exportKey;
    await huks.importKey(srcKeyAliasSecond, encryptOptions).then((data) => {
        console.info(`test ImportKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test ImportKey err information: ' + JSON.stringify(err));
    });
}
```

### Secure key Import

The service invoker and HUKS negotiate a shared symmetric key to encrypt and decrypt the intermediate key and the key to be imported. After the encrypted key is imported, it is decrypted and saved in HUKS. The keys in plaintext can be processed in HUKS only.

The development procedure is as follows:

1.   Generate a key pair in HUKS. The key pair is used to encrypt the key to import.
2.  Export the public key of the key pair and obtain a shared key through key agreement.
3.  Generate intermediate key materials and encrypt the key.
4.  Import the key.

**Supported key types**:

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
| genWrapOptions | HuksOptions | Yes  | Tags required for generating the wrapping the key.|
| importOptions  | HuksOptions | Yes  | Tags required for importing the encrypted key.    |

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

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

### Key Encryption and Decryption

Use the symmetric or asymmetric key stored in HUKS to encrypt or decrypt data based on the specified alias. The keys in plaintext must be in a secure environment during the encryption and decryption process.

The development procedure is as follows:

1. Generate a key.
2. Encrypt the key.
3. Decrypt the key.

**Supported key types**:

| HUKS_ALG_ALGORITHM                                           | HUKS_TAG_PURPOSE                                   | HUKS_TAG_DIGEST                                              | HUKS_TAG_PADDING                                             | HUKS_TAG_BLOCK_MODE                         | HUKS_TAG_IV |
| ------------------------------------------------------------ | -------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------- | ----------- |
| HUKS_ALG_SM4 (supported key length: HUKS_SM4_KEY_SIZE_128)| HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT | Optional                                                  | HUKS_PADDING_NONE                                            | HUKS_MODE_CTR  HUKS_MODE_ECB  HUKS_MODE_CBC | Mandatory   |
| HUKS_ALG_SM4 (supported key length: HUKS_SM4_KEY_SIZE_128)| HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT | Optional                                                  | HUKS_PADDING_PKCS7                                           | HUKS_MODE_ECB  HUKS_MODE_CBC                | Mandatory   |
| HUKS_ALG_RSA (supported key lengths: HUKS_SM4_KEY_SIZE_512, HUKS_SM4_KEY_SIZE_768, HUKS_SM4_KEY_SIZE_1024, HUKS_SM4_KEY_SIZE_2048, HUKS_SM4_KEY_SIZE_3072, HUKS_SM4_KEY_SIZE_4096)| HUKS_KEY_PURPOSE_ENCRYPT  HUKS_KEY_PURPOSE_DECRYPT | HUKS_DIGEST_SHA1 HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 | HUKS_PADDING_NONE  HUKS_PADDING_PKCS1_V1_5  HUKS_PADDING_OAEP | HUKS_MODE_ECB                               | Optional |

| HUKS_ALG_ALGORITHM                                           | HUKS_TAG_PURPOSE         | HUKS_TAG_PADDING                      | HUKS_TAG_BLOCK_MODE          | HUKS_TAG_IV | HUKS_TAG_NONCE | HUKS_TAG_ASSOCIATED_DATA | HUKS_TAG_AE_TAG |
| ------------------------------------------------------------ | ------------------------ | ------------------------------------- | ---------------------------- | ----------- | -------------- | ------------------------ | --------------- |
| HUKS_ALG_AES (supported key lengths: HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256)| HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_NONE  HUKS_PADDING_PKCS7 | HUKS_MODE_CBC                | Mandatory   | Optional    | Optional              | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CCM  HUKS_MODE_GCM | Optional | Mandatory      | Mandatory                | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CTR                | Mandatory   | Optional    | Optional              | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_ENCRYPT | HUKS_PADDING_PKCS7  HUKS_PADDING_NONE | HUKS_MODE_ECB                | Mandatory   | Optional    | Optional              | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE  HUKS_PADDING_PKCS7 | HUKS_MODE_CBC                | Mandatory   | Optional    | Optional              | Mandatory       |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CCM  HUKS_MODE_GCM | Optional | Mandatory      | Mandatory                | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE                     | HUKS_MODE_CTR                | Mandatory   | Optional    | Optional              | Optional     |
| HUKS_ALG_AES                                                 | HUKS_KEY_PURPOSE_DECRYPT | HUKS_PADDING_NONE  HUKS_PADDING_PKCS7 | HUKS_MODE_ECB                | Mandatory   | Optional    | Optional              | Optional     |

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
    /* Integrate the key generation parameter set and key encryption parameter set. */
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

    /* Generate a key. */
    await huks.generateKey(srcKeyAlias, huksOptions).then((data) => {
        console.info(`test generateKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test generateKey err information: ' + JSON.stringify(err));
    });

    /* Encrypt the key. */
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

    /* Modify the key encryption parameter set to the decryption parameter set. */
    propertiesEncrypt.splice(1, 1, {
        tag: huks.HuksTag.HUKS_TAG_PURPOSE,
        value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
    });
    var decryptOptions = {
        properties: propertiesEncrypt,
        inData: new Uint8Array(new Array())
    }

    /* Decrypt the key. */
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

**Example 2:**

```ts
/* The cipher operation supports RSA, AES, and SM4 keys.
 *
 * The following uses the Promise() operation of an AES128 GCM key as an example.
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
    /* Integrate the key generation parameter set and key encryption parameter set. */
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

    /* Generate a key. */
    await huks.generateKey(srcKeyAlias, HuksOptions).then((data) => {
        console.info(`test generateKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test generateKey err information: ' + JSON.stringify(err));
    });

    /* Encrypt the key. */
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

    /* Modify the key encryption parameter set to the decryption parameter set. */
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

    /* Decrypt the key. */
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
| HUKS_ALG_RSA       | HUKS_RSA_KEY_SIZE_512, HUKS_RSA_KEY_SIZE_768, HUKS_RSA_KEY_SIZE_1024, HUKS_RSA_KEY_SIZE_2048, HUKS_RSA_KEY_SIZE_3072, HUKS_RSA_KEY_SIZE_4096| HUKS_KEY_PURPOSE_SIGN  HUKS_KEY_PURPOSE_VERIFY | HUKS_PADDING_PSS        | HUKS_DIGEST_SHA1, HUKS_DIGEST_SHA224, HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512|
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

| Parameter              | Type       | Mandatory| Description                    |
| -------------------- | ----------- | ---- | ------------------------ |
| srcRsaKeyAliasSign   | string      | Yes  | Alias of the key generated.          |
| srcRsaKeyAliasVerify | string      | Yes  | Alias of the key imported.          |
| rsaSignOptions       | HuksOptions | Yes  | Tags required for generating the key.|
| rsaSignOptionsSecond | HuksOptions | Yes  | Tags required for signing.|
| rsaVerifyOptions     | HuksOptions | Yes  | Tags required for verifying the signature.|

For details about the APIs, see [HUKS](../reference/apis/js-apis-huks.md).

**Example**

```ts
/*The Sign() and Verify() operations support RSA, ECC, SM2, ED25519, and DSA keys.
 *
 * The following uses the Promise() operation of an RSA512 key as an example.
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
    /* Integrate the key generation parameter set, signing parameter set, and signature verification parameter set. */
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

    /* Generate a key. */
    await huks.generateKey(srcRsaKeyAliasSign, rsaSignOptions).then((data) => {
        console.info(`test generateKey data: ${JSON.stringify(data)}`);
    }).catch((err) => {
        console.info('test generateKey err information: ' + JSON.stringify(err));
    });

    /* Use the key to sign the data to be sent. */
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

    /* Obtain a segment of key data. */
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

    /* Verify the signature. */
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
| srcKeyAliasFirst    | string      | Yes  | Alias of key 1 generated.                        |
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
    /* Configure the parameters for generating the key. */
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

    /* 1. Generate two keys and export them. */
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

    /* Configure parameters for the first key agreement. */
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
    
    /* Obtain the first agreed key. */
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

    /* Configure parameters for the second key agreement. */
    var finishOptionsSecond = {
        properties: finishProperties,
        inData: AgreeStringToUint8Array(agreeX25519InData)
    }
    finishOptionsSecond.properties.splice(6, 1, {
        tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
        value: AgreeStringToUint8Array(srcKeyAliasSecond + 'final'),
    })
    
    /* Obtain the second agreed key. */
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

### Key Derivation

Derive one or more keys from a key.

The development procedure is as follows:

1. Generate a key.
2. Derive a key.

**Supported key types**:

**HksInit()** and **HksFinish()** have requirements on **paramSet**. **HksUpdate()** has no requirements on **paramSet**.

Requirements of **HksInit()** for **paramSet**:

| HUKS_TAG_ALGORITHM                                           | HUKS_TAG_PURPOSE        | HUKS_TAG_DIGEST                                            | HUKS_TAG_DERIVE_KEY_SIZE |
| ------------------------------------------------------------ | ----------------------- | ---------------------------------------------------------- | ------------------------ |
| HUKS_ALG_HKDF (supported key lengths: HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256)| HUKS_KEY_PURPOSE_DERIVE | HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512| Mandatory                |
| HUKS_ALG_PBKDF2 (supported key lengths: HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256)| HUKS_KEY_PURPOSE_DERIVE | HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512| Mandatory                |

Requirements of **HksFinish()** for **paramSet**:

The derived key is used as a symmetric key.

| HUKS_TAG_KEY_STORAGE_FLAG      | HUKS_TAG_KEY_ALIAS | HUKS_TAG_IS_KEY_ALIAS | HUKS_TAG_ALGORITHM | HUKS_TAG_KEY_SIZE                                            | HUKS_TAG_PURPOSE                                   | HUKS_TAG_PADDING                      | HUKS_TAG_DIGEST                                              | HUKS_TAG_BLOCK_MODE                         |
| ------------------------------ | ------------------ | --------------------- | ------------------ | ------------------------------------------------------------ | -------------------------------------------------- | ------------------------------------- | ------------------------------------------------------------ | ------------------------------------------- |
| **HUKS_STORAGE_TEMP** or not set| Not required            | TRUE                  | Not required            | Not required                                                      | Not required                                            | Not required                               | Not required                                                      | Not required                                     |
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256| HUKS_KEY_PURPOSE_ENCRYPT or HUKS_KEY_PURPOSE_DECRYPT| HUKS_PADDING_NONE, HUKS_PADDING_PKCS7| Optional                                                  | HUKS_MODE_CBC  HUKS_MODE_ECB                |
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256| HUKS_KEY_PURPOSE_ENCRYPT or HUKS_KEY_PURPOSE_DECRYPT| HUKS_PADDING_NONE                     | Optional                                                  | HUKS_MODE_CCM, HUKS_MODE_GCM, HUKS_MODE_CTR|
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_AES       | HUKS_AES_KEY_SIZE_128, HUKS_AES_KEY_SIZE_192, HUKS_AES_KEY_SIZE_256| HUKS_KEY_PURPOSE_DERIVE                            | Optional                           | HUKS_DIGEST_SHA256, HUKS_DIGEST_SHA384, HUKS_DIGEST_SHA512  | Optional                                 |
| HUKS_STORAGE_PERSISTENT        | (Mandatory) Maximum 64 bytes.| TRUE                  | HUKS_ALG_HMAC      | Multiple of 8, in bits                                        | HUKS_KEY_PURPOSE_MAC                               | Optional                           | HUKS_DIGEST_SHA1  HUKS_DIGEST_SHA224  HUKS_DIGEST_SHA256  HUKS_DIGEST_SHA384  HUKS_DIGEST_SHA512 | Optional                                 |

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
    /* Configure the parameters for generating the key. */
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

    /* Generate a key. */
    await huks.generateKey(srcKeyAlias, huksOptions).then((data) => {
        console.info('test generateKey data = ' + JSON.stringify(data));
    }).catch((err) => {
        console.info(`test init err: " + ${JSON.stringify(err)}`);
    });

    /* Modify the parameter set for init(). */
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

    /* Derive a key. */
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
    /* Configure the parameters for generating the key. */
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

    /* Generate a key. */
    await huks.generateKey(srcKeyAlias, huksOptions).then((data) => {
        console.info('test generateKey data = ' + JSON.stringify(data));
    }).catch((err) => {
        console.info(`test init err: " + ${JSON.stringify(err)}`);
    });

    /* Modify the parameter set for init() and perform the mac operation. */
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

/* Configure parameters and generate a key. */
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

    /* Configure the certificate parameter set. */
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

/* Configure parameters and generate a key. */
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

    /* Configure the certificate parameter set. */
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
