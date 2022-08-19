# IDE使用常见问题



## 如何解决报错“npm ERR! code SELF_SIGNED_CERT_IN_CHAIN”？

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 在Dev Eco Studio terminal中执行npm config set strict-ssl=false；

2. 在Dev Eco Studio terminal中执行npm install。

## 手工更新DevEco的SDK后，编译HAP报错“Cannot find module 'xxx\ets\x.x.x.x\build-tools\ets-loader\node_modules\webpack\bin\webpack.js'” 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 到SDK的ets\x.x.x.x\build-tools\ets-loader目录下执行npm install；

2. 到SDK的js\x.x.x.x\build-tools\ace-loader目录下执行npm install。 完成步骤后重新编辑既可。
