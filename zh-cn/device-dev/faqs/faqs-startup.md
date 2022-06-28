# startup常见问题

## 启动恢复常见问题

### 系统启动过程中打印“parse failed!”错误后停止启动

**现象描述**

系统启动过程中，打印“[Init] InitReadCfg, parse failed! please check file /etc/init.cfg format.”错误，启动过程停止，如下图所示：

  **图1** 运行报错图

  ![zh-cn_image_0000001200053087](figures/zh-cn_image_0000001200053087.png)

**可能原因**

修改init.cfg文件时，漏掉或多加了逗号或括号等，导致init.cfg文件的json格式被破坏。

**解决办法**

仔细检查init.cfg文件，确保其格式符合json格式要求。


### 系统启动过程未结束就自动重启，如此反复持续

**现象描述**

镜像烧写完成后系统启动，启动过程未完成即自动重新启动，如此反复持续。

**可能原因**

被init启动的服务都有一个叫做“importance”的属性（详见[第2章表3](../subsystems/subsys-boot-init.md)描述）。

- 当该属性为0时，表示若当前服务进程退出，init不需要重启单板。

- 当该属性为1时，表示若当前服务进程退出，init需要重启单板。

因此出现上述现象的可能原因：有“importance”属性为1的服务在每次启动的过程中都会退出（可能是进程崩溃或出错自动退出），导致init进程自动重启单板。

**解决办法**

1. 需要通过日志确认崩溃或报错退出的服务，并解决其崩溃/报错的问题，然后重新烧写镜像即可。

2. 也可以将崩溃/报错退出的服务的“importance”属性改为0，然后重新烧写镜像，这样即使其退出，init也不会重启单板。


### 参数正确的情况下调用SetParameter/GetParameter返回失败

**现象描述**

在各参数正确的情况下调用SetParameter/GetParameter返回失败。

**可能原因**

程序对SetParameter/GetParameter这两个接口做了权限校验，在各参数正确的情况下调用SetParameter/GetParameter返回操作失败，很有可能是调用者的uid大于1000，没有调用权限。

**解决办法**

无需处理


### ueventd服务启动后报获取socket失败，尝试创建

**现象描述**

ueventd服务启动后，首先出现打印 “Failed to get uevent socket, try to create”，并且应当伴随如下图所示错误日志：

  **图2** ueventd获取socket失败

  ![ueventd_socket](figures/ueventd_socket.png)

**可能原因**

由于ueventd服务是按需启动的服务，其启动后首先要做的就是从环境变量中拿到init为其创建的socket的fd。根据上述报错打印可知，是获取环境变量的值失败，这种情况可能是：
1. cfg文件中的ueventd服务没有配置socket，导致init并没有为其创建socket，也就没有相应的环境变量能够让其获取。
2. cfg文件中的ueventd服务已经配置了socket，但仍然有此现象，那可能是在另外一个cfg文件中重复配置了ueventd服务，并且其中没有配置socket。

**解决办法**

