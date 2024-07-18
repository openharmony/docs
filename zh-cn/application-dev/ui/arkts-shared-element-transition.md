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

通过[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md)[自定义占位节点](arkts-user-defined-place-hoder.md)，利用[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md)实现组件的跨节点迁移，配合属性动画给组件的迁移过程赋予一镜到底效果。

以展开收起卡片的场景为例，实现步骤为：

- 展开卡片时，获取节点A的位置信息，将其中的组件迁移到与节点A位置一致的节点B处，节点B的层级高于节点A。

- 对节点B添加属性动画，使之展开并运动到展开后的位置，完成一镜到底的动画效果。

- 收起卡片时，对节点B添加属性动画，使之收起并运动到收起时的位置，即节点A的位置，实现一镜到底的动画效果。

- 在动画结束时利用回调将节点B中的组件迁移回节点A处。

```ts
// Index.ets
import { createPostNode, getPostNode, PostNode } from "../PostNode"
import { componentUtils, curves } from '@kit.ArkUI';

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
import { curves } from '@kit.ArkUI';

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

![cn_image_sharedElementsNodeTransfer](figures/zh-cn_image_sharedElementsNodeTransfer.gif)

## 使用geometryTransition共享元素转场

[geometryTransition](../reference/apis-arkui/arkui-ts/ts-transition-animation-geometrytransition.md)用于组件内隐式共享元素转场，在视图状态切换过程中提供丝滑的上下文继承过渡体验。

geometryTransition的使用方式为对需要添加一镜到底动效的两个组件使用geometryTransition接口绑定同一id，这样在其中一个组件消失同时另一个组件创建出现的时候，系统会对二者添加一镜到底动效。

geometryTransition绑定两个对象的实现方式使得geometryTransition区别于其他方法，最适合用于两个不同对象之间完成一镜到底。

### geometryTransition的简单使用

对于同一个页面中的两个元素的一镜到底效果，geometryTransition接口的简单使用示例如下：

```ts
import { curves } from '@kit.ArkUI';

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