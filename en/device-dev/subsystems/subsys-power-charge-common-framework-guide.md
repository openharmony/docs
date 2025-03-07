# General Framework for Battery Kernel Node Read/Write

## Overview

### Introduction

OpenHarmony supports differentiated configuration of charging features on different devices and therefore provides a general framework for reading and writing the battery kernel node. Specifically, OpenHarmony reads the kernel node based on the charging scenario to obtain the charging feature and then writes data to the kernel node to enable or start the feature. You can configure charging features based on the product specifications and manage the features through system APIs.

### Constraints

N/A

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate development of the general framework for reading/writing the battery kernel node.

1. Modify the `battery_config.json` file in [default battery service configuration folder](https://gitee.com/openharmony/drivers_peripheral/tree/master/battery/interfaces/hdi_service/profile). The configuration is as follows:

```text
profile
├── BUILD.gn
├── battery_config.json
```

Example configuration:

```json
{
    // Add the new configuration after the original configuration.
    "charger": {
        ..... // Content omitted.
    }, 
    // Add the new configuration. Do not omit the comma at the end of the previous line.
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

Configuration description:

- **charger**: original configuration. Add the new configuration after this configuration.

- **charge_scene**: new configuration. It is the identifier of the charging scenario and cannot be changed.

- **scene_name**: charging scenario. The **support**, **get**, and **set** attributes can be configured for each charging scenario. You can change the scenario name, but make sure that it must be the same as that in the system API request. You can also add a charging scenario.

- **support**: whether the charging scenario is supported. **path** is the default attribute, which specifies the path of the kernel node that can be queried in the charging scenario. In addition, the **type** and **expect_value** attributes are supported.

  ​- **type**: type of the kernel node path in the charging scenario. This field is mandatory and can only be set to **dir/file**. **dir** indicates that the kernel node path is a directory or file, and **file** indicates that the kernel node path is a file.

  ​- **expect_value**: expected value that supports the charging scenario when type is set to **file**.

- **get**: getter attribute of the charging scenario. **path** is the default attribute, which specifies the path of the kernel node that can be queried in the charging scenario.

- **set**: setter attribute of the charging scenario. **path** is the default attribute, which specifies the path of the kernel node that can be set in the charging scenario.

2. Modify the API file `@ohos.batteryInfo.d.ts` in [interface_sdk-js/api](https://gitee.com/openharmony/interface_sdk-js/tree/master/api).

```
profile
├── ...
├── @ohos.base.d.ts
├── @ohos.batteryInfo.d.ts
├── @ohos.batteryStatistics.d.ts
├── ...
```

The system API configuration is as follows:

```
..... // Content omitted.

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

..... // Content omitted.
```

System API description:

- **setBatteryConfig**: Sets the battery configuration. **sceneName** and **sceneValue** indicates the name and value of the charging scenario, respectively. If the return result is **0**, the operation is successful. Otherwise, the operation fails.

- **getBatteryConfig**: Queries the battery configuration. **sceneName** indicates the name of the charging scenario. The returned value indicates the value of the charging scenario.

- **isBatteryConfigSupported**: Checks whether the battery configuration is supported. **sceneName** indicates the name of the charging scenario. If the return result is **true**, the charging scenario is supported. If the return result is **false**, the charging scenario is not supported.

3. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

```shell
./build.sh --product-name rk3568 --ccache
```

4. Burn the customized version to the RK3568 development board.

### Debugging and Verification

Upon device restarting, check whether the return results of the getter and setter APIs comply with the device configuration. If yes, the function test is successful.

## Reference

During development, you can refer to the default battery vibrator configuration:

[Configuration file of the battery charging scenario](https://gitee.com/openharmony/drivers_peripheral/tree/master/battery/interfaces/hdi_service/profile)
