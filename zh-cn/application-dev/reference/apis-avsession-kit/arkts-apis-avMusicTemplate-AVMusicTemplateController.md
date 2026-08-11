# Class (AVMusicTemplateController)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_gyH0B0hP-->
<!--Designer: @ccfriend-->
<!--Tester: @chen-gong1-->
<!--Adviser: @w_Machine_cc-->

音频模板控制器，可以获得音频模板控制器唯一的标识，用于与接入音频模板的媒体应用数据交互。

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

| 名称      | 类型    | 只读 | 可选 | 说明                                                    |
| :-------- | :------ | :--- | :--- | :------------------------------------------------------ |
| sessionId | string  | 否   | 否   | 音频模板控制器唯一的标识。                              |
| isDestroy | boolean | 否   | 否   | 音频模板控制器是否销毁。true表示已经销毁，false表示没有销毁。无默认值。 |

## queryMainTabs

queryMainTabs(): Promise&lt;MediaTab[]&gt;

查询主标签。通过音频模板控制器向媒体应用请求主标签列表，返回包含标签ID、标签名称等信息的主标签数组。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                                                         | 说明                                  |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise<[MediaTab](arkts-apis-avMusicTemplate-i.md#mediatab)[]> | Promise对象，返回查询的主标签页数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 查询主标签。
   */
  public async queryMainTabs(): Promise<avMusicTemplate.MediaTab[]> {
    let tabs: avMusicTemplate.MediaTab[] = [];
    if (!this.controller) {
      console.info(TAG, 'queryMainTabs: controller is undefined')
      return tabs;
    }
    try {
      console.info(TAG, 'queryMainTabs')
      tabs = await this.controller.queryMainTabs();
    } catch (e) {
      console.error(TAG, `Failed to query main tabs. Code: ${e?.code}, message: ${e?.message}`);
    }
    return tabs;
  }
}
```

## queryMediaTabContent

queryMediaTabContent(tabId: string): Promise&lt;MediaTabContent&gt;

查询媒体标签内容。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| tabId  | string | 是   | 标签页ID。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise<[MediaTabContent](arkts-apis-avMusicTemplate-i.md#mediatabcontent)> | Promise对象，返回媒体标签页内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟查询媒体标签页内容。
   *
   * @param tabId 标签页ID。
   */
  public async queryMediaTabContent(tabId: string): Promise<avMusicTemplate.MediaTabContent | undefined> {
    try {
      let tabContent: avMusicTemplate.MediaTabContent | undefined = await this.controller?.queryMediaTabContent(tabId);
      if (tabContent?.errorCode != 0) {
        console.warn(TAG, 'queryMediaTabContent fail')
        return undefined;
      }
      console.info('Succeeded in querying media tab content.');
      return tabContent;
    } catch (e) {
      console.error(TAG, `queryMediaTabContent failed, errCode: ${e?.code}`)
      return undefined;
    }
  }
}
```

## queryMediaEntity

queryMediaEntity(params: QueryMediaEntityParam): Promise&lt;PageMediaEntity&gt;

查询媒体实体。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| params | [QueryMediaEntityParam](arkts-apis-avMusicTemplate-i.md#querymediaentityparam) | 是   | 查询媒体实体参数。 |

**返回值：**

| 类型                                                         | 说明                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| Promise<[PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity)> | Promise对象，返回查询的媒体实体分页对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟查询媒体实体。
   *
   * @returns 页面媒体实体。
   */
  public async queryMediaEntity(): Promise<avMusicTemplate.PageMediaEntity | undefined> {
    // 查询媒体实体。
    let queryMediaEntityParam: avMusicTemplate.QueryMediaEntityParam = {
      entityId: 'entityId',
      pageIndex: 0,
      type: avMusicTemplate.EntityType.SINGLE
    };
    try {
      let pageMediaEntity: avMusicTemplate.PageMediaEntity | undefined =
        await this.controller?.queryMediaEntity(queryMediaEntityParam);
      if (pageMediaEntity?.errorCode != 0) {
        console.warn(TAG, 'queryMediaEntity fail')
        return undefined;
      }
      console.info('Succeeded in querying media entity.');
      return pageMediaEntity;
    } catch (e) {
      console.error(TAG, `queryMediaEntity failed, errCode: ${e?.code}`)
      return undefined;
    }
  }
}
```

## queryCompilation

queryCompilation(compilationId: string, pageIndex: number): Promise&lt;PageMediaEntity&gt;

查询媒体内容合集。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名        | 类型   | 必填 | 说明           |
| ------------- | ------ | ---- | -------------- |
| compilationId | string | 是   | 合集的ID。     |
| pageIndex     | number    | 是   | 页索引。 |

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise<[PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity)> | Promise对象，返回查询的合集的分页对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟查询合集。
   *
   * @returns 页面媒体实体。
   */
  public async queryCompilation(): Promise<avMusicTemplate.PageMediaEntity | undefined> {
    let compilationId: string = 'compilationId';
    let pageIndex: number = 0;
    try {
      let pageMediaEntity: avMusicTemplate.PageMediaEntity | undefined =
        await this.controller?.queryCompilation(compilationId, pageIndex);
      if (pageMediaEntity?.errorCode != 0) {
        console.warn(TAG, 'queryCompilation fail')
        return undefined;
      }
      console.info('Succeeded in querying compilation.');
      return pageMediaEntity;
    } catch (e) {
      console.error(TAG, `queryCompilation failed, errCode: ${e?.code}`)
      return undefined;
    }
  }
}
```

## queryPlaylist

