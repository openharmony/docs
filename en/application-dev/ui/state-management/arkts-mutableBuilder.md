# mutableBuilder: Implementing Dynamic Update of Global @Builder

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @zhangwenhan-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:05:17.954Z pushedAt=2026-07-22T09:32:58.295Z -->

 When multiple global [\@Builder](./arkts-builder.md) functions are used within a single custom component to achieve different UI effects, code maintenance becomes very difficult, and the page is not neat enough. In this case, you can use [wrapBuilder](./arkts-wrapBuilder.md) to encapsulate the global @Builder. However, wrapBuilder does not support dynamically switching @Builder. The [mutableBuilder](../../reference/apis-arkui/arkui-ts/ts-universal-mutableBuilder.md) API is introduced to implement the dynamic switching of global @Builder.

> **NOTE**
>
> Since API version 22, developers can use **mutableBuilder** to implement dynamic switching of global @Builder.
>
> Since API version 22, **mutableBuilder** can be used in atomic services.

## **wrapBuilder** Does Not Support Dynamic Global @Builder

Currently, **wrapBuilder** does not support secondary value assignment. If \@Builder is changed, the UI remains unchanged.

```ts
class TextContent {
  text: string = '';
}

@Builder
function textBuilder(p: TextContent) {
  Text(p.text)
}

@Builder
function buttonBuilder(p: TextContent) {
  Button(p.text)
}

@Entry
@Component
struct Index {
  @State message: string = 'init';
  @State text: WrappedBuilder<[TextContent]> = wrapBuilder(textBuilder); // Use textBuilder for initialization.

  build() {
    Column() {
      this.text.builder({ text: this.message })
      Button().onClick(() => {
        this.text = wrapBuilder(buttonBuilder); // Click Button and replace textBuilder with buttonBuilder for secondary value assignment.
      })
    }
  }
}
```

In the preceding code, **textBuilder** is used to initialize **wrapBuilder**. When the **onClick** event of the **Button** is triggered, reinitializing **wrapBuilder** with **buttonBuilder** does not trigger the update of the corresponding @Builder.

