# 应用上下文<a name="ZH-CN_TOPIC_0000001163812234"></a>

-   [导入模块](#zh-cn_topic_0000001173324607_s1959b1529f574b74861e62008289bb21)
-   [权限列表](#zh-cn_topic_0000001173324607_section11257113618419)
-   [app.getInfo](#zh-cn_topic_0000001173324607_s0e8ff40704e442bc87a848afa47bdfbb)
-   [app.terminate](#zh-cn_topic_0000001173324607_section974325124119)

## 导入模块<a name="zh-cn_topic_0000001173324607_s1959b1529f574b74861e62008289bb21"></a>

```
import app from '@system.app';
```

## 权限列表<a name="zh-cn_topic_0000001173324607_section11257113618419"></a>

无

## app.getInfo<a name="zh-cn_topic_0000001173324607_s0e8ff40704e442bc87a848afa47bdfbb"></a>

getInfo\(\): <[AppResponse](#zh-cn_topic_0000001173324607_t3e93239d9b134b80957bcdd4acb05291)\>

获取当前应用配置文件中声明的信息。

-   返回值

    **表 1**  AppResponse

    <a name="zh-cn_topic_0000001173324607_t3e93239d9b134b80957bcdd4acb05291"></a>
    <table><tbody><tr id="zh-cn_topic_0000001173324607_recc81d9f995d44aa87ba9d714b756569"><td class="cellrowborder" valign="top" width="19%"><p id="zh-cn_topic_0000001173324607_aa3137ce511d140fba6cc93513a7a91e3"><a name="zh-cn_topic_0000001173324607_aa3137ce511d140fba6cc93513a7a91e3"></a><a name="zh-cn_topic_0000001173324607_aa3137ce511d140fba6cc93513a7a91e3"></a>参数名</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%"><p id="zh-cn_topic_0000001173324607_a6b166163db284e5ca8dc0190b36ae40a"><a name="zh-cn_topic_0000001173324607_a6b166163db284e5ca8dc0190b36ae40a"></a><a name="zh-cn_topic_0000001173324607_a6b166163db284e5ca8dc0190b36ae40a"></a>类型</p>
    </td>
    <td class="cellrowborder" valign="top" width="68%"><p id="zh-cn_topic_0000001173324607_a4ba8ead9ee7b48298d9a6ed10659f13b"><a name="zh-cn_topic_0000001173324607_a4ba8ead9ee7b48298d9a6ed10659f13b"></a><a name="zh-cn_topic_0000001173324607_a4ba8ead9ee7b48298d9a6ed10659f13b"></a>说明</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324607_row2557173813243"><td class="cellrowborder" valign="top" width="19%"><p id="zh-cn_topic_0000001173324607_p898462584011"><a name="zh-cn_topic_0000001173324607_p898462584011"></a><a name="zh-cn_topic_0000001173324607_p898462584011"></a>appID<sup id="zh-cn_topic_0000001173324607_sup193948321350"><a name="zh-cn_topic_0000001173324607_sup193948321350"></a><a name="zh-cn_topic_0000001173324607_sup193948321350"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="13%"><p id="zh-cn_topic_0000001173324607_p698492564013"><a name="zh-cn_topic_0000001173324607_p698492564013"></a><a name="zh-cn_topic_0000001173324607_p698492564013"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="68%"><p id="zh-cn_topic_0000001173324607_p1998432514020"><a name="zh-cn_topic_0000001173324607_p1998432514020"></a><a name="zh-cn_topic_0000001173324607_p1998432514020"></a>表示应用的包名，用于标识应用的唯一性。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324607_r64430cb15b54497f88ea6330b9a7454c"><td class="cellrowborder" valign="top" width="19%"><p id="zh-cn_topic_0000001173324607_a7cccea39636b47cd83188d400eed51e3"><a name="zh-cn_topic_0000001173324607_a7cccea39636b47cd83188d400eed51e3"></a><a name="zh-cn_topic_0000001173324607_a7cccea39636b47cd83188d400eed51e3"></a>appName</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%"><p id="zh-cn_topic_0000001173324607_a2f72300143c441ef9a3fb5dc2f8e4aac"><a name="zh-cn_topic_0000001173324607_a2f72300143c441ef9a3fb5dc2f8e4aac"></a><a name="zh-cn_topic_0000001173324607_a2f72300143c441ef9a3fb5dc2f8e4aac"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="68%"><p id="zh-cn_topic_0000001173324607_a1c9b8d1829ef489e9e0fd1863190d228"><a name="zh-cn_topic_0000001173324607_a1c9b8d1829ef489e9e0fd1863190d228"></a><a name="zh-cn_topic_0000001173324607_a1c9b8d1829ef489e9e0fd1863190d228"></a>表示应用的名称。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324607_r4f8f612a65b24ae9b75ae53893aeb3b9"><td class="cellrowborder" valign="top" width="19%"><p id="zh-cn_topic_0000001173324607_ae036f88e139e4379abdaf4969f0720ea"><a name="zh-cn_topic_0000001173324607_ae036f88e139e4379abdaf4969f0720ea"></a><a name="zh-cn_topic_0000001173324607_ae036f88e139e4379abdaf4969f0720ea"></a>versionName</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%"><p id="zh-cn_topic_0000001173324607_a1d379931a20144f0b6d98f5396202cd9"><a name="zh-cn_topic_0000001173324607_a1d379931a20144f0b6d98f5396202cd9"></a><a name="zh-cn_topic_0000001173324607_a1d379931a20144f0b6d98f5396202cd9"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="68%"><p id="zh-cn_topic_0000001173324607_a70c91c442f7c41439a90ceb9041252e8"><a name="zh-cn_topic_0000001173324607_a70c91c442f7c41439a90ceb9041252e8"></a><a name="zh-cn_topic_0000001173324607_a70c91c442f7c41439a90ceb9041252e8"></a>表示应用的版本名称。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001173324607_r89cf0afd5f444bd1b66ace0c31a25cda"><td class="cellrowborder" valign="top" width="19%"><p id="zh-cn_topic_0000001173324607_a3a86c086e40e475b8fb26cf43fe9a8d6"><a name="zh-cn_topic_0000001173324607_a3a86c086e40e475b8fb26cf43fe9a8d6"></a><a name="zh-cn_topic_0000001173324607_a3a86c086e40e475b8fb26cf43fe9a8d6"></a>versionCode</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%"><p id="zh-cn_topic_0000001173324607_abcfd352ff3d84552938de0e2daf0703e"><a name="zh-cn_topic_0000001173324607_abcfd352ff3d84552938de0e2daf0703e"></a><a name="zh-cn_topic_0000001173324607_abcfd352ff3d84552938de0e2daf0703e"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="68%"><p id="zh-cn_topic_0000001173324607_af943e2ec7622407387d25d9331a01245"><a name="zh-cn_topic_0000001173324607_af943e2ec7622407387d25d9331a01245"></a><a name="zh-cn_topic_0000001173324607_af943e2ec7622407387d25d9331a01245"></a>表示应用的版本号。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    var info = app.getInfo();
    console.log(JSON.stringify(info));
    ```


## app.terminate<a name="zh-cn_topic_0000001173324607_section974325124119"></a>

terminate\(\): void

退出当前Ability

-   示例

    ```
    app.terminate();
    ```


