# wrapBuilder: Encapsulating Global @Builder


 **wrapBuilder** is a template function that accepts a [global \@Builder decorated function](arkts-builder.md#global-custom-builder-function) as its argument and returns a **WrappedBuilder** object, thereby allowing global \@Builder decorated function to be assigned a value and transferred.


> **NOTE**
>
> This API is supported since API version 11.

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

Example:

```ts
let builderVar: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder)
let builderArr: WrappedBuilder<[string, number]>[] = [wrapBuilder(MyBuilder)] // An array is acceptable.
```

## Constraints

**wrapBuilder** only accepts a [global \@Builder decorated function](arkts-builder.md#global-custom-builder-function) as its argument.

Of the **WrappedBuilder** object it returns, the **builder** attribute method can be used only inside the struct.

## Use Scenario 1

In this example, **wrapBuilder** is assigned to **globalBuilder**, and **MyBuilder** is passed in to **wrapBuilder** as its input parameter. In this way, **MyBuilder** is assigned to **globalBuilder** indirectly.

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

## Use Scenario 2

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

## Use Scenario 3

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

## Incorrect Usage

```
function MyBuilder() {

}

// wrapBuilder accepts only a global function decorated by @Builder.
const globalBuilder: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder);

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        globalBuilder.builder(this.message, 30)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
