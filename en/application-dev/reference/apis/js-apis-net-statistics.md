# Network Traffic Management

The Network Traffic Management module collects statistics on the mobile data traffic and allows you to query the data volume by network interface (cellular or Wi-Fi) or application.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import statistics from '@ohos.net.statistics'
```

## statistics.getIfaceRxBytes

getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void

Obtains the volume of mobile data traffic received by a specified NIC. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| nic | string | Yes  | NIC name.|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in bytes.|

**Example**

```js
statistics.getIfaceRxBytes(this.nic, (err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getIfaceRxBytes

getIfaceRxBytes(nic: string): Promise\<number>;

Obtains the volume of mobile data traffic received by a specified NIC. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| nic | string | Yes  | NIC name.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in bytes.|

**Example**

```js
statistics.getIfaceRxBytes(this.nic).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getIfaceTxBytes

getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void

Obtains the volume of mobile data traffic sent by a specified NIC. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| nic | string | Yes  | NIC name.|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in bytes.|

**Example**

```js
statistics.getIfaceTxBytes(this.nic, (err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getIfaceTxBytes

getIfaceTxBytes(nic: string): Promise\<number>;

Obtains the volume of mobile data traffic sent by a specified NIC. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| nic | string | Yes  | NIC name.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in bytes.|

**Example**

```js
statistics.getIfaceTxBytes(this.nic).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getCellularRxBytes

getCellularRxBytes(callback: AsyncCallback\<number>): void;

Obtains the volume of mobile data traffic received by the cellular network. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in bytes.|

**Example**

```js
statistics.getCellularRxBytes((err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getCellularRxBytes

getCellularRxBytes(): Promise\<number>;

Obtains the volume of mobile data traffic received by the cellular network. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in bytes.|

**Example**

```js
statistics.getCellularRxBytes().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getCellularTxBytes

getCellularTxBytes(callback: AsyncCallback\<number>): void;

Obtains the volume of mobile data traffic sent by the cellular network. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in bytes.|

**Example**

```js
statistics.getCellularTxBytes((err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getCellularTxBytes

getCellularTxBytes(): Promise\<number>;

Obtains the volume of mobile data traffic sent by the cellular network. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in bytes.|

**Example**

```js
statistics.getCellularTxBytes().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getAllRxBytes

getAllRxBytes(callback: AsyncCallback\<number>): void;

Obtains the volume of mobile data traffic received by all NICs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in bytes.|

**Example**

```js
statistics.getAllRxBytes(err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getAllRxBytes

getAllRxBytes(): Promise\<number>;

Obtains the volume of mobile data traffic received by all NICs. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in bytes.|

**Example**

```js
statistics.getAllRxBytes().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getAllTxBytes

getAllTxBytes(callback: AsyncCallback\<number>): void;

Obtains the volume of mobile data traffic sent by all NICs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in bytes.|

**Example**

```js
statistics.getAllTxBytes((err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getAllTxBytes

getAllTxBytes(): Promise\<number>;

Obtains the volume of mobile data traffic sent by all NICs. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in bytes.|

**Example**

```js
statistics.getAllTxBytes().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getUidRxBytes

getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void;

Obtains the volume of mobile data traffic received by a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes  | Application ID.|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in bytes.|

**Example**

```js
statistics.getUidRxBytes(this.uid, (err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getUidRxBytes

getUidRxBytes(uid: number): Promise\<number>;

Obtains the volume of mobile data traffic received by a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes  | Application ID.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in bytes.|

**Example**

```js
statistics.getUidRxBytes(this.uid).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## statistics.getUidTxBytes

getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void;

Obtains the volume of mobile data traffic sent by a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes  | Application ID.|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in bytes.|

**Example**

```js
statistics.getUidTxBytes(this.uid, (err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

## statistics.getUidTxBytes

getUidTxBytes(uid: number): Promise\<number>;

Obtains the volume of mobile data traffic sent by a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes  | Application ID.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in bytes.|

**Example**

```js
statistics.getUidTxBytes(this.uid).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```
