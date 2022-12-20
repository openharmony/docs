# hdc_std Command Usage

## Common Log Commands

Applicable to: OpenHarmony SDK 3.2.2.5

Clearing logs: hdc_std shell hilog -r

Increasing the buffer size to 20 MB: hdc_std shell hilog -G 20M

Capturing logs: hdc_std shell hilog &gt; log.txt

## What should I do to avoid log flow control?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

- Disabling log flow control: hdc_std shell hilog -Q pidoff

- Disabling the privacy flag: hdc_std shell hilog -p off

- Increasing the log buffer to 200 MB: hdc_std shell hilog -G 200M

- Enabling the log function of the specific domain (that is, disabling the global log function): hdc_std shell hilog –b D –D  0xd0xxxxx

After performing the preceding operations, restart the DevEco Studio.

## What should I do if the HAP installed on the development board through the IDE cannot be opened?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Check whether the SDK version is consistent with the system version on the development board. You are advised to use the SDK version and system version that are released on the same day.

## How do I upload files using the hdc command?

Applicable to: OpenHarmony SDK 3.2.2.5

Run the **hdc_std file send** command.

## How do I prevent the screen of the RK3568 development board from turning off?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Run the **hdc_std shell "power-shell setmode 602"** command.

## How do I start an ability using the hdc command?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Run the **hdc\_std shell aa start -a AbilityName -b bundleName -m moduleName** command.

## How do I change the read and write permissions on a file directory on the development board?

Applicable to: OpenHarmony SDK 3.2.5.6, stage model of API version 9

Run the **hdc\_std shell mount -o remount,rw /** command.

## What should I do if the error message "Unknown file option -r" is displayed when hdc_std file recv is run?

Applicable to: OpenHarmony SDK 3.2.5.6, stage model of API version 9

1. Use the the hdc tool in the device image or SDK of the same version.

2. Remove any Chinese characters or spaces from the directory specified for the hdc tool.

## How do I uninstall an application using the hdc command?

Applicable to: OpenHarmony SDK 3.2.2.5

Run the **hdc\_std uninstall [-k] [package_name]** command.

## How do I check whether the system is 32-bit or 64-bit?

Applicable to: OpenHarmony SDK 3.2.5.5

Run the **hdc\_std shell getconf LONG_BIT** command.

If **64** is returned, the system is a 64-bit one. Otherwise, the system is a 32-bit one.

## How do I view the component tree structure?

Applicable to: OpenHarmony SDK 3.2.5.5

1. Run the **hdc\_std shell** command to launch the CLI.

2. Run the **aa dump -a** command to find **abilityID**.

3. Run the **aa dump -i [abilityID] -c -render** command to view the component tree.
