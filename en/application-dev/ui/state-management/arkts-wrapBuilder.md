# wrapBuilder: Encapsulating Global @Builder

When you use multiple global @Builder functions in a struct to implement different UI effects, the code maintenance becomes difficult and the page is not neat. In this case, you can use **wrapBuilder** to encapsulate the global @Builder.

  Before reading this topic, you are advised to read [\@Builder](./arkts-builder.md).

> **NOTE**
>
> This API is supported since API version 11.

After the @Builder method assigns a value to a variable or array, the variable or array cannot be used in the UI method.

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

In the preceding code, **builderArr** is an array consisting of @Builder methods. When each @Builder method is obtained from **ForEach**, the @Builder method cannot be used in the UI method.

 To solve this problem, **wrapBuilder** is introduced as the global @Builder encapsulation function. **wrapBuilder** is a template function that accepts a [global \@Builder decorated function](arkts-builder.md#global-custom-builder-function) as its argument and returns a **WrappedBuilder** object, thereby allowing global \@Builder decorated function to be assigned a value and transferred.

## Available APIs

**wrapBuilder** is a template function that returns a **WrappedBuilder** object.

```ts
declare function wrapBuilder< Args extends Object[]>(builder: (...args: Args) => void): WrappedBuilder;
```
The **WrappedBuilder** object is also a template class.

```ts
declare class WrappedBuilder< Args extends Object[]> {
  builder: (...args: Args) => void;

  constructor(builder: (...args: Args) => void);
}
```


>**NOTE**<br>The template parameter **Args extends Object[]** is a parameter list of the builder function to be wrapped.

Example

```ts
let builderVar: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder)
let builderArr: WrappedBuilder<[string, number]>[] = [wrapBuilder(MyBuilder)] // An array is acceptable.
```



## Constraints

**wrapBuilder** only accepts a [global \@Builder decorated function](arkts-builder.md#global-custom-builder-function) as its argument.

Of the **WrappedBuilder** object it returns, the **builder** attribute method can be used only inside the struct.



## Assigning a Value to a Variable Using the @Builder Method

The **MyBuilder** method decorated by @Builder is used as the parameter of **wrapBuilder**, and **wrapBuilder** is assigned to the **globalBuilder** variable, which solves the problem that the @Builder method cannot be used after being assigned to the variable.

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

In this example, the custom component **Index** uses **ForEach** to render different \@Builder functions. You can use the **wrapBuilder** array declared in **builderArr** to present different \@Builder function effects. In this way, the code is neat.

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
  @Builder testBuilder() {
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

If parameters are passed in by reference, the UI re-rendering is triggered.

```ts
class Tmp {
  paramA2: string = 'hello';
}

@Builder function overBuilder(param: Tmp) {
  Column(){
    Text(`wrapBuildervalue:${param.paramA2}`)
  }
}

const wBuilder: WrappedBuilder<[Tmp]> = wrapBuilder(overBuilder);

@Entry
@Component
struct Parent{
  @State label: Tmp = new Tmp();
  build(){
    Column(){
      wBuilder.builder({paramA2: this.label.paramA2})
      Button('Click me').onClick(() => {
        this.label.paramA2 = 'ArkUI';
      })
    }
  }
}
```

## FAQs

### wrapBuilder Redefinition Failure

In the same custom component, the same **wrapBuilder** can be initialized only once. In the example, after **builderObj** is initialized through **wrapBuilder(MyBuilderFirst)**, **wrapBuilder(MyBuilderSecond)** does not take effect when a value is assigned to **builderObj** again.

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
      // wrapBuilder (MyBuilderSecond) does not take effect.
      this.builderObj.globalBuilder = wrapBuilder(MyBuilderSecond);
    },1000)
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
