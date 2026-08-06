# \@Type装饰器：标记类属性的类型
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

为了实现序列化类时不丢失属性的复杂类型，开发者可以使用[\@Type](../../reference/apis-arkui/arkui-ts/ts-state-management-type.md#type)装饰器装饰类属性。

\@Type的目的是标记类属性，配合PersistenceV2使用，防止序列化时类丢失。在阅读本文档前，建议提前阅读：[PersistenceV2](./arkts-new-persistencev2.md)。

>**说明：**
>
> \@Type从API version 12开始支持。
>
> 从API version 12开始，该装饰器支持在原子化服务中使用。

## 概述

\@Type标记类属性，使得类属性序列化时不丢失类型信息，便于类的反序列化。

## 装饰器说明

| \@Type装饰器 | 说明 |
| ------------------- | ------------------------------------------------------------ |
| 装饰器参数 | type：类型。 |
| 可装饰的类型 | Object class以及Array、Date、Map、Set等内嵌类型。 |

## 使用限制

1. 只能用在[\@ObservedV2](./arkts-new-observedV2-and-trace.md)装饰的类中，不能用在自定义组件中。

   <!-- @[DataModel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NewType/entry/src/main/ets/pages/DataModel.ets) --> 
   
   ``` TypeScript
   class Sample {
     private data: number = 0;
   }
   @ObservedV2
   class Info {
     @Type(Sample)
     @Trace public sample: Sample = new Sample(); // 正确用法
   }
   ```

   ```ts
    @Observed
    class Info2 {
      @Type(Sample)
      sample: Sample = new Sample(); // 错误用法，不能用在@Observed装饰的类中，编译时报错
    }
    @ComponentV2
    struct Index {
      @Type(Sample)
      sample: Sample = new Sample(); // 错误用法，不能用在自定义组件中，编译时报错
      build() {
      }
    }
   ```

2. 不支持collections.Set、collections.Map等类型。

3. 不支持非built-in类型。如[PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md)、NativePointer、[ArrayList](../../reference/apis-arkts/js-apis-arraylist.md)等Native类型。

4. 不支持简单类型。如string、number、boolean等。

5. 不支持构造函数含参的类。

## 使用场景

### 持久化数据

<!-- @[NewType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NewType/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { PersistenceV2, Type } from '@kit.ArkUI';

@ObservedV2
class SampleChild {
  @Trace childNumber: number = 1;
}

@ObservedV2
class Sample {
  // 对于复杂对象需要@Type修饰，确保反序列化成功，去掉@Type会反序列化值失败。
  @Type(SampleChild)
  // 对于没有初值的类属性，经过@Type修饰后，需要手动保存，否则持久化失败。
  // 无法使用@Type修饰的类属性，必须要有初值才能持久化。
  @Trace sampleChild?: SampleChild = undefined;
}

@Entry
@ComponentV2
struct TestCase {
  @Local sample: Sample = PersistenceV2.connect(Sample, () => new Sample)!;

  build() {
    Column() {
      Text('childNumber value:' + this.sample.sampleChild?.childNumber)
        .fontSize(30)
        .margin(10)
        .onClick(() => {
          this.sample.sampleChild = new SampleChild();
          this.sample.sampleChild.childNumber = 2;
          PersistenceV2.save(Sample);
        })
    }
    .width('100%')
  }
}
```

![type-sync-0](./figures/type-sync-0.gif)

## 常见问题

### \@Type传入容器泛型而非元素类型

\@Type装饰`Array<T>`、`Set<T>`、`Map<string, T>`等容器类型的属性时，应传入元素类型T对应的类，不应传入`Array<T>`等容器泛型。泛型参数在运行时会被擦除，`@Type(Array<T>)`等同于`@Type(Array)`，`@Type(Set<T>)`等同于`@Type(Set)`，框架无法从中获知元素类型为T。

| 属性类型 | \@Type应传入 | 不应传入 |
|---|---|---|
| `Array<T>` | `T` | `Array<T>`、`Array` |
| `Set<T>` | `T` | `Set<T>`、`Set` |
| `Map<string, T>` | `T` | `Map<string, T>`、`Map` |

当T为基本类型、Date、Array、Set、Map等非自定义类时，框架原生支持反序列化，\@Type参数不影响结果。当T为自定义类时，首次运行数据可正常保存，但应用重启从磁盘恢复数据时，反序列化创建空容器实例（如`new Array()`）而非`new T()`，T的构造函数不执行，T的属性未被初始化。反序列化结果取决于T的属性序列化后的值类型：值为基本类型或对象时被隐式转换为undefined，值为数组时打印Error日志，错误码为140107。具体如下：

| T的属性类型 | 序列化后的值 | 反序列化结果 |
|---|---|---|
| number、string、boolean | 基本类型 | 隐式转换为undefined，无报错 |
| Date | 字符串 | 隐式转换为undefined，无报错 |
| Array、Set、Map | 数组 | 打印Error日志，错误码为140107 |
| 自定义类 | 对象 | 隐式转换为undefined，无报错 |

以下示例中，元素类型ItemModel包含基本类型属性和容器类型属性，使用`@Type(Array<ItemModel>)`后应用重启将触发上述问题：

```TypeScript
import { PersistenceV2, Type } from '@kit.ArkUI';

@ObservedV2
class ItemModel {
  @Trace num: number = 1;
  @Trace arr: Array<number> = [1, 2, 3];
  @Trace set: Set<number> = new Set([1, 2, 3]);
}

@ObservedV2
class Data {
  @Type(Array<ItemModel>)
  // 错误用法：运行时退化为@Type(Array)，传入容器类型而非元素类型
  // 反序列化时创建new Array()而非new ItemModel()，ItemModel的构造函数不执行，num、arr、set属性均未初始化
  // num序列化后为基本类型，反序列化时被隐式转换为undefined；arr、set序列化后为数组，反序列化时打印Error日志，错误码为140107
  // Set<T>、Map<string, T>场景传入@Type(Set<T>)或@Type(Map<string, T>)同理
  @Trace items: Array<ItemModel> = new Array();
}

@Entry
@ComponentV2
struct TestCase {
  @Local data: Data = PersistenceV2.connect(Data, () => new Data())!;

  build() {
    Column() {
      Button('push and save')
        .onClick(() => {
          this.data.items.push(new ItemModel());
          // 手动持久化数据到磁盘
          PersistenceV2.save(Data);
        })
    }
  }
}
```

上述示例中，首次点击按钮将ItemModel实例存入数组并保存到磁盘后，结束进程，第二次重新启动时，执行反序列化失败，打印如下Error日志：

```text
FIX THIS APPLICATION ERROR: For PersistenceV2 'Data' key has error, error code: 140107, message: The type of target 'undefined' mismatches the type of source 'object'
```

正确写法是将\@Type参数改为元素类型T对应的类，对`Array<T>`、`Set<T>`、`Map<string, T>`均适用：

```TypeScript
@ObservedV2
class Data {
  @Type(ItemModel) // 正确用法：传入元素类型ItemModel对应的类
  @Trace items: Array<ItemModel> = new Array();
}
```
