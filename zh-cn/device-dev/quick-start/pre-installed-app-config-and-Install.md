# 预置应用配置与安装指导

预置应用是指随OpenHarmony系统出厂预置的应用。

本文介绍开发者如何将一个非预置应用配置为预置应用，以及已有预置应用更新后如何重新安装。

## 将非预置应用配置为预置应用。

1. 确定预置应用支持的路径，可以通过下述命令查询。本文将以路径/system/etc/app/为例。

```
hdc_std param get const.cust.config_dir_layer
```

2. 在install_list.json中配置hap在设备上的路径。

```
hdc_std shell mount -o rw,renount /
hdc_std file recv /system/etc/app/install_list.json .
```

3. 按照json中的配置方式，配置对应的字段。

```
{
    "app_dir":"system/app/xxxx/yyyy",  // 设备上的hap路径，如果不存在，需要手动创建，并推送hap到此目录。
    "removable":true // 是否支持卸载，false表示不可卸载，true表示可以卸载。
}
```

4. 修改完成后，将install_list.json文件推送到设备上，并重启设备生效。

```
    hdc_std shell mount -o rw,remount /
    hdc_std file send install_list.json /system/etc/app/install_list.json
    hdc_std shell reboot
```

## 重新安装更新后的已有预置应用

有两种方法。

- 方法一：直接清空data，重启设备，应用会自动安装。

```
    hdc_std shell mount -o rw,remount / 
    hdc_std shell rm /data/* -rf
    hdc_std shell sync
    hdc_std shell /system/bin/udevadm trigger
    hdc_std shell reboot
```
- 方法二：如果该应用之前没有安装过，则可以执行下面命令后重启设备。

```
    hdc_std shell mount -o rw,remount /
    hdc_std shell param set persist.bms.test-upgrade true
    hdc_std shell reboot
```

如果应用之前已经安装过，这时继续推送新的hap到/system/app/的路径下，则需要保证应用的版本号，分为[Stage模型的版本号（versionCode）](https://gitee.com/openharmony/docs/blob/5ed63aa268e4a16aefe6fb569000735d7cf1e888b1/zh-cn/application-dev/qucik-start/app-configuration-file.md)，[FA模型的版本号（code）](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/app-structure.md#version对象内部结构)比之前的大。 这时执行方法二的命令，重启后应用同样可以正常安装。需要注意的是方法二命令，不需要反复执行， 重启之后依然生效。