# OpenHarmony版本定义

## 分支关系

为了保障OpenHarmony社区版本的平滑演进和历史发布版本的持续稳定可靠，会定期从Master主干拉出LTS/Release/Beta等类型分支，并按照OpenHarmony生命周期定义对其进行管理。


### Master （主干分支）

Master作为OpenHarmony社区持续滚动开发的主干，积极接纳社区每个软件包主干开发分支的代码更新，将其纳入主干实时构建。

###  LTS分支（长期支持维护分支）

OpenHarmony社区LTS分支为长期支持维护分支，按年度从Master主干分支拉出来。该LTS分支在经过集中编译、构建、集成测试并最终通过社区评审发布。

### Release分支（发布分支）

OpenHarmony社区Release分支为社区发布的稳定分支。该分支在经过集中编译、构建、集成测试并最终通过社区评审发布。其与LTS分支的发布要求一致，但其维护周期短于LTS分支。

### Beta分支（测试分支）

OpenHarmony社区Beta分支是在社区开发和演进过程中不定期从Master主干分支拉出来。该分支仅完成集中编译、构建、基础功能验证，可用于开发调试。

### 标签版本

OpenHarmony社区基于LTS/Release分支以patch形式合入少量补丁代码，用于解决单点bug、安全漏洞、以及其他必须的适配修改，经过集成验证之后发布的稳定可靠的标签版本。

社区版本发布在：https://gitee.com/openharmony/docs/tree/master/zh-cn/release-notes

## 生命周期策略

OpenHarmony社区依据《[OpenHarmony版本生命周期管理](https://gitee.com/openharmony/release-management/blob/master/OpenHarmony%E7%94%9F%E5%91%BD%E5%91%A8%E6%9C%9F%E5%8F%91%E5%B8%83%E5%85%AC%E5%91%8A.md)》对Release和LTS分支提供维护和技术支持。

### 维护时间表

OpenHarmony目前已发布的LTS/Release分支的维护时间表如下:

| 分支名        | 分支类型 | 发布时间  | 停止主动维护 | 停止维护  |
| ------------- | -------- | --------- | ------------ | --------- |
| 1.0.1-Release | Release  | 2021-3-30 | 2022-3-30    | 2023-3-30 |
| 3.0-LTS       | LTS      | 2021-9-30 | 2023-9-30    | 2025-3-30 |
| 3.1-Release   | Release  | 2022-3-30 | 2023-3-30    | 2024-3-30 |
| 3.2-Release   | Release  | 2023-4-9 | 2024-4-9    | 2025-4-9 |
| 4.0-Release   | Release  | 2023-10-26 | 2024-10-26    | 2025-10-26 |
| 4.1-Release   | Release  | 2024-3-30 | 2025-3-30    | 2026-3-30 |

分支下载命令如下：

| 分支          | 下载命令（repo + https）                                     | 下载命令（repo + ssh)                                        |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 1.0.1-Release | repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony_1.0.1_release -m default.xml --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' | repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.1-Release -m default.xml --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' |
| 3.0-LTS       | repo init -u https://gitee.com/openharmony/manifest.git -b OpenHarmony-3.0-LTS --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' | repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.0-LTS --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' |
| 3.1-Release   | repo init -u https://gitee.com/openharmony/manifest.git -b OpenHarmony-3.1-Release -m default.xml --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' | repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.1-Release -m default.xml --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' |
| 3.2-Release   | repo init -u https://gitee.com/openharmony/manifest.git -b OpenHarmony-3.2-Release -m default.xml --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' | repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Release -m default.xml --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' |
| 4.0-Release   | repo init -u https://gitee.com/openharmony/manifest.git -b OpenHarmony-4.0-Release -m default.xml --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' | repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.0-Release -m default.xml --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' |
| 4.1-Release   | repo init -u https://gitee.com/openharmony/manifest.git -b OpenHarmony-4.1-Release -m default.xml --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' | repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-4.1-Release -m default.xml --no-repo-verify<br/>repo sync -c<br/>repo forall -c 'git lfs pull' |



### 版本计划

OpenHarmony Release sig团队定期发布和更新维护分支版本计划，详情可参考：https://gitee.com/openharmony-sig/oh-inner-release-management/blob/master/OpenHarmony-SIG-RoadMap.md







