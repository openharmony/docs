# ComponentContent

**ComponentContent** represents an entity encapsulation of component content, which can be created and transmitted outside of UI components. It allows you to encapsulate and decouple dialog box components. The underlying implementation of **ComponentContent** uses BuilderNode. For details, see [BuilderNode](js-apis-arkui-builderNode.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> **ComponentContent** is not available in DevEco Studio Previewer.


## Modules to Import

```ts
import { ComponentContent } from '@kit.ArkUI';
```

## ComponentContent

### constructor

constructor(uiContext: UIContext, builder: WrappedBuilder\<[]>)

A constructor used to create a **ComponentContent** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory| Description                              |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating the node.|
| builder  | [WrappedBuilder\<[]>](../../quick-start/arkts-wrapBuilder.md) | Yes  |   **WrappedBuilder** object that encapsulates a builder function that has no parameters.|

### constructor

constructor(uiContext: UIContext, builder: WrappedBuilder\<[T]>, args: T)

A constructor used to create a **ComponentContent** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory| Description                              |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating the node.|
| builder  | [WrappedBuilder\<[T]>](../../quick-start/arkts-wrapBuilder.md) | Yes  |   **WrappedBuilder** object that encapsulates a builder function that has parameters.|
| args     |     T     |   Yes  |   Parameters of the builder function encapsulated in the **WrappedBuilder** object.|

### constructor

  constructor(uiContext: UIContext, builder: WrappedBuilder\<[T]>, args: T, options: BuildOptions)

A constructor used to create a **ComponentContent** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory| Description                              |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating the node.|
| builder  | [WrappedBuilder\<[T]>](../../quick-start/arkts-wrapBuilder.md) | Yes  |   **WrappedBuilder** object that encapsulates a builder function that has parameters.|
| args     |     T     |   Yes  |   Parameters of the builder function encapsulated in the **WrappedBuilder** object.|
| options | [BuildOptions](./js-apis-arkui-builderNode.md#buildoptions12)                                                    | Yes  |  Build options, which determine whether to support the behavior of nesting **@Builder** within **@Builder**.                                        |

**Example**
``` ts
import { ComponentContent, NodeContent, typeNode } from "@kit.ArkUI"

interface ParamsInterface {
  text: string;
  func: Function;
}

@Builder
function buildTextWithFunc(fun: Function) {
  Text(fun())
    .fontSize(50)
    .fontWeight(FontWeight.Bold)
    .margin({ bottom: 36 })
}

@Builder
function buildText(params: ParamsInterface) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({ bottom: 36 })
    buildTextWithFunc(params.func)
  }
}

@Entry
@Component
struct Index {
  @State message: string = "HELLO"
  private content: NodeContent = new NodeContent();

  build() {
    Row() {
      Column() {
        Button('addComponentContent')
          .onClick(() => {
            let column = typeNode.createNode(this.getUIContext(), "Column");
            column.initialize();
            column.addComponentContent(new ComponentContent<ParamsInterface>(this.getUIContext(),
              wrapBuilder<[ParamsInterface]>(buildText), {
                text: this.message, func: () => {
                  return "FUNCTION"
                }
              }, { nestingBuilderSupported: true }))
            this.content.addFrameNode(column);
          })
        ContentSlot(this.content)
      }
      .id("column")
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}

```

### update

update(args: T): void

Updates the parameters of the builder function encapsulated in the **WrappedBuilder** object. The parameter type must be the same as that passed in **constructor**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description                                                        |
| ------ | ---- | ---- | ------------------------------------------------------------ |
| args   | T    | Yes  | Parameters of the builder function encapsulated in the **WrappedBuilder** object. The parameter type must be the same as that passed in **constructor**.|

**Example**

```ts
import { ComponentContent } from "@kit.ArkUI";

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
                }, 2000);    // Automatically update the text in the dialog box after 2 seconds.
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

Passes the reuse event to the custom component in this **ComponentContent** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                                    |
| ------ | ------ | ---- | ------------------------------------------------------------------------ |
| param  | Object | No  | Parameters of the builder function encapsulated in the **WrappedBuilder** object. The parameter type must be the same as that passed in **constructor**.|

### recycle

recycle(): void

Passes the recycle event to the custom component in this **ComponentContent** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

```ts
import { ComponentContent } from '@kit.ArkUI';

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
            }, 2000); // Automatically update the text in the dialog box after 2 seconds.
          })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

### dispose

dispose(): void

Disposes of this **ComponentContent** object, which means to cancel the reference relationship between the **ComponentContent** object and its backend entity node.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ComponentContent } from '@kit.ArkUI';

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
                  promptAction.closeCustomDialog(contentNode)
                    .then(() => {
                      console.info('customdialog closed.')
                      if (contentNode !== null) {
                        contentNode.dispose();   // Dispose of the contentNode object.
                      }
                    }).catch((error: BusinessError) => {
                      let message = (error as BusinessError).message;
                      let code = (error as BusinessError).code;
                      console.error(`closeCustomDialog args error code is ${code}, message is ${message}`);
                    })
                }, 2000);     // Automatically close the dialog box after 2 seconds.
            })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```


### updateConfiguration

updateConfiguration(): void

Updates the configuration of the entire node by passing in a [system environment change](../apis-ability-kit/js-apis-app-ability-configuration.md) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

> **NOTE**
>
> The **updateConfiguration** API is used to instruct an object to update itself. The update is based on the current changes in the system environment.

**Example**
```ts
import { NodeController, FrameNode, ComponentContent, typeNode } from '@kit.ArkUI';
import { AbilityConstant, Configuration, EnvironmentCallback } from '@kit.AbilityKit';

@Builder
function buildText() {
  Column() {
    Text('hello')
      .width(50)
      .height(50)
      .fontColor($r(`app.color.text_color`))
  }.backgroundColor($r(`app.color.start_window_background`))
}

const componentContentMap: Array<ComponentContent<[Object]>> = new Array();

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    return this.rootNode;
  }

  createNode(context: UIContext) {
    this.rootNode = new FrameNode(context);
    let component = new ComponentContent<Object>(context, wrapBuilder(buildText));
    componentContentMap.push(component);
    this.rootNode.addComponentContent(component);
  }

  deleteNode() {
    let node = componentContentMap.pop();
    this.rootNode?.dispose();
    node?.dispose();
  }
}

function updateColorMode() {
  componentContentMap.forEach((value, index) => {
    value.updateConfiguration();
  })
}

@Entry
@Component
struct FrameNodeTypeTest {
  private myNodeController: MyNodeController = new MyNodeController();

  aboutToAppear(): void {
    let environmentCallback: EnvironmentCallback = {
      onMemoryLevel: (level: AbilityConstant.MemoryLevel): void => {
        console.log('onMemoryLevel');
      },
      onConfigurationUpdated: (config: Configuration): void => {
        console.log('onConfigurationUpdated ' + JSON.stringify(config));
        updateColorMode();
      }
    }
    // Register a callback.
    this.getUIContext().getHostContext()?.getApplicationContext().on('environment', environmentCallback);
    this.myNodeController.createNode(this.getUIContext());
  }

  aboutToDisappear(): void {
    // Remove the reference to the custom node from the map and release the node.
    this.myNodeController.deleteNode();
  }

  build() {
    Row() {
      NodeContainer(this.myNodeController);
    }
  }
}
```
