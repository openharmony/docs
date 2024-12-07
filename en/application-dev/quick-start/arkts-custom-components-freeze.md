# Freezing a Custom Component

Freezing a custom component is designed to optimize the performance of complex UI pages, especially for scenarios where multiple page stacks, long lists, or grid layouts are involved. In these cases, when the state variable is bound to multiple UI components, the change of the state variables may trigger the re-render of a large number of UI components, resulting in frame freezing and response delay. To improve the UI re-render performance, you can try to use the custom component freezing function.

Principles of freezing a component are as follows:
1. Setting the **freezeWhenInactive** attribute to activate the component freezing mechanism.
2. After this function is enabled, the system re-renders only the activated custom components. In this way, the UI framework can narrow down the re-render scope to the (activated) custom components that are visible to users, improving the re-render efficiency in complex UI scenarios.
3. When an inactive custom component turns into the active state, the state management framework performs necessary re-render operations on the custom component to ensure that the UI is correctly displayed.

In short, component freezing aims to optimize UI re-render performance on complex UIs. When there are multiple invisible custom components, such as multiple page stacks, long lists, or grids, you can freeze the components to re-render visible custom components as required, and the re-render of the invisible custom components is delayed until they become visible.

Note that the active or inactive state of a component is not equivalent to its visibility. Component freezing applies only to the following scenarios:

1. Page routing: The current top page of the navigation stack is in the active state, and the non-top invisible page is in the inactive state.
2. TabContent: Only the custom component in the currently displayed TabContent is in the active state.
3. LazyForEach: Only the custom component in the currently displayed LazyForEach is in the active state, and the component of the cache node is in the inactive state.
4. Navigation: Only the custom component in the currently displayed NavDestination is in the active state.
5. Component reuse: The component that enters the reuse pool is in the inactive state, and the node attached from the reuse pool is in the active state.
In other scenarios, for example, masked components in a stack layout are not considered to be in an inactive state although they are invisible. Therefore, component freezing cannot be applied to these components.


> **NOTE**
>
> Custom component freezing is supported since API version 11.

## Use Scenarios

### Page Routing

When page 1 calls the **router.pushUrl** API to jump to page 2, page 1 is hidden and invisible. In this case, if the state variable on page 1 is updated, page 1 is not re-rendered.
For details, see the following.
![freezeInPage](./figures/freezeInPage.png)

Page 1

```ts
import { router } from '@kit.ArkUI';

@Entry
@Component({ freezeWhenInactive: true })
struct Page1 {
  @StorageLink('PropA') @Watch("first") storageLink: number = 47;

  first() {
    console.info("first page " + `${this.storageLink}`)
  }

  build() {
    Column() {
      Text(`From first Page ${this.storageLink}`).fontSize(50)
      Button('first page storageLink + 1').fontSize(30)
        .onClick(() => {
          this.storageLink += 1
        })
      Button('go to next page').fontSize(30)
        .onClick(() => {
          router.pushUrl({ url: 'pages/Page2' })
        })
    }
  }
}
```

Page 2

