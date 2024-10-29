# E类加密数据库的使用


## 场景介绍

为了满足数据库的安全特性，存有敏感信息的应用会在[EL5](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode)（加密路径切换请参考[获取和修改加密分区](../application-models/application-context-stage.md#获取和修改加密分区)EL1-EL4路径切换）路径下创建了一个E类数据库。在锁屏的情况下，满足一定条件时，会触发密钥的销毁。此时E类数据库不可操作。当锁屏解锁后，密钥会恢复，E类数据库恢复正常读写操作。这样的设计可以有效防止用户数据的泄露。

然而，在锁屏的过程中，应用程序仍然可以继续写入数据，由于此时E类数据库不可读写，可能会导致数据丢失。为了解决这个问题，当前提供了一种方案：在锁屏的状态下，将数据存储在[EL2](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode)路径下的C类数据库中。当解锁后，再将数据迁移到E类数据库中。这样可以确保数据在锁屏期间的安全性和一致性。

键值型数据库和关系型数据库均支持E类加密数据库。

## 实现机制

通过封装Mover类、Store类、SecretKeyObserver类和ECStoreManager类实现应用数据库密钥加锁和解锁状态下E类数据库和C类数据库的切换和操作。

Mover类：提供数据库数据迁移接口，在锁屏解锁后，若C类数据库中有数据，使用该接口将数据迁移到E类数据库。

Store类：提供访问当前可操作数据库，对数据库进行相关操作的接口。

SecretKeyObserver类：提供了获取当前密钥状态的接口，在密钥销毁后，关闭E类数据库。

ECStoreManager类：用于管理应用的E类数据库和C类数据库。

## 配置权限

使用EL5路径下的数据库，需要配置ohos.permission.PROTECT_SCREEN_LOCK_DATA权限。

```ts
// module.json5
"requestPermissions": [
      {
        "name": "ohos.permission.PROTECT_SCREEN_LOCK_DATA"
      }
    ]
```

## 键值型数据库E类加密

本章节提供键值型数据库的E类加密数据库使用方式，提供[Mover](#mover)类、[Store](#store)类、[SecretKeyObserver](#secretkeyobserver)类和[ECStoreManager](#ecstoremanager)类的具体实现，并在[EntryAbility](#entryability)和[index按键事件](#index按键事件)中展示这几个类的使用方式。

### Mover

提供数据库数据迁移接口，在锁屏解锁后，若C类数据库中存在数据，使用该接口将数据迁移到E类数据库。

```ts
// Mover.ts
import { distributedKVStore } from '@kit.ArkData';

export class Mover {
  async move(eStore: distributedKVStore.SingleKVStore, cStore: distributedKVStore.SingleKVStore): Promise<void> {
    if (eStore != null && cStore != null) {
      let entries: distributedKVStore.Entry[] = await cStore.getEntries('key_test_string');
      await eStore.putBatch(entries);
      console.info(`ECDB_Encry move success`);
    }
  }
}
```

### Store

提供了获取数据库，在数据库中插入数据、删除数据、更新数据和获取当前数据数量的接口。

```ts
// Store.ts
import { distributedKVStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let kvManager: distributedKVStore.KVManager;

export class StoreInfo {
  kvManagerConfig: distributedKVStore.KVManagerConfig;
  storeId: string;
  option: distributedKVStore.Options;
}

export class Store {
  async getECStore(storeInfo: StoreInfo): Promise<distributedKVStore.SingleKVStore> {
    try {
      kvManager = distributedKVStore.createKVManager(storeInfo.kvManagerConfig);
      console.info("Succeeded in creating KVManager");
    } catch (e) {
      let error = e as BusinessError;
      console.error(`Failed to create KVManager.code is ${error.code},message is ${error.message}`);
    }
    if (kvManager !== undefined) {
      kvManager = kvManager as distributedKVStore.KVManager;
      let kvStore: distributedKVStore.SingleKVStore | null;
      try {
        kvStore = await kvManager.getKVStore<distributedKVStore.SingleKVStore>(storeInfo.storeId, storeInfo.option);
        if (kvStore != undefined) {
          console.info(`ECDB_Encry succeeded in getting store : ${storeInfo.storeId}`);
          return kvStore;
        }
      } catch (e) {
        let error = e as BusinessError;
        console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);
      }
    }
  }

  putOnedata(kvStore: distributedKVStore.SingleKVStore): void {
    if (kvStore != undefined) {
      const KEY_TEST_STRING_ELEMENT = 'key_test_string' + String(Date.now());
      const VALUE_TEST_STRING_ELEMENT = 'value_test_string' + String(Date.now());
      try {
        kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
          if (err !== undefined) {
            console.error(`Failed to put data. Code:${err.code},message:${err.message}`);
            return;
          }
          console.info(`ECDB_Encry Succeeded in putting data.${KEY_TEST_STRING_ELEMENT}`);
        });
      } catch (e) {
        let error = e as BusinessError;
        console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
      }
    }
  }

  getDataNum(kvStore: distributedKVStore.SingleKVStore): void {
    if (kvStore != undefined) {
      let resultSet: distributedKVStore.KVStoreResultSet;
      kvStore.getResultSet("key_test_string").then((result: distributedKVStore.KVStoreResultSet) => {
        console.info(`ECDB_Encry Succeeded in getting result set num ${result.getCount()}`);
        resultSet = result;
        if (kvStore != null) {
          kvStore.closeResultSet(resultSet).then(() => {
            console.info('Succeeded in closing result set');
          }).catch((err: BusinessError) => {
            console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);
          });
        }
      }).catch((err: BusinessError) => {
        console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);
      });
    }
  }

  deleteOnedata(kvStore: distributedKVStore.SingleKVStore): void {
    if (kvStore != undefined) {
      kvStore.getEntries('key_test_string', (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err != undefined) {
          console.error(`Failed to get Entries.code is ${err.code},message is ${err.message}`);
          return;
        }
        if (kvStore != null && entries.length != 0) {
          kvStore.delete(entries[0].key, (err: BusinessError) => {
            if (err != undefined) {
              console.error(`Failed to delete.code is ${err.code},message is ${err.message}`);
              return;
            }
            console.info('ECDB_Encry Succeeded in deleting');
          });
        }
      });
    }
  }

  updataOnedata(kvStore: distributedKVStore.SingleKVStore): void {
    if (kvStore != undefined) {
      kvStore.getEntries('key_test_string', async (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err != undefined) {
          console.error(`Failed to get Entries.code is ${err.code},message is ${err.message}`);
          return;
        }
        if (kvStore != null && entries.length != 0) {
          console.info(`ECDB_Encry old data:${entries[0].key},value :${entries[0].value.value.toString()}`)
          await kvStore.put(entries[0].key, "new value_test_string" + String(Date.now()) + 'new').then(() => {
          }).catch((err: BusinessError) => {
            console.error(`Failed to put.code is ${err.code},message is ${err.message}`);
          });
        }
        console.info(`ECDB_Encry updata success`)
      });
    }
  }
}
```

### SecretKeyObserver

该类提供了获取当前密钥状态的接口，在密钥销毁后，关闭E类数据库。

```ts
// SecretKeyObserver.ts
import { ECStoreManager } from './ECStoreManager';

export enum SecretStatus {
  Lock,
  UnLock
}

export class SecretKeyObserver {
  onLock(): void {
    this.lockStatuas = SecretStatus.Lock;
    this.storeManager.closeEStore();
  }

  onUnLock(): void {
    this.lockStatuas = SecretStatus.UnLock;
  }

  getCurrentStatus(): number {
    return this.lockStatuas;
  }

  initialize(storeManager: ECStoreManager): void {
    this.storeManager = storeManager;
  }

  updatalockStatus(code: number) {
    if (code === SecretStatus.Lock) {
      this.onLock();
    } else {
      this.lockStatuas = code;
    }
  }

  // 初始获取锁屏状态
  private lockStatuas: number = SecretStatus.UnLock;
  private storeManager: ECStoreManager;
}

export let lockObserve = new SecretKeyObserver();
```

### ECStoreManager

ECStoreManager类用于管理应用的E类数据库和C类数据库。提供配置数据库信息、配置迁移函数的信息，根据密钥状态为应用提供相应的数据库句柄、提供E类数据关库接口和在数据迁移完成后销毁C类数据库的接口。

```ts
// ECStoreManager.ts
import { distributedKVStore } from '@kit.ArkData';
import { Mover } from './Mover';
import { BusinessError } from '@kit.BasicServicesKit';
import { StoreInfo, Store } from './Store';
import { SecretStatus } from './SecretKeyObserver';

let store = new Store();

export class ECStoreManager {
  config(cInfo: StoreInfo, other: StoreInfo): void {
    this.cInfo = cInfo;
    this.eInfo = other;
  }

  configDataMover(mover: Mover): void {
    this.mover = mover;
  }

  async getCurrentStore(screanStatus: number): Promise<distributedKVStore.SingleKVStore> {
    console.info(`ECDB_Encry GetCurrentStore start screanStatus: ${screanStatus}`);
    if (screanStatus === SecretStatus.UnLock) {
      try {
        this.eStore = await store.getECStore(this.eInfo);
      } catch (e) {
        let error = e as BusinessError;
        console.error(`Failed to GetECStore.code is ${error.code},message is ${error.message}`);
      }
      // 解锁状态 获取e类库
      if (this.needMove) {
        if (this.eStore != undefined && this.cStore != undefined) {
          await this.mover.move(this.eStore, this.cStore);
        }
        this.deleteCStore();
        console.info(`ECDB_Encry Data migration is complete. Destroy cstore`);
        this.needMove = false;
      }
      return this.eStore;
    } else {
      // 加锁状态 获取c类库
      this.needMove = true;
      try {
        this.cStore = await store.getECStore(this.cInfo);
      } catch (e) {
        let error = e as BusinessError;
        console.error(`Failed to GetECStore.code is ${error.code},message is ${error.message}`);
      }
      return this.cStore;
    }
  }

  closeEStore(): void {
    try {
      let kvManager = distributedKVStore.createKVManager(this.eInfo.kvManagerConfig);
      console.info("Succeeded in creating KVManager");
      if (kvManager != undefined) {
        kvManager.closeKVStore(this.eInfo.kvManagerConfig.bundleName, this.eInfo.storeId);
        this.eStore = null;
        console.info(`ECDB_Encry close EStore success`)
      }
    } catch (e) {
      let error = e as BusinessError;
      console.error(`Failed to create KVManager.code is ${error.code},message is ${error.message}`);
    }
  }

  deleteCStore(): void {
    try {
      let kvManager = distributedKVStore.createKVManager(this.cInfo.kvManagerConfig);
      console.info("Succeeded in creating KVManager");
      if (kvManager != undefined) {
        kvManager.deleteKVStore(this.cInfo.kvManagerConfig.bundleName, this.cInfo.storeId);
        this.cStore = null;
        console.info("ECDB_Encry delete cStore success");
      }
    } catch (e) {
      let error = e as BusinessError;
      console.error(`Failed to create KVManager.code is ${error.code},message is ${error.message}`);
    }
  }

  private eStore: distributedKVStore.SingleKVStore = null;
  private cStore: distributedKVStore.SingleKVStore = null;
  private cInfo: StoreInfo | null = null;
  private eInfo: StoreInfo | null = null;
  private needMove: boolean = false;
  private mover: Mover | null = null;
}
```

### EntryAbility

模拟应用启动期间，注册对COMMON_EVENT_SCREEN_LOCK_FILE_ACCESS_STATE_CHANGED公共事件的监听，并配置相应的数据库信息、密钥状态信息等。

```ts
// EntryAbility.ets
import { AbilityConstant, contextConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { distributedKVStore } from '@kit.ArkData';
import { ECStoreManager } from './ECStoreManager';
import { StoreInfo } from './Store';
import { Mover } from './Mover';
import { SecretKeyObserver } from './SecretKeyObserver';
import { commonEventManager } from '@kit.BasicServicesKit';
import { BusinessError } from '@kit.BasicServicesKit';


export let storeManager = new ECStoreManager();

export let e_secretKeyObserver = new SecretKeyObserver();

let mover = new Mover();

let subscriber: commonEventManager.CommonEventSubscriber;

export function createCB(err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) {
  if (!err) {
    console.info('ECDB_Encry createSubscriber');
    subscriber = commonEventSubscriber;
    try {
      commonEventManager.subscribe(subscriber, (err: BusinessError, data: commonEventManager.CommonEventData) => {
        if (err) {
          console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
        } else {
          console.info(`ECDB_Encry SubscribeCB ${data.code}`);
          e_secretKeyObserver.updatalockStatus(data.code);
        }
      });
    } catch (error) {
      const err: BusinessError = error as BusinessError;
      console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    }
  } else {
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
  }
}

let cInfo: StoreInfo | null = null;
let eInfo: StoreInfo | null = null;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    let cContext = this.context;
    cInfo = {
      "kvManagerConfig": {
        context: cContext,
        bundleName: 'com.example.ecstoredemo',
      },
      "storeId": "cstore",
      "option": {
        createIfMissing: true,
        encrypt: false,
        backup: false,
        autoSync: false,
        // kvStoreType不填时，默认创建多设备协同数据库
        kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
        // 多设备协同数据库：kvStoreType: distributedKVStore.KVStoreType.DEVICE_COLLABORATION,
        securityLevel: distributedKVStore.SecurityLevel.S3
      }
    }
    let eContext = this.context.createModuleContext("entry");
    eContext.area = contextConstant.AreaMode.EL5;
    eInfo = {
      "kvManagerConfig": {
        context: eContext,
        bundleName: 'com.example.ecstoredemo',
      },
      "storeId": "estore",
      "option": {
        createIfMissing: true,
        encrypt: false,
        backup: false,
        autoSync: false,
        // kvStoreType不填时，默认创建多设备协同数据库
        kvStoreType: distributedKVStore.KVStoreType.SINGLE_VERSION,
        // 多设备协同数据库：kvStoreType: distributedKVStore.KVStoreType.DEVICE_COLLABORATION,
        securityLevel: distributedKVStore.SecurityLevel.S3
      }
    }
    console.info(`ECDB_Encry store area : estore:${eContext.area},cstore${cContext.area}`);
    // 监听COMMON_EVENT_SCREEN_LOCK_FILE_ACCESS_STATE_CHANGED事件 code == 1解锁状态，code==0加锁状态
    try {
      commonEventManager.createSubscriber({
        events: ['COMMON_EVENT_SCREEN_LOCK_FILE_ACCESS_STATE_CHANGED']
      }, createCB);
      console.info(`ECDB_Encry success subscribe`);
    } catch (error) {
      const err: BusinessError = error as BusinessError;
      console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
    }
    storeManager.config(cInfo, eInfo);
    storeManager.configDataMover(mover);
    e_secretKeyObserver.initialize(storeManager);
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content.');
    });
  }

  onWindowStageDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```

### Index按键事件

使用Button按钮，通过点击按钮来模拟应用操作数据库，如插入数据、删除数据、更新数据和获取数据数量的操作等，展示数据库基本的增删改查能力。

```ts
// Index.ets
import { storeManager, e_secretKeyObserver } from "../entryability/EntryAbility";
import { distributedKVStore } from '@kit.ArkData';
import { Store } from '../entryability/Store';

let storeOption = new Store();

let lockStatus: number = 1;

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button('加锁/解锁').onClick((event: ClickEvent) => {
          if (lockStatus) {
            e_secretKeyObserver.onLock();
            lockStatus = 0;
          } else {
            e_secretKeyObserver.onUnLock();
            lockStatus = 1;
          }
          lockStatus ? this.message = "解锁" : this.message = "加锁";
        }).margin("5");
        Button('store type').onClick(async (event: ClickEvent) => {
          e_secretKeyObserver.getCurrentStatus() ? this.message = "estroe" : this.message = "cstore";
        }).margin("5");

        Button("put").onClick(async (event: ClickEvent) => {
          let store: distributedKVStore.SingleKVStore = await storeManager.getCurrentStore(e_secretKeyObserver.getCurrentStatus());
          storeOption.putOnedata(store);
        }).margin(5)

        Button("Get").onClick(async (event: ClickEvent) => {
          let store: distributedKVStore.SingleKVStore = await storeManager.getCurrentStore(e_secretKeyObserver.getCurrentStatus());
          storeOption.getDataNum(store);
        }).margin(5)

        Button("delete").onClick(async (event: ClickEvent) => {
          let store: distributedKVStore.SingleKVStore = await storeManager.getCurrentStore(e_secretKeyObserver.getCurrentStatus());
          storeOption.deleteOnedata(store);
        }).margin(5)

        Button("updata").onClick(async (event: ClickEvent) => {
          let store: distributedKVStore.SingleKVStore = await storeManager.getCurrentStore(e_secretKeyObserver.getCurrentStatus());
          storeOption.updataOnedata(store);
        }).margin(5)

        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 关系型数据库E类加密

本章节提供关系型数据库的E类加密数据库使用方式，提供[Mover](#mover-1)类，[Store](#store-1)类，[SecretKeyObserver](#secretkeyobserver-1)类和[ECStoreManager](#ecstoremanager-1)类的具体实现，并在[EntryAbility](#entryability-1)和[index按键事件](#index按键事件-1)中展示这几个类的使用方式。

### Mover

提供数据库数据迁移接口，在锁屏解锁后，若C类数据库中有数据，使用该接口将数据迁移到E类数据库。

```ts
// Mover.ts
import { relationalStore } from '@kit.ArkData';

export class Mover {
  async move(eStore: relationalStore.RdbStore, cStore: relationalStore.RdbStore) {
    if (eStore != null && cStore != null) {
      let predicates = new relationalStore.RdbPredicates('employee');
      let resultSet = await cStore.query(predicates);
      while (resultSet.goToNextRow()) {
        let bucket = resultSet.getRow();
        await eStore.insert('employee', bucket);
      }
    }
  }
}
```

### Store

提供了获取数据库，在数据库中插入数据、删除数据、更新数据和获取当前数据数量的接口。其中StoreInfo类用于存储获取数据库相关信息。

```ts
// Store.ts
import { relationalStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import { Context } from '@kit.AbilityKit';

export class StoreInfo {
  context: Context;
  config: relationalStore.StoreConfig;
  storeId: string;
}

let id = 1;
const SQL_CREATE_TABLE = 'CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)';


export class Store {
  async getECStore(storeInfo: StoreInfo): Promise<relationalStore.RdbStore> {
    let rdbStore: relationalStore.RdbStore | null;
    try {
      rdbStore = await relationalStore.getRdbStore(storeInfo.context, storeInfo.config);
      if (rdbStore.version == 0) {
        await rdbStore.executeSql(SQL_CREATE_TABLE);
        console.info(`ECDB_Encry succeeded in getting Store ：${storeInfo.storeId}`);
        rdbStore.version = 1;
      }
    } catch (e) {
      let error = e as BusinessError;
      console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);
    }
    return rdbStore;
  }

  async putOnedata(rdbStore: relationalStore.RdbStore) {
    if (rdbStore != undefined) {
      const valueBucket: relationalStore.ValuesBucket = {
        ID: id++,
        NAME: 'Lisa',
        AGE: 18,
        SALARY: 100.5,
        CODES: new Uint8Array([1, 2, 3, 4, 5]),
      };
      try {
        await rdbStore.insert("EMPLOYEE", valueBucket);
        console.info(`ECDB_Encry insert success`);
      } catch (e) {
        let error = e as BusinessError;
        console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
      }
    }
  }

  async getDataNum(rdbStore: relationalStore.RdbStore) {
    if (rdbStore != undefined) {
      try {
        let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
        let resultSet = await rdbStore.query(predicates);
        let count = resultSet.rowCount;
        console.info(`ECDB_Encry getdatanum success count : ${count}`);
      } catch (e) {
        let error = e as BusinessError;
        console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
      }
    }
  }

  async deleteAlldata(rdbStore: relationalStore.RdbStore) {
    if (rdbStore != undefined) {
      try {
        let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
        predicates.equalTo('AGE', 18);
        await rdbStore.delete(predicates);
        console.info(`ECDB_Encry delete Success`);
      } catch (e) {
        let error = e as BusinessError;
        console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
      }
    }
  }

  async updataOnedata(rdbStore: relationalStore.RdbStore) {
    if (rdbStore != undefined) {
      try {
        let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
        predicates.equalTo('NAME', 'Lisa');
        const valueBucket: relationalStore.ValuesBucket = {
          NAME: 'Anna',
          SALARY: 100.5,
          CODES: new Uint8Array([1, 2, 3, 4, 5]),
        };
        await rdbStore.update(valueBucket, predicates);
        console.info(`ECDB_Encry update success`);
      } catch (e) {
        let error = e as BusinessError;
        console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
      }
    }
  }
}
```

### SecretKeyObserver

该类提供了获取当前密钥状态的接口，在密钥销毁后，关闭E类数据库。

```ts
// SecretKeyObserver.ts
import { ECStoreManager } from './ECStoreManager';

export enum SecretStatus {
  Lock,
  UnLock
}

export class SecretKeyObserver {
  onLock(): void {
    this.lockStatuas = SecretStatus.Lock;
    this.storeManager.closeEStore();
  }

  onUnLock(): void {
    this.lockStatuas = SecretStatus.UnLock;
  }

  getCurrentStatus(): number {
    return this.lockStatuas;
  }

  initialize(storeManager: ECStoreManager): void {
    this.storeManager = storeManager;
  }

  updatalockStatus(code: number) {
    if (this.lockStatuas === SecretStatus.Lock) {
      this.onLock();
    } else {
      this.lockStatuas = code;
    }
  }

  private lockStatuas: number = SecretStatus.UnLock;
  private storeManager: ECStoreManager;
}

export let lockObserve = new SecretKeyObserver();
```

### ECStoreManager

ECStoreManager类用于管理应用的E类数据库和C类数据库。提供配置数据库信息、配置迁移函数的信息，根据密钥状态为应用提供相应的数据库句柄、提供E类数据关库接口和在数据迁移完成后销毁C类数据库的接口。

```ts
// ECStoreManager.ts
import { relationalStore } from '@kit.ArkData';
import { Mover } from './Mover';
import { BusinessError } from '@kit.BasicServicesKit';
import { StoreInfo, Store } from './Store';
import { SecretStatus } from './SecretKeyObserver';

let store = new Store();

export class ECStoreManager {
  config(cInfo: StoreInfo, other: StoreInfo): void {
    this.cInfo = cInfo;
    this.eInfo = other;
  }

  configDataMover(mover: Mover): void {
    this.mover = mover;
  }

  async getCurrentStore(screanStatus: number): Promise<relationalStore.RdbStore> {
    if (screanStatus === SecretStatus.UnLock) {
      try {
        this.eStore = await store.getECStore(this.eInfo);
      } catch (e) {
        let error = e as BusinessError;
        console.error(`Failed to GetECStore.code is ${error.code},message is ${error.message}`);
      }
      // 解锁状态 获取e类库
      if (this.needMove) {
        if (this.eStore != undefined && this.cStore != undefined) {
          await this.mover.move(this.eStore, this.cStore);
          console.info(`ECDB_Encry cstore data move to estore success`);
        }
        this.deleteCStore();
        this.needMove = false;
      }
      return this.eStore;
    } else {
      // 加锁状态 获取c类库
      this.needMove = true;
      try {
        this.cStore = await store.getECStore(this.cInfo);
      } catch (e) {
        let error = e as BusinessError;
        console.error(`Failed to GetECStore.code is ${error.code},message is ${error.message}`);
      }
      return this.cStore;
    }
  }

  closeEStore(): void {
    this.eStore = undefined;
  }

  async deleteCStore() {
    try {
      await relationalStore.deleteRdbStore(this.cInfo.context, this.cInfo.storeId)
    } catch (e) {
      let error = e as BusinessError;
      console.error(`Failed to create KVManager.code is ${error.code},message is ${error.message}`);
    }
  }

  private eStore: relationalStore.RdbStore = null;
  private cStore: relationalStore.RdbStore = null;
  private cInfo: StoreInfo | null = null;
  private eInfo: StoreInfo | null = null;
  private needMove: boolean = false;
  private mover: Mover | null = null;
}
```

### EntryAbility

模拟在应用启动期间，注册对COMMON_EVENT_SCREEN_LOCK_FILE_ACCESS_STATE_CHANGED公共事件的监听，并配置相应的数据库信息、密钥状态信息等。

```ts
// EntryAbility.ets
import { AbilityConstant, contextConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { relationalStore } from '@kit.ArkData';
import { ECStoreManager } from './ECStoreManager';
import { StoreInfo } from './Store';
import { Mover } from './Mover';
import { SecretKeyObserver } from './SecretKeyObserver';
import { commonEventManager } from '@kit.BasicServicesKit';
import { BusinessError } from '@kit.BasicServicesKit';


export let storeManager = new ECStoreManager();

export let e_secretKeyObserver = new SecretKeyObserver();

let mover = new Mover();

let subscriber: commonEventManager.CommonEventSubscriber;

export function createCB(err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) {
  if (!err) {
    console.info('ECDB_Encry createSubscriber');
    subscriber = commonEventSubscriber;
    try {
      commonEventManager.subscribe(subscriber, (err: BusinessError, data: commonEventManager.CommonEventData) => {
        if (err) {
          console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
        } else {
          console.info(`ECDB_Encry SubscribeCB ${data.code}`);
          e_secretKeyObserver.updatalockStatus(data.code);
        }
      });
    } catch (error) {
      const err: BusinessError = error as BusinessError;
      console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    }
  } else {
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
  }
}

let cInfo: StoreInfo | null = null;
let eInfo: StoreInfo | null = null;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    let cContext = this.context;
    cInfo = {
      context: cContext,
      config: {
        name: 'cstore.db',
        securityLevel: relationalStore.SecurityLevel.S3,
      },
      storeId: "cstore.db"
    }
    let eContext = this.context.createModuleContext("entry");
    eContext.area = contextConstant.AreaMode.EL5;
    eInfo = {
      context: eContext,
      config: {
        name: 'estore.db',
        securityLevel: relationalStore.SecurityLevel.S3,
      },
      storeId: "estore.db",
    }
    // 监听COMMON_EVENT_SCREEN_LOCK_FILE_ACCESS_STATE_CHANGED事件 code == 1解锁状态，code==0加锁状态
    console.info(`ECDB_Encry store area : estore:${eContext.area},cstore${cContext.area}`)
    try {
      commonEventManager.createSubscriber({
        events: ['COMMON_EVENT_SCREEN_LOCK_FILE_ACCESS_STATE_CHANGED']
      }, createCB);
      console.info(`ECDB_Encry success subscribe`);
    } catch (error) {
      const err: BusinessError = error as BusinessError;
      console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
    }
    storeManager.config(cInfo, eInfo);
    storeManager.configDataMover(mover);
    e_secretKeyObserver.initialize(storeManager);
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content.');
    });
  }

  onWindowStageDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```

### Index按键事件

使用Button按钮，通过点击按钮来模拟应用操作数据库，如插入数据、删除数据、更新数据和获取数据数量的操作等，展示数据库基本的增删改查能力。

```ts
// Index.ets
import { storeManager, e_secretKeyObserver } from "../entryability/EntryAbility";
import { relationalStore } from '@kit.ArkData';
import { Store } from '../entryability/Store';

