# Getting Started with Application Development Performance Optimization

## Overview

It is critical to optimize application performance during application development. This document describes common performance problems during application development and provides solutions to help developers solve most performance problems.

The application performance analysis method is divided into four elements. The following describes how to use the four elements to solve performance problems during application development.

* The first factor is to properly use parallelization, pre-loading, and caching. Methods such as parallelization, pre-loading, and caching must be properly used. For example, multi-thread concurrency, asynchronous concurrency, and web pre-loading capabilities must be used to improve system resource utilization, reduce the load of main threads, and accelerate application startup and response.

* Second factor: Reduce the number of layout nesting layers. During page layout development, remove redundant layout nesting and use flat layouts such as relative layout, absolute positioning, customized layout, Grid, and GridRow to reduce the number of layout nesting layers and prevent the system from drawing more layout components, in this way, the performance is optimized and the memory usage is reduced.

* Third element: Properly manage status variables. Properly use status variables, accurately control the update scope of components, control the number of components associated with status variables, and control the number of components associated with member variables of object-level status variables to reduce the component rendering load of the system and improve application smoothness.

* The fourth factor is to properly use system APIs to avoid redundant operations. High-frequency callback APIs of the system should be properly used, and unnecessary trace and log printing should be deleted to avoid redundant callback of the registration system and reduce system overhead.

## First element: proper use of parallelization, pre-loading, and caching

Methods such as parallelization, pre-loading, and caching need to be properly used to improve system resource utilization, reduce the load of the main thread, and accelerate the startup and response speed of applications.

### Parallelization Is Used to Improve the Startup Speed

After a custom component is created, the aboutToAppear() lifecycle callback function is executed before the build function is executed. In this case, if time-consuming operations are performed in this function, UI rendering is blocked and the load of the UI main thread is increased. Therefore, avoid performing time-consuming operations during the lifecycle of a custom component. In the aboutToAppear() lifecycle function, it is recommended that only the initialization logic of the current component be performed. For time-consuming tasks that do not need to wait for results, multiple threads can be used to process the tasks to prevent the main thread from being blocked. You can also change the time-consuming operation to asynchronous concurrent or delayed processing to ensure that the main thread preferentially processes the component drawing logic.

#### Use multiple threads to perform time-consuming operations.

During routine development, the following problem often occurs: In the home page development scenario, multiple tab pages display different content. After the home page is loaded for the first time, network data needs to be loaded and processed when the second tab page is switched to. As a result, the second tab page is displayed slowly and the completion delay is long.

When this problem occurs, you can use the methods of multi-thread concurrency, efficient concurrent programming (efficient-concurrent-programming.md), and multi-thread capability scenario-based practice (multi_thread_capability.md) to perform time-consuming operations on the second tab page, such as network data access parsing and data loading, data can be loaded in advance without affecting UI drawing and rendering of the main thread.

The sample code for using TaskPool to perform time-consuming operations is as follows:

```typescript
import taskpool from '@ohos.taskpool';

aboutToAppear() {
  //In the lifecycle, use TaskPool to load and parse network data.
  this.requestByTaskPool();
}

@Concurrent
getInfoFromHttp(): string[] {
  //Load data from the network.
  return http.request();
}

requestByTaskPool(): void {
  //Create a task item.
  let task: taskpool.Task = new taskpool.Task(this.getInfoFromHttp);
  try {
    //Execute the network loading function.
    taskpool.execute(task, taskpool.Priority.HIGH).then((res: string[]) => {
  });
  } catch (err) {
    logger.error(TAG, "failed, " + (err as BusinessError).toString());
  }
}
```

Other articles related to multithreaded concurrency:

* [Implementing Cross-Thread Invoking in Native Mode] (native-threads-call-js.md)


#### Performing Time-consuming Operations Asynchronously

Problem: In the aboutToAppear lifecycle function, time-consuming operations such as service data parsing and processing are performed, affecting the response delay of the previous page.

You can change the execution mode of time-consuming operations from synchronous to asynchronous or delayed. [Improve the application cold start speed] (improve-application-cold-start-speed.md). For example, use setTimeOut to perform time-consuming operations. The following is an example:

```typescript
aboutToAppear() {
  //In the lifecycle, asynchronous data processing is used. The delay is determined based on the site requirements.
  setTimeout(() => {
    this.workoutResult();
  }, 1000)
}

workoutResult(): string[] {
  //Process the service data to be displayed.
  let data: Data[] = [];
  for(let i = 1; i < 100; i++) {
    result += data[i];
  }
  return result;
}
```

### Using Preloading to Improve Page Startup and Response Speed

Use the pre-loading capability of the system properly to improve the page startup and response speed. For example, use the pre-connection, pre-loading, and pre-rendering of web components, use the cachedCount attribute of components such as List, Swiper, Grid, and WaterFlow to implement pre-loading, and use conditional rendering to implement pre-loading.

