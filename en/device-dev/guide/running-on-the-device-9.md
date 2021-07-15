# Running on the Device<a name="EN-US_TOPIC_0000001115258034"></a>

Before you install the app and run it on the development board, install the DevEco Device Tool by following operations provided in  [HUAWEI DevEco Device Tool User Guide](https://device.harmonyos.com/en/docs/ide/user-guides/service_introduction-0000001050166905). Burn OpenHarmony into the development board, and run it on the board. For details about how to build, burn, and run an image, see  [Getting Started with Hi3516](../quick-start/standard-system.md). After the image is running normally and the system is started properly, perform the following steps to install or uninstall the app:

1.  Obtain the HDC client from the following path:

    ```
    developtools/hdc_standard/prebuilt/windows/hdc_std.exe
    ```

    Change the HDC client name to  **hdc.exe**  and add the path above to the system environment variable  **path**.

2.  Open the  **cmd**  window, and run the following commands to push the HAP file to the device directory, and install it:

    ```
    hdc smode
    hdc target mount
    hdc file send clock.hap /data/clock.hap
    hdc shell chmod 666 /data/clock.hap
    hdc shell bm install -p /data/clock.hap
    ```

3.  Run the following command to start the app.  **ohos.samples.clock**  indicates the app package name, and  **MainAbility**  indicates the ability started by the app.

    ```
    hdc shell aa start -d 123 -a ohos.samples.clock.MainAbility -b ohos.samples.clock
    ```

4.  \(Optional\) Run the following command to uninstall the app.  **ohos.samples.clock**  indicates the app package name.

    ```
    hdc shell bm uninstall -n ohos.samples.clock
    ```


