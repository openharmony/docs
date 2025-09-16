# Encryption and Decryption (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

This topic walks you through on how to perform encryption and decryption using AES128, RSA2048, and SM2. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-encryption-decryption-overview.md#supported-algorithms).

## How to Develop

**Key Generation**

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the key property set.

3. Use [generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) to generate a key. For details, see [Key Generation](huks-key-generation-overview.md).

Alternatively, you can [import a key](huks-key-import-overview.md).

**Encryption**

1. Obtain the key alias.

2. Obtain the data to be encrypted.

3. Obtain the [algorithm parameters](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) for encryption.

   The parameters to be configured vary with the algorithm used.
   - If the AES algorithm, CBC block mode, and PKCS7 padding mode are used for encryption, the **IV** parameter must be set. For details, see [AES/CBC/PKCS7](#aescbcpkcs7).
   - If the AES algorithm and GCM block mode are used for encryption, the **NONCE** parameter is mandatory and **AAD** is optional. For details, see [AES/GCM/NoPadding](#aesgcmnopadding).
   - If the RSA algorithm is used for encryption, you need to select the corresponding block mode, padding mode, and digest algorithm. For details, see [RSA/ECB/PKCS1_V1_5](#rsaecbpkcs1_v1_5) and [RSA/ECB/OAEP/SHA256](#rsaecboaepsha256).
   - If the SM2 algorithm is used for encryption, the digest algorithm must be SM3. For details, see [SM2](#sm2).
   
   For details about the specifications, see [Encryption and Decryption Overview and Algorithm Specifications](huks-encryption-decryption-overview.md).

4. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

5. Use [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) with the session handle to obtain the ciphertext.

**Decryption**

1. Obtain the key alias.

2. Obtain the ciphertext to be decrypted.

3. Obtain the [algorithm parameters](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksparam) for decryption.

   The parameters to be configured vary with the algorithm used.
   - If the AES algorithm and GCM block mode are used for decryption, **NONCE** and **AEAD** are mandatory and **AAD** is optional. For details, see [AES/GCM/NoPadding](#aesgcmnopadding).
   - The requirements for the parameters in the other development cases are the same as those in the encryption.
   
   For details about the specifications, see [Encryption and Decryption Overview and Algorithm Specifications](huks-encryption-decryption-overview.md).

4. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

5. Use [finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) to obtain the data decrypted.

**Key Deletion**

Use [deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9) to delete the key that is not required. For details, see [Deleting a Key](huks-delete-key-arkts.md).

## Development Cases

### AES/CBC/PKCS7

```ts
/*
 * The following uses AES/CBC/PKCS7 with promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let aesKeyAlias = 'test_aesKeyAlias';
let handle: number;
let plainText = '123456';
let IV = '001122334455'; // Replace this example code with a random value in practice.
let cipherData: Uint8Array;

function StringToUint8Array(str: string) {
  let arr: number[] = new Array();
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < fileData.length; i++) {
    dataString += String.fromCharCode(fileData[i]);
  }
  return dataString;
}

function GetAesGenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }];
  return properties;
}

function GetAesEncryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: StringToUint8Array(IV)
  }];
  return properties;
}

function GetAesDecryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS7
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: StringToUint8Array(IV)
  }];
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
    }).catch((error: Error) => {
      console.error(`promise: generate AES Key failed, ${JSON.stringify(error)}`);
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
    }).catch((error: Error) => {
      console.error(`promise: init EncryptData failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the ciphertext.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: encrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      cipherData = data.outData as Uint8Array;
    }).catch((error: Error) => {
      console.error(`promise: encrypt data failed, ${JSON.stringify(error)}`);
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
    }).catch((error: Error) => {
      console.error(`promise: init DecryptData failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the decrypted data.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: decrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((error: Error) => {
      console.error(`promise: decrypt data failed, ${JSON.stringify(error)}`);
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
    }).catch((error: Error) => {
      console.error(`promise: delete data failed, ${JSON.stringify(error)}`);
    })
}

export async function TestEncryptDecrypt()
{
  await GenerateAesKey();
  await EncryptData();
  await DecryptData();
  await DeleteKey();
}
```

### AES/GCM/NoPadding

```ts
/*
 * The following uses AES/GCM/NoPadding with promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let aesKeyAlias = 'test_aesKeyAlias';
let handle: number;
let plainText = '123456';
let cipherData: Uint8Array;
let AAD = '1234567890123456';
let NONCE = '001122334455'; // Replace this example code with a random value in practice.

function StringToUint8Array(str: string) {
  let arr: number[] = new Array();
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < fileData.length; i++) {
    dataString += String.fromCharCode(fileData[i]);
  }
  return dataString;
}

function GetAesGenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }];
  return properties;
}

function GetAesGcmEncryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_GCM
  }, {
    tag: huks.HuksTag.HUKS_TAG_NONCE,
    value: StringToUint8Array(NONCE)
  }, {
    tag: huks.HuksTag.HUKS_TAG_ASSOCIATED_DATA,
    value: StringToUint8Array(AAD)
  }];
  return properties;
}

function GetAesGcmDecryptProperties(cipherData:Uint8Array) {
  let properties: Array<huks.HuksParam> = [
    {
      tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
      value: huks.HuksKeyAlg.HUKS_ALG_AES
    }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_GCM
  }, {
    tag: huks.HuksTag.HUKS_TAG_NONCE,
    value: StringToUint8Array(NONCE)
  }, {
    tag: huks.HuksTag.HUKS_TAG_ASSOCIATED_DATA,
    value: StringToUint8Array(AAD)
  }, {
    tag: huks.HuksTag.HUKS_TAG_AE_TAG,
    value: cipherData.slice(cipherData.length-16)
  }];
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
    }).catch((error: Error) => {
      console.error(`promise: generate AES Key failed, ${JSON.stringify(error)}`);
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
  let encryptProperties = GetAesGcmEncryptProperties();
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
    }).catch((error: Error) => {
      console.error(`promise: init EncryptDataGcm failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the ciphertext.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: encrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      cipherData = data.outData as Uint8Array;
    }).catch((error: Error) => {
      console.error(`promise: encrypt data failed, ${JSON.stringify(error)}`);
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
  let decryptOptions = GetAesGcmDecryptProperties(cipherData)
  let options: huks.HuksOptions = {
    properties: decryptOptions,
    inData: cipherData.slice(0, cipherData.length-16)
  }
  /*
  * 4. Call initSession to obtain a session handle.
  */
  await huks.initSession(aesKeyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init DecryptDataGcm failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the decrypted data.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: decrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((error: Error) => {
      console.error(`promise: decrypt data failed, ${JSON.stringify(error)}`);
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
    }).catch((error: Error) => {
      console.error(`promise: delete data failed, ${JSON.stringify(error)}`);
    })
}

export async function TestEncryptDecrypt()
{
  await GenerateAesKey();
  await EncryptData();
  await DecryptData();
  await DeleteKey();
}
```

### RSA/ECB/PKCS1_V1_5

```ts
/*
 * The following uses RSA/ECB/PKCS1_V1_5 with promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let rsaKeyAlias = 'test_rsaKeyAlias';
let handle: number;
let plainText = '123456';
let cipherData: Uint8Array;

function StringToUint8Array(str: string) {
  let arr: number[] = new Array();
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < fileData.length; i++) {
    dataString += String.fromCharCode(fileData[i]);
  }
  return dataString;
}

function GetRsaGenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }];
  return properties;
}

function GetRsaEncryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
  }];
  return properties;
}

function GetRsaDecryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
  }];
  return properties;
}

async function GenerateRsaKey() {
  /*
  * Simulate the key generation scenario.
  * 1. Set the key alias.
  */
  /*
  * 2. Obtain the parameters for key generation.
  */
  let genProperties = GetRsaGenerateProperties();
  let options: huks.HuksOptions = {
    properties: genProperties
  }
  /*
  * 3. Call generateKeyItem.
  */
  await huks.generateKeyItem(rsaKeyAlias, options)
    .then((data) => {
      console.info(`promise: generate RSA Key success, data = ${JSON.stringify(data)}`);
    }).catch((error: Error) => {
      console.error(`promise: generate RSA Key failed, ${JSON.stringify(error)}`);
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
  let encryptProperties = GetRsaEncryptProperties();
  let options: huks.HuksOptions = {
    properties: encryptProperties,
    inData: StringToUint8Array(plainText)
  }
  /*
  * 4. Call initSession to obtain a session handle.
  */
  await huks.initSession(rsaKeyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init EncryptDataRsa failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the ciphertext.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: encrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      cipherData = data.outData as Uint8Array;
    }).catch((error: Error) => {
      console.error(`promise: encrypt data failed, ${JSON.stringify(error)}`);
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
  let decryptOptions = GetRsaDecryptProperties()
  let options: huks.HuksOptions = {
    properties: decryptOptions,
    inData: cipherData
  }
  /*
  * 4. Call initSession to obtain a session handle.
  */
  await huks.initSession(rsaKeyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init DecryptDataRsa failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the decrypted data.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: decrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((error: Error) => {
      console.error(`promise: decrypt data failed, ${JSON.stringify(error)}`);
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
  await huks.deleteKeyItem(rsaKeyAlias, emptyOptions)
    .then((data) => {
      console.info(`promise: delete data success`);
    }).catch((error: Error) => {
      console.error(`promise: delete data failed, ${JSON.stringify(error)}`);
    })
}

export async function TestEncryptDecrypt()
{
  await GenerateRsaKey();
  await EncryptData();
  await DecryptData();
  await DeleteKey();
}
```

### RSA/ECB/OAEP/SHA256

```ts
/*
 * The following uses RSA/ECB/OAEP/SHA256 with promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let rsaKeyAlias = 'test_rsaKeyAlias';
let handle: number;
let plainText = '123456';
let cipherData: Uint8Array;

function StringToUint8Array(str: string) {
  let arr: number[] = new Array();
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < fileData.length; i++) {
    dataString += String.fromCharCode(fileData[i]);
  }
  return dataString;
}

function GetRsaGenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }];
  return properties;
}

function GetRsaEncryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_OAEP
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }];
  return properties;
}

function GetRsaDecryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_2048
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_OAEP
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  }];
  return properties;
}

async function GenerateRsaKey() {
  /*
  * Simulate the key generation scenario.
  * 1. Set the key alias.
  */
  /*
  * 2. Obtain the parameters for key generation.
  */
  let genProperties = GetRsaGenerateProperties();
  let options: huks.HuksOptions = {
    properties: genProperties
  }
  /*
  * 3. Call generateKeyItem.
  */
  await huks.generateKeyItem(rsaKeyAlias, options)
    .then((data) => {
      console.info(`promise: generate RSA Key success, data = ${JSON.stringify(data)}`);
    }).catch((error: Error) => {
      console.error(`promise: generate RSA Key failed, ${JSON.stringify(error)}`);
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
  let encryptProperties = GetRsaEncryptProperties();
  let options: huks.HuksOptions = {
    properties: encryptProperties,
    inData: StringToUint8Array(plainText)
  }
  /*
  * 4. Call initSession to obtain a session handle.
  */
  await huks.initSession(rsaKeyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init EncryptDataRsa failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the ciphertext.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: encrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      cipherData = data.outData as Uint8Array;
    }).catch((error: Error) => {
      console.error(`promise: encrypt data failed, ${JSON.stringify(error)}`);
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
  let decryptOptions = GetRsaDecryptProperties()
  let options: huks.HuksOptions = {
    properties: decryptOptions,
    inData: cipherData
  }
  /*
  * 4. Call initSession to obtain a session handle.
  */
  await huks.initSession(rsaKeyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init DecryptDataRsa failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the decrypted data.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: decrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((error: Error) => {
      console.error(`promise: decrypt data failed, ${JSON.stringify(error)}`);
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
  await huks.deleteKeyItem(rsaKeyAlias, emptyOptions)
    .then((data) => {
      console.info(`promise: delete data success`);
    }).catch((error: Error) => {
      console.error(`promise: delete data failed, ${JSON.stringify(error)}`);
    })
}

export async function TestEncryptDecrypt()
{
  await GenerateRsaKey();
  await EncryptData();
  await DecryptData();
  await DeleteKey();
}
```

### SM2

```ts
/*
 * The following uses SM2 with promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let sm2KeyAlias = 'test_sm2KeyAlias';
let handle: number;
let plainText = '123456';
let cipherData: Uint8Array;

function StringToUint8Array(str: string) {
  let arr: number[] = new Array();
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < fileData.length; i++) {
    dataString += String.fromCharCode(fileData[i]);
  }
  return dataString;
}

function GetSm2GenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }];
  return properties;
}

function GetSm2EncryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3
  }];
  return properties;
}

function GetSm2DecryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_SM2
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_SM2_KEY_SIZE_256
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SM3
  }];
  return properties;
}

async function GenerateSm2Key() {
  /*
  * Simulate the key generation scenario.
  * 1. Set the key alias.
  */
  /*
  * 2. Obtain the parameters for key generation.
  */
  let genProperties = GetSm2GenerateProperties();
  let options: huks.HuksOptions = {
    properties: genProperties
  }
  /*
  * 3. Call generateKeyItem.
  */
  await huks.generateKeyItem(sm2KeyAlias, options)
    .then((data) => {
      console.info(`promise: generate SM2 Key success, data = ${JSON.stringify(data)}`);
    }).catch((error: Error) => {
      console.error(`promise: generate SM2 Key failed, ${JSON.stringify(error)}`);
    })
}

async function EncryptDataSm2() {
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
  let encryptProperties = GetSm2EncryptProperties();
  let options: huks.HuksOptions = {
    properties: encryptProperties,
    inData: StringToUint8Array(plainText)
  }
  /*
  * 4. Call initSession to obtain a session handle.
  */
  await huks.initSession(sm2KeyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init EncryptDataSm2 failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the ciphertext.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: encrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      cipherData = data.outData as Uint8Array;
    }).catch((error: Error) => {
      console.error(`promise: encrypt data failed, ${JSON.stringify(error)}`);
    })
}

async function DecryptDataSm2() {
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
  let decryptOptions = GetSm2DecryptProperties()
  let options: huks.HuksOptions = {
    properties: decryptOptions,
    inData: cipherData
  }
  /*
  * 4. Call initSession to obtain a session handle.
  */
  await huks.initSession(sm2KeyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init DecryptDataSm2 failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the decrypted data.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: decrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((error: Error) => {
      console.error(`promise: decrypt data failed, ${JSON.stringify(error)}`);
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
  await huks.deleteKeyItem(sm2KeyAlias, emptyOptions)
    .then((data) => {
      console.info(`promise: delete data success`);
    }).catch((error: Error) => {
      console.error(`promise: delete data failed, ${JSON.stringify(error)}`);
    })
}

export async function TestEncryptDecrypt()
{
  await GenerateSm2Key();
  await EncryptDataSm2();
  await DecryptDataSm2();
  await DeleteKey();
}
```

<!--Del-->
### DES/CBC/NoPadding

```ts
/*
 * The following uses DES/CBC/NoPadding with promise-based APIs as an example.
 */
import { huks } from '@kit.UniversalKeystoreKit';

let desKeyAlias = 'test_desKeyAlias';
let handle: number;
let plainText = '12345678';
let IV = '12345678'; // Replace this example code with a random value in practice.
let cipherData: Uint8Array;

function StringToUint8Array(str: string) {
  let arr: number[] = new Array();
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function Uint8ArrayToString(fileData: Uint8Array) {
  let dataString = '';
  for (let i = 0; i < fileData.length; i++) {
    dataString += String.fromCharCode(fileData[i]);
  }
  return dataString;
}

function GetDesGenerateProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_DES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_DES_KEY_SIZE_64
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
    huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }];
  return properties;
}

function GetDesEncryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_DES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_DES_KEY_SIZE_64
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: StringToUint8Array(IV)
  }];
  return properties;
}

function GetDesDecryptProperties() {
  let properties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_DES
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_DES_KEY_SIZE_64
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  }, {
    tag: huks.HuksTag.HUKS_TAG_IV,
    value: StringToUint8Array(IV)
  }];
  return properties;
}

async function GenerateDesKey() {
  /*
  * Simulate the key generation scenario.
  * 1. Set the key alias.
  */
  /*
  * 2. Obtain the parameters for key generation.
  */
  let genProperties = GetDesGenerateProperties();
  let options: huks.HuksOptions = {
    properties: genProperties
  }
  /*
  * 3. Call generateKeyItem.
  */
  await huks.generateKeyItem(desKeyAlias, options)
    .then((data) => {
      console.info(`promise: generate DES Key success, data = ${JSON.stringify(data)}`);
    }).catch((error: Error) => {
      console.error(`promise: generate DES Key failed, ${JSON.stringify(error)}`);
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
  let encryptProperties = GetDesEncryptProperties();
  let options: huks.HuksOptions = {
    properties: encryptProperties,
    inData: StringToUint8Array(plainText)
  }
  /*
  * 4. Call initSession to obtain a session handle.
  */
  await huks.initSession(desKeyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init EncryptData failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the ciphertext.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: encrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
      cipherData = data.outData as Uint8Array;
    }).catch((error: Error) => {
      console.error(`promise: encrypt data failed, ${JSON.stringify(error)}`);
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
  let decryptOptions = GetDesDecryptProperties()
  let options: huks.HuksOptions = {
    properties: decryptOptions,
    inData: cipherData
  }
  /*
  * 4. Call initSession to obtain a session handle.
  */
  await huks.initSession(desKeyAlias, options)
    .then((data) => {
      handle = data.handle;
    }).catch((error: Error) => {
      console.error(`promise: init DecryptData failed, ${JSON.stringify(error)}`);
    })
  /*
  * 5. Call finishSession to obtain the decrypted data.
  */
  await huks.finishSession(handle, options)
    .then((data) => {
      console.info(`promise: decrypt data success, data is ` + Uint8ArrayToString(data.outData as Uint8Array));
    }).catch((error: Error) => {
      console.error(`promise: decrypt data failed, ${JSON.stringify(error)}`);
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
  await huks.deleteKeyItem(desKeyAlias, emptyOptions)
    .then((data) => {
      console.info(`promise: delete data success`);
    }).catch((error: Error) => {
      console.error(`promise: delete data failed, ${JSON.stringify(error)}`);
    })
}

export async function TestEncryptDecrypt()
{
  await GenerateDesKey();
  await EncryptData();
  await DecryptData();
  await DeleteKey();
}
```
<!--DelEnd-->
