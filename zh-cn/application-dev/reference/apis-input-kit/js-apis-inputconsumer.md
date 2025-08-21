# @ohos.multimodalInput.inputConsumer (全局快捷键)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

全局快捷键订阅模块，用于处理组合按键的订阅，本模块也支持音量键拦截监听能力。

> **说明：**
>
> - 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 全局快捷键指由系统或应用定义的组合按键，系统快捷键指由系统定义的全局快捷键，应用快捷键指由应用定义的全局快捷键。


## 导入模块


```js
import { inputConsumer, KeyEvent } from '@kit.InputKit';
```

## HotkeyOptions

快捷键选项。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

| 名称        | 类型   | 只读   | 可选   | 说明      |
| --------- | ------ | ------- | ------- | ------- |
| preKeys   | Array&lt;number&gt; | 否      | 否      | 修饰键（包括 Ctrl、Shift 和 Alt）集合，数量范围[1, 2]，无顺序要求。<br>例如，Ctrl+Shift+Esc中，Ctrl+Shift称为修饰键。 |
| finalKey  | number  | 否      | 否      | 被修饰键，除修饰键和Meta键以外的按键，详细按键介绍请参见[键值](js-apis-keycode.md)。<br>例如，Ctrl+Shift+Esc中，Esc称为被修饰键。 |
| isRepeat  | boolean  | 否      | 是      | 是否上报重复的按键事件。true表示上报，false表示不上报，默认值为true。 |

## KeyPressedConfig<sup>16+</sup>

按键事件消费设置。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**设备行为差异**：该接口仅在Phone和Tablet设备上生效，在其他设备上返回801错误码。

