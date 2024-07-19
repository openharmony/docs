# 共享元素转场 (一镜到底)

共享元素转场是一种界面切换时对相同或者相似的两个元素做的一种位置和大小匹配的过渡动画效果，也称一镜到底动效。

如下例所示，在点击图片后，该图片消失，同时在另一个位置出现新的图片，二者之间内容相同，可以对它们添加一镜到底动效。左图为不添加一镜到底动效的效果，右图为添加一镜到底动效的效果，一镜到底的效果能够让二者的出现消失产生联动，使得内容切换过程显得灵动自然而不生硬。

![zh-cn_image_0000001599644876](figures/zh-cn_image_0000001599644876.gif)|![zh-cn_image_0000001599644877](figures/zh-cn_image_0000001599644877.gif)
---|---

实现一镜到底动效的方式有多种，实际开发过程中，需要依据具体的场景，选择相应的合适的方式进行实现。推荐度由高至低排序，介绍一镜到底的基本实现方式。

## 不新建容器并直接变化原容器

该方法不新建容器，通过在已有容器上增删组件触发[transition](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md)，搭配组件[属性动画](./arkts-attribute-animation-apis.md)实现一镜到底效果。

对于同一个容器展开，容器内兄弟组件消失或者出现的场景，可通过对同一个容器展开前后进行宽高位置变化并配置属性动画，对兄弟组件配置出现消失转场动画实现一镜到底效果。基本步骤为：

1. 构建需要展开的页面，并通过状态变量构建好普通状态和展开状态的界面。

      ```ts
      class Tmp{
        set(item:CradData):CradData{
          return item
        }
      }
      // 通过状态变量的判断，在同一个组件内构建普通状态和展开状态的界面
      @Component
      export struct MyExtendView {
        // 声明与父组件进行交互的是否展开状态变量
        @Link isExpand: boolean;
        @State cardList: Array<CardData> = xxxx;
      
        build() {
          List() {
            // 根据需要定制展开后的组件
            if (this.isExpand) {
              Text('expand')
                .transition(TransitionEffect.translate({y:300}).animation({ curve: curves.springMotion(0.6, 0.8) }))
            }
      
            ForEach(this.cardList, (item: CradData) => {
              let Item:Tmp = new Tmp()
              let Imp:Tmp = Item.set(item)
              let Mc:Record<string,Tmp> = {'cardData':Imp}
              MyCard(Mc) // 封装的卡片组件，需自行实现
            })
          }
          .width(this.isExpand ? 200 : 500) // 根据需要定义展开后组件的属性
          .animation({ curve: curves.springMotion() }) // 为组件属性绑定动画
        }
      }
      ... 
      ```

2. 将需要展开的页面展开，通过状态变量控制兄弟组件消失或出现，并通过绑定出现消失转场实现兄弟组件转场效果。

      ```ts
      class Tmp{
        isExpand: boolean = false;
        set(){
          this.isExpand = !this.isExpand;
        }
      }
      let Exp:Record<string,boolean> = {'isExpand': false}
        @State isExpand: boolean = false
        
        ...
        List() {
          // 通过是否展开状态变量控制兄弟组件的出现或者消失，并配置出现消失转场动画
          if (!this.isExpand) {
            Text('收起')
              .transition(TransitionEffect.translate({y:300}).animation({ curve: curves.springMotion(0.6, 0.9) }))
          }
        
          MyExtendView(Exp)
            .onClick(() => {
              let Epd:Tmp = new Tmp()
              Epd.set()
            })
        
          // 通过是否展开状态变量控制兄弟组件的出现或者消失，并配置出现消失转场动画
          if (this.isExpand) {
            Text('展开')
              .transition(TransitionEffect.translate({y:300}).animation({ curve: curves.springMotion() }))
          }
        }
      ...
      ```

以点击卡片后显示卡片内容详情场景为例：

```ts
class PostData {
  avatar: Resource = $r('app.media.flower');
  name: string = '';
  message: string = '';
  images: Resource[] = [];
}

@Entry
@Component
struct Index {
  @State isExpand: boolean = false;
  @State @Watch('onItemClicked') selectedIndex: number = -1;

  private allPostData: PostData[] = [
    { avatar: $r('app.media.flower'), name: 'Alice', message: '天气晴朗',
      images: [$r('app.media.spring'), $r('app.media.tree')] },
    { avatar: $r('app.media.sky'), name: 'Bob', message: '你好世界',
      images: [$r('app.media.island')] },
    { avatar: $r('app.media.tree'), name: 'Carl', message: '万物生长',
      images: [$r('app.media.flower'), $r('app.media.sky'), $r('app.media.spring')] }];

  private onItemClicked(): void {
    if (this.selectedIndex < 0) {
      return;
    }
    animateTo({
      duration: 350,
      curve: Curve.Friction
    }, () => {
      this.isExpand = !this.isExpand;
    });
  }

  build() {
    Column({ space: 20 }) {
      ForEach(this.allPostData, (postData: PostData, index: number) => {
        // 当点击了某个post后，会使其余的post消失下树
        if (!this.isExpand || this.selectedIndex === index) {
          Column() {
            Post({ data: postData, selecteIndex: this.selectedIndex, index: index })
          }
          .width('100%')
          // 对出现消失的post添加透明度转场和位移转场效果
          .transition(TransitionEffect.OPACITY
            .combine(TransitionEffect.translate({ y: index < this.selectedIndex ? -250 : 250 }))
            .animation({ duration: 350, curve: Curve.Friction}))
        }
      }, (postData: PostData, index: number) => index.toString())
    }
    .size({ width: '100%', height: '100%' })
    .backgroundColor('#40808080')
  }
}

@Component
export default struct  Post {
  @Link selecteIndex: number;

  @Prop data: PostData;
  @Prop index: number;

  @State itemHeight: number = 250;
  @State isExpand: boolean = false;
  @State expandImageSize: number = 100;
  @State avatarSize: number = 50;

  build() {
    Column({ space: 20 }) {
      Row({ space: 10 }) {
        Image(this.data.avatar)
          .size({ width: this.avatarSize, height: this.avatarSize })
          .borderRadius(this.avatarSize / 2)
          .clip(true)

        Text(this.data.name)
      }
      .justifyContent(FlexAlign.Start)

      Text(this.data.message)

      Row({ space: 15 }) {
        ForEach(this.data.images, (imageResource: Resource, index: number) => {
          Image(imageResource)
            .size({ width: this.expandImageSize, height: this.expandImageSize })
        }, (imageResource: Resource, index: number) => index.toString())
      }

      if (this.isExpand) {
        Column() {
          Text('评论区')
            // 对评论区文本添加出现消失转场效果
            .transition( TransitionEffect.OPACITY
              .animation({ duration: 350, curve: Curve.Friction }))
            .padding({ top: 10 })
        }
        .transition(TransitionEffect.asymmetric(
          TransitionEffect.opacity(0.99)
            .animation({ duration: 350, curve: Curve.Friction }),
          TransitionEffect.OPACITY.animation({ duration: 0 })
        ))
        .size({ width: '100%'})
      }
    }
    .backgroundColor(Color.White)
    .size({ width: '100%', height: this.itemHeight })
    .alignItems(HorizontalAlign.Start)
    .padding({ left: 10, top: 10 })
    .onClick(() => {
      this.selecteIndex = -1;
      this.selecteIndex = this.index;
      animateTo({
        duration: 350,
        curve: Curve.Friction
      }, () => {
        // 对展开的post做宽高动画，并对头像尺寸和图片尺寸加动画
        this.isExpand = !this.isExpand;
        this.itemHeight = this.isExpand ? 780 : 250;
        this.avatarSize = this.isExpand ? 75: 50;
        this.expandImageSize = (this.isExpand && this.data.images.length > 0)
          ? (360 - (this.data.images.length + 1) * 15) / this.data.images.length : 100;
      })
    })
  }
}
```

