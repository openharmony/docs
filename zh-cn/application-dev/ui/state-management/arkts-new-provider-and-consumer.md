# \@Provider装饰器和\@Consumer装饰器：跨组件层级双向同步
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

[\@Provider](../../reference/apis-arkui/arkui-ts/ts-state-management-provider.md#provider)和[\@Consumer](../../reference/apis-arkui/arkui-ts/ts-state-management-consumer.md#consumer)用于跨组件层级数据双向同步，可以使得开发者不用拘泥于组件层级。

\@Provider和\@Consumer属于状态管理V2装饰器，所以只能在[\@ComponentV2](./arkts-create-custom-components.md#componentv2)中才能使用，在[\@Component](./arkts-create-custom-components.md)中使用会编译报错。

\@Provider和\@Consumer提供了跨组件层级数据双向同步的能力。在阅读本文档前，建议提前阅读：[\@ComponentV2](./arkts-create-custom-components.md#componentv2)。常见问题请参考[组件内状态变量常见问题](./arkts-state-management-faq-inner-component.md)。

>**说明：**
>
> \@Provider和\@Consumer装饰器从API version 12开始支持。
>
> 从API version 12开始，\@Provider和\@Consumer装饰器支持在原子化服务中使用。
>
> 从API version 23开始，通过配置[BuilderNode](../../reference/apis-arkui/js-apis-arkui-builderNode.md)的[BuildOptions](../../reference/apis-arkui/js-apis-arkui-builderNode.md#buildoptions12)参数`enableProvideConsumeCrossing`为true，使得\@Provider和\@Consumer支持跨[BuilderNode](../../reference/apis-arkui/js-apis-arkui-builderNode.md)双向同步。在BuilderNode挂载到自定义组件节点树之后，\@Consumer会重新获取最近的\@Provider数据，与之建立双向同步关系。具体可见[\@Consumer在跨BuilderNode场景下和\@Provider建立双向同步](#consumer在跨buildernode场景下和provider建立双向同步过程)。
>
> 从API version 23开始，\@Provider和\@Consumer装饰器支持在ArkTS卡片中使用。

## 概述

\@Provider，即数据提供方，其所有的子组件都可以通过\@Consumer绑定相同的key来获取\@Provider提供的数据。

\@Consumer，即数据消费方，可以通过绑定同样的key获取其最近父节点的\@Provider的数据，当查找不到\@Provider的数据时，使用本地默认值。图示如下。

![ProviderConsumer_1](./figures/Provider_Consumer_1.png)

\@Provider和\@Consumer装饰的数据类型需要一致。

开发者在使用\@Provider和\@Consumer时要注意：
- \@Provider和\@Consumer强依赖自定义组件层级，\@Consumer会因为所在组件的父组件不同，而被初始化为不同的值。
- \@Provider和\@Consumer相当于把组件粘合在一起了，从组件独立角度考虑，应减少使用\@Provider和\@Consumer。

## \@Provider和\@Consumer vs \@Provide和\@Consume能力对比
在状态管理V1版本中，提供跨组件层级双向的装饰器为[\@Provide和\@Consume](./arkts-provide-and-consume.md)，当前文档介绍的是状态管理V2装饰器\@Provider和\@Consumer。虽然两者名字和功能类似，但在特性上还存在一些差异。

如果开发者不了解状态管理V1中的\@Provide和\@Consume，可以直接跳过本节。

| 能力 | V2装饰器\@Provider和\@Consumer                                             |V1装饰器\@Provide和\@Consume|
| ------------------ | ----------------------------------------------------- |----------------------------------------------------- |
| \@Consume(r)         |必须本地初始化，当找不到\@Provider时使用本地默认值。| API version 20以前，@Consume禁止本地初始化，当找不到对应\@Provide的时候，会抛出异常；从API version 20开始，@Consume支持设置默认值，如果没有设置默认值，且找不到对应\@Provide时，会抛出异常。 |
| 支持类型           | 支持function。 | 不支持function。 |
| 观察能力           | 仅能观察数据本身的变化，如果要观察嵌套场景，配合[\@Trace](arkts-new-observedV2-and-trace.md)一起使用。 | 观察第一层变化，如果要观察嵌套场景，配合[\@Observed和\@ObjectLink](arkts-observed-and-objectlink.md)一起使用。 |
| alias和属性名         | alias是唯一匹配的key，缺省时默认属性名为alias。 | alias和属性名都为key，优先匹配alias，匹配不到可以匹配属性名。|
| \@Provide(r) 从父组件初始化      | 不允许。 | 允许。|
| \@Provide(r)支持重载  | 默认开启，即\@Provider可以重名，\@Consumer向上查找最近的\@Provider。 | 默认关闭，即在组件树上不允许有同名\@Provide。如果需要重载，则需要配置allowOverride。|

## 装饰器说明

### 基本规则
\@Provider语法：

`@Provider(aliasName?: string) varName : varType = initValue`

| \@Provider属性装饰器 | 说明                                                  |
| ------------------ | ----------------------------------------------------- |
| 装饰器参数         | `aliasName?: string`，别名，缺省时默认为属性名。|
| 支持类型           | 自定义组件中成员变量。属性的类型可以为number、string、boolean、class、[Array](#装饰array类型变量)、[Date](#装饰date类型变量)、[Map](#装饰map类型变量)、[Set](#装饰set类型变量)等类型。支持装饰[箭头函数](#provider和consumer装饰回调事件用于组件之间完成行为抽象)。 |
| 从父组件初始化      | 禁止。 |
| 本地初始化         | 必须本地初始化。 |
| 观察能力         | 能力等同于\@Trace。变化会同步给对应的\@Consumer。 |

\@Consumer语法：

`@Consumer(aliasName?: string) varName : varType = initValue`

| \@Consumer属性装饰器 | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| 装饰器参数            | `aliasName?: string`，别名，缺省时默认为属性名，向上查找最近的\@Provider。    |
| 可装饰的变量          | 自定义组件中成员变量。属性的类型可以为number、string、boolean、class、Array、Date、Map、Set等类型。支持装饰箭头函数。 |
| 从父组件初始化      | 禁止。 |
| 本地初始化         | 必须本地初始化。 |
| 观察能力         | 能力等同于\@Trace。变化会同步给对应的\@Provider。 |

### aliasName和属性名

\@Provider和\@Consumer接受可选参数aliasName，没有配置参数时，使用属性名作为默认的aliasName。

>**说明：**
>
> aliasName是用于\@Provider和\@Consumer进行匹配的唯一指定key。

以下三个例子可清楚介绍\@Provider和\@Consumer如何使用aliasName进行查找匹配。

```ts
@ComponentV2
struct Parent {
  // 未定义aliasName, 使用属性名'str'作为aliasName
  @Provider() str: string = 'hello';
}

@ComponentV2
struct Child {
  // 定义aliasName为'str'，使用aliasName去寻找
  // 能够在Parent组件上找到, 使用@Provider的值'hello'
  @Consumer('str') str: string = 'world';
}
```

```ts
@ComponentV2
struct Parent {
  // 定义aliasName为'alias'
  @Provider('alias') str: string = 'hello';
}

@ComponentV2 
struct Child {
  // 定义aliasName为 'alias'，找到@Provider并获得值'hello'
  @Consumer('alias') str: string = 'world';
}
```

```ts
@ComponentV2
struct Parent {
  // 定义aliasName为'alias'
  @Provider('alias') str: string = 'hello';
}

@ComponentV2
struct Child {
  // 未定义aliasName，使用属性名'str'作为aliasName
  // 没有找到对应的@Provider，使用本地值'world'
  @Consumer() str: string = 'world';
}
```

## 变量传递

| 传递规则       | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| 从父组件初始化 | \@Provider和\@Consumer装饰的变量仅允许本地初始化，不允许从外部传入初始化。 |
| 初始化子组件   | \@Provider和\@Consumer装饰的变量可以初始化子组件中[\@Param](./arkts-new-param.md)装饰的变量。 |

## 使用限制

1. \@Provider和\@Consumer为自定义组件的属性装饰器，只能装饰自定义组件内的属性，不能装饰class的属性。
2. \@Provider和\@Consumer为状态管理V2装饰器，只能在\@ComponentV2中使用，不能在\@Component中使用。
3. \@Provider和\@Consumer只支持本地初始化，不支持外部传入初始化。

## 使用场景

### \@Provider和\@Consumer双向同步

**建立双向绑定**

1. 自定义组件Parent和Child初始化：
    - Child中`@Consumer() str: string = 'world'`向上查找，查找到Parent中声明的`@Provider() str: string = 'hello'`。
    - `@Consumer() str: string = 'world'`初始化为其查找到的`@Provider`的值，即'hello'。
    - 两者建立双向同步关系。
2. 点击Parent中的按钮，改变\@Provider装饰的str，通知其对应的\@Consumer，对应UI刷新。
3. 点击Child中的按钮，改变\@Consumer装饰的str，通知其对应的\@Provider，对应UI刷新。

<!-- @[Twoway_Binding](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/TwowayBinding.ets) --> 

``` TypeScript
@Entry
@ComponentV2
struct Parent {
  @Provider() str: string = 'hello';

  build() {
    Column() {
      Button(this.str)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.str += '0';
        })
      Child()
    }
    .width('100%')
  }
}

@ComponentV2
struct Child {
  // @Consumer装饰的属性str和Parent组件中@Provider装饰的属性str名称相同，因此建立了双向绑定关系
  @Consumer() str: string = 'world';

  build() {
    Column() {
      Button(this.str)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.str += '0';
        })
    }
    .width('100%')
  }
}
```

![provider-sync-0](figures/provider-sync-0.gif)

**未建立双向绑定**

下面的例子中，\@Provider和\@Consumer由于aliasName值不同，无法建立双向同步关系。
1. 自定义组件Parent和Child初始化：
    - Child中`@Consumer() str: string = 'world'`向上查找，未查找到其数据提供方@Provider。
    - `@Consumer() str: string = 'world'`使用其本地默认值为'world'。
    - 两者未建立双向同步关系。
2. 点击Parent中的按钮，改变\@Provider装饰的str1，仅刷新\@Provider关联的Button组件。
3. 点击Child中的按钮，改变\@Consumer装饰的str，仅刷新\@Consumer关联的Button组件。

<!-- @[No_Twoway_Binding](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/NoTwowayBinding.ets) --> 

``` TypeScript
@Entry
@ComponentV2
struct Parent {
  @Provider() str1: string = 'hello';

  build() {
    Column() {
      Button(this.str1)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.str1 += '0';
        })
      Child()
    }
    .width('100%')
  }
}

@ComponentV2
struct Child {
  // @Consumer装饰的属性str和Parent组件中@Provider装饰的属性str1名称不同，无法建立双向绑定关系
  @Consumer() str: string = 'world';

  build() {
    Column() {
      Button(this.str)
        .width(300)
        .margin(10)
        .onClick(() => {
          this.str += '0';
        })
    }
    .width('100%')
  }
}
```

![provider-sync-1](figures/provider-sync-1.gif)

### 装饰Array类型变量

当装饰的对象是Array时，可以观察到Array整体的赋值，同时可以通过调用Array的接口`push`, `pop`, `shift`, `unshift`, `splice`, `copyWithin`, `fill`, `reverse`, `sort`更新Array中的数据。

<!-- @[Decorative_Array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/DecorativeArray.ets) -->  

``` TypeScript
@Entry
@ComponentV2
struct Parent {
  @Provider() count: number[] = [1, 2, 3];

  build() {
    Row() {
      Column() {
        ForEach(this.count, (item: number) => {
          Text(`parent: ${item}`)
            .fontSize(30)
            .margin(10)
          Divider()
        })
        // count被@Provider装饰，可以被观察到Array整体的赋值以及调用Array接口带来的变化
        Button('push')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.count.push(111);
          })
        Button('reverse')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.count.reverse();
          })
        Button('fill')
          .width(300)
          .margin(10)
          .onClick(() => {
            this.count.fill(6);
          })
        Child()
      }
      .width('100%')
    }
    .height('100%')
  }
}

@ComponentV2
struct Child {
  @Consumer() count: number[] = [9, 8, 7];

  build() {
    Column() {
      ForEach(this.count, (item: number) => {
        Text(`child: ${item}`)
          .fontSize(30)
          .margin(10)
        Divider()
      })
      // count被@Consumer装饰，可以被观察到Array整体的赋值以及调用Array接口带来的变化
      Button('push')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.count.push(222);
        })
      Button('reverse')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.count.reverse();
        })
      Button('fill')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.count.fill(8);
        })
    }
    .width('100%')
  }
}
```

![provider-sync-2](figures/provider-sync-2.gif)

### 装饰Date类型变量

当装饰Date类型变量时，可以观察到数据源对Date整体的赋值，以及调用Date的接口`setFullYear`, `setMonth`, `setDate`, `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, `setUTCFullYear`, `setUTCMonth`, `setUTCDate`, `setUTCHours`, `setUTCMinutes`, `setUTCSeconds`, `setUTCMilliseconds`带来的变化。

<!-- @[Decorative_Date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/DecorativeDate.ets) -->  

``` TypeScript
@Entry
@ComponentV2
struct Parent {
  @Provider() selectedDate: Date = new Date('2021-08-08');

  build() {
    Column() {
      Text(`parent: ${this.selectedDate}`)
        .fontSize(20)
        .margin(10)
      // selectedDate被@Provider装饰，可以被观察到Date整体的赋值以及调用Date接口带来的变化
      Button('update the new date')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.selectedDate = new Date('2023-07-07');
        })
      Button('increase the year by 1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1);
        })
      Button('increase the month by 1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.selectedDate.setMonth(this.selectedDate.getMonth() + 1);
        })
      Button('increase the day by 1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.selectedDate.setDate(this.selectedDate.getDate() + 1);
        })
      Child()
    }
    .width('100%')
  }
}

