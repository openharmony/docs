# 泛Sensor子系统Changelog

## cl.vibrator.isSupportEffect接口新增

新增isSupportEffect接口。

**变更影响**

基于OpenHarmony4.0.5.2及之后的SDK版本开发的应用，可使用isSupportEffect接口查询传入effectId是否支持。

**关键接口/组件变更**

@ohos.vibrator.d.ts中新增isSupportEffect接口。

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|  -- | -- | -- | -- |
| @ohos.vibrator.d.ts | vibrator | isSupportEffect(effectId: string, callback: AsyncCallback&lt;boolean&gt;): void | 新增 |
| @ohos.vibrator.d.ts | vibrator | isSupportEffect(effectId: string): Promise&lt;boolean&gt; | 新增 |

**适配指导**<br>

通过调用isSupportEffect接口查询是否支持传入的参数effectId。

```ts
import vibrator from '@ohos.vibrator';
try {
    // 查询是否支持'haptic.clock.timer'
    vibrator.isSupportEffect('haptic.clock.timer', function (err, state) {
        if (err) {
            console.error('isSupportEffect failed, error:' + JSON.stringify(err));
            return;
        }
        console.log('The effectId is ' + (state ? 'supported' : 'unsupported'));
        if (state) {
            try {
                vibrator.startVibration({ // 使用startVibration需要添加ohos.permission.VIBRATE权限
                    type: 'preset',
                    effectId: 'haptic.clock.timer',
                    count: 1,
                }, {
                    usage: 'unknown'
                }, (error) => {
                    if(error) {
                        console.error('haptic.clock.timer vibrator error:'  + JSON.stringify(error));
                    } else {
                        console.log('haptic.clock.timer vibrator success');
                    }
                });
            } catch (error) {
                console.error('Exception in, error:' + JSON.stringify(error));
            }
        }
    })
} catch (error) {
    console.error('Exception in, error:' + JSON.stringify(error));
}
```

## cl.vibrator.stopVibration接口新增

新增stopVibration接口。

**变更影响**

基于OpenHarmony4.0.5.2及之后的SDK版本开发的应用，可使用stopVibration接口停止所有类型的振动。

**关键接口/组件变更**

@ohos.vibrator.d.ts中新增stopVibration接口。

| 模块名              | 类名     | 方法/属性/枚举/常量                                      | 变更类型 |
| ------------------- | -------- | -------------------------------------------------------- | -------- |
| @ohos.vibrator.d.ts | vibrator | stopVibration(callback: AsyncCallback&lt;void&gt;): void | 新增     |
| @ohos.vibrator.d.ts | vibrator | stopVibration(): Promise&lt;void&gt;                     | 新增     |

**适配指导**<br>

通过调用stopVibration接口停止所有类型的振动。

```ts
import vibrator from '@ohos.vibrator';
try {
    // 停止所有模式的马达振动
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
```

