# LCD Development Guidelines<a name="EN-US_TOPIC_0000001051616710"></a>

-   [How to Develop](#section3904154911218)

The display driver model is developed based on the HDF, platform APIs, and APIs at the OS abstraction layer \(OSAL\), and provides a unified driver model for the LCD regardless of the OS \(LiteOS or Linux OS\) and chip platforms \(such as Hi35xx, Hi38xx, and V3S\).

## How to Develop<a name="section3904154911218"></a>

1.  Add the LCD driver-related hardware descriptions.
2.  Add a driver that adapts to the chip at the SoC adapter layer.
3.  Add the LCD panel driver and register the panel driver functions in the driver entry function  **Init**. The functions provide capabilities for:
    -   Powering on/off the LCD device

        Based on the LCD hardware connection, use the GPIO interfaces provided by the platform to perform operations on the LCD pins, such as the reset pin and IOVCC pin. For details about the power-on sequence, see the SPEC provided by the LCD supplier.

    -   Sending the initialization sequence

        Based on the LCD hardware interfaces, use the I2C, SPI, and MIPI interfaces provided by the platform to download the LCD initialization sequence. For details, see the SPEC provided by the LCD supplier.


4.  Implement other HDF interfaces as required, for example, the  **Release**  interface.
5.  Use the HDF to create other device nodes for implementing service logic or debugging as required.

