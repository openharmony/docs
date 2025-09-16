# \@Extend Decorator: Defining Extended Component Styles
<!--Kit: ArkUI--> 
<!--Subsystem: ArkUI--> 
<!--Owner: @BlYynNe--> 
<!--SE: @lixingchi1--> 
<!--TSE: @TerryTsao-->

Apart from [\@Styles](arkts-style.md) used to reuse styles, ArkUI also provides \@Extend for extending component styles.


> **NOTE**
>
> This decorator can be used in ArkTS widgets since API version 9.
>
> This decorator can be used in atomic services since API version 11.

## How to Use


### Syntax


```ts
@Extend(UIComponentName) function functionName { ... }
```


### Usage Rules

- Unlike \@Styles, \@Extend can encapsulate private attributes, private events, and globally defined methods of specific components.

  ```ts
  // @Extend(Text) supports the private attribute fontColor of the Text component.
  @Extend(Text)
  function fancy() {
    .fontColor(Color.Red)
  }
  
  // superFancyText can call the predefined method fancy.
  @Extend(Text)
  function superFancyText(size: number) {
    .fontSize(size)
    .fancy()
  }
  ```


- Unlike \@Styles, \@Extend enables decorated methods to accept parameters. When calling these methods, you pass parameters following standard TypeScript parameter passing conventions.

  ```ts
  // xxx.ets
  @Extend(Text)
  function fancy(fontSize: number) {
    .fontColor(Color.Red)
    .fontSize(fontSize)
  }
  
  @Entry
  @Component
  struct FancyUse {
    build() {
      Row({ space: 10 }) {
        Text('Fancy')
          .fancy(16)
        Text('Fancy')
          .fancy(24)
      }
    }
  }
  ```

- Parameters passed into \@Extend decorated methods can be functions serving as event handlers.

  ```ts
  @Extend(Text)
  function makeMeClick(onClick: () => void) {
    .backgroundColor(Color.Blue)
    .onClick(onClick)
  }

  @Entry
  @Component
  struct FancyUse {
    @State label: string = 'Hello World';

    onClickHandler() {
      this.label = 'Hello ArkUI';
    }

    build() {
      Row({ space: 10 }) {
        Text(`${this.label}`)
          .makeMeClick(() => {
            this.onClickHandler();
          })
      }
    }
  }
  ```

- Parameters passed into \@Extend decorated methods can also be [state variables](arkts-state-management-overview.md). Changes to these state variables cause the UI to re-render.

  ```ts
  @Extend(Text)
  function fancy(fontSize: number) {
    .fontColor(Color.Red)
    .fontSize(fontSize)
  }
  
  @Entry
  @Component
  struct FancyUse {
    @State fontSizeValue: number = 20
  
    build() {
      Row({ space: 10 }) {
        Text('Fancy')
          .fancy(this.fontSizeValue)
          .onClick(() => {
            this.fontSizeValue = 30
          })
      }
    }
  }
  ```


## Constraints

- Unlike \@Styles, \@Extend must be defined globally, outside of any component declaration.

> **NOTE**
>
> Styles defined using \@Extend can be used only in the file where they are declared and cannot be exported to other files.
>
> For styles requiring cross-file reuse, you are advised to use [AttributeModifier](../../ui/arkts-user-defined-extension-attributeModifier.md).

**Incorrect Usage**

```ts
@Entry
@Component
struct FancyUse {
  // Incorrect. @Extend must be defined globally, outside of any component declaration.
  @Extend(Text) function fancy (fontSize: number) {
    .fontSize(fontSize)
  }

  build() {
    Row({ space: 10 }) {
      Text('Fancy')
        .fancy(16)
    }
  }
}
```

**Correct Usage**

```ts
// Correct usage.
@Extend(Text)
function fancy(fontSize: number) {
  .fontSize(fontSize)
}

@Entry
@Component
struct FancyUse {
  build() {
    Row({ space: 10 }) {
      Text('Fancy')
        .fancy(16)
    }
  }
}
```


## Use Cases

The following example demonstrates how to use \@Extend for style reuse.<br>Original implementation, where three **Text** components are declared with individual **fontStyle**, **fontWeight**, and **backgroundColor** style settings:


```ts
@Entry
@Component
struct FancyUse {
  @State label: string = 'Hello World';

  build() {
    Row({ space: 10 }) {
      Text(`${this.label}`)
        .fontStyle(FontStyle.Italic)
        .fontWeight(100)
        .backgroundColor(Color.Blue)
      Text(`${this.label}`)
        .fontStyle(FontStyle.Italic)
        .fontWeight(200)
        .backgroundColor(Color.Pink)
      Text(`${this.label}`)
        .fontStyle(FontStyle.Italic)
        .fontWeight(300)
        .backgroundColor(Color.Orange)
    }.margin('20%')
  }
}
```

Using \@Extend for style composition and reuse:


```ts
@Extend(Text)
function fancyText(weightValue: number, color: Color) {
  .fontStyle(FontStyle.Italic)
  .fontWeight(weightValue)
  .backgroundColor(color)
}
```

Simplified code with the use of \@Extend:


```ts
@Entry
@Component
struct FancyUse {
  @State label: string = 'Hello World';

  build() {
    Row({ space: 10 }) {
      Text(`${this.label}`)
        .fancyText(100, Color.Blue)
      Text(`${this.label}`)
        .fancyText(200, Color.Pink)
      Text(`${this.label}`)
        .fancyText(300, Color.Orange)
    }.margin('20%')
  }
}
```
