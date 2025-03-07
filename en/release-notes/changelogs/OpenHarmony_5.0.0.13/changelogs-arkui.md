# ArkUI Subsystem Changelog

## cl.arkui.1 Verification Against Undefined Keys for Decorators

**Access Level**

Public

**Reason for Change**

The **key** value should be verified for all decorators to comply with TypeScript syntax rules.

The following decorators are involved:

@LocalStorageLink, @LocalStorageProp, @StorageProp, @StorageLink, @Provide, @Consume, @Watch

**Change Impact**

If the **key** value of any of the aforementioned decorators is not defined, a compilation error is reported.

This change is a non-compatible change.

**Start API Level**

@LocalStorageLink: API version 9

@LocalStorageProp: API version 9

@StorageProp: API version 7

@StorageLink: API version 7

@Provide: API version 7

@Consume: API version 7

@Watch: API version 7



**Change Since**

OpenHarmony SDK 5.0.0.13

Example:

```
@Entry
@Component
struct ComA {
  // ERROR: Cannot find name 'aaa'.
  @StorageProp(aaa) storageProp: string = 'storageProp';
  // ERROR: Cannot find name 'aaa'.
  @StorageLink(aaa) storageLink: string = 'storageLink';
  // ERROR: Cannot find name 'aaa'.
  @LocalStorageLink(aaa) localStorageLink: string = 'localStorageLink';
  // ERROR: Cannot find name 'aaa'.
  @LocalStorageProp(aaa) localStorageProp: string = 'localStorageProp';
  // ERROR: Cannot find name 'aaa'.
  @Provide(aaa) provide: string = 'provide';
  // ERROR: Cannot find name 'aaa'.
  @Consume(aaa) consume: number;
  // ERROR: Cannot find name 'aaa'.
  @State @Watch(aaa) watch: number = 0;

  build() {
  }
}

```

**Adaptation Guide**

 Make sure the **key** value for the following decorators is defined: @LocalStorageLink, @LocalStorageProp, @StorageProp, @StorageLink, @Provide, @Consume, and @Watch.

```
// test.ts
export let oneKey = 'string';
```



```

// index.ets
import { oneKey } from './test';
@Entry
@Component
struct ComA {
  @StorageProp(oneKey) storageProp: string = 'storageProp';
  @StorageLink(oneKey) storageLink: string = 'storageLink';
  @LocalStorageLink(oneKey) localStorageLink: string = 'localStorageLink';
  @LocalStorageProp(oneKey) localStorageProp: string = 'localStorageProp';
  @Provide(oneKey) provide: string = 'provide';
  @Consume(oneKey) consume: number;

  build() {
  }
}
```




## cl.arkui.2 Addition of undefined and null Support for AppStorage, LocalStorage, and PersistentStorage

**Access Level**

Public

**Change Impact**

The AppStorage, LocalStorage, and PersistentStorage APIs now accept **null** and **undefined** as input parameters. The @StorageLink, @StorageProp, @LocalStorageLink, and @LocalStorageProp decorators now support **null** and **undefined** types.

Take @StorageLink as an example. If an AppStorage API uses **null** or **undefined** as the initial or target value, then: In the semantics before change, calling the API reports a warning and does not take effect. In the semantics after change, **null** or **undefined** is saved as the initial or target value in AppStorage. This change causes the original application code to crash in the following scenario:

Before change:

```ts
class PropA {
  num: number = 100;
}

AppStorage.setOrCreate("PropA", null);
AppStorage.has("PropA");// Because null and undefined are not supported, false is returned.

@Entry
@Component
struct TestPage {
  @StorageLink('PropA') propA: PropA = new PropA();

  build() {
    Column() {
      Text(this.propA.num.toString()) // propA is locally initialized to 100.
    }
  }
}
```

After change:

```ts
class PropA {
  num: number = 100;
}

AppStorage.setOrCreate("PropA", null);
AppStorage.has("PropA");// Because null and undefined are supported, true is returned.

@Entry
@Component
struct TestPage {
  @StorageLink('PropA') propA: PropA = new PropA();

  build() {
    Column() {
      Text(this.propA.num.toString()) // propA is initialized with the value null in AppStorage. As a result, JsCrash is triggered during invoking.
    }
  }
}
```

**Key API/Component Changes**

AppStorage: **set**, **setOrCreate**, **setAndLink**, **setAndProp**

LocalStorage: **set**, **setOrCreate**, **setAndLink**, **setAndProp**

PersistentStorage: **persistProp**


**Start API Level**

This change takes effect since API version 12.

AppStorage

**set**: API version 10

**setOrCreate**: API version 10

**setAndLink**: API version 10

**setAndProp**: API version 10

LocalStorage

**set**: API version 9

**setOrCreate**: API version 9

**setAndLink**: API version 9

**setAndProp**: API version 9

PersistentStorage

**persistProp**: API version 10

**Change Since**

OpenHarmony SDK 5.0.0.13

**Adaptation Guide**

1. Do not use **null** or **undefined** to initialize variables. Use meaningful values instead.

2. Changing a value to **null** or **undefined** will trigger UI re-render.

3. Add a null check to the invoking position.

```ts
class PropA {
  num: number = 100;
}

AppStorage.setOrCreate("PropA", null);
AppStorage.has("PropA"); // Because null and undefined are supported, true is returned.

@Entry
@Component
struct TestPage {
  @StorageLink('PropA') propA: PropA | null | undefined = new PropA();

  build() {
    Column() {
      Text(this.propA?.num.toString())// Check whether the value is null to prevent crashes caused by null and undefined during invoking.
        .fontSize(20)
      Button("Set propA to null")
        .margin(10)
        .onClick(() => {
          this.propA = null;
        })
      Button("Set propA to undefined")
        .margin(10)
        .onClick(() => {
          this.propA = undefined;
        })
      Button("Assign new PropA")
        .margin(10)
        .onClick(() => {
          this.propA = new PropA();
        })
    }
  }
}
```
