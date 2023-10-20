# LazyForEach: Lazy Data Loading


**LazyForEach** iterates over provided data sources and creates corresponding components during each iteration. When **LazyForEach** is used in a scrolling container, the framework creates components as required within the visible area of the scrolling container. When a component is out of the visible area, the framework destroys and reclaims the component to reduce memory usage.


## API Description


```ts
LazyForEach(
    dataSource: IDataSource,             // Data source to iterate over.
    itemGenerator: (item: Object) => void,  // Data source to iterate over.
    keyGenerator?: (item: Object): string => string // Data source to iterate over.
): void
```

**Parameters**


| Name       | Type                               | Mandatory| Description                                                    |
| ------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| dataSource    | [IDataSource](#description-of-idatasource)     | Yes  | **LazyForEach** data source. You need to implement related APIs.                 |
| itemGenerator | (item: any) =&gt; void   | Yes  | Child component generation function, which generates a child component for each data item in the array.<br>**NOTE**<br>The function body of **itemGenerator** must be included in braces {...}. **itemGenerator** can and must generate only one child component for each iteration. The **if** statement is allowed in **itemGenerator**, but you must ensure that each branch of the **if** statement creates a child component of the same type. **ForEach** and **LazyForEach** statements are not allowed in **itemGenerator**.|
| keyGenerator  | (item: any) =&gt; string | No  | ID generation function, which generates a unique and fixed ID for each data item in the data source. This ID must remain unchanged for the data item even when the item is relocated in the array. When the item is replaced by a new item, the ID of the new item must be different from that of the replaced item. This ID generation function is optional. However, for performance reasons, it is strongly recommended that the ID generation function be provided, so that the framework can better identify array changes. For example, if no ID generation function is provided, a reverse of an array will result in rebuilding of all nodes in **LazyForEach**.<br>**NOTE**<br>The ID generated for each data item in the data source must be unique.|

## Description of IDataSource

```ts
interface IDataSource {
    totalCount(): number; // Obtain the total number of data records.
    getData(index: number): Object; // Obtain the data that matches the specified index.
    registerDataChangeListener(listener: DataChangeListener): void; // Register a data change listener.
    unregisterDataChangeListener(listener: DataChangeListener): void; // Deregister the data change listener.
}
```

| Declaration                                                    | Parameter Type                                         | Description                                                       |
| ------------------------------------------------------------ | ------------------------------------------------- | ----------------------------------------------------------- |
| totalCount(): number                                    | -                                                 | Obtains the total number of data records.                                             |
| getData(index: number): any                        | number                                            | Obtains the data record corresponding to the specified index.<br>**index**: index of the data record to obtain.|
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
    onDataChange(index: number): void; // Invoked when data is deleted
}
```

| Declaration                                                    | Parameter Type                              | Description                                                        |
| ------------------------------------------------------------ | -------------------------------------- | ------------------------------------------------------------ |
| onDataReloaded(): void                                  | -                                      | Invoked when all data is reloaded.                                  |
| onDataAdd(index: number): void<sup>8+</sup>        | number                                 | Invoked when data is added to the position indicated by the specified index.<br>**index**: index of the position where data is added.|
| onDataMove(from: number, to: number): void<sup>8+</sup> | from: number,<br>to: number | Invoked when data is moved.<br>**from**: original position of data; **to**: target position of data.<br>**NOTE**<br>The ID must remain unchanged before and after data movement. If the ID changes, APIs for deleting and adding data must be called.|
| onDataDelete(index: number):void<sup>8+</sup>                | number                                 | Invoked when data is deleted from the position indicated by the specified index. LazyForEach will update the displayed content accordingly.<br>**index**: index of the position where data is deleted.<br>**NOTE**<br>Before **onDataDelete** is called, ensure that the corresponding data in **dataSource** has been deleted. Otherwise, undefined behavior will occur during page rendering.|
| onDataChange(index: number): void<sup>8+</sup>     | number                                 | Invoked when data in the position indicated by the specified index is changed.<br>**index**: index of the position where data is changed.|
| onDataAdded(index: number):void<sup>(deprecated)</sup>  | number                                 | Invoked when data is added to the position indicated by the specified index.<br>This API is deprecated since API version 8. You are advised to use **onDataAdd** instead.<br>**index**: index of the position where data is added.|
| onDataMoved(from: number, to: number): void<sup>(deprecated)</sup> | from: number,<br>to: number | Invoked when data is moved.<br>This API is deprecated since API version 8. You are advised to use **onDataMove** instead.<br>**from**: original position of data; **to**: target position of data.<br>**NOTE**<br>The ID must remain unchanged before and after data movement. If the ID changes, APIs for deleting and adding data must be called.|
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

- The call sequence of **itemGenerator** functions may be different from the order of the data items in the data source. Therefore, do not assume whether or when the **itemGenerator** and **keyGenerator** functions are executed. For example, the following example may not run properly:


  ```ts
  LazyForEach(dataSource, 
    (item: Object) => Text(`${item.i}. item.data.label`),
    (item: Object): string => item.data.id.toString())
  ```


## Example


```ts
// Basic implementation of IDataSource to handle data listener
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): Object {
    return undefined;
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

  public getData(index: number): Object {
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
  aboutToAppear() {
    for (let i = 100; i >= 80; i--) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  private data: MyDataSource = new MyDataSource();

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
          this.data.pushData(`Hello ${this.data.totalCount()}`);
        })
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```
