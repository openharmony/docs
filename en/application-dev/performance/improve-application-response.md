# Speeding Up Application Response

This topic provides the following tips for improving your application's response to user input.

- Prevent the main thread from being blocked by non-UI tasks.
- Reduce the number of components to be refreshed.

## Preventing Main Thread from Being Blocked by Non-UI Tasks

When the application responds to user input, its main thread should execute only UI tasks (such as preparation of data to be displayed and update of visible components). It is recommended that non-UI, time-consuming tasks (such as long-time content loading) be executed through asynchronous tasks or allocated to other threads.

### Using Asynchronous Component Loading

The **\<Image>** component has the asynchronous loading feature enabled by default. When an application loads a batch of local images to be displayed on the page, blank placeholder icons are displayed first, and then replaced by the images when these images have finished loading in other threads. In this way, image loading does not block page display. The following code is recommended only when the image loading takes a short time.

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
    // Several <Row> containers are omitted here. Each container contains the preceding <Image> components.
    }
  }
}
```

Recommendation: If it takes a short time to load an image, the benefits of asynchronous loading will be greatly undermined. In this case, change the value of the syncLoad attribute.

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
    // Several <Row> containers are omitted here. Each container contains the preceding <Image> components.
    }
  }
}
```

### Using TaskPool for Asynchronous Processing

Compared with the worker thread, [TaskPool](../reference/apis/js-apis-taskpool.md) provides the task priority setting and automatic thread pool management mechanism. The following is an example:

```typescript
import taskpool from '@ohos.taskpool';

@Concurrent
function computeTask(arr: string[]): string[] {
  // Simulate a compute-intensive task.
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
    // Component layout
  }
}
```

### Creating Asynchronous Tasks

The following code shows how to declare a long-running non-UI task as an asynchronous task through **Promise**. This allows the main thread to first focus on providing user feedback and completing the initial render, and then execute the asynchronous task when it is idle. After the asynchronous task is complete, related components are redrawn to refresh the page.

```typescript
@Entry
@Component
struct AspectRatioExample4 {
  @State private children: string[] = ['1', '2', '3', '4', '5', '6'];
  private count: number = 0;

  aboutToAppear() {
    this.computeTaskAsync(); // Invoke the asynchronous compute function.
  }

  // Simulate a compute-intensive task.
  computeTask() {
    this.count = 0;
    while (this.count < 100000000) {
      this.count++;
    }
    this.children = this.children.reverse();
  }

  computeTaskAsync() {
    setTimeout(() => {// setTimeout is used to implement asynchronous processing.
      this.computeTask();
    }, 1000)
  }

  build() {
    // Component layout
  }
}
```

## Reducing the Number of Components to Be Refreshed

When an application refreshes a page, the number of components to be refreshed must be reduced as much as possible. If this number is too large, the main thread will take a long time to perform measurement and layout. In addition, the **aboutToAppear()** and **aboutToDisappear()** APIs will be called multiple times during the creation and destruction of custom components, increasing the load of the main thread.

### Limiting the Refresh Scope with Containers

Negative example: If a component in a container is included in the **if** condition, changes in the **if** condition result will trigger the creation and destruction of the component. If the container layout is affected in this case, all components in the container are refreshed. As a result, the UI refresh of the main thread takes a long time.

In the following example, the **Text('New Page')** component is controlled by the state variable **isVisible**. When **isVisible** is set to **true**, the component is created. When **isVisible** is set to **false**, the component is destroyed. This means that, when the value of **isVisible** changes, all components in the **\<Stack>** container are refreshed.

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

        // 100 identical <Text> components are omitted here.

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

Recommendation: For the component controlled by the state variable, add a container to the **if** statement to reduce the refresh scope.

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

        // 100 identical <Text> components are omitted here.

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

### Implementing On-Demand Loading of List Items

Negative example: Each of the 10000 elements in **this.arr** is initialized and loaded. As a result, the execution of the main thread takes a long time.

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

Recommendation: In similar cases, replace **ForEach** with **LazyForEach** so that only visible elements are loaded.

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
