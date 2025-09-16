# UsbSerial_Params
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Defines the USB serial port parameters for the USB SERIAL DDK.

**Since**: 18

**Related module**: [SerialDdk](capi-serialddk.md)

**Header file:** [usb_serial_types.h](capi-usb-serial-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t baudRate | Baud rate.|
| uint8_t nDataBits | Number of data transfer bits.|
| uint8_t nStopBits | Number of data stop bits.|
| uint8_t parity | Parity settings.|
