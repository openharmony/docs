# Key Agreement (ArkTS)


This topic walks you through on how to agree on a 256-bit X25519 key that is used only in HUKS. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).


## How to Develop

**Key Generation**

Generate an asymmetric key for device A and device B each. For details, see [Key Generation](huks-key-generation-overview.md) or [Key Import](huks-key-import-overview.md).

When generating a key, you can set **HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** (optional) to specify how the shared secret generated from this key through key agreement is managed.

- If this tag is set to **HUKS_STORAGE_ONLY_USED_IN_HUKS**, the shared secret is managed by HUKS. That is, the shared secret is always in a secure environment throughout its lifecycle.

- If this tag is set to **HUKS_STORAGE_KEY_EXPORT_ALLOWED**, the shared secret generated will be returned to the caller for management. That is, the service side ensures the key security.

- If this tag is not set, the shared secret generated can be either managed by HUKS or returned to the caller for management. The key protection mode can be set in the subsequent key agreement on the service side.

**Key Export**

Export the public key of the asymmetric key pair of device A and device B. For details, see [Key Export](huks-export-key-arkts.md).

**Key Agreement**

Perform key agreement using the public key of the peer device and private key of the local device (that is, public key of device B and private key of device A for device A, and public key of device A and private key of device B for device B) to produce a shared secret.

During key agreement, you can set **HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** (optional) to specify how the shared secret generated is managed.

| Key Generation| Key Agreement| Specifications|
| -------- | -------- | -------- |
| HUKS_STORAGE_ONLY_USED_IN_HUKS | HUKS_STORAGE_ONLY_USED_IN_HUKS | The key is managed by HUKS.|
| HUKS_STORAGE_KEY_EXPORT_ALLOWED | HUKS_STORAGE_KEY_EXPORT_ALLOWED | The key is returned to the caller for management.|
| The tag is not set.| HUKS_STORAGE_ONLY_USED_IN_HUKS | The key is managed by HUKS.|
| The tag is not set.| HUKS_STORAGE_KEY_EXPORT_ALLOWED | The key is returned to the caller for management.|
| The tag is not set.| The tag is not set.| The key is returned to the caller for management.|

>**NOTE**<br>The tag value set in key agreement should not conflict with the tag value set in key generation. The above table lists only valid settings.

**Key Deletion**

Delete the keys from device A and device B when the keys are not required. For details, see [Deleting a Key](huks-delete-key-arkts.md).


