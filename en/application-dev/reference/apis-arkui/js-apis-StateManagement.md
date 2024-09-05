# @ohos.arkui.StateManagement (State Management)

The state management module provides data storage, persistent data management, UIAbility data storage, and environment state and tools required by applications.

>**NOTE**
>
>The initial APIs of this module are supported since API version 12.


The meanings of T and S in this topic are as follows:


| Type  | Description                                    |
| ---- | -------------------------------------- |
| T    | Class, number, boolean, string, and arras of these types.|
| S    | number, boolean, string.                |


## AppStorageV2

For details about how to use AppStorageV2, see [AppStorageV2: Storing Application-wide UI State](../../quick-start/arkts-new-appstoragev2.md).

### Modules to Import

```ts
import { AppStorageV2 } from '@kit.ArkUI';
```

### connect<sup>12+</sup>

static connect\<T extends object\>( <br>
      type: TypeConstructorWithArgs\<T\>, <br>
      keyOrDefaultCreator?: string | StorageDefaultCreator\<T\>, <br>
      defaultCreator?: StorageDefaultCreator\<T\> <br>
): T | undefined;

Stores key-value pair data in the application memory. If the given key already exists in [AppStorageV2](../../quick-start/arkts-new-appstoragev2.md), it returns the corresponding value; otherwise, it constructs a default value using the constructor for obtaining the default value and returns it.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description              |
| -------- | ------ | ---- | ---------------------- |
| type | TypeConstructorWithArgs\<T\> | Yes  | Type. If no key is specified, the name of the type is used as the key.|
| keyOrDefaultCreater | string \| StorageDefaultCreator\<T\> | No  | Key, or the constructor for obtaining the default value.|
| defaultCreator | StorageDefaultCreator\<T\> | No  | Constructor for obtaining the default value.|

>**NOTE**
>
>1. If no key is specified, the second parameter is used as the default constructor; otherwise, the third parameter is used as the default constructor.
>
>2. If the data has been stored in AppStorageV2, you can obtain the stored data without using the default constructor. Otherwise, you must specify the default constructor. If no constructor is specified, an application exception will occur.
>
>3. Ensure type compatibility. Connecting data of different types with the same key will cause an application exception.
>
>4. You are advised to use meaningful values for the key, with a length not exceeding 255 characters. The behavior of using illegal characters or empty characters is undefined.

**Return value**

| Type                                  | Description                                                        |
| -------------------------------------- | ------------------------------------------------------------ |
| T | Returns data if the creation or data acquisition from AppStorageV2 is successful; returns **undefined** otherwise.|

**Example**

```ts
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
class SampleClass {
  @Trace p: number = 0;
}

// Store the key-value pair with the key SampleClass and the value as a new instance of SampleClass() in memory, and assign it to variable as1.
const as1: SampleClass | undefined = AppStorageV2.connect(SampleClass, () => new SampleClass());

// Store the key-value pair with the key key_as2 and the value as a new instance of SampleClass() in memory, and assign it to variable as2.
const as2: SampleClass = AppStorageV2.connect(SampleClass, 'key_as2', () => new SampleClass())!;

// As the key SampleClass already exists in AppStorageV2, the value associated with the key is returned to variable as3.
const as3: SampleClass = AppStorageV2.connect(SampleClass) as SampleClass;
```

### remove<sup>12+</sup>

static remove\<T\>(keyOrType: string | TypeConstructorWithArgs\<T\>): void;

Removes the specified key-value pair from [AppStorageV2](../../quick-start/arkts-new-appstoragev2.md). If the specified key does not exist in AppStorageV2, the removal will fail.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description              |
| -------- | ------ | ---- | ---------------------- |
| keyOrType | string \| TypeConstructorWithArgs\<T\> | Yes  | Key to be removed. If a type is specified, the key to be deleted is the name of that type.|

>**NOTE**
>
>Attempting to remove a key that does not exist in AppStorageV2 will result in a warning.

**Return value**

None.

**Example**

```ts
// Assuming that there is a key named key_as2 in AppStorageV2, the following will remove the corresponding key-value pair from AppStorageV2.
AppStorageV2.remove('key_as2');

// Assuming that there is a key named SampleClass in AppStorageV2, the following will remove the corresponding key-value pair from AppStorageV2.
AppStorageV2.remove(SampleClass);

// Assuming there is no key named key_as1 in AppStorageV2, the following will result in a warning.
AppStorageV2.remove('key_as1');
```

### keys<sup>12+</sup>

static keys(): Array\<string\>;

