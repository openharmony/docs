# 输入设备


输入设备管理模块，用于监听输入设备连接、断开和变化，并查看输入设备相关信息。比如监听鼠标插拔，并获取鼠标的id、name和指针移动速度等信息。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```js
import inputDevice from '@ohos.multimodalInput.inputDevice';
```

## inputDevice.on<sup>9+</sup>

on(type: “change”, listener: Callback&lt;DeviceListener&gt;): void

监听设备的热插拔事件。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**参数：**

| 参数     | 类型                                              | 必填 | 说明                 |
| -------- | ------------------------------------------------- | ---- | -------------------- |
| type     | string                                            | 是   | 输入设备的事件类型   |
| listener | Callback&lt;[DeviceListener](#devicelistener<sup>9+</sup>)&gt; | 是   | 可上报的输入设备事件 |

**示例：** 

```js
let isPhysicalKeyboardExist = false;
inputDevice.on("change", (data)=>{
    console.log("type: " + data.type + ", deviceId: " + data.deviceId);
    inputDevice.getKeyboardType(data.deviceId, (ret) => {
       console.log("The keyboard type of the device is: " + ret);
        if (ret == 2 && data.type == 'add') {
            // 监听物理键盘已连接。
            isPhysicalKeyboardExist = true;
        } else if (ret == 2 && data.type == 'remove') {
            // 监听物理键盘已duan。
            isPhysicalKeyboardExist = false;
        }
    });
});
// 根据isPhysicalKeyboardExist的值决定软键盘是否弹出。
```

## inputDevice.off<sup>9+</sup>

off(type: “change”, listener?: Callback&lt;DeviceListener&gt;): void

取消监听设备的热插拔事件。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**参数：**

| 参数     | 类型                                              | 必填 | 说明                 |
| -------- | ------------------------------------------------- | ---- | -------------------- |
| type     | string                                            | 是   | 输入设备的事件类型   |
| listener | Callback&lt;[DeviceListener](#devicelistener<sup>9+</sup>)&gt; | 否   | 可上报的输入设备事件 |

**示例：** 

```js
listener: function(data) {
    console.log("type: " + data.type + ", deviceId: " + data.deviceId);
}

// 单独取消listener的监听。
inputDevice.off("change", this.listener);

// 取消所有监听
inputDevice.off("change");
```

## inputDevice.getDeviceIds

getDeviceIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

获取所有输入设备的id列表，使用callback方式作为异步方法。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**参数：**

| 参数       | 类型                                       | 必填   | 说明    |
| -------- | ---------------------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是    | 回调函数。 |

**示例：** 

```js
inputDevice.getDeviceIds((ids)=>{
    console.log("The device ID list is: " + ids);
});
```

## inputDevice.getDeviceIds

function getDeviceIds(): Promise&lt;&lt;Array&lt;number&gt;&gt;

获取所有输入设备的id列表，使用Promise方式作为异步方法。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**返回值：**

| 参数                      | 说明                          |
| ------------------------- | ----------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise实例，用于异步获取结果 |

**示例：**

```js
inputDevice.getDeviceIds().then((ids)=>{
    console.log("The device ID list is: " + ids);
});
```

## inputDevice.getDevice

getDevice(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void

获取输入设备的描述信息，使用callback方式作为异步方法。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**参数：** 

| 参数       | 类型                                       | 必填   | 说明                          |
| -------- | ---------------------------------------- | ---- | --------------------------- |
| deviceId | number                                   | 是    | 需要获取信息的设备id。                |
| callback | AsyncCallback&lt;[InputDeviceData](#inputdevicedata)&gt; | 是    | 回调函数，异步返回InputDeviceData对象。 |

**示例：** 

```js
// 示例获取设备id为1的设备name信息。
inputDevice.getDevice(1, (inputDevice)=>{
    console.log("The device name is: " + inputDevice.name);
});
```

## inputDevice.getDevice

function getDevice(deviceId: number): Promise&lt;InputDeviceData&gt;

获取输入设备的描述信息，使用Promise方式作为异步方法。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**参数：** 

| 参数     | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| deviceId | number | 是   | 需要获取信息的设备id。 |

**返回值：**

| 参数                                               | 说明                          |
| -------------------------------------------------- | ----------------------------- |
| Promise&lt;[InputDeviceData](#inputdevicedata)&gt; | Promise实例，用于异步获取结果 |

**示例：**

```js
// 示例获取设备id为1的设备name信息。
inputDevice.getDevice(1).then((inputDevice)=>{
    console.log("The device name is: " + inputDevice.name);
});
```

## inputDevice.supportKeys<sup>9+</sup>

supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;, callback: Callback&lt;Array&lt;boolean&gt;&gt;): void;

获取输入设备的描述信息，使用callback方式作为异步方法。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**参数：** 

| 参数     | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| deviceId | number                               | 是   | 输入设备的唯一标识，同一个物理设备反复插拔，其设备id会发生变化。 |
| keys     | Array&lt;KeyCode&gt;                 | 是   | 需要查询的键码值，最多支持5个按键查询。                      |
| callback | Callback&lt;Array&lt;boolean&gt;&gt; | 是   | 回调函数，异步返回查询结果。                                 |

**示例：** 

```js
// 示例查询id为1的设备对于17、22和2055按键的支持情况。
inputDevice.supportKeys(1, [17, 22, 2055], (ret)=>{
    console.log("The query result is as follows: " + ret);
});
```

## inputDevice.supportKeys<sup>9+</sup>

supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;): Promise&lt;Array&lt;boolean&gt;&gt;；

获取输入设备的描述信息，使用Promise方式作为异步方法。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**参数：** 

| 参数     | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId | number               | 是   | 输入设备的唯一标识，同一个物理设备反复插拔，其设备id会发生变化。 |
| keys     | Array&lt;KeyCode&gt; | 是   | 需要查询的键码值，最多支持5个按键查询。                      |

**返回值：**

| 参数                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise&lt;Array&lt;boolean&gt;&gt; | Promise实例，用于异步获取结果 |

**示例：** 

```js
// 示例查询id为1的设备对于17、22和2055按键的支持情况。
inputDevice.supportKeys(1, [17, 22, 2055]).then((ret)=>{
    console.log("The query result is as follows: " + ret);
})
```

## inputDevice.getKeyboardType<sup>9+</sup>

getKeyboardType(deviceId: number, callback: AsyncCallback&lt;KeyboardType&gt;): void;

查询输入设备的键盘类型，使用callback方式作为异步方法。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**参数：** 

| 参数     | 类型                                               | 必填 | 说明                                                         |
| -------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| deviceId | number                                             | 是   | 输入设备的唯一标识，同一个物理设备反复插拔，其设备id会发生变化。 |
| callback | AsyncCallback&lt;[KeyboardType](#keyboardtype)&gt; | 是   | 回调函数，异步返回查询结果。                                 |

**示例：** 

```js
// 示例查询设备id为1的设备键盘类型。
inputDevice.getKeyboardType(1, (ret)=>{
    console.log("The keyboard type of the device is: " + ret);
});
```

## inputDevice.getKeyboardType<sup>9+</sup>

getKeyboardType(deviceId: number,): Promise&lt;KeyboardType&gt;；

查询输入设备的键盘类型，使用Promise方式作为异步方法。

**系统能力：** SystemCapability.MultimodalInput.Input.InputDevice

**返回值：**

| 参数                                         | 说明                          |
| -------------------------------------------- | ----------------------------- |
| Promise&lt;[KeyboardType](#keyboardtype)&gt; | Promise实例，用于异步获取结果 |

**示例：** 

```js
// 示例查询设备id为1的设备键盘类型。
inputDevice.getKeyboardType().then((ret)=>{
    console.log("The keyboard type of the device is: " + ret);
})
```

## DeviceListener<sup>9+</sup>

输入设备的描述信息。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

| 名称     | 参数类型                    | 说明                                                         |
| -------- | --------------------------- | ------------------------------------------------------------ |
| type     | [ChangeType](#changetype) | 表示输入设备插入或者移除。                                   |
| deviceId | number                      | 输入设备的唯一标识，同一个物理设备反复插拔，其设备id会发生变化。 |

## InputDeviceData

输入设备的描述信息。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

| 名称                 | 参数类型                               | 说明                                                         |
| -------------------- | -------------------------------------- | ------------------------------------------------------------ |
| id                   | number                                 | 输入设备的唯一标识，同一个物理设备反复插拔，其设备id会发生变化。 |
| name                 | string                                 | 输入设备的名字。                                             |
| sources              | Array&lt;[SourceType](#sourcetype)&gt; | 输入设备支持的源类型。比如有的键盘上附带触摸板，则此设备有keyboard和touchpad两种输入源。 |
| axisRanges           | Array&lt;[axisRanges](#axisrange)&gt;  | 输入设备的轴信息。                                           |
| bus<sup>9+</sup>     | number                                 | 输入设备的总线类型。                                         |
| product<sup>9+</sup> | number                                 | 输入设备的产品信息。                                         |
| vendor<sup>9+</sup>  | number                                 | 输入设备的厂商信息。                                         |
| version<sup>9+</sup> | number                                 | 输入设备的版本信息。                                         |
| phys<sup>9+</sup>    | string                                 | 输入设备的物理地址。                                         |
| uniq<sup>9+</sup>    | string                                 | 输入设备的唯一标识。                                         |

## AxisType<sup>9+</sup>

输入设备的轴类型

**系统能力：**  以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

| 名称        | 参数类型 | 说明                |
| ----------- | -------- | ------------------- |
| touchMajor  | string   | 表示touchMajor轴。  |
| touchMinor  | string   | 表示touchMinor轴。  |
| toolMinor   | string   | 表示toolMinor轴。   |
| toolMajor   | string   | 表示toolMajor轴。   |
| orientation | string   | 表示orientation轴。 |
| pressure    | string   | 表示pressure轴。    |
| x           | string   | 表示x轴。           |
| y           | string   | 表示y轴。           |
| NULL        | string   | 无。                |

## AxisRange

输入设备的轴信息

**系统能力：**  以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

| 名称                    | 参数类型                  | 说明             |
| ----------------------- | ------------------------- | ---------------- |
| source                  | [SourceType](#sourcetype) | 轴的输入源类型。 |
| axis                    | [AxisType](axistype)      | 轴的类型。       |
| max                     | number                    | 轴的最大值。     |
| min                     | number                    | 轴的最小值。     |
| fuzz<sup>9+</sup>       | number                    | 轴的模糊值。     |
| flat<sup>9+</sup>       | number                    | 轴的基准值。     |
| resolution<sup>9+</sup> | number                    | 轴的分辨率。     |

## SourceType

定义这个轴的输入源类型。比如鼠标设备可上报x轴事件，则x轴的源就是鼠标。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

| 名称          | 参数类型   | 说明          |
| ----------- | ------ | ----------- |
| keyboard    | string | 表示输入设备是键盘。  |
| touchscreen | string | 表示输入设备是触摸屏。 |
| mouse       | string | 表示输入设备是鼠标。  |
| trackball   | string | 表示输入设备是轨迹球。 |
| touchpad    | string | 表示输入设备是触摸板。 |
| joystick    | string | 表示输入设备是操纵杆。 |

## ChangeType

定义监听设备热插拔事件。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

| 名称   | 参数类型 | 说明               |
| ------ | -------- | ------------------ |
| add    | string   | 表示输入设备插入。 |
| remove | string   | 表示输入设备移除。 |

## KeyboardType<sup>9+</sup>

定义键盘输入设备的类型。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputDevice

| 名称                | 参数类型 | 值   | 说明               |
| ------------------- | -------- | ---- | ------------------ |
| NONE                | number   | 0    | 表示无按键设备。   |
| UNKNOWN             | number   | 1    | 表示未知按键设备。 |
| ALPHABETIC_KEYBOARD | number   | 2    | 表示全键盘设备。   |
| DIGITAL_KEYBOARD    | number   | 3    | 表示小键盘设备。   |
| HANDWRITING_PEN     | number   | 4    | 表示手写笔设备。   |
| REMOTE_CONTROL      | number   | 5    | 表示遥控器设备。   |