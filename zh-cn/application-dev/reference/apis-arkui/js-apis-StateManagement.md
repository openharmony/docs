# @ohos.arkui.StateManagement (状态管理)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926; @liwenzhen3; @zzq212050299-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @HelloCrease-->

状态管理模块提供了应用程序的数据存储能力、持久化数据管理能力、UIAbility数据存储能力和应用程序需要的环境状态、工具。

>**说明：**
>
>本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。


本文中T和S的含义如下：


| 类型   | 说明                                     |
| ---- | -------------------------------------- |
| T    | Class，number，boolean，string和这些类型的数组形式。 |
| S    | number，boolean，string。                 |


## 导入模块

```ts
import { AppStorageV2, PersistenceV2, UIUtils } from '@kit.ArkUI';
```

## AppStorageV2

AppStorageV2具体UI使用说明，详见[AppStorageV2(应用全局的UI状态存储)](../../ui/state-management/arkts-new-appstoragev2.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### connect

static&nbsp;connect\<T extends object\>( </br >
  &nbsp;&nbsp;&nbsp;&nbsp;type:&nbsp;TypeConstructorWithArgs\<T\>, </br >
  &nbsp;&nbsp;&nbsp;&nbsp;keyOrDefaultCreator?:&nbsp;string&nbsp;|&nbsp;StorageDefaultCreator\<T\>, </br >
  &nbsp;&nbsp;&nbsp;&nbsp;defaultCreator?:&nbsp;StorageDefaultCreator\<T\> </br >
):&nbsp;T&nbsp;|&nbsp;undefined

将键值对数据储存在应用内存中。如果给定的key已经存在于[AppStorageV2](../../ui/state-management/arkts-new-appstoragev2.md)中，返回对应的值；否则，通过获取默认值的构造器构造默认值，并返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| type | [TypeConstructorWithArgs\<T\>](#typeconstructorwithargst) | 是   | 指定的类型，若未指定key，则使用type的name作为key。 |
| keyOrDefaultCreator | string&nbsp;\|&nbsp;[StorageDefaultCreator\<T\>](#storagedefaultcreatort) | 否   | 指定的key，或者是获取默认值的构造器。 |
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

| 类型                                   | 说明                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| T \| undefined | 创建或获取AppStorageV2数据成功时，返回数据；否则返回undefined。 |

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

### remove

static&nbsp;remove\<T\>(keyOrType:&nbsp;string&nbsp;|&nbsp;TypeConstructorWithArgs\<T\>):&nbsp;void

将指定的键值对数据从[AppStorageV2](../../ui/state-management/arkts-new-appstoragev2.md)里面删除。如果指定的键值不存在于AppStorageV2中，将删除失败。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| keyOrType | string \| TypeConstructorWithArgs\<T\> | 是   | 需要删除的key；如果指定的是type类型，删除的key为type的name。 |

>**说明：**
>
>删除AppStorageV2中不存在的key会报警告。


**示例：**

<!--code_no_check-->
```ts
// 假设AppStorageV2中存在key为key_as2的键，从AppStorageV2中删除该键值对数据
AppStorageV2.remove('key_as2');

// 假设AppStorageV2中存在key为SampleClass的键，从AppStorageV2中删除该键值对数据
AppStorageV2.remove(SampleClass);

// 假设AppStorageV2中不存在key为key_as1的键，报警告
AppStorageV2.remove('key_as1');
```

### keys

static&nbsp;keys():&nbsp;Array\<string\>

获取[AppStorageV2](../../ui/state-management/arkts-new-appstoragev2.md)中的所有key。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                   | 说明                                                         |
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

继承自[AppStorageV2](#appstoragev2)，PersistenceV2具体UI使用说明，详见[PersistenceV2(持久化存储UI状态)](../../ui/state-management/arkts-new-persistencev2.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### globalConnect<sup>18+</sup>

static globalConnect\<T extends object\>(type: ConnectOptions\<T\>): T | undefined

将键值对数据储存在应用磁盘中。如果给定的key已经存在于[PersistenceV2](../../ui/state-management/arkts-new-persistencev2.md)中，返回对应的值；否则，会通过获取默认值的构造器构造默认值，并返回。如果globalConnect的是\@ObservedV2对象，该对象\@Trace属性的变化，会触发整个关联对象的自动刷新；非\@Trace属性变化则不会，如有必要，可调用PersistenceV2.save接口手动存储。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   |类型   |必填   | 说明                                                      |
| ------------- | ------------|-------------------|-------------------------- |
| type    |[ConnectOptions\<T\>](#connectoptions18)    |是  |传入的connect参数，详细说明见ConnectOptions参数说明。 |

**返回值：**

|类型   |说明                 |
|----------|-----------------------------------|
|T \| undefined    |创建或获取数据成功时，返回数据；否则返回undefined。    |

> **说明：**
>
> 1、若未指定key，使用第二个参数作为默认构造器；否则使用第三个参数作为默认构造器（第二个参数非法也使用第三个参数作为默认构造器）。
>
> 2、确保数据已经存储在PersistenceV2中，可省略默认构造器，获取存储的数据；否则必须指定默认构造器，不指定将导致应用异常。
>
> 3、同一个key，globalConnect不同类型的数据会导致应用异常，应用需要确保类型匹配。
>
> 4、key建议使用有意义的值，可由字母、数字、下划线组成，长度不超过255，使用非法字符或空字符的行为是未定义的。
>
> 5、关联[\@Observed](../../ui/state-management/arkts-observed-and-objectlink.md)对象时，因为该类型的name属性未定义，需要指定key或者自定义name属性。
>
> 6、数据的存储路径为应用级别，不同module使用相同的key和相同的加密分区进行globalConnect，存储的数据副本应用仅有一份。
>
> 7、globalConnect使用同一个key但设置了不同的加密级别，数据为第一个使用globalConnect的加密级别，并且PersistenceV2中的数据也会存入最先使用key的加密级别。
>
> 8、connect和globalConnect不建议混用，因为数据副本路径不同，如果混用，则key不可以一样，否则会crash。
>
> 9、EL5加密要想生效，需要开发者在module.json中配置字段ohos.permission.PROTECT_SCREEN_LOCK_DATA，使用说明见[声明权限](../../security/AccessToken/declare-permissions.md)。

**示例：**
仅供开发者了解globalConnect用法，完整使用需开发者自己写出@Entry组件。

<!--code_no_check-->
```ts
import { PersistenceV2, Type, ConnectOptions } from '@kit.ArkUI';
import { contextConstant } from '@kit.AbilityKit';

@ObservedV2
class SampleChild {
  @Trace childId: number = 0;
  groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace father: SampleChild = new SampleChild();
}

// key不传入尝试用为type的name作为key，加密参数不传入默认加密等级为EL2
const p: Sample = PersistenceV2.globalConnect({ type: Sample, defaultCreator: () => new Sample() })!;

// 使用key:global1连接，传入加密等级为EL1
const p1: Sample = PersistenceV2.globalConnect({
  type: Sample,
  key: 'global1',
  defaultCreator: () => new Sample(),
  areaMode: contextConstant.AreaMode.EL1
})!;

// 使用key:global2连接，使用构造函数形式，加密参数不传入默认加密等级为EL2
const p2: Sample = PersistenceV2.globalConnect({ type: Sample, key: 'global2', defaultCreator: () => new Sample() })!;

// 使用key:global3连接，直接写加密数值，范围只能在0-4，否则运行会crash,例如加密设置为EL3
const p3: Sample = PersistenceV2.globalConnect({
  type: Sample,
  key: 'global3',
  defaultCreator: () => new Sample(),
  areaMode: 3
})!;

```

### save

static&nbsp;save\<T\>(keyOrType:&nbsp;string&nbsp;|&nbsp;TypeConstructorWithArgs\<T\>):&nbsp;void

将指定的键值对数据持久化一次。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| keyOrType | string \| TypeConstructorWithArgs\<T\> | 是   | 需要持久化的key；如果指定的是type类型，持久化的key为type的name。 |

>**说明：**
>
>由于非[\@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md)的数据改变不会触发[PersistenceV2](../../ui/state-management/arkts-new-persistencev2.md)的自动持久化，如有必要，可调用该接口持久化对应key的数据。
>
>手动持久化当前内存中不处于connect状态的key是无意义的。

**示例：**

<!--code_no_check-->

```ts
@ObservedV2
class SampleClass {
  @Trace p: number = 0;
}

// 假设PersistenceV2中存在key为key_as2的键，持久化该键值对数据
PersistenceV2.save('key_as2');

// 假设PersistenceV2中存在key为SampleClass的键，持久化该键值对数据
PersistenceV2.save(SampleClass);

// 假设PersistenceV2中不存在key为key_as1的键，无意义的操作
PersistenceV2.save('key_as1');
```

### notifyOnError

static notifyOnError(callback: PersistenceErrorCallback | undefined): void

在持久化失败时调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| callback | PersistenceErrorCallback \| undefined  | 是   | 持久化失败时调用。 |

**示例：**

```ts
// 持久化失败时调用
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});
```

## ConnectOptions<sup>18+</sup>

globalConnect参数类型。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|名称   |类型    |只读   |可选    |说明      |
|--------|------------|------------|-----------|--------------|
|type        | TypeConstructorWithArgs\<T\>   |否   |否   |指定的类型。         |
|key         | string   |否   |是   |传入的key，不传则使用type的名字作为key。             |
|defaultCreator   | StorageDefaultCreator\<T\>   |否   |是   |默认数据的构造器，建议传递，如果globalConnect是第一次连接key，不传会报错。 |
|areaMode      | contextConstant.AreaMode   |否   |是    |加密级别：EL1-EL5，详见[加密级别](../../application-models/application-context-stage.md#获取和修改加密分区)，对应数值：0-4，不传时默认为EL2，不同加密级别对应不同的加密分区，即不同的存储路径，传入的加密等级数值不在0-4会直接运行crash。 |

## UIUtils

UIUtils提供一些方法，用于处理状态管理相关的数据转换。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### getTarget

static getTarget\<T extends object\>(source: T): T

从状态管理框架包裹的代理对象中获取原始对象。详见[getTarget接口：获取状态管理框架代理前的原始对象](../../ui/state-management/arkts-new-getTarget.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   | 数据源对象。 |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| T    | 数据源对象去除状态管理框架所加代理后的原始对象。 |

**示例：**

```ts
import { UIUtils } from '@kit.ArkUI';
class NonObservedClass {
  name: string = 'Tom';
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
### makeObserved

static makeObserved\<T extends object\>(source: T): T

将普通不可观察数据变为可观察数据。详见[makeObserved接口：将非观察数据变为可观察数据](../../ui/state-management/arkts-new-makeObserved.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   | 数据源对象。支持非@Observed和@ObservedV2装饰的class，JSON.parse返回的Object和@Sendable修饰的class。</br>支持Array、Map、Set和Date。</br>支持collection.Array, collection.Set和collection.Map。</br>具体使用规则，详见[makeObserved接口：将非观察数据变为可观察数据](../../ui/state-management/arkts-new-makeObserved.md)。 |

**返回值：**

| 类型 | 说明                                             |
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

### enableV2Compatibility<sup>19+</sup>

static enableV2Compatibility\<T extends object\>(source: T): T

使V1的状态变量能够在\@ComponentV2中观察，主要应用于状态管理V1、V2混用场景。详见[状态管理V1V2混用文档](../../ui/state-management/arkts-v1-v2-mixusage.md)。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   | 数据源，仅支持V1状态数据。 |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| T    | 如果数据源是V1的状态数据，则返回能够在\@ComponentV2中观察的数据。否则返回数据源本身。 |


**示例：**

```ts
import { UIUtils } from '@kit.ArkUI';

@Observed
class ObservedClass {
  name: string = 'Tom';
}

@Entry
@Component
struct CompV1 {
  @State observedClass: ObservedClass = new ObservedClass();

  build() {
    Column() {
      Text(`@State observedClass: ${this.observedClass.name}`)
        .onClick(() => {
          this.observedClass.name = 'State'; // 刷新
        })
      // 将V1的状态变量使能V2的观察能力
      CompV2({ observedClass: UIUtils.enableV2Compatibility(this.observedClass) })
    }
  }
}

@ComponentV2
struct CompV2 {
  @Param observedClass: ObservedClass = new ObservedClass();

  build() {
    // V1状态变量在使能V2观察能力后，可以在V2观察第一层的变化
    Text(`@Param observedClass: ${this.observedClass.name}`)
      .onClick(() => {
        this.observedClass.name = 'Param'; // 刷新
      })
  }
}
```

### makeV1Observed<sup>19+</sup>
static makeV1Observed\<T extends object\>(source: T): T

将不可观察的对象包装成状态管理V1可观察的对象，其能力等同于@Observed，可初始化@ObjectLink。

该接口可搭配[enableV2Compatibility](#enablev2compatibility19)应用于状态管理V1和V2混用场景，详见[状态管理V1V2混用文档](../../ui/state-management/arkts-v1-v2-mixusage.md)。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   | 数据源。支持普通class、Array、Map、Set、Date类型。</br>不支持[collections类型](../apis-arkts/arkts-apis-arkts-collections.md)和[@Sendable](../../arkts-utils/arkts-sendable.md)修饰的class。</br>不支持undefined和null。不支持状态管理V2的数据和[makeObserved](#makeobserved)的返回值。 |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| T    | 对于支持的入参类型，返回状态管理V1的观察数据。对于不支持的入参类型，返回数据源对象本身。 |

**示例：**

```ts
import { UIUtils } from '@kit.ArkUI';

class Outer {
  outerValue: string = 'outer';
  inner: Inner;

  constructor(inner: Inner) {
    this.inner = inner;
  }
}

class Inner {
  interValue: string = 'inner';
}

@Entry
@Component
struct Index {
  @State outer: Outer = new Outer(UIUtils.makeV1Observed(new Inner()));

  build() {
    Column() {
      // makeV1Observed的返回值可初始化@ObjectLink
      Child({ inner: this.outer.inner })
    }
    .height('100%')
    .width('100%')
  }
}

@Component
struct Child {
  @ObjectLink inner: Inner;

  build() {
    Text(`${this.inner.interValue}`)
      .onClick(() => {
        this.inner.interValue += '!';
      })
  }
}
```

### makeBinding<sup>20+</sup>
static makeBinding\<T\>(getter: GetterCallback\<T\>): Binding\<T\>

创建只读的单向数据绑定实例，用于构建\@Builder函数中参数类型为`Binding`的对应实参。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| getter | [GetterCallback\<T\>](#gettercallback20)    | 是   | 获取值的回调函数，每次访问值都会重新执行函数，获取最新值。 |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| [Binding\<T\>](#bindingt20)    | 仅包含一个`value`属性，用于获取当前绑定的值。只能读取值，不能直接修改。 |

**示例：**

```ts
import { Binding, MutableBinding, UIUtils } from '@kit.ArkUI';

@Builder
function CustomButton(num1: Binding<number>) {
  Row() {
    Button(`Custom Button: ${num1.value}`)
      .onClick(() => {
        // num1.value += 1; 会报错，Binding类型不支持修改
      })
  }
}

@Entry
@ComponentV2
struct CompV2 {
  @Local number1: number = 5;
  @Local number2: number = 10;

  build() {
    Column() {
      Text('parent component')

      CustomButton(
        /**
         * 创建只读绑定实例
         * @param getter - 返回this.number1的函数
         * @returns 只读的Binding<number>对象
         *
         * 特点：
         * 1. 每次访问.value时重新计算
         * 2. 不能直接修改值
         */
        UIUtils.makeBinding<number>(
          () => this.number1 // GetterCallback
        )
      )
    }
  }
}
```

### makeBinding<sup>20+</sup>
static makeBinding\<T\>(getter: GetterCallback\<T\>, setter: SetterCallback\<T\>): MutableBinding\<T\>

创建可修改的双向数据绑定实例，用于构建\@Builder函数中参数类型为`MutableBinding`的对应实参。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| getter | [GetterCallback\<T\>](#gettercallback20)    | 是   | 获取值的回调函数，每次访问值都会重新执行函数，获取最新值。 |
| setter | [SetterCallback\<T\>](#settercallback20)    | 是   | 定义如何更新值，当`.value`被修改时自动调用此函数。 |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| [MutableBinding\<T\>](#mutablebindingt20)    | 包含一个`value`属性，支持通过`.value`读取和修改数据，设置值时会检查类型是否匹配泛型`T`。 |

**示例：**

```ts
import { Binding, MutableBinding, UIUtils } from '@kit.ArkUI';

@Builder
function CustomButton(num2: MutableBinding<number>) {
  Row() {
    Button(`Custom Button: ${num2.value}`)
      .onClick(() => {
        // MutableBinding类型支持修改
        num2.value += 1;
      })
  }
}

@Entry
@ComponentV2
struct CompV2 {
  @Local number1: number = 5;
  @Local number2: number = 10;

  build() {
    Column() {
      Text('parent component')

      CustomButton(
        /**
         * 创建可变绑定
         * @param getter - 返回this.number2的函数
         * @param setter - 当绑定值修改时调用的回调
         * @returns 可变的MutableBinding<number>对象
         *
         * 特点：
         * 1. 支持读取和写入操作
         * 2. 修改.value时会自动调用setter回调
         */
        UIUtils.makeBinding<number>(
          () => this.number2, // GetterCallback
          (val: number) => {
            this.number2 = val;
          }) // SetterCallback
      )
    }
  }
}
```

### addMonitor<sup>20+</sup>
static addMonitor(target: object, path: string | string[], monitorCallback: MonitorCallback, options?: MonitorOptions): void

给状态管理V2的状态变量动态添加监听方法，详见[addMonitor/clearMonitor](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| target | object | 是   | 目标对象，仅支持[\@ComponentV2](../../ui/state-management/arkts-new-componentV2.md)和[\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)实例。</br>对于不支持的类型，会抛出运行时错误，错误码见表格。 |
| path | string \| string[]    | 是   | 添加监听的变量名路径。可指定一个路径或者传入string数组用于一次性指定多个监听的变量路径。</br>仅支持string和string数组，对于不支持的类型，会抛出运行时错误，错误码见表格。 |
| monitorCallback | [MonitorCallback](#monitorcallback20)   | 是   | 给对应的状态变量注册的监听函数，即path路径对应的状态变量改变时，会回调对应的函数。</br>对于不支持的类型，会抛出运行时错误，错误码见表格。 |
| options | [MonitorOptions](#monitoroptions20)   | 否   | 监听函数的配置项，具体可见[MonitorOptions](#monitoroptions20)。 |


**错误码：**
以下错误码的详细介绍请参见[状态管理错误码](./errorcode-stateManagement.md)。
| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
|130000|The target is not a custom component instance or V2 class instance.|
|130001|The path is invalid.|
|130002|monitorCallback is not a function or an anonymous function.|

**示例：**
下面的示例：
1. 在`ObservedClass`的构造方法里，添加对`name`属性的同步监听回调`onChange`。
2. 点击Text组件，将`name`改为`Jack`和`Jane`，触发两次`onChange`回调，打印日志如下。
<!--code_no_check-->
```
ObservedClass property name change from Tom to Jack
ObservedClass property name change from Jack to Jane
```

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class ObservedClass {
  @Trace name: string = 'Tom';

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`ObservedClass property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    // 给当前ObservedClass的实例this添加对属性name的监听回调this.onChange，且当前监听回调是同步监听
    UIUtils.addMonitor(this, 'name', this.onChange, { isSynchronous: true });
  }
}

@Entry
@ComponentV2
struct Index {
  @Local observedClass: ObservedClass = new ObservedClass();

  build() {
    Column() {
      Text(`name: ${this.observedClass.name}`)
        .fontSize(20)
        .onClick(() => {
          this.observedClass.name = 'Jack';
          this.observedClass.name = 'Jane';
        })
    }
  }
}
```

### clearMonitor<sup>20+</sup>
static clearMonitor(target: object, path: string | string[], monitorCallback?: MonitorCallback): void

删除通过[addMonitor](#addmonitor20)给状态管理V2的状态变量添加的监听方法，详见[addMonitor/clearMonitor](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| target | object | 是   | 目标对象，仅支持[\@ComponentV2](../../ui/state-management/arkts-new-componentV2.md)和[\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)实例。</br>对于不支持的类型，会抛出运行时错误，错误码见表格。 |
| path | string \| string[]   | 是   | 删除监听的变量名路径。可指定一个路径或者传入string数组用于一次性指定删除多个状态变量的监听函数。</br>仅支持string和数组，对于不支持的类型，会抛出运行时错误，错误码见表格。 |
| monitorCallback | [MonitorCallback](#monitorcallback20)   | 否   | 指定被删除的监听函数。</br>当开发者不传此参数时，将删除path对应变量注册的所有监听函数。</br>对于不支持的类型，会抛出运行时错误，错误码见表格。 |

**错误码：**
以下错误码的详细介绍请参见[状态管理错误码](./errorcode-stateManagement.md)。
| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
|130000|The target is not a custom component instance or V2 class instance.|
|130001|The path is invalid.|
|130002|monitorCallback is not a function or an anonymous function.|

**示例：**
在下面的示例中：
1. 在`ObservedClass`的构造方法中，添加对`age`属性的同步监听回调`onChange`。
2. 点击Text组件，触发`age`自增，`onChange`的监听回调函数被触发。打印日志如下。
<!--code_no_check-->
```
ObservedClass property age change from 10 to 11
```
3. 点击`clear monitor`，删除`age`的监听函数`onChange`。
4. 再次点击Text组件，触发`age`自增，`onChange`不会被触发。

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class ObservedClass {
  @Trace age: number = 10;

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`ObservedClass property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    // 给当前ObservedClass的实例this添加对属性name的监听回调this.onChange，且当前监听回调是同步监听
    UIUtils.addMonitor(this, 'age', this.onChange);
  }
}

@Entry
@ComponentV2
struct Index {
  @Local observedClass: ObservedClass = new ObservedClass();

  build() {
    Column() {
      Text(`age: ${this.observedClass.age}`)
        .fontSize(20)
        .onClick(() => {
          // 点击触发age++，触发onChange回调
          this.observedClass.age++;
        })
      Button('clear monitor')
        .onClick(() => {
          // 点击clearMonitor，删除this.observedClass中age的监听函数onChange
          // 再次点击触发age++，没有触发监听函数onChange
          UIUtils.clearMonitor(this.observedClass, 'age', this.observedClass.onChange);
        })
    }
  }
}
```

## MonitorOptions<sup>20+</sup>

[addMonitor](#addmonitor20)的可选参数，用于配置回调类型。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明     |
| ------ | ---- | ---- | ---- | ------------ |
|isSynchronous|boolean|否|是|配置当前回调函数否是为同步回调。true为同步回调。默认值为false，即异步回调。|

## MonitorCallback<sup>20+</sup>
type MonitorCallback = (monitorValue: IMonitor) => void

参数为[IMonitor](./arkui-ts/ts-state-management-watch-monitor.md#imonitor12)类型的监听回调函数。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| monitorValue | IMonitor | 是   | 回调函数传入的变化信息。 |

## StorageDefaultCreator\<T\>

type StorageDefaultCreator\<T\> = () => T

返回默认构造器的函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
|   T  | 默认构造器执行得到的返回值。 |

**示例：**

```ts
import { PersistenceV2 } from '@kit.ArkUI';

@ObservedV2
class SampleClass {
  @Trace id: number = 0;
  count: number = 1;
}

@ObservedV2
class FatherSampleClass {
  @Trace sampleClass: SampleClass = new SampleClass();
}

// 将key为SampleClass、value为new SampleClass()对象的键值对持久化，并赋值给source
// StorageDefaultCreator 指的是 () => new FatherSampleClass()
const source: FatherSampleClass | undefined = PersistenceV2.connect(FatherSampleClass, () => new FatherSampleClass());

@Entry
@Component
struct SampleComp {
  data: FatherSampleClass | undefined = source;

  build() {
    Column() {
      Text(`${this.data?.sampleClass.id}`)
    }
  }
}
```

## TypeConstructorWithArgs\<T\>

含有任意入参的类构造器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### new

new(...args: any): T

创建并返回一个指定类型T的实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| ...args | any    | 是   | 函数入参。   |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| T    | T类型的实例。 |

**示例：**

```ts
import { PersistenceV2 } from '@kit.ArkUI';

@ObservedV2
  // TypeConstructorWithArgs 指的是 SampleClass
class SampleClass {
  @Trace id: number = 0;
  count: number = 1;
}

@ObservedV2
class FatherSampleClass {
  @Trace sampleClass: SampleClass = new SampleClass();
}

// 将key为SampleClass、value为new SampleClass()对象的键值对持久化，并赋值给source
const source: FatherSampleClass | undefined = PersistenceV2.connect(FatherSampleClass, () => new FatherSampleClass());

@Entry
@Component
struct SampleComp {
  data: FatherSampleClass | undefined = source;

  build() {
    Column() {
      Text(`${this.data?.sampleClass.id}`)
    }
  }
}
```

## PersistenceErrorCallback

type PersistenceErrorCallback = (key: string, reason: 'quota' | 'serialization' | 'unknown', message: string) => void

持久化失败时返回错误原因的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| key | string    | 是   | 出错的键值。   |
|reason| 'quota' \| 'serialization' \| 'unknown'    | 是   | 出错的原因类型。   |
| message | string    | 是   | 出错的更多消息。   |

**示例：**

```ts
import { PersistenceV2, Type } from '@kit.ArkUI';

@ObservedV2
class SampleChild {
  @Trace id: number = 0;
  count: number = 10;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace sampleChild: SampleChild = new SampleChild();
}

// 接受序列化失败的回调
// PersistenceErrorCallback 指的是 (key: string, reason: string, msg: string) => {console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);}
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@Entry
@ComponentV2
struct Index {
  // 在PersistenceV2中创建一个key为Sample的键值对（如果存在，则返回PersistenceV2中的数据），并且和data关联
  // 对于需要换connect对象的data属性，需要加@Local修饰（不建议对属性换connect的对象）
  @Local data: Sample = PersistenceV2.connect(Sample, () => new Sample())!;
  pageStack: NavPathStack = new NavPathStack();

  build() {
    Text(`Index add 1 to data.id: ${this.data.sampleChild.id}`)
      .fontSize(30)
      .onClick(() => {
        this.data.sampleChild.id++;
      })
  }
}
```

## TypeConstructor\<T\>

类构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### new

new(): T

创建并返回一个指定类型T的实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| T    | T类型的实例。 |

**示例：**

```ts
import { PersistenceV2, Type } from '@kit.ArkUI';

@ObservedV2
class SampleChild {
  @Trace id: number = 0;
  count: number = 10;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  // TypeConstructor 指的是 SampleChild
  @Type(SampleChild)
  @Trace sampleChild: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Index {
  data: Sample = PersistenceV2.connect(Sample, () => new Sample())!;

  build() {
    Column() {
      Text(`Index add 1 to data.id: ${this.data.sampleChild.id}`)
        .fontSize(30)
        .onClick(() => {
          this.data.sampleChild.id++;
        })
    }
  }
}
```

## TypeDecorator

type TypeDecorator = \<T\>(type: TypeConstructor\<T\>) => PropertyDecorator

属性装饰器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| type | [TypeConstructor\<T\>](#typeconstructort)    | 是   | 标记类属性的类型。   |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| PropertyDecorator    | 属性装饰器。 |

**示例：**

```ts
import { PersistenceV2, Type } from '@kit.ArkUI';

@ObservedV2
class SampleChild {
  @Trace id: number = 0;
  count: number = 10;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  // TypeDecorator 指的是 @Type
  @Type(SampleChild)
  @Trace sampleChild: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Index {
  data: Sample = PersistenceV2.connect(Sample, () => new Sample())!;

  build() {
    Column() {
      Text(`Index add 1 to data.id: ${this.data.sampleChild.id}`)
        .fontSize(30)
        .onClick(() => {
          this.data.sampleChild.id++;
        })
    }
  }
}
```

## GetterCallback<sup>20+</sup>

type GetterCallback\<T\> = () => T

获取值的回调方法。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| T    | T类型的值。 |

**示例：**

```ts
import { Binding, MutableBinding, UIUtils } from '@kit.ArkUI';

@Builder
function CustomButton(num1: Binding<number>) {
  Row() {
    Button(`Custom Button: ${num1.value}`)
      .onClick(() => {
        // num1.value += 1; 会报错，Binding类型不支持修改
      })
  }
}

@Entry
@ComponentV2
struct CompV2 {
  @Local number1: number = 5;
  @Local number2: number = 10;

  build() {
    Column() {
      Text('parent component')

      CustomButton(
        // 对于UIUtils.makeBinding函数的第一个参数需要传入GetterCallback
        UIUtils.makeBinding<number>(
          () => this.number1 // GetterCallback
        )
      )
    }
  }
}
```

## SetterCallback<sup>20+</sup>

type SetterCallback\<T\> = (newValue: T) => void

设置值的回调方法。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| newValue | T    | 是   | 类型为T的参数。   |

**示例：**

```ts
import { Binding, MutableBinding, UIUtils } from '@kit.ArkUI';

@Builder
function CustomButton(num2: MutableBinding<number>) {
  Row() {
    Button(`Custom Button: ${num2.value}`)
      .onClick(() => {
        // MutableBinding支持可变，可以修改num2.value
        num2.value += 1;
      })
  }
}

@Entry
@ComponentV2
struct CompV2 {
  @Local number1: number = 5;
  @Local number2: number = 10;

  build() {
    Column() {
      Text('parent component')

      CustomButton(
        // 对于UIUtils.makeBinding函数的第二个参数需要传入SetterCallback
        UIUtils.makeBinding<number>(
          () => this.number2, // GetterCallback
          (val: number) => {
            this.number2 = val;
          }) // SetterCallback 必须提供，否则触发时会造成运行时错误
      )
    }
  }
}
```

## Binding\<T\><sup>20+</sup>

只读数据绑定的泛型类，可以绑定任意类型的数据。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### value<sup>20+</sup>
get value(): T

提供get访问器，用于获取绑定的值。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型             | 说明                                                         |
| -------------------- | ------------------------------------------------------------ |
| T |返回值类型为泛型参数T，与Binding\<T\>定义的类型一致。|

**示例：**

```ts
import { Binding, MutableBinding, UIUtils } from '@kit.ArkUI';

@Builder
function CustomButton(num1: Binding<number>) {
  // CustomButton的第一个参数为Binding，一个只读数据绑定的泛型类
  Row() {
    // num1.value Binding类可以使用绑定的值
    Button(`Custom Button: ${num1.value}`)
      .onClick(() => {
        // num1.value += 1; 会报错，只读数据绑定的泛型类不能修改值
      })
  }
}

@Entry
@ComponentV2
struct CompV2 {
  @Local number1: number = 5;
  @Local number2: number = 10;

  build() {
    Column() {
      Text('parent component')

      CustomButton(
        UIUtils.makeBinding<number>(
          () => this.number1 // GetterCallback
        )
      )
    }
  }
}
```

## MutableBinding\<T\><sup>20+</sup>

可变数据绑定的泛型类，允许对绑定值进行读写操作，提供完整的get和set访问器。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### value<sup>20+</sup>
set value(newValue: T)

提供set访问器，用于设置当前绑定值的值。构造MutableBinding类实例时必须提供set访问器，否则触发set访问器会造成运行时错误。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| newValue  | T | 是   | 参数类型为泛型参数T，与MutableBinding\<T\>定义的类型一致。 |

### value<sup>20+</sup>
get value(): T

提供get访问器，用于获取当前绑定值。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型             | 说明                                                         |
| -------------------- | ------------------------------------------------------------ |
| T |返回值类型为泛型参数T，与Binding\<T\>定义的类型一致。|

**示例：**

```ts
import { Binding, MutableBinding, UIUtils } from '@kit.ArkUI';

@Builder
function CustomButton(num2: MutableBinding<number>) {
  // CustomButton的第二个参数为MutableBinding，一个可变数据绑定的泛型类
  Row() {
    Button(`Custom Button: ${num2.value}`)
      .onClick(() => {
        // 可变数据绑定的泛型类可以修改绑定的值
        num2.value += 1;
      })
  }
}

@Entry
@ComponentV2
struct CompV2 {
  @Local number1: number = 5;
  @Local number2: number = 10;

  build() {
    Column() {
      Text('parent component')

      CustomButton(
        UIUtils.makeBinding<number>(
          () => this.number2, // GetterCallback
          (val: number) => {
            this.number2 = val;
          }) // SetterCallback 必须提供，否则触发时会造成运行时错误
      )
    }
  }
}
```