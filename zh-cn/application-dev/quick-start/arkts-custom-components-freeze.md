# 自定义组件冻结功能

自定义组件处于非激活状态时，状态变量将不响应更新，即@Watch不会调用，状态变量关联的节点不会刷新。通过freezeWhenInactive属性来决定是否使用冻结功能，不传参数时默认不使用。支持的场景有：页面路由，TabContent，LazyForEach，Navigation。


> **说明：**
>
> 从API version 11开始，支持自定义组件冻结功能。

## 当前支持的场景

### 页面路由

- 当页面A调用router.pushUrl接口跳转到页面B时，页面A为隐藏不可见状态，此时如果更新页面A中的状态变量，不会触发页面A刷新。


页面A：

```ts
import { router } from '@kit.ArkUI';

@Entry
@Component({ freezeWhenInactive: true })
struct FirstTest {
  @StorageLink('PropA') @Watch("first") storageLink: number = 47;

  first() {
    console.info("first page " + `${this.storageLink}`)
  }

  build() {
    Column() {
      Text(`From fist Page ${this.storageLink}`).fontSize(50)
      Button('first page storageLink + 1').fontSize(30)
        .onClick(() => {
          this.storageLink += 1
        })
      Button('go to next page').fontSize(30)
        .onClick(() => {
          router.pushUrl({ url: 'pages/second' })
        })
    }
  }
}
```

页面B：

```ts
import { router } from '@kit.ArkUI';

@Entry
@Component({ freezeWhenInactive: true })
struct SecondTest {
  @StorageLink('PropA') @Watch("second") storageLink2: number = 1;

  second() {
    console.info("second page: " + `${this.storageLink2}`)
  }

  build() {
    Column() {

      Text(`second Page ${this.storageLink2}`).fontSize(50)
      Button('Change Divider.strokeWidth')
        .onClick(() => {
          router.back()
        })

      Button('second page storageLink2 + 2').fontSize(30)
        .onClick(() => {
          this.storageLink2 += 2
        })

    }
  }
}
```

在上面的示例中：

1.点击页面A中的Button “first page storageLink + 1”，storageLink状态变量改变，@Watch中注册的方法first会被调用。

2.通过router.pushUrl({url: 'pages/second'})，跳转到页面B，页面A隐藏，状态由active变为inactive。

3.点击页面B中的Button “this.storageLink2 += 2”，只回调页面B@Watch中注册的方法second，因为页面A的状态变量此时已被冻结。

4.点击“back”，页面B被销毁，页面A的状态由inactive变为active，重新刷新在inactive时被冻结的状态变量，页面A@Watch中注册的方法first被再次调用。


### TabContent

- 对Tabs中当前不可见的TabContent进行冻结，不会触发组件的更新。

- 需要注意的是：在首次渲染的时候，Tab只会创建当前正在显示的TabContent，当切换全部的TabContent后，TabContent才会被全部创建。

```ts
@Entry
@Component
struct TabContentTest {
  @State @Watch("onMessageUpdated") message: number = 0;
  private data: number[] = [0, 1]

  onMessageUpdated() {
    console.info(`TabContent message callback func ${this.message}`)
  }

  build() {
    Row() {
      Column() {
        Button('change message').onClick(() => {
          this.message++
        })

        Tabs() {
          ForEach(this.data, (item: number) => {
            TabContent() {
              FreezeChild({ message: this.message, index: item })
            }.tabBar(`tab${item}`)
          }, (item: number) => item.toString())
        }
      }
      .width('100%')
    }
    .height('100%')
  }
}

@Component({ freezeWhenInactive: true })
struct FreezeChild {
  @Link @Watch("onMessageUpdated") message: number
  private index: number = 0

  onMessageUpdated() {
    console.info(`FreezeChild message callback func ${this.message}, index: ${this.index}`)
  }

  build() {
    Text("message" + `${this.message}, index: ${this.index}`)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
  }
}
```

在上面的示例中：

1.点击“change message”更改message的值，当前正在显示的TabContent组件中的@Watch中注册的方法onMessageUpdated被触发。

2.点击“two”切换到另外的TabContent，TabContent状态由inactive变为active，对应的@Watch中注册的方法onMessageUpdated被触发。 

3.再次点击“change message”更改message的值，仅当前显示的TabContent子组件中的@Watch中注册的方法onMessageUpdated被触发。

![TabContent.gif](figures/TabContent.gif)


### LazyForEach

- 对LazyForEach中缓存的自定义组件进行冻结，不会触发组件的更新。

```ts
// Basic implementation of IDataSource to handle data listener
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  // 该方法为框架侧调用，为LazyForEach组件向其数据源处添加listener监听
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  // 该方法为框架侧调用，为对应的LazyForEach组件在数据源处去除listener监听
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  // 通知LazyForEach组件需要重载所有子组件
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  // 通知LazyForEach组件需要在index对应索引处添加子组件
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  // 通知LazyForEach组件在index对应索引处数据有变化，需要重建该子组件
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  // 通知LazyForEach组件需要在index对应索引处删除该子组件
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Entry
@Component
struct LforEachTest {
  private data: MyDataSource = new MyDataSource();
  @State @Watch("onMessageUpdated") message: number = 0;

  onMessageUpdated() {
    console.info(`LazyforEach message callback func ${this.message}`)
  }

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    Column() {
      Button('change message').onClick(() => {
        this.message++
      })
      List({ space: 3 }) {
        LazyForEach(this.data, (item: string) => {
          ListItem() {
            FreezeChild({ message: this.message, index: item })
          }
        }, (item: string) => item)
      }.cachedCount(5).height(500)
    }

  }
}

@Component({ freezeWhenInactive: true })
struct FreezeChild {
  @Link @Watch("onMessageUpdated") message: number;
  private index: string = "";

  aboutToAppear() {
    console.info(`FreezeChild aboutToAppear index: ${this.index}`)
  }

  onMessageUpdated() {
    console.info(`FreezeChild message callback func ${this.message}, index: ${this.index}`)
  }

  build() {
    Text("message" + `${this.message}, index: ${this.index}`)
      .width('90%')
      .height(160)
      .backgroundColor(0xAFEEEE)
      .textAlign(TextAlign.Center)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }
}
```

