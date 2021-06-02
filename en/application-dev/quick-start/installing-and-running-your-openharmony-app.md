# Installing and Running Your OpenHarmony App<a name="EN-US_TOPIC_0000001115941596"></a>

To install your OpenHarmony app, use the hdc tool to manually run the corresponding commands.

You can manually obtain the hdc tool from the open-source repository. Use the tool to send the compiled HAP package to the device and run the corresponding hdc commands to install the app.

The hdc commands are as follows:

-   File sending

    **file send  _localpath remotepath_**

    Example:

    ```
    hdc_std file send E:\hwadmin.hap /data/local/tmp/hwadmin.hap
    ```

-   App installation

    **install \[-r/-d/-g\]  _package_**

    Example:

    ```
    hdc_std install hwadmin.hap
    ```

-   Log capturing

    **hilog**

    Example:

    ```
    hdc_std hilog
    ```


For details about how to use the hdc tool and the command format, see the open-source repository  **docs/en/device-dev/subsystems/hdc-usage-guidelines.md**.

