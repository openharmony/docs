# \@Extend Decorator: Defining Extended Component Styles

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @BlYynNe-->
<!--Designer: @BlYynNe-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:03:27.795Z pushedAt=2026-07-22T07:47:51.322Z -->

In the preceding example, [@Styles](arkts-style.md) can be used to reuse styles. Building on @Styles, we provide [@Extend](../../reference/apis-arkui/arkui-ts/ts-custom-component-decorator-extend.md#extend) for extending component styles.

> **NOTE**
>
> The APIs of this module are supported since API version 9.
>
> This decorator can be used in ArkTS widgets since API version 9.
>
> This decorator can be used in atomic services since API version 11.

## How to Use

### Syntax

```ts
@Extend(UIComponentName) function functionName() { ... }
```

### Usage Rules

- Unlike \@Styles, \@Extend can encapsulate private attributes, private events, and globally defined methods of specific components.

  <!-- @[Extend_Global_Function_Extension_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/GlobalFunctionExtension.ets) -->

  ``` TypeScript
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

- When \@Extend is used to encapsulate the private attributes, private events, and globally defined methods of a specified component, \@Extend and \@Styles cannot be used together.

  ``` TypeScript
  @Styles
  function fancy() {
    .backgroundColor(Color.Red)
  }

  // superFancyText cannot call the predefined method fancy.
  @Extend(Text)
  function superFancyText(size: number) {
    .fontSize(size)
    .fancy()
  }
  ```

- Different from \@Styles decorated methods, the \@Extend decorated methods support passing parameters. The calling complies with the TS method calling convention.

  <!-- @[Extend_private_property_fancy_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendParameterUsage.ets) -->

  ``` TypeScript
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

  <!-- @[Extend_Function_handle_three](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendFunctionHandle.ets) --> 

  ``` TypeScript
  // Methods decorated with @Extend support function parameters.
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

  <!-- @[Extend_Refresh_rendering_four](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendUIStateVariable.ets) --> 

  ``` TypeScript
  // Use a state variable as the @Extend parameter so that state changes drive the Text style refresh.
  @Extend(Text)
  function fancy(fontSize: number) {
    .fontColor(Color.Blue)
    .fontSize(fontSize)
  }
  
  @Entry
  @Component
  struct FancyUse {
    @State fontSizeValue: number = 20;
  
    build() {
      Column({ space: 10 }) {
        Text('Fancy')
          .fancy(this.fontSizeValue)
          .onClick(() => {
            this.fontSizeValue = 30;
          })
      }
      .width('100%')
    }
  }
  ```

![](figures/arkts-extend-1.gif)

## Constraints

- Unlike \@Styles, \@Extend must be defined globally, outside of any component declaration.

> **NOTE**
>
> @Extend can be used only in the current file and cannot be exported.
>
> To implement the export feature, you are advised to use [AttributeModifier](../arkts-user-defined-extension-attributeModifier.md).

**Incorrect Usage**

  ```ts
  @Entry
  @Component
  struct FancyUse {
    // Incorrect usage. @Extend supports only global definition, not definition inside a component.
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

  <!-- @[Extend_Positive_Example_five](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendPositiveExample.ets) --> 

  ``` TypeScript
  // Correct approach
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

- Functions decorated with @Extend can be used only in the current file and cannot be exported or called in other files.

**Incorrect Usage**

  ``` TypeScript
    // Incorrect usage: Do not use an @Extend function defined in another file (for example, pageOne) in pageTwo.
    // pageOne.ets
    @Extend(Button)
    function ButtonUse() {
      .width(100)
      .buttonStyle(ButtonStyleMode.NORMAL)
    }

    @Entry
    @Component
    struct extendUseOne {
      build() {
        Row() {
          Button()
            .ButtonUse()
            .height(200)
        }
      }
    }
  
    // pageTwo.ets
    @Entry
    @Component
    struct TextUse {
      build() {
        Row() {
          Text('this is TextUse')

          Button()
            .ButtonUse()  // A compilation warning is reported: Property 'ButtonUse' does not exist on type 'ButtonAttribute'.
            .height(50)
        }
      }
    }
  ```

**Correct Usage**

  ``` TypeScript
    // Correct approach: In the pageTwo file, you can define an @Extend function with a different name from the @Extend function in the pageOne file.
    // pageOne.ets
    @Extend(Button)
    function ButtonUse() {
      .width(100)
      .buttonStyle(ButtonStyleMode.NORMAL)
    }

    @Entry
    @Component
    struct extendUseOne {
      build() {
        Row() {
          Button()
            .ButtonUse()
            .height(200)
        }
      }
    }
  
    // pageTwo.ets
    @Extend(Button)
    function ButtonUse2() {
      .width(200)
      .buttonStyle(ButtonStyleMode.EMPHASIZED)
    }

    @Entry
    @Component
    struct TextUse {
      build() {
        Row() {
          Text('this is TextUse')
  
          Button()
            .ButtonUse2()
            .height(50)
        }
      }
    }
  ```

## When to Use

The following example declares three **Text** components, each configured with [fontStyle](../../reference/apis-arkui/arkui-ts/ts-basic-components-text.md#fontstyle), [fontWeight](../../reference/apis-arkui/arkui-ts/ts-basic-components-text.md#fontweight), and [backgroundColor](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor) styles.

<!-- @[Extend_Usage_Scenario_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendUsageScenario.ets) --> 

``` TypeScript
@Entry
@Component
struct FancyUse {
  @State label: string = 'Hello World';

  build() {
    Row({ space: 10 }) {
      // Repeatedly set styles for the Text component.
      Text(`${this.label}`)
        .fontStyle(FontStyle.Italic)
        .fontWeight(500)
        .backgroundColor(Color.Yellow)
      Text(`${this.label}`)
        .fontStyle(FontStyle.Italic)
        .fontWeight(600)
        .backgroundColor(Color.Pink)
      Text(`${this.label}`)
        .fontStyle(FontStyle.Italic)
        .fontWeight(700)
        .backgroundColor(Color.Orange)
    }.margin('20%')
  }
}
```

![](figures/arkts-extend-2.png)

Using \@Extend for style composition and reuse:

<!-- @[Extend_Usage_Scenario_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendUsageScenariotwo.ets) --> 

``` TypeScript
// Use @Extend to encapsulate Text style combinations for easy reuse.
@Extend(Text)
function fancyText(weightValue: number, color: Color) {
  .fontStyle(FontStyle.Italic)
  .fontWeight(weightValue)
  .backgroundColor(color)
}
```

Simplified code with the use of \@Extend:

<!-- @[Extend_Usage_Scenario_three](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendUsageScenariotwo.ets) --> 

``` TypeScript
@Entry
@Component
struct FancyUse {
  @State label: string = 'Hello World';

  build() {
    Row({ space: 10 }) {
      // Call the fancyText reusable style encapsulated by @Extend.
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

<!--no_check-->