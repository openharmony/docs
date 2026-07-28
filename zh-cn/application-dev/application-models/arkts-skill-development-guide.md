# 基于ArkTS脚本的应用Skill开发指导

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->

## 概述

从API版本26.0.0开始，Ability Kit支持将应用内业务能力以Skill形式开放给系统智能体调用。Skill提供一种声明式的能力外化机制：开发者将应用内可被外部调用的业务能力组织为若干能力单元，每个单元由一份描述文件（声明其触发场景、入参约束与返回值契约）与一份ArkTS入口脚本（将外部调用桥接到应用内既有业务实现）共同构成，并通过模块配置绑定到指定Ability的运行上下文。运行时，系统智能体依据描述文件完成“意图—能力”的语义匹配，并将结果转化为面向用户的自然语言回复。

通过Skill，开发者得以在不改造既有业务实现的前提下，以薄封装将应用能力开放给系统智能体；系统智能体无需理解各应用的内部实现，仅依赖统一的声明契约即可完成调度。
> **说明：**
>
> 仅支持Stage模型，FA模型不可用。

## 接口说明

以下是基于ArkTS脚本开发应用Skill使用的主要接口，更多接口及使用方式请见[@ohos.app.ability.scriptManager](../reference/apis-ability-kit/js-apis-app-ability-scriptManager.md)。