queryPlaylist(pageIndex: number, sort: Sort): Promise&lt;PageMediaEntity&gt;

查询播放列表。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名    | 类型                                                   | 必填 | 说明                             |
| --------- | ------------------------------------------------------ | ---- | -------------------------------- |
| pageIndex | number                                                 | 是   | 页索引。                   |
| sort      | [Sort](arkts-apis-avMusicTemplate-e.md#sort) | 是   | 查询到的播放列表数据的排序类型。 |

**返回值：**

| 类型                                                         | 说明                                        |
| ------------------------------------------------------------ | ------------------------------------------- |
| Promise<[PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity)> | Promise对象，返回查询的播放列表的分页对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟查询播放列表。
   *
   * @returns 页面媒体实体。
   */
  public async queryPlaylist(): Promise<avMusicTemplate.PageMediaEntity | undefined> {
    let pageIndex: number = 0;
    let sort: avMusicTemplate.Sort = avMusicTemplate.Sort.ORDER;
    try {
      let pageMediaEntity: avMusicTemplate.PageMediaEntity | undefined =
        await this.controller?.queryPlaylist(pageIndex, sort);
      if (pageMediaEntity?.errorCode != 0) {
        console.warn(TAG, 'queryPlaylist fail')
        return undefined;
      }
      console.info('Succeeded in querying playlist.');
      return pageMediaEntity;
    } catch (e) {
      console.error(TAG, `queryPlaylist failed, errCode: ${e?.code}`)
      return undefined;
    }
  }
}
```

## queryCurrentSingle

queryCurrentSingle(): Promise&lt;Single&gt;

查询当前正在播放的单曲。通过音频模板控制器从媒体应用获取当前播放会话中的单曲信息，包括媒体ID、标题、作者等元数据。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                                                         | 说明                        |
| ------------------------------------------------------------ | --------------------------- |
| Promise<[Single](arkts-apis-avMusicTemplate-i.md#single)> | Promise对象，返回当前单曲。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟查询当前单曲。
   *
   * @returns 单曲。
   */
  public async queryCurrentSingle(): Promise<avMusicTemplate.Single | undefined> {
    try {
      let single: avMusicTemplate.Single | undefined = await this.controller?.queryCurrentSingle();
      if (!single?.mediaId || single?.mediaId === '') {
        console.warn(TAG, 'queryCurrentSingle fail')
        return undefined;
      }
      console.info('Succeeded in querying current single.');
      return single;
    } catch (e) {
      console.error(TAG, `queryCurrentSingle failed, errCode: ${e?.code}`)
      return undefined;
    }
  }
}
```

## queryCompilationByKeyword

queryCompilationByKeyword(keyword: string): Promise&lt;Compilation[]&gt;

按关键字查询合集。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名  | 类型   | 必填 | 说明     |
| ------- | ------ | ---- | -------- |
| keyword | string | 是   | 关键字。 |

**返回值：**

| 类型                                                         | 说明                        |
| ------------------------------------------------------------ | --------------------------- |
| Promise<[Compilation](arkts-apis-avMusicTemplate-i.md#compilation)[]> | Promise对象，返回合集数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟按关键字查询合集。
   *
   * @returns 合集数组。
   */
  public async queryCompilationByKeyword(): Promise<avMusicTemplate.Compilation[]> {
    let compilations: avMusicTemplate.Compilation[] = [];
    if (!this.controller) {
      console.error(TAG, 'queryCompilationByKeyword controller is undefined');
      return compilations;
    }
    let keyword: string = 'keyword';
    try {
      compilations = await this.controller.queryCompilationByKeyword(keyword);
      console.info('Succeeded in querying compilation by keyword.');
    } catch (e) {
      console.error(TAG, `queryCompilationByKeyword failed, errCode: ${e?.code}`)
    }
    return compilations;
  }
}
```

## queryMediaEntityByKeyword

queryMediaEntityByKeyword(keyword: string, searchType: EntityType, pageIndex: number): Promise&lt;PageMediaEntity&gt;

按关键字查询媒体实体。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明           |
| ---------- | ------------------------------------------------------------ | ---- | -------------- |
| keyword    | string                                                       | 是   | 关键字。       |
| searchType | [EntityType](arkts-apis-avMusicTemplate-e.md#entitytype) | 是   | 媒体资源类型。 |
| pageIndex  | number                                                          | 是   | 页索引。   |

**返回值：**

| 类型                                                         | 说明                                                |
| ------------------------------------------------------------ | --------------------------------------------------- |
| Promise<[PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity)> | Promise对象，返回与该关键字相关的媒体实体分页对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟按关键字查询媒体实体。
   *
   * @returns 合集数组。
   */
  public async queryMediaEntityByKeyword(): Promise<avMusicTemplate.PageMediaEntity | undefined> {
    let keyword: string = 'keyword';
    let searchType: avMusicTemplate.EntityType = avMusicTemplate.EntityType.SINGER;
    let pageIndex: number = 0;
    try {
      let pageMediaEntity: avMusicTemplate.PageMediaEntity | undefined =
        await this.controller?.queryMediaEntityByKeyword(keyword, searchType, pageIndex);
      if (pageMediaEntity?.errorCode != 0) {
        console.warn(TAG, 'queryMediaEntityByKeyword fail')
        return undefined;
      }
      console.info('Succeeded in querying media entity by keyword.');
      return pageMediaEntity;
    } catch (e) {
      console.error(TAG, `queryMediaEntityByKeyword failed, errCode: ${e?.code}`)
    }
    return undefined;
  }
}
```

## queryRecommendMediaEntityList

