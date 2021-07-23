# 开发板移植
目前OpenHarmony已经成立了SIG组[sig-devboard](https://gitee.com/openharmony/community/blob/master/sig/sig-devboard/sig_devboard_cn.md)。该SIG组以支持更多第三方开发板为目标，提供开发板移植的支撑。

在了解开发板移植前，需要先了解一下OpenHarmony对设备的分类。不同设备类型的移植方法会有较大差异。

| 设备类型    | 硬件要求        | 支持的内核          |
|---------|-------------|----------------|
| 轻量系统类设备 | 内存>128KB    | LiteOS-M       |
| 小型系统类设备 | 内存>1MB、有MMU | LiteOS-A、Linux |
| 标准系统类设备 | 内存>128MB    |  Linux       |

# 1. 代码准备

目前OpenHarmony已经为各厂家创建了仓库并在openharmony-sig中进行孵化。参与孵化仓开发，需要使用如下方法初始化和下载代码。

```shell
repo init -u https://gitee.com/openharmony-sig/manifest.git -b master -m devboard.xml --no-repo-verify
```

其他下载步骤与主线相同。

# 2. 开始移植你的开发板

- [轻量级系统](transplant-minichip.md)
- [小型系统](transplant-smallchip.md)
- [标准系统](standard-system-porting-guide.md)


