# @ohos.ability.featureAbility    
FeatureAbility模块提供与用户进行交互的Ability的能力，包括启动新的Ability、停止Ability、获取dataAbilityHelper对象、获取当前Ability对应的窗口，连接断连Service等。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import featureAbility from '@ohos.ability.featureAbility'    
```  
    
## getWant    
获取要拉起的Ability对应的Want  
 **调用形式：**     
    
- getWant(callback: AsyncCallback\<Want>): void    
起始版本： 6    
- getWant(): Promise\<Want>    
起始版本： 6  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback的形式返回want。 |  
| Promise<Want> | 以Promise的形式返回want。 |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
featureAbility.getWant((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getWant fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getWant success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
## startAbility    
启动新的Ability。  
 **调用形式：**     
    
- startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<number>): void    
起始版本： 6    
- startAbility(parameter: StartAbilityParameter): Promise\<number>    
起始版本： 6  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | StartAbilityParameter | true | 表示被启动的Ability。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback的形式返回启动Ability的结果。 |  
| Promise<number> |  |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
import wantConstant from '@ohos.app.ability.wantConstant';  
featureAbility.startAbility(  
    {  
        want:  
        {  
            action: '',  
            entities: [''],  
            type: '',  
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,  
            deviceId: '',  
            bundleName: 'com.example.myapplication',  
            /* FA模型中abilityName由package + Ability name组成 */  
            abilityName: 'com.example.myapplication.secondAbility',  
            uri: ''  
        },  
    },  
    (error, data) => {  
        if (error  error.code !== 0) {  
            console.error(`startAbility fail, error: ${JSON.stringify(error)}`);  
        } else {  
            console.log(`startAbility success, data: ${JSON.stringify(data)}`);  
        }  
    }  
);  
    
```    
  
    
## getContext    
获取应用上下文。  
 **调用形式：**     
