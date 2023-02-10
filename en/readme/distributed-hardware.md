# Distributed Hardware

## Introduction

### **Distributed Hardware Subsystem**

The distributed hardware subsystem manages hardware information of all the devices in a Super Device so that the hardware capabilities can be shared and called across devices.

### Architecture

![Distributed Hardware Subsystem](figures/distributed-hardware-subsystem.png)

## Directory Structure

```
foundation/distributedhardware
├──device_manager                     # Directory of DeviceManager.
├──distributed_hardware_fwk           # Directory of the distributed hardware framework.
├──distributed_camera                 # Directory of the distributed camera component. 
└──distributed_screen                 # Directory of the distributed screen component.
```

## Component Description

### DeviceManager

DeviceManager provides authentication and networking for devices of a Super Device, including discovering distributed devices, performing authentication, and listening for device online/offline status.

### Distributed Hardware Framework

As an information management component of the distributed hardware subsystem, the distributed hardware framework implements unified hardware access, information query, and hardware enablement.

### Distributed Camera

The distributed camera component implements collaboration of cameras of multiple devices that form a Super Device. Instead of directly interacting with applications, the distributed camera component only provides C++ interfaces for the distributed hardware framework. Applications can call the APIs of the camera framework to use the distributed camera component to operate cameras of other devices, just like operating a local camera.

### Distributed Screen

The distributed screen provides a screen virtualization capability, which allows the screen of another authenticated device to be used as a display. In the distributed hardware subsystem, the distributed screen component implements system projection, screen mirroring, and screen splitting across the devices that form a Super Device.

## Repositories Involved

[distributedhardware\_device\_manager](https://gitee.com/openharmony/distributedhardware_device_manager)

[distributedhardware\_distributed\_hardware\_fwk](https://gitee.com/openharmony/distributedhardware_distributed_hardware_fwk)

[distributedhardware\_distributed\_camera](https://gitee.com/openharmony/distributedhardware_distributed_camera)

[distributedhardware\_distributed\_screen](https://gitee.com/openharmony/distributedhardware_distributed_screen)
