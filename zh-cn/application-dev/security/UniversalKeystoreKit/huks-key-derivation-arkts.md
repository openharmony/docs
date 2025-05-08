# 密钥派生(ArkTS)

以HKDF256密钥为例，完成密钥派生。具体的场景介绍及支持的算法规格，请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。

## 开发步骤

**生成密钥**

1. 指定密钥别名。

2. 初始化密钥属性集，可指定参数HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG（可选），用于标识基于该密钥派生出的密钥是否由HUKS管理。

    - 当TAG设置为HUKS_STORAGE_ONLY_USED_IN_HUKS时，表示基于该密钥派生出的密钥，由HUKS管理，可保证派生密钥全生命周期不出安全环境。

    - 当TAG设置为HUKS_STORAGE_KEY_EXPORT_ALLOWED时，表示基于该密钥派生出的密钥，返回给调用方管理，由业务自行保证密钥安全。

    - 若业务未设置TAG的具体值，表示基于该密钥派生出的密钥，即可由HUKS管理，也可返回给调用方管理，业务可在后续派生时再选择使用何种方式保护密钥。

3. 调用[generateKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9)生成密钥，具体请参考[密钥生成](huks-key-generation-overview.md)。

除此之外，开发者也可以参考[密钥导入](huks-key-import-overview.md)，导入已有的密钥。

**密钥派生**

1. 获取密钥别名，指定对应的属性参数HuksOptions。

    可指定参数HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG（可选），用于标识派生得到的密钥是否由HUKS管理。

    | 生成 | 派生 | 规格 |
    | -------- | -------- | -------- |
    | HUKS_STORAGE_ONLY_USED_IN_HUKS | HUKS_STORAGE_ONLY_USED_IN_HUKS | 密钥由HUKS管理 |
    | HUKS_STORAGE_KEY_EXPORT_ALLOWED | HUKS_STORAGE_KEY_EXPORT_ALLOWED | 密钥返回给调用方管理 |
    | 未指定TAG具体值 | HUKS_STORAGE_ONLY_USED_IN_HUKS | 密钥由HUKS管理 |
    | 未指定TAG具体值 | HUKS_STORAGE_KEY_EXPORT_ALLOWED | 密钥返回给调用方管理 |
    | 未指定TAG具体值 | 未指定TAG具体值 | 密钥返回给调用方管理 |

    注：派生时指定的TAG值，不可与生成时指定的TAG值冲突。表格中仅列举有效的指定方式。


2. 调用[initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9)初始化密钥会话，并获取会话的句柄handle。

3. 调用[updateSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksupdatesession9)更新密钥会话。

4. 调用[finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9)结束密钥会话，完成派生。

**删除密钥**

当密钥废弃不用时，需要调用[deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9)删除密钥，具体请参考[密钥删除](huks-delete-key-arkts.md)。

## 开发案例

### HKDF
```ts
/*
 * 以下以HKDF密钥的Promise操作使用为例
 */
import { huks } from '@kit.UniversalKeystoreKit';

/*
 * 确定密钥别名和封装密钥属性参数集
 */
let srcKeyAlias = "hkdf_Key";
let deriveHkdfInData = "deriveHkdfTestIndata";
let handle: number;
let finishOutData: Uint8Array;
let HuksKeyDeriveKeySize = 32;
/* 集成生成密钥参数集 */
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
/* 集成init时密钥参数集 */
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
/* 集成finish时密钥参数集 */
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
### PBKDF2

```ts
/*
 * 以下以PBKDF2密钥的Promise操作使用为例
 */
import { huks } from '@kit.UniversalKeystoreKit';

/*
 * 确定密钥别名和封装密钥属性参数集
 */
let srcKeyAlias = "pbkdf2_Key";
let salt = "mySalt";
let iterationCount = 10000;
let derivedKeySize = 32;
let handle: number;
let finishOutData: Uint8Array;

/* 集成生成密钥参数集 */
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

/* 集成init时密钥参数集 */
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

/* 集成finish时密钥参数集 */
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
  /* 生成密钥 */
  await publicGenKeyFunc(srcKeyAlias, huksOptions);
  /* 进行派生操作 */
  await publicInitFunc(srcKeyAlias, initOptions);
  await publicUpdateFunc(handle, initOptions);
  await publicFinishFunc(handle, finishOptions);
  await publicDeleteKeyFunc(srcKeyAlias, huksOptions);
}
```