| 接口名 | 描述 |
| -------- | -------- |
| [ExecuteResult](../reference/apis-ability-kit/js-apis-app-ability-scriptManager.md#executeresult) | ArkTS脚本执行结果。 |
| [ArkTSScriptInfo](../reference/apis-ability-kit/js-apis-app-ability-scriptManager.md#arktsscriptinfo) | 应用的ArkTS脚本入口函数的第一个参数，用于接收系统传递的脚本上下文信息。 |
| [completeArkTSScriptInApp(context: Context, requestCode: string, result: ExecuteResult): Promise\<void>](../reference/apis-ability-kit/js-apis-app-ability-scriptManager.md#scriptmanagercompletearktsscriptinapp) | 完成应用的ArkTS脚本执行，上报执行结果。使用Promise异步回调。 |

## 开发步骤

下文以“音乐助手Skill（`example-org-music-assistant`）”为示例，演示如何在自有应用中，通过代码开发和封装，实现按名称播放音乐（`playMusicByName`）与播放控制（`controlPlayback`）的能力。

1. 创建文件和目录。

   在模块（`entry`）下按以下结构创建文件和目录：

   ```text
   Application/
   ├── AppScope/
   │   ├── app.json5
   │   └── resources/
   └── entry/
       ├── skills/                            <- 【固定值】当前模块所有Skill的根目录
       │   └── example-org-music-assistant/   <- Skill名，需与SKILL.md的name一致，为防止命名冲突，推荐使用公司或组织名作为前缀
       │       ├── scripts/                   <- 【固定值】ETS脚本目录
       │       │   └── MusicSkill.ets         <- Skill入口脚本
       │       └── SKILL.md                   <- 【固定值】Skill描述文件
       └── src/
           └── main/
               ├── ets/
               │   ├── entryability/
               │   │   └── EntryAbility.ets
               │   └── service/
               │       └── MusicPlayer.ets    <- 应用内业务服务(被Skill入口脚本调用)
               ├── module.json5
               └── resources/
   ```

2. 配置module.json5文件。

   在`entry/src/main/module.json5`的`module`标签下新增[skillProfiles标签](../quick-start/module-configuration-file.md#skillprofiles标签)，将Skill注册到模块。

   示例Skill运行时需要添加网络权限访问云端音乐列表，在`module`标签下的requestPermissions标签配置。

   <!-- @[module_skill](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ArktsSkillDevelopmentGuide/entry/src/main/module.json5) -->
   
   ``` JSON5
   {
     "module": {
       // ...
       "skillProfiles": [
         {
           "name": "music-assistant", // Skill名，需与SKILL.md的name一致
           "abilityName": "EntryAbility", // 与该Skill关联的组件名称
           "srcEntries": [  // 实现Skill的代码文件路径列表
             "../../skills/music-assistant/scripts/MusicSkill.ets"
           ],
           "version": "1.0.0"
         }
       ],
   
       "requestPermissions": [  // Skill运行需要的权限列表
         { "name": "ohos.permission.INTERNET" }
       ],
       // ...
     }
   }
   ```

3. 实现ArkTS脚本。

   ArkTS入口脚本（`MusicSkill.ets`）是Skill调用链路上的“薄适配层”，负责把系统智能体传入的字符串参数转交给应用内已有业务实现，并把业务执行结果按SKILL.md声明的契约回传。其调用的`MusicPlayer`属于应用既有业务实现，与Skill机制本身无耦合，本节不再展开其内部逻辑。

   3.1 导入Skill相关接口。

   入口脚本需要从`@kit.AbilityKit`引入`scriptManager`，同时引入待桥接的应用内业务模块。

   <!-- @[music_skill_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ArktsSkillDevelopmentGuide/entry/skills/example-org-music-assistant/scripts/MusicSkill.ets) -->
   
   ``` TypeScript
   
   import { scriptManager } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // 应用既有业务模块
   import { MusicPlayer, Track, PlayResult } from '../../../src/main/ets/service/MusicPlayer';
   ```

   3.2 定义入口类骨架。

   入口脚本以`export default`方式导出一个类，类内每个`public async`方法对应SKILL.md声明的一项能力，须满足以下约定：

   - **方法名约定**：必须与SKILL.md中的`functionName`严格一致（本例为`playMusicByName`、`controlPlayback`）。
   - **方法签名约定**：第一个参数类型固定为[ArkTSScriptInfo](../reference/apis-ability-kit/js-apis-app-ability-scriptManager.md#arktsscriptinfo)。

   <!-- @[music_skill](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ArktsSkillDevelopmentGuide/entry/skills/example-org-music-assistant/scripts/MusicSkill.ets) -->
   
   ``` TypeScript
   export default class MusicSkill {
     // ...
     public async playMusicByName(info: scriptManager.ArkTSScriptInfo, ...argv: string[]): Promise<void> {
       /* 见 3.3 ~ 3.5 */
       // ...
     }
   
     // ...
     public async controlPlayback(info: scriptManager.ArkTSScriptInfo, ...argv: string[]): Promise<void> {
       /* 同上模式 */
       // ...
     }
   
     // ...
   }
   ```

   3.3 解析并校验入参。

   每个能力方法的第一项任务是从`argv`中按位置获取参数，对照SKILL.md的`args` Schema完成前置校验。

   <!-- @[music_skill_verify](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ArktsSkillDevelopmentGuide/entry/skills/example-org-music-assistant/scripts/MusicSkill.ets) -->
   
   ``` TypeScript
   // 例1：playMusicByName 的两个可选参数，至少一个非空
   const songName: string = argv.length > 0 ? argv[0].trim() : '';
   const singer: string = argv.length > 1 ? argv[1].trim() : '';
   if (songName.length === 0 && singer.length === 0) {
     // 走 ERR_INVALID_PARAMS 分支回包（见 3.5），不再进入业务
         // ...
     return;
   }
       // ...
   
   // 例2：controlPlayback 的枚举值参数，需用白名单二次校验
   const action: string = argv.length > 0 ? argv[0].trim() : '';
   const validActions: string[] = ['pause', 'resume', 'next', 'previous'];
   if (!validActions.includes(action)) {
     // 走 ERR_INVALID_PARAMS 分支回包
         // ...
     return;
   }
   ```

   3.4 调用应用内业务实现。

   校验通过后，调用既有业务接口完成实际任务。入口脚本不承载业务逻辑，仅充当“参数适配器”，读取业务返回值与运行时异常，分别映射到SKILL.md声明的不同结果分支。


   <!-- @[music_skill_try](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ArktsSkillDevelopmentGuide/entry/skills/example-org-music-assistant/scripts/MusicSkill.ets)  -->
   
   ``` TypeScript
   
   try {
     // 直接调用应用内已有业务API
     const playResult: PlayResult | null = MusicPlayer.searchAndPlay(songName, singer);
     // 业务返回值 → 映射到"成功"或"未命中"分支（见 3.5）
         // ...
   } catch (e) {
     // 业务异常 → 统一映射到 ERR_INTERNAL 分支（见 3.5）
     const err = e as BusinessError;
   // ...
   }
   ```

   3.5 按契约构造ExecuteResult并回传。

   业务执行完成后，需将结果封装为[ExecuteResult](../reference/apis-ability-kit/js-apis-app-ability-scriptManager.md#executeresult)，并通过调用[completeArkTSScriptInApp](../reference/apis-ability-kit/js-apis-app-ability-scriptManager.md#scriptmanagercompletearktsscriptinapp)回传给系统智能体，回包内容应与SKILL.md中“执行返回值”声明的分支保持一致。

   <!-- @[music_skill_branch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/ArktsSkillDevelopmentGuide/entry/skills/example-org-music-assistant/scripts/MusicSkill.ets) -->
   
   ``` TypeScript
   // 成功分支示例
   const first: Track = playResult.tracks[0];     
   const playingTrack: Record<string, Object> = {     
     'name': first.name,     
     'singer': first.singer,     
     'duration': first.duration     
   };
   const data: Record<string, Object> = {     
     'playingTrack': playingTrack,     
     'matchedCount': playResult.tracks.length     
   };
   const payload: Record<string, Object> = {
     'type': 'result',
     'status': 'success',
     'data': data
   };
   await this.report(info, { code: 0, result: payload });
         // ...
   
   // 失败分支示例（以 ERR_NOT_FOUND 为例）
   const payloadData: Record<string, Object> = {     
     'searchedKeywords': [] 
   };
   const payload: Record<string, Object> = {
     'type': 'result',
     'status': 'failed',
     'errCode': 'ERR_NOT_FOUND',
     'data': payloadData,
     'suggestion': `没有找到${singer}${songName.length > 0 ? `的《${songName}》` : '相关歌曲'}`
   };
   await this.report(info, { code: -1, result: payload });
   // ...
   
   // 唯一的回包出口：只封装API调用与异常打印，不参与结果构造
   private async report(info: scriptManager.ArkTSScriptInfo, result: scriptManager.ExecuteResult): Promise<void> {
     try {
       await scriptManager.completeArkTSScriptInApp(info.context, info.requestCode, result);
     } catch (e) {
       const err = e as BusinessError;
       console.error(`completeArkTSScriptInApp failed, code: ${err.code}, message: ${err.message}`);
     }
   }
   ```

4. 编写SKILL.md。

   SKILL.md是Skill的声明契约文件，是系统智能体进行“意图—能力”匹配的唯一依据。主要由“元数据->触发场景->能力契约”三段构成。

   4.1 撰写元数据（YAML Front Matter）。

   在文件头部使用YAML Front Matter声明 `name` 与 `description`。其中，`name` 必须与 Skill 目录名以及 `module.json5` 中 `skillProfiles[].name` 完全保持一致；`description` 应简洁地描述能力范围，作为系统智能体进行 Skill 初次筛选的关键依据。

   ```text
   ---
   name: example-org-music-assistant
   description: 提供音乐搜索播放与播控能力，响应“放首歌”、“切歌”、“暂停”等播放控制类指令
   ---
   ```

   4.2 撰写触发场景。

   用自然语言列出典型话术，并补充不要调用的情况以划清能力边界，降低误触发。典型话术应覆盖能力对应的多种说法，边界说明应覆盖容易混淆的相邻意图。

   ```text
   ## 触发场景

   当用户明确表达**播放音乐**或**控制当前播放**时调用。典型话术：

   - “放一首SingerA的《SongA》”
   - “来首《SongA》”
   - “暂停”、“继续播放”
   - “切歌”、“下一首”、“上一曲”

   不调用的情况：

   - 用户说“把这首歌加入收藏”——意图是修改歌单，本Skill仅支持播放与播控。
   - 用户说“今天有什么演唱会”——意图是查询资讯，非播放。
   - 用户没有明确指向播放（如“这首歌真好听”）——情绪表达，无需调用。
   - 用户说“调小音量”——意图是系统音量控制，应走系统能力。
   ```

   4.3 为每项能力撰写“执行参数”契约。

   每项能力对应一个`### 场景N：能力名（functionName）`子小节，“执行参数”部分需包含`exec-cli`形式的调用示例和一份JSON Schema约束。

   调用示例包含四个核心字段：`command`固定为`ohos-arkTSScript`；`skillName`需与SKILL.md中的`name`保持一致；`scriptPath`为相对于Skill目录的入口脚本路径；`functionName`必须与MusicSkill.ets中public方法名严格对应。

   ```bash
   exec-cli(command: ohos-arkTSScript --skillName 'example-org-music-assistant' --scriptPath 'scripts/MusicSkill.ets' --functionName 'playMusicByName' --args '{
       "arg1": "SongA",
       "arg2": "SingerA"
   }'
   )
   ```

    Schema的核心在于`args`子对象，它定义了系统智能体可填写的入参结构。`playMusicByName`支持“歌名”和“歌手”二选一填写，因此使用`anyOf`约束以确保至少包含其中之一：

   ```json
   "args": {
     "type": "object",
     "properties": {
       "arg1": {
         "type": "string",
         "description": "歌曲名，如《SongA》"
       },
       "arg2": {
         "type": "string",
         "description": "歌手名，如SingerA"
       }
     },
     "anyOf": [
       { "required": ["arg1"] },
       { "required": ["arg2"] }
     ]
   }
   ```

   4.4 为每项能力撰写“执行返回值”契约。

   “执行返回值”部分需先列出所有可能的结果示例（成功 + 各类失败），再给出整体的JSON Schema约束。

   以`playMusicByName`为例，需逐一列出四组示例：

   ```json5
   // 1. 成功播放
   {
       "type": "result",
       "status": "success",
       "data": {
           "playingTrack": {
               "name": "SongA",
               "singer": "SingerA",
               "duration": 269
           },
           "matchedCount": 1
       }
   }
   ```

   ```json5
   // 2. 入参非法
   {
       "type": "result",
       "status": "failed",
       "errCode": "ERR_INVALID_PARAMS",
       "errMsg": "songName and singer are both empty",
       "suggestion": "我没听清，你想听哪首歌？"
   }
   ```

   ```json5
   // 3. 未命中
   {
       "type": "result",
       "status": "failed",
       "errCode": "ERR_NOT_FOUND",
       "data": {
           "searchedKeywords": ["SongA", "SingerA"]
       },
       "suggestion": "没有找到SingerA的《SongA》"
   }
   ```

   ```json5
   // 4. 内部错误
   {
       "type": "result",
       "status": "failed",
       "errCode": "ERR_INTERNAL",
       "errMsg": "network timeout",
       "suggestion": "播放失败了，稍后再试试"
   }
   ```

   对应的Schema顶层定义公共字段，并通过`oneOf`枚举上述四种分支形态：

   ```json5
   {
     "type": "object",
     "required": ["type", "status"],
     "properties": {
       "type":   { "type": "string", "const": "result" },
       "status": { "type": "string", "enum": ["success", "failed"] },
       "data":   { "type": "object" },
       "errCode": {
         "type": "string",
         "enum": ["ERR_INVALID_PARAMS", "ERR_NOT_FOUND", "ERR_INTERNAL"]
       },
       "errMsg":     { "type": "string", "minLength": 1 },
       "suggestion": { "type": "string", "minLength": 1 }
     },
     "oneOf": [
       /* 成功：               要求 data.playingTrack 与 data.matchedCount */
       /* ERR_INVALID_PARAMS:  要求 errMsg 与 suggestion */
       /* ERR_NOT_FOUND:       要求 data.searchedKeywords 与 suggestion */
       /* ERR_INTERNAL:        要求 errMsg 与 suggestion */
     ]
   }
   ```

## 相关实例

针对应用Skill开发，可参考以下相关实例：

- [音乐助手Skill示例工程（example-org-music-assistant）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/bmsSample/ArktsSkillDevelopmentGuide)
