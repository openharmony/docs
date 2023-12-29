# LazyForEach: Lazy Data Loading


**LazyForEach** iterates over provided data sources and creates corresponding components during each iteration. When **LazyForEach** is used in a scrolling container, the framework creates components as required within the visible area of the scrolling container. When a component is out of the visible area, the framework destroys and reclaims the component to reduce memory usage.


## API Description


```ts
LazyForEach(
    dataSource: IDataSource,             // Data source to iterate over.
    itemGenerator: (item: any, index?: number) => void,  // Child component generation function.
    keyGenerator?: (item: any, index?: number) => string // Key generation function.
): void
```

**Parameters**


| Name       | Type                                              | Mandatory| Description                                                    |
| ------------- | ------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataSource    | [IDataSource](#description-of-idatasource)                    | Yes  | **LazyForEach** data source. You need to implement related APIs.                 |
| itemGenerator | (item: any, index?:number) =&gt; void | Yes  | Child component generation function, which generates a child component for each data item in the array.<br>**NOTE**<br>**item** indicates the current data item, and **index** indicates the index of the data item.<br>The function body of **itemGenerator** must be included in braces {...}. **itemGenerator** can and must generate only one child component for each iteration. The **if** statement is allowed in **itemGenerator**, but you must ensure that each branch of the **if** statement creates a child component of the same type. **ForEach** and **LazyForEach** statements are not allowed in **itemGenerator**.|
| keyGenerator  | (item: any, index?:number) =&gt; string | No  | ID generation function, which generates a unique and fixed ID for each data item in the data source. This ID must remain unchanged for the data item even when the item is relocated in the array. When the item is replaced by a new item, the ID of the new item must be different from that of the replaced item. This ID generation function is optional. However, for performance reasons, it is strongly recommended that the ID generation function be provided, so that the framework can better identify array changes. For example, if no ID generation function is provided, a reverse of an array will result in rebuilding of all nodes in **LazyForEach**.<br>**NOTE**<br>**item** indicates the current data item, and **index** indicates the index of the data item.<br>The ID generated for each data item in the data source must be unique.|

## Description of IDataSource

```ts
interface IDataSource {
    totalCount(): number; // Obtain the total number of data items.
    getData(index: number): Object; // Obtain the data item that matches the specified index.
    registerDataChangeListener(listener: DataChangeListener): void; // Register a data change listener.
    unregisterDataChangeListener(listener: DataChangeListener): void; // Deregister the data change listener.
}
```

| Declaration                                                    | Parameter Type                                         | Description                                                       |
| ------------------------------------------------------------ | ------------------------------------------------- | ----------------------------------------------------------- |
| totalCount(): number                                    | -                                                 | Obtains the total number of data items.                                             |
| getData(index: number): any                        | number                                            | Obtains the data item that matches the specified index.<br>**index**: index of the data item to obtain.|
| registerDataChangeListener(listener:[DataChangeListener](#description-of-datachangelistener)): void | [DataChangeListener](#description-of-datachangelistener) | Registers a listener for data changes.<br>**listener**: listener for data changes.        |
| unregisterDataChangeListener(listener:[DataChangeListener](#description-of-datachangelistener)): void | [DataChangeListener](#description-of-datachangelistener) | Deregisters the listener for data changes.<br>**listener**: listener for data changes.        |

## Description of DataChangeListener

```ts
interface DataChangeListener {
    onDataReloaded(): void; // Invoked when data is reloaded.
    onDataAdded(index: number): void; // Invoked when data is added.
    onDataMoved(from: number, to: number): void; // Invoked when data is moved.
    onDataDeleted(index: number): void; // Invoked when data is deleted.
    onDataChanged(index: number): void; // Invoked when data is changed.
    onDataAdd(index: number): void; // Invoked when data is added.
    onDataMove(from: number, to: number): void; // Invoked when data is moved.
    onDataDelete(index: number): void; // Invoked when data is deleted.
    onDataChange(index: number): void; // Invoked when data is changed.
}
```

| Declaration                                                    | Parameter Type                              | Description                                                        |
| ------------------------------------------------------------ | -------------------------------------- | ------------------------------------------------------------ |
| onDataReloaded(): void                                  | -                                      | Invoked when all data is reloaded.<br>For data items whose key remains unchanged, the original child component is used. For data items whose key changes, a new child component is created.|
| onDataAdd(index: number): void<sup>8+</sup>        | number                                 | Invoked when data is added to the position indicated by the specified index.<br>**index**: index of the position where data is added.|
| onDataMove(from: number, to: number): void<sup>8+</sup> | from: number,<br>to: number | Invoked when data is moved.<br>**from**: original position of data; **to**: target position of data.<br>Data is swapped between the **from** and **to** positions.<br>**NOTE**<br>The ID must remain unchanged before and after data movement. If the ID changes, APIs for deleting and adding data must be called.|
| onDataDelete(index: number):void<sup>8+</sup>                | number                                 | Invoked when data is deleted from the position indicated by the specified index. LazyForEach will update the displayed content accordingly.<br>**index**: index of the position where data is deleted.<br>**NOTE**<br>Before **onDataDelete** is called, ensure that the corresponding data in **dataSource** has been deleted. Otherwise, undefined behavior will occur during page rendering.|
| onDataChange(index: number): void<sup>8+</sup>     | number                                 | Invoked when data in the position indicated by the specified index is changed.<br>**index**: index of the position where data is changed.|
| onDataAdded(index: number):void<sup>(deprecated)</sup>  | number                                 | Invoked when data is added to the position indicated by the specified index.<br>This API is deprecated since API version 8. You are advised to use **onDataAdd** instead.<br>**index**: index of the position where data is added.|
| onDataMoved(from: number, to: number): void<sup>(deprecated)</sup> | from: number,<br>to: number | Invoked when data is moved.<br>This API is deprecated since API version 8. You are advised to use **onDataMove** instead.<br>**from**: original position of data; **to**: target position of data.<br>Data is swapped between the **from** and **to** positions.<br>**NOTE**<br>The ID must remain unchanged before and after data movement. If the ID changes, APIs for deleting and adding data must be called.|
| onDataDeleted(index: number):void<sup>(deprecated)</sup>     | number                                 | Invoked when data is deleted from the position indicated by the specified index. LazyForEach will update the displayed content accordingly.<br>This API is deprecated since API version 8. You are advised to use **onDataDelete** instead.<br>**index**: index of the position where data is deleted.|
| onDataChanged(index: number): void<sup>(deprecated)</sup> | number                                 | Invoked when data in the position indicated by the specified index is changed.<br>This API is deprecated since API version 8. You are advised to use **onDataChange** instead.<br>**index**: listener for data changes.|


## Restrictions

- LazyForEach must be used in the container component. Only the [\<List>](../reference/arkui-ts/ts-container-list.md), [\<Grid>](../reference/arkui-ts/ts-container-grid.md), [\<Swiper>](../reference/arkui-ts/ts-container-swiper.md), and [\<WaterFlow>](../reference/arkui-ts/ts-container-waterflow.md) components support lazy loading (that is, only the visible part and a small amount of data before and after the visible part are loaded for caching). For other components, all data is loaded at the same time.
- **LazyForEach** must create one and only one child component in each iteration.
- The generated child components must be allowed in the parent container component of **LazyForEach**.
- **LazyForEach** can be included in an **if/else** statement, and can also contain such a statement.
- The ID generation function must generate a unique value for each piece of data. If the IDs are the same, the framework ignores the UI components with the same key value. As a result, these UI components cannot be displayed in the parent container.
- **LazyForEach** must be updated using a **DataChangeListener** object. When the first parameter **dataSource** uses a state variable, a state variable change does not trigger the UI update of **LazyForEach**.
- For better rendering performance, when the **onDataChange** API of the **DataChangeListener** object is used to update the UI, an ID different from the original one needs to be generated to trigger component re-rendering.

## Key Generation Rules

During **LazyForEach** rendering, the system generates a unique, persistent key for each item to identify the owing component. When the key changes, the ArkUI framework considers that the array element has been replaced or modified and creates a new component based on the new key.

**LazyForEach** provides a parameter named **keyGenerator**, which is in effect a function through which you can customize key generation rules. If no **keyGenerator** function is defined, the ArkUI framework uses the default key generator, that is, **(item: any, index: number) => { return viewId + '-' + index.toString(); }**, wherein **viewId** is generated during compiler conversion. The **viewId** values in the same **LazyForEach** component are the same.

## Component Creation Rules

After the key generation rules are determined, the **itemGenerator** function – the second parameter in **LazyForEach** – creates a component for each array item of the data source based on the rules. There are two cases for creating a component: [initial render](#initial-render) and [non initial render](#non-initial-render).

### Initial Render

- ### Generating Different Key Values

When used for initial render, **LazyForEach** generates a unique key for each array item of the data source based on the key generation rules, and creates a component.

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

  // This method is called by the framework to add a listener to the data source of the LazyForEach component.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  // This method is called by the framework to remove the listener from the data source of the LazyForEach component.
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

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource();
   
  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

In the preceding code snippets, the key generation rule is the return value **item** of the **keyGenerator** function. During **LazyForEach** rendering, keys (from **Hello 0**, **Hello 1**, through to **Hello 20**) are generated in sequence for data source array items, and corresponding list items are created and rendered to the UI.

The figure below shows the effect.

**Figure 1** Initial render of LazyForEach 
![LazyForEach-Render-DifferentKey](./figures/LazyForEach-Render-DifferentKey.gif)

- ### Incorrect Rendering When Keys Are the Same

When the keys generated for different data items are the same, the behavior of the framework is unpredictable. For example, in the following code, the keys of the data items rendered by **LazyForEach** are the same. During the swipe process, **LazyForEach** preloads child components for the current page. Because the new child component and the destroyed component have the same key, the framework may incorrectly obtain the cache. As a result, the child component rendering is abnormal.

 ```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

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

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
      }, (item: string) => 'same key')
    }.cachedCount(5)
  }
}
 ```

The figure below shows the effect. You can see that **Hello 0** is incorrectly rendered as **Hello 13** during the swiping.

**Figure 2** LazyForEach rendering when keys are the same 
![LazyForEach-Render-SameKey](./figures/LazyForEach-Render-SameKey.gif)

### Non Initial Render

When the **LazyForEach** data source changes and a re-render is required, call a listener API based on the data source change to notify **LazyForEach**. Below are some use cases.

- ### Adding Data

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

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

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
        .onClick(() => {
          // Click to add a child component.
          this.data.pushData(`Hello ${this.data.totalCount()}`);
        })
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

When the child component of **LazyForEach** is clicked, the **pushData** method of the data source is called first. This method adds data to the end of the data source and then calls the **notifyDataAdd** method. In the **notifyDataAdd** method, the **listener.onDataAdd** method is called to notify **LazyForEach** that data is added, and LazyForEach creates a child component at the position indicated by the specified index.

The figure below shows the effect.

**Figure 3** Adding data to LazyForEach 
![LazyForEach-Add-Data](./figures/LazyForEach-Add-Data.gif)

- ### Deleting Data

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    })
  }
}

class MyDataSource extends BasicDataSource {
  dataArray: string[] = [];

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
  
  public deleteData(index: number): void {
    this.dataArray.splice(index, 1);
    this.notifyDataDelete(index);
  }
}

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string, index: number) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
        .onClick(() => {
          // Click to delete a child component.
          this.data.deleteData(this.data.dataArray.indexOf(item));
        })
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

When the child component of **LazyForEach** is clicked, the **deleteData** method of the data source is called first. This method deletes data that matches the specified index from the data source and then calls the **notifyDatDelete** method. In the **notifyDataDelete** method, the **listener.onDataDelete** method is called to notify **LazyForEach** that data is deleted, and **LazyForEach** deletes the child component at the position indicated by the specified index.

The figure below shows the effect.

**Figure 4** Deleting data from LazyForEach 
![LazyForEach-Delete-Data](./figures/LazyForEach-Delete-Data.gif)

- ### Swapping Data

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    })
  }
}