#### Use the pre-connection, pre-loading, and pre-rendering capabilities of web components.

If the web page loading is slow, you can use the pre-connection, pre-loading, and pre-rendering capabilities of the web component to initialize the web engine and load the page in advance when the application is idle. For details, see the Web Component Development Performance Improvement Guide (performance-web-import.md). The startup and response speed of the next page are improved.

The sample code is as follows:

```typescript
import webview from '@ohos.web.webview';

preload() {
  //Initialize the web component engine.
  webview.WebviewController.initializeWebEngine();
  //Start the pre-connection. The connection address is the website to be opened.
  webview.WebviewController.prepareForPageLoad('https://gitee.com/harmonyos-cases/cases', true, 2);
}
```

#### Using the cachedCount Attribute to Implement Preloading

You are advised to use the cachedCount attribute to implement pre-loading when using components such as List, Swiper, Grid, and WaterFlow. For details, see WaterFlow High-Performance Development Guide (waterflow_optimization.md) and Swiper High-Performance Development Guide. swiper_optimization.md, grid_optimization.md, and list-perf-improvment.md. The sample code is as follows:

```typescript
  private source: MyDataSource = new MyDataSource();

  build() {
    List() {
      LazyForEach(this.source, item => {
        ListItem() {
          Text("Hello" + item)
            .fontSize(50)
            .onAppear(() => {
              console.info("appear:" + item)
            })
        }
      })
    }.cachedCount(3) // Increase the number of list or grid items preloaded outside of the screen.
  }
```

#### Preloading Using Conditional Rendering

Problem: The page layout is complex. As a result, the response delay for jumping to the page is long.

You can use the condition rendering mode to select proper condition rendering and display/hide control (proper-choice-between-if-and-visibility.md). Add a simple skeleton diagram of the page as the default display page. After the data is loaded, the final complex layout is displayed, accelerating the click response speed.

The sample code is as follows:

```typescript
import skeletonComponent from "./skeletonComponent";
import businessComponent from "./businessComponent";

@State isInitialized: boolean = false;

build() {
  // Display the skeleton diagram when the data is not in place, improving the click response speed and reducing the page rendering time.
  if(!this.isInitialized) {
    //Use the skeleton diagram before network data is obtained.
    skeletonComponent();
  } else {
    //Refresh the displayed content after the data is obtained.
    businessComponent();
  }
}
```

### Using the Cache to Improve the Startup Speed and Sliding Frame Rate

In the list scenario, the LazyForEach, component reuse, and list item cache capabilities are recommended to replace the Scroll/ForEach to implement the scrolling list scenario, accelerate the page startup speed, and improve the sliding frame rate. In some attribute animation scenarios, you can use the renderGroup cache to improve the attribute animation performance. You can also use the display/hide control function to cache pages to accelerate the page display response speed.

#### Reusing Components

The application framework provides the component reuse capability. When a reusable component is removed from the component tree, it enters a recycling buffer. When a new component node is created, the node in the cache is reused to save the component re-creation time.

If the following scenarios exist in service implementation and become the frame rate bottleneck of the UI thread, component reuse is recommended. For details, see [Component Reuse Practice] (component-recycle.md) and [Performance Improvement Practice in List Scenarios] (list-perf-improvment.md).

* List scrolling (scenario in this example): When an application needs to display a list of a large amount of data and a user performs scrolling operations, frequent creation and destruction of views of list items may cause frame freezing and performance problems. In this case, the component reuse mechanism that uses the list component can reuse the created list item view to improve the scrolling smoothness.
* Dynamic layout update: If the layout of an application interface needs to be frequently updated, for example, the view structure and style need to be dynamically changed based on user operations or data changes, repeated creation and destruction of views may cause frequent layout calculation, affecting the frame rate. In this case, using component reuse can avoid unnecessary view creation and layout calculation and improve performance.
* Map rendering: In map rendering scenarios, frequent creation and destruction of views of data items may cause performance problems. Component reuse allows you to reuse created views and update only data content, reducing view creation and destruction and improving performance.

The sample code is as follows:

```typescript
// xxx.ets
class MyDataSource implements IDataSource {
  private dataArray: string[] = [];
  private listener: DataChangeListener | undefined;
  // ...
}

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i < 1000; i++) {
      this.data.pushData(i.toString());
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          ReusableChildComponent({ item: item })
        }
      }, (item: string) => item)
    }
    .width('100%')
    .height('100%')
  }
}

@Reusable
@Component
struct ReusableChildComponent {
  @State item: string = ''
  //Lifecycle triggered during multiplexing
  aboutToReuse(params: ESObject) {
    this.item = params.item;
  }

  build() {
    Row() {
      Text(this.item)
        .fontSize(20)
        .margin({ left: 10 })
    }.margin({ left: 10, right: 10 })
  }
}
```

