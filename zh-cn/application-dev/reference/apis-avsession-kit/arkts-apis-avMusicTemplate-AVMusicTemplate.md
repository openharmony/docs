# Class (AVMusicTemplate)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_gyH0B0hP-->
<!--Designer: @ccfriend-->
<!--Tester: @chen-gong1-->
<!--Adviser: @w_Machine_cc-->

开发者调用[avMusicTemplate.createAVMusicTemplate](arkts-apis-avMusicTemplate-f.md#avmusictemplatecreateavmusictemplate)获取实例后，可获取其ID，启动音频模板界面，并配置数据获取方法。随后，同步数据给模板控制方，以完成数据交互和界面更新等操作。

> **说明：**
>
> - 本模块首批接口从API version 23开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块仅适用于API version 23及以上版本的Car设备。

## 导入模块

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';
```

## 属性

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称       | 类型   | 只读 | 可选 | 说明                 |
| :--------- | :----- | :--- | :--- | :------------------- |
| sessionId  | string | 否   | 否   | 音频模板唯一的标识。 |
| sessionTag | string | 否   | 否   | 音频模板标签。       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private static instance: TemplateManager;

  private constructor() {
  }

  /**
   * 获取模板控制器实例。
   *
   * @returns 模板控制器实例。
   */
  public static getInstance(): TemplateManager {
    if (!TemplateManager.instance) {
      TemplateManager.instance = new TemplateManager();
    }
    return TemplateManager.instance;
  }

  /**
   * 创建音频模板。
   */
  public createTemplate() {
    if (this.template) {
      console.warn('createTemplate: template not undefined');
      return;
    }
    this.template = avMusicTemplate.createAVMusicTemplate(avMusicTemplate.AVMusicTemplateType.DEFAULT);
    console.info('Succeeded in creating template.');
  }
}
```

## startTemplate

startTemplate(): Promise&lt;OperResult&gt;

启动音频模板界面。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise\<[OperResult](arkts-apis-avMusicTemplate-i.md#operresult)> | Promise对象，返回启动音频模板界面的操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ------------------------- |
| 801      | capability not supported. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 模拟开启模板。
   */
  public startTemplate() {
    this.template?.startTemplate();
  }
}
```

## onQueryMainTabs

onQueryMainTabs(callback: QueryMainTabsEvent): void

注册查询主标签的事件监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | [QueryMainTabsEvent](arkts-apis-avMusicTemplate-t.md#querymaintabsevent) | 是   | 回调函数，返回查询主标签事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryMainTabs can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryMainTabsEvent: avMusicTemplate.QueryMainTabsEvent = async () => {
    try {
      return await this.getMainTabs();
    } catch (e) {
      const msg = `Failed to queryMainTabsEvent. Code: ${e?.code}`;
      console.error(msg);
      throw e instanceof Error ? e : new Error(e?.message ?? msg);
    }
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryMainTabs(this.queryMainTabsEvent);
  }

  /**
   * 模拟获取主界面的所有TAB。
   *
   * @returns Promise类型MediaTab数组。
   */
  private async getMainTabs(): Promise<avMusicTemplate.MediaTab[]> {
    let homeTab: avMusicTemplate.MediaTab = {
      tabId: 'home',
      tabName: '首页'
    };
    let mineTab: avMusicTemplate.MediaTab = {
      tabId: 'mine',
      tabName: '我的'
    };
    let mainTabs: avMusicTemplate.MediaTab[] = [homeTab, mineTab];
    return mainTabs;
  };
}
```

## offQueryMainTabs

offQueryMainTabs(callback?: QueryMainTabsEvent): void

注销查询主标签事件监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                   |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------ |
| callback | [QueryMainTabsEvent](arkts-apis-avMusicTemplate-t.md#querymaintabsevent) | 否   | 查询主标签事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryMainTabs can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryMainTabs();
  }
}
```

## onQueryMediaTabContent

onQueryMediaTabContent(callback: QueryMediaTabContentEvent): void

注册查询媒体标签内容事件监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                     |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------- |
| callback | [QueryMediaTabContentEvent](arkts-apis-avMusicTemplate-t.md#querymediatabcontentevent) | 是   | 回调函数，返回查询媒体标签页内容的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryMediaTabContent can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryMediaTabContentEvent: avMusicTemplate.QueryMediaTabContentEvent = async (tabId: string) => {
    return new Promise<avMusicTemplate.MediaTabContent>(async (resolve, reject) => {
      let tabContent: avMusicTemplate.MediaTabContent = await this.createMediaTabContent();
      resolve(tabContent);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryMediaTabContent(this.queryMediaTabContentEvent);
  }

  /**
   * 模拟获取TAB内容。
   *
   * @returns 标签页内容。
   */
  private async createMediaTabContent(): Promise<avMusicTemplate.MediaTabContent> {
    let compilation: avMusicTemplate.Compilation = await this.createCompilation();
    let mediaTabContent: avMusicTemplate.MediaTabContent = {
      errorCode: 0,
      tabId: 'tabId',
      compilations: [compilation]
    }
    return mediaTabContent;
  };

  /**
   * 模拟获取合集数据。
   *
   * @returns 合集。
   */
  private async createCompilation(): Promise<avMusicTemplate.Compilation> {
    let mediaEntity: avMusicTemplate.MediaEntity = await this.createMediaEntity();
    let compilation: avMusicTemplate.Compilation = {
      errorCode: 0,
      id: '',
      title: '',
      hasMoreData: false,
      totalSize: 1,
      memberMediaType: avMusicTemplate.EntityType.SINGLE,
      topElements: [mediaEntity],
    }
    return compilation;
  };

  /**
   * 模拟获取媒体数据。
   *
   * @returns 媒体数据。
   */
  private async createMediaEntity(): Promise<avMusicTemplate.MediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    };
    return mediaEntity;
  };
}
```

## offQueryMediaTabContent

offQueryMediaTabContent(callback?: QueryMediaTabContentEvent): void

