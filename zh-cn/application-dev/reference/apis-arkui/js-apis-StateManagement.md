# @ohos.arkui.StateManagement (状态管理)

状态管理模块提供了应用程序的数据存储能力、持久化数据管理能力、UIAbility数据存储能力和应用程序需要的环境状态、工具。

>**说明：**
>
>本模块首批接口从API version 12开始支持。


本文中T和S的含义如下：


| 类型   | 描述                                     |
| ---- | -------------------------------------- |
| T    | Class，number，boolean，string和这些类型的数组形式。 |
| S    | number，boolean，string。                 |


## 导入模块

```ts
import { AppStorageV2,PersistenceV2,UIUtils} from '@kit.ArkUI';
```

## AppStorageV2

AppStorageV2具体UI使用说明，详见[AppStorageV2(应用全局的UI状态存储)](../../quick-start/arkts-new-appstoragev2.md)

### connect<sup>12+</sup>

static&nbsp;connect\<T extends object\>( </br >
  &nbsp;&nbsp;&nbsp;&nbsp;type:&nbsp;TypeConstructorWithArgs\<T\>, </br >
  &nbsp;&nbsp;&nbsp;&nbsp;keyOrDefaultCreator?:&nbsp;string&nbsp;|&nbsp;StorageDefaultCreator\<T\>, </br >
  &nbsp;&nbsp;&nbsp;&nbsp;defaultCreator?:&nbsp;StorageDefaultCreator\<T\> </br >
):&nbsp;T&nbsp;|&nbsp;undefined;

将键值对数据储存在应用内存中。如果给定的key已经存在于[AppStorageV2](../../quick-start/arkts-new-appstoragev2.md)中，返回对应的值；否则，通过获取默认值的构造器构造默认值，并返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 参数描述               |
| -------- | ------ | ---- | ---------------------- |
| type | TypeConstructorWithArgs\<T\> | 是   | 指定的类型，若未指定key，则使用type的name作为key。 |
| keyOrDefaultCreater | string&nbsp;\|&nbsp;StorageDefaultCreator\<T\> | 否   | 指定的key，或者是获取默认值的构造器。 |
| defaultCreator | StorageDefaultCreator\<T\> | 否   | 获取默认值的构造器。 |

>**说明：**
>
>1、若未指定key，使用第二个参数作为默认构造器；否则使用第三个参数作为默认构造器；
>
>2、确保数据已经存储在AppStorageV2中，可省略默认构造器，获取存储的数据；否则必须指定默认构造器，不指定将导致应用异常；
>
>3、同一个key，connect不同类型的数据会导致应用异常，应用需要确保类型匹配；
>
>4、key建议使用有意义的值，长度不超过255，使用非法字符或空字符的行为是未定义的。

**返回值：**

| 类型                                   | 描述                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| T | 创建或获取AppStorageV2数据成功时，返回数据；否则返回undefined。 |

**示例：**

```ts
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
class SampleClass {
  @Trace p: number = 0;
}

// 将key为SampleClass、value为new SampleClass()对象的键值对存储到内存中，并赋值给as1
const as1: SampleClass | undefined = AppStorageV2.connect(SampleClass, () => new SampleClass());

// 将key为key_as2、value为new SampleClass()对象的键值对存储到内存中，并赋值给as2
const as2: SampleClass = AppStorageV2.connect(SampleClass, 'key_as2', () => new SampleClass())!;

// key为SampleClass已经在AppStorageV2中，将key为SampleClass的值返回给as3
const as3: SampleClass = AppStorageV2.connect(SampleClass) as SampleClass;
```

### remove<sup>12+</sup>

static&nbsp;remove\<T\>(keyOrType:&nbsp;string&nbsp;|&nbsp;TypeConstructorWithArgs\<T\>):&nbsp;void;

将指定的键值对数据从[AppStorageV2](../../quick-start/arkts-new-appstoragev2.md)里面删除。如果指定的键值不存在于AppStorageV2中，将删除失败。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 参数描述               |
| -------- | ------ | ---- | ---------------------- |
| keyOrType | string \| TypeConstructorWithArgs\<T\> | 是   | 需要删除的key；如果指定的是type类型，删除的key为type的name。 |

>**说明：**
>
>删除AppStorageV2中不存在的key会报警告。


**示例：**

```ts
// 假设AppStorageV2中存在key为key_as2的键，从AppStorageV2中删除该键值对数据
AppStorageV2.remove('key_as2');

// 假设AppStorageV2中存在key为SampleClass的键，从AppStorageV2中删除该键值对数据
AppStorageV2.remove(SampleClass);

// 假设AppStorageV2中不存在key为key_as1的键，报警告
AppStorageV2.remove('key_as1');
```

