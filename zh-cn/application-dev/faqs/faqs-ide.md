# IDE使用常见问题

## 如何解决报错“npm ERR! code SELF_SIGNED_CERT_IN_CHAIN”

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 在Dev Eco Studio terminal中执行npm config set strict-ssl=false；

2. 在Dev Eco Studio terminal中执行npm install。

## 手工更新DevEco的SDK后，编译HAP报错“Cannot find module 'xxx\ets\x.x.x.x\build-tools\ArkTS-loader\node_modules\webpack\bin\webpack.js'” 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 到SDK的ets\x.x.x.x\build-tools\ets-loader目录下执行npm install；

2. 到SDK的js\x.x.x.x\build-tools\ace-loader目录下执行npm install。 完成步骤后重新编辑。

## 如何通过命令行打包HAP

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

方式一：运行hvigor assembleHap。

方式二：在工程的package.json的scripts中，定义构建任务脚本后，运行npm buildOhosHaps。“buildOhosHaps”字段可以自定义。

  
```
"scripts": {
  "buildOhosHaps": "hvigor assembleHap"
},
```

## DevEco创建新工程为什么选不到API9

适用于：DevEco Studio 3.0 Beta4 3.0.0.993(B06)版本

创建新工程的时候，首先要选择OpenHarmony页签再创建工程就可以选到API9。

## 下载时收不到回调且无法返回错误码

适用于：OpenHarmony所有版本

1. 重装hdc命令： hdc_std重裝 拉起 设备连接

2. 关闭日志限流 ：hdc_std shell hilog -Q pidoff 打开"

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

将dts文件命名为\@ohos.xxxx.d.ts ,  放入SDK的路径中，重启IDE。

引入时会有代码提醒。

## 如何替换full-SDK

适用于：OpenHarmony SDK 3.2.7.5版本

参考文档[full-SDK替换指南](../quick-start/full-sdk-switch-guide.md)
<!--no_check-->