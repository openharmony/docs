# PersistenceV2: Persisting Application State

To enhance the state management framework's capability of persistently storing UIs, you can use PersistenceV2 to persist data. During application development, you may want selected attributes to persist even when the application is closed. In this case, you'll need PersistenceV2.

PersistenceV2 is an optional singleton object within an application. Its purpose is to persist UI-related data so that their values are the same upon application re-start as they were when the application was closed.

>**NOTE**
>
>PersistenceV2 is supported since API version 12.
>
>State management V2 is still under development, and some features may be incomplete or not always work as expected.


## Overview

PersistenceV2 is a singleton to be created when the application UI is started. Its purpose is to provide central storage for application UI state attributes. Each attribute is accessed using a unique key, which is a string. Unlike AppStorageV2, PersistenceV2 also persistently stores the latest data on device disks. In this way, the selected result can still be saved even when the application is closed.

For a [\@ObservedV2](arkts-new-observedV2-and-trace.md) object associated with PersistenceV2, the change of the [\@Trace](arkts-new-observedV2-and-trace.md) attribute of the object triggers **automatic persistence of the entire associated object**. If necessary, you can call PersistenceV2 APIs to manually perform persistence.

UI components synchronize application state attributes with PersistenceV2. PersistenceV2 can be accessed during implementation of application service logic as well.

PersistenceV2 supports state sharing among multiple UIAbility instances in the [main thread](../application-models/thread-model-stage.md) of an application.


## How to Use

### connect: Creating or Obtaining Stored Data

```JavaScript
static connect<T extends object>(
    type: TypeConstructorWithArgs<T>,
    keyOrDefaultCreator?: string | StorageDefaultCreator<T>,
    defaultCreator?: StorageDefaultCreator<T> 
): T | undefined;
```

| connect      | Description                                                 |
| ------------ | ----------------------------------------------------- |
| Parameter        | **type**: specified type. If no **key** is specified, the name of the **type** is used as the **key**.<br>**keyOrDefaultCreater**: specified key or default constructor.<br>**defaultCreator**: default constructor.                                         |
| Return value      | After creating or obtaining data, value is returned. Otherwise, **undefined** is returned.|

>**NOTE**
>
>1. The third parameter is used when no **key** is specified or the second parameter is invalid. Otherwise, the second parameter is used.
>
>2. If the data has been stored in PersistenceV2, you can obtain the stored data without using the default constructor. Otherwise, you must specify the default constructor. If no constructor is specified, the application exception occurs.
>
>3. Ensure that the data types match the key. If different types of data are connected to the same key, the application exception occurs.
>
>4. You are advised to use meaningful values for keys. The values can contain letters, digits, and underscores (_) and a maximum of 255 characters. If use invalid characters or null characters, undefined behavior may occur.
>
>5. When matching the key with the [\@Observed](arkts-observed-and-objectlink.md) object, specify the key or customize the **name** attribute.

### remove: Deleting the Stored Data of a Specified Key

```JavaScript
static remove<T>(keyOrType: string | TypeConstructorWithArgs<T>): void;
```

| remove       | Description                                                 |
| ------------ | ----------------------------------------------------- |
| Parameter        | **keyOrType**: key to be deleted. If the key is of the **type**, the key to be deleted is the name of the **type**.                                         |
| Return value      | None.|

>**NOTE**
>
>If a key that does not exist in PersistenceV2 is deleted, a warning is reported.

### keys: Returning All Keys Stored in PersistenceV2

```JavaScript
static keys(): Array<string>;
```

| keys         | Description                                                 |
| ------------ | ----------------------------------------------------- |
| Parameter        | None.                                        |
| Return value      | All keys in PersistenceV2.|


### save: Persisting Stored Data Manually

```JavaScript
static save<T>(keyOrType: string | TypeConstructorWithArgs<T>): void;
```

| save         | Description                                                 |
| ------------ | ----------------------------------------------------- |
| Parameter        | **keyOrType**: key that needs to be manually persist. If the key is of the **Type**, the key is the name of the **Type**.                                         |
| Return value      | None.|

>**NOTE**
>
>Changes to the non-[\@Trace](arkts-new-observedV2-and-trace.md) data do not trigger PersistenceV2. If necessary, call this API to persist the data of the corresponding key.
>
>It is useless to manually persist the keys that are not in the **connect** state in the memory.


### **notifyOnError**: Callback for Responding to a Serialization or Deserialization Failure

```JavaScript
static notifyOnError(callback: PersistenceErrorCallback | undefined): void;
```

| notifyOnError| Description                                                 |
| ------------ | ----------------------------------------------------- |
| Parameter        | **callback**: When a serialization or deserialization fails, the callback is executed. Pass in **undefined** can cancel this callback.|
| Return value      | None.|

>**NOTE**
>
>When data is stored to disks, the data needs to be serialized. If a key fails to be serialized, the error is unpredictable. As a result, this API can be called to capture exceptions.