Example: Perform X25519 key agreement.
```ts
/*
* Agree on a 256-bit X25519 key using promise-based APIs.
*/
import { huks } from '@kit.UniversalKeystoreKit';

/*
* Set the key alias and encapsulate the key property set.
*/
let srcKeyAliasFirst = "AgreeX25519KeyFirstAlias";
let srcKeyAliasSecond = "AgreeX25519KeySecondAlias";
let agreeX25519InData = 'AgreeX25519TestIndata';
let finishOutData: Uint8Array;
let handle: number;
let exportKey: Uint8Array;
let exportKeyFirst: Uint8Array;
let exportKeySecond: Uint8Array;
/* Set the parameter set used for generating the key. */
let properties: Array<huks.HuksParam> = [{
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_X25519,
}, {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE,
}, {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256,
}, {
  tag: huks.HuksTag.HUKS_TAG_DIGEST,
  value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
}, {
  tag: huks.HuksTag.HUKS_TAG_PADDING,
  value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}, {
  tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
  value: huks.HuksCipherMode.HUKS_MODE_CBC,
}, {
  tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
  value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
}];
let HuksOptions: huks.HuksOptions = {
  properties: properties,
  inData: new Uint8Array(new Array())
}
/* Set the parameter set for the first key agreement. */
const finishProperties: Array<huks.HuksParam> = [{
  tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
  value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
}, {
  tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS,
  value: true
}, {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_AES,
}, {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
}, {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value:
  huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
  huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
}, {
  tag: huks.HuksTag.HUKS_TAG_DIGEST,
  value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
}, {
  tag: huks.HuksTag.HUKS_TAG_PADDING,
  value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}, {
  tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
  value: huks.HuksCipherMode.HUKS_MODE_ECB,
}];
let finishOptionsFirst: huks.HuksOptions = {
  properties: [
    ...finishProperties, {
    tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
    value: StringToUint8Array(srcKeyAliasFirst + 'final'),
  }],
  inData: StringToUint8Array(agreeX25519InData)
}
/* Set the parameter set for the second key agreement. */
let finishOptionsSecond: huks.HuksOptions = {
  properties: [
    ...finishProperties, {
    tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
    value: StringToUint8Array(srcKeyAliasSecond + 'final'),
  }],
  inData: StringToUint8Array(agreeX25519InData)
}

function StringToUint8Array(str: string) {
  let arr: number[] = new Array();
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

class throwObject {
  isThrow: boolean = false
}

/* Generate a key. */
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
      throw (error as Error);
    }
  });
}

/* Call generateKeyItem to generate a key. */
async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise generateKeyItem`);
  let throwObject: throwObject = { isThrow: false };
  try {
    await generateKeyItem(keyAlias, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: generateKeyItem failed, ${JSON.stringify(error)}`);
        }
      });
  } catch (error) {
    console.error(`promise: generateKeyItem input arg invalid, ${JSON.stringify(error)}`);
  }
}

/* Initializes a key session, which returns a session handle (mandatory) and a challenge (optional). */
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
      throw (error as Error);
    }
  });
}

/* Call initSession. A session handle is returned. */
async function publicInitFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise doInit`);
  let throwObject: throwObject = { isThrow: false };
  try {
    await initSession(keyAlias, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
        handle = data.handle;
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: doInit failed, ${JSON.stringify(error)}`);
        }
      });
  } catch (error) {
    console.error(`promise: doInit input arg invalid, ${JSON.stringify(error)}`);
  }
}

/* Call updateSession multiple times to process data by segment and output the processed data. */
function updateSession(handle: number, huksOptions: huks.HuksOptions, throwObject: throwObject) {
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
      throw (error as Error);
    }
  });
}

/* Call updateSession to perform key agreement. */
async function publicUpdateFunc(handle: number, huksOptions: huks.HuksOptions) {
  console.info(`enter promise doUpdate`);
  let throwObject: throwObject = { isThrow: false };
  try {
    await updateSession(handle, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: doUpdate failed, ${JSON.stringify(error)}`);
        }
      });
  } catch (error) {
    console.error(`promise: doUpdate input arg invalid, ${JSON.stringify(error)}`);
  }
}

/* Finish the key session to output the shared secret key. */
function finishSession(handle: number, huksOptions: huks.HuksOptions, throwObject: throwObject) {
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

/* Call finishSession to finish the operation. */
async function publicFinishFunc(handle: number, huksOptions: huks.HuksOptions) {
  console.info(`enter promise doFinish`);
  let throwObject: throwObject = { isThrow: false };
  try {
    await finishSession(handle, huksOptions, throwObject)
      .then((data) => {
        finishOutData = data.outData as Uint8Array;
        console.info(`promise: doFinish success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: doFinish failed, ${JSON.stringify(error)}`);
        }
      });
  } catch (error) {
    console.error(`promise: doFinish input arg invalid, ${JSON.stringify(error)}`);
  }
}

/* Export a key. */
function exportKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
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
      throw (error as Error);
    }
  });
}

/* Call exportKeyItem to export the public key. */
async function publicExportKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise export`);
  let throwObject: throwObject = { isThrow: false };
  try {
    await exportKeyItem(keyAlias, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: exportKeyItem success, data = ${JSON.stringify(data)}`);
        exportKey = data.outData as Uint8Array;
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: exportKeyItem failed, ${JSON.stringify(error)}`);
        }
      });
  } catch (error) {
    console.error(`promise: exportKeyItem input arg invalid, ${JSON.stringify(error)}`);
  }
}

/* Delete the keys. */
function deleteKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObject: throwObject) {
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
      throw (error as Error);
    }
  });
}

/* Call deleteKeyItem to delete a key. */
async function publicDeleteKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise deleteKeyItem`);
  let throwObject: throwObject = { isThrow: false };
  try {
    await deleteKeyItem(keyAlias, huksOptions, throwObject)
      .then((data) => {
        console.info(`promise: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObject.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: deleteKeyItem failed, ${JSON.stringify(error)}`);
        }
      });
  } catch (error) {
    console.error(`promise: deleteKeyItem input arg invalid, ${JSON.stringify(error)}`);
  }
}

