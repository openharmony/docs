# 支持E类数据加密


## 场景介绍

为了满足数据库的安全特性，存有敏感信息的应用会在el5路径下创建了一个E类数据库。在锁屏的情况下，当满足一定条件时，会触发密钥的销毁。此时，E类数据库不可操作。当锁屏解锁后，密钥会恢复，并且E类数据库恢复正常进行读写操作。这样的设计可以有效防止用户数据的泄露。

然而，在锁屏的过程中，应用程序仍然可以继续写入数据，这可能会导致数据的不一致。为了解决这个问题，本文档提供了一种方案：在锁屏的状态下，将数据存储在el2路径下的C类数据库中。当解锁后，再将数据迁移到E类数据库中。这样可以确保数据在锁屏期间的安全性，同时在解锁后保持数据的一致性。

## 设计思路

### 类图

Mover类:提供数据库数据迁移接口，在锁屏开启后若C类数据库中有数据，使用该接口将数据迁移到E类数据库。

Store:提供访问操作数据库的公共函数。

secretKeyObserve类：提供了获取当前密钥状态的接口，在密钥销毁后，关闭E类数据库。

ECStoreManager类：用于管理应用的E类数据库和C类数据库。

![image-20240611214951850](C:\Users\ljy\AppData\Roaming\Typora\typora-user-images\image-20240611214951850.png)

### 时序图

![image-20240611215607990](C:\Users\ljy\AppData\Roaming\Typora\typora-user-images\image-20240611215607990.png)

![image-20240611215604295](C:\Users\ljy\AppData\Roaming\Typora\typora-user-images\image-20240611215604295.png)

![image-20240611215624748](C:\Users\ljy\AppData\Roaming\Typora\typora-user-images\image-20240611215624748.png)

## 配置权限

在model.json5中配置ohos.permission.PROTECT_SCREEN_LOCK_DATA权限。

```
//未配置权限会报错：create dir /data/storage/el5/database/entry failed, errno is 13.）
"requestPermissions": [
      {
        "name": "ohos.permission.PROTECT_SCREEN_LOCK_DATA"
      }
    ]
```

## 键值型数据库E类加密

### Mover

提供数据库数据迁移接口，在锁屏开启后若C类数据库中有数据，使用该接口将数据迁移到E类数据库。

```
import { distributedKVStore } from '@kit.ArkData';

export class Mover {
  async Move(eStore: distributedKVStore.SingleKVStore, cStore: distributedKVStore.SingleKVStore) {
    if (eStore != null && cStore != null) {
      console.info(`ljy needmove`);
      let entries: distributedKVStore.Entry[] = await cStore.getEntries('key_test_string');
      await eStore.putBatch(entries);
      console.info(`ljy move success`);
    }
  }
}

```

### Store

提供了在数据库中插入数据，删除数据，更新数据，获取当前数据条数的接口。其中StoreInfo类是一个用于存储获取数据库相关信息。