```ts
import { router } from '@kit.ArkUI';

@Entry
@Component({ freezeWhenInactive: true })
struct Page2 {
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

In the preceding example:

1. When the button **first page storageLink + 1** on page 1 is clicked, the **storageLink** state variable is updated, and the @Watch decorated **first** method is called.

2. Through **router.pushUrl({url:'pages/second'})**, page 2 is displayed, and page 1 is hidden with its state changing from active to inactive.

3. When the button **this.storageLink2 += 2** on page 2 is clicked, only the @Watch decorated **second** method of page 2 is called, because page 1 has been frozen when inactive.

4. When the **back** button is clicked, page 2 is destroyed, and page 1 changes from inactive to active. At this time, if the state variable of page 1 is updated, the @Watch decorated **first** method of page 1 is called again.


### TabContent

- You can freeze invisible **TabContent** components in the **Tabs** container so that they do not trigger UI re-rendering.

- During initial rendering, only the **TabContent** component that is being displayed is created. All **TabContent** components are created only after all of them have been switched to.

For details, see the following.
![freezeWithTab](./figures/freezewithTabs.png)

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

In the preceding example:

1. When **change message** is clicked, the value of **message** changes, and the @Watch decorated **onMessageUpdated** method of the **TabContent** component being displayed is called.

2. When you click **two** to switch to another **TabContent** component, it switches from inactive to active, and the corresponding @Watch decorated **onMessageUpdated** method is called.

3. When **change message** is clicked again, the value of **message** changes, and only the @Watch decorated **onMessageUpdated** method of the **TabContent** component being displayed is called.

![TabContent.gif](figures/TabContent.gif)


### LazyForEach

- You can freeze custom components cached in **LazyForEach** so that they do not trigger UI re-rendering.

```ts
// Basic implementation of IDataSource used to listening for data.
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  // This method is called by the framework to add a listener to the LazyForEach data source.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  // This method is called by the framework to remove the listener from the LazyForEach data source.
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  // Notify LazyForEach that all child components need to be reloaded.
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  // Notify LazyForEach that a child component needs to be added for the data item with the specified index.
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  // Notify LazyForEach that the data item with the specified index has changed and the child component needs to be rebuilt.
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  // Notify LazyForEach that the child component that matches the specified index needs to be deleted.
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

In the preceding example:

1. When **change message** is clicked, the value of **message** changes, the @Watch decorated **onMessageUpdated** method of the list items being displayed is called, and that of the cached list items is not called. (If the component is not frozen, the @Watch decorated **onMessageUpdated** method of both list items that are being displayed and cached list items is called.)

2. When a list item moves from outside the list content area into the list content area, it switches from inactive to active, and the corresponding @Watch decorated **onMessageUpdated** method is called.

3. When **change message** is clicked again, the value of **message** changes, and only the @Watch decorated **onMessageUpdated** method of the list items being displayed is called.

![FrezzeLazyforEach.gif](figures/FrezzeLazyforEach.gif)

### Navigation

- When the navigation destination page is invisible, its child custom components are set to the inactive state and will not be re-rendered. When return to this page, its child custom components are restored to the active state and the @Watch callback is triggered to re-render the page.

- In the following example, **NavigationContentMsgStack** is set to the inactive state, which does not respond to the change of the state variables, and does not trigger component re-rendering.

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
              this.pageInfo.pushPath({ name: 'pageOne' }); // Push the navigation destination page specified by name to the navigation stack.
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

In the preceding example:

1. When **change message** is clicked, the value of **message** changes, and the @Watch decorated **info** method of the **MyNavigationTestStack** component being displayed is called.

2. When **Next Page** is clicked, **PageOne** is displayed, and the **PageOneStack** node is created.

3. When **change message** is clicked again, the value of **message** changes, and only the @Watch decorated **info** method of the **NavigationContentMsgStack** child component in **pageOneStack** is called.

4. When **Next Page** is clicked again, **PageTwo** is displayed, and the **pageTwoStack** node is created.

5. When **change message** is clicked again, the value of **message** changes, and only the @Watch decorated **info** method of the **NavigationContentMsgStack** child component in **pageTwoStack** is called.

6. When **Next Page** is clicked again, **PageThree** is displayed, and the **pageThreeStack** node is created.

7. When **change message** is clicked again, the value of **message** changes, and only the @Watch decorated **info** method of the **NavigationContentMsgStack** child component in **pageThreeStack** is called.

8. When **Back Page** is clicked, **PageTwo** is displayed, and only the @Watch decorated **info** method of the **NavigationContentMsgStack** child component in **pageTwoStack** is called.

9. When **Back Page** is clicked again, **PageOne** is displayed, and only the @Watch decorated **info** method of the **NavigationContentMsgStack** child component in **PageOne** is called.

10. When **Back Page** is clicked again, the initial page is displayed, and no method is called.

