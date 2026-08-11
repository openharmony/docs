# 本地媒体会话常见问题
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

本文汇总音视频应用在本地媒体会话接入[AVSession Kit简介](avsession-overview.md)过程中遇到的典型问题及其定位与解决方法。开发者可结合[媒体会话管理错误码](../../reference/apis-avsession-kit/errorcode-avsession.md)和HiLog日志进一步定位问题。

## 创建AVSession失败

**问题现象**

调用[createAVSession](../../reference/apis-avsession-kit/arkts-apis-avsession-f.md#avsessioncreateavsession10)抛出异常，会话未创建成功。

**可能原因**

- 重复创建AVSession会话对象。一个进程只能存在一个AVSession会话对象。
- 存在频繁创建和销毁AVSession的场景时，旧会话尚未销毁完成。destroy调用是异步过程，如果应用在调用destroy后立即创建新的AVSession，可能因前一个会话尚未完成销毁，导致新会话创建失败。
- context入参无效。createAVSession的context需要使用应用的合法上下文。
- type参数取值非法。type必须为[AVSessionType](../../reference/apis-avsession-kit/arkts-apis-avsession-t.md#avsessiontype10)定义的值（`audio`/`video`/`voice_call`/`video_call`/`photo`），传入其他字符串会导致校验失败。
- 其他必填参数传入非法值。createAVSession的context、tag、type均为必填参数，任一缺失或非法都会抛出异常。

**解决措施**

1. 确认是否已经存在存活的AVSession，必要时先调用[destroy](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#destroy10)释放旧会话后再创建。在创建前还可以通过[getAVSession](../../reference/apis-avsession-kit/arkts-apis-avsession-f.md#avsessiongetavsession22)接口判断当前应用是否已经创建过会话对象，再决定是否销毁旧会话或直接复用已有会话。
2. 频繁创建和销毁场景下，通过媒体会话控制器监听[on('sessionDestroy')](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSessionController.md#onsessiondestroy10)事件，待收到旧会话销毁回调后再创建新的AVSession对象。

    ```TypeScript
    import { avSession } from '@kit.AVSessionKit';

    async destroyAndRecreateAVSession(context: Context) {
        let videoSession: avSession.AVSession;
        let avSessionController: avSession.AVSessionController;
        try {
            // 第一次创建AVSession，并获取其控制器。
            videoSession = await avSession.createAVSession(context, 'VIDEO_SESSION', 'video');
            avSessionController = await videoSession.getController();

            // 注册会话销毁监听，会话销毁后触发回调。
            avSessionController.on('sessionDestroy', async () => {
                // 第二次创建AVSession，销毁后重新创建同类型会话。
                videoSession = await avSession.createAVSession(context, 'VIDEO_SESSION', 'video');
                // 第二次销毁AVSession。
                await videoSession.destroy();
            });

            // 第一次销毁AVSession，触发上述sessionDestroy回调。
            await videoSession.destroy();
        } catch (err) {
            console.error(`AVSession create Error: Code: ${err.code}, message: ${err.message}`);
        }
    }
    ```

3. 推荐通过`this.getUIContext().getHostContext() as Context`获取context，避免传入undefined或非当前UIAbility的上下文。
4. 确保type为[AVSessionType](../../reference/apis-avsession-kit/arkts-apis-avsession-t.md#avsessiontype10)定义的合法取值。
5. 确保所有必填参数均为合法非空值，例如tag避免传入空字符串等无效值。

## 应用退至后台后音视频被强制暂停

**问题现象**

应用切到后台后，音视频播放被系统强制暂停，用户无法继续收听。

**可能原因**

- 未接入AVSession。系统会对未接入AVSession的音视频应用在后台进行强制管控。当流类型为`STREAM_USAGE_MUSIC`、`STREAM_USAGE_MOVIE`、`STREAM_USAGE_AUDIOBOOK`或`STREAM_USAGE_GAME`时，必须接入AVSession。
- 未申请长时任务。仅接入AVSession不足以保证后台播放，还需同时申请长时任务，否则应用进入后台后会被挂起或冻结。
- AVSession实例被回收。AVSession对象需在后台播放业务活动期间一直存在。如果将会话保存在局部变量中，方法返回后对象即被释放，系统判定应用没有有效AVSession实例，会强制暂停音频。
- AVSession创建失败导致应用未持有有效会话。
- 后台播放模式设置不正确。

**解决措施**

1. 参考后台播放中的[接入AVSession](avsession-background-scene.md#接入avsession)完成AVSession接入。
2. 申请AUDIO_PLAYBACK类型[长时任务(ArkTS)](../../task-management/continuous-task.md)。
3. 使用类成员变量保存session实例，并在应用进程结束或退出播放业务时再释放。
4. 参考[创建AVSession失败](#创建avsession失败)中的相关原因逐一排查，确保应用持有有效会话。
5. 应用退至后台前通过[setBackgroundPlayMode](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setbackgroundplaymode24)设置后台播放模式（[BackgroundPlayMode](../../reference/apis-avsession-kit/arkts-apis-avsession-e.md#backgroundplaymode24)），告知系统应用退至后台时是否继续播放：

     - `ENABLE_BACKGROUND_PLAY`（支持后台播放）：应用退至后台时仍继续播放。
     - `DISABLE_BACKGROUND_PLAY`（不支持后台播放）：应用退至后台时不再继续播放。

     其中[AVSessionType](../../reference/apis-avsession-kit/arkts-apis-avsession-t.md#avsessiontype10)为`audio`类型的应用默认值为`ENABLE_BACKGROUND_PLAY`；`video`类型的应用默认值为`DISABLE_BACKGROUND_PLAY`。如果视频类应用希望支持后台放音，需显式设置为`ENABLE_BACKGROUND_PLAY`；如果应用内提供了"是否支持后台播放"的开关，设置的后台播放模式务必与开关状态保持一致，否则可能导致退后台后被强制暂停或系统实况窗展示错误。设置示例如下：

     ```TypeScript
     import { avSession } from '@kit.AVSessionKit';
     import { BusinessError } from '@kit.BasicServicesKit';

     // 假设已创建并持有currentAVSession。
     async setBackgroundPlayMode(currentAVSession: avSession.AVSession) {
       try {
         await currentAVSession.setBackgroundPlayMode(avSession.BackgroundPlayMode.ENABLE_BACKGROUND_PLAY);
         console.info(' Succeeded in setBackgroundPlayMode');
       } catch (err) {
         let error = err as BusinessError;
         console.error(`setBackgroundPlayMode BusinessError: code: ${error.code}, message: ${error.message}`);
       }
     }
     ```

     更多说明请参考[设置后台播放模式](avsession-background-scene.md#设置后台播放模式)。

## 播控中心看不到应用会话

**问题现象**

应用已创建AVSession，但播控中心未展示对应媒体信息或控制条。

**可能原因**

- 未设置元数据或元数据设置失败。
- 未注册任何控制命令回调。会话在播控中心上屏展示要求至少注册一个控制命令（如播放/暂停）。
- 封面图等字段包含非法字符导致图片不展示。[AVMetadata](../../reference/apis-avsession-kit/arkts-apis-avsession-i.md#avmetadata10)中的mediaImage字段传入的文件路径若包含中文字符或特殊字符（如`/`、`·`等），会导致图片无法正常展示；同理，avQueueName和avQueueId传入非法字符也可能导致图片不展示。
- 歌词内容超出长度限制。[AVMetadata](../../reference/apis-avsession-kit/arkts-apis-avsession-i.md#avmetadata10)中的lyric字段（歌词内容）字符串长度需小于40960字节，超出限制播控中心将不显示歌词内容。
- 通话类应用未使用通话会话类型，或系统版本/应用分类不满足要求。<!--RP1--><!--RP1End-->

**解决措施**

1. 设置标题、副标题/歌手、封面图等媒体信息，具体请参考[设置元数据信息](avsession-access-scene.md#设置元数据信息)。确保assetId等元数据关键字段为合法值，避免传入空字符串导致设置失败。
2. 至少注册一个控制命令，具体请参考[控制命令的处理](avsession-access-scene.md#控制命令的处理)。
3. 确保mediaImage、avQueueName、avQueueId等相关字段取值为合法字符。
4. 确保歌词内容不超过40960字节的长度限制。
5. 通话类应用接入AVSession时，会话类型（[AVSessionType](../../reference/apis-avsession-kit/arkts-apis-avsession-t.md#avsessiontype10)）需选择`voice_call`或`video_call`。<!--RP2--><!--RP2End-->

## 播控命令无响应 / 播控展示与实际不符

**问题现象**

播控中心点击控制按钮（播放、暂停、上一首、下一首等）无响应，且应用与播控界面均未更新；或应用实际播放状态与播控中心显示状态不同步，如应用正在播放，播控仍显示为暂停。

**可能原因**

- 会话未激活。会话需激活后，控制命令才能通过播控中心正常下发。
- 未注册控制命令监听。如果未注册监听，播控命令将无法传递到应用。
- 未将自身播放状态同步给系统播控中心。播控中心展示的状态（如播放/暂停、进度等）以应用通过控制命令上报的状态为准，如果应用实际播放状态发生变化时未及时同步，会导致播控中心显示与实际不符。

**解决措施**

1. 通过[activate](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#activate10)激活会话，确认会话已完成激活。
2. 通过AVSession对象的`on('play')`、`on('pause')`、`on('playNext')`、`on('playPrevious')`等接口注册对应控制命令的监听，并在回调中驱动播放器执行相应操作。请参考[控制命令的处理](avsession-access-scene.md#控制命令的处理)补全注册逻辑。
3. 在播放状态变更时调用[setAVPlaybackState](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setavplaybackstate10)更新播放状态。当状态设置为[PLAYBACK_STATE_PAUSE](../../reference/apis-avsession-kit/arkts-apis-avsession-e.md#playbackstate10)，应用回到后台5秒后，系统将回收胶囊位置的播控卡片；10分钟后，系统将回收通知栏、锁屏位置的播控卡片。

## 播控进度条回退闪烁

**问题现象**

在播控中心点击播放按钮后，播控进度条发生回退闪烁。

**可能原因**

播放器起播延迟导致进度不一致。点击播放后播控进度条即开始计时，而应用内播放器尚未真正起播，进度落后于播控。应用随后同步进度时，因进度小于播控已计时进度，导致进度条回退闪烁。

**解决措施**

在播放器起播前，先通过[setAVPlaybackState](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setavplaybackstate10)将状态置为[PLAYBACK_STATE_BUFFERING](../../reference/apis-avsession-kit/arkts-apis-avsession-e.md#playbackstate10)（缓冲），待真正起播后再同步状态与进度。

```TypeScript
import { avSession } from '@kit.AVSessionKit';
import { media } from '@kit.MediaKit';

// avPlayer为通过media.createAVPlayer()创建的播放器实例，currentAVSession为已创建的AVSession对象。

async listenAVPlayer(avPlayer: media.AVPlayer, currentAVSession: avSession.AVSession) {
    // 预先监听AVPlayer状态机切换，真正起播（进入playing状态）后，再同步真实状态与进度。
    avPlayer.on('stateChange', async (state: string) => {
        if (state === 'playing') {
        let playingState: avSession.AVPlaybackState = {
            state: avSession.PlaybackState.PLAYBACK_STATE_PLAY,
            speed: 1.0,
            // currentTime为AVPlayer当前真实播放进度，单位为毫秒（ms）。
            position: { elapsedTime: avPlayer.currentTime, updateTime: (new Date()).getTime() }
        };
        await currentAVSession.setAVPlaybackState(playingState);
        }
    });

    // 收到播放命令后、AVPlayer真正起播前，先将播控状态置为缓冲，避免播控进度条先行计时。
    let bufferingState: avSession.AVPlaybackState = {
        state: avSession.PlaybackState.PLAYBACK_STATE_BUFFERING,
        speed: 0,
        position: { elapsedTime: 0, updateTime: (new Date()).getTime() }
    };
    await currentAVSession.setAVPlaybackState(bufferingState);
    await avPlayer.play();
}
```
