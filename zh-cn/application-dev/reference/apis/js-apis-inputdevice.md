# 输入设备


输入设备管理模块，用于监听输入设备连接、断开和变化，并查看输入设备相关信息。比如监听鼠标插拔，并获取鼠标的id、name和指针移动速度等信息。


> **说明**：<br>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import inputDevice from '@ohos.multimodalInput.inputDevice';
```


## inputDevice.getDeviceIds

getDeviceIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

获取所有输入设备的id列表，使用callback方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDevice

**参数**：

| 参数       | 类型                                       | 必填   | 说明    |
| -------- | ---------------------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是    | 回调函数。 |

**示例**：

```js
inputDevice.getDeviceIds((ids)=>{
    console.log("The device ID list is: " + ids);
});
```

## inputDevice.getDeviceIds

getDeviceIds(): Promise&lt;Array&lt;number&gt;&gt;

获取所有输入设备的id列表，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDevice

**返回值**：

| 参数                                 | 说明                  |
| ---------------------------------- | ------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise实例，用于异步获取结果。 |

**示例**：

```js
inputDevice.getDeviceIds().then((ids)=>{
    console.log("The device ID list is: " + ids);
});
```

## inputDevice.getDevice

getDevice(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void

获取输入设备的描述信息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDevice

**参数**：

| 参数       | 类型                                       | 必填   | 说明                          |
| -------- | ---------------------------------------- | ---- | --------------------------- |
| deviceId | number                                   | 是    | 需要获取信息的设备id。                |
| callback | AsyncCallback&lt;[InputDeviceData](#inputdevicedata)&gt; | 是    | 回调函数，异步返回InputDeviceData对象。 |

**示例**：

```js
// 示例获取设备id为1的设备name信息。
inputDevice.getDevice(1, (inputDevice)=>{
    console.log("The device name is: " + inputDevice.name);
});
```

## inputDevice.getDevice

getDevice(deviceId: number): Promise&lt;InputDeviceData&gt;

获取输入设备的描述信息，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDevice

**参数**：

| 参数       | 类型     | 必填   | 说明           |
| -------- | ------ | ---- | ------------ |
| deviceId | number | 是    | 需要获取信息的设备id。 |

**返回值**：

| 参数                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| Promise&lt;[InputDeviceData](#inputdevicedata)&gt; | Promise实例，用于异步获取结果。 |

**示例**：

```js
// 示例获取设备id为1的设备name信息。
inputDevice.getDevice(1).then((inputDevice)=>{
    console.log("The device name is: " + inputDevice.name);
});
```



## InputDeviceData

输入设备的描述信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

| 名称                   | 参数类型                                   | 说明                                       |
| -------------------- | -------------------------------------- | ---------------------------------------- |
| id                   | number                                 | 输入设备的唯一标识，同一个物理设备反复插拔，其设备id会发生变化。        |
| name                 | string                                 | 输入设备的名字。                                 |
| sources              | Array&lt;[SourceType](#sourcetype)&gt; | 输入设备支持的源类型。比如有的键盘上附带触摸板，则此设备有keyboard和touchpad两种输入源。 |
| axisRanges           | Array&lt;[axisRanges](#axisrange)&gt;  | 输入设备的轴信息。                                |

## AxisType<sup>9+</sup>

输入设备的轴类型。

## AxisRange

输入设备的轴信息。

**系统能力**： 以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

| 名称     | 参数类型                      | 说明       |
| ------ | ------------------------- | -------- |
| source | [SourceType](#sourcetype) | 轴的输入源类型。 |
| axis   | [AxisType](#axistype)     | 轴的类型     |
| max    | number                    | 轴上报的最大值  |
| min    | number                    | 轴上报的最小值  |


## SourceType

定义这个轴的输入源类型。比如鼠标设备可上报x轴事件，则x轴的源就是鼠标。

**系统能力**：以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

| 名称          | 参数类型   | 说明          |
| ----------- | ------ | ----------- |
| keyboard    | string | 表示输入设备是键盘。  |
| touchscreen | string | 表示输入设备是触摸屏。 |
| mouse       | string | 表示输入设备是鼠标。  |
| trackball   | string | 表示输入设备是轨迹球。 |
| touchpad    | string | 表示输入设备是触摸板。 |
| joystick    | string | 表示输入设备是操纵杆。 |
