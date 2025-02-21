# 创建列表 (List)


## 概述

列表是一种复杂的容器，当列表项达到一定数量，内容超过屏幕大小时，可以自动提供滚动功能。它适合用于呈现同类数据类型或数据类型集，例如图片和文本。在列表中显示数据集合是许多应用程序中的常见要求（如通讯录、音乐列表、购物清单等）。

使用列表可以轻松高效地显示结构化、可滚动的信息。通过在[List](../reference/apis-arkui/arkui-ts/ts-container-list.md)组件中按垂直或者水平方向线性排列子组件[ListItemGroup](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md)或[ListItem](../reference/apis-arkui/arkui-ts/ts-container-listitem.md)，为列表中的行或列提供单个视图，或使用[循环渲染](../quick-start/arkts-rendering-control-foreach.md)迭代一组行或列，或混合任意数量的单个视图和ForEach结构，构建一个列表。List组件支持使用条件渲染、循环渲染、懒加载等[渲染控制](../quick-start/arkts-rendering-control-overview.md)方式生成子组件。


## 布局与约束

列表作为一种容器，会自动按其滚动方向排列子组件，向列表中添加组件或从列表中移除组件会重新排列子组件。

如下图所示，在垂直列表中，List按垂直方向自动排列ListItemGroup或ListItem。

ListItemGroup用于列表数据的分组展示，其子组件也是ListItem。ListItem表示单个列表项，可以包含单个子组件。

  **图1** List、ListItemGroup和ListItem组件关系  

![zh-cn_image_0000001562940589](figures/zh-cn_image_0000001562940589.png)

>**说明：**
>
>List的子组件必须是ListItemGroup或ListItem，ListItem和ListItemGroup必须配合List来使用。


### 布局