### keys<sup>12+</sup>

static&nbsp;keys():&nbsp;Array\<string\>;

获取[AppStorageV2](../../quick-start/arkts-new-appstoragev2.md)中的所有key。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

无。

**返回值：**

| 类型                                   | 描述                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| Array\<string\> | 所有AppStorageV2中的key。 |

>**说明：**
>
>key在Array中的顺序是无序的，与key插入到AppStorageV2中的顺序无关。

**示例：**

```ts
// 假设AppStorageV2中存在两个key（key_as1、key_as2），返回[key_as1、key_as2]赋值给keys
const keys: Array<string> = AppStorageV2.keys();
```



## PersistenceV2

PersistenceV2具体UI使用说明，详见[PersistenceV2(持久化存储UI状态)](../../quick-start/arkts-new-persistencev2.md)

### connect<sup>12+</sup>

static&nbsp;connect\<T extends object\>( </br >
  &nbsp;&nbsp;&nbsp;&nbsp;type:&nbsp;TypeConstructorWithArgs\<T\>, </br >
  &nbsp;&nbsp;&nbsp;&nbsp;keyOrDefaultCreator?:&nbsp;string&nbsp;|&nbsp;StorageDefaultCreator\<T\>, </br >
  &nbsp;&nbsp;&nbsp;&nbsp;defaultCreator?:&nbsp;StorageDefaultCreator\<T\> </br >
):&nbsp;T&nbsp;|&nbsp;undefined;

将键值对数据储存在应用磁盘中（持久化）。如果给定的key已经存在于[PersistenceV2](../../quick-start/arkts-new-persistencev2.md)中，返回对应的值；否则，通过获取默认值的构造器构造默认值，并返回。如果connect的是[\@ObservedV2](../../quick-start/arkts-new-observedV2-and-trace.md)对象，该对象的[\@Trace](../../quick-start/arkts-new-observedV2-and-trace.md)属性的变化，会触发**整个关联对象的自动持久化**；非\@Trace属性的变化则不会，如有必要，可调用PersistenceV2.save接口手动持久化。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 参数描述               |
| -------- | ------ | ---- | ---------------------- |
| type | TypeConstructorWithArgs\<T\> | 是   | 指定的类型，若未指定key，则使用type的name作为key。 |
| keyOrDefaultCreater | string&nbsp;\|&nbsp;StorageDefaultCreator\<T\> | 否   | 指定的key，或者是获取默认值的构造器。 |
| defaultCreator | StorageDefaultCreator\<T\> | 否   | 获取默认值的构造器。 |

>**说明：**
>
>1、若未指定key，使用第二个参数作为默认构造器；否则使用第三个参数作为默认构造器（第二个参数非法也使用第三个参数作为默认构造器）；
>
>2、确保数据已经存储在PersistenceV2中，可省略默认构造器，获取存储的数据；否则必须指定默认构造器，不指定将导致应用异常；
>
>3、同一个key，connect不同类型的数据会导致应用异常，应用需要确保类型匹配；
>
>4、key建议使用有意义的值，可由字母、数字、下划线组成，长度不超过255，使用非法字符或空字符的行为是未定义的。

**返回值：**

| 类型                                   | 描述                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| T | 创建或获取AppStorageV2数据成功时，返回数据；否则返回undefined。 |

**示例：**

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

// 将key为SampleClass、value为new SampleClass()对象的键值对持久化，并赋值给as1
const as1: FatherSampleClass | undefined = PersistenceV2.connect(FatherSampleClass, () => new FatherSampleClass());

// 将key为key_as2、value为new SampleClass()对象的键值对持久化，并赋值给as2
const as2: FatherSampleClass = PersistenceV2.connect(FatherSampleClass, 'key_as2', () => new FatherSampleClass())!;

// key为SampleClass已经在PersistenceV2中，将key为SampleClass的值返回给as3
const as3: FatherSampleClass = PersistenceV2.connect(FatherSampleClass) as FatherSampleClass;

@Entry
@Component
struct SampleComp {
  v: FatherSampleClass = as2;

