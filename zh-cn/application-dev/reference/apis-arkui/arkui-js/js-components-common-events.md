# 通用事件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--SE: @piggyguy-->
<!--TSE: @songyanhong-->

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 事件说明

- 事件绑定在组件上，当组件达到事件触发条件时，会执行JS中对应的事件回调函数，实现页面UI视图和页面JS逻辑层的交互。

- 事件回调函数中通过参数可以携带额外的信息，如组件上的数据对象dataset，事件特有的回调参数。


相对于私有事件，大部分组件都可以绑定如下事件。


| 名称                     | 参数       | 描述                                                         | 是否支持冒泡                                          | 是否支持捕获    |
| ------------------------ | ---------- | ------------------------------------------------------------ | ----------------------------------------------------- | --------------- |
| touchstart               | TouchEvent | 手指刚触摸屏幕时触发该事件。TouchEvent具体可参考表2。       | 是<sup>5+</sup>                                       | 是<sup>5+</sup> |
| touchmove                | TouchEvent | 手指触摸屏幕后移动时触发该事件。                             | 是<sup>5+</sup>                                       | 是<sup>5+</sup> |
| touchcancel              | TouchEvent | 手指触摸屏幕中动作被打断时触发该事件。                       | 是<sup>5+</sup>                                       | 是<sup>5+</sup> |
| touchend                 | TouchEvent | 手指触摸结束离开屏幕时触发该事件。                           | 是<sup>5+</sup>                                       | 是<sup>5+</sup> |
| click                    | BaseEvent  | 点击动作触发该事件。                                         | 是<sup>6+</sup>                                       | 否              |
| doubleclick<sup>7+</sup> | BaseEvent  | 双击动作触发该事件                                           | 否<br/> 从API&nbsp;Version&nbsp;9&nbsp;开始支持冒泡。 | 否              |
| longpress                | BaseEvent  | 长按动作触发该事件。                                         | 否<br/>从API&nbsp;Version&nbsp;9&nbsp;开始支持冒泡。  | 否              |
| swipe<sup>5+</sup>       | SwipeEvent | 组件上快速滑动后触发该事件。 SwipeEvent具体可参考表4 。      | 否<br/>从API&nbsp;Version&nbsp;9&nbsp;开始支持冒泡。  | 否              |
| attached<sup>6+</sup>    | -          | 当前组件节点挂载在渲染树后触发。                             | 否                                                    | 否              |
| detached<sup>6+</sup>    | -          | 当前组件节点从渲染树中移除后触发。                           | 否                                                    | 否              |
| pinchstart<sup>7+</sup>  | PinchEvent | 手指开始执行捏合操作时触发该事件。<br/>PinchEvent具体可参考表5。 | 否                                                    | 否              |
| pinchupdate<sup>7+</sup> | PinchEvent | 手指执行捏合操作过程中触发该事件。                           | 否                                                    | 否              |
| pinchend<sup>7+</sup>    | PinchEvent | 手指捏合操作结束离开屏幕时触发该事件。                       | 否                                                    | 否              |
| pinchcancel<sup>7+</sup> | PinchEvent | 手指捏合操作被打断时触发该事件。                             | 否                                                    | 否              |
| dragstart<sup>7+</sup>   | DragEvent  | 用户开始拖拽时触发该事件。<br/>DragEvent具体可参考表6。      | 否                                                    | 否              |
| drag<sup>7+</sup>        | DragEvent  | 拖拽过程中触发该事件。                                       | 否                                                    | 否              |
| dragend<sup>7+</sup>     | DragEvent  | 用户拖拽完成后触发。                                         | 否                                                    | 否              |
| dragenter<sup>7+</sup>   | DragEvent  | 进入释放目标时触发该事件。                                   | 否                                                    | 否              |
| dragover<sup>7+</sup>    | DragEvent  | 在释放目标内拖动时触发。                                     | 否                                                    | 否              |
| dragleave<sup>7+</sup>   | DragEvent  | 离开释放目标区域时触发。                                     | 否                                                    | 否              |
| drop<sup>7+</sup>        | DragEvent  | 在可释放目标区域内释放时触发。                               | 否                                                    | 否              |


