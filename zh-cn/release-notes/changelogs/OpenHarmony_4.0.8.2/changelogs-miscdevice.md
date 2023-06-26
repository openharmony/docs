# 泛Sensor子系统Changelog


## cl.vibrator.1 新增自定义振动相关属性

新增自定义振动效果属性VibrateFromFile，自定义振动配置文件描述符属性HapticFileDescriptor；振动下发接口startVibration支持的振动效果由VibrateEffect = VibrateTime | VibratePreset扩展为VibrateEffect = VibrateTime | VibratePreset | VibrateFromFile。

**变更影响**

基于OpenHarmony4.0.8.2及之后的SDK版本开发的应用，可使用VibrateFromFile属性在支持自定义振动的设备上播放自定义振动文件中配置的振动序列。

**关键接口/组件变更**

@ohos.vibrator.d.ts中新增属性VibrateFromFile，HapticFileDescriptor。

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|  -- | -- | -- | -- |
| @ohos.vibrator.d.ts | vibrator | HapticFileDescriptor | 新增 |
| @ohos.vibrator.d.ts | vibrator | VibrateFromFile | 新增 |

**适配指导**<br>

通过资源管理接口获取振动配置文件资源，启动自定义振动并停止。

```ts
import vibrator from '@ohos.vibrator';
import resourceManager from '@ohos.resourceManager';

const FILE_NAME = "xxx.json";

async function openResource(fileName) {
    let fileDescriptor = undefined;
    let mgr = await resourceManager.getResourceManager();
    await mgr.getRawFd(fileName).then(value => {
        fileDescriptor = {fd: value.fd, offset: value.offset, length: value.length};
        console.log('openResource success fileName: ' + fileName);
    }).catch(error => {
        console.log('openResource err: ' + error);
    });
    return fileDescriptor;
}

async function closeResource(fileName) {
    let mgr = await resourceManager.getResourceManager();
    await mgr.closeRawFd(fileName).then(()=> {
        console.log('closeResource success fileName: ' + fileName);
    }).catch(error => {
        console.log('closeResource err: ' + error);
    });
}

// 获取振动文件资源描述符
let rawFd = openResource(FILE_NAME);
// 使用startVibration、stopVibration需要添加ohos.permission.VIBRATE权限
try {
    // 启动自定义振动
    vibrator.startVibration({
        type: "file",
        hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }
    }, {
        usage: "alarm"
    }).then(() => {
        console.info('startVibration success');
    }, (error) => {
        console.info('startVibration error');
    });
    // 停止所有类型的马达振动
    vibrator.stopVibration(function (error) {
        if (error) {
            console.log('error.code' + error.code + 'error.message' + error.message);
            return;
        }
        console.log('Callback returned to indicate successful.');
    })
} catch (error) {
    console.info('errCode: ' + error.code + ' ,msg: ' + error.message);
}
// 关闭振动文件资源
closeResource(FILE_NAME);
```
