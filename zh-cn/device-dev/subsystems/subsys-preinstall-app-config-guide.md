# 预置应用配置指南

OpenHarmony支持在不同产品上对预置应用进行差异化配置，设备厂商可根据需要对预置应用进行配置。

此外，OpenHarmony根据GetCfgDirList获得系统支持的预置目录，如system、chipset、sys_prod、chip_prod；并且按照返回的顺序越靠后优先级越高，如chip_prod的优先级高于system的优先级。

## 预置应用安装列表配置

### 应用预置到系统中的配置步骤

1. 在预置目录下创建应用的名称作为应用目录
2. 将应用预置到应用目录下，如 /system/app/Hiworld/entry.hap
3. 添加应用目录到[install_list.json](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list.json)，根据需求配置removable

### 示例

```
{
    "install_list" : [
        {
            "app_dir" : "/system/app/Hiworld",
            "removable" : false // 是否可卸载
        }
    ]
}
```

## 预置不安装列表配置

[uninstall_list.json](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/uninstall_list.json)的配置优先级高于install_list.json,在该文件中配置后，则对应的预置应用不会安装。

### 示例一

```
/system/etc/app/uninstall_list.json
{
    "uninstall_list" : ["/system/app/Hiworld"],  // 配置后，则Hiworld不会被安装
    "recover_list" : []
}
```

### 示例二

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

