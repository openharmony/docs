# 输入设备


输入设备管理模块，用于监听输入设备连接、断开和变化，并查看输入设备相关信息。比如监听鼠标插拔，并获取鼠标的id、name和指针移动速度等信息。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import inputDevice from '@ohos.multimodalInput.inputDevice';
```


## inputDevice.getDeviceIds

getDeviceIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

获取所有输入设备的id列表，使用callback方式作为异步方法。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**参数：** 

| 参数 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是 | 回调函数。 | 

**示例：** 

```
data: {
    deviceIds: Array,
},
callback: function(ids) {
    this.deviceIds = ids;
},
testGetDeviceIds: function () {
    console.info("InputDeviceJsTest---start---testGetDeviceIds");
    inputDevice.getDeviceIds(this.callback);
    console.info("InputDeviceJsTest---end---testGetDeviceIds");
}
```


## inputDevice.getDevice

getDevice(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void

获取输入设备的描述信息，使用callback方式作为异步方法。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**参数：** 

| 参数 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| deviceId | number | 是 | 需要获取信息的设备id。 | 
| callback | AsyncCallback&lt;[InputDeviceData](#inputdevicedata)&gt; | 是 | 回调函数，异步返回InputDeviceData对象。 | 

**示例：** 

```
InputDeviceData {
    deviceId : 0,
    name : "NA",
    sources : Array,
    axisRanges : Array,
},
callback: function(deviceData) {
    this.InputDeviceData = deviceData;
},
testGetDevice: function () {
    // 示例获取设备id为1的设备信息。
    console.info("InputDeviceJsTest---start---testGetDevice");
    inputDevice.getDevice(1, this.callback);
    console.info("InputDeviceJsTest---end---testGetDevice");
}
```


## InputDeviceData

输入设备的描述信息。

**系统能力：**  以下各项对应系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

  | 名称 | 参数类型 | 说明 | 
| -------- | -------- | -------- |
| id | number | 输入设备的唯一标识，同一个物理设备反复插拔，其设备id会发生变化。 | 
| name | string | 输入设备的名字。 | 
| sources | Array&lt;[SourceType](#sourcetype)&gt; | 输入设备支持的源类型。比如有的键盘上附带触摸板，则此设备有keyboard和touchpad两种输入源。 |


## SourceType

定义这个轴的输入源类型。比如鼠标设备可上报x轴事件，则x轴的源就是鼠标。

**系统能力：**  以下各项对应系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

  | 名称 | 参数类型 | 说明 | 
| -------- | -------- | -------- |
| keyboard | string | 表示输入设备是键盘。 |
| touchscreen | string | 表示输入设备是触摸屏。 | 
| mouse | string | 表示输入设备是鼠标。 |
| trackball | string | 表示输入设备是轨迹球。 |
| touchpad | string | 表示输入设备是触摸板。 |
| joystick | string | 表示输入设备是操纵杆。 |
