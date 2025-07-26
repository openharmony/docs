# 全局快捷键开发指导

## 场景介绍

全局快捷键功能提供订阅全局快捷键、设置屏蔽按键拦截状态等能力。使用场景例如：当用户需要通过全局快捷键实现快捷功能时，开发者可以订阅全局快捷键，通过组合按键启用快捷功能。

全局快捷键指由系统或应用定义的组合按键，系统快捷键指由系统定义的全局快捷键，应用快捷键指由应用定义的全局快捷键。

## 导入模块

```js
import { inputConsumer } from '@kit.InputKit';
```

## 接口说明

全局快捷键管理常用接口如下表所示，接口详细介绍请参考[ohos.multimodalInput.inputConsumer-sys文档](../../reference/apis-input-kit/js-apis-inputconsumer-sys.md)和[ohos.multimodalInput.inputConsumer文档](../../reference/apis-input-kit/js-apis-inputconsumer.md)。

| 接口名称  | 描述 |
| ------------------------------------------------------------ | -------------------------- |
| on(type: 'key', keyOptions: KeyOptions, callback: Callback\<KeyOptions>): void | 订阅系统快捷键。 |
| off(type: 'key', keyOptions: KeyOptions, callback?: Callback\<KeyOptions>): void | 取消订阅系统快捷键。 |
| setShieldStatus(shieldMode: ShieldMode, isShield: boolean): void | 设置屏蔽按键拦截状态。 |
| getShieldStatus(shieldMode: ShieldMode): boolean | 获取屏蔽按键拦截是否生效。 |
| getAllSystemHotkeys(): Promise\<Array\<HotkeyOptions>> | 获取所有系统快捷键。 |
| on(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback: Callback\<HotkeyOptions>): void | 订阅应用快捷键。 |
| off(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback?: Callback\<HotkeyOptions>): void | 取消订阅应用快捷键。 |

## 开发步骤

特定全局快捷键的应用开启时调用[on](../../reference/apis-input-kit/js-apis-inputconsumer-sys.md#inputconsumeron)方法订阅全局快捷键，应用关闭时再用[off](../../reference/apis-input-kit/js-apis-inputconsumer-sys.md#inputconsumeroff)方法取消订阅全局快捷键。

```js
import { inputConsumer } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let leftAltKey = 2045;
          let tabKey = 2049;
          let callback = (keyOptions: inputConsumer.KeyOptions) => {
            console.info(`keyOptions: ${JSON.stringify(keyOptions)}`);
          }
          //应用开启
          let keyOption: inputConsumer.KeyOptions = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
          try {
            inputConsumer.on("key", keyOption, callback);//订阅系统快捷键
          } catch (error) {
            console.error(`Execute failed, error: ${JSON.stringify(error, ["code", "message"])}`);
          }
          //应用关闭
          try {
            inputConsumer.off("key", keyOption, callback);//取消订阅系统快捷键
            console.info(`Unsubscribe success`);
          } catch (error) {
            console.error(`Execute failed, error: ${JSON.stringify(error, ["code", "message"])}`);
          }
        })
    }
  }
}
```

```js
import { inputConsumer } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let leftCtrlKey = 2072;
          let zKey = 2042;
          let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
            console.info(`keyOptions: ${JSON.stringify(hotkeyOptions)}`);
          }
          let hotkeyOption: inputConsumer.HotkeyOptions = {preKeys: [leftCtrlKey], finalKey: zKey, isRepeat: false};
          //在订阅全局快捷键之前，需要先获取所有系统快捷键，查询需要订阅的快捷键是否存在于系统快捷键列表中，避免冲突
          inputConsumer.getAllSystemHotkeys().then((data: Array<inputConsumer.HotkeyOptions>) => {//获取所有系统快捷键
            console.info(`List of system hotkeys : ${JSON.stringify(data)}`);
          });
          //应用开启
          try {
            inputConsumer.on("hotkeyChange", hotkeyOption, hotkeyCallback);//订阅应用快捷键
          } catch (error) {
            console.error(`Execute failed, error: ${JSON.stringify(error, ["code", "message"])}`);
          }
          //应用关闭
          try {
            inputConsumer.off("hotkeyChange", hotkeyOption, hotkeyCallback);//取消订阅应用快捷键
            console.info(`Unsubscribe success`);
          } catch (error) {
            console.error(`Execute failed, error: ${JSON.stringify(error, ["code", "message"])}`);
          }
        })
    }
  }
}
```