@ComponentV2
struct Child {
  @Consumer() selectedDate: Date = new Date('2022-07-07');

  build() {
    Column() {
      Text(`child: ${this.selectedDate}`)
        .fontSize(20)
        .margin(10)
      // selectedDate被@Consumer装饰，可以被观察到Date整体的赋值以及调用Date接口带来的变化
      Button('update the new date')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.selectedDate = new Date('2025-01-01');
        })
      Button('increase the year by 1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1);
        })
      Button('increase the month by 1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.selectedDate.setMonth(this.selectedDate.getMonth() + 1);
        })
      Button('increase the day by 1')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.selectedDate.setDate(this.selectedDate.getDate() + 1);
        })
    }
    .width('100%')
  }
}
```

![provider-sync-3](figures/provider-sync-3.gif)

### 装饰Map类型变量

当装饰Map类型变量时，可以观察到数据源对Map整体的赋值，以及调用Map的接口`set`, `clear`, `delete`带来的变化。

<!-- @[Decorative_Map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/DecorativeMap.ets) -->  

``` TypeScript
@Entry
@ComponentV2
struct Parent {
  @Provider() message: Map<number, string> = new Map([[0, 'a'], [1, 'b'], [3, 'c']]);

  build() {
    Column() {
      Text('Parent')
        .fontSize(20)
        .margin(5)
      ForEach(Array.from(this.message.entries()), (item: [number, string]) => {
        Text(`${item[0]}`)
          .fontSize(20)
        Text(`${item[1]}`)
          .fontSize(20)
        Divider()
      })
      // message被@Provider装饰，可以被观察到Map整体的赋值以及调用Map接口带来的变化
      Button('init map')
        .width(300)
        .margin(5)
        .onClick(() => {
          this.message = new Map([[0, 'aa'], [1, 'bb'], [3, 'cc']]);
        })
      Button('set new one')
        .width(300)
        .margin(5)
        .onClick(() => {
          this.message.set(4, 'd');
        })
      Button('clear')
        .width(300)
        .margin(5)
        .onClick(() => {
          this.message.clear();
        })
      Button('replace the first one')
        .width(300)
        .margin(5)
        .onClick(() => {
          this.message.set(0, 'a~');
        })
      Button('delete the first one')
        .width(300)
        .margin(5)
        .onClick(() => {
          this.message.delete(0);
        })
      Child()
    }
    .width('100%')
  }
}

