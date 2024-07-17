# ComponentContent

ComponentContent indicates the entity encapsulation of component content. The ComponentContent object can be created and transferred in non-UI components so that developers can decouple and encapsulate pop-up window components.

> **NOTE**
>
> This module is supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> **XComponentNode** is not available in DevEco Studio Previewer.


## Import modules.

```ts
import { ComponentContent } from "@ohos.arkui.node";
```

## ComponentContent

### constructor

constructor(uiContext: UIContext, builder: WrappedBuilder<[]>)

This function is the constructor of ComponentContent.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory/Optional | Note:                              |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | Supported  | UI context required for creating a node. |
| builder  | [WrappedBuilder<[]>](../../quick-start/arkts-wrapBuilder.md) | Supported  |   WrappedBuilder object that encapsulates the builder function without parameters. |

### constructor

constructor(uiContext: UIContext, builder: WrappedBuilder<[T]>, args: T)

This function is the constructor of ComponentContent.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory/Optional | Description                              |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | Supported  | UI context required for creating a node. |
| builder  | [WrappedBuilder<[T]>](../../quick-start/arkts-wrapBuilder.md) | Supported  |   WrappedBuilder object that encapsulates the builder function with parameters. |
| args     |     T     |   M  |   Parameters of the builder function encapsulated in the WrappedBuilder object. |

### update

update(args: T): void

Updates the builder function parameters encapsulated in the WrappedBuilder object. The parameter type must be the same as that transferred by the constructor.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters

| Parameter | Type | Mandatory/Optional | Note:                                                        |
| ------ | ---- | ---- | ------------------------------------------------------------ |
| args   | T    | Supported  | Updates the builder function parameters encapsulated in the WrappedBuilder object. The parameter type must be the same as that transferred by the constructor. |

**Example**

```ts
import { ComponentContent } from "@ohos.arkui.node";

class Params {
  text: string = ""
  constructor(text: string) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({bottom: 36})
  }.backgroundColor('#FFF0F0F0')
}

@Entry
@Component
struct Index {
  @State message: string = "hello"

  build() {
    Row() {
      Column() {
        Button("click me")
            .onClick(() => {
                let uiContext = this.getUIContext();
                let promptAction = uiContext.getPromptAction();
                let contentNode = new ComponentContent(uiContext, wrapBuilder(buildText), new Params(this.message));
                promptAction.openCustomDialog(contentNode);

                setTimeout(() => {
                  contentNode.update(new Params("new message"));
                }, 2000); // Automatically update the text in the pop-up window 2 seconds later.
            })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

### reuse

reuse(param?: Object): void

Transfer the reuse event to the custom component in ComponentContent.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters

| Parameter | Type  | Mandatory/Optional | Note:                                                                    |
| ------ | ------ | ---- | ------------------------------------------------------------------------ |
| param  | Object | No  | This parameter is used to reuse the builder function parameters encapsulated by the WrappedBuilder object. The parameter type must be the same as that transferred by the constructor. |

### recycle

recycle(): void

Transfer the recycle event to the custom component in ComponentContent.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

```ts
import { ComponentContent } from "@ohos.arkui.node";

class Params {
  text: string = ""

  constructor(text: string) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  ReusableChildComponent2({ text: params.text });
}

@Component
struct ReusableChildComponent2 {
  @Prop text: string = "false";

  aboutToReuse(params: Record<string, object>) {
    console.log("ReusableChildComponent2 Reusable " + JSON.stringify(params));
  }

  aboutToRecycle(): void {
    console.log("ReusableChildComponent2 aboutToRecycle " + this.text);
  }

  build() {
    Column() {
      Text(this.text)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .margin({ bottom: 36 })
    }.backgroundColor('#FFF0F0F0')
  }
}

@Entry
@Component
struct Index {
  @State message: string = "hello"

  build() {
    Row() {
      Column() {
        Button("click me")
          .onClick(() => {
            let uiContext = this.getUIContext();
            let promptAction = uiContext.getPromptAction();
            let contentNode = new ComponentContent(uiContext, wrapBuilder(buildText), new Params(this.message));
            promptAction.openCustomDialog(contentNode);

            setTimeout(() => {
              contentNode.reuse(new Params("new message"));
              contentNode.recycle();
            }, 2000); // Automatically update the text in the pop-up window 2 seconds later.
          })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```