取消查询媒体标签内容监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | [QueryMediaTabContentEvent](arkts-apis-avMusicTemplate-t.md#querymediatabcontentevent) | 否   | 查询媒体标签页内容的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryMediaTabContent can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryMediaTabContent();
  }
}
```

## onQueryMediaEntity

onQueryMediaEntity(callback: QueryMediaEntityEvent): void

注册查询媒体实体监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | [QueryMediaEntityEvent](arkts-apis-avMusicTemplate-t.md#querymediaentityevent) | 是   | 回调函数，返回查询媒体实体的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryMediaEntity can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryMediaEntityEvent: avMusicTemplate.QueryMediaEntityEvent =
    async (params: avMusicTemplate.QueryMediaEntityParam) => {
      return new Promise<avMusicTemplate.PageMediaEntity>(async (resolve, reject) => {
        let pageMediaEntity: avMusicTemplate.PageMediaEntity = await this.createPageMediaEntity();
        resolve(pageMediaEntity);
      });
    };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryMediaEntity(this.queryMediaEntityEvent);
  }

  /**
   * 模拟获取PageMediaEntity。
   *
   * @returns PageMediaEntity实例。
   */
  private async createPageMediaEntity(): Promise<avMusicTemplate.PageMediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = await this.createMediaEntity();
    let pageMediaEntity: avMusicTemplate.PageMediaEntity = {
      errorCode: 0,
      pageIndex: 0,
      pageSize: 1,
      hasMoreData: false,
      totalSize: 1,
      memberMediaType: avMusicTemplate.EntityType.SINGLE,
      elements: [mediaEntity]
    }
    return pageMediaEntity;
  };

  /**
   * 模拟获取媒体数据。
   *
   * @returns 媒体数据。
   */
  private async createMediaEntity(): Promise<avMusicTemplate.MediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    };
    return mediaEntity;
  };
}
```

## offQueryMediaEntity

offQueryMediaEntity(callback?: QueryMediaEntityEvent): void

注销查询媒体实体监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [QueryMediaEntityEvent](arkts-apis-avMusicTemplate-t.md#querymediaentityevent) | 否   | 查询媒体实体的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryMediaEntity can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryMediaEntity();
  }
}
```

## onQueryCompilation

onQueryCompilation(callback: QueryCompilationEvent): void

注册查询合集的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | [QueryCompilationEvent](arkts-apis-avMusicTemplate-t.md#querycompilationevent) | 是   | 回调函数，返回查询合集的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryCompilation can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryCompilationEvent: avMusicTemplate.QueryCompilationEvent =
    async (compilationId: string, pageIndex: number) => {
      return new Promise<avMusicTemplate.PageMediaEntity>(async (resolve, reject) => {
        let pageMediaEntity: avMusicTemplate.PageMediaEntity = await this.createPageMediaEntity();
        resolve(pageMediaEntity);
      });
    };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryCompilation(this.queryCompilationEvent);
  }

  /**
   * 模拟获取PageMediaEntity。
   *
   * @returns PageMediaEntity实例。
   */
  private async createPageMediaEntity(): Promise<avMusicTemplate.PageMediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = await this.createMediaEntity();
    let pageMediaEntity: avMusicTemplate.PageMediaEntity = {
      errorCode: 0,
      pageIndex: 0,
      pageSize: 1,
      hasMoreData: false,
      totalSize: 1,
      memberMediaType: avMusicTemplate.EntityType.SINGLE,
      elements: [mediaEntity]
    }
    return pageMediaEntity;
  };

  /**
   * 模拟获取媒体数据。
   *
   * @returns 媒体数据。
   */
  private async createMediaEntity(): Promise<avMusicTemplate.MediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    };
    return mediaEntity;
  };
}
```

## offQueryCompilation

offQueryCompilation(callback?: QueryCompilationEvent): void

注销查询合集的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                   |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------ |
| callback | [QueryCompilationEvent](arkts-apis-avMusicTemplate-t.md#querycompilationevent) | 否   | 查询合集的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryCompilation can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryCompilation();
  }
}
```

## onQueryPlaylist

onQueryPlaylist(callback: QueryPlaylistEvent): void

注册查询播放列表的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | [QueryPlaylistEvent](arkts-apis-avMusicTemplate-t.md#queryplaylistevent) | 是   | 回调函数，返回查询播放列表的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryPlaylist can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryPlaylistEvent: avMusicTemplate.QueryPlaylistEvent =
    async (pageIndex: number, sort: avMusicTemplate.Sort) => {
      return new Promise<avMusicTemplate.PageMediaEntity>(async (resolve, reject) => {
        let pageMediaEntity: avMusicTemplate.PageMediaEntity = await this.createPageMediaEntity();
        resolve(pageMediaEntity);
      });
    };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryPlaylist(this.queryPlaylistEvent);
  }

  /**
   * 模拟获取PageMediaEntity。
   *
   * @returns PageMediaEntity实例。
   */
  private async createPageMediaEntity(): Promise<avMusicTemplate.PageMediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = await this.createMediaEntity();
    let pageMediaEntity: avMusicTemplate.PageMediaEntity = {
      errorCode: 0,
      pageIndex: 0,
      pageSize: 1,
      hasMoreData: false,
      totalSize: 1,
      memberMediaType: avMusicTemplate.EntityType.SINGLE,
      elements: [mediaEntity]
    }
    return pageMediaEntity;
  };

  /**
   * 模拟获取媒体数据。
   *
   * @returns 媒体数据。
   */
  private async createMediaEntity(): Promise<avMusicTemplate.MediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    };
    return mediaEntity;
  };
}
```

## offQueryPlaylist

offQueryPlaylist(callback?: QueryPlaylistEvent): void

注销查询播放列表的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [QueryPlaylistEvent](arkts-apis-avMusicTemplate-t.md#queryplaylistevent) | 否   | 查询播放列表的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryPlaylist can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryPlaylist();
  }
}
```

## onQueryCurrentSingle

onQueryCurrentSingle(callback: QueryCurrentSingleEvent): void

注册查询当前单曲的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | [QueryCurrentSingleEvent](arkts-apis-avMusicTemplate-t.md#querycurrentsingleevent) | 是   | 回调函数，返回查询当前单曲的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryCurrentSingle can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryCurrentSingleEvent: avMusicTemplate.QueryCurrentSingleEvent = async () => {
    return new Promise<avMusicTemplate.Single>(async (resolve, reject) => {
      let single: avMusicTemplate.Single = await this.createCurrentSingle();
      resolve(single);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryCurrentSingle(this.queryCurrentSingleEvent);
  }

  /**
   * 模拟获取当前单曲。
   *
   * @returns 当前单曲。
   */
  private async createCurrentSingle(): Promise<avMusicTemplate.Single> {
    let playInfo: avMusicTemplate.PlayInfo = {
      playCounts: '100w',
      isSupportNext: true,
      isSupportPrev: false,
      isSupportQuickForward: true,
      isSupportQuickBackward: true,
      quickForwardStep: 10,
      quickBackwardStep: 10,
      isSupportSkipHead: false,
      isSupportSkipTail: true,
      isSupportPlayMode: true,
      isSupportPlayRate: true,
      supportedPlayRate: ['1', '2', '3'],
      currentPlayRate: '1',
      isSupportSoundQuality: false,
      isSupportSoundEffect: true,
      totalDuration: 60,
      currentPlayDuration: 10,
      isSupportProgress: false,
    }
    let favoriteData: avMusicTemplate.FavoriteData = {
      isSupportFav: true,
      isFavorite: false,
      favCounts: '1000+'
    }
    let single: avMusicTemplate.Single = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: '歌曲标题',
      desc: '歌曲描述',
      imageUrl: '',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE,
      isVip: false,
      singer: '',
      tags: [],
      playInfo: playInfo,
      favSubscribeData: favoriteData
    }
    return single;
  };
}
```