在上面的示例中：

1.点击“change message”更改message的值，当前正在显示的ListItem中的子组件@Watch中注册的方法onMessageUpdated被触发。缓存节点@Watch中注册的方法不会被触发。（如果不加组件冻结，当前正在显示的ListItem和cachecount缓存节点@Watch中注册的方法onMessageUpdated都会触发watch回调。）

2.List区域外的ListItem滑动到List区域内，状态由inactive变为active，对应的@Watch中注册的方法onMessageUpdated被触发。

3.再次点击“change message”更改message的值，仅有当前显示的ListItem中的子组件@Watch中注册的方法onMessageUpdated被触发。

![FrezzeLazyforEach.gif](figures/FrezzeLazyforEach.gif)

### Navigation

- 当NavDestination不可见时，会对其子自定义组件设置成非激活态，不会触发组件的刷新。当返回该页面时，其子自定义组件重新恢复成激活态，触发@Watch回调进行刷新。

- 在下面例子中，NavigationContentMsgStack会被设置成非激活态，将不再响应状态变量的变化，也不会触发组件刷新。

```ts
@Entry
@Component
struct MyNavigationTestStack {
  @Provide('pageInfo') pageInfo: NavPathStack = new NavPathStack();
  @State @Watch("info") message: number = 0;
  @State logNumber: number = 0;

  info() {
    console.info(`freeze-test MyNavigation message callback ${this.message}`);
  }

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      pageOneStack({ message: this.message, logNumber: this.logNumber })
    } else if (name === 'pageTwo') {
      pageTwoStack({ message: this.message, logNumber: this.logNumber })
    } else if (name === 'pageThree') {
      pageThreeStack({ message: this.message, logNumber: this.logNumber })
    }
  }

  build() {
    Column() {
      Button('change message')
        .onClick(() => {
          this.message++;
        })
      Navigation(this.pageInfo) {
        Column() {
          Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
            .width('80%')
            .height(40)
            .margin(20)
            .onClick(() => {
              this.pageInfo.pushPath({ name: 'pageOne' }); //将name指定的NavDestination页面信息入栈
            })
        }
      }.title('NavIndex')
      .navDestination(this.PageMap)
      .mode(NavigationMode.Stack)
    }
  }
}

@Component
struct pageOneStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @State index: number = 1;
  @Link message: number;
  @Link logNumber: number;

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack({ message: this.message, index: this.index, logNumber: this.logNumber })
        Text("cur stack size:" + `${this.pageInfo.size()}`)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageTwo', null);
          })
        Button('Back Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pop();
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct pageTwoStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @State index: number = 2;
  @Link message: number;
  @Link logNumber: number;

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack({ message: this.message, index: this.index, logNumber: this.logNumber })
        Text("cur stack size:" + `${this.pageInfo.size()}`)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageThree', null);
          })
        Button('Back Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pop();
          })
      }.width('100%').height('100%')
    }.title('pageTwo')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct pageThreeStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @State index: number = 3;
  @Link message: number;
  @Link logNumber: number;

  build() {
    NavDestination() {
      Column() {
        NavigationContentMsgStack({ message: this.message, index: this.index, logNumber: this.logNumber })
        Text("cur stack size:" + `${this.pageInfo.size()}`)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageOne', null);
          })
        Button('Back Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pop();
          })
      }.width('100%').height('100%')
    }.title('pageThree')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component({ freezeWhenInactive: true })
struct NavigationContentMsgStack {
  @Link @Watch("info") message: number;
  @Link index: number;
  @Link logNumber: number;

  info() {
    console.info(`freeze-test NavigationContent message callback ${this.message}`);
    console.info(`freeze-test ---- called by content ${this.index}`);
    this.logNumber++;
  }

  build() {
    Column() {
      Text("msg:" + `${this.message}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
      Text("log number:" + `${this.logNumber}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

在上面的示例中：

1.点击“change message”更改message的值，当前正在显示的MyNavigationTestStack组件中的@Watch中注册的方法info被触发。

2.点击“Next Page”切换到PageOne，创建pageOneStack节点。

3.再次点击“change message”更改message的值，仅pageOneStack中的NavigationContentMsgStack子组件中的@Watch中注册的方法info被触发。

4.再次点击“Next Page”切换到PageTwo，创建pageTwoStack节点。

5.再次点击“change message”更改message的值，仅pageTwoStack中的NavigationContentMsgStack子组件中的@Watch中注册的方法info被触发。

6.再次点击“Next Page”切换到PageThree，创建pageThreeStack节点。

7.再次点击“change message”更改message的值，仅pageThreeStack中的NavigationContentMsgStack子组件中的@Watch中注册的方法info被触发。

8.点击“Back Page”回到PageTwo，此时，仅pageTwoStack中的NavigationContentMsgStack子组件中的@Watch中注册的方法info被触发。

9.再次点击“Back Page”回到PageOne，此时，仅pageOneStack中的NavigationContentMsgStack子组件中的@Watch中注册的方法info被触发。

10.再次点击“Back Page”回到初始页，此时，无任何触发。

![navigation-freeze.gif](figures/navigation-freeze.gif)