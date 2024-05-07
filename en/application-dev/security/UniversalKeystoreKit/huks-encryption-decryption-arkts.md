# Encryption and Decryption (ArkTS)

The topic uses a 128-bit AES key as an example to describe how to encrypt and decrypt data. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).

## How to Develop

**Key Generation**

1. Set the key alias.

2. Initialize the key property set.

3. Use [generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) to generate a key. For details, see [Key Generation](huks-key-generation-overview.md).

Alternatively, you can [import a key](huks-key-import-overview.md).

**Encryption**

1. Obtain the key alias.

2. Obtain the data to be encrypted.

3. Obtain the [algorithm parameters](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) for encryption.<br>
   If AES is used for encryption, the cipher mode and padding mode must be specified. In the following example, the cipher mode is **CBC** and the padding mode is **PKCS7**. In this case, the IV must be set.

4. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

5. Use [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) with the session handle to obtain the ciphertext.

**Decryption**

1. Obtain the key alias.

2. Obtain the ciphertext to be decrypted.

3. Obtain the [algorithm parameters](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) for decryption.<br>
   The parameters vary with the decryption algorithm to be used. For details, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).

   If AES is used for decryption, the cipher mode and padding mode must be specified. In the following example, the cipher mode is **CBC** and the padding mode is **PKCS7**. In this case, the IV must be set.

4. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

5. Use [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) to obtain the data decrypted.

**Key Deletion**

Use [deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9) to delete the key that is not required. For details, see [Deleting a Key](huks-delete-key-arkts.md).

```ts
/*
 * Use a 128-bit AES to encrypt and decrypt data. The following example uses promise-based APIs.
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
    * Simulate the key generation scenario.
    * 1. Set the key alias.
    */
    /*
    * 2. Obtain the parameters for key generation.
    */
    let genProperties = GetAesGenerateProperties();
    let options: huks.HuksOptions = {
        properties: genProperties
    }
    /*
    * 3. Call generateKeyItem.
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
    * Simulate the encryption scenario.
    * 1. Obtain the key alias.
    */
    /*
    * 2. Obtain the data to be encrypted.
    */
    /*
    * 3. Obtain the algorithm parameters for encryption.
    */
    let encryptProperties = GetAesEncryptProperties();
    let options: huks.HuksOptions = {
        properties: encryptProperties,
        inData: StringToUint8Array(plainText)
    }
    /*
    * 4. Call initSession to obtain a session handle.
    */
    await huks.initSession(aesKeyAlias, options)
    .then((data) => {
        handle = data.handle;
    }).catch((error: BusinessError)=>{
        console.error(`promise: init encryptdata failed` + error);
    })
    /*
    * 5. Call finishSession to obtain the ciphertext.
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
    * Simulate the decryption scenario.
    * 1. Obtain the key alias.
    */
    /*
    * 2. Obtain the ciphertext to be decrypted.
    */
    /*
    * 3. Obtain the algorithm parameters for decryption.
    */
    let decryptOptions = GetAesDecryptProperties()
    let options: huks.HuksOptions = {
        properties: decryptOptions,
        inData: cipherData
    }
    /*
    * 4. Call initSession to obtain a session handle.
    */
    await huks.initSession(aesKeyAlias, options)
    .then((data) => {
        handle = data.handle;
    }).catch((error: BusinessError)=>{
        console.error(`promise: init decryptdata failed` + error);
    })
    /*
    * 5. Call finishSession to obtain the decrypted data.
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
    * Simulate the key deletion scenario.
    * 1. Obtain the key alias.
    */
    let emptyOptions: huks.HuksOptions = {
        properties: []
    }
    /*
    * 2. Call deleteKeyItem to delete the key.
    */
    await huks.deleteKeyItem(aesKeyAlias, emptyOptions)
    .then((data) => {
        console.info(`promise: delete data success`);
    }).catch((error: BusinessError)=>{
        console.error(`promise: delete data failed` + error);
    })
}
```
