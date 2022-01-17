# Installing and Running Your OpenHarmony App<a name="EN-US_TOPIC_0000001115941596"></a>

To install your OpenHarmony app, use the hdc tool to manually run the corresponding commands.

You can manually obtain the hdc tool from the open-source repository. Use the tool to send the compiled HAP package to the device and install the app.

The hdc commands are as follows:

-   App installation

    **install \[-r/-d/-g\]  _package_**

    Example:

    ```
    hdc_std install E:\hwadmin.hap
    ```

-   Log capturing

    **hilog**

    Example:

    ```
    hdc_std hilog
    ```


For details about how to use the hdc tool and the command format, see [hdc_std Usage Guidelines](../../device-dev/subsystems/oem_subsys_toolchain_hdc_guide.md).

