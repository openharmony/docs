# 输入监听开发指导

## 场景介绍

输入监听提供监听按键，触控板特殊手势等能力。使用场景例如：当用户需要应用在触控板三指上划实现特定功能时，开发者可以通过监听三指上划判断特定功能是否启用。

## 导入模块

```js
import { inputMonitor } from '@kit.InputKit';
```

## 接口说明

输入监听常用接口如下表所示，接口详细介绍请参考[ohos.multimodalInput.inputMonitor文档](../../reference/apis-input-kit/js-apis-inputmonitor-sys.md)。

| 接口名称  | 描述 |
| ------------------------------------------------------------ | -------------------------- |
| on(type: 'mouse', receiver: Callback<MouseEvent>): void |监听鼠标事件。 |
| on(type: 'touch', receiver: TouchEventReceiver): void | 监听触屏事件。 |
| on(type: 'pinch', receiver: TouchEventReceiver): void | 监听捏合事件。 |
| on(type: 'threeFingersSwipe', receiver: Callback<ThreeFingersSwipe>): void | 监听三指上划事件。 |
| on(type: 'threeFingersTap', receiver: Callback<ThreeFingersSwipe>): void | 监听三指清点事件。 |
| on(type: 'fourFingersSwipe', receiver: Callback<FourFingersSwipe>): void | 监听四指滑动事件。 |
| on(type: 'rotate', fingers: number, receiver: Callback<Rotate>): void | 监听旋转事件。 |
| off(type: 'mouse', receiver: Callback<MouseEvent>): void |取消监听鼠标事件。 |
| off(type: 'touch', receiver: TouchEventReceiver): void | 取消监听触屏事件。 |
| off(type: 'pinch', receiver: TouchEventReceiver): void | 取消监听捏合事件。 |
| off(type: 'threeFingersSwipe', receiver: Callback<ThreeFingersSwipe>): void | 取消监听三指上划事件。 |
| off(type: 'threeFingersTap', receiver: Callback<ThreeFingersSwipe>): void | 取消监听三指清点事件。 |
| off(type: 'fourFingersSwipe', receiver: Callback<FourFingersSwipe>): void | 取消监听四指滑动事件。 |
| off(type: 'rotate', fingers: number, receiver: Callback<Rotate>): void | 取消监听旋转事件。 |

## 开发步骤

当应用需要根据鼠标按键按下状态变化样式时。调用[on](../../reference/apis-input-kit/js-apis-inputmonitor-sys.md#inputmonitoronmouse9)监听鼠标按键事件，调用[off](../../reference/apis-input-kit/js-apis-inputmonitor-sys.md#inputmonitoroffmouse9)取消监听鼠标按键事件.

```js
import { MouseEvent } from '@kit.InputKit';

let BUTTON_DOWN = 2;
let callback = (mouseEvent: MouseEvent) => {
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
    if(mouseEvent.action = BUTTON_DOWN){
      return true;//鼠标按下回调
    }
    return false;
};

try {
  inputMonitor.on('mouse', (mouseEvent: MouseEvent) => {//开始监听鼠标事件
    console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
//监听鼠标按下，按下callbackreturn true
try {
  inputMonitor.off('mouse', callback);//关闭监听鼠标事件
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor off failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```