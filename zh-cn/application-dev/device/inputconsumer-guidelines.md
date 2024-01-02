# 组合按键开发指导

## 场景介绍

组合按键管理提供订阅组合按键、设置屏蔽按键拦截状态等能力。使用场景例如：当用户需要组合按键实现快捷功能时，开发者可以通过订阅组合按键，通过组合按键启用快捷功能。

## 导入模块

```js
import inputConsumer from '@ohos.multimodalInput.inputConsumer';
```

## 接口说明

组合按键管理常用接口如下表所示，接口详细介绍请参考[ohos.multimodalInput.inputConsumer文档](../reference/apis/js-apis-inputconsumer.md)。

| 实例名 | 接口名  | 说明 |
| ----------- | ------------------------------------------------------------ | -------------------------- |
| inputConsumer | function on(type: 'key', keyOptions: KeyOptions, callback: Callback<KeyOptions>): void ；| 订阅组合按键。 |
| inputConsumer | function off(type: 'key', keyOptions: KeyOptions, callback?: Callback<KeyOptions>): void； | 取消订阅组合按键。 |
| inputConsumer | function setShieldStatus(shieldMode: ShieldMode, isShield: boolean): void； | 设置屏蔽按键拦截状态。 |
| inputConsumer | function getShieldStatus(shieldMode: ShieldMode): boolean; | 获取屏蔽按键拦截是否生效。 |

## 开发步骤

调用[on](../reference/apis/js-apis-inputconsumer.md#inputconsumeron)方法订阅组合键，再用[off](../reference/apis/js-apis-inputconsumer.md#inputconsumeroff)方法取消组合键订阅。

```js
let leftAltKey = 2045;
let tabKey = 2049;
// 取消订阅单个回调函数
let callback = (keyOptions: inputConsumer.KeyOptions) => {
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);
}
let keyOption: inputConsumer.KeyOptions = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
try {
  inputConsumer.on("key", keyOption, callback);
  inputConsumer.off("key", keyOption, callback);
  console.log(`Unsubscribe success`);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```