# hdc_std Command Usage



## What are the commands commonly used for log management?

Applicable to: OpenHarmony SDK 3.2.2.5

- Clearing logs: hdc_std shell hilog -r

- Increasing the buffer size to 20 MB: hdc_std shell hilog -G 20M

- Capturing logs: hdc_std shell hilog &gt; log.txt


## What should I do to avoid log flow control?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

- Disabling log flow control: hdc_std shell hilog -Q pidoff

- Disabling the privacy flag: hdc_std shell hilog -p off

- Increasing the log buffer to 200 MB: hdc_std shell hilog -G 200M

- Enabling the log function of the specific domain (that is, disabling the global log function): hdc_std shell hilog –b D –D  0xd0xxxxx

After performing the preceding operations, restart the DevEco Studio.


## Is HiLog or Console recommended for log printing? How do I set the domain if HiLog is used?

Applicable to: OpenHarmony SDK 3.2.2.5

[HiLog](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-hilog.md) is recommended for an application to print logs. For details about domain setting, see [Development Guide](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-hilog.md#hilogisloggable).


## What is the maximum length of a log record when HiLog is used? Is it configurable?

Applicable to: OpenHarmony SDK 3.2.2.5

The maximum length of a log record is 1,024 characters, and it is not changeable.

## What Should I Do If a HAP Package Cannot Be Opened After Being Installed on the Development Board Using the IDE?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Check whether the SDK version is consistent with the system version on the development board. You are advised to use the SDK version and system version that are released on the same day.


## How do I upload files using an hdc command?

Applicable to: OpenHarmony SDK 3.2.2.5

Run the **hdc_std file send** command.

## How do I prevent the screen of the RK3568 development board from turning off?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Run the **hdc_std shell "power-shell setmode 602"** command.


## How do I start an ability using an hdc command?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Run the **hdc_std shell aa start -a AbilityName -b bundleName -m moduleName** command.
