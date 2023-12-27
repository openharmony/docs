# 自定义组件冻结功能

自定义组件处于非激活状态时，状态变量将不响应更新，即@Watch不会调用，状态变量关联的节点不会刷新。通过freezeWhenInactive属性来决定是否使用冻结功能，不传参数时默认不使用。支持的场景有：页面路由，ListItem，GridItem，TabContent，FlowItem，LazyforEach。

对于滑动类组件，比如List、Grid等，在首次渲染时是否可以冻结依赖后端组件的具体实现，详情可见[当前支持的场景](#当前支持的场景)

## 当前支持的场景

### 页面路由

- 当页面A调用router.pushUrl接口跳转到页面B时，页面A为隐藏不可见状态，此时如果更新页面A中的状态变量，不会触发页面A刷新。

- 当应用退到后台运行时无法被冻结。

页面A：

```ts
import router from '@ohos.router';

@Entry
@Component({ freezeWhenInactive: true })
struct FirstTest {
  @StorageLink('PropA')@Watch("first") storLink: number = 47;
  first(){
    console.info("first page "+ `${this.storLink}`)
  }

  build() {
    Column() {
      Text(`From fist Page ${this.storLink}`).fontSize(50)
      Button('first page storLink + 1').fontSize(30)
        .onClick(() => {
          this.storLink += 1
        })
      Button('go to next page').fontSize(30)
        .onClick(() => {
          router.pushUrl({url: 'pages/second'})
        })
    }
  }
}
```

页面B：

```ts
import router from '@ohos.router';
@Entry
@Component({ freezeWhenInactive: true })
struct SeconedTest {
  @StorageLink('PropA') @Watch("seconed") storLink2: number = 1;

  seconed() {
    console.info("seconed page: " + `${this.storLink2}`)
  }

  build() {
    Column() {

      Text(`seconed Page ${this.storLink2}`).fontSize(50)
      Button('Change Divider.strokeWidth')
        .onClick(() => {
          router.back()
        })

      Button('second page storLink2 + 2').fontSize(30)
        .onClick(() => {
          this.storLink2 += 2
        })

    }
  }
}
```

在上面的示例中：

1.点击页面A中的Button first page storLink + 1，storLink状态变量改变，@Watch中的方法first()会被调用。  
2.通过router.pushUrl({url: 'pages/second'})，跳转到页面B，页面A隐藏，状态由active变为inactive。  
3.点击页面B中的Button this.storLink2 += 2，只回调页面B@Watch中seconed()方法，因为页面A已经在inactive时被冻结。  
4.点击back，页面B被销毁，页面A的状态由inactive变为active，重新刷新在inactive时被冻结的状态变量，页面A@Watch中的方法first()被再次调用。

### ListItem

- 对划出List区域外的ListItem进行冻结，不会触发组件的更新。当ListItem滑到List区域外后，listItem组件状态由active变为inactive。

- 由于FreezeChild设置了@Component({ freezeWhenInactive: true })，即inactive的时候冻结，这时FreezeChild会延迟所有状态变量的更新通知。

- 等到组件状态重新变为active时，再更新在冻结状态时变化的状态变量。

- 需要注意的是：在首次渲染的时候，ListItem的子组件会懒加载，即只会创建当前正在显示的和cachedcount的ListItem的子组件，如果没有设置cachedCount，则默认为1。对于未滑动到且不在cache的ListItem，其子组件不会创建：
  - 当滑动List，在cache内的ListItem进入List区域内时，ListItem子节点从inactive->active，\@watch方法执行。非cache内的ListItem首次进入List区域内时，ListItem子节点会被创建，不存在状态的变化。
  - 当滑动ListItem离开List区域内时，ListItem子节点从active->inactive。

```ts
@Entry
@Component
struct Page {
  @State @Watch("onMessageUpdated") message: number = 0
  onMessageUpdated() {
    console.info(`Page message callback func ${this.message}`)
  }

  build() {
    Row() {
      Column() {
        Button('change message').onClick(() => {
          this.message++
        })
        List() {
          ListItem() {
            FreezeChild({message: this.message, index: 0})
          }.height('50%').border({width: 1})

          ListItem() {
            FreezeChild({message: this.message,  index: 1})
          }.height('50%').border({width: 1})

          ListItem() {
            FreezeChild({message: this.message,  index: 2})
          }.height('50%').border({width: 1})

          ListItem() {
            FreezeChild({message: this.message, index: 3})
          }.height('50%').border({width: 1})

          ListItem() {
            FreezeChild({message: this.message, index: 4})
          }.height('50%').border({width: 1})

          ListItem() {
            FreezeChild({message: this.message, index: 5})
          }.height('50%').border({width: 1})
        }.height('300').width('300')

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

1.点击change message更改message的值，当前正在显示的listItem子组件中的@Watch方法onMessageUpdated()被触发。  
2.List区域外的ListItem滑动到List区域内，状态由inactive变为active，对应的@Watch方法onMessageUpdated()被触发。  
3.再次点击change message更改message的值，仅有当前显示的listItem子组件中的@Watch方法onMessageUpdated()被触发。

![ListItem.gif](figures/ListItem.gif)

### GridItem

- 对划出Grid区域外的GridItem进行冻结，不会触发组件的更新。

- 需要注意的是，和ListItem不同，GridItem首次创建非懒加载，即会创建GridItem及其子节点：
  - 当滑动GridItem进入Grid区域内时，GridItem子节点从inactive->active。
  - 当滑动GridItem离开Grid区域内时，GridItem子节点从active->inactive。

```ts
@Entry
@Component
struct Page {
  @State @Watch("onMessageUpdated") message: number = 0
  onMessageUpdated() {
    console.info(`Page message callback func ${this.message}`)
  }

  build() {
    Row() {
      Column() {
        Button('change message').onClick(() => {
          this.message++;
        })

        Grid() {
          GridItem() {
            FreezeChild({message: this.message, index: 0})
          }.border({width: 1}).height('50%')

          GridItem() {
            FreezeChild({message: this.message,  index: 1})
          }.border({width: 1}).height('50%')

          GridItem() {
            FreezeChild({message: this.message,  index: 2})
          }.border({width: 1}).height('50%')

          GridItem() {
            FreezeChild({message: this.message, index: 3})
          }.border({width: 1}).height('50%')

          GridItem() {
            FreezeChild({message: this.message, index: 4})
          }.border({width: 1}).height('50%')

          GridItem() {
            FreezeChild({message: this.message, index: 5})
          }.height('50%').border({width: 1})

        }
        .height(400)
        .columnsTemplate('1fr')
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

1.点击change message更改message的值，当前正在显示的GridItem子组件中的@Watch方法onMessageUpdated()被触发。  
2.Grid区域外的GridItem滑动到Grid区域内，状态由inactive变为active，对应的@Watch方法onMessageUpdated()被触发。  
3.再次点击change message更改message的值，仅有当前显示的GridItem子组件中的@Watch方法onMessageUpdated()被触发。

![GridItem.gif](figures/GridItem.gif)

### TabContent

- 对Tabs中当前不可见的TabContent进行冻结，不会触发组件的更新。

- 需要注意的是：在首次渲染的时候，Tab只会创建当前正在显示的TabContent，当切换全部的TabContent后，TabContent才会被全部创建。

```ts
@Entry
@Component
struct TabContentTest {
  @State @Watch("onMessageUpdated") message: number = 0
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
          TabContent() {
            FreezeChild({message: this.message})
          }
          TabContent() {
            FreezeChild({message: this.message})
          }
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

1.点击change message更改message的值，当前正在显示的TabContent子组件中的@Watch方法onMessageUpdated()被触发。  
2.点击切换另外的TabContent，TabContent状态由inactive变为active，对应的@Watch方法onMessageUpdated()被触发。  
3.再次点击change message更改message的值，仅当前显示的TabContent子组件中的@Watch方法onMessageUpdated()被触发。

![TabContent.gif](figures/TabContent.gif)

### FlowItem

- 对WaterFlow中当前不可见的FlowItem进行冻结，不会触发组件的更新。

- 需要注意的是，和ListItem不同，FlowItem首次创建非懒加载，即会创建FlowItem及其子节点：
  - 当滑动FlowItem进入WaterFlow区域内时，FlowItem子节点从inactive->active。
  - 当滑动FlowItem离开WaterFlow区域内时，FlowItem子节点从active->inactive。

```ts
@Entry
@Component
struct WaterflowTest {
  @State @Watch("onMessageUpdated") message: number = 0
  onMessageUpdated() {
    console.info(`Waterflow message callback func ${this.message}`)
  }
  build() {
    Column({ space: 2 }) {
      Button('change message').onClick(() => {
        this.message++
      })
      WaterFlow() {
        FlowItem() {
          FreezeChild({message: this.message, index: 0})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 1})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 2})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 3})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 4})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 5})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 6})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 7})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 8})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 9})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 10})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 11})
        }
        FlowItem() {
          FreezeChild({message: this.message, index: 12})
        }
      }
      .columnsTemplate("1fr 1fr")
      .columnsGap(10)
      .rowsGap(5)
      .backgroundColor(0xFAEEE0)
      .width('100%')
      .height('60%')
    }
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
    Column(){
      Image($r('app.media.icon')).height(100)
      Text("message" + `${this.message}, index: ${this.index}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

在上面的示例中：

1.点击change message更改message的值，当前正在显示的FlowItem子组件中的@Watch方法onMessageUpdated()被触发。  
2.WaterFlow区域外的FlowItem滑动到WaterFlow区域内，状态由inactive变为active，对应的@Watch方法onMessageUpdated()被触发。  
3.再次点击change message更改message的值，仅有当前显示的FlowItem子组件中的@Watch方法onMessageUpdated()被触发。

![FlowItem.gif](figures/FlowItem.gif)

### LazyforEach

- 对LazyforEach中缓存的自定义组件进行冻结，不会触发组件的更新。

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
  @State @Watch("onMessageUpdated") message: number = 0

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
            FreezeChild({message: this.message})
          }
        }, (item: string) => item)
      }.cachedCount(5).height(500)
    }

  }
}

@Component({ freezeWhenInactive: true })
struct FreezeChild {
  @Link @Watch("onMessageUpdated") message: number
  private index: number = 0

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

1.点击change message更改message的值，当前正在显示的ListItem中的子组件@Watch方法onMessageUpdated()被触发。缓存节点@Watch方法onMessageUpdated()不会被触发。（如果不加组件冻结，当前正在显示的ListItem和cachcount缓存节点@Watch方法onMessageUpdated()都会触发watch回调）    
2.List区域外的ListItem滑动到List区域内，状态由inactive变为active，对应的@Watch方法onMessageUpdated()被触发。  
3.再次点击change message更改message的值，仅有当前显示的ListItem中的子组件@Watch方法onMessageUpdated()被触发。

![FrezzeLazyforEach.gif](figures/FrezzeLazyforEach.gif)



