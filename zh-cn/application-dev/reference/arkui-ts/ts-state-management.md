# 应用级变量的状态管理

状态管理模块提供了应用程序的数据存储能力、持久化数据管理能力、Ability数据存储能力和应用程序需要的环境状态，其中Ability数据存储从API version9开始支持。

> **说明：**
>
> 本模块首批接口从API version 7开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## AppStorage

### Link

Link(propName: string): any

与localStorage双向数据绑定。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述        |
| -------- | ------ | ---- | ----------- |
| propName | string | 是    | 要双向绑定的属性名称。 |

**返回值：**

| 类型    | 描述                                       |
| ----- | ---------------------------------------- |
| @Link | 在具有给定键的数据，则返回到此属性的双向数据绑定，该双向绑定意味着变量或者组件对数据的更改将同步到AppStorage，通过AppStorage对数据的修改将同步到变量或者组件。 |

```ts
let simple = AppStorage.Link('simpleProp')
```

### SetAndLink

SetAndLink\<T>(propName: string, defaultValue: T): SubscribedAbstractProperty\<T>

与Link接口类似，如果当前的key保存于AppStorage，则返回该key对应的value。如果该key未被创建，则创建一个对应default值的Link返回。

**参数：**

| 参数名          | 类型     | 必填   | 参数描述        |
| ------------ | ------ | ---- | ----------- |
| propName     | string | 是    | 要进行创建的key值。 |
| defaultValue | T      | 是    | 要进行设置的默认值。  |

**返回值：**

| 类型    | 描述                                       |
| ----- | ---------------------------------------- |
| @Link | 与Link接口类似，如果当前的key保存于AppStorage，返回该key值对应的value值。如果该key值未被创建，则创建一个对应的defaultValue的Link返回。 |

```ts
let simple = AppStorage.SetAndLink('simpleProp', 121)
```

### Prop

Prop(propName: string): any

单向属性绑定的一种。更新组件的状态。。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述        |
| -------- | ------ | ---- | ----------- |
| propName | string | 是    | 要进行创建的key值。 |

**返回值：**

| 类型    | 描述                                       |
| ----- | ---------------------------------------- |
| @Prop | 如果存在具有给定键的属性，则返回此属性的单向数据绑定。该单向绑定意味着只能通过AppStorage将属性的更改同步到变量或者组件。该方法返回的变量为不可变变量，适用于可变和不可变的状态属性，如果具有此键的属性不存在则返回undefined。 |

```ts
let simple = AppStorage.Prop('simpleProp')
```

### SetAndProp

SetAndProp\<S>(propName: string, defaultValue: S): SubscribedAbstractProperty\<S>;

与Prop接口类似，如果当前的key保存于AppStorage，则返回该key对应的value。如果该key未被创建，则创建一个对应default值的Prop返回。

**参数：**

| 参数名          | 类型     | 必填   | 参数描述            |
| ------------ | ------ | ---- | --------------- |
| propName     | string | 是    | 要保存的的键值对中的key值。 |
| defaultValue | S      | 是    | 创建的默认值。         |

**返回值：**

| 类型    | 描述                                       |
| ----- | ---------------------------------------- |
| @Prop | 如果当前的key保存与AppStorage，返回该key值对应的value值。如果该key值未被创建，则创建一个对应的defaultValue的Prop返回。 |

```ts
let simple = AppStorage.SetAndProp('simpleProp', 121)
```

### Has

Has(propName: string): boolean

判断对应键值的属性是否存在。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述    |
| -------- | ------ | ---- | ------- |
| propName | string | 是    | 属性的属性值。 |

**返回值：**

| 类型      | 描述            |
| ------- | ------------- |
| boolean | 返回属性的属性值是否存在。 |

```ts
let simple = AppStorage.Has('simpleProp')
```

### Get

Get\<T>(propName: string): T | undefined

通过此接口获取对应key值的value。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述        |
| -------- | ------ | ---- | ----------- |
| propName | string | 是    | 要获取对应的key值。 |

**返回值：**

