# PersistenceV2: 持久化存储UI状态
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

为了增强状态管理框架对持久化存储UI的能力，开发者可以使用PersistenceV2存储持久化的数据。

PersistenceV2是应用程序中的可选单例对象。此对象的作用是持久化存储UI相关的数据，以确保这些属性在应用程序重新启动时的值与应用程序关闭时的值相同。

PersistenceV2提供状态变量持久化能力，开发者可以通过connect或者globalConnect绑定同一个key，在状态变量变化和应用冷启动时，实现持久化能力。

在阅读本文档前，建议提前阅读：[\@ComponentV2](./arkts-create-custom-components.md#componentv2)，[\@ObservedV2和\@Trace](./arkts-new-observedV2-and-trace.md)，配合阅读：[PersistenceV2-API文档](../../reference/apis-arkui/js-apis-stateManagement.md#persistencev2)。

>**说明：**
>
>PersistenceV2从API version 12开始支持。
>
>globalConnect从API version 18开始支持，行为和connect保持一致，唯一的区别为connect的底层存储路径为module级别的路径，而globalConnect的底层存储路径为应用级别，详细区别见使用场景[在不同的module中使用connect和globalConnect](#在不同的module中使用connect和globalconnect)。
>
>globalConnect从API version 23开始支持[集合类型](#globalconnect支持集合的类型)（Array、Map、Set、Date、collections.Array、collections.Map、collections.Set）的持久化，支持在UI线程持久化@Sendable类型的数据持久化，支持持久化循环引用的对象，支持持久化单个key超过8k的数据。目前建议开发者使用API version 23的新增的globalConnect接口。

## 概述

PersistenceV2是在应用UI启动时会被创建的单例。它的目的是提供应用状态数据的中心存储，这些状态数据在应用级别都是可访问的。数据通过唯一的键值字符串访问。不同于AppStorageV2，PersistenceV2还将最新数据存储在设备磁盘上（持久化）。这意味着，应用退出再次启动后，依然能保存选定的结果。

对于与PersistenceV2关联的[\@ObservedV2](./arkts-new-observedV2-and-trace.md)对象，该对象的[\@Trace](./arkts-new-observedV2-and-trace.md)属性的变化，会触发**整个关联对象的自动持久化**；非[\@Trace](./arkts-new-observedV2-and-trace.md)属性的变化则不会，如有必要，可调用PersistenceV2 API手动持久化。请注意：被PersistenceV2持久化的类属性必须要有初值，否则不支持持久化。

PersistenceV2可以和UI组件同步，且可以在应用业务逻辑中被访问。

PersistenceV2支持应用的[主线程](../../application-models/thread-model-stage.md)内多个UIAbility实例间的状态共享。

PersistenceV2继承自[AppStorageV2](../../reference/apis-arkui/js-apis-stateManagement.md#appstoragev2)，支持通过[connect](../../reference/apis-arkui/js-apis-stateManagement.md#connect)创建或获取存储的数据。

## 使用说明
- globalConnect：创建或获取存储的数据。
>**说明：**
>
>1、关联[\@Observed](./arkts-observed-and-objectlink.md)对象时，由于该类型的name属性未定义，需要指定key或者自定义name属性。
>
>2、 globalConnect为应用级别存储，对于一个key，整个应用在对应加密分区只有一份存储路径。使用PersistenceV2的connect存储的数据路径为module级别，即哪个module调用了connect，数据副本存入对应module的持久化文件中。如果多个module使用相同的key，则数据为最先使用connect的module，并且PersistenceV2中的数据也会存入最先使用connect的module里。因为存储路径在应用第一个ability启动时就已确定，为该ability所属的module。如果一个ability调用了connect，并且该ability能被不同的module拉起， 那么ability存在多少种启动方式，就会有多少份数据副本，因此，建议开发者使用globalConnect代替connect接口。
- remove：删除指定key的存储数据。删除PersistenceV2中不存在的key会报警告。
- keys：返回所有PersistenceV2中的key。包括module级别存储路径和应用级别存储路径中的所有key。
- save：手动持久化数据。
- notifyOnError：响应序列化或反序列化失败的回调。将数据存入磁盘时，需要对数据进行序列化；当某个key序列化失败时，错误是不可预知的；可调用该接口捕获异常。

以上接口详细描述请参考[PersistenceV2-API文档](../../reference/apis-arkui/js-apis-stateManagement.md#persistencev2)和[AppStorageV2-API文档](../../reference/apis-arkui/js-apis-stateManagement.md#appstoragev2)。

## 使用限制

1、需要配合UI使用（UI线程），不能在其他线程使用。在API version 23以前，不支持@Sendable。

   -  从API version 23开始，提供globalConnect接口，支持在UI线程持久化`@Sendable`装饰的类对象，其成员属性的类型需为基础内置类型（`string`、`number`和`boolean`）。
  

2、在API version 23以前，不支持`collections.Set`、`collections.Map`等类型。

- 从API version 23开始，提供globalConnect接口，支持[collections.Set](../../reference/apis-arkts/arkts-apis-arkts-collections-Set.md)、[collections.Map](../../reference/apis-arkts/arkts-apis-arkts-collections-Map.md)和[collections.Array](../../reference/apis-arkts/arkts-apis-arkts-collections-Array.md)。`collections.Set`、`collections.Map`和`collections.Array`本身无法观察，在globalConnect接口使用defaultCreator时，需要使用[UIUtils.makeObserved](../../reference/apis-arkui/js-apis-stateManagement.md#makeobserved)，才能在值变化时自动保存，如果不使用，开发者需要手动调用[PersistenceV2.save(key)](../../reference/apis-arkui/js-apis-stateManagement.md#save)保存变化的数据。

   如下是新增接口globalConnect支持collections.Array的示例代码:
    
    <!-- @[top_level_collections_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/PersistenceV2/entry/src/main/ets/pages/TopLevelCollectionsArray.ets) -->
     
    ``` TypeScript
    import { PersistenceV2, UIUtils } from '@kit.ArkUI';
    import { collections } from '@kit.ArkTS';

    @Entry
    @ComponentV2
    struct Page1 {
      // 支持直接持久化collections.Array的类型
      @Local array: collections.Array<number> = PersistenceV2.globalConnect({
        // 定义持久化的数据类型
        type: collections.Array<number>,
        // 定义默认构造器，返回时需要调用makeObserved，才能实现自动持久化
        defaultCreator: () => UIUtils.makeObserved(new collections.Array<number>(1,2))
      })!;
      // 基于collections.Array构建Repeat的数据源
      toArray<T>(array: collections.Array<T>): Array<T> {
        const result = new Array<T>();
        array.forEach((item: T) => result.push(item));
        return result;
      }

      build() {
        Column({ space: 10 }) {
          Column({ space: 0 }) {
            Repeat(this.toArray(this.array))
              .each(ri => {
                Row() {
                  Text(`Item: `)
                    .fontSize(20)
                    .margin(10)
                  Text(`${ri.item}`)
                    .fontSize(20)
                    .margin(10)
                }
              })
              .key((item: number, index: number) => `${index} - ${item}`)
          }
          Divider().width('100%')
          // 点击'array.push(0)'，重启应用，Repeat数组项是：1, 2, 0
          Button('array.push(0)')
            .onClick(() => {
              this.array.push(Math.round(0));
            })
            .width(300)
            .margin(10)
          // 点击'array.pop()'，重启应用，Repeat数组项是：1, 2
          Button('array.pop()')
            .onClick(() => {
              this.array.pop();
            })
            .width(300)
            .margin(10)
          // 点击'array.splice(0)'，重启应用，Repeat数组项为空
          Button('array.splice(0)')
            .onClick(() => {
              this.array.splice(0);
            })
            .width(300)
            .margin(10)
          // 点击'splice(1, 0, random)'，重启应用：Repeat组件再次显示相同的数组项
          Button('array.splice(1, 0, random)')
            .onClick(() => {
              this.array.splice(1, 0, Math.round(100*Math.random()));
            })
            .width(300)
            .margin(10)
          // 点击'array.splice(0, 2, random, random)'，前两个数组项目被替换，记录下来
          // 重启应用：Repeat组件再次显示数组项
          Button('array.splice(0, 2, random, random)')
            .onClick(() => {
              this.array.splice(0, 2, Math.round(100*Math.random()), Math.round(100*Math.random()));
            })
            .width(300)
            .margin(10)
          // 点击'array.sort', 对数组项升序排列，重启应用，Repeat组件展示升序数组
          Button('array.sort')
            .onClick(() => {
              this.array.sort((a, b) => a -b);
            })
            .width(300)
            .margin(10)
          // 点击'array.reverse', 对数组项降序排列，重启应用，Repeat组件展示降序数组
          Button('array.reverse')
            .onClick(() => {
              this.array.reverse();
            })
            .width(300)
            .margin(10)
        }
        .width('100%')
      }
    }
    ```

     ![persistencev2-sync-0](./figures/persistencev2-sync-0.gif)

- globalConnect在持久化多个相同[集合类型](#globalconnect支持集合的类型)时，需要提供不同的`key`来区分持久化数据。

   如下展示开发者持久化相同的`Array<number>`类型的部分示例代码片段：

  ```typescript
  @Entry
  @ComponentV2
  struct Page1 {
    // 持久化相同容器类型的数据，建议开发者使用不同的key来区分持久化数据
    @Local arr1: Array<number> = PersistenceV2.globalConnect({
      type: Array<number>,
      key: 'arr1',
      defaultCreator: () => UIUtils.makeObserved(new Array<number>()),
    })!;

    @Local arr2: Array<number> = PersistenceV2.globalConnect({
      type: Array<number>,
      key: 'arr2',
      defaultCreator: () => UIUtils.makeObserved(new Array<number>()),
    })!;
    // ...
  }
  ```

3、不支持非built-in类型，如[PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md)、NativePointer、[ArrayList](../../reference/apis-arkts/js-apis-arraylist.md)等Native类型。

4、在API version 23以前，单个key支持数据大小约8k，过大会导致持久化失败。

- 在API version 23开始，解除单个key只能持久化8K数据的限制，读取和写入持久化存储的数据会在UI线程中同步进行，但开发者需要注意，不建议开发者在UI线程存储大量的持久化数据，会导致界面卡顿。

5、在API version 23以前，持久化的数据必须是class对象，不支持容器类型（如Array、Set、Map），不支持built-in的构造对象（如String、Number），不支持持久化基本类型（如string、number、boolean）。如果需要持久化非class对象，建议使用[Preferences](../../database/preferences-guidelines.md)进行数据持久化。

- 在API version 23开始，支持持久化Class类型和容器类型（Array、Set、Map，Date）。支持built-in的构造对象类型（如String、Number）及基本类型（如string、number、boolean）作为class属性的持久化（String、Number是不可变的数据对象，没法直接作为[顶层数据类型](#globalconnect顶层持久化数据类型及非顶层数据类型)进行持久化）。对于不支持的类型，会抛出运行时报错，从API version 23开始，将返回错误码[140103](../../reference/apis-arkui/errorcode-stateManagement.md#140103-appstoragev2和persistencev2使用不支持的数据类型)。

   如下为新增globalConnect支持`Array<ClassA>`类型的持久化示例：

    <!-- @[top_level_array_classa](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/PersistenceV2/entry/src/main/ets/pages/TopLevelArrayClassA.ets) -->
   
    ``` TypeScript
    import { PersistenceV2, UIUtils } from '@kit.ArkUI';

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
      // 持久化顶层数据类型为Array<ClassA>的数据
      @Local arr: Array<ClassA> = PersistenceV2.globalConnect({
        type: Array<ClassA>,
        defaultCreator: () => UIUtils.makeObserved(new Array<ClassA>()),
        // 添加defaultSubCreator，通知状态管理框架如何创建数组项
        // 另外持久化的数据需要加上makeObserved，因为JSON对象本身没有观察能力，自动持久化会失败
        defaultSubCreator: () => UIUtils.makeObserved(new ClassA())
      })!;

      build() {
        Column() {
          Repeat(this.arr)
            .each(ri => {
              Row() {
                Text(`propA '${ri.item.propA}'`)
                  .fontSize(20)
                  .margin(10)
                Text(`propB '${ri.item.propB}'`)
                  .fontSize(20)
                  .margin(10)
                Text(`report?.() '${ri.item.report?.()}'`)
                  .fontSize(20)
                  .margin(10)
              }
            })
          // 点击'add item',显示`propA 'a' propB 'b'report?.()'a - b'`, 杀掉应用，再次进入，会显示上次的结果
          Button('add item')
            .width(300)
            .margin(10)
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

   ![persistencev2-sync-1](./figures/persistencev2-sync-1.gif)

   如下为globalConnect支持Date类型的持久化示例：

    <!-- @[top_level_date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/PersistenceV2/entry/src/main/ets/pages/TopLevelDate.ets) --> 
    
    ``` TypeScript
    import { PersistenceV2, UIUtils } from '@kit.ArkUI';
    
    @Entry
    @ComponentV2
    struct Page1 {
      // 支持直接持久化Date类型的数据
      @Local date: Date = PersistenceV2.globalConnect({
        type: Date,
        defaultCreator: () => UIUtils.makeObserved(new Date())
      })!;
    
      build() {
        Column({ space: 40 }) {
          Text(`date: ${this.date.toISOString()}`)
            .fontSize(24)
            .margin(10)
          // 点击'date.setTime( Date.now() )', 杀掉应用，进入应用后，显示日期
          Button('date.setTime( Date.now() )')
            .margin(10)
            .onClick(() => {
              this.date.setTime(Date.now());
            })
            .fontSize(24)
        }
        .width('100%')
      }
    }
    ```

    ![persistencev2-sync-2](./figures/persistencev2-sync-2.gif)

  如下为globalConnect支持Number类型作为class子属性的持久化示例：

  <!-- @[non_top_level_number_of_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/PersistenceV2/entry/src/main/ets/pages/NonTopLevelNumberOfClass.ets) --> 
  
  ``` TypeScript
  import { PersistenceV2 } from '@kit.ArkUI';
  
  @ObservedV2 class NumberClass {
    // Number类型不是顶层持久化数据类型，只能支持非顶层数据类型的持久化
    @Trace public value: Number = new Number(Infinity);
  }
  
  @Entry
  @ComponentV2
  struct Page1 {
    // Number类型只能作为NumberClass的子属性去持久化
    @Local number: NumberClass = PersistenceV2.globalConnect({
      type: NumberClass,
      defaultCreator: () => new NumberClass()
    })!;
    output: string[] = [];
  
    aboutToAppear(): void {
      this.output.push(`this.number.value: ${this.number.value}, is instanceof Number ${this.number.value instanceof Number}`);
      this.number.value = new Number(-this.number.value);
    }
  
    build() {
      Column() {
        Row() {
          // 第一次打开应用，界面显示'this.number.value: Infinity, is instanceof Number true'
          // 第二次打开应用，界面显示'this.number.value: -Infinity, is instanceof Number true'
          Text(this.output.join('\n\n'))
            .fontSize(24)
        }
      }
      .width('100%')
    }
  }
  ```

  ![persistencev2-sync-3](./figures/persistencev2-sync-3.png)

6、在API version 23以前，不支持循环引用对象的持久化。

- 在API version 23开始，提供globalConnect接口支持循环引用的对象持久化。

   如下为globalConnect支持循环引用的对象的持久化示例：

   <!-- @[circular_reference_of_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/PersistenceV2/entry/src/main/ets/pages/CircularReferenceOfObject.ets) --> 
   
   ``` TypeScript
   import { PersistenceV2 } from '@kit.ArkUI';
   
   @ObservedV2
   class ClassA {
     @Trace public value: string = 'a';
     @Trace public refB: ClassB | undefined;
   }
   
   @ObservedV2
   class ClassB {
     @Trace public value: string = 'b';
     @Trace public refA: ClassA | undefined;
   }
   
   @ObservedV2
   class ClassC {
     @Trace public value: string = 'c';
     @Trace public objA: ClassA = new ClassA();
     @Trace public objB: ClassB = new ClassB();
   
     // ClassC是循环引用对象
     constructor() {
       this.objA.refB = this.objB;
       this.objB.refA = this.objA;
     }
   }
   
   @Entry
   @ComponentV2
   struct Page1 {
     @Local test: ClassC = PersistenceV2.globalConnect({
       type: ClassC,
       defaultCreator: () => new ClassC()
     })!;
     output: string[] = [];
   
     aboutToAppear(): void {
       const refAValue = this.test.objA?.refB?.refA?.value;
       const refBValue = this.test.objB?.refA?.refB?.value;
       this.output.push(`${refAValue}, ${refBValue}`);
       this.test.objA.value += 'a';
       this.test.objB.value += 'b';
     }
   
     build() {
       Column() {
         Row() {
           // 第一次打开应用，界面显示'a, b'
           // 第二次打开应用，界面显示'aa, bb'
           Text(this.output.join('\n\n'))
             .fontSize(20)
             .width(300)
             .margin(10)
         }
         .height('100%')
       }
       .width('100%')
     }
   }
   ```

   ![persistencev2-sync-4](./figures/persistencev2-sync-4.png)

7、只有[\@Trace](./arkts-new-observedV2-and-trace.md)的数据改变会触发自动持久化，如V1状态变量、[\@Observed](./arkts-observed-and-objectlink.md)对象、普通数据的改变不会触发持久化。

8、connect和globalConnect不建议混用，如果混用，key不能一样，否则应用crash，从API version 23开始，将返回错误码[140105](../../reference/apis-arkui/errorcode-stateManagement.md#140105-persistencev2混用connect和globalconnect并使用相同的key)。

9、PersistenceV2必须与UI实例关联，持久化操作需在UI实例初始化完成后调用（即[loadContent](../../reference/apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9)回调触发后）。
```ts
// EntryAbility.ets
// 以下为代码片段，需要开发者自己在EntryAbility.ets中补全
import { PersistenceV2 } from '@kit.ArkUI';

// 在EntryAbility外部定义class
@ObservedV2
class Storage {
  @Trace isPersist: boolean = false;
}

// 在onWindowStageCreate的loadContent回调中调用PersistenceV2
onWindowStageCreate(windowStage: window.WindowStage): void {
  windowStage.loadContent('pages/Index', (err) => {
    if (err.code) {
      return;
    }
    PersistenceV2.connect(Storage, () => new Storage());
  });
}
```

10、如果开发者对数据持久化能力有较强的诉求，例如持久化时机，建议使用[Preferences](../../database/preferences-guidelines.md)进行数据持久化。注意：不允许混用PersistenceV2和Preferences，因为Preferences存储的数据不会有状态变量信息，反序列化的数据不能触发PersistenceV2的自动化存储。

11、当开发者使用globalConnect持久化数据，从磁盘读取数据时，需要保证key数据在持久化前后类型一致。从API version 23开始，将返回错误码[140107](../../reference/apis-arkui/errorcode-stateManagement.md#140107-appstoragev2和persistencev2数据类型不匹配)。

12、globalConnect仅支持设置EL1-EL5加密级别，否则会抛出运行时异常，从API version 23开始，将返回错误码[140106](../../reference/apis-arkui/errorcode-stateManagement.md#140106-使用persistencev2存储数据到不支持的加密级别)，示例见[使用globalConnect存储数据](#使用globalconnect存储数据)。

13、当存储数据的结构与当前数据的结构不一致时，可能会导致反序列化失败。在API版本26.0.0以前，开发者无法获取旧的序列化数据，进而无法判断自己的数据结构有哪些改变。
- 从API版本26.0.0开始，[PersistenceErrorCallback](../../reference/apis-arkui/js-apis-stateManagement.md#persistenceerrorcallback)支持传入oldValue参数，开发者可通过该参数获取存于磁盘的旧的序列化数据，具体用例可见[通过notifyonerror获取旧的序列化数据](#通过notifyonerror获取旧的序列化数据)。

14、不支持在使用connect或globalConnect的类中使用[\@Computed](./arkts-new-computed.md)。\@Computed为只读属性，不支持赋值操作，因此会导致反序列化失败。

## globalConnect支持的类型

### globalConnect顶层持久化数据类型及非顶层数据类型

在API version 23以前，持久化的顶层数据类型必须是用户自定义的`class`对象，不支持容器类型（如`Array`、`Set`、`Map`，`Date`）。在API version 23开始，持久化的顶层数据类型可以是用户自定义的`class`，也可以是容器类型。非顶层数据类型，是指定义在用户自定义`class`属性的类型。

如下示例中，`Array<ClassA>`是顶层持久化数据类型, 可作为`globalConnect`的直接返回值类型，`collections.Map`是`CollectionMapClass`类中属性的类型，属于非顶层持久化的数据类型。

```typescript
class ClassA {
  propA: number;

}
@Sendable
class CollectionMapClass {
  // 用户自定义的class中属性类型为collections.Map，非顶层持久化数据类型
  value = new collections.Map<number, number>([]);
}

@ComponentV2
struct Page1 {
  // 顶层持久化数据类型为Array<ClassA>
  @Local arr: Array<ClassA> = PersistenceV2.globalConnect({
    type: Array<ClassA>,
    defaultCreator: () => UIUtils.makeObserved(new Array<ClassA>()),
    // 添加defaultSubCreator，通知状态管理框架如何创建数组项
    // 另外持久化的数据需要加上makeObserved，否则会持久化失败
    defaultSubCreator: () => UIUtils.makeObserved(new ClassA())
  })!;
  
  // 顶层持久化数据类型为用户自定义的class，collections.Map为非顶层持久化数据类型
  collectionMap: CollectionMapClass = PersistenceV2.globalConnect({
    type: CollectionMapClass,
    defaultCreator: () => new CollectionMapClass()
  })!
  // ...
}
```

### globalConnect用户自定义class对象属性支持的类型

用户自定义class对象的属性可以使用以下类型：`boolean`、`number`、`string`、`undefined`、`null`、`Object`、`Date`、`Number`、`Boolean`、`String`以及自定义类`class`。还支持以下集合类型：`Array`、`Map`、`Set`。

```typescript
// 观察类的@Trace属性支持上述所有类型
@ObservedV2
class ClassA {
  // VType是上述列举的类型
  @Trace propA: VType;  
}

@ComponentV2 struct Comp {
  @Local obsObj : ClassA = PersistenceV2.globalConnect({
    type: ClassA, 
    defaultCreator: () => new ClassA()
  })
  // ...
}
```
用户自定义class类型的属性必须使用`@Type`装饰器装饰，且其`class`属性值必须严格为`@Type`中指定类的实例。

```typescript
class ClassA {
  // ...
}
class PersistClass {
  @Type(ClassA)
  propA: ClassA = new ClassA();
}
```

### globalConnect支持集合的类型

集合类型是指`Array<V>`、`Map<K, V>`、`Set<V>`、`collections.Array<V>`、`collections.Map<K, V>`、`collections.Set<V>`。

其中，`Map<K, V>`和`collections.Map<K, V>`中的key值类型（`K`）是指`string`或`number`类型。

`Array<V>`、`Map<K, V>`和 `Set<V>`中，`V`的类型包括：`boolean`、`number`、`string`、`Date`、`Number`、`Boolean`、`String`、interface类型和class类型。

`collections.Array<V>`、`collections.Map<K, V>`、`collections.Set<V>`要求`V`的类型必须是`@Sendable`类型的数据（`boolean`、`number`、`string`类型）。

如下展示`globalConnect`持久化`Array<ClassA>`的示例：

<!-- @[top_level_array_classa_apis](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/PersistenceV2/entry/src/main/ets/pages/TopLevelArrayClassAAPIs.ets) -->
 
``` TypeScript
import { PersistenceV2, UIUtils } from '@kit.ArkUI';

class ClassA {
  public propA: number = 0;
  public classAToString() : string {
    return this.propA?.toString()
  }
}

@Entry
@ComponentV2
struct Page1 {
  @Local arr: Array<ClassA> = PersistenceV2.globalConnect({
    type: Array<ClassA>,
    defaultCreator: () => UIUtils.makeObserved(new Array<ClassA>()),
    // 添加defaultSubCreator，通知状态管理框架如何创建ClassA对象
    // 另外持久化后的数据需要加上makeObserved，否则会持久化失败
    defaultSubCreator: () => UIUtils.makeObserved(new ClassA())
  })!;

  build() {
    Column({ space: 10 }) {
      Column({ space: 0 }) {
        Repeat(this.arr)
          .each(ri => {
            Row() {
              Text(`Item: `)
                .fontSize(20)
                .margin(10)
              Text(ri.item?.classAToString ? ri.item?.classAToString(): `classAToString() missing from object, propA: ${ri.item?.propA}`)
                .fontSize(20)
                .margin(10)
            }
          })
          .key((item: ClassA, index: number) => `${index} - ${item?.propA}`)
      }
      .width('100%')

      Divider().width('100%')
      // 点击'array.push(0)'，重启应用，Repeat数组项是：1, 2, 0
      Button('array.push(0)')
        .width(300)
        .margin(10)
        .onClick(() => {
          let temp = new ClassA();
          temp.propA = 0;
          this.arr.push(UIUtils.makeObserved(temp));
        })
        .fontSize(24)
      // 点击'array.pop()'，重启应用，Repeat数组项是：1, 2
      Button('array.pop()')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.arr.pop();
        })
        .fontSize(24)
      // 点击'array.splice(0)'，重启应用，Repeat数组项为空
      Button('array.splice(0)')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.arr.splice(0);
        })
        .fontSize(24)
      // 点击'splice(1, 0, random)'，重启应用：Repeat组件再次显示相同的数组项
      Button('array.splice(1, 0, random)')
        .margin(10)
        .onClick(() => {
          let temp = new ClassA();
          temp.propA = Math.round(100 * Math.random());
          this.arr.splice(1, 0, UIUtils.makeObserved(temp));
        })
        .fontSize(24)
      // 点击'array.splice(0, 2, random, random)'，前两个数组项目被替换，记录下来
      // 重启应用：Repeat组件再次显示数组项
      Button('array.splice(0, 2, random, random)')
        .margin(10)
        .onClick(() => {
          let tempA = new ClassA();
          tempA.propA = Math.round(100 * Math.random());
          this.arr.splice(0, 2,
            UIUtils.makeObserved(tempA),
            UIUtils.makeObserved(tempA));
        })
        .fontSize(18)
      // 点击'array.sort', 对数组项升序排列，重启应用，Repeat组件展示升序数组
      Button('array.sort')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.arr.sort((tempA, tempB)=> tempA?.propA - tempB?.propA);
        })
        .fontSize(24)
      // 点击'array.reverse', 对数组项降序排列，重启应用，Repeat组件展示降序数组
      Button('array.reverse')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.arr.reverse();
        })
        .fontSize(24)
    }
    .width('100%')
  }
}
```

 ![persistencev2-sync-5](./figures/persistencev2-sync-5.gif)

## 使用场景

### 在两个页面之间存储数据

数据页面
<!-- @[persistence_v2_sample](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/persistenceV2/Sample.ets) --> 

``` TypeScript

