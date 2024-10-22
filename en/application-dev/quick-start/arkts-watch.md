# \@Watch Decorator: Getting Notified of State Variable Changes


\@Watch is used to listen for state variables. If your application needs watch for value changes of a state variable, you can decorate the variable with \@Watch.


> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.
>
> This decorator can be used in atomic services since API version 11.

## Overview

An application can request to be notified whenever the value of the \@Watch decorated variable changes. The \@Watch callback is called when the value change has occurred. \@Watch uses strict equality (===) to determine whether a value is updated in the ArkUI framework. If **false** is returned, the \@Watch callback is triggered.


## Decorator Description

| \@Watch Decorator| Description                                      |
| -------------- | ---------------------------------------- |
| Decorator parameters         | Mandatory. Constant string, which is quoted. Reference to a (string) => void custom component member function.|
| Custom component variables that can be decorated   | All decorated state variables. Regular variables cannot be watched.              |
| Order of decorators        | Place the [\@State](./arkts-state.md), [\@Prop](./arkts-prop.md), or [\@Link](./arkts-link.md) decorator in front of the \@Watch decorator.|


## Syntax

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| (changedPropertyName?&nbsp;:&nbsp;string)&nbsp;=&gt;&nbsp;void | This function is a member function of the custom component. **changedPropertyName** indicates the name of the watched attribute.<br>It is useful when you use the same function as a callback to several watched attributes.<br>It takes the attribute name as a string input parameter and returns nothing.|


## Observed Changes and Behavior

1. \@Watch callback is triggered when a change of a state variable (including the change of a key in [AppStorage](./arkts-appstorage.md) and [LocalStorage](./arkts-localstorage.md) that are bound in a two-way manner) is observed.

2. The \@Watch callback is executed synchronously after the variable change in the custom component.

3. If the \@Watch callback mutates other watched variables, their variable @Watch callbacks in the same and other custom components as well as state updates are triggered.

4. A \@Watch function is not called upon custom component variable initialization, because initialization is not considered as variable mutation. A \@Watch function is called upon change of the custom component variable.


## Restrictions

- Pay attention to the risk of infinite loops. Loops can be caused by the \@Watch callback directly or indirectly mutating the same variable. To avoid loops, do not mutate the \@Watch decorated state variable inside the callback handler.

- Pay attention to performance. The attribute value update function delays component re-render (see the preceding behavior description). The callback should only perform quick computations.

- Calling **async await** from an \@Watch function is not recommended, because asynchronous behavior may cause performance issues of re-rendering.


## Application Scenarios

### \@Watch and Custom Component Update

This example is used to clarify the processing steps of custom component updates and \@Watch. **count** is decorated by \@State in **CountModifier** and \@Prop in **TotalView**.


```ts
@Component
struct TotalView {
  @Prop @Watch('onCountUpdated') count: number = 0;
  @State total: number = 0;
  // @Watch callback
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

Processing steps:

1. The click event **Button.onClick** of the **CountModifier** custom component increases the value of **count**.

2. In response to the change of the @State decorated variable **count**, \@Prop in the child component **TotalView** is updated, and its **\@Watch('onCountUpdated')** callback is invoked, which updates the **total** variable in **TotalView**.

3. The **Text** component in the child component **TotalView** is re-rendered.


### Combination of \@Watch and \@Link

This example illustrates how to watch an \@Link decorated variable in a child component.


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
    // A discount is provided when the amount exceeds 100 euros.
    if (total >= 100) {
      total = 0.9 * total;
    }
    return total;
  }
  // @Watch callback
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

Processing steps:

1. **Button.onClick** of the **BasketModifier** component adds an item to **BasketModifier shopBasket**.

2. The value of the \@Link decorated variable **BasketViewer shopBasket** changes.

3. The state management framework calls the \@Watch callback **BasketViewer onBasketUpdated** to update the value of **BasketViewer TotalPurchase**.

4. Because \@Link decorated shopBasket changes (a new item is added), the **ForEach** component executes the item Builder to render and build the new item. Because the @State decorated **totalPurchase** variable changes, the **Text** component is also re-rendered. Re-rendering happens asynchronously.
