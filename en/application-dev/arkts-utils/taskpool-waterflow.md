# ArkUI Waterfall Rendering
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

This topic describes how to use [TaskPool](../reference/apis-arkts/js-apis-taskpool.md) to improve the rendering performance of the [WaterFlow](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md) component. When the UI thread queries large volumes of data from the database and renders the data to the **WaterFlow** component, the UI may become unresponsive, negatively impacting user experience. To address this, we can offload data query to child threads and return the data to the UI thread using TaskPool APIs.

This example describes the following scenarios:
- A child thread [queries data from the database](batch-database-operations-guide.md) and returns the data to the UI thread.
- The UI thread detects data updates and renders the data returned from the child thread to the **WaterFlow** component.

1. Define an interface for the child thread to query data from the database and return the data to the UI thread.

    ```ts
    // Mock.ets
    import { taskpool } from '@kit.ArkTS';
    import { fillImg } from './Index';

    @Concurrent
    function query() {
      console.info("TaskPoolTest-this is query");
      let result = new Array<string>(33);
      for (let i = 0; i < 33; i++) {
        result[i] = 'Image' + i;
      }
      taskpool.Task.sendData(result);
    }


    export function getImgFromDB() {
      // Simulate the operation of querying the database and returning data.
      let task = new taskpool.Task(query);
      task.onReceiveData(fillImg);
      taskpool.execute(task);
    }
    ```
    <!-- @[query_database_return_main_thread](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/Mock.ets) -->

2. Encapsulate a waterfall data source for loading data to the **WaterFlow** component.

    ```ts
    // WaterFlowDataSource.ets

    // An object that implements the IDataSource interface, which is used by the WaterFlow component to load data.
    export class WaterFlowDataSource implements IDataSource {
      private dataArray: number[] = [];
      private listeners: DataChangeListener[] = [];

      constructor() {
        for (let i = 0; i < 100; i++) {
          this.dataArray.push(i);
        }
      }

      // Obtain the data corresponding to the specified index.
      public getData(index: number): number {
        return this.dataArray[index];
      }

      // Notify the controller that data has been reloaded.
      notifyDataReload(): void {
        this.listeners.forEach(listener => {
          listener.onDataReloaded();
        })
      }

      // Notify the controller that data has been added.
      notifyDataAdd(index: number): void {
        this.listeners.forEach(listener => {
          listener.onDataAdd(index);
        })
      }

      // Notify the controller that data has changed.
      notifyDataChange(index: number): void {
        this.listeners.forEach(listener => {
          listener.onDataChange(index);
        })
      }

      // Notify the controller that data has been deleted.
      notifyDataDelete(index: number): void {
        this.listeners.forEach(listener => {
          listener.onDataDelete(index);
        })
      }

      // Notify the controller that the data position has changed.
      notifyDataMove(from: number, to: number): void {
        this.listeners.forEach(listener => {
          listener.onDataMove(from, to);
        })
      }

      //Notify the controller that data has been deleted in batch.
      notifyDatasetChange(operations: DataOperation[]): void {
        this.listeners.forEach(listener => {
          listener.onDatasetChange(operations);
        })
      }

      // Obtain the total number of data records.
      public totalCount(): number {
        return this.dataArray.length;
      }

      // Register a controller for data changes.
      registerDataChangeListener(listener: DataChangeListener): void {
        if (this.listeners.indexOf(listener) < 0) {
          this.listeners.push(listener);
        }
      }

      // Unregister the controller for data changes.
      unregisterDataChangeListener(listener: DataChangeListener): void {
        const pos = this.listeners.indexOf(listener);
        if (pos >= 0) {
          this.listeners.splice(pos, 1);
        }
      }

      // Add data.
      public add1stItem(): void {
        this.dataArray.splice(0, 0, this.dataArray.length);
        this.notifyDataAdd(0);
      }

      // Add an element to the end of the data.
      public addLastItem(): void {
        this.dataArray.splice(this.dataArray.length, 0, this.dataArray.length);
        this.notifyDataAdd(this.dataArray.length - 1);
      }

      // Add an element at the specified index.
      public addItem(index: number): void {
        this.dataArray.splice(index, 0, this.dataArray.length);
        this.notifyDataAdd(index);
      }

      // Delete the first element.
      public delete1stItem(): void {
        this.dataArray.splice(0, 1);
        this.notifyDataDelete(0);
      }

      // Delete the second element.
      public delete2ndItem(): void {
        this.dataArray.splice(1, 1);
        this.notifyDataDelete(1);
      }

      // Delete the last element.
      public deleteLastItem(): void {
        this.dataArray.splice(-1, 1);
        this.notifyDataDelete(this.dataArray.length - 1);
      }

      // Delete an element at the specified index.
      public deleteItem(index: number): void {
        this.dataArray.splice(index, 1);
        this.notifyDataDelete(index);
      }

      // Reload the data.
      public reload(): void {
        this.dataArray.splice(1, 1);
        this.dataArray.splice(3, 2);
        this.notifyDataReload();
      }
    }
    ```
    <!-- @[encapsulate_waterfall_data_source](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/WaterFlowDataSource.ets) -->

