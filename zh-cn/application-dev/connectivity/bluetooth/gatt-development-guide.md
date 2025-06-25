# 连接和传输数据

## 简介
本指南主要提供了基于通用属性协议（Generic Attribute Profile，GATT）实现BLE设备间连接和传输数据的开发指导。当两个设备间进行GATT通信交互时，依据设备功能的不同，可区分为GATT客户端和GATT服务端，本指南将分别介绍客户端与服务端的实现方法。

GATT是低功耗蓝牙（BLE）的核心协议，定义了基于服务（Service）、特征值（Characteristic）和描述符（Descriptor）进行蓝牙通信和传输数据的机制。相关术语介绍请参考[Connectivity Kit术语](../terminology.md)。

## 实现原理
客户端获取到服务端的设备地址后，即可向服务端发起连接。服务端设备地址可以通过BLE扫描流程获取。待两端连接成功后，即可向服务端发起服务查询、读写特征值和接收通知等操作，从而实现向服务端发送数据或者接收服务端数据的功能。

服务端需要发送BLE广播才能被客户端发现。服务端需要支持客户端需要连接的服务，等待客户端的连接请求即可。待两端连接成功后，即可接收客户端的读写特征值和发送通知等操作，从而实现接收客户端数据或者向客户端发送数据的功能。

客户端的BLE扫描和服务端的BLE广播流程，请参考[查找设备](ble-development-guide.md)。

## 开发步骤