@ComponentV2
struct Child {
  @Consumer() message: Map<number, string> = new Map([[0, 'd'], [1, 'e'], [3, 'f']]);

  build() {
    Column() {
      Text('Child')
        .fontSize(20)
        .margin(5)
      ForEach(Array.from(this.message.entries()), (item: [number, string]) => {
        Text(`${item[0]}`)
          .fontSize(20)
        Text(`${item[1]}`)
          .fontSize(20)
        Divider()
      })
      // message被@Consumer装饰，可以被观察到Map整体的赋值以及调用Map接口带来的变化
      Button('init map')
        .width(300)
        .margin(5)
        .onClick(() => {
          this.message = new Map([[0, 'dd'], [1, 'ee'], [3, 'ff']]);
        })
      Button('set new one')
        .width(300)
        .margin(5)
        .onClick(() => {
          this.message.set(4, 'g');
        })
      Button('clear')
        .width(300)
        .margin(5)
        .onClick(() => {
          this.message.clear();
        })
      Button('replace the first one')
        .width(300)
        .margin(5)
        .onClick(() => {
          this.message.set(0, 'a*');
        })
      Button('delete the first one')
        .width(300)
        .margin(5)
        .onClick(() => {
          this.message.delete(0);
        })
    }
    .width('100%')
  }
}
```

![provider-sync-4](figures/provider-sync-4.gif)

### 装饰Set类型变量

当装饰Set类型变量时，可以观察到数据源对Set整体的赋值，以及调用Set的接口 `add`, `clear`, `delete`带来的变化。

<!-- @[Decorative_Set](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/DecorativeSet.ets) -->  

``` TypeScript
@Entry
@ComponentV2
struct Parent {
  @Provider() message: Set<number> = new Set([1, 2, 3, 4]);