- getContext(): Context  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Context | 返回应用程序上下文。 |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context = featureAbility.getContext();  
context.getBundleName((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getBundleName fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getBundleName success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
## startAbilityForResult<sup>(7+)</sup>    
启动一个Ability。Ability被启动后，有如下情况(callback形式):  - 正常情况下可通过调用[terminateSelfWithResult](#featureabilityterminateselfwithresult7)接口使之终止并且返回结果给调用方。  - 异常情况下比如杀死Ability会返回异常信息给调用方, 异常信息中resultCode为-1。  - 如果被启动的Ability模式是单实例模式, 不同应用多次调用该接口启动这个Ability，当这个Ability调用[terminateSelfWithResult](#featureabilityterminateselfwithresult7)接口使之终止时，只将正常结果返回给最后一个调用方, 其它调用方返回异常信息, 异常信息中resultCode为-1。  使用规则：  - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限  - 跨应用场景下，目标Ability的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限  - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)  
 **调用形式：**     
    
- startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback\<AbilityResult>): void    
起始版本： 7    
- startAbilityForResult(parameter: StartAbilityParameter): Promise\<AbilityResult>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | StartAbilityParameter | true | 表示被启动的Ability。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback的形式返回启动Ability结果。 |  
| Promise<AbilityResult> |  |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
import wantConstant from '@ohos.app.ability.wantConstant';  
featureAbility.startAbilityForResult(  
   {  
        want:  
        {  
            action: 'ohos.want.action.home',  
            entities: ['entity.system.home'],  
            type: 'MIMETYPE',  
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,  
            deviceId: '',  
            bundleName: 'com.example.myapplication',  
            /* FA模型中abilityName由package + Ability name组成 */  
            abilityName: 'com.example.myapplication.secondAbility',  
            uri:''  
        },  
    },  
    (error, data) => {  
        if (error  error.code !== 0) {  
            console.error(`startAbilityForResult fail, error: ${JSON.stringify(error)}`);  
        } else {  
            console.log(`startAbilityForResult success, data: ${JSON.stringify(data)}`);  
        }  
    }  
);  
    
```    
  
    
## terminateSelfWithResult<sup>(7+)</sup>    
停止当前的Ability。如果该Ability是通过调用[startAbilityForResult](#featureabilitystartabilityforresult7)接口被拉起的，调用terminateSelfWithResult接口时会将结果返回给调用者，如果该Ability不是通过调用[startAbilityForResult](#featureabilitystartabilityforresult7)接口被拉起的，调用terminateSelfWithResult接口时不会有结果返回给调用者（Promise形式）。  
 **调用形式：**     
    
- terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>): void    
起始版本： 7    
- terminateSelfWithResult(parameter: AbilityResult): Promise\<void>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | AbilityResult | true | 表示停止Ability之后返回的结果 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | 以Promise形式返回停止当前Ability结果。 |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';import wantConstant from '@ohos.app.ability.wantConstant';featureAbility.terminateSelfWithResult(    {        resultCode: 1,        want:        {            action: 'ohos.want.action.home',            entities: ['entity.system.home'],            type: 'MIMETYPE',            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,            deviceId: '',            bundleName: 'com.example.myapplication',            /* FA模型中abilityName由package + Ability name组成 */            abilityName: 'com.example.myapplication.secondAbility',            uri:'',            parameters: {                mykey0: 2222,                mykey1: [1, 2, 3],                mykey2: '[1, 2, 3]',                mykey3: 'ssssssssssssssssssssssssss',                mykey4: [1, 15],                mykey5: [false, true, false],                mykey6: ['qqqqq', 'wwwwww', 'aaaaaaaaaaaaaaaaa'],                mykey7: true,            }        },    }).then((data) => {    console.info('==========================>terminateSelfWithResult=======================>');});    
```    
  
    
## terminateSelf<sup>(7+)</sup>    
停止当前的Ability（Promise形式）。  
 **调用形式：**     
    
- terminateSelf(callback: AsyncCallback\<void>): void    
起始版本： 7    
- terminateSelf(): Promise\<void>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | 以Promise的形式返回停止当前Ability结果。 |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';featureAbility.terminateSelf(    (error) => {        console.error(`error: ${JSON.stringify(error)}`);    })    
```    
  
    
## acquireDataAbilityHelper<sup>(7+)</sup>    
获取dataAbilityHelper对象。  
 **调用形式：**     
- acquireDataAbilityHelper(uri: string): DataAbilityHelper  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示要打开的文件的路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityHelper | 用来协助其他Ability访问DataAbility的工具类。 |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';let dataAbilityHelper = featureAbility.acquireDataAbilityHelper(    'dataability:///com.example.DataAbility');    
```    
  
    
## hasWindowFocus<sup>(7+)</sup>    
检查Ability的主窗口是否具有窗口焦点（callback形式）。  
 **调用形式：**     
    
- hasWindowFocus(callback: AsyncCallback\<boolean>): void    
起始版本： 7    
- hasWindowFocus(): Promise\<boolean>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback的形式返回结果。<br>如果此Ability当前具有视窗焦点，则返回true；否则返回false。 |  
| Promise<boolean> |  |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
featureAbility.hasWindowFocus((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`hasWindowFocus fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`hasWindowFocus success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
## connectAbility<sup>(7+)</sup>    
将当前Ability与指定的ServiceAbility进行连接。  
 **调用形式：**     
- connectAbility(request: Want, options: ConnectOptions): number  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | Want | true | 表示被连接的ServiceAbility。 |  
| options | ConnectOptions | true | 表示连接回调函数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 连接的ServiceAbility的ID(ID从0开始自增，每连接成功一次ID加1)。 |  
    
 **示例代码：**   
```ts    
import rpc from '@ohos.rpc';import featureAbility from '@ohos.ability.featureAbility';  
let connectId = featureAbility.connectAbility(    {        deviceId: '',        bundleName: 'com.ix.ServiceAbility',        abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',    },    {        onConnect: (element, remote) => {            console.log('ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}');        },        onDisconnect: (element) => {            console.log('ConnectAbility onDisconnect element.deviceId : ${element.deviceId}')        },        onFailed: (code) => {            console.error('featureAbilityTest ConnectAbility onFailed errCode : ${code}')        },    },);    
```    
  
    
## disconnectAbility<sup>(7+)</sup>    
断开与指定ServiceAbility的连接（callback形式）。  
 **调用形式：**     
    
- disconnectAbility(connection: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- disconnectAbility(connection: number): Promise\<void>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| connection | number | true | 表示断开连接的ServiceAbility的ID |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import rpc from '@ohos.rpc';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let connectId = featureAbility.connectAbility(  
    {  
        bundleName: 'com.ix.ServiceAbility',  
        abilityName: 'com.ix.ServiceAbility.ServiceAbilityA',  
    },  
    {  
        onConnect: (element, remote) => {  
            console.log('ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}');  
        },  
        onDisconnect: (element) => {  
            console.log('ConnectAbility onDisconnect element.deviceId : ${element.deviceId}');  
        },  
        onFailed: (code) => {  
            console.error('featureAbilityTest ConnectAbility onFailed errCode : ${code}');  
        },  
    },  
);  
  
featureAbility.disconnectAbility(connectId, (error) => {  
    if (error  error.code !== 0) {  
        console.error(`disconnectAbility fail, connectId: ${connectId}, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`disconnectAbility success， connectId: ${connectId}`);  
    }  
});  
    
```    
  
    
## getWindow<sup>(7+)</sup>    
获取当前Ability对应的窗口（callback形式）。  
 **调用形式：**     
    
- getWindow(callback: AsyncCallback\<window.Window>): void    
起始版本： 7    
- getWindow(): Promise\<window.Window>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回当前Ability对应的窗口。 |  
| Promise<window.Window> |  |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
import { BusinessError } from '@ohos.base';  
import window from '@ohos.window';  
  
featureAbility.getWindow((error: BusinessError, data: window.Window) => {  
    if (error  error.code !== 0) {  
        console.error(`getWindow fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getWindow success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
## AbilityWindowConfiguration<sup>(7+)</sup>    
表示当前Ability对应的窗口配置项，使用时通过featureAbility.AbilityWindowConfiguration获取。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WINDOW_MODE_UNDEFINED | 0 | 未定义。 |  
| WINDOW_MODE_FULLSCREEN | 1 | 全屏。 |  
| WINDOW_MODE_SPLIT_PRIMARY | 100 | 屏幕如果是水平方向表示左分屏，屏幕如果是竖直方向表示上分屏。 |  
| WINDOW_MODE_SPLIT_SECONDARY | 101 | 屏幕如果是水平方向表示右分屏，屏幕如果是竖直方向表示下分屏。 |  
| WINDOW_MODE_FLOATING | 102 | 悬浮窗。 |  
    
## AbilityStartSetting<sup>(7+)</sup>    
表示当前Ability对应的窗口属性，abilityStartSetting属性是一个定义为[key: string]: any的对象，key对应设定类型为：AbilityStartSetting枚举类型，value对应设定类型为：AbilityWindowConfiguration枚举类型。  
  
使用时通过featureAbility.AbilityStartSetting获取。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BOUNDS_KEY | abilityBounds | 窗口显示大小属性的参数名。 |  
| WINDOW_MODE_KEY | windowMode | 窗口显示模式属性的参数名。 |  
| DISPLAY_ID_KEY | displayId | 窗口显示设备ID属性的参数名。 |  
    
## ErrorCode<sup>(7+)</sup>    
表示错误码。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NO_ERROR | 0 | 没有错误。 |  
| INVALID_PARAMETER | -1 | 无效的参数。 |  
| ABILITY_NOT_FOUND | -2 | 找不到ABILITY。  |  
| PERMISSION_DENY | -3 | 权限拒绝。  |  
    
## DataAbilityOperationType<sup>(7+)</sup>    
表示数据的操作类型。DataAbility批量操作数据时可以通过该枚举值指定操作类型。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_INSERT | 1 | 插入类型。 |  
| TYPE_UPDATE | 2 |  修改类型。 |  
| TYPE_DELETE | 3 | 删除类型。 |  
| TYPE_ASSERT | 4 | 声明类型。 |  