class MyDataSource extends BasicDataSource {
  dataArray: string[] = [];

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
  
  public deleteData(index: number): void {
    this.dataArray.splice(index, 1);
    this.notifyDataDelete(index);
  }
  
  public moveData(from: number, to: number): void {
    let temp: string = this.dataArray[from];
    this.dataArray[from] = this.dataArray[to];
    this.dataArray[to] = temp;
    this.notifyDataMove(from, to);
  }
}

@Entry
@Component
struct MyComponent {
  private moved: number[] = [];
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string, index: number) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
        .onClick(() => {
          this.moved.push(this.data.dataArray.indexOf(item));
          if (this.moved.length === 2) {
          	// Click to move a child component.
          	this.data.moveData(this.moved[0], this.moved[1]);
            this.moved = [];
          }
        })
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

When a child component of **LazyForEach** is clicked, the index of the data to be moved is stored in the **moved** member variable. When another child component of **LazyForEach** is clicked, the first child component clicked is moved here. The **moveData** method of the data source is called to move the data from the original location to the expected location, after which the **notifyDatMove** method is called. In the **notifyDataMove** method, the **listener.onDataMove** method is called to notify **LazyForEach** that data needs to be moved. **LazyForEach** then swaps data between the **from** and **to** positions.

The figure below shows the effect.