Obtains all keys in [AppStorageV2](../../quick-start/arkts-new-appstoragev2.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

None.

**Return value**

| Type                                  | Description                                                        |
| -------------------------------------- | ------------------------------------------------------------ |
| Array\<string\> | All keys stored in AppStorageV2.|

>**NOTE**
>
>The order of the keys in the Array is not sequential and does not correspond to the order in which the keys were inserted into AppStorageV2.

**Example**

```ts
// Assuming there are two keys (key_as1 and key_as2) in AppStorageV2, the following will return an array containing these keys and assign it to keys.
const keys: Array<string> = AppStorageV2.keys();
```



## PersistenceV2

For details about how to use PersistenceV2, see [PersistenceV2: Persisting Application State](../../quick-start/arkts-new-persistencev2.md).

### Modules to Import

```ts
import { PersistenceV2 } from '@kit.ArkUI';
```

### connect<sup>12+</sup>

static connect\<T extends object\>( <br>
      type: TypeConstructorWithArgs\<T\>, <br>
      keyOrDefaultCreator?: string | StorageDefaultCreator\<T\>, <br>
      defaultCreator?: StorageDefaultCreator\<T\> <br>
): T | undefined;

Stores the key-value pair data on the application disk (for persistence). If the given key already exists in [PersistenceV2](../../quick-start/arkts-new-persistencev2.md), it returns the corresponding value; otherwise, it constructs a default value using the constructor for obtaining the default value and returns it. If what is connected is an [\@ObservedV2](../../quick-start/arkts-new-observedV2-and-trace.md) object, changes to the object's [\@Trace](../../quick-start/arkts-new-observedV2-and-trace.md) decorated property will trigger automatic persistence of the entire associated object; changes to non-@Trace-decorated properties will not. If necessary, you can manually persist data by calling the **PersistenceV2.save** API.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description              |
| -------- | ------ | ---- | ---------------------- |
| type | TypeConstructorWithArgs\<T\> | Yes  | Type. If no key is specified, the name of the type is used as the key.|
| keyOrDefaultCreater | string \| StorageDefaultCreator\<T\> | No  | Key, or the constructor for obtaining the default value.|
| defaultCreator | StorageDefaultCreator\<T\> | No  | Constructor for obtaining the default value.|

>**NOTE**
>
>1. If no key is specified, the second parameter is used as the default constructor; if the second parameter is invalid, the third parameter is used as the default constructor
>
>2. If the data has been stored in PersistenceV2, you can obtain the stored data without using the default constructor. Otherwise, you must specify the default constructor. If no constructor is specified, an application exception occurs.
>
>3. Ensure type compatibility. Connecting data of different types with the same key will cause an application exception.
>
>4. You are advised to use meaningful values for keys. The values can contain letters, digits, and underscores (_) and a maximum of 255 characters. If use invalid characters or null characters, undefined behavior will occur.

**Return value**

| Type                                  | Description                                                        |
| -------------------------------------- | ------------------------------------------------------------ |
| T | Returns data if the creation or data acquisition from AppStorageV2 is successful; returns **undefined** otherwise.|

**Example**

```ts
import { PersistenceV2, Type } from '@kit.ArkUI';

@ObservedV2
class SampleClass {
  @Trace p1: number = 0;
  p2: number = 1;
}

@ObservedV2
class FatherSampleClass {
  @Trace f: SampleClass = new SampleClass();
}

// Persist the key-value pair with the key SampleClass and the value as an instance of SampleClass(), and assign it to variable as1.
const as1: FatherSampleClass | undefined = PersistenceV2.connect(FatherSampleClass, () => new FatherSampleClass());

// Persist the key-value pair with the key key_as2 and the value as an instance of SampleClass(), and assign it to variable as2.
const as2: FatherSampleClass = PersistenceV2.connect(FatherSampleClass, 'key_as2', () => new FatherSampleClass())!;

// As the key SampleClass already exists in PersistenceV2, the value associated with the key is returned to variable as3.
const as3: FatherSampleClass = PersistenceV2.connect(FatherSampleClass) as FatherSampleClass;

@Entry
@Component
struct SampleComp {
  v: FatherSampleClass = as2;

  build() {
    Column() {
      Text(`${this.v.f.p1}`)
        .onClick(() => {
          // Automatic persistence
          this.v.f.p1++;
        })
      Text(`${this.v.f.p2}`)
        .onClick(() => {
          // Automatic persistence is not available. You need to call the PersistenceV2.save API for manual persistence.
          this.v.f.p2++;
        })
    }
  }
}
```

### remove<sup>12+</sup>

static remove\<T\>(keyOrType: string | TypeConstructorWithArgs\<T\>): void;

Removes the specified key-value pair from [PersistenceV2](../../quick-start/arkts-new-persistencev2.md). If the specified key does not exist in PersistenceV2, the removal will fail.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description              |
| -------- | ------ | ---- | ---------------------- |
| keyOrType | string \| TypeConstructorWithArgs\<T\> | Yes  | Key to be removed. If a type is specified, the key to be deleted is the name of that type.|

>**NOTE**
>
>Attempting to remove a key that does not exist in PersistenceV2 will result in a warning.

**Return value**

None.

**Example**

```ts
// Assuming that there is a key named key_as2 in PersistenceV2, the following will remove the corresponding key-value pair from PersistenceV2.
PersistenceV2.remove('key_as2');

// Assuming that there is a key named SampleClass in PersistenceV2, the following will remove the corresponding key-value pair from PersistenceV2.
PersistenceV2.remove(SampleClass);

// Assuming there is no key named key_as1 in PersistenceV2, the following will result in a warning.
PersistenceV2.remove('key_as1');
```

### keys<sup>12+</sup>

static keys(): Array\<string\>;

Obtains all keys in [PersistenceV2](../../quick-start/arkts-new-persistencev2.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

None.

**Return value**

| Type                                  | Description                                                        |
| -------------------------------------- | ------------------------------------------------------------ |
| Array\<string\> | All keys in PersistenceV2.|

>**NOTE**
>
>The order of the keys in the Array is not sequential and does not correspond to the order in which the keys were inserted into PersistenceV2.

**Example**

```ts
// Assuming there are two keys (key_as1 and key_as2) in PersistenceV2, the following will return an array containing these keys and assign it to keys.
const keys: Array<string> = PersistenceV2.keys();
```

### save<sup>12+</sup>

static save\<T\>(keyOrType: string | TypeConstructorWithArgs\<T\>): void;

Persists the specified key-value pair data once.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description              |
| -------- | ------ | ---- | ---------------------- |
| keyOrType | string \| TypeConstructorWithArgs\<T\> | Yes  | Key to be persisted. If a type is specified, the key for persistence is the name of the type.|

>**NOTE**
>
>Since changes to non-[\@Trace](../../quick-start/arkts-new-observedV2-and-trace.md) decorated data do not trigger automatic persistence by [PersistenceV2](../../quick-start/arkts-new-persistencev2.md), this API can be called if necessary to persist the data for the corresponding key.
>
>It is useless to manually persist the keys that are not in the **connect** state in the memory.

**Return value**

None.

**Example**

```ts
// Assuming there is a key named key_as2 in PersistenceV2, the following will persist the data for this key-value pair.
PersistenceV2.save('key_as2');

// Assuming there is a key named SampleClass in PersistenceV2, the following will persist the data for this key-value pair.
PersistenceV2.remove(SampleClass);

// Assuming there is no key named key_as1 in PersistenceV2, this operation is meaningless.
PersistenceV2.remove('key_as1');
```

## UIUtils

Provides APIs for handling data transformations related to state management.

### Modules to Import

```ts
import { UIUtils } from '@kit.ArkUI';
```

### getTarget<sup>12+</sup>

static getTarget\<T extends object\>(source: T): T;

Obtains the original object from a proxy object wrapped by the state management framework. For details, see [getTarget API: Obtaining Original Objects](../../quick-start/arkts-new-getTarget.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description    |
| ------ | ---- | ---- | ------------ |
| source | T    | Yes  | Source object.|

**Return value**

| Type| Description                                            |
| ---- | ------------------------------------------------ |
| T    | Original object of the source after the proxy added by the state management framework is removed.|

**Example**

```ts
import { UIUtils } from '@kit.ArkUI';
class NonObservedClass {
  name: string = "Tom";
}
let nonObservedClass: NonObservedClass = new NonObservedClass();
@Entry
@Component
struct Index {
  @State someClass: NonObservedClass = nonObservedClass;
  build() {
    Column() {
      Text(`this.someClass === nonObservedClass: ${this.someClass === nonObservedClass}`) // false
      Text(`UIUtils.getTarget(this.someClass) === nonObservedClass: ${UIUtils.getTarget(this.someClass) ===
        nonObservedClass}`) // true
    }
  }
}
```
### makeObserved<sup>12+</sup>

static makeObserved\<T extends object\>(source: T): T;

Converts ordinary unobservable data into observable data. For details, see [makeObserved API: Changing Unobservable Data to Observable Data](../../quick-start/arkts-new-makeObserved.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description    |
| ------ | ---- | ---- | ------------ |
| source | T    | Yes  | Source object. It supports classes not decorated by @Observed or @ObserveV2, objects returned by **JSON.parse**, and classes decorated by @Sendable.<br>Array, Map, Set, and Date types are supported.<br>**collection.Array**, **collection.Set**, and **collection.Map** are supported.<br>For details, see [makeObserved API: Changing Unobservable Data to Observable Data](../../quick-start/arkts-new-makeObserved.md).|

**Return value**

| Type| Description                                            |
| ---- | ------------------------------------------------ |
| T    | Observable data.|

**Example**

```ts
import { UIUtils } from '@kit.ArkUI';
class NonObservedClass {
  name: string = 'Tom';
}

@Entry
@ComponentV2
struct Index {
  observedClass: NonObservedClass = UIUtils.makeObserved(new NonObservedClass());
  nonObservedClass: NonObservedClass = new NonObservedClass();
  build() {
    Column() {
      Text(`observedClass: ${this.observedClass.name}`)
        .onClick(() => {
          this.observedClass.name = 'Jane'; // This will trigger a UI update.
        })
      Text(`observedClass: ${this.nonObservedClass.name}`)
        .onClick(() => {
          this.nonObservedClass.name = 'Jane'; // This will not trigger a UI update.
        })
    }
  }
}
```