List除了提供垂直和水平布局能力、超出屏幕时可以滚动的自适应[延伸能力](../key-features/multi-device-app-dev/adaptive-layout.md#延伸能力)之外，还提供了自适应交叉轴方向上排列个数的布局能力。

利用垂直布局能力可以构建单列或者多列垂直滚动列表，如下图所示。

  **图2** 垂直滚动列表（左：单列；右：多列）  

![zh-cn_image_0000001511580940](figures/zh-cn_image_0000001511580940.png)

利用水平布局能力可以是构建单行或多行水平滚动列表，如下图所示。

  **图3** 水平滚动列表（左：单行；右：多行）  

![zh-cn_image_0000001511421344](figures/zh-cn_image_0000001511421344.png)


Grid和WaterFlow也可以实现单列、多列布局，如果布局每列等宽，且不需要跨行跨列布局，相比Grid和WaterFlow，则更推荐使用List。

### 约束

列表的主轴方向是指子组件列的排列方向，也是列表的滚动方向。垂直于主轴的轴称为交叉轴，其方向与主轴方向相互垂直。

如下图所示，垂直列表的主轴是垂直方向，交叉轴是水平方向；水平列表的主轴是水平方向，交叉轴是垂直方向。

  **图4** 列表的主轴与交叉轴  

![zh-cn_image_0000001562940581](figures/zh-cn_image_0000001562940581.png)

如果List组件主轴或交叉轴方向设置了尺寸，则其对应方向上的尺寸为设置值。

如果List组件主轴方向没有设置尺寸，当List子组件主轴方向总尺寸小于List的父组件尺寸时，List主轴方向尺寸自动适应子组件的总尺寸。

如下图所示，一个垂直列表B没有设置高度时，其父组件A高度为200vp，若其所有子组件C的高度总和为150vp，则此时列表B的高度为150vp。

  **图5** 列表主轴高度约束示例1（**A**: List的父组件; **B**: List组件; **C**: List的所有子组件）  

![zh-cn_image_0000001511580956](figures/zh-cn_image_0000001511580956.png)

如果子组件主轴方向总尺寸超过List父组件尺寸时，List主轴方向尺寸适应List的父组件尺寸。

如下图所示，同样是没有设置高度的垂直列表B，其父组件A高度为200vp，若其所有子组件C的高度总和为300vp，则此时列表B的高度为200vp。

  **图6** 列表主轴高度约束示例2（**A**: List的父组件; **B**: List组件; **C**: List的所有子组件）  

![zh-cn_image_0000001511740548](figures/zh-cn_image_0000001511740548.png)

List组件交叉轴方向在没有设置尺寸时，其尺寸默认自适应父组件尺寸。


## 开发布局


### 设置主轴方向

List组件主轴默认是垂直方向，即默认情况下不需要手动设置List方向，就可以构建一个垂直滚动列表。

若是水平滚动列表场景，将List的listDirection属性设置为Axis.Horizontal即可实现。listDirection默认为Axis.Vertical，即主轴默认是垂直方向。


```ts
List() {
  // ...
}
.listDirection(Axis.Horizontal)
```


### 设置交叉轴布局

List组件的交叉轴布局可以通过lanes和alignListItem属性进行设置，lanes属性用于确定交叉轴排列的列表项数量，alignListItem用于设置子组件在交叉轴方向的对齐方式。

List组件的lanes属性通常用于在不同尺寸的设备自适应构建不同行数或列数的列表，即一次开发、多端部署的场景，例如[歌单列表](../key-features/multi-device-app-dev/music-album-page.md#歌单列表)。lanes属性的取值类型是"number | [LengthConstrain](../reference/apis-arkui/arkui-ts/ts-types.md#lengthconstrain)"，即整数或者LengthConstrain类型。以垂直列表为例，如果将lanes属性设为2，表示构建的是一个两列的垂直列表，如图2中右图所示。lanes的默认值为1，即默认情况下，垂直列表的列数是1。


```ts
List() {
  // ...
}
.lanes(2)
```

当其取值为LengthConstrain类型时，表示会根据LengthConstrain与List组件的尺寸自适应决定行或列数。


```ts
@Entry
@Component
struct EgLanes {
  @State egLanes: LengthConstrain = { minLength: 200, maxLength: 300 }
  build() {
    List() {
      // ...
    }
    .lanes(this.egLanes)
  }
}
```

例如，假设在垂直列表中设置了lanes的值为{ minLength: 200, maxLength: 300 }。此时：

- 当List组件宽度为300vp时，由于minLength为200vp，此时列表为一列。

- 当List组件宽度变化至400vp时，符合两倍的minLength，则此时列表自适应为两列。

同样以垂直列表为例，当alignListItem属性设置为ListItemAlign.Center表示列表项在水平方向上居中对齐。alignListItem的默认值是ListItemAlign.Start，即列表项在列表交叉轴方向上默认按首部对齐。


```ts
List() {
  // ...
}
.alignListItem(ListItemAlign.Center)
```


## 在列表中显示数据

列表视图垂直或水平显示项目集合，在行或列超出屏幕时提供滚动功能，使其适合显示大型数据集合。在最简单的列表形式中，List静态地创建其列表项ListItem的内容。

  **图7** 城市列表  

![zh-cn_image_0000001563060761](figures/zh-cn_image_0000001563060761.png)

```ts
@Entry
@Component
struct CityList {
  build() {
    List() {
      ListItem() {
        Text('北京').fontSize(24)
      }

      ListItem() {
        Text('杭州').fontSize(24)
      }

      ListItem() {
        Text('上海').fontSize(24)
      }
    }
    .backgroundColor('#FFF1F3F5')
    .alignListItem(ListItemAlign.Center)
  }
}
```

由于在ListItem中只能有一个根节点组件，不支持以平铺形式使用多个组件。因此，若列表项是由多个组件元素组成的，则需要将这多个元素组合到一个容器组件内或组成一个自定义组件。

  **图8** 联系人列表项示例  

![zh-cn_image_0000001511421328](figures/zh-cn_image_0000001511421328.png)

如上图所示，联系人列表的列表项中，每个联系人都有头像和名称。此时，需要将Image和Text封装到一个Row容器内。


```ts
List() {
  ListItem() {
    Row() {
      Image($r('app.media.iconE'))
        .width(40)
        .height(40)
        .margin(10)

      Text('小明')
        .fontSize(20)
    }
  }

  ListItem() {
    Row() {
      Image($r('app.media.iconF'))
        .width(40)
        .height(40)
        .margin(10)

      Text('小红')
        .fontSize(20)
    }
  }
}
```


## 迭代列表内容

通常，应用通过数据集合动态地创建列表。使用[循环渲染](../quick-start/arkts-rendering-control-foreach.md)可从数据源中迭代获取数据，并在每次迭代过程中创建相应的组件，降低代码复杂度。

ArkTS通过[ForEach](../quick-start/arkts-rendering-control-foreach.md)提供了组件的循环渲染能力。以简单形式的联系人列表为例，将联系人名称和头像数据以Contact类结构存储到contacts数组，使用ForEach中嵌套ListItem的形式来代替多个平铺的、内容相似的ListItem，从而减少重复代码。


```ts
import { util } from '@kit.ArkTS'

class Contact {
  key: string = util.generateRandomUUID(true);
  name: string;
  icon: Resource;

  constructor(name: string, icon: Resource) {
    this.name = name;
    this.icon = icon;
  }
}

@Entry
@Component
struct SimpleContacts {
  private contacts: Array<object> = [
    new Contact('小明', $r("app.media.iconA")),
    new Contact('小红', $r("app.media.iconB")),
  ]

  build() {
    List() {
      ForEach(this.contacts, (item: Contact) => {
        ListItem() {
          Row() {
            Image(item.icon)
              .width(40)
              .height(40)
              .margin(10)
            Text(item.name).fontSize(20)
          }
          .width('100%')
          .justifyContent(FlexAlign.Start)
        }
      }, (item: Contact) => JSON.stringify(item))
    }
    .width('100%')
  }
}
```

在List组件中，ForEach除了可以用来循环渲染ListItem，也可以用来循环渲染ListItemGroup。ListItemGroup的循环渲染详细使用请参见[支持分组列表](#支持分组列表)。


## 自定义列表样式


### 设置内容间距

在初始化列表时，如需在列表项之间添加间距，可以使用space参数。例如，在每个列表项之间沿主轴方向添加10vp的间距：


```ts
List({ space: 10 }) {
  // ...
}
```


### 添加分隔线

分隔线用来将界面元素隔开，使单个元素更加容易识别。如下图所示，当列表项左边有图标（如蓝牙图标），由于图标本身就能很好的区分，此时分隔线从图标之后开始显示即可。

  **图9** 设置列表分隔线样式  

![zh-cn_image_0000001511580960](figures/zh-cn_image_0000001511580960.png)

List提供了divider属性用于给列表项之间添加分隔线。在设置divider属性时，可以通过strokeWidth和color属性设置分隔线的粗细和颜色。

startMargin和endMargin属性分别用于设置分隔线距离列表侧边起始端的距离和距离列表侧边结束端的距离。


```ts
class DividerTmp {
  strokeWidth: Length = 1
  startMargin: Length = 60
  endMargin: Length = 10
  color: ResourceColor = '#ffe9f0f0'

  constructor(strokeWidth: Length, startMargin: Length, endMargin: Length, color: ResourceColor) {
    this.strokeWidth = strokeWidth
    this.startMargin = startMargin
    this.endMargin = endMargin
    this.color = color
  }
}
@Entry
@Component
struct EgDivider {
  @State egDivider: DividerTmp = new DividerTmp(1, 60, 10, '#ffe9f0f0')
  build() {
    List() {
      // ...
    }
    .divider(this.egDivider)
  }
}
```

此示例表示从距离列表侧边起始端60vp开始到距离结束端10vp的位置，画一条粗细为1vp的分割线，可以实现图9设置列表分隔线的样式。

>**说明：**
>
>1. 分隔线的宽度会使ListItem之间存在一定间隔，当List设置的内容间距小于分隔线宽度时，ListItem之间的间隔会使用分隔线的宽度。
>
>2. 当List存在多列时，分割线的startMargin和endMargin作用于每一列上。
>
>3. List组件的分隔线画在两个ListItem之间，第一个ListItem上方和最后一个ListItem下方不会绘制分隔线。


### 添加滚动条

当列表项高度（宽度）超出屏幕高度（宽度）时，列表可以沿垂直（水平）方向滚动。在页面内容很多时，若用户需快速定位，可拖拽滚动条，如下图所示。

  **图10** 列表的滚动条 

![zh-cn_image_0000001511740544](figures/zh-cn_image_0000001511740544.gif)

在使用List组件时，可通过scrollBar属性控制列表滚动条的显示。scrollBar的取值类型为[BarState](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#barstate)，当取值为BarState.Auto表示按需显示滚动条。此时，当触摸到滚动条区域时显示控件，可上下拖拽滚动条快速浏览内容，拖拽时会变粗。若不进行任何操作，2秒后滚动条自动消失。

scrollBar属性API version 9及以下版本默认值为BarState.Off，从API version 10版本开始默认值为BarState.Auto。
```ts
List() {
  // ...
}
.scrollBar(BarState.Auto)
```


## 支持分组列表

在列表中支持数据的分组展示，可以使列表显示结构清晰，查找方便，从而提高使用效率。分组列表在实际应用中十分常见，如下图所示联系人列表。

  **图11** 联系人分组列表 

![zh-cn_image_0000001511580948](figures/zh-cn_image_0000001511580948.png)

在List组件中使用ListItemGroup对项目进行分组，可以构建二维列表。

在List组件中可以直接使用一个或者多个ListItemGroup组件，ListItemGroup的宽度默认充满List组件。在初始化ListItemGroup时，可通过header参数设置列表分组的头部组件。


```ts
@Entry
@Component
struct ContactsList {
  
  @Builder itemHead(text: string) {
    // 列表分组的头部组件，对应联系人分组A、B等位置的组件
    Text(text)
      .fontSize(20)
      .backgroundColor('#fff1f3f5')
      .width('100%')
      .padding(5)
  }

  build() {
    List() {
      ListItemGroup({ header: this.itemHead('A') }) {
        // 循环渲染分组A的ListItem
      }

      ListItemGroup({ header: this.itemHead('B') }) {
        // 循环渲染分组B的ListItem
      }
    }
  }
}
```

如果多个ListItemGroup结构类似，可以将多个分组的数据组成数组，然后使用ForEach对多个分组进行循环渲染。例如在联系人列表中，将每个分组的联系人数据contacts（可参考[迭代列表内容](#迭代列表内容)章节）和对应分组的标题title数据进行组合，定义为数组contactsGroups。然后在ForEach中对contactsGroups进行循环渲染，即可实现多个分组的联系人列表。可参考[添加粘性标题](#添加粘性标题)章节示例代码。

## 添加粘性标题

粘性标题是一种常见的标题模式，常用于定位字母列表的头部元素。如下图所示，在联系人列表中滚动A部分时，B部分开始的头部元素始终处于A的下方。而在开始滚动B部分时，B的头部会固定在屏幕顶部，直到所有B的项均完成滚动后，才被后面的头部替代。

粘性标题不仅有助于阐明列表中数据的表示形式和用途，还可以帮助用户在大量信息中进行数据定位，从而避免用户在标题所在的表的顶部与感兴趣区域之间反复滚动。

  **图12** 粘性标题  

![zh-cn_image_0000001511740552](figures/zh-cn_image_0000001511740552.gif)

List组件的sticky属性配合ListItemGroup组件使用，用于设置ListItemGroup中的头部组件是否呈现吸顶效果或者尾部组件是否呈现吸底效果。

通过给List组件设置sticky属性为StickyStyle.Header，即可实现列表的粘性标题效果。如果需要支持吸底效果，可以通过footer参数初始化ListItemGroup的底部组件，并将sticky属性设置为StickyStyle.Footer。


```ts
import { util } from '@kit.ArkTS'
class Contact {
  key: string = util.generateRandomUUID(true);
  name: string;
  icon: Resource;

  constructor(name: string, icon: Resource) {
    this.name = name;
    this.icon = icon;
  }
}
class ContactsGroup {
  title: string = ''
  contacts: Array<object> | null = null
  key: string = ""
}
export let contactsGroups: object[] = [
  {
    title: 'A',
    contacts: [
      new Contact('艾佳', $r('app.media.iconA')),
      new Contact('安安', $r('app.media.iconB')),
      new Contact('Angela', $r('app.media.iconC')),
    ],
    key: util.generateRandomUUID(true)
  } as ContactsGroup,
  {
    title: 'B',
    contacts: [
      new Contact('白叶', $r('app.media.iconD')),
      new Contact('伯明', $r('app.media.iconE')),
    ],
    key: util.generateRandomUUID(true)
  } as ContactsGroup,
  // ...
]
@Entry
@Component
struct ContactsList {
  // 定义分组联系人数据集合contactsGroups数组
  @Builder itemHead(text: string) {
    // 列表分组的头部组件，对应联系人分组A、B等位置的组件
    Text(text)
      .fontSize(20)
      .backgroundColor('#fff1f3f5')
      .width('100%')
      .padding(5)
  }
  build() {
    List() {
      // 循环渲染ListItemGroup，contactsGroups为多个分组联系人contacts和标题title的数据集合
      ForEach(contactsGroups, (itemGroup: ContactsGroup) => {
        ListItemGroup({ header: this.itemHead(itemGroup.title) }) {
          // 循环渲染ListItem
          if (itemGroup.contacts) {
            ForEach(itemGroup.contacts, (item: Contact) => {
              ListItem() {
                // ...
              }
            }, (item: Contact) => JSON.stringify(item))
          }
        }
      }, (itemGroup: ContactsGroup) => JSON.stringify(itemGroup))
    }.sticky(StickyStyle.Header)  // 设置吸顶，实现粘性标题效果
  }
}
```


## 控制滚动位置

控制滚动位置在实际应用中十分常见，例如当新闻页列表项数量庞大，用户滚动列表到一定位置时，希望快速滚动到列表底部或返回列表顶部。此时，可以通过控制滚动位置来实现列表的快速定位，如下图所示。

  **图13** 返回列表顶部  

![zh-cn_image_0000001511900520](figures/zh-cn_image_0000001511900520.gif)

List组件初始化时，可以通过scroller参数绑定一个[Scroller](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#scroller)对象，进行列表的滚动控制。例如，用户在新闻应用中，点击新闻页面底部的返回顶部按钮时，就可以通过Scroller对象的scrollToIndex方法使列表滚动到指定的列表项索引位置。

首先，需要创建一个Scroller的对象listScroller。


```ts
private listScroller: Scroller = new Scroller();
```

然后，通过将listScroller用于初始化List组件的scroller参数，完成listScroller与列表的绑定。在需要跳转的位置指定scrollToIndex的参数为0，表示返回列表顶部。


```ts
Stack({ alignContent: Alignment.Bottom }) {
  // 将listScroller用于初始化List组件的scroller参数，完成listScroller与列表的绑定。
  List({ space: 20, scroller: this.listScroller }) {
    // ...
  }

  Button() {
    // ...
  }
  .onClick(() => {
    // 点击按钮时，指定跳转位置，返回列表顶部
    this.listScroller.scrollToIndex(0)
  })
}
```


## 响应滚动位置

许多应用需要监听列表的滚动位置变化并作出响应。例如，在联系人列表滚动时，如果跨越了不同字母开头的分组，则侧边字母索引栏也需要更新到对应的字母位置。

除了字母索引之外，滚动列表结合多级分类索引在应用开发过程中也很常见，例如购物应用的商品分类页面，多级分类也需要监听列表的滚动位置。

**图14** 字母索引响应联系人列表滚动  

![zh-cn_image_0000001563060769](figures/zh-cn_image_0000001563060769.gif)

如上图所示，当联系人列表从A滚动到B时，右侧索引栏也需要同步从选中A状态变成选中B状态。此场景可以通过监听List组件的onScrollIndex事件来实现，右侧索引栏需要使用字母表索引组件[AlphabetIndexer](../reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md)。

在列表滚动时，根据列表此时所在的索引值位置firstIndex，重新计算字母索引栏对应字母的位置selectedIndex。由于AlphabetIndexer组件通过selected属性设置了选中项索引值，当selectedIndex变化时会触发AlphabetIndexer组件重新渲染，从而显示为选中对应字母的状态。


```ts
const alphabets = ['#', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
  'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];
@Entry
@Component
struct ContactsList {
  @State selectedIndex: number = 0;
  private listScroller: Scroller = new Scroller();

  build() {
    Stack({ alignContent: Alignment.End }) {
      List({ scroller: this.listScroller }) {}
      .onScrollIndex((firstIndex: number) => {
        // 根据列表滚动到的索引值，重新计算对应联系人索引栏的位置this.selectedIndex
      })

      // 字母表索引组件
      AlphabetIndexer({ arrayValue: alphabets, selected: 0 })
        .selected(this.selectedIndex)
    }
  }
}
```

>**说明：**
>
>计算索引值时，ListItemGroup作为一个整体占一个索引值，不计算ListItemGroup内部ListItem的索引值。


## 响应列表项侧滑

侧滑菜单在许多应用中都很常见。例如，通讯类应用通常会给消息列表提供侧滑删除功能，即用户可以通过向左侧滑列表的某一项，再点击删除按钮删除消息，如下图所示。其中，列表项头像右上角标记设置参考[给列表项添加标记](#给列表项添加标记)。

**图15** 侧滑删除列表项  

![zh-cn_image_0000001563060773](figures/zh-cn_image_0000001563060773.gif)

ListItem的[swipeAction属性](../reference/apis-arkui/arkui-ts/ts-container-listitem.md#swipeaction9)可用于实现列表项的左右滑动功能。swipeAction属性方法初始化时有必填参数SwipeActionOptions，其中，start参数表示设置列表项右滑时起始端滑出的组件，end参数表示设置列表项左滑时尾端滑出的组件。

在消息列表中，end参数表示设置ListItem左滑时尾端划出自定义组件，即删除按钮。在初始化end方法时，将滑动列表项的索引传入删除按钮组件，当用户点击删除按钮时，可以根据索引值来删除列表项对应的数据，从而实现侧滑删除功能。

1. 实现尾端滑出组件的构建。

    ```ts
    @Builder itemEnd(index: number) {
      // 构建尾端滑出组件
      Button({ type: ButtonType.Circle }) {
        Image($r('app.media.ic_public_delete_filled'))
          .width(20)
          .height(20)
      }
      .onClick(() => {
        // this.messages为列表数据源，可根据实际场景构造。点击后从数据源删除指定数据项。
        this.messages.splice(index, 1);
      })
    }
    ```

2. 绑定swipeAction属性到可左滑的ListItem上。

    ```ts
    // 构建List时，通过ForEach基于数据源this.messages循环渲染ListItem。
    ListItem() {
      // ...
    }
    .swipeAction({
      end: {
        // index为该ListItem在List中的索引值。
        builder: () => { this.itemEnd(index) },
      }
    }) // 设置侧滑属性.
    ```

## 给列表项添加标记

添加标记是一种无干扰性且直观的方法，用于显示通知或将注意力集中到应用内的某个区域。例如，当消息列表接收到新消息时，通常对应的联系人头像的右上方会出现标记，提示有若干条未读消息，如下图所示。

  **图16** 给列表项添加标记  

![zh-cn_image_0000001511580952](figures/zh-cn_image_0000001511580952.png)

在ListItem中使用[Badge](../reference/apis-arkui/arkui-ts/ts-container-badge.md)组件可实现给列表项添加标记功能。Badge是可以附加在单个组件上用于信息标记的容器组件。

在消息列表中，若希望在联系人头像右上角添加标记，可在实现消息列表项ListItem的联系人头像时，将头像Image组件作为Badge的子组件。

在Badge组件中，count和position参数用于设置需要展示的消息数量和提示点显示位置，还可以通过style参数灵活设置标记的样式。


```ts
ListItem() {
  Badge({
    count: 1,
    position: BadgePosition.RightTop,
    style: { badgeSize: 16, badgeColor: '#FA2A2D' }
  }) {
    // Image组件实现消息联系人头像
    // ...
  }
}
```


## 下拉刷新与上拉加载

页面的下拉刷新与上拉加载功能在移动应用中十分常见，例如，新闻页面的内容刷新和加载。这两种操作的原理都是通过响应用户的[触摸事件](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md)，在顶部或者底部显示一个刷新或加载视图，完成后再将此视图隐藏。

以下拉刷新为例，其实现主要分成三步：

1. 监听手指按下事件，记录其初始位置的值。

2. 监听手指按压移动事件，记录并计算当前移动的位置与初始值的差值，大于0表示向下移动，同时设置一个允许移动的最大值。

3. 监听手指抬起事件，若此时移动达到最大值，则触发数据加载并显示刷新视图，加载完成后将此视图隐藏。

> **说明：** 
>
> 页面的下拉刷新操作推荐使用[Refresh](../reference/apis-arkui/arkui-ts/ts-container-refresh.md)组件实现。

<!--RP1--><!--RP1End-->

<!--Del-->
下拉刷新与上拉加载的具体实现可参考[相关实例](#相关实例)中新闻数据加载。若开发者希望快速实现此功能，也可使用三方组件[PullToRefresh](https://gitee.com/openharmony-sig/PullToRefresh)。<!--DelEnd-->


## 编辑列表

列表的编辑模式用途十分广泛，常见于待办事项管理、文件管理、备忘录的记录管理等应用场景。在列表的编辑模式下，新增和删除列表项是最基础的功能，其核心是对列表项对应的数据集合进行数据添加和删除。

下面以待办事项管理为例，介绍如何快速实现新增和删除列表项功能。


### 新增列表项

如下图所示，当用户点击添加按钮时，提供用户新增列表项内容选择或填写的交互界面，用户点击确定后，列表中新增对应的项目。

  **图17** 新增待办  

![zh-cn_image_0000001511740556](figures/zh-cn_image_0000001511740556.gif)

添加列表项功能实现主要流程如下：

1. 定义列表项数据结构，以待办事项管理为例，首先定义待办数据结构。

   ```ts
   //ToDo.ets
   import { util } from '@kit.ArkTS'

   export class ToDo {
     key: string = util.generateRandomUUID(true);
     name: string;

     constructor(name: string) {
       this.name = name;
     }
   }
   ```

2. 构建列表整体布局和列表项。

   ```ts
   //ToDoListItem.ets
   import { ToDo } from './ToDo';
   @Component
   export struct ToDoListItem {
     @Link isEditMode: boolean
     @Link selectedItems: ToDo[]
     private toDoItem: ToDo = new ToDo("");

     build() {
      Flex({ justifyContent: FlexAlign.SpaceBetween, alignItems: ItemAlign.Center }) {
        // ...
      }
      .width('100%')
      .height(80)
      //.padding() 根据具体使用场景设置
      .borderRadius(24)
      //.linearGradient() 根据具体使用场景设置
      .gesture(
        GestureGroup(GestureMode.Exclusive,
        LongPressGesture()
          .onAction(() => {
            // ...
          })
        )
      )
     }
   }
   ```

3. 初始化待办列表数据和可选事项，最后，构建列表布局和列表项。

   ```ts
   //ToDoList.ets
   import { ToDo } from './ToDo';
   import { ToDoListItem } from './ToDoListItem';
   
   @Entry
   @Component
   struct ToDoList {
     @State toDoData: ToDo[] = []
     @Watch('onEditModeChange') @State isEditMode: boolean = false
     @State selectedItems: ToDo[] = []
    private availableThings: string[] = ['读书', '运动', '旅游', '听音乐', '看电影', '唱歌']
   
     onEditModeChange() {
       if (!this.isEditMode) {
         this.selectedItems = []
       }
    }
   
     build() {
       Column() {
         Row() {
           if (this.isEditMode) {
             Text('X')
               .fontSize(20)
               .onClick(() => {
                 this.isEditMode = false;
               })
               .margin({ left: 20, right: 20 })
           } else {
             Text('待办')
               .fontSize(36)
               .margin({ left: 40 })
             Blank()
             Text('+') //提供新增列表项入口，即给新增按钮添加点击事件
               .onClick(() => {
                 this.getUIContext().showTextPickerDialog({
                   range: this.availableThings,
                   onAccept: (value: TextPickerResult) => {
                     let arr = Array.isArray(value.index) ? value.index : [value.index];
                     for (let i = 0; i < arr.length; i++) {
                       this.toDoData.push(new ToDo(this.availableThings[arr[i]])); // 新增列表项数据toDoData(可选事项)
                     }
                   },
                 })
               })
           }
           List({ space: 10 }) {
             ForEach(this.toDoData, (toDoItem: ToDo) => {
               ListItem() {
                 // 将toDoData的每个数据放入到以model的形式放进ListItem里
                 ToDoListItem({
                   isEditMode: this.isEditMode,
                   toDoItem: toDoItem,
                   selectedItems: this.selectedItems })
               }
             }, (toDoItem: ToDo) => toDoItem.key.toString())
           }
         }
       }
     }
   }
   ```


### 删除列表项

如下图所示，当用户长按列表项进入删除模式时，提供用户删除列表项选择的交互界面，用户勾选完成后点击删除按钮，列表中删除对应的项目。

  **图18** 长按删除待办事项  

![zh-cn_image_0000001562820877](figures/zh-cn_image_0000001562820877.gif)

删除列表项功能实现主要流程如下：

1. 列表的删除功能一般进入编辑模式后才可使用，所以需要提供编辑模式的入口。
   以待办列表为例，通过监听列表项的长按事件，当用户长按列表项时，进入编辑模式。

    ```ts
    // 结构参考
    export class ToDo {
      key: string = util.generateRandomUUID(true);
      name: string;
      toDoData: ToDo[] = [];

      constructor(name: string) {
        this.name = name;
      }
    }
    ```
    ```ts
    // 实现参考
    Flex({ justifyContent: FlexAlign.SpaceBetween, alignItems: ItemAlign.Center }) {
      // ...
    }
    .gesture(
    GestureGroup(GestureMode.Exclusive,
      LongPressGesture()
        .onAction(() => {
          if (!this.isEditMode) {
            this.isEditMode = true; //进入编辑模式
          }
        })
      )
    )
    ```
   
2. 需要响应用户的选择交互，记录要删除的列表项数据。
   在待办列表中，通过勾选框的勾选或取消勾选，响应用户勾选列表项变化，记录所有选择的列表项。

    ```ts
   // 结构参考
   import { util } from '@kit.ArkTS'
   export class ToDo {
     key: string = util.generateRandomUUID(true);
     name: string;
     toDoData: ToDo[] = [];

     constructor(name: string) {
       this.name = name;
     }
   }
    ```
    ```ts
    // 实现参考
    if (this.isEditMode) {
      Checkbox()
        .onChange((isSelected) => {
          if (isSelected) {
            this.selectedItems.push(toDoList.toDoItem) // this.selectedItems为勾选时，记录选中的列表项，可根据实际场景构造
          } else {
            let index = this.selectedItems.indexOf(toDoList.toDoItem)
            if (index !== -1) {
              this.selectedItems.splice(index, 1) // 取消勾选时，则将此项从selectedItems中删除
            }
          }
        })
    }
    ```
   
3. 需要响应用户点击删除按钮事件，删除列表中对应的选项。

    ```ts
    // 结构参考
    import { util } from '@kit.ArkTS'
    export class ToDo {
      key: string = util.generateRandomUUID(true);
      name: string;
      toDoData: ToDo[] = [];

      constructor(name: string) {
        this.name = name;
      }
    }
    ```
    ```ts
    // 实现参考
    Button('删除')
      .onClick(() => {
        // this.toDoData为待办的列表项，可根据实际场景构造。点击后删除选中的列表项对应的toDoData数据
        let leftData = this.toDoData.filter((item) => {
          return !this.selectedItems.find((selectedItem) => selectedItem == item);
        })
        this.toDoData = leftData;
        this.isEditMode = false;
      })
    ```


## 长列表的处理

[循环渲染](../quick-start/arkts-rendering-control-foreach.md)适用于短列表，当构建具有大量列表项的长列表时，如果直接采用循环渲染方式，会一次性加载所有的列表元素，会导致页面启动时间过长，影响用户体验。因此，推荐使用[数据懒加载](../quick-start/arkts-rendering-control-lazyforeach.md)（LazyForEach）方式实现按需迭代加载数据，从而提升列表性能。

关于长列表按需加载优化的具体实现可参考[数据懒加载](../quick-start/arkts-rendering-control-lazyforeach.md)章节中的示例。

当使用懒加载方式渲染列表时，为了更好的列表滚动体验，减少列表滑动时出现白块，List组件提供了cachedCount参数用于设置列表项缓存数，只在懒加载LazyForEach中生效。


```ts
List() {
  // ...
}.cachedCount(3)
```

以垂直列表为例：

- 若懒加载是用于ListItem，当列表为单列模式时，会在List显示的ListItem前后各缓存cachedCount个ListItem；若是多列模式下，会在List显示的ListItem前后各缓存cachedCount \* 列数个ListItem。

- 若懒加载是用于ListItemGroup，无论单列模式还是多列模式，都是在List显示的ListItem前后各缓存cachedCount个ListItemGroup。

>**说明：**
>
>1. cachedCount的增加会增大UI的CPU、内存开销。使用时需要根据实际情况，综合性能和用户体验进行调整。
>
>2. 列表使用数据懒加载时，除了显示区域的列表项和前后缓存的列表项，其他列表项会被销毁。


## 折叠与展开

列表项的折叠与展开用途广泛，常用于信息清单的展示、填写等应用场景。

  **图19** 列表项的折叠与展开 

![zh-cn_image_0000001949866104](figures/zh-cn_image_0000001949866104.gif)

列表项折叠与展开效果实现主要流程如下：

1. 定义列表项数据结构。

    ```ts
    interface ItemInfo {
      index: number,
      name: string,
      label: ResourceStr,
      type?: string,
    }

    interface ItemGroupInfo extends ItemInfo {
      children: ItemInfo[]
    }
    ```

2. 构造列表结构。

    ```ts
    @State routes: ItemGroupInfo[] = [
      {
        index: 0,
        name: 'basicInfo',
        label: '个人基本资料',
        children: [
          {
            index: 0,
            name: '昵称',
            label: 'xxxx',
            type: 'Text'
          },
          {
            index: 1,
            name: '头像',
            label: $r('sys.media.ohos_user_auth_icon_face'),
            type: 'Image'
          },
          {
            index: 2,
            name: '年龄',
            label: 'xxxx',
            type: 'Text'
          },
          {
            index: 3,
            name: '生日',
            label: 'xxxxxxxxx',
            type: 'Text'
          },
          {
            index: 4,
            name: '性别',
            label: 'xxxxxxxx',
            type: 'Text'
          },
        ]
      },
      {
        index: 1,
        name: 'equipInfo',
        label: '设备信息',
        children: []
      },
      {
        index: 2,
        name: 'appInfo',
        label: '应用使用信息',
        children: []
      },
      {
        index: 3,
        name: 'uploadInfo',
        label: '您主动上传的数据',
        children: []
      },
      {
        index: 4,
        name: 'tradeInfo',
        label: '交易与资产信息',
        children: []
      },
      {
        index: 5,
        name: 'otherInfo',
        label: '其他资料',
        children: []
      },
    ];
    @State expandedItems: boolean[] = Array(this.routes.length).fill(false);
    @State selection: string | null = null;
    build() {
      Column() {
        // ...

        List({ space: 10 }) {
          ForEach(this.routes, (itemGroup: ItemGroupInfo) => {
            ListItemGroup({
              header: this.ListItemGroupHeader(itemGroup),
              style: ListItemGroupStyle.CARD,
            }) {
              if (this.expandedItems[itemGroup.index] && itemGroup.children) {
                ForEach(itemGroup.children, (item: ItemInfo) => {
                  ListItem({ style: ListItemStyle.CARD }) {
                    Row() {
                      Text(item.name)
                      Blank()
                      if (item.type === 'Image') {
                        Image(item.label)
                          .height(20)
                          .width(20)
                      } else {
                        Text(item.label)
                      }
                      Image($r('sys.media.ohos_ic_public_arrow_right'))
                        .fillColor($r('sys.color.ohos_id_color_fourth'))
                        .height(30)
                        .width(30)
                    }
                    .width("100%")
                  }
                  .width("100%")
                  .animation({ curve: curves.interpolatingSpring(0, 1, 528, 39) })
                })
              }
            }.clip(true)
          })
        }
        .width("100%")
      }
      .width('100%')
      .height('100%')
      .justifyContent(FlexAlign.Start)
      .backgroundColor($r('sys.color.ohos_id_color_sub_background'))
    }
    ```

3. 通过改变ListItem的状态，来控制每个列表项是否展开，并通过animation和animateTo来实现展开与折叠过程中的动效效果。

    ```ts
    @Builder
    ListItemGroupHeader(itemGroup: ItemGroupInfo) {
      Row() {
        Text(itemGroup.label)
        Blank()
        Image($r('sys.media.ohos_ic_public_arrow_down'))
          .fillColor($r('sys.color.ohos_id_color_fourth'))
          .height(30)
          .width(30)
          .rotate({ angle: !!itemGroup.children.length ? (this.expandedItems[itemGroup.index] ? 180 : 0) : 180 })
          .animation({ curve: curves.interpolatingSpring(0, 1, 228, 22) })
      }
      .width("100%")
      .padding(10)
      .animation({ curve: curves.interpolatingSpring(0, 1, 528, 39) })
      .onClick(() => {
        if (itemGroup.children.length) {
          this.getUIContext()?.animateTo({ curve: curves.interpolatingSpring(0, 1, 528, 39) }, () => {
            this.expandedItems[itemGroup.index] = !this.expandedItems[itemGroup.index]
          })
        }
      })
    }
    ```

## 切换布局方向

部分业务场景需要列表底部插入数据时，自动向上滚动，把新插入的节点展示出来。例如，直播评论、即时聊天等应用场景。而List组件正常布局时, 在内容下方增加节点，内容是保持不变的。此时，可以通过切换布局方向来实现所需效果。

  **图20** 实时消息滚动显示

![zh-cn_image_0000001949866105](figures/zh-cn_image_0000001949866105.gif)

1. 定义列表项数据结构。

    ```ts
    interface Message {
      id: number
      content: string
      sender: string
    }
    ```

2. 构造列表结构，同时把stackFromEnd接口值设置为true，即可实现list列表在底部插入数据时，内容向上滚动。

    ```ts
    @State messages: Message[] = [
        { id: 1, content: '欢迎来到直播间！', sender: '系统' },
        { id: 2, content: '大家好啊~', sender: '主播' }
    ]
    build() {
      Column() {
        List({ space: 10 }) {
          ForEach(this.messages, (item: Message) => {
            ListItem() {
              this.MessageItem(item)
            }
          }, (item: Message) => item.id.toString())
        }
        .stackFromEnd(true)
        .layoutWeight(1)
        .alignListItem(ListItemAlign.Center)
        // ...
      }
      .width('100%')
      .height('100%')
    }
    ```

## 相关实例

如需详细了解ArkUI中列表的创建与使用，请参考以下示例：

- [新闻数据加载](https://gitee.com/openharmony/codelabs/tree/master/NetworkManagement/NewsDataArkTS)

- [音乐专辑页](../key-features/multi-device-app-dev/music-album-page.md)

- [常用组件和容器低代码开发示例（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/EfficiencyEnhancementKit/SuperVisualSample)

- [二级联动（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/SecondLevelLinkage)

- [List组件的使用之商品列表（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/List)

- [List组件的使用之设置项（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/List_HDC)

- [PullToRefresh](https://gitee.com/openharmony-sig/PullToRefresh)

<!--RP2--><!--RP2End-->
