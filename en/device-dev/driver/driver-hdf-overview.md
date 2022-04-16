# HDF Overview


## Introduction

The Hardware Driver Foundation (HDF) provides driver framework capabilities including driver loading, driver service management, and driver messaging mechanism. It strives to build a unified driver architecture platform to provide a more precise and efficient development environment, where you can perform one-time development for multi-device deployment.


## Driver Loading

The HDF supports the following loading modes:

- On-demand loading
  The driver is loaded by default during the operating system (OS) boot process or dynamically loaded after OS is started.

- Sequential loading
  The driver is loaded based on its priority during the OS boot process.


## Driver Service Management

The HDF allows centralized management of driver services. You can obtain a driver service by using the API provided by the HDF.


## Driver messaging mechanism

The HDF provides a unified driver messaging mechanism, which allows messages to be exchanged between user-mode applications and kernel-mode drivers.