| 名称        | 类型   | 只读   | 可选   | 说明      |
| --------- | ------ | ------- | ------- | ------- |
| key       | number  | 否      | 否      | 按键键值。<br>当前仅支持[KEYCODE_VOLUME_UP](js-apis-keycode.md#keycode)键和[KEYCODE_VOLUME_DOWN](js-apis-keycode.md#keycode)键。 |
| action    | number  | 否      | 否      | 按键事件类型。当前仅支持取值为1，表示按键按下。 |
| isRepeat  | boolean  | 否      | 否      | 是否上报重复的按键事件。true表示上报，false表示不上报，默认值为true。 |

## inputConsumer.getAllSystemHotkeys

getAllSystemHotkeys(): Promise&lt;Array&lt;HotkeyOptions&gt;&gt;

获取所有系统快捷键，使用Promise异步回调。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**返回值：**

| 类型         |  说明                                       |
| ---------- |  ---------------------------------------- |
| Promise&lt;Array&lt;HotkeyOptions&gt;&gt;                    | Promise对象，返回所有系统快捷键的列表。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ------------------------- |
| 801      | Capability not supported. |

**示例：**

```js
import { inputConsumer } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputConsumer.getAllSystemHotkeys().then((data: Array<inputConsumer.HotkeyOptions>) => {
            console.log(`List of system hotkeys : ${JSON.stringify(data)}`);
          });
        })
    }
  }
}
```

## inputConsumer.on('hotkeyChange')

on(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback: Callback&lt;HotkeyOptions&gt;): void

订阅应用快捷键。获取满足条件的组合按键输入事件，使用Callback异步回调。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**参数：** 

| 参数名         | 类型                         | 必填   | 说明                                       |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | 是    | 事件类型，固定取值为'hotkeyChange'。                   |
| hotkeyOptions | [HotkeyOptions](#hotkeyoptions) | 是    | 快捷键选项。                 |
| callback   | Callback&lt;HotkeyOptions&gt; | 是    | 回调函数，获取满足条件的组合按键输入事件。 |

**错误码**：

以下错误码的详细介绍请参见[全局快捷键管理错误码](errorcode-inputconsumer.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |
| 4200002  | The hotkey has been used by the system. |
| 4200003  | The hotkey has been subscribed to by another. |

**示例：**

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
          let hotkeyOptions: inputConsumer.HotkeyOptions = {
            preKeys: [ leftCtrlKey ],
            finalKey: zKey,
            isRepeat: true
          };
          let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
            console.log(`hotkeyOptions: ${JSON.stringify(hotkeyOptions)}`);
          }
          try {
            inputConsumer.on("hotkeyChange", hotkeyOptions, hotkeyCallback);
          } catch (error) {
            console.error(`Subscribe failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputConsumer.off('hotkeyChange')

off(type: 'hotkeyChange', hotkeyOptions: HotkeyOptions, callback?: Callback&lt;HotkeyOptions&gt;): void

取消订阅应用快捷键。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**参数：** 

| 参数名         | 类型                         | 必填   | 说明                              |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | 是    | 事件类型，固定取值为'hotkeyChange'。        |
| hotkeyOptions | [HotkeyOptions](#hotkeyoptions) | 是    | 快捷键选项。             |
| callback   | Callback&lt;HotkeyOptions&gt; | 否    | 需要取消订阅的回调函数。若缺省，则取消当前应用快捷键选项已订阅的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |

**示例：**

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
          // 取消订阅单个应用快捷键回调函数
          let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
            console.log(`hotkeyOptions: ${JSON.stringify(hotkeyOptions)}`);
          }
          let hotkeyOption: inputConsumer.HotkeyOptions = {preKeys: [leftCtrlKey], finalKey: zKey, isRepeat: true};
          try {
            inputConsumer.on("hotkeyChange", hotkeyOption, hotkeyCallback);
            inputConsumer.off("hotkeyChange", hotkeyOption, hotkeyCallback);
            console.log(`Unsubscribe success`);
          } catch (error) {
            console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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
          // 取消订阅所有应用快捷键回调函数
          let hotkeyCallback = (hotkeyOptions: inputConsumer.HotkeyOptions) => {
            console.log(`hotkeyOptions: ${JSON.stringify(hotkeyOptions)}`);
          }
          let hotkeyOption: inputConsumer.HotkeyOptions = {preKeys: [leftCtrlKey], finalKey: zKey, isRepeat: true};
          try {
            inputConsumer.on("hotkeyChange", hotkeyOption, hotkeyCallback);
            inputConsumer.off("hotkeyChange", hotkeyOption);
            console.log(`Unsubscribe success`);
          } catch (error) {
            console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputConsumer.on('keyPressed')<sup>16+</sup>

on(type: 'keyPressed', options: KeyPressedConfig, callback: Callback&lt;KeyEvent&gt;): void

订阅按键按下事件，使用callback异步回调。若当前应用窗口为前台焦点窗口，用户按下指定按键，会触发回调。

订阅成功后，该按键事件的系统默认行为将被屏蔽，即不会再触发系统级的响应，如音量调节。要恢复系统响应，请使用[off](#inputconsumeroffkeypressed16)方法取消订阅。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**设备行为差异**：该接口仅在Phone和Tablet设备中可正常调用，在其他设备上返回801错误码。

**参数：**

| 参数名         | 类型                                | 必填  | 说明                              |
| ---------- | --------------------------             | ----  | ---------- |
| type       | string                                 | 是     | 事件类型，固定取值为'keyPressed'。        |
| options    | [KeyPressedConfig](#keypressedconfig16)| 是     | 按键事件消费设置。           |
| callback   | Callback&lt;[KeyEvent](./js-apis-keyevent.md#keyevent)&gt; | 是    | 回调函数，用于返回按键事件。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |

**示例：**

```js
import { inputConsumer, KeyEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            let options: inputConsumer.KeyPressedConfig = {
              key: 16,
              action: 1,
              isRepeat: false,
            }
            inputConsumer.on('keyPressed', options, (event: KeyEvent) => {
              console.log(`Subscribe success ${JSON.stringify(event)}`);
            });
          } catch (error) {
            console.error(`Subscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputConsumer.off('keyPressed')<sup>16+</sup>

off(type: 'keyPressed', callback?: Callback&lt;KeyEvent&gt;): void

取消对'keyPressed'事件的订阅，使用callback异步回调。调用该方法后，被屏蔽的系统按键默认行为将恢复，即系统对音量调节等默认响应将恢复。

**系统能力：** SystemCapability.MultimodalInput.Input.InputConsumer

**设备行为差异**：该接口仅在Phone和Tablet设备中可正常调用，在其他设备上返回801错误码。

**参数：**

| 参数名         | 类型                         | 必填   | 说明                              |
| ---------- | -------------------------- | ---- | ---------- |
| type       | string                     | 是    | 事件类型，固定取值为'keyPressed'。        |
| callback   | Callback&lt;[KeyEvent](./js-apis-keyevent.md#keyevent)&gt; | 否    | 需要取消订阅的回调函数。若缺省，则取消当前已订阅的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |

**示例：**

```js
import { inputConsumer, KeyEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 取消指定回调函数
            inputConsumer.off('keyPressed', (event: KeyEvent) => {
              console.log(`Unsubscribe success ${JSON.stringify(event)}`);
            });
            // 取消当前已订阅的所有回调函数
            inputConsumer.off("keyPressed");
          } catch (error) {
            console.error(`Unsubscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```
