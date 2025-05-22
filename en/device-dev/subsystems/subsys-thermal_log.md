# Thermal Log Customization

## Overview

### Introduction

By default, the OpenHarmony provides the thermal log feature. Thermal logs record the temperature of device components during usage. However, the content and path of thermal logs vary according to product specifications. To address this issue, OpenHarmony provides the thermal log customization function.

### Constraints

The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate thermal log customization.

1. Create the `thermal` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default thermal log configuration folder](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/interfaces/hdi_service/profile), and install it in `//vendor/hihope/rk3568/thermal`. The content is as follows:
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_hdi_config.xml
    ```

3. Create a target folder by referring to the [default thermal log parameter configuration folder](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/etc) and install it in `//vendor/hihope/rk3568/thermal`. The file format is as follows:
    ```text
    etc
    ├── BUILD.gn
    ├── thermal.para
    ├── thermal.para.dac
    ```

4. Write the custom `thermal_hdi_config.xml` file by referring to the [thermal_hdi_config.xml](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/thermal_hdi_config.xml) file in the default thermal log configuration folder. The following tables describe the related configuration items.

    **Table 1** Description of the tracing configuration

    | Configuration Item| Description| Data Type| Value Range|
    | -------- | -------- | -------- | -------- |
    | interval | Interval for recording temperature tracing logs, in ms.| int | >0 |
    | width | Width of the temperature tracing log, in characters.| int | >0 |
    | outpath | Path for storing temperature tracing logs.| string | N/A|

    **Table 2** Description of the node configuration

    | Node| Configuration Item| Description|
    | -------- | -------- | -------- |
    | title | path | Path for obtaining the thermal zone name.|
    | title | name | Thermal zone name.|
    | value | path | Path for obtaining the thermal zone temperature.|

    ```shell
    <tracing interval="5000" width="20" outpath="/data/log/thermal-log">
        <node>
            <title path="sys/class/thermal/thermal_zone0/type"/>
            <value path="sys/class/thermal/thermal_zone0/temp"/>
        </node>
        <node>
            <title name="gpu-thermal"/>   
            <value path="sys/class/thermal/thermal_zone1/temp"/>
        </node>
    </tracing>
    ```

5. Write the custom `thermal.para` and `thermal.para.dac` files by referring to the [thermal.para](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/etc/thermal.para) and [thermal.para.dac](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/etc/thermal.para.dac) files in the default hot log parameter configuration folder. The custom configuration is as follows:

    thermal.para:
    ```text
    persist.thermal.log.enable=true     # Enable the thermal log function.
    persist.thermal.log.interval=5000   # Set the interval for recording temperature tracing logs, in ms.
    persist.thermal.log.width=20        # Set the width of the temperature tracing log, in characters.
    ```

    thermal.para.dac:
    ```text
    persist.thermal.log.="power_host:power_host:600" # Configure access permissions.
    ```

6. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/BUILD.gn) file in the default thermal log configuration folder to pack the `thermal_hdi_config.xml` file to the `//vendor/etc/thermal_config/hdf` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")

    ohos_prebuilt_etc("thermal_hdf_config") {
        source = "thermal_hdi_config.xml"
        relative_install_dir = "thermal_config/hdf"
        install_images = [ chipset_base_dir ]       # Required configuration for installing the thermal_hdi_config.xml file in the vendor directory.
        part_name = "product_rk3568"                # Set part_name to product_rk3568 for subsequent build. You can change it as required.
    }
    ```

7. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/etc/BUILD.gn) file in the default thermal log parameter configuration folder to pack the `thermal.para` and `thermal.para.dac` files to the `//vendor/etc/param/thermal.para` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")

    ## Install thermal.para to /vendor/etc/param/thermal.para

    ohos_prebuilt_etc("thermal.para") {
        source = "thermal.para"
        relative_install_dir = "param"
        install_images = [ chipset_base_dir ]
        part_name = "product_rk3568"
    }

    ohos_prebuilt_etc("thermal.para.dac") {
        source = "thermal.para.dac"
        relative_install_dir = "param"
        install_images = [ chipset_base_dir ]
        part_name = "product_rk3568"
    }

    group("param_files") {
        deps = [
            ":thermal.para",
            ":thermal.para.dac",
        ]
    }
    ```

8. Add the build target to `module_list` in [ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build) in the `/vendor/hihope/rk3568` directory. For example:

    ```json
    {
        "parts": {
            "product_rk3568": {
                "module_list": [
                    "//vendor/hihope/rk3568/default_app_config:default_app_config",
                    "//vendor/hihope/rk3568/image_conf:custom_image_conf",
                    "//vendor/hihope/rk3568/preinstall-config:preinstall-config",
                    "//vendor/hihope/rk3568/resourceschedule:resourceschedule",
                    "//vendor/hihope/rk3568/etc:product_etc_conf",
                    "//vendor/hihope/rk3568/thermal/profile:thermal_hdf_config",  // Add the configuration for building of thermal_hdf_config.
                    "//vendor/hihope/rk3568/thermal/etc:param_files"              // Add the configuration for building of thermal.para and thermal.para.dac.
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    In the preceding code, `//vendor/hihope/rk3568/thermal/` is the folder path, `profile` and `etc` are folder names, and `thermal_hdf_config` and `param_files` are the build targets.

9. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

10. Burn the customized version to the DAYU200 development board.

### Debugging and Verification

1. After startup, run the following command to launch the shell command line:
    ```shell
    hdc shell
    ```
 
2. Go to the customized directory.
    ```shell
    cd /data/log/thermal/
    ```

    View thermal logs.
    ```shell
    cat thermal.000.20170805-175756
    ```

    The following is the reference thermal log after customization:
    ```shell
    timestamp                    soc-thermal         gpu-thermal
    2017-08-05 17:57:56          37777               37222
    2017-08-05 17:58:01          38333               37777
    2017-08-05 17:58:06          36666               37222
    2017-08-05 17:58:11          36666               37222
    2017-08-05 17:58:16          36666               37222
    2017-08-05 17:58:21          36111               37222
    2017-08-05 17:58:26          36111               37222
    2017-08-05 17:58:31          36666               37222
    2017-08-05 17:58:36          36111               37222
    2017-08-05 17:58:41          36111               37222
    2017-08-05 17:58:46          36666               36666
    ```

## Reference
During development, you can refer to the [default thermal log configuration](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/interfaces/hdi_service/profile/) and [default thermal log parameter configuration](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/etc).

Packing path: `/vendor/etc/thermal_config/hdf`
