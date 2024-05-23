# 支持E类数据加密


## 场景介绍

为满足数据库安全特性，锁屏下将数据库升级为E类数据库，销毁密钥，E类数据库可读不可写，防止用户数据泄露。但在锁屏过程中，应用会继续写入数据，为解决该问题，本文档提供锁屏下将数据存入C类数据库，解锁后同步到E类数据库的场景设计。

## 键值型数据库E类加密

### Mover

```
import distributedKVStore from '@ohos.data.distributedKVStore';

export  class Mover {
  Move(cStore: distributedKVStore.SingleKVStore, eStore: distributedKVStore.SingleKVStore): void {

  }
}
```

### StoreMetaInfo

```ts
import distributedKVStore from '@ohos.data.distributedKVStore';

export class StoreMetaInfo {
  bundleName: string;
  storeId: string;
  option:  distributedKVStore.Options;
}
```

### ScreanObserve

```
export class ScreanObserve {
  OnLock(): void {

  }

  OnUnLock(): void {

  }

  GetCurrentStatus(): number {
    return this.ScreanStatus ? 1 : 0;
  }

  Initialize(): void {
    this.ScreanStatus = false;
  }

  private ScreanStatus: boolean = false;
}
```

### ECStoreManager

设计一个ECStoreManager类管理应用的E类数据库（eStore)和C类数据库（cStore)

```ts
import { Mover } from './Mover';
import { StoreMetaInfo } from './StoreMetaInfo';
import distributedKVStore from '@ohos.data.distributedKVStore';
import { BusinessError } from '@ohos.base';
import UIAbility from '@ohos.app.ability.UIAbility';

let kvManager: distributedKVStore.KVManager | undefined = undefined;

export class ECStoreMananger extends UIAbility {
  GetCurrentStore(screanStatus: number): distributedKVStore.SingleKVStore {
    //0锁屏 1解锁
    if (screanStatus == 0) {
      this.needMove = true;
      //创建cstore
      this.cstore = this.getStore(this.cInfo);
      return this.cstore;
    } else {
      this.estore = this.getStore(this.eInfo);
      if (this.needMove) {
        this.mover.Move(this.estore, this.cstore);
      }
      //关cstore
      kvManager.closeKVStore(this.cInfo.bundleName, this.cInfo.storeId);
      return this.estore;
    }
  }

  CloseEStore(): void {
    kvManager.closeKVStore(this.eInfo.bundleName, this.eInfo.storeId);
  }

  Config(cInfo: StoreMetaInfo, other: StoreMetaInfo): void {
    //创建estore
    this.eInfo = other;
    //保存cstore信息
    this.cInfo = cInfo;
  }

  ConfigDataMover(mover: Mover): void {
    this.mover = mover;
  }

  private getStore(storeInfo: StoreMetaInfo): distributedKVStore.SingleKVStore {
    const kvManagerConfig: distributedKVStore.KVManagerConfig = {
      context: this.context,
      bundleName: 'com.example.datamanagertest'
    };
    try {
      // 创建KVManager实例
      kvManager = distributedKVStore.createKVManager(kvManagerConfig);
      console.info('Succeeded in creating KVManager.');
      // 继续创建获取数据库
    } catch (e) {
      let error = e as BusinessError;
      console.error(`Failed to create KVManager. Code:${error.code},message:${error.message}`);
    }
    if (kvManager !== undefined) {
      let kvStore: distributedKVStore.SingleKVStore | undefined = undefined;
      try {
        kvManager.getKVStore<distributedKVStore.SingleKVStore>(storeInfo.storeId, storeInfo.option, (err, store: distributedKVStore.SingleKVStore) => {
          if (err) {
            console.error(`Failed to get KVStore: Code:${err.code},message:${err.message}`);
            return;
          }
          console.info('Succeeded in getting KVStore.');
          kvStore = store;
          // 请确保获取到键值数据库实例后，再进行相关数据操作
        });
      } catch (e) {
        let error = e as BusinessError;
        console.error(`An unexpected error occurred. Code:${error.code},message:${error.message}`);
      }
      if (kvStore !== undefined) {
        kvStore = kvStore as distributedKVStore.SingleKVStore;
        return kvStore;
      }
    }
  }

  estore: distributedKVStore.SingleKVStore | null = null;
  cstore: distributedKVStore.SingleKVStore | null = null;
  needMove: boolean = true;
  mover: Mover | null = null;

  cInfo: StoreMetaInfo = null;
  eInfo: StoreMetaInfo = null;
}
```

### EntryAbility

```
import UIAbility from '@ohos.app.ability.UIAbility';
import hilog from '@ohos.hilog';
import window from '@ohos.window';
import { ECStoreMananger } from "../ability/ECStoreManager"
import { StoreMetaInfo } from "../ability/StoreMetaInfo"
import { Mover } from "../ability/Mover"
import { ScreanObserve } from '../ability/ScreanObserve';
//import { Store } from "../ability/Store"
import distributedKVStore from '@ohos.data.distributedKVStore';


let cInfo: StoreMetaInfo = {
  "bundleName": "test_bundlename",
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
}
let other: StoreMetaInfo = {
  "bundleName": "test_bundlename",
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
}

let storeMananger = new ECStoreMananger();
let screanObserve = new ScreanObserve();

export default class EntryAbility extends UIAbility {
  onCreate() {
    storeMananger.Config(cInfo, other);
    let Mover: Mover | undefined = undefined;
    storeMananger.ConfigDataMover(Mover);
    screanObserve.Initialize();
  }

  onDestroy() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    let screenStatus = screanObserve.GetCurrentStatus();
    let store: distributedKVStore.SingleKVStore = storeMananger.GetCurrentStore(screenStatus);
  }

  onWindowStageDestroy() {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground() {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground() {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}

```




## 关系型数据库E类加密

