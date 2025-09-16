# Importing a Key in Ciphertext (ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

This topic walks you through on how to import an ECDH key pair. However, the example does not cover the operations such as [key generation](huks-key-generation-overview.md) and [key agreement](huks-key-agreement-overview.md) of the service side.

For details about the scenarios and supported algorithm specifications, see [Supported Algorithms](huks-key-import-overview.md#supported-algorithms).

## How to Develop

1. Convert the key to be imported from device A (device from which the key is imported) to [HUKS key material format](huks-concepts.md#key material format) **To_Import_Key**. (This step applies only to asymmetric key pairs. If the key to be imported is a symmetric key, skip over this step.)

2. Generate an asymmetric key pair **Wrapping_Key** (public key **Wrapping_Pk** and private key **Wrapping_Sk**) with the purpose of **HUKS_KEY_PURPOSE_UNWRAP** for device B (device to which the key is imported), and export the public key **Wrapping_Pk** of **Wrapping_Key** and save it. The asymmetric key pair **Wrapping_Key** is used for key agreement in the encrypted import process.

3. Use the same algorithm to generate an asymmetric key pair **Caller_Key** (public key **Caller_Pk** and private key **Caller_Sk**) with the purpose of **HUKS_KEY_PURPOSE_UNWRAP** for device A, and export the public key **Caller_Pk** of **Caller_Key** and save it. The asymmetric key pair **Caller_Key** is used for key agreement in the encrypted import process.

4. Generate a symmetric key **Caller_Kek** for device A. This key is used to encrypt **To_Import_Key**.

5. Perform key agreement with the private key **Caller_Sk** in **Caller_Key** of device A and the public key **Wrapping_Pk** in **Wrapping_Key** of device B to yield a **Shared_Key**.

6. Use **Caller_Kek** to encrypt **To_Import_Key** of device A and generate **To_Import_Key_Enc**.

7. Use **Shared_Key** to encrypt **Caller_Kek** of device A and generate **Caller_Kek_Enc**.

8. Encapsulate the key material **Caller_Pk**, **Caller_Kek_Enc**, and **To_Import_Key_Enc** of device A, and sends it to device B. For details about the format of the key material to be imported, see [Key Material Format for Encrypted Import](huks-key-import-overview.md#key-material-format-for-encrypted-import).

9. Import the encrypted key material to device B.

10. Delete the intermediate keys (keys used for encrypting the key to import) from devices A and B.

```ts
import { huks } from '@kit.UniversalKeystoreKit';

let IV = '0000000000000000'; // Replace this example code with a random value in practice.
let AAD = "abababababababab";
let NONCE = 'hahahahahaha'; // Replace this example code with a random value in practice.
let TAG_SIZE = 16;
let FILED_LENGTH = 4;
let importedAes192PlainKey = "The aes192 key to import";
let callerAes256Kek = "It's a kek to encrypt aes192 key";
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

let genWrappingKeyParams: huks.HuksOptions = {
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
      value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
    },
    {
      tag: huks.HuksTag.HUKS_TAG_PADDING,
      value: huks.HuksKeyPadding.HUKS_PADDING_NONE
    }
  )
}
let genCallerEcdhParams: huks.HuksOptions = {
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
      value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
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
      .catch((err: Error) => {
        console.error(`promise: generateKeyItem failed, ${JSON.stringify(err)}`);
      })
  } catch (err) {
    console.error(`promise: generateKeyItem invalid, ${JSON.stringify(err)}`);
  }
}

async function publicImportKeyItemFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise importKeyItem`);
  try {
    await huks.importKeyItem(keyAlias, huksOptions)
      .then(data => {
        console.info(`promise: importKeyItem success, data = ${JSON.stringify(data)}`);
      }).catch((err: Error) => {
        console.error(`promise: importKeyItem failed, ${JSON.stringify(err)}`);
      })
  } catch (err) {
    console.error(`promise: importKeyItem input arg invalid, ${JSON.stringify(err)}`);
  }
}

async function publicDeleteKeyItemFunc(KeyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise deleteKeyItem`);
  try {
    await huks.deleteKeyItem(KeyAlias, huksOptions)
      .then(data => {
        console.info(`promise: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
      })
      .catch((err: Error) => {
        console.error(`promise: deleteKeyItem failed, ${JSON.stringify(err)}`);
      })
  } catch (err) {
    console.error(`promise: deleteKeyItem input arg invalid, ${JSON.stringify(err)}`);
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
  console.info(`enter promise importWrappedKeyItem`);
  for (let i = 0; i < huksOptions.inData!.length; i++) {
    console.info(`${i}: ${huksOptions.inData![i]}`);
  }
  try {
    await importWrappedKeyItem(keyAlias, wrappingKeyAlias, huksOptions)
      .then((data) => {
        console.info(`promise: importWrappedKeyItem success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        console.error(`promise: importWrappedKeyItem failed, ${JSON.stringify(error)}`);
      });
  } catch (error) {
    console.error(`promise: importWrappedKeyItem input arg invalid, ${JSON.stringify(error)}`);
  }
}

async function publicInitFunc(srcKeyAlias: string, huksOptions: huks.HuksOptions) {
  let handle: number = 0;
  console.info(`enter promise doInit`);
  try {
    await huks.initSession(srcKeyAlias, huksOptions)
      .then((data) => {
        console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
        handle = data.handle;
      })
      .catch((error: Error) => {
        console.error(`promise: doInit key failed, ${JSON.stringify(error)}`);
      });
  } catch (error) {
    console.error(`promise: doInit input arg invalid, ${JSON.stringify(error)}`);
  }
  return handle;
}

async function publicUpdateSessionFunction(handle: number, huksOptions: huks.HuksOptions) {
  const maxUpdateSize = 64;
  const inData = huksOptions.inData!;
  const lastInDataPosition = inData.length - 1;
  let inDataSegSize = maxUpdateSize;
  let inDataSegPosition = 0;
  let isFinished = false;
  let outData: number[] = [];

  while (inDataSegPosition <= lastInDataPosition) {
    if (inDataSegPosition + maxUpdateSize > lastInDataPosition) {
      isFinished = true;
      inDataSegSize = lastInDataPosition - inDataSegPosition + 1;
      console.info(`enter promise doUpdate`);
      break;
    }
    huksOptions.inData = new Uint8Array(
      Array.from(inData).slice(inDataSegPosition, inDataSegPosition + inDataSegSize)
    );
    console.info(`enter promise doUpdate`);
    try {
      await huks.updateSession(handle, huksOptions)
        .then((data) => {
          console.info(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
          outData = outData.concat(Array.from(data.outData!));
        })
        .catch((error: Error) => {
          console.error(`promise: doUpdate failed, ${JSON.stringify(error)}`);
        });
    } catch (error) {
      console.error(`promise: doUpdate input arg invalid, ${JSON.stringify(error)}`);
    }
    if ((!isFinished) && (inDataSegPosition + maxUpdateSize > lastInDataPosition)) {
      console.error(`update size invalid isFinished = ${isFinished}`);
      console.error(`inDataSegPosition = ${inDataSegPosition}`);
      console.error(`lastInDataPosition = ${lastInDataPosition}`);
      return;
    }
    inDataSegPosition += maxUpdateSize;
  }
  return outData;
}

async function publicFinishSession(handle: number, huksOptions: huks.HuksOptions, inData: number[]) {
  let outData: number[] = [];
  console.info(`enter promise doFinish`);
  try {
    await huks.finishSession(handle, huksOptions)
      .then((data) => {
        console.info(`promise: doFinish success, data = ${JSON.stringify(data)}`);
        outData = inData.concat(Array.from(data.outData!));
      })
      .catch((error: Error) => {
        console.error(`promise: doFinish key failed, ${JSON.stringify(error)}`);
      });
  } catch (error) {
    console.error(`promise: doFinish input arg invalid, ${JSON.stringify(error)}`);
  }
  return new Uint8Array(outData);
}

async function cipherFunction(keyAlias: string, huksOptions: huks.HuksOptions) {
  let handle = await publicInitFunc(keyAlias, huksOptions);
  let tmpData = await publicUpdateSessionFunction(handle, huksOptions);
  let outData = await publicFinishSession(handle, huksOptions, tmpData!);
  return outData;
}

async function agreeFunction(keyAlias: string, huksOptions: huks.HuksOptions, huksPublicKey: Uint8Array) {
  let handle = await publicInitFunc(keyAlias, huksOptions);
  let outSharedKey: Uint8Array = new Uint8Array();
  huksOptions.inData = huksPublicKey;
  console.info(`enter promise doUpdate`);
  try {
    await huks.updateSession(handle, huksOptions)
      .then((data) => {
        console.info(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        console.error(`promise: doUpdate failed, ${JSON.stringify(error)}`);
      });
  } catch (error) {
    console.error(`promise: doUpdate input arg invalid, ${JSON.stringify(error)}`);
  }
  console.info(`enter promise doInit`);
  try {
    await huks.finishSession(handle, huksOptions)
      .then((data) => {
        console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
        outSharedKey = data.outData as Uint8Array;
      })
      .catch((error: Error) => {
        console.error(`promise: doInit key failed, ${JSON.stringify(error)}`);
      });
  } catch (error) {
    console.error(`promise: doInit input arg invalid, ${JSON.stringify(error)}`);
  }
  return outSharedKey;
}

async function ImportKekAndAgreeSharedSecret(callerKekAlias: string, importKekParams: huks.HuksOptions,
  callerKeyAlias: string, huksPublicKey: Uint8Array, agreeParams: huks.HuksOptions) {
  await publicImportKeyItemFunc(callerKekAlias, importKekParams);
  outSharedKey = await agreeFunction(callerKeyAlias, agreeParams, huksPublicKey);
  importParamsAgreeKey.inData = outSharedKey;
  await publicImportKeyItemFunc(callerAgreeKeyAliasAes256, importParamsAgreeKey);
}

async function generateAndExportPublicKey(keyAlias: string, huksOptions: huks.HuksOptions, caller: Boolean) {
  await publicGenerateItemFunc(keyAlias, huksOptions);
  try {
    await huks.exportKeyItem(keyAlias, huksOptions)
      .then((data) => {
        console.info(`promise: exportKeyItem success, data = ${JSON.stringify(data)}`);
        if (caller) {
          callerSelfPublicKey = data.outData as Uint8Array;
        } else {
          huksPubKey = data.outData as Uint8Array;
        }
      })
      .catch((error: Error) => {
        console.error(`promise: exportKeyItem failed, ${JSON.stringify(error)}`);
      });
  } catch (error) {
    console.error(`promise: generate pubKey failed, ${JSON.stringify(error)}`);
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
  index += assignLength(callerSelfPublicKey.length, wrappedData, index); // 4
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

/* Simulate the encrypted key import scenario. Import a key from device A (remote device) to device B (local device). */
async function ImportWrappedKey() {
  /**
   * 1. If the key to import from device A is an asymmetric key pair, convert it into the HUKS key material format **To_Import_Key**. Skip over this step if the key is a symmetric key.
   * This example uses importedAes192PlainKey (symmetric key) as an example.
   */

  /* 2. Generate an asymmetric key pair Wrapping_Key (public key Wrapping_Pk and private key Wrapping_Sk) with the purpose of HUKS_KEY_PURPOSE_UNWRAP for device B, export the public key Wrapping_Pk of Wrapping_Key, and save it to huksPubKey. */
  const srcKeyAliasWrap = 'HUKS_Basic_Capability_Import_0200';
  await generateAndExportPublicKey(srcKeyAliasWrap, genWrappingKeyParams, false);

  /* 3. Use the same algorithm to generate an asymmetric key pair Caller_Key (public key Caller_Pk and private key Caller_Sk) with the purpose of HUKS_KEY_PURPOSE_UNWRAP for device A, export the public key Caller_Pk of Caller_Key, save it to callerSelfPublicKey. */
  await generateAndExportPublicKey(callerKeyAlias, genCallerEcdhParams, true);

  /**
   4. Generate a symmetric key Caller_Kek for device A. This key is used to encrypt To_Import_Key.
   * 5. Perform key agreement with the private key Caller_Sk in Caller_Key of device A and the public key Wrapping_Pk in Wrapping_Key of device B to yield a Shared_Key.
   */
  await ImportKekAndAgreeSharedSecret(callerKekAliasAes256, importParamsCallerKek, callerKeyAlias, huksPubKey,
    callerAgreeParams);

  /**
   * 6. Use Caller_Kek to encrypt To_Import_Key of device A and generate To_Import_Key_Enc.
   * 7. Use Shared_Key to encrypt Caller_Kek of device A and generate Caller_Kek_Enc.
   */
  await EncryptImportedPlainKeyAndKek(importedAes192PlainKey);

  /* 8. Encapsulate the key material Caller_Pk, To_Import_Key_Enc, and Caller_Kek_Enc of device A, and sends it to device B. In this example, Caller_Pk is placed in callerSelfPublicKey, To_Import_Key_Enc in PlainKeyEncData, and Caller_Kek_Enc in KekEncData. */
  let wrappedData = await BuildWrappedDataAndImportWrappedKey(importedAes192PlainKey);
  importWrappedAes192Params.inData = wrappedData;

  /* 9. Import the encapsulated key material to device B. */
  await publicImportWrappedKeyFunc(importedKeyAliasAes192, srcKeyAliasWrap, importWrappedAes192Params);

  /* 10. Delete the intermediate keys (keys used for encrypting the key to import) from devices A and B. */
  await publicDeleteKeyItemFunc(srcKeyAliasWrap, genWrappingKeyParams);
  await publicDeleteKeyItemFunc(callerKeyAlias, genCallerEcdhParams);
  await publicDeleteKeyItemFunc(callerKekAliasAes256, callerAgreeParams);
}

```


## Verification

Use [huks.isKeyItemExist](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksiskeyitemexist9) to check whether the key exists. If the key exists, the key is successfully imported.

```ts
import { huks } from '@kit.UniversalKeystoreKit';

/*
 * Set the key alias and encapsulate the key property set.
 */
let keyAlias = 'test_import_key_ecdh_aes192';
let isKeyExist: Boolean;
let keyProperties: Array<huks.HuksParam> = [{
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_AES,
}];
let huksOptions: huks.HuksOptions = {
  properties: keyProperties, // It cannot be empty.
  inData: new Uint8Array(new Array()) // It cannot be empty.
}
try {
  huks.isKeyItemExist(keyAlias, huksOptions, (error, data) => {
    if (error) {
      console.error(`callback: isKeyItemExist failed, ${JSON.stringify(error)}`);
    } else {
      if (data !== null && data.valueOf() !== null) {
        isKeyExist = data.valueOf();
        console.info(`callback: isKeyItemExist success, isKeyExist = ${isKeyExist}`);
      }
    }
  });
} catch (error) {
  console.error(`callback: isKeyItemExist input arg invalid, ${JSON.stringify(error)}`);
}
```
