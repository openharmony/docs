# @ohos.geoLocationManager    
位置服务提供GNSS定位、网络定位、地理编码、逆地理编码、国家码和地理围栏等基本功能。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import geoLocationManager from '@ohos.geoLocationManager'    
```  
    
## on('locatingRequiredDataChange')<sup>(10+)</sup>    
订阅定位业务所需数据的变化，主要包含WiFi和蓝牙扫描信息；根据入参决定是否启动WiFi和蓝牙扫描。  
 **调用形式：**     
    
- on(type: 'locatingRequiredDataChange', config: LocatingRequiredDataConfig, callback: Callback\<Array\<LocatingRequiredData>>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“locatingRequiredDataChange”，表示订阅定位业务所需数据的变化。 |  
| config | LocatingRequiredDataConfig | true | 表示获取定位所需数据时的配置参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收定位业务所需数据的上报。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301800 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let callback = (code:Array<geoLocationManager.LocatingRequiredData>):void => {  
    console.log('locatingRequiredDataChange: ' + JSON.stringify(code));  
}  
let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};  
try {  
    geoLocationManager.on('locatingRequiredDataChange', config, callback);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## off('locatingRequiredDataChange')<sup>(10+)</sup>    
取消订阅定位业务所需数据的变化，并停止WiFi和蓝牙扫描。  
 **调用形式：**     
    
- off(type: 'locatingRequiredDataChange', callback?: Callback\<Array\<LocatingRequiredData>>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“locatingRequiredDataChange”，表示取消订阅定位业务所需数据的变化。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let callback = (code:Array<geoLocationManager.LocatingRequiredData>):void => {  
    console.log('locatingRequiredDataChange: ' + JSON.stringify(code));  
}  
let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};  
try {  
    geoLocationManager.on('locatingRequiredDataChange', config, callback);  
    geoLocationManager.off('locatingRequiredDataChange', callback);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## enableLocation    
打开位置服务。  
 **调用形式：**     
    
- enableLocation(callback: AsyncCallback\<void>): void    
起始版本： 9    
- enableLocation(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.MANAGE_SECURE_SETTINGS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 用来接收错误码信息。 |  
| Promise<void> | 返回错误码信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.enableLocation((err, data) => {  
        if (err) {  
            console.log('enableLocation: err=' + JSON.stringify(err));  
        }  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.enableLocation().then((result) => {  
        console.log('promise, enableLocation succeed');  
    })  
    .catch((error:number) => {  
        console.log('promise, enableLocation: error=' + JSON.stringify(error));  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## disableLocation    
关闭位置服务。  
 **调用形式：**     
- disableLocation(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.MANAGE_SECURE_SETTINGS    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.disableLocation();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## enableLocationMock    
使能位置模拟功能。  
 **调用形式：**     
- enableLocationMock(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.enableLocationMock();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## disableLocationMock    
去使能位置模拟功能。  
 **调用形式：**     
- disableLocationMock(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.disableLocationMock();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## setMockedLocations    
设置模拟的位置信息，后面会以该接口中携带的时间间隔上报模拟位置。  
 **调用形式：**     
- setMockedLocations(config: LocationMockConfig): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | LocationMockConfig | true | 指示位置模拟的配置参数，包含模拟位置上报的时间间隔和模拟位置数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let locations:Array<geoLocationManager.Location> = [  
    {"latitude": 30.12, "longitude": 120.11, "altitude": 123, "accuracy": 1, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 1000000000, "additionSize": 0, "isFromMock": true},  
    {"latitude": 31.13, "longitude": 121.11, "altitude": 123, "accuracy": 2, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 2000000000, "additionSize": 0, "isFromMock": true},  
    {"latitude": 32.14, "longitude": 122.11, "altitude": 123, "accuracy": 3, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 3000000000, "additionSize": 0, "isFromMock": true},  
    {"latitude": 33.15, "longitude": 123.11, "altitude": 123, "accuracy": 4, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 4000000000, "additionSize": 0, "isFromMock": true},  
    {"latitude": 34.16, "longitude": 124.11, "altitude": 123, "accuracy": 5, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 5000000000, "additionSize": 0, "isFromMock": true}  
];  
let config:geoLocationManager.LocationMockConfig = {"timeInterval": 5, "locations": locations};  
try {  
    geoLocationManager.enableLocationMock();  
    geoLocationManager.setMockedLocations(config);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## enableReverseGeocodingMock    
使能逆地理编码模拟功能。  
 **调用形式：**     
- enableReverseGeocodingMock(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.enableReverseGeocodingMock();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## disableReverseGeocodingMock    
去使能逆地理编码模拟功能。  
 **调用形式：**     
- disableReverseGeocodingMock(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.disableReverseGeocodingMock();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## setReverseGeocodingMockInfo    
设置逆地理编码模拟功能的配置信息，包含了位置和地名的对应关系，后续进行逆地理编码查询时如果位置信息位于配置信息中，就返回对应的地名。  
 **调用形式：**     
- setReverseGeocodingMockInfo(mockInfos: Array\<ReverseGeocodingMockInfo>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mockInfos | Array<ReverseGeocodingMockInfo> | true | 指示逆地理编码模拟功能的配置参数数组。逆地理编码模拟功能的配置参数包含了一个位置和一个地名。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let mockInfos:Array<geoLocationManager.ReverseGeocodingMockInfo> = [  
    {"location": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "isFromMock": true}},  
    {"location": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "isFromMock": true}},  
    {"location": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "isFromMock": true}},  
    {"location": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "isFromMock": true}},  
    {"location": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "isFromMock": true}},  
];  
try {  
    geoLocationManager.enableReverseGeocodingMock();  
    geoLocationManager.setReverseGeocodingMockInfo(mockInfos);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## isLocationPrivacyConfirmed    
查询用户是否同意定位服务隐私申明，是否同意启用定位服务。只有系统应用才能调用。  
 **调用形式：**     
- isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | LocationPrivacyType | true | 指定隐私申明场景，例如开机向导中的隐私申明、开启网络定位功能时弹出的隐私申明等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 表示用户是否同意定位服务隐私申明。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    let isConfirmed = geoLocationManager.isLocationPrivacyConfirmed(1);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## setLocationPrivacyConfirmStatus    
设置用户勾选定位服务隐私申明的状态，记录用户是否同意启用定位服务。只有系统应用才能调用。  
 **调用形式：**     
- setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.MANAGE_SECURE_SETTINGS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | LocationPrivacyType | true | 指定隐私申明场景，例如开机向导中的隐私申明、开启网络定位功能时弹出的隐私申明等。 |  
| isConfirmed | boolean | true | 表示用户是否同意定位服务隐私申明。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.setLocationPrivacyConfirmStatus(1, true);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## getLocatingRequiredData<sup>(10+)</sup>    
单次获取定位业务所需数据，包含WiFi蓝牙扫描信息。  
 **调用形式：**     
    
- getLocatingRequiredData(config: LocatingRequiredDataConfig): Promise\<Array\<LocatingRequiredData>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | LocatingRequiredDataConfig | true | 表示获取定位所需数据时的配置参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Array<LocatingRequiredData>> | 用来接收定位业务所需数据，包含WiFi蓝牙扫描信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301800 | Failed to start WiFi or Bluetooth scanning. |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};  
try {  
    geoLocationManager.getLocatingRequiredData(config).then((result) => {  
        console.log('getLocatingRequiredData return: ' + JSON.stringify(result));  
    })    
    .catch((error:number) => {  
        console.log('promise, getLocatingRequiredData: error=' + JSON.stringify(error));  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## ReverseGeocodingMockInfo    
逆地理编码模拟功能的配置信息，包含一个位置信息和一个地名信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| location | ReverseGeoCodeRequest | false | true | 表示经纬度信息。 |  
| geoAddress | GeoAddress | false | true | 表示地名信息。 |  
    
## LocationMockConfig    
位置模拟功能的配置参数，包含了模拟位置上报的时间间隔和模拟位置数组。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| timeInterval | number | false | true | 表示模拟位置上报的时间间隔，单位是秒。 |  
| locations | Array<Location> | false | true | 表示模拟位置数组。 |  
    
## GeoAddress    
地理编码类型。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isFromMock | Boolean | false | false | 表示地名信息是否来自于逆地理编码模拟功能。<br>**系统API**：此接口为系统接口。 |  
    
## Location    
位置信息类型。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isFromMock | Boolean | false | false | 表示位置信息是否来自于位置模拟功能。<br>**系统API**：此接口为系统接口。 |  
    
## LocatingRequiredDataConfig<sup>(10+)</sup>    
获取定位所需数据时的配置参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(10+)</sup> | LocatingRequiredDataType | false | true | 表示请求获取数据的类型。 |  
| needStartScan<sup>(10+)</sup> | boolean | false | true | 表示是否需要发起扫描。 |  
| scanInterval<sup>(10+)</sup> | number | false | false | 表示扫描的时间间隔。单位是毫秒，默认值是10000毫秒，取值范围为大于0。 |  
| scanTimeout<sup>(10+)</sup> | number | false | false | 表示单次扫描的超时时间。单位是毫秒，默认值是10000毫秒，取值范围为大于0小于600000。 |  
    
## LocatingRequiredData<sup>(10+)</sup>    
表示定位业务所需的数据，包含WiFi或蓝牙扫描结果，APP拿到这些数据之后可以用于网络定位等业务。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| wifiData<sup>(10+)</sup> | WifiScanInfo | false | false | 表示WiFi扫描结果。 |  
| bluetoothData<sup>(10+)</sup> | BluetoothScanInfo | false | false | 表示蓝牙扫描结果。 |  
    
## WifiScanInfo<sup>(10+)</sup>    
WiFi扫描信息，包含扫描到的WiFi热点的ssid、bssid和rssi等信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ssid<sup>(10+)</sup> | string | false | true | WiFi热点的SSID，编码格式为UTF-8。 |  
| bssid<sup>(10+)</sup> | string | false | true | WiFi热点的BSSID。 |  
| rssi<sup>(10+)</sup> | number | false | true | WiFi热点的信号强度(dBm)。 |  
| frequency<sup>(10+)</sup> | number | false | true | WiFi热点的频率。 |  
| timestamp<sup>(10+)</sup> | number | false | true | 时间戳。 |  
    
## BluetoothScanInfo<sup>(10+)</sup>    
蓝牙扫描信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceName<sup>(10+)</sup> | string | false | true | 蓝牙设备名称。 |  
| macAddress<sup>(10+)</sup> | string | false | true | 蓝牙设备的MAC地址。 |  
| rssi<sup>(10+)</sup> | number | false | true | 蓝牙设备的信号强度(dBm)。 |  
| timestamp<sup>(10+)</sup> | number | false | true | 时间戳。 |  
    
## LocationPrivacyType    
定位服务隐私协议类型。    
    
 **系统能力:**  SystemCapability.Location.Location.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| OTHERS | 0 | 其他场景。预留字段。 |  
| STARTUP | 1 | 开机向导场景下的隐私协议。在开机时弹出协议，提醒用户阅读并选择是否授权。 |  
| CORE_LOCATION | 2 | 开启网络定位时弹出的隐私协议。 |  
    
## LocatingRequiredDataType<sup>(10+)</sup>    
定位业务所需数据的类型。    
    
 **系统能力:**  SystemCapability.Location.Location.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WIFI | 1 | 表示WiFi扫描信息。 |  
| BLUETOOTH | 2 | 表示蓝牙扫描信息。 |  
