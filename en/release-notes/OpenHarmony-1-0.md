# OpenHarmony 1.0 \(2020-09-10) (EOL)

## Overview

This is the initial release for this product.

## Source Code Acquisition

### Acquiring Source Code from Mirrors

**Table  1**  Mirrors for acquiring source code

| Source Code              | Version Information | Mirror                                                       | SHA-256 Checksum                                             |
| ------------------------ | ------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Full code base           | 1.0                 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.0/code-1.0.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.0/code-1.0.tar.gz.sha256) |
| Hi3861 solution (binary) | 1.0                 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.0/wifiiot-1.0.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.0/wifiiot-1.0.tar.gz.sha256) |
| Hi3518 solution (binary) | 1.0                 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.0/ipcamera_hi3518ev300-1.0.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.0/ipcamera_hi3518ev300-1.0.tar.gz.sha256) |
| Hi3516 solution (binary) | 1.0                 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.0/ipcamera_hi3516dv300-1.0.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/1.0/ipcamera_hi3516dv300-1.0.tar.gz.sha256) |
| Release Notes            | 1.0                 | [Download](https://repo.huaweicloud.com/harmonyos/os/1.0/RELEASE-NOTES.txt) | -                                                            |

### Acquiring Source Code Using the repo Tool

Method 1 \(recommended\): Use the  **repo**  tool to download the source code.

```shell
repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
repo sync -c
```

Method 2: Run the  **git clone**  command to clone a single code repository.

Go to the  [code repository homepage](https://gitee.com/openharmony), select the code repository to be cloned, and run the following command:

```shell
git clone https://gitee.com/openharmony/manifest.git -b master
```