![zh-cn_image_0000001600653160](figures/zh-cn_image_0000001600653160.gif)

## 新建容器并跨容器迁移组件

通过[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md)[自定义占位节点](arkts-user-defined-place-hoder.md)，利用[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md)实现组件的跨节点迁移，配合属性动画给组件的迁移过程赋予一镜到底效果。这种一镜到底的实现方式可以结合多种转场方式使用，如导航转场（[Navigation](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md)），半模态转场（[bindSheet](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)）等。

### 结合Stack使用

可以利用Stack内后定义组件在最上方的特性控制组件在跨节点迁移后位z序最高，以展开收起卡片的场景为例，实现步骤为：

- 展开卡片时，获取节点A的位置信息，将其中的组件迁移到与节点A位置一致的节点B处，节点B的层级高于节点A。

- 对节点B添加属性动画，使之展开并运动到展开后的位置，完成一镜到底的动画效果。

- 收起卡片时，对节点B添加属性动画，使之收起并运动到收起时的位置，即节点A的位置，实现一镜到底的动画效果。

- 在动画结束时利用回调将节点B中的组件迁移回节点A处。

```ts
// Index.ets
import { createPostNode, getPostNode, PostNode } from "../PostNode"
import { componentUtils } from '@kit.ArkUI';
import curves from '@ohos.curves';

class RectInfo {
  left: number = 0;
  top: number = 0;
  right: number = 0;
  bottom: number = 0;
  width: number = 0;
  height: number = 0;
}

@Entry
@Component
struct Index {
  @State nodeController: PostNode | undefined = undefined;
  @State listArray: Array<number> = [1, 2, 3, 4, 5, 6, 7, 8 ,9, 10];
  @State isExpandPageShow: boolean = false;
  @State curIndex: number = -1;
  @State changedHeight: boolean = false;
  @State translateX: number = 0;
  @State translateY: number = 0;
  @State positionX: number = 0;
  @State positionY: number = 0;
  @State calculatedTranslateX: number = 0;
  @State calculatedTranslateY: number = 0;
  // 设置迁移后组件相对父组件的位置
  @State expandTranslateX: number = 0;
  @State expandTranslateY: number = 0;
  // 控制组件是否响应点击事件
  @State isEnabled: boolean = true;

  // 获取需要跨节点迁移的组件的位置，及迁移前后节点的公共父节点的位置，用以计算做动画组件的动画参数
  calculateData(id: string): void {
    let clickedImageInfo = this.getRectInfoById(id);
    let rootStackInfo = this.getRectInfoById('rootStack');
    this.positionX = px2vp(clickedImageInfo.left - rootStackInfo.left);
    this.positionY = px2vp(clickedImageInfo.top - rootStackInfo.top);
    this.calculatedTranslateX = px2vp(rootStackInfo.left - clickedImageInfo.left) + this.expandTranslateX;
    this.calculatedTranslateY = px2vp(rootStackInfo.top - clickedImageInfo.top) + this.expandTranslateY;
  }

  // 根据组件的id获取组件的位置信息
  getRectInfoById(id: string): RectInfo {
    let componentInfo: componentUtils.ComponentInfo = componentUtils.getRectangleById(id);

    if (!componentInfo) {
      throw Error('object is empty');
    }

    let rstRect: RectInfo = new RectInfo();
    const widthScaleGap = componentInfo.size.width * (1 - componentInfo.scale.x) / 2;
    const heightScaleGap = componentInfo.size.height * (1 - componentInfo.scale.y) / 2;
    rstRect.left = componentInfo.translate.x + componentInfo.windowOffset.x + widthScaleGap;
    rstRect.top = componentInfo.translate.y + componentInfo.windowOffset.y + heightScaleGap;
    rstRect.right =
      componentInfo.translate.x + componentInfo.windowOffset.x + componentInfo.size.width - widthScaleGap;
    rstRect.bottom =
      componentInfo.translate.y + componentInfo.windowOffset.y + componentInfo.size.height - heightScaleGap;
    rstRect.width = rstRect.right - rstRect.left;
    rstRect.height = rstRect.bottom - rstRect.top;

    return {
      left: rstRect.left,
      right: rstRect.right,
      top: rstRect.top,
      bottom: rstRect.bottom,
      width: rstRect.width,
      height: rstRect.height
    }
  }

  transferNode(index: number): void {
    if (index != undefined) {
      this.curIndex = index;
    }
    this.calculateData(index.toString());
    this.nodeController = getPostNode(index.toString())
    if (this.nodeController != undefined) {
      // 组件迁移出该节点
      (this.nodeController as PostNode).onRemove();
      this.isExpandPageShow = true;
    }
  }

  onAnimationFinish(): void {
    if (this.nodeController != undefined) {
      // 组件回到迁移前的节点
      this.nodeController.callCallback();
    }
    // 组件迁移出该节点
    (this.nodeController as PostNode).onRemove();
    this.isExpandPageShow = false
    this.isEnabled = true
  }

  build() {
    Stack() {
      Column() {
        List() {
          ForEach(this.listArray, (item: number) => {
            ListItem() {
              Column() {
                Stack() {
                  Stack() {
                    // 卡片折叠态
                    PostItem({ index: item })
                  }
                  .transition(TransitionEffect.OPACITY)
                  .width('100%')
                  .height(100)
                  .id(item.toString())
                  .borderRadius(15)
                  .onClick( ()=> {
                    this.transferNode(item);
                    animateTo({ curve: curves.springMotion(0.6, 0.9)
                    }, () => {
                      this.translateX = this.calculatedTranslateX;
                      this.translateY = this.calculatedTranslateY;
                      this.changedHeight = true
                    })
                  })
                }.width('100%')
              }
              .height(120)
            }
          })
        }
        .clip(false)
        .height('100%')
        .alignListItem(ListItemAlign.Center)
        .enabled(this.isEnabled)
      }
      .width('100%')
      .height('100%')
      .justifyContent(FlexAlign.Start)
      if (this.isExpandPageShow) {
        Stack() {
          // 卡片展开态
          ExpandPage({ index: this.curIndex })
        }
        .width('100%')
        .height(this.changedHeight ? 1000 : 100)
        .translate({ x: this.translateX, y: this.translateY })
        .position({ x: this.positionX, y: this.positionY })
        .transition(TransitionEffect.OPACITY)
        .borderRadius(15)
        .enabled(this.isEnabled)
        .onClick(() => {
          animateTo({ curve: curves.springMotion(0.6, 0.9),
            onFinish: () => {
              this.onAnimationFinish();
            }
          }, () => {
            this.isEnabled = false
            this.translateX = 0;
            this.translateY = 0;
            this.changedHeight = false
            this.nodeController = getPostNode(this.curIndex.toString())
            // 卡片展开态内容消失
            this.nodeController?.update(this.curIndex.toString(), false)
          })
        })
      }
    }
    .id('rootStack')
  }
}

@Component
struct PostItem {
  @Prop index: number
  @State nodeController: PostNode | undefined = undefined;

  aboutToAppear(): void {
    let node = createPostNode(this.getUIContext(), this.index.toString(), false)
    this.nodeController = node
    if (node != undefined) {
      node.setCallback(this.resetNode.bind(this));
    }
  }
  resetNode() {
    this.nodeController = getPostNode(this.index.toString())
  }

  build() {
    NodeContainer(this.nodeController)
  }
}

@Component
struct ExpandPage {
  @Prop index: number
  @State nodeController: PostNode | undefined = undefined;

  aboutToAppear(): void {
    this.nodeController = getPostNode(this.index.toString())
    // 卡片展开态内容出现
    this.nodeController?.update(this.index.toString(), true)
  }

  build() {
    NodeContainer(this.nodeController)
  }
}
```

