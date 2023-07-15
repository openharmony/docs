# 热日志定制开发指导

## 概述 

### 简介 

OpenHarmony默认提供了热日志的特性。热日志是设备器件在使用过程中温度的流水日志。由于热日志输出的内容和路径在不同的产品上规格是不同的，产品希望根据产品的设计规格来定制此特性。OpenHarmony提供了热日志的定制方式，产品定制开发者可根据产品的设计规格来定制这些特性。

### 约束与限制

产品定制的配置路径，需要根据[配置策略](https://gitee.com/openharmony/customization_config_policy)决定。本开发指导中的定制路径以`/vendor`进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍热日志的定制方法。

1. 在产品目录[（/vendor/hihope/rk3568）](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建thermal文件夹。

2. 参考[默认热日志的配置文件夹](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/interfaces/hdi_service/profile)创建目标文件夹，并安装到`//vendor/hihope/rk3568/thermal`，文件格式如下：
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_hdi_config.xml
    ```

3. 参考[默认热日志的参数配置文件夹](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/etc)创建目标文件夹，并安装到`//vendor/hihope/rk3568/thermal`，文件格式如下：
    ```text
    etc
    ├── BUILD.gn
    ├── thermal.para
    ├── thermal.para.dac
    ```

4. 参考[默认热日志的配置文件夹中的thermal_hdi_config.xml](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/thermal_hdi_config.xml)编写定制的thermal_hdi_config.xml。包含热日志配置说明及定制后的热日志配置如下：

    **表1** tracing配置说明

    | 配置项名称 | 配置项描述 | 数据类型 | 取值范围 |
    | -------- | -------- | -------- | -------- |
    | outpath | 温度跟踪日志输出的路径 | string | 无 |

    **表2** node配置说明

    | 节点名称 | 配置项名称 | 配置项描述 |
    | -------- | -------- | -------- |
    | title | path | 获取thermal zone名称的路径 |
    | title | name | thermal zone名称 |
    | value | path | 获取thermal zone温度的路径 |

    ```shell
    <tracing outpath="/data/log/thermal-log">
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

5. 参考默认热日志的参数配置文件夹中的[thermal.para](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/etc/thermal.para)和[thermal.para.dac](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/etc/thermal.para.dac)编写定制的thermal.para和thermal.para.dac。包含定制后的配置如下：

    thermal.para：
    ```text
    persist.thermal.log.enable=true     # 打开thermal log
    persist.thermal.log.interval=5000   # 温度跟踪日志的时间间隔，单位为毫秒
    persist.thermal.log.width=20        # 温度跟踪日志的宽度，单位为字符
    ```

    thermal.para.dac：
    ```text
    persist.thermal.log.="power_host:power_host:500" # 控制访问权限
    ```

6. 参考[默认热日志配置文件夹中的BUILD.gn](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/BUILD.gn)编写BUILD.gn文件，将thermal_hdi_config.xml打包到`//vendor/etc/thermal_config/hdf`目录下：

    ```shell
    import("//build/ohos.gni")

    ohos_prebuilt_etc("thermal_hdf_config") {
        source = "thermal_hdi_config.xml"
        relative_install_dir = "thermal_config/hdf"
        install_images = [ chipset_base_dir ]       # 安装到vendor目录下的必要配置
        part_name = "product_rk3568"                # part_name暂定为product_rk3568，以实现后续编译，产品定制根据需要自行修改
    }
    ```

7. 参考[默认热日志的参数配置文件夹的BUILD.gn](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/etc/BUILD.gn)编写BUILD.gn文件，将thermal.para和thermal.para.dac打包到`//vendor/etc/param/thermal.para`目录下

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

8. 将编译目标添加到[ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build)的"module_list"中，例如：

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
                    "//vendor/hihope/rk3568/thermal/profile:thermal_hdf_config",  // 添加thermal_hdf_config的编译
                    "//vendor/hihope/rk3568/thermal/etc:param_files"              // 添加thermal.para和thermal.para.dac的编译
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    “//vendor/hihope/rk3568/thermal/”为文件夹路径，“profile”、“etc”为创建的文件夹名字，“thermal_hdf_config”、“param_files”为编译目标。

9. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

10. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

1. 开机后，进入shell命令行：
    ```shell
    hdc shell
    ```
 
2. 进入定制后的目录。
    ```shell
    cd /data/log/thermal/
    ```

    查看热日志。
    ```shell
    cat thermal.000.20170805-175756
    ```

    成功获取热日志内容
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

## 参考 
开发过程中可参考的配置文件路径：[默认热日志的配置源码路径](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/interfaces/hdi_service/profile/) 和[默认热日志的参数配置源码路径](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/etc)

打包路径：`/vendor/etc/thermal_config/hdf`


