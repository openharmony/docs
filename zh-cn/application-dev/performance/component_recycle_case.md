#  组件复用性能优化指导

## 概述

在滑动场景下，常常会对同一类自定义组件的实例进行频繁的创建与销毁。此时可以考虑通过组件复用减少频繁创建与销毁的能耗。组件复用时，可能存在许多影响组件复用效率的操作，本篇文章将重点介绍如何通过**组件复用性能优化四建议**提升复用性能。

组件复用性能优化四建议：

* **减少组件复用的嵌套层级**，如果在复用的自定义组件中再嵌套自定义组件，会存在节点构造的开销，且需要在每个嵌套的子组件中的aboutToReuse方法中实现数据的刷新，造成耗时。
* **优化状态管理，精准控制组件刷新范围**，在复用的场景下，需要控制状态变量的刷新范围，避免扩大刷新范围，降低组件复用的效率。
* **复用组件嵌套结构会变更的场景，使用reuseId标记不同结构的组件构成**，如：使用if else结构来控制组件的创建，会造成组件树结构的大幅变动，降低组件复用的效率。需使用reuseId标记不同的组件结构，提升复用性能。
* **不要使用函数/方法作为复用组件的入参**，复用时会触发组件的构造，如果函数入参中存在耗时操作，会影响复用性能。

## 组件复用原理机制

![组件复用机制图](./figures/component_recycle_case.png)

1. 如上图①中，ListItem N-1滑出可视区域**即将销毁**时，如果标记了@Reusable，就会进入这个自定义组件**所在父组件**的复用缓存区。需注意**在自定义组件首次显示时，不会触发组件复用**。后续创建新组件节点时，会复用缓存区中的节点，节约组件重新创建的时间。尤其是该复用组件具有相同的布局结构，仅有某些数据差异时，通过组件复用可以提高列表页面的加载速度和响应速度。

2. 如上图②中，**复用缓存池是一个Map套Array的数据结构，以reuseId为key**，具有相同reuseId的组件在同一个Array中。如未设置reuseId，则reuseId默认是自定义组件的名字。

3. 如上图③中，发生复用行为时，会自动递归调用复用池中取出的自定义组件的aboutToReuse回调，应用可以在这个时候刷新数据。

   

## 减少组件复用的嵌套层级

在组件复用场景下，过深的自定义组件的嵌套会增加组件复用的使用难度，比如需要逐个实现所有嵌套组件中aboutToReuse回调实现数据更新；因此推荐优先使用@Builder替代自定义组件，减少嵌套层级，利于维护切能提升页面加载速度。正反例如下：

反例：

```ts
@Entry
@Component
struct lessEmbeddedComponent {
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
  }

  build() {
    Column() {
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            OneMomentNoBuilder({moment: moment})
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT)
    }
  }
}

@Reusable
@Component
export struct OneMomentNoBuilder {
  @Prop moment: FriendMoment;
    
  // 无需对@Prop修饰的变量进行aboutToReuse赋值，因为这些变量是由父组件传递给子组件的。如果在子组件中重新赋值这些变量，会导致重用的组件的内容重新触发状态刷新，从而降低组件的复用性能。
  build() {
    ...
    // 在复用组件中嵌套使用自定义组件
    Row() {
        InteractiveButton({
          imageStr: $r('app.media.ic_share'),
          text: $r('app.string.friendMomentsPage_share')
        })
        Blank()
        InteractiveButton({
          imageStr: $r('app.media.ic_thumbsup'),
          text: $r('app.string.friendMomentsPage_thumbsup')
        })
        Blank()
        InteractiveButton({
          imageStr: $r('app.media.ic_message'),
          text: $r('app.string.friendMomentsPage_message')
        })
    }
    ...
  }
}

@Component
export struct InteractiveButton {
  @State imageStr: ResourceStr;
  @State text: ResourceStr;

  // 嵌套的组件中也需要实现aboutToReuse来进行UI的刷新
  aboutToReuse(params: Record<string, Object>): void {
    this.imageStr = params.imageStr as ResourceStr;
    this.text = params.text as ResourceStr;
  }

  build() {
    Row() {
      Image(this.imageStr)
      Text(this.text)
    }
    .alignItems(VerticalAlign.Center)
  }
}

```