#### Using renderGroup Cache to Improve Attribute Animation Performance

When a page responds, a large number of attribute animations and transition animations may be used. When the complexity reaches a certain level, frame freezing may occur. [renderGroup](reasonable-using-renderGroup.md) is a common component method, which represents a combination of rendering and drawing.

When a component is drawn for the first time, if the component is marked with renderGroup enabled, the component and its subcomponents are drawn off the screen, and the drawing results are combined and saved to the cache. When the same component needs to be redrawn, the cache is preferentially used instead of redrawing the component. This reduces the drawing load and accelerates the response speed.

The sample code is as follows:

```typescript
// Index.ets
import { IconItem } from './IconItem';

// IconItem-related data
class IconItemSource {
  image: string | Resource = ''
  text: string | Resource = ''
  // ...
}

@Entry
@Component
struct Index {
  private iconItemSourceList: IconItemSource[] = [];

  aboutToAppear() {
    // Traverse the data for adding IconItem.
    this.iconItemSourceList.push(
      new IconItemSource($r('app.media.img1'), `label1`),
      new IconItemSource($r('app.media.img2'), `label2`),
      new IconItemSource($r('app.media.img3'), `label3`)
    );
  }

  build() {
    Column() {
      //IconItem is placed in the grid.
      GridRow() {
        ForEach(this.iconItemSourceList, (item: IconItemSource) => {
          GridCol() {
            IconItem({ image: item.image, text: item.text })
              .transition(TransitionEffect.scale({ x: 0, y: 0 })
                  .animation({ delay: 1000, duration: 1000 })
                  .combine(TransitionEffect.rotate({ z: 1, angle: 180 })
                  .animation({ duration: 1000 }))
              )
          }
        })
      }
    }
  }
}

// IconItem.ets
@Component
export struct IconItem {
  build()  {
    Flex()  {
      Image(this.image)
      Text(this.text)
    }
    //Enable renderGroup in IconItem.
    .renderGroup(true)
  }
}
```

#### Page Cache Using Display and Hide Control

It is a common scenario to display or hide control elements. You can use Visibility.None or if to determine whether to display or hide control elements. The if condition controls the component creation and layout phases, and the Visibility attribute controls whether an element participates in layout rendering in the layout phase. Improper use of this method may cause performance problems.
If the interaction effect of displaying and hiding elements is frequently responded, you are advised to switch between Visibility.None and Visibility.Visible to properly control the display and hiding of elements (proper-choice-between-if-and-visibility.md). When a component does not need to be displayed, cache the component to improve performance.

The sample code is as follows:

```typescript
@State isVisible: boolean = true;

build() {
  Column() {
    Button("Switch visible and hidden").onClick(() => {
        this.isVisible = !this.isVisible;
    })
    Stack() {
      Scroll() {
        Column() {
          Image($r('app.media.icon'))
        }
      }.visibility(this.isVisible ? Visibility.Visible : Visibility.None)// When the visibility attribute is used, components are not frequently created and destroyed.
    }  
  }  
}
```

## Second element: Minimize the number of nested layout layers.

During page layout development, redundant layout nesting must be removed. Flat layouts such as relative layout, absolute positioning, customized layout, grid, and grid row must be used to reduce the number of layout nesting layers and prevent the system from drawing more layout components, achieving layout performance optimization (reduce-view-nesting-levels.md). Purpose of reducing memory usage.

### Removing Redundant Nodes

Delete redundant layout nesting, for example, useless container nesting at the outermost layer of build and useless stack or column nesting, to reduce the number of layout layers.

#### Unnecessary Stack/Column/Row nesting is deleted.

For example, a Row container may contain a child that is also a Row container. This nesting is actually redundant and causes unnecessary overhead to the layout hierarchy. The sample code is as follows:

```typescript
// Avoid the usage below.
Row() {
  Row() {
    Text()
    Text()
  }
  Text()
}

// Positive example
Row() {
  Text()
  Text()
  Text()
}
```

#### Delete the outermost useless container nesting from the build function.

During development, layout implementation usually uses a large number of user-defined components in nesting mode. The redundant outermost useless container in build greatly enhances the nesting level and should be deleted.

The negative example code is as follows:

```typescript
@Entry
@Component
struct ComponentA {
  build() {
    Column() {
      ComponentB();
    }
  }
}

@Component
struct ComponentB {
  build() {
    Column() {
      Text('');
    }
  }
}
```

The positive code is as follows:

```typescript
@Entry
@Component
struct ComponentA {
  build() {
    Column() {
      ComponentB();
    }
  }
}

@Component
struct ComponentB {
  build() {
    Text('');
  }
}
```

### Use flattened layout to reduce the number of nodes.

#### Use Column/Row instead of Flex to build a linear layout.

