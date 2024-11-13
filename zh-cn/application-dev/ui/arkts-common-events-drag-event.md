# 拖拽事件

## 概述

拖拽框架提供了一种通过鼠标或手势触屏的方式传递数据，即从一个组件位置拖出数据，并拖入到另一个组件位置上进行响应，拖出一方提供数据，拖入一方接收和处理数据。该操作可以让用户方便地移动、复制或删除指定内容。

* 拖拽操作：在某个能够响应拖出的组件上长按并滑动触发的拖拽行为，当用户释放时，拖拽操作结束；
* 拖拽背景（背板）：用户所拖动数据的形象化表示，开发者可通过[onDragStart](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragstart)的[CustomerBuilder](../reference/apis-arkui/arkui-ts/ts-types.md#custombuilder8)或[DragItemInfo](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明)设置，也可以通过[dragPreview](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#dragpreview11)通用属性设置；
* 拖拽内容：拖动的数据，使用UDMF统一API [UnifiedData](../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) 进行封装；
* 拖出对象：触发拖拽操作并提供数据的组件；
* 拖入目标：可接收并处理拖动数据的组件；
* 拖拽点：鼠标或手指等与屏幕的接触位置，是否进入组件范围的判定是以接触点是否进入范围进行判断。

## 拖拽流程

### ​手势拖拽

​对于手势长按触发拖拽的场景，发起拖拽前框架侧会对当前组件是否可拖拽进行校验，针对默认可拖出的组件（[Search](../reference/apis-arkui/arkui-ts/ts-basic-components-search.md)、[TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)、[TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md)、[RichEditor](../reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md)、[Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md)、[Image](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md)、<!--Del-->[FormComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-formcomponent-sys.md)、<!--DelEnd-->[Hyperlink](../reference/apis-arkui/arkui-ts/ts-container-hyperlink.md)）需要判断是否设置了[draggable](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#draggable)属性为true（若系统使能分层参数，则draggable默认为true），其他组件需要额外判断是否设置了onDragStart回调函数，在满足上述可拖拽条件下，长按大于等于500ms可触发拖拽，长按800ms开始做预览图的浮起动效。

手势拖拽（手指/手写笔）触发拖拽流程：

![zh-cn_image_0000001562820825](figures/zh-cn_image_0000001562820825.png)

### ​鼠标拖拽

鼠标拖拽属于即拖即走，只要鼠标左键在可拖拽的组件上按下并移动大于1vp就可触发拖拽。

当前支持应用内和跨应用拖拽，提供了多个回调事件供开发者感知拖拽状态并干预系统默认拖拽行为，具体如下：

| **回调事件** | **说明**|
| ---------------- | ------------------------|
| onDragStart | 支持拖出的组件产生拖出动作时触发。<br>该回调可以感知拖拽行为的发起，开发者可通过在 onDragStart 方法中设置拖拽所传递的数据以及自定义拖拽背板图。推荐开发者使用pixelmap的方式返回背板图，不推荐使用customBuilder的方式，会有额外的性能开销。|
| onDragEnter | 当拖拽活动的拖拽点进入组件范围内时触发，只有该组件监听了[onDrop](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondrop)事件时，此回调才会被触发。|
| onDragMove| 拖拽点在组件范围内移动时触发；只有该组件监听了onDrop事件时，此回调才会被触发。<br>在此过程中可通过[DragEvent](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent)中的setResult方法影响系统部分场景下的外观<br>1. 设置DragResult.DROP\_ENABLED；<br>2. 设置DragResult.DROP\_DISABLED。|
| onDragLeave | 拖拽点离开组件范围时触发；只有该组件监听了onDrop事件时，此回调才会被触发。<br>针对以下两种情况默认不会发送onDragLeave事件：<br>1. 父组件移动到子组件；<br>2. 目标组件与当前组件布局有重叠。<br>API version 12开始可通过[UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md)中的[setDragEventStrictReportingEnabled](../reference/apis-arkui/js-apis-arkui-UIContext.md#setdrageventstrictreportingenabled12)方法严格触发onDragLeave事件。|
| onDrop | 当用户在组件范围内释放时触发，需在此回调中通过DragEvent中的setResult方法设置拖拽结果，否则在拖出方组件的onDragEnd方法中通过getResult方法只能拿到默认的处理结果DragResult.DRAG\_FAILED。<br>该回调也是开发者干预系统默认拖入处理行为的地方，系统会优先执行开发者的onDrop回调，通过在回调中执行setResult方法来告知系统该如何处理所拖拽的数据；<br>1. 设置 DragResult.DRAG\_SUCCESSFUL，数据完全由开发者自己处理，系统不进行处理；<br>2. 设置DragResult.DRAG\_FAILED，数据不再由系统继续处理；<br>3. 设置DragResult.DRAG\_CANCELED，系统也不需要进行数据处理；<br>4. 设置DragResult.DROP\_ENABLED或DragResult.DROP\_DISABLED会被忽略，同设置DragResult.DRAG\_FAILED。|
| onDragEnd | 当用户释放拖拽时，拖拽活动结束，发起拖出动作的组件会触发该回调。|
| onPreDrag | 绑定此事件的组件，当触发拖拽发起前的不同阶段时，触发回调。<br>开发者可以使用该方法监听[PreDragStatus](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#predragstatus12枚举说明)中的枚举在发起拖拽前的不同阶段准备数据。<br>1. ACTION\_DETECTING\_STATUS：拖拽手势启动阶段。(按下50ms时触发)；<br>2. READY\_TO\_TRIGGER\_DRAG\_ACTION：拖拽准备完成，可发起拖拽阶段。(按下500ms时触发)；<br>3. PREVIEW\_LIFT\_STARTED：拖拽浮起动效发起阶段。(按下800ms时触发)；<br>4. PREVIEW\_LIFT\_FINISHED：拖拽浮起动效结束阶段。(浮起动效完全结束时触发)；<br>5. PREVIEW\_LANDING\_STARTED：拖拽落回动效发起阶段。(落回动效发起时触发)；<br>6. PREVIEW\_LANDING\_FINISHED：拖拽落回动效结束阶段。(落回动效结束时触发)；<br>7. ACTION\_CANCELED\_BEFORE\_DRAG：拖拽浮起落位动效中断。(已满足READY\_TO\_TRIGGER\_DRAG\_ACTION状态后，未达到动效阶段，手指抬手时触发)。 |

更多用法参考[拖拽事件](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md)。

[DragEvent](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent)支持相关get方法获取拖拽行为的相关信息，下表列出了get方法在对应拖拽回调中是否能返回有效数据。
| 回调事件 | onDragStart | onDragEnter | onDragMove | onDragLeave | onDrop | onDragEnd |
| - | - | - | - | - | - | - |
| getData         |   |   |   |   | 支持 |   |
| getSummary      |   | 支持 | 支持 | 支持 | 支持 |   |
| getResult       |   |   |   |   |   | 支持 |
| getPreviewRect  |   |   |   |   | 支持 |   |
| getVelocity/X/Y |   | 支持 | 支持 | 支持 | 支持 |   |
| getWindowX/Y    | 支持 | 支持 | 支持 | 支持 | 支持 |   |
| getDisplayX/Y   | 支持 | 支持 | 支持 | 支持 | 支持 |   |
| getX/Y          | 支持 | 支持 | 支持 | 支持 | 支持 |   |
| behavior        |   |   |   |   |   | 支持 |

[DragEvent](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent)支持相关set方法向系统传递信息，这些信息部分会影响系统对UI或数据的处理方式。下表列出了set方法应该在回调的哪个阶段执行才会被系统接受并处理。
| 回调事件 | onDragStart | onDragEnter | onDragMove | onDragLeave | onDrop |
| - | - | - | - | - | - |
| useCustomDropAnimation |   |   |   |   | 支持 |
| setData                | 支持 |   |   |   |   |
| setResult              | 支持，可通过set failed或cancel来阻止拖拽发起 | 支持，不作为最终结果传递给onDragEnd | 支持，不作为最终结果传递给onDragEnd | 支持，不作为最终结果传递给onDragEnd  | 支持，作为最终结果传递给onDragEnd |
| behavior               |   | 支持 | 支持 | 支持 | 支持 |

## 拖拽背板图

拖拽移动过程中显示的拖拽背板图，并非是组件本身，其是用户拖动数据的表示，开发者可以将其设置为任意可显示的图像。其中onDragStart 回调返回的customBuilder或pixelmap可以设置拖拽移动过程中的背板图，浮起图默认使用组件本身的截图；dragpreview属性设置的customBuilder或pixelmap可以设置浮起和拖拽过程的背板图；如果开发者没有配置背板图，则系统会默认取组件本身的截图作为浮起及拖拽过程中的背板图。

拖拽背板图当前支持设置透明度、圆角、阴影和模糊，具体用法见：[拖拽控制](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md)。

**约束：**

* 对于容器组件，如果内部内容通过position，offset等手段使得绘制区域超出了容器组件范围，则系统截图无法截取到范围之外的内容，此种情况下，如果一定要浮起及拖拽背板能够包含范围之外的内容，则可考虑通过扩大容器范围或自定义方式进行；
* 不管是使用自定义builder或是系统默认截图方式，截图都暂时无法应用[scale](../reference/apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#scale)、[rotate](../reference/apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#rotate)等图形变换效果。

## 开发步骤

### 通用拖拽适配

如下以[Image](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md)组件为例，介绍组件拖拽开发的基本步骤，以及开发中需要注意的事项。

1. 组件使能拖拽。

   设置draggable属性为true，并设置onDragStart回调，回调中可以通过UDMF设置拖拽的数据，并返回自定义拖拽背板图；

    ```ts
    import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';

    Image($r('app.media.app_icon'))
        .width(100)
        .height(100)
        .draggable(true)
        .onDragStart((event) => {
            let data: unifiedDataChannel.Image = new unifiedDataChannel.Image();
            data.imageUri = 'common/pic/img.png';
            let unifiedData = new unifiedDataChannel.UnifiedData(data);
            event.setData(unifiedData);

            let dragItemInfo: DragItemInfo = {
            pixelMap: this.pixmap,
            extraInfo: "this is extraInfo",
            };
            // onDragStart回调函数中返回自定义拖拽背板图
            return dragItemInfo;
        })
    ```

   手势场景触发拖拽依赖底层绑定的长按手势，若开发者在被拖拽组件上也绑定长按手势，则会与底层的长按手势发生竞争，导致拖拽失败。可以用并行手势解决此类问题，如下：

    ```ts
    .parallelGesture(LongPressGesture().onAction(() => {
       promptAction.showToast({ duration: 100, message: 'Long press gesture trigger' });
    }))
    ```

2. 自定义拖拽背板图。
   
   自定义拖拽背板图的pixmap可以通过设置[onPreDrag](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#onpredrag12)函数在长按50ms时触发的回调中前提准备；
   
    ```ts
    .onPreDrag((status: PreDragStatus) => {
        if (preDragStatus == PreDragStatus.ACTION_DETECTING_STATUS) {
            this.getComponentSnapshot();
        }
    })
    ```
   
   具体pixmap的生成可以调用[componentSnapshot.createFromBuilder](../reference/apis-arkui/js-apis-arkui-componentSnapshot.md#componentsnapshotcreatefrombuilder)函数；

      ```ts
      @Builder
      pixelMapBuilder() {
          Column() {
            Image($r('app.media.startIcon'))
              .width(120)
              .height(120)
              .backgroundColor(Color.Yellow)
          }
        }
        private getComponentSnapshot(): void {
        this.getUIContext().getComponentSnapshot().createFromBuilder(()=>{this.pixelMapBuilder()},
        (error: Error, pixmap: image.PixelMap) => {
            if(error){
              console.log("error: " + JSON.stringify(error))
              return;
            }
            this.pixmap = pixmap;
        })
      }
      ```

3. 如果开发者要严格触发[onDragLeave](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragleave)事件，可以通过[setDragEventStrictReportingEnabled](../reference/apis-arkui/js-apis-arkui-UIContext.md#setdrageventstrictreportingenabled12)方法设置。

    ```ts
    import { UIAbility } from '@kit.AbilityKit';
    import { window, UIContext } from '@kit.ArkUI';

    export default class EntryAbility extends UIAbility {
      onWindowStageCreate(windowStage: window.WindowStage): void {
        windowStage.loadContent('pages/Index', (err, data) => {
          if (err.code) {
            return;
          }
          windowStage.getMainWindow((err, data) => {
            if (err.code) {
              return;
            }
            let windowClass: window.Window = data;
            let uiContext: UIContext = windowClass.getUIContext();
            uiContext.getDragController().setDragEventStrictReportingEnabled(true);
          });
        });
      }
    }
    ```

4. 拖拽过程显示角标样式。

   可以通过设置[allowDrop](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#allowdrop)定义接收的数据类型影响角标显示，当拖拽数据是定义允许落入的数据类型时，显示COPY角标；当拖拽数据不在定义允许落入的数据类型范围时，显示FORBIDDEN角标；未设置allowDrop时，显示MOVE角标。如下代码表示只接收UnifiedData中定义的HYPERLINK和PLAIN\_TEXT类型的数据，其他数据类型将禁止落入；

    ```ts
    .allowDrop([uniformTypeDescriptor.UniformDataType.HYPERLINK, uniformTypeDescriptor.UniformDataType.PLAIN_TEXT])
    ```

   此外在实现onDrop回调的情况下还可以通过在onDragMove中设置[DragResult](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragresult10枚举说明)为DROP\_ENABLED，并设置[DragBehavior](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragbehavior10)为COPY或MOVE控制角标显示。如下代码将移动时的角标强制设置为MOVE；

    ```ts
    .onDragMove((event) => {
        event.setResult(DragResult.DROP_ENABLED);
        event.dragBehavior = DragBehavior.MOVE;
    })
    ```

5. 拖拽数据的接收。

   需要设置onDrop回调，并在回调中处理拖拽数据，显示设置拖拽结果

    ```ts
    .onDrop((dragEvent?: DragEvent) => {
        // 获取拖拽数据
        this.getDataFromUdmf((dragEvent as DragEvent), (event: DragEvent) => {
        let records: Array<unifiedDataChannel.UnifiedRecord> = event.getData().getRecords();
        let rect: Rectangle = event.getPreviewRect();
        this.imageWidth = Number(rect.width);
        this.imageHeight = Number(rect.height);
        this.targetImage = (records[0] as unifiedDataChannel.Image).imageUri;
        this.imgState = Visibility.None；
        // 显式设置result为successful，则将该值传递给拖出方的onDragEnd
        event.setResult(DragResult.DRAG_SUCCESSFUL);
    })
    ```

   数据的传递是通过UDMF实现的，在数据较大时可能存在时延，因此在首次获取数据失败时建议加1500ms的延迟重试机制：

    ```ts
    getDataFromUdmfRetry(event: DragEvent, callback: (data: DragEvent) => void) {
       try {
         let data: UnifiedData = event.getData();
         if (!data) {
           return false;
         }
         let records: Array<unifiedDataChannel.UnifiedRecord> = data.getRecords();
         if (!records || records.length <= 0) {
           return false;
         }
         callback(event);
         return true;
       } catch (e) {
         console.log("getData failed, code: " + (e as BusinessError).code + ", message: " + (e as BusinessError).message);
         return false;
       }
    }

    getDataFromUdmf(event: DragEvent, callback: (data: DragEvent) => void) {
      if (this.getDataFromUdmfRetry(event, callback)) {
        return;
      }
      setTimeout(() => {
        this.getDataFromUdmfRetry(event, callback);
      }, 1500);
    }
    ```

6. 拖拽发起方可以通过设置onDragEnd回调感知拖拽结果。

    ```ts
    import { promptAction } from '@kit.ArkUI';

    .onDragEnd((event) => {
        // onDragEnd里取到的result值在接收方onDrop设置
      if (event.getResult() === DragResult.DRAG_SUCCESSFUL) {
        promptAction.showToast({ duration: 100, message: 'Drag Success' });
      } else if (event.getResult() === DragResult.DRAG_FAILED) {
        promptAction.showToast({ duration: 100, message: 'Drag failed' });
      }
    })
    ```

### 多选拖拽适配

API version 12开始[Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md)组件和[List](../reference/apis-arkui/arkui-ts/ts-container-list.md)组件中的GridItem和ListItem组件支持多选拖拽，当前只支持onDragStart的方式。如下以Grid为例，介绍多选拖拽的基本步骤，以及开发中的注意事项。

1. 组件多选拖拽使能。

   创建GridItem子组件并绑定onDragStart函数。同时设置GridItem组件的状态是可选中的。

    ```ts
    Grid() {
      ForEach(this.numbers, (idx: number) => {
        GridItem() {
          Column()
            .backgroundColor(this.colors[idx % 9])
            .width(50)
            .height(50)
            .opacity(1.0)
            .id('grid'+idx)
        }
        .onDragStart(()=>{})
        .selectable(true)
      }, (idx: string) => idx)
    }
    ```

   多选拖拽功能默认为关闭状态，使用多选拖拽需要在[dragPreviewOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#dragpreviewoptions11)接口中的DragInteractionOptions参数中设置isMultiSelectionEnabled为true，表示当前组件是否多选。DragInteractionOptions也有支持组件浮起前默认效果的参数defaultAnimationBeforeLifting，设置该参数为true后组件在浮起前会有一个默认缩小动效。

    ```ts
    .dragPreviewOptions({isMultiSelectionEnabled:true,defaultAnimationBeforeLifting:true})
    ```

   为了保证选中状态，需要设置GridItem子组件selected状态为true。例如，可以通过[onClick](../reference/apis-arkui/arkui-ts/ts-universal-events-click.md#onclick)的调用去设置特定的组件为选中的状态。

    ```ts
    .selected(this.isSelectedGrid[idx])
    .onClick(()=>{
        this.isSelectedGrid[idx] = !this.isSelectedGrid[idx]
    })
    ```

2. 多选拖拽性能优化。

   多选拖拽情况下，多选会有聚拢的动画效果，聚拢效果触发时，会给当前屏幕内显示的选中组件截图，当选中组件过多，会导致很高的性能开销。多选拖拽支持从dragPreview中获取截图来作为聚拢动效的截图，以节省性能。

    ```ts
    .dragPreview({
        pixelMap:this.pixmap
    })
    ```

   截图的获取可以在选中组件时通过调用componentSnapshot中的get方法获取。如下通过获取组件对应id的方法进行截图。

    ```ts
    @State previewData: DragItemInfo[] = []
    @State isSelectedGrid: boolean[] = []
    .onClick(()=>{
        this.isSelectedGrid[idx] = !this.isSelectedGrid[idx]
        if (this.isSelectedGrid[idx]) {
            let gridItemName = 'grid' + idx
            this.getUIContext().getComponentSnapshot().get(gridItemName, (error: Error, pixmap: image.PixelMap)=>{
                this.pixmap = pixmap
                this.previewData[idx] = {
                    pixelMap:this.pixmap
                }
            })
        }
    })
    ```

3. 多选显示效果。

    通过stateStyles可以设置选中态和非选中态的显示效果，方便区分。

    ```ts
    @Styles
    normalStyles(): void{
      .opacity(1.0)
    }

    @Styles
    selectStyles(): void{
      .opacity(0.4)
    }

    .stateStyles({
      normal : this.normalStyles,
      selected: this.selectStyles
    })
    ```

4. 数量角标适配。

    多选拖拽的数量角标当前需要应用使用dragPreviewOptions中的numberBadge参数设置，开发者需要根据当前选中的节点数量来设置数量角标。

    ```ts
    @State numberBadge: number = 0;

    .onClick(()=>{
        this.isSelectedGrid[idx] = !this.isSelectedGrid[idx]
        if (this.isSelectedGrid[idx]) {
          this.numberBadge++;
        } else {
          this.numberBadge--;
      }
    })
    // 多选场景右上角数量角标需要应用设置numberBadge参数
    .dragPreviewOptions({numberBadge: this.numberBadge})
    ```

## 完整示例

### 通用拖拽适配

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
import { promptAction } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

@Entry
@Component
struct Index {
  @State targetImage: string = '';
  @State imageWidth: number = 100;
  @State imageHeight: number = 100;
  @State imgState: Visibility = Visibility.Visible;
  @State pixmap: image.PixelMap|undefined = undefined

  @Builder
  pixelMapBuilder() {
    Column() {
      Image($r('app.media.startIcon'))
        .width(120)
        .height(120)
        .backgroundColor(Color.Yellow)
    }
  }

  getDataFromUdmfRetry(event: DragEvent, callback: (data: DragEvent) => void) {
    try {
      let data: UnifiedData = event.getData();
      if (!data) {
        return false;
      }
      let records: Array<unifiedDataChannel.UnifiedRecord> = data.getRecords();
      if (!records || records.length <= 0) {
        return false;
      }
      callback(event);
      return true;
    } catch (e) {
      console.log("getData failed, code: " + (e as BusinessError).code + ", message: " + (e as BusinessError).message);
      return false;
    }
  }
  // 获取UDMF数据，首次获取失败后添加1500ms延迟重试机制
  getDataFromUdmf(event: DragEvent, callback: (data: DragEvent) => void) {
    if (this.getDataFromUdmfRetry(event, callback)) {
      return;
    }
    setTimeout(() => {
      this.getDataFromUdmfRetry(event, callback);
    }, 1500);
  }
  // 调用componentSnapshot中的createFromBuilder接口截取自定义builder的截图
  private getComponentSnapshot(): void {
    this.getUIContext().getComponentSnapshot().createFromBuilder(()=>{this.pixelMapBuilder()},
      (error: Error, pixmap: image.PixelMap) => {
        if(error){
          console.log("error: " + JSON.stringify(error))
          return;
        }
        this.pixmap = pixmap;
      })
  }
  // 长按50ms时提前准备自定义截图的pixmap
  private PreDragChange(preDragStatus: PreDragStatus): void {
    if (preDragStatus == PreDragStatus.ACTION_DETECTING_STATUS) {
      this.getComponentSnapshot();
    }
  }

  build() {
    Row() {
      Column() {
        Text('start Drag')
          .fontSize(18)
          .width('100%')
          .height(40)
          .margin(10)
          .backgroundColor('#008888')
        Row() {
          Image($r('app.media.app_icon'))
            .width(100)
            .height(100)
            .draggable(true)
            .margin({ left: 15 })
            .visibility(this.imgState)
            // 绑定平行手势，可同时触发应用自定义长按手势
            .parallelGesture(LongPressGesture().onAction(() => {
              promptAction.showToast({ duration: 100, message: 'Long press gesture trigger' });
            }))
            .onDragStart((event) => {
              let data: unifiedDataChannel.Image = new unifiedDataChannel.Image();
              data.imageUri = 'common/pic/img.png';
              let unifiedData = new unifiedDataChannel.UnifiedData(data);
              event.setData(unifiedData);

              let dragItemInfo: DragItemInfo = {
                pixelMap: this.pixmap,
                extraInfo: "this is extraInfo",
              };
              return dragItemInfo;
            })
              // 提前准备拖拽自定义背板图
            .onPreDrag((status: PreDragStatus) => {
              this.PreDragChange(status);
            })
            .onDragEnd((event) => {
              // onDragEnd里取到的result值在接收方onDrop设置
              if (event.getResult() === DragResult.DRAG_SUCCESSFUL) {
                promptAction.showToast({ duration: 100, message: 'Drag Success' });
              } else if (event.getResult() === DragResult.DRAG_FAILED) {
                promptAction.showToast({ duration: 100, message: 'Drag failed' });
              }
            })
        }

        Text('Drag Target Area')
          .fontSize(20)
          .width('100%')
          .height(40)
          .margin(10)
          .backgroundColor('#008888')
        Row() {
          Image(this.targetImage)
            .width(this.imageWidth)
            .height(this.imageHeight)
            .draggable(true)
            .margin({ left: 15 })
            .border({ color: Color.Black, width: 1 })
            // 控制角标显示类型为MOVE，即不显示角标
            .onDragMove((event) => {
              event.setResult(DragResult.DROP_ENABLED)
              event.dragBehavior = DragBehavior.MOVE
            })
            .allowDrop([uniformTypeDescriptor.UniformDataType.IMAGE])
            .onDrop((dragEvent?: DragEvent) => {
              // 获取拖拽数据
              this.getDataFromUdmf((dragEvent as DragEvent), (event: DragEvent) => {
                let records: Array<unifiedDataChannel.UnifiedRecord> = event.getData().getRecords();
                let rect: Rectangle = event.getPreviewRect();
                this.imageWidth = Number(rect.width);
                this.imageHeight = Number(rect.height);
                this.targetImage = (records[0] as unifiedDataChannel.Image).imageUri;
                this.imgState = Visibility.None;
                // 显式设置result为successful，则将该值传递给拖出方的onDragEnd
                event.setResult(DragResult.DRAG_SUCCESSFUL);
              })
            })
        }
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}

```

### 多选拖拽适配

```ts
import { image } from '@kit.ImageKit';

@Entry
@Component
struct GridEts {
  @State pixmap: image.PixelMap|undefined = undefined
  @State numbers: number[] = []
  @State isSelectedGrid: boolean[] = []
  @State previewData: DragItemInfo[] = []
  @State colors: Color[] = [Color.Red, Color.Blue, Color.Brown, Color.Gray, Color.Green, Color.Grey, Color.Orange,Color.Pink ,Color.Yellow]
  @State numberBadge: number = 0;

  @Styles
  normalStyles(): void{
    .opacity(1.0)
  }

  @Styles
  selectStyles(): void{
    .opacity(0.4)
  }

  onPageShow(): void {
    let i: number = 0
    for(i=0;i<100;i++){
      this.numbers.push(i)
      this.isSelectedGrid.push(false)
      this.previewData.push({})
    }
  }

  @Builder
  RandomBuilder(idx: number) {
    Column()
      .backgroundColor(this.colors[idx % 9])
      .width(50)
      .height(50)
      .opacity(1.0)
  }

  build() {
    Column({ space: 5 }) {
      Grid() {
        ForEach(this.numbers, (idx: number) => {
          GridItem() {
            Column()
              .backgroundColor(this.colors[idx % 9])
              .width(50)
              .height(50)
              .opacity(1.0)
              .id('grid'+idx)
          }
          .dragPreview(this.previewData[idx])
          .selectable(true)
          .selected(this.isSelectedGrid[idx])
          // 设置多选显示效果
          .stateStyles({
            normal : this.normalStyles,
            selected: this.selectStyles
          })
          .onClick(()=>{
            this.isSelectedGrid[idx] = !this.isSelectedGrid[idx]
            if (this.isSelectedGrid[idx]) {
              this.numberBadge++;
              let gridItemName = 'grid' + idx
              // 选中状态下提前调用componentSnapshot中的get接口获取pixmap
              this.getUIContext().getComponentSnapshot().get(gridItemName, (error: Error, pixmap: image.PixelMap)=>{
                this.pixmap = pixmap
                this.previewData[idx] = {
                  pixelMap:this.pixmap
                }
              })
            } else {
              this.numberBadge--;
            }
          })
          // 使能多选拖拽，右上角数量角标需要应用设置numberBadge参数
          .dragPreviewOptions({numberBadge: this.numberBadge},{isMultiSelectionEnabled:true,defaultAnimationBeforeLifting:true})
          .onDragStart(()=>{
          })
        }, (idx: string) => idx)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(5)
      .rowsGap(10)
      .backgroundColor(0xFAEEE0)
    }.width('100%').margin({ top: 5 })
  }
}
```
<!--RP1--><!--RP1End-->