上述反例的操作中，在复用的自定义组件中嵌套了新的自定义组件。ArkUI中使用自定义组件时，在build阶段将在在后端FrameNode树创建一个相应的CustomNode节点，在渲染阶段时也会创建对应的RenderNode节点。会造成组件复用下，CustomNode创建和和RenderNod渲染的耗时。且嵌套的自定义组件InteractiveButton，也需要实现aboutToReuse来进行数据的刷新。

优化前，以11号列表项复用过程为例，观察Trace信息，看到该过程中需要逐个实现所有嵌套组件InteractiveButton中aboutToReuse回调，导致复用时间较长，BuildLazyItem耗时7ms。

![noBuilder](./figures/component_recycle_case/noBuilder.png)

正例：

```ts
@Entry
@Component
struct lessEmbeddedComponent {
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
  }

  build() {
    Column() {
      TopBar()
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            OneMoment({moment: moment})
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT)
    }
  }
}

@Reusable
@Component
export struct OneMoment {
  @Prop moment: FriendMoment;

  build() {
    ...
    // 使用@Builder，可以减少自定义组件创建和渲染的耗时
    Row() {
        interactiveButton({
          imageStr: $r('app.media.ic_share'),
          text: $r('app.string.friendMomentsPage_share')
        })
        Blank()
        interactiveButton({
          imageStr: $r('app.media.ic_thumbsup'),
          text: $r('app.string.friendMomentsPage_thumbsup')
        })
        Blank()
        interactiveButton({
          imageStr: $r('app.media.ic_message'),
          text: $r('app.string.friendMomentsPage_message')
        })
    }
    ...
  }
}

class Temp {
  imageStr: ResourceStr = '';
  text: ResourceStr = '';
}

@Builder
export function interactiveButton($$: Temp) {
  Row() {
    // 此处使用$$来进行按引用传递，让@Builder感知到数据变化，进行UI刷新
    Image($$.imageStr)
    Text($$.text)
  }
}
```

上述正例的操作中，在复用的自定义组件中用@Builder来代替了自定义组件。避免了CustomNode节点创建和RenderNode渲染的耗时。

**优化效果**

在正反例中，针对列表滑动场景中单个列表项中的三个交互按钮，反例中采用了自定义组件方式实现，正例中采用了自定义构建函数方式实现。

优化后，11号列表项复用时，不再需要需要逐个实现所有嵌套组件中aboutToReuse回调，BuildLazyItem耗时3ms。可见该示例中，BuildLazyItem优化大约4ms。

![useBuilder](./figures/component_recycle_case/useBuilder.png)

所以，Trace数据证明，优先使用@Builder替代自定义组件，减少嵌套层级，可以利于维护切能提升页面加载速度。

## 优化状态管理，精准控制组件刷新范围使用

### 使用AttributeUpdater精准控制组件属性的刷新，避免组件不必要的属性刷新

复用场景常用在高频的刷新场景，精准控制组件的刷新范围可以有效减少主线程渲染负载，提升滑动性能。正反例如下：

反例：

```ts
@Component
export struct LessEmbeddedComponent {
  aboutToAppear(): void {
    momentData.getFriendMomentFromRawfile();
  }

  build() {
    Column() {
      Text('use nothing')
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            OneMomentNoModifier({ color: moment.color })
              .onClick(() => {
                console.log(`my id is ${moment.id}`);
              })
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .width("100%")
      .height("100%")
      .cachedCount(5)
    }
  }
}

@Reusable
@Component
export struct OneMomentNoModifier {
  @State color: string | number | Resource = "";

  aboutToReuse(params: Record<string, Object>): void {
    this.color = params.color as number;
  }

  build() {
    Column() {
      Text('这是标题')
        Text('这是内部文字')
          .fontColor(this.color)// 此处使用属性直接进行刷新，会造成Text所有属性都刷新
          .textAlign(TextAlign.Center)
          .fontStyle(FontStyle.Normal)
          .fontSize(13)
          .lineHeight(30)
          .opacity(0.6)
          .margin({ top: 10 })
          .fontWeight(30)
          .clip(false)
          .backgroundBlurStyle(BlurStyle.NONE)
          .foregroundBlurStyle(BlurStyle.NONE)
          .borderWidth(1)
          .borderColor(Color.Pink)
          .borderStyle(BorderStyle.Solid)
          .alignRules({
            'top': { 'anchor': '__container__', 'align': VerticalAlign.Top },
            'left': { 'anchor': 'image', 'align': HorizontalAlign.End }
          })
    }
  }
}
```

