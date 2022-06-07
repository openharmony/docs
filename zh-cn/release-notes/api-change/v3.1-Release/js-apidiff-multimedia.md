# 媒体子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，媒体子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.multimedia.mediaLibrary | Size | height: number; | 新增 |
| ohos.multimedia.mediaLibrary | Size | width: number; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | startMediaSelect(option: MediaSelectOption, callback: AsyncCallback\<Array\<string>>): void;<br>startMediaSelect(option: MediaSelectOption): Promise\<Array\<string>>; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | startImagePreview(images: Array\<string>, index: number, callback: AsyncCallback\<void>): void;<br>startImagePreview(images: Array\<string>, callback: AsyncCallback\<void>): void;<br>startImagePreview(images: Array\<string>, index?: number): Promise\<void>; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback\<string>): void;<br>storeMediaAsset(option: MediaAssetOption): Promise\<string>; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album>>): void;<br>getAlbums(options: MediaFetchOptions): Promise\<Array\<Album>>; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset>): void;<br>createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset>; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult>; | 新增 |
| ohos.multimedia.mediaLibrary | MediaLibrary | getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string>): void;<br>getPublicDirectory(type: DirectoryType): Promise\<string>; | 新增 |
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_DOWNLOAD | 新增 |
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_DOCUMENTS | 新增 |
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_AUDIO | 新增 |
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_IMAGE | 新增 |
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_VIDEO | 新增 |
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_CAMERA = 0 | 新增 |
| ohos.multimedia.mediaLibrary | Album | getFileAssets(callback: AsyncCallback\<FetchFileResult>): void;<br>getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult>; | 新增 |
| ohos.multimedia.mediaLibrary | Album | commitModify(callback: AsyncCallback\<void>): void;<br>commitModify(): Promise\<void>; | 新增 |
| ohos.multimedia.mediaLibrary | Album | readonly coverUri: string; | 新增 |
| ohos.multimedia.mediaLibrary | Album | readonly relativePath: string; | 新增 |
| ohos.multimedia.mediaLibrary | Album | readonly count: number; | 新增 |
| ohos.multimedia.mediaLibrary | Album | readonly dateModified: number; | 新增 |
| ohos.multimedia.mediaLibrary | Album | readonly albumUri: string; | 新增 |
| ohos.multimedia.mediaLibrary | Album | albumName: string; | 新增 |
| ohos.multimedia.mediaLibrary | Album | readonly albumId: number; | 新增 |
| ohos.multimedia.mediaLibrary | FetchFileResult | getAllObject(callback: AsyncCallback\<Array\<FileAsset>>): void;<br>getAllObject(): Promise\<Array\<FileAsset>>; | 新增 |
| ohos.multimedia.mediaLibrary | FetchFileResult | getPositionObject(index: number, callback: AsyncCallback\<FileAsset>): void;<br>getPositionObject(index: number): Promise\<FileAsset>; | 新增 |
| ohos.multimedia.mediaLibrary | FetchFileResult | getLastObject(callback: AsyncCallback\<FileAsset>): void;<br>getLastObject(): Promise\<FileAsset>; | 新增 |
| ohos.multimedia.mediaLibrary | FetchFileResult | getNextObject(callback: AsyncCallback\<FileAsset>): void;<br>getNextObject(): Promise\<FileAsset>; | 新增 |
| ohos.multimedia.mediaLibrary | FetchFileResult | getFirstObject(callback: AsyncCallback\<FileAsset>): void;<br>getFirstObject(): Promise\<FileAsset>; | 新增 |
| ohos.multimedia.mediaLibrary | FetchFileResult | close(): void; | 新增 |
| ohos.multimedia.mediaLibrary | FetchFileResult | isAfterLast(): boolean; | 新增 |
| ohos.multimedia.mediaLibrary | FetchFileResult | getCount(): number; | 新增 |
| ohos.multimedia.mediaLibrary | MediaFetchOptions | extendArgs?: string; | 新增 |
| ohos.multimedia.mediaLibrary | MediaFetchOptions | networkId?: string; | 新增 |
| ohos.multimedia.mediaLibrary | MediaFetchOptions | uri?: string; | 新增 |
| ohos.multimedia.mediaLibrary | MediaFetchOptions | order?: string; | 新增 |
| ohos.multimedia.mediaLibrary | MediaFetchOptions | selectionArgs: Array\<string>; | 新增 |
| ohos.multimedia.mediaLibrary | MediaFetchOptions | selections: string; | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | ALBUM_NAME = "bucket_display_name" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | ALBUM_ID = "bucket_id" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | ORIENTATION = "orientation" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | HEIGHT = "height" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | WIDTH = "width" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | DURATION = "duration" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | AUDIOALBUM = "audio_album" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | ARTIST = "artist" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | TITLE = "title" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | DATE_TAKEN = "date_taken" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | DATE_MODIFIED = "date_modified" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | DATE_ADDED = "date_added" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | SIZE = "size" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | MEDIA_TYPE = "media_type" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | MIME_TYPE = "mime_type" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | PARENT = "parent" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | DISPLAY_NAME = "display_name" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | RELATIVE_PATH = "relative_path" | 新增 |
| ohos.multimedia.mediaLibrary | FileKey | ID = "file_id" | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | isTrash(callback: AsyncCallback\<boolean>): void;<br>isTrash():Promise\<boolean>; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | trash(isTrash: boolean, callback: AsyncCallback\<void>): void;<br>trash(isTrash: boolean): Promise\<void>; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | isFavorite(callback: AsyncCallback\<boolean>): void;<br>isFavorite():Promise\<boolean>; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | favorite(isFavorite: boolean, callback: AsyncCallback\<void>): void;<br>favorite(isFavorite: boolean): Promise\<void>; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | getThumbnail(callback: AsyncCallback\<image.PixelMap>): void;<br>getThumbnail(size: Size, callback: AsyncCallback\<image.PixelMap>): void;<br>getThumbnail(size?: Size): Promise\<image.PixelMap>; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | close(fd: number, callback: AsyncCallback\<void>): void;<br>close(fd: number): Promise\<void>; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | open(mode: string, callback: AsyncCallback\<number>): void;<br>open(mode: string): Promise\<number>; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | commitModify(callback: AsyncCallback\<void>): void;<br>commitModify(): Promise\<void>; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | isDirectory(callback: AsyncCallback\<boolean>): void;<br>isDirectory():Promise\<boolean>; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly albumName: string; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly albumUri: string; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly albumId: number; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly duration: number; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | orientation: number; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly height: number; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly width: number; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly audioAlbum: string; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly artist: string; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly dateTaken: number; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly dateModified: number; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly dateAdded: number; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly size: number; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly parent: number; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | relativePath: string; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | title: string; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | displayName: string; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly mediaType: MediaType; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly mimeType: string; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly uri: string; | 新增 |
| ohos.multimedia.mediaLibrary | FileAsset | readonly id: number; | 新增 |
| ohos.multimedia.mediaLibrary | MediaSelectOption | count: number; | 新增 |
| ohos.multimedia.mediaLibrary | MediaSelectOption | type: 'image' \| 'video' \| 'media'; | 新增 |
| ohos.multimedia.mediaLibrary | MediaAssetOption | relativePath?: string; | 新增 |
| ohos.multimedia.mediaLibrary | MediaAssetOption | mimeType: string; | 新增 |
| ohos.multimedia.mediaLibrary | MediaAssetOption | src: string; | 新增 |
| ohos.multimedia.mediaLibrary | MediaType | AUDIO | 新增 |
| ohos.multimedia.mediaLibrary | MediaType | VIDEO | 新增 |
| ohos.multimedia.mediaLibrary | MediaType | IMAGE | 新增 |
| ohos.multimedia.mediaLibrary | MediaType | FILE = 0 | 新增 |
| ohos.multimedia.mediaLibrary | mediaLibrary | getMediaLibrary(): MediaLibrary;<br>getMediaLibrary(context: Context): MediaLibrary; | 新增 |
| ohos.multimedia.media | CodecMimeType | AUDIO_FLAC = 'audio/flac' | 新增 |
| ohos.multimedia.media | CodecMimeType | AUDIO_VORBIS = 'audio/vorbis' | 新增 |
| ohos.multimedia.media | CodecMimeType | AUDIO_AAC = 'audio/mp4a-latm' | 新增 |
| ohos.multimedia.media | CodecMimeType | VIDEO_VP8 = 'video/x-vnd.on2.vp8' | 新增 |
| ohos.multimedia.media | CodecMimeType | VIDEO_MPEG4 = 'video/mp4v-es' | 新增 |
| ohos.multimedia.media | CodecMimeType | VIDEO_MPEG2 = 'video/mpeg2' | 新增 |
| ohos.multimedia.media | CodecMimeType | VIDEO_AVC = 'video/avc' | 新增 |
| ohos.multimedia.media | CodecMimeType | VIDEO_H263 = 'video/h263' | 新增 |
| ohos.multimedia.media | SeekMode | SEEK_PREV_SYNC = 1 | 新增 |
| ohos.multimedia.media | SeekMode | SEEK_NEXT_SYNC = 0 | 新增 |
| ohos.multimedia.media | MediaDescription | [key : string]: Object; | 新增 |
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_AUD_SAMPLE_RATE = "sample_rate" | 新增 |
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_AUD_CHANNEL_COUNT = "channel_count" | 新增 |
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_FRAME_RATE = "frame_rate" | 新增 |
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_HEIGHT = "height" | 新增 |
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_WIDTH = "width" | 新增 |
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_BITRATE = "bitrate" | 新增 |
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_DURATION = "duration" | 新增 |
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_CODEC_MIME = "codec_mime" | 新增 |
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_TRACK_TYPE = "track_type" | 新增 |
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_TRACK_INDEX = "track_index" | 新增 |
| ohos.multimedia.media | MediaType | MEDIA_TYPE_VID = 1 | 新增 |
| ohos.multimedia.media | MediaType | MEDIA_TYPE_AUD = 0 | 新增 |
| ohos.multimedia.media | ContainerFormatType | CFT_MPEG_4A = "m4a" | 新增 |
| ohos.multimedia.media | ContainerFormatType | CFT_MPEG_4 = "mp4" | 新增 |
| ohos.multimedia.media | VideoPlayer | on(type: 'error', callback: ErrorCallback): void; | 新增 |
| ohos.multimedia.media | VideoPlayer | on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void; | 新增 |
| ohos.multimedia.media | VideoPlayer | on(type: 'startRenderFrame', callback: Callback\<void>): void; | 新增 |
| ohos.multimedia.media | VideoPlayer | on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void; | 新增 |
| ohos.multimedia.media | VideoPlayer | on(type: 'playbackCompleted', callback: Callback\<void>): void; | 新增 |
| ohos.multimedia.media | VideoPlayer | setSpeed(speed:number, callback: AsyncCallback\<number>): void;<br>setSpeed(speed:number): Promise\<number>; | 新增 |
| ohos.multimedia.media | VideoPlayer | readonly height: number; | 新增 |
| ohos.multimedia.media | VideoPlayer | readonly width: number; | 新增 |
| ohos.multimedia.media | VideoPlayer | readonly state: VideoPlayState; | 新增 |
| ohos.multimedia.media | VideoPlayer | readonly duration: number; | 新增 |
| ohos.multimedia.media | VideoPlayer | readonly currentTime: number; | 新增 |
| ohos.multimedia.media | VideoPlayer | loop: boolean; | 新增 |
| ohos.multimedia.media | VideoPlayer | url: string; | 新增 |
| ohos.multimedia.media | VideoPlayer | getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>getTrackDescription() : Promise\<Array\<MediaDescription>>; | 新增 |
| ohos.multimedia.media | VideoPlayer | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoPlayer | setVolume(vol: number, callback: AsyncCallback\<void>): void;<br>setVolume(vol: number): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoPlayer | seek(timeMs: number, callback: AsyncCallback\<number>): void;<br>seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void;<br>seek(timeMs: number, mode?:SeekMode): Promise\<number>; | 新增 |
| ohos.multimedia.media | VideoPlayer | reset(callback: AsyncCallback\<void>): void;<br>reset(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoPlayer | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoPlayer | pause(callback: AsyncCallback\<void>): void;<br>pause(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoPlayer | play(callback: AsyncCallback\<void>): void;<br>play(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoPlayer | prepare(callback: AsyncCallback\<void>): void;<br>prepare(): Promise\<void>; | 新增 |
| ohos.multimedia.media | VideoPlayer | setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;<br>setDisplaySurface(surfaceId: string): Promise\<void>; | 新增 |
| ohos.multimedia.media | PlaybackSpeed | SPEED_FORWARD_2_00_X = 4 | 新增 |
| ohos.multimedia.media | PlaybackSpeed | SPEED_FORWARD_1_75_X = 3 | 新增 |
| ohos.multimedia.media | PlaybackSpeed | SPEED_FORWARD_1_25_X = 2 | 新增 |
| ohos.multimedia.media | PlaybackSpeed | SPEED_FORWARD_1_00_X = 1 | 新增 |
| ohos.multimedia.media | PlaybackSpeed | SPEED_FORWARD_0_75_X = 0 | 新增 |
| ohos.multimedia.media | AudioRecorder | on(type: 'error', callback: ErrorCallback): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | reset(): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | release(): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | stop(): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | resume(): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | pause(): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | start(): void; | 新增 |
| ohos.multimedia.media | AudioRecorder | prepare(config: AudioRecorderConfig): void; | 新增 |
| ohos.multimedia.media | AudioRecorderConfig | fileFormat?: ContainerFormatType; | 新增 |
| ohos.multimedia.media | AudioRecorderConfig | audioEncoderMime?: CodecMimeType; | 新增 |
| ohos.multimedia.media | AudioRecorderConfig | location?: Location; | 新增 |
| ohos.multimedia.media | AudioRecorderConfig | uri: string; | 新增 |
| ohos.multimedia.media | AudioRecorderConfig | format?: AudioOutputFormat; | 新增 |
| ohos.multimedia.media | AudioRecorderConfig | numberOfChannels?: number; | 新增 |
| ohos.multimedia.media | AudioRecorderConfig | audioSampleRate?: number; | 新增 |
| ohos.multimedia.media | AudioRecorderConfig | audioEncodeBitRate?: number; | 新增 |
| ohos.multimedia.media | AudioRecorderConfig | audioEncoder?: AudioEncoder; | 新增 |
| ohos.multimedia.media | Location | longitude: number; | 新增 |
| ohos.multimedia.media | Location | latitude: number; | 新增 |
| ohos.multimedia.media | AudioOutputFormat | AAC_ADTS = 6 | 新增 |
| ohos.multimedia.media | AudioOutputFormat | AMR_WB = 4 | 新增 |
| ohos.multimedia.media | AudioOutputFormat | AMR_NB = 3 | 新增 |
| ohos.multimedia.media | AudioOutputFormat | MPEG_4 = 2 | 新增 |
| ohos.multimedia.media | AudioOutputFormat | DEFAULT = 0 | 新增 |
| ohos.multimedia.media | AudioEncoder | HE_AAC = 4 | 新增 |
| ohos.multimedia.media | AudioEncoder | AAC_LC = 3 | 新增 |
| ohos.multimedia.media | AudioEncoder | AMR_WB = 2 | 新增 |
| ohos.multimedia.media | AudioEncoder | AMR_NB = 1 | 新增 |
| ohos.multimedia.media | AudioEncoder | DEFAULT = 0 | 新增 |
| ohos.multimedia.media | AudioPlayer | on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void; | 新增 |
| ohos.multimedia.media | AudioPlayer | on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void; | 新增 |
| ohos.multimedia.media | AudioPlayer | getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>getTrackDescription() : Promise\<Array\<MediaDescription>>; | 新增 |
| ohos.multimedia.media | AudioPlayer | reset(): void; | 新增 |
| ohos.multimedia.media | BufferingInfoType | CACHED_DURATION = 4 | 新增 |
| ohos.multimedia.media | BufferingInfoType | BUFFERING_PERCENT = 3 | 新增 |
| ohos.multimedia.media | BufferingInfoType | BUFFERING_END = 2 | 新增 |
| ohos.multimedia.media | BufferingInfoType | BUFFERING_START = 1 | 新增 |
| ohos.multimedia.media | MediaErrorCode | MSERR_UNSUPPORTED = 9 | 新增 |
| ohos.multimedia.media | MediaErrorCode | MSERR_INVALID_STATE = 8 | 新增 |
| ohos.multimedia.media | MediaErrorCode | MSERR_SERVICE_DIED = 7 | 新增 |
| ohos.multimedia.media | MediaErrorCode | MSERR_UNKNOWN = 6 | 新增 |
| ohos.multimedia.media | MediaErrorCode | MSERR_TIMEOUT = 5 | 新增 |
| ohos.multimedia.media | MediaErrorCode | MSERR_IO = 4 | 新增 |
| ohos.multimedia.media | MediaErrorCode | MSERR_INVALID_VAL = 3 | 新增 |
| ohos.multimedia.media | MediaErrorCode | MSERR_OPERATION_NOT_PERMIT = 2 | 新增 |
| ohos.multimedia.media | MediaErrorCode | MSERR_NO_MEMORY = 1 | 新增 |
| ohos.multimedia.media | MediaErrorCode | MSERR_OK = 0 | 新增 |
| ohos.multimedia.media | media | createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void;<br>createVideoPlayer() : Promise\<VideoPlayer>; | 新增 |
| ohos.multimedia.media | media | createAudioRecorder(): AudioRecorder; | 新增 |
| ohos.multimedia.image | ImagePacker | readonly supportedFormats: Array\<string>; | 新增 |
| ohos.multimedia.image | ImagePacker | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.image | ImagePacker | packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void;<br>packing(source: ImageSource, option: PackingOption): Promise\<ArrayBuffer>;<br>packing(source: PixelMap, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void;<br>packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>; | 新增 |
| ohos.multimedia.image | ImageSource | readonly supportedFormats: Array\<string>; | 新增 |
| ohos.multimedia.image | ImageSource | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.image | ImageSource | getImageProperty(key:string, options?: GetImagePropertyOptions): Promise\<string>;<br>getImageProperty(key:string, callback: AsyncCallback\<string>): void;<br>getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void; | 新增 |
| ohos.multimedia.image | ImageSource | createPixelMap(options?: DecodingOptions): Promise\<PixelMap>;<br>createPixelMap(callback: AsyncCallback\<PixelMap>): void;<br>createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void; | 新增 |
| ohos.multimedia.image | ImageSource | getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void;<br>getImageInfo(callback: AsyncCallback\<ImageInfo>): void;<br>getImageInfo(index?: number): Promise\<ImageInfo>; | 新增 |
| ohos.multimedia.image | PixelMap | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.image | PixelMap | getPixelBytesNumber(): number; | 新增 |
| ohos.multimedia.image | PixelMap | getBytesNumberPerRow(): number; | 新增 |
| ohos.multimedia.image | PixelMap | getImageInfo(): Promise\<ImageInfo>;<br>getImageInfo(callback: AsyncCallback\<ImageInfo>): void; | 新增 |
| ohos.multimedia.image | PixelMap | writeBufferToPixels(src: ArrayBuffer): Promise\<void>;<br>writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.multimedia.image | PixelMap | writePixels(area: PositionArea): Promise\<void>;<br>writePixels(area: PositionArea, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.multimedia.image | PixelMap | readPixels(area: PositionArea): Promise\<void>;<br>readPixels(area: PositionArea, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.multimedia.image | PixelMap | readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>;<br>readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.multimedia.image | PixelMap | readonly isEditable: boolean; | 新增 |
| ohos.multimedia.image | image | createImagePacker(): ImagePacker; | 新增 |
| ohos.multimedia.image | image | createImageSource(uri: string): ImageSource;<br>createImageSource(fd: number): ImageSource; | 新增 |
| ohos.multimedia.image | image | createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void;<br>createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>; | 新增 |
| ohos.multimedia.image | InitializationOptions | editable?: boolean; | 新增 |
| ohos.multimedia.image | InitializationOptions | pixelFormat?: PixelMapFormat; | 新增 |
| ohos.multimedia.image | InitializationOptions | size: Size; | 新增 |
| ohos.multimedia.image | DecodingOptions | desiredPixelFormat?: PixelMapFormat; | 新增 |
| ohos.multimedia.image | DecodingOptions | desiredRegion?: Region; | 新增 |
| ohos.multimedia.image | DecodingOptions | desiredSize?: Size; | 新增 |
| ohos.multimedia.image | DecodingOptions | editable?: boolean; | 新增 |
| ohos.multimedia.image | DecodingOptions | rotate?: number; | 新增 |
| ohos.multimedia.image | DecodingOptions | sampleSize?: number; | 新增 |
| ohos.multimedia.image | DecodingOptions | index?: number; | 新增 |
| ohos.multimedia.image | GetImagePropertyOptions | defaultValue?: string; | 新增 |
| ohos.multimedia.image | GetImagePropertyOptions | index?: number; | 新增 |
| ohos.multimedia.image | PackingOption | quality: number; | 新增 |
| ohos.multimedia.image | PackingOption | format: string; | 新增 |
| ohos.multimedia.image | ImageInfo | size: Size; | 新增 |
| ohos.multimedia.image | PositionArea | region: Region; | 新增 |
| ohos.multimedia.image | PositionArea | stride: number; | 新增 |
| ohos.multimedia.image | PositionArea | offset: number; | 新增 |
| ohos.multimedia.image | PositionArea | pixels: ArrayBuffer; | 新增 |
| ohos.multimedia.image | Region | y: number; | 新增 |
| ohos.multimedia.image | Region | x: number; | 新增 |
| ohos.multimedia.image | Region | size: Size; | 新增 |
| ohos.multimedia.image | PropertyKey | GPS_LONGITUDE_REF = "GPSLongitudeRef" | 新增 |
| ohos.multimedia.image | PropertyKey | GPS_LATITUDE_REF = "GPSLatitudeRef" | 新增 |
| ohos.multimedia.image | PropertyKey | GPS_LONGITUDE = "GPSLongitude" | 新增 |
| ohos.multimedia.image | PropertyKey | GPS_LATITUDE = "GPSLatitude" | 新增 |
| ohos.multimedia.image | PropertyKey | IMAGE_WIDTH = "ImageWidth" | 新增 |
| ohos.multimedia.image | PropertyKey | IMAGE_LENGTH = "ImageLength" | 新增 |
| ohos.multimedia.image | PropertyKey | ORIENTATION = "Orientation" | 新增 |
| ohos.multimedia.image | PropertyKey | BITS_PER_SAMPLE = "BitsPerSample" | 新增 |
| ohos.multimedia.image | Size | width: number; | 新增 |
| ohos.multimedia.image | Size | height: number; | 新增 |
| ohos.multimedia.image | PixelMapFormat | RGBA_8888 = 3 | 新增 |
| ohos.multimedia.image | PixelMapFormat | RGB_565 = 2 | 新增 |
| ohos.multimedia.image | PixelMapFormat | UNKNOWN = 0 | 新增 |
| ohos.multimedia.audio | AudioCapturer | on(type: "stateChange", callback: Callback\<AudioState>): void; | 新增 |
| ohos.multimedia.audio | AudioCapturer | off(type: "periodReach"): void; | 新增 |
| ohos.multimedia.audio | AudioCapturer | on(type: "periodReach", frame: number, callback: (position: number) => {}): void; | 新增 |
| ohos.multimedia.audio | AudioCapturer | off(type: "markReach"): void; | 新增 |
| ohos.multimedia.audio | AudioCapturer | on(type: "markReach", frame: number, callback: (position: number) => {}): void; | 新增 |
| ohos.multimedia.audio | AudioCapturer | getBufferSize(callback: AsyncCallback\<number>): void;<br>getBufferSize(): Promise\<number>; | 新增 |
| ohos.multimedia.audio | AudioCapturer | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioCapturer | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioCapturer | getAudioTime(callback: AsyncCallback\<number>): void;<br>getAudioTime(): Promise\<number>; | 新增 |
| ohos.multimedia.audio | AudioCapturer | read(size: number, isBlockingRead: boolean, callback: AsyncCallback\<ArrayBuffer>): void;<br>read(size: number, isBlockingRead: boolean): Promise\<ArrayBuffer>; | 新增 |
| ohos.multimedia.audio | AudioCapturer | start(callback: AsyncCallback\<void>): void;<br>start(): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioCapturer | getStreamInfo(callback: AsyncCallback\<AudioStreamInfo>): void;<br>getStreamInfo(): Promise\<AudioStreamInfo>; | 新增 |
| ohos.multimedia.audio | AudioCapturer | getCapturerInfo(callback: AsyncCallback\<AudioCapturerInfo>): void;<br>getCapturerInfo(): Promise\<AudioCapturerInfo>; | 新增 |
| ohos.multimedia.audio | AudioCapturer | readonly state: AudioState; | 新增 |
| ohos.multimedia.audio | AudioCapturerOptions | capturerInfo: AudioCapturerInfo; | 新增 |
| ohos.multimedia.audio | AudioCapturerOptions | streamInfo: AudioStreamInfo; | 新增 |
| ohos.multimedia.audio | AudioCapturerInfo | capturerFlags: number; | 新增 |
| ohos.multimedia.audio | AudioCapturerInfo | source: SourceType; | 新增 |
| ohos.multimedia.audio | SourceType | SOURCE_TYPE_VOICE_COMMUNICATION = 7 | 新增 |
| ohos.multimedia.audio | SourceType | SOURCE_TYPE_MIC = 0 | 新增 |
| ohos.multimedia.audio | SourceType | SOURCE_TYPE_INVALID = -1 | 新增 |
| ohos.multimedia.audio | AudioRenderer | on(type: "stateChange", callback: Callback\<AudioState>): void; | 新增 |
| ohos.multimedia.audio | AudioRenderer | off(type: "periodReach"): void; | 新增 |
| ohos.multimedia.audio | AudioRenderer | on(type: "periodReach", frame: number, callback: (position: number) => {}): void; | 新增 |
| ohos.multimedia.audio | AudioRenderer | off(type: "markReach"): void; | 新增 |
| ohos.multimedia.audio | AudioRenderer | on(type: "markReach", frame: number, callback: (position: number) => {}): void; | 新增 |
| ohos.multimedia.audio | AudioRenderer | getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void;<br>getRenderRate(): Promise\<AudioRendererRate>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | setRenderRate(rate: AudioRendererRate, callback: AsyncCallback\<void>): void;<br>setRenderRate(rate: AudioRendererRate): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | getBufferSize(callback: AsyncCallback\<number>): void;<br>getBufferSize(): Promise\<number>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | pause(callback: AsyncCallback\<void>): void;<br>pause(): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | drain(callback: AsyncCallback\<void>): void;<br>drain(): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | getAudioTime(callback: AsyncCallback\<number>): void;<br>getAudioTime(): Promise\<number>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | write(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void;<br>write(buffer: ArrayBuffer): Promise\<number>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | start(callback: AsyncCallback\<void>): void;<br>start(): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | getStreamInfo(callback: AsyncCallback\<AudioStreamInfo>): void;<br>getStreamInfo(): Promise\<AudioStreamInfo>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | getRendererInfo(callback: AsyncCallback\<AudioRendererInfo>): void;<br>getRendererInfo(): Promise\<AudioRendererInfo>; | 新增 |
| ohos.multimedia.audio | AudioRenderer | readonly state: AudioState; | 新增 |
| ohos.multimedia.audio | DeviceChangeAction | deviceDescriptors: AudioDeviceDescriptors; | 新增 |
| ohos.multimedia.audio | DeviceChangeAction | type: DeviceChangeType; | 新增 |
| ohos.multimedia.audio | AudioInterrupt | pauseWhenDucked: boolean; | 新增 |
| ohos.multimedia.audio | AudioInterrupt | contentType: ContentType; | 新增 |
| ohos.multimedia.audio | AudioInterrupt | streamUsage: StreamUsage; | 新增 |
| ohos.multimedia.audio | InterruptAction | activated?: boolean; | 新增 |
| ohos.multimedia.audio | InterruptAction | hint?: InterruptHint; | 新增 |
| ohos.multimedia.audio | InterruptAction | type?: InterruptType; | 新增 |
| ohos.multimedia.audio | InterruptAction | actionType: InterruptActionType; | 新增 |
| ohos.multimedia.audio | AudioManager | off(type: 'interrupt', interrupt: AudioInterrupt, callback?: Callback\<InterruptAction>): void; | 新增 |
| ohos.multimedia.audio | AudioManager | on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback\<InterruptAction>): void; | 新增 |
| ohos.multimedia.audio | AudioManager | off(type: 'deviceChange', callback?: Callback\<DeviceChangeAction>): void; | 新增 |
| ohos.multimedia.audio | AudioManager | on(type: 'deviceChange', callback: Callback\<DeviceChangeAction>): void; | 新增 |
| ohos.multimedia.audio | AudioManager | getAudioScene(callback: AsyncCallback\<AudioScene>): void;<br>getAudioScene(): Promise\<AudioScene>; | 新增 |
| ohos.multimedia.audio | AudioManager | isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback\<boolean>): void;<br>isDeviceActive(deviceType: ActiveDeviceType): Promise\<boolean>; | 新增 |
| ohos.multimedia.audio | AudioManager | setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback\<void>): void;<br>setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioManager | getAudioParameter(key: string, callback: AsyncCallback\<string>): void;<br>getAudioParameter(key: string): Promise\<string>; | 新增 |
| ohos.multimedia.audio | AudioManager | setAudioParameter(key: string, value: string, callback: AsyncCallback\<void>): void;<br>setAudioParameter(key: string, value: string): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioManager | getRingerMode(callback: AsyncCallback\<AudioRingMode>): void;<br>getRingerMode(): Promise\<AudioRingMode>; | 新增 |
| ohos.multimedia.audio | AudioManager | setRingerMode(mode: AudioRingMode, callback: AsyncCallback\<void>): void;<br>setRingerMode(mode: AudioRingMode): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioManager | isMicrophoneMute(callback: AsyncCallback\<boolean>): void;<br>isMicrophoneMute(): Promise\<boolean>; | 新增 |
| ohos.multimedia.audio | AudioManager | setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void;<br>setMicrophoneMute(mute: boolean): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioManager | isActive(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>isActive(volumeType: AudioVolumeType): Promise\<boolean>; | 新增 |
| ohos.multimedia.audio | AudioManager | isMute(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>isMute(volumeType: AudioVolumeType): Promise\<boolean>; | 新增 |
| ohos.multimedia.audio | AudioManager | mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback\<void>): void;<br>mute(volumeType: AudioVolumeType, mute: boolean): Promise\<void>; | 新增 |
| ohos.multimedia.audio | AudioScene | AUDIO_SCENE_VOICE_CHAT | 新增 |
| ohos.multimedia.audio | AudioScene | AUDIO_SCENE_DEFAULT = 0 | 新增 |
| ohos.multimedia.audio | DeviceChangeType | DISCONNECT = 1 | 新增 |
| ohos.multimedia.audio | DeviceChangeType | CONNECT = 0 | 新增 |
| ohos.multimedia.audio | InterruptActionType | TYPE_INTERRUPT = 1 | 新增 |
| ohos.multimedia.audio | InterruptActionType | TYPE_ACTIVATED = 0 | 新增 |
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_UNDUCK = 5 | 新增 |
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_DUCK = 4 | 新增 |
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_STOP = 3 | 新增 |
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_PAUSE = 2 | 新增 |
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_RESUME = 1 | 新增 |
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_NONE = 0 | 新增 |
| ohos.multimedia.audio | InterruptType | INTERRUPT_TYPE_END = 2 | 新增 |
| ohos.multimedia.audio | InterruptType | INTERRUPT_TYPE_BEGIN = 1 | 新增 |
| ohos.multimedia.audio | AudioRendererRate | RENDER_RATE_HALF = 2 | 新增 |
| ohos.multimedia.audio | AudioRendererRate | RENDER_RATE_DOUBLE = 1 | 新增 |
| ohos.multimedia.audio | AudioRendererRate | RENDER_RATE_NORMAL = 0 | 新增 |
| ohos.multimedia.audio | AudioRendererOptions | rendererInfo: AudioRendererInfo; | 新增 |
| ohos.multimedia.audio | AudioRendererOptions | streamInfo: AudioStreamInfo; | 新增 |
| ohos.multimedia.audio | AudioRendererInfo | rendererFlags: number; | 新增 |
| ohos.multimedia.audio | AudioRendererInfo | usage: StreamUsage; | 新增 |
| ohos.multimedia.audio | AudioRendererInfo | content: ContentType; | 新增 |
| ohos.multimedia.audio | AudioStreamInfo | encodingType: AudioEncodingType; | 新增 |
| ohos.multimedia.audio | AudioStreamInfo | sampleFormat: AudioSampleFormat; | 新增 |
| ohos.multimedia.audio | AudioStreamInfo | channels: AudioChannel; | 新增 |
| ohos.multimedia.audio | AudioStreamInfo | samplingRate: AudioSamplingRate; | 新增 |
| ohos.multimedia.audio | StreamUsage | STREAM_USAGE_NOTIFICATION_RINGTONE = 6 | 新增 |
| ohos.multimedia.audio | StreamUsage | STREAM_USAGE_VOICE_COMMUNICATION = 2 | 新增 |
| ohos.multimedia.audio | StreamUsage | STREAM_USAGE_MEDIA = 1 | 新增 |
| ohos.multimedia.audio | StreamUsage | STREAM_USAGE_UNKNOWN = 0 | 新增 |
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_RINGTONE = 5 | 新增 |
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_SONIFICATION = 4 | 新增 |
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_MOVIE = 3 | 新增 |
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_MUSIC = 2 | 新增 |
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_SPEECH = 1 | 新增 |
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_UNKNOWN = 0 | 新增 |
| ohos.multimedia.audio | AudioEncodingType | ENCODING_TYPE_RAW = 0 | 新增 |
| ohos.multimedia.audio | AudioEncodingType | ENCODING_TYPE_INVALID = -1 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_96000 = 96000 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_64000 = 64000 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_48000 = 48000 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_44100 = 44100 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_32000 = 32000 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_24000 = 24000 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_22050 = 22050 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_16000 = 16000 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_12000 = 12000 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_11025 = 11025 | 新增 |
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_8000 = 8000 | 新增 |
| ohos.multimedia.audio | AudioChannel | CHANNEL_2 = 0x1 \<\< 1 | 新增 |
| ohos.multimedia.audio | AudioChannel | CHANNEL_1 = 0x1 \<\< 0 | 新增 |
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_S32LE = 3 | 新增 |
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_S24LE = 2 | 新增 |
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_S16LE = 1 | 新增 |
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_U8 = 0 | 新增 |
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_INVALID = -1 | 新增 |
| ohos.multimedia.audio | AudioRingMode | RINGER_MODE_NORMAL = 2 | 新增 |
| ohos.multimedia.audio | AudioRingMode | RINGER_MODE_VIBRATE = 1 | 新增 |
| ohos.multimedia.audio | AudioRingMode | RINGER_MODE_SILENT = 0 | 新增 |
| ohos.multimedia.audio | ActiveDeviceType | BLUETOOTH_SCO = 7 | 新增 |
| ohos.multimedia.audio | ActiveDeviceType | SPEAKER = 2 | 新增 |
| ohos.multimedia.audio | DeviceType | USB_HEADSET = 22 | 新增 |
| ohos.multimedia.audio | DeviceType | WIRED_HEADPHONES = 4 | 新增 |
| ohos.multimedia.audio | DeviceType | EARPIECE = 1 | 新增 |
| ohos.multimedia.audio | AudioVolumeType | VOICE_ASSISTANT = 9 | 新增 |
| ohos.multimedia.audio | AudioVolumeType | VOICE_CALL = 0 | 新增 |
| ohos.multimedia.audio | AudioState | STATE_PAUSED | 新增 |
| ohos.multimedia.audio | AudioState | STATE_RELEASED | 新增 |
| ohos.multimedia.audio | AudioState | STATE_STOPPED | 新增 |
| ohos.multimedia.audio | AudioState | STATE_RUNNING | 新增 |
| ohos.multimedia.audio | AudioState | STATE_PREPARED | 新增 |
| ohos.multimedia.audio | AudioState | STATE_NEW | 新增 |
| ohos.multimedia.audio | AudioState | STATE_INVALID = -1 | 新增 |
| ohos.multimedia.audio | audio | createAudioRenderer(options: AudioRendererOptions, callback: AsyncCallback\<AudioRenderer>): void;<br>createAudioRenderer(options: AudioRendererOptions): Promise\<AudioRenderer>; | 新增 |
| ohos.multimedia.audio | audio | createAudioCapturer(options: AudioCapturerOptions, callback: AsyncCallback\<AudioCapturer>): void;<br>createAudioCapturer(options: AudioCapturerOptions): Promise\<AudioCapturer>; | 新增 |
