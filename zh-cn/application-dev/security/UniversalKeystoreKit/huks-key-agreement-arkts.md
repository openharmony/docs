# 密钥协商(ArkTS)


以协商密钥类型为X25519 256，并密钥仅在HUKS内使用为例，完成密钥协商。具体的场景介绍及支持的算法规格，请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。


## 开发步骤

**生成密钥**

设备A、设备B各自生成一个非对称密钥，具体请参考[密钥生成](huks-key-generation-overview.md)或[密钥导入](huks-key-import-overview.md)。

密钥生成时，可指定参数TAG(可选)，HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG：

- HUKS_STORAGE_ONLY_USED_IN_HUKS：表示由该密钥协商出的密钥存储于HUKS中，由HUKS进行托管。

- HUKS_STORAGE_KEY_EXPORT_ALLOWED(默认)：表示由该密钥协商出的密钥直接导出给业务方，HUKS不对其进行托管服务。

**导出密钥**

设备A、B导出非对称密钥对的公钥材料，具体请参考[密钥导出](huks-export-key-arkts.md)。

**密钥协商**

设备A、B分别基于本端私钥和对端设备的公钥，协商出共享密钥。

**删除密钥**

当密钥废弃不用时，设备A、B均需要删除密钥，具体请参考[密钥删除](huks-delete-key-arkts.md)。