Due to the impact of secondary layout brought by Flex, the performance of Flex is much lower than that of Column and Row containers. Therefore, you are advised to replace Flex with Column/Row to build linear layout. For details, see Guide to Improving Flex Layout Performance (flex-development-performance-boost.md).

The negative example code is as follows:

```typescript
@Entry
@Component
struct MyComponent {
  build() {
    Flex({ direction: FlexDirection.Column }) {
      Flex().width(300).height(200).backgroundColor(Color.Pink)
      Flex().width(300).height(200).backgroundColor(Color.Yellow)
      Flex().width(300).height(200).backgroundColor(Color.Grey)
    }
  }
}
```

The positive code is as follows:

```typescript
@Entry
@Component
struct MyComponent {
  build() {
    Column() {
      Row().width(300).height(200).backgroundColor(Color.Pink)
      Row().width(300).height(200).backgroundColor(Color.Yellow)
      Row().width(300).height(200).backgroundColor(Color.Grey)
    }
  }
}
```

#### Use Flex, List, Grid, RelativeContainer, Absolute Layout, and Custom Layout to build complex layouts.

Complex layout provides scenario-based capabilities. [Layout performance optimization] (reduce-view-nesting-levels.md) can solve one or more layout scenarios.

* Use Flex to build an elastic layout.
* The list features linear layout and supports lazy loading and sliding.
* Grid/GridItem provides the grid layout capability and supports lazy loading and sliding.
* RelativeContainer is a relative layout algorithm. It describes the relationships between content components to guide the layout of content elements. The layout can be described from the horizontal and vertical aspects.

The negative example code is as follows:

```typescript
@Entry
@Component
struct AspectRatioExample12 {
    @State children: Number[] = Array.from(Array<number>(900), (v, k) => k);

    build() {
      Scroll() {
        Grid() {
          ForEach(this.children, (item: Number[]) => {
            GridItem() {
              Stack() {  
                Stack() {  
                  Stack() {  
                    Text(item.toString())  
                  }.size({ width: "100%"})  
                }.backgroundColor(Color.Yellow)  
              }.backgroundColor(Color.Pink)  
            }  
          }, (item: string) => item)  
        }  
        .columnsTemplate('1fr 1fr 1fr 1fr')  
        .columnsGap(0)  
        .rowsGap(0)  
        .size({ width: "100%", height: "100%" })  
    }  
  }  
}
```

The positive code is as follows:

```typescript
@Entry  
@Component  
struct AspectRatioExample11 {  
  @State children: Number[] = Array.from(Array<number>(900), (v, k) => k);  

  build() {  
    Scroll() {  
      Grid() {  
        ForEach(this.children, (item: Number[]) => {  
          GridItem() {  
            Text(item.toString())  
          }.backgroundColor(Color.Yellow)  
        }, (item: string) => item)  
      }  
      .columnsTemplate('1fr 1fr 1fr 1fr')  
      .columnsGap(0)  
      .rowsGap(0)  
      .size({ width: "100%", height: "100%" })  
    }  
  }  
}
```

## Third Element: Reasonable Management of State Variables

Use status variables properly. [Precisely control the update range of components] (precisely-control-render-scope.md). Control the maximum number of components associated with status variables and the number of components associated with member variables of object-level status variables to reduce the component rendering load of the system and improve application smoothness.

### Precisely Controlling Render Scope

In development of complex pages, precisely controlling the component render scope is especially important to speed up applications. The container component refresh caused by the abuse of state variables should be avoided, which further affects the frame rate.

#### Use the container with the specified width and height to limit the refresh range.

When the layout inside a container is changed in a container with both the width and height specified, only the layout and measurement update are performed inside the container, and the components outside the container are not affected.

The negative example code is as follows:

```typescript
struct StackExample {
  @State isVisible: boolean = true;
  private data: number[] = [];

  aboutToAppear() {
    for (let i: number = 0; i < Constants.IMAGE_TOTAL_NUM; i++) {
      this.data.push(i);
    }
  }

  build() {
    Column() {
      Button('Switch Hidden and Show').onClick(() => {
        this.isVisible = !this.isVisible;
      })

      Stack() {
        if (this.isVisible) {
          Text('New Page').width(100).height(30).backgroundColor(0xd2cab3)
        }
      }.width(100) //In this case, the Stack container is used as an example. If only the width is specified, the parent container component is triggered to re-lay out and calculate, causing text measurement in Forach.

      ForEach(this.data, (item: number) => {//The width and height of the stack container are not specified at the same time. As a result, this layer is affected and the text measurement is updated.
        Text(`Item value: ${item}`)
          .fontSize($r('app.integer.font_size_20'))
          .width($r('app.string.layout_100_percent'))
          .textAlign(TextAlign.Center)
      }, (item: number) => item.toString())
    }
  }
}
```

The positive code is as follows:

