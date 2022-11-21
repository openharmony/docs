# Preset Application Configuration Guide

OpenHarmony supports differentiated configuration of preset applications on different devices.

In addition, OpenHarmony provides **GetCfgDirList** for your application to obtain the preset directories, such as **system**, **chipset**, **sys_prod**, and **chip_prod**, in ascending order of priority. For example, the priority of **chip_prod** is higher than that of **system**.

## Configuring the Preset Applications to Be Installed

### Procedure

1. Add the application name in the preset directory as the application directory.
2. Preset the application in the application directory, for example, **/system/app/Hiworld/entry.hap**.
3. Add the application directory to [install_list.json](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list.json) and configure **removable** as required.

### Example

```
{
    "install_list" : [
        {
            "app_dir" : "/system/app/Hiworld",
            "removable": false // The application cannot be uninstalled.
        }
    ]
}
```

## Configuring the Preset Applications Not to Be Installed

The configuration priority of [**uninstall_list.json**](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/uninstall_list.json) is higher than that of **install_list.json**. The applications added to **uninstall_list.json** will not be installed.

### Example 1:

```
/system/etc/app/uninstall_list.json
{
    "uninstall_list": ["/system/app/Hiworld"], // Hiworld will not be installed.
    "recover_list" : []
}
```

### Example 2:

```
/system/etc/app/uninstall_list.json
{
    "uninstall_list" : ["/system/app/Hiworld"],
    "recover_list" : []
}

/chipset/etc/app/uninstall_list.json
{
    "uninstall_list" : [],
    "recover_list": ["/system/app/Hiworld"] // Hiworld will be installed.
}
```
