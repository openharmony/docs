# 提升应用响应速度

应用对用户的输入需要快速反馈，以提升交互体验，因此本文提供了以下方法来提升应用响应速度。

- 避免主线程被非UI任务阻塞
- 减少组件刷新的数量

## 避免主线程被非UI任务阻塞

在应用响应用户输入期间，应用主线程应尽可能只执行UI任务（待显示数据的准备、可见视图组件的更新等），非UI的耗时任务（长时间加载的内容等）建议通过异步任务延迟处理或者分配到其他线程处理。

### 使用组件异步加载特性

当前系统提供的Image组件默认生效异步加载特性，当应用在页面上展示一批本地图片的时候，会先显示空白占位块，当图片在其他线程加载完毕后，再替换占位块。这样图片加载就可以不阻塞页面的显示，给用户带来良好的交互体验。因此，只在加载图片耗时比较短的情况下建议下述代码。 

```typescript
@Entry
@Component
struct ImageExample1 {
  build() {
    Column() {
      Row() {
        Image('resources/base/media/sss001.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%')
        Image('resources/base/media/sss002.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%')
        Image('resources/base/media/sss003.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%')
        Image('resources/base/media/sss004.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%')
      }
    // 此处省略若干个Row容器，每个容器内都包含如上的若干Image组件
    }
  }
}
```

建议：在加载图片的耗时比较短的时候，通过异步加载的效果会大打折扣，建议配置Image的syncLoad属性。

```typescript
@Entry
@Component
struct ImageExample2 {
  build() {
    Column() {
      Row() {
        Image('resources/base/media/sss001.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%').syncLoad(true)
        Image('resources/base/media/sss002.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%').syncLoad(true)
        Image('resources/base/media/sss003.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%').syncLoad(true)
        Image('resources/base/media/sss004.jpg')
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed).aspectRatio(1).width('25%').height('12.5%').syncLoad(true)
      }
    // 此处省略若干个Row容器，每个容器内都包含如上的若干Image组件
    }
  }
}
```

### 使用TaskPool线程池异步处理

当前系统提供了[TaskPool线程池](../reference/apis/js-apis-taskpool.md)，相比worker线程，TaskPool提供了任务优先级设置、线程池自动管理机制，示例如下：

```typescript
import taskpool from '@ohos.taskpool';

@Concurrent
function computeTask(arr: string[]): string[] {
  // 模拟一个计算密集型任务
  let count = 0;
  while (count < 100000000) {
    count++;
  }
  return arr.reverse();
}

@Entry
@Component
struct AspectRatioExample3 {
  @State children: string[] = ['1', '2', '3', '4', '5', '6'];

  aboutToAppear() {
    this.computeTaskInTaskPool();
  }

  async computeTaskInTaskPool() {
    const param = this.children.slice();
    let task = new taskpool.Task(computeTask, param);
    await taskpool.execute(task);
  }

  build() {
    // 组件布局
  }
}
```

### 创建异步任务

以下代码展示了将一个长时间执行的非UI任务通过Promise声明成异步任务，主线程可以先进行用户反馈-绘制初始页面。等主线程空闲时，再执行异步任务。等到异步任务运行完毕后，重绘相关组件刷新页面。

```typescript
@Entry
@Component
struct AspectRatioExample4 {
  @State private children: string[] = ['1', '2', '3', '4', '5', '6'];
  private count: number = 0;

  aboutToAppear() {
    this.computeTaskAsync();  // 调用异步运算函数
  }

  // 模拟一个计算密集型任务
  computeTask() {
    this.count = 0;
    while (this.count < 100000000) {
      this.count++;
    }
    this.children = this.children.reverse();
  }

  computeTaskAsync() {
    setTimeout(() => { // 这里使用setTimeout来实现异步延迟运行
      this.computeTask();
    }, 1000)
  }

  build() {
    // 组件布局
  }
}
```

## 减少刷新的组件数量

应用刷新页面时需要尽可能减少刷新的组件数量，如果数量过多会导致主线程执行测量、布局的耗时过长，还会在自定义组件新建和销毁过程中，多次调用aboutToAppear()、aboutToDisappear()方法，增加主线程负载。

### 使用容器限制刷新范围

反例：如果容器内有组件被if条件包含，if条件结果变更会触发创建和销毁该组件，如果此时影响到容器的布局，该容器内所有组件都会刷新，导致主线程UI刷新耗时过长。

以下代码的Text('New Page')组件被状态变量isVisible控制，isVisible为true时创建，false时销毁。当isVisible发生变化时，Stack容器内的所有组件都会刷新：

```typescript
@Entry
@Component
struct StackExample5 {
  @State isVisible : boolean = false;

  build() {
    Column() {
      Stack({alignContent: Alignment.Top}) {
        Text().width('100%').height('70%').backgroundColor(0xd2cab3)
          .align(Alignment.Center).textAlign(TextAlign.Center);

        // 此处省略100个相同的背景Text组件

        if (this.isVisible) {
          Text('New Page').height("100%").height("70%").backgroundColor(0xd2cab3)
            .align(Alignment.Center).textAlign(TextAlign.Center);
        }
      }
      Button("press").onClick(() => {
        this.isVisible = !(this.isVisible);
      })
    }
  }
}
```

建议：对于这种受状态变量控制的组件，在if外套一层容器，减少刷新范围。

```typescript
@Entry
@Component
struct StackExample6 {
  @State isVisible : boolean = false;

  build() {
    Column() {
      Stack({alignContent: Alignment.Top}) {
        Text().width('100%').height('70%').backgroundColor(0xd2cab3)
          .align(Alignment.Center).textAlign(TextAlign.Center);

        // 此处省略100个相同的背景Text组件

        Stack() {
          if (this.isVisible) {
            Text('New Page').height("100%").height("70%").backgroundColor(0xd2cab3)
              .align(Alignment.Center).textAlign(TextAlign.Center);
          }
        }.width('100%').height('70%')
      }
      Button("press").onClick(() => {
        this.isVisible = !(this.isVisible);
      })
    }
  }
}
```

### 按需加载列表组件的元素

反例：this.arr中的每一项元素都被初始化和加载，数组中的元素有10000个，主线程执行耗时长。

```typescript
@Entry
@Component
struct MyComponent7 {
  @State arr: number[] = Array.from(Array<number>(10000), (v,k) =>k); 
  build() {
    List() {
      ForEach(this.arr, (item: number) => {
        ListItem() {
          Text(`item value: ${item}`)
        }
      }, (item: number) => item.toString())
    }
  }
}
```

建议：这种情况下用LazyForEach替换ForEach，LazyForEach一般只加载可见的元素，避免一次性初始化和加载所有元素。

```typescript
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = []

  public totalCount(): number {
    return 0
  }

  public getData(index: number): string {
    return ''
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener')
      this.listeners.push(listener)
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener')
      this.listeners.splice(pos, 1)
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded()
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index)
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index)
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index)
    })
  }

  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to)
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = Array.from(Array<number>(10000), (v, k) => k.toString());

  public totalCount(): number {
    return this.dataArray.length
  }

  public getData(index: number): string  {
    return this.dataArray[index]
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data)
    this.notifyDataAdd(index)
  }

  public pushData(data: string): void {
    this.dataArray.push(data)
    this.notifyDataAdd(this.dataArray.length - 1)
  }
}

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource()

  build() {
    List() {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
            Text(item).fontSize(20).margin({ left: 10 })
        }
      }, (item:string) => item)
    }
  }
}
```