# memcheck<a name="ZH-CN_TOPIC_0000001134006252"></a>

-   [命令功能](#section191633812516)
-   [命令格式](#section428816435510)
-   [参数说明](#section1939943304411)
-   [使用指南](#section228914491951)
-   [使用实例](#section17373205314515)
-   [输出说明](#section13406205385413)

## 命令功能<a name="section191633812516"></a>

检查动态申请的内存块是否完整，是否存在内存越界造成节点损坏。

## 命令格式<a name="section428816435510"></a>

memcheck

## 参数说明<a name="section1939943304411"></a>

无。

## 使用指南<a name="section228914491951"></a>

-   当内存池所有节点完整时，输出"system memcheck over, all passed!"。
-   当内存池存在节点不完整时，输出被损坏节点的内存块信息。

## 使用实例<a name="section17373205314515"></a>

举例：

- 输入memcheck
- 输入memcheck出现内存越界

## 输出说明<a name="section13406205385413"></a>

**示例 1**  当前没有内存越界

```shell
OHOS # memcheck
system memcheck over, all passed!
```

**示例 2**  出现内存越界<a name="fig6414131084419"></a>  

```shell
[L0S DLnkCheckMenl 349, memory check
stFreeNodeInfo.pstPrev:0x7e0d31f3 is out of legal mem range[0x80ba5f40, 0х83d00000]
cur node: 0x81f2ce0c
pre node: 0x81f28a98
pre node was allocated by task:sofia
uwEхcTуpe = 0х2
puмExcBuffAddr pc = 0x803ad7a4
puwExcBuffAddr lr = 0x803ad7a4
puwExcBuffAddr sp = 0х80cb7de0
puwExcBuffAddr fp = 0x80cb7dec
*******backtrace begin*******
traceback 0 -- lr = 0х8037cb84
traceback 0 -- fp = 0х80cb7e1c
traceback 1 -- lr = 0х8037033c
traceback 1 -- fp = 0х80cb7e24
traceback 2 -- lr = 0x8000d108
traceback 2 -- fp = 0х80cb7e94
traceback 3 -- lr = 0х8037c7ac
traceback 3 -- fp = 0х80cb7ea4
traceback 4 -- lr = 0x803ad9e8
traceback 4 -- fp = 9x11111111
```

