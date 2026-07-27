# @ohos.arkui.StateManagement (状态管理)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926; @liwenzhen3-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

状态管理模块具备应用数据存储、持久化管理以及UIAbility（包含用户界面的应用组件）数据存储能力，同时覆盖环境状态、工具和UI状态同步等场景，从而帮助开发者简化状态管理逻辑，提升应用的响应能力和数据一致性。

>**说明：**
>
> - 本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。


本文中T和S的含义如下：


| 类型   | 说明                                     |
| ---- | -------------------------------------- |
| T    | Class、number、boolean、string和这些类型的数组形式。 |
| S    | number、boolean、string。                 |


## 导入模块

```ts
import { AppStorageV2, PersistenceV2, UIUtils } from '@kit.ArkUI';
```

## AppStorageV2

AppStorageV2提供应用级全局共享状态变量的能力，开发者可以通过connect绑定同一个key，进行跨Ability的数据共享。具体UI使用说明，详见[AppStorageV2(应用全局的UI状态存储)](../../ui/state-management/arkts-new-appstoragev2.md)。

### connect

static&nbsp;connect\<T extends object\>( <br>
  &nbsp;&nbsp;&nbsp;&nbsp;type:&nbsp;TypeConstructorWithArgs\<T\>, <br>
  &nbsp;&nbsp;&nbsp;&nbsp;keyOrDefaultCreator?:&nbsp;string&nbsp;|&nbsp;StorageDefaultCreator\<T\>, <br>
  &nbsp;&nbsp;&nbsp;&nbsp;defaultCreator?:&nbsp;StorageDefaultCreator\<T\> <br>
):&nbsp;T&nbsp;|&nbsp;undefined

将键值对数据存储在应用内存中。如果给定的key已经存在于[AppStorageV2](../../ui/state-management/arkts-new-appstoragev2.md)中，返回对应的值；否则，通过获取默认值的构造器构造默认值，并返回。