async function testAgree() {
  /* 1. Set the key alias srcKeyAliasFirst for device A and srcKeyAliasSecond for device B, and parameters for generating the key pairs. */
  /* 2. Generate an asymmetric key pair for device A. */
  await publicGenKeyFunc(srcKeyAliasFirst, HuksOptions);
  /* 3. Generate an asymmetric key pair for device B. */
  await publicGenKeyFunc(srcKeyAliasSecond, HuksOptions);
  /* 4. Export the public keys of the key pairs of device A and device B. */
  await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
  exportKeyFirst = exportKey;
  await publicExportKeyFunc(srcKeyAliasSecond, HuksOptions);
  exportKeySecond = exportKey;
  /* 5. Perform key agreement (Init-Update-Finish) for device A. */
  await publicInitFunc(srcKeyAliasFirst, HuksOptions);
  HuksOptions.inData = exportKeySecond;
  await publicUpdateFunc(handle, HuksOptions);
  await publicFinishFunc(handle, finishOptionsFirst);
  /* 5. Perform key agreement (Init-Update-Finish) for device B. */
  await publicInitFunc(srcKeyAliasSecond, HuksOptions);
  HuksOptions.inData = exportKeyFirst;
  await publicUpdateFunc(handle, HuksOptions);
  await publicFinishFunc(handle, finishOptionsSecond);
  /* 6. Delete keys from device A and device B. */
  await publicDeleteKeyFunc(srcKeyAliasFirst, HuksOptions);
  await publicDeleteKeyFunc(srcKeyAliasSecond, HuksOptions);
}
```

Example: Perform DH key agreement.

```ts
/*
 * Agree on a DH key using promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit'

function StringToUint8Array(str: string) {
  let arr: number[] = []
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i))
  }
  return new Uint8Array(arr)
}

function Uint8ArrayToBigInt(arr: Uint8Array): bigint {
  let i = 0
  const byteMax: bigint = BigInt('0x100')
  let result: bigint = BigInt('0')
  while (i < arr.length) {
    result = result * byteMax
    result = result + BigInt(arr[i])
    i += 1
  }
  return result
}

const dhAgree: Array<huks.HuksParam> = [{
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_DH,
}, {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE,
}]
const dh2048Agree: Array<huks.HuksParam> = [
  ...dhAgree, {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: huks.HuksKeySize.HUKS_DH_KEY_SIZE_2048,
}]
const dhGenOptions: huks.HuksOptions = {
  properties: dh2048Agree,
  inData: new Uint8Array([])
}
const emptyOptions: huks.HuksOptions = {
  properties: [],
  inData: new Uint8Array([])
}

async function HuksDhAgreeExportKey(keyAlias: string,
  peerPubKey: huks.HuksReturnResult): Promise<huks.HuksReturnResult> {
  const initHandle = await huks.initSession(keyAlias, dhGenOptions)
  const dhAgreeUpdateBobPubKey: huks.HuksOptions = {
    properties: [
      ...dh2048Agree, {
      tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
      value: huks.HuksKeyStorageType.HUKS_STORAGE_KEY_EXPORT_ALLOWED,
    }],
    inData: peerPubKey.outData
  }
  await huks.updateSession(initHandle.handle, dhAgreeUpdateBobPubKey)
  return await huks.finishSession(initHandle.handle, emptyOptions)
}

async function HuksDhAgreeExportTest(
  aliasA: string, aliasB: string,
  pubKeyA: huks.HuksReturnResult, pubKeyB: huks.HuksReturnResult) {

  const agreedKeyFromAlice = await HuksDhAgreeExportKey(aliasA, pubKeyB)
  console.info(`ok! agreedKeyFromAlice export is 0x${Uint8ArrayToBigInt(agreedKeyFromAlice.outData).toString(16)}`)

  const agreedKeyFromBob = await HuksDhAgreeExportKey(aliasB, pubKeyA)
  console.info(`ok! agreedKeyFromBob export is 0x${Uint8ArrayToBigInt(agreedKeyFromBob.outData).toString(16)}`)
}

async function HuksDhAgreeInHuks(keyAlias: string, peerPubKey: huks.HuksReturnResult,
  aliasAgreedKey: string): Promise<huks.HuksReturnResult> {
  const onlyUsedInHuks: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
  }, {
    tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
  }]
  const dhAgreeInit: huks.HuksOptions = {
    properties: [
      ...dhAgree,
      { tag: huks.HuksTag.HUKS_TAG_KEY_SIZE, value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256, },
      ...onlyUsedInHuks],
    inData: new Uint8Array([])
  }
  const dhAgreeFinishParams: Array<huks.HuksParam> = [
    ...onlyUsedInHuks,
    { tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS, value: true },
    { tag: huks.HuksTag.HUKS_TAG_ALGORITHM, value: huks.HuksKeyAlg.HUKS_ALG_AES },
    { tag: huks.HuksTag.HUKS_TAG_KEY_SIZE, value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256 },
    {
      tag: huks.HuksTag.HUKS_TAG_PURPOSE,
      value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
    }]

  const handle = await huks.initSession(keyAlias, dhAgreeInit)
  const dhAgreeUpdatePubKey: huks.HuksOptions = {
    properties: [...dhAgree, ...onlyUsedInHuks],
    inData: peerPubKey.outData
  }
  await huks.updateSession(handle.handle, dhAgreeUpdatePubKey)
  const dhAgreeAliceFinnish: huks.HuksOptions = {
    properties: [...dhAgreeFinishParams, {
      tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS, value: StringToUint8Array(aliasAgreedKey)
    }], inData: new Uint8Array([])
  }
  return await huks.finishSession(handle.handle, dhAgreeAliceFinnish)
}

async function HuksDhAgreeInHuksTest(
  aliasA: string, aliasB: string,
  pubKeyA: huks.HuksReturnResult, pubKeyB: huks.HuksReturnResult,
  aliasAgreedKeyFromA: string, aliasAgreedKeyFromB: string) {

  const finishAliceResult = await HuksDhAgreeInHuks(aliasA, pubKeyB, aliasAgreedKeyFromA)
  console.info(`ok! finishAliceResult in huks is 0x${Uint8ArrayToBigInt(finishAliceResult.outData).toString(16)}`)
  const aliceAgreedExist = await huks.isKeyItemExist(aliasAgreedKeyFromA, emptyOptions)
  console.info(`ok! aliceAgreedExist in huks is ${aliceAgreedExist}`)

  const finishBobResult = await HuksDhAgreeInHuks(aliasB, pubKeyA, aliasAgreedKeyFromB)
  console.info(`ok! finishBobResult in huks is 0x${Uint8ArrayToBigInt(finishBobResult.outData).toString(16)}`)
  const bobAgreedExist = await huks.isKeyItemExist(aliasAgreedKeyFromB, emptyOptions)
  console.info(`ok! bobAgreedExist in huks is ${bobAgreedExist}`)

  await huks.deleteKeyItem(aliasAgreedKeyFromA, emptyOptions)
  await huks.deleteKeyItem(aliasAgreedKeyFromB, emptyOptions)
}

export default async function HuksDhAgreeTest() {
  const aliasAlice = 'alice'
  const aliasBob = 'bob'

  /* Call generateKeyItem to generate a key with alias of alice and a key with alias of bob. */
  await huks.generateKeyItem(aliasAlice, dhGenOptions)
  await huks.generateKeyItem(aliasBob, dhGenOptions)

  /* Export the public keys of asymmetric key pairs alice and bob. */
  const pubKeyAlice = await huks.exportKeyItem(aliasAlice, emptyOptions)
  const pubKeyBob = await huks.exportKeyItem(aliasBob, emptyOptions)

  /* Perform key agreement and return the shared secret generated to the caller for management. */
  await HuksDhAgreeExportTest(aliasAlice, aliasBob, pubKeyAlice, pubKeyBob)

  /* Perform key agreement and let HUKS manage the shared secret generated. */
  await HuksDhAgreeInHuksTest(aliasAlice, aliasBob, pubKeyAlice, pubKeyBob, 'agreedKeyFromAlice', 'agreedKeyFromBob')

  await huks.deleteKeyItem(aliasAlice, emptyOptions)
  await huks.deleteKeyItem(aliasBob, emptyOptions)
}
```