// Sample.ets
import { Type } from '@kit.ArkUI';

// 数据中心
@ObservedV2
class SampleChild {
  @Trace public p1: number = 0;
  public p2: number = 10;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace public f: SampleChild = new SampleChild();
}
```

页面1
<!-- @[Persistence_Use_Case_Data_Page](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/persistenceV2/page/Page1.ets) --> 

``` TypeScript
// Page1.ets
import { PersistenceV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s', `error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@Entry
@ComponentV2
struct Page1 {
  // 在PersistenceV2中创建一个key为Sample的键值对（如果存在，则返回PersistenceV2中的数据），并且和prop关联
  // 对于需要换connect对象的prop属性，需要加@Local修饰（不建议对属性换connect的对象）
  @Local prop: Sample = PersistenceV2.connect(Sample, () => new Sample())!;
  pageStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pageStack) {
      Column() {
        Button('Go to page2')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
          })

        Button('Page1 connect the key Sample')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 在PersistenceV2中创建一个key为Sample的键值对（如果存在，则返回PersistenceV2中的数据），并且和prop关联
            // 不建议对prop属性换connect的对象
            this.prop = PersistenceV2.connect(Sample, 'Sample', () => new Sample())!;
          })

        Button('Page1 remove the key Sample')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 从PersistenceV2中删除后，prop将不会再与key为Sample的值关联
            PersistenceV2.remove(Sample);
          })

        Button('Page1 save the key Sample')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 如果处于connect状态，持久化key为Sample的键值对
            PersistenceV2.save(Sample);
          })

        Text(`Page1 add 1 to prop.p1: ${this.prop.f.p1}`)
          .fontSize(30)
          .margin(10)
          .onClick(() => {
            this.prop.f.p1++;
          })

        Text(`Page1 add 1 to prop.p2: ${this.prop.f.p2}`)
          .fontSize(30)
          .margin(10)
          .onClick(() => {
            // 页面不刷新，但是p2的值改变了
            this.prop.f.p2++;
          })

        // 获取当前PersistenceV2里面的所有key
        Text(`all keys in PersistenceV2: ${PersistenceV2.keys()}`)
          .fontSize(30)
          .margin(10)
      }
        .width('100%')
    }
  }
}
```

页面2
<!-- @[Persistence_Use_Case_Data_Page](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/persistenceV2/page/Page2.ets) --> 

``` TypeScript
// Page2.ets
import { PersistenceV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

@Builder
export function Page2Builder() {
  Page2()
}

@ComponentV2
struct Page2 {
  // 在PersistenceV2中创建一个key为Sample的键值对（如果存在，则返回PersistenceV2中的数据），并且和prop关联
  // 对于需要换connect对象的prop属性，需要加@Local修饰（不建议对属性换connect的对象）
  @Local prop: Sample = PersistenceV2.connect(Sample, () => new Sample())!;
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Column() {
        Button('Page2 connect the key Sample1')
          .width(300)
          .margin(10)
          .onClick(() => {
            // 在PersistenceV2中创建一个key为Sample1的键值对（如果存在，则返回PersistenceV2中的数据），并且和prop关联
            // 不建议对prop属性换connect的对象
            this.prop = PersistenceV2.connect(Sample, 'Sample1', () => new Sample())!;
          })

        Text(`Page2 add 1 to prop.p1: ${this.prop.f.p1}`)
          .fontSize(30)
          .margin(10)
          .onClick(() => {
            this.prop.f.p1++;
          })

        Text(`Page2 add 1 to prop.p2: ${this.prop.f.p2}`)
          .fontSize(30)
          .margin(10)
          .onClick(() => {
            // 页面不刷新，但是p2的值改变了；只有重新初始化才会改变
            this.prop.f.p2++;
          })

        // 获取当前PersistenceV2里面的所有key
        Text(`all keys in PersistenceV2: ${PersistenceV2.keys()}`)
          .fontSize(30)
          .margin(10)
      }
      .width('100%')
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```
使用Navigation时，需要添加配置系统路由表文件src/main/resources/base/profile/route_map.json，并替换pageSourceFile为Page2页面的路径，并且在module.json5中添加："routerMap": "$profile:route_map"。
```json
{
  "routerMap": [
    {
      "name": "Page2",
      "pageSourceFile": "src/main/ets/pages/Page2.ets",
      "buildFunction": "Page2Builder",
      "data": {
        "description" : "PersistenceV2 example"
      }
    }
  ]
}
```

![persistencev2-sync-6](./figures/persistencev2-sync-6.gif)

### 使用globalConnect存储数据

<!-- @[persistence_v2_global_connect](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/persistenceV2/PersistenceV2GlobalConnect.ets) -->   

``` TypeScript
import { PersistenceV2, Type, ConnectOptions } from '@kit.ArkUI';
import { contextConstant } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;
// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s', `error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@ObservedV2
class SampleChild {
  @Trace public childId: number = 0;
  public groupId: number = 1;
}

@ObservedV2
export class SampleGlobalConnect {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace public father: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // key不传入尝试用为type的name作为key，加密参数不传入默认加密等级为EL2
  @Local p: SampleGlobalConnect =
    PersistenceV2.globalConnect({ type: SampleGlobalConnect, defaultCreator: () => new SampleGlobalConnect() })!;
  // 使用key:global1连接，传入加密等级为EL1
  @Local p1: SampleGlobalConnect = PersistenceV2.globalConnect({
    type: SampleGlobalConnect,
    key: 'global1',
    defaultCreator: () => new SampleGlobalConnect(),
    areaMode: contextConstant.AreaMode.EL1
  })!;
  // 使用key:global2连接，使用构造函数形式，加密参数不传入默认加密等级为EL2
  options: ConnectOptions<SampleGlobalConnect> =
    { type: SampleGlobalConnect, key: 'global2', defaultCreator: () => new SampleGlobalConnect() };
  @Local p2: SampleGlobalConnect = PersistenceV2.globalConnect(this.options)!;
  // 使用key:global3连接，直接写加密数值，范围只能在0-4，否则运行会crash,例如加密设置为EL3
  @Local p3: SampleGlobalConnect = PersistenceV2.globalConnect({
    type: SampleGlobalConnect,
    key: 'global3',
    defaultCreator: () => new SampleGlobalConnect(),
    areaMode: 3
  })!;

  build() {
    Column() {
      // 显示数据
      // 被@Trace修饰的数据可以自动持久化进磁盘
      Text('Key SampleGlobalConnect: ' + this.p.father.childId.toString())
        .onClick(() => {
          this.p.father.childId += 1;
        })
        .fontSize(25)
        .margin(5)
        .fontColor(Color.Red)
      Text('Key global1: ' + this.p1.father.childId.toString())
        .onClick(() => {
          this.p1.father.childId += 1;
        })
        .fontSize(25)
        .margin(5)
        .fontColor(Color.Red)
      Text('Key global2: ' + this.p2.father.childId.toString())
        .onClick(() => {
          this.p2.father.childId += 1;
        })
        .fontSize(25)
        .margin(5)
        .fontColor(Color.Red)
      Text('Key global3: ' + this.p3.father.childId.toString())
        .onClick(() => {
          this.p3.father.childId += 1;
        })
        .fontSize(25)
        .margin(5)
        .fontColor(Color.Red)
      // keys接口
      // keys本身不会刷新，需要借助状态变量刷新
      Text('Persist keys: ' + PersistenceV2.keys().toString() + ' refresh: ' + this.refresh)
        .onClick(() => {
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(5)

      // remove接口
      Text('Remove key SampleGlobalConnect: ' + 'refresh: ' + this.refresh)
        .onClick(() => {
          // 删除这个key，会导致和p失去联系，之后即使reconnect，p也无法存储
          PersistenceV2.remove(SampleGlobalConnect);
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(5)
      Text('Remove key global1: ' + 'refresh: ' + this.refresh)
        .onClick(() => {
          // 删除这个key，会导致和p1失去联系，之后即使reconnect，p1也无法存储
          PersistenceV2.remove('global1');
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(5)
      Text('Remove key global2: ' + 'refresh: ' + this.refresh)
        .onClick(() => {
          // 删除这个key，会导致和p2失去联系，之后即使reconnect，p2也无法存储
          PersistenceV2.remove('global2');
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(5)
      Text('Remove key global3: ' + 'refresh: ' + this.refresh)
        .onClick(() => {
          // 删除这个key，会导致和p3失去联系，之后即使reconnect，p3也无法存储
          PersistenceV2.remove('global3');
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(5)
      // reConnect
      // 重新连接也无法和之前的状态变量建立联系，因此无法保存数据
      Text('ReConnect key global2: ' + 'refresh: ' + this.refresh)
        .onClick(() => {
          // 此时会重新存储一个key为global2的变量，但该变量与p2无关
          PersistenceV2.globalConnect(this.options);
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(5)

      // save接口
      Text('not save key SampleGlobalConnect: ' + this.p.father.groupId.toString() + ' refresh: ' + this.refresh)
        .onClick(() => {
          // 未被@Trace保存的对象无法自动存储
          this.p.father.groupId += 1;
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(5)
      Text('save key SampleGlobalConnect: ' + this.p.father.groupId.toString() + ' refresh: ' + this.refresh)
        .onClick(() => {
          // 未被@Trace保存的对象无法自动存储，需要调用save存储
          this.p.father.groupId += 1;
          PersistenceV2.save(SampleGlobalConnect);
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(5)
    }
    .width('100%')
  }
}
```

![persistencev2-sync-7](./figures/persistencev2-sync-7.gif)

### 在不同的module中使用connect和globalConnect

**connect的存储路径需要注意以下两点：**

1、connect使用module级别的存储路径，以最先启动的module的路径作为存储路径，从内存回写磁盘时会回写到第一个连接该module的路径。应用如果之后先从另一个module启动，则会以新module的路径作为存储路径。

2、当不同module使用相同的key时，哪个module先启动，数据就为哪个module中保存的键值对，回写到对应的module中。

**globalConnect的存储路径需要注意：**

globalConnect虽然是应用级别的路径，但是可以设置不同的加密分区，不同加密分区即代表不同的存储路径。connect不支持设置加密分区，但是module自身切换加密级别时，module存储路径也会切换成对应加密分区路径。

示例代码如下：开发者需要在项目基础上，新建一个module，并按照示例代码跳转到新module中。

<!-- @[persistence_v2_module_connect_storage_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/persistenceV2/PersistenceV2ModuleConnectStorage1.ets) --> 

``` TypeScript
// 模块1
import { PersistenceV2, Type } from '@kit.ArkUI';
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { contextConstant } from '@kit.AbilityKit';

const DOMAIN = 0x0000;

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s', `error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@ObservedV2
class SampleChild {
  @Trace public childId: number = 0;
  public groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace public father: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // 使用key:globalConnect1连接，传入加密等级为EL1
  @Local p1: Sample =
    PersistenceV2.globalConnect({
      type: Sample,
      key: 'globalConnect1',
      defaultCreator: () => new Sample(),
      areaMode: contextConstant.AreaMode.EL1
    })!;
  // 使用key:connect2连接，使用构造函数形式，加密参数不传入默认加密等级为EL2
  @Local p2: Sample = PersistenceV2.connect(Sample, 'connect2', () => new Sample())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      // 显示数据
      Text('Key globalConnect1: ' + this.p1.father.childId.toString())
        .onClick(() => {
          this.p1.father.childId += 1;
        })
        .fontSize(25)
        .margin(10)
        .fontColor(Color.Pink)
      Text('Key connect2: ' + this.p2.father.childId.toString())
        .onClick(() => {
          this.p2.father.childId += 1;
        })
        .fontSize(25)
        .margin(10)
        .fontColor(Color.Pink)

      // 跳转
      Button('Jump to newModule')
        .width(300)
        .margin(10)
        .onClick(() => { // 不同module之间使用，建议使用globalConnect
          let want: Want = {
            deviceId: '', // deviceId为空代表本设备
            bundleName: 'com.samples.paradigmstatemanagement', // 在app.json5中查看
            moduleName: 'demo', // 在需要跳转的module的module.json5中查看，非必选参数
            abilityName: 'NewModuleAbility', // 跳转启动的ability，在需要跳转的module的module.json5中查看
            uri: 'src/main/ets/pages/Index'
          };
          // context为调用方UIAbility的UIAbilityContext
          this.context.startAbility(want).then(() => {
            hilog.info(DOMAIN, 'testTag', '%{public}s', 'start ability success');
          }).catch((err: Error) => {
            hilog.error(DOMAIN, 'testTag', '%{public}s',
              `start ability failed. code is ${err.name}, message is ${err.message}`);
          });
        })
    }
    .width('100%')
    .borderWidth(3)
    .borderColor(Color.Blue)
    .margin({ top: 5, bottom: 5 })
  }
}
```

![persistencev2-sync-8](./figures/persistencev2-sync-8.png)

<!-- @[persistence_v2_module_connect_storage_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/demo/src/main/ets/pages/Index.ets) -->  

``` TypeScript
// 模块2
import { PersistenceV2, Type } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { contextConstant } from '@kit.AbilityKit';

const DOMAIN = 0x0000;
// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s', `error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@ObservedV2
class SampleChild {
  @Trace public childId: number = 0;
  public groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace public father: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Page1 {
  @Local a: number = 0;
  // 使用key:globalConnect1连接，传入加密等级为EL1
  @Local p1: Sample =
    PersistenceV2.globalConnect({ type: Sample, key: 'globalConnect1', defaultCreator: () => new Sample(), areaMode: contextConstant.AreaMode.EL1 })!;
  // 使用key:connect2连接，使用构造函数形式，加密参数不传入默认加密等级为EL2
  @Local p2: Sample = PersistenceV2.connect(Sample, 'connect2', () => new Sample())!;

  build() {
    Column() {
      // 显示数据
      Text('Key globalConnect1: ' + this.p1.father.childId.toString())
        .onClick(() => {
          this.p1.father.childId += 1;
        })
        .fontSize(25)
        .margin(10)
        .fontColor(Color.Red)
      Text('Key connect2: ' + this.p2.father.childId.toString())
        .onClick(() => {
          this.p2.father.childId += 1;
        })
        .fontSize(25)
        .margin(10)
        .fontColor(Color.Red)
    }
    .width('100%')
  }
}
```

![persistencev2-sync-9](./figures/persistencev2-sync-9.png)

当开发者对newModule使用不同启动方式会有以下现象：

*   开发者直接启动newModule，分别修改globalConnect1和connect2绑定的变量，例如将childId都改成5。
* 应用退出并清空后台，启动模块entry，通过跳转按键启动newModule，会发现globalConnect1值为5，而connect2值为0未修改。
* globalConnect为应用级别存储，对于一个key，整个应用在对应加密分区只有一份存储路径；connect为module级别的存储路径，会因为module的启动方式不同而在各自的加密分区对应不同的存储路径。

### 通过notifyOnError获取旧的序列化数据

当存储数据的结构与当前数据的结构不同时，可能会导致反序列化失败。从API版本26.0.0开始，开发者可通过向notifyOnError的入参回调中加入oldValue参数来获取存于磁盘的旧的序列化数据，从而直观感知到数据结构的差异。

<!-- @[persistence_v2_notifyOnError](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/persistenceV2/PersistenceV2NotifyOnError.ets) --> 

``` TypeScript
import { PersistenceV2, Type } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string, oldValue?: string) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s',
    `error key: ${key}, reason: ${reason}, message: ${msg}, oldValue: ${oldValue}`);
});

@ObservedV2
class SampleInfo {
  @Trace public info: boolean = true;
  @Trace public propertyName: string = 'Hello';
}

@ObservedV2
class SampleChild {
  // 起始时childInfo类型为SampleInfo，使用connect/globalConnect将其存储到磁盘
  @Type(SampleInfo)
  @Trace public childInfo: SampleInfo = new SampleInfo();
  // 将childInfo类型切换为number，并重新运行
  // @Trace public childInfo: number = 0;
  public groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace public father: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Index {
  @Local refresh: number = 0;
  // 调用connect或globalConnect存储
  @Local p: Sample = PersistenceV2.connect(Sample, 'connectSample', () => new Sample())!;
  // @Local p: Sample = PersistenceV2.globalConnect(
  //   { type: Sample, key: 'connectSample', defaultCreator: () => new Sample() })!;

  build() {
    Column({ space: 5 }) {
      // 显示数据
      Text('Key connectSample: ' + this.p.father.groupId.toString())
        .onClick(() => {
          this.p.father.groupId += 1;
        })
        .fontSize(25)
        .margin(10)
        .fontColor(Color.Red)

      // save接口
      // 未被@Trace装饰的变量需要借助状态变量refresh才能刷新
      Text('save key connectSample: ' + this.p.father.groupId.toString() + ' refresh:' + this.refresh)
        .onClick(() => {
          // 未被@Trace保存的对象无法自动存储，需要调用save存储
          this.p.father.groupId += 1;
          PersistenceV2.save('connectSample');
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(10)
    }
    .width('100%')
  }
}
```

![persistencev2-sync-10](./figures/persistencev2-sync-10.gif)

起始时，SampleChild中的childInfo变量类型为SampleInfo，正常存储后，将childInfo变量的类型切换为number，并赋值为1，之后再次启动程序，此时会由于存储数据的结构与当前数据的结构不一致，导致数据反序列化失败。此时会通过notifyOnError中写入的回调，将磁盘中存储的旧的序列化数据打印出来。即在Error日志中显示：
```text
error key: connectSample, reason: serialization, message: TypeError: Receiver is not a JSObject, oldValue: {"father":{"childInfo":{"info":true,"propertyName":"Hello"},"groupId":1}}
```

## 使用建议

建议开发者使用新接口globalConnect创建和获取数据。globalConnect的存储规格和内存规格一致，对于应用只有一份，并且支持设置加密级别，不需要去切换ability的加密才能设置数据的加密级别。当然如果开发者应用不涉及多模块，保持使用connect也不会有影响。

### connect向globalConnect迁移实现

<!-- @[persistence_v2_connect_migration_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/persistenceV2/PersistenceV2ConnectMigration1.ets) --> 

``` TypeScript
// 使用connect存储数据
import { PersistenceV2, Type } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s', `error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@ObservedV2
class SampleChild {
  @Trace public childId: number = 0;
  public groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace public father: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // 使用key:connect3存储
  @Local p: Sample = PersistenceV2.connect(Sample, 'connect3', () => new Sample())!;

  build() {
    Column({ space: 5 }) {
      // 显示数据
      Text('Key connect3: ' + this.p.father.childId.toString())
        .onClick(() => {
          this.p.father.childId += 1;
        })
        .fontSize(25)
        .margin(10)
        .fontColor(Color.Red)

      // save接口
      // 未被@Trace装饰的变量需要借助状态变量refresh才能刷新
      Text('save key connect3: ' + this.p.father.groupId.toString() + ' refresh:' + this.refresh)
        .onClick(() => {
          // 未被@Trace保存的对象无法自动存储，需要调用save存储
          this.p.father.groupId += 1;
          PersistenceV2.save('connect3');
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(10)
    }
    .width('100%')
  }
}
```

![persistencev2-sync-11](./figures/persistencev2-sync-11.gif)

<!-- @[persistence_v2_connect_migration_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/persistenceV2/PersistenceV2ConnectMigration2.ets) -->  

``` TypeScript
// 迁移到globalConnect
import { PersistenceV2, Type } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s', `error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@ObservedV2
class SampleChild {
  @Trace public childId: number = 0;
  public groupId: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(SampleChild)
  @Trace public father: SampleChild = new SampleChild();
}

// 用于判断是否完成数据迁移的辅助数据
@ObservedV2
class StorageState {
  @Trace public isCompleteMoving: boolean = false;
}

function move() {
  let movingState = PersistenceV2.globalConnect({ type: StorageState, defaultCreator: () => new StorageState() })!;
  if (!movingState.isCompleteMoving) {
    let p: Sample = PersistenceV2.connect(Sample, 'connect3', () => new Sample())!;
    PersistenceV2.remove('connect3');
    let p1 = PersistenceV2.globalConnect({ type: Sample, key: 'connect4', defaultCreator: () => p })!; // 使用默认构造函数也可以
    // 赋值数据，@Trace修饰的会自动保存
    p1.father = p.father;
    // 将迁移标志设置为true
    movingState.isCompleteMoving = true;
  }
}

move();

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // 使用key:connect4存入数据
  @Local p: Sample =
    PersistenceV2.globalConnect({ type: Sample, key: 'connect4', defaultCreator: () => new Sample() })!;

  build() {
    Column({ space: 5 }) {
      // 显示数据
      Text('Key connect4: ' + this.p.father.childId.toString())
        .onClick(() => {
          this.p.father.childId += 1;
        })
        .fontSize(25)
        .margin(10)
        .fontColor(Color.Red)

      // save接口
      // 未被@Trace装饰的变量需要借助状态变量refresh才能刷新
      Text('save key connect4: ' + this.p.father.groupId.toString() + ' refresh:' + this.refresh)
        .onClick(() => {
          // 未被@Trace保存的对象无法自动存储，需要调用save存储
          this.p.father.groupId += 1;
          PersistenceV2.save('connect4');
          this.refresh += 1;
        })
        .fontSize(25)
        .margin(10)
    }
    .width('100%')
  }
}
```

![persistencev2-sync-12](./figures/persistencev2-sync-12.gif)

connect向globalConnect迁移，需要将key绑定的value赋值给globalConnect进行存储，之后当自定义组件使用globalConnect连接时，globalConnect绑定的数据即为之前使用connect保存的数据，开发者可以自定义move函数，并将其放在合适位置迁移即可。

### 使用connect/globalConnect存储数据后，不建议变更数据结构

在使用connect/globalConnect存储数据后，不建议变更数据结构，因为变更数据结构可能导致存储的数据反序列化失败，从而无法获取之前的数据。上文[通过notifyOnError获取旧的序列化数据](#通过notifyonerror获取旧的序列化数据)介绍了在变更数据结构后，如何通过旧的序列化数据定位数据结构的具体变更。但是，某些场景下由于代码实现中存在数据结构隐式转换等原因，不会触发notifyOnError，导致无法获取旧的序列化数据，例如下面代码所示场景。

<!-- @[persistence_v2_change_data_structure](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/persistenceV2/PersistenceV2ChangeDataStructure.ets) -->  

``` TypeScript
import { PersistenceV2, Type } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string, oldValue?: string) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s',
    `error key: ${key}, reason: ${reason}, message: ${msg}, oldValue: ${oldValue}`);
});

@ObservedV2
class SampleChild {
  @Trace public info: string = 'Hello';
}

@ObservedV2
class Sample {
  // 起始时childInfo类型为SampleChild，使用connect/globalConnect将其存储到磁盘
  @Type(SampleChild)
  @Trace public childInfo: SampleChild = new SampleChild();
}

@Entry
@ComponentV2
struct Index {
  // 调用connect或globalConnect存储
  @Local sample: Sample =
    PersistenceV2.globalConnect({ type: Sample, key: 'connectSample', defaultCreator: () => new Sample() })!;

  build() {
    Column({ space: 5 }) {
      Text(JSON.stringify(this.sample)) // 序列化sample变量并显示
        .fontSize(20)
        .margin(10)
      Button('Change Info')
        .width(300)
        .margin(10)
        .onClick(() => {
          // 通过将类型转换为ESObject，再转为SampleChild，绕过了类型校验，故点击后不会触发notifyOnError。
          // 点击并重新运行后，由于此处存储的info为Array类型，但SampleChild中的info仍是string类型，故会触发notifyOnError。
          this.sample.childInfo = { info: [1, 2] } as ESObject as SampleChild;
        })
    }
    .width('100%')
  }
}
```

![persistencev2-sync-13](./figures/persistencev2-sync-13.png)

下表将结合样例，说明在变更数据结构时会触发notifyOnError的情形。

> **说明：** 
>
>1、oldValue为notifyOnError的入参回调的参数，用于在反序列化失败时，获取旧的序列化数据。
>
>2、下表中会触发notifyOnError的类型，指的是将原始类型改变后，会触发notifyOnError回调的类型。
>
>3、下表中的类型，均是指class中属性的类型。
>
>4、在反序列化时，如果属性类型为Object，则会递归遍历并反序列化其内部属性。

**使用PersistenceV2.connect在数据结构变更后触发notifyOnError情况表**

| 原始类型 | 样例 | 样例的序列化存储结果 | 会触发notifyOnError的类型 | oldValue |
|---|---|---|---|---|
| number | `50` | `50` | boolean, Array, Set, Map, Object | `50` |
| boolean | `true` | `true` | number, Array, Set, Map, Object | `true` |
| string | `'hello'` | `"hello"` | number, boolean, Array, Set, Map, Object | `"hello"` |
| Array | `new Array<number>([1,2,3])` | `[1,2,3]` | number, boolean, string | `[1,2,3]` |
| Set | `new Set<number>([1,2,3])` | `[1,2,3]` | number, boolean, string | `[1,2,3]` |
| Map | `new Map<string, number>([['a',1],['b',2]])` | `[["a",1],["b",2]]` | number, boolean, string, Array, Date | `[["a",1],["b",2]]` |
| Date | `new Date()` | `"2026-03-26T00:00:00.000Z"` | number, boolean, Array, Set, Map, Object | `"2026-03-26T00:00:00.000Z"` |
| Object | `new Class A { public info: number = 100; }` | `{"info":100}` | number, boolean, string | `{"info":100}` |

**使用PersistenceV2.globalConnect在数据结构变更后触发notifyOnError情况表**

| 原始类型 | 样例 | 样例的序列化存储结果 | 会触发notifyOnError的类型 | oldValue |
|---|---|---|---|---|
| number | `50` | `50` | 无 | 无 |
| boolean | `true` | `true` | 无 | 无 |
| string | `'hello'` | `"hello"` | 无 | 无 |
| Array | `new Array<number>([1,2,3])` | `\"Ar0003[1,2,3]\"` | number, boolean, string, Set, Map, Date, Object | `[1,2,3]` |
| Set | `new Set<number>([1,2,3])` | `\"Se0003\\\"Ar0004[1,2,3]\\\"\"` | number, boolean, string, Array, Map, Date, Object | `[1,2,3]` |
| Map | `new Map<string, number>([['a',1],['b',2]])` | `\"Ma0003[[\\\"a\\\",\\\"1\\\"],[\\\"b\\\",\\\"2\\\"]]\"` | number, boolean, string, Array, Set, Date, Object | `[["a",1],["b",2]]` |
| Date | `new Date()` | `\"Da00032026-03-26T00:00:00.000Z\"` | 无 | 无 |
| Object | `new Class A { public info: number = 100; }` | `\"0b0003{\\\"info\\\":100}\"` | number, boolean, string |  `{"info":100}` |