```typescript
struct StackExample2 {
  @State isVisible: boolean = true;
  private data: number[] = [];

  aboutToAppear() {
    for (let i: number = 0; i < Constants.IMAGE_TOTAL_NUM; i++) {
      this.data.push(i);
    }
  }

  build() {
    Column() {//Parent container
      Button('Switch Hidden and Show').onClick(() => {
        this.isVisible = !this.isVisible;
      })

      Stack() {
        if (this.isVisible) {
          Text('New Page').width(100).height(30).backgroundColor(0xd2cab3)
        }
      }.width(100).height(30) //In the stack container with the specified width and height, the internal Text component changes only in the layout and measurement update inside the container, and does not affect the Text component in the Forach outside the container.

      The width and height of the ForEach(this.data, (item: number) => { // Stack container are specified, which does not affect the sibling nodes at this layer.
        Text(`Item value: ${item}`)
          .fontSize($r('app.integer.font_size_20'))
          .width($r('app.string.layout_100_percent'))
          .textAlign(TextAlign.Center)
      }, (item: number) => item.toString())
    }
  }
```
#### Unnecessary parameter transfer is reduced.

The implementation modes of the @State+@Prop, @State+@Link, and @State+@Observed+@ObjectLink solutions are level-by-level status transfer. When the levels of components that share the status differ greatly, the status is transferred layer by layer. This is "additional consumption" for intermediate components that do not use this state. Therefore, it is more reasonable to use the @Provide+@Consume solution for state variable transfer across multiple layers.

The negative example code is as follows:

```typescript
//Parent component
@Component
struct componentParent{
  @State data: Data = {};

  aboutToAppear() {
    //Obtain the subcomponent data.
    this.data = getData();
  }

  build() {
    Column() {
      componentSon({ data: this.data })
    }
  }
}

//Subcomponent
@Component
struct componentSon{
  //Obtain the transferred parameters.
  @Prop data: Data;

  build() {
    Column() {
      Text(data.text)
      componentGrandSon({ data: this.data })
    }
  }
}

@Component
struct componentGrandSon{
  //Obtain the transferred parameters.
  @Prop data: Data;

  build() {
    Column() {
      Text(data.text)
    }
  }
}
```

The positive code is as follows:

```typescript
//Parent component
@Component
struct componentParent{
  @Provide('data') data: Data = {};

  aboutToAppear() {
    //Obtain the subcomponent data.
    this.data = getData()
  }

  build() {
    Column() {
      componentSon({ data: this.data })
    }
  }
}

//Subcomponent
@Component
struct componentSon{
  //Obtain the transferred parameters.
  @Consume("data") data: Data;

  build() {
    Column() {
      Text(data.text)
      componentGrandSon({ data: this.data })
    }
  }
}

@Component
struct componentGrandSon{
  //Obtain the transferred parameters.
  @Consume("data") data: Data;

  build() {
    Column() {
      Text(data.text)
    }
  }
}
```

#### Avoid abuse of @Provide+@Consume

In the scenario where parent and child components are associated, the overhead of @Provide+@Consume is greater than that of @State+@Prop/@Link. Therefore, the combination of @State+@Prop/@Link is recommended in this scenario.

The negative example code is as follows:

```typescript
//Parent component
@Component
struct componentParent{
  @Provide("data") data: Data = {};

  aboutToAppear() {
    //Obtain the subcomponent data.
    this.data = getData();
  }

  build() {
    Column() {
      componentSon()
    }
  }
}

//Subcomponent
@Component
struct componentSon{
  //Obtain the transferred parameters.
  @Consume("data") data: Data;

  build() {
    Column() {
      Text(data.text)
    }
  }
}
```

The positive code is as follows:

```typescript
//Parent component
@Component
struct componentParent{
  @State data:Data = {};

  aboutToAppear() {
    //Obtain the subcomponent data.
    this.data = getData();
  }

  build() {
    Column() {
      componentSon({ data: this.data })
    }
  }
}

//Subcomponent
@Component
struct componentSon{
  //Obtain the transferred parameters.
  @Prop data:Data;

  build() {
    Column() {
      Text(data.text)
    }
  }
}
```

### Precisely control the number of components associated with status variables.

The number of components associated with a status variable must be controlled. If a status variable is associated with too many components, too many components will be redrawn and rendered when the variable is updated. It is recommended that the number of associated components be limited to 20 to achieve [Precise control of the component update range] (precisely-control-render-scope.md).

#### Number of components associated with the control status variable

The negative example code is as follows:

