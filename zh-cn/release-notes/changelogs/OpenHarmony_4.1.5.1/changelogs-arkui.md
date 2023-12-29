# ArkUI子系统变更说明

## cl.arkui.1 轴事件响应能力变更

**访问级别**

公开接口

**变更原因**

提升用户使用鼠标滚轮和触控板对滑动事件和滑动组件操作的便捷性，使其更贴合用户的行为习惯，并解决了多方向滑动事件行为冲突的问题。

**变更影响**

该变更为兼容性变更，无API变更，但是优化了滑动事件在使用鼠标滚轮和触控板时的响应逻辑，对应用原先的滑动/滚动事件的响应操作可能存在一定影响。

**变更发生版本**

从OpenHarmony SDK 4.1.5.1 开始。

**变更的接口/组件**

受影响的接口有：PanGesture、SwipeGesture。

受影响的组件有：List、Grid、Scroll等所有可使用鼠标滚轮进行滚动操作的组件。

**适配指导**

变更前：

无论鼠标指针所在的区域内有多少个滑动事件，鼠标滚轮和触控板的双指滑动仅能响应首个子节点上绑定的第一个滑动事件。若这个滑动事件的方向是横向的，那么鼠标滚轮可以触发它响应、双指在触控板上横向或纵向滑动也可以触发它响应。若这个滑动事件的方向是纵向的，那么鼠标滚轮可以触发它响应、双指在触控板上纵向滑动也可以触发它响应。

例子1：组件上绑定或内置的是一个横向的滑动事件，当鼠标指针位于该组件区域内，滚动鼠标滚轮可以触发事件响应，双指在触控板纵向或横向滑动也可以触发事件响应。

例子2：组件上绑定或内置的是一个纵向的滑动事件，当鼠标指针位于该组件区域内，滚动鼠标滚轮可以触发事件响应，双指在触控板纵向滑动也可以触发事件响应。

例子3：父组件上绑定或内置的是一个纵向的滑动事件，子组件上绑定或内置的是一个横向的滑动事件，当鼠标指针位于子组件区域内（同时也是在父组件的区域内），此时鼠标滚轮和触控板上的任何操作都无法使父组件响应，鼠标滚轮和触控板双指滑动（无论是横向还是纵向的滑动）均只能触发子组件上的滑动事件响应。

变更后：

当鼠标指针所在的区域内只有横向的滑动事件时，首个子节点上的第一个滑动事件可以被鼠标滚轮、Shift+鼠标滚轮、触控板的双指横向滑动触发响应。

当鼠标指针所在的区域内只有纵向的滑动事件时，首个子节点上的第一个滑动事件可以被鼠标滚轮、触控板的双指纵向滑动触发响应，不会被Shift+鼠标滚轮触发。

当鼠标指针所在的区域内既有横向的滑动事件，也有纵向的滑动事件时，首个子节点上的第一个纵向滑动事件可以被鼠标滚轮、触控板的双指纵向滑动触发响应，首个子节点上的第一个横向滑动事件可以被Shift+鼠标滚轮、触控板的双指横向滑动触发响应。

以上所有场景中，对于触控板的双指滑动操作，均不支持Shift组合操作，按住Shif不会对触发响应的结果造成任何影响。

例子1：滚动鼠标滚轮、Shift+滚动鼠标滚轮、双指在触控板横向滑动可以触发事件响应。

例子2：滚动鼠标滚轮、双指在触控板纵向滑动可以触发事件响应。

例子3：滚动鼠标滚轮、双指在触控板纵向滑动会触发父组件的滑动事件响应，Shift+滚动鼠标滚轮、双指在触控板横向滑动会触发子组件的滑动事件响应。
## cl.arkui.2 UIContext的showActionMenu的接口修改

**访问级别**

公开接口

**变更原因**

UIContext的showActionMenu的接口callback参数类型定义错误，导致接口回调不可用。

**变更影响**

该变更为非兼容性变更，存在API变更，修改原始不可用的接口参数，使得开发者可以如预期调用接口实现对应回调的接收和使用。若存在应用使用该错误接口，传入callback参数，则对应功能不可用。

**变更发生版本**

从OpenHarmony SDK 4.1.5.1 开始。

**变更的接口/组件**

受影响的接口有：@ohos.arkui.UIContext的showActionMenu方法。

**适配指导**

变更前：

callback参数为promptAction.ActionMenuSuccessResponse，为一个数据对象，若按照接口定义传入promptAction.ActionMenuSuccessResponse则该接口无法使用。

```ts
import { PromptAction, UIInspector } from '@ohos.arkui.UIContext';
import promptAction from '@ohos.promptAction';
import { BusinessError } from '@ohos.base';

let promptActionF: PromptAction = uiContext.getPromptAction();
try {
    promptActionF.showActionMenu({
      title: 'Title Info',
      buttons: [
        {
          text: 'item1',
          color: '#666666'
        },
        {
          text: 'item2',
          color: '#000000'
        }
      ]
    },  (data:promptAction.ActionMenuSuccessResponse))
} catch (error) {
  let message = (error as BusinessError).message;
  let code = (error as BusinessError).code;
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);
};
```

变更后：

callback参数数据类型为AsyncCallback&lt;[promptAction.ActionMenuSuccessResponse](../../../application-dev/reference/apis/js-apis-promptAction.md#actionmenusuccessresponse)&gt;，为回调方法。使用AsyncCallback&lt;[promptAction.ActionMenuSuccessResponse](../../../application-dev/reference/apis/js-apis-promptAction.md#actionmenusuccessresponse)&gt;作为callback的入参接口可以正常使用。

```ts
import { PromptAction, UIInspector } from '@ohos.arkui.UIContext';
import promptAction from '@ohos.promptAction';
import { BusinessError } from '@ohos.base';

let promptActionF: PromptAction = uiContext.getPromptAction();
try {
    promptActionF.showActionMenu({
      title: 'Title Info',
      buttons: [
        {
          text: 'item1',
          color: '#666666'
        },
        {
          text: 'item2',
          color: '#000000'
        }
      ]
    }, (err:BusinessError, data:promptAction.ActionMenuSuccessResponse) => {
        if (err) {
        console.info('showDialog err: ' + err);
        return;
        }
        console.info('showDialog success callback, click button: ' + data.index);
    });
} catch (error) {
    let message = (error as BusinessError).message;
    let code = (error as BusinessError).code;
    console.error(`showActionMenu args error code is ${code}, message is ${message}`);
};
```
## cl.arkui.3 RelativeContainer组件尺寸计算优先级变更

**访问级别**

公开接口

**变更原因**

当同时设置了组件尺寸和约束条件时，优先使用开发者设置的尺寸来表示组件大小。同时在API version 11上，增加了bias属性用于设置组件在约束条件下的偏移，上述约定也更便于开发者理解bias的含义。

**变更影响**

变更前，当组件的尺寸和约束条件同时设置时，优先采用约束条件来决定组件大小；变更后优先采用用户设置的尺寸来决定组件大小。

**变更发生版本**

从OpenHarmony SDK 4.1.5.1 开始（API version 11及以上）。

**变更的接口/组件**

受影响的组件有：RelativeContainer。

