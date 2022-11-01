# IDE使用常见问题

## 如何解决报错“npm ERR! code SELF_SIGNED_CERT_IN_CHAIN”

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 在Dev Eco Studio terminal中执行npm config set strict-ssl=false；

2. 在Dev Eco Studio terminal中执行npm install。

## 手工更新DevEco的SDK后，编译HAP报错“Cannot find module 'xxx\ets\x.x.x.x\build-tools\ArkTS-loader\node_modules\webpack\bin\webpack.js'” 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 到SDK的ets\x.x.x.x\build-tools\ets-loader目录下执行npm install；

2. 到SDK的js\x.x.x.x\build-tools\ace-loader目录下执行npm install。 完成步骤后重新编辑。

## 安装系统应用比如HMS Core时，报releaseType不匹配，如何解决

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

先卸载原型机上的hmscore，执行以下命令后，再安装。

  
```
hdc_std shell mount -o rw,remount /
hdc_std shell rm -rf /system/app/HMSCore
hdc_std shell mount -o remount,rw /
hdc_std shell rm /data/* -rf
hdc_std shell sync
hdc_std shell /system/bin/udevadm trigger
hdc_std shell reboot
```

## 如何通过命令行打包HAP

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

方式一：运行hvigor assembleHap。

方式二：在工程的package.json的scripts中，定义构建任务脚本后，运行npm buildOhosHaps。“buildOhosHaps”字段可以自定义。

  
```
"scripts": {
  "buildOhosHaps": "hvigor assembleHap"
},
```

## 如何使用Matepad11运行应用并显示内容

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 确认设备apiversion的指令

2. 确定“compileSdkVersion”“compatibleSdkVersion” “apiversion”“releasetype” “API version ”这些名称的关系

3. 具体参考：[测试运行](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/faq-debugging-and-running-0000001122066466#section72441218359)

## DevEco创建新工程为什么选不到API9 

适用于：DevEco Studio 3.0 Beta4 3.0.0.993(B06)版本

创建新工程的时候，首先要选择OpenHarmony页签再创建工程就可以选到API9。

![zh-cn_image_0000001366477556](figures/zh-cn_image_0000001366477556.png)

## 下载时收不到回调且无法返回错误码（）

适用于：OpenHarmony所有版本

1）重装hdc命令： hdc_std重裝 拉起 设备连接

2）关闭日志限流 ：hdc_std shell hilog -Q pidoff 打开"

## IDE点击run按钮后，报错：error: unknow option. usage: aa start &lt;options&gt;

适用于：OpenHarmony SDK 3.2.5.6版本，API9 Stage模型

报错原因：aa命令参数错误，执行打开应用操作报错。

有2种处理方法：

1. 检查SDK版本和OS版本，确保SDK版本和OS版本一致。

2. 点击设备上app图标，手动启动app进行使用。

## IDE运行app报错：The hdc_std version of the SDK does not match the hdcd version of the device.

适用于：OpenHarmony SDK 3.2.5.6版本，API9 Stage模型

hdc 和 hdcd版本不匹配 ，请更新IDE至Dev Eco 3.0.1.993及以上版本。

旧版本IDE检测不匹配会拦截安装，新版本IDE仅提醒不影响正常使用。

## 如何在OpenHarmony 的SDK中加入自定义的\*.d.ts文件 

适用于：OpenHarmony SDK 3.1.7.7版本 ,  API8 FA模型

将dts文件命名为\@ohos.xxxx.d.ts ,  放入SDK的路径中，重启IDE。引入时会有代码提醒。

![zh-cn_image_0000001374227840](figures/zh-cn_image_0000001374227840.png)

## 云桌面能连测试机吗

适用于：OpenHarmony SDK 3.2.5.5版本

可以连HarmonyOS设备，但是不能连openHarmony的设备

## 如何替换full-SDK

适用于：OpenHarmony SDK 3.2.7.5版本

参考文档[full-SDK替换指南](../quick-start/full-sdk-switch-guide.md)
