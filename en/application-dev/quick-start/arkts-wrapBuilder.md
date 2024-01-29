# wrapBuilder: Encapsulating a Global @Builder


 **wrapBuilder** is a method that accepts a global \@Builder method and returns a **WrappedBuilder** object. With this method, you can assign values and pass parameters for the [global \@Builder](arkts-builder.md#global-custom-builder-function).


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
  builder: (...args: Args): void;

  constructor(builder: (...args: Args) => void);
}
```


>**NOTE**<br>The template parameter **Args extends Object[]** is a parameter list of the builder function to be wrapped.

Example

```ts
let builderVar: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder)
let builderArr: WrappedBuilder<[string, number]>[] = [wrapBuilder(MyBuilder)] // An array can be placed.
```



## Constraints

The **wrapBuilder** method accepts only a [global \@Builder](arkts-builder.md#global-custom-builder-function) method as its argument.

Of the **WrappedBuilder** object it returns, the **builder** attribute method can be used only inside the struct.



## Usage Scenario 1

In this example, the custom component **Index** uses the **wrapBuilder** method declared in the global builder method **globalBuilder**. When the **Text()** component is clicked, **globalBuilder** assigns a new value to **wrapBuilder**, thereby switching between different effects.

```ts
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

let globalBuilder: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder);
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        globalBuilder.builder(this.message, 50)
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() =>{
            this.message = 'Test wrapBuilder';
            globalBuilder = wrapBuilder(YourBuilder);
          })

      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Usage Scenario 2

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



## Nonexample

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
