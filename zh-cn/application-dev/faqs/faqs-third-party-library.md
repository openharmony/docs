# 三四方库使用常见问题

## 报错“Stage model module … does not support including OpenHarmony npm packages or modules in FA model. OpenHarmony build tasks will not be executed, and OpenHarmony resources will not be packed. ”如何解决

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

三四方件未适配API9 Stage模型，无法使用。

## 项目是否支持传递依赖

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

比如项目A依赖项目B，项目B依赖项目C，那项目A是否能直接使用项目C提供的接口？

不支持。由于项目打包使用npm工具，npm不支持传递依赖。可以在项目A增加项目C的依赖来解决问题。

## 如何获取可用的三方库

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

参见：[OpenHarmony上可直接使用的三方组件汇总](https://gitee.com/openharmony-sig/third_party_app_libs)。

## 网络相关的三方库有哪些

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

网络相关的三方库有[Axios](https://gitee.com/openharmony-sig/axios)。

## 如何使用npm引入三四方库

  适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型
- 方法一：
  1. 打开Terminal窗口，通过如下指令进入到entry目录。
        
      ```
      cd entry
      ```
  2. 以引入“dayjs”为例，执行以下指令进行安装。
        
      ```
      npm install dayjs --save
      ```
  3. 在对应的js文件中直接引用。
        
      ```
      import dayjs from 'dayjs'; 
      ```

- 方法二：
  1. 打开工程目录下的entry目录，找到该目录下的package.json文件。
  2. 在package.json文件中写入想要安装的三方npm，以“dayjs”为例，示例如下：
        
      ```
      {
        "dependencies": {
          "dayjs": "^1.10.4",
        }
      }
      ```
  3. 打开Terminal窗口，通过如下指令进入到entry目录。
        
      ```
      cd entry
      ```
  4. 执行指令进行安装。
        
      ```
      npm install
      ```
  5. 在对应的js文件中直接引用。
        
      ```
      import dayjs from 'dayjs'; 
      ```
<!--no_check-->