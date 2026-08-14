# 蓝牙可选属性显式设置为undefined报401无效参数

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## 问题现象
在BLE蓝牙应用开发过程中，调用携带可选参数的接口时，如果将可选属性显式设置为undefined，比如[startScan](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#startscan15)，（在对象字面量中写入manufactureId: undefined），接口会抛出错误码401（Invalid parameter），提示无效参数。

## 问题原因
bleScanner.startScan等接口的底层由C/C++实现。在TS侧调用这些接口时，参数会通过NAPI传递到系统底层进行解析：

- **对象键的存在性**：在内存中，{}（不写属性）和{ manufactureId: undefined }（显式赋值为undefined）是不同的。前者不包含该Key，后者包含该Key，但值为undefined。
- **底层的强类型校验**：当底层C++接收到配置对象时：
    - 如果存在manufactureId这个键，安全机制会严格校验对应的值。系统期望解析出一个合法的数值（Number类型），但实际拿到的是undefined，导致类型不匹配。NAPI解析失败，在入口处抛出401: Invalid parameter。
    - 如果不存在manufactureId这个键，会直接跳过，按系统默认逻辑（即不限制manufactureId）执行。
    

## 解决方案
为避免跨语言调用时的严格类型校验问题，对于可选参数，建议遵循按需挂载原则（没有有效值就不写Key），以bleScanner.startScan接口为例：

```ts
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';

let manufactureId: number | undefined = undefined; // 模拟实际业务中可能为空的值
let manufactureData: Uint8Array = new Uint8Array([1, 2, 3, 4]);
let manufactureDataMask: Uint8Array = new Uint8Array([0xFF, 0xFF, 0xFF, 0xFF]);

// 不推荐将undefined直接写入对象字面量（会触发401错误码）
// let scanFilter: ble.ScanFilter = {
//     manufactureId: undefined,
//     manufactureData: manufactureData.buffer,
//     manufactureDataMask: manufactureDataMask.buffer
// };

// 推荐：只初始化确定有值的属性
let scanFilter: ble.ScanFilter = {
    manufactureData: manufactureData.buffer,
    manufactureDataMask: manufactureDataMask.buffer
};

// 通过动态判断，仅在值有效时才将其挂载到对象上
if (manufactureId !== undefined) {
    scanFilter.manufactureId = manufactureId;
}

let bleScanner: ble.BleScanner = ble.createBleScanner();

function onReceiveEvent(scanReport: ble.ScanReport) {
    console.info('BLE scan device find result = ' + JSON.stringify(scanReport));
}

let scanOptions: ble.ScanOptions = {
    interval: 500,
    dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
    matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE,
    reportMode: ble.ScanReportMode.FENCE_SENSITIVITY_LOW
};

try {
    bleScanner.on("BLEDeviceFind", onReceiveEvent);
    bleScanner.startScan([scanFilter], scanOptions);
    console.info('startScan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## 总结
- 构造参数对象时，对于可选属性，不要显式赋值为undefined。
- 仅在属性有有效值时，才将其写入对象字面量或动态挂载到对象上。
- 该规范适用于所有通过NAPI调用底层C/C++接口的场景，包括但不限于BLE扫描过滤条件构造、事件订阅/取消订阅等。