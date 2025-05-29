# 电池读写内核节点通用框架开发指导 

## 概述 

### 简介 

OpenHarmony支持在不同设备上多种充电特性进行差异化配置，为此OpenHarmony提供了读写电池内核节点的通用框架：根据充电场景读取内核节点来获取特性详情，根据充电场景写入内核节点来开启或进入特性。系统开发者可根据产品的设计规格进行相应的配置，并通过系统API的进行管控。

### 约束与限制

无

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以RK3568开发板为例，介绍如何实现配置。

1. 修改[drivers_peripheral/battery/interfaces/hdi_service/profile](https://gitee.com/openharmony/drivers_peripheral/tree/master/battery/interfaces/hdi_service/profile)路径下的电池配置文件battery_config.json。

```text
profile
├── BUILD.gn
├── battery_config.json
```

以如下配置为例：

```json
{
    // 原有配置，新增配置在该条配置后增加
    "charger": {
        ..... // 省略内容
    }, 
    // 新增配置，注意不要遗漏上一行结尾的逗号
	"charge_scene": {
        "scene_name": {
            "support": {
                "path": "",
                "type": "",
                "expect_value": ""
            },
            "get": {
                "path": ""
            },
            "set": {
                "path": ""
            }
        }
    } 
}
```

配置说明：

- charger：原有配置，新增配置在该条配置后增加。

- charge_scene：新增配置，充电场景配置标识符，不可更改。

- scene_name：充电场景名称，每个充电场景可以配置support、get、set三条属性。可以修改场景名称，但需要与系统API接口请求中场景名称保持一致；可以增加新的场景。

- support：充电场景的支持属性，path为其默认存在的属性，表示充电场景对应的支持查询的内核节点路径。除外还支持type和expect_value两个属性：

  ​- type：充电场景的内核节点路径的类型，必填字段，只能填充dir/file。dir：表示内核节点路径为目录或者文件；file：表示内核节点路径为文件。

  ​- expect_value：type为file时，支持该充电场景的预期值。

- get：充电场景的查询属性，path为其默认存在的属性，表示充电场景对应的查询内核节点路径。

- set：充电场景的设置属性，path为其默认存在的属性，表示充电场景对应的设置内核节点路径。

2. 修改[interface_sdk-js/api](https://gitee.com/openharmony/interface_sdk-js/tree/master/api)路径下的api文件@ohos.batteryInfo.d.ts。

```
profile
├── ...
├── @ohos.base.d.ts
├── @ohos.batteryInfo.d.ts
├── @ohos.batteryStatistics.d.ts
├── ...
```

系统API接口配置如下：

```
... // 省略内容

declare namespace chargeScene {
  /**
   * Sets the battery config by scene name.
   *
   * @param { string } sceneName - Indicates the battery charging scene name.
   * @param { string } sceneValue - Indicates the battery charging scene value.
   * @returns { number } Return to set the charging configuration result.
   * @throws { BusinessError } 201 - If the permission is denied.
   * @throws { BusinessError } 202 - If the system permission is denied.
   * @throws { BusinessError } 401 - If the reason is not valid.
   * @throws { BusinessError } 4900101 - If connecting to the service failed.
   * @syscap SystemCapability.PowerManager.BatteryManager.Core
   * @systemapi
   * @since 11
   */
  function setBatteryConfig(sceneName: string, sceneValue: string): number;

  /**
   * Queries the battery config by scene name.
   *
   * @param { string } sceneName - Indicates the battery charging scene name.
   * @returns { string } Returns the battery charging configuration, returns "" otherwise.
   * @throws { BusinessError } 201 - If the permission is denied.
   * @throws { BusinessError } 202 - If the system permission is denied.
   * @throws { BusinessError } 401 - If the reason is not valid.
   * @throws { BusinessError } 4900101 - If connecting to the service failed.
   * @syscap SystemCapability.PowerManager.BatteryManager.Core
   * @systemapi
   * @since 11
   */
  function getBatteryConfig(sceneName: string): string;

  /**
   * Checks the battery config is enable by scene name.
   *
   * @param { string } sceneName - Indicates the battery charging scene name.
   * @returns { boolean } Returns true if the device supports the charging scene, returns false otherwise.
   * @throws { BusinessError } 201 - If the permission is denied.
   * @throws { BusinessError } 202 - If the system permission is denied.
   * @throws { BusinessError } 401 - If the reason is not valid.
   * @throws { BusinessError } 4900101 - If connecting to the service failed.
   * @syscap SystemCapability.PowerManager.BatteryManager.Core
   * @systemapi
   * @since 11
   */
  function isBatteryConfigSupported(sceneName: string): boolean;

... // 省略内容
```

系统API说明：

- setBatteryConfig：设置电池配置，sceneName表示充电场景名称，sceneValue表示充电场景配置值，返回值为0表示设置成功，其他表示设置失败。

- getBatteryConfig：查询电池配置，sceneName表示充电场景名称，返回值表示充电场景配置值。

- isBatteryConfigSupported：是否支持电池配置，sceneName表示充电场景名称，返回值为true表示支持该充电场景，返回值为false表示不支持该充电场景。

3. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

```shell
./build.sh --product-name rk3568 --ccache
```

4. 将定制版本烧录到RK3568开发板中。

### 调测验证 

烧录版本后重启设备，验证TS接口查询/设置结果是否符合设备配置情况，符合则功能测试成功。

## 参考 

开发过程中可参考的配置文件路径：

[电池充电场景配置文件路径](https://gitee.com/openharmony/drivers_peripheral/tree/master/battery/interfaces/hdi_service/profile)