## offQueryCurrentSingle

offQueryCurrentSingle(callback?: QueryCurrentSingleEvent): void

注销查询当前单曲的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [QueryCurrentSingleEvent](arkts-apis-avMusicTemplate-t.md#querycurrentsingleevent) | 否   | 查询当前单曲的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryCurrentSingle can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryCurrentSingle();
  }
}
```

## onQueryCompilationByKeyword

onQueryCompilationByKeyword(callback: QueryCompilationByKeywordEvent): void

注册按关键字查询合集的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | [QueryCompilationByKeywordEvent](arkts-apis-avMusicTemplate-t.md#querycompilationbykeywordevent) | 是   | 回调函数，返回按关键字查询合集的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryCompilationByKeyword can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryCompilationByKeywordEvent: avMusicTemplate.QueryCompilationByKeywordEvent = async (keyword: string) => {
    return new Promise<avMusicTemplate.Compilation[]>(async (resolve, reject) => {
      let compilation: avMusicTemplate.Compilation = await this.createCompilation();
      let compilations: avMusicTemplate.Compilation[] = [compilation];
      resolve(compilations);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryCompilationByKeyword(this.queryCompilationByKeywordEvent);
  }

  /**
   * 模拟获取合集数据。
   *
   * @returns 合集。
   */
  private async createCompilation(): Promise<avMusicTemplate.Compilation> {
    let mediaEntity: avMusicTemplate.MediaEntity = await this.createMediaEntity();
    let compilation: avMusicTemplate.Compilation = {
      errorCode: 0,
      id: '',
      title: '',
      hasMoreData: false,
      totalSize: 1,
      memberMediaType: avMusicTemplate.EntityType.SINGLE,
      topElements: [mediaEntity],
    }
    return compilation;
  };

  /**
   * 模拟获取媒体数据。
   *
   * @returns 媒体数据。
   */
  private async createMediaEntity(): Promise<avMusicTemplate.MediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    };
    return mediaEntity;
  };
}
```

## offQueryCompilationByKeyword

offQueryCompilationByKeyword(callback?: QueryCompilationByKeywordEvent): void

注销按关键字查询合集的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | [QueryCompilationByKeywordEvent](arkts-apis-avMusicTemplate-t.md#querycompilationbykeywordevent) | 否   | 按关键字查询合集的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryCompilationByKeyword can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryCompilationByKeyword();
  }
}
```

## onQueryMediaEntityByKeyword

onQueryMediaEntityByKeyword(callback: QueryMediaEntityByKeywordEvent): void

注册按关键字查询媒体实体的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | [QueryMediaEntityByKeywordEvent](arkts-apis-avMusicTemplate-t.md#querymediaentitybykeywordevent) | 是   | 回调函数，返回按关键字查询媒体实体的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryMediaEntityByKeyword can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryMediaEntityByKeywordEvent: avMusicTemplate.QueryMediaEntityByKeywordEvent =
    async (keyword: string, searchType: avMusicTemplate.EntityType, pageIndex: number) => {
      return new Promise<avMusicTemplate.PageMediaEntity>(async (resolve, reject) => {
        let pageMediaEntity: avMusicTemplate.PageMediaEntity = await this.createPageMediaEntity();
        resolve(pageMediaEntity);
      });
    };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryMediaEntityByKeyword(this.queryMediaEntityByKeywordEvent);
  }

  /**
   * 模拟获取PageMediaEntity。
   *
   * @returns PageMediaEntity实例。
   */
  private async createPageMediaEntity(): Promise<avMusicTemplate.PageMediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = await this.createMediaEntity();
    let pageMediaEntity: avMusicTemplate.PageMediaEntity = {
      errorCode: 0,
      pageIndex: 0,
      pageSize: 1,
      hasMoreData: false,
      totalSize: 1,
      memberMediaType: avMusicTemplate.EntityType.SINGLE,
      elements: [mediaEntity]
    }
    return pageMediaEntity;
  };

  /**
   * 模拟获取媒体数据。
   *
   * @returns 媒体数据。
   */
  private async createMediaEntity(): Promise<avMusicTemplate.MediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    };
    return mediaEntity;
  };
}
```

## offQueryMediaEntityByKeyword

offQueryMediaEntityByKeyword(callback?: QueryMediaEntityByKeywordEvent): void

注销按关键字查询媒体实体的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | [QueryMediaEntityByKeywordEvent](arkts-apis-avMusicTemplate-t.md#querymediaentitybykeywordevent) | 否   | 按关键字查询媒体实体的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryMediaEntityByKeyword can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryMediaEntityByKeyword();
  }
}
```

## onQueryRecommendMediaEntityList

onQueryRecommendMediaEntityList(callback: QueryRecommendMediaEntityListEvent): void

注册查询推荐媒体列表的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | [QueryRecommendMediaEntityListEvent](arkts-apis-avMusicTemplate-t.md#queryrecommendmediaentitylistevent) | 是   | 回调函数，返回查询推荐媒体列表的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryRecommendMediaEntityList can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryRecommendMediaEntityListEvent: avMusicTemplate.QueryRecommendMediaEntityListEvent = async () => {
    return new Promise<avMusicTemplate.MediaEntity[]>(async (resolve, reject) => {
      let mediaEntity: avMusicTemplate.MediaEntity = await this.createMediaEntity();
      let mediaEntities: avMusicTemplate.MediaEntity[] = [mediaEntity];
      resolve(mediaEntities);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryRecommendMediaEntityList(this.queryRecommendMediaEntityListEvent);
  }

  /**
   * 模拟获取媒体数据。
   *
   * @returns 媒体数据。
   */
  private async createMediaEntity(): Promise<avMusicTemplate.MediaEntity> {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    };
    return mediaEntity;
  };
}
```

## offQueryRecommendMediaEntityList

offQueryRecommendMediaEntityList(callback?: QueryRecommendMediaEntityListEvent): void

注销查询推荐媒体列表的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | [QueryRecommendMediaEntityListEvent](arkts-apis-avMusicTemplate-t.md#queryrecommendmediaentitylistevent) | 否   | 查询推荐媒体列表的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryRecommendMediaEntityList can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryRecommendMediaEntityList();
  }
}
```

## onQueryHotWords

onQueryHotWords(callback: QueryHotWordsEvent): void

注册查询热词的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | [QueryHotWordsEvent](arkts-apis-avMusicTemplate-t.md#queryhotwordsevent) | 是   | 回调函数，返回查询热词的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryHotWords can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryHotWordsEvent: avMusicTemplate.QueryHotWordsEvent = async () => {
    return new Promise<string[]>(async (resolve, reject) => {
      let hotWords: string[] = ['热词1', '热词2', '热词3', '热词4', '热词5'];
      resolve(hotWords);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryHotWords(this.queryHotWordsEvent);
  }
}
```

