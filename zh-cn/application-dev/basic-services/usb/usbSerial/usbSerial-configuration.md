# USB串口配置管理

## 场景介绍

波特率、数据位、校验位和停止位是串口通信协议的核心参数，它们共同定义了数据传输的格式和规则。通过合理配置这些参数，可以显著提升串口通信的可靠性和效率。

### 基本概念

在进行USB串口开发时，开发者应了解以下基本概念：

- 波特率（Baud Rate）

  - 定义：每秒传输的符号数（包括数据位、起始位、停止位、校验位），单位为Baud（波特）。
  
  - 作用：决定通信速度。例如9600 Baud表示每秒传输9600个符号。

  - 关键点：收发双方必须使用相同的波特率，否则数据无法正确解析。


- 数据位（Data Bit）

  - 定义：每个数据包中实际传输的有效数据位数，可选5、6、7、8位。

  - 作用：决定单次传输的信息量。

  - 关键点：数据位越多，单次传输信息量越大，但需更多时间同步。


- 校验位（Parity Bit）

  - 定义：用于检测数据传输错误的单比特标记，可选无校验（None）、奇校验（Odd）、偶校验（Even）、标记位（Mark）、空格位（Space）。

  - 作用：通过校验位使整个数据包（数据位 + 校验位）的1的个数为奇数（奇校验）或偶数（偶校验）。简单检测传输过程中单个比特位的翻转（如线路噪声导致的数据位错误）。
    
  - 关键点：增加校验位会略微降低传输效率，但能提高容错性。


- 停止位（Stop Bit）

  - 定义：标志数据包结束的固定逻辑电平（通常为1），可选1、1.5、2位。

  - 作用：为接收端提供时钟同步时间窗口，补偿时钟偏差。更多停止位（如2位）可提高抗干扰能力，但会降低传输效率。

  - 关键点： 默认选择1位停止位，兼顾效率与可靠性。工业控制或噪声严重场景可选2位停止位。

## 环境准备

### 环境要求

- 开发工具及配置：

  DevEco Studio作为开发工具，是进行开发必备条件之一，开发者可以使用该工具进行开发、调试、打包等操作。请[下载安装](https://developer.huawei.com/consumer/cn/download/)该工具，并参考[DevEco Studio使用指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V14/ide-tools-overview-V14)中的[创建工程及运行](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V14/ide-create-new-project-V14)进行基本的操作验证，保证DevEco Studio可正常运行。

- SDK版本配置：

  本模块提供的ArkTs接口，所需SDK版本为API16及以上才可使用。

### 搭建环境

- 在PC上安装[DevEco Studio](https://developer.huawei.com/consumer/cn/download/deveco-studio)，要求版本在4.1及以上。
- 将public-SDK更新到API 16或以上，更新SDK的具体操作可参见[更新指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/faqs/full-sdk-switch-guide.md)。
- USB线缆一端连接到OpenHarmony设备，另一端连接到标准串口设备。

## 开发指导

### 接口说明

| 接口名                                                                          | 描述                        |
|------------------------------------------------------------------------------|---------------------------|
| getAttribute(portId: number): Readonly&lt;SerialAttribute&gt;                      | 获取串口设备配置                |
| setAttribute(portId: number, attribute: SerialAttribute): void               | 设置串口设备配置                |

### 开发步骤

开发者可以通过上述接口获取和设置串口的配置：

1. 导入模块。

    ```ts
    // 导入usbManager模块。
    import serial from '@ohos.usbManager.serial';
    ``` 

2. 获取设备列表。

    ```ts
    // 获取连接主设备的USB设备列表
    let portList: serial.SerialPort[] = serial.getPortList();
    console.info('usbSerial portList: ' + JSON.stringify(portList));
    if (portList === undefined || portList.length === 0) {
      console.info('usbSerial portList is empty');
      return;
    }
    ```

3. 获取设备操作权限。

    ```ts
    // 此处对列表中的第一台USB设备判断是否拥有访问权限
    let portId: number = portList[0].portId;
    if (!serial.hasSerialRight(portId)) {
      await serial.requestSerialRight(portId).then(result => {
        if(!result) {
          // 没有访问设备的权限且用户不授权则退出
          console.info('usbSerial user is not granted the operation permission');
          return;
        }
      });
    }
    ```

4. 根据串口打开设备。

    ```ts
    try {
      serial.open(portId)
      console.info('open usbSerial success, portId: ' + portId);
    } catch (error) {
      console.error('open usbSerial error, ' + JSON.stringify(error));
    }
    ```

5. 获取和修改串口配置。

    ```ts
    // 获取串口配置
    try {
      let attribute: serial.SerialAttribute = serial.getAttribute(portId);
      if (attribute === undefined) {
        console.error('getAttribute usbSerial error, attribute is undefined');
      } else {
        console.info('getAttribute usbSerial success, attribute: ' + JSON.stringify(attribute));
      }
    } catch (error) {
      console.error('getAttribute usbSerial error, ' + JSON.stringify(error));
    }
   
    // 设置串口配置
    try {
      let attribute: serial.SerialAttribute = {
        baudRate: serial.BaudRates.BAUDRATE_9600,
        dataBits: serial.DataBits.DATABIT_8,
        parity: serial.Parity.PARITY_NONE,
        stopBits: serial.StopBits.STOPBIT_1
      }
      serial.setAttribute(portId, attribute);
      console.info('setAttribute usbSerial success, attribute: ' + JSON.stringify(attribute));
    } catch (error) {
      console.error('setAttribute usbSerial error, ' + JSON.stringify(error));
    }
    ```

### 调测验证

1. USB线缆一端连接到OpenHarmony设备，另一端连接到标准串口设备。
2. 执行上述代码。
3. log中搜索关键字`usbSerial success, attribute`，可以查看当前串口的配置。

## 常见问题

设备双方（如嵌入式模块与上位机）必须配置完全相同的参数，否则会导致通信失败（如乱码或无响应）。

| 现象    | 	可能原因	      | 解决方案                |
|-------|-------------|---------------------|
| 数据乱码  | 波特率不匹配      | 确认双方波特率一致           |
| 通信失败  | 校验位或停止位配置错误 | 检查参数是否与设备要求完全一致     |
| 偶发丢包  | 噪声干扰或停止位不足  | 增加停止位（如从 1 位改为 2 位） |