**Figure 5** Swapping data in LazyForEach 
![LazyForEach-Exchange-Data](./figures/LazyForEach-Exchange-Data.gif)

- ### Changing a Data Item

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

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
  
  public deleteData(index: number): void {
    this.dataArray.splice(index, 1);
    this.notifyDataDelete(index);
  }
  
  public changeData(index: number, data: string): void {
    this.dataArray.splice(index, 1, data);
    this.notifyDataChange(index);
  }
}

@Entry
@Component
struct MyComponent {
  private moved: number[] = [];
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }


  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string, index: number) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
        .onClick(() => {
          this.data.changeData(index, item + '00');
        })
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

When the child component of **LazyForEach** is clicked, the data is changed first, and then the **changeData** method of the data source is called. In this method, the **notifyDataChange** method is called. In the **notifyDataChange** method, the **listener.onDataChange** method is called to notify **LazyForEach** of data changes. **LazyForEach** then rebuilds the child component that matches the specified index.

The figure below shows the effect.

**Figure 6** Changing a data item in LazyForEach 
![LazyForEach-Change-SingleData](./figures/LazyForEach-Change-SingleData.gif)

- ### Changing Multiple Data Items

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

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
  
  public deleteData(index: number): void {
    this.dataArray.splice(index, 1);
    this.notifyDataDelete(index);
  }
  
  public changeData(index: number): void {
    this.notifyDataChange(index);
  }
    
  public reloadData(): void {
    this.notifyDataReload();
  }
    
  public modifyAllData(): void {
    this.dataArray = this.dataArray.map((item: string) => {
        return item + '0';
    })
  }
}