queryRecommendMediaEntityList(): Promise&lt;MediaEntity[]&gt;

查询推荐的媒体实体列表。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                                                         | 说明                                  |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise<[MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity)[]> | Promise对象，返回推荐的媒体实体数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟查询推荐的媒体实体列表。
   *
   * @returns 媒体实体数组。
   */
  public async queryRecommendMediaEntityList(): Promise<avMusicTemplate.MediaEntity[]> {
    let mediaEntities: avMusicTemplate.MediaEntity[] = [];
    if (!this.controller) {
      console.error(TAG, 'queryRecommendMediaEntityList controller is undefined');
      return mediaEntities;
    }
    try {
      mediaEntities = await this.controller.queryRecommendMediaEntityList();
      console.info('Succeeded in querying recommend media entity list.');
    } catch (e) {
      console.error(TAG, `queryRecommendMediaEntityList failed, errCode: ${e?.code}`)
    }
    return mediaEntities;
  }
}
```

## queryHotWords

queryHotWords(): Promise&lt;string[]&gt;

查询热词。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型              | 说明                        |
| ----------------- | --------------------------- |
| Promise<string[]> | Promise对象，返回热词数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟查询热词。
   *
   * @returns 热词数组。
   */
  public async queryHotWords(): Promise<string[]> {
    let hotWords: string[] = [];
    if (!this.controller) {
      console.error(TAG, 'queryHotWords controller is undefined');
      return hotWords;
    }
    try {
      hotWords = await this.controller.queryHotWords();
      console.info('Succeeded in querying hot words.');
    } catch (e) {
      console.error(TAG, `queryHotWords failed, errCode: ${e?.code}`)
    }
    return hotWords;
  }
}
```

## querySearchHistory

querySearchHistory(): Promise&lt;string[]&gt;

查询搜索历史。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型              | 说明                              |
| ----------------- | --------------------------------- |
| Promise<string[]> | Promise对象，返回历史搜索词数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟查询搜索历史。
   *
   * @returns 搜索历史数组。
   */
  public async querySearchHistory(): Promise<string[]> {
    let searchHistory: string[] = [];
    if (!this.controller) {
      console.error(TAG, 'querySearchHistory controller is undefined');
      return searchHistory;
    }
    try {
      searchHistory = await this.controller.querySearchHistory();
      console.info('Succeeded in querying search history.');
    } catch (e) {
      console.error(TAG, `querySearchHistory failed, errCode: ${e?.code}`)
    }
    return searchHistory;
  }
}
```

## clearSearchHistory

clearSearchHistory(): Promise&lt;OperResult&gt;

清除搜索历史。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                                                         | 说明                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| Promise<[OperResult](arkts-apis-avMusicTemplate-i.md#operresult)> | Promise对象，返回清除搜索历史的操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟清除搜索历史。
   *
   * @returns Promise类型的boolean，清除成功或者失败。
   */
  public async clearSearchHistory(): Promise<boolean> {
    try {
      let operResult: avMusicTemplate.OperResult | undefined = await this.controller?.clearSearchHistory()
      if (operResult?.errorCode != 0) {
        console.warn(TAG, 'clearSearchHistory fail');
        return false;
      }
      console.info('Succeeded in clearing search history.');
      return true;
    } catch (e) {
      console.error(TAG, `clearSearchHistory failed, errCode: ${e?.code}`);
      return false;
    }
  }
}
```

## updateSettings

updateSettings(settingItem: SettingItem): Promise&lt;SettingItem&gt;

更新设置信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明             |
| ----------- | ------------------------------------------------------------ | ---- | ---------------- |
| settingItem | [SettingItem](arkts-apis-avMusicTemplate-i.md#settingitem) | 是   | 待更新的设置项。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise<[SettingItem](arkts-apis-avMusicTemplate-i.md#settingitem)> | Promise对象，返回更新后的设置项。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟更新设置信息。
   *
   * @returns Promise类型更新后的设置项。
   */
  public async updateSettings(): Promise<avMusicTemplate.SettingItem | undefined> {
    let settingItem: avMusicTemplate.SettingItem = {
      id: 'id',
      title: 'title',
      desc: 'desc',
      mediaId: 'mediaId',
      settingType: avMusicTemplate.SettingType.SWITCH,
      settingValue: false
    };
    try {
      let setting: avMusicTemplate.SettingItem | undefined = await this.controller?.updateSettings(settingItem);
      if (!setting?.id || setting?.id !== settingItem.id) {
        console.warn(TAG, 'updateSettings fail')
        return settingItem;
      }
      console.info('Succeeded in updating settings.');
      return setting;
    } catch (e) {
      console.error(TAG, `updateSettings failed, errCode: ${e?.code}`)
      return settingItem;
    }
  }
}
```

## reportProblemAndAdvice

reportProblemAndAdvice(advice: string): Promise&lt;OperResult&gt;

报告问题和建议。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| advice | string | 是   | 问题或者建议。 |

**返回值：**

| 类型                                                         | 说明                                        |
| ------------------------------------------------------------ | ------------------------------------------- |
| Promise<[OperResult](arkts-apis-avMusicTemplate-i.md#operresult)> | Promise对象，返回报告问题和建议的操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟报告问题和建议。
   *
   * @returns Promise类型上报结果。true：成功。false：失败。
   */
  public async reportProblemAndAdvice(): Promise<boolean> {
    let advice: string = 'advice';
    try {
      let operResult: avMusicTemplate.OperResult | undefined = await this.controller?.reportProblemAndAdvice(advice);
      if (operResult?.errorCode != 0) {
        console.warn(TAG, 'reportProblemAndAdvice fail')
        return false;
      }
      console.info('Succeeded in reporting problem and advice.');
      return true;
    } catch (e) {
      console.error(TAG, `reportProblemAndAdvice failed, errCode: ${e?.code}`)
      return false;
    }
  }
}
```