  build() {
    Column() {
      Text('Parent')
        .fontSize(30)
        .margin(10)
      ForEach(Array.from(this.message.entries()), (item: [number, number]) => {
        Text(`${item[0]}`)
          .fontSize(30)
          .margin(10)
        Divider()
      })
      // message被@Provider装饰，可以被观察到Set整体的赋值以及调用Set接口带来的变化
      Button('init set')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message = new Set([1, 2, 3, 4]);
        })
      Button('set new one')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message.add(5);
        })
      Button('clear')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message.clear();
        })
      Button('delete the first one')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message.delete(1);
        })
      Child()
    }
    .width('100%')
  }
}

@ComponentV2
struct Child {
  @Consumer() message: Set<number> = new Set([1, 2, 3, 4, 5, 6]);

  build() {
    Column() {
      Text('Child')
        .fontSize(30)
        .margin(10)
      ForEach(Array.from(this.message.entries()), (item: [number, number]) => {
        Text(`${item[0]}`)
          .fontSize(30)
          .margin(10)
        Divider()
      })
      // message被@Consumer装饰，可以被观察到Set整体的赋值以及调用Set接口带来的变化
      Button('init set')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message = new Set([1, 2, 3, 4, 5, 6]);
        })
      Button('set new one')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message.add(7);
        })
      Button('clear')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message.clear();
        })
      Button('delete the first one')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.message.delete(1);
        })
    }
    .width('100%')
  }
}
```

![provider-sync-5](figures/provider-sync-5.gif)

### \@Provider和\@Consumer装饰回调事件用于组件之间完成行为抽象

当需要在父组件中向子组件注册回调函数时，可以使用\@Provider和\@Consumer装饰回调方法来实现。

在拖拽场景中，若需将子组件的拖拽起始位置信息同步给父组件，可参考以下示例。

<!-- @[Drag_Drop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/DragDrop.ets) --> 

``` TypeScript
@Entry
@ComponentV2
struct Parent {
  @Local childX: number = 0;
  @Local childY: number = 1;
  @Provider() onDrag: (x: number, y: number) => void = (x: number, y: number) => {
    console.info(`onDrag event at x=${x} y:${y}`);
    this.childX = x;
    this.childY = y;
  }

