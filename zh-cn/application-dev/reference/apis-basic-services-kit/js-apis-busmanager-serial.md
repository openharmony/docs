# @ohos.busManager.serial (串口通信管理)

<!--Kit: Basic Services Kit-->
<!--Subsystem: BusManager-->
<!--Owner: @hwymlgitcode-->
<!--Designer: @hwymlgitcode-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->

本模块提供串口通信管理功能，适用于需要与串口设备进行数据交互的场景，如工业控制、传感器数据采集、嵌入式设备通信等。支持获取串口设备列表、打开和关闭串口、读写数据、硬件流控信号管理等功能，帮助开发者便捷地实现与外部串口设备的通信，提高设备互联效率。

**起始版本：** 26.0.0

## 导入模块

```ts
import { serial } from '@kit.BasicServicesKit';
```

## serial.getSerialPortList

getSerialPortList(): Promise&lt;[SerialPort](#serialport)[]&gt;

查询串口设备列表，返回[SerialPort](#serialport)对象数组。使用Promise异步回调。用于需要识别可用串口设备的场景，如工业设备连接、物联网设备管理、嵌入式系统调试等应用。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**返回值：**

| 类型                                      | 说明                |
|-----------------------------------------|-------------------|
| Promise&lt;[SerialPort](#serialport)[]&gt; | Promise对象，返回串口设备列表。 |

**错误码：**

以下错误码的详细介绍参见[通用错误码](../errorcode-universal.md)和[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                                         |
| -------- | ------------------------------------------------ |
| 203      | This function is prohibited by enterprise management policies. |
| 35700001 | Service error.                                   |

**示例：**

```ts
// BusinessError需从@kit.BasicServicesKit导入
// 获取串口设备列表
serial.getSerialPortList().then((portList: serial.SerialPort[]) => {
  console.info(`getSerialPortList success, length: ${portList.length}`);
  if (portList.length > 0) {
    let portInfo: serial.SerialPortInfo = portList[0].portInfo;
    console.info(`portName: ${portInfo.portName}`);
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to get serial port list. Code: ${error.code}, message: ${error.message}`);
});
```

## SerialPort

串口对象，提供串口设备的信息和通信能力。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

### 属性

| 名称       | 类型                                       | 只读 | 可选 | 说明         |
| ---------- | ------------------------------------------ | ---- | ---- | ------------ |
| portInfo   | [SerialPortInfo](#serialportinfo)          | 是   | 否   | 串口设备信息。 |

### open

open(config?: [SerialConfigs](#serialconfigs)): Promise&lt;void&gt;

打开串口设备。使用Promise异步回调。用于建立与串口设备的通信连接，如传感器数据采集、设备控制命令发送、串口打印机等场景。

**配对调用：**
- 调用open()后，必须在使用完毕后调用close()释放串口资源
- 未调用close()会导致串口资源泄漏，可能影响其他应用的串口使用

**起始版本：** 26.0.0

**系统能力：**  SystemCapability.BusManager.Serial

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                      | 必填 | 说明                                       |
| ------ | ----------------------------------------- | ---- | ------------------------------------------ |
| config | [SerialConfigs](#serialconfigs)           | 否   | 串口通信参数。不传入config参数时，使用SerialConfigs的默认配置打开串口。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 35700001 | Service error.                    |
| 35700002 | Invalid parameter.                |
| 35700003 | Virtual serial port disconnected. |
| 35700004 | Port already in use.              |
| 35700007 | User authorization required.      |

**示例：**

```ts
// BusinessError需从@kit.BasicServicesKit导入
// 获取串口列表并打开第一个串口
serial.getSerialPortList().then(async (portList: serial.SerialPort[]) => {
  if (portList.length === 0) {
    console.error('portList is empty');
    return;
  }
  let port: serial.SerialPort = portList[0];
  let config: serial.SerialConfigs = {
    baudRate: 115200,
    dataBits: serial.DataBits.EIGHT,
    stopBits: serial.StopBits.ONE,
    parity: serial.Parity.NONE
  };
  await port.open(config);
  console.info('open success');
  // 串口使用完毕后需调用port.close()释放资源
  await port.close();
}).catch((error: BusinessError) => {
  console.error(`Failed to open serial port. Code: ${error.code}, message: ${error.message}`);
});
```

### close

close(): Promise&lt;void&gt;

关闭串口设备。使用Promise异步回调。用于断开与串口设备的通信连接，如应用退出、设备切换、任务完成后释放串口资源等场景。需在串口打开后调用。

**配对调用：**
- 必须先调用open()打开串口，才能调用close()关闭串口
- 调用close()后释放串口资源，如需再次使用需要重新调用open()

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息             |
| -------- | -------------------- |
| 35700001 | Service error.       |
| 35700005 | Port not open.       |

**示例：**

<!--code_no_check-->
```ts
// BusinessError需从@kit.BasicServicesKit导入
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 关闭串口
port.close().then(() => {
  console.info('close success');
}).catch((error: BusinessError) => {
  console.error(`Failed to close serial port. Code: ${error.code}, message: ${error.message}`);
});
```

### write

write(data: Uint8Array, timeout?: number): Promise&lt;number&gt;

向串口设备发送数据，每次发送数据长度范围：(0, 4096]。使用Promise异步回调。用于向连接的串口设备发送控制命令、数据包、配置参数等，如工业控制、设备调试、数据采集等场景。需在串口打开后调用。

**调用顺序：**
- 必须先调用open()打开串口，才能调用write()发送数据
- 未调用open()就调用write()会抛出错误码35700005（Port not open）

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**参数：**

| 参数名   | 类型         | 必填 | 说明                                                                                                     |
| -------- | ------------ | ---- | -------------------------------------------------------------------------------------------------------- |
| data     | Uint8Array   | 是   | 待发送的数据。长度范围：(0, 4096]。发送超过4096字节的数据时，建议分多次调用write方法发送。                                                                        |
| timeout  | number       | 否   | 超时时间，取值范围：[0, 300000]，整数，单位为毫秒。默认值0表示当数据无法写入串口时，不等待直接返回写入长度0。传入负数、非整数或大于300000时返回错误码35700002。 |

**返回值：**

| 类型                    | 说明                        |
| ----------------------- | --------------------------- |
| Promise&lt;number&gt;   | Promise对象，返回写入数据长度。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 35700001 | Service error.                    |
| 35700002 | Invalid parameter.                |
| 35700003 | Virtual serial port disconnected. |
| 35700005 | Port not open.                    |
| 35700006 | Transmission timeout.             |

**示例：**

<!--code_no_check-->
```ts
// buffer需从@kit.ArkTS导入
// BusinessError需从@kit.BasicServicesKit导入
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 向串口写入数据
let writeData: Uint8Array = new Uint8Array(buffer.from('Hello World', 'utf-8').buffer);
port.write(writeData, 2000).then((size: number) => {
  console.info('write success, size: ' + size);
}).catch((error: BusinessError) => {
  console.error(`Failed to write to serial port. Code: ${error.code}, message: ${error.message}`);
});
```

### onDataRead

onDataRead(callback: Callback&lt;Uint8Array&gt;): void

监听串口接收数据事件。使用callback异步回调，返回接收到的数据。需在串口打开后调用，调用[close](#close)后，所有回调将被清除。用于实时接收串口设备发送的数据，如传感器数据监测、设备状态反馈、实时数据采集等场景。

**配对调用：**
- 与offDataRead()方法配对使用，offDataRead()用于取消监听
- 建议在不需要监听时调用offDataRead()释放监听资源

**调用顺序：**
- 必须先调用open()打开串口，才能调用onDataRead()监听数据
- 未调用open()就调用onDataRead()会抛出错误码35700005（Port not open）

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**参数：**

| 参数名   | 类型                       | 必填 | 说明                             |
| -------- | -------------------------- | ---- | -------------------------------- |
| callback | Callback&lt;Uint8Array&gt; | 是   | 回调函数，返回串口接收到的数据。用于监听串口数据接收事件，注册回调后，串口接收到数据时会触发该回调函数。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 35700001 | Service error.                    |
| 35700003 | Virtual serial port disconnected. |
| 35700005 | Port not open.                    |

**示例：**

<!--code_no_check-->
```ts
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 监听串口数据接收
port.onDataRead((data: Uint8Array) => {
  console.info(`onDataRead, length: ${data.length}`);
});
```

### offDataRead

offDataRead(callback?: Callback&lt;Uint8Array&gt;): void

取消监听串口接收数据事件。使用callback异步回调。用于不再需要监听串口数据接收时释放监听资源，如应用切换到其他功能、主动断开连接后清理监听等场景。

**配对调用：**
- 与onDataRead()方法配对使用，用于取消onDataRead()注册的监听
- 可以取消所有监听，也可以取消指定的监听回调

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                   |
| -------- | -------------------------- | ---- | ------------------------------------------------------ |
| callback | Callback&lt;Uint8Array&gt; | 否   | 回调函数。传入callback时，取消指定的串口数据接收监听；不传入callback时，清除所有串口数据接收监听。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息             |
| -------- | -------------------- |
| 35700001 | Service error.       |
| 35700005 | Port not open.       |

**示例：**

<!--code_no_check-->
```ts
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 取消监听串口数据接收
port.offDataRead();

// 取消指定的监听回调
let callback = (data: Uint8Array) => {
  console.info(`received data length: ${data.length}`);
};
port.offDataRead(callback);
```

### flush

flush(): Promise&lt;void&gt;

清空串口缓冲区，包括读缓冲区和写缓冲区，缓冲区中的数据将被直接丢弃，不再发送或读取。使用Promise异步回调。需在串口打开后调用。用于丢弃缓冲区中无效或过时的数据，如数据传输出错时清空缓冲区重传、切换通信协议时清理旧数据等场景。

**调用顺序：**
- 必须先调用open()打开串口，才能调用flush()清空缓冲区
- 未调用open()就调用flush()会抛出错误码35700005（Port not open）

**与drain的区别：** flush直接丢弃缓冲区中的所有数据，适用于需要快速清空缓冲区或丢弃无效数据的场景；drain等待写缓冲区中的数据正常发送完成，适用于需要确保数据完整传输的场景。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 35700001 | Service error.                    |
| 35700003 | Virtual serial port disconnected. |
| 35700005 | Port not open.                    |

**示例：**

<!--code_no_check-->
```ts
// BusinessError需从@kit.BasicServicesKit导入
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 刷新串口缓冲区
port.flush().then(() => {
  console.info('flush success');
}).catch((error: BusinessError) => {
  console.error(`Failed to flush serial port. Code: ${error.code}, message: ${error.message}`);
});
```

### drain

drain(): Promise&lt;void&gt;

等待所有写请求完成。使用Promise异步回调。需在串口打开后调用。用于确保所有数据写入完成后再进行后续操作，如数据传输完成后关闭串口、发送数据后等待硬件响应等场景。

**调用顺序：**
- 必须先调用open()打开串口，才能调用drain()
- 应在write()之后调用drain()，确保写入数据完全发送
- 建议在close()之前调用drain()，确保所有数据完整传输后再关闭串口
- 未调用open()就调用drain()会抛出错误码35700005（Port not open）

**与flush的区别：** 
- drain等待写缓冲区中的数据正常发送完成，适用于需要确保数据完整传输的场景；flush直接丢弃缓冲区中的所有数据，适用于需要快速清空缓冲区或丢弃无效数据的场景。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 35700001 | Service error.                    |
| 35700003 | Virtual serial port disconnected. |
| 35700005 | Port not open.                    |

**示例：**

<!--code_no_check-->
```ts
// BusinessError需从@kit.BasicServicesKit导入
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 等待所有写请求完成
port.drain().then(() => {
  console.info('drain success');
}).catch((error: BusinessError) => {
  console.error(`Failed to drain serial port. Code: ${error.code}, message: ${error.message}`);
});
```

### setRts

setRts(enable: boolean): Promise&lt;void&gt;

设置RTS（请求发送）信号状态。使用Promise异步回调。需在串口打开后调用。用于控制硬件流控的请求发送信号，如启用RTS/CTS硬件流控时控制发送权、与支持硬件流控的设备通信等场景。

**与setDtr的区别：** setRts和setDtr分别控制RTS/CTS和DTR/DSR两种硬件信号。RTS/CTS主要用于数据流控制，可通过SerialConfigs.rtscts启用自动流控；DTR/DSR主要用于设备状态控制和检测，用于特殊协议或设备状态管理。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**参数：**

| 参数名 | 类型     | 必填 | 说明                                       |
| ------ | -------- | ---- | ------------------------------------------ |
| enable | boolean  | 是   | RTS信号状态，true表示请求发送数据，false表示不请求发送数据。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 35700001 | Service error.                    |
| 35700003 | Virtual serial port disconnected. |
| 35700005 | Port not open.                    |

**示例：**

<!--code_no_check-->
```ts
// BusinessError需从@kit.BasicServicesKit导入
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 设置RTS信号
port.setRts(true).then(() => {
  console.info('setRts success');
}).catch((error: BusinessError) => {
  console.error(`Failed to set RTS. Code: ${error.code}, message: ${error.message}`);
});
```

### getCts

getCts(): Promise&lt;boolean&gt;

获取CTS（清除发送）信号状态。使用Promise异步回调。需在串口打开后调用。用于查询硬件流控的清除发送信号状态，判断是否可以发送数据，如启用RTS/CTS硬件流控时检查发送权、与支持硬件流控的设备通信前检查状态等场景。

**与getDsr的区别：** 
- getCts查询CTS信号（清除发送），属于RTS/CTS硬件流控信号，用于判断是否可以发送数据；getDsr查询DSR信号（数据设备就绪），属于DTR/DSR设备状态信号，用于判断通信设备是否准备就绪。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**返回值：**

| 类型                     | 说明                                             |
| ------------------------ | ------------------------------------------------ |
| Promise&lt;boolean&gt;   | Promise对象，返回CTS信号状态，返回true表示可以发送数据，返回false表示不可以发送数据。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 35700001 | Service error.                    |
| 35700003 | Virtual serial port disconnected. |
| 35700005 | Port not open.                    |

**示例：**

<!--code_no_check-->
```ts
// BusinessError需从@kit.BasicServicesKit导入
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 获取CTS信号状态
port.getCts().then((cts: boolean) => {
  console.info('getCts success, cts: ' + cts);
}).catch((error: BusinessError) => {
  console.error(`Failed to get CTS. Code: ${error.code}, message: ${error.message}`);
});
```

### sendBrk

sendBrk(): Promise&lt;void&gt;

发送BRK（中断）信号。使用Promise异步回调。需在串口打开后调用。用于向设备发送中断信号，如紧急停止设备通信、通知设备复位、特殊协议要求的信号交互等场景。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 35700001 | Service error.                    |
| 35700003 | Virtual serial port disconnected. |
| 35700005 | Port not open.                    |

**示例：**

<!--code_no_check-->
```ts
// BusinessError需从@kit.BasicServicesKit导入
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 发送BRK信号
port.sendBrk().then(() => {
  console.info('sendBrk success');
}).catch((error: BusinessError) => {
  console.error(`Failed to send BRK. Code: ${error.code}, message: ${error.message}`);
});
```

### setDtr

setDtr(enable: boolean): Promise&lt;void&gt;

设置DTR（数据终端就绪）信号状态。使用Promise异步回调。需在串口打开后调用。用于控制数据终端就绪信号，如向设备通知终端准备就绪、通过DTR信号控制设备上电或复位、与需要DTR信号检测的设备通信等场景。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**参数：**

| 参数名 | 类型     | 必填 | 说明                                       |
| ------ | -------- | ---- | ------------------------------------------ |
| enable | boolean  | 是   | DTR信号状态，true表示数据终端就绪；false表示数据终端未就绪。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 35700001 | Service error.                    |
| 35700003 | Virtual serial port disconnected. |
| 35700005 | Port not open.                    |

**示例：**

<!--code_no_check-->
```ts
// BusinessError需从@kit.BasicServicesKit导入
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 设置DTR信号
port.setDtr(true).then(() => {
  console.info('setDtr success');
}).catch((error: BusinessError) => {
  console.error(`Failed to set DTR. Code: ${error.code}, message: ${error.message}`);
});
```

### getDsr

getDsr(): Promise&lt;boolean&gt;

获取DSR（数据设备就绪）信号状态。使用Promise异步回调。需在串口打开后调用。用于查询数据设备就绪信号状态，判断通信设备是否准备就绪，如检查设备连接状态、在设备准备就绪后开始通信等场景。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**返回值：**

| 类型                     | 说明                                             |
| ------------------------ | ------------------------------------------------ |
| Promise&lt;boolean&gt;   | Promise对象，返回DSR信号状态；true表示数据设备就绪；false表示数据设备未就绪。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 35700001 | Service error.                    |
| 35700003 | Virtual serial port disconnected. |
| 35700005 | Port not open.                    |

**示例：**

<!--code_no_check-->
```ts
// BusinessError需从@kit.BasicServicesKit导入
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 获取DSR信号状态
port.getDsr().then((dsr: boolean) => {
  console.info('getDsr success, dsr: ' + dsr);
}).catch((error: BusinessError) => {
  console.error(`Failed to get DSR. Code: ${error.code}, message: ${error.message}`);
});
```

### onDisconnect

onDisconnect(callback: Callback&lt;void&gt;): void

监听串口断开事件。使用callback异步回调。调用close后，所有回调将被清除。用于监听串口连接断开事件，如USB虚拟串口拔出、设备断电、连接中断时及时处理异常状态、提示用户或尝试重连等场景。

**配对调用：**
- 与offDisconnect()方法配对使用，offDisconnect()用于取消监听
- 建议在不需要监听时调用offDisconnect()释放监听资源

**调用顺序：**
- 必须先调用open()打开串口，才能调用onDisconnect()监听断开事件
- 未调用open()就调用onDisconnect()会抛出错误码35700005（Port not open）

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

**参数：**

| 参数名   | 类型                  | 必填 | 说明                             |
| -------- | --------------------- | ---- | -------------------------------- |
| callback | Callback&lt;void&gt;  | 是   | 回调函数，串口断开时触发。用于监听串口断开事件，注册回调后，串口设备断开连接时会触发该回调函数。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息             |
| -------- | -------------------- |
| 35700001 | Service error.       |
| 35700005 | Port not open.       |

**示例：**

<!--code_no_check-->
```ts
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 监听串口断开事件
port.onDisconnect(() => {
  console.info('serial port disconnected');
});
```

### offDisconnect

offDisconnect(callback?: Callback&lt;void&gt;): void

取消监听串口断开事件。需在串口打开后调用。用于不再需要监听串口断开事件时释放监听资源，如应用切换到其他功能、主动断开连接后清理监听等场景。

**调用顺序：**
- 必须先调用open()打开串口，才能调用offDisconnect()取消监听
- 未调用open()就调用offDisconnect()会抛出错误码35700005（Port not open）

**配对调用：**
- 与onDisconnect()方法配对使用，用于取消onDisconnect()注册的监听
- 可以取消所有监听，也可以取消指定的监听回调

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.BusManager.Serial

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                   |
| -------- | --------------------- | ---- | ------------------------------------------------------ |
| callback | Callback&lt;void&gt;  | 否   | 回调函数，需先通过onDisconnect()注册回调后才能取消。传入callback时，取消指定的串口断开事件监听；不传入callback时，清除所有串口断开事件监听。 |

**错误码：**

以下错误码的详细介绍参见[串口管理错误码](errorcode-busmanager-serial.md)。

| 错误码ID | 错误信息             |
| -------- | -------------------- |
| 35700001 | Service error.       |
| 35700005 | Port not open.       |

**示例：**

<!--code_no_check-->
```ts
// port为串口对象，需要先通过serial.getSerialPortList()获取
// 取消监听串口断开事件
port.offDisconnect();

// 取消指定的监听回调
let disconnectedCallback = () => {
  console.info('serial port disconnected');
};
port.offDisconnect(disconnectedCallback);
```

## SerialPortInfo

串口设备信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

| 名称          | 类型     | 只读 | 可选 | 说明                        |
| ------------- | -------- | ---- | ---- | --------------------------- |
| portName      | string   | 否   | 否   | 端口名称。                  |
| vendorId      | number   | 否   | 是   | USB虚拟串口的厂商ID。       |
| productId     | number   | 否   | 是   | USB虚拟串口设备的产品ID。   |
| manufacturer  | string   | 否   | 是   | USB虚拟串口设备的制造商名称。 |

## DataBits

表示数据位的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

| 名称   | 值 | 说明              |
| ------ | -- | ----------------- |
| FIVE   | 5  | 5个数据位。       |
| SIX    | 6  | 6个数据位。       |
| SEVEN  | 7  | 7个数据位。       |
| EIGHT  | 8  | 8个数据位。       |

## StopBits

表示停止位的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

| 名称 | 值 | 说明              |
| ---- | -- | ----------------- |
| ONE  | 1  | 1个停止位。       |
| TWO  | 2  | 2个停止位。       |

## Parity

表示校验位的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

| 名称  | 值       | 说明                    |
| ----- | -------- | ----------------------- |
| NONE  | 'none'   | 无校验。                |
| EVEN  | 'even'   | 偶校验。                |
| ODD   | 'odd'    | 奇校验。                |
| MARK  | 'mark'   | 标记校验，校验位始终为1。 |
| SPACE | 'space'  | 空格校验，校验位始终为0。 |

## SerialConfigs

串口通信配置参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.BusManager.Serial

| 名称     | 类型                     | 只读 | 可选 | 说明                                                                  |
| -------- | ------------------------ | ---- | ---- | --------------------------------------------------------------------- |
| baudRate | number                   | 否   | 是   | 波特率。值为正整数，非标准波特率的具体支持情况依赖于硬件。单位：bit/s。默认值：115200。       |
| dataBits | [DataBits](#databits) | 否 | 是   | 数据位。默认值：EIGHT（8数据位，标准通信）。FIVE/SIX/SEVEN用于老旧设备或特殊协议。 |
| stopBits | [StopBits](#stopbits)    | 否   | 是   | 停止位。默认值：ONE。1个停止位用于标准通信场景；2个停止位用于低速通信或与老旧设备通信时增加信号稳定性。 |
| parity | [Parity](#parity) | 否 | 是   | 校验位。默认值：NONE（无校验）。EVEN/ODD用于数据准确性要求高的场景；MARK/SPACE用于特殊通信协议。 |
| rtscts   | boolean                  | 否   | 是   | 是否启用RTS/CTS硬件自动流控。RTS/CTS硬件流控是一种通过硬件信号实现的自动数据流控制机制，RTS和CTS信号线协同工作以防止缓冲区溢出。启用后，系统会自动控制RTS和CTS信号来管理数据流量。默认值：false。true表示启用，false表示未启用。                                   |
| xon      | boolean                  | 否   | 是   | 是否启用XON（Xmitter On，传输继续控制字符）控制发送流。XON是软件流控协议中的一个控制字符（ASCII值为17），当接收端缓冲区有空间时发送XON字符通知发送端恢复发送数据。默认值：false。true表示启用，false表示未启用。                                  |
| xoff     | boolean                  | 否   | 是   | 是否启用XOFF（Xmitter Off，传输停止控制字符）控制发送流。XOFF是软件流控协议中的一个控制字符（ASCII值为19），当接收端缓冲区即将溢出时发送XOFF字符通知发送端暂停发送数据。默认值：false。true表示启用，false表示未启用。                                 |
| xany     | boolean                  | 否   | 是   | 是否启用XANY（Any Character Resume，任意字符恢复模式）控制流。XANY是软件流控协议中的一种扩展模式，需在xon或xoff启用时才能生效。当启用XANY时，任何字符都可以作为恢复发送的信号，而不仅仅是XON字符；若未启用软件流控（xon/xoff），xany设置无效。默认值：false。true表示启用，false表示未启用。                                     |
