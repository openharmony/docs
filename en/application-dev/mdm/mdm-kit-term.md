# Glossary

<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=188ff5fef3d90fc0078e4760b9813c31639f710c translatedAt=2026-08-04T13:32:21.618Z pushedAt=2026-08-05T08:55:12.392Z -->

## B

### Bring Your Own Device (BYOD)

An enterprise strategy that allows employees to bring their personal mobile devices, such as tablets or smartphones, to the workplace and connect these devices to the office environment. It is applicable to scenarios such as daily office work or external visitors accessing factory or lab environments with their own devices.

### BYOD Device Admin (BDA)

An Admin role activated by an MDM app in BYOD scenarios. It can perform basic device controls such as disabling photographing and recording.

## C

### Corporate-Owned, Personally-Enabled (COPE)

A management model in which an enterprise purchases laptops, tablets, smartphones, and other devices and distributes them to employees. The enterprise owns the devices and can exercise full control over them.

## D

### Device Admin (DA)

An Admin role activated by an MDM app as a DA. It can control devices but cannot manage other DA apps. It is applicable to enterprise device office scenarios.

## E

### Enterprise Device Manager (EDM)

The core foundation service of the enterprise device management framework. It manages the lifecycle of Admin components, including creation, keep-alive, startup, and shutdown, as well as permission verification and policy conflict handling for management interfaces.

### EnterpriseAdminExtensionAbility

A mandatory component for MDM applications. When developing an MDM application, you need to create an **EnterpriseAdminExtensionAbility** instance and implement MDM service logic in this instance. EnterpriseAdminExtensionAbility implements notifications of system management status changes and defines the callbacks to be invoked when a device administrator application is enabled or disabled or an application is installed or uninstalled. Once this ability is activated, it remains alive and will launch automatically after a system restart or user switch. Note that an MDM application with EnterpriseAdminExtensionAbility activated cannot be uninstalled.

### Enterprise Mobility Management (EMM)

A business domain that provides enterprises with a complete set of mobile device management software, solutions, and services. An EMM provider is a company that specializes in offering such products and services.

## M

### MDM App

A Mobile Device Management (MDM) application is an enterprise-level application integrated with MDM capabilities. It can centrally manage, monitor, and protect mobile devices (such as smartphones, tablets, and laptops) in an enterprise. It allows IT administrators to remotely configure devices, enforce security policies, deploy applications and safeguard enterprise data.

### Mobile Device Management (MDM)

In a narrow sense, MDM refers to the management of mobile office devices such as phones and tablets. In a broad sense, MDM refers to enterprise device management in general, covering PCs, large screens, and wearables.

## S

### Super Device Admin (SDA)

An Admin role activated by an MDM app as an SDA. It can control devices and manage other DA apps, including activating and deactivating them. It is applicable to enterprise device office scenarios.