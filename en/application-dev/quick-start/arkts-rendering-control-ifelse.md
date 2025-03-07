# if/else: Conditional Rendering


ArkTS provides conditional rendering. It supports the use of the **if**, **else**, and **else if** statements to display different content based on the application state.

> **NOTE**
>
> This API can be used in ArkTS widgets since API version 9.

## Rules of Use

- The **if**, **else**, and **else if** statements are supported.

- The condition statements following the **if** or **else if** statement can use state variables or normal variables. (Value change of state variables can trigger UI rendering in real time, but value change of normal variables cannot.)

- Conditional statements can be used within a container component to build different child components.

- Conditional statements are "transparent" when it comes to the parent-child relationship of components. Rules about permissible child components must be followed when there is one or more **if** statements between the parent and child components.

- The build function inside each conditional branch must follow the special rules for build functions. Each of such build functions must create one or more components. An empty build function that creates no components will result in a syntax error.

- Some container components impose restrictions on the type or number of child components. When conditional statements are used in such components, these restrictions also apply to the components to be created by using the conditional statements. For example, the child component of the [Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md) container component supports only the [GridItem](../reference/apis-arkui/arkui-ts/ts-container-griditem.md) component. Therefore, only the **GridItem** can be used in the conditional statement within **Grid**.


## Update Mechanism

A conditional statement updates whenever a state variable used inside the **if** or **else if** condition changes. Specifically:

1. The conditional statement re-evaluates the conditions. If the evaluation of the conditions changes, steps 2 and 3 are performed. Otherwise, no follow-up operation is required.

2. The ArkUI framework removes all child components that have been built.

3. The ArkUI framework executes the build function of the conditional branch again to add the generated child component to its parent component. If an applicable **else** branch is missing, no new build function will be executed.

A condition can include Typescript expressions. As for any expression inside build functions, such an expression must not change any application state.


## Use Scenarios


### Using if for Conditional Rendering


```ts
@Entry
@Component
struct ViewA {
  @State count: number = 0;

  build() {
    Column() {
      Text(`count=${this.count}`)

      if (this.count > 0) {
        Text(`count is positive`)
          .fontColor(Color.Green)
      }

      Button('increase count')
        .onClick(() => {
          this.count++;
        })

      Button('decrease count')
        .onClick(() => {
          this.count--;
        })
    }
  }
}
```

Each branch of the **if** statement includes a build function. Each of such build functions must create one or more components. On initial render, **if** will execute a build function and add the generated child component to its parent component.

**if** updates whenever a state variable used inside the **if** or **else if** condition changes, and re-evaluates the conditions. If the evaluation of the conditions changes, it means that another branch of **if** needs to be built. In this case, the ArkUI framework will:

1. Remove all previously rendered components (of the earlier branch).

2. Execute the build function of the branch and add the generated child component to its parent component.

In the preceding example, if **count** increases from 0 to 1, then **if** updates, the condition **count > 0** is re-evaluated, and the evaluation result changes from **false** to **true**. Therefore, the positive branch build function will be executed, which creates a **Text** component and adds it to the **Column** parent component. If **count** changes back to 0 later, then the **Text** component will be removed from the **Column** component. Since there is no **else** branch, no new build function will be executed.


### if/else Statement and Child Component States

This example involves an **if/else** statement and a child component with an \@State decorated variable.