> **说明：**
>
> 1、若未指定key，使用第二个参数作为默认构造器；否则使用第三个参数（第二个参数非法也使用第三个参数作为默认构造器）。
>
> 2、确保数据已经存储在AppStorageV2中，可省略默认构造器，获取存储的数据；否则必须指定默认构造器，不指定将导致应用异常。
>
> 3、同一个key，connect不同类型的数据会导致应用异常，应用需要确保类型匹配。
>
> 4、key建议使用有意义的值，可由字母、数字、下划线组成，长度不超过255个字符，使用非法字符或空字符的行为是未定义的。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| type | [TypeConstructorWithArgs\<T\>](#typeconstructorwithargst) | 是   | 指定的类型，若未指定key，则使用type的name作为key。 |
| keyOrDefaultCreator | string&nbsp;\|&nbsp;[StorageDefaultCreator\<T\>](#storagedefaultcreatort) | 否   | 指定的key，或者是获取默认值的构造器。默认值为undefined。 |
| defaultCreator | [StorageDefaultCreator\<T\>](#storagedefaultcreatort) | 否   | 获取默认值的构造器。默认值为undefined。如果数据未存储在AppStorageV2中，且没有传递默认构造器，则返回undefined。 |

**返回值：**

| 类型                                   | 说明                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| T \| undefined | 创建或获取AppStorageV2数据成功时，返回数据；否则返回undefined。 |

**示例：**

```ts
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
class SampleClass {
  @Trace value: number = 0;
}

// 将key为SampleClass、value为new SampleClass()对象的键值对存储到内存中，并赋值给sampleData1
const sampleData1: SampleClass | undefined = AppStorageV2.connect(SampleClass, () => new SampleClass());

// 将key为key_as2、value为new SampleClass()对象的键值对存储到内存中，并赋值给sampleData2
const sampleData2: SampleClass = AppStorageV2.connect(SampleClass, 'key_as2', () => new SampleClass())!;

// key为SampleClass已经在AppStorageV2中，将key为SampleClass的值返回给sampleData3
const sampleData3: SampleClass = AppStorageV2.connect(SampleClass) as SampleClass;
```

### remove

static&nbsp;remove\<T\>(keyOrType:&nbsp;string&nbsp;|&nbsp;TypeConstructorWithArgs\<T\>):&nbsp;void

将指定的键值对数据从[AppStorageV2](../../ui/state-management/arkts-new-appstoragev2.md)里面删除。如果指定的键值不存在于AppStorageV2中，将删除失败。

> **说明：**
>
> 删除AppStorageV2中不存在的key会报警告。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| keyOrType | string \| [TypeConstructorWithArgs](#typeconstructorwithargst)\<T\> | 是   | 需要删除的key；如果指定的是type类型，删除的key为type的name。 |


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

> **说明：**
>
> key在Array中的顺序是无序的，与key插入到AppStorageV2中的顺序无关。


**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                   | 说明                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| Array\<string\> | 所有AppStorageV2中的key。 |

**示例：**

```ts
// 假设AppStorageV2中存在两个key（key_as1、key_as2），返回[key_as1、key_as2]赋值给keys
const keys: Array<string> = AppStorageV2.keys();
```



## PersistenceV2

继承自[AppStorageV2](#appstoragev2)，PersistenceV2提供UI状态的持久化存储能力，支持将应用状态数据持久化到磁盘，在应用重启后恢复数据，适用于需要保留UI状态数据的场景。具体UI使用说明，详见[PersistenceV2(持久化存储UI状态)](../../ui/state-management/arkts-new-persistencev2.md)。

### globalConnect<sup>18+</sup>

static globalConnect\<T extends object\>(type: ConnectOptions\<T\>): T | undefined

将键值对数据存储在应用磁盘中。如果给定的key已经存在于[PersistenceV2](../../ui/state-management/arkts-new-persistencev2.md)中，返回对应的值；否则，会通过获取默认值的构造器构造默认值，并返回。如果通过globalConnect连接的对象是[\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)对象，该对象[\@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md)属性的变化，会触发整个关联对象的自动刷新；非\@Trace属性变化则不会自动持久化，如需持久化非\@Trace属性的变化，可调用[PersistenceV2.save](#save)接口手动存储。

> **说明：**
>
> 1、若未指定key，使用默认构造器defaultCreator返回数据的类名作为key存入PersistenceV2中。
>
> 2、确保数据已经存储在PersistenceV2中，可省略默认构造器，获取存储的数据；否则必须指定默认构造器，不指定将导致应用异常。
>
> 3、同一个key，globalConnect不同类型的数据会导致应用异常，应用需要确保类型匹配。
>
> 4、key建议使用有意义的值，可由字母、数字、下划线组成，长度不超过255个字符，使用非法字符或空字符的行为是未定义的。
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

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   |类型   |必填   | 说明                                                      |
| ------------- | ------------|-------------------|-------------------------- |
| type    |[ConnectOptions\<T\>](#connectoptionst18)    |是  | globalConnect的配置参数，包含指定的类型、key、默认构造器和加密级别等配置项，详细说明见ConnectOptions参数说明。 |

**返回值：**

|类型   |说明                 |
|----------|-----------------------------------|
|T \| undefined    |创建或获取数据成功时，返回数据；否则返回undefined。    |

**示例：**
仅供开发者了解globalConnect用法，完整使用需开发者自行编写@Entry组件。

<!--code_no_check-->
```ts
import { PersistenceV2, Type } from '@kit.ArkUI';
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
const persistedSample: Sample = PersistenceV2.globalConnect({ type: Sample, defaultCreator: () => new Sample() })!;

// 使用key:global1连接，传入加密等级为EL1
const persistedSample1: Sample = PersistenceV2.globalConnect({
  type: Sample,
  key: 'global1',
  defaultCreator: () => new Sample(),
  areaMode: contextConstant.AreaMode.EL1
})!;

// 使用key:global2连接，使用构造函数形式，加密参数不传入默认加密等级为EL2
const persistedSample2: Sample = PersistenceV2.globalConnect({ type: Sample, key: 'global2', defaultCreator: () => new Sample() })!;

// 使用key:global3连接，直接写加密数值，范围只能在0-4，否则运行会crash，例如加密设置为EL4
const persistedSample3: Sample = PersistenceV2.globalConnect({
  type: Sample,
  key: 'global3',
  defaultCreator: () => new Sample(),
  areaMode: 3
})!;

```
### globalConnect<sup>23+</sup>

static globalConnect\<T extends CollectionType<S\>, S extends object\>( <br>
  &nbsp;&nbsp;&nbsp;&nbsp;type: ConnectOptionsCollections\<T, S\> | ConnectOptions\<T\> <br>
): T | undefined

将键值对数据存储在应用磁盘中。支持集合类型[`Array`，`Map`，`Set`，`collections.Array`，`collections.Map`，`collections.Set`类型的持久化](../../ui/state-management/arkts-new-persistencev2.md#globalconnect支持集合的类型)。注意在持久化`Array<ClassA>`类型的数据时，需要调用[`makeObserved`](#makeobserved)使返回的对象被观察到。不支持多个嵌套集合，例如不支持`Array<Array<ClassA>>`的持久化。

> **说明：**
>
> 1、若未指定key，使用默认构造器defaultCreator返回数据的类名作为key存入PersistenceV2中。
>
> 2、key建议使用有意义的值，可由字母、数字、下划线组成，长度不超过255，使用非法字符或空字符的行为是未定义的。
>
> 3、connect和globalConnect不建议混用，因为数据副本路径不同，如果混用，则key不可以一样，否则会crash。
>
> 其他通用条件详见globalConnect<sup>18+</sup>的说明。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| type | [ConnectOptionsCollections\<T, S\>](#connectoptionscollectionst-s23) \| [ConnectOptions\<T\>](#connectoptionst18) |  是   | globalConnect的配置参数，支持ConnectOptions和ConnectOptionsCollections两种类型，包含类型、key、默认构造器、集合项构造器等配置项，详细说明见ConnectOptions和ConnectOptionsCollections参数说明。<br>当开发者在ConnectOptionsCollections中提供默认defaultSubCreator时，则需要同时提供默认创建器defaultCreator，如果不提供，会导致持久化失败。且集合项类型S必须与defaultSubCreator的返回类型相同。如果返回类型不一致，编译会报错。|  

当开发者在`globalConnect`中使用`defaultSubCreator`选项时，必须要提供`defaultCreator`。且`defaultSubCreator`函数的返回类型必须与`defaultCreator`返回的集合项类型相同。<br>当`globalConnect`持久化`Array<ClassA>`类型的数据时，开发者需要使用`defaultSubCreator`选项去告诉状态管理框架创建`ClassA`类的一个实例。如下是`globalConnect`持久化`Array<ClassA>`类型的数据的示例：

<!--code_no_check-->
```typescript
class ClassA {
  propA: number;
  // ...
}

@ComponentV2
struct Page1 {
  // 顶层持久化数据类型为Array<ClassA>
  @Local arr: Array<ClassA> = PersistenceV2.globalConnect({
    type: Array<ClassA>,
    defaultCreator: () => UIUtils.makeObserved(new Array<ClassA>()),
    // 添加defaultSubCreator，通知状态管理框架如何创建ClassA对象
    // 另外持久化后的数据需要加上makeObserved，否则会持久化失败
    defaultSubCreator: () => UIUtils.makeObserved(new ClassA())
  })!;
  // ...
}
```

**返回值：**

|类型   |说明                 |
|----------|-----------------------------------|
|T \| undefined    |创建或获取数据成功时，返回数据；否则返回undefined。    |

**示例：**

如下展示globalConnect持久化Map类型的示例代码：
```typescript
import { PersistenceV2 } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Page1 {
  // globalConnect支持持久化Map类型的数据
  @Local map: Map<number, number> = PersistenceV2.globalConnect({
    type: Map<number, number>, defaultCreator: () => new Map<number, number>()
  })!;
  output: string[] = [];

  // 启动应用，第一次进入，展示restored Map.size=0, map.get(0)=undefined, map.get(1)=undefined, map.get(2)=undefined
  // 关闭应用，第二次进入，展示restored Map.size=1, map.get(0)=0, map.get(1)=undefined, map.get(2)=undefined
  // 关闭应用，第三次进入，展示restored Map.size=2, map.get(0)=0, map.get(1)=1, map.get(2)=undefined
  // 关闭应用，第四次进入，展示restored Map.size=3, map.get(0)=0, map.get(1)=1, map.get(2)=2
  aboutToAppear(): void {
    const restoredMapSize = this.map.size;
    this.output.push(`restored Map.size=${restoredMapSize}, map.get(0)=${this.map.get(0)}, map.get(1)=${this.map.get(1)}, map.get(2)=${this.map.get(2)}`);
    this.map.set(restoredMapSize, restoredMapSize);
    // 需要手工持久化
    PersistenceV2.save('Map');
  }

  build() {
    Column() {
      Row() {
        Text(this.output.join('\n\n'))
          .fontSize(24)
      }
    }
    .width('100%')
  }
}
```
### save

static&nbsp;save\<T\>(keyOrType:&nbsp;string&nbsp;|&nbsp;TypeConstructorWithArgs\<T\>):&nbsp;void

将指定的键值对数据持久化一次。

> **说明：**
>
> 由于非[\@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md)的数据改变不会触发[PersistenceV2](../../ui/state-management/arkts-new-persistencev2.md)的自动持久化，当非\@Trace的数据发生变化且需要持久化时，可调用该接口持久化对应key的数据。
>
> 手动持久化当前内存中不处于connect状态的key是无意义的。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| keyOrType | string \| [TypeConstructorWithArgs\<T\>](#typeconstructorwithargst) | 是   | 需要持久化的key；如果指定的是type类型，持久化的key为type的name。 |

**示例：**

<!--code_no_check-->

```ts
@ObservedV2
class SampleClass {
  @Trace value: number = 0;
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

注册持久化失败时的回调函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| callback | [PersistenceErrorCallback](#persistenceerrorcallback) \| undefined  | 是   | 持久化失败时的回调函数。回调参数包括：key（出错的键值）、reason（出错原因类型，取值为'quota'、'serialization'或'unknown'）、message（出错的详细信息）和oldValue（反序列化失败时返回的旧数据，可选）。 |

**示例：**

```ts
// 持久化失败时调用
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});
```

## ConnectOptions\<T\><sup>18+</sup>

globalConnect参数类型。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|名称   |类型    |只读   |可选    |说明      |
|--------|------------|------------|-----------|--------------|
|type        | [TypeConstructorWithArgs\<T\>](#typeconstructorwithargst)   |否   |否   |指定的类型。         |
|key         | string   |否   |是   |传入的key，不传则使用type的名字作为key。             |
|defaultCreator   | [StorageDefaultCreator\<T\>](#storagedefaultcreatort)   |否   |是   |默认数据的构造器，建议传递，如果globalConnect是第一次连接key，不传会报错。 |
|areaMode      | [contextConstant.AreaMode](../apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode)   |否   |是    |加密级别：EL1-EL5，对应数值：0-4，详见[加密级别](../../application-models/application-context-stage.md#获取和修改加密分区)。不传时默认为EL2，不同加密级别对应不同的加密分区，即不同的存储路径，传入的加密级别数值不在0-4会直接运行crash。同一个key使用不同的加密级别时，以第一次globalConnect的加密级别为准。 |

## ConnectOptionsCollections\<T, S\><sup>23+</sup>

[globalConnect](#globalconnect23)接口参数类型，ConnectOptionsCollections继承自[ConnectOptions\<T\>](#connectoptionst18)。当开发者需要持久化容器类型数据（如`Array<S>`）时，需要使用`ConnectOptionsCollections`入参。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

|名称   |类型    |只读   |可选    |说明      |
|--------|------------|------------|-----------|--------------|
|defaultCreator   | [StorageDefaultCreator\<T\>](#storagedefaultcreatort)   |否   |是   | 用于持久化容器类型数据，当提供默认`defaultSubCreator`时，则需要同时提供默认构造器`defaultCreator`，不提供默认构造器会导致持久化失败。集合项类型`S`必须与`defaultSubCreator`的返回类型相同。 |
|defaultSubCreator   | StorageDefaultCreator\<S\> |否   |是   | 使用该集合项默认构造函数，用于持久化容器类数据。使用此参数时，必须同时提供`defaultCreator`，否则会导致持久化失败。如果defaultSubCreator返回的是`undefined`或`null`时，会导致持久化失败。 当持久化用户自定义class类集合（如`Array<ClassA>`）时，`defaultCreator`中的泛型类型`T`为`Array<ClassA>`，则`defaultSubCreator`中的泛型类型`S`为`ClassA`。|

如下展示`StorageDefaultCreator<T>`和`StorageDefaultCreator<S>`示例：

**示例：**
<!--code_no_check-->
```typescript
class ClassA {
  propA: number;
  // ...
}

@ComponentV2
struct Page {
  // StorageDefaultCreator<T>默认创建器为`() => UIUtils.makeObserved(new Array<ClassA>())`, 其中`T`的类型是指`Array<ClassA>`
  // StorageDefaultCreator<S> 默认创建器为`() =>UIUtils.makeObserved(new ClassA())`，其中，`S`的类型是指`ClassA`
  @Local arr: Array<ClassA> = PersistenceV2.globalConnect({
    type: Array<ClassA>,
    defaultCreator: () => UIUtils.makeObserved(new Array<ClassA>()),
    // 添加defaultSubCreator，通知状态管理框架如何创建ClassA对象
    // 另外持久化后的数据需要加上makeObserved，否则会持久化失败
    defaultSubCreator: () => UIUtils.makeObserved(new ClassA())
  })!
  // ...
}
```

当`StorageDefaultCreator<S>`返回值为`undefined`或`null`时，持久化会失败。当`StorageDefaultCreator<S>`直接设置为`undefined`或`null`时，状态管理框架会按照原始的类型（如`Object`类型）进行持久化，但是会丢失`class`对象中的方法。在如下示例中，`StorageDefaultCreator<S>`直接被设置为`undefined`或`null`时，持久化过程中`ClassA`对象中的`report`方法将被丢失。

```typescript
import { PersistenceV2, UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class ClassA {
  @Trace public propA: string = '';
  @Trace public propB: string = '';

  public report(): string {
    return `${this.propA} - ${this.propB}`;
  }
}

@Entry
@ComponentV2
struct Comp {
  // 持久化顶层数据类型为`Array<ClassA>`的数据。
  @Local arr: Array<ClassA> = PersistenceV2.globalConnect({
    type: Array<ClassA>,
    defaultCreator: () => UIUtils.makeObserved(new Array<ClassA>()),
    // defaultSubCreator的返回的值被设置为`undefined`或`null` (defaultSubCreator: () => undefined)，持久化失败。
    // defaultSubCreator被直接设置为`undefined`或`null` (defaultSubCreator: undefined)，持久化会丢失`ClassA`中的方法。
    defaultSubCreator: undefined
  })!;

  aboutToAppear(): void {
    if (this.arr.length) {
      // 步骤3：再次进入应用，持久化过程中丢失`ClassA中`的方法，当调用`ClassA`对象中的`report`方法，会报`undefined is not callable`的错误。
      hilog.info(0xFF00, 'testTag', '%{public}s', this.arr[0].report());
    }
  }
  build() {
    Column() {
      Repeat(this.arr)
        .each(ri => {
          Row() {
            Text(`propA '${ri.item.propA}'`)
            Text(`propB '${ri.item.propB}'`)
            Text(`report?.() '${ri.item.report?.()}'`)
          }
        })
      // 步骤1：点击'add item'，显示`propA 'a' propB 'b' report?.() 'a - b'`。
      // 步骤2：关闭应用。
      Button('add item')
        .onClick(() => {
          let temp: ClassA = new ClassA();
          temp.propA = 'a';
          temp.propB = 'b';
          this.arr.push(temp);
        })
    }
  }
}
```

## CollectionType<sup>23+</sup>

type CollectionType\<S\> = Array\<S\> | Map\<string | number, S\> |
Set\<S\> | collections.Array\<S\> | collections.Map\<string | number, S\> | collections.Set\<S\>

globalConnect的入参泛型，用于定义globalConnect支持的持久化集合数据类型。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

| 类型 | 说明                       |
| ---- | -------------------------- |
| Array\<S\>     | 表示值类型为Array类型。 |
| Map\<string \| number, S\>     | 表示值类型为Map类型。 |
|Set\<S\>     | 表示值类型为Set类型。 |
|[collections.Array](../apis-arkts/arkts-apis-arkts-collections-Array.md)\<S\>     | 表示值类型为collections.Array类型。 |
|[collections.Map](../apis-arkts/arkts-apis-arkts-collections-Map.md)\<string \| number, S\>     | 表示值类型为collections.Map类型。 |
|[collections.Set](../apis-arkts/arkts-apis-arkts-collections-Set.md)\<S\>     | 表示值类型为collections.Set类型。 |

## ObservedResult<sup>23+</sup>

对象是否可被观察的结果。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读  |可选 | 说明     |
| ------ | ---- | ---- | ---- | ------------ |
| isObserved | boolean  | 否 |  否   | 对象是否可被观察。<br>true：表示是可被观察对象。<br>false：表示不是可被观察对象。 |
| reason | string  | 否 | 否   | 对象是否可被观察的原因。<br>不可被观察原因：对象本身是不可被观察的。<br>可被观察原因或使用场景：<br> 1. V1对象被[@Observed](./../../ui/state-management/arkts-observed-and-objectlink.md)装饰器装饰或对象是被[makeV1Observed](#makev1observed19)方法转换的。 <br> 2. V1对象被[@Observed](./../../ui/state-management/arkts-observed-and-objectlink.md)装饰器装饰或对象是被[makeV1Observed](#makev1observed19)方法转换的，但对象没有被UI组件使用。 <br> 3. V1对象被[enableV2Compatibility](#enablev2compatibility19)方法转换后传入V2组件。 <br> 4. V1对象被[enableV2Compatibility](#enablev2compatibility19)方法转换后传入V2组件，但没有被V2组件使用。 <br> 5. V2对象是被[@ObservedV2/@Trace](./../../ui/state-management/arkts-new-observedV2-and-trace.md)装饰的。<br> 6. V2对象是被[makeObserved](#makeobserved)方法转换的。 <br> 7. V2对象属于Array/Map/Set/Date类型。 <br> 8. V2对象是被[@ObservedV2/@Trace](./../../ui/state-management/arkts-new-observedV2-and-trace.md)装饰的，但对象没有被UI组件使用。 <br> 9. V2对象是被[makeObserved](#makeobserved)方法转换的，但没有被UI组件使用。 <br> 10. V2对象属于Array/Map/Set/Date类型，但没有被UI组件使用。 |
| decoratorInfo | Array\<[DecoratorInfo](#decoratorinfo23)\>  | 否 | 否   | 对象可被观察时，数组中内容为对象关联的装饰器和组件信息。对象不可被观察时，此数组为空。 |

## DecoratorInfo<sup>23+</sup>

可被观察对象关联的装饰器和组件信息。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读  | 可选 | 说明     |
| ------ | ---- | ---- |---- | ------------ |
| decoratorName | string  | 否 | 否   | 当对象是V1对象时，值是对象关联的装饰器名称。<br> 当V1对象使用[@Track](./../../ui/state-management/arkts-track.md)时，值为：'@Track'。<br> 当V2对象使用[@Trace](./../../ui/state-management/arkts-new-observedV2-and-trace.md)时，值为：'@Trace'。<br> 当V2对象使用[makeObserved](#makeobserved)时，值为：'MakeObserved'。<br> 当V2对象使用[enableV2Compatibility](#enablev2compatibility19)时，值为：'EnableV2Compatible'。 <br> 当V2对象使用built-in类型数据时，值为：'ProxyObservedV2'。 |
| stateVariableName | string  | 否 | 否   | 被装饰器装饰的属性名称。 |
| owningComponentOrClassName | string  | 否 | 否   | V1对象返回被使用的组件名称。<br> V1对象有属性使用[@Track](./../../ui/state-management/arkts-track.md)装饰器时返回对象名称。<br> V2对象返回对象名称。 |
| owningComponentId | number  | 否 | 否   | V1对象返回被使用的组件id。<br> **当V1对象有属性使用[@Track](./../../ui/state-management/arkts-track.md)装饰器时，无组件id，返回-1；V2对象同样无组件id，返回-1。** |
| dependentInfo | Array<[ElementInfo](#elementinfo23)>  | 否 | 否   | 使用该可观察对象的组件信息。若对象没有用在任何UI上，则返回空数组。 |

## ElementInfo<sup>23+</sup>

可被观察对象关联的组件信息，包含系统组件和自定义组件。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读  | 可选 | 说明     |
| ------ | ---- | ---- |---- | ------------ |
| elementName | string  | 否 | 否   | 组件的名称。 |
| elementId | number  | 否 | 否   | 组件的ID。 |

## UIUtils

UIUtils状态管理相关的工具方法，包括获取代理对象的原始对象、将非观察数据变为可观察数据、动态添加和删除状态变量监听、同步刷新状态变量修改、创建数据绑定等，适用于需要手动管理状态观察、监听和同步刷新的场景。

### getTarget

static getTarget\<T extends object\>(source: T): T

从状态管理框架包裹的代理对象中获取原始对象。详见[getTarget接口：获取状态管理框架代理前的原始对象](../../ui/state-management/arkts-new-getTarget.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   |  数据源对象，即被状态管理框架包裹的代理对象，用于获取去除代理后的原始对象。 |

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

### getLifecycle<sup>23+</sup>

static getLifecycle\<T extends BaseCustomComponent\>(customComponent: T): CustomComponentLifecycle

getLifecycle用于获取[自定义组件的生命周期](./arkui-ts/ts-custom-component-new-lifecycle.md)实例。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| customComponent | T    | 是   | 自定义组件实例。 |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| [CustomComponentLifecycle](./arkui-ts/ts-custom-component-new-lifecycle.md#customcomponentlifecycle)    | 自定义组件的生命周期实例。 |

**示例：**

```ts
import { UIUtils, ComponentAppear } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State lifecycleState: number = -1;

  @ComponentAppear
  myAppear() {
    // UIUtils.getLifecycle获得自定义组件的生命周期实例，getCurrentState查询自定义组件当前生命周期。
    // 预期查询到的生命周期为CustomComponentLifecycleState.APPEARED = 1。
    this.lifecycleState = UIUtils.getLifecycle(this).getCurrentState();
  }

  build() {
    Text(`${this.lifecycleState}`)
  }
}
```

### canBeObserved<sup>23+</sup>

static canBeObserved\<T extends object\>(source: T): ObservedResult

判断数据对象是否为可观察对象，并返回观察结果。详见[canBeObserved接口：判断对象是否为可被观察对象](../../ui/state-management/arkts-new-canBeObserved.md)。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   | 输入一个数据对象，判断其是否可被观察。支持Array、Map、Set和Date类型数据。<br>具体使用规则，详见[canBeObserved接口：判断对象是否为可被观察对象](../../ui/state-management/arkts-new-canBeObserved.md)。 |

**返回值：**

| 类型 | 说明     |
| ---- | ------------ |
| [ObservedResult](#observedresult23)  | 返回对象是否可被观察的结果。 |

**示例：**

``` ts
import { UIUtils } from '@kit.ArkUI';
import { DecoratorInfo, ElementInfo } from '@ohos.arkui.StateManagement';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = 'CanBeObserved';

class Student {
  public name?: string;

  constructor(name?: string) {
    this.name = name ?? '';
  }

  // 在对象中提供判断该对象是否为可被观察对象的方法
  test(): void {
    const result = UIUtils.canBeObserved(this);
    // 对象是否可被观察
    const isObserved = result.isObserved;
    hilog.info(0x00, TAG, `isObserved: ${JSON.stringify(isObserved)}`);
    // 对象是否可被观察的原因
    const reason = result.reason;
    hilog.info(0x00, TAG, `reason: ${reason}`);
    // 对象可被观察时，对象关联的装饰器信息
    const decoratorInfoArr = result.decoratorInfo;
    decoratorInfoArr.forEach((decorator: DecoratorInfo) => {
      // 装饰器名称
      const decoratorName = decorator.decoratorName;
      hilog.info(0x00, TAG, `decoratorName: ${decoratorName}`);
      // 装饰器装饰的属性名称
      const stateVariableName = decorator.stateVariableName;
      hilog.info(0x00, TAG, `stateVariableName: ${stateVariableName}`);
      // 装饰器所在的组件名称
      const owningName = decorator.owningComponentOrClassName;
      hilog.info(0x00, TAG, `owningComponentOrClassName: ${owningName}`);
      // 装饰器所在的组件id
      const owningId = decorator.owningComponentId;
      hilog.info(0x00, TAG, `owningComponentId: ${owningId}`);
      // 装饰器关联的组件信息
      const dependentInfo = decorator.dependentInfo;
      dependentInfo.forEach((elementInfo: ElementInfo) => {
        // 装饰器关联的组件名称
        const eleName = elementInfo.elementName;
        hilog.info(0x00, TAG, `elementName: ${eleName}`);
        // 装饰器关联的组件id
        const eleId = elementInfo.elementId;
        hilog.info(0x00, TAG, `elementId: ${eleId}`);
      });
    });
  }
}

@Entry
@Component
struct Index {
  @State student: Student = new Student('LiMei');

  build() {
    Column({ space: 20 }) {
      Classroom({ student: this.student })
      Home({ student: this.student })
      Button('test')
        .onClick(() => {
          // 开发者可以在任意页面中使用接口来判断当前对象是否为可被观察对象
          this.student.test();
        })
    }
    .height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
  }
}

@Component
export struct Classroom {
  @State student: Student = new Student();

  build() {
    Column() {
      Text('Classroom ' + this.student.name)
      School({ student: this.student })
    }
  }
}

@Component
export struct Home {
  @State student: Student = new Student();

  build() {
    Column() {
      Text('Home ' + this.student.name)
    }
  }
}

@Component
export struct School {
  @State student: Student = new Student();

  build() {
    Column() {
      Text('School ' + this.student.name)
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
| source | T    | 是   | 数据源对象。支持非@Observed和@ObservedV2装饰的class，JSON.parse返回的Object和@Sendable修饰的class。<br>支持Array、Map、Set和Date。<br>支持collections.Array、collections.Set和collections.Map。<br>具体使用规则，详见[makeObserved接口：将非观察数据变为可观察数据](../../ui/state-management/arkts-new-makeObserved.md)。 |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| T    | 对于支持的入参类型，返回可观察的数据。对于不支持的入参类型，返回数据源对象本身。 |

**示例：**

```ts
import { UIUtils } from '@kit.ArkUI';

class NonObservedClass {
  name: string = 'Tom';
}

@Entry
@ComponentV2
struct Index {
  // 使用makeObserved将NonObservedClass实例变为可观察对象
  observedClass: NonObservedClass = UIUtils.makeObserved(new NonObservedClass());
  nonObservedClass: NonObservedClass = new NonObservedClass();

  build() {
    Column() {
      Text(`observedClass: ${this.observedClass.name}`)
        .onClick(() => {
          this.observedClass.name = 'Jane'; // 刷新
        })
      Text(`nonObservedClass: ${this.nonObservedClass.name}`)
        .onClick(() => {
          this.nonObservedClass.name = 'Jane'; // 不刷新
        })
    }
  }
}
```

### enableV2Compatibility<sup>19+</sup>

static enableV2Compatibility\<T extends object\>(source: T): T

使V1的状态变量能够在\@ComponentV2中观察，主要应用于状态管理V1、V2混用场景。详见[状态管理V1和V2混用指导（API version 19及之后）](../../ui/state-management/arkts-v1-v2-mixusage.md)。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   | 数据源，仅支持V1状态数据，如被@Observed装饰的对象或被makeV1Observed方法转换的对象。传入非V1状态数据时返回数据源本身。 |

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

该接口可搭配[enableV2Compatibility](#enablev2compatibility19)应用于状态管理V1和V2混用场景，详见[状态管理V1和V2混用指导（API version 19及之后）](../../ui/state-management/arkts-v1-v2-mixusage.md)。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   | 数据源。支持普通class、Array、Map、Set、Date类型。<br>不支持[@arkts.collections (ArkTS容器集)](../apis-arkts/arkts-apis-arkts-collections.md)和[@Sendable](../../arkts-utils/arkts-sendable.md)修饰的class。<br>不支持undefined和null。不支持状态管理V2的数据和[makeObserved](#makeobserved)的返回值。 |

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
  // 使用makeV1Observed将Inner实例包装为V1可观察对象，传入Outer构造函数
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

创建只读的单向数据绑定实例，用于构建[\@Builder](../../ui/state-management/arkts-builder.md)函数中参数类型为`Binding`的对应实参。

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
import { Binding, UIUtils } from '@kit.ArkUI';

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
import { MutableBinding, UIUtils } from '@kit.ArkUI';

@Builder
function CustomButton(num1: MutableBinding<number>) {
  Row() {
    Button(`Custom Button: ${num1.value}`)
      .onClick(() => {
        // MutableBinding类型支持修改
        num1.value += 1;
      })
  }
}

@Entry
@ComponentV2
struct CompV2 {
  @Local number1: number = 10;

  build() {
    Column() {
      Text('parent component')

      CustomButton(
        /**
         * 创建可变绑定
         * @param getter - 返回this.number1的函数
         * @param setter - 当绑定值修改时调用的回调
         * @returns 可变的MutableBinding<number>对象
         *
         * 特点：
         * 1. 支持读取和写入操作
         * 2. 修改.value时会自动调用setter回调
         */
        UIUtils.makeBinding<number>(
          () => this.number1, // GetterCallback
          (val: number) => {
            this.number1 = val;
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
| target | object | 是   | 目标对象，仅支持[\@ComponentV2](../../ui/state-management/arkts-create-custom-components.md#componentv2)和[\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)实例。<br>对于不支持的类型，会抛出运行时错误，错误码见表格。 |
| path | string \| string[]    | 是   | 添加监听的变量名路径。可指定一个路径或者传入string数组用于一次性指定多个监听的变量路径。<br>仅支持string和string数组，对于不支持的类型，会抛出运行时错误，错误码见表格。 |
| monitorCallback | [MonitorCallback](#monitorcallback20)   | 是   | 给对应的状态变量注册的监听函数，即path路径对应的状态变量改变时，会回调对应的函数。<br>对于不支持的类型，会抛出运行时错误，错误码见表格。 |
| options | [MonitorOptions](#monitoroptions20)   | 否   | 监听函数的配置项，具体可见[MonitorOptions](#monitoroptions20)。默认为异步回调。 |


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
```text
ObservedClass property name change from Tom to Jack
ObservedClass property name change from Jack to Jane
```

```Typescript
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
| target | object | 是   | 目标对象，仅支持[\@ComponentV2](../../ui/state-management/arkts-create-custom-components.md#componentv2)和[\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)实例。<br>对于不支持的类型，会抛出运行时错误，错误码见表格。 |
| path | string \| string[]   | 是   | 删除监听的变量名路径。可指定一个路径或者传入string数组用于一次性指定删除多个状态变量的监听函数。<br>仅支持string和数组，对于不支持的类型，会抛出运行时错误，错误码见表格。 |
| monitorCallback | [MonitorCallback](#monitorcallback20)   | 否   | 指定被删除的监听函数。<br>当开发者不传此参数时，将删除path对应变量注册的所有监听函数。<br>对于不支持的类型，会抛出运行时错误，错误码见表格。 |

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
   ```text
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
    // 给当前ObservedClass的实例this添加对属性age的监听回调this.onChange
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

### applySync<sup>22+</sup>

static applySync\<T\>(task: TaskCallback): T

同步刷新指定的状态变量，该接口接收一个闭包函数，仅刷新闭包函数内的修改，包括更新[@Computed计算](../../ui/state-management/arkts-new-computed.md)、[@Monitor回调](../../ui/state-management/arkts-new-monitor.md)以及重新渲染UI节点，详见[applySync/flushUpdates/flushUIUpdates接口：同步刷新](../../ui/state-management/arkts-new-applySync-flushUpdates-flushUIUpdates.md)。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                          | 必填 | 说明                                             |
| ------ | ----------------------------- | ---- | ------------------------------------------------ |
| task   | [TaskCallback](#taskcallback22) | 是   | 闭包函数，该闭包中产生的状态变量修改会同步执行。 |

**返回值：**

| 类型 | 说明                       |
| ---- | -------------------------- |
| T    | 闭包函数执行得到的返回值。 |

**错误码：**

以下错误码的详细介绍请参见[状态管理错误码](./errorcode-stateManagement.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 140001   | The function is not allowed to be called in @Computed. |

**示例：**

```ts
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local columnWidth: number = 50; // 宽度
  @Local columnHeight: number = 50; // 高度
  @Local message: string = 'Hello';

  build() {
    Column() {
      Button('change size')
        .margin(20)
        .onClick(() => {
          // 在执行动画前，存在额外的修改
          UIUtils.applySync(() => {
            this.columnWidth = 100;
            this.columnHeight = 100;
            this.message = 'Hello World';
          });
          // 动画在1s内，Column方框的尺寸由（100*100）渐变为（200*200），方框内的文本变为Hello ArkUI
          this.getUIContext().animateTo({
            duration: 1000
          }, () => {
            console.info(`animateTo-in, width=${this.columnWidth}, height=${this.columnHeight}`);
            this.columnWidth = 200;
            this.columnHeight = 200;
            this.message = 'Hello ArkUI';
            console.info(`animateTo-out, width=${this.columnWidth}, height=${this.columnHeight}`);
          });
        })
      // Column方框
      Column() {
        Text(`${this.message}`)
      }
      .backgroundColor('#ff17a98d')
      .width(this.columnWidth)
      .height(this.columnHeight)
    }
  }
}
```

### flushUpdates<sup>22+</sup>

static flushUpdates(): void

同步刷新在调用该函数之前所有的状态变量修改，包括更新@Computed计算、@Monitor回调以及重新渲染UI节点，详见[applySync/flushUpdates/flushUIUpdates接口：同步刷新](../../ui/state-management/arkts-new-applySync-flushUpdates-flushUIUpdates.md)。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**错误码：**

以下错误码的详细介绍请参见[状态管理错误码](./errorcode-stateManagement.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 140001   | The function is not allowed to be called in @Computed. |
| 140002   | The function is not allowed to be called in @Monitor.  |

**示例：**

```ts
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local columnWidth: number = 50; // 宽度
  @Local columnHeight: number = 50; // 高度
  @Local message: string = 'Hello';

  build() {
    Column() {
      Button('change size')
        .margin(20)
        .onClick(() => {
          // 在执行动画前，存在额外的修改
          this.columnWidth = 100;
          this.columnHeight = 100;
          this.message = 'Hello World';
          UIUtils.flushUpdates();
          // 动画在1s内，Column方框的尺寸由（100*100）渐变为（200*200），方框内的文本变为Hello ArkUI
          this.getUIContext().animateTo({
            duration: 1000
          }, () => {
            console.info(`animateTo-in, width=${this.columnWidth}, height=${this.columnHeight}`);
            this.columnWidth = 200;
            this.columnHeight = 200;
            this.message = 'Hello ArkUI';
            console.info(`animateTo-out, width=${this.columnWidth}, height=${this.columnHeight}`);
          });
        })
      // Column方框
      Column() {
        Text(`${this.message}`)
      }
      .backgroundColor('#ff17a98d')
      .width(this.columnWidth)
      .height(this.columnHeight)
    }
  }
}
```

### flushUIUpdates<sup>22+</sup>

static flushUIUpdates(): void

立即处理在调用该函数之前所有的状态变量修改，同步[标脏](../../ui/state-management/arkts-state-management-introduce.md#触发更新)对应的UI节点，但不会同步执行@Computed计算和@Monitor回调，详见[applySync/flushUpdates/flushUIUpdates接口：同步刷新](../../ui/state-management/arkts-new-applySync-flushUpdates-flushUIUpdates.md)。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**错误码：**

以下错误码的详细介绍请参见[状态管理错误码](./errorcode-stateManagement.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 140001   | The function is not allowed to be called in @Computed. |
| 140002   | The function is not allowed to be called in @Monitor.  |

**示例：**

```ts
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local columnWidth: number = 50; // 宽度
  @Local columnHeight: number = 50; // 高度
  @Local message: string = 'Hello';

  build() {
    Column() {
      Button('change size')
        .margin(20)
        .onClick(() => {
          // 在执行动画前，存在额外的修改
          this.columnWidth = 100;
          this.columnHeight = 100;
          this.message = 'Hello World';
          // 立即处理上述状态变量修改，同步标脏对应的UI节点
          UIUtils.flushUIUpdates();
          // 动画在1s内，Column方框的尺寸由（100*100）渐变为（200*200），方框内的文本变为Hello ArkUI
          this.getUIContext().animateTo({
            duration: 1000
          }, () => {
            console.info(`animateTo-in, width=${this.columnWidth}, height=${this.columnHeight}`);
            this.columnWidth = 200;
            this.columnHeight = 200;
            this.message = 'Hello ArkUI';
            console.info(`animateTo-out, width=${this.columnWidth}, height=${this.columnHeight}`);
          });
        })
      // Column方框
      Column() {
        Text(`${this.message}`)
      }
      .backgroundColor('#ff17a98d')
      .width(this.columnWidth)
      .height(this.columnHeight)
    }
  }
}
```

### getCustomComponentContext

static getCustomComponentContext\<T extends BaseCustomComponent\>(customComponent: T): CustomComponentContext

返回给定@Component(V1)或@ComponentV2的[CustomComponentContext](#customcomponentcontext)。使用它来访问组件的复用池。有关复用池的详细信息，请参阅[全局复用池：集中化的组件回收与复用](../../ui/state-management/arkts-global-reuse-pool.md)。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名  | 类型                                 | 必填 |  说明              |
| ------- | ------------------------------------ | ---- | -------------------------------------------------- |
| customComponent  | T | 是   | 要获取其上下文的@Component或@ComponentV2实例。 |

**返回值：**

| 类型                                              | 说明                          |
| ------------------------------------------------- | ---------------------------- |
| [CustomComponentContext](#customcomponentcontext)  | 给定组件实例的上下文对象。     |

**示例：**

```ts
import { UIUtils } from '@kit.ArkUI';

@ReusableV2
@ComponentV2
struct ReusableChild {
  aboutToRecycle() {
    console.info('ReusableChild aboutToRecycle');
  }
  aboutToReuse() {
    console.info('ReusableChild aboutToReuse');
  }

  build() {
    Text('ReusableChild')
  }
}

@Entry
@ComponentV2({ 
  reusePool: 'shared', // 声明共享全局复用池
  poolAccepts: [ReusableChild], // 全局复用池接纳子组件类型ReusableChild
  freezeWhenInactive: false // 关闭组件冻结功能。该参数必须在声明reusePool时提供，也可以开启组件冻结。
})
struct Index {
  @Local showChild: boolean = true;

  inspectPool() {
    // 获取此组件的CustomComponentContext
    const context = UIUtils.getCustomComponentContext(this);
    // 通过上下文访问复用池。
    const pool = context.getReusePool();
    if (pool) {
      const info = pool.getReusableInfo(ReusableChild);
      if (info && !Array.isArray(info)) {
        console.info(`ReusableChild 在池中: count=${info.count}, maxCount=${info.maxCount}`);
      }
    }
  }

  build() {
    Column() {
      Button('切换子组件')
        .onClick(() => { 
          this.showChild = !this.showChild;
        })
      Button('检查池')
        .onClick(() => {
          this.inspectPool();
        })
      if (this.showChild) {
        ReusableChild()
      }
    }
  }
}
```

## TaskCallback<sup>22+</sup>

type TaskCallback = () => T

同步执行的回调方法。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型 | 说明                       |
| ---- | -------------------------- |
| T    | 闭包函数执行得到的返回值。 |

## MonitorOptions<sup>20+</sup>

[addMonitor](#addmonitor20)的可选参数，用于配置回调类型以及是否使能通配符能力。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明     |
| ------ | ---- | ---- | ---- | ------------ |
|isSynchronous|boolean|否|是|配置当前回调函数是否为同步回调。true为同步回调。默认值为false，即异步回调。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|
|enableWildcard|boolean|否|是| 配置当前addMonitor是否使能通配符能力。true表示使能，false表示关闭。默认值为false，即关闭。当关闭通配符能力，但路径中含有通配符时，该路径将视为不合法路径。<br>**起始版本：** 26.0.0 <br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 |

## MonitorCallback<sup>20+</sup>
type MonitorCallback = (monitorValue: IMonitor) => void

参数为[IMonitor](./arkui-ts/ts-state-management-monitor.md#imonitor)类型的监听回调函数。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| monitorValue | [IMonitor](./arkui-ts/ts-state-management-monitor.md#imonitor) | 是   | 回调函数传入的变化信息，包含状态变量变化的路径（dirty）、变化前后的值（通过value方法获取）等详细信息。具体属性和方法详见IMonitor。 |

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

// 将key为FatherSampleClass、value为new FatherSampleClass()对象的键值对持久化，并赋值给source
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

### new

new(...args: any): T

创建并返回一个指定类型T的实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| ...args | any    | 否   | 创建类型T实例时传入的构造参数，用于初始化实例。 |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| T    | 通过new方法创建的T类型实例。默认不传入任何构造参数。 |

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

// 将key为FatherSampleClass、value为new FatherSampleClass()对象的键值对持久化，并赋值给source
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

type PersistenceErrorCallback = (key: string, reason: 'quota' | 'serialization' | 'unknown', message: string, oldValue?: string) => void

持久化失败时返回错误原因的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| key | string    | 是   | 出错的键值。   |
|reason| 'quota' \| 'serialization' \| 'unknown'    | 是   | 出错的原因类型。取值包括：'quota'表示存储配额超限；'serialization'表示序列化或反序列化失败；'unknown'表示未知错误。 |
| message | string    | 是   | 出错的更多消息。   |
| oldValue | string    | 否   | 反序列化失败时，返回旧的存储于磁盘的序列化数据；非反序列化失败场景下该参数默认值为undefined。<br> **起始版本：** 26.0.0。   |

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
// PersistenceErrorCallback 指的是 (key: string, reason: string, msg: string, oldValue?: string) => {console.error(`error key: ${key}, reason: ${reason}, message: ${msg}, oldValue: ${oldValue}`);}
PersistenceV2.notifyOnError((key: string, reason: string, msg: string, oldValue?: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}, oldValue: ${oldValue}`);
});

@Entry
@ComponentV2
struct Index {
  // 在PersistenceV2中创建一个key为Sample的键值对（如果存在，则返回PersistenceV2中的数据），并且和data关联
  // 对于需要换connect对象的data属性，需要加@Local修饰（不建议对属性换connect的对象）
  @Local data: Sample = PersistenceV2.connect(Sample, () => new Sample())!;

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

属性装饰器，用于装饰嵌套类中属于自定义class类的属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
| type | [TypeConstructor\<T\>](#typeconstructort)    | 是   | 标记类属性的类型，仅支持自定义class类型，传入其他类型会导致持久化失败。 |

**返回值：**

| 类型 | 说明                                             |
| ---- | ------------------------------------------------ |
| PropertyDecorator    | 属性装饰器，用于装饰嵌套类中属于自定义class类的属性。 |

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

在使用@Type装饰嵌套类属性时，仅支持自定义class类型，传入其他类型会持久化失败。
<!--code_no_check-->
```ts
@ObservedV2
class SampleChild {
  @Trace id: number = 0;
  count: number = 10;
}

@ObservedV2
class Sample {
  // 建议用法，装饰自定义Sample类中的sampleChild属性，其类型为SampleChild类型
  @Type(SampleChild)
  @Trace sampleChild: SampleChild = new SampleChild();

  // 不建议用法，装饰的嵌套类属性类型是Array<number>
  @Type(Array<number>)
  @Trace value: Array<Array<number>> = new Array();
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
| T    | 回调函数获取到的值。 |

**示例：**

```ts
import { Binding, UIUtils } from '@kit.ArkUI';

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
| newValue | T    | 是   | 要设置的新值，当绑定值被修改时传入此参数。   |

**示例：**

```ts
import { MutableBinding, UIUtils } from '@kit.ArkUI';

@Builder
function CustomButton(num1: MutableBinding<number>) {
  Row() {
    Button(`Custom Button: ${num1.value}`)
      .onClick(() => {
        // MutableBinding支持可变，可以修改num1.value
        num1.value += 1;
      })
  }
}

@Entry
@ComponentV2
struct CompV2 {
  @Local number1: number = 10;

  build() {
    Column() {
      Text('parent component')

      CustomButton(
        // 对于UIUtils.makeBinding函数的第二个参数需要传入SetterCallback
        UIUtils.makeBinding<number>(
          () => this.number1, // GetterCallback
          (val: number) => {
            this.number1 = val;
          }) // SetterCallback 必须提供，否则触发时会造成运行时错误
      )
    }
  }
}
```

## Binding\<T\><sup>20+</sup>

只读数据绑定的泛型类，可以绑定任意类型的数据。

### value<sup>20+</sup>
get value(): T

提供get访问器，用于获取绑定的值。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型             | 说明                                                         |
| -------------------- | ------------------------------------------------------------ |
| T | 当前绑定的值，返回值类型为泛型参数T，与Binding\<T\>定义的类型一致。 |

**示例：**

```ts
import { Binding, UIUtils } from '@kit.ArkUI';

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

### value<sup>20+</sup>
set value(newValue: T)

提供set访问器，用于设置当前绑定值的值。构造MutableBinding类实例时必须提供set访问器，否则触发set访问器会造成运行时错误。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| newValue  | T | 是   | 要设置的新值，当绑定值被修改时传入此参数。类型与MutableBinding\<T\>定义的泛型T一致。  |

### value<sup>20+</sup>
get value(): T

提供get访问器，用于获取当前绑定值。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型             | 说明                                                         |
| -------------------- | ------------------------------------------------------------ |
| T | 当前绑定的值，返回值类型为泛型参数T，与MutableBinding\<T\>定义的类型一致。 |

**示例：**

```ts
import { MutableBinding, UIUtils } from '@kit.ArkUI';

@Builder
function CustomButton(num1: MutableBinding<number>) {
  // CustomButton的第二个参数为MutableBinding，一个可变数据绑定的泛型类
  Row() {
    Button(`Custom Button: ${num1.value}`)
      .onClick(() => {
        // 可变数据绑定的泛型类可以修改绑定的值
        num1.value += 1;
      })
  }
}

@Entry
@ComponentV2
struct CompV2 {
  @Local number1: number = 10;

  build() {
    Column() {
      Text('parent component')

      CustomButton(
        UIUtils.makeBinding<number>(
          () => this.number1, // GetterCallback
          (val: number) => {
            this.number1 = val;
          }) // SetterCallback 必须提供，否则触发时会造成运行时错误
      )
    }
  }
}
```

## CustomComponentContext

`CustomComponentContext`类提供对组件级服务的访问，包括复用池。通过[UIUtils.getCustomComponentContext](#getcustomcomponentcontext)获取实例。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

### getReusePool

getReusePool(): IReusePool | undefined

返回该自定义组件拥有的全局复用池。如果组件或其上层组件没有通过`reusePool`和`poolAccepts`配置全局复用池，则返回`undefined`。配置全局复用池方式请参考[全局复用开发指南](../../../application-dev/ui/state-management/arkts-global-reuse-pool.md)。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型                                   |  说明                          |
| -------------------------------------- | ------------------------------------------------ |
| [IReusePool](#ireusepool) \| undefined | 当前组件配置全局复用池时，返回复用池信息，否则返回`undefined`。 |

**示例：**

```ts
import { UIUtils } from '@kit.ArkUI';

@ReusableV2
@ComponentV2
struct ReusableChild {
  build() {
    Text('ReusableChild')
  }
}

@Entry
@ComponentV2({ reusePool: 'perInstance', poolAccepts: [ReusableChild], freezeWhenInactive: false })
struct PoolOwner {
  checkPool() {
    const pool = UIUtils.getCustomComponentContext(this).getReusePool();
    if (pool) {
      console.info('Global reuse pool configured.');
    } else {
      console.info('No global reuse pool configured.');
    }
  }

  build() {
    Column() {
      ReusableChild()
      Button('Check Pool')
        .onClick(() => {
          this.checkPool();
        })
    }
  }
}
```

## IReusePool

`IReusePool`接口提供自定义组件上的全局复用池的相关功能，包括查询回收组件的当前数量和上限信息、预渲染可复用组件到复用池中等，适用于开发者需要手动管理和优化组件复用效率的场景。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

### getReusableInfo

getReusableInfo(constructor: ReusableComponentConstructor, reuseId?: string): IReusableInfo[] | IReusableInfo | undefined

检索此复用池中给定可复用组件类型的回收实例信息。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名        | 类型                                 | 必填 |  说明            |
| ------------ | ------------------------------------ | ---- | --------------------------------------------------------------------------------------------------------------------------- |
| constructor | [ReusableComponentConstructor](#reusablecomponentconstructor) | 是   | 要查询的可复用自定义组件的构造函数。|
| reuseId      | string   | 否   | 可选的reuseId用于过滤结果。如果指定，则仅返回此特定reuseId复用池的信息。默认值是undefined，返回所有reuseId复用池信息。   |

**返回值：**

| 类型 | 说明 |
| --------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [IReusableInfo](#ireusableinfo)[] \| [IReusableInfo](#ireusableinfo) \| undefined | 如果此复用池未配置为接受给定的组件类型，则返回`undefined`。<br>如果将`reuseId`指定为参数，则返回单个`IReusableInfo`（即使计数为0 且maxCount为默认值）。<br>如果未指定`reuseId`参数且复用组件在创建时未使用reuseId，则返回单个`IReusableInfo`。<br>如果未指定`reuseId`参数但复用组件在创建时使用了reuseId，则返回一个`Array<IReusableInfo>`，为每个具有正计数或非默认maxCount的reuseId提供单独的条目，外加一个`reuseId: undefined`的条目。 |

**示例：**

```ts
import { UIUtils, IReusableInfo } from '@kit.ArkUI';

@ReusableV2
@ComponentV2
struct ReusableChild {
  aboutToRecycle() {
    console.info('ReusableChild aboutToRecycle');
  }
  aboutToReuse() {
    console.info('ReusableChild aboutToReuse');
  }

  build() {
    Text('ReusableChild')
  }
}

@Entry
@ComponentV2({ reusePool: 'perInstance', poolAccepts: [ReusableChild], freezeWhenInactive: false })
struct PoolOwner {
  @Local showChild: boolean = true;

  inspectPool() {
    const pool = UIUtils.getCustomComponentContext(this).getReusePool();
    if (!pool) {
      return;
    }

    // 查询池接受的组件类型。
    const info = pool.getReusableInfo(ReusableChild);
    if (info === undefined) {
      console.info('No reuse pool that accepts ReusableChild');
    } else if (Array.isArray(info)) {
      // 使用了多个 reuseId 桶。
      info.forEach((item: IReusableInfo, i: number) => {
        console.info(`[${i}] reuseId=${item.reuseId}, count=${item.count}, maxCount=${item.maxCount}`);
      });
    } else {
      // 单个条目（未使用 reuseId，或查询了特定的 reuseId）。
      console.info(`count=${info.count}, maxCount=${info.maxCount}`);
    }

    // 查询特定的 reuseId — 始终返回单个 IReusableInfo。
    const bucketInfo = pool.getReusableInfo(ReusableChild, 'A') as IReusableInfo;
    console.info(`reuseId 'A': count=${bucketInfo.count}, maxCount=${bucketInfo.maxCount}`);
  }

  build() {
    Column() {
      Button('切换子组件')
        .onClick(() => {
          this.showChild = !this.showChild;
        })
      Button('检查池')
        .onClick(() => this.inspectPool())
      if (this.showChild) {
        ReusableChild()
          .reuse({ reuseId: () => 'A' })
      }
    }
  }
}
```

### preRender

preRender(builder: WrappedBuilder\<[]\>, times: number): Promise\<void\>

调用空闲任务以预创建可复用组件并在首次使用前将其放入复用池。

> **说明：**
>
> 1. `preRender`仅将池配置为接受的组件放入池中。预渲染池不接受的组件会立即创建并销毁。
>
> 2. 预渲染期间不会从池中复用组件；池仅接受新创建的实例。
>
> 3. @Builder函数执行完整的深度渲染，包括嵌套的子组件。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名  | 类型                 | 必填 |  说明                            |
| ------- | -------------------- | ---- | --------------------------------------------------------------------------------------------------------------------------------- |
| builder | [WrappedBuilder](././arkui-ts/ts-universal-wrapBuilder.md#wrappedbuilder)\<[]\> | 是   | 包含要执行`times`次的@Builder函数的 `WrappedBuilder`。每次执行应创建一个或多个[@Reusable](../../ui/state-management/arkts-create-custom-components.md#reusable)/[@ReusableV2](../../ui/state-management/arkts-create-custom-components.md#reusablev2)组件。 |
| times   | number               | 是   | 执行@Builder函数的次数。取值范围为正整数。传入0或负数时不生效。传入小数时会向上取整。 |

**返回值：**

| 类型 | 说明  |
| --------------- | ------------------------------------------------------------------------------------------------------------------- |
| Promise\<void\> | 当空闲任务成功完成时兑现的Promise。Promise对象无返回结果。当预渲染任务执行失败时，Promise会被拒绝。|

**示例：**

```ts
import { UIUtils, IReusableInfo } from '@kit.ArkUI';

@ReusableV2
@ComponentV2
struct ReusableComponent {
  @Param param: number = 8;

  aboutToAppear() {
    console.info('ReusableComponent aboutToAppear');
  }
  aboutToReuse() {
    console.info('ReusableComponent aboutToReuse');
  }

  build() {
    Column() {
      Text(`ReusableComponent ${this.param}`)
    }
  }
}

@Builder 
function preRenderBuilder() {
  ReusableComponent()
}

@Entry
@ComponentV2({ reusePool: 'shared', poolAccepts: [ReusableComponent], freezeWhenInactive: false })
struct Index {
  @Local onUIFullyLoaded: boolean = false;

  aboutToAppear() {
    // 获取池并调度预渲染。
    const pool = UIUtils.getCustomComponentContext(this).getReusePool();
    // 预加载preRenderBuilder内的复用组件到当前的全局复用池中，执行一次preRenderBuilder。
    pool!.preRender(new WrappedBuilder<[]>(preRenderBuilder), 1)
      .then(() => {
        console.info('ReusableComponent preRender completes');
      });
  }

  checkPool() {
    // 获取全局复用池内组件数量
    const reusePool = UIUtils.getCustomComponentContext(this).getReusePool();
    const reusableInfo: IReusableInfo = reusePool!.getReusableInfo(ReusableComponent) as IReusableInfo;
    console.info(`ReusableComponent reuse pool count=${reusableInfo.count}`);
  }

  build() {
    Column({ space: 5 }) {
      Button('Switch')
        .onClick(() => {
          this.onUIFullyLoaded = !this.onUIFullyLoaded;
        })
        .width(100)
      Button('Check pool')
        .onClick(() => {
          this.checkPool();
        })
        .width(100)
      CompA({ showFullUI: this.onUIFullyLoaded })
    }
    .width('100%')
  }
}

@ComponentV2
struct CompA {
  @Require @Param showFullUI: boolean;

  build() {
    if (this.showFullUI) {
      // 这将从池中复用预渲染的实例。
      ReusableComponent()
    }
  }
}
```

## IReusableInfo

`IReusableInfo`接口提供有关复用池管理的可复用组件的当前数量和数量上限的信息。

### 属性

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称     | 类型   | 只读 | 可选 |  说明                               |
| -------- | ------ | ---- | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| count    | number | 是   | 否   | 池中当前回收的组件数。如果设置了`reuseId`，则`count`指的是具有此特定reuseId的组件数。                                   |
| maxCount | number | 否   | 否   | 池中允许的最大回收组件数。如果设置了`reuseId`，则`maxCount`指的是具有此特定reuseId的组件数。将此设置为小于当前`count`的值会导致框架异步清除多余组件。在延迟期间，`count`可能暂时超过`maxCount`。默认值：100，最大值：200，最小值：0。赋值超出范围时，取最接近的最大值或最小值。赋值为小数时会向下取整。|
| reuseId  | string | 是   | 是   | 回收组件时指定的reuseId。如果组件没有使用reuseId回收，则此属性为`undefined`。                                 |

**示例：**

```ts
import { UIUtils, IReusableInfo } from '@kit.ArkUI';

@ReusableV2
@ComponentV2
struct TestChild {
  @Param label: string = '';
  aboutToAppear() {
    console.info(`TestChild [${this.label}] aboutToAppear`);
  }
  aboutToReuse() {
    console.info(`TestChild [${this.label}] aboutToReuse`);
  }
  aboutToRecycle() {
    console.info(`TestChild [${this.label}] aboutToRecycle`);
  }
  aboutToDisappear() {
    console.info(`TestChild [${this.label}] aboutToDisappear`);
  }

  build() {
    Text(`子组件: ${this.label}`)
  }
}

@Entry
@ComponentV2({ reusePool: 'perInstance', poolAccepts: [TestChild], freezeWhenInactive: false })
struct PoolOwner {
  @Local showA: boolean = true;
  @Local showB: boolean = true;

  controlPool() {
    const pool = UIUtils.getCustomComponentContext(this).getReusePool();
    if (!pool) {
      return;
    }

    // 查询所有回收的 TestChild 实例。
    const info = pool.getReusableInfo(TestChild);
    if (info && !Array.isArray(info)) {
      console.info(`TestChild: count=${info.count}, maxCount=${info.maxCount}`);
      // 将缓存限制为 5 个组件。
      info.maxCount = 5;
    }

    // 通过将 maxCount 设置为 0 来清除特定的 reuseId 桶。
    const bucketB = pool.getReusableInfo(TestChild, 'B') as IReusableInfo;
    if (bucketB) {
      bucketB.maxCount = 0; // 仅驱逐 'B' reuseId 桶。
    }
  }

  build() {
    Column() {
      Button('切换A')
        .onClick(() => {
          this.showA = !this.showA;
        })
      Button('切换B')
        .onClick(() => {
          this.showB = !this.showB;
        })
      Button('控制池')
        .onClick(() => this.controlPool())
      if (this.showA) {
        TestChild({ label: 'A' })
          .reuse({ reuseId: () => 'A' })
      }
      if (this.showB) {
        TestChild({ label: 'B' })
          .reuse({ reuseId: () => 'B' })
      }
    }
  }
}
```

## ReusableComponentConstructor

type ReusableComponentConstructor = Function

复用自定义组件初始化函数。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。