### 申请蓝牙权限
需要申请权限ohos.permission.ACCESS_BLUETOOTH。如何配置和申请权限，请参考[声明权限](../../security/AccessToken/declare-permissions.md)和[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

### 导入所需API模块
导入ble、constant和错误码模块。
```ts
import { ble, constant } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```
### 客户端

#### 1. 创建客户端实例
客户端通过查找设备流程搜索到目标设备后，即可构造客户端实例，后续所有操作都基于该客户端实例。
```ts
// 此处是伪代码
let device = 'XX:XX:XX:XX:XX:XX';

try {
  let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 2. 订阅连接状态变化事件
通过订阅连接状态变化事件，可以获取实时的GATT连接状态。整个连接过程会涉及多种状态的跃迁，其中[STATE_CONNECTED](../../reference/apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate)表示已连接，[STATE_DISCONNECTED](../../reference/apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate)表示已断连。
```ts
// 此处是伪代码
let device = 'XX:XX:XX:XX:XX:XX';

function clientConnectStateChanged(state: ble.BLEConnectionChangeState) {
  console.info('bluetooth connect state changed');
  let connectState: ble.ProfileConnectionState = state.state;
}

try {
  let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);
  gattClient.on('BLEConnectionStateChange', clientConnectStateChanged);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 3. 发起连接
通过创建的客户端实例，直接发起连接即可。通过连接状态变化事件判断是否已连接成功。
```ts
// 此处是伪代码
let device = 'XX:XX:XX:XX:XX:XX';

try {
    let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);
    gattClient.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 4. 服务发现
服务发现是获取服务端支持的所有服务能力集合的过程。客户端需要根据服务发现结果，判断服务端是否存在应用需要的服务能力。
- 后续的读写特征值、读写描述符等操作都需要在服务发现操作完成后进行，否则会失败。
- 后续的读写等操作中指定的特征值或描述符必须包含在服务能力集合中，否则会失败。
```ts
// 此处是伪代码
let device = 'XX:XX:XX:XX:XX:XX';

try {
  let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);
  // 此处是伪代码，需要连接上后，才可以调用
  gattClient.getServices().then((result: Array<ble.GattService>) => {
    console.info('getServices successfully:' + JSON.stringify(result));
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 5 传输数据
传输数据通过操作服务端的特征值或者描述符实现。

**5.1 读取或写入特征值**<br>
读取特征值操作，可以获取服务端特征值的数据内容。<br>
写入特征值操作，可以更新服务端特征值的数据内容。<br>
相关API请参考[readCharacteristicValue](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#readcharacteristicvalue)和[writeCharacteristicValue](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#writecharacteristicvalue)。
```ts
// 此处是伪代码
let device = 'XX:XX:XX:XX:XX:XX';
let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00008888-0000-1000-8000-00805F9B34FB',
  descriptorValue: bufferDesc
};
descriptors[0] = descriptor;
let bufferCCC = new ArrayBuffer(2);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: bufferCCC,
  descriptors:descriptors
};

let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);

// 读取特征值
try {
  gattClient.readCharacteristicValue(characteristic).then((outData: ble.BLECharacteristic) => {
  });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// 写入特征值
try {
  gattClient.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE, (err) => {
    if (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      return;
    }
    console.info(TAG, 'writeCharacteristicValue success');
  });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**5.2 读取或写入描述符**<br>
读取描述符操作，可以获取服务端描述符的数据内容。<br>
写入描述符操作，可以更新服务端描述符的数据内容。<br>
相关API请参考[readDescriptorValue](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#readdescriptorvalue)和[writeDescriptorValue](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#writedescriptorvalue)。
```ts
// 此处是伪代码
let device = 'XX:XX:XX:XX:XX:XX';
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00008888-0000-1000-8000-00805F9B34FB',
  descriptorValue: bufferDesc
};
let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);

// 读取描述符
try {
  gattClient.readDescriptorValue(descriptor).then((outData: ble.BLEDescriptor) => {
  });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// 写入描述符
try {
  gattClient.writeDescriptorValue(descriptor, (err) => {
    if (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      return;
    }
  });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**5.3 接收服务端特征值变化通知或指示**<br>
当服务端特征值的数据内容发生变化时，客户端可以通过接收服务端的特征值变化通知或者指示来实现更新数据。该服务端特征值需包含蓝牙标准协议定义的Client Characteristic Configuration描述符UUID（00002902-0000-1000-8000-00805f9b34fb），才能支持通知或者指示能力。

客户端收到服务端通知时，不需要回复确认；客户端收到服务端指示时，需要回复确认，蓝牙子系统会实现该操作，应用无需关注。

- 先订阅服务端特征值变化事件，详情请见[on('BLECharacteristicChange')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#onblecharacteristicchange)。
- 再使能服务端特征值变化通知或者指示能力，应用根据实际场景选择一种方式即可。相关API请参考[setCharacteristicChangeNotification](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#setcharacteristicchangeindication)。
```ts
// 此处是伪代码
let device = 'XX:XX:XX:XX:XX:XX';

// 定义服务端特征值变化事件
function characteristicChange(characteristicChangeReq: ble.BLECharacteristic) {
  let serviceUuid: string = characteristicChangeReq.serviceUuid;
  let characteristicUuid: string = characteristicChangeReq.characteristicUuid;
  let value: Uint8Array = new Uint8Array(characteristicChangeReq.characteristicValue);
}

let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
  descriptorValue: arrayBuffer
};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(2);
let characteristic: ble.BLECharacteristic = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: arrayBufferC,
  descriptors:descriptors
};

let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);

// 发起订阅
try {
    gattClient.on('BLECharacteristicChange', characteristicChange);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// 通知和指示，2选1即可
// 设置特征值变化通知能力
try {
  // enable入参: true表示启用，false表示禁用
  gattClient.setCharacteristicChangeNotification(characteristic, true, (err: BusinessError) => {
    if (err) {
      console.info('setCharacteristicChangeNotification callback failed');
    } else {
      console.info('setCharacteristicChangeNotification callback successful');
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// 设置特征值变化指示能力
try {
  // enable入参: true表示启用，false表示禁用
  gattClient.setCharacteristicChangeIndication(characteristic, true, (err: BusinessError) => {
    if (err) {
      console.info('setCharacteristicChangeIndication callback failed');
    } else {
      console.info('setCharacteristicChangeIndication callback successful');
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 6. 断开连接
当应用不再需要已建立的连接时，需主动断开连接。
```ts
// 此处是伪代码
let device = 'XX:XX:XX:XX:XX:XX';

let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);
try {
  // 发起断连
  gattClient.disconnect();

  // 如果应用不再使用此gattClient，则需要close，gattClient实例将不能再使用
  gattClient.close() 
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### 服务端

#### 1. 创建服务端实例
构造服务端实例，后续所有操作都基于该服务端实例。
```ts
try {
  let gattServer: ble.GattServer = ble.createGattServer();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 2. 添加服务
添加应用需要的服务，将在蓝牙子系统中注册指定的UUID服务。客户端会发起服务查询，判断服务端是否支持特定的服务。
```ts
// 创建descriptors
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
  descriptorValue: arrayBuffer};
descriptors[0] = descriptor;

// 创建characteristics
let characteristics: Array<ble.BLECharacteristic> = [];
let arrayBufferC = new ArrayBuffer(2);
let cccV = new Uint8Array(arrayBufferC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: arrayBufferC,
  descriptors:descriptors
};
characteristics[0] = characteristic;

// 创建gattService
let gattService: ble.GattService = {
  serviceUuid:'00001810-0000-1000-8000-00805F9B34FB',
  isPrimary: true,
  characteristics:characteristics,
  includeServices:[]
};

try {
  let gattServer: ble.GattServer = ble.createGattServer(); 
  gattServer.addService(gattService);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 3. 订阅连接状态变化事件
通过订阅连接状态变化事件，可以获取实时的GATT连接状态以及客户端的设备地址。整个连接过程涉及多种状态的跃迁，其中[STATE_CONNECTED](../../reference/apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate)表示已连接，[STATE_DISCONNECTED](../../reference/apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate)表示已断连。
```ts
function ServerConnectStateChanged(state: ble.BLEConnectionChangeState) {
  console.info('bluetooth connect state changed');
  let connectState: ble.ProfileConnectionState = state.state;
  let device = state.deviceId;
}

try {
  let gattServer: ble.GattServer = ble.createGattServer(); 
  gattServer.on('connectionStateChange', ServerConnectStateChanged);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 4. 传输数据
传输数据可以通过客户端读写特征值数据内容、读写描述符数据内容、主动发送特征值数据内容变化通知或指示实现。

**4.1 订阅特征值读取或写入事件**<br>
通过订阅特征值读取或写入事件，获取客户端的操作请求，相关API请参考[on('characteristicRead')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#oncharacteristicread)和[on('characteristicWrite')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#oncharacteristicwrite)。

- 收到读取特征值请求时，需要调用[sendResponse](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#sendresponse)进行回复对应特征值的数据内容。
- 收到写入特征值请求时，可保存客户端写入的特征值数据内容。根据写入请求[CharacteristicWriteRequest](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#characteristicwriterequest)的needRsp判断是否需要调用[sendResponse](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#sendresponse)进行回复。
```ts
let gattServer: ble.GattServer = ble.createGattServer();
let arrayBufferCCC = new ArrayBuffer(2);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1;

// 定义特征值读取回调函数
function readCharacteristicReq(characteristicReadRequest: ble.CharacteristicReadRequest) {
  let deviceId: string = characteristicReadRequest.deviceId;
  let transId: number = characteristicReadRequest.transId;
  let offset: number = characteristicReadRequest.offset;
  let characteristicUuid: string = characteristicReadRequest.characteristicUuid;

  let serverResponse: ble.ServerResponse = {
    deviceId: deviceId,
    transId: transId,
    status: 0,
    offset: offset,
    value:arrayBufferCCC // 传入服务端对应特征值的数据内容，此处是伪代码
  };

  try {
    gattServer.sendResponse(serverResponse);
  } catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  }
}

// 定义特征值写入回调函数
function writeCharacteristicReq(characteristicWriteRequest: ble.CharacteristicWriteRequest) {
  let deviceId: string = characteristicWriteRequest.deviceId;
  let transId: number = characteristicWriteRequest.transId;
  let offset: number = characteristicWriteRequest.offset;
  let needRsp: boolean = characteristicWriteRequest.needRsp;
  if (!needRsp) { // 判断是否需要回复客户端
      return;
  }
  let value: Uint8Array =  new Uint8Array(characteristicWriteRequest.value); // 可保存写入的数据内容
  let characteristicUuid: string = characteristicWriteRequest.characteristicUuid;
  cccValue[0] = value[0];
  let serverResponse: ble.ServerResponse = {
    deviceId: deviceId,
    transId: transId,
    status: 0,
    offset: offset,
    value:arrayBufferCCC
  };

  try {
    gattServer.sendResponse(serverResponse);
  } catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  }
}

// 订阅特征值读取事件
gattServer.on('characteristicRead', readCharacteristicReq);

// 订阅特征值写入事件
gattServer.on('characteristicWrite', writeCharacteristicReq);
```

**4.2 订阅描述符读取或写入事件**<br>
通过订阅描述符读取或写入事件，获取客户端的操作请求，相关API请参考[on('descriptorRead')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#ondescriptorread)和[on('descriptorWrite')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#ondescriptorwrite)。

- 收到读取描述符请求时，需要调用[sendResponse](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#sendresponse)进行回复对应描述符的数据内容。
- 收到写入描述符请求时，可保存客户端写入的描述符数据内容。根据写入请求[DescriptorWriteRequest](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#descriptorwriterequest)的needRsp判断是否需要调用[sendResponse](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#sendresponse)进行回复。
```ts
let gattServer: ble.GattServer = ble.createGattServer();

// 定义描述符读取回调函数
let arrayBufferDesc = new ArrayBuffer(2);
let descValue = new Uint8Array(arrayBufferDesc);
descValue[0] = 1;
function readDescriptorReq(descriptorReadRequest: ble.DescriptorReadRequest) {
  let deviceId: string = descriptorReadRequest.deviceId;
  let transId: number = descriptorReadRequest.transId;
  let offset: number = descriptorReadRequest.offset;
  let descriptorUuid: string = descriptorReadRequest.descriptorUuid;

  let serverResponse: ble.ServerResponse = {
    deviceId: deviceId,
    transId: transId,
    status: 0,
    offset: offset,
    value:arrayBufferDesc
  };

  try {
    gattServer.sendResponse(serverResponse);
  } catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  }
}

// 定义描述符写入回调函数
function writeDescriptorReq(descriptorWriteRequest: ble.DescriptorWriteRequest) {
  let deviceId: string = descriptorWriteRequest.deviceId;
  let transId: number = descriptorWriteRequest.transId;
  let offset: number = descriptorWriteRequest.offset;
  let isPrepared: boolean = descriptorWriteRequest.isPrepared;
  let needRsp: boolean = descriptorWriteRequest.needRsp;
  if (!needRsp) { // 判断是否需要回复客户端
      return;
  }

  let value: Uint8Array = new Uint8Array(descriptorWriteRequest.value); // 可保存写入的数据内容
  let descriptorUuid: string = descriptorWriteRequest.descriptorUuid;
  descValue[0] = value[0];
  let serverResponse: ble.ServerResponse = {
    deviceId: deviceId,
    transId: transId,
    status: 0,
    offset: offset,
    value:arrayBufferDesc
  };

  try {
    gattServer.sendResponse(serverResponse);
  } catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  }
}

// 订阅描述符读取事件
gattServer.on('descriptorRead', readDescriptorReq);

// 订阅描述符写入事件
gattServer.on('descriptorWrite', writeDescriptorReq);
```

**4.3 发送特征值变化通知或指示**<br>
当服务端的特征值数据内容发生变化时，可以通过通知或者指示主动知会到客户端，相关API请参考[notifyCharacteristicChanged](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#notifycharacteristicchanged)。

发送通知时，不需要客户端回复确认；发送指示时，需要客户端回复确认。应用根据[NotifyCharacteristic](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#notifycharacteristic)的confirm参数决定发送哪种类型。

- 该特征值需包含蓝牙标准协议定义的Client Characteristic Configuration描述符UUID（00002902-0000-1000-8000-00805f9b34fb），才支持通知或者指示能力。
- 使用通知或者指示能力需要使能。客户端可以通过[setCharacteristicChangeNotification](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#setcharacteristicchangenotification)或[setCharacteristicChangeIndication](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#setcharacteristicchangeindication)使能该能力，应用根据实际场景选择一种方式即可。
```ts
let device = 'XX:XX:XX:XX:XX:XX'; // 该设备地址表示客户端地址，可以通过连接状态变化事件中获取
let arrayBufferC = new ArrayBuffer(2);
let notifyCharacter: ble.NotifyCharacteristic = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: arrayBufferC,
  confirm: true // 决定发送通知还是指示
};
try {
  let gattServer: ble.GattServer = ble.createGattServer();
  // 发送变更通知或指示
  gattServer.notifyCharacteristicChanged(device, notifyCharacter, (err: BusinessError) => {
    if (err) {
      console.info('notifyCharacteristicChanged callback failed');
    } else {
      console.info('notifyCharacteristicChanged callback successful');
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 5. 关闭服务端实例
当应用不再需要创建的服务端实例时，需要主动关闭，并释放相关资源。例如：删除已添加的服务，取消已订阅事件。
```ts
try {
  let gattServer: ble.GattServer = ble.createGattServer();
  gattServer.removeService('00001810-0000-1000-8000-00805F9B34FB'); // 删除此前注册的服务
  gattServer.close() // 应用不再使用此gattServer，则需要close
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## 完整示例

### 客户端
```ts
import { ble, constant } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = 'GattClientManager';

export class GattClientManager {
  device: string = '';
  gattClient: ble.GattClientDevice | undefined = undefined;
  connectState: ble.ProfileConnectionState = constant.ProfileConnectionState.STATE_DISCONNECTED;
  myServiceUuid: string = '00001810-0000-1000-8000-00805F9B34FB';
  myCharacteristicUuid: string = '00001820-0000-1000-8000-00805F9B34FB';
  // 标准协议描述符Client Characteristic Configuration，用于特征值变化通知或指示
  myFirstDescriptorUuid: string = '00002902-0000-1000-8000-00805F9B34FB';
  // 自定义描述符
  mySecondDescriptorUuid: string = '00008888-0000-1000-8000-00805F9B34FB';

  myService: ble.GattService | undefined = undefined;
  myCharacteristic: ble.BLECharacteristic | undefined = undefined;
  myFirstDescriptor: ble.BLEDescriptor | undefined = undefined;
  mySecondDescriptor: ble.BLEDescriptor | undefined = undefined;

  foundService: boolean = false;
  foundChar: boolean = false;
  foundFirstDes: boolean = false;
  foundSecondDes: boolean = false;

  // 构造BLEDescriptor
  private initDescriptor(des: string, value: ArrayBuffer): ble.BLEDescriptor {
    let descriptor: ble.BLEDescriptor = {
      serviceUuid: this.myServiceUuid,
      characteristicUuid: this.myCharacteristicUuid,
      descriptorUuid: des,
      descriptorValue: value
    };
    return descriptor;
  }

  // 构造BLECharacteristic
  private initCharacteristic(isWrite: boolean): ble.BLECharacteristic {
    let descriptors: Array<ble.BLEDescriptor> = [];
    let charBuffer = new ArrayBuffer(2);
    if (isWrite) {
      let charValue = new Uint8Array(charBuffer);
      charValue[0] = 21;
      charValue[1] = 22;
    }
    let characteristic: ble.BLECharacteristic = {
      serviceUuid: this.myServiceUuid,
      characteristicUuid: this.myCharacteristicUuid,
      characteristicValue: charBuffer,
      descriptors: descriptors
    };
    return characteristic;
  }

  private logCharacteristic(char: ble.BLECharacteristic) {
    let message = 'logCharacteristic uuid:' + char.characteristicUuid + ', value: ';
    let value = new Uint8Array(char.characteristicValue);
    message += 'logCharacteristic value: ';
    for (let i = 0; i < char.characteristicValue.byteLength; i++) {
      message += value[i] + ' ';
    }
    console.info(TAG, message);
  }

  private logDescriptor(des: ble.BLEDescriptor) {
    let message = 'logDescriptor uuid:' + des.descriptorUuid + ', value: ';
    let value = new Uint8Array(des.descriptorValue);
    message += 'logDescriptor value: ';
    for (let i = 0; i < des.descriptorValue.byteLength; i++) {
      message += value[i] + ' ';
    }
    console.info(TAG, message);
  }

  private checkService(services: Array<ble.GattService>) {
    for (let i = 0; i < services.length; i++) {
      if (services[i].serviceUuid != this.myServiceUuid) {
        continue;
      }
      this.myService = services[i];
      this.foundService = true;
      for (let j = 0; j < services[i].characteristics.length; j++) {
        if (services[i].characteristics[j].characteristicUuid != this.myCharacteristicUuid) {
          continue;
        }
        this.logCharacteristic(services[i].characteristics[j]);
        this.myCharacteristic = services[i].characteristics[j];
        this.foundChar = true;
        for (let k = 0; k < services[i].characteristics[j].descriptors.length; k++) {
          if (services[i].characteristics[j].descriptors[k].descriptorUuid == this.myFirstDescriptorUuid) {
            this.myFirstDescriptor= services[i].characteristics[j].descriptors[k];
            this.foundFirstDes = true;
            continue;
          }
          if (services[i].characteristics[j].descriptors[k].descriptorUuid == this.mySecondDescriptorUuid) {
            this.mySecondDescriptor = services[i].characteristics[j].descriptors[k];
            this.foundSecondDes = true;
            continue;
          }
        }
      }
    }
    console.info(TAG, 'foundService: ' + this.foundService + ', foundChar: ' + this.foundChar +
      ', foundFirDes: ' + this.foundFirstDes + ', foundSecDes: ' + this.foundSecondDes);
  }

  // 1. 定义连接状态变化回调函数
  onGattClientStateChange = (stateInfo: ble.BLEConnectionChangeState) => {
    let state = '';
    switch (stateInfo.state) {
      case 0:
        state = 'DISCONNECTED';
        break;
      case 1:
        state = 'CONNECTING';
        break;
      case 2:
        state = 'CONNECTED';
        break;
      case 3:
        state = 'DISCONNECTING';
        break;
      default:
        state = 'undefined';
        break;
    }
    console.info(TAG, 'onGattClientStateChange: device=' + stateInfo.deviceId + ', state=' + state);
    if (stateInfo.deviceId == this.device) {
      this.connectState = stateInfo.state;
    }
  };

  // 2. client端主动连接时调用
  public startConnect(peerDevice: string) { // 对端设备一般通过ble查找设备获取到
    if (this.connectState != constant.ProfileConnectionState.STATE_DISCONNECTED) {
      console.error(TAG, 'startConnect failed');
      return;
    }
    console.info(TAG, 'startConnect ' + peerDevice);
    this.device = peerDevice;
    // 2.1 使用device构造gattClient，后续的交互都需要使用该实例
    this.gattClient = ble.createGattClientDevice(peerDevice);
    try {
      // 2.2 订阅连接状态
      this.gattClient.on('BLEConnectionStateChange', this.onGattClientStateChange);

      // 2.3 发起连接
      this.gattClient.connect();
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 3. client端连接成功后，需要进行服务发现
  public async discoverServices() {
    if (!this.gattClient) {
      console.info(TAG, 'gattClient does not exist');
      return;
    }
    console.info(TAG, 'discoverServices');
    try {
      let serverSerice = await this.gattClient.getServices();
      this.checkService(serverSerice); // 要确保server端的服务内容有业务所需要的服务
      if (typeof this.myService !== 'undefined') {
        console.info(TAG, 'Service: ' + JSON.stringify(this.myService));
      }
      if (typeof this.myCharacteristic !== 'undefined') {
        this.logCharacteristic(this.myCharacteristic);
      }
      if (typeof this.myFirstDescriptor !== 'undefined') {
        this.logDescriptor(this.myFirstDescriptor);
      }
      if (typeof this.mySecondDescriptor !== 'undefined') {
        this.logDescriptor(this.mySecondDescriptor);
      }
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 4. 在确保拿到了server端的服务结果后，读取server端特定服务的特征值时调用
  public readCharacteristicValue() {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }
    if (!this.foundChar) { // 要确保server端有对应的characteristic
      console.error(TAG, 'server characteristic does not exist');
      return;
    }

    let characteristic = this.initCharacteristic(false);
    console.info(TAG, 'readCharacteristicValue');
    try {
      this.gattClient.readCharacteristicValue(characteristic).then((outData: ble.BLECharacteristic) => {
        this.myCharacteristic = outData;
        this.logCharacteristic(this.myCharacteristic);
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 5. 在确保拿到了server端的服务结果后，写入server端特定服务的特征值时调用
  public writeCharacteristicValue() {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }
    if (!this.foundChar) { // 要确保server端有对应的characteristic
      console.error(TAG, 'server characteristic does not exist');
      return;
    }

    let characteristic = this.initCharacteristic(true);
    console.info(TAG, 'writeCharacteristicValue');
    try {
      this.gattClient.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE, (err) => {
        if (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
          return;
        }
        console.info(TAG, 'writeCharacteristicValue success');
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 6. 在确保拿到了server端的服务结果后，读取server端特定服务的描述符时调用
  public readDescriptorValue() {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }
    if (!this.foundSecondDes) { // 要确保server端有对应的descriptor
      console.error(TAG, 'server descriptor does not exist');
      return;
    }

    let descBuffer = new ArrayBuffer(0);
    let descriptor = this.initDescriptor(this.mySecondDescriptorUuid, descBuffer);
    console.info(TAG, 'readDescriptorValue');
    try {
      this.gattClient.readDescriptorValue(descriptor).then((outData: ble.BLEDescriptor) => {
        this.logDescriptor(outData);
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 7. 在确保拿到了server端的服务结果后，写入server端特定服务的描述符时调用
  public writeDescriptorValue() {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }
    if (!this.foundSecondDes) { // 要确保server端有对应的descriptor
      console.error(TAG, 'server descriptor does not exist');
      return;
    }

    let descBuffer = new ArrayBuffer(2);
    let descValue = new Uint8Array(descBuffer);
    descValue[0] = 41;
    descValue[1] = 42;
    let descriptor = this.initDescriptor(this.mySecondDescriptorUuid, descBuffer);
    console.info(TAG, 'writeDescriptorValue');
    try {
      this.gattClient.writeDescriptorValue(descriptor, (err) => {
        if (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
          return;
        }
        console.info(TAG, 'writeDescriptorValue success');
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 8. 定义特征值变化回调函数
  onCharacteristicChange = (char: ble.BLECharacteristic) => {
    console.info(TAG, 'onCharacteristicChange: uuid: ' + char.characteristicUuid + ', value: ' + JSON.stringify(new Uint8Array(char.characteristicValue)));
    this.myCharacteristic = char;
    this.logCharacteristic(this.myCharacteristic);
  }

  // 9. 使能或禁用接收服务端端特征值内容变更通知的能力时调用，一般通知或者指示，二选一
  public Notify(enable: boolean) {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }

    if (!this.foundFirstDes) { // 要确保server端有对应的client configuration descriptor
      console.error(TAG, 'server client configuration descriptor does not exist');
      return;
    }

    console.info(TAG, 'Notify ' + this.device + ' enable: ' + enable);
    try {
      // 订阅特征值变化
      this.gattClient.on('BLECharacteristicChange', this.onCharacteristicChange);
      // 设置特征值变化通知能力，enable: true表示启用，false表示禁用
      this.gattClient.setCharacteristicChangeNotification(this.myCharacteristic, enable, (err: BusinessError) => {
        if (err) {
          console.info('setCharacteristicChangeNotification callback failed');
        } else {
          console.info('setCharacteristicChangeNotification callback successful');
        }
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 10. 使能或禁用接收服务端端特征值内容变更指示的能力时调用，一般通知或者指示，二选一
  public Indicate(enable: boolean) {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }

    if (!this.foundFirstDes) { // 要确保server端有对应的client configuration descriptor
      console.error(TAG, 'server client configuration descriptor does not exist');
      return;
    }

    console.info(TAG, 'Indicate ' + this.device + ' enable: ' + enable);
    try {
      // 订阅特征值变化
      this.gattClient.on('BLECharacteristicChange', this.onCharacteristicChange);
      // 设置特征值变化指示能力，enable: true表示启用，false表示禁用
      this.gattClient.setCharacteristicChangeIndication(this.myCharacteristic, enable, (err: BusinessError) => {
        if (err) {
          console.info('setCharacteristicChangeIndication callback failed');
        } else {
          console.info('setCharacteristicChangeIndication callback successful');
        }
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 11.client端主动断开时调用
  public stopConnect() {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }

    console.info(TAG, 'stopConnect ' + this.device);
    try {
      this.gattClient.disconnect(); // 11.1 断开连接
      this.gattClient.off('BLEConnectionStateChange', this.onGattClientStateChange); // 11.2 取消订阅连接状态
      this.gattClient.off('BLECharacteristicChange', this.onCharacteristicChange); // 11.3 取消订阅特征值变化
      this.gattClient.close() // 11.4 如果应用不再使用此gattClient，则需要close
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let gattClientManager = new GattClientManager();
export default gattClientManager as GattClientManager;
```

### 服务端
```ts
import { ble, constant } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = 'GattServerManager';

export class GattServerManager {
  device = '';
  gattServer: ble.GattServer | undefined = undefined;
  connectState: ble.ProfileConnectionState = constant.ProfileConnectionState.STATE_DISCONNECTED;
  myServiceUuid: string = '00001810-0000-1000-8000-00805F9B34FB';
  myCharacteristicUuid: string = '00001820-0000-1000-8000-00805F9B34FB';
  // 标准协议描述符Client Characteristic Configuration，用于特征值变化通知或指示
  myFirstDescriptorUuid: string = '00002902-0000-1000-8000-00805F9B34FB';
  // 自定义描述符
  mySecondDescriptorUuid: string = '00008888-0000-1000-8000-00805F9B34FB';

  charBuffer = new ArrayBuffer(2);
  charValue = new Uint8Array(this.charBuffer);

  firDescBuffer = new ArrayBuffer(2);
  firDescValue = new Uint8Array(this.firDescBuffer);

  secDescBuffer = new ArrayBuffer(2);
  secDescValue = new Uint8Array(this.secDescBuffer);

  // 构造BLEDescriptor
  private initDescriptor(des: string, value: ArrayBuffer): ble.BLEDescriptor {
    let descriptor: ble.BLEDescriptor = {
      serviceUuid: this.myServiceUuid,
      characteristicUuid: this.myCharacteristicUuid,
      descriptorUuid: des,
      descriptorValue: value
    };
    return descriptor;
  }

  // 构造BLECharacteristic
  private initCharacteristic(): ble.BLECharacteristic {
    let descriptors: Array<ble.BLEDescriptor> = [];
    // 默认Client Characteristic Configuration描述符没有使能特征值变化通知或者指示能力
    descriptors[0] = this.initDescriptor(this.myFirstDescriptorUuid, this.firDescBuffer);
    this.secDescValue[0] = 31;
    this.secDescValue[1] = 32;
    descriptors[1] = this.initDescriptor(this.mySecondDescriptorUuid, this.secDescBuffer);
    this.charValue[0] = 1;
    this.charValue[1] = 2;
    let characteristic: ble.BLECharacteristic = {
      serviceUuid: this.myServiceUuid,
      characteristicUuid: this.myCharacteristicUuid,
      characteristicValue: this.charBuffer,
      descriptors: descriptors
    };
    return characteristic;
  }

  // 1. 定义连接状态变化回调函数
  onGattServerStateChange = (stateInfo: ble.BLEConnectionChangeState) => {
    let state = '';
    switch (stateInfo.state) {
      case 0:
        state = 'DISCONNECTED';
      break;
      case 1:
        state = 'CONNECTING';
      break;
      case 2:
        state = 'CONNECTED';
      break;
      case 3:
        state = 'DISCONNECTING';
      break;
      default:
        state = 'undefined';
      break;
    }
    console.info(TAG, 'onGattServerStateChange: device=' + stateInfo.deviceId + ', state=' + state);
    this.device = stateInfo.deviceId;
  }

  // 2. 定义读取特征值请求回调函数
  onCharacteristicRead = (charReq: ble.CharacteristicReadRequest) => {
    let deviceId: string = charReq.deviceId;
    let transId: number = charReq.transId;
    let offset: number = charReq.offset;
    console.info(TAG, 'receive characteristicRead: uuid: ' + charReq.characteristicUuid + ', value: ' + JSON.stringify(this.charValue));
    let serverResponse: ble.ServerResponse = {
      deviceId: deviceId,
      transId: transId,
      status: 0, // 0表示成功
      offset: offset,
      value: this.charBuffer
    };

    try {
      this.gattServer?.sendResponse(serverResponse);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  };

  // 检查client configuration descriptor的通知能力是否使能
  private checkDescriptorNotification(buffer: Uint8Array): boolean {
    const notify = new ArrayBuffer(2);
    let notifyValue = new Uint8Array(notify);
    notifyValue.set([1, 0]); // 使能client configuration descriptor notification的值
    return notifyValue.every((value, index) => value === buffer[index]);
  }

  // 检查client configuration descriptor的指示能力是否使能
  private checkDescriptorIndication(buffer: Uint8Array): boolean {
    const notify = new ArrayBuffer(2);
    let notifyValue = new Uint8Array(notify);
    notifyValue.set([2, 0]); // 使能client configuration descriptor indication的值
    return notifyValue.every((value, index) => value === buffer[index]);
  }

  // 3. 定义写入特征值请求回调函数
  onCharacteristicWrite = (charReq: ble.CharacteristicWriteRequest) => {
    let deviceId: string = charReq.deviceId;
    let transId: number = charReq.transId;
    let offset: number = charReq.offset;
    this.charBuffer = charReq.value;
    this.charValue = new Uint8Array(charReq.value);
    console.info(TAG, 'receive characteristicWrite: uuid: ' + charReq.characteristicUuid + ', needRsp=' + charReq.needRsp + ', value: ' + JSON.stringify(this.charValue));
    if (!charReq.needRsp) {
      return;
    }
    let rspBuffer = new ArrayBuffer(0);
    let serverResponse: ble.ServerResponse = {
      deviceId: deviceId,
      transId: transId,
      status: 0, // 0表示成功
      offset: offset,
      value: rspBuffer
    };

    try {
      this.gattServer?.sendResponse(serverResponse);
      this.sendCharacterChange(); // 此处特征值变化了，模拟主动发送变化通知或者指示
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 4. 定义读取描述符请求回调函数
  onDescriptorRead = (desReq: ble.DescriptorReadRequest) => {
    let deviceId: string = desReq.deviceId;
    let transId: number = desReq.transId;
    let offset: number = desReq.offset;
    let tmpBuffer = new ArrayBuffer(2);
    if (desReq.descriptorUuid == this.myFirstDescriptorUuid) {
      tmpBuffer = this.firDescBuffer;
    } else {
      tmpBuffer = this.secDescBuffer;
    }
    let tmpValue = new Uint8Array(tmpBuffer);
    console.info(TAG, 'receive descriptorRead: ' + desReq.descriptorUuid + ', tmpValue: ' + JSON.stringify(tmpValue));
    let serverResponse: ble.ServerResponse = {
      deviceId: deviceId,
      transId: transId,
      status: 0, // 0表示成功
      offset: offset,
      value: tmpBuffer
    };

    try {
      this.gattServer?.sendResponse(serverResponse);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 5. 定义写入描述符请求回调函数
  onDescriptorWrite = (desReq: ble.DescriptorWriteRequest) => {
    let deviceId: string = desReq.deviceId;
    let transId: number = desReq.transId;
    let offset: number = desReq.offset;
    console.info(TAG, 'receive descriptorWrite: uuid: ' + desReq.descriptorUuid + ', needRsp: '+ desReq.needRsp + ', value: ' + JSON.stringify(new Uint8Array(desReq.value)));
    if (desReq.descriptorUuid == this.myFirstDescriptorUuid) {
      this.firDescBuffer = desReq.value;
      this.firDescValue = new Uint8Array(desReq.value);
    } else {
      this.secDescBuffer = desReq.value;
      this.secDescValue = new Uint8Array(desReq.value);
    }
    if (!desReq.needRsp) {
      return;
    }
    let rspBuffer = new ArrayBuffer(0);
    let serverResponse: ble.ServerResponse = {
      deviceId: deviceId,
      transId: transId,
      status: 0, // 0表示成功
      offset: offset,
      value: rspBuffer
    };

    try {
      this.gattServer?.sendResponse(serverResponse);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 6. server端注册服务时调用
  public registerServer() {
    let characteristics: Array<ble.BLECharacteristic> = [];
    let characteristic = this.initCharacteristic();
    characteristics.push(characteristic);
    let gattService: ble.GattService = {
      serviceUuid: this.myServiceUuid,
      isPrimary: true,
      characteristics: characteristics
    };

    console.info(TAG, 'registerServer ' + this.myServiceUuid);
    try {
      this.gattServer = ble.createGattServer(); // 6.1 构造gattServer，后续的交互都需要使用该实例
      this.gattServer.addService(gattService); // 6.2 注册服务
      this.gattServer.on('connectionStateChange', this.onGattServerStateChange); // 6.3 订阅连接状态
      this.gattServer.on('characteristicRead', this.onCharacteristicRead); // 6.4 订阅特征值读事件
      this.gattServer.on('characteristicWrite', this.onCharacteristicWrite); // 6.5 订阅特征值读事件
      this.gattServer.on('descriptorRead', this.onDescriptorRead); // 6.6 订阅特征值读事件
      this.gattServer.on('descriptorWrite', this.onDescriptorWrite); // 6.7 订阅特征值读事件
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 7. 特征值内容发生变化时调用
  public sendCharacterChange() {
    console.info(TAG, 'sendCharacterChange: uuid: ' + this.myCharacteristicUuid + ', value: ' + JSON.stringify(new Uint8Array(this.charBuffer)));
    if (this.checkDescriptorNotification(this.firDescValue)) {
      let notifyCharacter: ble.NotifyCharacteristic = {
        serviceUuid: this.myServiceUuid,
        characteristicUuid: this.myCharacteristicUuid,
        characteristicValue: this.charBuffer,
        confirm: false
      };
      console.info(TAG, 'sendCharacterChange notification');
      this.gattServer?.notifyCharacteristicChanged(this.device, notifyCharacter, (err: BusinessError) => {
        if (err) {
          console.info(TAG, 'notifyCharacteristicChanged notification callback failed');
        } else {
          console.info(TAG, 'notifyCharacteristicChanged notification callback successful');
        }
      });
    } else if (this.checkDescriptorIndication(this.firDescValue)) {
      let notifyCharacter: ble.NotifyCharacteristic = {
        serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
        characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
        characteristicValue: this.charBuffer,
        confirm: true
      };
      console.info(TAG, 'sendCharacterChange indication');
      this.gattServer?.notifyCharacteristicChanged(this.device, notifyCharacter, (err: BusinessError) => {
        if (err) {
          console.info(TAG, 'notifyCharacteristicChanged indication callback failed');
        } else {
          console.info(TAG, 'notifyCharacteristicChanged indication callback successful');
        }
      });
    } else {
      console.info(TAG, 'notification/indication is disabled');
    }
  }

  // 8. server端删除服务，不再使用时调用
  public unRegisterServer() {
    if (!this.gattServer) {
      console.error(TAG, 'no gattServer');
      return;
    }

    console.info(TAG, 'unRegisterServer ' + this.myServiceUuid);
    try {
      this.gattServer.removeService(this.myServiceUuid); // 8.1 删除服务
      this.gattServer.off('connectionStateChange', this.onGattServerStateChange) // 8.2 取消订阅连接状态
      this.gattServer.on('characteristicRead', this.onCharacteristicRead); // 8.3 订阅特征值读事件
      this.gattServer.on('characteristicWrite', this.onCharacteristicWrite); // 8.4 订阅特征值读事件
      this.gattServer.on('descriptorRead', this.onDescriptorRead); // 8.5 订阅特征值读事件
      this.gattServer.on('descriptorWrite', this.onDescriptorWrite); // 8.6 订阅特征值读事件
      this.gattServer.close() // 8.7 如果应用不再使用此gattServer，则需要close
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let gattServerManager = new GattServerManager();
export default gattServerManager as GattServerManager;
```