let storeOption = new Store();

let lockStatus: number = 1;

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Button('加锁/解锁').onClick((event: ClickEvent) => {
          if (lockStatus) {
            e_secretKeyObserver.onLock();
            lockStatus = 0;
          } else {
            e_secretKeyObserver.onUnLock();
            lockStatus = 1;
          }
          lockStatus ? this.message = "解锁" : this.message = "加锁";
        }).margin("5");
        Button('store type').onClick(async (event: ClickEvent) => {
          e_secretKeyObserver.getCurrentStatus() ? this.message = "estroe" : this.message = "cstore";
          console.info(`ECDB_Encry current store : ${this.message}`);
        }).margin("5");

        Button("put").onClick(async (event: ClickEvent) => {
          let store: relationalStore.RdbStore = await storeManager.getCurrentStore(e_secretKeyObserver.getCurrentStatus());
          storeOption.putOnedata(store);
        }).margin(5)

        Button("Get").onClick(async (event: ClickEvent) => {
          let store: relationalStore.RdbStore = await storeManager.getCurrentStore(e_secretKeyObserver.getCurrentStatus());
          storeOption.getDataNum(store);
        }).margin(5)

        Button("delete").onClick(async (event: ClickEvent) => {
          let store: relationalStore.RdbStore = await storeManager.getCurrentStore(e_secretKeyObserver.getCurrentStatus());
          storeOption.deleteAlldata(store);
        }).margin(5)

        Button("updata").onClick(async (event: ClickEvent) => {
          let store: relationalStore.RdbStore = await storeManager.getCurrentStore(e_secretKeyObserver.getCurrentStatus());
          storeOption.updataOnedata(store);
        }).margin(5)

        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