```ts
@Component
struct CounterView {
  @State counter: number = 0;
  label: string = 'unknown';

  build() {
    Column({ space: 20 }) {
      Text(`${this.label}`)
      Button(`counter ${this.counter} +1`)
        .onClick(() => {
          this.counter += 1;
        })
    }
    .margin(10)
    .padding(10)
    .border({ width: 1 })
  }
}

@Entry
@Component
struct MainView {
  @State toggle: boolean = true;

  build() {
    Column() {
      if (this.toggle) {
        CounterView({ label: 'CounterView #positive' })
      } else {
        CounterView({ label: 'CounterView #negative' })
      }
      Button(`toggle ${this.toggle}`)
        .onClick(() => {
          this.toggle = !this.toggle;
        })
    }
    .width('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

On first render, the child component **CounterView(label: 'CounterView \#positive')** is created. This child component carries the \@State decorated variable, named **counter**. When the **CounterView.counter** state variable is updated, the child component **CounterView(label: 'CounterView \#positive')** is re-rendered, with its state variable value preserved. When the value of the **MainView.toggle** state variable changes to **false**, the **if** statement inside the **MainView** parent component gets updated, and subsequently **CounterView(label: 'CounterView \#positive')** is removed. At the same time, a new child component **CounterView(label: 'CounterView \#negative')** is created, with the **counter** state variable set to the initial value **0**.

> **NOTE**
>
> **CounterView(label: 'CounterView \#positive')** and **CounterView(label: 'CounterView \#negative')** are two distinct instances of the same custom component. When the **if** branch changes, there is no update to an existing child component or no preservation of state.

The following example shows the required modifications if the value of **counter** needs to be preserved when the **if** condition changes:


```ts
@Component
struct CounterView {
  @Link counter: number;
  label: string = 'unknown';

  build() {
    Column({ space: 20 }) {
      Text(`${this.label}`)
        .fontSize(20)
      Button(`counter ${this.counter} +1`)
        .onClick(() => {
          this.counter += 1;
        })
    }
    .margin(10)
    .padding(10)
    .border({ width: 1 })
  }
}

@Entry
@Component
struct MainView {
  @State toggle: boolean = true;
  @State counter: number = 0;