  build() {
    Column() {
      Text(`child position x: ${this.childX}, y: ${this.childY}`)
        .fontSize(20)
        .margin(10)
      Child()
    }
    .width('100%')
  }
}

@ComponentV2
struct Child {
  @Consumer() onDrag: (x: number, y: number) => void = (x: number, y: number) => {};

  build() {
    Button('changed')
      .width(300)
      .margin(10)
      .draggable(true)
      .onDragStart((event: DragEvent) => {
        // 当前预览器上不支持通用拖拽事件
        this.onDrag(event.getDisplayX(), event.getDisplayY());
      })
  }
}
```

![provider-sync-6](figures/provider-sync-6.gif)

### \@Provider和\@Consumer装饰复杂类型，配合\@Trace一起使用

1. \@Provider和\@Consumer只能观察到数据本身的变化。如果需要观察其装饰的复杂数据类型的属性变化，可以配合\@Trace一起使用，也可以使用[makeObserved](./arkts-new-makeObserved.md)将非可观察数据变为可观察数据。
2. 装饰内置类型：Array、Map、Set、Date时，可以观察到某些API的变化，观察能力同[\@Trace](./arkts-new-observedV2-and-trace.md#观察变化)。

<!-- @[Decorative_Complex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/DecorativeComplex.ets) -->  

``` TypeScript
@ObservedV2
class User {
  // 复杂数据类型的属性被@Trace装饰，可以被观察到属性变化
  @Trace public name: string;
  @Trace public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
const data: User[] = [new User('Json', 10), new User('Eric', 15)];
@Entry
@ComponentV2
struct Parent {
  @Provider('data') users: User[] = data;