| 类型                | 描述            |
| ----------------- | ------------- |
| boolean或undefined | 返回属性的属性值是否存在。 |

```ts
let simple = AppStorage.Get('simpleProp')
```

### Set

Set\<T>(propName: string, newValue: T): boolean

对已保存的key值，替换其value值。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述        |
| -------- | ------ | ---- | ----------- |
| propName | string | 是    | 要设置的key值。   |
| newValue | T      | 是    | 要设置的value值。 |

**返回值：**

| 类型      | 描述                                  |
| ------- | ----------------------------------- |
| boolean | 如果存在key值，设置value值并返回true，否则返回false。 |

```ts
let simple = AppStorage.Set('simpleProp', 121);
```

### SetOrCreate

SetOrCreate\<T>(propName: string, newValue: T): void

创建或更新setOrCreate内部的值。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述            |
| -------- | ------ | ---- | --------------- |
| propName | string | 是    | 要更新或者创建的key值。   |
| newValue | T      | 是    | 要更新或者创建的value值。 |

**返回值：**

| 类型      | 描述                                       |
| ------- | ---------------------------------------- |
| boolean | 如果已存在与给定键名字相同的属性，更新其值且返回true。如果不存在具有给定名称的属性，在AppStorage中创建具有给定默认值的新属性，默认值必须是T类型。不允许undefined 或 null 返回true。 |

```ts
let simple = AppStorage.SetOrCreate('simpleProp', 121)
```

### Delete

Delete(propName: string): boolean

删除key指定的键值对。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述         |
| -------- | ------ | ---- | ------------ |
| propName | string | 是    | 要删除的属性的key值。 |

**返回值：**

| 类型      | 描述                                       |
| ------- | ---------------------------------------- |
| boolean | 删除key指定的键值对，如果存在且删除成功返回true，不存在或删除失败返回false。 |

```ts
let simple = AppStorage.Delete('simpleProp')
```

### keys

keys(): IterableIterator\<string>

查找所有键。

**返回值：**

| 类型             | 描述             |
| -------------- | -------------- |
| array\<string> | 返回包含所有键的字符串数组。 |

```ts
let simple = AppStorage.Keys()
```

### staticClear

staticClear(): boolean

删除所有的属性。