## Constraints

1. This singleton must be used together with the UI thread only. Other threads, for example, @Sendable decorator is not supported.

2. Types such as collections.Set and collections.Map are not supported.

3. Non-buildin types, such as native PixelMap, NativePointer, and ArrayList types, are not supported.

4. A single key supports a maximum of 8 KB data. If the data is too large, the persistence fails.

5. The persistent data must be a class object. Containers, such as Array, Set, and Map, or objects of the builtin types, such as Date and Number, are not supported.

6. Objects that used for loop reference are not supported.

7. Automatic persistency is triggered only when [\@Trace](arkts-new-observedV2-and-trace.md) data is changed. The change of state variables in V1, [\@Observed](arkts-observed-and-objectlink.md) objects, and common data does not trigger persistency.

8. Do not store a large amount of persistent data. Otherwise, frame freezing may occur.

## Use Scenarios

### Storing Data Between Two Pages

Page 1
```ts
import { router, PersistenceV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

// Callback used to receive serialization failure.
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@Entry
@ComponentV2
struct Page1 {
  // Create a KV pair whose key is Sample in PersistenceV2 (if the key exists, the data in PersistenceV2 is returned) and associate it with prop.
  // Add @Local to decorate the prop attribute that needs to change the connected object. (Changing the connected object is not recommended.)
  @Local prop: Sample = PersistenceV2.connect(Sample, () => new Sample())!;

  build() {
    Column() {
      Button('Go to page2')
        .onClick(() => {
          router.pushUrl({
            url: 'pages/Page2'
          })
        })

      Button('Page1 connect the key Sample')
        .onClick(() => {
          // Create a KV pair whose key is Sample in PersistenceV2 (if the key exists, the data in PersistenceV2 is returned) and associate it with prop.
          // Changing the connected object for the prop attribute is not recommended.
          this.prop = PersistenceV2.connect(Sample, 'Sample', () => new Sample())!;
        })

      Button('Page1 remove the key Sample')
        .onClick(() => {
          // After being deleted from PersistenceV2, prop will no longer be associated with the value whose key is Sample.
          PersistenceV2.remove(Sample);
        })

      Button('Page1 save the key Sample')
        .onClick(() => {
          // If the sample is in the connect state, persist the KV pair of the Sample.
          PersistenceV2.save(Sample);
        })

      Text(`Page1 add 1 to prop.p1: ${this.prop.f.p1}`)
        .fontSize(30)
        .onClick(() => {
          this.prop.f.p1++;
        })

      Text(`Page1 add 1 to prop.p2: ${this.prop.f.p2}`)
        .fontSize(30)
        .onClick(() => {
          // The page is not re-rendered, but the value of p2 is changed.
          this.prop.f.p2++;
        })

      // Obtain all keys in the current PersistenceV2.
      Text(`all keys in PersistenceV2: ${PersistenceV2.keys()}`)
        .fontSize(30)
    }
  }
}
```

Page 2
```ts
import { PersistenceV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

@Entry
@ComponentV2
struct Page2 {
  // Create a KV pair whose key is Sample in PersistenceV2 (if the key exists, the data in PersistenceV2 is returned) and associate it with prop.
  // Add @Local to decorate the prop attribute that needs to change the connected object. (Changing the connected object is not recommended.)
  @Local prop: Sample = PersistenceV2.connect(Sample, () => new Sample())!;

  build() {
    Column() {
      Button('Page2 connect the key Sample1')
        .onClick(() => {
          // Create a KV pair whose key is Sample1 in PersistenceV2 (if the key exists, the data in PersistenceV2 is returned) and associate it with prop.
          // Changing the connected object for the prop attribute is not recommended.
          this.prop = PersistenceV2.connect(Sample, 'Sample1', () => new Sample())!;
        })

      Text(`Page2 add 1 to prop.p1: ${this.prop.f.p1}`)
        .fontSize(30)
        .onClick(() => {
          this.prop.f.p1++;
        })

      Text(`Page2 add 1 to prop.p2: ${this.prop.f.p2}`)
        .fontSize(30)
        .onClick(() => {
          // The page is not re-rendered, but the value of p2 is changed, which is performed after re-initialization.
          this.prop.f.p2++;
        })

      // Obtain all keys in the current PersistenceV2.
      Text(`all keys in PersistenceV2: ${PersistenceV2.keys()}`)
        .fontSize(30)
    }
  }
}
```

Data page
```ts
import { Type } from '@kit.ArkUI';

// Data center
@ObservedV2
class SampleChild {
  @Trace p1: number = 0;
  p2: number = 10;
}

@ObservedV2
export class Sample {
  // Complex objects need to be decorated by @Type to ensure successful serialization.
  @Type(SampleChild)
  @Trace f: SampleChild = new SampleChild();
}
```
