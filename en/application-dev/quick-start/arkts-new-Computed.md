# \@Computed Decorator: Computed Property

\@Computed decorator: Computed property means that the computation is performed only once when the value changes. It is mainly used to solve the performance problem caused by repeated computation when the UI reuses the property for multiple times.


The change of a state variable can trigger the recomputing of its associated \@Computed. Before reading this topic, you are advised to read [\@ComponentV2](./arkts-new-componentV2.md), [\@ObservedV2 and \@Trace](./arkts-new-observedV2-and-trace.md), and [\@Local](./arkts-new-local.md).

>**NOTE**
>
>The \@Computed decorator is supported since API version 12.
>

## Overview

\@Computed is a method-type decorator that decorates the **getter** method. \@Computed detects the change of the computed property. When this property changes, \@Computed is solved only once.
For complex computing, \@Computed provides better performance.


## Decorator Description
\@Computed syntax:

```ts
@Computed
get varName(): T {
    return value;
}
```

| \@Computed Method-Type Decorator| Description                                                 |
| ------------------ | ----------------------------------------------------- |
| Supported type          | **getter** accessor.|
| Initialization from the parent component     | Forbidden.|
| Child component initialization     | \@Param  |
| Execution time       | When \@ComponentV2 is initialized, the computed property will be triggered. When the computed value changes, the computed property will be also triggered.|
|Value assignment allowed        | No. @Computed decorated properties are read-only. For details, see [Constraints](#constraints).|

## Constraints

- \@Computed is a method decorator, which can decorate only the **getter** method.

  ```ts
  @Computed
  get fullName() { // Correct format.
    return this.firstName + ' ' + this.lastName;
  }
  @Computed val: number = 0; // Incorrect format. An error is reported during compilation.
  @Computed
  func() { // Incorrect usage. An error is reported during compilation.
  }
  ```
- In the **getter** method decorated by \@Computed, the properties involved in computation cannot be changed.

  ```ts
  @Computed
  get fullName() {
    this.lastName += 'a'; // Error. The properties involved in computation cannot be changed.
    return this.firstName + ' ' + this.lastName;
  }
  ```

- \@Computed cannot be used together with **!!**. That is, \@Computed decorates the **getter** accessor, which is not synchronized by the child components nor assigned a value. **setter** of the computed property implemented by you does not take effect, and an error is reported during compilation.

  ```ts
  @ComponentV2
  struct Child {
    @Param double: number = 100;
    @Event $double: (val: number) => void;
  
    build() {
      Button('ChildChange')
        .onClick(() => {
          this.$double(200);
        })
    }
  }
  
  @Entry
  @ComponentV2
  struct Index {
    @Local count: number = 100;
  
    @Computed
    get double() {
      return this.count * 2;
    }
  
    // The @Computed decorated property is read-only. The setter implemented by you does not take effect, and an error is reported during compilation.
    set double(newValue : number) {
      this.count = newValue / 2;
    }
  
    build() {
      Scroll() {
        Column({ space: 3 }) {
          Text(`${this.count}`)
          // Incorrect format. The @Computed decorated property method is read-only and cannot be used together with two-way binding.
          Child({ double: this.double!! })
        }
      }
    }
  }
  ```

- The capability provided by \@Computed for the status management V2 can be used only in \@ComponentV2 and \@ObservedV2.
- Be cautious about loop solving when multiple \@Computed are used together.

  ```ts
  @Local a : number = 1;
  @Computed
  get b() {
    return this.a + ' ' + this.c;  // Incorrect format. A loop b -> c -> b exists.
  }
  @Computed
  get c() {
    return this.a + ' ' + this.b; // Incorrect format. A loop c -> b -> c exists.
  }
  ```

## Use Scenarios
### When the computed property changes, the **getter** accessor decorated by \@Computed is solved only once.
1. Using Computed Property in a Custom Component

- Click the first button to change the value of **lastName**, triggering **\@Computed fullName** recomputation.
- The **this.fullName** is bound to two **Text** components. The **fullName** log shows that the computation occurs only once.
- For the first two **Text** components, the **this.lastName +' '+ this.firstName** logic is solved twice.
- If multiple places on the UI need to use the **this.lastName +' '+ this.firstName** computational logic, you can use the computed property to reduce the number of computation times.
- Click the second button. The **age** increases automatically and the UI remains unchanged. Because **age** is not a state variable, only observed changes can trigger **\@Computed fullName** recomputation.

```ts
@Entry
@ComponentV2
struct Index {
  @Local firstName: string = 'Li';
  @Local lastName: string = 'Hua';
  age: number = 20; // Computed cannot be triggered.

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
        this.age++;  // Computed cannot be triggered.
      })
    }
  }
}
```

Note that the computed property itself has performance overhead. In actual application development:
- For the preceding simple computation, computed property is not needed.
- If the computed property is used only once in the view, you can solve the problem directly.

2. Using Computed Property in Classes Decorated by \@ObservedV2
- Click the button to change the value of **lastName** and the **\@Computed fullName** will be recomputed only once.

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

### \@Monitor can Listen for the Changes of the \@Computed Decorated Properties
The following example shows how to solve **fahrenheit** and **kelvin** by using computed property.
- Click "-" to run the logic **celsius--** -> **fahrenheit** -> **kelvin**. The change of **kelvin** triggers the **onKelvinMonitor**.
- Click "+" to run the logic **celsius++** -> **fahrenheit** -> **kelvin**. The change of **kelvin** triggers the **onKelvinMonitor**.

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
### \@Computed Decorated Properties Initialize \@Param
The following example shows how \@Computed Initialize \@Param.
- Click **Button('-')** and **Button('+')** to change the offering quantity. The **quantity** is decorated by \@Trace and can be observed when it is changed.
- The change of **quantity** triggers the recomputation of **total** and **qualifiesForDiscount**. In this way, you can get a result of the total price of the offering and the available discounts.
- The change of **total** and **qualifiesForDiscount** triggers the update of the **Text** component corresponding to the **Child** component.

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
