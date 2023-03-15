# pmm


## 命令功能

查看系统内存物理页及pagecache物理页使用情况。


## 命令格式

pmm


## 参数说明

无


## 使用指南

Debug版本才具备的命令。


## 使用实例

举例：输入pmm


## 输出说明

**示例** 查看物理页使用情况

```
OHOS # pmm
 phys_seg      base         size        free_pages
 --------      -------      ----------  ---------
 0x4065552c    0x809b0000   0x07550000      22344
order = 0, free_count = 16
order = 1, free_count = 12
order = 2, free_count = 8
order = 3, free_count = 6
order = 4, free_count = 13
order = 5, free_count = 16
order = 6, free_count = 12
order = 7, free_count = 4
order = 8, free_count = 79
active   anon   0
inactive anon   0
active   file   1385
inactice file   84
pmm pages: total = 30032, used = 7688, free = 22344
pathCache number = 325
pathCache memory size = 17621(B)
Vnode number = 67
Vnode memory size = 10720(B)
```

**表1** 输出说明

| 输出 | 说明 | 
| -------- | -------- |
| phys_seg | 物理页控制块地址信息 | 
| base | 第一个物理页地址，即物理页内存起始地址 | 
| size | 物理页内存大小 | 
| free_pages | 空闲物理页数量 | 
| active&nbsp;anon | pagecache中，活跃的匿名页数量 | 
| inactive&nbsp;anon | pagecache中，不活跃的匿名页数量 | 
| active&nbsp;file | pagecache中，活跃的文件页数量 | 
| inactive&nbsp;file | pagecache中，不活跃的文件页数量 | 
| pmm&nbsp;pages | total：总的物理页数，used：已使用的物理页数，free：空闲的物理页数 | 
