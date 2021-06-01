# Developing a Touchscreen Driver<a name="EN-US_TOPIC_0000001156903325"></a>

Complete the following tasks to adapt a touchscreen IC based on the input driver model:

1. Configure the touchscreen driver description required for registering the driver with the HDF, for example, whether the driver is loaded and what is the loading priority.

2. Configure the private data of the touchscreen \(such as the power-on and power-off sequence\) and the platform hardware information \(such as the GPIO port that connects the touchscreen to the development board\).

3. Adapt to the private drivers of the touchscreen. The input driver model abstracts the development process of input devices. You only need to adapt to the input chip driver without making any modifications for the input device manager and common driver.

-   **[Configuring Device Driver Descriptions](configuring-device-driver-descriptions.md)**  

-   **[Configuring the Touchscreen](configuring-the-touchscreen.md)**  

-   **[Adapting to the Private Drivers of the Touchscreen](adapting-to-the-private-drivers-of-the-touchscreen.md)**  


