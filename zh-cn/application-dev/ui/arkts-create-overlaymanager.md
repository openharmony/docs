# 设置浮层（OverlayManager）

**浮层（OverlayManager）** 用于将自定义的UI内容展示在页面（Page）之上，在Dialog、Popup、Menu、BindSheet、BindContentCover和Toast等组件之下，展示的范围为当前窗口安全区内。可适用于常驻悬浮等场景。

![image](figures/overlayManager.png)

可以通过使用[UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext)中的[getOverlayManager](../reference/apis-arkui/js-apis-arkui-UIContext.md#getoverlaymanager12)方法获取当前UI上下文关联的[OverlayManager](../reference/apis-arkui/js-apis-arkui-UIContext.md#overlaymanager12)对象，再通过该对象调用对应方法。

## 规格约束

* OverlayManager上节点的层级在Page页面层级之上，在Dialog、Popup、Menu、BindSheet、BindContentCover和Toast等组件之下。
* OverlayManager添加的节点显示和消失时没有默认动画。
* OverlayManager上节点安全区域内外的绘制方式与Page一致，键盘避让方式与Page一致。
* 与OverlayManager相关的属性推荐采用AppStorage来进行应用全局存储，以免切换页面后属性值发生变化从而导致业务错误。

## 设置浮层

在OverlayManager上[新增指定节点（addComponentContent）](../reference/apis-arkui/js-apis-arkui-UIContext.md#addcomponentcontent12)、[删除指定节点（removeComponentContent）](../reference/apis-arkui/js-apis-arkui-UIContext.md#removecomponentcontent12)、[显示所有节点（showAllComponentContents）](../reference/apis-arkui/js-apis-arkui-UIContext.md#showallcomponentcontents12)和[隐藏所有节点（hideAllComponentContents）](../reference/apis-arkui/js-apis-arkui-UIContext.md#hideallcomponentcontents12)。

```ts
import { ComponentContent, OverlayManager, router } from '@kit.ArkUI';

class Params {
  text: string = ""
  offset: Position
  constructor(text: string, offset: Position) {
    this.text = text
    this.offset = offset
  }
}
@Builder
function builderText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }.offset(params.offset)
}

@Entry
@Component
struct OverlayExample {
  @State message: string = 'ComponentContent';
  private uiContext: UIContext = this.getUIContext()
  private overlayNode: OverlayManager = this.uiContext.getOverlayManager()
  @StorageLink('contentArray') contentArray: ComponentContent<Params>[] = []
  @StorageLink('componentContentIndex') componentContentIndex: number = 0
  @StorageLink('arrayIndex') arrayIndex: number = 0
  @StorageLink("componentOffset") componentOffset: Position = {x: 0, y: 80}

  build() {
    Column() {
      Button("++componentContentIndex: " + this.componentContentIndex).onClick(()=>{
        ++this.componentContentIndex
      })
      Button("--componentContentIndex: " + this.componentContentIndex).onClick(()=>{
        --this.componentContentIndex
      })
      Button("增加ComponentContent" + this.contentArray.length).onClick(()=>{
        let componentContent = new ComponentContent(
          this.uiContext, wrapBuilder<[Params]>(builderText),
          new Params(this.message + (this.contentArray.length), this.componentOffset)
        )
        this.contentArray.push(componentContent)
        this.overlayNode.addComponentContent(componentContent, this.componentContentIndex)
      })
      Button("++arrayIndex: " + this.arrayIndex).onClick(()=>{
        ++this.arrayIndex
      })
      Button("--arrayIndex: " + this.arrayIndex).onClick(()=>{
        --this.arrayIndex
      })
      Button("删除ComponentContent" + this.arrayIndex).onClick(()=>{
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray.splice(this.arrayIndex, 1)
          this.overlayNode.removeComponentContent(componentContent.pop())
        } else {
          console.info("arrayIndex有误")
        }
      })
      Button("显示ComponentContent" + this.arrayIndex).onClick(()=>{
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray[this.arrayIndex]
          this.overlayNode.showComponentContent(componentContent)
        } else {
          console.info("arrayIndex有误")
        }
      })
      Button("隐藏ComponentContent" + this.arrayIndex).onClick(()=>{
        if (this.arrayIndex >= 0 && this.arrayIndex < this.contentArray.length) {
          let componentContent = this.contentArray[this.arrayIndex]
          this.overlayNode.hideComponentContent(componentContent)
        } else {
          console.info("arrayIndex有误")
        }
      })
      Button("显示所有ComponentContent").onClick(()=>{
          this.overlayNode.showAllComponentContents()
      })
      Button("隐藏所有ComponentContent").onClick(()=>{
        this.overlayNode.hideAllComponentContents()
      })

      Button("跳转页面").onClick(()=>{
        router.pushUrl({
          url: 'pages/Second'
        })
      })
    }
    .width('100%')
    .height('100%')
  }
}
```
显示一个始终在屏幕左侧的悬浮球，点击可以弹出alertDialog弹窗。

```ts
import { ComponentContent, OverlayManager } from '@kit.ArkUI';

class Params {
  context: UIContext
  offset: Position
  constructor(context: UIContext, offset: Position) {
    this.context = context
    this.offset = offset
  }
}
@Builder
function builderOverlay(params: Params) {
  Column() {
    Stack(){
    }.width(50).height(50).backgroundColor(Color.Yellow).position(params.offset).borderRadius(50)
    .onClick(() => {
      params.context.showAlertDialog(
        {
          title: 'title',
          message: 'text',
          autoCancel: true,
          alignment: DialogAlignment.Center,
          gridCount: 3,
          confirm: {
            value: 'button',
            action: () => {}
          },
          cancel: () => {}
        }
      )
    })
  }.focusable(false).width('100%').height('100%').hitTestBehavior(HitTestMode.Transparent)
}

@Entry
@Component
struct OverlayExample {
  @State message: string = 'ComponentContent';
  private uiContext: UIContext = this.getUIContext()
  private overlayNode: OverlayManager = this.uiContext.getOverlayManager()
  private overlayContent:ComponentContent<Params>[] = []
  controller: TextInputController = new TextInputController()

  aboutToAppear(): void {
    let uiContext = this.getUIContext();
    let componentContent = new ComponentContent(
      this.uiContext, wrapBuilder<[Params]>(builderOverlay),
      new Params(uiContext, {x:0, y: 100})
    )
    this.overlayNode.addComponentContent(componentContent, 0)
    this.overlayContent.push(componentContent)
  }

  aboutToDisappear(): void {
    let componentContent = this.overlayContent.pop()
    this.overlayNode.removeComponentContent(componentContent)
  }

  build() {
    Column() {

    }
    .width('100%')
    .height('100%')
  }
}

```