## offQueryHotWords

offQueryHotWords(callback?: QueryHotWordsEvent): void

注销查询热词的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                   |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------ |
| callback | [QueryHotWordsEvent](arkts-apis-avMusicTemplate-t.md#queryhotwordsevent) | 否   | 查询热词的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryHotWords can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryHotWords();
  }
}
```

## onQuerySearchHistory

onQuerySearchHistory(callback: QuerySearchHistoryEvent): void

注册查询搜索历史的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | [QuerySearchHistoryEvent](arkts-apis-avMusicTemplate-t.md#querysearchhistoryevent) | 是   | 回调函数，返回查询搜索历史的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQuerySearchHistory can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private querySearchHistoryEvent: avMusicTemplate.QuerySearchHistoryEvent = async () => {
    return new Promise<string[]>(async (resolve, reject) => {
      let searchHistory: string[] = ['搜索历史1', '搜索历史2', '搜索历史3', '搜索历史4', '搜索历史5'];
      resolve(searchHistory);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQuerySearchHistory(this.querySearchHistoryEvent);
  }
}
```

## offQuerySearchHistory

offQuerySearchHistory(callback?: QuerySearchHistoryEvent): void

注销查询搜索历史的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [QuerySearchHistoryEvent](arkts-apis-avMusicTemplate-t.md#querysearchhistoryevent) | 否   | 查询搜索历史的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQuerySearchHistory can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQuerySearchHistory();
  }
}
```

## onClearSearchHistory

onClearSearchHistory(callback: ClearSearchHistoryEvent): void

注册清除搜索历史的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | [ClearSearchHistoryEvent](arkts-apis-avMusicTemplate-t.md#clearsearchhistoryevent) | 是   | 回调函数，返回清除搜索历史的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onClearSearchHistory can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private clearSearchHistoryEvent: avMusicTemplate.ClearSearchHistoryEvent = async () => {
    return new Promise<avMusicTemplate.OperResult>(async (resolve, reject) => {
      let operResult: avMusicTemplate.OperResult = await this.createOperResult();
      resolve(operResult);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onClearSearchHistory(this.clearSearchHistoryEvent);
  }

  /**
   * 模拟操作结果。
   *
   * @returns 操作结果。
   */
  private async createOperResult(): Promise<avMusicTemplate.OperResult> {
    let operResult: avMusicTemplate.OperResult = {
      errorCode: 0,
    }
    return operResult;
  };
}
```

## offClearSearchHistory

offClearSearchHistory(callback?: ClearSearchHistoryEvent): void

注销清除搜索历史的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [ClearSearchHistoryEvent](arkts-apis-avMusicTemplate-t.md#clearsearchhistoryevent) | 否   | 清除搜索历史的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offClearSearchHistory can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offClearSearchHistory();
  }
}
```

## onLogin

onLogin(callback: LoginEvent): void

注册登录事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| callback | [LoginEvent](arkts-apis-avMusicTemplate-t.md#loginevent) | 是   | 回调函数，返回登录事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onLogin can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private loginEvent: avMusicTemplate.LoginEvent = async (controlType: avMusicTemplate.LoginType, id?: string) => {
    return new Promise<avMusicTemplate.QrCodeInfo[]>(async (resolve, reject) => {
      let qrCodeInfo: avMusicTemplate.QrCodeInfo = await this.createQrCodeInfo();
      let qrCodeInfos: avMusicTemplate.QrCodeInfo[] = [qrCodeInfo];
      resolve(qrCodeInfos);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onLogin(this.loginEvent);
  }

  /**
   * 模拟创建二维码信息数组。
   *
   * @returns Promise类型的二维码信息数组。
   */
  private async createQrCodeInfo(): Promise<avMusicTemplate.QrCodeInfo> {
    let qrCodeInfo: avMusicTemplate.QrCodeInfo = {
      id: 'id',
      price: '10',
      titleName: 'title',
      detailName: 'detail',
      tips: 'tip',
      content: 'content',
      validPeriod: 1
    };
    return qrCodeInfo;
  };
}
```

## offLogin

offLogin(callback?: LoginEvent): void

注销登录事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                             |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| callback | [LoginEvent](arkts-apis-avMusicTemplate-t.md#loginevent) | 否   | 登录事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offLogin can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offLogin();
  }
}
```

## onRequestDialogInfo

onRequestDialogInfo(callback: RequestDialogInfoEvent): void

注册请求对话框信息的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                 |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------ |
| callback | [RequestDialogInfoEvent](arkts-apis-avMusicTemplate-t.md#requestdialoginfoevent) | 是   | 回调函数，返回请求对话框信息的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onRequestDialogInfo can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private requestDialogInfoEvent: avMusicTemplate.RequestDialogInfoEvent =
    async (actionType: avMusicTemplate.DialogActionType, actionInfo?: avMusicTemplate.DialogActionInfo) => {
      return new Promise<avMusicTemplate.DialogInfo>(async (resolve, reject) => {
        let dialogInfo: avMusicTemplate.DialogInfo = await this.createDialogInfo();
        resolve(dialogInfo);
      });
    };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onRequestDialogInfo(this.requestDialogInfoEvent);
  }

  /**
   * 模拟对话框信息。
   *
   * @returns 对话框信息。
   */
  private async createDialogInfo(): Promise<avMusicTemplate.DialogInfo> {
    let qrCodeInfo: avMusicTemplate.QrCodeInfo[] = [{
      id: 'id',
      price: '10',
      titleName: 'title',
      detailName: 'detail',
      tips: 'tip',
      content: 'content',
      validPeriod: 1
    }
    ];
    let dialogInfo: avMusicTemplate.DialogInfo = {
      dialogId: 'dialogId',
      dialogType: avMusicTemplate.DialogType.LOGIN,
      qrCodes: qrCodeInfo
    };
    return dialogInfo;
  };
}
```

## offRequestDialogInfo

offRequestDialogInfo(callback?: RequestDialogInfoEvent): void

