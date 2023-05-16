# 原子化服务空间管理（仅对系统应用开放）

从用户的角度，用户不感知原子化服务的安装，也不会主动的卸载原子化服务；从操作系统的角度，原子化服务使用[免安装特性](../reference/apis/js-apis-freeInstall.md)，但并不是真的不安装。因此，为了减少系统空间占用，需要对原子化服务有序管理。

## 原子化服务数据目录配额管理

对原子化服务的数据沙箱目录设置存储配额上限，可通过系统参数persist.sys.bms.aging.policy.atomicservice.datasize.threshold获得，默认值50MB，当超过该配额限制时，写入数据返回失败。

查看和设置系统参数可使用[param get/set](../../device-dev/subsystems/subsys-boot-init-plugin.md)命令

## 主动销毁原子化服务

可以通过[uninstall](../reference/apis/js-apis-installer.md#bundleinstalleruninstall)接口主动销毁原子化服务。

**示例：**

```ts
import installer from '@ohos.bundle.installer';
let bundleName = 'com.ohos.demo';
let installParam = {
    userId: 100
};

try {
    installer.getBundleInstaller().then(data => {
        data.uninstall(bundleName, installParam, err => {
            if (err) {
                console.error('uninstall failed:' + err.message);
            } else {
                console.info('uninstall successfully.');
            }
        });
    }).catch(error => {
        console.error('getBundleInstaller failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInstaller failed. Cause: ' + error.message);
}
```

## 自动销毁原子化服务

### 自动销毁时机

- 定时器触发，其间隔可通过系统参数persist.sys.bms.aging.policy.timer.interval获得，默认8小时；要求剩余电量必须大于等于系统参数persist.sys.bms.aging.policy.battery.threshold，默认10%
- 安装原子化服务时触发
- 修改原子化服务可清理标识时触发

### 销毁条件

#### 原子化服务可销毁

- 通过[isHapModuleRemovable](../reference/apis/js-apis-freeInstall.md#ishapmoduleremovable)返回true
- 非运行状态

#### 销毁开始条件

当前系统所有原子化服务占用空间（包含安装目录和数据目录）大于系统参数persist.sys.bms.aging.policy.data.size.threshold，默认500MB

#### 销毁结束条件

当前系统所有原子化服务占用空间（包含安装目录和数据目录）小于系统参数persist.sys.bms.aging.policy.data.size.threshold的80%

### 自动销毁顺序

- 将可销毁的原子化服务按照最近使用时间区分到不同时间区域内，如[0, 10), [10, 20), [20, 30), [30, ~), 可通过系统参数persist.sys.bms.aging.policy.recently.used.threshold获得时间区域单位，默认是1天；
- 对于两个可销毁的原子化服务，若处于同一时间区域内优先销毁使用频率低的原子化服务；若处于不同时间区域内优先销毁长时间未使用的原子化服务。

### 分级自动销毁

- 当满足自动销毁开始条件时，按照销毁顺序优先销毁原子化服务的cache目录，若满足销毁结束条件，则退出；
- 若不满足，则按照销毁顺序再次清理原子化服务的其他目录。