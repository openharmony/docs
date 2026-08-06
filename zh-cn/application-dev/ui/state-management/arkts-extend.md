# \@Extend装饰器：定义扩展组件样式
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @BlYynNe-->
<!--Designer: @BlYynNe-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

在前文的示例中，可以使用[\@Styles](arkts-style.md)复用样式，在\@Styles的基础上，我们提供了[\@Extend](../../reference/apis-arkui/arkui-ts/ts-custom-component-decorator-extend.md#extend)，用于扩展组件样式。

> **说明：**
>
> 从API version 9开始支持。
>
> 从API version 9开始，该装饰器支持在ArkTS卡片中使用。
>
> 从API version 11开始，该装饰器支持在原子化服务中使用。

## 装饰器使用说明


### 语法


```ts
@Extend(UIComponentName) function functionName() { ... }
```


### 使用规则

- 和\@Styles不同，\@Extend支持封装指定组件的私有属性、私有事件和自身定义的全局方法。
  <!-- @[Extend_Global_Function_Extension_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/GlobalFunctionExtension.ets) -->
  
  ``` TypeScript
  // @Extend(Text)可以支持Text的私有属性fontColor
  @Extend(Text)
  function fancy() {
    .fontColor(Color.Red)
  }
  
  // superFancyText可以调用预定义的fancy
  @Extend(Text)
  function superFancyText(size: number) {
    .fontSize(size)
    .fancy()
  }
  ```

- 使用\@Extend封装指定组件的私有属性、私有事件和自身定义的全局方法时，不支持和\@Styles混用。
  ``` TypeScript
  @Styles
  function fancy() {
    .backgroundColor(Color.Red)
  }

  // superFancyText不可以调用预定义的fancy
  @Extend(Text)
  function superFancyText(size: number) {
    .fontSize(size)
    .fancy()
  }
  ```

- 和\@Styles不同，\@Extend装饰的方法支持传入参数，调用遵循TS方法传值调用。
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

- \@Extend装饰的方法的参数可以为function，作为Event事件的句柄。
  <!-- @[Extend_Function_handle_three](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendFunctionHandle.ets) --> 
  
  ``` TypeScript
  // @Extend装饰的方法支持function参数
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

- \@Extend的参数可以为[状态变量](arkts-state-management-overview.md)，当状态变量改变时，UI可以正常地被刷新渲染。
  <!-- @[Extend_Refresh_rendering_four](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendUIStateVariable.ets) --> 
  
  ``` TypeScript
  // 将状态变量作为@Extend参数，状态变化驱动Text样式刷新
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

## 限制条件

- 和\@Styles不同，\@Extend仅支持在全局定义，不支持在组件内部定义。

  > **说明：**
  >
  > 仅限在当前文件内使用，不支持导出。
  >
  > 如果要实现export功能，推荐使用[AttributeModifier](../arkts-user-defined-extension-attributeModifier.md)。
  
  【反例】
  
  ```ts
  @Entry
  @Component
  struct FancyUse {
    // 错误写法，@Extend仅支持在全局定义，不支持在组件内部定义。
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
  
  【正例】
  <!-- @[Extend_Positive_Example_five](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendPositiveExample.ets) --> 
  
  ``` TypeScript
  // 正确写法
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

- @Extend装饰的函数仅限当前文件使用，不支持导出，不支持在其他文件调用。

  【反例】

  ``` TypeScript
    // 错误写法 不要在pageTwo当中使用在其他文件比如pageOne中定义的@Extend函数。
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
            .ButtonUse()  // 会有编译告警提示: Property 'ButtonUse' does not exist  on type 'ButtonAttribute'.
            .height(50)
        }
      }
    }
  ```

  【正例】

  ``` TypeScript
    // 正确写法 在pageTwo文件当中可以定义与pageOne文件中的@Extend函数不重名的@Extend函数。
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

## 使用场景

以下示例声明了3个Text组件，每个Text组件均设置了[fontStyle](../../reference/apis-arkui/arkui-ts/ts-basic-components-text.md#fontstyle)、[fontWeight](../../reference/apis-arkui/arkui-ts/ts-basic-components-text.md#fontweight) 和[backgroundColor](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundcolor)样式。
<!-- @[Extend_Usage_Scenario_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendUsageScenario.ets) --> 

``` TypeScript
@Entry
@Component
struct FancyUse {
  @State label: string = 'Hello World';

  build() {
    Row({ space: 10 }) {
      // Text组件重复设置样式
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

使用@Extend将样式组合复用，示例如下。
<!-- @[Extend_Usage_Scenario_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendUsageScenariotwo.ets) --> 

``` TypeScript
// 使用@Extend封装Text样式组合，便于复用
@Extend(Text)
function fancyText(weightValue: number, color: Color) {
  .fontStyle(FontStyle.Italic)
  .fontWeight(weightValue)
  .backgroundColor(color)
}
```

通过\@Extend组合样式后，使得代码更加简洁，增强可读性。
<!-- @[Extend_Usage_Scenario_three](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/extend/ExtendUsageScenariotwo.ets) --> 

``` TypeScript
@Entry
@Component
struct FancyUse {
  @State label: string = 'Hello World';

  build() {
    Row({ space: 10 }) {
      // 调用@Extend封装的fancyText复用样式
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