```ts
import { distributedKVStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let kvManager: distributedKVStore.KVManager;

export class StoreInfo {
  kvManagerConfig: distributedKVStore.KVManagerConfig;
  storeId: string;
  option: distributedKVStore.Options;
  isEstore: boolean;
}

export class Store {
  async GetECStore(storeInfo: StoreInfo): Promise<distributedKVStore.SingleKVStore> {
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
          return kvStore;
        }
      } catch (e) {
        let error = e as BusinessError;
        console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);
      }
    }
  }

  Putdata(kvStore: distributedKVStore.SingleKVStore) {
    if (kvStore != undefined) {
      const KEY_TEST_STRING_ELEMENT = 'key_test_string' + String(Date.now());
      const VALUE_TEST_STRING_ELEMENT = 'value_test_string' + String(Date.now());
      try {
        kvStore.put(KEY_TEST_STRING_ELEMENT, VALUE_TEST_STRING_ELEMENT, (err) => {
          if (err !== undefined) {
            console.error(`Failed to put data. Code:${err.code},message:${err.message}`);
            return;
          }
          console.info(`ljy Succeeded in putting data.${KEY_TEST_STRING_ELEMENT}`);
        });
      } catch (e) {
        let error = e as BusinessError;
        console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
      }
    }
  }

  GetDataNum(kvStore: distributedKVStore.SingleKVStore) {
    if (kvStore != undefined) {
      let resultSet: distributedKVStore.KVStoreResultSet;
      kvStore.getResultSet("key_test_string").then((result: distributedKVStore.KVStoreResultSet) => {
        console.info(`ljy Succeeded in getting result set num ${result.getCount()}`);
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

  deleteOnedata(kvStore: distributedKVStore.SingleKVStore) {
    if (kvStore != undefined) {
      kvStore.getEntries('key_test_string', (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err != undefined) {
          console.error(`Failed to get Entries.code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('ljy Succeeded in getting Entries');
        if (kvStore != null && entries.length != 0) {
          kvStore.delete(entries[0].key, (err: BusinessError) => {
            if (err != undefined) {
              console.error(`Failed to delete.code is ${err.code},message is ${err.message}`);
              return;
            }
            console.info('ljy Succeeded in deleting');
          });
        }
      });
    }
  }

  updataOnedata(kvStore: distributedKVStore.SingleKVStore) {
    if (kvStore != undefined) {
      kvStore.getEntries('key_test_string', async (err: BusinessError, entries: distributedKVStore.Entry[]) => {
        if (err != undefined) {
          console.error(`Failed to get Entries.code is ${err.code},message is ${err.message}`);
          return;
        }
        if (kvStore != null && entries.length != 0) {
          console.info(`ljy old data:${entries[0].key},value :${entries[0].value.value.toString()}`)
          await kvStore.put(entries[0].key, "new value_test_string" + String(Date.now()) + 'new').then(() => {
          }).catch((err: BusinessError) => {
            console.error(`Failed to put.code is ${err.code},message is ${err.message}`);
          });
        }
        console.info(`ljy updata success`)
      });
    }
  }
}
```

### secretKeyObserve

该类提供了获取当前密钥状态的接口，在密钥销毁后，关闭E类数据库。

```
import { ECStoreManager } from './ECStoreManager'

enum secretStatus {
  Lock,
  UnLock
}

export class secretKeyObserve {
  OnLock(): void {
    this.lockStatuas = secretStatus.Lock;
    this.storeManager.CloseEStore();
  }

  OnUnLock(): void {
    this.lockStatuas = secretStatus.UnLock;
  }

  GetCurrentStatus(): number {
    return this.lockStatuas;
  }

  Initialize(storeManager: ECStoreManager): void {
    this.storeManager = storeManager;
  }

  UpdatalockStatus(code: number) {
    this.lockStatuas = code;
  }

  private lockStatuas: number = secretStatus.UnLock;
  private storeManager: ECStoreManager;
}

export let lockObserve = new secretKeyObserve();
```

### ECStoreManager

ECStoreManager类用于管理应用的E类数据库和C类数据库。提供配置数据库信息，配置迁移函数的信息，根据密钥状态为应用提供相应的数据库句柄，提供E类数据关库接口和在数据迁移完成后销毁C类数据库的接口。

```ts
import distributedKVStore from '@ohos.data.distributedKVStore';
import { Mover } from './Mover'
import { BusinessError } from '@kit.BasicServicesKit';
import { StoreInfo, Store } from './Store'

let storeOption = new Store();

export class ECStoreManager {
  Config(cInfo: StoreInfo, other: StoreInfo): void {
    this.cInfo = cInfo;
    this.eInfo = other;
  }

  ConfigDataMover(mover: Mover): void {
    this.mover = mover;
  }

  async GetCurrentStore(screanStatus: number): Promise<distributedKVStore.SingleKVStore> {
    console.info(`GetCurrentStore start screanStatus: ${screanStatus}`);
    if (screanStatus) {
      this.eStore = await storeOption.GetECStore(this.eInfo);
      //解锁状态 获取e类库
      if (this.needMove) {
        if (this.eStore != undefined && this.cStore != undefined) {
          console.info(`ljy need Moving`);
          await this.mover.Move(this.eStore, this.cStore);
        }
        this.deleteCStore();
        console.info(`Data migration is complete. Destroy cstore`);
        this.needMove = false;
      }
      return this.eStore;
    } else {
      //加锁状态 获取c类库
      this.needMove = true;
      this.cStore = await storeOption.GetECStore(this.cInfo);
      return this.cStore;
    }
  }

  CloseEStore(): void {
    try {
      let kvManager = distributedKVStore.createKVManager(this.eInfo.kvManagerConfig);
      console.info("Succeeded in creating KVManager");
      if (kvManager != undefined) {
        kvManager.closeKVStore(this.eInfo.kvManagerConfig.bundleName, this.eInfo.storeId);
        this.eStore = null;
        console.info(`close EStore success`)
      }
    } catch (e) {
      let error = e as BusinessError;
      console.error(`Failed to create KVManager.code is ${error.code},message is ${error.message}`);
    }
  }