上述反例的操作中，通过aboutToReuse对fontColor状态变量更新，进而导致组件的全部属性进行刷新，造成不必要的耗时。因此可以考虑对需要更新的组件的属性，进行精准刷新，避免不必要的重绘和渲染。

![noModifier1](./figures/component_recycle_case/noModifier1.png)

优化前，由`H:ViewPU.viewPropertyHasChanged OneMomentNoModifier color 1`标签可知，OneMomentNoModifier自定义组件下的状态变量color发生变化，与之相关联的子控件数量为1，即有一个子控件发生了标脏，之后Text全部属性会进行了刷新。

此时，`H:CustomNode:BuildRecycle`耗时543μs，`Create[Text]`耗时为4μs。

![noModifier2](./figures/component_recycle_case/noModifier2.png)

![noModifier3](./figures/component_recycle_case/noModifier3.png)

正例：

```typescript
import { AttributeUpdater } from '@ohos.arkui.modifier';

export class MyTextUpdater extends AttributeUpdater<TextAttribute> {
  private color: string | number | Resource = "";

  constructor(color: string | number | Resource) {
    super();
    this.color = color;
  }

  initializeModifier(instance: TextAttribute): void {
    instance.fontColor(this.color); // 差异化更新
  }
}

@Component
export struct UpdaterComponent {
  aboutToAppear(): void {
    momentData.getFriendMomentFromRawfile();
  }

  build() {
    Column() {
      Text('use MyTextUpdater')
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            OneMomentNoModifier({ color: moment.color })
              .onClick(() => {
                console.log(`my id is ${moment.id}`);
              })
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(5)
    }
  }
}

@Reusable
@Component
export struct OneMomentNoModifier {
  color: string | number | Resource = "";
  textUpdater: MyTextUpdater | null = null;

  aboutToAppear(): void {
    this.textUpdater = new MyTextUpdater(this.color);
  }

  aboutToReuse(params: Record<string, Object>): void {
    this.color = params.color as string;
    this.textUpdater?.attribute?.fontColor(this.color);
  }

  build() {
    Column() {
      Text('这是标题')
      Text('这是内部文字')
        .attributeModifier(this.textUpdater) // 采用attributeUpdater来对需要更新的fontColor属性进行精准刷新，避免不必要的属性刷新。
        .textAlign(TextAlign.Center)
        .fontStyle(FontStyle.Normal)
        .fontSize(13)
        .lineHeight(30)
        .opacity(0.6)
        .margin({ top: 10 })
        .fontWeight(30)
        .clip(false)
        .backgroundBlurStyle(BlurStyle.NONE)
        .foregroundBlurStyle(BlurStyle.NONE)
        .borderWidth(1)
        .borderColor(Color.Pink)
        .borderStyle(BorderStyle.Solid)
        .alignRules({
          'top': { 'anchor': '__container__', 'align': VerticalAlign.Top },
          'left': { 'anchor': 'image', 'align': HorizontalAlign.End }
        })
    }
  }
}
```

上述正例的操作中，通过AttributeUpdater来对Text组件需要刷新的属性进行精准刷新，避免Text其它不需要更改的属性的刷新。  

![useUpdater1](./figures/component_recycle_case/useUpdater1.png)

优化后，在`H:aboutToReuse`标签下没有`H:ViewPU.viewPropertyHasChanged`标签，后续也没有`Create[Text]`标签。此时，`H:CustomNode:BuildRecycle`耗时415μs。

**优化效果**

在正反例中，针对列表滑动场景中，单个列表项中Text组件字体颜色属性的修改，反例中采用了普通组件属性刷新方式实现，正例中采用了AttributeUpdater动态属性设置方式实现。

