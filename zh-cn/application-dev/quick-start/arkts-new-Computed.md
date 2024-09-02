# \@Computed装饰器：计算属性

\@Computed装饰器：计算属性，在被计算的值变化的时候，只会计算一次。主要应用于解决UI多次重用该属性从而重复计算导致的性能问题。

>**说明：**
>
>\@Computed装饰器从API version 12开始支持。
>
>当前状态管理（V2试用版）仍在逐步开发中，相关功能尚未成熟，建议开发者尝鲜试用。

## 概述

\@Computed为方法装饰器，装饰getter方法。\@Computed会检测被计算的属性变化，当被计算的属性变化时，\@Computed只会被求解一次。
对于复杂的计算，\@Computed会有性能收益。


## 装饰器说明
\@Computed语法：

```ts
@Computed get varName(): T {
    return value;
}
```

| \@Computed方法装饰器 | 说明                                                  |
| ------------------ | ----------------------------------------------------- |
| 支持类型           | getter访问器。 |
| 从父组件初始化      | 禁止。 |
| 可初始化子组件      | \@Param  |
| 被执行的时机        | \@ComponentV2被初始化时，计算属性会被触发被计算。当被计算的值改变的时候，计算属性也会发生计算。 |
|是否允许赋值         | @Computed装饰的属性是只读的，不允许赋值，详情见[使用限制](##使用限制)。|

## 使用限制

- \@Computed为方法装饰器装饰getter方法，在getter方法中，不能改变参与计算的属性。

  ```ts
  @Computed
  get fullName() {
    this.lastName += 'a'; // error
    return this.firstName + ' ' + this.lastName;
  }
  ```

- \@Computed不能和双向绑定!!连用，即\@Computed装饰的是getter访问器，不会被子组件同步，也不能被赋值。开发者自己实现的计算属性的setter不生效。

  ```ts
  @ComponentV2
  struct Child {
    @Param double: number = 100
    @Event $double: (val: number) => void;
  
    build() {
      Button('ChildChange')
        .onClick(() => {
          this.$double(200)
        })
    }
  }
  
  @Entry
  @ComponentV2
  struct Index {
    @Local count: number = 100
  
    @Computed
    get double() {
      return this.count * 2
    }
  
    // @Computed装饰的属性是只读的，开发者自己实现的setter不生效
    set double(newValue : number) {
      this.count = newValue / 2;
    }
  
    build() {
      Scroll() {
        Column({ space: 3 }) {
          Text(`${this.count}`)
          // 错误写法，@Computed装饰的属性方法是只读的，无法和双向绑定连用
          Child({ double: this.double!! })
        }
      }
    }
  }
  ```

- \@Computed为状态管理V2提供的能力，只能在\@ComponentV2和\@ObservedV2中使用。
- 多个\@Computed一起使用时，警惕循环求解。

  ```ts
  @Local a : number = 1;
  @Computed
  get b() {
    return this.a + ' ' + this.c;  // error: b -> c -> b
  }
  @Computed
  get c() {
    return this.a + ' ' + this.b; // error: c -> b -> c
  }
  ```
## 使用场景
### 当被计算的属性变化时，\@Computed装饰的getter访问器只会被求解一次
1. 在自定义组件中使用计算属性

- 点击第一个Button改变lastName，触发\@Computed fullName重新计算。
- `this.fullName`被绑定在两个Text组件上，观察`fullName`日志，可以发现，计算只发生了一次。
- 对于前两个Text组件，`this.lastName + ' '+ this.firstName`这段逻辑被求解了两次。
- 如果UI中有多处需要使用`this.lastName + ' '+ this.firstName`这段计算逻辑，可以使用计算属性，减少计算次数。
- 点击第二个Button，age自增，UI无变化。因为age非状态变量，只有被观察到的变化才会触发\@Computed fullName重新计算。

```ts
@Entry
@ComponentV2
struct Index {
  @Local firstName: string = 'Li';
  @Local lastName: string = 'Hua';
  age: number = 20; // cannot trigger Computed

  @Computed
  get fullName() {
    console.info("---------Computed----------");
    return this.firstName + ' ' + this.lastName + this.age;
  }

  build() {
    Column() {
      Text(this.lastName + ' ' + this.firstName)
      Text(this.lastName + ' ' + this.firstName)
      Divider()
      Text(this.fullName)
      Text(this.fullName)
      Button('changed lastName').onClick(() => {
        this.lastName += 'a';
      })

      Button('changed age').onClick(() => {
        this.age++;  // cannot trigger Computed
      })
    }
  }
}
```

但是需要注意，计算属性本身是有性能开销的，实际应用开发中：
- 如果是上面这种简单计算，可以不使用计算属性。
- 如果在视图中只使用一次，也可以不使用计算属性，建议直接求解。

2. 在\@ObservedV2装饰的类中使用计算属性
- 点击Button改变lastName，触发\@Computed fullName重新计算，且只被计算一次。

```ts
@ObservedV2
class Name {
  @Trace firstName: string = 'Li';
  @Trace lastName: string = 'Hua';

  @Computed
  get fullName() {
    console.info('---------Computed----------');
    return this.firstName + ' ' + this.lastName;
  }
}

const name: Name = new Name();

@Entry
@ComponentV2
struct Index {
  name1: Name = name;

  build() {
    Column() {
      Text(this.name1.fullName)
      Text(this.name1.fullName)
      Button('changed lastName').onClick(() => {
        this.name1.lastName += 'a';
      })
    }
  }
}
```

### \@Computed装饰的属性可以被\@Monitor监听变化
下面的例子展示了使用计算属性求解fahrenheit和kelvin。
- 点击“-”，celsius-- -> fahrenheit -> kelvin --> kelvin改变触发onKelvinMonitor。
- 点击“+”，celsius++ -> fahrenheit -> kelvin --> kelvin改变触发onKelvinMonitor。

```ts
@Entry
@ComponentV2
struct MyView {
  @Local celsius: number = 20;

  @Computed
  get fahrenheit(): number {
    return this.celsius * 9 / 5 + 32; // C -> F
  }

  @Computed
  get kelvin(): number {
    return (this.fahrenheit - 32) * 5 / 9 + 273.15; // F -> K
  }

  @Monitor("kelvin")
  onKelvinMonitor(mon: IMonitor) {
    console.log("kelvin changed from " + mon.value()?.before + " to " + mon.value()?.now);
  }

  build() {
    Column({ space: 20 }) {
      Row({ space: 20 }) {
        Button('-')
          .onClick(() => {
            this.celsius--;
          })

        Text(`Celsius ${this.celsius.toFixed(1)}`).fontSize(50)

        Button('+')
          .onClick(() => {
            this.celsius++;
          })
      }

      Text(`Fahrenheit ${this.fahrenheit.toFixed(2)}`).fontSize(50)
      Text(`Kelvin ${this.kelvin.toFixed(2)}`).fontSize(50)
    }
    .width('100%')
  }
}
```
### \@Computed装饰的属性可以初始化\@Param
下面的例子展示了\@Computed初始\@Param。
- 点击`Button('-')`和`Button('+')`改变商品数量，`quantity`是被\@Trace装饰的，其改变时可以被观察到的。
- `quantity`的改变触发`total`和`qualifiesForDiscount`重新计算，计算商品总价和是否可以享有优惠。
- `total`和`qualifiesForDiscount`的改变触发子组件`Child`对应Text组件刷新。

```ts
@ObservedV2
class Article {
  @Trace quantity: number = 0;
  unitPrice: number = 0;

  constructor(quantity: number, unitPrice: number) {
    this.quantity = quantity;
    this.unitPrice = unitPrice;
  }
}

@Entry
@ComponentV2
struct Index {
  @Local shoppingBasket: Article[] = [new Article(1, 20), new Article(5, 2)];

  @Computed
  get total(): number {
    return this.shoppingBasket.reduce((acc: number, item: Article) => acc + (item.quantity * item.unitPrice), 0);
  }

  @Computed
  get qualifiesForDiscount(): boolean {
    return this.total >= 100;
  }

  build() {
    Column() {
      Text(`Shopping List: `).fontSize(30)
      ForEach(this.shoppingBasket, (item: Article) => {
        Row() {
          Text(`unitPrice: ${item.unitPrice}`)
          Button('-').onClick(() => {
            if (item.quantity > 0) {
              item.quantity--;
            }
          })
          Text(`quantity: ${item.quantity}`)
          Button('+').onClick(() => {
            item.quantity++;
          })
        }

        Divider()
      })
      Child({ total: this.total, qualifiesForDiscount: this.qualifiesForDiscount })
    }.alignItems(HorizontalAlign.Start)
  }
}

@ComponentV2
struct Child {
  @Param total: number = 0;
  @Param qualifiesForDiscount: boolean = false;

  build() {
    Row() {
      Text(`Total: ${this.total} `).fontSize(30)
      Text(`Discount: ${this.qualifiesForDiscount} `).fontSize(30)
    }

  }
}
```