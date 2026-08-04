# @ohos.arkui.inspector (布局回调)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

提供注册组件布局和组件绘制送显完成回调通知的能力。开发者可通过注册回调，在组件布局完成或绘制送显完成后及时获取通知，适用于需要精确感知组件渲染时机并据此执行自定义逻辑的场景。适用于需要在组件布局或绘制送显完成后执行自定义逻辑的场景，帮助开发者精准掌控组件渲染时机。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

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
> - 从API version 10开始支持，从API version 18开始废弃。建议使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getUIInspector](arkts-apis-uicontext-uicontext.md#getuiinspector)方法获取[UIInspector](arkts-apis-uicontext-uiinspector.md)实例，再通过此实例调用替代方法[createComponentObserver](arkts-apis-uicontext-uiinspector.md#createcomponentobserver)。
>
> - 从API version 10开始，可以通过使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getUIInspector](arkts-apis-uicontext-uicontext.md#getuiinspector)方法获取当前UI上下文关联的[UIInspector](arkts-apis-uicontext-uiinspector.md)对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

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
let listener: inspector.ComponentObserver = inspector.createComponentObserver('COMPONENT_ID'); // 监听id为COMPONENT_ID的组件回调事件
```

## ComponentObserver

组件布局和组件绘制送显完成回调的句柄，通过该句柄可调用以下方法。

### on('layout')

on(type: 'layout', callback: () => void): void

通过句柄为指定组件注册回调，当组件布局完成时会触发该回调。请注意，该接口无法监听窗口尺寸变化，相关需求请参考[on('windowSizeChange')](./arkts-apis-window-Window.md#onwindowsizechange7)。此外，布局回调和窗口尺寸变化回调之间不存在确定的执行顺序依赖。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型   | 必填 | 说明|
| -------- | ------ | ---- | -------------------------------------|
| type     | string | 是   | 必须填写字符串'layout'。<br>layout：组件布局完成。|
| callback | () => void   | 是   | 监听layout的回调。|

### off('layout')

off(type: 'layout', callback?: () => void): void

通过句柄取消注册回调，当组件布局完成时不再触发指定的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | -------------------------------------------- |
| type     | string | 是   | 必须填写字符串'layout'。<br>layout：组件布局完成。|
| callback | () => void   | 否   | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。callback需要和[on('layout')](#onlayout)方法中的callback为相同对象时才能取消回调成功。|

### on('draw')

on(type: 'draw', callback: () => void): void

通过句柄注册回调，当组件绘制送显完成时会触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 必须填写字符串'draw'。<br>draw：组件绘制送显完成。|
| callback | () => void   | 是   | 监听draw的回调。                                     |

### off('draw')

off(type: 'draw', callback?: () => void): void

通过句柄取消注册回调，当组件绘制送显完成时不再触发指定的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 必须填写字符串'draw'。<br>draw：组件绘制送显完成。|
| callback | () => void   | 否   | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。callback需要和[on('draw')](#ondraw)方法中的callback为相同对象时才能取消回调成功。 |

### on('drawChildren')<sup>20+</sup>

on(type: 'drawChildren', callback: Callback\<void\>): void

通过[ComponentObserver](#componentobserver)注册drawChildren事件回调方法。当组件的子组件位于UI组件主树中且绘制送显完成时，会触发该回调方法。如果组件树中存在多个drawChildren事件回调，只会触发最顶层的drawChildren事件回调。取消最顶层的回调后，其余drawChildren事件回调也无法生效。当前节点注册回调后，不支持修改其在UI组件主树中的层级位置。如需调整，请先取消事件回调，再重新注册事件回调。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 必须填写字符串'drawChildren'。<br>drawChildren：子组件绘制送显完成。|
| callback | [Callback](./arkui-ts/ts-types.md#callback12)\<void\>  | 是   | 监听drawChildren的回调。                                     |

### off('drawChildren')<sup>20+</sup>

off(type: 'drawChildren', callback?: Callback\<void\>): void

通过句柄取消注册回调，当组件的子组件绘制送显完成时不再触发指定的回调。如果组件树中存在多个drawChildren事件回调，取消最顶层的回调后，其余drawChildren事件回调也无法生效。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 必须填写字符串'drawChildren'。<br>drawChildren：子组件绘制送显完成。|
| callback | [Callback](./arkui-ts/ts-types.md#callback12)\<void\>   | 否   | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。callback需要和[on('drawChildren')<sup>20+</sup>](#ondrawchildren20)方法中的callback为相同对象时才能取消回调成功。 |

### onLayoutChildren<sup>23+</sup>

onLayoutChildren(callback: Callback\<void\>): void

通过[ComponentObserver](#componentobserver)注册layoutChildren事件回调。使用callback异步回调。

以当前注册事件回调的节点为根节点，当子树中的节点位于UI组件主树中且完成布局时，会触发该回调。如果组件树中存在多个layoutChildren事件回调，只会触发最顶层的layoutChildren事件回调。通过[offLayoutChildren](#offlayoutchildren23)取消最顶层的回调后，其余layoutChildren事件回调也无法生效。当前节点注册回调后，不支持修改其在UI组件主树中的层级位置。如需调整，请先取消事件回调，再重新注册事件回调。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| callback | [Callback](./arkui-ts/ts-types.md#callback12)\<void\>  | 是   | 监听layoutChildren的回调。                              |

### offLayoutChildren<sup>23+</sup>

offLayoutChildren(callback?: Callback\<void\>): void

取消注册layoutChildren事件回调。

要实现在子组件布局完成后停止触发特定回调，只需通过ComponentObserver句柄，取消注册该回调即可。如果组件树中存在多个layoutChildren事件回调，取消最顶层的回调后，其余layoutChildren事件回调也无法生效。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：** 

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| callback | [Callback](./arkui-ts/ts-types.md#callback12)\<void\>   | 否   | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。callback需要和[onLayoutChildren<sup>23+</sup>](#onlayoutchildren23)方法中的callback为相同对象时才能取消回调成功。 |

**示例：**

以下示例展示了inspector注册组件布局和组件绘制送显完成回调通知能力的基本用法。同时，通过[onLayoutChildren<sup>23+</sup>](#onlayoutchildren23)接口监听子树中的节点完成布局时的回调事件。

```ts
import { inspector } from '@kit.ArkUI';

@Entry
@Component
struct ImageExample {
  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Row({ space: 5 }) {
          Image($r('app.media.startIcon'))
            .width(110)
            .height(110)
            .border({ width: 1 })
            .id('IMAGE_ID')
        }
        .id('ROW_ID')
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }

  listenerForImage: inspector.ComponentObserver = this.getUIContext().getUIInspector().createComponentObserver('IMAGE_ID');
  listenerForRow: inspector.ComponentObserver = this.getUIContext().getUIInspector().createComponentObserver('ROW_ID');

  aboutToAppear() {
    let onLayoutComplete: () => void = (): void => {
      // 根据需要补充实现代码
    };
    let onDrawComplete: () => void = (): void => {
      // 根据需要补充实现代码
    };
    let onDrawChildrenComplete: () => void = (): void => {
      // 根据需要补充实现代码
    };
    // 绑定当前js实例
    let funcLayout = onLayoutComplete;
    let funcDraw = onDrawComplete;
    let funcDrawChildren = onDrawChildrenComplete;
    let offFuncLayout = onLayoutComplete;
    let offFuncDraw = onDrawComplete;
    let offFuncDrawChildren = onDrawChildrenComplete;

    this.listenerForImage.on('layout', funcLayout);
    this.listenerForImage.on('draw', funcDraw);
    this.listenerForRow.on('drawChildren', funcDrawChildren);

    // 通过句柄向对应的查询条件取消注册回调，由开发者自行决定在何时调用。
    // this.listenerForImage.off('layout', offFuncLayout)
    // this.listenerForImage.off('draw', offFuncDraw)
    // this.listenerForRow.off('drawChildren', offFuncDrawChildren)

    let onLayoutChildrenComplete: () => void = (): void => {
      // 监听到layoutChildren事件后，用户可以自定义实现逻辑。
    };

    let uniqueId: number = 0; // 替换为实际组件的uniqueId
    let listenerForUniqueId: inspector.ComponentObserver = this.getUIContext().getUIInspector().createComponentObserver(uniqueId.toString());
    listenerForUniqueId.onLayoutChildren(onLayoutChildrenComplete);
  }

  // 通过句柄向对应的查询条件取消注册回调，由开发者自行决定在何时调用。
  // listenerForUniqueId.offLayoutChildren(onLayoutChildrenComplete)
}
```

### onDrawChildren<sup>24+</sup>

onDrawChildren(callback: Callback\<number[]\>): void

通过[ComponentObserver](#componentobserver)注册drawChildren事件回调。使用callback异步回调。与[on('drawChildren')](#ondrawchildren20)相比，本方法在回调中额外返回子组件的uniqueId信息（Callback<number[]>），便于开发者定位具体子组件。如需获取子组件标识，建议使用本方法；若不需要子组件信息，两者均可使用。

以当前注册事件回调的节点为根节点，当组件的子组件位于UI组件主树中且绘制送显完成时，会触发该回调。如果组件树中存在多个drawChildren事件回调，只会触发最顶层的drawChildren事件回调。取消最顶层的回调后，其余drawChildren事件回调也无法生效。当前节点注册事件回调后，不支持修改其在UI组件主树中的层级位置。如需调整，请先取消事件回调，再重新注册事件回调。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| callback | [Callback](./arkui-ts/ts-types.md#callback12)\<number[]\>  | 是   | 监听drawChildren的回调，回调参数为子组件uniqueId数组，表示绘制送显完成的子组件的唯一标识列表。                              |

**示例：**

以下示例展示了inspector注册组件绘制送显完成回调通知能力的基本用法。通过[onDrawChildren<sup>24+</sup>](#ondrawchildren24)接口注册回调，当子树内节点完成渲染时，回调返回该节点的uniqueId信息。

```ts
import { inspector } from '@kit.ArkUI';

