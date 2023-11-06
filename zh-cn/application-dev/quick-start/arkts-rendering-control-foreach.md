# ForEach：循环渲染


ForEach接口基于数组类型数据来进行循环渲染，需要与容器组件配合使用，且接口返回的组件应当是允许包含在ForEach父容器组件中的子组件。例如，ListItem组件要求ForEach的父容器组件必须为[List组件](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V4/arkts-layout-development-create-list-0000001630265229-V4?catalogVersion=V4)。

> **说明：**
>
> 从API version 9开始，该接口支持在ArkTS卡片中使用。

## 接口描述


```ts
ForEach(
  arr: Array,
  itemGenerator: (item: Array, index?: number) => void,
  keyGenerator?: (item: Array, index?: number): string => string
)
```

以下是参数的详细说明：

| 参数名        | 参数类型                                | 是否必填 | 参数描述                                                     |
| ------------- | --------------------------------------- | -------- | ------------------------------------------------------------ |
| arr           | Array                                   | 是       | 数据源，为`Array`类型的数组。<br/>**说明：**<br/>- 可以设置为空数组，此时不会创建子组件。<br/>- 可以设置返回值为数组类型的函数，例如`arr.slice(1, 3)`，但设置的函数不应改变包括数组本身在内的任何状态变量，例如不应使用`Array.splice()`,`Array.sort()`或`Array.reverse()`这些会改变原数组的函数。 |
| itemGenerator | `(item: any, index?: number) => void`   | 是       | 组件生成函数。<br/>- 为数组中的每个元素创建对应的组件。<br/>- `item`参数：`arr`数组中的数据项。<br/>- `index`参数（可选）：`arr`数组中的数据项索引。<br/>**说明：**<br/>- 组件的类型必须是`ForEach`的父容器所允许的。例如，`ListItem`组件要求`ForEach`的父容器组件必须为`List`组件。 |
| keyGenerator  | `(item: any, index?: number) => string` | 否       | 键值生成函数。<br/>- 为数据源`arr`的每个数组项生成唯一且持久的键值。函数返回值为开发者自定义的键值生成规则。<br/>- `item`参数：`arr`数组中的数据项。<br/>- `index`参数（可选）：`arr`数组中的数据项索引。<br/>**说明：**<br/>- 如果函数缺省，框架默认的键值生成函数为`(item: T, index: number) => { return index + '__' + JSON.stringify(index); }`<br/>- 键值生成函数不应改变任何组件状态。 |

> **说明：**
>
> - `ForEach`的`itemGenerator`函数可以包含`if/else`条件渲染逻辑。另外，也可以在`if/else`条件渲染语句中使用`ForEach`组件。
> - 在初始化渲染时，`ForEach`会加载数据源的所有数据，并为每个数据项创建对应的组件，然后将其挂载到渲染树上。如果数据源非常大或有特定的性能需求，建议使用`LazyForEach`组件。

## 键值生成规则

在`ForEach`循环渲染过程中，系统会为每个数组元素生成一个唯一且持久的键值，用于标识对应的组件。当这个键值变化时，ArkUI框架将视为该数组元素已被替换或修改，并会基于新的键值创建一个新的组件。

`ForEach`提供了一个名为`keyGenerator`的参数，这是一个函数，开发者可以通过它自定义键值的生成规则。如果开发者没有定义`keyGenerator`函数，则ArkUI框架会使用默认的键值生成函数，即`(item: any, index: number) => { return index + '__' + JSON.stringify(item); }`。

ArkUI框架对于`ForEach`的键值生成有一套特定的判断规则，这主要与`itemGenerator`函数的第二个参数`index`以及`keyGenerator`函数的返回值有关。总的来说，只有当开发者在`itemGenerator`函数中声明了`index`参数，并且自定义的`keyGenerator`函数返回值中不包含`index`参数时，ArkUI框架才会在开发者自定义的`itemGenerator`函数返回值前添加`index`参数，作为最终的键值。在其他情况下，系统将直接使用开发者自定义的`keyGenerator`函数返回值作为最终的键值。如果`keyGenerator`函数未定义，系统将使用上述默认的键值生成函数。具体的键值生成规则判断逻辑如下图所示。