  build() {
    Column() {
      Child()
      Button('add new user')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.users.push(new User('Molly', 18));
        })
      Button('age++')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.users[0].age++;
        })
      Button('change name')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.users[0].name = 'Shelly';
        })
    }
    .width('100%')
  }
}

@ComponentV2
struct Child {
  @Consumer('data') users: User[] = [];

  build() {
    Column() {
      ForEach(this.users, (item: User) => {
        Column() {
          Text(`name: ${item.name}`)
            .fontSize(30)
            .margin(10)
          Text(`age: ${item.age}`)
            .fontSize(30)
            .margin(10)
          Divider()
        }
        .width('100%')
      })
    }
    .width('100%')
  }
}
```

![provider-sync-7](figures/provider-sync-7.gif)

### \@Provider重名时，\@Consumer向上查找其最近的\@Provider

\@Provider可以在组件树上重名，\@Consumer会向上查找其最近父节点的\@Provider的数据。

<!-- @[Provider_Same](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/ProviderSame.ets) --> 

``` TypeScript
@Entry
@ComponentV2
struct Index {
  @Provider() val: number = 10;

  build() {
    Column() {
      Parent()
    }
    .width('100%')
  }
}

@ComponentV2
struct Parent {
  @Provider() val: number = 20;
  @Consumer('val') val2: number = 0; // 10

  build() {
    Column() {
      Text(`${this.val2}`)
        .fontSize(20)
        .margin(10)
      Child()
    }
    .width('100%')
  }
}

@ComponentV2
struct Child {
  @Consumer() val: number = 0; // 20

  build() {
    Column() {
      Text(`${this.val}`)
        .fontSize(20)
        .margin(10)
    }
    .width('100%')
  }
}
```

![provider-sync-8](figures/provider-sync-8.png)

上面的例子中：

- Parent中的\@Consumer向上查找，查找到Index中定义的`@Provider() val: number = 10`，初始化为10。
- Child中的\@Consumer向上查找，查找到Parent中定义的`@Provider() val: number = 20`后停止，初始化为20。

### \@Provider和\@Consumer初始化\@Param

\@Provider和\@Consumer装饰的变量可以初始化子组件中\@Param装饰的变量。

<!-- @[Decorative_Initialized](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/DecorativeInitialized.ets) -->  

``` TypeScript
@Entry
@ComponentV2
struct Index {
  @Provider() val: number = 10;