@Entry
@Component
struct ImageExample {
  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Row({ space: 5 }) {
          Image($r('app.media.startIcon'))
            .width(110)
            .height(110)
            .border({ width: 1 })
            .id('IMAGE_ID')
        }
        .id('ROW_ID')
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }

  listenerForRow: inspector.ComponentObserver = this.getUIContext().getUIInspector().createComponentObserver('ROW_ID');

  aboutToAppear() {
    let onDrawChildrenCompleteUniqueId: (childIds: number[]) => void = (childIds: number[]): void => {
      // 从API version 24开始，新增onDrawChildren接口。监听到drawChildren事件后，用户可以自定义实现逻辑。
    };

    this.listenerForRow.onDrawChildren(onDrawChildrenCompleteUniqueId);
  }
}
```

### offDrawChildren<sup>24+</sup>

offDrawChildren(callback?: Callback\<number[]\>): void

取消注册drawChildren事件回调。

要实现在子组件绘制送显完成后停止触发特定回调，只需通过ComponentObserver句柄，取消注册该回调即可。如果组件树中存在多个drawChildren事件回调，取消最顶层的回调后，其余drawChildren事件回调也无法生效。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| callback | [Callback](./arkui-ts/ts-types.md#callback12)\<number[]\>   | 否   | 需要取消注册的回调，如果参数缺省则取消注册该句柄下所有的回调。callback需要和[onDrawChildren](#ondrawchildren24)方法中的callback为相同对象时才能取消回调成功。 |

**示例：**

```ts
import { inspector } from '@kit.ArkUI';

@Entry
@Component
struct ImageExample {
  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Row({ space: 5 }) {
          Image($r('app.media.startIcon'))
            .width(110)
            .height(110)
            .border({ width: 1 })
            .id('IMAGE_ID')
        }
        .id('ROW_ID')
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }

  listenerForRow: inspector.ComponentObserver = this.getUIContext().getUIInspector().createComponentObserver('ROW_ID');

  aboutToAppear() {
    let onDrawChildrenCompleteUniqueId: (childIds: number[]) => void = (childIds: number[]): void => {
      // 从API version 24开始，新增onDrawChildren接口。监听到DrawChildren事件后，用户可以自定义实现逻辑。
    };

    this.listenerForRow.onDrawChildren(onDrawChildrenCompleteUniqueId);
  }
  // 通过句柄取消注册回调，由开发者自行决定在何时调用。
  // this.listenerForRow.offDrawChildren(onDrawChildrenCompleteUniqueId)
}
```