![navigation-freeze.gif](figures/navigation-freeze.gif)

### Reusing Components

[Components reuse](../performance/component-recycle.md) existing nodes in the cache pool instead of creating new nodes to optimize UI performance and improve application smoothness. Although the nodes in the reuse pool are not displayed in the UI component tree, the change of the state variable still triggers the UI re-render. To solve the problem that components in the reuse pool are re-rendered abnormally, you can perform component freezing.

#### Mixing Use of Component Reuse, if, and Component Freezing
The following example shows that when the state variable bound to the **if** component changes to **false**, the detach of **ChildComponent** is triggered. Because **ChildComponent** is marked as component reuse, it is not destroyed but enters the reuse pool, in this case, if the component freezing is enabled at the same time, the component will not be re-rendered in the reuse pool.
The procedure is as follows:
1. Click **change flag** and change the value of **flag** to **false**.
    -  When **ChildComponent** marked with \@Reusable is detached, it is not destroyed. Instead, it enters the reuse pool, triggers the **aboutToRecycle** lifecycle, and sets the component state to inactive.
    - **ChildComponent** also enables component freezing. When **ChildComponent** is in the inactive state, it does not respond to any UI re-render caused by state variable changes.
2. Click **change desc** to trigger the change of the member variable **desc** of **Page**.
    - The change of \@State decorated **desc** will be notified to \@Link decorated **desc** of **ChildComponent**.
    - However, **ChildComponent** is in the inactive state and the component freezing is enabled. Therefore, the change does not trigger the callback of @Watch('descChange') and the re-render of the `ChildComponent` UI. If component freezing is not enabled, the current @Watch('descChange') callback is returned immediately, and **ChildComponent** in the reuse pool is re-rendered accordingly.
3. Click **change flag** again and change the value of **flag** to **true**.
    - **ChildComponent** is attached to the component tree from the reuse pool.
    - Return the **aboutToReuse** lifecycle callback and synchronize the latest **count** value to **ChildComponent**. The value of **desc** is synchronized from @State to @Link. Therefore, you do not need to manually assign a value to **aboutToReuse**.
    - Set **ChildComponent** to the active state and re-render the component that is not re-rendered when **ChildComponent** is inactive, for example, **Text (ChildComponent desc: ${this.desc})**.


