# 应用级变量的状态管理

状态管理模块提供了应用程序的数据存储能力、持久化数据管理能力、UIAbility数据存储能力和应用程序需要的环境状态。

>**说明：**
>
>本模块首批接口从API version 7开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

本文中T和S的含义如下：

| 类型   | 说明                                     |
| ---- | -------------------------------------- |
| T    | Class，number，boolean，string和这些类型的数组形式。 |
| S    | number，boolean，string。                 |

## AppStorage

AppStorage具体UI使用说明，详见[AppStorage(应用全局的UI状态存储)](../../../ui/state-management/arkts-appstorage.md)

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### ref<sup>12+</sup>

static ref\<T\>(propName: string): AbstractProperty\<T\>&nbsp;|&nbsp;undefined

如果给定的propName在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中存在，则获得AppStorage中propName对应数据的引用。否则，返回undefined。

与[link](#link10)的功能基本一致，但不需要手动释放返回的[AbstractProperty](#abstractproperty)类型的变量。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| propName | string | 是   | AppStorage中的属性名。 |

**返回值：**

| 类型                                   | 说明                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| [AbstractProperty&lt;T&gt;](#abstractproperty) \| undefined | AppStorage中propName对应属性的引用，如果AppStorage中不存在对应的propName，则返回undefined。 |

**示例：**

```ts
AppStorage.setOrCreate('PropA', 47);
let refToPropA1: AbstractProperty<number> | undefined = AppStorage.ref('PropA');
let refToPropA2: AbstractProperty<number> | undefined = AppStorage.ref('PropA'); // refToPropA2.get() == 47
refToPropA1?.set(48); // 同步修改AppStorage: refToPropA1.get() == refToPropA2.get() == 48
```

### setAndRef<sup>12+</sup>

static setAndRef&lt;T&gt;(propName: string, defaultValue: T): AbstractProperty&lt;T&gt;

与[ref](#ref12)接口类似，如果给定的propName在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中存在，则获得AppStorage中propName对应数据的引用。如果不存在，则使用defaultValue在AppStorage中创建和初始化propName对应的属性，并返回其引用。defaultValue须为T类型，可以为null或undefined。

与[setAndLink](#setandlink10)的功能基本一致，但不需要手动释放返回的[AbstractProperty](#abstractproperty)类型的变量。

> **说明：**<br/>
> 从API version 12开始，AppStorage支持[Map](../../../ui/state-management/arkts-appstorage.md#装饰map类型变量)、[Set](../../../ui/state-management/arkts-appstorage.md#装饰set类型变量)、[Date类型](../../../ui/state-management/arkts-appstorage.md#装饰date类型变量)，支持null、undefined以及[联合类型](../../../ui/state-management/arkts-appstorage.md#appstorage支持联合类型)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | 是   | AppStorage中的属性名。                                       |
| defaultValue | T      | 是   | 当propName在AppStorage中不存在时，使用defaultValue在AppStorage中初始化对应的propName，defaultValue可以为null或undefined。 |

**返回值：**

| 类型                      | 说明                                                         |
| ------------------------- | ------------------------------------------------------------ |
| [AbstractProperty&lt;T&gt;](#abstractproperty) | AbstractProperty&lt;T&gt;的实例，为AppStorage中propName对应属性的引用。 |

**示例：**

```ts
AppStorage.setOrCreate('PropA', 47);
let ref1: AbstractProperty<number> = AppStorage.setAndRef('PropB', 49); // 用默认值49创建PropB
let ref2: AbstractProperty<number> = AppStorage.setAndRef('PropA', 50); // PropA已存在，值为47
```

### link<sup>10+</sup>

static link&lt;T&gt;(propName: string): SubscribedAbstractProperty&lt;T&gt;

与[AppStorage](../../../ui/state-management/arkts-appstorage.md)中对应的propName建立双向数据绑定。如果给定的propName在AppStorage中存在，返回AppStorage中propName对应属性的双向绑定数据。

双向绑定数据的修改会同步回AppStorage中，AppStorage会将变化同步到所有绑定该propName的数据和自定义组件中。

如果AppStorage中不存在propName，则返回undefined。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型                                | 说明                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | 返回双向绑定的数据，如果AppStorage中不存在对应的propName，则返回undefined。 |

**示例：**
```ts
AppStorage.setOrCreate('PropA', 47);
let linkToPropA1: SubscribedAbstractProperty<number> = AppStorage.link('PropA');
let linkToPropA2: SubscribedAbstractProperty<number> = AppStorage.link('PropA'); // linkToPropA2.get() == 47
linkToPropA1.set(48); // 双向同步: linkToPropA1.get() == linkToPropA2.get() == 48
```

### setAndLink<sup>10+</sup>

static setAndLink&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

与[link](#link10)接口类似，如果给定的propName在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中存在，则返回该propName对应的属性的双向绑定数据。如果不存在，则使用defaultValue在AppStorage中创建和初始化propName对应的属性，返回其双向绑定数据。defaultValue必须为T类型，从API version 12开始defaultValue可以为null或undefined。

> **说明：**<br/>
> 从API version 12开始，AppStorage支持[Map](../../../ui/state-management/arkts-appstorage.md#装饰map类型变量)、[Set](../../../ui/state-management/arkts-appstorage.md#装饰set类型变量)、[Date类型](../../../ui/state-management/arkts-appstorage.md#装饰date类型变量)，支持null、undefined以及[联合类型](../../../ui/state-management/arkts-appstorage.md#appstorage支持联合类型)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | 是   | AppStorage中的属性名。                                       |
| defaultValue | T      | 是   | 当propName在AppStorage中不存在时，使用defaultValue在AppStorage中初始化对应的propName，从API version 12开始，defaultValue可以为null或undefined。 |

**返回值：**

| 类型                                  | 说明                                       |
| ----------------------------------- | ---------------------------------------- |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | SubscribedAbstractProperty&lt;T&gt;的实例，为AppStorage中propName对应属性的双向绑定的数据。 |

**示例：**
```ts
AppStorage.setOrCreate('PropA', 47);
let link1: SubscribedAbstractProperty<number> = AppStorage.setAndLink('PropB', 49); // 用默认值49创建PropB
let link2: SubscribedAbstractProperty<number> = AppStorage.setAndLink('PropA', 50); // PropA已存在，值为47
```

### prop<sup>10+</sup>

static prop&lt;T&gt;(propName: string): SubscribedAbstractProperty&lt;T&gt;

与[AppStorage](../../../ui/state-management/arkts-appstorage.md)中对应的propName建立单向属性绑定。如果给定的propName在AppStorage中存在，则返回与AppStorage中propName对应属性的单向绑定数据。如果AppStorage中不存在propName，则返回undefined。单向绑定数据的修改不会被同步回AppStorage中。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型                                | 说明                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | 返回单向绑定的数据，如果AppStorage中不存在对应的propName，则返回undefined。 |

**示例：**

```ts
AppStorage.setOrCreate('PropA', 47);
let prop1: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');
let prop2: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');
prop1.set(1); // 单向同步：prop1.get()的值为1，prop2.get()的值为47
```

### setAndProp<sup>10+</sup>

static setAndProp&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

与[prop](#prop10)接口类似。如果给定的propName在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中存在，则返回该propName对应的属性的单向绑定数据。如果不存在，则使用defaultValue在AppStorage中创建和初始化propName对应的属性，返回其单向绑定数据。defaultValue必须为T类型，从API version 12开始defaultValue可以为null或undefined。

> **说明：**<br/>
> 从API version 12开始，AppStorage支持[Map](../../../ui/state-management/arkts-appstorage.md#装饰map类型变量)、[Set](../../../ui/state-management/arkts-appstorage.md#装饰set类型变量)、[Date类型](../../../ui/state-management/arkts-appstorage.md#装饰date类型变量)，支持null、undefined以及[联合类型](../../../ui/state-management/arkts-appstorage.md#appstorage支持联合类型)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | 是   | AppStorage中的属性名。                                       |
| defaultValue | T      | 是   | 当propName在AppStorage中不存在时，使用defaultValue在AppStorage中初始化对应的propName，从API version 12开始，defaultValue可以为null或undefined。 |

**返回值：**

| 类型                                  | 说明                                      |
| ----------------------------------- | --------------------------------------- |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | SubscribedAbstractProperty&lt;T&gt;的实例。 |

**示例：**
```ts
AppStorage.setOrCreate('PropA', 47);
let prop: SubscribedAbstractProperty<number> = AppStorage.setAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```

### has<sup>10+</sup>

static has(propName: string): boolean

判断propName对应的属性是否在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中存在。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 如果propName对应的属性在AppStorage中存在，则返回true。不存在则返回false。 |

**示例：**
```ts
AppStorage.has('simpleProp');
```

### get<sup>10+</sup>

static get&lt;T&gt;(propName: string): T | undefined

获取propName在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中对应的属性值。如果不存在则返回undefined。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型                     | 说明                                                        |
| ------------------------ | ----------------------------------------------------------- |
| T&nbsp;\|&nbsp;undefined | AppStorage中propName对应的属性，如果不存在则返回undefined。 |

**示例：**
```ts
AppStorage.setOrCreate('PropA', 47);
let value: number = AppStorage.get('PropA') as number; // 47
```

### set<sup>10+</sup>

static set&lt;T&gt;(propName: string, newValue: T): boolean

在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中设置propName对应属性的值。如果newValue的值和propName对应属性的值相同，即不需要做赋值操作，状态变量不会通知UI刷新propName对应属性的值，从API version 12开始，newValue可以为null或undefined。

> **说明：**<br/>
> 从API version 12开始，AppStorage支持[Map](../../../ui/state-management/arkts-appstorage.md#装饰map类型变量)、[Set](../../../ui/state-management/arkts-appstorage.md#装饰set类型变量)、[Date类型](../../../ui/state-management/arkts-appstorage.md#装饰date类型变量)，支持null、undefined以及[联合类型](../../../ui/state-management/arkts-appstorage.md#appstorage支持联合类型)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| propName | string | 是    | AppStorage中的属性名。       |
| newValue | T      | 是    | 属性值，从API version 12开始可以为null或undefined。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果AppStorage中不存在propName对应的属性，或设值失败，则返回false。设置成功则返回true。 |

**示例：**
```ts
AppStorage.setOrCreate('PropA', 48);
let res: boolean = AppStorage.set('PropA', 47) // true
let res1: boolean = AppStorage.set('PropB', 47) // false
```

### setOrCreate<sup>10+</sup>

static setOrCreate&lt;T&gt;(propName: string, newValue: T): void

如果propName已经在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中存在，并且newValue和propName对应属性的值不同，则设置propName对应属性的值为newValue，否则状态变量不会通知UI刷新propName对应属性的值。
如果propName不存在，则创建propName属性，值为newValue。setOrCreate只可以创建单个AppStorage的键值对，如果想创建多个AppStorage键值对，可以多次调用此方法。从API version 12开始，newValue可以为null或undefined。

> **说明：**<br/>
> 从API version 12开始，AppStorage支持[Map](../../../ui/state-management/arkts-appstorage.md#装饰map类型变量)、[Set](../../../ui/state-management/arkts-appstorage.md#装饰set类型变量)、[Date类型](../../../ui/state-management/arkts-appstorage.md#装饰date类型变量)，支持null、undefined以及[联合类型](../../../ui/state-management/arkts-appstorage.md#appstorage支持联合类型)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| propName | string | 是    | AppStorage中的属性名。       |
| newValue | T      | 是    | 属性值，从API version 12开始可以为null或undefined。 |

**示例：**
```ts
AppStorage.setOrCreate('simpleProp', 121);
```

### delete<sup>10+</sup>

static delete(propName: string): boolean

在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中删除propName对应的属性。

在AppStorage中删除该属性的前提是必须保证该属性没有订阅者。如果有订阅者，则返回false。如果没有订阅者，则删除成功并返回true。

属性的订阅者为：

1. [\@StorageLink](../../../ui/state-management/arkts-appstorage.md#storagelink)、[\@StorageProp](../../../ui/state-management/arkts-appstorage.md#storageprop)装饰的变量。

2. 通过[link](#link10)、[prop](#prop10)、[setAndLink](#setandlink10)、[setAndProp](#setandprop10)接口返回的[SubscribedAbstractProperty](#subscribedabstractproperty)的实例。

如果想要删除这些订阅者，可以通过以下方式：

1. 删除\@StorageLink、\@StorageProp所在的自定义组件。删除自定义组件请参考[自定义组件的删除](../../../ui/state-management/arkts-page-custom-components-lifecycle.md#自定义组件的删除)。

2. 对link、prop、setAndLink、setAndProp接口返回的SubscribedAbstractProperty的实例调用[aboutToBeDeleted](#abouttobedeleted10)接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 如果AppStorage中有对应的属性，且该属性已经没有订阅者，则删除成功，返回true。如果属性不存在，或者该属性还存在订阅者，则返回false。 |

**示例：**
```ts
AppStorage.setOrCreate('PropA', 47);
AppStorage.link<number>('PropA');
let res: boolean = AppStorage.delete('PropA'); // false，PropA 还存在订阅者

AppStorage.setOrCreate('PropB', 48);
let res1: boolean = AppStorage.delete('PropB'); // true，PropB 已从AppStorage成功删除
```

### keys<sup>10+</sup>

static keys(): IterableIterator&lt;string&gt;

返回[AppStorage](../../../ui/state-management/arkts-appstorage.md)中所有的属性名。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                             | 说明                 |
| ------------------------------ | ------------------ |
| IterableIterator&lt;string&gt; | AppStorage中所有的属性名。 |

**示例：**
```ts
AppStorage.setOrCreate('PropB', 48);
let keys: IterableIterator<string> = AppStorage.keys();
```

### clear<sup>10+</sup>

static clear(): boolean

删除[AppStorage](../../../ui/state-management/arkts-appstorage.md)中所有属性。删除所有属性的前提是，AppStorage已经没有任何订阅者。如果有订阅者，clear将不会生效并返回false。如果没有订阅者，则删除成功，并返回true。

订阅者的含义参考[delete](#delete10)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果AppStorage中的属性已经没有订阅者则删除成功，返回true；如果当前仍有订阅者，返回false。|

**示例：**
```ts
AppStorage.setOrCreate('PropA', 47);
let res: boolean = AppStorage.clear(); // true，已经没有订阅者
```

### size<sup>10+</sup>

static size(): number

返回[AppStorage](../../../ui/state-management/arkts-appstorage.md)中的属性数量。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| number | 返回AppStorage中属性的数量。 |

**示例：**
```ts
AppStorage.setOrCreate('PropB', 48);
let res: number = AppStorage.size(); // 1
```

### Link<sup>(deprecated)</sup>

static Link(propName: string): any

与[AppStorage](../../../ui/state-management/arkts-appstorage.md)中对应的propName建立双向数据绑定。如果给定的propName在AppStorage中存在，返回与AppStorage中propName对应属性的双向绑定数据。

双向绑定数据的修改会同步回AppStorage中，AppStorage会将变化同步到所有绑定该propName的数据和自定义组件中。

如果AppStorage中不存在propName，则返回undefined。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[link10+](#link10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型                             | 说明                                                         |
| -------------------------------- | ------------------------------------------------------------ |
| any | 返回双向绑定的数据，如果AppStorage中不存在对应的propName，则返回undefined。 |

**示例：**
```ts
AppStorage.SetOrCreate('PropA', 47);
let linkToPropA1: SubscribedAbstractProperty<number> = AppStorage.Link('PropA');
let linkToPropA2: SubscribedAbstractProperty<number> = AppStorage.Link('PropA'); // linkToPropA2.get() == 47
linkToPropA1.set(48); // 双向同步: linkToPropA1.get() == linkToPropA2.get() == 48
```

### SetAndLink<sup>(deprecated)</sup>

static SetAndLink&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

与[Link](#linkdeprecated)接口类似，如果给定的propName在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中存在，则返回该propName对应的属性的双向绑定数据。如果不存在，则使用defaultValue在AppStorage中创建和初始化propName对应的属性，并返回其双向绑定数据。defaultValue必须为T类型，且不能为null或undefined。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[setAndLink10+](#setandlink10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | 是   | AppStorage中的属性名。                                       |
| defaultValue | T      | 是   | 当propName在AppStorage中不存在，使用defaultValue在AppStorage中初始化对应的propName，defaultValue不能为null或undefined。 |

**返回值：**

| 类型                                  | 说明                                       |
| ----------------------------------- | ---------------------------------------- |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | SubscribedAbstractProperty&lt;T&gt;的实例，和AppStorage中propName对应属性的双向绑定的数据。 |

**示例：**
```ts
AppStorage.SetOrCreate('PropA', 47);
let link1: SubscribedAbstractProperty<number> = AppStorage.SetAndLink('PropB', 49); // 用默认值49创建PropB
let link2: SubscribedAbstractProperty<number> = AppStorage.SetAndLink('PropA', 50); // PropA已存在，值为47
```

### Prop<sup>(deprecated)</sup>

static Prop(propName: string): any

与[AppStorage](../../../ui/state-management/arkts-appstorage.md)中对应的propName建立单向属性绑定。如果给定的propName在AppStorage中存在，则返回与AppStorage中propName对应属性的单向绑定数据。如果AppStorage中不存在propName，则返回undefined。单向绑定数据的修改不会被同步回AppStorage中。

> **说明：**<br/>
> Prop仅支持简单类型。
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[prop10+](#prop10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型                             | 说明                                                         |
| -------------------------------- | ------------------------------------------------------------ |
| any | 返回单向绑定的数据，如果AppStorage中不存在对应的propName，则返回undefined。 |

**示例：**
```ts
AppStorage.SetOrCreate('PropA', 47);
let prop1: SubscribedAbstractProperty<number> = AppStorage.Prop('PropA');
let prop2: SubscribedAbstractProperty<number> = AppStorage.Prop('PropA');
prop1.set(1); // 单向同步：prop1.get()的值为1，prop2.get()的值为47
```

### SetAndProp<sup>(deprecated)</sup>

static SetAndProp&lt;S&gt;(propName: string, defaultValue: S): SubscribedAbstractProperty&lt;S&gt;

与[Prop](#propdeprecated)接口类似。如果给定的propName在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中存在，则返回该propName对应的属性的单向绑定数据。如果不存在，则使用defaultValue在AppStorage中创建和初始化propName对应的属性，返回其单向绑定数据。defaultValue必须为S类型，且不能为null或undefined。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[setAndProp10+](#setandprop10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | 是   | AppStorage中的属性名。                                       |
| defaultValue | S      | 是   | 当propName在AppStorage中不存在时，使用defaultValue在AppStorage中初始化对应的propName，defaultValue不能为null或undefined。 |

**返回值：**

| 类型                                  | 说明                                      |
| ----------------------------------- | --------------------------------------- |
| [SubscribedAbstractProperty&lt;S&gt;](#subscribedabstractproperty) | SubscribedAbstractProperty&lt;S&gt;的实例。 |

**示例：**
```ts
AppStorage.SetOrCreate('PropA', 47);
let prop: SubscribedAbstractProperty<number> = AppStorage.SetAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```

### Has<sup>(deprecated)</sup>

static Has(propName: string): boolean

判断propName对应的属性是否在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中存在。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[has10+](#has10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 如果propName对应的属性在AppStorage中存在，则返回true。不存在则返回false。 |

**示例：**
```ts
AppStorage.Has('simpleProp');
```

### Get<sup>(deprecated)</sup>

static Get&lt;T&gt;(propName: string): T | undefined

获取propName在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中对应的属性值。如果不存在则返回undefined。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[get10+](#get10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T&nbsp;\|&nbsp;undefined | AppStorage中propName对应的属性值，如果不存在则返回undefined。 |

**示例：**
```ts
AppStorage.SetOrCreate('PropA', 47);
let value: number = AppStorage.Get('PropA') as number; // 47
```

### Set<sup>(deprecated)</sup>

static Set&lt;T&gt;(propName: string, newValue: T): boolean

在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中设置propName对应属性的值。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[set10+](#set10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明                        |
| -------- | ------ | ---- | ------------------------------- |
| propName | string | 是   | AppStorage中的属性名。          |
| newValue | T      | 是   | 属性值，不能为null或undefined。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果AppStorage中不存在propName对应的属性，或者设置的newValue是undefined或者null，返回false。设置成功则返回true。 |

**示例：**
```ts
AppStorage.SetOrCreate('PropA', 48);
let res: boolean = AppStorage.Set('PropA', 47) // true
let res1: boolean = AppStorage.Set('PropB', 47) // false
```

### SetOrCreate<sup>(deprecated)</sup>

static SetOrCreate&lt;T&gt;(propName: string, newValue: T): void

如果propName已经在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中存在，则设置propName对应是属性的值为newValue。如果不存在，则创建propName属性，值为newValue。

newValue不能为null或undefined。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[setOrCreate10+](#setorcreate10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明                        |
| -------- | ------ | ---- | ------------------------------- |
| propName | string | 是   | AppStorage中的属性名。          |
| newValue | T      | 是   | 属性值，不能为null或undefined。 |

**示例：**
```ts
AppStorage.SetOrCreate('simpleProp', 121);
```

### Delete<sup>(deprecated)</sup>

static Delete(propName: string): boolean

在[AppStorage](../../../ui/state-management/arkts-appstorage.md)中删除propName对应的属性。

在AppStorage中删除该属性的前提是必须保证该属性没有订阅者。如果有订阅者，则返回false。如果没有订阅者则删除成功并返回true。

属性的订阅者为[Link](#linkdeprecated)、[Prop](#propdeprecated)等接口绑定的propName，以及[\@StorageLink('propName')](../../../ui/state-management/arkts-appstorage.md#storagelink)和[\@StorageProp('propName')](../../../ui/state-management/arkts-appstorage.md#storageprop)。如果自定义组件中使用\@StorageLink('propName')和\@StorageProp('propName')或者SubscribedAbstractProperty实例依旧对propName有同步关系，则该属性不能从AppStorage中删除。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[delete10+](#delete10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 如果AppStorage中有对应的属性，且该属性已经没有订阅者，则删除成功，返回true。如果属性不存在，或者该属性还存在订阅者，则返回false。 |

**示例：**
```ts
AppStorage.SetOrCreate('PropA', 47);
AppStorage.Link('PropA');
let res: boolean = AppStorage.Delete('PropA'); // false，PropA 还存在订阅者

AppStorage.SetOrCreate('PropB', 48);
let res1: boolean = AppStorage.Delete('PropB'); // true，PropB 已从AppStorage成功删除
```

### Keys<sup>(deprecated)</sup>

static Keys(): IterableIterator&lt;string&gt;

返回[AppStorage](../../../ui/state-management/arkts-appstorage.md)中所有的属性名。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[keys10+](#keys10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                             | 说明                 |
| ------------------------------ | ------------------ |
| IterableIterator&lt;string&gt; | AppStorage中所有的属性名。 |

**示例：**
```ts
AppStorage.SetOrCreate('PropB', 48);
let keys: IterableIterator<string> = AppStorage.Keys();
```


### staticClear<sup>(deprecated)</sup>

static staticClear(): boolean

删除所有的属性。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，推荐使用[clear10+](#clear10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型      | 说明                                |
| ------- | --------------------------------- |
| boolean | 删除所有的属性。如果删除成功，返回true；如果当前有状态变量依旧引用此属性，返回false。 |

**示例：**
```ts
let simple = AppStorage.staticClear();
```


### Clear<sup>(deprecated)</sup>

static Clear(): boolean

删除[AppStorage](../../../ui/state-management/arkts-appstorage.md)中所有属性。删除所有属性的前提是，AppStorage已经没有任何订阅者。如果有订阅者，Clear将不会生效并返回false。如果没有订阅者且删除成功则返回true。

订阅者的含义参考[delete](#delete10)。

> **说明：**<br/>
> 从API version 9 开始支持，从API version 10 开始废弃，推荐使用[clear10+](#clear10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果AppStorage中的属性已经没有订阅者则删除成功，返回true。否则返回false。 |

**示例：**
```typescript
AppStorage.SetOrCreate('PropA', 47);
let res: boolean = AppStorage.Clear(); // true，已经没有订阅者
```


### IsMutable<sup>(deprecated)</sup>

static IsMutable(propName: string): boolean

返回[AppStorage](../../../ui/state-management/arkts-appstorage.md)中propName对应的属性是否是可变的。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明             |
| -------- | ------ | ---- | ---------------- |
| propName | string | 是    | AppStorage中的属性名。 |

**返回值：**

| 类型      | 说明                               |
| ------- | -------------------------------- |
| boolean | 返回AppStorage中propName对应的属性是否是可变的。当前该返回值恒为true。 |

**示例：**
```ts
AppStorage.SetOrCreate('PropA', 47);
let res: boolean = AppStorage.IsMutable('simpleProp');
```


### Size<sup>(deprecated)</sup>

static Size(): number

返回[AppStorage](../../../ui/state-management/arkts-appstorage.md)中的属性数量。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 10 开始废弃，推荐使用[size10+](#size10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明                  |
| ------ | ------------------- |
| number | 返回AppStorage中属性的数量。 |

**示例：**
```ts
AppStorage.SetOrCreate('PropB', 48);
let res: number = AppStorage.Size(); // 1
```


## LocalStorage<sup>9+</sup>


LocalStorage具体UI使用说明，详见[LocalStorage(页面级UI状态存储)](../../../ui/state-management/arkts-localstorage.md)

**卡片能力：** 从API version 9开始，支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor<sup>9+</sup>

constructor(initializingProperties?: Object)

创建一个新的[LocalStorage](../../../ui/state-management/arkts-localstorage.md)实例。使用Object.keys(initializingProperties)返回的属性和其数值，初始化LocalStorage实例。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名                    | 类型     | 必填   | 说明                                     |
| ---------------------- | ------ | ---- | ---------------------------------------- |
| initializingProperties | Object | 否    | 用initializingProperties包含的属性和数值初始化LocalStorage。initializingProperties不能为undefined。 |

**示例：**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
```


### getShared<sup>(deprecated)</sup>

static getShared(): LocalStorage

获取当前stage共享的[LocalStorage](../../../ui/state-management/arkts-localstorage.md)实例。

> **说明：**
> 
> 从API version 10开始支持，从API version 18开始废弃，建议使用[UIContext](../arkts-apis-uicontext-uicontext.md)中的[getSharedLocalStorage](../arkts-apis-uicontext-uicontext.md#getsharedlocalstorage12)替代。
>
> 从API version 12开始，可以通过使用[UIContext](../arkts-apis-uicontext-uicontext.md)中的[getSharedLocalStorage](../arkts-apis-uicontext-uicontext.md#getsharedlocalstorage12)来明确UI的执行上下文。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型                             | 说明                |
| ------------------------------ | ----------------- |
| [LocalStorage](#localstorage9) | 返回LocalStorage实例。 |

### has<sup>9+</sup>

has(propName: string): boolean

判断propName对应的属性是否在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中存在。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明               |
| -------- | ------ | ---- | ------------------ |
| propName | string | 是    | LocalStorage中的属性名。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果propName对应的属性在LocalStorage中存在，则返回true。不存在则返回false。 |

**示例：**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
storage.has('PropA'); // true
```


### get<sup>9+</sup>

get&lt;T&gt;(propName: string): T | undefined

获取propName在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中对应的属性值。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明               |
| -------- | ------ | ---- | ------------------ |
| propName | string | 是    | LocalStorage中的属性名。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| T&nbsp;\|&nbsp;undefined | LocalStorage中propName对应的属性值，如果不存在则返回undefined。 |

**示例：**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let value: number = storage.get('PropA') as number; // 47
```


### set<sup>9+</sup>

set&lt;T&gt;(propName: string, newValue: T): boolean

在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中设置propName对应属性的值。如果newValue的值和propName对应属性的值相同，即不需要做赋值操作，状态变量不会通知UI刷新propName对应属性的值。从API version 12开始，newValue可以为null或undefined。

> **说明：** 
> 
> 从API version 12开始，LocalStorage支持[Map](../../../ui/state-management/arkts-localstorage.md#装饰map类型变量)、[Set](../../../ui/state-management/arkts-localstorage.md#装饰set类型变量)、[Date类型](../../../ui/state-management/arkts-localstorage.md#装饰date类型变量)，支持null、undefined以及[联合类型](../../../ui/state-management/arkts-localstorage.md#localstorage支持联合类型)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明                    |
| -------- | ------ | ---- | ----------------------- |
| propName | string | 是    | LocalStorage中的属性名。      |
| newValue | T      | 是    | 属性值，从API version 12开始可以为undefined或者null。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果LocalStorage中不存在propName对应的属性，返回false。设置成功返回true。 |

**示例：**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: boolean = storage.set('PropA', 47); // true
let res1: boolean = storage.set('PropB', 47); // false
```


### setOrCreate<sup>9+</sup>

setOrCreate&lt;T&gt;(propName: string, newValue: T): boolean

如果propName已经在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中存在，并且newValue和propName对应属性的值不同，则设置propName对应属性的值为newValue，否则状态变量不会通知UI刷新propName对应属性的值。
如果propName不存在，则创建propName属性，值为newValue。setOrCreate只可以创建单个LocalStorage的键值对，如果想创建多个LocalStorage键值对，可以多次调用此方法。从API version 12开始，newValue可以为null或undefined。

> **说明：** 
> 
> 从API version 12开始，LocalStorage支持[Map](../../../ui/state-management/arkts-localstorage.md#装饰map类型变量)、[Set](../../../ui/state-management/arkts-localstorage.md#装饰set类型变量)、[Date类型](../../../ui/state-management/arkts-localstorage.md#装饰date类型变量)，支持null、undefined以及[联合类型](../../../ui/state-management/arkts-localstorage.md#localstorage支持联合类型)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明                    |
| -------- | ------ | ---- | ----------------------- |
| propName | string | 是    | LocalStorage中的属性名。      |
| newValue | T      | 是    | 属性值，从API version 12开始可以为undefined或者null。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果LocalStorage中存在propName，则更新其值为newValue，返回true。<br/>如果LocalStorage中不存在propName，则创建propName，并初始化其值为newValue，返回true。 |

**示例：**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: boolean = storage.setOrCreate('PropA', 121); // true
let res1: boolean = storage.setOrCreate('PropB', 111); // true
let res2: boolean = storage.setOrCreate('PropB', null); // true (API12及之后返回true，API11及之前返回false)
```

### ref<sup>12+</sup>

public ref\<T\>(propName: string): AbstractProperty\<T\>&nbsp;|&nbsp;undefined

如果给定的propName在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中存在，则获得LocalStorage中propName对应数据的引用。否则，返回undefined。

与[link](#link9)的功能基本一致，但不需要手动释放返回的[AbstractProperty](#abstractproperty)类型的变量。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明                 |
| -------- | ------ | ---- | ------------------------ |
| propName | string | 是   | LocalStorage中的属性名。 |

**返回值：**

| 类型                                   | 说明                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| [AbstractProperty&lt;T&gt;](#abstractproperty) \| undefined | LocalStorage中propName对应属性的引用，如果LocalStorage中不存在对应的propName，则返回undefined。 |

**示例：**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let refToPropA1: AbstractProperty<number> | undefined = storage.ref('PropA');
let refToPropA2: AbstractProperty<number> | undefined = storage.ref('PropA'); // refToPropA2.get() == 47
refToPropA1?.set(48); // refToPropA1.get() == refToPropA2.get() == 48
```

### setAndRef<sup>12+</sup>

public setAndRef&lt;T&gt;(propName: string, defaultValue: T): AbstractProperty&lt;T&gt;

与[ref](#ref12-1)接口类似，如果给定的propName在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中存在，则获得LocalStorage中propName对应数据的引用。如果不存在，则使用defaultValue在LocalStorage中创建和初始化propName对应的属性，并返回其引用。defaultValue须为T类型，可以为null或undefined。

与[setAndLink](#setandlink9)的功能基本一致，但不需要手动释放返回的[AbstractProperty](#abstractproperty)类型的变量。

> **说明：**<br/>
> 从API version 12开始，LocalStorage支持[Map](../../../ui/state-management/arkts-localstorage.md#装饰map类型变量)、[Set](../../../ui/state-management/arkts-localstorage.md#装饰set类型变量)、[Date类型](../../../ui/state-management/arkts-localstorage.md#装饰date类型变量)，支持null、undefined以及[联合类型](../../../ui/state-management/arkts-localstorage.md#localstorage支持联合类型)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | 是   | LocalStorage中的属性名。                                     |
| defaultValue | T      | 是   | 当propName在LocalStorage中不存在时，使用defaultValue在LocalStorage中初始化对应的propName，defaultValue可以为null或undefined。 |

**返回值：**

| 类型                      | 说明                                                         |
| ------------------------- | ------------------------------------------------------------ |
| [AbstractProperty&lt;T&gt;](#abstractproperty) | AbstractProperty&lt;T&gt;的实例，为LocalStorage中propName对应属性的引用。 |

**示例：**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let ref1: AbstractProperty<number> = storage.setAndRef('PropB', 49); // 用默认值49创建PropB
let ref2: AbstractProperty<number> = storage.setAndRef('PropA', 50); // PropA已存在，值为47
```

### link<sup>9+</sup>

link&lt;T&gt;(propName: string): SubscribedAbstractProperty&lt;T&gt;

如果给定的propName在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)实例中存在，则返回与LocalStorage中propName对应属性的双向绑定数据。

双向绑定数据的修改会被同步回LocalStorage中，LocalStorage会将变化同步到所有绑定该propName的数据和Component中。

如果LocalStorage中不存在propName，则返回undefined。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明               |
| -------- | ------ | ---- | ------------------ |
| propName | string | 是    | LocalStorage中的属性名。 |

**返回值：**

| 类型                                | 说明                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | SubscribedAbstractProperty&lt;T&gt;的实例，与LocalStorage中propName对应属性的双向绑定的数据，如果LocalStorage中不存在对应的propName，则返回undefined。 |

**示例：**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let linkToPropA1: SubscribedAbstractProperty<number> = storage.link('PropA');
let linkToPropA2: SubscribedAbstractProperty<number> = storage.link('PropA'); // linkToPropA2.get() == 47
linkToPropA1.set(48); // 双向同步: linkToPropA1.get() == linkToPropA2.get() == 48
```


### setAndLink<sup>9+</sup>

setAndLink&lt;T&gt;(propName: string, defaultValue: T): SubscribedAbstractProperty&lt;T&gt;

与[link](#link9)接口类似，如果给定的propName在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中存在，则返回该propName对应的属性的双向绑定数据。如果不存在，则使用defaultValue在LocalStorage中创建和初始化propName对应的属性，返回其双向绑定数据。defaultValue必须为T类型，从API version 12开始defaultValue可以为null或undefined。

> **说明：** 
> 
> 从API version 12开始，LocalStorage支持[Map](../../../ui/state-management/arkts-localstorage.md#装饰map类型变量)、[Set](../../../ui/state-management/arkts-localstorage.md#装饰set类型变量)、[Date类型](../../../ui/state-management/arkts-localstorage.md#装饰date类型变量)，支持null、undefined以及[联合类型](../../../ui/state-management/arkts-localstorage.md#localstorage支持联合类型)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | 是   | LocalStorage中的属性名。                                     |
| defaultValue | T      | 是   | 当propName在LocalStorage中不存在时，使用defaultValue在LocalStorage中初始化对应的propName，从API version 12开始defaultValue可以为null或undefined。 |

**返回值：**

| 类型                                | 说明                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;T&gt;](#subscribedabstractproperty) | SubscribedAbstractProperty&lt;T&gt;的实例，与LocalStorage中propName对应属性的双向绑定的数据。 |

**示例：**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let link1: SubscribedAbstractProperty<number> = storage.setAndLink('PropB', 49); // 用默认值49创建PropB
let link2: SubscribedAbstractProperty<number> = storage.setAndLink('PropA', 50); // PropA已存在，值为47
```


### prop<sup>9+</sup>

prop&lt;S&gt;(propName: string): SubscribedAbstractProperty&lt;S&gt;

如果给定的propName在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中存在，则返回与LocalStorage中propName对应属性的单向绑定数据。如果LocalStorage中不存在propName，则返回undefined。单向绑定数据的修改不会被同步回LocalStorage中。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明               |
| -------- | ------ | ---- | ------------------ |
| propName | string | 是    | LocalStorage中的属性名。 |

**返回值：**

| 类型                                | 说明                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;S&gt;](#subscribedabstractproperty) | SubscribedAbstractProperty&lt;S&gt;的实例，和LocalStorage中propName对应属性的单向绑定的数据。如果LocalStorage中不存在对应的propName，则返回undefined。 |

**示例：**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let prop1: SubscribedAbstractProperty<number> = storage.prop('PropA');
let prop2: SubscribedAbstractProperty<number> = storage.prop('PropA');
prop1.set(1); // 单向同步：prop1.get()的值为1，prop2.get()的值为47
```


### setAndProp<sup>9+</sup>

setAndProp&lt;S&gt;(propName: string, defaultValue: S): SubscribedAbstractProperty&lt;S&gt;

与[prop](#prop9)接口类似。如果propName在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中存在，则返回该propName对应的属性的单向绑定数据。如果不存在，则使用defaultValue在LocalStorage中创建和初始化propName对应的属性，返回其单向绑定数据。defaultValue必须为S类型，从API version 12开始defaultValue可以为null或undefined。

> **说明：** 
> 
> 从API version 12开始，LocalStorage支持[Map](../../../ui/state-management/arkts-localstorage.md#装饰map类型变量)、[Set](../../../ui/state-management/arkts-localstorage.md#装饰set类型变量)、[Date类型](../../../ui/state-management/arkts-localstorage.md#装饰date类型变量)，支持null、undefined以及[联合类型](../../../ui/state-management/arkts-localstorage.md#localstorage支持联合类型)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| propName     | string | 是   | LocalStorage中的属性名。                                     |
| defaultValue | S      | 是   | 当propName在LocalStorage中不存在，使用defaultValue在LocalStorage中初始化对应的propName，从API version 12开始defaultValue可以为null或undefined。 |

**返回值：**

| 类型                                | 说明                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
| [SubscribedAbstractProperty&lt;S&gt;](#subscribedabstractproperty) | SubscribedAbstractProperty&lt;S&gt;的实例，和LocalStorage中propName对应属性的单向绑定的数据。 |

**示例：**

```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let prop: SubscribedAbstractProperty<number> = storage.setAndProp('PropB', 49); // PropA -> 47, PropB -> 49
```


### delete<sup>9+</sup>

delete(propName: string): boolean

在[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中删除propName对应的属性。在LocalStorage中删除属性的前提是该属性已经没有订阅者，如果有订阅者，则返回false。如果没有订阅者则删除成功并返回true。

属性的订阅者为：

1. [\@LocalStorageLink](../../../ui/state-management/arkts-localstorage.md#localstoragelink)、[\@LocalStorageProp](../../../ui/state-management/arkts-localstorage.md#localstorageprop)装饰的变量。

2. 通过[link](#link9)、[prop](#prop9)、[setAndLink](#setandlink9)、[setAndProp](#setandprop9)接口返回的[SubscribedAbstractProperty](#subscribedabstractproperty)的实例。

如果想要删除这些订阅者，可以通过以下方式：

1. 删除\@LocalStorageLink、\@LocalStorageProp所在的自定义组件。删除自定义组件请参考[自定义组件的删除](../../../ui/state-management/arkts-page-custom-components-lifecycle.md#自定义组件的删除)。

2. 对link、prop、setAndLink、setAndProp接口返回的SubscribedAbstractProperty的实例调用[aboutToBeDeleted](#abouttobedeleted10)接口。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型     | 必填   | 说明               |
| -------- | ------ | ---- | ------------------ |
| propName | string | 是    | LocalStorage中的属性名。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果LocalStorage中有对应的属性，且该属性已经没有订阅者，则删除成功，返回true。如果属性不存在，或者该属性还存在订阅者，则返回false。 |

**示例：**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
storage.link<number>('PropA');
let res: boolean = storage.delete('PropA'); // false，PropA 还存在订阅者
let res1: boolean = storage.delete('PropB'); // false，PropB 不存在于storage中
storage.setOrCreate('PropB', 48);
let res2: boolean = storage.delete('PropB'); // true，PropB 已从storage成功删除
```


### keys<sup>9+</sup>

keys(): IterableIterator&lt;string&gt;

返回[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中所有的属性名。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                             | 说明                   |
| ------------------------------ | -------------------- |
| IterableIterator&lt;string&gt; | LocalStorage中所有的属性名。 |

**示例：**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let keys: IterableIterator<string> = storage.keys();
```


### size<sup>9+</sup>

size(): number

返回[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中的属性数量。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| number | LocalStorage中属性的数量。 |

**示例：**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: number = storage.size(); // 1
```


### clear<sup>9+</sup>

clear(): boolean

删除[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中所有的属性。删除所有属性的前提是已经没有任何订阅者。如果有订阅者，clear不会生效并返回false。如果没有订阅者则删除成功并返回true。

订阅者的含义参考[delete](#delete9)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**


| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果LocalStorage中的属性已经没有任何订阅者，则删除成功，并返回true。否则返回false。 |


**示例：**
```ts
let para: Record<string, number> = { 'PropA': 47 };
let storage: LocalStorage = new LocalStorage(para);
let res: boolean = storage.clear(); // true，已经没有订阅者
```


### GetShared<sup>(deprecated)</sup>

static GetShared(): LocalStorage

获取当前stage共享的[LocalStorage](../../../ui/state-management/arkts-localstorage.md)实例。

> **说明：** 
> 
> 从API version 10开始废弃，建议使用[UIContext](../arkts-apis-uicontext-uicontext.md)中的[getSharedLocalStorage](../arkts-apis-uicontext-uicontext.md#getsharedlocalstorage12)替代。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型                             | 说明                |
| ------------------------------ | ----------------- |
| [LocalStorage](#localstorage9) | 返回LocalStorage实例。 |

**示例：**
```ts
let storage: LocalStorage = LocalStorage.GetShared();
```

## AbstractProperty

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### get<sup>12+</sup>

get(): T

读取[AppStorage](../../../ui/state-management/arkts-appstorage.md)/[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中所引用属性的数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型 | 说明                                        |
| ---- | ------------------------------------------- |
| T    | AppStorage/LocalStorage中所引用属性的数据。 |

**示例：**

```ts
AppStorage.setOrCreate('PropA', 47);
let ref1: AbstractProperty<number> | undefined = AppStorage.ref('PropA');
ref1?.get(); //  ref1.get()=47
```


### set<sup>12+</sup>

set(newValue: T): void

更新[AppStorage](../../../ui/state-management/arkts-appstorage.md)/[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中所引用属性的数据，newValue必须是T类型，可以为null或undefined。

> **说明：**<br/>
>
> 从API version 12开始，AppStorage/LocalStorage支持Map、Set、Date类型，支持null、undefined以及联合类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：**


| 参数名   | 类型 | 必填 | 说明                              |
| -------- | ---- | ---- | ------------------------------------- |
| newValue | T    | 是   | 要更新的数据，可以为null或undefined。 |


**示例：**

```ts
AppStorage.setOrCreate('PropA', 47);
let ref1: AbstractProperty<number> | undefined = AppStorage.ref('PropA');
ref1?.set(1); //  ref1.get()=1
let a: Map<string, number> = new Map([['1', 0]]);
let ref2 = AppStorage.setAndRef('MapA', a);
ref2.set(a);
let b: Set<string> = new Set('1');
let ref3 = AppStorage.setAndRef('SetB', b);
ref3.set(b);
let c: Date = new Date('2024');
let ref4 = AppStorage.setAndRef('DateC', c);
ref4.set(c);
ref2.set(null);
ref3.set(undefined);
```

### info<sup>12+</sup>

info(): string

读取[AppStorage](../../../ui/state-management/arkts-appstorage.md)/[LocalStorage](../../../ui/state-management/arkts-localstorage.md)中所引用属性的属性名。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型   | 说明                                          |
| ------ | --------------------------------------------- |
| string | AppStorage/LocalStorage中所引用属性的属性名。 |

**示例：**

```ts
AppStorage.setOrCreate('PropA', 47);
let ref1: AbstractProperty<number> | undefined = AppStorage.ref('PropA');
ref1?.info(); //  ref1.info()='PropA'
```

## SubscribedAbstractProperty

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### get<sup>9+</sup>

abstract get(): T

读取从[AppStorage](../../../ui/state-management/arkts-appstorage.md)/[LocalStorage](../../../ui/state-management/arkts-localstorage.md)同步属性的数据。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型   | 说明                              |
| ---- | ------------------------------- |
| T    | AppStorage/LocalStorage同步属性的数据。 |

**示例：**
```ts
AppStorage.setOrCreate('PropA', 47); 
let prop1: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');    
prop1.get(); //  prop1.get()=47
```


### set<sup>9+</sup>

abstract set(newValue: T): void

设置[AppStorage](../../../ui/state-management/arkts-appstorage.md)/[LocalStorage](../../../ui/state-management/arkts-localstorage.md)同步属性的数据，newValue必须是T类型，从API version 12开始可以为null或undefined。

> **说明：** 
> 
>从API version 12开始，AppStorage/LocalStorage支持Map、Set、Date类型，支持null、undefined以及联合类型。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：**


| 参数名   | 类型 | 必填 | 说明                                                  |
| -------- | ---- | ---- | --------------------------------------------------------- |
| newValue | T    | 是   | 要设置的数据，从API version 12开始可以为null或undefined。 |


**示例：**
```ts
AppStorage.setOrCreate('PropA', 47);
let prop1: SubscribedAbstractProperty<number> = AppStorage.prop('PropA');
prop1.set(1); //  prop1.get()=1
// 从API12开始支持Map、Set、Date类型，支持null、undefined以及联合类型。
let a: Map<string, number> = new Map([['1', 0]]);
let prop2 = AppStorage.setAndProp('MapA', a);
prop2.set(a);
let b: Set<string> = new Set('1');
let prop3 = AppStorage.setAndProp('SetB', b);
prop3.set(b);
let c: Date = new Date('2024');
let prop4 = AppStorage.setAndProp('DateC', c);
prop4.set(c);
prop2.set(null);
prop3.set(undefined);
```

### aboutToBeDeleted<sup>10+</sup>

abstract aboutToBeDeleted(): void

取消[SubscribedAbstractProperty](#subscribedabstractproperty)实例对[AppStorage](../../../ui/state-management/arkts-appstorage.md)/[LocalStorage](../../../ui/state-management/arkts-localstorage.md)的单/双向同步关系，并无效化SubscribedAbstractProperty实例，即当调用aboutToBeDeleted方法之后不能再使用SubscribedAbstractProperty实例调用[set](#set9-1)或[get](#get9-1)方法。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**
```ts
AppStorage.setOrCreate('PropA', 47);
let link = AppStorage.setAndLink('PropB', 49); // PropA -> 47, PropB -> 49
link.aboutToBeDeleted();
```

### info

info(): string;

返回属性名称。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

|类型   |说明     |
|---------|-------------|
|string    |属性名称。    |

## PersistPropsOptions<sup>10+</sup>

用于指定持久化属性及其默认值的键值对对象，作为[persistProps](#persistprops10)参数传入。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型                                  | 必填 | 说明                                                     |
| ------------ | ------------------------------------- | ---- | ------------------------------------------------------------ |
| key          | string                                | 是   | 属性名。                                                     |
| defaultValue | number \| string \| boolean \| Object | 是   | 在PersistentStorage和AppStorage未查询到时，则使用默认值初始化它。从API version 12开始，defaultValue允许为null或undefined。 |

## PersistentStorage

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

PersistentStorage具体UI使用说明，详见[PersistentStorage(持久化存储UI状态)](../../../ui/state-management/arkts-persiststorage.md)

> **说明：**<br/>
> 从API version 12开始，PersistentStorage支持null、undefined。

### persistProp<sup>10+</sup>

static persistProp&lt;T&gt;(key: string, defaultValue: T): void

将[AppStorage](../../../ui/state-management/arkts-appstorage.md)中key对应的属性持久化到文件中。该接口的调用通常在访问AppStorage之前。

确定属性的类型和值的顺序如下：

1. 如果[PersistentStorage](../../../ui/state-management/arkts-persiststorage.md)文件中存在key对应的属性，在AppStorage中创建对应的propName，并用在PersistentStorage中找到的key的属性初始化。

2. 如果PersistentStorage文件中没有查询到key对应的属性，则在AppStorage中查找key对应的属性。如果找到key对应的属性，则将该属性持久化。

3. 如果AppStorage中也没查找到key对应的属性，则在AppStorage中创建key对应的属性。用defaultValue初始化其值，并将该属性持久化。

根据上述的初始化流程，如果AppStorage中有该属性，则会使用其值，覆盖掉PersistentStorage文件中的值。由于AppStorage是内存内数据，该行为会导致数据丧失持久化能力。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| key          | string | 是   | 属性名。                                                     |
| defaultValue | T      | 是   | 在PersistentStorage和AppStorage中未查询到时，则使用默认值进行初始化。从API version 12开始允许为null或undefined。 |


**示例：**


persistProp具体使用，见[从AppStorage中访问PersistentStorage初始化的属性](../../../ui/state-management/arkts-persiststorage.md#从appstorage中访问persistentstorage初始化的属性)


### deleteProp<sup>10+</sup>

static deleteProp(key: string): void

[persistProp](#persistprop10)的逆向操作。将key对应的属性从PersistentStorage中删除，后续[AppStorage](../../../ui/state-management/arkts-appstorage.md)的操作，对[PersistentStorage](../../../ui/state-management/arkts-persiststorage.md)不会再有影响。该操作会将对应的key从持久化文件中删除，如果希望再次持久化，可以再次调用[persistProp](#persistprop10)接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填   | 说明                    |
| ---- | ------ | ---- | ----------------------- |
| key  | string | 是    | PersistentStorage中的属性名。 |

**示例：**
```ts
PersistentStorage.deleteProp('highScore');
```


### persistProps<sup>10+</sup>

static persistProps(props: PersistPropsOptions[]): void

行为和[persistProp](#persistprop10)类似，不同在于可以一次性持久化多个数据，适合在应用启动的时候初始化。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名        | 类型                                       | 必填   | 说明                                     |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| props | [PersistPropsOptions](#persistpropsoptions10)[] | 是 | 持久化数组。 |

**示例：**
```ts
PersistentStorage.persistProps([{ key: 'highScore', defaultValue: '0' }, { key: 'wightScore', defaultValue: '1' }]);
```


### keys<sup>10+</sup>

static keys(): Array&lt;string&gt;

返回所有持久化属性的属性名的数组。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                | 说明                               |
| ------------------- | ---------------------------------- |
| Array&lt;string&gt; | 返回所有持久化属性的属性名的数组。 |

**示例：**
```ts
let keys: Array<string> = PersistentStorage.keys();
```


### PersistProp<sup>(deprecated)</sup>

static PersistProp&lt;T&gt;(key: string, defaultValue: T): void

将[AppStorage](../../../ui/state-management/arkts-appstorage.md)中key对应的属性持久化到文件中。该接口的调用通常在访问AppStorage之前。

确定属性的类型和值的顺序如下：

1. 如果[PersistentStorage](../../../ui/state-management/arkts-persiststorage.md)文件中存在key对应的属性，在AppStorage中创建对应的propName，并用在PersistentStorage中找到的key的属性初始化。

2. 如果PersistentStorage文件中没有查询到key对应的属性，则在AppStorage中查找key对应的属性。如果找到key对应的属性，则将该属性持久化。

3. 如果AppStorage也没查找到key对应的属性，则在AppStorage中创建key对应的属性。用defaultValue初始化其值，并将该属性持久化。

根据上述的初始化流程，如果AppStorage中有该属性，则会使用其值，覆盖掉PersistentStorage文件中的值。由于AppStorage是内存内数据，该行为会导致数据丧失持久化能力。


> **说明：**<br/>
> 从API version 10开始废弃，推荐使用[persistProp10+](#persistprop10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| key          | string | 是   | 属性名。                                                     |
| defaultValue | T      | 是   | 在PersistentStorage和AppStorage中未查询到时，则使用默认值进行初始化。不允许为null或undefined。 |


**示例：**


```ts
PersistentStorage.PersistProp('highScore', '0');
```


### DeleteProp<sup>(deprecated)</sup>

static DeleteProp(key: string): void

[PersistProp](#persistpropdeprecated)的逆向操作。将key对应的属性从[PersistentStorage](../../../ui/state-management/arkts-persiststorage.md)中删除，后续[AppStorage](../../../ui/state-management/arkts-appstorage.md)的操作，对PersistentStorage不会再有影响。


> **说明：**<br/>
> 从API version 10开始废弃，推荐使用[deleteProp10+](#deleteprop10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填   | 说明                    |
| ---- | ------ | ---- | ----------------------- |
| key  | string | 是    | PersistentStorage中的属性名。 |

**示例：**
```ts
PersistentStorage.DeleteProp('highScore');
```


### PersistProps<sup>(deprecated)</sup>

static PersistProps(properties: {key: string, defaultValue: any;}[]): void

行为和[PersistProp](#persistpropdeprecated)类似，不同在于可以一次性持久化多个数据，适合在应用启动的时候初始化。

> **说明：**<br/>
> 从API version 10开始废弃，推荐使用[persistProps10+](#persistprops10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                               | 必填 | 说明                                                     |
| ---------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| properties | {key: string, defaultValue: any}[] | 是   | 持久化数组，启动key为属性名，defaultValue为默认值。规则同PersistProp。 |

**示例：**

```ts
PersistentStorage.PersistProps([{ key: 'highScore', defaultValue: '0' }, { key: 'wightScore', defaultValue: '1' }]);
```

### Keys<sup>(deprecated)</sup>

static Keys(): Array&lt;string&gt;

返回所有持久化属性的属性名的数组。

> **说明：**<br/>
> 从API version 10开始废弃，推荐使用[keys10+](#keys10-1)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                | 说明                               |
| ------------------- | ---------------------------------- |
| Array&lt;string&gt; | 返回所有持久化属性的属性名的数组。 |

**示例：**
```ts
let keys: Array<string> = PersistentStorage.Keys();
```
## EnvPropsOptions<sup>10+</sup>

用于指定环境变量名称及其默认值的键值对对象，作为[envProps](#envprops10)参数传入。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型                        | 必填 | 说明                                                     |
| ------------ | --------------------------- | ---- | ------------------------------------------------------------ |
| key          | string                      | 是   | 环境变量名称，支持的范围详见[内置环境变量说明](#内置环境变量说明)。 |
| defaultValue | number \| string \| boolean | 是   | 查询不到环境变量key，则使用defaultValue作为默认值存入AppStorage中。 |

## Environment

Environment具体使用说明，详见[Environment(设备环境查询)](../../../ui/state-management/arkts-environment.md)

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### envProp<sup>10+</sup>

static envProp&lt;S&gt;(key: string, value: S): boolean

将[Environment](../../../ui/state-management/arkts-environment.md)的内置环境变量key存入[AppStorage](../../../ui/state-management/arkts-appstorage.md)中。如果系统中未查询到Environment环境变量key的值，则使用默认值value，存入成功，返回true。如果AppStorage中已经有对应的key，则返回false。

所以建议在程序启动的时候调用该接口。

在没有调用envProp的情况下，就使用AppStorage读取环境变量是错误的。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                     |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| key    | string | 是   | 环境变量名称，支持的范围详见[内置环境变量说明](#内置环境变量说明)。 |
| value  | S      | 是   | 查询不到环境变量key时，则使用value作为默认值存入AppStorage中。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果key对应的属性在AppStorage中存在，则返回false。不存在则在AppStorage中用value作为默认值创建key对应的属性，返回true。 |

**示例：**

envProp具体使用，详见[从UI中访问Environment参数](../../../ui/state-management/arkts-environment.md#从ui中访问environment参数)。


### envProps<sup>10+</sup>

static envProps(props: EnvPropsOptions[]): void

和[envProp](#envprop10)类似，不同点在于参数为数组，可以一次性初始化多个数据。建议在应用启动时调用，将系统环境变量批量存入[AppStorage](../../../ui/state-management/arkts-appstorage.md)中。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                          | 必填 | 说明                             |
| ------ | --------------------------------------------- | ---- | ------------------------------------ |
| props  | [EnvPropsOptions](#envpropsoptions10)[] | 是   | 系统环境变量和默认值的键值对的数组。 |

**示例：**
```ts
Environment.envProps([{ key: 'accessibilityEnabled', defaultValue: 'default' }, {
  key: 'languageCode',
  defaultValue: 'en'
}, { key: 'prop', defaultValue: 'hhhh' }]);
```


### keys<sup>10+</sup>

static keys(): Array&lt;string&gt;

返回环境变量的属性key的数组。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                  | 说明          |
| ------------------- | ----------- |
| Array&lt;string&gt; | 返回关联的系统项数组。 |

**示例：**
```ts
Environment.envProps([{ key: 'accessibilityEnabled', defaultValue: 'default' }, {
  key: 'languageCode',
  defaultValue: 'en'
}, { key: 'prop', defaultValue: 'hhhh' }]);

let keys: Array<string> = Environment.keys(); // keys 包含 accessibilityEnabled，languageCode，prop
```


### EnvProp<sup>(deprecated)</sup>

static EnvProp&lt;S&gt;(key: string, value: S): boolean

将[Environment](../../../ui/state-management/arkts-environment.md)的内置环境变量key存入[AppStorage](../../../ui/state-management/arkts-appstorage.md)中。如果系统中未查询到Environment环境变量key的值，则使用默认值value，存入成功，返回true。如果AppStorage中已经有对应的key，则返回false。

所以建议在程序启动的时候调用该接口。

在没有调用EnvProp的情况下，就使用AppStorage读取环境变量是错误的。

> **说明：**<br/>
> 从API version 10开始废弃，推荐使用[envProp10+](#envprop10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                     |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| key    | string | 是   | 环境变量名称，支持的范围详见[内置环境变量说明](#内置环境变量说明)。 |
| value  | S      | 是   | 查询不到环境变量key，则使用value作为默认值存入AppStorage中。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果key对应的属性在AppStorage中存在，则返回false。不存在则在AppStorage中用value作为默认值创建key对应的属性，返回true。 |

**示例：**


```ts
Environment.EnvProp('accessibilityEnabled', 'default');
```


### EnvProps<sup>(deprecated)</sup>

static EnvProps(props: {key: string; defaultValue: any;}[]): void

和[EnvProp](#envpropdeprecated)类似，不同点在于参数为数组，可以一次性初始化多个数据。建议在应用启动时调用，将系统环境变量批量存入[AppStorage](../../../ui/state-management/arkts-appstorage.md)中。

> **说明：**<br/>
> 从API version 10开始废弃，推荐使用[envProps10+](#envprops10)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                              | 必填 | 说明                             |
| ------ | ------------------------------------------------- | ---- | ------------------------------------ |
| props  | {key:&nbsp;string,&nbsp;defaultValue:&nbsp;any}[] | 是   | 系统环境变量和默认值的键值对的数组。 |

**示例：**
```ts
Environment.EnvProps([{ key: 'accessibilityEnabled', defaultValue: 'default' }, {
  key: 'languageCode',
  defaultValue: 'en'
}, { key: 'prop', defaultValue: 'hhhh' }]);
```


### Keys<sup>(deprecated)</sup>

static Keys(): Array&lt;string&gt;

返回环境变量的属性key的数组。

> **说明：**<br/>
> 从API version 10开始废弃，推荐使用[keys10+](#keys10-2)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                  | 说明          |
| ------------------- | ----------- |
| Array&lt;string&gt; | 返回关联的系统项数组。 |

**示例：**

```ts
Environment.EnvProps([{ key: 'accessibilityEnabled', defaultValue: 'default' }, {
  key: 'languageCode',
  defaultValue: 'en'
}, { key: 'prop', defaultValue: 'hhhh' }]);

let keys: Array<string> = Environment.Keys(); // keys 包含 accessibilityEnabled，languageCode，prop
```


## 内置环境变量说明

| key                  | 类型            | 说明                                                         |
| -------------------- | --------------- | ------------------------------------------------------------ |
| accessibilityEnabled | string          | 无障碍屏幕朗读是否启用。当无法获取环境变量中的accessibilityEnabled的值时，将通过envProp、envProps等接口传入的开发者指定的默认值添加到AppStorage中。 |
| colorMode            | ColorMode       | 深浅色模式，可选值为：<br/>-&nbsp;ColorMode.LIGHT：浅色模式；<br/>-&nbsp;ColorMode.DARK：深色模式。 |
| fontScale            | number          | 字体大小比例。                                               |
| fontWeightScale      | number          | 字重比例。                                                   |
| layoutDirection      | LayoutDirection | 布局方向类型，可选值为：<br/>-&nbsp;LayoutDirection.LTR：从左到右；<br/>-&nbsp;LayoutDirection.RTL：从右到左。<br/>-&nbsp;Auto：跟随系统。 |
| languageCode         | string          | 当前系统语言，小写字母，例如zh。                             |
