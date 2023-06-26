# Configuration and Installation of Pre-installed Applications

Pre-installed applications are applications that are natively installed on a device from factory setup. OpenHarmony supports differentiated configuration of pr-installed applications on different devices.

## Configuring Pre-installed Applications

1. Before the configuration, run the following command to query the directories for pre-installed applications supported by the system:
   
   ```
   hdc shell param get const.cust.config_dir_layer
   ```
   
   The query result includes **system**, **chipset**, **sys_prod**, **chip_prod**, and more. The directories are listed in ascending order of priority. For example, **chip_prod** has higher priority than **system**. This document uses **/system/etc/app/** as an example.

2. Configure the HAP path on the device in the **install_list.json** file.

```
hdc shell mount -o rw,remount /
hdc file recv /system/etc/app/install_list.json .
```

3. Configure **install_list**.

```
{
    "install_list" : [
        {
            "app_dir":"system/app/xxxx/yyyy", // HAP path on the device. If the directory does not exist, create it and push HAP to this directory.
            "removable":true // Whether the application can be uninstalled. The value true means the application can be uninstalled; the value false means the opposite.
        }
    ]
}
```

4. Transfer the **install_list.json** file to the device, and restart the device for the modification to take effect.

```
    hdc shell mount -o rw,remount /
    hdc file send install_list.json /system/etc/app/install_list.json
    hdc shell reboot
```

## Updating Pre-installed Applications

After the pre-installed applications are updated, use either of the following methods to reinstall them:

- Method 1: Clear **/data** and restart the device. The applications will be automatically installed.

```
    hdc shell mount -o rw,remount / 
    hdc shell rm /data/* -rf
    hdc shell sync
    hdc shell /system/bin/udevadm trigger
    hdc shell reboot
```
- Method 2: Run the following command to restart the device. The applications will be installed.

    If an application has been installed, the application version No. ([versionCode](../../application-dev/quick-start/app-configuration-file.md) configured in **app.json5** for the stage model or [code](../../application-dev/quick-start/app-structure.md#internal-structure-of-the-version-atttribute) in the configuration file for the FA model) sent to the **/system/app/** directory must be later than the version number of the application installed.

```
    hdc shell mount -o rw,remount /
    hdc shell param set persist.bms.test-upgrade true
    hdc shell reboot
```

# Configuring Applications Not Installed

The [**uninstall_list.json**](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/uninstall_list.json) has higher configuration priority than **install_list.json**. The applications added to **uninstall_list.json** will not be installed.

## Example 1

```
/system/etc/app/uninstall_list.json
{
    "uninstall_list": ["/system/app/Hiworld"], // Hiworld will not be installed.
    "recover_list" : []
}
```

## Example 2

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
