# \@Watch装饰器：状态变量更改通知


\@Watch应用于对状态变量的监听。如果开发者需要关注某个状态变量的值是否改变，可以使用\@Watch为状态变量设置回调函数。


> **说明：**
>
> 从API version 9开始，该装饰器支持在ArkTS卡片中使用。
>
> 从API version 11开始，该装饰器支持在原子化服务中使用。

## 概述

\@Watch用于监听状态变量的变化，当状态变量变化时，\@Watch的回调方法将被调用。\@Watch在ArkUI框架内部判断数值有无更新使用的是严格相等（===），遵循严格相等规范。当在严格相等为false的情况下，就会触发\@Watch的回调。


## 装饰器说明

| \@Watch补充变量装饰器 | 说明                                       |
| -------------- | ---------------------------------------- |
| 装饰器参数          | 必填。常量字符串，字符串需要有引号。是(string)&nbsp;=&gt;&nbsp;void自定义成员函数的方法的引用。 |
| 可装饰的自定义组件变量    | 可监听所有装饰器装饰的状态变量。不允许监听常规变量。               |
| 装饰器的顺序         | 建议[\@State](./arkts-state.md)、[\@Prop](./arkts-prop.md)、[\@Link](./arkts-link.md)等装饰器在\@Watch装饰器之前。 |


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

2. 状态管理框架调用\@Watch函数countUpdated，发生变化的状态变量名为apple，满足if逻辑条件，fruit的值被改变；

3. 绑定了apple，fruit状态变量的Text重新渲染。

4. 点击Button('Add cabbages')时，cabbage的值发生变化。

5. 状态管理框架调用\@Watch函数countUpdated，发生变化的状态变量名为cabbage，不满足if逻辑条件，fruit的值不发生变化；

6. 绑定了cabbage状态变量的Text重新渲染。
