# @ohos.deviceInfo (设备信息)

本模块提供产品信息。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 部分参数返回值为default的，会在正式发布的版本中配置。

## 导入模块

```ts
import deviceInfo from '@ohos.deviceInfo';
```

## 属性

**系统能力**：SystemCapability.Startup.SystemInfo。

**权限**：以下各项所需要的权限有所不同，详见下表。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceType | string | 是 | 否 | 设备类型。 |
| brand | string | 是 | 否 | 设备品牌名称。 |
| productModel | string | 是 | 否 | 认证型号。 |
| osFullName | string | 是 | 否 | 系统版本。 |

**示例**

```ts
    import deviceinfo from '@ohos.deviceInfo';

    let deviceTypeInfo: string = deviceinfo.deviceType;
    console.info('the value of the deviceType is :' + deviceTypeInfo);

    let brandInfo: string = deviceinfo.brand;
    console.info('the value of the device brand is :' + brandInfo);

    let productModelInfo: string = deviceinfo.productModel;
    console.info('the value of the deviceinfo productModel is :' + productModelInfo);

    let osFullNameInfo: string = deviceinfo.osFullName;
    console.info('the value of the deviceinfo osFullName is :' + osFullNameInfo);

```