## login

login(controlType: LoginType, id?: string): Promise&lt;QrCodeInfo[]&gt;

登录媒体应用账号。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明       |
| ----------- | ------------------------------------------------------------ | ---- | ---------- |
| controlType | [LoginType](arkts-apis-avMusicTemplate-t.md#logintype) | 是   | 登录类型。 |
| id          | string                                                       | 否   | 二维码ID。 |

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<[QrCodeInfo](arkts-apis-avMusicTemplate-i.md#qrcodeinfo)[]> | Promise对象，返回二维码信息的数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟登录。
   *
   * @returns Promise类型的二维码信息数组。
   */
  public async login(): Promise<avMusicTemplate.QrCodeInfo[]> {
    let qrCodeInfos: avMusicTemplate.QrCodeInfo[] = [];
    if (!this.controller) {
      console.error(TAG, 'login controller is undefined');
      return qrCodeInfos;
    }
    let controlType: avMusicTemplate.LoginType = 'queryLoginInfo';
    // 可不传id。id为QrCodeInfo.id，用于LoginType为refreshLoginInfo场景。
    let id: string | undefined = undefined;
    try {
      qrCodeInfos = await this.controller.login(controlType, id);
      console.info('Succeeded in logging in callback.');
    } catch (e) {
      console.error(TAG, `login callback failed, errCode: ${e?.code}`)
    }
    return qrCodeInfos;
  }
}
```

## requestDialogInfo

requestDialogInfo(actionType: DialogActionType, actionInfo?: DialogActionInfo): Promise&lt;DialogInfo&gt;

请求对话框信息。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明               |
| ---------- | ------------------------------------------------------------ | ---- | ------------------ |
| actionType | [DialogActionType](arkts-apis-avMusicTemplate-t.md#dialogactiontype) | 是   | 对话框操作类型。   |
| actionInfo | [DialogActionInfo](arkts-apis-avMusicTemplate-i.md#dialogactioninfo) | 否   | 对话框操作的信息。 |

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<[DialogInfo](arkts-apis-avMusicTemplate-i.md#dialoginfo)> | Promise对象，返回对话框信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟请求对话框信息。
   *
   * @returns Promise类型的对话框信息。
   */
  public async requestDialogInfo(): Promise<avMusicTemplate.DialogInfo | undefined> {
    let actionType: avMusicTemplate.DialogActionType = 'open';
    // 可不传actionInfo。用于DialogActionType为refresh和close场景。
    let actionInfo: avMusicTemplate.DialogActionInfo = {
      dialogId: 'dialogId',
      isChecked: true,
      clickedBtnId: 'clickedBtnId'
    };
    try {
      let dialogInfo: avMusicTemplate.DialogInfo | undefined =
        await this.controller?.requestDialogInfo(actionType, actionInfo);
      if (!dialogInfo?.dialogId || dialogInfo?.dialogId === '') {
        console.info(TAG, 'requestDialogInfo fail')
        return undefined;
      }
      console.info('Succeeded in requesting dialog info.');
      return dialogInfo;
    } catch (e) {
      console.error(TAG, `requestDialogInfo failed, errCode: ${e?.code}`)
    }
    return undefined;
  }
}
```

## handleMemberPurchase

handleMemberPurchase(info: MemberPurchaseInfo): Promise&lt;DialogInfo&gt;

处理购买会员情况。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明             |
| ------ | ------------------------------------------------------------ | ---- | ---------------- |
| info   | [MemberPurchaseInfo](arkts-apis-avMusicTemplate-i.md#memberpurchaseinfo) | 是   | 购买会员的信息。 |

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<[DialogInfo](arkts-apis-avMusicTemplate-i.md#dialoginfo)> | Promise对象，返回对话框信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟处理购买会员情况。
   *
   * @returns Promise类型的对话框信息。
   */
  public async handleMemberPurchase(): Promise<avMusicTemplate.DialogInfo | undefined> {
    let memberPurchaseInfo: avMusicTemplate.MemberPurchaseInfo = {
      id: 'id',
      diagramUrl: 'diagramUrl',
      diagramContent: 'diagramContent',
      memberPurchaseType: avMusicTemplate.MemberPurchaseType.NORMAL
    };
    try {
      let dialogInfo: avMusicTemplate.DialogInfo | undefined =
        await this.controller?.handleMemberPurchase(memberPurchaseInfo);
      if (!dialogInfo?.dialogId || dialogInfo?.dialogId === '') {
        console.info(TAG, 'handleMemberPurchase fail')
        return undefined;
      }
      console.info('Succeeded in handling member purchase.');
      return dialogInfo;
    } catch (e) {
      console.error(TAG, `handleMemberPurchase failed, errCode: ${e?.code}`)
    }
    return undefined;
  }
}
```

## queryMemberPurchase

queryMemberPurchase(memberPurchaseType: MemberPurchaseType): Promise&lt;MemberPurchaseInfo[]&gt;

查询购买会员的情况。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名             | 类型                                                         | 必填 | 说明           |
| ------------------ | ------------------------------------------------------------ | ---- | -------------- |
| memberPurchaseType | [MemberPurchaseType](arkts-apis-avMusicTemplate-e.md#memberpurchasetype) | 是   | 会员购买类型。 |

**返回值：**

| 类型                                                         | 说明                                  |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise<[MemberPurchaseInfo](arkts-apis-avMusicTemplate-i.md#memberpurchaseinfo)[]> | Promise对象，返回购买会员信息的数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟查询购买会员的情况。
   *
   * @returns 会员购买信息列表。
   */
  public async queryMemberPurchase(): Promise<avMusicTemplate.MemberPurchaseInfo[]> {
    let memberPurchaseInfo: avMusicTemplate.MemberPurchaseInfo[] = [];
    if (!this.controller) {
      console.error(TAG, 'queryMemberPurchase controller is undefined');
      return memberPurchaseInfo;
    }
    let memberPurchaseType: avMusicTemplate.MemberPurchaseType = avMusicTemplate.MemberPurchaseType.NORMAL;
    try {
      memberPurchaseInfo = await this.controller.queryMemberPurchase(memberPurchaseType);
      console.info('Succeeded in querying member purchase.');
    } catch (e) {
      console.error(TAG, `queryMemberPurchase failed, errCode: ${e?.code}`)
    }
    return memberPurchaseInfo;
  }
}
```

## queryCustomContent

queryCustomContent(queryType: CustomType[]): Promise&lt;CustomElement&gt;

查询自定义内容。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明             |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| queryType | [CustomType](arkts-apis-avMusicTemplate-t.md#customtype)[] | 是   | 自定义类型数组。 |

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<[CustomElement](arkts-apis-avMusicTemplate-i.md#customelement)> | Promise对象，返回查询的自定义元素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟查询自定义内容。
   *
   * @returns 自定义元素。
   */
  public async queryCustomContent(): Promise<avMusicTemplate.CustomElement | undefined> {
    let queryType: avMusicTemplate.CustomType[] = ['USER_INFO', 'TAB', 'COMPILATION', 'SETTINGS'];
    try {
      let customElement: avMusicTemplate.CustomElement | undefined =
        await this.controller?.queryCustomContent(queryType);
      if (customElement?.errorCode != 0) {
        console.warn(TAG, 'queryCustomContent fail')
        return undefined;
      }
      console.info('Succeeded in querying custom content.');
      return customElement;
    } catch (e) {
      console.error(TAG, `queryCustomContent failed, errCode: ${e?.code}`)
      return undefined;
    }
  }
}
```

## downloadMediaEntity

downloadMediaEntity(controlType: DownloadControlType, mediaEntity: MediaEntity): Promise&lt;OperResult&gt;

下载媒体实体。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明             |
| ----------- | ------------------------------------------------------------ | ---- | ---------------- |
| controlType | [DownloadControlType](arkts-apis-avMusicTemplate-t.md#downloadcontroltype) | 是   | 下载的控制类型。 |
| mediaEntity | [MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity) | 是   | 媒体实体。       |

**返回值：**

| 类型                                                         | 说明                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| Promise<[OperResult](arkts-apis-avMusicTemplate-i.md#operresult)> | Promise对象，返回下载媒体实体的操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟下载媒体实体。
   *
   * @returns Promise类型操作结果。
   */
  public async downloadMediaEntity(): Promise<boolean> {
    let controlType: avMusicTemplate.DownloadControlType = 'startDownload';
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    };
    try {
      let operResult: avMusicTemplate.OperResult | undefined =
        await this.controller?.downloadMediaEntity(controlType, mediaEntity);
      if (operResult?.errorCode != 0) {
        console.warn(TAG, 'start downloadMediaEntity fail')
        return false;
      }
      console.info('Succeeded in starting download media entity.');
      return true;
    } catch (e) {
      console.error(TAG, `start downloadMediaEntity failed, errCode: ${e?.code}`)
      return false;
    }
  }
}
```

## playForSearch

playForSearch(command: SearchPlayInfoType, args: SearchPlayInfo): Promise&lt;OperResult&gt;

搜播，支持音视频，示例仅以音频为例。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                 |
| ------- | ------------------------------------------------------------ | ---- | -------------------- |
| command | [SearchPlayInfoType](arkts-apis-avMusicTemplate-e.md#searchplayinfotype) | 是   | 搜播的信息类型。 |
| args    | [SearchPlayInfo](arkts-apis-avMusicTemplate-i.md#searchplayinfo) | 是   | 搜播信息。           |

**返回值：**

| 类型                                                         | 说明                        |
| ------------------------------------------------------------ | --------------------------- |
| Promise<[OperResult](arkts-apis-avMusicTemplate-i.md#operresult)> | Promise对象，返回操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟搜播。
   *
   * @returns Promise类型操作结果。
   */
  public async playForSearch(): Promise<boolean> {
    let command: avMusicTemplate.SearchPlayInfoType = avMusicTemplate.SearchPlayInfoType.PLAY_MUSIC;
    let searchPlayMusicItems: avMusicTemplate.SearchPlayMusicItem[] = [{
      entityId: 'entityId',
      entityName: 'entityName'
    }];
    let searchPlayMusicInfo: avMusicTemplate.SearchPlayMusicInfo = {
      items: searchPlayMusicItems,
      displayName: 'displayName',
      description: 'description'
    };
    let searchPlayInfo: avMusicTemplate.SearchPlayInfo = {
      musicInfo: searchPlayMusicInfo
    };
    try {
      let operResult: avMusicTemplate.OperResult | undefined =
        await this.controller?.playForSearch(command, searchPlayInfo);
      if (operResult?.errorCode != 0) {
        console.warn(TAG, 'playForSearch fail')
        return false;
      }
      console.info('Succeeded in playing for search.');
      return true;
    } catch (e) {
      console.error(TAG, `playForSearch failed, errCode: ${e?.code}`)
      return false;
    }
  }
}
```

## executeAction

executeAction(actionType: string, params: string): Promise&lt;string&gt;

执行动作。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名     | 类型   | 必填 | 说明       |
| ---------- | ------ | ---- | ---------- |
| actionType | string | 是   | 动作类型。 |
| params     | string | 是   | 动作信息。 |

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回执行动作的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟执行动作。
   *
   * @returns Promise<string>类型操作结果。
   */
  public async executeAction(): Promise<string> {
    let actionType: string = 'actionType';
    let params: string = 'params';
    try {
      let result: string | undefined = await this.controller?.executeAction(actionType, params);
      if (!result || result === '') {
        console.warn(TAG, 'executeAction fail')
        return '';
      }
      console.info('Succeeded in executing action.');
      return result;
    } catch (e) {
      console.error(TAG, `executeAction failed, errCode: ${e?.code}`)
      return '';
    }
  }
}
```

## playMediaEntity

playMediaEntity(mediaEntity: MediaEntity): Promise&lt;void&gt;

播放媒体。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明       |
| ----------- | ------------------------------------------------------------ | ---- | ---------- |
| mediaEntity | [MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity) | 是   | 包含标题、作者等元数据的媒体实体对象。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟播放媒体。
   */
  public async playMediaEntity() {
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    };
    this.controller?.playMediaEntity(mediaEntity);
  }
}
```

## favoriteMediaEntity

favoriteMediaEntity(actionType: MediaFavoriteType, mediaEntity: MediaEntity): Promise&lt;OperResult&gt;

收藏媒体。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明             |
| ----------- | ------------------------------------------------------------ | ---- | ---------------- |
| actionType  | [MediaFavoriteType](arkts-apis-avMusicTemplate-t.md#mediafavoritetype) | 是   | 媒体收藏的类型。 |
| mediaEntity | [MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity) | 是   | 媒体实体。       |

**返回值：**

| 类型                                                         | 说明                                  |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise<[OperResult](arkts-apis-avMusicTemplate-i.md#operresult)> | Promise对象，返回收藏媒体的操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000003 | Template listener not registered.         |
| 35000005 | AVMusicTemplate does not exist.           |
| 35000006 | AVMusicTemplateController does not exist. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 模拟收藏媒体。
   *
   * @returns Promise类型操作结果。
   */
  public async favoriteMediaEntity(): Promise<boolean> {
    let actionType: avMusicTemplate.MediaFavoriteType = 'addFavorite';
    let mediaEntity: avMusicTemplate.MediaEntity = {
      mediaId: 'mediaId',
      mediaType: avMusicTemplate.EntityType.SINGLE,
      parentId: 'parentId',
      parentMediaType: avMusicTemplate.EntityType.SINGLE,
      title: 'title',
      imageUrl: 'imageUrl',
      playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
    };
    try {
      let operResult: avMusicTemplate.OperResult | undefined =
        await this.controller?.favoriteMediaEntity(actionType, mediaEntity);
      if (operResult?.errorCode != 0) {
        console.warn(TAG, 'favoriteMediaEntity fail')
        return false;
      }
      console.info('Succeeded in favoriting media entity.');
      return true;
    } catch (e) {
      console.error(TAG, `favoriteMediaEntity failed, errCode: ${e?.code}`)
      return false;
    }
  }
}
```

## onUserInfoChange

onUserInfoChange(callback: Callback&lt;UserInfo&gt;): void

注册用户信息改变的回调。当媒体应用的用户信息发生变化（如登录状态改变、用户资料更新等）时，通过音频模板控制器触发该回调，通知音频模版控制方。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明            |
| -------- | ------------------------------------------------------------ | ---- |---------------|
| callback | Callback<[UserInfo](arkts-apis-avMusicTemplate-i.md#userinfo)> | 是   | 回调函数，参数为用户信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private userInfoChangeCallback: Callback<avMusicTemplate.UserInfo> = (userInfo: avMusicTemplate.UserInfo) => {
    console.info(TAG, 'userInfoChangeCallback');
  };

  public registerListener() {
    // 注册用户信息改变的监听。
    this.controller?.onUserInfoChange(this.userInfoChangeCallback);
  }
}
```

## offUserInfoChange

offUserInfoChange(callback?: Callback&lt;UserInfo&gt;): void

注销用户信息改变的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                               |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| callback | Callback<[UserInfo](arkts-apis-avMusicTemplate-i.md#userinfo)> | 否   | 回调函数，返回用户信息。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销用户信息改变的监听。
    this.controller?.offUserInfoChange();
  }
}
```

## onDialogCommandChange

onDialogCommandChange(callback: ReportDialogCommandEvent): void

注册对话框命令改变的回调。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | [ReportDialogCommandEvent](arkts-apis-avMusicTemplate-t.md#reportdialogcommandevent) | 是   | 回调函数，上报对话框命令事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private reportDialogCommandEvent: avMusicTemplate.ReportDialogCommandEvent =
    (type: avMusicTemplate.DialogControlType, buttonInfo: avMusicTemplate.DialogInfo) => {
      console.info(TAG, 'reportDialogCommandEvent');
    };

  public registerListener() {
    // 注册对话框命令改变的监听。
    this.controller?.onDialogCommandChange(this.reportDialogCommandEvent);
  }
}
```

## offDialogCommandChange

offDialogCommandChange(callback?: ReportDialogCommandEvent): void

注销对话框命令改变的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [ReportDialogCommandEvent](arkts-apis-avMusicTemplate-t.md#reportdialogcommandevent) | 否   | 上报对话框命令事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销对话框命令改变的监听。
    this.controller?.offDialogCommandChange();
  }
}
```

## onCurrentSingleChange

onCurrentSingleChange(callback: Callback&lt;Single&gt;): void

注册当前单曲改变的回调。当正在播放的单曲发生变化（如切换歌曲、开始播放新歌曲等）时，通过音频模板控制器触发该回调，通知音频模版控制方。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                     |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------- |
| callback | Callback<[Single](arkts-apis-avMusicTemplate-i.md#single)> | 是   | 回调函数，返回当前单曲的信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private currentSingleChangeCallback: Callback<avMusicTemplate.Single> = (single: avMusicTemplate.Single) => {
    console.info(TAG, 'onCurrentSingleChange');
  };

  public registerListener() {
    // 注册当前单曲改变的监听。
    this.controller?.onCurrentSingleChange(this.currentSingleChangeCallback);
  }
}
```

## offCurrentSingleChange

offCurrentSingleChange(callback?: Callback&lt;Single&gt;): void

注销当前单曲改变的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                     |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------- |
| callback | Callback<[Single](arkts-apis-avMusicTemplate-i.md#single)> | 否   | 回调函数，返回当前单曲的信息。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销当前单曲改变的监听。
    this.controller?.offCurrentSingleChange();
  }
}
```

## onMediaEntitiesChange

onMediaEntitiesChange(callback: Callback&lt;MediaEntity[]&gt;): void

注册媒体实体改变的回调。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | Callback<[MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity)[]> | 是   | 回调函数，返回媒体实体数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private mediaEntitiesChangeCallback: Callback<avMusicTemplate.MediaEntity[]> =
    (single: avMusicTemplate.MediaEntity[]) => {
      console.info(TAG, 'mediaEntitiesChangeCallback');
    }

  public registerListener() {
    // 注册媒体实体改变的监听。
    this.controller?.onMediaEntitiesChange(this.mediaEntitiesChangeCallback);
  }
}
```

## offMediaEntitiesChange

offMediaEntitiesChange(callback?: Callback&lt;MediaEntity[]&gt;): void

注销媒体实体改变的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | Callback<[MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity)[]> | 否   | 回调函数，返回媒体实体数组。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销媒体实体改变的监听。
    this.controller?.offMediaEntitiesChange();
  }
}
```

