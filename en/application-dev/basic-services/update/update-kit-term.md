# Update Service Terminology

<!--Kit: Basic Services Kit-->
<!--Subsystem: Update-->
<!--Owner: @RainyDay_005; @huangsiping3-->
<!--Designer: @zhangzhengxue; @jackd320-->
<!--Tester: @mamba-ting-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=2bd1465d343a4b04f3239b7ef52d244cdbbef8ab translatedAt=2026-07-28T07:32:43.453Z pushedAt=2026-07-31T04:01:43.130Z -->

## A

### AB Upgrade

A dual-partition upgrade method. The system runs and upgrades alternately on partitions A and B. During an upgrade, the new system is written to the inactive partition, and the system switches to the new partition after a restart.

If the upgrade fails, the system can roll back to the old partition, improving upgrade reliability.

## C

### Cold Upgrade

An upgrade method that requires a device restart to take effect. It is applicable to scenarios that require a complete system reset or firmware update.

## D

### Deep Factory Reset

Deeply clears the user data partition and operating system partition through methods such as overwriting, thoroughly destroys data, and restores the device to its factory state.

Compared with forced factory reset, it has a broader scope of erasure, covers the operating system partition, and makes data recovery more difficult.

### Differential Package

Contains only the differences from the current version. Compared with a full package, it is smaller in size, faster to download and install, and saves network traffic and storage space.

Suitable for incremental upgrade scenarios where a base version is already installed.

## F

### Fix Package

An update package that typically contains incremental update content or patches for specific issues. It is mainly used for security patches or minor version fixes.

It applies to special update scenarios such as system fault repair or system function restoration.

### Firmware

Pre-installed system-level software on a device, including the operating system kernel, system services, built-in resources, and pre-installed apps (excluding third-party apps).

The update scope covers the entire system. A firmware update can fix vulnerabilities, improve performance, or add new features.

### Factory Reset

Clears the user data partition, removes user-installed apps, user files, and personal settings, and restores the device to its factory default state. This operation is irreversible, so back up your data in advance.

### Force Factory Reset

Clears the user data partition and simultaneously removes the file encryption key (the key used to encrypt user data). This applies to high-security scenarios such as before device handover or destruction of sensitive data.

## L

### Live And Cold

A live and cold upgrade combines the characteristics of both, and is applicable to scenarios where both live upgrade and cold upgrade components are present.

### Live Upgrade

Live Upgrade takes effect without restarting the device. It is suitable for upgrading app-layer components or scenarios where the device must remain running.

## O

### Over The Air (OTA)

A method of downloading an update package remotely over a network and completing the system upgrade. The device connects directly to the update server to obtain the update package without requiring physical media. It is the mainstream approach for system upgrades on mobile devices.

A general term referring to upgrading over a wireless air interface.

It does not specify a particular network type (which can be cellular data, Wi-Fi, or even Bluetooth), nor does it prescribe a specific implementation method.

### Online Upgrade

A method of completing a system upgrade by connecting to an update server over a network, downloading the update package, and installing it. It relies on the update server deployed by the device vendor for version detection and package management.

The device can periodically or manually check for new versions and download the update.

## S

### SD Card Upgrade

A local upgrade method that uses an SD card to store the upgrade package. The upgrade package is copied to the SD card, and the device reads and executes the upgrade from the SD card. This method is suitable for scenarios where no network connection is available or the upgrade package is large.

### Stream OTA

An update method where update package data is downloaded and written simultaneously, without requiring a full download before installation. This approach saves storage space, reduces waiting time, and is suitable for devices with limited storage.