  build() {
    Column() {
      Text(`${this.v.f.p1}`)
        .onClick(() => {
          // 自动持久化
          this.v.f.p1++;
        })
      Text(`${this.v.f.p2}`)
        .onClick(() => {
          // 不能自动持久化，需要调用PersistenceV2.save
          this.v.f.p2++;
        })
    }
  }
}
```

### remove<sup>12+</sup>

static&nbsp;remove\<T\>(keyOrType:&nbsp;string&nbsp;|&nbsp;TypeConstructorWithArgs\<T\>):&nbsp;void;

将指定的键值对数据从[PersistenceV2](../../quick-start/arkts-new-persistencev2.md)里面删除。如果指定的键值不存在于PersistenceV2中，将删除失败。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 参数描述               |
| -------- | ------ | ---- | ---------------------- |
| keyOrType | string \| TypeConstructorWithArgs\<T\> | 是   | 需要删除的key；如果指定的是type类型，删除的key为type的name。 |

>**说明：**
>
>删除PersistenceV2中不存在的key会报警告。


**示例：**

```ts
// 假设PersistenceV2中存在key为key_as2的键，从PersistenceV2中删除该键值对数据
PersistenceV2.remove('key_as2');

// 假设PersistenceV2中存在key为SampleClass的键，从PersistenceV2中删除该键值对数据
PersistenceV2.remove(SampleClass);

// 假设PersistenceV2中不存在key为key_as1的键，报警告
PersistenceV2.remove('key_as1');
```

### keys<sup>12+</sup>

static&nbsp;keys():&nbsp;Array\<string\>;

获取[PersistenceV2](../../quick-start/arkts-new-persistencev2.md)中的所有key。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

无。

**返回值：**

| 类型                                   | 描述                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| Array\<string\> | 所有PersistenceV2中的key。 |

>**说明：**
>
>key在Array中的顺序是无序的，与key插入到PersistenceV2中的顺序无关。

**示例：**

```ts
// 假设PersistenceV2中存在两个key（key_as1、key_as2），返回[key_as1、key_as2]赋值给keys
const keys: Array<string> = PersistenceV2.keys();
```

### save<sup>12+</sup>

static&nbsp;save\<T\>(keyOrType:&nbsp;string&nbsp;|&nbsp;TypeConstructorWithArgs\<T\>):&nbsp;void;

将指定的键值对数据持久化一次。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 参数描述               |
| -------- | ------ | ---- | ---------------------- |
| keyOrType | string \| TypeConstructorWithArgs\<T\> | 是   | 需要持久化的key；如果指定的是type类型，持久化的key为type的name。 |

>**说明：**
>
>由于非[\@Trace](../../quick-start/arkts-new-observedV2-and-trace.md)的数据改变不会触发[PersistenceV2](../../quick-start/arkts-new-persistencev2.md)的自动持久化，如有必要，可调用该接口持久化对应key的数据；
>
>手动持久化当前内存中不处于connect状态的key是无意义的。


**示例：**

```ts
// 假设PersistenceV2中存在key为key_as2的键，持久化该键值对数据
PersistenceV2.save('key_as2');

// 假设PersistenceV2中存在key为SampleClass的键，持久化该键值对数据
PersistenceV2.remove(SampleClass);

// 假设PersistenceV2中不存在key为key_as1的键，无意义的操作
PersistenceV2.remove('key_as1');
```

## UIUtils

UIUtils提供一些方法，用于处理状态管理相关的数据转换。

### getTarget<sup>12+</sup>

static getTarget\<T extends object\>(source: T): T;

从状态管理框架包裹的代理对象中获取原始对象。详见[getTarget接口：获取状态管理框架代理前的原始对象](../../quick-start/arkts-new-getTarget.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 参数描述     |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   | 数据源对象。 |

**返回值：**

| 类型 | 描述                                             |
| ---- | ------------------------------------------------ |
| T    | 数据源对象去除状态管理框架所加代理后的原始对象。 |

**示例：**

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

将普通不可观察数据变为可观察数据。详见[makeObserved接口：将非观察数据变为可观察数据](../../quick-start/arkts-new-makeObserved.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 参数描述     |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   | 数据源对象。支持非@Observed和@ObserveV2修饰的class，JSON.parse返回的Object和@Sendable修饰的class。</br>支持Array、Map、Set和Date。</br>支持collection.Array, collection.Set和collection.Map。</br>具体使用规则，详见[makeObserved接口：将非观察数据变为可观察数据](../../quick-start/arkts-new-makeObserved.md)。 |

**返回值：**

| 类型 | 描述                                             |
| ---- | ------------------------------------------------ |
| T    | 可观察的数据。 |

**示例：**

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
          this.observedClass.name = 'Jane'; // 刷新
        })
      Text(`observedClass: ${this.nonObservedClass.name}`)
        .onClick(() => {
          this.nonObservedClass.name = 'Jane'; // 不刷新
        })
    }
  }
}
```