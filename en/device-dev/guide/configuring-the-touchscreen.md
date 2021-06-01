# Configuring the Touchscreen<a name="EN-US_TOPIC_0000001113543350"></a>

You can configure the touchscreen in the configuration file at  **./drivers/adapter/khdf/linux/hcs/input/input\_config.hcs**.

The  **input\_config.hcs**  file consists of the private configuration data of both the common driver and chip driver. Information of this file is read and parsed by the driver code. The configuration in the file includes the board-level hardware information and private configuration of the touchscreen. You can tailor the configuration during your development.

```
root {                                                              
    input_config {
        touchConfig {
            touch0 {                                                 // Configure the first touchscreen.
                boardConfig {                                        // Specify the board-level hardware information.
                    match_attr = "touch_device1";                    // Keep this value the same as the match_attr field in the private configuration data of the input common driver in the device description.
                    inputAttr {
                        /* 0:touch 1:key 2:keyboard 3:mouse 4:button 5:crown 6:encoder */
                        inputType = 0;                               // Set the input type to touch.
                        solutionX = 480;                             // Set the resolution in the X-axis.
                        solutionY = 960;                             // Set the resolution in the Y-axis.
                        devName = "main_touch";                      // Set the device name.
                    }
                    busConfig {
                        /* 0:i2c 1:spi */
                        busType = 0;                                 // GT911 uses the I2C bus for communication.
                        busNum = 6;                                  // Use the sixth bus of the chip to communicate with the development board through I2C.
                        clkGpio = 86;                                // Set the SCL pin of the chip.
                        dataGpio = 87;                               // Set the SDA pin of the chip.
                        i2cClkIomux = [0x114f0048, 0x403];           // Configure the SCL pin information.
                        i2cDataIomux = [0x114f004c, 0x403];          // Configure the SDA pin information.
                    }
                    pinConfig {
                        rstGpio = 3;                                 // Set the reset pin.
                         intGpio = 4;                                 // Set the interrupt pin.
                        rstRegCfg = [0x112f0094, 0x400];             // Configure the reset pin information.
                        intRegCfg = [0x112f0098, 0x400];             // Configure the interrupt pin information.
                    }
                    powerConfig {
                        /* Value 0 indicates that power supply is not used; value 1 indicates the LDO power supply; value 2 indicates the GPIO power supply; value 3 indicates the PMIC power supply. */
                        vccType = 2;                                  // Set the VCC type. Value 2 indicates the GPIO power supply.
                        vccNum = 20;                                  // Set the VCC number. The GPIO number is 20.
                        vccValue = 1800;                              // Set the voltage amplitude to 1800 mV.
                        vciType = 1;                                  // Set the VCI type. Value 1 indicates the LDO power supply.
                        vciNum = 12;                                  // Set the VCI number. The LDO number is 12.
                        vciValue = 3300;                              // Set the voltage amplitude to 3300 mV.
                    }

                    featureConfig {
                        capacitanceTest = 0;                          // Configure the capacitance test.
                        gestureMode = 0;                              // Configure the gesture mode.
                        gloverMode = 0;                               // Configure the gloves mode.
                        coverMode = 0;                                // Configure the cover mode.
                        chargerMode = 0;                              // Configure the charging mode.
                        knuckleMode = 0;                              // Configure the knuckle mode.
                    }
                }
                chipConfig {                                          // Configure the private data of the touchscreen chip.
                    template touchChip {                              // Template
                        match_attr = "";
                        chipName = "gt911";                           // Set the touchscreen IC model.
                        vendorName = "zsj";                           // Set the vendor name.
                        chipInfo = "AAAA11222";                       // The first four characters indicate the product name. The fifth and sixth characters indicate the IC model. The last three characters indicate the chip model.
                        busType = 0;                                  // 0 indicates the I2C bus, and 1 indicates the SPI bus.
                        deviceAddr = 0x5D;                            // Set the IC communication address.
                        irqFlag = 2;                                  // Values 1 and 2 indicate that the interrupt is triggered on the rising and falling edges, respectively. Values 4 and 8 indicate that the interrupt is triggered by the high and low levels, respectively.
                        maxSpeed = 400;                               // Set the maximum communication rate to 400 Hz.
                        chipVersion = 0;                              // Set the touchscreen IC version.
                        powerSequence {
                             /* Power-on sequence is described as follows:
                               [Type, status, direction, delay]
                               <type> Value 0 indicates the power or pin is empty. Values 1 and 2 indicate the VCC (1.8 V) and VCI (3.3 V) power, respectively. Values 3 and 4 indicate the reset and interrupt pins, respectively.
                               <status> Values 0 and 1 indicate the power-off or pull-down, and the power-on or pull-up, respectively. Value 2 indicates that no operation is performed.
                               <dir> Values 0 and 1 indicate the input and output directions, respectively. Value 2 indicates that no operation is performed.
                               <delay> Delay time, in milliseconds.
                             */
                            powerOnSeq = [4, 0, 1, 0,                 // Set the output direction for the interrupt pin and pull down the pin.
                                         3, 0, 1, 10,                 // Set the output direction for the reset pin and pull down the pin, with a delay of 10 ms.
                                         3, 1, 2, 60,                 // No operation is performed on the reset pin. Pull up the pin, with a delay of 60 ms.
                                         4, 2, 0, 0];                 // Set the input direction for the interrupt pin.
                            suspendSeq = [3, 0, 2, 10];               // No operation is performed on the reset pin. Pull down the pin, with a delay of 10 ms.
                            resumeSeq = [3, 1, 2, 10];                // No operation is performed on the reset pin. Pull up the pin, with a delay of 10 ms.
                            powerOffSeq = [3, 0, 2, 10,               // No operation is performed on the reset pin. Pull down the pin, with a delay of 10 ms.
                                           1, 0, 2, 20];              // No operation is performed on the positive pin. Pull down the pin, with a delay of 20 ms.
                        }
                    }

                    chip0 :: touchChip {
                        match_attr = "zsj_gt911_5p5";                 // Keep this value the same as the match_attr field in the touchscreen private configuration data in the device description.
                        chipInfo = "ZIDN45100";                       // The chip information is composed of the product name, module number, and chip number, used to identity the current touchscreen in user space.
                        chipVersion = 0;                              // IC model version
                    }
                }
            }
        }
    }
}
```

In the example,  **touchConfig**  contains the  **touch0**  configuration, which describes the  **boardConfig**  and  **chipConfig**  configuration information. The  **boardConfig**  field provides the board-level hardware information of Hi3516D V300, and the  **chipConfig**  field provides the private configuration data of the touchscreen. To use another touchscreen, you can change the value of the  **chipConfig**  field. You can also configure multiple touchscreens for your product. In this example,  **touch0**  represents the hardware interface and chip configuration of the default touchscreen. If you need to configure a secondary touchscreen, add a  **touch1**  block parallel to  **touch0**.

