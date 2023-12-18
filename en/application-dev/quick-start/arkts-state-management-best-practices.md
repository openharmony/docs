# Best Practices for State Management


This guide outlines best practices for state management in ArkUI applications. Read on to discover the common pitfalls in state management and how to avoid them, with carefully selected examples of recommended and not-recommended practices.

## Replacing @Prop with @ObjectLink to Minimize Unnecessary Deep Copy

When you need to pass values between parent and child components, choosing the right decorator can significantly improve application performance. If the value of a state variable is not changed in the child component, using @Prop to decorate the state variable will mean more time required in component creation.

[Nonexample]

```ts
@Observed
class ClassA {
  public c: number = 0;

  constructor(c: number) {
    this.c = c;
  }
}

@Component
struct PropChild {
  The @Prop testNum: ClassA; // @Prop makes a deep copy.

  build() {
    Text(`PropChild testNum ${this.testNum.c}`)
  }
}

@Entry
@Component
struct Parent {
  @State testNum: ClassA[] = [new ClassA(1)];

  build() {
    Column() {
      Text(`Parent testNum ${this.testNum[0].c}`)
        .onClick(() => {
          this.testNum[0].c += 1;
        })
      // PropChild does not change the value of @Prop testNum: ClassA. Therefore, @ObjectLink is a better choice.
      PropChild({ testNum: this.testNum[0] })
    }
  }
}
```

In the preceding example, the **PropChild** component does not change the value of **\@Prop testNum: ClassA**. Therefore, \@ObjectLink is a better choice, because \@Prop makes a deep copy and increases performance overhead.

[Example]


  
```ts
@Observed
class ClassA {
  public c: number = 0;

  constructor(c: number) {
    this.c = c;
  }
}

@Component
struct PropChild {
  @ObjectLink testNum: ClassA; // @ObjectLink does not make a deep copy.

  build() {
    Text(`PropChild testNum ${this.testNum.c}`)
  }
}

@Entry
@Component
struct Parent {
  @State testNum: ClassA[] = [new ClassA(1)];

  build() {
    Column() {
      Text(`Parent testNum ${this.testNum.c}`)
        .onClick(() => {
          this.testNum[0].c += 1;
        })
      PropChild({ testNum: this.testNum[0] })
    }
  }
}
```


## Avoiding Forcibly Updating Unassociated Components Through State Variables

[Nonexample]


```ts
@Entry
@Component
struct CompA {
  @State needsUpdate: boolean = true;
  realState1: Array<number> = [4, 1, 3, 2]; // No state variable decorator is used.
  realState2: Color = Color.Yellow;

  updateUI1(param: Array<number>): Array<number> {
    const triggerAGet = this.needsUpdate;
    return param;
  }
  updateUI2(param: Color): Color {
    const triggerAGet = this.needsUpdate;
    return param;
  }
  build() {
    Column({ space: 20 }) {
      ForEach(this.updateUI1(this.realState1),
        (item: Array<number>) => {
          Text(`${item}`)
        })
      Text("add item")
        .onClick(() => {
          // Changing realState1 does not trigger UI update.
          this.realState1.push(this.realState1[this.realState1.length-1] + 1);

          // Trigger the UI update.
          this.needsUpdate = !this.needsUpdate;
        })
      Text("chg color")
        .onClick(() => {
          // Changing realState2 does not trigger UI update.
          this.realState2 = this.realState2 == Color.Yellow ? Color.Red : Color.Yellow;

          // Trigger the UI update.
          this.needsUpdate = !this.needsUpdate;
        })
    }.backgroundColor(this.updateUI2(this.realState2))
    .width(200).height(500)
  }
}
```

The preceding example has the following pitfalls:

- The application wants to control the UI update logic, but in ArkUI, the UI update logic should be implemented by the framework detecting changes to the application state variables.

- **this.needsUpdate** is a custom state variable that should be applied only to the UI component to which it is bound. Because **this.realState1** and **this.realState2** are regular variables (not decorated), their changes do not trigger UI re-render.

