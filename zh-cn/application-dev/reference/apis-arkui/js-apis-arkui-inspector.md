# @ohos.arkui.inspector (布局回调)

提供注册组件布局和绘制完成回调通知的能力。

> **说明：**
>
> 从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 从API version 10开始，可以通过使用[UIContext](./js-apis-arkui-UIContext.md#uicontext)中的[getUIInspector](./js-apis-arkui-UIContext.md#getuiinspector)方法获取当前UI上下文关联的[UIInspector](./js-apis-arkui-UIContext.md#uiinspector)对象。

## 导入模块

```ts
import { inspector } from '@kit.ArkUI'
```

## inspector.createComponentObserver

createComponentObserver(id: string): ComponentObserver

绑定指定组件，返回对应的监听句柄。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| id     | string | 是   | 指定组件id。 |

**返回值：** 

| 类型              | 说明                                             |
| ----------------- | ------------------------------------------------ |
|[ComponentObserver](#componentobserver)| 组件回调事件监听句柄，用于注册和取消注册监听回调。 |

**示例：** 

```ts
let listener:inspector.ComponentObserver = inspector.createComponentObserver('COMPONENT_ID'); //监听id为COMPONENT_ID的组件回调事件
```

## ComponentObserver

组件布局绘制完成回调的句柄，包含了申请句柄时的首次查询结果。

### on

on(type: 'layout', callback: () => void): void

通过句柄向对应的查询条件注册回调，当组件布局完成时会触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明|
| -------- | ------ | ---- | -------------------------------------|
| type     | string | 是   | 必须填写字符串'layout'或'draw'。<br>layout: 组件布局完成。<br>draw: 组件绘制完成。 |
| callback | void   | 是   | 监听layout或draw的回调。|

### off

off(type: 'layout', callback?: () => void): void

通过句柄向对应的查询条件取消注册回调，当组件布局完成时不再触发指定的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | -------------------------------------------- |
| type     | string | 是   | 必须填写字符串'layout'或'draw'。<br>layout: 组件布局完成。<br>draw: 组件绘制完成。 |
| callback | void   | 否   | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。|

### on

on(type: 'draw', callback: () => void): void

通过句柄向对应的查询条件注册回调，当组件绘制完成时会触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 必须填写字符串'layout'或'draw'。<br>layout: 组件布局完成。<br>draw: 组件绘制完成。 |
| callback | void   | 是   | 监听layout或draw的回调。                                     |

### off

off(type: 'draw', callback?: () => void): void

通过句柄向对应的查询条件取消注册回调，当组件绘制完成时不再触发指定的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 必须填写字符串'layout'或'draw'。<br>layout: 组件布局完成。<br>draw: 组件绘制完成。 |
| callback | void   | 否   | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。callback需要和on方法中的callback为相同对象时才能取消回调成功。 |

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

    listener:inspector.ComponentObserver = inspector.createComponentObserver('IMAGE_ID') // 建议使用 this.getUIContext().getUIInspector().createComponentObserver()接口

    aboutToAppear() {
      let onLayoutComplete:()=>void=():void=>{
          // do something here
      }
      let onDrawComplete:()=>void=():void=>{
          // do something here
      }
      let FuncLayout = onLayoutComplete // bind current js instance
      let FuncDraw = onDrawComplete // bind current js instance
      let OffFuncLayout = onLayoutComplete // bind current js instance
      let OffFuncDraw = onDrawComplete // bind current js instance

      this.listener.on('layout', FuncLayout)
      this.listener.on('draw', FuncDraw)

      // 通过句柄向对应的查询条件取消注册回调，由开发者自行决定在何时调用。
      // this.listener.off('layout', OffFuncLayout)
      // this.listener.off('draw', OffFuncDraw)
    }
  }
  ```
