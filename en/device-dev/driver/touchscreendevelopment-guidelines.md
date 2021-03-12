# Touchscreen Development Guidelines<a name="EN-US_TOPIC_0000001052537515"></a>

-   [How to Develop](#section1255740132616)

Regardless of the OS and system on a chip \(SoC\), the input driver is developed based on the HDF, platform, and OSAL APIs to provide a unified driver model for touchscreen devices.

-   The following uses the touchscreen driver as an example to describe the loading process of the input driver model:
    -   Add the touchscreen driver-related descriptions: You can add the touchscreen driver-related descriptions, such as the loading priority, board-level hardware information, and private data, by referring to the existing template.

    -   Load the input device manager driver: The HDF automatically loads the input device manager driver, which then creates the device manager and initializes it.

    -   Load the touchscreen common driver: The HDF automatically loads the touchscreen common driver, which then parses the board-level configuration, initializes the hardware, and provides the API for registering the touchscreen.

    -   Load the touchscreen chip driver: The HDF automatically loads the touchscreen chip driver, which then instantiates the touchscreen device, parses the private data, and implements differentiated APIs provided by the platform.

    -   Register the touchscreen device with the platform driver: Register the instantiated touchscreen device with the platform driver, bind this device to the platform driver, and complete touchscreen initialization such as interrupt registration and power-on and power-off.

    -   Register the input device: Instantiate the input device and register it with the input manager after the touchscreen is initialized.


## How to Develop<a name="section1255740132616"></a>

1.  Add the touchscreen driver-related descriptions.

    Currently, the input driver is developed based on the HDF and is loaded and started by the HDF. Register the driver information, such as whether to load the driver and the loading priority in the configuration file. Then, the HDF starts the registered driver modules one by one. For details about the driver configuration, see  [How to Develop](driver-development.md#section1969312275533).

2.  Complete the board-level configuration and private data configuration of the touchscreen.

    Configure the required I/O pins. For example, configure a register for the I2C pin reserved for the touchscreen to use I2C for transmitting data.

3.  Implement differentiated adaptation APIs of the touchscreen.

    Use the platform APIs to perform operations for the reset pins, interrupt pins and power based on the communications interfaces designed for boards. For details about the GPIO-related operations, see  [GPIO Usage Guidelines](gpiousage-guidelines.md).