```typescript
@Observed
class Translate {
  translateX: number = 20;
}
@Component
struct Title {
  @ObjectLink translateObj: Translate;
  build() {
    Row() {
      Image($r('app.media.icon'))
        .translate({
          x: this.translateObj.translateX // this.translateObj.translateX used in two component both in Row
        })
      Text("Title")
        .translate({
          x: this.translateObj.translateX
        })
    }
  }
}
@Entry
@Component
struct Page {
  @State translateObj: Translate = new Translate();
  build() {
    Column() {
      Title({
        translateObj: this.translateObj
      })
      Stack() {
      }
      .translate({
        x:this.translateObj.translateX // this.translateObj.translateX used in two components both in Column
      })
      Button("move")
        .translate({
          x: this.translateObj.translateX
        })
        .onClick(() => {
          animateTo({
            duration: 50
          }, () => {
            this.translateObj.translateX = (this.translateObj.translateX + 50) % 150
          })
        })
    }
  }
}
```

The positive code is as follows:

```typescript
@Observed
class Translate {
  translateX: number = 20;
}
@Component
struct Title {
  build() {
    Row() {
      Image($r('app.media.icon'))
      Text("Title")
    }
  }
}
@Entry
@Component
struct Page1 {
  @State translateObj: Translate = new Translate();
  build() {
    Column() {
      Title()
      Stack() {
      }
      Button("move")
        .onClick(() => {
          animateTo({
            duration: 50
          }, () => {
            this.translateObj.translateX = (this.translateObj.translateX + 50) % 150
          })
        })
    }
    .translate({ // the component in Column shares the same property translate
      x: this.translateObj.translateX
    })
  }
}
```

#### Controlling the Number of Object-Level Status Variable Members

The number of components associated with a member variable of an object-level state variable should be controlled. When a developer encapsulates a data structure class for status variable association, do not associate too many member variables with a large number of ArkUI components. In this case, when a member variable of the large object is updated, all components associated with the large object are updated at the same time, causing unnecessary performance loss, as a result, the frame rate is affected.

The negative example code is as follows:

```typescript
@Observed
class AnimationParams {
  translateX: number = 0;
  translateY: number = 0;
  alpha: number = 1;
  rotationX: number = 0;
  rotationY: number = 0;
  centerX: number = 0;
  centerY: number = 0;
  angle: number = 0;
  scaleX: number = 1;
  scaleY: number = 1;
}

@Entry
@Component
struct Page {
  @State animationParam: AnimationParams = new AnimationParams();

  build() {
    Column() {
      Row() {
        Image($r('app.media.startIcon'))
          .translate({
            x: this.animationParam.translateX,
            y: this.animationParam.translateY
          })
          .rotate({
            x: this.animationParam.rotationX,
            y: this.animationParam.translateY,
            centerX: this.animationParam.centerX,
            centerY: this.animationParam.centerY,
            angle: this.animationParam.angle
          })
          .opacity(this.animationParam.alpha)
          .scale({
            x: this.animationParam.scaleX,
            y: this.animationParam.scaleY,
            centerX: this.animationParam.centerX,
            centerY: this.animationParam.centerY
          })
          .animation({
            duration: 3000
          })
      }

      Button ('Click to play animation')
        .onClick(() => {
          this.animationParam.translateX = 300;
          this.animationParam.translateY = 200;
          this.animationParam.rotationX = 90;
          this.animationParam.rotationY = 90;
          this.animationParam.centerX = 20;
          this.animationParam.centerY = 20;
          this.animationParam.angle = 270;
          this.animationParam.alpha = 0.5;
          this.animationParam.scaleX = 3;
          this.animationParam.scaleY = 3;
        })
    }
  }
}
```

The positive code is as follows:

```typescript
@Observed
class RotationAnimationParams {
  rotationX: number = 0;
  rotationY: number = 0;
  centerX: number = 0;
  centerY: number = 0;
  angle: number = 0;
}

@Observed
class TranslateAnimationParams {
  translateX: number = 0;
  translateY: number = 0;
}

@Observed
class AlphaAnimationParams {
  alpha: number = 1;
}

@Observed
class ScaleAnimationParams {
  scaleX: number = 1;
  scaleY: number = 1;
  centerX: number = 0;
  centerY: number = 0;
}

@Entry
@Component
struct Page {
  @State rotationAnimation: RotationAnimationParams = new RotationAnimationParams();
  @State translateAnimation: TranslateAnimationParams = new TranslateAnimationParams();
  @State alphaAnimation: AlphaAnimationParams = new AlphaAnimationParams();
  @State scaleAnimation: ScaleAnimationParams = new ScaleAnimationParams();

  build() {
    Column() {
      Row() {
        Image($r('app.media.startIcon'))
          .translate({
            x: this.translateAnimation.translateX,
            y: this.translateAnimation.translateY
          })
          .rotate({
            x: this.rotationAnimation.rotationX,
            y: this.rotationAnimation.rotationY,
            centerX: this.rotationAnimation.centerX,
            centerY: this.rotationAnimation.centerY,
            angle: this.rotationAnimation.angle
          })
          .opacity(this.alphaAnimation.alpha)
          .scale({
            x: this.scaleAnimation.scaleX,
            y: this.scaleAnimation.scaleY,
            centerX: this.scaleAnimation.centerX,
            centerY: this.scaleAnimation.centerY
          })
          .animation({
            duration: 3000
          })
      }

      Button ('Click to play animation')
        .onClick(() => {
          this.rotationAnimation.rotationX = 90;
          this.rotationAnimation.rotationY = 90;
          this.rotationAnimation.centerX = 20;
          this.rotationAnimation.centerY = 20;
          this.rotationAnimation.angle = 270;

          this.translateAnimation.translateX = 300;
          this.translateAnimation.translateY = 200;

          this.alphaAnimation.alpha = 0.5;

          this.scaleAnimation.scaleX = 3;
          this.scaleAnimation.scaleY = 3;
          this.scaleAnimation.centerX = 20;
          this.scaleAnimation.centerY = 20;
        })
    }
  }
}
```

