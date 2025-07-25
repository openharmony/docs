# 密钥协商(ArkTS)

以协商密钥类型为X25519，并密钥仅在HUKS内使用为例，完成密钥协商。具体的场景介绍及支持的算法规格，请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。

## 开发步骤

**生成密钥**

设备A、设备B各自生成一个非对称密钥，具体请参考[密钥生成](huks-key-generation-overview.md)或[密钥导入](huks-key-import-overview.md)。

密钥生成时，可指定参数HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG（可选），用于标识基于该密钥协商出的密钥是否由HUKS管理。

- 当TAG设置为HUKS_STORAGE_ONLY_USED_IN_HUKS时，表示基于该密钥协商出的密钥，由HUKS管理，可保证协商密钥全生命周期不出安全环境。

- 当TAG设置为HUKS_STORAGE_KEY_EXPORT_ALLOWED时，表示基于该密钥协商出的密钥，返回给调用方管理，由业务自行保证密钥安全。

- 若业务未设置TAG的具体值，表示基于该密钥协商出的密钥，可由HUKS管理，也可返回给调用方管理，业务可在后续协商时再选择使用何种方式保护密钥。

**导出密钥**

设备A、B导出非对称密钥对的公钥材料，具体请参考[密钥导出](huks-export-key-arkts.md)。

**密钥协商**

设备A、B分别基于本端私钥和对端设备的公钥，协商出共享密钥。

密钥协商时，可指定参数HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG（可选），用于标识协商得到的密钥是否由HUKS管理。

| 生成 | 协商 | 规格 |
| -------- | -------- | -------- |
| HUKS_STORAGE_ONLY_USED_IN_HUKS | HUKS_STORAGE_ONLY_USED_IN_HUKS | 密钥由HUKS管理 |
| HUKS_STORAGE_KEY_EXPORT_ALLOWED | HUKS_STORAGE_KEY_EXPORT_ALLOWED | 密钥返回给调用方管理 |
| 未指定TAG具体值 | HUKS_STORAGE_ONLY_USED_IN_HUKS | 密钥由HUKS管理 |
| 未指定TAG具体值 | HUKS_STORAGE_KEY_EXPORT_ALLOWED | 密钥返回给调用方管理 |
| 未指定TAG具体值 | 未指定TAG具体值 | 密钥返回给调用方管理 |

注：协商时指定的TAG值，不可与生成时指定的TAG值冲突。表格中仅列举有效的指定方式。

**删除密钥**

当密钥废弃不用时，设备A、B均需要删除密钥，具体请参考[密钥删除](huks-delete-key-arkts.md)。


下面分别以X25519 与 DH密钥为例，进行协商。  
- X25519非对称密钥协商用例
  ```ts
  /*
  *以下以X25519密钥的Promise操作使用为例
  */
  import { huks } from '@kit.UniversalKeystoreKit';

  function StringToUint8Array(str: string) {
    let arr: number[] = new Array();
    for (let i = 0, j = str.length; i < j; ++i) {
      arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
  }

  /*
  * 确定密钥别名和封装密钥属性参数集
  */
  let srcKeyAliasFirst = "AgreeX25519KeyFirstAlias";
  let srcKeyAliasSecond = "AgreeX25519KeySecondAlias";
  let agreeX25519InData = 'AgreeX25519TestIndata';
  let finishOutData: Uint8Array;
  let handle: number;
  let exportKey: Uint8Array;
  let exportKeyFirst: Uint8Array;
  let exportKeySecond: Uint8Array;
  /* 集成生成密钥参数集 */
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
  /* 集成第一个协商参数集 */
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
  /* 集成第二个协商参数集 */
  let finishOptionsSecond: huks.HuksOptions = {
    properties: [
      ...finishProperties, {
      tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
      value: StringToUint8Array(srcKeyAliasSecond + 'final'),
    }],
    inData: StringToUint8Array(agreeX25519InData)
  }

  class throwObject {
    isThrow: boolean = false
  }

  /* 生成密钥 */
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

  /* 调用generateKeyItem生成密钥 */
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

  /*初始化密钥会话接口，并获取一个句柄（必选）和挑战值（可选）*/
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

  /*调用initSession获取handle*/
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

  /* 分段添加密钥操作的数据并进行相应的密钥操作，输出处理数据 */
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

  /* 调用updateSession进行协商操作 */
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

  /* 结束密钥会话并进行相应的密钥操作，输出处理数据 */
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

  /* 调用finishSession结束操作 */
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

  /* 导出密钥 */
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

  /* 调用exportKeyItem导出公钥操作 */
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

  /* 删除密钥操作 */
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

  /* 调用deleteKeyItem删除密钥操作 */
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
    /* 1.确定密钥别名并集成要参数集 A设备：srcKeyAliasFirst  B设备：srcKeyAliasSecond*/
    /* 2.设备A生成密钥 */
    await publicGenKeyFunc(srcKeyAliasFirst, HuksOptions);
    /* 3.设备B生成密钥 */
    await publicGenKeyFunc(srcKeyAliasSecond, HuksOptions);
    /* 4.设备A、B导出非对称密钥的公钥 */
    await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
    exportKeyFirst = exportKey;
    await publicExportKeyFunc(srcKeyAliasSecond, HuksOptions);
    exportKeySecond = exportKey;
    /* 5.对第一个密钥进行协商（三段式）*/
    await publicInitFunc(srcKeyAliasFirst, HuksOptions);
    HuksOptions.inData = exportKeySecond;
    await publicUpdateFunc(handle, HuksOptions);
    await publicFinishFunc(handle, finishOptionsFirst);
    /* 5.对第二个密钥进行协商（三段式） */
    await publicInitFunc(srcKeyAliasSecond, HuksOptions);
    HuksOptions.inData = exportKeyFirst;
    await publicUpdateFunc(handle, HuksOptions);
    await publicFinishFunc(handle, finishOptionsSecond);
    /* 6.设备A、B删除密钥 */
    await publicDeleteKeyFunc(srcKeyAliasFirst, HuksOptions);
    await publicDeleteKeyFunc(srcKeyAliasSecond, HuksOptions);
  }
  ```

- DH密钥协商用例

  ```ts
  /*
  *以下以 DH密钥的Promise操作使用为例
  */
  import { huks } from '@kit.UniversalKeystoreKit';

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

    /* 调用generateKeyItem生成别名为alice与bob的两个密钥 */
    await huks.generateKeyItem(aliasAlice, dhGenOptions)
    await huks.generateKeyItem(aliasBob, dhGenOptions)

    /* 导出非对称密钥alice与bob的公钥 */
    const pubKeyAlice = await huks.exportKeyItem(aliasAlice, emptyOptions)
    const pubKeyBob = await huks.exportKeyItem(aliasBob, emptyOptions)

    /* 开始协商，协商生成的密钥返回给业务管理 */
    await HuksDhAgreeExportTest(aliasAlice, aliasBob, pubKeyAlice, pubKeyBob)

    /* 开始协商，协商生成的密钥由HUKS管理 */
    await HuksDhAgreeInHuksTest(aliasAlice, aliasBob, pubKeyAlice, pubKeyBob, 'agreedKeyFromAlice', 'agreedKeyFromBob')

    await huks.deleteKeyItem(aliasAlice, emptyOptions)
    await huks.deleteKeyItem(aliasBob, emptyOptions)
  }
  ```
