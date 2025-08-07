# 连接和传输数据

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--SE: @chengguohong; @tangjia15-->
<!--TSE: @wangfeng517-->

## 简介
本指南主要提供了基于串口通信协议（Serial Port Profile，SPP）实现设备间连接和传输数据的开发指导。当两个设备间进行SPP通信交互时，依据设备功能的不同，可区分为客户端与服务端，本指南将分别介绍客户端与服务端的实现方法。

## 实现原理
客户端获取到服务端的设备地址后，即可向服务端特定的UUID发起连接。服务端设备地址可以通过查找设备流程获取，详见[查找设备](br-discovery-development-guide.md)。待两端连接成功后，可向服务端发送数据或者接收服务端的数据。

服务端需要支持客户端连接的UUID服务，保持连接状态监听即可。待两端连接成功后，即可接收客户端数据或者向客户端发送数据。

客户端和服务端都可以主动断开连接，应用需要根据实际场景决定由哪一端执行断开操作。

## 开发步骤

### 申请蓝牙权限
需要申请权限ohos.permission.ACCESS_BLUETOOTH。如何配置和申请权限，请参考[声明权限](../../security/AccessToken/declare-permissions.md)和[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

### 导入所需API模块
导入socket和错误码模块。
```ts
import { socket } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

### 客户端

**1. 发起连接**<br>
客户端通过查找设备流程搜索到目标设备后，即可发起连接。需要连接的UUID服务，必须与服务端创建socket时构造的UUID服务一致。在连接过程中，蓝牙子系统会去查询服务端是否支持该UUID服务，若不支持，则会连接失败。因此应用需要确保目标设备是否支持需要的UUID服务，否则发起的是无效连接。
```ts
// 设备地址可以通过查找设备流程获取
let peerDevice = 'XX:XX:XX:XX:XX:XX';

// 定义客户端socket id
let clientNumber = -1;

// 配置连接参数
let option: socket.SppOptions = {
  uuid: '00009999-0000-1000-8000-00805F9B34FB', // 需要连接的服务端UUID服务，确保服务端支持
  secure: false,
  type: socket.SppType.SPP_RFCOMM
};
console.info('startConnect ' + peerDevice);
socket.sppConnect(peerDevice, option, (err, num: number) => {
  if (err) {
    console.error('startConnect errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  } else {
    console.info('startConnect clientNumber: ' + num);
    clientNumber = num;
  }
});
console.info('startConnect after ' + peerDevice);
```

**2. 传输数据**<br>

**2.1 发送数据**<br>
待客户端和服务端建立的连接建立成功后，即可向服务端发送数据。
```ts
let clientNumber = 1; // 注意：该值需要的是客户端发起连接时，异步callback获取到的客户端socket id，此处是伪代码id
let arrayBuffer = new ArrayBuffer(2);
let data = new Uint8Array(arrayBuffer);
data[0] = 3;
data[1] = 4;
try {
  socket.sppWrite(clientNumber, arrayBuffer);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**2.2 接收数据**<br>
待客户端和服务端建立的连接建立成功后，即可接收服务端的数据。通过订阅读取数据接口[socket.on('sppRead')](../../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md#socketonsppread)实现。
```ts
let clientNumber = 1; // 注意：该值需要的是客户端发起连接时，异步callback获取到的客户端socket id，此处是伪代码id

// 定义接收数据的回调函数
function read(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.info('client data: ' + JSON.stringify(data));
}

try {
  // 发起订阅
  socket.on('sppRead', clientNumber, read);
} catch (err) {
  console.error('readData errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**3. 断开连接**<br>
当应用不再需要已建立的连接时，可以通过客户端主动断开连接。需要先取消读取数据的订阅，再断开连接。
```ts
let clientNumber = 1; // 注意：该值需要的是客户端发起连接时，异步callback获取到的客户端socket id，此处是伪代码id

// 定义接收数据的回调函数
function read(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.info('client data: ' + JSON.stringify(data));
}

try {
  // 取消接收数据订阅
  socket.off('sppRead', clientNumber, read);
} catch (err) {
  console.error('off sppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
try {
  // 从client端断开连接
  socket.sppCloseClientSocket(clientNumber);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### 服务端

**1. 创建服务端套接字**<br>
服务端需通过创建套接字的方式，在蓝牙子系统中注册指定的UUID服务。该UUID服务的名称无限制，可使用应用名称。当客户端发起连接请求时，会携带一个UUID以表示所需连接的服务。只有服务端与客户端的UUID一致时，连接才能成功建立。
```ts
// 定义服务端socket id
let serverNumber = -1;

// 配置监听参数
let option: socket.SppOptions = {
  uuid: '00009999-0000-1000-8000-00805F9B34FB',
  secure: false,
  type: socket.SppType.SPP_RFCOMM
};

// 创建服务端监听socket，将在蓝牙子系统中注册该UUID服务
socket.sppListen("demonstration", option, (err, num: number) => {
  if (err) {
    console.error('sppListen errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  } else {
    console.info('sppListen serverNumber: ' + num);
    serverNumber = num;
  }
});
```

**2. 监听客户端连接**<br>
创建好服务端套接字后，服务端即可监听连接。待收到客户端连接后，会获取到标识此次客户端的socket id，此时也表示服务端和客户端的连接已建立成功。
```ts
let serverNumber = 1; // 注意：该值需要的是创建服务端套接字时，异步callback获取到的服务端socket id，此处是伪代码id

// 定义客户端socket id
let clientNumber = -1;

socket.sppAccept(serverNumber, (err, num: number) => {
  if (err) {
    console.error('accept errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  } else {
    console.info('accept clientNumber: ' + num);
    clientNumber = num;
  }
});
```

**3. 传输数据**<br>

**3.1 发送数据**<br>
待服务端和客户端的连接建立成功后，即可向客户端发送数据。
```ts
let clientNumber = 1; // 注意：该值需要的是服务端监听连接时，异步callback获取到的客户端socket id，此处是伪代码id

let arrayBuffer = new ArrayBuffer(2);
let data = new Uint8Array(arrayBuffer);
data[0] = 9;
data[1] = 8;
try {
  socket.sppWrite(clientNumber, arrayBuffer);
} catch (err) {
  console.error('sppWrite errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**3.2 接收数据**<br>
待服务端和客户端的连接建立成功后，即可接收客户端的数据。通过订阅读取数据接口[socket.on('sppRead')](../../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md#socketonsppread)实现。
```ts
let clientNumber = 1; // 注意：该值需要的是服务端监听连接时，异步callback获取到的客户端socket id，此处是伪代码id

// 定义接收数据的回调函数
function read(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.info('client data: ' + JSON.stringify(data));
}

try {
  // 发起订阅
  socket.on('sppRead', clientNumber, read);
} catch (err) {
  console.error('readData errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
**4. 断开连接**<br>
当应用不再需要已建立的连接时，可以通过服务端主动断开连接。

- 需要先取消读取数据的订阅，再断开连接。
```ts
let clientNumber = 1; // 注意：该值需要的是服务端监听连接时，异步callback获取到的客户端socket id，此处是伪代码id

// 定义接收数据的回调函数
function read(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.info('client data: ' + JSON.stringify(data));
}

try {
  // 取消订阅
  socket.off('sppRead', clientNumber, read);
} catch (err) {
  console.error('off sppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
try {
  // 从server断开连接
  socket.sppCloseClientSocket(clientNumber);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**5. 删除服务端套接字**<br>
当应用不再需要该服务端套接字时，需要主动关闭创建时获取到的套接字，蓝牙子系统会删除此前注册的UUID服务。如果此时客户端发起连接，就会连接失败。

- 应用也可以通过删除套接字时，实现断开连接。在此之前，需要先取消读取数据的订阅。
```ts
let clientNumber = 1; // 注意：该值需要的是服务端监听连接时，异步callback获取到的客户端socket id，此处是伪代码id
let serverNumber = 1; // 注意：该值需要的是创建服务端套接字时，异步callback获取到的服务端socket id，此处是伪代码id

// 定义接收数据的回调函数
function read(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.info('client data: ' + JSON.stringify(data));
}

try {
  // 取消订阅
  socket.off('sppRead', clientNumber, read);
} catch (err) {
  console.error('off sppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

try {
  // 若应用不再需要此能力，则主动删除
  socket.sppCloseServerSocket(serverNumber);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## 完整示例

### 客户端
```ts
import { socket } from '@kit.ConnectivityKit'
import { BusinessError } from '@kit.BasicServicesKit';

class SppClientManager {
  // 定义客户端的socket id
  clientNumber: number = -1;

  // 发起连接
  public startConnect(peerDevice: string): void {
    // 配置连接参数
    let option: socket.SppOptions = {
      uuid: '00009999-0000-1000-8000-00805F9B34FB', // 需要连接的服务端UUID服务，确保服务端支持
      secure: false,
      type: socket.SppType.SPP_RFCOMM
    };
    console.info('startConnect ' + peerDevice);
    socket.sppConnect(peerDevice, option, (err, num: number) => {
      if (err) {
        console.error('startConnect errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      } else {
        console.info('startConnect clientNumber: ' + num);
        this.clientNumber = num;
      }
    });
    console.info('startConnect after ' + peerDevice);
  }

  // 发送数据
  public sendData() {
    console.info('sendData ' + this.clientNumber);
    let arrayBuffer = new ArrayBuffer(2);
    let data = new Uint8Array(arrayBuffer);
    data[0] = 3;
    data[1] = 4;
    try {
      socket.sppWrite(this.clientNumber, arrayBuffer);
    } catch (err) {
      console.error('sppWrite errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 定义接收数据的回调函数
  read = (dataBuffer: ArrayBuffer) => {
    let data = new Uint8Array(dataBuffer);
    console.info('client data: ' + JSON.stringify(data));
  };

  // 接收数据
  public readData() {
    try {
      // 发起订阅
      socket.on('sppRead', this.clientNumber, this.read);
    } catch (err) {
      console.error('readData errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 断开连接
  public stopConnect() {
    console.info('closeSppClient ' + this.clientNumber);
    try {
      // 取消接收数据订阅
      socket.off('sppRead', this.clientNumber, this.read);
    } catch (err) {
      console.error('off sppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
    try {
      // 从client端断开连接
      socket.sppCloseClientSocket(this.clientNumber);
    } catch (err) {
      console.error('stopConnect errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let sppClientManager = new SppClientManager();
export default sppClientManager as SppClientManager;
```

### 服务端
```ts
import { socket } from '@kit.ConnectivityKit'
import { BusinessError } from '@kit.BasicServicesKit';

class SppServerManager {
  serverNumber: number = -1;
  clientNumber: number = -1;

  // 创建服务端监听socket
  public startListen(): void {
    console.info('startListen');

    // 配置监听参数
    let option: socket.SppOptions = {
      uuid: '00009999-0000-1000-8000-00805F9B34FB',
      secure: false,
      type: socket.SppType.SPP_RFCOMM
    };

    // 创建服务端监听socket，将在蓝牙子系统中注册该UUID服务
    socket.sppListen("demonstration", option, (err, num: number) => {
      if (err) {
        console.error('sppListen errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      } else {
        console.info('sppListen serverNumber: ' + num);
        this.serverNumber = num;
      }
    });
  }

  // 监听连接请求，等待连接
  public accept() {
    console.info('accept ' + this.serverNumber);
    socket.sppAccept(this.serverNumber, (err, num: number) => {
      if (err) {
        console.error('accept errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      } else {
        console.info('accept clientNumber: ' + num);
        this.clientNumber = num;
      }
    });
  }

  // 发送数据
  public sendData() {
    console.info('sendData serverNumber: ' + this.serverNumber + ' clientNumber: ' + this.clientNumber);
    let arrayBuffer = new ArrayBuffer(2);
    let data = new Uint8Array(arrayBuffer);
    data[0] = 9;
    data[1] = 8;
    try {
      socket.sppWrite(this.clientNumber, arrayBuffer);
    } catch (err) {
      console.error('sppWrite errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 定义接收数据的回调函数
  read = (dataBuffer: ArrayBuffer) => {
    let data = new Uint8Array(dataBuffer);
    console.info('client data: ' + JSON.stringify(data));
  };

  // 接收数据
  public readData() {
    try {
      // 发起订阅
      socket.on('sppRead', this.clientNumber, this.read);
    } catch (err) {
      console.error('readData errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 停止连接
  public stopConnect() {
    console.info('stopConnect');
    try {
      // 取消订阅
      socket.off('sppRead', this.clientNumber, this.read);
    } catch (err) {
      console.error('off sppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
    try {
      // 从server断开连接
      socket.sppCloseClientSocket(this.clientNumber);
    } catch (err) {
      console.error('stopConnect errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 删除能力
  public closeSppServer() {
    console.info('closeSppServer');
    try {
      // 若应用不再需要此能力，则主动删除
      socket.sppCloseServerSocket(this.serverNumber);
    } catch (err) {
      console.error('sppCloseServerSocket errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let sppServerManager = new SppServerManager();
export default sppServerManager as SppServerManager;
```