### Avoid unnecessary creation and reading of state variables.

Avoid unnecessary creation and reading of status variables to reduce performance loss.

#### Delete redundant state variable flags.

The management of state variables has certain overhead and should be used in proper scenarios. If common variables are marked with state variables, the performance may deteriorate.

The negative example code is as follows:

```typescript
@Component
struct component {
  @State bgcolor: string | Color = '#ffffff';
  @State selectColor: string | Color = '#007DFF';

  build() {
  }
}
```

The positive code is as follows:

```typescript
@Component
struct component {
  bgcolor: string | Color = '#ffffff';
  selectColor: string | Color = '#007DFF';

  build() {
  }
}
```

#### Avoid repeatedly reading status variables in loop functions such as For/while.

The time required for reading a status variable is much longer than that for reading a common variable. Therefore, do not read a status variable repeatedly. Instead, read the status variable outside the loop. For example, print the log information of the status variable in the For/while loop.

The negative example code is as follows:

```typescript
@Component
struct Page {
  @State message: string = '';

  build() {
    Column() {
      Button ('Print Log')
        .onClick(() => {
          for (let i = 0; i < 10; i++) {
            console.info(this.message);
          }
        })
    }
  }
}
```

The positive code is as follows:

```typescript
@Component
struct Page {
  @State message: string = '';

  build() {
    Column() {
      Button ('Print Log')
        .onClick(() => {
          let logMessage: string = this.message;
          for (let i = 0; i < 10; i++) {
            console.info(logMessage);
          }
        })
    }
  }
}
```

## Factor 4: Properly use system APIs to avoid redundant operations.

High-frequency callback APIs of the system must be properly used. Unnecessary trace and log printing must be deleted to avoid redundant operations and reduce system overhead. [Avoid redundant operations during development] (avoiding-redundant-operations.md)

### Avoid Redundant and Time-consuming Operations Using System High-frequency Callbacks

Do not perform redundant and time-consuming operations in the high-frequency callback APIs of the system, such as onScroll and onAreaChange. These APIs perform callback operations in each frame drawing of the system. Therefore, performing redundant and time-consuming operations in these APIs consumes a large number of system resources and affects the application running performance.

#### Do not frequently call the trace function in the system.

Printing trace information consumes extra system performance. Therefore, do not print trace information in these high-frequency callback APIs. The sample code is as follows:

```typescript
// Avoid the usage below.
Scroll() {
  ForEach(this.arr, (item: number) => {
    Text("ListItem" + item)
    .width("100%")
    .height("100%")
  }, (item: number) => item.toString())
}
.width('100%')
.height('100%')
.onScroll(() => {
  hitrace.startTrace("ScrollSlide", 1002);
  // Service logic
  // ...
  hitrace.finishTrace("ScrollSlide", 1002);
})

// Positive example
@Component
struct PositiveOfOnScroll {
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  build() {
    Scroll() {
      List() {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text("TextItem" + item)
          }
          .width("100%")
          .height(100)
        }, (item: number) => item.toString())
      }
      .divider({ strokeWidth: 3, color: Color.Gray })
    }
    .width('100%')
    .height('100%')
    .onScroll(() => {
      // Service logic
      // ...
    })
  }
}
```

#### Do not frequently call and print logs in the system.

Printing logs consumes extra system performance. Especially, some logs read status variable information, which increases resource overhead. Therefore, do not print logs in these high-frequency callback APIs. The sample code is as follows:

```typescript
// Avoid the usage below.
@Component
struct NegativeOfOnScroll {
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  build() {
    Scroll() {
      List() {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text("TextItem" + item)
          }
          .width("100%")
          .height(100)
        }, (item: number) => item.toString())
      }
      .divider({ strokeWidth: 3, color: Color.Gray })
    }
    .width('100%')
    .height('100%')
    .onScroll(() => {
      hilog.info(1002, 'Scroll', 'TextItem');
      // Service logic
      // ...
    })
  }
}

// Positive example
@Component
struct PositiveOfOnScroll {
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  build() {
    Scroll() {
      List() {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text("TextItem" + item)
          }
          .width("100%")
          .height(100)
        }, (item: number) => item.toString())
      }
      .divider({ strokeWidth: 3, color: Color.Gray })
    }
    .width('100%')
    .height('100%')
    .onScroll(() => {
      // Service logic
      // ...
    })
  }
}
```

