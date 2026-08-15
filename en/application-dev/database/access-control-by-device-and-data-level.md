# Access Control by Device and Data Level (ArkTS)

<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=21aa413cf1755b055fbf63fdc2c1e46117039e5c translatedAt=2026-08-15T01:42:10.350Z pushedAt=2026-08-15T06:11:38.029Z -->

## Basic Concepts

Distributed data management implements access control based on data security labels and device security levels.

A higher data security label and device security level indicate stricter encryption and access control measures and higher data security.

### Data Security Labels

The data can be rated into four security levels as below.

| Risk Level| Security Level| Definition| Example| 
| -------- | -------- | -------- | -------- |
| Critical| S4 | Special data types defined by industry laws and regulations, involving the most private individual information or data that may cause severe adverse impact on an individual or group once disclosed, tampered with, corrupted, or destroyed.| Political opinions, religious and philosophical belief, trade union membership, genetic data, biological information, health and sexual life status, sexual orientation, device authentication, and personal credit card information| 
| High| S3 | Data that may cause critical adverse impact on an individual or group once disclosed, tampered with, corrupted, or destroyed.| Individual real-time precise positioning information and movement trajectory| 
| Moderate| S2 | Data that may cause major adverse impact on an individual or group once disclosed, tampered with, corrupted, or destroyed.| Detailed addresses and nicknames of individuals| 
| Low| S1 | Data that may cause minor adverse impact on an individual or group once disclosed, tampered with, corrupted, or destroyed.| Gender, nationality, and user application records| 

### Device Security Levels

<!--RP1-->

Device security levels are classified into SL1 to SL5 based on devices' security capabilities, such as whether a Trusted Execution Environment (TEE) or a secure storage chip is available. For example, the development boards RK3568 and Hi3516 are SL1 (lower security) devices, and tablets are SL4 (higher security) devices.

When devices are networked, you can run the `hidumper -s 3511` command to check the device security level. If no result is returned, run the `service_control start dslm_service` command to start the corresponding service, and then run the hidumper command again. The following figure shows the security level of an RK3568 device.

<!--RP1End-->
<!--Del-->

![Device-Security-Levels](figures/Device-Security-Levels.png)

<!--DelEnd-->

## Access Control Mechanism in Cross-Device Sync

In cross-device data sync, data access is controlled based on the device security level and data security labels. In principle, data can be synced only to the devices whose data security labels are not higher than the device's security level. The access control matrix is as follows.

|Device Security Level|Data Security Labels That Can Be Synced|
|---|---|
|SL1|S1|
|SL2|S1~S2|
|SL3|S1~S3|
|SL4|S1~S4|
|SL5|S1~S4|

<!--RP2-->

For example, the security level of development boards RK3568 and Hi3516 is SL1. The database with data security label S1 can be synced with RK3568 and Hi3516, but the databases with database labels S2-S4 cannot.

<!--RP2End-->

## When to Use

The access control mechanism ensures secure data storage and sync across devices. When creating a database, you need to correctly set the security level for the database.

## Setting the Security Level for a KV Store

