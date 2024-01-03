# app和deviceConfig的切换


为了便于开发者维护应用级别的属性配置，Stage模型将config.json中的app和deviceConfig标签提取到了app.json5中进行配置，并对部分标签名称进行了修改，具体差异见下表。


  **表1** 配置文件app标签差异对比

| 配置项 | FA模型配置文件config.json中app标签 | Stage模型配置文件app.json5中app标签 |
| -------- | -------- | -------- |
| 应用的版本号 | "version": {<br/>    "code": 1,<br/>} | "versionCode":&nbsp;1&nbsp;, |
| 标识版本号的文字描述，用于向用户展示 | "version": {<br/>    "name": "1.0.0",<br/>} | "versionName"&nbsp;:&nbsp;"1.0.0"&nbsp;, |
| 标识应用可兼容的最低版本号 | "version": {<br/>    "minCompatibleVersionCode":  1,<br/>} | "minCompatibleVersionCode"&nbsp;:&nbsp;1&nbsp;, |
| 运行应用所需要的最低API版本 | "apiVersion": {<br/>    "compatible":  7,<br/>}            | "minAPIVersion"&nbsp;:&nbsp;7&nbsp;, |
| 应用运行所需的目标API版本 | "apiVersion": {<br/>    "target":  8,<br/>} | "targetApiVersion"&nbsp;:&nbsp;8&nbsp;, |
| 应用运行所需的目标API版本的类型 | "apiVersion": {<br/>    "releaseType":  Release,<br/>} | "apiReleaseType":&nbsp;"Release"&nbsp;, |


app.json5中对原先config.json中的[deviceConfig](../quick-start/deviceconfig-structure.md)标签进行了重构，将deviceConfig下的标签的设备信息整合到了[app.json5](../quick-start/app-configuration-file.md)的app标签下，具体差异见下表。


  **表2** 配置文件deviceConfig标签差异对比

| FA中deviceConfig标签 | 描述 | stage模型中 | 差异比对 |
| -------- | -------- | -------- | -------- |
| deviceConfig标签 | deviceConfig标签配置了设备信息。 | / | Stage模型中没有该标签，直接在app标签下配置设备信息。 |
| process | 标识应用或者UIAbility的进程名。如果在deviceConfig标签下配置了process标签，则该应用的所有UIAbility都运行在这个进程中。如果在abilities标签下也为某个UIAbility配置了process标签，则该UIAbility就运行在这个进程中。 | / | Stage模型不支持配置进程名称。 |
| keepAlive | 标识应用是否始终保持运行状态，仅支持系统应用配置，三方应用配置不生效。 | / | Stage模型不支持系统应用模型管控方式变更。 |
| supportBackup | 标识应用是否支持备份和恢复。 | / | Stage模型不支持。 |
| compressNativeLibs | 标识libs库是否以压缩存储的方式打包到HAP。 | / | Stage模型不支持。 |
| network | 标识网络安全性配置。 | / | Stage模型不支持。 |
