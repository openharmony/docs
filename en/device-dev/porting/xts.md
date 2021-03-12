# XTS<a name="EN-US_TOPIC_0000001063110883"></a>

-   [Introduction](#section6725155811454)
    -   [Adding the XTS Subsystem to the Building Component](#section46981118105417)
    -   [Executing ACTS Cases for the IoTLink Module](#section9489122319819)


## Introduction<a name="section6725155811454"></a>

X Test Suite \(XTS\) is a set of OpenHarmony certification test suites. Currently, the application compatibility test suite \(ACTS\) is supported. The  **test/xts**  repository contains the  **acts**  directory and  **tools**  software package.

-   The  **acts**  directory stores the source code and configuration files of ACTS test cases. The ACTS helps device vendors detect the software incompatibility as early as possible and ensures that the software is compatible with OpenHarmony during the entire development process.
-   The  **tools**  software package stores the test case development framework related to  **acts**.

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>The startup of the XTS depends on the SAMGR module.

The XTS adaptation consists of the following steps:

1.  Add the XTS subsystem to the building component.
2.  Execute ACTS cases for the IoTLink module.

### Adding the XTS Subsystem to the Building Component<a name="section46981118105417"></a>

The following example shows how to add the XTS subsystem to the building component  **hispark\_aries**:

1.  Add the definition of the XTS subsystem to the  **vendor/hisilicon/hispark\_aries/config.json**  file.

    ```
    {
        "subsystem": "test",
        "components": [
           { "component": "xts_acts", "features":[] },
           { "component": "xts_tools", "features":[] }
         ]
    },
    ```

2.  Set the building type to the debug version so that the XTS subsystem can be built.

### Executing ACTS Cases for the IoTLink Module<a name="section9489122319819"></a>

The following example shows how to execute ACTS cases for the IoTLink module of  **hispark\_aries**:

1.  Obtain the built image.

    Obtain the image from the  **out/hispark\_pegasus/wifiiot\_hispark\_pegasus/**  directory.

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >To check whether the ACTS is integrated into the current image, check whether the corresponding  **.a**  file is compiled.

2.  Burn the image into the development board.
3.  Execute the test by performing the following steps.
    -   Use a serial port tool to log in to the development board and save information about the serial port.

    -   Restart the device and view serial port logs.

4.  Analyze the test result.
    -   View the serial port logs, whose format is as follows:

    -   The log for each test suite starts with  **Start to run test suite:**  and ends with  **xx Tests xx Failures xx Ignored**.