注销请求对话框信息的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | [RequestDialogInfoEvent](arkts-apis-avMusicTemplate-t.md#requestdialoginfoevent) | 否   | 请求对话框信息的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offRequestDialogInfo can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offRequestDialogInfo();
  }
}
```

## onHandleMemberPurchase

onHandleMemberPurchase(callback: HandleMemberPurchaseEvent): void

注册处理购买会员事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | [HandleMemberPurchaseEvent](arkts-apis-avMusicTemplate-t.md#handlememberpurchaseevent) | 是   | 回调函数，返回处理购买会员的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onHandleMemberPurchase can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private handleMemberPurchaseEvent: avMusicTemplate.HandleMemberPurchaseEvent =
    async (info: avMusicTemplate.MemberPurchaseInfo) => {
      return new Promise<avMusicTemplate.DialogInfo>(async (resolve, reject) => {
        let dialogInfo: avMusicTemplate.DialogInfo = await this.createDialogInfo();
        resolve(dialogInfo);
      });
    };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onHandleMemberPurchase(this.handleMemberPurchaseEvent);
  }

  /**
   * 模拟对话框信息。
   *
   * @returns 对话框信息。
   */
  private async createDialogInfo(): Promise<avMusicTemplate.DialogInfo> {
    let qrCodeInfo: avMusicTemplate.QrCodeInfo[] = [{
      id: 'id',
      price: '10',
      titleName: 'title',
      detailName: 'detail',
      tips: 'tip',
      content: 'content',
      validPeriod: 1
    }
    ];
    let dialogInfo: avMusicTemplate.DialogInfo = {
      dialogId: 'dialogId',
      dialogType: avMusicTemplate.DialogType.LOGIN,
      qrCodes: qrCodeInfo
    };
    return dialogInfo;
  };
}
```

## offHandleMemberPurchase

offHandleMemberPurchase(callback?: HandleMemberPurchaseEvent): void

注销处理购买会员事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [HandleMemberPurchaseEvent](arkts-apis-avMusicTemplate-t.md#handlememberpurchaseevent) | 否   | 处理购买会员的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offHandleMemberPurchase can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offHandleMemberPurchase();
  }
}
```

## onQueryMemberPurchase

onQueryMemberPurchase(callback: QueryMemberPurchaseEvent): void

注册查询购买会员事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | [QueryMemberPurchaseEvent](arkts-apis-avMusicTemplate-t.md#querymemberpurchaseevent) | 是   | 回调函数，返回查询购买会员的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryMemberPurchase can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryMemberPurchaseEvent: avMusicTemplate.QueryMemberPurchaseEvent =
    async (memberPurchaseType: avMusicTemplate.MemberPurchaseType) => {
      return new Promise<avMusicTemplate.MemberPurchaseInfo[]>(async (resolve, reject) => {
        let memberPurchaseInfo: avMusicTemplate.MemberPurchaseInfo = await this.createQueryMemberPurchase();
        let memberPurchaseInfos: avMusicTemplate.MemberPurchaseInfo[] = [memberPurchaseInfo];
        resolve(memberPurchaseInfos);
      });
    };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryMemberPurchase(this.queryMemberPurchaseEvent);
  }

  /**
   * 模拟查询会员购买信息。
   *
   * @returns Promise类型的购买会员信息数组。
   */
  private async createQueryMemberPurchase(): Promise<avMusicTemplate.MemberPurchaseInfo> {
    let memberPurchaseInfo: avMusicTemplate.MemberPurchaseInfo = {
      id: 'id',
      diagramUrl: 'diagramUrl',
      diagramContent: 'diagramContent',
      memberPurchaseType: avMusicTemplate.MemberPurchaseType.NORMAL
    };
    return memberPurchaseInfo;
  };
}
```

## offQueryMemberPurchase

offQueryMemberPurchase(callback?: QueryMemberPurchaseEvent): void

注销查询购买会员事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [QueryMemberPurchaseEvent](arkts-apis-avMusicTemplate-t.md#querymemberpurchaseevent) | 否   | 查询购买会员的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryMemberPurchase can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryMemberPurchase();
  }
}
```

## onQueryCustomContent

onQueryCustomContent(callback: QueryCustomContentEvent): void

注册查询自定义内容事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                 |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------ |
| callback | [QueryCustomContentEvent](arkts-apis-avMusicTemplate-t.md#querycustomcontentevent) | 是   | 回调函数，返回查询自定义内容的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onQueryCustomContent can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private queryCustomContentEvent: avMusicTemplate.QueryCustomContentEvent =
    async (queryTypes: avMusicTemplate.CustomType[]) => {
      return new Promise<avMusicTemplate.CustomElement>(async (resolve, reject) => {
        let customElement: avMusicTemplate.CustomElement = await this.createCustomContent();
        resolve(customElement);
      });
    };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onQueryCustomContent(this.queryCustomContentEvent);
  }

  /**
   * 模拟获取自定义内容。
   *
   * @returns 自定义元素。
   */
  private async createCustomContent(): Promise<avMusicTemplate.CustomElement> {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    }
    let compilation: avMusicTemplate.Compilation = {
      errorCode: 0,
      errorMsg: 'success',
      id: 'id',
      title: 'title',
      hasMoreData: false,
      totalSize: 1,
      memberMediaType: avMusicTemplate.EntityType.SINGLE,
      topElements: [mediaEntity]
    };
    let customElement: avMusicTemplate.CustomElement = {
      errorCode: 0,
      customCompilations: [compilation],
    };
    return customElement;
  };
}
```

## offQueryCustomContent

offQueryCustomContent(callback?: QueryCustomContentEvent): void

注销查询自定义内容事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | [QueryCustomContentEvent](arkts-apis-avMusicTemplate-t.md#querycustomcontentevent) | 否   | 查询自定义内容的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offQueryCustomContent can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offQueryCustomContent();
  }
}
```

## onDownloadMediaEntity

onDownloadMediaEntity(callback: DownloadMediaEntityEvent): void

注册下载媒体实体事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | [DownloadMediaEntityEvent](arkts-apis-avMusicTemplate-t.md#downloadmediaentityevent) | 是   | 回调函数，返回下载媒体实体的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onDownloadMediaEntity can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private downloadMediaEntityEvent: avMusicTemplate.DownloadMediaEntityEvent =
    async (controlType: avMusicTemplate.DownloadControlType, mediaEntity: avMusicTemplate.MediaEntity) => {
      return new Promise<avMusicTemplate.OperResult>(async (resolve, reject) => {
        let operResult: avMusicTemplate.OperResult = await this.createOperResult();
        this.downloadMediaEntity(mediaEntity);
        resolve(operResult);
      });
    };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onDownloadMediaEntity(this.downloadMediaEntityEvent);
  }

  /**
   * 下载状态，进度刷新。
   */
  public setDownloadMediaEntityStatus(mediaEntity: avMusicTemplate.MediaEntity) {
    this.template?.setDownloadMediaEntityStatus(mediaEntity);
  };

  /**
   * 模拟操作结果。
   *
   * @returns 操作结果。
   */
  private async createOperResult(): Promise<avMusicTemplate.OperResult> {
    let operResult: avMusicTemplate.OperResult = {
      errorCode: 0,
    }
    return operResult;
  };

  /**
   * 模拟下载过程。
   *
   * @param mediaEntity 媒体实体。
   */
  private async downloadMediaEntity(mediaEntity: avMusicTemplate.MediaEntity) {
    // 下载完成之后。
    this.setDownloadMediaEntityStatus(mediaEntity);
  };
}
```

