# Subsystem Porting Overview


System functions are developed by levels, from system to subsystem and then to component. Customize subsystems and components as required. This topic uses certain subsystems and components as examples. To use the capabilities of the OpenHarmony system, the corresponding subsystems need to be adapted.


Table 1 lists the common subsystems involved in OpenHarmony chip adaptation. Add or delete subsystems based on the specific chip you use.


  **Table 1** OpenHarmony subsystems

| Subsystem| Description| 
| -------- | -------- |
| applications | Application demo. You can store the source code related to the application in this directory.| 
| kernel | Kernel subsystem, which is responsible for common kernel functions such as task scheduling and memory management.| 
| hiviewdfx | DFX subsystem, which provides log-related functions.| 
| communication | Communication subsystem, which provides Wi-Fi and Bluetooth functions.| 
| iothardware | IoT peripheral subsystem, which provides common peripheral interfaces, such as GPIO, I2C, and SPI.| 
| startup | Startup subsystem, which is the first subsystem that runs after the kernel is started. It is responsible for the startup of key system processes and services after the kernel is started and before the application is started.| 
| update | Update subsystem, which provides OTA update support for OpenHarmony devices.| 
| utils | Utils subsystem, which provides some common enhanced APIs for development using C and C++.| 
| distributed_schedule | Distributed scheduler subsystem, which manages cross-device components, provides the capabilities of accessing and controlling remote components, and supports application collaboration in distributed scenarios.| 
| security | Security subsystem, which provides system, data, and application security capabilities to protect system and user data of OpenHarmony. It implements application integrity verification, application permission management, device authentication, OpenHarmony Universal KeyStore (HUKS) key management, and data transfer management.| 
| test | Test subsystem. OpenHarmony provides a comprehensive auto-test framework for designing test cases. Detecting defects in the development process can improve code quality.| 