>  **说明：**
>  除上述事件外，其他事件均为非冒泡事件，如[input的change事件](js-components-basic-input.md#事件)，详见各个组件。

**表1** BaseEvent对象属性列表

| 属性                  | 类型                   | 说明                                     |
| --------------------- | ---------------------- | ---------------------------------------- |
| type                  | string                 | 当前事件的类型，比如click、longpress等。 |
| timestamp             | number                 | 该事件触发时的时间戳。                   |
| deviceId<sup>8+</sup> | number                 | 触发该事件的设备ID信息。                 |
| target<sup>12+</sup>   | [Target](#target对象6) | 触发该事件的目标对象。                   |

**表2** TouchEvent对象属性列表(继承BaseEvent)

| 属性             | 类型                     | 说明                                       |
| -------------- | ---------------------- | ---------------------------------------- |
| touches        | Array&lt;TouchInfo&gt; | 触摸事件时的属性集合，包含屏幕触摸点的信息数组。                 |
| changedTouches | Array&lt;TouchInfo&gt; | 触摸事件时的属性集合，包括产生变化的屏幕触摸点的信息数组。数据格式和touches一样。该属性表示有变化的触摸点，如从无变有，位置变化，从有变无。例如用户手指刚接触屏幕时，touches数组中有数据，但changedTouches无数据。 |

**表3** TouchInfo

| 属性                 | 类型     | 说明                             |
| ------------------ | ------ | ------------------------------ |
| globalX            | number | 距离屏幕左上角（不包括状态栏）横向距离。屏幕的左上角为原点。 |
| globalY            | number | 距离屏幕左上角（不包括状态栏）纵向距离。屏幕的左上角为原点。 |
| localX             | number | 距离被触摸组件左上角横向距离。组件的左上角为原点。      |
| localY             | number | 距离被触摸组件左上角纵向距离。组件的左上角为原点。      |
| size               | number | 触摸接触面积。                        |
| force<sup>6+</sup> | number | 接触力信息。                         |

**表4** SwipeEvent 基础事件对象属性列表（继承BaseEvent）

| 属性                    | 类型     | 说明                                       |
| --------------------- | ------ | ---------------------------------------- |
| direction             | string | 滑动方向，可能值有：<br/>- &nbsp;left：向左滑动；<br/>- &nbsp;right：向右滑动；<br/>- &nbsp;up：向上滑动；<br/>- &nbsp;down：向下滑动。 |
| distance<sup>6+</sup> | number | 在滑动方向上的滑动距离。                             |

**表5** PinchEvent 对象属性列表<sup>7+</sup>

| 属性           | 类型     | 说明             |
| ------------ | ------ | -------------- |
| scale        | number | 缩放比例。           |
| pinchCenterX | number | 捏合中心点X轴坐标，单位px。 |
| pinchCenterY | number | 捏合中心点Y轴坐标，单位px。 |

**表6** DragEvent对象属性列表(继承BaseEvent)<sup>7+</sup>

| 属性                        | 类型                               | 说明               |
| ------------------------- | -------------------------------- | ---------------- |
| type                      | string                           | 事件名称。            |
| globalX                   | number                           | 距离屏幕左上角坐标原点横向距离。 |
| globalY                   | number                           | 距离屏幕左上角坐标原点纵向距离。 |
| timestamp                 | number                           | 时间戳。             |
| dataTransfer<sup>9+</sup> | [DataTransfer](#datatransfer对象9) | 用于传输数据。          |

## Target对象<sup>6+</sup>

当组件触发事件后，事件回调函数默认会收到一个事件对象，通过该事件对象可以获取相应的信息。



| 属性                   | 类型     | 说明                                       |
| -------------------- | ------ | ---------------------------------------- |
| dataSet<sup>6+</sup> | Object | 组件上通过通用属性设置的[data-*](js-components-common-attributes.md)的自定义属性组成的集合。 |

**示例：**

```html
<!-- xxx.hml -->
<div>
  <div data-a="dataA" data-b="dataB" 
    style="width: 100%; height: 50%; background-color: saddlebrown;"@touchstart='touchstartfunc'></div>
</div>
```

```js
// xxx.js
export default {
  touchstartfunc(msg) {
    console.info(`on touch start, point is: ${msg.touches[0].globalX}`);
    console.info(`on touch start, data is: ${msg.target.dataSet.a}`);
  }
}
```

## DataTransfer对象<sup>9+</sup>

在拖拽操作的过程中，可以通过dataTransfer对象来传输数据，以便在拖拽操作结束的时候对数据进行其他操作。

### setData<sup>9+</sup>

setData(key: string, value: object): boolean

设置给定key关联的数据。如果没有与该key关联的数据，则将其添加到末尾。如果该key关联的数据已经存在，则在相同位置替换现有数据。

**参数：** 

| 参数名   | 参数类型   | 必填   | 描述      |
| ----- | ------ | ---- | ------- |
| key   | string | 是    | 数据键值。   |
| value | object | 是    | 要存储的数据。 |

**返回值：** 

| 类型      | 说明                       |
| ------- | ------------------------ |
| boolean | 执行结果，true表示成功，false表示失败。 |

**示例：** 

```js
// setData的value参数，可以是基本数据类型。
dragStart(e) {
	var isSetOk = e.dataTransfer.setData('name', 1);
},
// setData的value参数，也可以是对象类型。
dragStart(e) {
	var person = new Object();
	person.name = "tom";
	person.age = 21;
	var isSetOk = e.dataTransfer.setData('person', person);
}
```
### getData<sup>9+</sup>

getData(key: string): object

获取给定key关联的数据，如果没有与该key关联的数据，则返回空字符串。

**参数：** 

| 参数名  | 参数类型   | 必填   | 描述    |
| ---- | ------ | ---- | ----- |
| key  | string | 是    | 数据键值。 |

**返回值：** 

| 类型     | 说明     |
| ------ | ------ |
| object | 获取的数据。 |

**示例：** 

```js
dragStart(e) {
	var person = new Object();
	person.name = "tom";
	person.age = 21;
	e.dataTransfer.setData('person', person);
},
dragEnd(e){
	var person = e.dataTransfer.getData('person');
},
```
### clearData<sup>9+</sup>

clearData(key?: string): boolean

删除给定key关联的数据。如果没有与该key关联的数据，则该方法不会产生任何效果。
如果key为空，则删除所有数据。

**参数：** 

| 参数名  | 参数类型   | 必填   | 描述    |
| ---- | ------ | ---- | ----- |
| key  | string | 否    | 数据键值。 |

**返回值：** 

| 类型      | 说明                       |
| ------- | ------------------------ |
| boolean | 执行结果，true表示成功，false表示失败。 |

**示例：** 

```js
dragEnd(e) {
	var isSuccess = e.dataTransfer.clearData('name');
}
```
### setDragImage<sup>9+</sup>

setDragImage(pixelmap: PixelMap, offsetX: number,offsetY: number): boolean

用于设置自定义的拖动图像。

**参数：** 

| 参数名      | 参数类型     | 必填   | 描述                                       |
| -------- | -------- | ---- | ---------------------------------------- |
| pixelmap | [PixelMap](../../apis-image-kit/arkts-apis-image-PixelMap.md) | 是    | 前端传入的图片资源。 |
| offsetX  | number   | 是    | 相对于图片的横向偏移量。                             |
| offsetY  | number   | 是    | 相对于图片的纵向偏移量。                            |

**返回值：** 

| 类型   | 说明                       |
| ---- | ------------------------ |
| boolean | 执行结果，true表示成功，false表示失败。 |

**示例：** 

```js
import image from '@ohos.multimedia.image';

export default {
    createPixelMap() {
        let color = new ArrayBuffer(4 * 96 * 96);
        var buffer = new Uint8Array(color);
        for (var i = 0; i < buffer.length; i++) {
            buffer[i] = (i + 1) % 255;
        }
        let opts = {
            alphaType: 0,
            editable: true,
            pixelFormat: 4,
            scaleMode: 1,
            size: {
                height: 96, width: 96
            }
        }
        const promise = image.createPixelMap(color, opts);
        promise.then((data) => {
            console.error('-create pixmap has info message:' + JSON.stringify(data));
            this.pixelMap = data;
            this.pixelMapReader = data;
        })
    },

    onInit() {
        this.createPixelMap()
    },

    dragStart(e) {
        e.dataTransfer.setDragImage(this.pixelMapReader, 50, 50);
    }
}
```