对于原因1，需要在cfg文件中对ueventd服务进行socket配置，具体可参看init.cfg中[ueventd服务的配置](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-boot-init.md#%E5%BC%80%E5%8F%91%E6%8C%87%E5%AF%BC)（开发指导第3部分）。

对于原因2，则需要查看所有cfg文件找到重复配置的ueventd服务，并将其删除，最终只保留一个有效的ueventd服务配置。

### ueventd服务轮询socket超时，并自动退出

**现象描述**

ueventd服务启动一段时间后，出现打印 “poll ueventd socket timeout, ueventd exit” 并自动退出。

**可能原因**

由于ueventd服务是按需启动的服务，其行为是当有uevent事件上报时，init监听到socket消息，会将ueventd服务拉起使其处理相应的socket消息，ueventd服务处理完现有的socket消息后，会自己再轮询对应socket句柄30秒，若30秒内又有新消息上报，则继续处理，待处理结束后再次计时轮询30秒；若超过30秒都没有新消息上报，ueventd服务将会退出，并将socket交还给init轮询，此时就会出现现象中的打印，因此这是一个正常的行为逻辑。

**解决办法**

正常行为，无需解决。

### 配置了ondemand属性的服务无法被正确解析启动

**现象描述**

一个符合json格式的服务配置无法被正确解析，打印 “Service is invalid which has both critical and ondemand attribute”，启动该服务时提示Cannot find service.

**可能原因**

首先应该确保该服务的配置符合json格式，否则将导致所在cfg文件解析失败，服务自然也会解析失败。其次需要检查配置了ondemand属性的服务，是否同时配置了critical属性值为1，或者critical属性数组的第一个值为1，若是如此，将导致服务解析失败，这是因为ondemand属性默认是按需启动的，只有当需要时才会拉起，空闲时退出，而配置了critical属性的服务被认为是系统关键服务，不可退出，所以这两种属性在同一服务中共存是不合理的，因此在逻辑上做了屏蔽处理。

**解决办法**

确认该服务是否要做成按需启动的服务，如果不是，就不需要配置ondemand属性；如果是，则在配置了ondemand属性后，不可再配置critical属性，若是需要critical中的服务异常退出次数限制，请将critical属性数组中的第一个值配置为0再加次数限制，例如"critical" : [0, 15, 5]，代表该服务在5秒钟内启动退出超过15次，将不再启动该服务，并且不会导致系统重启。


### 配置了ondemand属性的服务不受并行启动控制

**现象描述**

配置了ondemand属性的服务并没有在并行启动阶段被拉起，不论是将start-mode配置为boot，normal还是使用缺省配置。

**可能原因**

由于ondemand属性是控制服务按需启动的属性，对于按需启动的服务，应当是当需要时，即满足其启动条件时启动，因此并行启动不会拉起配置有ondemand属性的服务，这是正常的行为逻辑。

**解决办法**

若要一个服务加入并行启动，不应为其配置ondemand属性。

### SA按需启动服务无法实现按需拉起

**现象描述**

将一个SA服务配置为按需启动的情况下，在SA客户端发送请求后，samgr并没有动态拉起SA服务。

**可能原因**

在SA服务实现按需启动初期，还是使用统一接口SystemAbilityManager::CheckSystemAbility(int32_t systemAbilityId)，后续为了将按需启动的SA服务区分开来，专门新增了samgr提供的动态加载接口LoadSystemAbility(int32_t systemAbilityId, const sptr& callback)，原接口不适配按需启动的SA服务，故可能是接口使用错误导致SA服务未能按需拉起。

**解决办法**

在按需启动的SA服务中使用samgr提供的动态加载接口LoadSystemAbility(int32_t systemAbilityId, const sptr& callback)。

### dac配置不合理

**现象描述**

dac 配置错误，会导致配置失效，报错如下：
 ```
4.619955] [pid=1 0][Init][ERROR][init_capability.c:119]service=multimodalinput not support caps = CAP_DC_OVERRIDE caps 41
[ 4.620014] [pid=1 0][Init][ERROR][init_service_manager.c:818]GetServiceSecon secon section not found, skip
[ 4.620216] [pid=1 0][Init][ERROR][init_service_manager.c:818]GetServiceSecon secon section not found, skip
[ 4.620608] [pid=1 0][Init][ERROR][init_capability.c:119]service=mmi_uinput_service  not support caps = CAP_DC_OVERRIDE caps 41
```
**可能原因**

1. caps配置问题，防止配置最大属性。
2. 带CAP和非CAP开头的解析能力。
3. const问题。

**解决办法**

1. 支持带CAP和非CAP开头的解析能力。
2. 解决caps配置问题，防止配置最大属性。
3. 添加const属性文件，修复可以产品覆盖平台的。

### critical属性配置不生效

**现象描述**

配置critical 不生效。

**可能原因**

1. critical 配置格式是否有效。
2. 配置critical 的服务是否拉起。
3. 修改的配置文件是否生效。

**解决办法**

1. 修改配置文件格式可能存在问题。
2. 配置critical的服务可能不存在。
3. 不同设备对应的配置文件不同。3516设备修改init.cfg， RK3568设备修改init.without_two_stages.cfg。

### 不支持socket类进程按需启动

**现象描述**

不支持socket类进程按需启动。

**可能原因**

ueventd按需启动，DISABLE_INIT_TWO_STAGES宏的修改失效。

**解决办法**

在startUeventd中关闭socket，未能在在创建socket函数中增加了对socket有效性的检查， 故可能未做socket有效性检查导致的异常。


### 小型系统编译告警

**现象描述**

warning: implicit declaration of function 'usleep' is invalid in C99。
warning: implicit declaration of function 'setgroups' is invalid in C99。

**可能原因**

头文件可能包含错误， _GNU_SOURCE宏可能未打开。

**解决办法**

检查对应头文件是否包含正确， 如果正确， _GNU_SOURCE宏是否打开。

## Appspawn应用孵化常见问题

### 系统启动中，appspawn启动失败

**现象描述**

系统启动过程中，系统停止开机动画中， 进入appspawn失败。

**可能原因**

1. 开机动画未能正常退出。
2. 拉起系统应用失败， 导致appspawn启动失败。

**解决办法**

需要通过日志确认崩溃或报错退出的服务，并解决其崩溃/报错的问题，然后重新烧写镜像即可。

### 冷启动应用失败

**现象描述**

通过冷启动命令拉起应用失败。
  ```
  aa start -d 12345 -a $name -b $package -C
  ```

**可能原因**

1. 冷启动未能生效。
2. 确认冷启动命令正确。

**解决办法**

1. 需要设置 param set appspawn.cold.boot true 确认冷启动时候生效。
2. 确认冷启动命令正确。

### 应用沙盒创建失败

**现象描述**

systemui启动失败，卡顿在OpenHarmony开机动画中，或者计算器应用无法点击， 字体不能正常显示等。hilog日志中报错：
 - bind mount `<src-path>` to `<sandbox-path>` failed errno `<errorCode>`。
 - private mount to `<sandbox-path>`  failed errno `<errorCode>`。
 - symlink failed, `<link-name>`, errno is `<errorCode>`。

**可能原因**

1. 沙盒流程创建是否正确。
2. com.ohos.systemui 沙盒创建失败。
3. 沙盒应用依赖的文件配置失败。

**解决办法**

1. 查看hilog日志中，出现的相关hilog报错信息，针对报错修改对应的json文件。
2. 查看对应应用的pid情况，排查沙盒建立过程的代码逻辑，以及相应的json配置的正确性。