When a KV store is created, the **securityLevel** parameter specifies the security level of the KV store. For details about the security levels, see [SecurityLevel](../reference/apis-arkdata/js-apis-distributedKVStore.md#securitylevel). The following example shows how to create a KV store with security level of S3.

For details about the APIs, see [Distributed KV Store](../reference/apis-arkdata/js-apis-distributedKVStore.md).
> **NOTE**
>
> For the scenarios involving a single device, you can upgrade the security level of a KV store by modifying the **securityLevel** parameter. When upgrading the database security level, observe the following:
> * This operation does not apply to the databases that require cross-device sync. Data cannot be synced between databases of different security levels. If you want to upgrade the security level of a database that requires cross-device sync, you are advised to create a database of a higher security level.
> * You need to close the database before modifying the **securityLevel** parameter, and open it after the security level is upgraded.
> * You cannot downgrade the database security level. For example, you can change the database security level from S2 to S3, but cannot change it from S3 to S2.

   ```ts
   // Import modules.
   // Create a KvStoreInterface.ets file in the pages directory.
   import { distributedKVStore } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   import EntryAbility from '../entryability/EntryAbility';
   // Logger implements the print feature after Hilog is encapsulated.
   import Logger from '../common/Logger';

   let kvManager: distributedKVStore.KVManager | undefined = undefined;
   let kvStore: distributedKVStore.SingleKVStore | undefined = undefined;
   let appId: string = 'com.example.kvstoresamples';
   let storeId: string = 'storeId';
   const context = EntryAbility.getContext();

   // The code of all the following APIs is implemented in KvInterface.
   export class KvInterface {
   }
   ```

   <!-- @[kv_store1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/KvStore/KvStoreSamples/entry/src/main/ets/pages/KvStoreInterface.ets) -->

   ``` TypeScript
   public CreateKvManager = (() => {
     Logger.info('CreateKvManager start');
     if (typeof (kvManager) === 'undefined') {
       const kvManagerConfig: distributedKVStore.KVManagerConfig = {
         bundleName: appId,
         context: context
       };
       try {
         // Create a KVManager instance.
         kvManager = distributedKVStore.createKVManager(kvManagerConfig);
         Logger.info('Succeeded in creating KVManager.');
       } catch (err) {
         Logger.error(`Failed to create KVManager. Code:${err.code},message:${err.message}`);
       }
     } else {
       Logger.info ('KVManager has created');
     }
   })
   ```

   <!-- @[kv_store3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/KvStore/KvStoreSamples/entry/src/main/ets/pages/KvStoreInterface.ets) -->

   ``` TypeScript
   public GetKvStore = (() => {
     Logger.info('GetKvStore start');
     if (kvManager === undefined) {
       Logger.info('KvManager not initialized');
       return;
     }
     try {
       let child1 = new distributedKVStore.FieldNode('id');
       child1.type = distributedKVStore.ValueType.INTEGER;
       child1.nullable = false;
       child1.default = '1';
       let child2 = new distributedKVStore.FieldNode('name');
       child2.type = distributedKVStore.ValueType.STRING;
       child2.nullable = false;
       child2.default = 'zhangsan';
   
       let schema = new distributedKVStore.Schema();
       schema.root.appendChild(child1);
       schema.root.appendChild(child2);
       schema.indexes = ['$.id', '$.name'];
       // The value 0 indicates the compatible mode, and 1 indicates the strict mode.
       schema.mode = 1;
       // Set the number of bytes to be skipped during the value check. The value range is [0, 4M-2].
       schema.skip = 0;
   
       const options: distributedKVStore.Options = {
         createIfMissing: true,
         // Whether to encrypt the KV store.
         encrypt: true,
         backup: false,
         autoSync: false,
         // If kvStoreType is left empty, a device KV store is created by default.
         kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
         // kvStoreType is distributedKVStore.KVStoreType.DEVICE_COLLABORATION for a device KV store.
         schema: schema,
         // If the schema is not defined, you can leave it empty. For details about how to define the schema, see the example above.
         securityLevel: distributedKVStore.SecurityLevel.S3
       };
       kvManager.getKVStore<distributedKVStore.SingleKVStore>(storeId, options,
         (err, store: distributedKVStore.SingleKVStore) => {
           if (err) {
             Logger.error(`Failed to get KVStore: Code:${err.code},message:${err.message}`);
             return;
           }
           Logger.info('Succeeded in getting KVStore.');
           kvStore = store;
           // Before performing related data operations, obtain a KV store instance.
         });
     } catch (e) {
       let error = e as BusinessError;
       Logger.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
     }
   })
   ```

## Setting the Security Level for an RDB Store

When an RDB store is created, the **securityLevel** parameter specifies the security level of the RDB store. For details about the security levels, see [SecurityLevel](../reference/apis-arkdata/arkts-apis-data-relationalStore-e.md#securitylevel). The following example shows how to create an RDB store with security level of S3.

For details about the APIs, see [RDB Store](../reference/apis-arkdata/arkts-apis-data-relationalStore.md).

<!-- @[rdb_accessControlByDeviceAndDataLevel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/RelationalStore/RdbStore/entry/src/main/ets/pages/accessControlByDeviceAndDataLevel.ets) -->  

``` TypeScript
import { relationalStore } from '@kit.ArkData';
import { UIContext } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

let store: relationalStore.RdbStore | undefined = undefined;

export async function accessControlByDeviceAndDataLevel() {
  /* context indicates the application's context information, which is obtained by the caller. The following is for demonstration purposes only. */
  const context = new UIContext().getHostContext() as common.UIAbilityContext;
  try {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: 'RdbTest.db',
      // Set the security level of the RDB store to S3.
      securityLevel: relationalStore.SecurityLevel.S3
    };
    store = await relationalStore.getRdbStore(context, STORE_CONFIG);
    console.info('Succeeded in getting RdbStore.')
  } catch (err) {
    console.error(`Failed to get RdbStore. Code:${err.code}, message:${err.message}`);
  }
}
```