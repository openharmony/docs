# Repeat: Reusing Child Components

>**NOTE**
>
>Repeat is supported since API version 12.
>

For details about API parameters, see [Repeat APIs](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-arkui/arkui-ts/ts-rendering-control-repeat.md).

In the non-virtualScroll scenario (that is, **virtualScroll** is disabled), **Repeat**, used together with container components, renders repeated components based on the data source. In addition, the component returned by the API must be a child component that can be contained in the **Repeat** parent container component. Compared with ForEach, **Repeat** optimizes the rendering performance in some update scenarios and generates function with the index maintained by the framework.

When virtualScroll is enabled, **Repeat** iterates data from the provided data source as required and creates the corresponding component during each iteration. In this way, **Repeat** must be used together with the scrolling container component. When **Repeat** is used in the scrolling container component, the framework creates components as required based on the visible area of the scrolling container. When a component slides out of the visible area, the framework caches the component and uses it in the next iteration.

> **Note:**
>
> When **virtualScroll** is enabled, **Repeat** is not fully compatible with the decorators of V1. Using them together may throw an exception during rendering.

## Constraints

- Repeat uses key value as identifiers. Therefore, **key()** must generate a unique value for each data.
- **Repeat virtualScroll** must be used in the scrolling container component. Only the [List](../reference/apis-arkui/arkui-ts/ts-container-list.md), [Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md), [Swiper](../reference/apis-arkui/arkui-ts/ts-container-swiper.md), and [WaterFlow](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md) components support this scenario. In this case, **cachedCount** takes effect. Other container components apply only to the non-virtualScroll scenario.
- After **virtualScroll** is enabled for **Repeat**, only one child component can be created in each iteration. Otherwise, there is no constraint. The generated child components must be allowed in the parent container component of **Repeat**.
- When **Repeat** and **\@Builder** are used together, parameters of the **RepeatItem** type must be passed so that the component can listen for data changes. If only **RepeatItem.item** or **RepeatItem.index** is passed, UI rendering exceptions occur.
- Currently, the template applies to scenarios where **virtualScroll** is enabled. If multiple template types are the same, **Repeat** overrides old **template()** and only the latest **template()** takes effect.
- If the value of **totalCount** is greater than that of **array.length**, when the parent component container is scrolling, the application should ensure that subsequent data is requested when the list is about to slide to the end of the data source until all data sources are loaded. Otherwise, the scrolling effect is abnormal. For details about the solution, see [The totalCount Value Is Greater Than the Length of Data Source](#the-totalcount-value-is-greater-than-the-length-of-data-source).

## Key Generation Rules

The purpose of **key()** is to allow **Repeat** to identify the details of array changes, including addition, deletion, and location (index) of data.

Suggestions:

- Even if there are duplicate data items (or the data source changes), you must ensure that the key is unique .
- Each time **key()** is executed, the same data item is used as the input, and the output must be consistent.
- Using index in **key()** is allowed, but not recommended. The reason is that the index changes when the data item is moved, that is, the key changes. Therefore, Repeat considers that the data item changes and triggers UI re-rendering, which deteriorates the performance.
- You are advised to convert a simple array to a class object array, add a **readonly id** property, and assign a unique value to it in the constructor.

### Non-virtualScroll

**key()** can be left empty. **Repeat** will generate the default key.

![Repeat-NonVS-KeyGen](./figures/Repeat-NonVS-KeyGen.png)

### virtualScroll

The rule is basically the same as that of non-virtualScroll: **key()** can be left empty.

![Repeat-VS-KeyGen](./figures/Repeat-VS-KeyGen.png)

## Component Generation and Reuse Rules

### non-virtualScroll

All child components are created when **Repeat** is rendered for the first time. The original components are reused when data is updated.

When the **Repeat** component updates data, it compares all keys in the last update with those in the latest update. If the current key is the same as the last one, **Repeat** reuses the child component and updates **RepeatItem.index**.

After **Repeat** compares all duplicate keys and reuses them, if the last key is unique and a new key is generated after this update, a child component needs to be created. In this case, **Repeat** will reuse redundant child components, update the **RepeatItem.item** data source and **RepeatItem.index**, and re-render the UI.

If the number of remaining child components is greater than or equal to the number of newly updated components, the components are fully reused and redundant components are released. If the number of remaining child components is less than the number of newly updated components, **Repeat** will create components corresponding to the extra data items after the remaining data items are all reused.

![Repeat-NonVS-FuncGen](./figures/Repeat-NonVS-FuncGen.png)

### virtualScroll

At the first time when **Repeat** renders child components, only the required component is generated. During sliding and data update, nodes on the lower screen are cached. When a new component needs to be generated, the cached component is reused.

#### Slide shortcut

The following figure describes the node state before sliding.

![Repeat-Start](./figures/Repeat-Start.PNG)

Currently, the **Repeat** component has two types of templateId. **templateId a** sets three as its maximum cache value for the corresponding cache pool. **templateId b** sets four as its maximum cache value and preloads one note for its parent components by default. Now swipe right on the screen, and **Repeat** will reuse the nodes in the cache pool.

![Repeat-Slide](./figures/Repeat-Slide.PNG)

The data of **index=18** enters the screen and the preloading range of the parent component, coming up with a result of **templateId b**. In this case, **Repeat** obtains a node from the **type=b** cache pool for reuse and updates its key, index, and data. Other grandchildren notes that use the data and index in the child node are updated based on the state management V2 rules.

The **index=10** note slides out of the screen and the preloading range of the parent component. When the UI main thread is idle, it checks whether the **type=a** cache pool has sufficient space. In this case, there are four nodes in the cache pool, which exceeds the rated three, so **Repeat** will release the last node.

![Repeat-Slide-Done](./figures/Repeat-Slide-Done.PNG)

#### Data Update Scenarios

![Repeat-Start](./figures/Repeat-Start.PNG)

In this case, delete the **index=12** node, update the data of the **index=13** node, change the **templateId b** to **templateId a** of the **index=14** node, and update the key of the **index=15** node.

![Repeat-Update1](./figures/Repeat-Update1.PNG)

Now, **Repeat** notifies the parent component to re-lay out the nodes and compares the keys one by one. If the template ID of the node is the same as that of the original one, the note is reused to update the **key**, **index** and **data**. Otherwise, the node in the cache pool with the same template ID is reused to update the **key**, **index**, and **data**.

![Repeat-Update2](./figures/Repeat-Update2.PNG)

As shown in the preceding figure, node13 updates **data** and **index**; node14 updates the template ID and **index** and reuses a node from the cache pool; node15 reuses its own node and updates the **key**, **index**, and **data** synchronously because of the changed **key** and the unchanged template ID; node 16 and node 17 only update the **index**. The **index=17** node is new and reused from the cache pool.

![Repeat-Update-Done](./figures/Repeat-Update-Done.PNG)

## totalCount

Total length of the data source, which can be greater than the number of loaded data items. Define the data source length as **arr.length**. The processing rules of **totalCount** are as follows:

- When **totalCount** is set to the default value or a non-natural number, the value of **totalCount** is **arr.length**, and the list scrolls normally.
- When **0** <= **totalCount** < **arr.length**, only **totalCount** list items are rendered.
- When **totalCount** is greater than **arr.length**, Repeat renders **totalCount** list items, and the scroll bar style changes based on the value of **totalCount**.

> **Note**<br>If **totalCount** is smaller than **arr.length**, when the parent component container is scrolling, the application needs to ensure that subsequent data is requested when the list is about to slide to the end of the data source. You need to fix the data request error (caused by, for example, network delay) until all data sources are loaded. Otherwise, the scrolling effect is abnormal.

## cachedCount

**cachedCount** indicates the maximum number of subnodes that can be cached in the **Repeat** cache pool of the current template. This parameter is valid only when **virtualScroll** is enabled.

You need to understand the differences between **.cachedCount()** of the scrolling container component and **cachedCount()** of **Repeat**. Both are used to balance performance and memory, but their definitions are different.

- **.cachedCount()** indicates the nodes that are located in the component tree and treated as invisible. Container components such as **List** or **Grid** render these nodes to achieve better performance. But **Repeat** treats these nodes as visible.
- **cachedCount()** of **Repeat** indicates the nodes that are treated as invisible by **Repeat**. These nodes are idle and are temporarily stored in the framework. You can update these nodes as required to implement reuse.

When **cachedCount** is set to the maximum number of nodes that may appear on the screen of the current template, **Repeat** can be reused as much as possible. However, when there is no node of the current template on the screen, the cache pool is not released and the application memory increases. You need to set the configuration based on the actual situation.

- If the default value is used, the framework calculates the value of **cachedCount** for each template based on the number of nodes displayed on the screen and the number of preloaded nodes. If the number increases, the value of **cachedCount** increases accordingly. Note that the value of cachedCount does not decrease.
- Explicitly specify **cachedCount**. It is recommended that the value be the same as the number of nodes on the screen. Yet, setting **cachedCount** to less than 2 is not advised. Doing so may lead to the creation of new nodes during rapid scrolling, which could result in performance degradation.

## Use Scenarios

### Non-virtualScroll

#### Changing the Data Source

```ts
@Entry
@ComponentV2
struct Parent {
  @Local simpleList: Array<string> = ['one', 'two', 'three'];

  build() {
    Row() {
      Column() {
        Text('Click to change the value of the third array item')
          .fontSize(24)
          .fontColor(Color.Red)
          .onClick(() => {
            this.simpleList[2] = 'new three';
          })

        Repeat<string>(this.simpleList)
            .each((obj: RepeatItem<string>)=>{
              ChildItem({ item: obj.item })
                .margin({top: 20})
            })
            .key((item: string) => item)
      }
      .justifyContent(FlexAlign.Center)
      .width('100%')
      .height('100%')
    }
    .height('100%')
    .backgroundColor(0xF1F3F5)
  }
}

@ComponentV2
struct ChildItem {
  @Param @Require item: string;

  build() {
    Text(this.item)
      .fontSize(30)
  }
}
```

![ForEach-Non-Initial-Render-Case-Effect](./figures/ForEach-Non-Initial-Render-Case-Effect.gif)

The component of the third array item is reused when the array item is re-rendered, and only the data is refreshed.

#### Changing the Index Value

In the following example, when array items 1 and 2 are exchanged, if the key is as the same as the last one, **Repeat** reuses the previous component and updates only the data of the component that uses the **index** value.

```ts
@Entry
@ComponentV2
struct Parent {
  @Local simpleList: Array<string> = ['one', 'two', 'three'];

  build() {
    Row() {
      Column() {
        Text ('Exchange array items 1 and 2')
          .fontSize(24)
          .fontColor(Color.Red)
          .onClick(() => {
            let temp: string = this.simpleList[2]
            this.simpleList[2] = this.simpleList[1]
            this.simpleList[1] = temp
          })
          .margin({bottom: 20})

        Repeat<string>(this.simpleList)
          .each((obj: RepeatItem<string>)=>{
            Text("index: " + obj.index)
              .fontSize(30)
            ChildItem({ item: obj.item })
              .margin({bottom: 20})
          })
          .key((item: string) => item)
      }
      .justifyContent(FlexAlign.Center)
      .width('100%')
      .height('100%')
    }
    .height('100%')
    .backgroundColor(0xF1F3F5)
  }
}

@ComponentV2
struct ChildItem {
  @Param @Require item: string;

  build() {
    Text(this.item)
      .fontSize(30)
  }
}
```

![Repeat-Non-Initial-Render-Case-Exchange-Effect](./figures/Repeat-Non-Initial-Render-Case-Exchange-Effect.gif)

### VirtualScroll

This section describes the actual application scenarios of **Repeat** and the reuse of component nodes in the **virtualScroll** scenario. A large number of test scenarios can be derived based on reuse rules. This section only describes typical data changes.

#### One template

The following code designs typical data source operations in the **virtualScroll** scenario of the **Repeat** component, including **inserting, modifying, deleting, and exchanging data**. Select an index value from the drop-down list and click the corresponding button to change the data. You can click two data items in sequence to exchange them.

```ts
@ObservedV2
class Repeat005Clazz {
  @Trace message: string = '';

  constructor(message: string) {
    this.message = message;
  }
}

@Entry
@ComponentV2
struct RepeatVirtualScroll {
  @Local simpleList: Array<Repeat005Clazz> = [];
  private exchange: number[] = [];
  private counter: number = 0;
  @Local selectOptions: SelectOption[] = [];
  @Local selectIdx: number = 0;

  @Monitor("simpleList")
  reloadSelectOptions(): void {
    this.selectOptions = [];
    for (let i = 0; i < this.simpleList.length; ++i) {
      this.selectOptions.push({ value: i.toString() });
    }
    if (this.selectIdx >= this.simpleList.length) {
      this.selectIdx = this.simpleList.length - 1;
    }
  }

  aboutToAppear(): void {
    for (let i = 0; i < 100; i++) {
      this.simpleList.push(new Repeat005Clazz(`item_${i}`));
    }
    this.reloadSelectOptions();
  }

  handleExchange(idx: number): void { // Click to exchange child components.
    this.exchange.push(idx);
    if (this.exchange.length === 2) {
      let _a = this.exchange[0];
      let _b = this.exchange[1];
      let temp: Repeat005Clazz = this.simpleList[_a];
      this.simpleList[_a] = this.simpleList[_b];
      this.simpleList[_b] = temp;
      this.exchange = [];
    }
  }

  build() {
    Column({ space: 10 }) {
      Text('virtualScroll each()&template() 1t')
        .fontSize(15)
        .fontColor(Color.Gray)
      Text('Select an index and press the button to update data.')
        .fontSize(15)
        .fontColor(Color.Gray)

      Select(this.selectOptions)
        .selected(this.selectIdx)
        .value(this.selectIdx.toString())
        .key('selectIdx')
        .onSelect((index: number) => {
          this.selectIdx = index;
        })
      Row({ space: 5 }) {
        Button('Add No.' + this.selectIdx)
          .onClick(() => {
            this.simpleList.splice(this.selectIdx, 0, new Repeat005Clazz(`${this.counter++}_add_item`));
            this.reloadSelectOptions();
          })
        Button('Modify No.' + this.selectIdx)
          .onClick(() => {
            this.simpleList.splice(this.selectIdx, 1, new Repeat005Clazz(`${this.counter++}_modify_item`));
          })
        Button('Del No.' + this.selectIdx)
          .onClick(() => {
            this.simpleList.splice(this.selectIdx, 1);
            this.reloadSelectOptions();
          })
      }
      Button('Update array length to 5.')
        .onClick(() => {
          this.simpleList = this.simpleList.slice(0, 5);
          this.reloadSelectOptions();
        })

      Text('Click on two items to exchange.')
        .fontSize(15)
        .fontColor(Color.Gray)

      List({ space: 10 }) {
        Repeat<Repeat005Clazz>(this.simpleList)
          .each((obj: RepeatItem<Repeat005Clazz>) => {
            ListItem() {
              Text(`[each] index${obj.index}: ${obj.item.message}`)
                .fontSize(25)
                .onClick(() => {
                  this.handleExchange(obj.index);
                })
            }
          })
          .key((item: Repeat005Clazz, index: number) => {
            return item.message;
          })
          .virtualScroll({ totalCount: this.simpleList.length })
          .templateId(() => "a")
          .template('a', (ri) => {
            Text(`[a] index${ri.index}: ${ri.item.message}`)
              .fontSize(25)
              .onClick(() => {
                this.handleExchange(ri.index);
              })
          }, { cachedCount: 3 })
      }
      .cachedCount(2)
      .border({ width: 1 })
      .width('95%')
      .height('40%')
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
  }
}
```
The application list contains 100 **message** properties of the custom class **RepeatClazz**. The value of **cachedCount** of the **List** component is set to **2**, and the cache pool size of the template A is set to **3**. The application screen is shown as bellow.

![Repeat-VirtualScroll-Demo](./figures/Repeat-VirtualScroll-Demo.gif)

#### Multiple templates

```
@ObservedV2
class Repeat006Clazz {
  @Trace message: string = '';

  constructor(message: string) {
    this.message = message;
  }
}

@Entry
@ComponentV2
struct RepeatVirtualScroll2T {
  @Local simpleList: Array<Repeat006Clazz> = [];
  private exchange: number[] = [];
  private counter: number = 0;
  @Local selectOptions: SelectOption[] = [];
  @Local selectIdx: number = 0;

  @Monitor("simpleList")
  reloadSelectOptions(): void {
    this.selectOptions = [];
    for (let i = 0; i < this.simpleList.length; ++i) {
      this.selectOptions.push({ value: i.toString() });
    }
    if (this.selectIdx >= this.simpleList.length) {
      this.selectIdx = this.simpleList.length - 1;
    }
  }

  aboutToAppear(): void {
    for (let i = 0; i < 100; i++) {
      this.simpleList.push(new Repeat006Clazz(`item_${i}`));
    }
    this.reloadSelectOptions();
  }

  handleExchange(idx: number): void { // Click to exchange child components.
    this.exchange.push(idx);
    if (this.exchange.length === 2) {
      let _a = this.exchange[0];
      let _b = this.exchange[1];
      let temp: Repeat006Clazz = this.simpleList[_a];
      this.simpleList[_a] = this.simpleList[_b];
      this.simpleList[_b] = temp;
      this.exchange = [];
    }
  }

  build() {
    Column({ space: 10 }) {
      Text('virtualScroll each()&template() 2t')
        .fontSize(15)
        .fontColor(Color.Gray)
      Text('Select an index and press the button to update data.')
        .fontSize(15)
        .fontColor(Color.Gray)

      Select(this.selectOptions)
        .selected(this.selectIdx)
        .value(this.selectIdx.toString())
        .key('selectIdx')
        .onSelect((index: number) => {
          this.selectIdx = index;
        })
      Row({ space: 5 }) {
        Button('Add No.' + this.selectIdx)
          .onClick(() => {
            this.simpleList.splice(this.selectIdx, 0, new Repeat006Clazz(`${this.counter++}_add_item`));
            this.reloadSelectOptions();
          })
        Button('Modify No.' + this.selectIdx)
          .onClick(() => {
            this.simpleList.splice(this.selectIdx, 1, new Repeat006Clazz(`${this.counter++}_modify_item`));
          })
        Button('Del No.' + this.selectIdx)
          .onClick(() => {
            this.simpleList.splice(this.selectIdx, 1);
            this.reloadSelectOptions();
          })
      }
      Button('Update array length to 5.')
        .onClick(() => {
          this.simpleList = this.simpleList.slice(0, 5);
          this.reloadSelectOptions();
        })

      Text('Click on two items to exchange.')
        .fontSize(15)
        .fontColor(Color.Gray)

      List({ space: 10 }) {
        Repeat<Repeat006Clazz>(this.simpleList)
          .each((obj: RepeatItem<Repeat006Clazz>) => {
            ListItem() {
              Text(`[each] index${obj.index}: ${obj.item.message}`)
                .fontSize(25)
                .onClick(() => {
                  this.handleExchange(obj.index);
                })
            }
          })
          .key((item: Repeat006Clazz, index: number) => {
            return item.message;
          })
          .virtualScroll({ totalCount: this.simpleList.length })
          .templateId((item: Repeat006Clazz, index: number) => {
            return (index % 2 === 0) ? 'odd' : 'even';
          })
          .template('odd', (ri) => {
            Text(`[odd] index${ri.index}: ${ri.item.message}`)
              .fontSize(25)
              .fontColor(Color.Blue)
              .onClick(() => {
                this.handleExchange(ri.index);
              })
          }, { cachedCount: 3 })
          .template('even', (ri) => {
            Text(`[even] index${ri.index}: ${ri.item.message}`)
              .fontSize(25)
              .fontColor(Color.Green)
              .onClick(() => {
                this.handleExchange(ri.index);
              })
          }, { cachedCount: 1 })
      }
      .cachedCount(2)
      .border({ width: 1 })
      .width('95%')
      .height('40%')
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
  }
}
```

![Repeat-VirtualScroll-2T-Demo](./figures/Repeat-VirtualScroll-2T-Demo.gif)

### Using Repeat in a Nesting Manner

 Example:

```ts
// Repeat can be nested in other components.
@Entry
@ComponentV2
struct RepeatNest {
  @Local outerList: string[] = [];
  @Local innerList: number[] = [];

  aboutToAppear(): void {
    for (let i = 0; i < 20; i++) {
      this.outerList.push(i.toString());
      this.innerList.push(i);
    }
  }

  build() {
    Column({ space: 20 }) {
      Text('Using Repeat virtualScroll in a Nesting Manner')
        .fontSize(15)
        .fontColor(Color.Gray)
      List() {
        Repeat<string>(this.outerList)
          .each((obj) => {
            ListItem() {
              Column() {
                Text('outerList item: ' + obj.item)
                  .fontSize(30)
                List() {
                  Repeat<number>(this.innerList)
                    .each((subObj) => {
                      ListItem() {
                        Text('innerList item: ' + subObj.item)
                          .fontSize(20)
                      }
                    })
                    .key((item) => "innerList_" + item)
                }
                .width('80%')
                .border({ width: 1 })
                .backgroundColor(Color.Orange)
              }
              .height('30%')
              .backgroundColor(Color.Pink)
            }
            .border({ width: 1 })
          })
          .key((item) => "outerList_" + item)
      }
      .width('80%')
      .border({ width: 1 })
    }
    .justifyContent(FlexAlign.Center)
    .width('90%')
    .height('80%')
  }
}
```

The figure below shows the effect.

![Repeat-Nest](./figures/Repeat-Nest.png)

## FAQs

### Ensure that the Position of the Scrollbar Remains Unchanged When the List Data Outside the Screen Changes

Declare the **Repeat** component in the **List** component to implement the **key** generation logic and **each** logic (as shown in the following sample code). Click **insert** to insert an element before the first element displayed on the screen, enabling the screen to scroll down.

```ts
// Define a class and mark it as observable.
// Customize an array in the class and mark it as traceable.
@ObservedV2
class ArrayHolder {
  @Trace arr: Array<number> = [];

  // constructor, used to initialize arrays.
  constructor(count: number) {
    for (let i = 0; i < count; i++) {
      this.arr.push(i);
    }
  }
}

@Entry
@ComponentV2
export struct RepeatTemplateSingle {
  @Local arrayHolder: ArrayHolder = new ArrayHolder(100);
  @Local totalCount: number = this.arrayHolder.arr.length;
  scroller: Scroller = new Scroller();

  build() {
    Column({ space: 5 }) {
      List({ space: 20, initialIndex: 19, scroller: this.scroller }) {
        Repeat(this.arrayHolder.arr)
          .virtualScroll({ totalCount: this.totalCount })
          .templateId((item, index) => {
            return 'number';
          })
          .template('number', (r) => {
            ListItem() {
              Text(r.index! + ":" + r.item + "Reuse");
            }
          })
          .each((r) => {
            ListItem() {
              Text(r.index! + ":" + r.item + "eachMessage");
            }
          })
      }
      .height('30%')

      Button(`insert totalCount ${this.totalCount}`)
        .height(60)
        .onClick(() => {
          // Insert an element which locates in the previous position displayed on the screen.
          this.arrayHolder.arr.splice(18, 0, this.totalCount);
          this.totalCount = this.arrayHolder.arr.length;
        })
    }
    .width('100%')
    .margin({ top: 5 })
  }
}
```

The figure below shows the effect.

![Repeat-case1-Error](./figures/Repeat-Case1-Error.gif)

In some scenarios, if you do not want the data source change outside the screen to affect the position where the **Scroller** of the **List** stays on the screen, you can use the [onScrollIndex](https://gitee.com/openharmony/docs/blob/master/en/application-dev/ui/arkts-layout-development-create-list.md#responding-to-the-scrolling-position) of the **List** component to listen for the scrolling action. When the list scrolls, you can obtain the scrolling position of a list. Use the [scrollToIndex](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-scroll.md#scrolltoindex) feature of the **Scroller** component to slide to the specified **index** position. In this way, when data is added to or deleted from the data source outside the screen, the position where the **Scroller** stays remains unchanged.

The following code shows the case of adding data to the data source.

```ts
// The definition of ArrayHolder is the same as that in the demo code.

@Entry
@ComponentV2
export struct RepeatTemplateSingle {
  @Local arrayHolder: ArrayHolder = new ArrayHolder(100);
  @Local totalCount: number = this.arrayHolder.arr.length;
  scroller: Scroller = new Scroller();

  private start: number = 1;
  private end: number = 1;

  build() {
    Column({ space: 5 }) {
      List({ space: 20, initialIndex: 19, scroller: this.scroller }) {
        Repeat(this.arrayHolder.arr)
          .virtualScroll({ totalCount: this.totalCount })
          .templateId((item, index) => {
            return 'number';
          })
          .template('number', (r) => {
            ListItem() {
              Text(r.index! + ":" + r.item + "Reuse");
            }
          })
          .each((r) => {
            ListItem() {
              Text(r.index! + ":" + r.item + "eachMessage");
            }
          })
      }
      .onScrollIndex((start, end) => {
        this.start = start;
        this.end = end;
      })
      .height('30%')

      Button(`insert totalCount ${this.totalCount}`)
        .height(60)
        .onClick(() => {
          // Insert an element which locates in the previous position displayed on the screen.
          this.arrayHolder.arr.splice(18, 0, this.totalCount);
          let rect = this.scroller.getItemRect(this.start); // Obtain the size and position of the child component.
          this.scroller.scrollToIndex(this.start + 1); // Slide to the specified index.
          this.scroller.scrollBy(0, -rect.y); // Slide by a specified distance.
          this.totalCount = this.arrayHolder.arr.length;
        })
    }
    .width('100%')
    .margin({ top: 5 })
  }
}
```

The figure below shows the effect.

![Repeat-case1-Succ](./figures/Repeat-Case1-Succ.gif)

### The totalCount Value Is Greater Than the Length of Data Source

When the total length of the data source is large, the lazy loading is used to load some data first. To enable **Repeat** to display the correct scrollbar style, you need to change the value of **totalCount** to the total length of data. That is, before all data sources are loaded, the value of **totalCount** is greater than that of **array.length**.

If **totalCount** is larger than **array.length**, when the parent component container is scrolling, the application needs to ensure that subsequent data is requested when the list is about to slide to the end of the data source. You need to fix the data request error (caused by, for example, network delay) until all data sources are loaded. Otherwise, the scrolling effect is abnormal.

You can use the callback of [onScrollIndex](https://gitee.com/openharmony/docs/blob/master/en/application-dev/ui/arkts-layout-development-create-list.md#controlling-the-scrolling-position) attribute of the **List** or **Grid** parent component to implement the preceding specification. The sample code is as follows:

```ts
@ObservedV2
class VehicleData {
  @Trace name: string;
  @Trace price: number;

  constructor(name: string, price: number) {
    this.name = name;
    this.price = price;
  }
}

@ObservedV2
class VehicleDB {
  public vehicleItems: VehicleData[] = [];

  constructor() {
    // init data size 20
    for (let i = 1; i <= 20; i++) {
      this.vehicleItems.push(new VehicleData(`Vehicle${i}`, i));
    }
  }
}

@Entry
@ComponentV2
struct entryCompSucc {
  @Local vehicleItems: VehicleData[] = new VehicleDB().vehicleItems;
  @Local listChildrenSize: ChildrenMainSize = new ChildrenMainSize(60);
  @Local totalCount: number = this.vehicleItems.length;
  scroller: Scroller = new Scroller();

  build() {
    Column({ space: 3 }) {
      List({ scroller: this.scroller }) {
        Repeat(this.vehicleItems)
          .virtualScroll({ totalCount: 50 }) // total data size 50
          .templateId(() => 'default')
          .template('default', (ri) => {
            ListItem() {
              Column() {
                Text(`${ri.item.name} + ${ri.index}`)
                  .width('90%')
                  .height(this.listChildrenSize.childDefaultSize)
                  .backgroundColor(0xFFA07A)
                  .textAlign(TextAlign.Center)
                  .fontSize(20)
                  .fontWeight(FontWeight.Bold)
              }
            }.border({ width: 1 })
          }, { cachedCount: 5 })
          .each((ri) => {
            ListItem() {
              Text("Wrong: " + `${ri.item.name} + ${ri.index}`)
                .width('90%')
                .height(this.listChildrenSize.childDefaultSize)
                .backgroundColor(0xFFA07A)
                .textAlign(TextAlign.Center)
                .fontSize(20)
                .fontWeight(FontWeight.Bold)
            }.border({ width: 1 })
          })
          .key((item, index) => `${index}:${item}`)
      }
      .height('50%')
      .margin({ top: 20 })
      .childrenMainSize(this.listChildrenSize)
      .alignListItem(ListItemAlign.Center)
      .onScrollIndex((start, end) => {
        console.log('onScrollIndex', start, end);
        // lazy data loading
        if (this.vehicleItems.length < 50) {
          for (let i = 0; i < 10; i++) {
            if (this.vehicleItems.length < 50) {
              this.vehicleItems.push(new VehicleData("Vehicle_loaded", i));
            }
          }
        }
      })
    }
  }
}
```

The figure below shows the effect.

![Repeat-Case2-Succ](./figures/Repeat-Case2-Succ.gif)

### Constraints on the Mixed Use of Repeat and @Builder

When **Repeat** and \@Builder are used together, parameters of the **RepeatItem** type must be passed so that the component can listen for data changes. If only **RepeatItem.item** or **RepeatItem.index** is passed, UI rendering exceptions occur.

The sample code is as follows:

```ts
@Entry
@ComponentV2
struct RepeatBuilderPage {
  @Local simpleList1: Array<number> = [];
  @Local simpleList2: Array<number> = [];

  aboutToAppear(): void {
    for (let i = 0; i < 100; i++) {
      this.simpleList1.push(i)
      this.simpleList2.push(i)
    }
  }

  build() {
    Column({ space: 20 }) {
      Text('Use Repeat and @Builder together: The abnormal display is on the left, and the normal display is on the right.')
        .fontSize(15)
        .fontColor(Color.Gray)

      Row({ space: 20 }) {
        List({ initialIndex: 5, space: 20 }) {
          Repeat<number>(this.simpleList1)
            .each((ri) => {})
            .virtualScroll({ totalCount: this.simpleList1.length })
            .templateId((item: number, index: number) => "default")
            .template('default', (ri) => {
              ListItem() {
                Column() {
                  Text('Text id = ' + ri.item)
                    .fontSize(20)
                  this.buildItem1 (ri.item) // Change to this.buildItem1(ri).
                }
              }
              .border({ width: 1 })
            }, { cachedCount: 3 })
        }
        .cachedCount(1)
        .border({ width: 1 })
        .width('45%')
        .height('60%')

        List({ initialIndex: 5, space: 20 }) {
          Repeat<number>(this.simpleList2)
            .each((ri) => {})
            .virtualScroll({ totalCount: this.simpleList2.length })
            .templateId((item: number, index: number) => "default")
            .template('default', (ri) => {
              ListItem() {
                Column() {
                  Text('Text id = ' + ri.item)
                    .fontSize(20)
                  this.buildItem2(ri)
                }
              }
              .border({ width: 1 })
            }, { cachedCount: 3 })
        }
        .cachedCount(1)
        .border({ width: 1 })
        .width('45%')
        .height('60%')
      }
    }
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }

  @Builder
  // The @Builder parameter must be of the RepeatItem type for normal rendering.
  buildItem1(item: number) {
    Text('Builder1 id = ' + item)
      .fontSize(20)
      .fontColor(Color.Red)
      .margin({ top: 2 })
  }

  @Builder
  buildItem2(ri: RepeatItem<number>) {
    Text('Builder2 id = ' + ri.item)
      .fontSize(20)
      .fontColor(Color.Red)
      .margin({ top: 2 })
  }
}
```

The following figure shows the display effect. Swipe down the list and you can see the difference.The incorrect usage is on the left, and the correct usage is on the right. (The **Text** component is in black and the **Builder** component is in red). The preceding code shows the error-prone scenario during development. That is, only the value, instead the entire **RepeatItem** class, is passed in the @Builder function.

![Repeat-Builder](./figures/Repeat-Builder.png)