  build() {
    Column() {
      Text(`Index @Provider val: ${this.val}`)
        .fontSize(30)
        .margin(10)
      // @Provider装饰的变量val可以初始化@Param装饰的变量val2
      Parent({ val2: this.val })
    }
    .width('100%')
  }
}

@ComponentV2
struct Parent {
  @Consumer() val: number = 0;
  @Require @Param val2: number;

  build() {
    Column() {
      Text(`Parent @Consumer val: ${this.val}`)
        .fontSize(30)
        .margin(10)
      Button('change val')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.val++;
        })
      Text(`Parent @Param val2: ${this.val2}`)
        .fontSize(30)
        .margin(10)
      // @Consumer装饰的变量val可以初始化@Param装饰的变量val
      Child({ val: this.val })
    }
    .width('95%')
    .border({ width: 2, color: Color.Green })
    .height('45%')
  }
}

@ComponentV2
struct Child {
  @Require @Param val: number;

  build() {
    Column() {
      Text(`Child @Param val ${this.val}`)
        .fontSize(30)
        .margin(10)
    }
    .width('95%')
    .border({ width: 2, color: Color.Pink })
  }
}
```

![provider-sync-9](figures/provider-sync-9.gif)

上面的例子中：

- Index中\@Provider装饰的变量val与Parent中\@Consumer装饰的变量val建立双向数据绑定。Parent中\@Param装饰的变量val2接收Index中数据源val的数据，并同步其变化。Child中\@Param装饰的变量val接收Parent中数据源val的数据，并同步其变化。
- 点击Parent中的按钮，触发`@Consumer() val`的变化，变化同步给Index中的`@Provider() val`和Child中的`@Param val`，对应UI刷新。
- Index中`@Provider() val`的变化同步给Parent中的`@Param val2`，对应UI刷新。

### \@Consumer在跨BuilderNode场景下和\@Provider建立双向同步过程

> **说明：**
>
> 从API version 23开始，支持跨BuilderNode配对\@Provider和\@Consumer。

下面给出一个示例，实现如下功能：
1. BuilderNode通过[全局自定义构建函数](arkts-builder.md#全局自定义构建函数)构建组件树，组件树的根[FrameNode](../../reference/apis-arkui/js-apis-arkui-frameNode.md)节点可通过[getFrameNode](../../reference/apis-arkui/js-apis-arkui-builderNode.md#getframenode)获取，该节点可直接由[NodeController](../../reference/apis-arkui/js-apis-arkui-nodeController.md)返回并挂载于[NodeContainer](../../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md)节点下。
2. 挂载到自定义组件节点树时，BuilderNode会通过addBuilderNode方法挂载在自定义组件下，此时BuilderNode节点下的\@Consumer会向上查找\@Provider，根据key的匹配规则找到最近的\@Provider后，会和\@Provider建立双向同步关系。如果找不到配对的\@Provider，则\@Consumer仍使用默认值。
3. 建立双向同步的关系后，如果\@Provider装饰变量的值和\@Consumer的默认值不同，则会回调\@Consumer的\@Monitor方法，以及与\@Consumer有同步关系的变量的[\@Monitor](./arkts-new-monitor.md)方法，例如：\@Consumer通知其子组件中的\@Param触发\@Monitor方法。
4. BuilderNode从组件树卸载后，\@Consumer会再次试图查找对应的\@Provider，如果发现从组件树卸载后无法再找到之前配对的\@Provider，则断开和\@Provider的双向同步关系，\@Consumer装饰的变量恢复成默认值。
5. \@Consumer断开和\@Provider的连接，恢复成默认值时，会判断\@Consumer装饰变量的值相对于从\@Provider变为\@Consumer的默认值是否有变化，如果有变化，则会回调\@Consumer的\@Monitor方法以及与该\@Consumer存在同步关系的变量的\@Monitor方法。

<!-- @[Builder_Node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ProviderConsumer/entry/src/main/ets/homePage/BuilderNode.ets) --> 

``` TypeScript
import { BuilderNode, FrameNode, NodeController } from '@kit.ArkUI';