## onTabContentChange

onTabContentChange(callback: ReportTabContentEvent): void

注册标签页内容改变的回调。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明               |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| callback | [ReportTabContentEvent](arkts-apis-avMusicTemplate-t.md#reporttabcontentevent) | 是   | 回调函数，上报标签页内容事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private reportTabContentEvent: avMusicTemplate.ReportTabContentEvent =
    (tabId: string, tabContent: avMusicTemplate.MediaTabContent) => {
      console.info(TAG, 'reportTabContentEvent');
    };

  public registerListener() {
    // 注册标签页内容改变的监听。
    this.controller?.onTabContentChange(this.reportTabContentEvent);
  }
}
```

## offTabContentChange

offTabContentChange(callback?: ReportTabContentEvent): void

注销标签页内容改变的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                 |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | [ReportTabContentEvent](arkts-apis-avMusicTemplate-t.md#reporttabcontentevent) | 否   | 上报标签页内容事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销标签页内容改变的监听。
    this.controller?.offTabContentChange();
  }
}
```

## onPlaylistChange

onPlaylistChange(callback: Callback&lt;PageMediaEntity&gt;): void

注册上报播放列表改变的回调。当播放列表发生改变（如添加歌曲、删除歌曲、调整播放顺序等）时，通过音频模板控制器触发该回调，通知音频模板控制方。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| callback | Callback<[PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity)> | 是   | 回调函数，返回标签页媒体实体信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private playlistChangeCallback: Callback<avMusicTemplate.PageMediaEntity> =
    (pageMediaEntity: avMusicTemplate.PageMediaEntity) => {
      console.info(TAG, 'playlistChangeCallback');
    }

  public registerListener() {
    // 注册播放列表改变的监听。
    this.controller?.onPlaylistChange(this.playlistChangeCallback);
  }
}
```

## offPlaylistChange

offPlaylistChange(callback?: Callback&lt;PageMediaEntity&gt;): void

注销上报播放列表改变的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| callback | Callback<[PageMediaEntity](arkts-apis-avMusicTemplate-i.md#pagemediaentity)> | 否   | 回调函数，返回标签页媒体实体信息。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销播放列表改变的监听。
    this.controller?.offPlaylistChange();
  }
}
```

