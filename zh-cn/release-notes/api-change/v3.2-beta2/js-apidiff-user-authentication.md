# 用户身份认证子系统JS API变更

OpenHarmony 3.2 Release版本相较于OpenHarmony 3.2 Beta1版本，用户身份认证子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.userIAM.faceAuth | ResultCode | FAIL = 1 | 新增 |
| ohos.userIAM.faceAuth | ResultCode | SUCCESS = 0 | 新增 |
| ohos.userIAM.faceAuth | FaceAuthManager | setSurfaceId(surfaceId: string): ResultCode; | 新增 |
| ohos.userIAM.faceAuth | FaceAuthManager | constructor(); | 新增 |
