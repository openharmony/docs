# \@Watch装饰器：状态变量更改通知
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->


\@Watch应用于对状态变量的监听。如果开发者需要关注某个状态变量的值是否改变，可以使用\@Watch为状态变量设置回调函数。


\@Watch提供了状态变量的监听能力，\@Watch仅能监听到可以观察到的变化。

在阅读本文档前，建议开发者对状态管理基本观察能力有基本的了解。建议提前阅读：[\@State](./arkts-state.md)。

> **说明：**
>
> 从API version 9开始，该装饰器支持在ArkTS卡片中使用。
>
> 从API version 11开始，该装饰器支持在原子化服务中使用。

## 概述

\@Watch用于监听状态变量的变化，当状态变量变化时，\@Watch的回调方法将被调用。\@Watch在ArkUI框架内部判断数值有无更新使用的是严格相等（===），遵循严格相等规范。当严格相等判断的结果是false（即不相等）的情况下，就会触发\@Watch的回调。


## 装饰器说明

| \@Watch补充变量装饰器 | 说明                                       |
| -------------- | ---------------------------------------- |
| 装饰器参数          | 必填。常量字符串，字符串需要有引号。是(string)&nbsp;=&gt;&nbsp;void自定义成员函数的方法的引用。 |
| 可装饰的自定义组件变量    | 可监听所有装饰器装饰的状态变量。不允许监听常规变量。               |
| 装饰器的顺序         | 装饰器顺序不影响实际功能，开发者可以根据自己的需要决定装饰器顺序的先后。建议[\@State](./arkts-state.md)、[\@Prop](./arkts-prop.md)、[\@Link](./arkts-link.md)等装饰器在\@Watch装饰器之前，以保持整体风格的一致。 |
| \@Watch触发时机 | 使用\@Watch来监听状态变量变化时，回调触发时间是变量真正变化、被赋值的时间。详细示例请参考使用场景中的[@Watch的触发时机](#watch的触发时机)。 |

## 语法说明

| 类型                                       | 说明                                       |
| ---------------------------------------- | ---------------------------------------- |
| (changedPropertyName?&nbsp;:&nbsp;string)&nbsp;=&gt;&nbsp;void | 该函数是自定义组件的成员函数，changedPropertyName是被watch的属性名。<br/>在多个状态变量绑定同一个\@Watch的回调方法的时候，可以通过changedPropertyName进行不同的逻辑处理<br/>将属性名作为字符串输入参数，不返回任何内容。 |


## 观察变化和行为表现

1. 当观察到状态变量的变化（包括双向绑定的[AppStorage](./arkts-appstorage.md)和[LocalStorage](./arkts-localstorage.md)中对应的key发生的变化）的时候，对应的\@Watch的回调方法将被触发；

2. \@Watch方法在自定义组件的属性变更之后同步执行；

3. 如果在\@Watch的方法里改变了其他的状态变量，也会引起状态变更和\@Watch的执行；

4. 在第一次初始化的时候，\@Watch装饰的方法不会被调用，即认为初始化不是状态变量的改变。只有在后续状态改变时，才会调用\@Watch回调方法。


## 限制条件

- 建议开发者避免无限循环。循环可能是因为在\@Watch的回调方法里直接或者间接地修改了同一个状态变量引起的。为了避免循环的产生，建议不要在\@Watch的回调方法里修改当前装饰的状态变量；

- 开发者应关注性能，属性值更新函数会延迟组件的重新渲染（具体请见上面的行为表现），因此，回调函数应仅执行快速运算；

- 不建议在\@Watch函数中调用async await，因为\@Watch设计的用途是为了快速的计算，异步行为可能会导致重新渲染速度的性能问题。

- \@Watch参数为必选，且参数类型必须是string，否则编译期会报错。

```ts
// 错误写法，编译报错
@State @Watch() num: number = 10;
@State @Watch(change) num: number = 10;

// 正确写法
@State @Watch('change') num: number = 10;
change() {
  console.log(`xxx`);
}
```

- \@Watch内的参数必须是声明的方法名，否则编译期会报错。

```ts
// 错误写法，没有对应名称的函数，编译报错
@State @Watch('change') num: number = 10;
onChange() {
  console.log(`xxx`);
}

// 正确写法
@State @Watch('change') num: number = 10;
change() {
  console.log(`xxx`);
}
```

- 常规变量不能被\@Watch装饰，否则编译期会报错。

```ts
//错误写法
@Watch('change') num: number = 10;
change() {
  console.log(`xxx`);
}

// 正确写法
@State @Watch('change') num: number = 10;
change() {
  console.log(`xxx`);
}
```


## 使用场景

### \@Watch和自定义组件更新

以下示例展示组件更新和\@Watch的处理步骤。count在CountModifier中由\@State装饰，在TotalView中由\@Prop装饰。


```ts
@Component
struct TotalView {
  @Prop @Watch('onCountUpdated') count: number = 0;
  @State total: number = 0;
  // @Watch 回调
  onCountUpdated(propName: string): void {
    this.total += this.count;
  }

  build() {
    Text(`Total: ${this.total}`)
  }
}

@Entry
@Component
struct CountModifier {
  @State count: number = 0;

  build() {
    Column() {
      Button('add to basket')
        .onClick(() => {
          this.count++
        })
      TotalView({ count: this.count })
    }
  }
}
```

处理步骤：

1. CountModifier自定义组件的Button.onClick点击事件自增count。

2. 由于\@State count变量更改，子组件TotalView中的\@Prop被更新，其\@Watch('onCountUpdated')方法被调用，更新了子组件TotalView 中的total变量。

3. 子组件TotalView中的Text重新渲染。


### \@Watch与\@Link组合使用

以下示例说明了如何在子组件中观察\@Link变量。


```ts
class PurchaseItem {
  static NextId: number = 0;
  public id: number;
  public price: number;

  constructor(price: number) {
    this.id = PurchaseItem.NextId++;
    this.price = price;
  }
}

@Component
struct BasketViewer {
  @Link @Watch('onBasketUpdated') shopBasket: PurchaseItem[];
  @State totalPurchase: number = 0;

  updateTotal(): number {
    let total = this.shopBasket.reduce((sum, i) => sum + i.price, 0);
    // 超过100欧元可享受折扣
    if (total >= 100) {
      total = 0.9 * total;
    }
    return total;
  }
  // @Watch 回调
  onBasketUpdated(propName: string): void {
    this.totalPurchase = this.updateTotal();
  }

  build() {
    Column() {
      ForEach(this.shopBasket,
        (item: PurchaseItem) => {
          Text(`Price: ${item.price.toFixed(2)} €`)
        },
        (item: PurchaseItem) => item.id.toString()
      )
      Text(`Total: ${this.totalPurchase.toFixed(2)} €`)
    }
  }
}

@Entry
@Component
struct BasketModifier {
  @State shopBasket: PurchaseItem[] = [];

  build() {
    Column() {
      Button('Add to basket')
        .onClick(() => {
          this.shopBasket.push(new PurchaseItem(Math.round(100 * Math.random())))
        })
      BasketViewer({ shopBasket: $shopBasket })
    }
  }
}
```

处理步骤如下：

1. BasketModifier组件的Button.onClick向BasketModifier shopBasket中添加条目；

2. \@Link装饰的BasketViewer shopBasket值发生变化；

3. 状态管理框架调用\@Watch函数BasketViewer onBasketUpdated 更新BasketViewer TotalPurchase的值；

4. \@Link shopBasket的改变，新增了数组项，ForEach组件会执行item Builder，渲染构建新的Item项；\@State totalPurchase改变，对应的Text组件也重新渲染；重新渲染是异步发生的。

### \@Watch的触发时机

为了展示\@Watch回调触发时间是根据状态变量真正变化的时间，本示例在子组件中同时使用\@Link和\@ObjectLink装饰器，分别观察不同的状态对象。通过在父组件中更改状态变量并观察\@Watch回调的先后顺序，来表明@Watch触发的时机与赋值、同步的关系。

```ts
@Observed
class Task {
  isFinished: boolean = false;

  constructor(isFinished : boolean) {
    this.isFinished = isFinished;
  }
}

@Entry
@Component
struct ParentComponent {
  @State @Watch('onTaskAChanged') taskA: Task = new Task(false);
  @State @Watch('onTaskBChanged') taskB: Task = new Task(false);

  onTaskAChanged(changedPropertyName: string): void {
    console.log(`观测到父组件任务属性变化: ${changedPropertyName}`);
  }

  onTaskBChanged(changedPropertyName: string): void {
    console.log(`观测到父组件任务属性变化: ${changedPropertyName}`);
  }

  build() {
    Column() {
      Text(`父组件任务A状态: ${this.taskA.isFinished ? '已完成' : '未完成'}`)
      Text(`父组件任务B状态: ${this.taskB.isFinished ? '已完成' : '未完成'}`)
      ChildComponent({ taskA: this.taskA, taskB: this.taskB })
      Button('切换任务状态')
        .onClick(() => {
          this.taskB = new Task(!this.taskB.isFinished);
          this.taskA = new Task(!this.taskA.isFinished);
        })
    }
  }
}

@Component
struct ChildComponent {
  @ObjectLink @Watch('onObjectLinkTaskChanged') taskB: Task;
  @Link @Watch('onLinkTaskChanged') taskA: Task;

  onObjectLinkTaskChanged(changedPropertyName: string): void {
    console.log(`观测到子组件@ObjectLink关联的任务属性变化: ${changedPropertyName}`);
  }

  onLinkTaskChanged(changedPropertyName: string): void {
    console.log(`观测到子组件@Link关联的任务属性变化: ${changedPropertyName}`);
  }

  build() {
    Column() {
      Text(`子组件任务A状态: ${this.taskA.isFinished ? '已完成' : '未完成'}`)
      Text(`子组件任务B状态: ${this.taskB.isFinished ? '已完成' : '未完成'}`)
    }
  }
}
```

处理步骤如下：

1. 当点击按钮切换任务状态时，父组件首先更新了被\@ObjectLink关联的taskB，然后更新了被\@Link关联的taskA。

2. 观察到日志依次显示：
    ```
    观测到父组件任务属性变化: taskB
    观测到父组件任务属性变化: taskA
    观测到子组件@Link关联的任务属性变化: taskA
    观测到子组件@ObjectLink关联的任务属性变化: taskB
    ```

3. 通过日志可以看到，父组件的回调顺序和修改顺序一致，而子组件中\@Link和\@ObjectLink的回调触发顺序与父组件中变量更新的顺序不同。这是因为父组件的变量更新是即时的，但子组件中\@Link和\@ObjectLink获取更新数据的时机不同。\@Link的状态更新是同步的，状态变化会立刻触发\@Watch回调。而\@ObjectLink的更新依赖于父组件的同步，当父组件刷新并将更新后的变量传递给子组件时，\@Watch回调才会触发，因此触发顺序略晚于\@Link。

4. 这是符合预期的行为，展示了\@Watch回调的触发时机是根据状态变量真正变化的时间。因为\@Link直接同步，而\@ObjectLink需要等父组件更新子组件变量。类似地，\@Prop也可能表现出与\@ObjectLink类似的行为，其回调触发时间也会略晚。

### 使用changedPropertyName进行不同的逻辑处理

以下示例说明了如何在\@Watch函数中使用changedPropertyName进行不同的逻辑处理。


```ts
@Entry
@Component
struct UsePropertyName {
  @State @Watch('countUpdated') apple: number = 0;
  @State @Watch('countUpdated') cabbage: number = 0;
  @State fruit: number = 0;
  // @Watch 回调
  countUpdated(propName: string): void {
    if (propName == 'apple') {
      this.fruit = this.apple;
    }
  }

  build() {
    Column() {
      Text(`Number of apples: ${this.apple.toString()}`).fontSize(30)
      Text(`Number of cabbages: ${this.cabbage.toString()}`).fontSize(30)
      Text(`Total number of fruits: ${this.fruit.toString()}`).fontSize(30)
      Button('Add apples')
        .onClick(() => {
          this.apple++;
        })
      Button('Add cabbages')
        .onClick(() => {
          this.cabbage++;
        })
    }
  }
}
```

处理步骤如下：

1. 点击Button('Add apples')时，apple的值发生变化。

2. 状态管理框架调用\@Watch函数countUpdated，发生变化的状态变量名为apple，满足if逻辑条件，fruit的值被改变。

3. 绑定了apple，fruit状态变量的Text重新渲染。

4. 点击Button('Add cabbages')时，cabbage的值发生变化。

5. 状态管理框架调用\@Watch函数countUpdated，发生变化的状态变量名为cabbage，不满足if逻辑条件，fruit的值不发生变化。

6. 绑定了cabbage状态变量的Text重新渲染。