## onDownloadMediaEntityStatusChange

onDownloadMediaEntityStatusChange(callback: Callback&lt;MediaEntity&gt;): void

注册上报下载媒体状态改变的回调。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | Callback<[MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity)> | 是   | 回调函数，返回媒体实体信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private downloadStatusChangeCallback: Callback<avMusicTemplate.MediaEntity> =
    (mediaEntity: avMusicTemplate.MediaEntity) => {
      console.info(TAG, 'downloadStatusChangeCallback');
    };

  public registerListener() {
    // 注册下载媒体状态改变的监听。
    this.controller?.onDownloadMediaEntityStatusChange(this.downloadStatusChangeCallback);
  }
}
```

## offDownloadMediaEntityStatusChange

offDownloadMediaEntityStatusChange(callback?: Callback&lt;MediaEntity&gt;): void

注销上报下载媒体状态改变的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| callback | Callback<[MediaEntity](arkts-apis-avMusicTemplate-i.md#mediaentity)> | 否   | 回调函数，返回媒体实体信息。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销下载媒体状态改变的监听。
    this.controller?.offDownloadMediaEntityStatusChange();
  }
}
```

## onCustomElementsChange

onCustomElementsChange(callback: ReportCustomElementsChangeEvent): void

注册上报自定义元素改变的回调。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | [ReportCustomElementsChangeEvent](arkts-apis-avMusicTemplate-t.md#reportcustomelementschangeevent) | 是   | 回调函数，上报自定义元素改变事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private reportCustomElementsChangeEvent: avMusicTemplate.ReportCustomElementsChangeEvent =
    (actionType: avMusicTemplate.ActionType, customType: avMusicTemplate.CustomType,
      customElement: avMusicTemplate.CustomElement) => {
      console.info(TAG, 'reportCustomElementsChangeEvent');
    };

  public registerListener() {
    // 注册自定义元素改变的监听。
    this.controller?.onCustomElementsChange(this.reportCustomElementsChangeEvent);
  }
}
```

## offCustomElementsChange

offCustomElementsChange(callback?: ReportCustomElementsChangeEvent): void

注销上报自定义元素改变的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| callback | [ReportCustomElementsChangeEvent](arkts-apis-avMusicTemplate-t.md#reportcustomelementschangeevent) | 否   | 上报自定义元素改变事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销自定义元素改变的监听。
    this.controller?.offCustomElementsChange();
  }
}
```

