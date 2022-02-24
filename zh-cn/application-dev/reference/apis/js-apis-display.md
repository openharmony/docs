# 显示设备属性

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本

## 导入模块

```
import display from '@ohos.display';
```


## DisplayState

用于表示显示设备的状态。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| STATE_UNKNOWN | 0 | 表示显示设备状态未知。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| STATE_OFF | 1 | 表示显示设备状态为关闭。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| STATE_ON | 2 | 表示显示设备状态为开启。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| STATE_DOZE | 3 | 表示显示设备为低电耗模式。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| STATE_DOZE_SUSPEND | 4 | 表示显示设备为睡眠模式，CPU为挂起状态&nbsp;。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| STATE_VR | 5 | 表示显示设备为VR模式。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| STATE_ON_SUSPEND | 6 | 表示显示设备为开启状态，CPU为挂起状态。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |


## Display

描述display对象的属性。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| id | number | 是 | 否 | 显示设备的id号。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| name | string | 是 | 否 | 显示设备的名称。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| alive | boolean | 是 | 否 | 显示设备是否启用。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| state | DisplayState | 是 | 否 | 显示设备的状态。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| refreshRate | number | 是 | 否 | 显示设备的刷新率。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| rotation | number | 是 | 否 | 显示设备的屏幕旋转角度。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| width | number | 是 | 否 | 显示设备的宽度，单位为像素。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| height | number | 是 | 否 | 显示设备的高度，单位为像素。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| densityDPI | number | 是 | 否 | 显示设备的屏幕密度，单位为DPI。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| densityPixels | number | 是 | 否 | 显示设备的屏幕密度，单位为像素。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| scaledDensity | number | 是 | 否 | 显示设备的显示字体的缩放因子。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| xDPI | number | 是 | 否 | x方向中每英寸屏幕的确切物理像素值。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| yDPI | number | 是 | 否 | y方向中每英寸屏幕的确切物理像素值。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |


## display.getDefaultDisplay

getDefaultDisplay(callback: AsyncCallback&lt;Display&gt;): void

获取当前默认的display对象。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;Display&gt; | 是 | 回调返回当前默认的display对象。 |

- 示例
  ```
  var displayClass = null;
  display.getDefaultDisplay((err, data) => {
      if (err) {
          console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
      displayClass = data;
  });
  ```


## display.on('add'|'remove'|'change')

on(type: 'add'|'remove'|'change', callback: Callback&lt;number&gt;): void

开启监听。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置监听类型。<br/>-&nbsp;type为"add"，表示监听增加显示设备。<br/>-&nbsp;type为"remove"，表示监听移除显示设备。<br/>-&nbsp;type为"change"，表示监听改变显示设备。 |
  | callback | Callback&lt;number&gt; | 是 | 回调返回监听到的显示设备的id。 |

- 示例
  ```
  var type = "add";
  var callback = (data) => {
      console.info('Listening enabled. Data: ' + JSON.stringify(data))
  }
  display.on(type, callback);
  ```


## display.off('add'|'remove'|'change')

off(type: 'add'|'remove'|'change', callback?: Callback&lt;number&gt;): void

关闭监听。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置监听类型。<br/>-&nbsp;type为"add"，表示监听增加显示设备。<br/>-&nbsp;type为"remove"，表示监听移除显示设备。<br/>-&nbsp;type为"change"，表示监听改变显示设备。 |
  | callback | Callback&lt;number&gt; | 否 | 回调返回监听到的显示设备的id。 |

- 示例
  ```
  var type = "remove";
  display.off(type);
  ```
