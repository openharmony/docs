# wrapBuilder: Encapsulating Global @Builder

  When multiple global @Builder functions are used within a single struct to implement different UI effects, code maintenance becomes challenging and the page structure appears cluttered. **wrapBuilder** provides a solution to encapsulate these global builders.

  Before reading this topic, you are advised to read [\@Builder](./arkts-builder.md).

> **NOTE**
>
> This feature is supported since API version 11.

When the @Builder method is assigned to a variable or array, it cannot be used in the UI method.

```ts
@Builder
function builderElement() {}

let builderArr: Function[] = [builderElement];
@Builder
function testBuilder() {
  ForEach(builderArr, (item: Function) => {
    item();
  })
}
```

In the preceding code, **builderArr** is an array of @Builder methods. When you obtain each @Builder method in the ForEach loop, an issue arises where the @Builder method cannot be used in the UI method.

To address this issue, **wrapBuilder** is introduced as a global @Builder encapsulation function. **wrapBuilder** returns a **WrappedBuilder** object, enabling [global @Builder functions](arkts-builder.md#global-custom-builder-function) to be assigned and passed.

## Available APIs

**wrapBuilder** is a template function that returns a **WrappedBuilder** object.

```ts
declare function wrapBuilder<Args extends Object[]>(builder: (...args: Args) => void): WrappedBuilder<Args>;
```
The **WrappedBuilder** object is also a template class.

```ts
declare class WrappedBuilder<Args extends Object[]> {
  builder: (...args: Args) => void;

  constructor(builder: (...args: Args) => void);
}
```


>**NOTE**<br>The template parameter **Args extends Object[]** is a parameter list of the builder function to be wrapped.

Example

```ts
let builderVar: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder);
let builderArr: WrappedBuilder<[string, number]>[] = [wrapBuilder(MyBuilder)]; // Can be placed in arrays.
```



## Constraints

1. **wrapBuilder** only accepts a [global \@Builder decorated function](arkts-builder.md#global-custom-builder-function) as its argument.

2. Of the **WrappedBuilder** object it returns, the **builder** attribute method can be used only inside the struct.

## Assigning a Value to a Variable Using the @Builder Method

To solve the issue where an @Builder decorated method (for example, **MyBuilder**) cannot be used after being assigned to a variable, you can pass the method as a parameter to **wrapBuilder**, and then assign the return value of **wrapBuilder** to the variable **globalBuilder**.

```ts
@Builder
function MyBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
}

let globalBuilder: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder);

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        globalBuilder.builder(this.message, 50)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

##  Assigning a Value to a Variable by the @Builder Method to Use the Variable in UI Syntax

In this example, the custom component **Index** uses **ForEach** to render different \@Builder functions. You can use the **wrapBuilder** array declared in **builderArr** to achieve different \@Builder function effects. This results in cleaner and more organized code.

```
@Builder
function MyBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
}

@Builder
function YourBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
    .fontColor(Color.Pink)
}

const builderArr: WrappedBuilder<[string, number]>[] = [wrapBuilder(MyBuilder), wrapBuilder(YourBuilder)];


@Entry
@Component
struct Index {
  @Builder
  testBuilder() {
    ForEach(builderArr, (item: WrappedBuilder<[string, number]>) => {
      item.builder('Hello World', 30)
    }

    )
  }

  build() {
    Row() {
      Column() {
        this.testBuilder()
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Passing Parameters by Reference

When parameters are passed by reference, changes to state variables will trigger UI updates inside the @Builder method.

```ts
class Tmp {
  paramA2: string = 'hello';
}

@Builder
function overBuilder(param: Tmp) {
  Column() {
    Text(`wrapBuildervalue:${param.paramA2}`)
  }
}

const wBuilder: WrappedBuilder<[Tmp]> = wrapBuilder(overBuilder);

@Entry
@Component
struct Parent {
  @State label: Tmp = new Tmp();

  build() {
    Column() {
      wBuilder.builder({ paramA2: this.label.paramA2 })
      Button('Click me').onClick(() => {
        this.label.paramA2 = 'ArkUI';
      })
    }
  }
}
```

## FAQs

### Failure of Duplicate wrapBuilder Initialization

In the same custom component, the same **wrapBuilder** can be initialized only once. In the example, after **builderObj** is initialized through **wrapBuilder(MyBuilderFirst)**, re-assigning it with **wrapBuilder(MyBuilderSecond)** will not take effect.

```ts
@Builder
function MyBuilderFirst(value: string, size: number) {
  Text('MyBuilderFirst: ' + value)
    .fontSize(size)
}

@Builder
function MyBuilderSecond(value: string, size: number) {
  Text('MyBuilderSecond: ' + value)
    .fontSize(size)
}

interface BuilderModel {
  globalBuilder: WrappedBuilder<[string, number]>;
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  @State builderObj: BuilderModel = { globalBuilder: wrapBuilder(MyBuilderFirst) };

  aboutToAppear(): void {
    setTimeout(() => {
      // wrapBuilder(MyBuilderSecond) does not take effect.
      this.builderObj.globalBuilder = wrapBuilder(MyBuilderSecond);
    }, 1000);
  }

  build() {
    Row() {
      Column() {
        this.builderObj.globalBuilder.builder(this.message, 20)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