从API version 9开始废弃，推荐使用[Clear](#clear)。

**返回值：**

| 类型      | 描述                                |
| ------- | --------------------------------- |
| boolean | 删除所有的属性，如果当前有状态变量依旧引用此属性，返回false。 |

```ts
let simple = AppStorage.staticClear()
```

### Clear<sup>9+</sup>

Clear(): boolean

删除所有的属性。

**返回值：**

| 类型      | 描述                                |
| ------- | --------------------------------- |
| boolean | 删除所有的属性，如果当前有状态变量依旧引用此属性，返回false。 |

```typescript
let simple = AppStorage.Clear()
```

### IsMutable

IsMutable(propName: string): boolean

查询属性及状态。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述         |
| -------- | ------ | :--- | ------------ |
| propName | string | 是    | 要查询的属性的key值。 |

**返回值：**

| 类型      | 描述                 |
| ------- | ------------------ |
| boolean | 返回此属性是否存在并且是否可以改变。 |

```ts
let simple = AppStorage.IsMutable('simpleProp')
```

### Size

Size(): number

存在的键值对的个数。

**返回值：**

| 类型     | 描述        |
| ------ | --------- |
| number | 返回键值对的数量。 |

```ts
let simple = AppStorage.Size()
```

## LocalStorage<sup>9+</sup>

### constructor<sup>9+</sup>

constructor(initializingProperties?: Object)

创建一个新的LocalStorage对象，并进行初始化。

**参数：**

| 参数名                    | 类型     | 必填   | 参数描述                                     |
| ---------------------- | ------ | ---- | ---------------------------------------- |
| initializingProperties | Object | 否    | object.keys(obj)返回的所有对象属性及其值都将添加到LocalStorage。 |

```ts
this.storage = new LocalStorage()
```

### GetShared<sup>9+</sup>

static GetShared(): LocalStorage

获取当前的共享的LocalStorage对象。

此接口仅可在Stage模型下使用。

**返回值：**

| 类型                            | 描述                |
| ----------------------------- | ----------------- |
| [LocalStorage](#localstorage) | 返回LocalStorage对象。 |

```ts
let storage = LocalStorage.GetShared()
```

### has<sup>9+</sup>

has(propName: string): boolean

判断属性值是否存在。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述    |
| -------- | ------ | ---- | ------- |
| propName | string | 是    | 属性的属性值。 |

**返回值：**

| 类型      | 描述            |
| ------- | ------------- |
| boolean | 返回属性的属性值是否存在。 |

```ts
this.storage = new LocalStorage()
this.storage.has('storageSimpleProp')
```

### get<sup>9+</sup>

get\<T>(propName: string): T

获取对应key值的value。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述        |
| -------- | ------ | ---- | ----------- |
| propName | string | 是    | 要获取对应的key值。 |

**返回值：**

| 类型             | 描述                                       |
| -------------- | ---------------------------------------- |
| T \| undefined | 当keyvalue存在时，返回keyvalue值。不存在返回undefined。 |

```ts
this.storage = new LocalStorage()
let simpleValue = this.storage.get('storageSimpleProp')
```

### set<sup>9+</sup>

set\<T>(propName: string, newValue: T): boolean

存储对象值。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述        |
| -------- | ------ | ---- | ----------- |
| propName | string | 是    | 要设置的key值。   |
| newValue | T      | 是    | 要设置的value值。 |

**返回值：**

| 类型      | 描述                                  |
| ------- | ----------------------------------- |
| boolean | 如果存在key值，设置value值并返回true，否则返回false。 |

```ts
this.storage = new LocalStorage()
this.storage.set('storageSimpleProp', 121)
```

### setOrCreate<sup>9+</sup>

setOrCreate\<T>(propName: string, newValue: T): boolean

创建或更新setOrCreate内部的值。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述           |
| -------- | ------ | :--- | -------------- |
| propName | string | 是    | 要更新或创建的key值。   |
| newValue | T      | 是    | 要更新或创建的value值。 |

**返回值：**

| 类型      | 描述                                       |
| ------- | ---------------------------------------- |
| boolean | 如果已存在与给定键名字相同的属性，更新其值且返回true。如果不存在具有给定名称的属性，在LocalStorage中创建具有给定默认值的新属性，默认值必须是T类型，不允许undefined 或 null 。 |

```ts
this.storage = new LocalStorage()
this.storage.setOrCreate('storageSimpleProp', 121)
```

### link<sup>9+</sup>

link\<T>(propName: string): T

与localStorage双向数据绑定。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述        |
| -------- | ------ | ---- | ----------- |
| propName | string | 是    | 要双向绑定的属性名称。 |

**返回值：**

| 类型   | 描述                                       |
| ---- | ---------------------------------------- |
| T    | 如果存在具有给定键的属性，返回到此属性的双向绑定，该双向绑定意味着变量或者组件对数据的更改将同步到LocalStorage，然后通过LocalStorage实例同步到任何变量或组件。如果不存在给定键的属性，返回undefined。 |

```ts
this.storage = new LocalStorage()
let localStorage = this.storage.link('storageSimpleProp')
```

### setAndLink<sup>9+</sup>

setAndLink\<T>(propName: string, defaultValue: T): T

与link接口类似，双向数据绑定localStorage。

**参数：**

| 参数名          | 类型     | 必填   | 参数描述        |
| ------------ | ------ | ---- | ----------- |
| propName     | string | 是    | 要进行创建的key值。 |
| defaultValue | T      | 是    | 要进行设置的默认值。  |

**返回值：**

| 类型    | 描述                                       |
| ----- | ---------------------------------------- |
| @Link | 与Link接口类似，如果当前的key保存于LocalStorage，返回该key值对应的value值。如果该key值未被创建，则创建一个对应的defaultValue的Link返回。 |

```ts
this.storage = new LocalStorage()
let localStorage = this.storage.setAndLink('storageSimpleProp', 121)
```

### prop<sup>9+</sup>

prop\<T>(propName: string): T

单向属性绑定的一种。更新组件的状态。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述          |
| -------- | ------ | ---- | ------------- |
| propName | string | 是    | 要单向数据绑定的key值。 |

**返回值：**

| 类型    | 描述                                       |
| ----- | ---------------------------------------- |
| @Prop | 如果存在具有给定键的属性，返回此属性的单向数据绑定。该单向绑定意味着只能通过LocalStorage将属性的更改同步到变量或组件。该方法返回的变量为不可变变量，适用于可变和不可变的状态变量。如果此键的属性不存在则返回undefined。 |

```ts
this.storage = new LocalStorage()
let localStorage = this.storage.prop('storageSimpleProp')
```

### setAndProp<sup>9+</sup>

setAndProp\<T>(propName: string, defaultValue: T): T

与Prop接口类似，存在localStorage的单向数据绑定prop值。

**参数：**

| 参数名          | 类型     | 必填   | 参数描述           |
| ------------ | ------ | ---- | -------------- |
| propName     | string | 是    | 要保存的键值对中的key值。 |
| defaultValue | T      | 是    | 创建的默认值。        |

**返回值：**

| 类型    | 描述                                       |
| ----- | ---------------------------------------- |
| @Prop | 如果当前的key保存与LocalStorage，返回该key值对应的value值。如果该key值未被创建，则创建一个对应的defaultValue的Prop返回。 |

```ts
this.storage = new LocalStorage()
let localStorage = this.storage.setAndProp('storageSimpleProp', 121)
```

### delete<sup>9+</sup>

delete(propName: string): boolean

删除key指定的键值对。

**参数：**

| 参数名      | 类型     | 必填   | 参数描述         |
| -------- | ------ | :--- | ------------ |
| propName | string | 是    | 要删除的属性的key值。 |

**返回值：**

| 类型      | 描述                                       |
| ------- | ---------------------------------------- |
| boolean | 删除key指定的键值对。存在且删除成功，返回true。不存在、删除失败或有状态变量依旧引用propName，返回false。 |

```ts
this.storage = new LocalStorage()
this.storage.delete('storageSimpleProp')
```

### keys<sup>9+</sup>

keys(): IterableIterator\<string>

查找所有键。

**返回值：**

| 类型             | 描述                  |
| -------------- | ------------------- |
| array\<string> | 返回包含所有键不可序列化的字符串数组。 |

```ts
this.storage = new LocalStorage()
let simple = this.storage.keys()
```

### size<sup>9+</sup>

size(): number

存在的键值对的个数。

**返回值：**

| 类型     | 描述        |
| ------ | --------- |
| number | 返回键值对的数量。 |

```ts
this.storage = new LocalStorage()
let simple = this.storage.size()
```

### Clear<sup>9+</sup>

clear(): boolean

删除所有的属性。

**返回值：**

| 类型      | 描述                                |
| ------- | --------------------------------- |
| boolean | 删除所有的属性，如果当前有状态变量依旧引用此属性，返回false。 |

```ts
this.storage = new LocalStorage()
let simple = this.storage.clear()
```

## PersistentStorage

### constructor

constructor(appStorage: AppStorage, storage: Storage)

创建一个新的persistentstorage对象。

**参数：**

| 参数名        | 类型         | 必填   | 参数描述             |
| ---------- | ---------- | ---- | ---------------- |
| appStorage | AppStorage | 是    | 保存所有属性及属性值的单例对象。 |
| storage    | Storage    | 是    | Storage实例对象。     |

```ts
this.persistentstorage = new PersistentStorage(AppStorage,Storage)
```

### PersistProp

PersistProp(key:string,defaultValue:T): void

关联命名的属性再AppStorage变为持久化数据。

**参数：**

| 参数名          | 类型     | 必填   | 参数描述           |
| ------------ | ------ | ---- | -------------- |
| key          | string | 是    | 要关联的属性的key值。   |
| defaultValue | T      | 是    | 要关联的属性的value值。 |

```ts
PersistentStorage.PersistProp('highScore', '0')
```

### DeleteProp

DeleteProp(key: string): void

取消双向数据绑定，该属性值将从持久存储中删除。

**参数：**

| 参数名  | 类型     | 必填   | 参数描述         |
| ---- | ------ | ---- | ------------ |
| key  | string | 是    | 要取消的属性的key值。 |

```ts
PersistentStorage.DeleteProp('highScore')
```

### PersistProps

PersistProps(properties: {key: string, defaultValue: any}[]): void;

关联多个命名的属性绑定。

**参数：**

| 参数名  | 类型                                 | 必填   | 参数描述      |
| ---- | ---------------------------------- | ---- | --------- |
| key  | {key: string, defaultValue: any}[] | 是    | 要关联的属性数组。 |

```ts
PersistentStorage.PersistProps([{key: 'highScore', defaultValue: '0'},{key: 'wightScore',defaultValue: '1'}])
```

### Keys

Keys(): Array\<string>

返回所有持久化属性的标记。

**返回值：**

| 类型             | 描述            |
| -------------- | ------------- |
| Array\<string> | 返回所有持久化属性的标记。 |

```ts
let simple = PersistentStorage.Keys()
```

> **说明：**
>
> - PersistProp接口使用时，需要保证输入对应的key应当在AppStorage存在。
>
> - DeleteProp接口使用时，只能对本次启动已经link过的数据生效。

## Environment

### constructor

创建一个environment对象。

```ts
let simple = new Environment()
```

### EnvProp

EnvProp\<S>(key: string, value: S): boolean

关联此系统项到AppStorage中，建议在app启动时使用此接口。如果该属性在AppStorage已存在，返回false。请勿使用AppStorage中的变量，在调用此方法关联环境变量。

**参数：**

| 参数名   | 类型     | 必填   | 参数描述       | 参数描述                      |
| ----- | ------ | ---- | ---------- | ------------------------- |
| key   | string | 是    | 要关联的key值   | 要关联的key值，支持的范围详见内置环境变量说明。 |
| value | S      | 是    | 要关联的value值 | 要关联的value值。               |

**返回值：**

| 类型      | 描述                     |
| ------- | ---------------------- |
| boolean | 返回该属性在AppStorage中是否存在。 |

**内置环境变量说明：**

| key                  | 类型              | 说明                                       |
| -------------------- | --------------- | ---------------------------------------- |
| accessibilityEnabled | string          | 无障碍屏幕朗读是否启用。                             |
| colorMode            | ColorMode       | 深浅色模式，可选值为：<br>- ColorMode.LIGHT：浅色模式；<br>- ColorMode.DARK：深色模式。 |
| fontScale            | number          | 字体大小比例。                                  |
| fontWeightScale      | number          | 字重比例。                                    |
| layoutDirection      | LayoutDirection | 布局方向类型，可选值为：<br>- LayoutDirection.LTR：从左到右；<br>- LayoutDirection.RTL：从右到左。 |
| languageCode         | string          | 当前系统语言，小写字母，例如zh。                        |

```ts
Environment.EnvProp('accessibilityEnabled', 'default')
```

### EnvProps

EnvProps(props: {key: string, defaultValue: any}[]): void

关联此系统项数组到AppStorage中

**参数：**

| 参数名  | 类型                                 | 必填   | 参数描述      | 参数描述      |
| ---- | ---------------------------------- | ---- | --------- | --------- |
| key  | {key: string, defaultValue: any}[] | 是    | 要关联的属性数组。 | 要关联的属性数组。 |

```ts
Environment.EnvProps([{key: 'accessibilityEnabled', defaultValue: 'default'},{key: 'accessibilityUnEnabled', defaultValue: 'undefault'}])
```

### Keys

Keys(): Array\<string>

返回关联的系统项。

**返回值：**

| 类型             | 描述          |
| -------------- | ----------- |
| Array\<string> | 返回关联的系统项数组。 |

```ts
let simple = Environment.Keys()
```

