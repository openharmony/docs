# mediatool工具

mediatool是一个轻量级的命令行工具集合，开发者可通过此工具操作媒体库资源

## 前置条件

- 正常连接设备
- 系统设置中开启开发者模式
- 使用hdc shell进入命令行执行模式

## 命令行说明

- mediatool命令行使用方式：

  | 选项  | 参数                | 说明             | 返回值               | 返回值说明       |
  | ----- | ------------------- | ---------------- | -------------------- | ---------------- |
  | query | &lt;displayName&gt; | 要查询资源的名称 | vector&lt;string&gt; | 包含真实路径集合 |
  
  **使用示例：**

  ```shell
  mediatool query IMG_001.jpg
  ```
  
  **预期结果：**
  
     文件存在：find 1 result: /storage/cloud/100/files/Photo/3/IMG_001.jpg                                                                     
     文件不存在：The displayName you want to query do not exist

