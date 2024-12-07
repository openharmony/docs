# Key Derivation (ArkTS)


This topic walks you through on how to derive a 256-bit key using HKDF. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).


## How to Develop

**Key Generation**

1. Set the key alias.

2. Initialize the key property set. You can set **HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** (optional) to specify how the key derived from this key is managed.

    - If this tag is set to **HUKS_STORAGE_ONLY_USED_IN_HUKS**, the derived key is managed by HUKS. That is, the derived key is always in a secure environment throughout its lifecycle.

    - If this tag is set to **HUKS_STORAGE_KEY_EXPORT_ALLOWED**, the derived key will be returned to the caller for management. That is, the service side ensures the key security.

    - If this tag is not set, the derived key can be either managed by HUKS or returned to the caller for management. The key protection mode can be set in the subsequent key derivation on the service side.

3. Use [generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9) to generate a key. For details, see [Key Generation](huks-key-generation-overview.md).

Alternatively, you can [import a key](huks-key-import-overview.md).

**Key Derivation**

1. Obtain the key alias and set the **HuksOptions** parameter.

    You can set **HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** to specify how the derived key is managed.

    | Key Generation| Key Derivation| Specifications|
    | -------- | -------- | -------- |
    | HUKS_STORAGE_ONLY_USED_IN_HUKS | HUKS_STORAGE_ONLY_USED_IN_HUKS | The key is managed by HUKS.|
    | HUKS_STORAGE_KEY_EXPORT_ALLOWED | HUKS_STORAGE_KEY_EXPORT_ALLOWED | The key is returned to the caller for management.|
    | The tag is not set.| HUKS_STORAGE_ONLY_USED_IN_HUKS | The key is managed by HUKS.|
    | The tag is not set.| HUKS_STORAGE_KEY_EXPORT_ALLOWED | The key is returned to the caller for management.|
    | The tag is not set.| The tag is not set.| The key is returned to the caller for management.|

    >**NOTE**<br>The tag value set in key derivation should not conflict with the tag value set in key generation. The above table lists only valid settings.


2. Use [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9) to initialize a key session. The session handle is returned after the initialization.

3. Use [updateSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksupdatesession9) to process data.

4. Use [OH_Huks_FinishSession](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_finishsession) to derive a key.

**Key Deletion**

Use [deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9) to delete the key that is not required. For details, see [Deleting a Key](huks-delete-key-arkts.md).
## Development Cases
### HKDF
```ts
/*
 * Derive an HKDF key using promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';

/*
 * Set the key alias and encapsulate the key property set.
 */
let srcKeyAlias = "hkdf_Key";
let deriveHkdfInData = "deriveHkdfTestIndata";
let handle: number;
let finishOutData: Uint8Array;
let HuksKeyDeriveKeySize = 32;
/* Set the parameter set used for key generation. */
let properties: Array<huks.HuksParam> = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
  }, {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DERIVE,
}, {
  tag: huks.HuksTag.HUKS_TAG_DIGEST,
  value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
}, {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
}, {
  tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
  value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
}];

let huksOptions: huks.HuksOptions = {
  properties: properties,
  inData: new Uint8Array(new Array())
}
/* Set the parameter set used for init(). */
let initProperties: Array<huks.HuksParam> = [{
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_HKDF,
}, {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DERIVE,
}, {
  tag: huks.HuksTag.HUKS_TAG_DIGEST,
  value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
}, {
  tag: huks.HuksTag.HUKS_TAG_DERIVE_KEY_SIZE,
  value: HuksKeyDeriveKeySize,
}];

let initOptions: huks.HuksOptions = {
  properties: initProperties,
  inData: new Uint8Array(new Array())
}
/* Set the parameter set used for finish(). */
let finishProperties: Array<huks.HuksParam> = [{
  tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
  value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
}, {
  tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS,
  value: true,
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
  tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
  value: StringToUint8Array(srcKeyAlias),
}, {
  tag: huks.HuksTag.HUKS_TAG_PADDING,
  value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
}, {
  tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
  value: huks.HuksCipherMode.HUKS_MODE_ECB,
}];
let finishOptions: huks.HuksOptions = {
  properties: finishProperties,
  inData: new Uint8Array(new Array())
}

function StringToUint8Array(str: String) {
  let arr: number[] = new Array();
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

class throwObject {
  isThrow = false;
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
      throw (error as Error);
    }
  });
}

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

function updateSession(handle: number, huksOptions: huks.HuksOptions, throwObject: throwObject) {
  return new Promise<huks.HuksOptions>((resolve, reject) => {
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

async function testDerive() {
  /* Generate a key. */
  await publicGenKeyFunc(srcKeyAlias, huksOptions);
  /* Perform key derivation. */
  await publicInitFunc(srcKeyAlias, initOptions);
  initOptions.inData = StringToUint8Array(deriveHkdfInData);
  await publicUpdateFunc(handle, initOptions);
  await publicFinishFunc(handle, finishOptions);
  await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
}
```
### PBKDF2

```ts
/*
 * Derive a PBKDF2 key using promise-based APIs.
 */
import { huks } from '@kit.UniversalKeystoreKit';

/*
 * Set the key alias and encapsulate the key property set.
 */
let srcKeyAlias = "pbkdf2_Key";
let password = "myPassword";
let salt = "mySalt";
let iterationCount = 10000;
let derivedKeySize = 32;
let handle: number;
let finishOutData: Uint8Array;

/* Set the parameter set used for key generation. */
let properties: Array<huks.HuksParam> = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DERIVE,
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
  }, {
    tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
  }
];

let huksOptions: huks.HuksOptions = {
  properties: properties,
  inData: new Uint8Array(new Array())
}

/* Set the parameter set used for init(). */
let initProperties: Array<huks.HuksParam> = [
  {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_PBKDF2,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DERIVE,
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256,
  }, {
    tag: huks.HuksTag.HUKS_TAG_DERIVE_KEY_SIZE,
    value: derivedKeySize,
  }, {
    tag: huks.HuksTag.HUKS_TAG_ITERATION,
    value: iterationCount,
  }, {
    tag: huks.HuksTag.HUKS_TAG_SALT,
    value: StringToUint8Array(salt),
  }
];

let initOptions: huks.HuksOptions = {
  properties: initProperties,
  inData: new Uint8Array(new Array())
}

/* Set the parameter set used for finish(). */
let finishProperties: Array<huks.HuksParam> = [
  {
    tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
    value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
  }, {
    tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS,
    value: true,
  }, {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
  }, {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
  }, {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
  }, {
    tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
    value: StringToUint8Array(srcKeyAlias),
  }, {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
  }, {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_ECB,
  }
];

let finishOptions: huks.HuksOptions = {
  properties: finishProperties,
  inData: new Uint8Array(new Array())
}

function StringToUint8Array(str: String) {
  let arr: number[] = new Array();
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

class throwObject {
  isThrow = false;
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
      throw (error as Error);
    }
  });
}

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

function updateSession(handle: number, huksOptions: huks.HuksOptions, throwObject: throwObject) {
  return new Promise<huks.HuksOptions>((resolve, reject) => {
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

async function testDerive() {
  /* Generate a key. */
  await publicGenKeyFunc(srcKeyAlias, huksOptions);
  /* Perform key derivation. */
  await publicInitFunc(srcKeyAlias, initOptions);
  initOptions.inData = StringToUint8Array(password);
  await publicUpdateFunc(handle, initOptions);
  await publicFinishFunc(handle, finishOptions);
  await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
}
```
