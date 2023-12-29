# OpenHarmony Version Definitions

## Branches

To ensure smooth version evolution and continuous stability and reliability of historical versions, the OpenHarmony community periodically pulls branches such as Long Term Support (LTS), Release, and Beta from Master and manages them based on the OpenHarmony lifecycle definition.


### Master

Master is the main branch in the OpenHarmony community, to which code updates of all software packages' Master branches in the community are proactively merged for real-time build.

###  LTS

LTS is a branch pulled from Master in the OpenHarmony community by year. This branch is compiled, built, and tested in a centralized manner, and finally reviewed and released by the community.

### Release

Release is a stable branch released in the OpenHarmony community. This branch is compiled, built, and tested in a centralized manner, and finally reviewed and released by the community. A Release branch has the same release requirements but a shorter maintenance period when compared with an LTS branch.

### Beta

Beta is a branch pulled from Master in the OpenHarmony community irregularly. This branch has centralized compilation, building, and basic function verification finished, and can be used for development and debugging.

### Tag

A tag version is a stable and reliable version created by applying patches to an LTS or a Release branch, with the purpose of fixing individual bugs, security vulnerabilities, and other necessary adaptation modifications.

The release versions are available in the [**Release Notes** folder](../).

## Lifecycle Policies

The OpenHarmony community provides maintenance and technical support for Release and LTS branches based on the OpenHarmony Version Lifecycle Management. The OpenHarmony community provides maintenance and technical support based on the *OpenHarmony Version Lifecycle Management*.

### Maintenance Schedule

The following table lists the maintenance schedule of the LTS and Release branches that have been released in the OpenHarmony community.

| Branch Name       | Branch Type| Release Date | End of Proactive Maintenance| End of Maintenance |
| ------------- | -------- | --------- | ------------ | --------- |
| 1.0.1-Release | Release  | 2021-03-30| 2022-03-30   | 2023-03-30|
| 3.0-LTS       | LTS      | 2021-09-30| 2023-09-30   | 2025-03-30|
| 3.1-Release   | Release  | 2022-03-30| 2023-03-30   | 2024-03-30|
| 3.2-Release   | Release  | 2023-4-9 | 2024-4-9    | 2025-4-9 |

Run the following commands to download the source code of each branch:

| Branch         | Download Command (repo + https)                                    | Download Command (repo + ssh)                                       |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 1.0.1-Release | repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony_1.0.1_release -m default.xml --no-repo-verify<br>repo sync -c<br>repo forall -c 'git lfs pull' | repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.1-Release -m default.xml --no-repo-verify<br>repo sync -c<br>repo forall -c 'git lfs pull' |
| 3.0-LTS       | repo init -u https://gitee.com/openharmony/manifest.git -b OpenHarmony-3.0-LTS --no-repo-verify<br>repo sync -c<br>repo forall -c 'git lfs pull' | repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.0-LTS --no-repo-verify<br>repo sync -c<br>repo forall -c 'git lfs pull' |
| 3.1-Release   | repo init -u https://gitee.com/openharmony/manifest.git -b OpenHarmony-3.1-Release -m default.xml --no-repo-verify<br>repo sync -c<br>repo forall -c 'git lfs pull' | repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.1-Release -m default.xml --no-repo-verify<br>repo sync -c<br>repo forall -c 'git lfs pull' |
| 3.2-Release   | repo init -u https://gitee.com/openharmony/manifest.git -b OpenHarmony-3.2-Release -m default.xml --no-repo-verify<br>repo sync -c<br>repo forall -c 'git lfs pull' | repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Release -m default.xml --no-repo-verify<br>repo sync -c<br>repo forall -c 'git lfs pull' |



### Version Plan

The OpenHarmony Release SIG periodically releases, updates, and maintains branch version plans. For details, visit [OpenHarmony-SIG-RoadMap](https://gitee.com/openharmony-sig/oh-inner-release-management/blob/master/OpenHarmony-SIG-RoadMap.md).