## onSettingsChange

onSettingsChange(callback: Callback&lt;SettingItem[]&gt;): void

注册上报设置改变的回调。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                 |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------ |
| callback | Callback<[SettingItem](arkts-apis-avMusicTemplate-i.md#settingitem)[]> | 是   | 回调函数，返回设置项数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private settingsChangeCallback: Callback<avMusicTemplate.SettingItem[]> =
    (settingItems: avMusicTemplate.SettingItem[]) => {
      console.info(TAG, 'settingsChangeCallback');
    };

  public registerListener() {
    // 注册设置改变的监听。
    this.controller?.onSettingsChange(this.settingsChangeCallback);
  }
}
```

## offSettingsChange

offSettingsChange(callback?: Callback&lt;SettingItem[]&gt;): void

注销上报设置改变的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                 |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------ |
| callback | Callback<[SettingItem](arkts-apis-avMusicTemplate-i.md#settingitem)[]> | 否   | 回调函数，用于接收并处理设置项数组。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销设置改变的监听。
    this.controller?.offSettingsChange();
  }
}
```

## onReportExecuteAction

onReportExecuteAction(callback: ReportExecuteActionEvent): void

注册上报执行动作的回调。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                 |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| callback | [ReportExecuteActionEvent](arkts-apis-avMusicTemplate-t.md#reportexecuteactionevent) | 是   | 回调函数，上报对应按钮动作的事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private reportExecuteActionEvent: avMusicTemplate.ReportExecuteActionEvent =
    (actionType: string, customType: string) => {
      console.info(TAG, 'reportExecuteActionEvent');
    };

  public registerListener() {
    // 注册上报执行动作的监听。
    this.controller?.onReportExecuteAction(this.reportExecuteActionEvent);
  }
}
```

## offReportExecuteAction

offReportExecuteAction(callback?: ReportExecuteActionEvent): void

注销上报执行动作的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                 |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | [ReportExecuteActionEvent](arkts-apis-avMusicTemplate-t.md#reportexecuteactionevent) | 否   | 上报执行动作的事件。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销上报执行动作的监听。
    this.controller?.offReportExecuteAction();
  }
}
```