- However, in this application, an attempt is made to update these two regular variables through **this.needsUpdate**. This approach is nonviable and may result in poor re-render performance: The change of **this.needsUpdate** will cause **ForEach** to re-render, even if the original intent is to update only the background color.

[Example]

To address this issue, decorate the **realState1** and **realState2** variables with \@State. Then, the variable **needsUpdate** is no longer required.


```ts
@Entry
@Component
struct CompA {
  @State realState1: Array<number> = [4, 1, 3, 2];
  @State realState2: Color = Color.Yellow;
  build() {
    Column({ space: 20 }) {
      ForEach(this.realState1,
        (item: Array<number>) => {
          Text(`${item}`)
        })
      Text("add item")
        .onClick(() => {
          // Changing realState1 triggers UI update.
          this.realState1.push(this.realState1[this.realState1.length-1] + 1);
        })
      Text("chg color")
        .onClick(() => {
          // Changing realState2 triggers UI update.
          this.realState2 = this.realState2 == Color.Yellow ? Color.Red : Color.Yellow;
        })
    }.backgroundColor(this.realState2)
    .width(200).height(500)
  }
}
```

## Precisely Controlling the Number of Components Associated with State Variables

When components are associated with state variables, they are re-rendered when the state value changes. The more components associated, the more components re-rendered, and the heavier the UI thread load, which causes a drop in application performance. Things can get worse when the associated components are complex. Therefore, it is critical to precisely control the number of associated components. For example, instead of associating a state variable with multiple components at the same level, associating it with these components' parent can greatly reduce the number of components to be re-rendered, thereby improving UI responsiveness.

[Nonexample]

```ts
@Observed
class Translate {
  translateX: number = 20;
}
@Component
struct Title {
  @ObjectLink translateObj: Translate;
  build() {
    Row() {
      Image($r('app.media.icon'))
        .width(50)
        .height(50)
        .translate({
          x:this.translateObj.translateX // this.translateObj.translateX used in two component both in Row
        })
      Text("Title")
        .fontSize(20)
        .translate({
          x: this.translateObj.translateX
        })
    }
  }
}
@Entry
@Component
struct Page {
  @State translateObj: Translate = new Translate();
  build() {
    Column() {
      Title({
        translateObj: this.translateObj
      })
      Stack() {
      }
      .backgroundColor("black")
      .width(200)
      .height(400)
      .translate({
        x:this.translateObj.translateX //this.translateObj.translateX used in two components both in Column
      })
      Button("move")
        .translate({
          x:this.translateObj.translateX
        })
        .onClick(() => {
          animateTo({
            duration: 50
          },()=>{
            this.translateObj.translateX = (this.translateObj.translateX + 50) % 150
          })
        })
    }
  }
}
```

In the preceding example, the state variable **this.translateObj.translateX** is used in multiple child components at the same level. When it changes, all these associated components are re-rendered. Since the changes of these components are the same, you can associate the state variable with their parent component to reduce the number of components re-rendered. Analysis reveals that all these child components are located in the **\<Column>** component under strcut **Page**. Therefore, you can associate the **translate** attribute to the **\<Column>** component instead.

[Example]

```ts
@Observed
class Translate {
  translateX: number = 20;
}
@Component
struct Title {
  build() {
    Row() {
      Image($r('app.media.icon'))
        .width(50)
        .height(50)
      Text("Title")
        .fontSize(20)
    }
  }
}
@Entry
@Component
struct Page1 {
  @State translateObj: Translate = new Translate();
  build() {
    Column() {
      Title()
      Stack() {
      }
      .backgroundColor("black")
      .width(200)
      .height(400)
      Button("move")
        .onClick(() => {
          animateTo({
            duration: 50
          },()=>{
            this.translateObj.translateX = (this.translateObj.translateX + 50) % 150
          })
        })
    }
    .translate({ // the component in Column shares the same property translate
      x: this.translateObj.translateX
    })
  }
}
```
