# @ohos.arkui.inspector (布局回调)

提供注册组件布局和组件绘制送显完成回调通知的能力。

> **说明：**
>
> 从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

<!--deprecated_code_no_check-->
```ts
import { inspector } from '@kit.ArkUI';
```

## inspector.createComponentObserver<sup>(deprecated)</sup>

createComponentObserver(id: string): ComponentObserver

绑定指定组件，返回对应的监听句柄。

> **说明：**
> 
> 从API version 18开始废弃，建议使用[UIContext](js-apis-arkui-UIContext.md#uicontext)中的[getUIInspector](js-apis-arkui-UIContext.md#getuiinspector)获取[UIInspector](js-apis-arkui-UIContext.md#uiinspector)实例，再通过此实例调用替代方法[createComponentObserver](js-apis-arkui-UIContext.md#createcomponentobserver)。
>
> 从API version 10开始，可以通过使用[UIContext](js-apis-arkui-UIContext.md#uicontext)中的[getUIInspector](js-apis-arkui-UIContext.md#getuiinspector)方法获取当前UI上下文关联的[UIInspector](js-apis-arkui-UIContext.md#uiinspector)对象。

**原子化服务API：** 从API version 10开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| id     | string | 是   | 指定组件id，该id通过通用属性[id](./arkui-ts/ts-universal-attributes-component-id.md#id)或者[key](./arkui-ts/ts-universal-attributes-component-id.md#key12)设置。 |

**返回值：** 

| 类型              | 说明                                             |
| ----------------- | ------------------------------------------------ |
|[ComponentObserver](#componentobserver)| 组件回调事件监听句柄，用于注册和取消注册监听回调。 |

**示例：** 

```ts
let listener:inspector.ComponentObserver = inspector.createComponentObserver('COMPONENT_ID'); //监听id为COMPONENT_ID的组件回调事件
```

## ComponentObserver

组件布局和组件绘制送显完成回调的句柄，包含了申请句柄时的首次查询结果。

### on('layout')

on(type: 'layout', callback: () => void): void

通过句柄向对应的查询条件注册回调，当组件布局完成时会触发该回调。

**原子化服务API：** 从API version 10开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明|
| -------- | ------ | ---- | -------------------------------------|
| type     | string | 是   | 必须填写字符串'layout'。<br>layout: 组件布局完成。|
| callback | () => void   | 是   | 监听layout的回调。|

### off('layout')

off(type: 'layout', callback?: () => void): void

通过句柄向对应的查询条件取消注册回调，当组件布局完成时不再触发指定的回调。

**原子化服务API：** 从API version 10开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | -------------------------------------------- |
| type     | string | 是   | 必须填写字符串'layout'。<br>layout: 组件布局完成。|
| callback | () => void   | 否   | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。callback需要和[on('layout')](#onlayout)方法中的callback为相同对象时才能取消回调成功。|

### on('draw')

on(type: 'draw', callback: () => void): void

通过句柄向对应的查询条件注册回调，当组件绘制送显完成时会触发该回调。

**原子化服务API：** 从API version 10开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 必须填写字符串'draw'。<br>draw: 组件绘制送显完成。|
| callback | () => void   | 是   | 监听draw的回调。                                     |

### off('draw')

off(type: 'draw', callback?: () => void): void

通过句柄向对应的查询条件取消注册回调，当组件绘制送显完成时不再触发指定的回调。

**原子化服务API：** 从API version 10开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 必须填写字符串'draw'。<br>draw: 组件绘制送显完成。|
| callback | () => void   | 否   | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。callback需要和[on('draw')](#ondraw)方法中的callback为相同对象时才能取消回调成功。 |

### on('drawChildren')<sup>20+<sup>

on(type: 'drawChildren',  callback: Callback\<void\>): void

通过[ComponentObserver](#componentobserver)注册drawChildren事件回调方法，当组件的子组件绘制送显完成时会触发该回调方法。如果组件树中存在多个drawChildren事件回调，只会触发在最顶层的drawChildren事件回调。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 必须填写字符串'drawChildren'。<br>drawChildren: 子组件绘制送显完成。|
| callback | [Callback\<void\>](js-apis-arkui-inspector.md#)   | 是   | 监听drawChildren的回调。                                     |

### off('drawChildren')<sup>20+<sup>

off(type: 'drawChildren', callback?: Callback\<void\>): void

通过句柄向对应的查询条件取消注册回调，当组件绘制送显完成时不再触发指定的回调。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 必须填写字符串'drawChildren'。<br>drawChildren: 子组件绘制送显完成。|
| callback | Callback\<void\>   | 否   | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。callback需要和[on('drawChildren')20+](#ondrawchildren20)方法中的callback为相同对象时才能取消回调成功。 |

**示例：**

> **说明：**
>
> 推荐通过使用[UIContext](./js-apis-arkui-UIContext.md#uicontext)中的[getUIInspector](./js-apis-arkui-UIContext.md#getuiinspector)方法获取当前UI上下文关联的[UIInspector](./js-apis-arkui-UIContext.md#uiinspector)对象。

  ```ts
  import { inspector } from '@kit.ArkUI'

  @Entry
  @Component
  struct ImageExample {
    build() {
      Column() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
          Row({ space: 5 }) {
            Image($r('app.media.app_icon'))
              .width(110)
              .height(110)
              .border({ width: 1 })
              .id('IMAGE_ID')
          }
        }
      }.height(320).width(360).padding({ right: 10, top: 10 })
    }

    listener:inspector.ComponentObserver = this.getUIContext().getUIInspector().createComponentObserver('IMAGE_ID')

    aboutToAppear() {
      let onLayoutComplete:()=>void=():void=>{
          // do something here
      }
      let onDrawComplete:()=>void=():void=>{
          // do something here
      }
      let onDrawChildrenComplete:()=>void=():void=>{
          // do something here
      }
      let FuncLayout = onLayoutComplete // bind current js instance
      let FuncDraw = onDrawComplete // bind current js instance
      let FuncDrawChildren = onDrawChildrenComplete // bind current js instance
      let OffFuncLayout = onLayoutComplete // bind current js instance
      let OffFuncDraw = onDrawComplete // bind current js instance
      let OffFuncDrawChildren = onDrawChildrenComplete // bind current js instance

      this.listener.on('layout', FuncLayout)
      this.listener.on('draw', FuncDraw)
      this.listener.on('drawChildren', FuncDrawChildren)
      
      // 通过句柄向对应的查询条件取消注册回调，由开发者自行决定在何时调用。
      // this.listener.off('layout', OffFuncLayout)
      // this.listener.off('draw', OffFuncDraw)
      // this.listener.off('drawChildren', OffFuncDrawChildren)
    }
  }
  ```