```ts
// PostNode.ets
// 跨容器迁移能力
import { UIContext } from '@ohos.arkui.UIContext';
import { NodeController, BuilderNode, FrameNode } from '@ohos.arkui.node';
import curves from '@ohos.curves';

class Data {
  item: string | null = null
  isExpand: Boolean | false = false
}

@Builder
function PostBuilder(data: Data) {
  // 跨容器迁移组件置于@Builder内
  Column() {
    Row() {
      Row()
        .backgroundColor(Color.Pink)
        .borderRadius(20)
        .width(80)
        .height(80)

      Column() {
        Text('点击展开 Item ' + data.item)
          .fontSize(20)
        Text('共享元素转场')
          .fontSize(12)
          .fontColor(0x909399)
      }
      .alignItems(HorizontalAlign.Start)
      .justifyContent(FlexAlign.SpaceAround)
      .margin({ left: 10 })
      .height(80)
    }
    .width('90%')
    .height(100)
    if (data.isExpand) {
      Row() {
        Text('展开态')
          .fontSize(28)
          .fontColor(0x909399)
          .textAlign(TextAlign.Center)
          .transition(TransitionEffect.OPACITY.animation({ curve: curves.springMotion(0.6, 0.9) }))
      }
      .width('90%')
      .justifyContent(FlexAlign.Center)
    }
  }
  .width('90%')
  .height('100%')
  .alignItems(HorizontalAlign.Center)
  .borderRadius(10)
  .margin({ top: 15 })
  .backgroundColor(Color.White)
  .shadow({ radius: 20, color: 0x909399, offsetX: 20, offsetY: 10 })
}

class __InternalValue__{
  flag:boolean =false;
};

export class PostNode extends NodeController {
  private node: BuilderNode<Data[]> | null = null;
  private isRemove: __InternalValue__ = new __InternalValue__();
  private callback: Function | undefined = undefined
  private data: Data | null = null

  makeNode(uiContext: UIContext): FrameNode | null {
    if(this.isRemove.flag == true){
      return null;
    }
    if (this.node != null) {
      return this.node.getFrameNode();
    }

    return null;
  }

  init(uiContext: UIContext, id: string, isExpand: boolean) {
    if (this.node != null) {
      return;
    }
    // 创建节点，需要uiContext
    this.node = new BuilderNode(uiContext)
    // 创建离线组件
    this.data = { item: id, isExpand: isExpand }
    this.node.build(wrapBuilder<Data[]>(PostBuilder), this.data)
  }

  update(id: string, isExpand: boolean) {
    if (this.node !== null) {
      // 调用update进行更新。
      this.data = { item: id, isExpand: isExpand }
      this.node.update(this.data);
    }
  }

  setCallback(callback: Function | undefined) {
    this.callback = callback
  }

  callCallback() {
    if (this.callback != undefined) {
      this.callback();
    }
  }

  onRemove(){
    this.isRemove.flag = true;
    // 组件迁移出节点时触发重建
    this.rebuild();
    this.isRemove.flag = false;
  }
}

let gNodeMap: Map<string, PostNode | undefined> = new Map();

export const createPostNode =
  (uiContext: UIContext, id: string, isExpand: boolean): PostNode | undefined => {
    let node = new PostNode();
    node.init(uiContext, id, isExpand);
    gNodeMap.set(id, node);
    return node;
  }

export const getPostNode = (id: string): PostNode | undefined => {
  if (!gNodeMap.has(id)) {
    return undefined
  }
  return gNodeMap.get(id);
}

export const deleteNode = (id: string) => {
  gNodeMap.delete(id)
}
```

![zh_cn_image_sharedElementsNodeTransfer](figures/zh-cn_image_sharedElementsNodeTransfer.gif)

### 结合Navigation使用

