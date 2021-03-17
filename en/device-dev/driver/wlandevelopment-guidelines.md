# WLAN Development Guidelines<a name="EN-US_TOPIC_0000001051802310"></a>

-   [How to Develop](#section96091936185820)

The WLAN driver is developed based on the HDF and PLATFORM. It provides a unified driver model for WLAN modules of different vendors regardless of the operating system \(OS\) and system on a chip \(SoC\).

## How to Develop<a name="section96091936185820"></a>

1.  Set hardware parameters such as  **module**  \(different features\) and  **chip**  in the  **wifi\_config.hcs**  file.
2.  Parse the  **wifi\_config.hcs**  file and generate a structure with the configured parameters.
3.  Initialize and create a module.
4.  Mount and initialize the chip.
5.  Initialize the bus.
6.  Mount the upper-layer WPA service.

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>Some of the above adaptation steps have been provided. For details, see the third part  **[WLAN Development Example](wlandevelopment-example.md)**. The steps waiting to be performed by developers include setting configuration parameters based on hardware attributes, adapting and mounting a chip, and performing tests and verification.