优化后的`H:CustomNode:BuildRecycle OneMomentNoModifier`的耗时，如下表所示：

| 次数 | 反例：使用@State(单位μs) | 正例：使用AttributeUpdater(单位μs) |
| --- | --- | --- |
| 1 | 357 | 338 |
| 2 | 903 | 494 |
| 3 | 543 | 415 |
| 4 | 543 | 451 |
| 5 | 692 | 509 |
| 平均 | 607 | 441 |

> 不同设备和场景都会对数据有影响，该数据仅供参考。

所以，Trace数据证明，精准控制组件的刷新范围可以有效减少主线程渲染负载，提升滑动性能。

> 因为示例中仅涉及一个Text组件的属性更新，所以优化时间绝对值较小。如果涉及组件较多，性能提升会更明显。

### 使用@Link/@ObjectLink替代@Prop减少深拷贝，提升组件创建速度

在父子组件数据同步时，如果仅仅是需要父组件向子组件同步数据，不存在修改子组件的数据变化不同步给父组件的需求。建议使用@Link/@ObjectLink替代@Prop，@Prop在装饰变量时会进行深拷贝，在拷贝的过程中除了基本类型、Map、Set、Date、Array外，都会丢失类型。正反例如下：

反例：

```ts
@Entry
@Component
struct lessEmbeddedComponent {
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
  }

  build() {
    Column() {
      TopBar()
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            OneMoment({moment: moment})
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT)
    }
  }
}

@Reusable
@Component
export struct OneMoment {
  @Prop moment: FriendMoment;
    
  build() {
    Column() {
      ...
      Text(`${this.moment.userName}`)
      ...
    }
  }
}

export const momentData: FriendMomentsData = new FriendMomentsData(); 
    
export class FriendMoment {
  id: string; 
  userName: string; 
  avatar: string; 
  text: string; 
  size: number; 
  image?: string; 

  constructor(id: string, userName: string, avatar: string, text: string, size: number, image?: string) {
    this.id = id;
    this.userName = userName;
    this.avatar = avatar;
    this.text = text;
    this.size = size;
    if (image !== undefined) {
      this.image = image;
    }
  }
}
```

上述反例的操作中，父子组件之间的数据同步用了@Prop来进行，各@Prop装饰的变量在初始化时都在本地拷贝了一份数据。会增加创建时间及内存的消耗，造成性能问题。

优化前，子组件在初始化时都在本地拷贝了一份数据，BuildItem耗时7ms175μs。

![useProp](./figures/component_recycle_case/useProp.png)

正例：

```ts
@Entry
@Component
struct lessEmbeddedComponent {
  @State momentData: FriendMomentsData = new FriendMomentsData();
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
  }

  build() {
    Column() {
      TopBar()
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            OneMoment({moment: moment})
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT)
    }
  }
}

@Reusable
@Component
export struct OneMoment {
  @ObjectLink moment: FriendMoment;
    
  build() {
    Column() {
      ...
      Text(`${this.moment.userName}`)
      ...
    }
  }
}
    
@Observed
export class FriendMoment {
  id: string; 
  userName: string; 
  avatar: string; 
  text: string; 
  size: number; 
  image?: string; 

  constructor(id: string, userName: string, avatar: string, text: string, size: number, image?: string) {
    this.id = id;
    this.userName = userName;
    this.avatar = avatar;
    this.text = text;
    this.size = size;
    if (image !== undefined) {
      this.image = image;
    }
  }
}
```

上述正例的操作中，父子组件之间的数据同步用了@ObjectLink来进行，子组件@ObjectLink包装类把当前this指针注册给父组件，会直接将父组件的数据同步给子组件，实现父子组件数据的双向同步，降低子组件创建时间和内存消耗。

**优化效果**

在正反例中，针对列表滑动场景，反例采用@Prop修饰的变量，来进行父子组件间的数据同步。子组件在初始化时@Prop修饰的变量，都在本地拷贝了一份数据，增加了组件创建的时间；正例采用@ObjectLink来进行父子组件间的数据同步，把当前this指针注册给父组件，减少了组件创建的时间。

