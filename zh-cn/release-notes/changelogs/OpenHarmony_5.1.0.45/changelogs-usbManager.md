# USB服务子系统Changelog

## cl.usbManager.1 @ohos.usbManager 当系统应用未添加ohos.permission.MANAGE_USB_CONFIG权限时调用系统API接口返回错误码从202变更为201

**访问级别**

系统接口。

**变更原因**

当调用系统API接口时：系统应用配置文件中的permission字段需要添加ohos.permission.MANAGE_USB_CONFIG权限才可以有权限访问系统API接口，如果未配置权限需要返回201错误码。

**变更影响**

该变更为不兼容变更。

举例说明，执行以下用例：

```ts
import { usbManager } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let devicesName: string = "1-1";
let tokenId: string = "";

  try {
    let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
    bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo) => {
      console.info('testTag', 'getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(bundleInfo));
      let token = bundleInfo.appInfo.accessTokenId;
      tokenId = token.toString();
      if (usbManager.addDeviceAccessRight(tokenId, devicesName)) {
        console.log(`Succeed in adding right`);
      }
    }).catch((err : BusinessError) => {
      console.error('testTag getBundleInfoForSelf failed' );
    });
  } catch (err) {
    console.error('testTag failed');
  }
```

变更前：系统应用未在配置文件中的permission字段添加ohos.permission.MANAGE_USB_CONFIG权限时，调用系统API接口返回202错误码。

变更后：系统应用未在配置文件中的permission字段添加ohos.permission.MANAGE_USB_CONFIG权限时，调用系统API接口返回201错误码。

**起始 API Level**

12

**变更-新增发生的版本**

从OpenHarmony SDK 5.1.0.45开始。

**新增错误码的接口/组件**

|            接口声明            |               新增说明               |
| :----------------------------: | :----------------------------------: |
| addDeviceAccessRight(tokenId: string, deviceName: string): boolean | 新增201错误码 | 
| getFunctionsFromString(funcs: string): number | 新增201错误码 |
| getStringFromFunctions(funcs: FunctionType): string | 新增201错误码 |
| setDeviceFunctions(funcs: FunctionType): Promise\<void> | 新增201错误码 |
| getDeviceFunctions(): FunctionType | 新增201错误码 |
| getPortList(): Array\<USBPort> | 新增201错误码 |
| getPortSupportModes(portId: number): PortModeType | 新增201错误码 |
| setPortRoleTypes(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void> | 新增201错误码 |


**适配指导**

开发者需将使用@ohos.usbManager模块新增错误码的系统接口调用的地方适配新增201错误码提示。