To solve this problem, **mutableBuilder** is introduced as an encapsulation function for dynamic global @Builder. **mutableBuilder** returns a **MutableBuilder** object, which is used for the dynamic refresh of [global \@Builder](arkts-builder.md#global-custom-builder-function)

## API Description

mutableBuilder is a template function that returns a [MutableBuilder](../../reference/apis-arkui/arkui-ts/ts-universal-mutableBuilder.md#mutablebuilder-2) object. Compared with [WrappedBuilder](../../reference/apis-arkui/arkui-ts/ts-universal-wrapBuilder.md#wrappedbuilder), MutableBuilder can dynamically switch global @Builder functions.

```ts
declare function mutableBuilder<Args extends Object[]>(builder: BuilderCallback): MutableBuilder<Args>;
```

In addition, the **MutableBuilder** object is a template class , which is inherited from [WrappedBuilder](./arkts-wrapBuilder.md#available-apis).

```ts
declare class MutableBuilder<Args extends Object[]> extends WrappedBuilder<Args> {
}
```

> **NOTE**
>
> The template parameter **Args extends Object[]** needs to match the type of the \@Builder function parameter.

Invocation pattern:

```ts
let builderVar: MutableBuilder<[string, number]> = mutableBuilder(MyBuilder);
let builderArr: MutableBuilder<[string, number]>[] = [mutableBuilder(MyBuilder)]; // mutableBuilder can be placed in an array.
```

## Constraints

1. **mutableBuilder** only accepts a [global \@Builder decorated function](arkts-builder.md#global-custom-builder-function) as its argument, local @Builder decorated function is not supported. Otherwise, a compilation error is reported.

   ```ts
   class TextContent {
     text: string = '';
   }
   
   @Builder
   function globalBuilder(p: TextContent) {
     Text(p.text)
   }
   
   @ComponentV2
   struct MyApp {
     @Local message: string = 'init';
     // Correct usage.
     @Local switchingBuilder: MutableBuilder<[TextContent]> = mutableBuilder(globalBuilder);
     // Incorrect usage. When the local @Builder is used, an error is reported during compilation.
     @Local localBuilderObject: MutableBuilder<[TextContent]> = mutableBuilder(this.localBuilder);
     
     @Builder
     localBuilder(p: TextContent) {
       Text(p.text)
     }
     build() {
       Column() {
         this.switchingBuilder.builder({ text: this.message })
       }
     }
   }
   ```

2. The **builder** property method of the **MutableBuilder** object can only be used inside custom components; using it outside custom components will cause the program to crash at runtime.

   ```ts
   class TextContent {
     text: string = '';
   }
   
   @Builder
   function globalBuilder(p: TextContent) {
     Text(p.text)
   }
   
   // Incorrect usage. The builder property method of the MutableBuilder object is used outside the custom component. As a result, the system crashes at runtime.
   let outSideBuilder: MutableBuilder<[TextContent]> = mutableBuilder(globalBuilder);
   outSideBuilder.builder({ text: 'message' });
   
   @ComponentV2
   struct MyApp {
     @Local message: string = 'init';
     @Local switchingBuilder: MutableBuilder<[TextContent]> = mutableBuilder(globalBuilder);
     build() {
       Column() {
         // Correct usage. The builder property method of the MutableBuilder object is used in the custom component.
         this.switchingBuilder.builder({ text: this.message })
       }
     }
   }
   ```

3. You are not advised to use **mutableBuilder** together with **wrapBuilder** because the object type created by **mutableBuilder** is **MutableBuilder**, which may cause unexpected updates.

   The following usage is not recommended:

   ```ts
   // Use the mutableBuilder(builderName) method when instantiating the MutableBuilder object.
   @State switchingBuilder: MutableBuilder<[MutableBinding]> = mutableBuilder(textBuilder);
   // Do not assign undefined or null to variables of the MutableBuilder type. Otherwise, the system crashes.
   @State switchingBuilder: MutableBuilder<[MutableBinding]> | undefined | null = null; 
   Button(`MutableBuilder`).onClick(() => {
     // Do not assign the object created by wrapBuilder to the object of the MutableBuilder type. After the value is assigned, textBuilder is dynamically switched to buttonBuilder.
     this.switchingBuilder = wrapBuilder(buttonBuilder);  
   })
   ```

   The recommended usage is as follows:

   ```ts
   // Use the mutableBuilder(builderName) method when instantiating the MutableBuilder object.
   @State switchingBuilder: MutableBuilder<[MutableBinding]> = mutableBuilder(textBuilder);
   
   Button(`MutableBuilder`).onClick(() => {
      // The assignment dynamically switches textBuilder to buttonBuilder.
     this.switchingBuilder = mutableBuilder(buttonBuilder); // Recommended usage.
   })
   ```

## Dynamically Changing the Global @Builder Instance

Use the **textBuilder** method decorated with the \@Builder decorator as the parameter of **mutableBuilder**, and assign the return value of **mutableBuilder** to the **switchingBuilder** variable. In the **Button** click event, use the **buttonBuilder** method decorated with the \@Builder as the parameter of **mutableBuilder**, and assign the return value of **mutableBuilder** to the **switchingBuilder** variable again. In this way, **textBuilder** can be updated to **buttonBuilder**, solving the problem that **wrapBuilder** does not support secondary assignment.

```ts
class TextContent {
  text: string = '';
}

@Builder
function textBuilder(p: TextContent) {
  Text(p.text).margin(20)
}

@Builder
function buttonBuilder(p: TextContent) {
  Button(p.text).margin(20)
}

let counter: number = 1;
@Entry
@ComponentV2
struct MyApp {
  @Local message: string = 'init';
  @Local switchingBuilder: MutableBuilder<[TextContent]> = mutableBuilder(textBuilder);
  build() {
    Column() {
      this.switchingBuilder.builder({ text: this.message })
      Button('Click to change')
      .onClick(() => {
        counter++; // Modify counter each time the button is clicked to dynamically change the global @Builder.
        if(counter % 2 === 0) {
          this.message += 'B';
          this.switchingBuilder = mutableBuilder(buttonBuilder); // textBuilder--->buttonBuilder
        } else {
          this.message += 'T';
          this.switchingBuilder = mutableBuilder(textBuilder); // buttonBuilder--->textBuilder
        }
      })
    }.position({x: 120, y: 60})
  }
}
```

Click the button to dynamically change **textBuilder** to **buttonBuilder**, as shown in the following figure.

![arkts-mutableBuilder-dynamic-demo1](figures/mutableBuilder-dynamic-demo1.gif)

## Using mutableBuilder to Display Pop-up Menus

Since **MutableBuilder** inherits from **WrappedBuilder**, the @Builder corresponding to **mutableBuilder** has the same capabilities as **WrappedBuilder**. As shown in the following example, the @Builder method corresponding to **mutableBuilder** can be used as an input parameter for **bindMenu**, supporting the display of a pop-up menu when clicked.

```ts
@Builder
function overBuilder() {
  Row() {
    Text('Global Builder')
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }
}

@Entry
@Component
struct Index {
  @State arr: number[] = [1,2,3,4,5];

  mutableBuilderMenu: MutableBuilder<[]> = mutableBuilder<[]>(overBuilder);
  build() {
    Column() {
      List({ space: 10 }) {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text(`${item}`)
            .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
          // Display a popup menu using mutableBuilder.
          .bindMenu(this.mutableBuilderMenu.builder)
        }, (item: number) => JSON.stringify(item))
      }
    }
  }
}
```

## Observing @Builder Changes in mutableBuilder

 In the @Builder function corresponding to **mutableBuilder**, [MutableBinding](../../reference/apis-arkui/js-apis-stateManagement.md#mutablebindingt20) can be used to encapsulate state variables to observe changes in them. At the same time, changes to the @Builder in **mutableBuilder** can be listened to via [@Monitor](./arkts-new-monitor.md) or [addMonitor](./arkts-new-addMonitor-clearMonitor.md).

```ts
import { UIUtils, MutableBinding } from '@kit.ArkUI';

@Builder
function textBuilder(p: MutableBinding<string>) {
  Text(p.value)
    .margin(20)
    .onClick(() => {
      p.value += 't';
    })
}

@Builder
function buttonBuilder(p: MutableBinding<string>) {
  Button(p.value)
    .margin(20)
    .onClick(() => {
      p.value += 'b';
    })
}

let counter: number = 1;

@Entry
@ComponentV2
struct MyApp {
  @Local message: string = 'init';
  @Local switchingBuilder: MutableBuilder<[MutableBinding<string>]> = mutableBuilder(textBuilder);

  @Monitor('switchingBuilder') variableChange(m: IMonitor): void {
    console.info(`Builder changed. is buttonBuilder: ${m.value<MutableBuilder<[MutableBinding<string>]>>()?.now.builder === buttonBuilder}`);
  }

  build() {
    Column() {
      this.switchingBuilder.builder(UIUtils.makeBinding(()=> this.message, txt => this.message = txt))
      Button('Click to change')
        .onClick(() => {
          counter++;
          if(counter % 2 === 0) {
            this.message += 'B';
            this.switchingBuilder = mutableBuilder(buttonBuilder); // textBuilder--->buttonBuilder, @Monitor will trigger the callback.
          } else {
            this.message += 'T';
            this.switchingBuilder = mutableBuilder(textBuilder); // buttonBuilder--->textBuilder, @Monitor will trigger the callback.
          }
        })
    }.position({x: 120, y: 60})
  }
}
```

Click **Click to change** to dynamically switch **textBuilder** to **buttonBuilder**. **this.message** will be automatically added with **B**, and the **initB** button will be displayed on the page. Click **initB**. **p.value** in **buttonBuilder** is automatically added with **b**, as shown in the following figure.

![arkts-mutableBuilder-dynamic-demo2](figures/mutableBuilder-dynamic-demo2.gif)

When the `Click to change` button is tapped to dynamically switch `textBuilder` to `buttonBuilder`, @Monitor detects the change of the global @Builder and prints the log `Builder changed. is buttonBuilder: true`.