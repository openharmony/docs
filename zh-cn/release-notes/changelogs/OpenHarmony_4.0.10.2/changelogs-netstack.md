# 网络管理子系统ChangeLog

## request2 接口名称变更

此前版本http流式请求的名称为request2，无法清楚的表达该接口的意图，且容易产生歧义，不符合OpenHarmony的API接口规范。
现做出如下变更：
  - request2接口名称更换为requestInStream。

## dataProgress 流式数据接收进度事件名称变更

此前版本http流式数据接收进度事件名称为dataProgress，无法清楚的表达该事件为数据接收事件，不符合OpenHarmony的API接口规范。
现做出如下变更：
  - dataProgress事件名称更换为dataReceiveProgress。

**变更影响**

基于此前版本开发的应用，需更改对应接口和监听事件名称，否则无法正常调用接口，影响原有业务逻辑。

**关键的接口/组件变更**

涉及接口

  - request2;
  - on(type: "dataProgress", callback: Callback<{ receiveSize: number, totalSize: number }>): void;
  - off(type: "dataProgress", callback: Callback<{ receiveSize: number, totalSize: number }>): void;

变更前：
  - request2(url: string, callback: AsyncCallback<number>): void;
  - request2(url: string, options: HttpRequestOptions, callback: AsyncCallback<number>): void;
  - request2(url: string, options?: HttpRequestOptions): Promise<number>;
  - on(type: "dataProgress", callback: Callback<{ receiveSize: number, totalSize: number }>): void;
  - off(type: 'dataProgress', callback?: Callback<{ receiveSize: number, totalSize: number }>): void;

变更后：
  - requestInStream(url: string, callback: AsyncCallback<number>): void;
  - requestInStream(url: string, options: HttpRequestOptions, callback: AsyncCallback<number>): void;
  - requestInStream(url: string, options?: HttpRequestOptions): Promise<number>;
  - on(type: "dataReceiveProgress", callback: Callback<{ receiveSize: number, totalSize: number }>): void;
  - off(type: 'dataReceiveProgress', callback?: Callback<{ receiveSize: number, totalSize: number }>): void;

**适配指导**

将原有业务代码中request2接口名称和dataProgress事件名称分别替换为requestInStream和dataReceiveProgress即可正常使用。