## offDownloadMediaEntity

offDownloadMediaEntity(callback?: DownloadMediaEntityEvent): void

注销下载媒体实体事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [DownloadMediaEntityEvent](arkts-apis-avMusicTemplate-t.md#downloadmediaentityevent) | 否   | 下载媒体实体的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offDownloadMediaEntity can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offDownloadMediaEntity();
  }
}
```

## onSettingsChange

onSettingsChange(callback: SettingsChangeEvent): void

注册设置改变事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | [SettingsChangeEvent](arkts-apis-avMusicTemplate-t.md#settingschangeevent) | 是   | 回调函数，返回设置改变的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onSettingsChange can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private settingsChangeEvent: avMusicTemplate.SettingsChangeEvent =
    async (settingItem: avMusicTemplate.SettingItem) => {
      return new Promise<avMusicTemplate.SettingItem>(async (resolve, reject) => {
        let settingItem: avMusicTemplate.SettingItem = await this.settingsChange();
        resolve(settingItem);
      });
    };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onSettingsChange(this.settingsChangeEvent);
  }

  /**
   * 模拟设置改变。
   *
   * @returns Promise类型的设置条目。
   */
  private async settingsChange(): Promise<avMusicTemplate.SettingItem> {
    let setting: avMusicTemplate.SettingItem = {
      id: 'id',
      title: 'title',
      desc: 'desc',
      mediaId: 'mediaId',
      settingType: avMusicTemplate.SettingType.SWITCH,
      settingValue: false
    }
    return setting;
  };
}
```

## offSettingsChange

offSettingsChange(callback?: SettingsChangeEvent): void

注销设置改变事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                   |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------ |
| callback | [SettingsChangeEvent](arkts-apis-avMusicTemplate-t.md#settingschangeevent) | 否   | 设置改变的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offSettingsChange can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offSettingsChange();
  }
}
```

## onProblemAndAdvice

onProblemAndAdvice(callback: ProblemAndAdviceEvent): void

注册问题与建议事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | [ProblemAndAdviceEvent](arkts-apis-avMusicTemplate-t.md#problemandadviceevent) | 是   | 回调函数，返回问题与建议的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onProblemAndAdvice can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private problemAndAdviceEvent: avMusicTemplate.ProblemAndAdviceEvent = async (advice: string) => {
    return new Promise<avMusicTemplate.OperResult>(async (resolve, reject) => {
      let operResult: avMusicTemplate.OperResult = await this.createOperResult();
      resolve(operResult);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onProblemAndAdvice(this.problemAndAdviceEvent);
  }

  /**
   * 模拟操作结果。
   *
   * @returns 操作结果。
   */
  private async createOperResult(): Promise<avMusicTemplate.OperResult> {
    let operResult: avMusicTemplate.OperResult = {
      errorCode: 0,
    }
    return operResult;
  };
}
```

## offProblemAndAdvice

offProblemAndAdvice(callback?: ProblemAndAdviceEvent): void

注销问题与建议事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | [ProblemAndAdviceEvent](arkts-apis-avMusicTemplate-t.md#problemandadviceevent) | 否   | 处理问题与建议的回调。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offProblemAndAdvice can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offProblemAndAdvice();
  }
}
```

## onPlayForSearch

onPlayForSearch(callback: PlayForSearchEvent): void

注册搜播事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                       |
| -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| callback | [PlayForSearchEvent](arkts-apis-avMusicTemplate-t.md#playforsearchevent) | 是   | 回调函数，返回搜播的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onPlayForSearch can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private playForSearchEvent: avMusicTemplate.PlayForSearchEvent = async (command: avMusicTemplate.SearchPlayInfoType,
    args: avMusicTemplate.SearchPlayInfo) => {
    return new Promise<avMusicTemplate.OperResult>(async (resolve, reject) => {
      let operResult: avMusicTemplate.OperResult = await this.createOperResult();
      resolve(operResult);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onPlayForSearch(this.playForSearchEvent);
  }

  /**
   * 模拟操作结果。
   *
   * @returns 操作结果。
   */
  private async createOperResult(): Promise<avMusicTemplate.OperResult> {
    let operResult: avMusicTemplate.OperResult = {
      errorCode: 0,
    }
    return operResult;
  };
}
```

## offPlayForSearch

offPlayForSearch(callback?: PlayForSearchEvent): void

注销搜播事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                               |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| callback | [PlayForSearchEvent](arkts-apis-avMusicTemplate-t.md#playforsearchevent) | 否   | 搜播的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offPlayForSearch can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offPlayForSearch();
  }
}
```

## onExecuteAction

onExecuteAction(callback: ExecuteActionEvent): void

注册执行操作事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | [ExecuteActionEvent](arkts-apis-avMusicTemplate-t.md#executeactionevent) | 是   | 回调函数，返回执行操作的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onExecuteAction can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
  private executeActionEvent: avMusicTemplate.ExecuteActionEvent = async (actionType: string, params: string) => {
    return new Promise<string>(async (resolve, reject) => {
      let result: string = 'success';
      resolve(result);
    });
  };

  /**
   * 注册监听。
   */
  private registerListener() {
    this.template?.onExecuteAction(this.executeActionEvent);
  }
}
```

## offExecuteAction

offExecuteAction(callback?: ExecuteActionEvent): void

注销执行操作事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                   |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------ |
| callback | [ExecuteActionEvent](arkts-apis-avMusicTemplate-t.md#executeactionevent) | 否   | 执行操作的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offExecuteAction can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offExecuteAction();
  }
}
```

## onPlayMediaEntity

onPlayMediaEntity(callback: PlayMediaEntityEvent): void

注册播放媒体实体事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | [PlayMediaEntityEvent](arkts-apis-avMusicTemplate-t.md#playmediaentityevent) | 是   | 回调函数，返回播放媒体实体的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onPlayMediaEntity can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
    private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
    private playMediaEntityEvent: avMusicTemplate.PlayMediaEntityEvent =
        async (mediaEntity: avMusicTemplate.MediaEntity) => {
            console.info('playMediaEntity');
        };

    /**
     * 注册监听。
     */
    private registerListener() {
        this.template?.onPlayMediaEntity(this.playMediaEntityEvent);
    }
}
```


## offPlayMediaEntity

offPlayMediaEntity(callback?: PlayMediaEntityEvent): void

