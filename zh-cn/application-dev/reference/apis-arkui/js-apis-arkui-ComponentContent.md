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

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                               |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | 是   | 创建对应节点时候所需要的UI上下文。 |
| builder  | [WrappedBuilder<[]>](../../quick-start/arkts-wrapBuilder.md) | 是   |   封装不带参builder函数的WrappedBuilder对象。 |

### constructor

constructor(uiContext: UIContext, builder: WrappedBuilder<[T]>, args: T)

ComponentContent的构造函数。

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

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                        |
| ------ | ------ | ---- | -----------------------------------------------------------|
| arg    |   T    | 是   | 用于更新WrappedBuilder对象封装的builder函数参数，与constructor传入的参数类型保持一致。 |

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

