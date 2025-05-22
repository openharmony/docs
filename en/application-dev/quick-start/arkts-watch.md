# \@Watch Decorator: Getting Notified of State Variable Changes


\@Watch is used to listen for state variables. If your application needs watch for value changes of a state variable, you can decorate the variable with \@Watch.


In addition, \@Watch can only listen for changes that can be observed.

Before reading this topic, you are advised to read [\@State](./arkts-state.md) to have a understanding of the basic observation capabilities of state management.

> **NOTE**
>
> Since API version 9, this decorator is supported in ArkTS widgets.
>
> This decorator can be used in atomic services since API version 11.

## Overview

An application can request to be notified whenever the value of the \@Watch decorated variable changes. The \@Watch callback is called when the value change has occurred. \@Watch uses strict equality (===) to determine whether a value is updated in the ArkUI framework. If **false** is return, the \@Monitor decorated callback is triggered.


## Decorator Description

| \@Watch Decorator| Description                                      |
| -------------- | ---------------------------------------- |
| Decorator parameters         | Mandatory. Constant string, which is quoted. Reference to a (string) => void custom component member function.|
| Custom component variables that can be decorated   | All decorated state variables. Regular variables cannot be watched.              |
| Order of decorators        | The order of decorators does not affect the actual functions. You can determine it as required. It is recommended that the [\@State](./arkts-state.md), [\@Prop](./arkts-prop.md), and [\@Link](./arkts-link.md) decorators be placed before the \@Watch decorator, to keep the overall style consistent.|
| Called when| The variable changes and is assigned a value. For details, see [Time for \@Watch to be Called](#time-for-watch-to-be-called).|

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

- The \@Watch parameter is mandatory and must be of the string type. Otherwise, an error will be reported during compilation.

```ts
// Incorrect format. An error is reported during compilation.
@State @Watch() num: number = 10;
@State @Watch(change) num: number = 10;

// Correct format.
@State @Watch('change') num: number = 10;
change() {
  console.log(`xxx`);
}
```

- The parameters in \@Watch must be declared method names. Otherwise, an error will be reported during compilation.

```ts
// Incorrect format. No function with the corresponding name is available, and an error is reported during compilation.
@State @Watch('change') num: number = 10;
onChange() {
  console.log(`xxx`);
}

// Correct format.
@State @Watch('change') num: number = 10;
change() {
  console.log(`xxx`);
}
```

- Common variables cannot be decorated by \@Watch. Otherwise, an error will be reported during compilation.

```ts
// Incorrect format.
@Watch('change') num: number = 10;
change() {
  console.log(`xxx`);
}

// Correct format.
@State @Watch('change') num: number = 10;
change() {
  console.log(`xxx`);
}
```


## Use Scenarios

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

The procedure is as follows:

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

The procedure is as follows:

1. **Button.onClick** of the **BasketModifier** component adds an item to **BasketModifier shopBasket**.

2. The value of the \@Link decorated variable **BasketViewer shopBasket** changes.

3. The state management framework calls the \@Watch callback **BasketViewer onBasketUpdated** to update the value of **BasketViewer TotalPurchase**.

4. Because \@Link decorated shopBasket changes (a new item is added), the **ForEach** component executes the item Builder to render and build the new item. Because the @State decorated **totalPurchase** variable changes, the **Text** component is also re-rendered. Re-rendering happens asynchronously.

### Time for \@Watch to be Called

To show the \@Watch callback is called when the state variable changes, this example uses the \@Link and \@ObjectLink decorators in the child component to observe different state objects. You can change the state variable in the parent component and observe the calling sequence of the \@Watch callback to learn the relationship between the time for calling, value assignment, and synchronization.

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
    console.log(`Property of this parent component task is changed: ${changedPropertyName}`);
  }

  onTaskBChanged(changedPropertyName: string): void {
    console.log(`Property of this parent component task is changed: ${changedPropertyName}`);
  }

  build() {
    Column() {
      Text(`Parent component task A state: ${this.taskA.isFinished ? 'Finished' : 'Unfinished'}`)
      Text(`Parent component task B state: ${this.taskB.isFinished ? 'Finished' : 'Unfinished'}`)
      ChildComponent({ taskA: this.taskA, taskB: this.taskB })
      Button('Switch Task State')
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
    console.log(`Property of @ObjectLink associated task of the child component is changed: ${changedPropertyName}`);
  }

  onLinkTaskChanged(changedPropertyName: string): void {
    console.log(`Property of @Link associated task of the child component is changed: ${changedPropertyName}`);
  }

  build() {
    Column() {
      Text(`Child component task A state: ${this.taskA.isFinished ? 'Finished' : 'Unfinished'}`)
      Text(`Child component task B state: ${this.taskB.isFinished ? 'Finished' : 'Unfinished'}`)
    }
  }
}
```

The procedure is as follows:

1. When you click the button to switch the task state, the parent component updates **taskB** associated with \@ObjectLink and **taskA** associated with \@Link.

2. The following information is displayed in sequence in the log:
    ```
    Property of this parent component task is changed: taskB
    Property of this parent component task is changed: taskA
    Property of @Link associated task of the child component is changed: taskA
    Property of @ObjectLink associated task of the child component is changed: taskB
    ```

3. The log shows that the calling sequence of the parent component is the same as the change sequence, but the calling sequence of \@Link and \@ObjectLink in the child component is different from the variable update sequence in the parent component. This is because the variables of the parent component are updated in real time, but \@Link and \@ObjectLink in the child component obtain the updated data at different time. The \@Link associated state is updated synchronously, therefore, state change immediately calls the \@Watch callback. The update of \@ObjectLink associated state depends on the synchronization of the parent component. The \@Watch callback is called only when the parent component updates and passes the updated variables to the child component. Therefore, the calling sequence is slightly later than that of \@Link.

4. This behavior meets the expectation. The \@Watch callback is invoked based on the actual state variable change time.  Similarly, \@Prop may behave similarly to \@ObjectLink, and the time for its callback to be invoked is slightly later.

### Using changedPropertyName for Different Logic Processing

The following example shows how to use **changedPropertyName** in the \@Watch function for different logic processing.


```ts
@Entry
@Component
struct UsePropertyName {
  @State @Watch('countUpdated') apple: number = 0;
  @State @Watch('countUpdated') cabbage: number = 0;
  @State fruit: number = 0;
  // @Watch callback
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

The procedure is as follows:

1. Click **Button('Add apples')**, the value of **apple** changes.

2. The state management framework calls the \@Watch function **countUpdated** and the value of state variable **apple** is changed; the **if** logic condition is met, the value of **fruit** changes.

3. **Text**s bound to **apple** and **fruit** are rendered again.

4. Click **Button('Add cabbages')**, the value of **cabbage** changes.

5. The state management framework calls the \@Watch function **countUpdated** and the value of state variable **cabbage** is changed; the **if** logic condition is not met, the value of **fruit** does not change.

6. **Text** bound to **cabbage** is rendered again.
