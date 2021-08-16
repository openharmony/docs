# Development Example<a name="EN-US_TOPIC_0000001072143838"></a>

The following uses the Hi3861 platform as an example to describe how to install and build bundles by using the hpm.

1.  Run the following commands to create a directory \(its name can be customized\) and create a default project based on the dist template:

    ```
    mkdir test3861
    cd test3861
    hpm init -t dist myproduct
    ```

    If the following information is displayed, the project is created:

    ```
    Initialization finished.
    ```

2.  Run the following command to install the  **hispark\_pegasus**  distribution:

    ```
    hpm install @ohos/hispark_pegasus
    ```

    If the following information is displayed, the installation is successful:

    ```
    Installed.
    ```

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >If you are using the Hi3516 platform, run the following command:
    >```
    >hpm install @ohos/hispark_taurus
    >```
    >If you are using the Hi3518 platform, run the following command:
    >```
    >hpm install @ohos/hispark_aries
    >```

3.  Run the following command to build and package bundles:

    ```
    hpm dist
    ```

    If the building is successful, the following information is displayed:

    ```
    {{name}}: distribution building completed.
    ```

4.  Check the result in the  **./out**  directory. You can burn the distribution into the corresponding development board for testing.

