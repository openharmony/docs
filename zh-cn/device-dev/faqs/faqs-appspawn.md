# Appspawn应用孵化常见问题

## 系统启动中，appspawn启动失败

**现象描述**

系统启动过程中，系统停止开机动画中， 进入appspawn失败。

**可能原因**

1. 开机动画未能正常退出。
2. 拉起系统应用失败， 导致appspawn启动失败。

**解决办法**

需要通过日志确认崩溃或报错退出的服务，并解决其崩溃/报错的问题，然后重新烧写镜像即可。

## 冷启动应用失败

**现象描述**

通过 aa start -d 12345 -a \$name -b \$package -C 拉起应用失败。

**可能原因**

1. 冷启动未能生效。
2. 确认冷启动命令正确。

**解决办法**

1. 需要设置 param set appspawn.cold.boot true 确认冷启动时候生效。
2. 确认冷启动命令正确。

## 应用沙盒创建失败

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