3. During cold start of the application, call the **getImgFromDB()** interface to offload the data query operation to a child thread. After the img receives data from the child thread, render the data to the **WaterFlow** component.

    ```ts
    // Index.ets
    import { WaterFlowDataSource } from './WaterFlowDataSource';
    import { getImgFromDB } from './Mock';

    // Simulate an image array.
    let img = new Array<string>(33);
    export function fillImg(imgArr : Array<string>) {
      img = imgArr;
    }

    @Entry
    @Component
    struct WaterFlowDemo {
      @State minSize: number = 80;
      @State maxSize: number = 180;
      @State fontSize: number = 24;
      @State colors: number[] = [0xFFC0CB, 0xDA70D6, 0x6B8E23, 0x6A5ACD, 0x00FFFF, 0x00FF7F];
      scroller: Scroller = new Scroller();
      dataSource: WaterFlowDataSource = new WaterFlowDataSource();
      private itemWidthArray: number[] = [];
      private itemHeightArray: number[] = [];
      // Calculate the width and height of a flow item.
      getSize() {
        let ret = Math.floor(Math.random() * this.maxSize);
        return (ret > this.minSize ? ret : this.minSize);
      }

      // Set the width and height array of the flow item.
      setItemSizeArray() {
        for (let i = 0; i < 100; i++) {
          this.itemWidthArray.push(this.getSize());
          this.itemHeightArray.push(this.getSize());
        }
      }

      aboutToAppear() {
        this.setItemSizeArray();
      }

      @Builder
      itemFoot() {
        Column() {
          Text(`Footer`)
            .fontSize(10)
            .backgroundColor(Color.Red)
            .width(50)
            .height(50)
            .align(Alignment.Center)
            .margin({ top: 2 });
        }
      }

      build() {
        Column({ space: 2 }) {
          Text("ArkUI WaterFlow Demo")
            .onAppear(()=>{
              getImgFromDB();
            })
          WaterFlow() {
            LazyForEach(this.dataSource, (item: number) => {
              FlowItem() {
                Column() {
                  Text("N" + item)
                    .fontSize(12)
                    .height('16')
                    .onClick(()=>{

                    });
                  // To simulate image loading, use the Text component. For actual JPG loading, use the Image component directly. Example: Image(this.img[item % 33]).objectFit(ImageFit.Contain).width('100%').layoutWeight(1)
                  if (img[item % 33] == null) {
                    Text('Loading image...')
                      .width('100%')
                      .layoutWeight(1);
                  }
                  Text(img[item % 33])
                    .width('100%')
                    .layoutWeight(1);
                }
              }
              .onAppear(() => {
                // Pre-load more data when approaching the bottom.
                if (item + 20 == this.dataSource.totalCount()) {
                  for (let i = 0; i < 100; i++) {
                    this.dataSource.addLastItem();
                  }
                }
              })
              .width('100%')
              .height(this.itemHeightArray[item % 100])
              .backgroundColor(this.colors[item % 5])
            }, (item: string) => item)
          }
          .columnsTemplate("1fr 1fr")
          .columnsGap(10)
          .rowsGap(5)
          .backgroundColor(0xFAEEE0)
          .width('100%')
          .height('100%')
          .onReachStart(() => {
            console.info('TaskPoolTest-waterFlow reach start');
          })
          .onScrollStart(() => {
            console.info('TaskPoolTest-waterFlow scroll start');
          })
          .onScrollStop(() => {
            console.info('TaskPoolTest-waterFlow scroll stop');
          })
          .onScrollFrameBegin((offset: number, state: ScrollState) => {
            console.info('TaskPoolTest-waterFlow scrollFrameBegin offset: ' + offset + ' state: ' + state.toString());
            return { offsetRemain: offset };
          })
        }
      }
    }
    ```
    <!-- @[receive_child_thread_data_render_waterfall_component](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/WaterfallRendering.ets) -->
