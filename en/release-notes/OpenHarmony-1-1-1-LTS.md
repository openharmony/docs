# OpenHarmony 1.1.1 LTS \(2021-06-22) (EOL)

## Version Description

This is an updated long-term support \(LTS\) version of OpenHarmony. It supports more functions and fixes some bugs in OpenHarmony 1.1.0.

## Source Code Acquisition

### Acquiring Source Code from Mirrors

**Table  1**  Mirrors for acquiring source code

| Source Code              | Version | Mirror                                                       | SHA-256 Checksum                                             |
| ------------------------ | ------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base           | 1.1.1   | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.1/code-v1.1.1-LTS.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.1/code-v1.1.1-LTS.tar.gz.sha256) |
| Hi3861 solution (binary) | 1.1.1   | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.1/wifiiot-1.1.0.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.1/wifiiot-1.1.0.tar.gz.sha256) |
| Hi3518 solution (binary) | 1.1.1   | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.1/ipcamera_hi3518ev300-1.1.1.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.1/ipcamera_hi3518ev300-1.1.1.tar.gz.sha256) |
| Hi3516 solution (binary) | 1.1.1   | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.1/ipcamera_hi3516dv300-1.1.1.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.1/ipcamera_hi3516dv300-1.1.1.tar.gz.sha256) |
| Release Notes            | 1.1.1   | [Download](https://repo.huaweicloud.com/harmonyos/os/1.1.1/OpenHarmony_Release_Notes_1.1.1_LTS.md) | -                                                            |

### Acquiring Source Code Using the repo Tool

Run the following commands to download the source code:

repo init -u  [https://gitee.com/openharmony/manifest.git](https://gitee.com/openharmony/manifest.git)  -b refs/tags/OpenHarmony-v1.1.1-LTS  --no-repo-verify

## What's New

This version inherits all features of OpenHarmony 1.1.0, and fixes bugs and optimizes performance for different modules based on OpenHarmony 1.1.0. The following table lists the updates.

**Table  2**  Version updates

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Communications | - Updated data classes of some STA related functions, and added innerkits APIs of some AP related functions<br/>- Added innerkits APIs for Bluetooth-related functions, including GATT related operations of BLE devices, BLE broadcast, and scanning. |
| Security       | - Removed device authentication so callers can use bound capabilities alone.<br/>- Allowed device authentication removed from Huawei Universal Keystore Service (HUKS). |
| Kernel         | - Fixed the bug of unavailable kernel stack backtracking of the system image built using Clang.<br/>- Fixed the bug of improper comparison between signed numbers and unsigned numbers during scheduling.<br/>- Fixed the bug of memory overwriting because **setitimer** does not hold the scheduler lock when periodically sending signals to the process.<br/>- Added adaptation to the kernel's POSIX APIs for lwIP.<br/>- Fixed the bug of unexpected signal execution sequence after **sigsuspend** in **sigaction** is called; fixed the bug so that the signal mask field passed by the developer is now masked during signal registration. |
| Driver         | - Corrected the compilation error on **liteos_m**.<br/>- Fixed MMC crashes. |
| AI             | - Added support for shared memory.<br/>- Added adaptation to the Linux kernel.<br/>- Disabled asynchronous call for the synchronous algorithm.<br/>- Added gitignore and CMakeLists. |
| Graphics       | - Fixed the bug that occurs when the endpoint style is enabled for circle progress.<br/>- Resolved issues related to the sensitivity and direction of crown rotation.<br/>- Added the feature of automatic alignment with the animation time for **UIList**.<br/>- Provided correct width for **GetTextWidth** in **UILabel** when **LineBreakMode** is set to **LINE_BREAK_ELLIPSIS**.<br/>- Added new style attributes to the **Slider** component.<br/>- Added the API for setting loops to the **UITimePicker** component.<br/>- Fixed the bug of abnormal Neon rotation and scaling display that results from optimization of fixed-point numbers.<br/>- Rectified the improper newline issue that occurs when a string contains multiple newlines.<br/>- Fixed the bug of the blurred screen of watch pointers. |
| Globalization  | Added the **Ed** and **MEd** templates for data and time formatting. |
| ACE framework  | - Fixed the bug of abnormal click events on the checkbox and radio buttons.<br/>- Fixed JavaScript application crashes when **list** and **if** are used.<br/>- Normalized the styles of the **\<slider>** component.<br/>- Added swiping loops for the **\<picker-view>** component.<br/>- Fixed the bug of in-the-middle display of child components when **align-item** is set to **stretch**. |