注销播放媒体实体事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [PlayMediaEntityEvent](arkts-apis-avMusicTemplate-t.md#playmediaentityevent) | 否   | 播放媒体实体的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offPlayMediaEntity can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offPlayMediaEntity();
  }
}
```

## onFavoriteMediaEntity

onFavoriteMediaEntity(callback: FavoriteMediaEntityEvent): void

注册收藏媒体实体事件的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | [FavoriteMediaEntityEvent](arkts-apis-avMusicTemplate-t.md#favoritemediaentityevent) | 是   | 回调函数，返回收藏媒体实体的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function onFavoriteMediaEntity can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
    private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
    private favoriteMediaEntityEvent: avMusicTemplate.FavoriteMediaEntityEvent =
        async (actionType: avMusicTemplate.MediaFavoriteType, mediaEntity: avMusicTemplate.MediaEntity) => {
            return new Promise<avMusicTemplate.OperResult>(async (resolve, reject) => {
                let operResult: avMusicTemplate.OperResult = await this.createOperResult();
                resolve(operResult);
            });
        };

    /**
     * 注册监听。
     */
    private registerListener() {
        this.template?.onFavoriteMediaEntity(this.favoriteMediaEntityEvent);
    }

    /**
     * 模拟操作结果。
     *
     * @returns 操作结果。
     */
    private async createOperResult(): Promise<avMusicTemplate.OperResult> {
        let operResult: avMusicTemplate.OperResult = {
            errorCode: 0,
        }
        return operResult;
    };
}
```

## offFavoriteMediaEntity

offFavoriteMediaEntity(callback?: FavoriteMediaEntityEvent): void

注销收藏媒体实体事件的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [FavoriteMediaEntityEvent](arkts-apis-avMusicTemplate-t.md#favoritemediaentityevent) | 否   | 收藏媒体实体的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function offFavoriteMediaEntity can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000012 | AVMusicTemplate error.                                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    this.template?.offFavoriteMediaEntity();
  }
}
```

## setUserInfo

setUserInfo(userInfo: UserInfo): Promise&lt;void&gt;

向音频模板控制方同步用户信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明       |
| -------- | ------------------------------------------------------------ | ---- | ---------- |
| userInfo | [UserInfo](arkts-apis-avMusicTemplate-i.md#userinfo) | 是   | 用户信息。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function setUserInfo can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000011 | The data write error, data is invalid.                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
    private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
    private isLogin: boolean = false;

    /**
     * 模拟登录状态改变。
     *
     * @param isLogin 是否登录。
     */
    public setLoginState(isLogin: boolean) {
        this.isLogin = isLogin;
        this.setUserInfo();
    }

    /**
     * 用户信息发生变化后通知界面刷新用户信息，如登录账号后。
     */
    public setUserInfo() {
        let userInfo: avMusicTemplate.UserInfo = {
            userInfoId: this.isLogin ? 'userInfoId' : '',
            nickName: this.isLogin ? '昵称' : '',
            profilePicUrl: this.isLogin ? 'profilePicUrl' : '',
            tips: this.isLogin ? 'tips' : '',
            isLogin: this.isLogin,
            isVip: false
        };
        this.template?.setUserInfo(userInfo);
    };
}
```

## setDialogCommand

setDialogCommand(type: DialogControlType, dialogInfo: DialogInfo): Promise&lt;void&gt;

向音频模板控制方同步对话框命令。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明             |
| ---------- | ------------------------------------------------------------ | ---- | ---------------- |
| type       | [DialogControlType](arkts-apis-avMusicTemplate-t.md#dialogcontroltype) | 是   | 对话框控制类型。 |
| dialogInfo | [DialogInfo](arkts-apis-avMusicTemplate-i.md#dialoginfo) | 是   | 对话框信息。     |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function setDialogCommand can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000011 | The data write error, data is invalid.                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
    private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

    /**
     * 对话框相关的操作，如：打开，关闭。
     */
    public setDialogCommand() {
        let type: avMusicTemplate.DialogControlType = 'open';
        let qrCodeInfo: avMusicTemplate.QrCodeInfo[] = [{
            id: 'id',
            price: '10',
            titleName: 'title',
            detailName: 'detail',
            tips: 'tip',
            content: 'content',
            validPeriod: 1
        }];
        let dialogInfo: avMusicTemplate.DialogInfo = {
            dialogId: 'dialogId',
            dialogType: avMusicTemplate.DialogType.LOGIN,
            qrCodes: qrCodeInfo
        };
        this.template?.setDialogCommand(type, dialogInfo);
    };
}
```
## setCurrentSingle

setCurrentSingle(single: Single): Promise&lt;void&gt;

向音频模板控制方同步当前单曲。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明       |
| ------ | ---------------------------------------------------------- | ---- | ---------- |
| single | [Single](arkts-apis-avMusicTemplate-i.md#single) | 是   | 当前单曲。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function setCurrentSingle can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000011 | The data write error, data is invalid.                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  public async setCurrentSingle() {
    let single: avMusicTemplate.Single = await this.createCurrentSingle()
    this.template?.setCurrentSingle(single);
  };

  /**
   * 模拟获取当前单曲。
   *
   * @returns 当前单曲。
   */
  private async createCurrentSingle(): Promise<avMusicTemplate.Single> {
    let playInfo: avMusicTemplate.PlayInfo = {
      playCounts: '100w',
      isSupportNext: true,
      isSupportPrev: false,
      isSupportQuickForward: true,
      isSupportQuickBackward: true,
      quickForwardStep: 10,
      quickBackwardStep: 10,
      isSupportSkipHead: false,
      isSupportSkipTail: true,
      isSupportPlayMode: true,
      isSupportPlayRate: true,
      supportedPlayRate: ['1', '2', '3'],
      currentPlayRate: '1',
      isSupportSoundQuality: false,
      isSupportSoundEffect: true,
      totalDuration: 60,
      currentPlayDuration: 10,
      isSupportProgress: false,
    }
    let favoriteData: avMusicTemplate.FavoriteData = {
      isSupportFav: true,
      isFavorite: false,
      favCounts: '1000+'
    }
    let single: avMusicTemplate.Single = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: '歌曲标题',
      desc: '歌曲描述',
      imageUrl: '',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE,
      isVip: false,
      singer: '',
      tags: [],
      playInfo: playInfo,
      favSubscribeData: favoriteData
    }
    return single;
  };
}
```

## setMediaEntities

setMediaEntities(entities: MediaEntity[]): Promise&lt;void&gt;

向音频模板控制方同步媒体资源变更信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明             |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| entities | [MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity)[] | 是   | 媒体实体的数组。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function setMediaEntities can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000011 | The data write error, data is invalid.                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 向音频模板控制方同步媒体资源变更信息，如歌单播放状态。
   */
  public setMediaEntities() {
    let mediaEntities: avMusicTemplate.MediaEntity[] = [{
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    }];
    this.template?.setMediaEntities(mediaEntities);
  };
}
```
## setTabContent

setTabContent(tabId: string, tabContent: MediaTabContent): Promise&lt;void&gt;

向音频模板控制方同步标签页内容信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明             |
| ---------- | ------------------------------------------------------------ | ---- | ---------------- |
| tabId      | string                                                       | 是   | 标签的ID。       |
| tabContent | [MediaTabContent](arkts-apis-avMusicTemplate-i.md#mediatabcontent) | 是   | 媒体标签页内容。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function setTabContent can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000011 | The data write error, data is invalid.                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 向音频模板控制方同步标签页内容信息，用于标签页内容变化后刷新界面。
   */
  public setTabContent() {
    let mediaEntity: avMusicTemplate.MediaEntity[] = [{
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    }]
    let compilation: avMusicTemplate.Compilation[] = [{
      errorCode: 0,
      errorMsg: 'success',
      id: 'id',
      title: 'title',
      hasMoreData: true,
      totalSize: 2,
      memberMediaType: avMusicTemplate.EntityType.SINGLE,
      topElements: mediaEntity
    }]
    let mediaTabContent: avMusicTemplate.MediaTabContent = {
      errorCode: 0,
      errorMsg: 'success',
      tabId: 'tabId',
      compilations: compilation
    }
    this.template?.setTabContent('tabId', mediaTabContent);
  };
}
```
## setPlaylist

