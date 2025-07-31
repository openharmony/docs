# Class (AVCastPickerHelper)

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Class首批接口从API version 14开始支持。

投播半模态对象，可拉起半模态窗口，选择投播设备。在使用前，需要创建AVCastPickerHelper实例。

## 导入模块

```ts
import { avSession } from '@kit.AVSessionKit';
```

## constructor<sup>14+</sup>

constructor(context: Context)

创建AVCastPickerHelper对象，获取context参考[getContext](../apis-arkui/js-apis-arkui-UIContext.md#gethostcontext12)。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context | 是   | 应用上下文（仅支持[UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)）。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(40)
          .fontWeight(FontWeight.Bold)
          .onClick(()=>{
            let context = this.getUIContext().getHostContext() as Context;
            let avCastPicker = new avSession.AVCastPickerHelper(context);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## select<sup>14+</sup>

select(options?: AVCastPickerOptions): Promise\<void>

通过选择模式拉起AVCastPicker界面，用户可以选择投播设备。接口采用Promise异步返回形式，传入可选参数AVCastPickerOptions对象，无返回值。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [AVCastPickerOptions](arkts-apis-avsession-i.md#avcastpickeroptions14) | 否   | AVCastPicker选择选项。无此参数时，以AVCastPickerOptions默认值拉起。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function avCastPicker(context: common.Context) {
  let avCastPickerOptions : avSession.AVCastPickerOptions = {
    sessionType : 'video',
  }
  let avCastPicker = new avSession.AVCastPickerHelper(context);
  avCastPicker.select(avCastPickerOptions).then(() => {
    console.info('select successfully');
  }).catch((err: BusinessError) => {
    console.error(`AVCastPicker.select failed with err: ${err.code}, ${err.message}`);
  });
}
```

## on('pickerStateChange')<sup>14+</sup>

on(type: 'pickerStateChange', callback: Callback<AVCastPickerState\>) : void

设置半模态窗口变化的监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型       | 必填 | 说明      |
| --------| -----------|-----|------------|
| type     | string    | 是   | 事件回调类型，支持事件`'pickerStateChange'`：当半模态窗口变化时，触发该事件。 |
| callback | Callback\<[AVCastPickerState](js-apis-avCastPickerParam.md#avcastpickerstate11)>       | 是   | 回调函数，参数state是变化后的半模态窗口状态。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { AVCastPickerState } from '@kit.AVSessionKit';

async function onPickerStateChange(context: common.Context) {
  let avCastPicker = new avSession.AVCastPickerHelper(context);
  avCastPicker.on('pickerStateChange', (state: AVCastPickerState) => {
    console.info(`picker state change : ${state}`);
  });
}
```

## off('pickerStateChange')<sup>14+</sup>

off(type: 'pickerStateChange', callback?: Callback<AVCastPickerState\>) : void

取消半模态窗口变化事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                                                    |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------ |
| type     | string                                           | 是   | 取消对应的监听事件，支持事件`'pickerStateChange'`。         |
| callback | Callback\<[AVCastPickerState](js-apis-avCastPickerParam.md#avcastpickerstate11)> | 否   | 回调函数，参数state是变化后的半模态窗口状态。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                           |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';

async function onPickerStateChange(context: common.Context) {
  let avCastPicker = new avSession.AVCastPickerHelper(context);
  avCastPicker.off('pickerStateChange');
}
```