可以利用[Navigation](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md)的自定义导航转场动画能力（[customNavContentTransition](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#customnavcontenttransition11)，可参考[Navigation示例3](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#示例3)）实现一镜到底动效。共享元素转场期间，组件由消失页面迁移至出现页面。

以展开收起缩略图的场景为例，实现步骤为：

- 通过customNavContentTransition配置PageOne与PageTwo的自定义导航转场动画。

- 自定义的共享元素转场效果由属性动画实现，具体实现方式为抓取页面内组件相对窗口的位置信息从而正确匹配组件在PageOne与PageTwo的位置、缩放等，即动画开始和结束的属性信息。

- 点击缩略图后共享元素组件从PageOne被迁移至PageTwo，随后触发由PageOne至PageTwo的自定义转场动画，即PageTwo的共享元素组件从原来的缩略图状态做动画到全屏状态。

- 由全屏状态返回到缩略图时，触发由PageTwo至PageOne的自定义转场动画，即PageTwo的共享元素组件从全屏状态做动画到原PageOne的缩略图状态，转场结束后共享元素组件从PageTwo被迁移回PageOne。

```
├──entry/src/main/ets                 // 代码区
│  ├──CustomTransition
│  │  ├──AnimationProperties.ets      // 一镜到底转场动画封装
│  │  └──CustomNavigationUtils.ets    // Navigation自定义转场动画配置
│  ├──entryability
│  │  └──EntryAbility.ets             // 程序入口类
│  ├──NodeContainer
│  │  └──CustomComponent.ets          // 自定义占位节点
│  ├──pages
│  │  ├──Index.ets                    // 导航页面
│  │  ├──PageOne.ets                  // 缩略图页面
│  │  └──PageTwo.ets                  // 全屏展开页面
│  └──utils
│     ├──ComponentAttrUtils.ets       // 组件位置获取
│     └──WindowUtils.ets              // 窗口信息
└──entry/src/main/resources           // 资源文件
```

```ts
// Index.ets
import { AnimateCallback, CustomTransition } from '../CustomTransition/CustomNavigationUtils';

const TAG: string = 'Index';

@Entry
@Component
struct Index {
  private pageInfos: NavPathStack = new NavPathStack();
  // 允许进行自定义转场的页面名称
  private allowedCustomTransitionFromPageName: string[] = ['PageOne'];
  private allowedCustomTransitionToPageName: string[] = ['PageTwo'];

  aboutToAppear(): void {
    this.pageInfos.pushPath({ name: 'PageOne' });
  }

  private isCustomTransitionEnabled(fromName: string, toName: string): boolean {
    // 点击和返回均需要进行自定义转场，因此需要分别判断
    if ((this.allowedCustomTransitionFromPageName.includes(fromName)
      && this.allowedCustomTransitionToPageName.includes(toName))
      || (this.allowedCustomTransitionFromPageName.includes(toName)
        && this.allowedCustomTransitionToPageName.includes(fromName))) {
      return true;
    }
    return false;
  }

  build() {
    Navigation(this.pageInfos)
      .hideNavBar(true)
      .customNavContentTransition((from: NavContentInfo, to: NavContentInfo, operation: NavigationOperation) => {
        if ((!from || !to) || (!from.name || !to.name)) {
          return undefined;
        }

        // 通过from和to的name对自定义转场路由进行管控
        if (!this.isCustomTransitionEnabled(from.name, to.name)) {
          return undefined;
        }

        // 需要对转场页面是否注册了animation进行判断，来决定是否进行自定义转场
        let fromParam: AnimateCallback = CustomTransition.getInstance().getAnimateParam(from.index);
        let toParam: AnimateCallback = CustomTransition.getInstance().getAnimateParam(to.index);
        if (!fromParam.animation || !toParam.animation) {
          return undefined;
        }

        // 一切判断完成后，构造customAnimation给系统侧调用，执行自定义转场动画
        let customAnimation: NavigationAnimatedTransition = {
          onTransitionEnd: (isSuccess: boolean) => {
            console.log(TAG, `current transition result is ${isSuccess}`);
          },
          timeout: 2000,
          transition: (transitionProxy: NavigationTransitionProxy) => {
            console.log(TAG, 'trigger transition callback');
            if (fromParam.animation) {
              fromParam.animation(operation == NavigationOperation.PUSH, true, transitionProxy);
            }
            if (toParam.animation) {
              toParam.animation(operation == NavigationOperation.PUSH, false, transitionProxy);
            }
          }
        };
        return customAnimation;
      })
  }
}
```

```ts
// PageOne.ets
import { CustomTransition } from '../CustomTransition/CustomNavigationUtils';
import { MyNodeController, createMyNode, getMyNode } from '../NodeContainer/CustomComponent';
import { ComponentAttrUtils, RectInfoInPx } from '../utils/ComponentAttrUtils';
import { WindowUtils } from '../utils/WindowUtils';

@Builder
export function PageOneBuilder() {
  PageOne();
}

@Component
export struct PageOne {
  private pageInfos: NavPathStack = new NavPathStack();
  private pageId: number = -1;
  @State myNodeController: MyNodeController | undefined = new MyNodeController(false);

  aboutToAppear(): void {
    let node = getMyNode();
    if (node == undefined) {
      // 新建自定义节点
      createMyNode(this.getUIContext());
    }
    this.myNodeController = getMyNode();
  }

  private doFinishTransition(): void {
    // PageTwo结束转场时将节点从PageTwo迁移回PageOne
    this.myNodeController = getMyNode();
  }

  private registerCustomTransition(): void {
    // 注册自定义动画协议
    CustomTransition.getInstance().registerNavParam(this.pageId,
      (isPush: boolean, isExit: boolean, transitionProxy: NavigationTransitionProxy) => {}, 500);
  }

  private onCardClicked(): void {
    let cardItemInfo: RectInfoInPx =
      ComponentAttrUtils.getRectInfoById(WindowUtils.window.getUIContext(), 'card');
    let param: Record<string, Object> = {};
    param['cardItemInfo'] = cardItemInfo;
    param['doDefaultTransition'] = (myController: MyNodeController) => {
      this.doFinishTransition()
    };
    this.pageInfos.pushPath({ name: 'PageTwo', param: param });
    // 自定义节点从PageOne下树
    if (this.myNodeController != undefined) {
      (this.myNodeController as MyNodeController).onRemove();
    }
  }

  build() {
    NavDestination() {
      Stack() {
        Column({ space: 20 }) {
          Row({ space: 10 }) {
            Image($r("app.media.avatar"))
              .size({ width: 50, height: 50 })
              .borderRadius(25)
              .clip(true)

            Text('Alice')
          }
          .justifyContent(FlexAlign.Start)

          Text('你好世界')

          NodeContainer(this.myNodeController)
            .size({ width: 320, height: 250 })
            .onClick(() => {
              this.onCardClicked()
            })
        }
        .alignItems(HorizontalAlign.Start)
        .margin(30)
      }
    }
    .title('卡片一镜到底首页')
    .onReady((context: NavDestinationContext) => {
      this.pageInfos = context.pathStack;
      this.pageId = this.pageInfos.getAllPathName().length - 1;
      this.registerCustomTransition();
    })
    .onDisAppear(() => {
      CustomTransition.getInstance().unRegisterNavParam(this.pageId);
      // 自定义节点从PageOne下树
      if (this.myNodeController != undefined) {
        (this.myNodeController as MyNodeController).onRemove();
      }
    })
  }
}
```

```ts
// PageTwo.ets
import { CustomTransition } from '../CustomTransition/CustomNavigationUtils';
import { AnimationProperties } from '../CustomTransition/AnimationProperties';
import { RectInfoInPx } from '../utils/ComponentAttrUtils';
import { getMyNode, MyNodeController } from '../NodeContainer/CustomComponent';

@Builder
export function PageTwoBuilder() {
  PageTwo();
}

@Component
export struct PageTwo {
  @State pageInfos: NavPathStack = new NavPathStack();
  @State AnimationProperties: AnimationProperties = new AnimationProperties();
  @State myNodeController: MyNodeController | undefined = new MyNodeController(false);

  private pageId: number = -1;

  private shouldDoDefaultTransition: boolean = false;
  private prePageDoFinishTransition: () => void = () => {};
  private cardItemInfo: RectInfoInPx = new RectInfoInPx();

  @StorageProp('windowSizeChanged') @Watch('unRegisterNavParam') windowSizeChangedTime: number = 0;
  @StorageProp('onConfigurationUpdate') @Watch('unRegisterNavParam') onConfigurationUpdateTime: number = 0;

  aboutToAppear(): void {
    // 迁移自定义节点至当前页面
    this.myNodeController = getMyNode();
  }

  private unRegisterNavParam(): void {
    this.shouldDoDefaultTransition = true;
  }

  private onBackPressed(): boolean {
    if (this.shouldDoDefaultTransition) {
      CustomTransition.getInstance().unRegisterNavParam(this.pageId);
      this.pageInfos.pop();
      this.prePageDoFinishTransition();
      this.shouldDoDefaultTransition = false;
      return true;
    }
    this.pageInfos.pop();
    return true;
  }

  build() {
    NavDestination() {
      // Stack需要设置alignContent为TopStart，否则在高度变化过程中，截图和内容都会随高度重新布局位置
      Stack({ alignContent: Alignment.TopStart }) {
        Stack({ alignContent: Alignment.TopStart }) {
          NodeContainer(this.myNodeController)
        }
        .position({ y: this.AnimationProperties.positionValue })
      }
      .scale({ x: this.AnimationProperties.scaleValue, y: this.AnimationProperties.scaleValue })
      .translate({ x: this.AnimationProperties.translateX, y: this.AnimationProperties.translateY })
      .width(this.AnimationProperties.clipWidth)
      .height(this.AnimationProperties.clipHeight)
      .borderRadius(this.AnimationProperties.radius)
      // expandSafeArea使得Stack做沉浸式效果，向上扩到状态栏，向下扩到导航条
      .expandSafeArea([SafeAreaType.SYSTEM])
      .backgroundColor(Color.Black)
      // 对高度进行裁切
      .clip(true)
    }
    .backgroundColor(this.AnimationProperties.navDestinationBgColor)
    .hideTitleBar(true)
    .onReady((context: NavDestinationContext) => {
      this.pageInfos = context.pathStack;
      this.pageId = this.pageInfos.getAllPathName().length - 1;
      let param = context.pathInfo?.param as Record<string, Object>;
      this.prePageDoFinishTransition = param['doDefaultTransition'] as () => void;
      this.cardItemInfo = param['cardItemInfo'] as RectInfoInPx;
      CustomTransition.getInstance().registerNavParam(this.pageId,
        (isPush: boolean, isExit: boolean, transitionProxy: NavigationTransitionProxy) => {
          this.AnimationProperties.doAnimation(
            this.cardItemInfo, isPush, isExit, transitionProxy, 0,
            this.prePageDoFinishTransition, this.myNodeController);
        }, 500);
    })
    .onBackPressed(() => {
      return this.onBackPressed();
    })
    .onDisAppear(() => {
      CustomTransition.getInstance().unRegisterNavParam(this.pageId);
    })
  }
}
```

```ts
// CustomNavigationUtils.ets
// 配置Navigation自定义转场动画
export interface AnimateCallback {
  animation: ((isPush: boolean, isExit: boolean, transitionProxy: NavigationTransitionProxy) => void | undefined)
    | undefined;
  timeout: (number | undefined) | undefined;
}

const customTransitionMap: Map<number, AnimateCallback> = new Map();

export class CustomTransition {
  private constructor() {};

  static delegate = new CustomTransition();

  static getInstance() {
    return CustomTransition.delegate;
  }

  // 注册页面的动画回调，name是注册页面的动画的回调
  // animationCallback是需要执行的动画内容，timeout是转场结束的超时时间
  registerNavParam(
    name: number,
    animationCallback: (operation: boolean, isExit: boolean, transitionProxy: NavigationTransitionProxy) => void,
    timeout: number): void {
    if (customTransitionMap.has(name)) {
      let param = customTransitionMap.get(name);
      if (param != undefined) {
        param.animation = animationCallback;
        param.timeout = timeout;
        return;
      }
    }
    let params: AnimateCallback = { timeout: timeout, animation: animationCallback };
    customTransitionMap.set(name, params);
  }

  unRegisterNavParam(name: number): void {
    customTransitionMap.delete(name);
  }

  getAnimateParam(name: number): AnimateCallback {
    let result: AnimateCallback = {
      animation: customTransitionMap.get(name)?.animation,
      timeout: customTransitionMap.get(name)?.timeout,
    };
    return result;
  }
}
```

```ts
// 工程配置文件module.json5中配置 {"routerMap": "$profile:route_map"}
// route_map.json
{
  "routerMap": [
    {
      "name": "PageOne",
      "pageSourceFile": "src/main/ets/pages/PageOne.ets",
      "buildFunction": "PageOneBuilder"
    },
    {
      "name": "PageTwo",
      "pageSourceFile": "src/main/ets/pages/PageTwo.ets",
      "buildFunction": "PageTwoBuilder"
    }
  ]
}
```

```ts
// AnimationProperties.ets
// 一镜到底转场动画封装
import { curves } from '@kit.ArkUI';
import { RectInfoInPx } from '../utils/ComponentAttrUtils';
import { WindowUtils } from '../utils/WindowUtils';
import { MyNodeController } from '../NodeContainer/CustomComponent';

const TAG: string = 'AnimationProperties';

const DEVICE_BORDER_RADIUS: number = 34;

// 将自定义一镜到底转场动画进行封装，其他界面也需要做自定义一镜到底转场的话，可以直接复用，减少工作量
@Observed
export class AnimationProperties {
  public navDestinationBgColor: ResourceColor = Color.Transparent;
  public snapShotOpacity: number = 1;
  public postPageOpacity: number = 0;
  public translateX: number = 0;
  public translateY: number = 0;
  public scaleValue: number = 1;
  public clipWidth: Dimension = 0;
  public clipHeight: Dimension = 0;
  public radius: number = 0;
  public positionValue: number = 0;
  private animationCount: number = 0;

  public doAnimation(cardItemInfo_px: RectInfoInPx, isPush: boolean, isExit: boolean,
    transitionProxy: NavigationTransitionProxy, extraTranslateValue: number,
    prePageOnFinish: (index: MyNodeController) => void, myNodeController: MyNodeController|undefined): void {
    // 首先计算卡片的宽高与窗口宽高的比例
    let widthScaleRatio = cardItemInfo_px.width / WindowUtils.windowWidth_px;
    let heightScaleRatio = cardItemInfo_px.height / WindowUtils.windowHeight_px;
    let isUseWidthScale = widthScaleRatio > heightScaleRatio;
    let initScale: number = isUseWidthScale ? widthScaleRatio : heightScaleRatio;

    let initTranslateX: number = 0;
    let initClipWidth: Dimension = 0;
    let initClipHeight: Dimension = 0;
    let initTranslateY: number = 0;
    let initPositionValue: number = -px2vp(WindowUtils.topAvoidAreaHeight_px + extraTranslateValue);;

    if (isUseWidthScale) {
      initTranslateX = px2vp(cardItemInfo_px.left - (WindowUtils.windowWidth_px - cardItemInfo_px.width) / 2);
      initClipWidth = '100%';
      initClipHeight = px2vp((cardItemInfo_px.height) / initScale);
      initTranslateY = px2vp(cardItemInfo_px.top - ((vp2px(initClipHeight) - vp2px(initClipHeight) * initScale) / 2));
    } else {
      initTranslateY = px2vp(cardItemInfo_px.top - (WindowUtils.windowHeight_px - cardItemInfo_px.height) / 2);
      initClipHeight = '100%';
      initClipWidth = px2vp((cardItemInfo_px.width) / initScale);
      initTranslateX = px2vp(cardItemInfo_px.left - (WindowUtils.windowWidth_px / 2 - cardItemInfo_px.width / 2));
    }

    // 这里转场动画开始前通过计算scale、translate、position和clip height & width，确定节点迁移前后位置一致
    console.log(TAG, 'initScale ' + initScale + ' initTranslateX ' + initTranslateX +
                     ' initTranslateY ' + initTranslateY + ' initClipWidth ' + initClipWidth +
                     ' initClipHeight ' + initClipHeight + ' initPositionValue ' + initPositionValue);

    // 转场至新页面
    if (isPush && !isExit) {
      this.scaleValue = initScale;
      this.translateX = initTranslateX;
      this.clipWidth = initClipWidth;
      this.clipHeight = initClipHeight;
      this.translateY = initTranslateY;
      this.positionValue = initPositionValue;

      let animationCount = ++this.animationCount;

      animateTo({
        curve: curves.interpolatingSpring(0, 1, 328, 36),
        onFinish: () => {
          if (transitionProxy) {
            transitionProxy.finishTransition();
          }
          if (animationCount === this.animationCount) {
            this.radius = 0;
          }
        }
      }, () => {
        this.scaleValue = 1.0;
        this.translateX = 0;
        this.translateY = 0;
        this.clipWidth = '100%';
        this.clipHeight = '100%';
        this.positionValue = 0;
        this.radius = DEVICE_BORDER_RADIUS;
      })

      animateTo({
        duration: 100,
        curve: Curve.Sharp,
      }, () => {
        this.snapShotOpacity = 0;
        this.navDestinationBgColor = '#33000000';
      })

      animateTo({
        duration: 100,
        curve: Curve.Sharp,
      }, () => {
        this.postPageOpacity = 1.0;
      })

      // 返回旧页面
    } else if (!isPush && isExit) {
      ++this.animationCount;

      animateTo({
        duration: 350,
        curve: Curve.EaseInOut,
        onFinish: () => {
          if (transitionProxy) {
            transitionProxy.finishTransition();
          }
          prePageOnFinish(myNodeController);
          // 自定义节点从PageTwo下树
          if (myNodeController != undefined) {
            (myNodeController as MyNodeController).onRemove();
          }
        }
      }, () => {
        this.scaleValue = initScale;
        this.translateX = initTranslateX;
        this.clipWidth = initClipWidth;
        this.clipHeight = initClipHeight;
        this.translateY = initTranslateY;
        this.radius = 0;
        this.positionValue = initPositionValue;
      })

      animateTo({
        duration: 200,
        delay: 150,
        curve: Curve.Friction,
      }, () => {
        this.navDestinationBgColor = '#00ffffff';
      })

      animateTo({
        duration: 100,
        delay: 150,
        curve: Curve.Friction,
      }, () => {
        this.snapShotOpacity = 1;
      })

      animateTo({
        duration: 100,
        delay: 150,
        curve: Curve.Friction,
      }, () => {
        this.postPageOpacity = 0;
      })
    }
  }
}
```

```ts
// ComponentAttrUtils.ets
// 获取组件相对窗口的位置
import { componentUtils, UIContext } from '@kit.ArkUI';
import { JSON } from '@kit.ArkTS';

export class ComponentAttrUtils {
  // 根据组件的id获取组件的位置信息
  public static getRectInfoById(context: UIContext, id: string): RectInfoInPx {
    if (!context || !id) {
      throw Error('object is empty');
    }
    let componentInfo: componentUtils.ComponentInfo = context.getComponentUtils().getRectangleById(id);

    if (!componentInfo) {
      throw Error('object is empty');
    }

    let rstRect: RectInfoInPx = new RectInfoInPx();
    const widthScaleGap = componentInfo.size.width * (1 - componentInfo.scale.x) / 2;
    const heightScaleGap = componentInfo.size.height * (1 - componentInfo.scale.y) / 2;
    rstRect.left = componentInfo.translate.x + componentInfo.screenOffset.x + widthScaleGap;
    rstRect.top = componentInfo.translate.y + componentInfo.screenOffset.y + heightScaleGap;
    rstRect.right =
      componentInfo.translate.x + componentInfo.screenOffset.x + componentInfo.size.width - widthScaleGap;
    rstRect.bottom =
      componentInfo.translate.y + componentInfo.screenOffset.y + componentInfo.size.height - heightScaleGap;
    rstRect.width = rstRect.right - rstRect.left;
    rstRect.height = rstRect.bottom - rstRect.top;
    return {
      left: rstRect.left,
      right: rstRect.right,
      top: rstRect.top,
      bottom: rstRect.bottom,
      width: rstRect.width,
      height: rstRect.height
    }
  }
}

export class RectInfoInPx {
  left: number = 0;
  top: number = 0;
  right: number = 0;
  bottom: number = 0;
  width: number = 0;
  height: number = 0;
}

export class RectJson {
  $rect: Array<number> = [];
}
```

```ts
// WindowUtils.ets
// 窗口信息
import { window } from '@kit.ArkUI';

export class WindowUtils {
  public static window: window.Window;
  public static windowWidth_px: number;
  public static windowHeight_px: number;
  public static topAvoidAreaHeight_px: number;
  public static navigationIndicatorHeight_px: number;
}
```

```ts
// EntryAbility.ets
// 程序入口处的onWindowStageCreate增加对窗口宽高等的抓取

import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { display, window } from '@kit.ArkUI';
import { WindowUtils } from '../utils/WindowUtils';

const TAG: string = 'EntryAbility';

export default class EntryAbility extends UIAbility {
  private currentBreakPoint: string = '';

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    // 获取窗口宽高
    WindowUtils.window = windowStage.getMainWindowSync();
    WindowUtils.windowWidth_px = WindowUtils.window.getWindowProperties().windowRect.width;
    WindowUtils.windowHeight_px = WindowUtils.window.getWindowProperties().windowRect.height;

    this.updateBreakpoint(WindowUtils.windowWidth_px);

    // 获取上方避让区(状态栏等)高度
    let avoidArea = WindowUtils.window.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);
    WindowUtils.topAvoidAreaHeight_px = avoidArea.topRect.height;

    // 获取导航条高度
    let navigationArea = WindowUtils.window.getWindowAvoidArea(window.AvoidAreaType.TYPE_NAVIGATION_INDICATOR);
    WindowUtils.navigationIndicatorHeight_px = navigationArea.bottomRect.height;

    console.log(TAG, 'the width is ' + WindowUtils.windowWidth_px + '  ' + WindowUtils.windowHeight_px + '  ' +
    WindowUtils.topAvoidAreaHeight_px + '  ' + WindowUtils.navigationIndicatorHeight_px);

    // 监听窗口尺寸、状态栏高度及导航条高度的变化并更新
    try {
      WindowUtils.window.on('windowSizeChange', (data) => {
        console.log(TAG, 'on windowSizeChange, the width is ' + data.width + ', the height is ' + data.height);
        WindowUtils.windowWidth_px = data.width;
        WindowUtils.windowHeight_px = data.height;
        this.updateBreakpoint(data.width);
        AppStorage.setOrCreate('windowSizeChanged', Date.now())
      })

      WindowUtils.window.on('avoidAreaChange', (data) => {
        if (data.type == window.AvoidAreaType.TYPE_SYSTEM) {
          let topRectHeight = data.area.topRect.height;
          console.log(TAG, 'on avoidAreaChange, the top avoid area height is ' + topRectHeight);
          WindowUtils.topAvoidAreaHeight_px = topRectHeight;
        } else if (data.type == window.AvoidAreaType.TYPE_NAVIGATION_INDICATOR) {
          let bottomRectHeight = data.area.bottomRect.height;
          console.log(TAG, 'on avoidAreaChange, the navigation indicator height is ' + bottomRectHeight);
          WindowUtils.navigationIndicatorHeight_px = bottomRectHeight;
        }
      })
    } catch (exception) {
      console.log('register failed ' + JSON.stringify(exception));
    }

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content.');
    });
  }

  updateBreakpoint(width: number) {
    let windowWidthVp = width / (display.getDefaultDisplaySync().densityDPI / 160);
    let newBreakPoint: string = '';
    if (windowWidthVp < 400) {
      newBreakPoint = 'xs';
    } else if (windowWidthVp < 600) {
      newBreakPoint = 'sm';
    } else if (windowWidthVp < 800) {
      newBreakPoint = 'md';
    } else {
      newBreakPoint = 'lg';
    }
    if (this.currentBreakPoint !== newBreakPoint) {
      this.currentBreakPoint = newBreakPoint;
      // 使用状态变量记录当前断点值
      AppStorage.setOrCreate('currentBreakpoint', this.currentBreakPoint);
    }
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```

```ts
// CustomComponent.ets
// 自定义占位节点，跨容器迁移能力
import { BuilderNode, FrameNode, NodeController } from '@kit.ArkUI';

@Builder
function CardBuilder() {
  Column() {
    Stack() {
      Image($r("app.media.card"))
    }
    .id('card')
  }
}

export class MyNodeController extends NodeController {
  private CardNode: BuilderNode<[]> | null = null;
  private wrapBuilder: WrappedBuilder<[]> = wrapBuilder(CardBuilder);
  private needCreate: boolean = false;
  private isRemove: boolean = false;

  constructor(create: boolean) {
    super();
    this.needCreate = create;
  }

  makeNode(uiContext: UIContext): FrameNode | null {
    if(this.isRemove == true){
      return null;
    }
    if (this.needCreate && this.CardNode == null) {
      this.CardNode = new BuilderNode(uiContext);
      this.CardNode.build(this.wrapBuilder)
    }
    if (this.CardNode == null) {
      return null;
    }
    return this.CardNode!.getFrameNode()!;
  }

  getNode(): BuilderNode<[]> | null {
    return this.CardNode;
  }

  setNode(node: BuilderNode<[]> | null) {
    this.CardNode = node;
    this.rebuild();
  }

  onRemove() {
    this.isRemove = true;
    this.rebuild();
    this.isRemove = false;
  }

  init(uiContext: UIContext) {
    this.CardNode = new BuilderNode(uiContext);
    this.CardNode.build(this.wrapBuilder)
  }
}

let myNode: MyNodeController | undefined;

export const createMyNode =
  (uiContext: UIContext) => {
    myNode = new MyNodeController(false);
    myNode.init(uiContext);
  }

export const getMyNode = (): MyNodeController | undefined => {
  return myNode;
}
```

![zh-cn_image_NavigationNodeTransfer](figures/zh-cn_image_NavigationNodeTransfer.gif)

## 使用geometryTransition共享元素转场

[geometryTransition](../reference/apis-arkui/arkui-ts/ts-transition-animation-geometrytransition.md)用于组件内隐式共享元素转场，在视图状态切换过程中提供丝滑的上下文继承过渡体验。

geometryTransition的使用方式为对需要添加一镜到底动效的两个组件使用geometryTransition接口绑定同一id，这样在其中一个组件消失同时另一个组件创建出现的时候，系统会对二者添加一镜到底动效。

geometryTransition绑定两个对象的实现方式使得geometryTransition区别于其他方法，最适合用于两个不同对象之间完成一镜到底。

### geometryTransition的简单使用

对于同一个页面中的两个元素的一镜到底效果，geometryTransition接口的简单使用示例如下：

```ts
import curves from '@ohos.curves';

@Entry
@Component
struct IfElseGeometryTransition {
  @State isShow: boolean = false;

  build() {
    Stack({ alignContent: Alignment.Center }) {
      if (this.isShow) {
        Image($r('app.media.spring'))
          .autoResize(false)
          .clip(true)
          .width(200)
          .height(200)
          .borderRadius(100)
          .geometryTransition("picture")
          .transition(TransitionEffect.OPACITY)
          // 在打断场景下，即动画过程中点击页面触发下一次转场，如果不加id，则会出现重影
          // 加了id之后，新建的spring图片会复用之前的spring图片节点，不会重新创建节点，也就不会有重影问题
          // 加id的规则为加在if和else下的第一个节点上，有多个并列节点则也需要进行添加
          .id('item1')
      } else {
        // geometryTransition此处绑定的是容器，那么容器内的子组件需设为相对布局跟随父容器变化，
        // 套多层容器为了说明相对布局约束传递
        Column() {
          Column() {
            Image($r('app.media.sky'))
              .size({ width: '100%', height: '100%' })
          }
          .size({ width: '100%', height: '100%' })
        }
        .width(100)
        .height(100)
        // geometryTransition会同步圆角，但仅限于geometryTransition绑定处，此处绑定的是容器
        // 则对容器本身有圆角同步而不会操作容器内部子组件的borderRadius
        .borderRadius(50)
        .clip(true)
        .geometryTransition("picture")
        // transition保证节点离场不被立即析构，设置通用转场效果
        .transition(TransitionEffect.OPACITY)
        .position({ x: 40, y: 40 })
        .id('item2')
      }
    }
    .onClick(() => {
      animateTo({
        curve: curves.springMotion()
      }, () => {
        this.isShow = !this.isShow;
      })
    })
    .size({ width: '100%', height: '100%' })
  }
}
```

![zh-cn_image_0000001599644878](figures/zh-cn_image_0000001599644878.gif)

### geometryTransition结合模态转场使用

更多的场景中，需要对一个页面的元素与另一个页面的元素添加一镜到底动效。可以通过geometryTransition搭配模态转场接口实现。以点击头像弹出个人信息页的demo为例：

```ts
class PostData {
  avatar: Resource = $r('app.media.flower');
  name: string = '';
  message: string = '';
  images: Resource[] = [];
}

@Entry
@Component
struct Index {
  @State isPersonalPageShow: boolean = false;
  @State selectedIndex: number = 0;
  @State alphaValue: number = 1;

  private allPostData: PostData[] = [
    { avatar: $r('app.media.flower'), name: 'Alice', message: '天气晴朗',
      images: [$r('app.media.spring'), $r('app.media.tree')] },
    { avatar: $r('app.media.sky'), name: 'Bob', message: '你好世界',
      images: [$r('app.media.island')] },
    { avatar: $r('app.media.tree'), name: 'Carl', message: '万物生长',
      images: [$r('app.media.flower'), $r('app.media.sky'), $r('app.media.spring')] }];

  private onAvatarClicked(index: number): void {
    this.selectedIndex = index;
    animateTo({
      duration: 350,
      curve: Curve.Friction
    }, () => {
      this.isPersonalPageShow = !this.isPersonalPageShow;
      this.alphaValue = 0;
    });
  }

  private onPersonalPageBack(index: number): void {
    animateTo({
      duration: 350,
      curve: Curve.Friction
    }, () => {
      this.isPersonalPageShow = !this.isPersonalPageShow;
      this.alphaValue = 1;
    });
  }

  @Builder
  PersonalPageBuilder(index: number) {
    Column({ space: 20 }) {
      Image(this.allPostData[index].avatar)
        .size({ width: 200, height: 200 })
        .borderRadius(100)
        // 头像配置共享元素效果，与点击的头像的id匹配
        .geometryTransition(index.toString())
        .clip(true)
        .transition(TransitionEffect.opacity(0.99))

      Text(this.allPostData[index].name)
        .font({ size: 30, weight: 600 })
        // 对文本添加出现转场效果
        .transition(TransitionEffect.asymmetric(
          TransitionEffect.OPACITY
            .combine(TransitionEffect.translate({ y: 100 })),
          TransitionEffect.OPACITY.animation({ duration: 0 })
        ))

      Text('你好，我是' + this.allPostData[index].name)
        // 对文本添加出现转场效果
        .transition(TransitionEffect.asymmetric(
          TransitionEffect.OPACITY
            .combine(TransitionEffect.translate({ y: 100 })),
          TransitionEffect.OPACITY.animation({ duration: 0 })
        ))
    }
    .padding({ top: 20 })
    .size({ width: 360, height: 780 })
    .backgroundColor(Color.White)
    .onClick(() => {
      this.onPersonalPageBack(index);
    })
    .transition(TransitionEffect.asymmetric(
      TransitionEffect.opacity(0.99),
      TransitionEffect.OPACITY
    ))
  }

  build() {
    Column({ space: 20 }) {
      ForEach(this.allPostData, (postData: PostData, index: number) => {
        Column() {
          Post({ data: postData, index: index, onAvatarClicked: (index: number) => { this.onAvatarClicked(index) } })
        }
        .width('100%')
      }, (postData: PostData, index: number) => index.toString())
    }
    .size({ width: '100%', height: '100%' })
    .backgroundColor('#40808080')
    .bindContentCover(this.isPersonalPageShow,
      this.PersonalPageBuilder(this.selectedIndex), { modalTransition: ModalTransition.NONE })
    .opacity(this.alphaValue)
  }
}

@Component
export default struct  Post {
  @Prop data: PostData;
  @Prop index: number;

  @State expandImageSize: number = 100;
  @State avatarSize: number = 50;

  private onAvatarClicked: (index: number) => void = (index: number) => { };

  build() {
    Column({ space: 20 }) {
      Row({ space: 10 }) {
        Image(this.data.avatar)
          .size({ width: this.avatarSize, height: this.avatarSize })
          .borderRadius(this.avatarSize / 2)
          .clip(true)
          .onClick(() => {
            this.onAvatarClicked(this.index);
          })
          // 对头像绑定共享元素转场的id
          .geometryTransition(this.index.toString(), {follow:true})
          .transition(TransitionEffect.OPACITY.animation({ duration: 350, curve: Curve.Friction }))

        Text(this.data.name)
      }
      .justifyContent(FlexAlign.Start)

      Text(this.data.message)

      Row({ space: 15 }) {
        ForEach(this.data.images, (imageResource: Resource, index: number) => {
          Image(imageResource)
            .size({ width: 100, height: 100 })
        }, (imageResource: Resource, index: number) => index.toString())
      }
    }
    .backgroundColor(Color.White)
    .size({ width: '100%', height: 250 })
    .alignItems(HorizontalAlign.Start)
    .padding({ left: 10, top: 10 })
  }
}
```

效果为点击主页的头像后，弹出模态页面显示个人信息，并且两个页面之间的头像做一镜到底动效：

![zh-cn_image_0000001597320327](figures/zh-cn_image_0000001597320327.gif)

## 相关实例

针对共享元素转场开发，有以下相关实例可供参考：

- [电子相册（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/ElectronicAlbum)