  deleteCStore() {
    try {
      let kvManager = distributedKVStore.createKVManager(this.cInfo.kvManagerConfig);
      console.info("Succeeded in creating KVManager");
      if (kvManager != undefined) {
        kvManager.deleteKVStore(this.cInfo.kvManagerConfig.bundleName, this.cInfo.storeId);
        this.cStore = null;
        console.info("delete cStore success");
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

在EntryAbility类的中模拟在应用启动时，注册对COMMON_EVENT_SCREEN_LOCK_FILE_ACCESS_STATE_CHANGED公共事件的监听，并配置相应的数据库信息，密钥状态信息等。

```
import { AbilityConstant, contextConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { distributedKVStore } from '@kit.ArkData';
import { ECStoreManager } from './ECStoreManager'
import { StoreInfo } from './store'
import { Mover } from './Mover'
import { secretKeyObserve } from './secretKeyObserve'
import CommonEventManager from '@ohos.commonEventManager';
import Base from '@ohos.base';


export let storeManager = new ECStoreManager();

export let screenObserver = new secretKeyObserve();

let mover = new Mover();

let subscriber: CommonEventManager.CommonEventSubscriber;

export function createCB(err: Base.BusinessError, commonEventSubscriber: CommonEventManager.CommonEventSubscriber) {
  if (!err) {
    console.info('ljy createSubscriber');
    subscriber = commonEventSubscriber;
    try {
      CommonEventManager.subscribe(subscriber, (err: Base.BusinessError, data: CommonEventManager.CommonEventData) => {
        if (err) {
          console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
        } else {
          console.info(`ljy SubscribeCB ${data.code}`);
          screenObserver.UpdatalockStatus(data.code);
        }
      });
    } catch (error) {
      const err: Base.BusinessError = error as Base.BusinessError;
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
        securityLevel: distributedKVStore.SecurityLevel.S1
      },
      "isEstore": false,
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
        securityLevel: distributedKVStore.SecurityLevel.S1
      },
      "isEstore": true,
    }
    console.info(`ljy store area : estore:${eContext.area}, cstore${cContext.area}`)
    //监听COMMON_EVENT_SCREEN_LOCK_FILE_ACCESS_STATE_CHANGED事件 code == 1解锁状态，code==0加锁状态
    console.info(`ljy store area : estore:${eContext.area},cstore${cContext.area}`)
    try {
      CommonEventManager.createSubscriber({
        events: ['COMMON_EVENT_SCREEN_LOCK_FILE_ACCESS_STATE_CHANGED']
      }, createCB);
      console.info(`ljy success subscribe`);
    } catch (error) {
      const err: Base.BusinessError = error as Base.BusinessError;
      console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
    }
    storeManager.Config(cInfo, eInfo);
    storeManager.ConfigDataMover(mover);
    screenObserver.Initialize(storeManager);
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
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
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}

```
### index按键事件

提供案件 模拟应用操作数据库，如插入数据，删除数据，更新数据和获取数据数量的操作等。

```
import { storeManager, screenObserver } from "../entryability/EntryAbility"
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
            screenObserver.OnLock();
            lockStatus = 0;
          } else {
            screenObserver.OnUnLock();
            lockStatus = 1;
          }
          lockStatus ? this.message = "解锁" : this.message = "加锁";
        }).margin("5");
        Button('store type').onClick(async (event: ClickEvent) => {
          screenObserver.GetCurrentStatus() ? this.message = "estroe" : this.message = "cstore";
        }).margin("5");

        Button("put").onClick(async (event: ClickEvent) => {
          let store: distributedKVStore.SingleKVStore = await storeManager.GetCurrentStore(screenObserver.GetCurrentStatus());
          storeOption.Putdata(store);
        }).margin(5)

        Button("Get").onClick(async (event: ClickEvent) => {
          let store: distributedKVStore.SingleKVStore = await storeManager.GetCurrentStore(screenObserver.GetCurrentStatus());
          storeOption.GetDataNum(store);
        }).margin(5)

        Button("delete").onClick(async (event: ClickEvent) => {
          let store: distributedKVStore.SingleKVStore = await storeManager.GetCurrentStore(screenObserver.GetCurrentStatus());
          storeOption.deleteOnedata(store);
        }).margin(5)

        Button("updata").onClick(async (event: ClickEvent) => {
          let store: distributedKVStore.SingleKVStore = await storeManager.GetCurrentStore(screenObserver.GetCurrentStatus());
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