**图1** ForEach键值生成规则  
![ForEach-Key-Generation-Rules](figures/ForEach-Key-Generation-Rules.png)

> **说明：**
>
> - 即使在`itemGenerator`函数中声明了`index`参数，但并未在函数体中使用，也被视为对`index`参数进行了处理。
> - ArkUI框架会对重复的键值发出警告。在UI更新的场景下，如果出现重复的键值，框架可能无法正常工作，具体请参见[渲染结果非预期](#渲染结果非预期)。

## 组件创建规则

在确定键值生成规则后，ForEach的第二个参数`itemGenerator`函数会根据键值生成规则为数据源的每个数组项创建组件。组件的创建包括两种情况：[ForEach首次渲染](#首次渲染)和[ForEach非首次渲染](#非首次渲染)。

### 首次渲染

在ForEach首次渲染时，会根据前述键值生成规则为数据源的每个数组项生成唯一键值，并创建相应的组件。

```ts
@Entry
@Component
struct Parent {
  @State simpleList: Array<string> = ['one', 'two', 'three'];

  build() {
    Row() {
      Column() {
        ForEach(this.simpleList, (item: string) => {
          ChildItem({ item: item })
        }, (item: string) => item)
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
    .backgroundColor(0xF1F3F5)
  }
}

@Component
struct ChildItem {
  @Prop item: string;

  build() {
    Text(this.item)
      .fontSize(50)
  }
}
```

运行效果如下图所示。

**图2**  ForEach数据源不存在相同值案例首次渲染运行效果图  
![ForEach-CaseStudy-1stRender-NoDup](figures/ForEach-CaseStudy-1stRender-NoDup.png)

在上述代码中，键值生成规则是`keyGenerator`函数的返回值`item`。在ForEach渲染循环时，为数据源数组项依次生成键值`one`、`two`和`three`，并创建对应的`ChildItem`组件渲染到界面上。

当不同数组项按照键值生成规则生成的键值相同时，框架的行为是未定义的。例如，在以下代码中，ForEach渲染相同的数据项`two`时，只创建了一个`ChildItem`组件，而没有创建多个具有相同键值的组件。

 ```ts
 @Entry
 @Component
 struct Parent {
   @State simpleList: Array<string> = ['one', 'two', 'two', 'three'];
 
   build() {
     Row() {
       Column() {
         ForEach(this.simpleList, (item: string) => {
           ChildItem({ item: item })
         }, (item: string) => item)
       }
       .width('100%')
       .height('100%')
     }
     .height('100%')
     .backgroundColor(0xF1F3F5)
   }
 }
 
 @Component
 struct ChildItem {
   @Prop item: string;
 
   build() {
     Text(this.item)
       .fontSize(50)
   }
 }
 ```

运行效果如下图所示。

**图3**  ForEach数据源存在相同值案例首次渲染运行效果图  
![ForEach-CaseStudy-1stRender-Dup](figures/ForEach-CaseStudy-1stRender-Dup.png)

在该示例中，最终键值生成规则为`item`。当ForEach遍历数据源`simpleList`，遍历到索引为1的`two`时，按照最终键值生成规则生成键值为`two`的组件并进行标记。当遍历到索引为2的`two`时，按照最终键值生成规则当前项的键值也为`two`，此时不再创建新的组件。

### 非首次渲染

在ForEach组件进行非首次渲染时，它会检查新生成的键值是否在上次渲染中已经存在。如果键值不存在，则会创建一个新的组件；如果键值存在，则不会创建新的组件，而是直接渲染该键值所对应的组件。例如，在以下的代码示例中，通过点击事件修改了数组的第三项值为"new three"，这将触发ForEach组件进行非首次渲染。

```ts
@Entry
@Component
struct Parent {
  @State simpleList: Array<string> = ['one', 'two', 'three'];

  build() {
    Row() {
      Column() {
        Text('点击修改第3个数组项的值')
          .fontSize(24)
          .fontColor(Color.Red)
          .onClick(() => {
            this.simpleList[2] = 'new three';
          })

        ForEach(this.simpleList, (item: string) => {
          ChildItem({ item: item })
            .margin({ top: 20 })
        }, (item: string) => item)
      }
      .justifyContent(FlexAlign.Center)
      .width('100%')
      .height('100%')
    }
    .height('100%')
    .backgroundColor(0xF1F3F5)
  }
}

@Component
struct ChildItem {
  @Prop item: string;

  build() {
    Text(this.item)
      .fontSize(30)
  }
}
```

运行效果如下图所示。

**图4**  ForEach非首次渲染案例运行效果图  
![ForEach-Non-Initial-Render-Case-Effect](figures/ForEach-Non-Initial-Render-Case-Effect.gif)

从本例可以看出`@State` 能够监听到简单数据类型数组数据源 `simpleList` 数组项的变化。

当 `simpleList` 数组项发生变化时，会触发 `ForEach` 进行重新渲染。

`ForEach` 遍历新的数据源 `['one', 'two', 'new three']`，并生成对应的键值`one`、`two`和`new three`。

其中，键值`one`和`two`在上次渲染中已经存在，所以 `ForEach` 复用了对应的组件并进行了渲染。对于第三个数组项 "new three"，由于其通过键值生成规则 `item` 生成的键值`new three`在上次渲染中不存在，因此 `ForEach` 为该数组项创建了一个新的组件。

## 使用场景

ForEach组件在开发过程中的主要应用场景包括：[数据源不变](#数据源不变)、[数据源数组项发生变化](#数据源数组项发生变化)（如插入、删除操作）、[数据源数组项子属性变化](#数据源数组项子属性变化)。

### 数据源不变

在数据源保持不变的场景中，数据源可以直接采用基本数据类型。例如，在页面加载状态时，可以使用骨架屏列表进行渲染展示。

```ts
@Entry
@Component
struct ArticleList {
  @State simpleList: Array<number> = [1, 2, 3, 4, 5];

  build() {
    Column() {
      ForEach(this.simpleList, (item: string) => {
        ArticleSkeletonView()
          .margin({ top: 20 })
      }, (item: string) => item)
    }
    .padding(20)
    .width('100%')
    .height('100%')
  }
}

@Builder
function textArea(width: number | Resource | string = '100%', height: number | Resource | string = '100%') {
  Row()
    .width(width)
    .height(height)
    .backgroundColor('#FFF2F3F4')
}

@Component
struct ArticleSkeletonView {
  build() {
    Row() {
      Column() {
        textArea(80, 80)
      }
      .margin({ right: 20 })

      Column() {
        textArea('60%', 20)
        textArea('50%', 20)
      }
      .alignItems(HorizontalAlign.Start)
      .justifyContent(FlexAlign.SpaceAround)
      .height('100%')
    }
    .padding(20)
    .borderRadius(12)
    .backgroundColor('#FFECECEC')
    .height(120)
    .width('100%')
    .justifyContent(FlexAlign.SpaceBetween)
  }
}
```

运行效果如下图所示。

**图5** 骨架屏运行效果图  
![ForEach-SkeletonScreen](figures/ForEach-SkeletonScreen.png)

在本示例中，采用数据项item作为键值生成规则，由于数据源simpleList的数组项各不相同，因此能够保证键值的唯一性。

### 数据源数组项发生变化

在数据源数组项发生变化的场景下，例如进行数组插入、删除操作或者数组项索引位置发生交换时，数据源应为对象数组类型，并使用对象的唯一ID作为最终键值。例如，当在页面上通过手势上滑加载下一页数据时，会在数据源数组尾部新增新获取的数据项，从而使得数据源数组长度增大。

```ts
class Article {
  id: string;
  title: string;
  brief: string;

  constructor(id: string, title: string, brief: string) {
    this.id = id;
    this.title = title;
    this.brief = brief;
  }
}

@Entry
@Component
struct ArticleListView {
  @State isListReachEnd: boolean = false;
  @State articleList: Array<Article> = [
    new Article('001', '第1篇文章', '文章简介内容'),
    new Article('002', '第2篇文章', '文章简介内容'),
    new Article('003', '第3篇文章', '文章简介内容'),
    new Article('004', '第4篇文章', '文章简介内容'),
    new Article('005', '第5篇文章', '文章简介内容'),
    new Article('006', '第6篇文章', '文章简介内容')
  ]

  loadMoreArticles() {
    this.articleList.push(new Article('007', '加载的新文章', '文章简介内容'));
  }

  build() {
    Column({ space: 5 }) {
      List() {
        ForEach(this.articleList, (item: Article) => {
          ListItem() {
            ArticleCard({ article: item })
              .margin({ top: 20 })
          }
        }, (item: Article) => item.id)
      }
      .onReachEnd(() => {
        this.isListReachEnd = true;
      })
      .parallelGesture(
        PanGesture({ direction: PanDirection.Up, distance: 80 })
          .onActionStart(() => {
            if (this.isListReachEnd) {
              this.loadMoreArticles();
              this.isListReachEnd = false;
            }
          })
      )
      .padding(20)
      .scrollBar(BarState.Off)
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xF1F3F5)
  }
}

@Component
struct ArticleCard {
  @Prop article: Article;

  build() {
    Row() {
      Image($r('app.media.icon'))
        .width(80)
        .height(80)
        .margin({ right: 20 })

      Column() {
        Text(this.article.title)
          .fontSize(20)
          .margin({ bottom: 8 })
        Text(this.article.brief)
          .fontSize(16)
          .fontColor(Color.Gray)
          .margin({ bottom: 8 })
      }
      .alignItems(HorizontalAlign.Start)
      .width('80%')
      .height('100%')
    }
    .padding(20)
    .borderRadius(12)
    .backgroundColor('#FFECECEC')
    .height(120)
    .width('100%')
    .justifyContent(FlexAlign.SpaceBetween)
  }
}
```

初始运行效果（左图）和手势上滑加载后效果（右图）如下图所示。

**图6**  数据源数组项变化案例运行效果图  
![ForEach-DataSourceArrayChange](figures/ForEach-DataSourceArrayChange.png)

本示例中，ArticleCard组件是ArticleListView组件的子组件，通过@Prop传入Article对象渲染展示文章卡片。

### 数据源数组项子属性变化

当数据源的数组项为对象数据类型，并且只修改某个数组项的属性值时，由于数据源为复杂数据类型，ArkUI框架无法监听到`@State`装饰器修饰的数据源数组项的属性变化，从而无法触发`ForEach`的重新渲染。为实现`ForEach`重新渲染，需要结合`@Observed`和`@ObjectLink`装饰器使用。例如，在文章列表卡片上点击“点赞”按钮，从而修改文章的点赞数量。

```ts
@Observed
class Article {
  id: string;
  title: string;
  brief: string;
  isLiked: boolean;
  likesCount: number;

  constructor(id: string, title: string, brief: string, isLiked: boolean, likesCount: number) {
    this.id = id;
    this.title = title;
    this.brief = brief;
    this.isLiked = isLiked;
    this.likesCount = likesCount;
  }
}

@Entry
@Component
struct ArticleListView {
  @State articleList: Array<Article> = [
    new Article('001', '第0篇文章', '文章简介内容', false, 100),
    new Article('002', '第1篇文章', '文章简介内容', false, 100),
    new Article('003', '第2篇文章', '文章简介内容', false, 100),
    new Article('004', '第4篇文章', '文章简介内容', false, 100),
    new Article('005', '第5篇文章', '文章简介内容', false, 100),
    new Article('006', '第6篇文章', '文章简介内容', false, 100),
  ];

  build() {
    List() {
      ForEach(this.articleList, (item: Article) => {
        ListItem() {
          ArticleCard({
            article: item
          })
            .margin({ top: 20 })
        }
      }, (item: Article) => item.id)
    }
    .padding(20)
    .scrollBar(BarState.Off)
    .backgroundColor(0xF1F3F5)
  }
}

@Component
struct ArticleCard {
  @ObjectLink article: Article;

  handleLiked() {
    this.article.isLiked = !this.article.isLiked;
    this.article.likesCount = this.article.isLiked ? this.article.likesCount + 1 : this.article.likesCount - 1;
  }

  build() {
    Row() {
      Image($r('app.media.icon'))
        .width(80)
        .height(80)
        .margin({ right: 20 })

      Column() {
        Text(this.article.title)
          .fontSize(20)
          .margin({ bottom: 8 })
        Text(this.article.brief)
          .fontSize(16)
          .fontColor(Color.Gray)
          .margin({ bottom: 8 })

        Row() {
          Image(this.article.isLiked ? $r('app.media.iconLiked') : $r('app.media.iconUnLiked'))
            .width(24)
            .height(24)
            .margin({ right: 8 })
          Text(this.article.likesCount.toString())
            .fontSize(16)
        }
        .onClick(() => this.handleLiked())
        .justifyContent(FlexAlign.Center)
      }
      .alignItems(HorizontalAlign.Start)
      .width('80%')
      .height('100%')
    }
    .padding(20)
    .borderRadius(12)
    .backgroundColor('#FFECECEC')
    .height(120)
    .width('100%')
    .justifyContent(FlexAlign.SpaceBetween)
  }
}
```

上述代码的初始运行效果（左图）和点击第1个文章卡片上的点赞图标后的运行效果（右图）如下图所示。

**图7** 数据源数组项子属性变化案例运行效果图  
![ForEach-DataSourceArraySubpropertyChange](figures/ForEach-DataSourceArraySubpropertyChange.png)

在本示例中，`Article`类被`@Observed`装饰器修饰。父组件`ArticleListView`传入`Article`对象实例给子组件`ArticleCard`，子组件使用`@ObjectLink`装饰器接收该实例。

- 当点击第1个文章卡片上的点赞图标时，会触发`ArticleCard`组件的`handleLiked`函数。该函数修改第1个卡片对应组件里`article`实例的`isLiked`和`likesCount`属性值。
- 由于子组件`ArticleCard`中的`article`使用了`@ObjectLink`装饰器，父子组件共享同一份`article`数据。因此，父组件中`articleList`的第1个数组项的`isLiked`和`likedCounts`数值也会同步修改。
- 当父组件监听到数据源数组项属性值变化时，会触发`ForEach`重新渲染。
- 在此处，`ForEach`键值生成规则为数组项的`id`属性值。当`ForEach`遍历新数据源时，数组项的`id`均没有变化，不会新建组件。
- 渲染第1个数组项对应的`ArticleCard`组件时，读取到的`isLiked`和`likesCount`为修改后的新值。

## 使用建议

- 尽量避免在最终的键值生成规则中包含数据项索引`index`，以防止出现[渲染结果非预期](#渲染结果非预期)和[渲染性能降低](#渲染性能降低)。如果业务确实需要使用`index`，例如列表需要通过`index`进行条件渲染，开发者需要接受`ForEach`在改变数据源后重新创建组件所带来的性能损耗。
- 为满足键值的唯一性，对于对象数据类型，建议使用对象数据中的唯一`id`作为键值。
- 基本数据类型的数据项没有唯一`ID`属性。如果使用基本数据类型本身作为键值，必须确保数组项无重复。因此，对于数据源会发生变化的场景，建议将基本数据类型数组转化为具备唯一`ID`属性的对象数据类型数组，再使用`ID`属性作为键值生成规则。

## 不推荐案例

开发者在使用ForEach的过程中，若对于键值生成规则的理解不够充分，可能会出现错误的使用方式。错误使用一方面会导致功能层面问题，例如[渲染结果非预期](#渲染结果非预期)，另一方面会导致性能层面问题，例如[渲染性能降低](#渲染性能降低)。

### 渲染结果非预期

在本示例中，通过设置`ForEach`的第三个参数`KeyGenerator`函数，自定义键值生成规则为数据源的索引`index`的字符串类型值。当点击父组件`Parent`中“在第1项后插入新项”文本组件后，界面会出现非预期的结果。

```ts
@Entry
@Component
struct Parent {
  @State simpleList: Array<string> = ['one', 'two', 'three'];

  build() {
    Column() {
      Button() {
        Text('在第1项后插入新项').fontSize(30)
      }
      .onClick(() => {
        this.simpleList.splice(1, 0, 'new item');
      })

      ForEach(this.simpleList, (item: string) => {
        ChildItem({ item: item })
      }, (item: string, index: number) => index.toString())
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
    .backgroundColor(0xF1F3F5)
  }
}

@Component
struct ChildItem {
  @Prop item: string;

  build() {
    Text(this.item)
      .fontSize(30)
  }
}
```

上述代码的初始渲染效果（左图）和点击“在第1项后插入新项”文本组件后的渲染效果（右图）如下图所示。

图8  渲染结果非预期运行效果图  
![ForEach-UnexpectedRenderingResult](figures/ForEach-UnexpectedRenderingResult.gif)

`ForEach`在首次渲染时，创建的键值依次为"0"、"1"、"2"。

插入新项后，数据源`simpleList`变为`['one','new item','two','three']`，框架监听到`@State`装饰的数据源长度变化触发`ForEach`重新渲染。

`ForEach`依次遍历新数据源，遍历数据项"one"时生成键值"0"，存在相同键值，因此不创建新组件。继续遍历数据项"new item"时生成键值"1"，存在相同键值，因此不创建新组件。继续遍历数据项"two"生成键值"2"，存在相同键值，因此不创建新组件。最后遍历数据项"three"时生成键值"3"，不存在相同键值，创建内容为"three"的新组件并渲染。

从以上可以看出，当最终键值生成规则包含`index`时，期望的界面渲染结果为`['one', 'new item', 'two', 'three']`，而实际的渲染结果为`['one', 'two', 'three', 'three']`，渲染结果不符合开发者预期。因此，开发者在使用`ForEach`时应尽量避免最终键值生成规则中包含`index`。

### 渲染性能降低

在本示例中，`ForEach`的第三个参数`KeyGenerator`函数处于缺省状态。根据上述[键值生成规则](#键值生成规则)，此例使用框架默认的键值生成规则，即最终键值为字符串`index + '__' + JSON.stringify(item)`。当点击“在第1项后插入新项”文本组件后，`ForEach`将需要为第2个数组项以及其后的所有项重新创建组件。

```ts
@Entry
@Component
struct Parent {
  @State simpleList: Array<string> = ['one', 'two', 'three'];

  build() {
    Column() {
      Button() {
        Text('在第1项后插入新项').fontSize(30)
      }
      .onClick(() => {
        this.simpleList.splice(1, 0, 'new item');
        console.log(`[onClick]: simpleList is ${JSON.stringify(this.simpleList)}`);
      })

      ForEach(this.simpleList, (item: string) => {
        ChildItem({ item: item })
      })
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
    .backgroundColor(0xF1F3F5)
  }
}

@Component
struct ChildItem {
  @Prop item: string;

  aboutToAppear() {
    console.log(`[aboutToAppear]: item is ${this.item}`);
  }

  build() {
    Text(this.item)
      .fontSize(50)
  }
}
```

以上代码的初始渲染效果（左图）和点击"在第1项后插入新项"文本组件后的渲染效果（右图）如下所示。

图9  渲染性能降低案例运行效果图  
![ForEach-RenderPerformanceDecrease](figures/ForEach-RenderPerformanceDecrease.gif)

点击“在第1项后插入新项”文本组件后，IDE的日志打印结果如下所示。

图 10  渲染性能降低案例日志打印图  
![ForEach-RenderPerformanceDecreaseLogs](figures/ForEach-RenderPerformanceDecreaseLogs.png)

插入新项后，`ForEach`为`new item`、 `two`、 `three`三个数组项创建了对应的组件`ChildItem`，并执行了组件的[`aboutToAppear()`](../reference/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear)生命周期函数。这是因为：

- 在`ForEach`首次渲染时，创建的键值依次为`0__one`、`1__two`、`2__three`。
- 插入新项后，数据源`simpleList`变为`['one', 'new item', 'two', 'three']`，ArkUI框架监听到`@State`装饰的数据源长度变化触发`ForEach`重新渲染。
- `ForEach`依次遍历新数据源，遍历数据项`one`时生成键值`0__one`，键值已存在，因此不创建新组件。继续遍历数据项`new item`时生成键值`1__new item`，不存在相同键值，创建内容为`new item`的新组件并渲染。继续遍历数据项`two`生成键值`2__two`，不存在相同键值，创建内容为`two`的新组件并渲染。最后遍历数据项`three`时生成键值`3__three`，不存在相同键值，创建内容为`three`的新组件并渲染。

尽管此示例中界面渲染的结果符合预期，但每次插入一条新数组项时，`ForEach`都会为从该数组项起后面的所有数组项全部重新创建组件。当数据源数据量较大或组件结构复杂时，由于组件无法得到复用，将导致性能体验不佳。因此，除非必要，否则不推荐将第三个参数`KeyGenerator`函数处于缺省状态，以及在键值生成规则中包含数据项索引`index`。
