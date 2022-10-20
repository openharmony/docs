# 屏幕亮度

该模块提供屏幕亮度和模式的查询、调节接口。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 从API Version 7 开始不再维护，建议使用[`@ohos.brightness`](js-apis-brightness.md)替代。
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import brightness from '@system.brightness';
```


## brightness.getValue

getValue(options?: GetBrightnessOptions): void

获得设备当前的屏幕亮度值。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [GetBrightnessOptions](#getbrightnessoptions) | 否   | 获取屏幕亮度的参数对象。 |

**示例：**

  ```js
  brightness.getValue({
      success: function(data) {
          console.log('success get brightness value:' + data.value);
      },
      fail: function(data, code) {
          console.error('get brightness fail, code: ' + code + ', data: ' + data);
      }
  });
  ```


## brightness.setValue

etValue(options?: SetBrightnessOptions): void

设置设备当前的屏幕亮度值。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [SetBrightnessOptions](#setbrightnessoptions) | 否   | 设置屏幕亮度的参数对象。 |

**示例：**

  ```js
  brightness.setValue({
      value: 100,
      success: function() {
          console.log('handling set brightness success.');
      },
      fail: function(data, code) {
          console.error('handling set brightness value fail, code:' + code + ', data: ' + data);
      }
  });
  ```


## brightness.getMode

getMode(options?: GetBrightnessModeOptions: void

获得当前屏幕亮度模式。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [GetBrightnessModeOptions](#getbrightnessmodeoptions) | 否 | 获取屏幕亮度模式的参数对象。 |

**示例：**

  ```js
  brightness.getMode({
      success: function(data) {
          console.log('success get mode:' + data.mode);
      },
      fail: function(data, code){
          console.error('handling get mode fail, code:' + code + ', data: ' + data);
      }
  });
  ```


## brightness.setMode

setMode(options?: SetBrightnessModeOptions): void

设置设备当前的屏幕亮度模式。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [SetBrightnessModeOptions](#setbrightnessmodeoptions) | 否   | 设置屏幕亮度模式的参数对象。 |

**示例：**

  ```js
  brightness.setMode({
      mode: 1,
      success: function() {
          console.log('handling set mode success.');
      },
      fail: function(data, code) {
          console.error('handling set mode fail, code:' + code + ', data: ' + data);
      }
  });
  ```


## brightness.setKeepScreenOn

setKeepScreenOn(options?: SetKeepScreenOnOptions): void

>从API version 7开始不再维护，建议使用[window.setKeepScreenOn](js-apis-window.md#setkeepscreenon)替代。

设置屏幕是否保持常亮状态，开启常亮模式推荐在onShow()阶段调用。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [SetKeepScreenOnOptions](#setkeepscreenonoptions) | 否 | 设置屏幕常亮的参数对象。 |

**示例：**

  ```js
  brightness.setKeepScreenOn({
      keepScreenOn: true,
      success: function () {
          console.log('handling set keep screen on success.');
      },
      fail: function (data, code) {
          console.error('handling set keep screen on fail, code:' + code + ', data: ' + data);
      }
  });
  ```
## GetBrightnessOptions

获取屏幕亮度的参数对象。

| 名称     | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| success  | (data: [BrightnessResponse](#brightnessresponse)) => void | 否   | 接口调用成功的回调函数。data为[BrightnessResponse](#brightnessresponse)类型的返回值。 |
| fail     | (data: string, code: number) => void                      | 否   | 接口调用失败的回调函数。data为错误信息，code为错误码。       |
| complete | () => void                                                | 否   | 接口调用结束的回调函数。                                     |

## SetBrightnessOptions

设置屏幕亮度的参数对象。

| 名称     | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| value    | number                               | 是   | 屏幕亮度，值为1-255之间的整数。<br/>-&nbsp;如果值小于等于0，系统按1处理。<br/>-&nbsp;如果值大于255，系统按255处理。<br/>-&nbsp;如果值为小数，系统将处理为整数。例如设置为8.1，系统按8处理。 |
| success  | () => void                           | 否   | 接口调用成功的回调函数。                                     |
| fail     | (data: string, code: number) => void | 否   | 接口调用失败的回调函数。data为错误信息，code为错误码。       |
| complete | () => void                           | 否   | 接口调用结束的回调函数。                                     |

## BrightnessResponse

包含屏幕亮度的对象。

| 名称 | 类型  | 说明 |
| -------- | -------- | -------- |
| value | number | 屏幕亮度，范围：1到255。 |

## GetBrightnessModeOptions

获取屏幕亮度模式的参数对象。

| 名称     | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| success  | (data: [BrightnessModeResponse](#brightnessmoderesponse)) => void | 否   | 接口调用成功的回调函数。data为[BrightnessModeResponse](#brightnessmoderesponse)类型的返回值。 |
| fail     | (data: string, code: number) => void                         | 否   | 接口调用失败的回调函数。data为错误信息，code为错误码。       |
| complete | () => void                                                   | 否   | 接口调用结束的回调函数。                                     |

## SetBrightnessModeOptions

设置屏幕亮度模式的参数对象。

| 名称     | 类型                                 | 必填 | 说明                                                   |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------ |
| mode     | number                               | 是   | 0表示手动调节屏幕亮度模式，1表示自动调节屏幕亮度模式。 |
| success  | () => void                           | 否   | 接口调用成功的回调函数。                               |
| fail     | (data: string, code: number) => void | 否   | 接口调用失败的回调函数。data为错误信息，code为错误码。 |
| complete | () => void                           | 否   | 接口调用结束的回调函数。                               |

## BrightnessModeResponse

包含屏幕亮度模式的对象。

| 名称 | 类型  | 说明 |
| -------- | -------- | -------- |
| mode | number | 0表示手动调节屏幕亮度模式，1表示自动调节屏幕亮度模式。 |

## SetKeepScreenOnOptions

设置屏幕常亮的参数对象。

| 名称         | 类型                                 | 必填 | 说明                                                   |
| ------------ | ------------------------------------ | ---- | ------------------------------------------------------ |
| keepScreenOn | boolean                              | 是   | true表示保持屏幕常亮，false表示取消屏幕常亮。          |
| success      | () => void                           | 否   | 接口调用成功的回调函数。                               |
| fail         | (data: string, code: number) => void | 否   | 接口调用失败的回调函数。data为错误信息，code为错误码。 |
| complete     | () => void                           | 否   | 接口调用结束的回调函数。                               |