优化后，子组件直接同步父组件数据，无需深拷贝，BuildItem耗时缩短为7ms1μs。

![useLink](./figures/component_recycle_case/useLink.png)

所以，Trace数据证明，使用@Link/@ObjectLink替代@Prop减少深拷贝，可以提升组件创建速度。

> **说明：**
>
> 因为示例中仅涉及一个简单对象FriendMoment的深拷贝，所以优化时间绝对值较小。如果涉及变量较多、对象较复杂，性能提升会更明显。

### 避免对@Link/@ObjectLink/@Prop等自动更新的状态变量，在aboutToReuse方法中再进行更新

在父子组件数据同步时，如果子组件已经使用@Link/@ObjectLink/@Prop等会自动同步父子组件数据、且驱动组件刷新的状态变量。不需要再在boutToReuse方法中再进行数据更新，此操作会造成不必要的方法执行和变量更新的耗时。正反例如下：

反例：

```ts
@Entry
@Component
struct LessEmbeddedComponent {
  @State momentData: FriendMomentsData = new FriendMomentsData();
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
  }

  build() {
    Column() {
      TopBar()
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            OneMoment({moment: moment})
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT)
    }
  }
}

@Reusable
@Component
export struct OneMoment {
  // 该类型的状态变量已包含自动刷新功能，不需要再重复进行刷新
  @ObjectLink moment: FriendMoment;

  // 此处aboutToReuse为多余刷新
  aboutToReuse(params: Record<string, Object>): void {
    this.moment.id = (params.moment as FriendMoment).id;
    this.moment.userName = (params.moment as FriendMoment).userName;
    this.moment.avatar = (params.moment as FriendMoment).avatar;
    this.moment.text = (params.moment as FriendMoment).text;
    this.moment.image = (params.moment as FriendMoment).image;
  }
    
  build() {
    Column() {
      ...
      Text(`${this.moment.userName}`)
      ...
    }
  }
}
    
@Observed
export class FriendMoment {
  id: string; 
  userName: string; 
  avatar: string; 
  text: string; 
  size: number; 
  image?: string; 

  constructor(id: string, userName: string, avatar: string, text: string, size: number, image?: string) {
    this.id = id;
    this.userName = userName;
    this.avatar = avatar;
    this.text = text;
    this.size = size;
    if (image !== undefined) {
      this.image = image;
    }
  }
}
```

上述反例的操作中，子组件中moment变量被@ObjectLink修饰，把当前this指针注册给父组件，会直接将父组件的数据同步给子组件，实现数据刷新。重新在aboutToReuse中刷新，如果刷新涉及的变量较多、变量中成员变量复杂，可能会造成较大性能开销。

优化前，由于在复用组件OneMoment的aboutToReuse方法中，对moment变量的各个成员变量进行了刷新，aboutToReuse耗时168μs。

![refresh_auto_fresh_variable](./figures/component_recycle_case/avoid_auto_variable_false_trace.png)

正例：

```ts
@Entry
@Component
struct LessEmbeddedComponent {
  @State momentData: FriendMomentsData = new FriendMomentsData();
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
  }

  build() {
    Column() {
      TopBar()
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            OneMoment({moment: moment})
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT)
    }
  }
}

@Reusable
@Component
export struct OneMoment {
  @ObjectLink moment: FriendMoment;
    
  build() {
    Column() {
      ...
      Text(`${this.moment.userName}`)
      ...
    }
  }
}
    
@Observed
export class FriendMoment {
  id: string; 
  userName: string; 
  avatar: string; 
  text: string; 
  size: number; 
  image?: string; 

  constructor(id: string, userName: string, avatar: string, text: string, size: number, image?: string) {
    this.id = id;
    this.userName = userName;
    this.avatar = avatar;
    this.text = text;
    this.size = size;
    if (image !== undefined) {
      this.image = image;
    }
  }
}
```

上述正例的操作中，子组件中moment变量被@ObjectLink修饰，把当前this指针注册给父组件，会直接将父组件的数据同步给子组件，实现数据刷新。

**优化效果**

