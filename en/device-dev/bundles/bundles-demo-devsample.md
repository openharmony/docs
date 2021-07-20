# Development Example<a name="EN-US_TOPIC_0000001072143838"></a>

This following uses the Hi3861 platform as an example to describe how to install, compile, and package components by using HPM.

1.  Run the following commands to initialize the installation directory \(whose name can be customized\):

    ```
    mkdir test3861
    cd test3861
    hpm init -t dist
    ```

    If the following information is displayed, the initialization is successful:

    ```
    Initialization finished.
    ```

2.  Run the following command to install the  **wifi\_iot**  distribution:

    ```
    hpm install @ohos/wifi_iot
    ```

    If the following information is displayed, the installation is successful:

    ```
    Installed.
    ```

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >Run the following command for the Hi3516 platform:
    >```
    >hpm install @ohos/ip_camera_hi3516dv300
    >```
    >Run the following command for the Hi3518 platform:
    >```
    >hpm install @ohos/ip_camera_hi3518ev300
    >```

3.  Run the following command to build and package components:

    ```
    hpm dist
    ```

    If the building is successful, the following information is displayed:

    ```
    {{name}}: distribution building completed.
    ```

4.  Check the result in the  **./out**  directory. You can burn the distribution into the corresponding development board for testing.