### Redundant Trace and Log Printing Are Deleted

Trace and log printing consume system performance. Therefore, redundant trace and log printing must be avoided. You are advised to delete all trace information and debug logs in the release version to reduce extra system overhead.

#### Traces are deleted from the release version.

The trace function consumes system performance. Therefore, you are advised to delete the trace function in the release version.

The negative example code is as follows:

```typescript
@Component
struct NegativeOfTrace {
  aboutToAppear(): void {
    hitrace.startTrace("HITRACE_TAG_APP", 1003);
    // Service code.
    // ...
    hitrace.finishTrace("HITRACE_TAG_APP", 1003);
  }
  build() {
    // Service code.
    // ...
  }
}
```

The positive code is as follows:

```typescript
@Component
struct PositiveOfTrace {
  aboutToAppear(): void {
    // Service code.
    // ...
  }
  build() {
    // Service code.
    // ...
  }
}
```

#### Debug logs are deleted from the release version.

Although debug logs are not recorded in the release version, if parameters are concatenated in the input parameters of the logs, the string concatenation logic is still executed, which causes redundant overhead. Therefore, to avoid redundant operations during development (avoiding-redundant-operations.md), it is recommended that debug log recording be deleted in the release version.

The negative example code is as follows:

```typescript
@Component
struct NegativeOfDebug {
  @State string1: string = 'a';
  @State string2: string = 'b';

  aboutToAppear(): void {
    hilog.debug(1004, 'Debug', (this.string1 + this.string2));
    // Service code.
    // ...
  }

  build() {
    // Service code.
    // ...
  }
}
```

The positive code is as follows:

```typescript
@Component
struct PositiveOfDebug {
  aboutToAppear(): void {
    // Service code.
    // ...
  }
  build() {
    // Service code.
    // ...
  }
}
```

### Do not set redundant system callback listening.

Redundant system callback listening consumes extra system overhead for calculation and function callback. For example, if onAreaChange is set, even if there is no logic in the callback, the system calculates the size and position changes of the component on the C++ side and calls back the result to the TS side, which consumes extra system overhead.

The negative example code is as follows:

```typescript
@Component
struct NegativeOfOnClick {
  build() {
    Button('Click', { type: ButtonType.Normal, stateEffect: true })
      .onClick(() => {
        hitrace.startTrace("ButtonClick", 1004);
        hilog.info(1004, 'Click', 'ButtonType.Normal')
        hitrace.finishTrace("ButtonClick", 1004);
        // Service code.
        // ...
      })
      .onAreaChange((oldValue: Area, newValue: Area) => {
        //No code.
      })
  }
}
```

The positive code is as follows:

```typescript
@Component
struct PositiveOfOnClick {
  build() {
    Button('Click', { type: ButtonType.Normal, stateEffect: true })
      .onClick(() => {
        // Service code.
        // ...
      })
  }
```

## Use performance tools to analyze and locate problems.

Learn how to properly use tools to analyze and locate problems, improving problem solving efficiency.

### Learn how to use the Profier tool of the IDE to locate faults.

You can use the Profier tool to locate performance problems during application development. For details, see [Performance Analysis Tool CPU Profiler](application-performance-analysis.md).

### Using SmartPerf-Host to Analyze Application Performance

[SmartPerf-Host](performance-optimization-using-smartperf-host.md) is a performance and power consumption optimization tool that deeply mines data and displays data in a fine-grained manner. It can collect data such as CPU scheduling, frequency, process thread time slice, heap memory, and frame rate. The collected data is clearly displayed to developers in swimlanes and analyzed in a visualized manner on the GUI. The tool provides five analysis templates for developers: frame rate analysis, CPU/thread scheduling analysis, application startup analysis, task pool analysis, and dynamic effect analysis.

### Use the state variable component location tool to analyze the state variable association information.

Developers can use the status variable component locating tool (state_variable_dfx_pratice.md) to obtain status management information, such as status variables of customized components, synchronization objects of status variables, and associated components, understand the impact scope of status variables on the UI, and write high-performance application code.

### Use the common trace usage guide to locate performance problems.

This document describes the meanings and usage of common traces (common-trace-using-instructions.md) and how to use these traces to identify potential performance problems. In addition, this document describes the working principles of traces to help developers better understand the traces and how to collect and analyze performance data. After reading this article, developers will have an in-depth understanding of Trace and provide strong support for application performance optimization.