## onExtensionAbilityChange

onExtensionAbilityChange(callback: ReportExecuteAbilityEvent): void

注册回调，当需要拉起指定媒体应用界面时触发。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| callback | [ReportExecuteAbilityEvent](arkts-apis-avMusicTemplate-t.md#reportexecuteabilityevent) | 是   | 回调函数，通知音频模板控制方拉起指定三方应用界面的事件，包含应用包名和界面名称等信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';
import { WantAgent } from '@kit.AbilityKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private reportExecuteAbilityEvent: avMusicTemplate.ReportExecuteAbilityEvent = (want: WantAgent) => {
    console.info(TAG, 'reportExecuteAbilityEvent');
  };

  public registerListener() {
    // 注册通知媒体中心拉起指定三方应用界面的信息的监听。
    this.controller?.onExtensionAbilityChange(this.reportExecuteAbilityEvent);
  }
}
```

## offExtensionAbilityChange

offExtensionAbilityChange(callback?: ReportExecuteAbilityEvent): void

注销拉起指定媒体应用界面的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                 |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| callback | [ReportExecuteAbilityEvent](arkts-apis-avMusicTemplate-t.md#reportexecuteabilityevent) | 否   | 通知音频模板控制方拉起指定的媒体应用界面的事件回调。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 801      | capability not supported.                 |
| 35000006 | AVMusicTemplateController does not exist. |
| 35000012 | AVMusicTemplate error.                    |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销通知媒体中心拉起指定三方应用界面的信息的监听。
    this.controller?.offExtensionAbilityChange();
  }
}
```

## destroy

destroy(): Promise&lt;void&gt;

销毁音频模板控制器。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                  |
| -------- | ------------------------- |
| 801      | capability not supported. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private currentBundleName: string | undefined = undefined;

  /**
   * 销毁控制器。
   */
  public destroyController() {
    console.info(TAG, 'destroyController')
    this.controller?.destroy();
    this.controller = undefined;
    this.currentBundleName = undefined;
  }
}
```