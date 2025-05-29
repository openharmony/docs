# USB串口配置管理

## 简介

USB串口配置管理中，波特率、数据位、校验位和停止位是串口通信协议的核心参数，它们共同定义了数据传输的格式和规则。通过合理配置这些参数，可以显著提升串口通信的可靠性和效率。

### 基本概念

在进行USB串口开发时，开发者应了解以下基本概念：

- 波特率（Baud Rate）

  波特率表示串口设备每秒传输的符号数（符号即二进制位，包括数据位、起始位、停止位、校验位），单位为Baud（波特），例如9600 Baud表示每秒传输9600个符号。收发双方必须使用相同的波特率，否则数据无法正确解析。


- 数据位（Data Bit）

  数据位表示每个数据包中实际传输的有效二进制位数，决定了单个字符的数据容量。常见的取值包括5位、6位、7位和8位。数据位决定单次传输的信息量，数据位越多，单次传输信息量越大，但需更多时间同步。


- 校验位（Parity Bit）

  校验位是附加在数据帧中的1位二进制值，根据数据位的内容按特定规则生成。常见的有，奇校验（Odd）数据位+校验位中“1”的总数为奇数，偶校验（Even）数据位+校验位中“1”的总数为偶数，无校验（None）不添加校验位。校验位通过验证数据位中“1”的数量，判断数据在传输过程中是否发生位翻转、噪声干扰等错误，增加校验位会略微降低传输效率，但能提高容错性。


- 停止位（Stop Bit）

  停止位位于数据帧末尾，是逻辑高电平信号，用于标识一个字符（数据包）传输的结束。典型长度有1位和2位（实际开发中1位最常用，2位多用于抗干扰场景）。其核心作用是为接收端提供时序同步容错空间，并确保数据完整性。


## 环境准备

请参考USB串口通信服务开发概述[环境准备](usbSerial-overview.md#环境准备)。

## 开发指导

### 接口说明

| 接口名                                                                          | 描述        |
|------------------------------------------------------------------------------|-----------|
| getAttribute(portId: number): Readonly&lt;SerialAttribute&gt;                      | 获取串口设备配置。 |
| setAttribute(portId: number, attribute: SerialAttribute): void               | 设置串口设备配置。 |

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

1. 准备一根USB转串口线缆，线缆的USB接口连接到OpenHarmony设备USB端口（该端口需支持USB转串口），线缆的串口接口连接到目标设备的串口上。
2. 在OpenHarmony设备上执行上述示例。
3. 返回`getAttribute usbSerial success`和`setAttribute usbSerial success`表示相关接口调用成功，可以查看当前串口的配置。
