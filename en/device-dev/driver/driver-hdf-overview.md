# HDF Overview


## Introduction

The Hardware Driver Foundation (HDF) provides driver framework capabilities, such as driver loading, driver service management, driver messaging mechanism, and configuration management, for driver developers. It strives to provide a more precise and efficient driver development environment, where you can perform one-time development for multi-device deployment.


## Driver Loading

The HDF supports the following loading modes:

- On-demand loading

  The HDF allows drivers to be loaded by default during the operating system (OS) boot process or dynamically loaded after the OS is started.

- Sequential loading

  The HDF allows drivers to be loaded based on their priorities during the OS boot process.


## Driver Service Management

The HDF supports centralized management of driver services. You can obtain a driver service by using the API provided by the HDF.


## Driver Messaging Mechanism

The HDF provides a unified driver messaging mechanism, which allows messages to be exchanged between user-mode applications and kernel-mode drivers.


## Configuration Management

HDF Configuration Source (HCS) provides the source code that describes the HDF configuration in key-value pairs. It decouples the configuration code from driver code, simplifying configuration management.