```ts
@Reusable
@Component({freezeWhenInactive: true})
struct ChildComponent {
  @Link @Watch('descChange') desc: string;
  @State count: number = 0;
  descChange() {
    console.info(`ChildComponent messageChange ${this.desc}`);
  }

  aboutToReuse(params: Record<string, ESObject>): void {
    this.count = params.count as number;
  }

  aboutToRecycle(): void {
    console.info(`ChildComponent has been recycled`);
  }
  build() {
    Column() {
      Text(`ChildComponent desc: ${this.desc}`)
        .fontSize(20)
      Text(`ChildComponent count ${this.count}`)
        .fontSize(20)
    }.border({width: 2, color: Color.Pink})
  }
}

@Entry
@Component
struct Page {
  @State desc: string = 'Hello World';
  @State flag: boolean = true;
  @State count: number = 0;
  build() {
    Column() {
      Button(`change desc`).onClick(() => {
        this.desc += '!';
      })
      Button(`change flag`).onClick(() => {
        this.count++;
        this.flag =! this.flag;
      })
      if (this.flag) {
        ChildComponent({desc: this.desc, count: this.count})
      }
    }
    .height('100%')
  }
}
```
#### Mixing Use of LazyForEach, Component Reuse, and Component Freezing
In the scrolling scenario of a long list with a large amount of data, you can use **LazyForEach** to create components as required. In addition, you can reuse components to reduce the overhead caused by component creation and destruction during scrolling.
However, if you set [reuseId](../performance/component-recycle.md#available-apis) based on the reuse type or assign a large value to **cacheCount** to ensure the scrolling performance, more nodes will be cached in the reuse pool or **LazyForEach**.
In this case, if you trigger the re-render of all subnodes in **List**, the number of re-renders is too large. In this case, you can freeze the component.

Example:
1. Swipe the list to the position whose index is 14. There are 15 **ChildComponent** in the visible area on the current page.
2. During swiping:
    - **ChildComponent** in the upper part of the list is swiped out of the visible area. In this case, **ChildComponent** enters the cache area of LazyForEach and is set to inactive. After the component slides out of the **LazyForEach** area, the component is not destructed and enters the reuse pool because the component is marked for reuse. In this case, the component is set to inactive again.
    - The cache node of **LazyForEach** at the bottom of the list enters the list. In this case, the system attempts to create a node to enter the cache of **LazyForEach**. If a node that can be reused is found, the system takes out the existing node from the reuse pool and triggers the **aboutToReuse** lifecycle callback, in this case, the node enters the cache area of **LazyForEach** and the state of the node is still inactive.
3. Click **change desc** to trigger the change of the member variable **desc** of **Page**.
    - The change of \@State decorated **desc** will be notified to \@Link decorated **desc** of **ChildComponent**.
    - **ChildComponent** in the invisible area is in the inactive state, and the component freezing is enabled. Therefore, this change triggers the @Watch('descChange') callback of the 15 nodes in the visible area and re-renders these nodes. Nodes cached in **LazyForEach** and the reuse pool are not re-rendered, and the \@Watch callback is not triggered.
    
For details, see the following.
![freeze](./figures/freezeResuable.png)
You can listen for the changes by \@Trace, only 15 **ChildComponent** nodes are re-rendered.
![freeze](./figures/traceWithFreeze.png)
A complete sample code is as follows:
```ts
import { hiTraceMeter } from '@kit.PerformanceAnalysisKit';
// Basic implementation of IDataSource used to listening for data.
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  // This method is called by the framework to add a listener to the LazyForEach data source.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  // This method is called by the framework to remove the listener from the LazyForEach data source.
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  // Notify LazyForEach that all child components need to be reloaded.
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  // Notify LazyForEach that a child component needs to be added for the data item with the specified index.
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  // Notify LazyForEach that the data item with the specified index has changed and the child component needs to be rebuilt.
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  // Notify LazyForEach that the child component that matches the specified index needs to be deleted.
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

  // Notify LazyForEach that data needs to be swapped between the from and to positions.
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
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

@Reusable
@Component({freezeWhenInactive: true})
struct ChildComponent {
  @Link @Watch('descChange') desc: string;
  @State item: string = '';
  @State index: number = 0;
  descChange() {
    console.info(`ChildComponent messageChange ${this.desc}`);
  }

  aboutToReuse(params: Record<string, ESObject>): void {
    this.item = params.item;
    this.index = params.index;
  }

  aboutToRecycle(): void {
    console.info(`ChildComponent has been recycled`);
  }
  build() {
    Column() {
      Text(`ChildComponent index: ${this.index} item: ${this.item}`)
        .fontSize(20)
      Text(`desc: ${this.desc}`)
        .fontSize(20)
    }.border({width: 2, color: Color.Pink})
  }
}

@Entry
@Component
struct Page {
  @State desc: string = 'Hello World';
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i < 50; i++) {
      this.data.pushData(`Hello ${i}`);
    }
  }

  build() {
    Column() {
      Button(`change desc`).onClick(() => {
        hiTraceMeter.startTrace('change decs', 1);
        this.desc += '!';
        hiTraceMeter.finishTrace('change decs', 1);
      })
      List({ space: 3 }) {
        LazyForEach(this.data, (item: string, index: number) => {
          ListItem() {
            ChildComponent({index: index, item: item, desc: this.desc}).reuseId(index % 10 < 5 ? "1": "0")
          }
        }, (item: string) => item)
      }.cachedCount(5)
    }
    .height('100%')
  }
}
```
#### Mixing Use of LazyForEach, if, Component Reuse, and Component Freezing

 Under the same parent custom component, reusable nodes may enter the reuse pool in different ways. For example:
- Detaching from the cache area of LazyForEach by swiping.
- Notifying the subnodes to detach by switching the if condition.

In the following example:
1. When you swipe the list to the position whose index is 14, there are 10 **ChildComponent**s in the visible area on the page, among which nine are subnodes of **LazyForEach** and one is a subnode of **if**.
2. Click **change flag**. The **if** condition is changed to **false**, and its subnode **ChildComponent** enters the reuse pool. Nine nodes are displayed on the page.
3. In this case, the nodes detached through **LazyForEach** or **if** all enter the reuse pool under the **Page** node.
4. Click **change desc** to update only the nine **ChildComponent** nodes on the page. For details, see figures below.
5. Click **change flag** again. The **if** condition changes to **true**, and **ChildComponent** is attached from the reuse pool to the component tree again. The state of **ChildComponent** changes to active.
6. Click **change desc** again. The nodes attached through **if** and **LazyForEach** from the reuse pool can be re-rendered.

Trace for component freezing enabled

![traceWithFreezeLazyForeachAndIf](./figures/traceWithFreezeLazyForeachAndIf.png)

Trace for component freezing disabled

![traceWithFreezeLazyForeachAndIf](./figures/traceWithLazyForeachAndIf.png)


A complete example is as follows:
```
import { hiTraceMeter } from '@kit.PerformanceAnalysisKit';
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  // This method is called by the framework to add a listener to the LazyForEach data source.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  // This method is called by the framework to remove the listener from the LazyForEach data source.
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  // Notify LazyForEach that all child components need to be reloaded.
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  // Notify LazyForEach that a child component needs to be added for the data item with the specified index.
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  // Notify LazyForEach that the data item with the specified index has changed and the child component needs to be rebuilt.
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  // Notify LazyForEach that the child component that matches the specified index needs to be deleted.
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

  // Notify LazyForEach that data needs to be swapped between the from and to positions.
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
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

@Reusable
@Component({freezeWhenInactive: true})
struct ChildComponent {
  @Link @Watch('descChange') desc: string;
  @State item: string = '';
  @State index: number = 0;
  descChange() {
    console.info(`ChildComponent messageChange ${this.desc}`);
  }

  aboutToReuse(params: Record<string, ESObject>): void {
    this.item = params.item;
    this.index = params.index;
  }

  aboutToRecycle(): void {
    console.info(`ChildComponent has been recycled`);
  }
  build() {
    Column() {
      Text(`ChildComponent index: ${this.index} item: ${this.item}`)
        .fontSize(20)
      Text(`desc: ${this.desc}`)
        .fontSize(20)
    }.border({width: 2, color: Color.Pink})
  }
}

@Entry
@Component
struct Page {
  @State desc: string = 'Hello World';
  @State flag: boolean = true;
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i < 50; i++) {
      this.data.pushData(`Hello ${i}`);
    }
  }

  build() {
    Column() {
      Button(`change desc`).onClick(() => {
        hiTraceMeter.startTrace('change decs', 1);
        this.desc += '!';
        hiTraceMeter.finishTrace('change decs', 1);
      })

      Button(`change flag`).onClick(() => {
        hiTraceMeter.startTrace('change flag', 1);
        this.flag = !this.flag;
        hiTraceMeter.finishTrace('change flag', 1);
      })

      List({ space: 3 }) {
        LazyForEach(this.data, (item: string, index: number) => {
          ListItem() {
            ChildComponent({index: index, item: item, desc: this.desc}).reuseId(index % 10 < 5 ? "1": "0")
          }
        }, (item: string) => item)
      }
      .cachedCount(5)
      .height('60%')

      if (this.flag) {
        ChildComponent({index: -1, item: 'Hello', desc: this.desc}).reuseId( "1")
      }
    }
    .height('100%')
  }
}
```
