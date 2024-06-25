# ComponentContent

ComponentContent表示组件内容的实体封装，ComponentContent对象支持在非UI组件中创建与传递，便于开发者对弹窗类组件进行解耦封装。

> **说明：**
>
> 本模块从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 当前不支持在预览器中使用ComponentContent。


## 导入模块

```ts
import { ComponentContent } from "@ohos.arkui.node";
```

## ComponentContent

### constructor

constructor(uiContext: UIContext, builder: WrappedBuilder<[]>)

ComponentContent的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                               |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时候所需要的UI上下文。 |
| builder  | [WrappedBuilder<[]>](../../quick-start/arkts-wrapBuilder.md) | 是   |   封装不带参builder函数的WrappedBuilder对象。 |

### constructor

constructor(uiContext: UIContext, builder: WrappedBuilder<[T]>, args: T)

ComponentContent的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                               |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时候所需要的UI上下文。 |
| builder  | [WrappedBuilder<[T]>](../../quick-start/arkts-wrapBuilder.md) | 是   |   封装带参builder函数的WrappedBuilder对象。 |
| args     |     T     |   是   |   WrappedBuilder对象封装的builder函数的参数。 |

### update

update(args: T): void

用于更新WrappedBuilder对象封装的builder函数参数，与constructor传入的参数类型保持一致。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | ---- | ---- | ------------------------------------------------------------ |
| args   | T    | 是   | 用于更新WrappedBuilder对象封装的builder函数参数，与constructor传入的参数类型保持一致。 |

**示例：**

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
                }, 2000);    //2秒后自动更新弹窗内容文本
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

传递reuse事件到ComponentContent中的自定义组件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                     |
| ------ | ------ | ---- | ------------------------------------------------------------------------ |
| param  | Object | 否   | 用于复用WrappedBuilder对象封装的builder函数参数，与constructor传入的参数类型保持一致。 |

### recycle

recycle(): void

传递recycle事件到ComponentContent中的自定义组件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

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
            }, 2000); //2秒后自动更新弹窗内容文本
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

立即释放当前ComponentContent，即ComponentContent对象与后端实体节点解除引用关系。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
import { BusinessError } from '@ohos.base';
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
                  promptAction.closeCustomDialog(contentNode)
                    .then(() => {
                      console.info('customdialog closed.')
                      if (contentNode !== null) {
                        contentNode.dispose();   //释放contentNode
                      }
                    }).catch((error: BusinessError) => {
                      let message = (error as BusinessError).message;
                      let code = (error as BusinessError).code;
                      console.error(`closeCustomDialog args error code is ${code}, message is ${message}`);
                    })
                }, 2000);     //2秒后自动关闭
            })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```