@Entry
@Component
struct MyComponent {
  private moved: number[] = [];
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string, index: number) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
        .onClick(() => {
          this.data.modifyAllData();
          this.data.reloadData();
        })
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

When a child component of **LazyForEach** is clicked, the **modifyAllData** method of the data source is called to change all data items, and then the **reloadData** method of the data source is called. In this method, the **notifyDataReload** method is called. In the **notifyDataReload** method, the **listener.onDataReloaded** method is called to notify **LazyForEach** that all subnodes need to be rebuilt. **LazyForEach** compares the keys of all original data items with those of all new data items on a one-by-one basis. If the keys are the same, the cache is used. If the keys are different, the child component is rebuilt.

The figure below shows the effect.

**Figure 7** Changing multiple data items in LazyForEach 
![LazyForEach-Reload-Data](./figures/LazyForEach-Reload-Data.gif)

- ### Changing Data Subproperties

When **LazyForEach** is used for UI re-renders, a child component needs to be destroyed and rebuilt when the data item changes. This may result in low re-render performance when the child component structure is complex. This is where @Observed and @ObjectLink come into picture. By providing in-depth observation, @Observed and @ObjectLink enable precise re-renders of only components that use the changed properties. You can select a re-render mode that better suits your needs.

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: StringData[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): StringData {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: StringData[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): StringData {
    return this.dataArray[index];
  }

  public addData(index: number, data: StringData): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: StringData): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Observed
