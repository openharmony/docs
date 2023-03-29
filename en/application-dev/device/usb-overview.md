# USB Service Overview<a name="EN-US_TOPIC_0000001222914233"></a>

## Basic Concepts<a name="section433mcpsimp"></a>

The USB service is an abstraction of underlying hardware-based USB devices. Your application can access the USB devices via the USB service. With the APIs provided by the USB service, you can obtain the list of connected USB devices, manage device access permissions, and perform data transfer or control transfer between the host and connected devices.

## Working Principles<a name="section485mcpsimp"></a>

The USB subsystem consists of three parts: USB API, USB Service, and USB HAL. The following figure shows how the USB service is implemented.

**Figure  1**  Implementation of the USB service<a name="fig913672814333"></a>  


![](figures/en-us_image_0000001237821727.png)

-   USB API: provides USB APIs that implement various basic functions, for example, query of the USB device list, bulk data transfer, control transfer, and right management.

-   USB Service: receives, parses, and distributes Hardware Abstraction Layer \(HAL\) data, manages and controls foreground and background policies, and manages devices.

-   USB HAL: provides driver capability APIs that can be directly called in user mode.

