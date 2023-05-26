# 预置应用配置与安装指导

预置应用是指随设备出厂预置的应用。OpenHarmony支持在不同设备上对预置应用进行差异化配置，设备厂商可根据需要对与预置应用进行配置。

## 将应用配置为预置应用

1. 在进行预置应用配置前，使用如下命令查询系统支持的预置目录。
   
   命令查询结果如system、chipset、sys_prod、chip_prod等，并且返回的顺序越靠后优先级越高，如chip_prod的优先级高于system的优先级。本文以路径/system/etc/app/为例。

```
hdc shell param get const.cust.config_dir_layer
```

2. 在install_list.json中配置hap在设备上的路径。

```
hdc shell mount -o rw,remount /
hdc file recv /system/etc/app/install_list.json .
```

3. 按照json中的配置方式，配置对应的字段。

```
{
    "install_list" : [
        {
            "app_dir":"system/app/xxxx/yyyy",  // 设备上的hap路径，如果不存在，需要手动创建，并推送hap到此目录。
            "removable":true // 是否支持卸载，false表示不可卸载，true表示可以卸载。
        }
    ]
}
```

4. 修改完成后，将install_list.json文件推送到设备上，并重启设备生效。

```
    hdc shell mount -o rw,remount /
    hdc file send install_list.json /system/etc/app/install_list.json
    hdc shell reboot
```

## 更新预置应用

预置应用更新后，使用如下方法重新安装。

- 方法一：直接清空data，重启设备，应用会自动安装。

```
    hdc shell mount -o rw,remount / 
    hdc shell rm /data/* -rf
    hdc shell sync
    hdc shell /system/bin/udevadm trigger
    hdc shell reboot
```
- 方法二：执行如下命令，重启设备，应用即可安装。

    如果应用之前已经安装过，这时推送新的hap到/system/app/路径下，需保证应用的版本号（Stage模型下对应app.json5配置文件中的[versionCode](../../application-dev/quick-start/app-configuration-file.md)标签；FA模型下对应配置文件中的[code](../../application-dev/quick-start/app-structure.md#version对象内部结构)标签）大于之前的版本号。 

```
    hdc shell mount -o rw,remount /
    hdc shell param set persist.bms.test-upgrade true
    hdc shell reboot
```

# 预置不安装列表配置

[uninstall_list.json](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/uninstall_list.json)的配置优先级高于install_list.json,在该文件中配置后，则对应的预置应用不会安装。

## 示例一

```
/system/etc/app/uninstall_list.json
{
    "uninstall_list" : ["/system/app/Hiworld"],  // 配置后，则Hiworld不会被安装
    "recover_list" : []
}
```

## 示例二

```
/system/etc/app/uninstall_list.json
{
    "uninstall_list" : ["/system/app/Hiworld"],
    "recover_list" : []
}

/chipset/etc/app/uninstall_list.json
{
    "uninstall_list" : [],
    "recover_list" : ["/system/app/Hiworld"] // 配置后，则Hiworld被恢复安装
}
```