在正反例中，针对列表滑动场景，反例中在aboutToReuse方法中，冗余刷新了自动刷新的变量moment中的各个成员变量。正例中，利用@ObjectLink修饰的变量moment自动同步数据的特性，直接进行刷新，不在aboutToReuse方法再进行刷新。

优化后，避免在复用组件OneMoment的aboutToReuse方法中，重复刷新变量moment的各个成员变量，aboutToReuse耗时110μs。

![aovid_refresh_auto_fresh_variable](./figures/component_recycle_case/avoid_auto_vaiable_true_trace.png)

所以，通过上述Trace数据证明，避免在复用组件中，对@Link/@ObjectLink/@Prop等自动更新的状态变量，在aboutToReuse方法中再进行更新。会减少aboutToReuse方法的时间，进而减少复用组件的创建时间。

> **说明：**
>
> 因为示例中仅涉及一个简单变量moment的各成员变量的冗余刷新，所以优化时间绝对值不大。如果涉及变量较多、变量中成员变量复杂，性能提升会更明显。

## 复用组件嵌套结构会变更的场景，使用reuseId标记不同结构的组件构成

在自定义组件复用的场景中，如果使用if/else条件语句来控制布局的结构，会导致在不同逻辑创建不同布局结构嵌套的组件，从而造成组件树结构的不同。此时我们应该使用reuseId来区分不同结构的组件，确保系统能够根据reuseId缓存各种结构的组件，提升复用性能。正反例如下：

反例：

```ts
@Entry
@Component
struct withoutReuseId {
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
  }

  build() {
    Column() {
      TopBar()
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            // 此处的复用组件，只有一个reuseId，为组件的名称。但是该复用组件中又存在if else重新创建组件的逻辑
            TrueOneMoment({ moment: moment, sum: this.sum, fontSize: moment.size })
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT) 
    }
  }
}

@Reusable
@Component
export struct TrueOneMoment {
  @Prop moment: FriendMoment;
  @State sum: number = 0;
  @State fontSize: number | Resource = $r('app.integer.list_history_userText_fontSize');

  aboutToReuse(params: ESObject): void {
    this.fontSize = params.fontSize as number;
    this.sum = params.sum as number;
  }

  build() {
    Column() {
      if (this.moment.image) {
        FalseOneMoment({ moment: this.moment, sum: this.sum, fontSize: this.moment.size })
      } else {
        OneMoment({ moment: this.moment, sum: this.sum, fontSize: this.moment.size })
      }
    }
    .width('100%')
  }
}
```

上述反例的操作中，在一个reuseId标识的组件TrueOneMoment中，通过if来控制其中的组件走不同的分支，选择是否创建FalseOneMoment或OneMoment组件。导致更新if分支时仍然可能走删除重创的逻辑（此处BuildItem重新创建了OneMoment组件）。考虑采用根据不同的分支设置不同的reuseId来提高复用的性能。

优化前，15号列表项复用时长为10ms左右，且存在自定义组件创建的情况。

![noReuseId](./figures/component_recycle_case/noReuseId.png)

正例：

```ts
@Entry
@Component
struct withoutReuseId {
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
  }

  build() {
    Column() {
      TopBar()
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            // 使用不同的reuseId标记，保证TrueOneMoment中各个子组件在复用时，不重新创建
            TrueOneMoment({ moment: moment, sum: this.sum, fontSize: moment.size })
              .reuseId((moment.image !=='' ?'withImage' : 'noImage'))
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT) 
    }
  }
}

@Reusable
@Component
export struct TrueOneMoment {
  @Prop moment: FriendMoment;
  @State sum: number = 0;
  @State fontSize: number | Resource = $r('app.integer.list_history_userText_fontSize');

  aboutToReuse(params: ESObject): void {
    this.fontSize = params.fontSize as number;
    this.sum = params.sum as number;
  }

  build() {
    Column() {
      if (this.moment.image) {
        FalseOneMoment({ moment: this.moment, sum: this.sum, fontSize: this.moment.size })
      } else {
        OneMoment({ moment: this.moment, sum: this.sum, fontSize: this.moment.size })
      }
    }
    .width('100%')
  }
}   
```