setPlaylist(playlist: PageMediaEntity): Promise&lt;void&gt;

向音频模板控制方同步播放列表。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明           |
| -------- | ------------------------------------------------------------ | ---- | -------------- |
| playlist | [PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity) | 是   | 分页媒体实体。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function setPlaylist can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000011 | The data write error, data is invalid.                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 向音频模板控制方同步播放列表，用于播放列表变化后刷新界面。
   */
  public setPlaylist() {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    }
    let pageMediaEntity: avMusicTemplate.PageMediaEntity = {
      errorCode: 0,
      errorMsg: 'success',
      pageIndex: 0,
      pageSize: 1,
      hasMoreData: true,
      totalSize: 2,
      memberMediaType: avMusicTemplate.EntityType.SINGLE,
      elements: [mediaEntity]
    }
    this.template?.setPlaylist(pageMediaEntity);
  };
}
```

## setDownloadMediaEntityStatus

setDownloadMediaEntityStatus(single: MediaEntity): Promise&lt;void&gt;

向音频模板控制方同步单曲下载状态信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明       |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| single | [MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity) | 是   | 单曲。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function setDownloadMediaEntityStatus can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000011 | The data write error, data is invalid.                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 向音频模板控制方同步单曲下载状态信息，用于刷新下载进度。
   */
  public setDownloadMediaEntityStatus(mediaEntity: avMusicTemplate.MediaEntity) {
    this.template?.setDownloadMediaEntityStatus(mediaEntity);
  };

  /**
   * 模拟下载过程。
   *
   * @param mediaEntity 媒体实体。
   */
  private async downloadMediaEntity(mediaEntity: avMusicTemplate.MediaEntity) {
    // 下载完成之后。
    this.setDownloadMediaEntityStatus(mediaEntity);
  };
}
```

## setCustomElements

setCustomElements(actionType: ActionType, customType: CustomType, customElement: CustomElement): Promise&lt;void&gt;

向音频模板控制方同步自定义元素变更信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名        | 类型                                                         | 必填 | 说明         |
| ------------- | ------------------------------------------------------------ | ---- | ------------ |
| actionType    | [ActionType](arkts-apis-avMusicTemplate-t.md#actiontype) | 是   | 操作类型。   |
| customType    | [CustomType](arkts-apis-avMusicTemplate-t.md#customtype) | 是   | 自定义类型。 |
| customElement | [CustomElement](arkts-apis-avMusicTemplate-i.md#customelement) | 是   | 自定义元素。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function setCustomElements can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000011 | The data write error, data is invalid.                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 向音频模板控制方同步自定义元素变更信息。
   */
  public setCustomElements() {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    }
    let compilation: avMusicTemplate.Compilation = {
      errorCode: 0,
      errorMsg: 'success',
      id: 'id',
      title: 'title',
      hasMoreData: true,
      totalSize: 2,
      memberMediaType: avMusicTemplate.EntityType.SINGLE,
      topElements: [mediaEntity]
    }
    let customElement: avMusicTemplate.CustomElement = {
      errorCode: 0,
      errorMsg: 'success',
      customCompilations: [compilation]
    }
    this.template?.setCustomElements('add', 'COMPILATION', customElement);
  };
}
```
## setSettings

setSettings(settingItems: SettingItem[]): Promise&lt;void&gt;

向音频模板控制方同步设置信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明         |
| ------------ | ------------------------------------------------------------ | ---- | ------------ |
| settingItems | [SettingItem](arkts-apis-avMusicTemplate-i.md#settingitem)[] | 是   | 设置项数组。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function setSettings can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000011 | The data write error, data is invalid.                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 向音频模板控制方同步设置信息。
   */
  public setSettings() {
    let settingItems: avMusicTemplate.SettingItem[] = [{
      id: 'id',
      title: 'title',
      desc: 'desc',
      mediaId: 'mediaId',
      settingType: avMusicTemplate.SettingType.SWITCH,
      settingValue: false
    }];
    this.template?.setSettings(settingItems);
  };
}
```

## reportExecuteAction

reportExecuteAction(actionType: string, params: string): Promise&lt;void&gt;

向音频模板控制方同步执行操作信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型   | 必填 | 说明       |
| ---------- | ------ | ---- | ---------- |
| actionType | string | 是   | 行为类型。 |
| params     | string | 是   | 行为信息。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function reportExecuteAction can not work correctly due to limited device capabilities. |
| 35000005 | AVMusicTemplate does not exist.                              |
| 35000011 | The data write error, data is invalid.                       |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 向音频模板控制方同步执行操作信息。
   */
  public reportExecuteAction() {
    let actionType: string = 'actionType';
    let params: string = 'params';
    this.template?.reportExecuteAction(actionType, params);
  };
}
```

## setExtensionAbility

setExtensionAbility(want: WantAgent): Promise&lt;void&gt;

向音频模板控制方同步用于被拉起的Ability。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明       |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| want   | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md#wantagent) | 是   | 能力信息。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 801      | capability not supported.              |
| 35000005 | AVMusicTemplate does not exist.        |
| 35000011 | The data write error, data is invalid. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';
import { wantAgent } from '@kit.AbilityKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  /**
   * 媒体应用需要拉起应用的自定义界面时调用。
   */
  public setExtensionAbility() {
    let wantAgentInfo: wantAgent.WantAgentInfo = {
      wants: [
        {
          bundleName: "com.example.templateprovider",
          abilityName: 'EntryAbility',
          type: 'action',
          parameters: {
            'ability.want.params.uiExtensionType': 'action'
          }
        }
      ],
      actionType: wantAgent.OperationType.START_ABILITIES,
      requestCode: 0
    }
    wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
      this.template?.setExtensionAbility(agent);
    })
  };
}
```

## destroy

destroy(): Promise&lt;void&gt;

销毁音频模板实例。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.function destroy can not work correctly due to limited device capabilities. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class TemplateManager {
  private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;

  public unregisterListener() {
    this.template?.destroy();
    this.template = undefined;
  }
}
```