#  multimodalinput子系统ChangeLog

##  cl.multimodalinput.1  inputMonitor接口实现错误修正

多模输入inputMonitor接口中针对TouchEvent的监听接口，callback中TouchEvent原先引用arkui-js的通用事件TouchEvent，但该接口没有对外暴露（即未export），IDE中默认TouchEvent为arkui-ts中的TouchEvent，ArtTS语法整改之后，原接口失效。因此需要将inputMointor中的TouchEvent引用修改为多模输入的TouchEvent。

**变更影响**

字段名变更，原有的字段获取的值为undefine

**关键的接口/组件变更**

使用inputMonitor监听多模输入TouchEvent时，需要单独import多模的touchEvent类

```ts
import touchEvent from '@ohos.multimodalInput.touchEvent';
try {
  inputMonitor.on('touch', (touchEvent: touchEvent.TouchEvent) => {
    console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

**适配指导**

OpenHarmony4.0.11.5之后需要应用将字段修改为多模的TouchEvent字段名

| 变更前         | 变更后     |
| -------------- | ---------- |
| type           | action     |
| timestamp      | actionTime |
| deviceId       | deviceId   |
| globalX        | screenX    |
| globalY        | screenY    |
| localX         | windowX    |
| localY         | windowY    |
| force          | pressure   |
| touches        | touches    |
| changedTouches | touches    |