上述正例的操作中，通过不同的reuseId来标识需要复用的组件，省去走if删除重创的逻辑，提高组件复用的效率和性能。

**优化效果**

针对列表滑动场景中，复用的组件中又存在多个自定义组件。通过if进行条件渲染，存在不同逻辑创建不同布局结构的组件的情况。反例中多个复用组件使用相同的复用标识reuseId，正例中采用不同的复用标识reuseId区分不同结构的自定义组件。

优化后，15号列表项复用时长缩短为3ms左右，不存在自定义组件的创建。

![ReuseId](./figures/component_recycle_case/ReuseId.png)

所以，Trace数据证明，针对不同逻辑创建不同布局结构嵌套的组件的情况，通过使用reuseId来区分不同结构的组件，能减少删除重创的逻辑，提高组件复用的效率和性能。

## 避免使用函数/方法作为复用组件创建时的入参

由于在组件复用的场景下，每次复用都需要重新创建组件关联的数据对象，导致重复执行入参中的函数来获取入参结果。如果函数中存在耗时操作，会严重影响性能。正反例如下：

反例：

```ts
@Entry
@Component
struct withFuncParam {
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
  }
  // 真实场景的函数中可能存在未知的耗时操作逻辑，此处用循环函数模拟耗时操作
  countAndReturn(): number {
    let temp: number = 0;
    for (let index = 0; index < 100000; index++) {
      temp += index;
    }
    return temp;
  }

  build() {
    Column() {
      TopBar()
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            OneMoment({
              moment: moment,
              sum: this.countAndReturn()
            })
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT) 
    }
  }
}

@Reusable
@Component
export struct OneMoment {
  @Prop moment: FriendMoment;
  @State sum: number = 0;

  aboutToReuse(params: Record<string, Object>): void {
    this.sum = params.sum as number;
  }

  build() {
    Column() {
      ...
      Text(`${this.moment.userName} （${this.moment.id} / ${this.sum}）`)
      ...
    }
  }
}
```

上述反例的操作中，复用的子组件参数sum是通过耗时函数生成。该函数在每次组件复用时都需要执行，会造成性能问题，甚至是列表滑动过程中的卡顿丢帧现象。

优化前，aboutToReuse中需要重复执行入参中的函数来获取入参结果，导致耗时较长为4ms。

![FuncParam](./figures/component_recycle_case/FuncParam.png)

正例：

```ts
@Entry
@Component
struct withFuncParam {
  @State sum: number = 0;
    
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
    // 执行该异步函数
    this.countAndRecord();
  }
  // 真实场景的函数中可能存在未知的耗时操作逻辑，此处用循环函数模拟耗时操作
  async countAndRecord() {
    let temp: number = 0;
    for (let index = 0; index < 100000; index++) {
      temp += index;
    }
    // 将结果放入状态变量中
    this.sum = temp;
  }

  build() {
    Column() {
      TopBar()
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            // 子组件的传参通过状态变量进行
            OneMoment({
              moment: moment,
              sum: this.sum
            })
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT) 
    }
  }
}

@Reusable
@Component
export struct OneMoment {
  @Prop moment: FriendMoment;
  @State sum: number = 0;

  aboutToReuse(params: Record<string, Object>): void {
    this.sum = params.sum as number;
  }

  build() {
    Column() {
      ...
      Text(`${this.moment.userName} （${this.moment.id} / ${this.sum}）`)
      ...
    }
  }
}
```

上述正例的操作中，通过耗时函数countAndRecord生成的结果不变，可以将其放到页面初始渲染时执行一次，将结果赋值给this.sum。在复用组件的参数传递时，通过this.sum来进行。

**优化效果**

针对列表滑动场景，单个列表项中的一个Text组件，需要依赖复用组件创建时的入参，反例中入参直接传入函数，正例中入参通过状态变量传递。

优化后，aboutToReuse中只是通过变量传参，无需重复执行计算函数，耗时缩短为2ms。

![noFuncParam](./figures/component_recycle_case/noFuncParam.png)

所以，Trace数据证明，避免使用函数/方法作为复用组件创建时的入参，可以减少重复执行入参中的函数所带来的性能消耗。
