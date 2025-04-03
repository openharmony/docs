# uevent事件定制开发指导 

## 概述 

### 简介 

OpenHarmony默认电池管理系统可以接收uevent事件，系统根据事件，对设备进行相应的动作，产品定制开发者可根据产品设计规格来定制。定制时采用修改配置文件的方式，实现根据配置文件有选择的接收uevent事件，并且设备触发相应的动作。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以RK3568开发板为例，介绍uevent事件的定制方法。

1. 修改[HDI层电池服务配置文件夹中的battery_config.json](https://gitee.com/openharmony/drivers_peripheral/tree/master/battery/interfaces/hdi_service/profile)与[service层电池服务配置文件夹中的battery_config.json](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile)定制后的uevent事件配置如下：

    ```json
    {
        "uevent": {
            "SUBSYSTEM=hw_power": {
                "BATTERY_UNDER_VOLTAGE=1": "shutdown",
                "BATTERY_UNDER_CURRENT=2": "reboot",
                "BATTERY_UNDER_VOLTAGE=3": "sendcommonevent"
            }
        }
    }
    ``` 

    **表1** uevent事件所属子系统说明

    | 所属子系统 | 描述 |
    | -------- | -------- |
    | SUBSYSTEM=hw_power | 所属子系统为hw_power|

    **表2** uevent事件说明

    | uevent事件 | 描述 |
    | -------- | -------- |
    | BATTERY_UNDER_VOLTAGE=1 | uevent事件(支持正则表达式) 电池电压小于1 |
    | BATTERY_UNDER_CURRENT=2 | uevent事件(支持正则表达式) 电池电流小于2 |
    | BATTERY_UNDER_VOLTAGE=3 | uevent事件(支持正则表达式) 电池电压小于3|

    **表3** 动作配置说明

    | 动作 | 类型 | 描述 |
    | -------- | -------- | -------- |
    | shutdown | string | 关机 |
    | reboot | string | 重启 |
    | sendcommonevent | string | 发送广播 |

2. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

3. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

1. 更改[uevent接收代码](https://gitee.com/openharmony/drivers_peripheral/blob/master/battery/interfaces/hdi_service/src/battery_thread.cpp),强制接收配置文件中的uevent事件BATTERY_UNDER_VOLTAGE=1：
   ```c++
    void BatteryThread::UeventCallback(void* service)
    {
        char msg[UEVENT_MSG_LEN + UEVENT_RESERVED_SIZE] = { 0 };

        ssize_t len = recv(ueventFd_, msg, UEVENT_MSG_LEN, 0);
        if (len < 0 || len >= UEVENT_MSG_LEN) {
            BATTERY_HILOGI(COMP_HDI, "recv return msg is invalid, len: %{public}zd", len);
            return;
        }

        // msg separator
        msg[len] = '\0';
        msg[len + 1] = '\0';

        std::string powerUevent;
        if (!MatchPowerUevent(msg, powerUevent)) {
            return;
        }
        powerUevent = "BATTERY_UNDER_VOLTAGE=1";
        BATTERY_HILOGI(FEATURE_BATT_INFO, "PowerUevent msg:%{public}s",
        powerUevent.c_str());
        UpdateBatteryInfo(service, powerUevent);
    }
    ```
2. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

3. 将定制版本烧录到DAYU200开发板中。
4. 设备启动后接收到uevent时关机。
    
## 参考 
开发过程中可参考的配置文件路径：[uevent事件配置源码路径](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile/) 

默认配置：

```json
{
    "uevent": {
        "SUBSYSTEM=hw_power": {
            "BATTERY_UNDER_VOLTAGE=1": "shutdown",
            "BATTERY_UNDER_VOLTAGE=2": "reboot",
            "BATTERY_UNDER_VOLTAGE=3": "sendcommonevent"
        }
    }
}
``` 

打包路径：/system/etc/battery
