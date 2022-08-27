# 配置其他子系统


除上述子系统之外，还有一些必要但是无需进行移植的子系统。如：分布式任务调度子系统、DFX子系统。


  这些子系统添加方式比较简单，在“vendor/MyVendorCompany/MyProduct/config.json”文件中进行如下配置即可：
  
```
{
  "subsystem": "distributed_schedule",
  "components": [
    { "component": "system_ability_manager", "features":[] }  # 此处部件名不同版本可能有变化，请根据实际代码填写
  ]
},
{
  "subsystem": "hiviewdfx",
  "components": [
    { "component": "hilog_lite", "features":[] },
    { "component": "hievent_lite", "features":[] }
  ]
},
```
