# Overview<a name="EN-US_TOPIC_0000001157064271"></a>

-   [When to Use](#section191543223549)

This document uses the I2C driver as an example to describe how to develop platform drivers based on the hardware driver foundation \(HDF\).

>![](public_sys-resources/icon-caution.gif) **CAUTION:** 
>The sample code in this document is for reference only and cannot be directly used for commercial integration.

## When to Use<a name="section191543223549"></a>

The HDF provides a standard driver framework for common peripherals. To use the APIs provided by the HDF to perform operations on peripherals, you only need to adapt the specific driver to the HDF.

In this example, an I2C driver is used.  [Figure 1](#fig148041484161)  shows the sequence diagram of the I2C driver.

**Figure  1**  I2C driver sequence diagram<a name="fig148041484161"></a>  


![](figures/en-us_image_0000001161922745.png)

-   User Business: business-triggered driver
-   i2cManagerEntry: entry to the I2C manager, which is used to register the I2C manager with the HDF
-   I2cManager: I2C manager, which manages the I2C controller
-   I2cCntlr: I2C controller
-   i2cDriverEntry: entry to the I2C controller, which is used to register the I2C controller with the HDF