  build() {
    Column() {
      if (this.toggle) {
        CounterView({ counter: $counter, label: 'CounterView #positive' })
      } else {
        CounterView({ counter: $counter, label: 'CounterView #negative' })
      }
      Button(`toggle ${this.toggle}`)
        .onClick(() => {
          this.toggle = !this.toggle;
        })
    }
    .width('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

Here, the \@State decorated variable **counter** is owned by the parent component. Therefore, it is not destroyed when a **CounterView** component instance is destroyed. The **CounterView** component refers to the state by an \@Link decorator. The state must be moved from a child to its parent (or parent of parent) to avoid losing it when the conditional content (or repeated content) is destroyed.


### Nested if Statements

The nesting of **if** statements makes no difference to the rule about the parent component.


```ts
@Entry
@Component
struct CompA {
  @State toggle: boolean = false;
  @State toggleColor: boolean = false;

  build() {
    Column({ space: 20 }) {
      Text('Before')
        .fontSize(15)
      if (this.toggle) {
        Text('Top True, positive 1 top')
          .backgroundColor('#aaffaa').fontSize(20)
        // Inner if statement
        if (this.toggleColor) {
          Text('Top True, Nested True, positive COLOR  Nested ')
            .backgroundColor('#00aaaa').fontSize(15)
        } else {
          Text('Top True, Nested False, Negative COLOR  Nested ')
            .backgroundColor('#aaaaff').fontSize(15)
        }
      } else {
        Text('Top false, negative top level').fontSize(20)
          .backgroundColor('#ffaaaa')
        if (this.toggleColor) {
          Text('positive COLOR  Nested ')
            .backgroundColor('#00aaaa').fontSize(15)
        } else {
          Text('Negative COLOR  Nested ')
            .backgroundColor('#aaaaff').fontSize(15)
        }
      }
      Text('After')
        .fontSize(15)
      Button('Toggle Outer')
        .onClick(() => {
          this.toggle = !this.toggle;
        })
      Button('Toggle Inner')
        .onClick(() => {
          this.toggleColor = !this.toggleColor;
        })
    }
    .width('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

## FAQs

### The if Branch Switching Protection Fails in the Animation Scenario

Switching the **if/else** branch, which is used for data protection, in the animation and continuously using it, data access will throw an exception, causing a crash.

Negative example:


```ts
class MyData {
  str: string;
  constructor(str: string) {
    this.str = str;
  }
}
@Entry
@Component
struct Index {
  @State data1: MyData|undefined = new MyData("branch 0");
  @State data2: MyData|undefined = new MyData("branch 1");

  build() {
    Column() {
      if (this.data1) {
        // If a Text is added or deleted in the animation, a default transition is added to Text.
        // However, when the Text is deleted, the component lifecycle is prolonged after the default opacity transition is added. The Text component is not deleted until the transition animation is complete.
        Text(this.data1.str)
          .id("1")
      } else if (this.data2) {
        // If a Text is added or deleted in the animation, a default transition is added to Text.
        Text(this.data2.str)
          .id("2")
      }

      Button("play with animation")
        .onClick(() => {
          animateTo({}, ()=>{
            // Change the if condition in animateTo, the first-layer component under the if condition is transitioned by default in the animation.
            if (this.data1) {
              this.data1 = undefined;
              this.data2 = new MyData("branch 1");
            } else {
              this.data1 = new MyData("branch 0");
              this.data2 = undefined;
            }
          })
        })

      Button("play directlp")
        .onClick(() => {
          // Directly changing the if condition enables proper branch switching, and the default transition is not added even is .
          if (this.data1) {
            this.data1 = undefined;
            this.data2 = new MyData("branch 1");
          } else {
            this.data1 = new MyData("branch 0");
            this.data2 = undefined;
          }
        })
    }.width("100%")
    .padding(10)
  }
}
```

Positive example:

Method 1: Add a null check protection to data when using data. For example, **Text(this.data1?.str)**.


```ts
class MyData {
  str: string;
  constructor(str: string) {
    this.str = str;
  }
}
@Entry
@Component
struct Index {
  @State data1: MyData|undefined = new MyData("branch 0");
  @State data2: MyData|undefined = new MyData("branch 1");

  build() {
    Column() {
      if (this.data1) {
        // If a Text is added or deleted in the animation, a default transition is added to Text.
        // However, when the Text is deleted, the component lifecycle is prolonged after the default opacity transition is added. The Text component is not deleted until the transition animation is complete.
        // Add a null check protection when using data. If data1 exists, use str in data1.
        Text(this.data1?.str)
          .id("1")
      } else if (this.data2) {
        // If a Text is added or deleted in the animation, a default transition is added to Text.
        // Add a null check protection when using data.
        Text(this.data2?.str)
          .id("2")
      }

      Button("play with animation")
        .onClick(() => {
          animateTo({}, ()=>{
            // Change the if condition in animateTo, the first-layer component under the if condition is transitioned by default in the animation.
            if (this.data1) {
              this.data1 = undefined;
              this.data2 = new MyData("branch 1");
            } else {
              this.data1 = new MyData("branch 0");
              this.data2 = undefined;
            }
          })
        })
    }.width("100%")
    .padding(10)
  }
}
```

Method 2: Add the **transition(TransitionEffect.IDENTITY)** attribute to the component to be deleted in the **if/else** statement to prevent the system from adding the default transition.


```ts
class MyData {
  str: string;
  constructor(str: string) {
    this.str = str;
  }
}
@Entry
@Component
struct Index {
  @State data1: MyData|undefined = new MyData("branch 0");
  @State data2: MyData|undefined = new MyData("branch 1");

  build() {
    Column() {
      if (this.data1) {
        // Display the specified null transition effect in the root component of the if/else statement to avoid the default transition animation.
        Text(this.data1.str)
          .transition(TransitionEffect.IDENTITY)
          .id("1")
      } else if (this.data2) {
        // Display the specified null transition effect in the root component of the if/else statement to avoid the default transition animation.
        Text(this.data2.str)
          .transition(TransitionEffect.IDENTITY)
          .id("2")
      }

      Button("play with animation")
        .onClick(() => {
          animateTo({}, ()=>{
            // Change the if condition in animateTo, the first-layer component under the if condition is transitioned by default in the animation.
            // The default transition will not be added if the specified transition has been displayed.
            if (this.data1) {
              this.data1 = undefined;
              this.data2 = new MyData("branch 1");
            } else {
              this.data1 = new MyData("branch 0");
              this.data2 = undefined;
            }
          })
        })
    }.width("100%")
    .padding(10)
  }
}
```
