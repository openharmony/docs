# Introduction to MDM Kit

## Introduction

Mobile Device Management (MDM) is an enterprise-level IT application solution used to manage and protect data and applications on enterprise devices. It ensures device and data security and stability through centralized management, remote configuration, and monitoring. It is widely used in enterprises and government agencies to ensure efficient management and secure use of devices and data.

## Working Principles

<!--RP1-->

The framework layer and system ability (SA) layer use the enterprise_device_management component to provide the device administrator application framework and basic device management capabilities. The device administrator application uses an **EnterpriseAdminExtensionAbility** to call APIs in MDM Kit to manage devices.

<!--RP1End-->

![intro_arch.png](./figures/intro_arch.png)


## Constraints

- The SDK version must be 5.0.0 (API version 12) or later.

- Only the stage model is supported.

<!--RP3--><!--RP3End-->