class StringData {
  message: string;
  constructor(message: string) {
    this.message = message;
  }  
}

@Entry
@Component
struct MyComponent {
  private moved: number[] = [];
  @State data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(new StringData(`Hello ${i}`));
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: StringData, index: number) => {
        ListItem() {
          ChildComponent({data: item})
        }
        .onClick(() => {
          item.message += '0';
        })
      }, (item: StringData, index: number) => index.toString())
    }.cachedCount(5)
  }
}

@Component
struct ChildComponent {
  @ObjectLink data: StringData
  build() {
    Row() {
      Text(this.data.message).fontSize(50)
        .onAppear(() => {
          console.info("appear:" + this.data.message)
        })
    }.margin({ left: 10, right: 10 })
  }
}
```

When the child component of **LazyForEach** is clicked, **item.message** is changed. As re-rendering depends on the listening of the @ObjectLink decorated member variable of **ChildComponent** on its subproperties. In this case, the framework only re-renders **Text(this.data.message)** and does not rebuild the entire **ListItem** child component.

**Figure 8** Changing data subproperties in LazyForEach 
![LazyForEach-Change-SubProperty](./figures/LazyForEach-Change-SubProperty.gif)

## FAQs

- ### Unexpected Rendering Result

  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: string[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): string {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  
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
    
    public deleteData(index: number): void {
      this.dataArray.splice(index, 1);
      this.notifyDataDelete(index);
    }
  }
  
  @Entry
  @Component
  struct MyComponent {
    private data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(`Hello ${i}`)
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: string, index: number) => {
          ListItem() {
            Row() {
              Text(item).fontSize(50)
                .onAppear(() => {
                  console.info("appear:" + item)
                })
            }.margin({ left: 10, right: 10 })
          }
          .onClick(() => {
            // Click to delete a child component.
            this.data.deleteData(index);
          })
        }, (item: string) => item)
      }.cachedCount(5)
    }
  }
  ```

  **Figure 9** Unexpected data deletion by LazyForEach 
  ![LazyForEach-Render-Not-Expected](./figures/LazyForEach-Render-Not-Expected.gif)

  When child components are clicked to be deleted, there may be cases where the deleted child component is not the one clicked. If this is the case, the indexes of data items are not updated correctly. In normal cases, after a child component is deleted, all data items following the data item of the child component should have their index decreased by 1. If these data items still use the original indexes, the indexes in **itemGenerator** do not change, resulting in the unexpected rendering result.

  The following shows the code snippet after optimization:

  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: string[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): string {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  
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
    
    public deleteData(index: number): void {
      this.dataArray.splice(index, 1);
      this.notifyDataDelete(index);
    }
      
    public reloadData(): void {
      this.notifyDataReload();
    }
  }
  
  @Entry
  @Component
  struct MyComponent {
    private data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(`Hello ${i}`)
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: string, index: number) => {
          ListItem() {
            Row() {
              Text(item).fontSize(50)
                .onAppear(() => {
                  console.info("appear:" + item)
                })
            }.margin({ left: 10, right: 10 })
          }
          .onClick(() => {
            // Click to delete a child component.
            this.data.deleteData(index);
            // Reset the indexes of all child components.
            this.data.reloadData();
          })
        }, (item: string, index: number) => item + index.toString())
      }.cachedCount(5)
    }
  }
  ```

  After a data item is deleted, the **reloadData** method is called to rebuild the subsequent data items to update the indexes.

  **Figure 10** Fixing unexpected data deletion 
  ![LazyForEach-Render-Not-Expected-Repair](./figures/LazyForEach-Render-Not-Expected-Repair.gif)

- ### Image Flickering During Re-renders

  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: StringData[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): StringData {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  
    notifyDataMove(from: number, to: number): void {
      this.listeners.forEach(listener => {
        listener.onDataMove(from, to);
      })
    }
  }
  
  class MyDataSource extends BasicDataSource {
    private dataArray: StringData[] = [];
  
    public totalCount(): number {
      return this.dataArray.length;
    }
  
    public getData(index: number): StringData {
      return this.dataArray[index];
    }
  
    public addData(index: number, data: StringData): void {
      this.dataArray.splice(index, 0, data);
      this.notifyDataAdd(index);
    }
  
    public pushData(data: StringData): void {
      this.dataArray.push(data);
      this.notifyDataAdd(this.dataArray.length - 1);
    }
      
    public reloadData(): void {
      this.notifyDataReload();
    }
  }
  
  class StringData {
    message: string;
    imgSrc: Resource;
    constructor(message: string, imgSrc: Resource) {
        this.message = message;
        this.imgSrc = imgSrc;
    }  
  }
  
  @Entry
  @Component
  struct MyComponent {
    private moved: number[] = [];
    private data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(new StringData(`Hello ${i}`, $r('app.media.img')));
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: StringData, index: number) => {
          ListItem() {
            Column() {
              Text(item.message).fontSize(50)
                .onAppear(() => {
                  console.info("appear:" + item.message)
                })
              Image(item.imgSrc)
                .width(500)
                .height(200)
            }.margin({ left: 10, right: 10 })
          }
          .onClick(() => {
            item.message += '00';
            this.data.reloadData();
          })
        }, (item: StringData, index: number) => JSON.stringify(item))
      }.cachedCount(5)
    }
  }
  ```

  **Figure 11** Unwanted image flickering with LazyForEach 
  ![LazyForEach-Image-Flush](./figures/LazyForEach-Image-Flush.gif)

  In the example, when a list item is clicked, only the **message** property of the item is changed. Yet, along with the text change comes the unwanted image flickering. This is because, with the **LazyForEach** update mechanism, the entire list item is rebuilt. As the **\<Image>** component is updated asynchronously, flickering occurs. To address this issue, use @ObjectLink and @Observed so that only the **\<Text>** component that uses the **item.message** property is re-rendered.

  The following shows the code snippet after optimization:

  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: StringData[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): StringData {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  
    notifyDataMove(from: number, to: number): void {
      this.listeners.forEach(listener => {
        listener.onDataMove(from, to);
      })
    }
  }
  
  class MyDataSource extends BasicDataSource {
    private dataArray: StringData[] = [];
  
    public totalCount(): number {
      return this.dataArray.length;
    }
  
    public getData(index: number): StringData {
      return this.dataArray[index];
    }
  
    public addData(index: number, data: StringData): void {
      this.dataArray.splice(index, 0, data);
      this.notifyDataAdd(index);
    }
  
    public pushData(data: StringData): void {
      this.dataArray.push(data);
      this.notifyDataAdd(this.dataArray.length - 1);
    }
  }
  
  @Observed
  class StringData {
    message: string;
    imgSrc: Resource;
    constructor(message: string, imgSrc: Resource) {
        this.message = message;
        this.imgSrc = imgSrc;
    }  
  }
  
  @Entry
  @Component
  struct MyComponent {
    @State data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(new StringData(`Hello ${i}`, $r('app.media.img')));
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: StringData, index: number) => {
          ListItem() {
            ChildComponent({data: item})
          }
          .onClick(() => {
            item.message += '0';
          })
        }, (item: StringData, index: number) => index.toString())
      }.cachedCount(5)
    }
  }
  
  @Component
  struct ChildComponent {
    @ObjectLink data: StringData
    build() {
      Column() {
        Text(this.data.message).fontSize(50)
          .onAppear(() => {
            console.info("appear:" + this.data.message)
          })
        Image(this.data.imgSrc)
          .width(500)
          .height(200)
      }.margin({ left: 10, right: 10 })
    }
  }
  ```

  **Figure 12** Fixing unwanted image flickering 
  ![LazyForEach-Image-Flush-Repair](./figures/LazyForEach-Image-Flush-Repair.gif)

- ### UI Not Re-rendered When @ObjectLink Property Is Changed

  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: StringData[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): StringData {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  
    notifyDataMove(from: number, to: number): void {
      this.listeners.forEach(listener => {
        listener.onDataMove(from, to);
      })
    }
  }
  
  class MyDataSource extends BasicDataSource {
    private dataArray: StringData[] = [];
  
    public totalCount(): number {
      return this.dataArray.length;
    }
  
    public getData(index: number): StringData {
      return this.dataArray[index];
    }
  
    public addData(index: number, data: StringData): void {
      this.dataArray.splice(index, 0, data);
      this.notifyDataAdd(index);
    }
  
    public pushData(data: StringData): void {
      this.dataArray.push(data);
      this.notifyDataAdd(this.dataArray.length - 1);
    }
  }
  
  @Observed
  class StringData {
    message: NestedString;
    constructor(message: NestedString) {
      this.message = message;
    }  
  }
  
  @Observed
  class NestedString {
    message: string;
    constructor(message: string) {
      this.message = message;
    }  
  }
  
  @Entry
  @Component
  struct MyComponent {
    private moved: number[] = [];
    @State data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(new StringData(new NestedString(`Hello ${i}`)));
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: StringData, index: number) => {
          ListItem() {
            ChildComponent({data: item})
          }
          .onClick(() => {
            item.message.message += '0';
          })
        }, (item: StringData, index: number) => item.toString() + index.toString())
      }.cachedCount(5)
    }
  }
  
  @Component
  struct ChildComponent {
    @ObjectLink data: StringData
    build() {
      Row() {
        Text(this.data.message.message).fontSize(50)
          .onAppear(() => {
            console.info("appear:" + this.data.message.message)
          })
      }.margin({ left: 10, right: 10 })
    }
  }
  ```

  **Figure 13** UI not re-rendered when @ObjectLink property is changed 
  ![LazyForEach-ObjectLink-NotRenderUI](./figures/LazyForEach-ObjectLink-NotRenderUI.gif)
  
  The member variable decorated by @ObjectLink can observe only changes of its sub-properties, not changes of nested properties. Therefore, to instruct a component to re-render, we need to change the component sub-properties. For details, see [\@Observed and \@ObjectLink Decorators](./arkts-observed-and-objectlink.md).
  
  The following shows the code snippet after optimization:
  
  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: StringData[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): StringData {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  
    notifyDataMove(from: number, to: number): void {
      this.listeners.forEach(listener => {
        listener.onDataMove(from, to);
      })
    }
  }
  
  class MyDataSource extends BasicDataSource {
    private dataArray: StringData[] = [];
  
    public totalCount(): number {
      return this.dataArray.length;
    }
  
    public getData(index: number): StringData {
      return this.dataArray[index];
    }
  
    public addData(index: number, data: StringData): void {
      this.dataArray.splice(index, 0, data);
      this.notifyDataAdd(index);
    }
  
    public pushData(data: StringData): void {
      this.dataArray.push(data);
      this.notifyDataAdd(this.dataArray.length - 1);
    }
  }
  
  @Observed
  class StringData {
    message: NestedString;
    constructor(message: NestedString) {
      this.message = message;
    }  
  }
  
  @Observed
  class NestedString {
    message: string;
    constructor(message: string) {
      this.message = message;
    }  
  }
  
  @Entry
  @Component
  struct MyComponent {
    private moved: number[] = [];
    @State data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(new StringData(new NestedString(`Hello ${i}`)));
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: StringData, index: number) => {
          ListItem() {
            ChildComponent({data: item})
          }
          .onClick(() => {
            item.message = new NestedString(item.message.message + '0');
          })
        }, (item: StringData, index: number) => item.toString() + index.toString())
      }.cachedCount(5)
    }
  }
  
  @Component
  struct ChildComponent {
    @ObjectLink data: StringData
    build() {
      Row() {
        Text(this.data.message.message).fontSize(50)
          .onAppear(() => {
            console.info("appear:" + this.data.message.message)
          })
      }.margin({ left: 10, right: 10 })
    }
  }
  ```
  
  **Figure 14** Fixing the UI-not-re-rendered issue 
  ![LazyForEach-ObjectLink-NotRenderUI-Repair](./figures/LazyForEach-ObjectLink-NotRenderUI-Repair.gif)