```ts
/*
 *以下以X25519 256密钥的Promise操作使用为例
 */
 import huks from '@ohos.security.huks';
 import { BusinessError } from '@ohos.base';
 /*
  * 确定密钥别名和封装密钥属性参数集
  */
 let srcKeyAliasFirst = "AgreeX25519KeyFirstAlias";
 let srcKeyAliasSecond = "AgreeX25519KeySecondAlias";
 let agreeX25519InData = 'AgreeX25519TestIndata';
 let finishOutData: Uint8Array;
 let handle: number;
 let exportKey: Uint8Array;
 let exportKeyFrist: Uint8Array;
 let exportKeySecond: Uint8Array;
 /* 集成生成密钥参数集 */
 let properties: Array<huks.HuksParam> = new Array();
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
 properties[6] = {
     tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
     value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
 }
 let HuksOptions: huks.HuksOptions = {
     properties: properties,
     inData: new Uint8Array(new Array())
 }
 /* 集成第一个协商参数集 */
 let finishProperties: Array<huks.HuksParam> = new Array();
 finishProperties[0] = {
     tag: huks.HuksTag.HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
     value: huks.HuksKeyStorageType.HUKS_STORAGE_ONLY_USED_IN_HUKS,
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
 let finishOptionsFrist: huks.HuksOptions = {
     properties: finishProperties,
     inData: StringToUint8Array(agreeX25519InData)
 }
 /* 集成第二个协商参数集 */
 let finishOptionsSecond: huks.HuksOptions = {
     properties: finishProperties,
     inData: StringToUint8Array(agreeX25519InData)
 }
 finishOptionsSecond.properties!.splice(6, 1, {
     tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
     value: StringToUint8Array(srcKeyAliasSecond + 'final'),
 })
 function StringToUint8Array(str:string) {
     let arr: number[] = new Array();
     for (let i = 0, j = str.length; i < j; ++i) {
         arr.push(str.charCodeAt(i));
     }
 return new Uint8Array(arr);
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
             throw(error as Error);
         }
     });
 }
 /* 调用generateKeyItem生成密钥 */
 async function publicGenKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
     console.info(`enter promise generateKeyItem`);
     let throwObject:throwObject = {isThrow: false};
     try {
         await generateKeyItem(keyAlias, huksOptions, throwObject)
         .then((data) => {
             console.info(`promise: generateKeyItem success, data = ${JSON.stringify(data)}`);
         })
         .catch((error: BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: generateKeyItem failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: generateKeyItem input arg invalid` + error);
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
             throw(error as Error);
         }
     });
 }
 /*调用initSession获取handle*/
 async function publicInitFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
     console.info(`enter promise doInit`);
     let throwObject: throwObject = {isThrow: false};
     try {
         await initSession(keyAlias, huksOptions, throwObject)
         .then ((data) => {
             console.info(`promise: doInit success, data = ${JSON.stringify(data)}`);
             handle = data.handle;
         })
         .catch((error: BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: doInit failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: doInit input arg invalid` + error);
     }
 }
 /* 分段添加密钥操作的数据并进行相应的密钥操作，输出处理数据 */
 function updateSession(handle: number, huksOptions: huks.HuksOptions, throwObject: throwObject)  {
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
             throw(error as Error);
         }
     });
 }
 /* 调用updateSession进行协商操作 */
 async function publicUpdateFunc(handle: number, huksOptions: huks.HuksOptions) {
     console.info(`enter promise doUpdate`);
     let throwObject: throwObject = {isThrow: false};
     try {
         await updateSession(handle, huksOptions, throwObject)
         .then ((data) => {
             console.info(`promise: doUpdate success, data = ${JSON.stringify(data)}`);
         })
         .catch((error: BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: doUpdate failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: doUpdate input arg invalid` + error);
     }
 }
 /* 结束密钥会话并进行相应的密钥操作，输出处理数据 */
 function finishSession(handle: number, huksOptions: huks.HuksOptions, throwObject: throwObject) {
     return new Promise<huks.HuksReturnResult>((resolve, reject) => {
         try {
             huks.finishSession(handle, huksOptions, (error, data) =>{
                 if (error) {
                     reject(error);
                 } else {
                     resolve(data);
                 }
             });
         } catch (error) {
             throwObject.isThrow = true;
             throw(error as Error);
         }
     });
 }
 /* 调用finishSession结束操作 */
 async function publicFinishFunc(handle: number, huksOptions: huks.HuksOptions) {
     console.info(`enter promise doFinish`);
     let throwObject: throwObject = {isThrow: false};
     try {
         await finishSession(handle, huksOptions, throwObject)
         .then ((data) => {
             finishOutData = data.outData as Uint8Array;
             console.info(`promise: doFinish success, data = ${JSON.stringify(data)}`);
         })
         .catch((error: BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: doFinish failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: doFinish input arg invalid` + error);
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
             throw(error as Error);
         }
     });
 }
 /* 调用exportKeyItem导出公钥操作 */
 async function publicExportKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
     console.info(`enter promise export`);
     let throwObject: throwObject = {isThrow: false};
     try {
         await exportKeyItem(keyAlias, huksOptions, throwObject)
         .then ((data) => {
             console.info(`promise: exportKeyItem success, data = ${JSON.stringify(data)}`);
             exportKey = data.outData as Uint8Array;
         })
         .catch((error: BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: exportKeyItem failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: exportKeyItem input arg invalid` + error);
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
             throw(error as Error);
         }
     });
 }
 /* 调用deleteKeyItem删除密钥操作 */
 async function publicDeleteKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
     console.info(`enter promise deleteKeyItem`);
     let throwObject: throwObject = {isThrow: false};
     try {
         await deleteKeyItem(keyAlias, huksOptions, throwObject)
         .then ((data) => {
            console.info(`promise: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
         })
         .catch((error :BusinessError) => {
             if (throwObject.isThrow) {
                 throw(error as Error);
             } else {
                 console.error(`promise: deleteKeyItem failed` + error);
             }
         });
     } catch (error) {
         console.error(`promise: deletKeeyItem input arg invalid` + error);
     }
 }
 async function testAgree() {
     /* 1.确定密钥别名并集成并集成要参数集 A设备：srcKeyAliasFirst  B设备：srcKeyAliasSecond*/
     /* 2.设备A生成密钥 */
     await publicGenKeyFunc(srcKeyAliasFirst, HuksOptions);
     /* 3.设备B生成密钥 */
     await publicGenKeyFunc(srcKeyAliasSecond, HuksOptions);
     /* 4.设备A、B导出非对称密钥的公钥 */
     await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
     exportKeyFrist = exportKey;
     await publicExportKeyFunc(srcKeyAliasFirst, HuksOptions);
     exportKeySecond = exportKey;
     /* 5.对第一个密钥进行协商（三段式）*/
     await publicInitFunc(srcKeyAliasFirst, HuksOptions);
     HuksOptions.inData = exportKeySecond;
     await publicUpdateFunc(handle, HuksOptions);
     await publicFinishFunc(handle, finishOptionsFrist);
     /* 5.对第二个密钥进行协商（三段式） */
     await publicInitFunc(srcKeyAliasSecond, HuksOptions);
     HuksOptions.inData = exportKeyFrist;
     await publicUpdateFunc(handle, HuksOptions);
     await publicFinishFunc(handle, finishOptionsSecond);
     /* 6.设备A、B删除密钥 */
     await publicDeleteKeyFunc(srcKeyAliasFirst, HuksOptions);
     await publicDeleteKeyFunc(srcKeyAliasSecond, HuksOptions);
 }
```