@Builder
function buildText() {
  TestRemove()
}

let globalBuilderNode: BuilderNode<[]> | null = null;

class TextNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private uiContext: UIContext | null = null;

  constructor() {
    super();
  }

  makeNode(context: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(context);
    this.uiContext = context;
    return this.rootNode;
  }

  addBuilderNode(): void {
    if (globalBuilderNode === null && this.uiContext) {
      globalBuilderNode = new BuilderNode(this.uiContext);
      // 构建BuilderNode，TestRemove作为子组件
      globalBuilderNode.build(wrapBuilder<[]>(buildText), undefined, { enableProvideConsumeCrossing: true });
    }
    if (this.rootNode && globalBuilderNode) {
      this.rootNode.appendChild(globalBuilderNode.getFrameNode());
    }
  }

  removeBuilderNode(): void {
    if (this.rootNode && globalBuilderNode) {
      this.rootNode.removeChild(globalBuilderNode.getFrameNode());
    }
  }

  disposeNode(): void {
    if (this.rootNode && globalBuilderNode) {
      globalBuilderNode.dispose();
      globalBuilderNode = null;
    }
  }
}

@Entry
@ComponentV2
struct RemoChildDisconnectProvider {
  @Provider() content: string = 'Index: hello world';
  @Monitor('content')
  providerWatch() {
    console.info(`Provider change ${this.content}`);
  }

  controllerIndex: TextNodeController = new TextNodeController();

  build() {
    Column({ space: 8 }) {
      Text(`Provider: ${this.content}`)
        .fontSize(20)
        .margin(10)

      // 添加BuilderNode，@Consumer与@Provider建立双向同步
      Button('add child')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.controllerIndex.addBuilderNode();
        })

      // 移除BuilderNode，@Consumer与@Provider断开连接，恢复默认值
      Button('remove child')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.controllerIndex.removeBuilderNode();
        })

      // 释放BuilderNode的子节点TestRemove，随后该子节点销毁，触发子节点的aboutToDisappear回调
      Button('dispose child')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.controllerIndex.disposeNode();
        })

      // @Provider/@Consumer双向同步更新
      Button('change Provider')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.content += 'Pro';
        })
      NodeContainer(this.controllerIndex)
    }
    .width('100%')
    .height('100%')
  }
}

@ComponentV2
struct TestRemove {
  @Consumer() content: string = 'default value';
  @Monitor('content')
  consumerWatch() {
    console.info(`Consumer change ${this.content}`);
  }

  aboutToDisappear() {
    console.info(`TestRemove aboutToDisappear`);
  }

  build() {
    Column() {
      Text('Consumer ' + this.content)
        .fontSize(20)
        .margin(10)

      // @Provider和@Consumer绑定的Text组件刷新，并回调@Provider和@Consumer的@Monitor方法
      Button('change cc')
        .width(300)
        .margin(10)
        .onClick(() => {
          this.content += 'cc';
        })
    }
    .width('100%')
  }
}
```

![provider-sync-10](figures/provider-sync-10.gif)

上面的例子中：

- 点击`add child`，`TestRemove`中\@Consumer向上找到最近的`RemoChildDisconnectProvider`中的\@Provider，将\@Consumer从默认值更新为\@Provider的值，并回调\@Consumer的\@Monitor方法。
- \@Provider和\@Consumer配对后，建立双向同步关系。点击`change Provider`和`change cc`，\@Provider和\@Consumer绑定的Text组件刷新，并回调\@Provider和\@Consumer的\@Monitor方法。
- 点击`remove child`，BuilderNode子节点从组件树卸载，`TestRemove`中的\@Consumer和`RemoChildDisconnectProvider`中的\@Provider断开连接，`TestRemove`中的\@Consumer恢复成默认值，并回调\@Consumer的\@Monitor方法。
- 点击`dispose child`，释放BuilderNode下的子节点`TestRemove`，随后该子节点销毁，执行aboutToDisappear回调。
