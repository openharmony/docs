# JS API Changes of the Multimedia Subsystem

The table below lists the APIs changes of the multimedia subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.multimedia.mediaLibrary | Size | height: number; | Added|
| ohos.multimedia.mediaLibrary | Size | width: number; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | startMediaSelect(option: MediaSelectOption, callback: AsyncCallback\<Array\<string>>): void;<br>startMediaSelect(option: MediaSelectOption): Promise\<Array\<string>>; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | startImagePreview(images: Array\<string>, index: number, callback: AsyncCallback\<void>): void;<br>startImagePreview(images: Array\<string>, callback: AsyncCallback\<void>): void;<br>startImagePreview(images: Array\<string>, index?: number): Promise\<void>; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback\<string>): void;<br>storeMediaAsset(option: MediaAssetOption): Promise\<string>; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album>>): void;<br>getAlbums(options: MediaFetchOptions): Promise\<Array\<Album>>; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset>): void;<br>createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset>; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void>): void; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult>; | Added|
| ohos.multimedia.mediaLibrary | MediaLibrary | getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string>): void;<br>getPublicDirectory(type: DirectoryType): Promise\<string>; | Added|
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_DOWNLOAD | Added|
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_DOCUMENTS | Added|
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_AUDIO | Added|
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_IMAGE | Added|
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_VIDEO | Added|
| ohos.multimedia.mediaLibrary | DirectoryType | DIR_CAMERA = 0 | Added|
| ohos.multimedia.mediaLibrary | Album | getFileAssets(callback: AsyncCallback\<FetchFileResult>): void;<br>getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void;<br>getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult>; | Added|
| ohos.multimedia.mediaLibrary | Album | commitModify(callback: AsyncCallback\<void>): void;<br>commitModify(): Promise\<void>; | Added|
| ohos.multimedia.mediaLibrary | Album | readonly coverUri: string; | Added|
| ohos.multimedia.mediaLibrary | Album | readonly relativePath: string; | Added|
| ohos.multimedia.mediaLibrary | Album | readonly count: number; | Added|
| ohos.multimedia.mediaLibrary | Album | readonly dateModified: number; | Added|
| ohos.multimedia.mediaLibrary | Album | readonly albumUri: string; | Added|
| ohos.multimedia.mediaLibrary | Album | albumName: string; | Added|
| ohos.multimedia.mediaLibrary | Album | readonly albumId: number; | Added|
| ohos.multimedia.mediaLibrary | FetchFileResult | getAllObject(callback: AsyncCallback\<Array\<FileAsset>>): void;<br>getAllObject(): Promise\<Array\<FileAsset>>; | Added|
| ohos.multimedia.mediaLibrary | FetchFileResult | getPositionObject(index: number, callback: AsyncCallback\<FileAsset>): void;<br>getPositionObject(index: number): Promise\<FileAsset>; | Added|
| ohos.multimedia.mediaLibrary | FetchFileResult | getLastObject(callback: AsyncCallback\<FileAsset>): void;<br>getLastObject(): Promise\<FileAsset>; | Added|
| ohos.multimedia.mediaLibrary | FetchFileResult | getNextObject(callback: AsyncCallback\<FileAsset>): void;<br>getNextObject(): Promise\<FileAsset>; | Added|
| ohos.multimedia.mediaLibrary | FetchFileResult | getFirstObject(callback: AsyncCallback\<FileAsset>): void;<br>getFirstObject(): Promise\<FileAsset>; | Added|
| ohos.multimedia.mediaLibrary | FetchFileResult | close(): void; | Added|
| ohos.multimedia.mediaLibrary | FetchFileResult | isAfterLast(): boolean; | Added|
| ohos.multimedia.mediaLibrary | FetchFileResult | getCount(): number; | Added|
| ohos.multimedia.mediaLibrary | MediaFetchOptions | extendArgs?: string; | Added|
| ohos.multimedia.mediaLibrary | MediaFetchOptions | networkId?: string; | Added|
| ohos.multimedia.mediaLibrary | MediaFetchOptions | uri?: string; | Added|
| ohos.multimedia.mediaLibrary | MediaFetchOptions | order?: string; | Added|
| ohos.multimedia.mediaLibrary | MediaFetchOptions | selectionArgs: Array\<string>; | Added|
| ohos.multimedia.mediaLibrary | MediaFetchOptions | selections: string; | Added|
| ohos.multimedia.mediaLibrary | FileKey | ALBUM_NAME = "bucket_display_name" | Added|
| ohos.multimedia.mediaLibrary | FileKey | ALBUM_ID = "bucket_id" | Added|
| ohos.multimedia.mediaLibrary | FileKey | ORIENTATION = "orientation" | Added|
| ohos.multimedia.mediaLibrary | FileKey | HEIGHT = "height" | Added|
| ohos.multimedia.mediaLibrary | FileKey | WIDTH = "width" | Added|
| ohos.multimedia.mediaLibrary | FileKey | DURATION = "duration" | Added|
| ohos.multimedia.mediaLibrary | FileKey | AUDIOALBUM = "audio_album" | Added|
| ohos.multimedia.mediaLibrary | FileKey | ARTIST = "artist" | Added|
| ohos.multimedia.mediaLibrary | FileKey | TITLE = "title" | Added|
| ohos.multimedia.mediaLibrary | FileKey | DATE_TAKEN = "date_taken" | Added|
| ohos.multimedia.mediaLibrary | FileKey | DATE_MODIFIED = "date_modified" | Added|
| ohos.multimedia.mediaLibrary | FileKey | DATE_ADDED = "date_added" | Added|
| ohos.multimedia.mediaLibrary | FileKey | SIZE = "size" | Added|
| ohos.multimedia.mediaLibrary | FileKey | MEDIA_TYPE = "media_type" | Added|
| ohos.multimedia.mediaLibrary | FileKey | MIME_TYPE = "mime_type" | Added|
| ohos.multimedia.mediaLibrary | FileKey | PARENT = "parent" | Added|
| ohos.multimedia.mediaLibrary | FileKey | DISPLAY_NAME = "display_name" | Added|
| ohos.multimedia.mediaLibrary | FileKey | RELATIVE_PATH = "relative_path" | Added|
| ohos.multimedia.mediaLibrary | FileKey | ID = "file_id" | Added|
| ohos.multimedia.mediaLibrary | FileAsset | isTrash(callback: AsyncCallback\<boolean>): void;<br>isTrash():Promise\<boolean>; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | trash(isTrash: boolean, callback: AsyncCallback\<void>): void;<br>trash(isTrash: boolean): Promise\<void>; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | isFavorite(callback: AsyncCallback\<boolean>): void;<br>isFavorite():Promise\<boolean>; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | favorite(isFavorite: boolean, callback: AsyncCallback\<void>): void;<br>favorite(isFavorite: boolean): Promise\<void>; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | getThumbnail(callback: AsyncCallback\<image.PixelMap>): void;<br>getThumbnail(size: Size, callback: AsyncCallback\<image.PixelMap>): void;<br>getThumbnail(size?: Size): Promise\<image.PixelMap>; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | close(fd: number, callback: AsyncCallback\<void>): void;<br>close(fd: number): Promise\<void>; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | open(mode: string, callback: AsyncCallback\<number>): void;<br>open(mode: string): Promise\<number>; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | commitModify(callback: AsyncCallback\<void>): void;<br>commitModify(): Promise\<void>; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | isDirectory(callback: AsyncCallback\<boolean>): void;<br>isDirectory():Promise\<boolean>; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly albumName: string; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly albumUri: string; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly albumId: number; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly duration: number; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | orientation: number; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly height: number; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly width: number; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly audioAlbum: string; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly artist: string; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly dateTaken: number; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly dateModified: number; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly dateAdded: number; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly size: number; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly parent: number; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | relativePath: string; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | title: string; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | displayName: string; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly mediaType: MediaType; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly mimeType: string; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly uri: string; | Added|
| ohos.multimedia.mediaLibrary | FileAsset | readonly id: number; | Added|
| ohos.multimedia.mediaLibrary | MediaSelectOption | count: number; | Added|
| ohos.multimedia.mediaLibrary | MediaSelectOption | type: 'image' \| 'video' \| 'media'; | Added|
| ohos.multimedia.mediaLibrary | MediaAssetOption | relativePath?: string; | Added|
| ohos.multimedia.mediaLibrary | MediaAssetOption | mimeType: string; | Added|
| ohos.multimedia.mediaLibrary | MediaAssetOption | src: string; | Added|
| ohos.multimedia.mediaLibrary | MediaType | AUDIO | Added|
| ohos.multimedia.mediaLibrary | MediaType | VIDEO | Added|
| ohos.multimedia.mediaLibrary | MediaType | IMAGE | Added|
| ohos.multimedia.mediaLibrary | MediaType | FILE = 0 | Added|
| ohos.multimedia.mediaLibrary | mediaLibrary | getMediaLibrary(): MediaLibrary;<br>getMediaLibrary(context: Context): MediaLibrary; | Added|
| ohos.multimedia.media | CodecMimeType | AUDIO_FLAC = 'audio/flac' | Added|
| ohos.multimedia.media | CodecMimeType | AUDIO_VORBIS = 'audio/vorbis' | Added|
| ohos.multimedia.media | CodecMimeType | AUDIO_AAC = 'audio/mp4a-latm' | Added|
| ohos.multimedia.media | CodecMimeType | VIDEO_VP8 = 'video/x-vnd.on2.vp8' | Added|
| ohos.multimedia.media | CodecMimeType | VIDEO_MPEG4 = 'video/mp4v-es' | Added|
| ohos.multimedia.media | CodecMimeType | VIDEO_MPEG2 = 'video/mpeg2' | Added|
| ohos.multimedia.media | CodecMimeType | VIDEO_AVC = 'video/avc' | Added|
| ohos.multimedia.media | CodecMimeType | VIDEO_H263 = 'video/h263' | Added|
| ohos.multimedia.media | SeekMode | SEEK_PREV_SYNC = 1 | Added|
| ohos.multimedia.media | SeekMode | SEEK_NEXT_SYNC = 0 | Added|
| ohos.multimedia.media | MediaDescription | [key : string]: Object; | Added|
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_AUD_SAMPLE_RATE = "sample_rate" | Added|
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_AUD_CHANNEL_COUNT = "channel_count" | Added|
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_FRAME_RATE = "frame_rate" | Added|
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_HEIGHT = "height" | Added|
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_WIDTH = "width" | Added|
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_BITRATE = "bitrate" | Added|
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_DURATION = "duration" | Added|
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_CODEC_MIME = "codec_mime" | Added|
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_TRACK_TYPE = "track_type" | Added|
| ohos.multimedia.media | MediaDescriptionKey | MD_KEY_TRACK_INDEX = "track_index" | Added|
| ohos.multimedia.media | MediaType | MEDIA_TYPE_VID = 1 | Added|
| ohos.multimedia.media | MediaType | MEDIA_TYPE_AUD = 0 | Added|
| ohos.multimedia.media | ContainerFormatType | CFT_MPEG_4A = "m4a" | Added|
| ohos.multimedia.media | ContainerFormatType | CFT_MPEG_4 = "mp4" | Added|
| ohos.multimedia.media | VideoPlayer | on(type: 'error', callback: ErrorCallback): void; | Added|
| ohos.multimedia.media | VideoPlayer | on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void; | Added|
| ohos.multimedia.media | VideoPlayer | on(type: 'startRenderFrame', callback: Callback\<void>): void; | Added|
| ohos.multimedia.media | VideoPlayer | on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void; | Added|
| ohos.multimedia.media | VideoPlayer | on(type: 'playbackCompleted', callback: Callback\<void>): void; | Added|
| ohos.multimedia.media | VideoPlayer | setSpeed(speed:number, callback: AsyncCallback\<number>): void;<br>setSpeed(speed:number): Promise\<number>; | Added|
| ohos.multimedia.media | VideoPlayer | readonly height: number; | Added|
| ohos.multimedia.media | VideoPlayer | readonly width: number; | Added|
| ohos.multimedia.media | VideoPlayer | readonly state: VideoPlayState; | Added|
| ohos.multimedia.media | VideoPlayer | readonly duration: number; | Added|
| ohos.multimedia.media | VideoPlayer | readonly currentTime: number; | Added|
| ohos.multimedia.media | VideoPlayer | loop: boolean; | Added|
| ohos.multimedia.media | VideoPlayer | url: string; | Added|
| ohos.multimedia.media | VideoPlayer | getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>getTrackDescription() : Promise\<Array\<MediaDescription>>; | Added|
| ohos.multimedia.media | VideoPlayer | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoPlayer | setVolume(vol: number, callback: AsyncCallback\<void>): void;<br>setVolume(vol: number): Promise\<void>; | Added|
| ohos.multimedia.media | VideoPlayer | seek(timeMs: number, callback: AsyncCallback\<number>): void;<br>seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void;<br>seek(timeMs: number, mode?:SeekMode): Promise\<number>; | Added|
| ohos.multimedia.media | VideoPlayer | reset(callback: AsyncCallback\<void>): void;<br>reset(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoPlayer | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoPlayer | pause(callback: AsyncCallback\<void>): void;<br>pause(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoPlayer | play(callback: AsyncCallback\<void>): void;<br>play(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoPlayer | prepare(callback: AsyncCallback\<void>): void;<br>prepare(): Promise\<void>; | Added|
| ohos.multimedia.media | VideoPlayer | setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void;<br>setDisplaySurface(surfaceId: string): Promise\<void>; | Added|
| ohos.multimedia.media | PlaybackSpeed | SPEED_FORWARD_2_00_X = 4 | Added|
| ohos.multimedia.media | PlaybackSpeed | SPEED_FORWARD_1_75_X = 3 | Added|
| ohos.multimedia.media | PlaybackSpeed | SPEED_FORWARD_1_25_X = 2 | Added|
| ohos.multimedia.media | PlaybackSpeed | SPEED_FORWARD_1_00_X = 1 | Added|
| ohos.multimedia.media | PlaybackSpeed | SPEED_FORWARD_0_75_X = 0 | Added|
| ohos.multimedia.media | AudioRecorder | on(type: 'error', callback: ErrorCallback): void; | Added|
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | Added|
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | Added|
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | Added|
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | Added|
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | Added|
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | Added|
| ohos.multimedia.media | AudioRecorder | on(type: 'prepare' \| 'start' \| 'pause' \| 'resume' \| 'stop' \| 'release' \| 'reset', callback: () => void): void; | Added|
| ohos.multimedia.media | AudioRecorder | reset(): void; | Added|
| ohos.multimedia.media | AudioRecorder | release(): void; | Added|
| ohos.multimedia.media | AudioRecorder | stop(): void; | Added|
| ohos.multimedia.media | AudioRecorder | resume(): void; | Added|
| ohos.multimedia.media | AudioRecorder | pause(): void; | Added|
| ohos.multimedia.media | AudioRecorder | start(): void; | Added|
| ohos.multimedia.media | AudioRecorder | prepare(config: AudioRecorderConfig): void; | Added|
| ohos.multimedia.media | AudioRecorderConfig | fileFormat?: ContainerFormatType; | Added|
| ohos.multimedia.media | AudioRecorderConfig | audioEncoderMime?: CodecMimeType; | Added|
| ohos.multimedia.media | AudioRecorderConfig | location?: Location; | Added|
| ohos.multimedia.media | AudioRecorderConfig | uri: string; | Added|
| ohos.multimedia.media | AudioRecorderConfig | format?: AudioOutputFormat; | Added|
| ohos.multimedia.media | AudioRecorderConfig | numberOfChannels?: number; | Added|
| ohos.multimedia.media | AudioRecorderConfig | audioSampleRate?: number; | Added|
| ohos.multimedia.media | AudioRecorderConfig | audioEncodeBitRate?: number; | Added|
| ohos.multimedia.media | AudioRecorderConfig | audioEncoder?: AudioEncoder; | Added|
| ohos.multimedia.media | Location | longitude: number; | Added|
| ohos.multimedia.media | Location | latitude: number; | Added|
| ohos.multimedia.media | AudioOutputFormat | AAC_ADTS = 6 | Added|
| ohos.multimedia.media | AudioOutputFormat | AMR_WB = 4 | Added|
| ohos.multimedia.media | AudioOutputFormat | AMR_NB = 3 | Added|
| ohos.multimedia.media | AudioOutputFormat | MPEG_4 = 2 | Added|
| ohos.multimedia.media | AudioOutputFormat | DEFAULT = 0 | Added|
| ohos.multimedia.media | AudioEncoder | HE_AAC = 4 | Added|
| ohos.multimedia.media | AudioEncoder | AAC_LC = 3 | Added|
| ohos.multimedia.media | AudioEncoder | AMR_WB = 2 | Added|
| ohos.multimedia.media | AudioEncoder | AMR_NB = 1 | Added|
| ohos.multimedia.media | AudioEncoder | DEFAULT = 0 | Added|
| ohos.multimedia.media | AudioPlayer | on(type: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange', callback: () => void): void; | Added|
| ohos.multimedia.media | AudioPlayer | on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void; | Added|
| ohos.multimedia.media | AudioPlayer | getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void;<br>getTrackDescription() : Promise\<Array\<MediaDescription>>; | Added|
| ohos.multimedia.media | AudioPlayer | reset(): void; | Added|
| ohos.multimedia.media | BufferingInfoType | CACHED_DURATION = 4 | Added|
| ohos.multimedia.media | BufferingInfoType | BUFFERING_PERCENT = 3 | Added|
| ohos.multimedia.media | BufferingInfoType | BUFFERING_END = 2 | Added|
| ohos.multimedia.media | BufferingInfoType | BUFFERING_START = 1 | Added|
| ohos.multimedia.media | MediaErrorCode | MSERR_UNSUPPORTED = 9 | Added|
| ohos.multimedia.media | MediaErrorCode | MSERR_INVALID_STATE = 8 | Added|
| ohos.multimedia.media | MediaErrorCode | MSERR_SERVICE_DIED = 7 | Added|
| ohos.multimedia.media | MediaErrorCode | MSERR_UNKNOWN = 6 | Added|
| ohos.multimedia.media | MediaErrorCode | MSERR_TIMEOUT = 5 | Added|
| ohos.multimedia.media | MediaErrorCode | MSERR_IO = 4 | Added|
| ohos.multimedia.media | MediaErrorCode | MSERR_INVALID_VAL = 3 | Added|
| ohos.multimedia.media | MediaErrorCode | MSERR_OPERATION_NOT_PERMIT = 2 | Added|
| ohos.multimedia.media | MediaErrorCode | MSERR_NO_MEMORY = 1 | Added|
| ohos.multimedia.media | MediaErrorCode | MSERR_OK = 0 | Added|
| ohos.multimedia.media | media | createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void;<br>createVideoPlayer() : Promise\<VideoPlayer>; | Added|
| ohos.multimedia.media | media | createAudioRecorder(): AudioRecorder; | Added|
| ohos.multimedia.image | ImagePacker | readonly supportedFormats: Array\<string>; | Added|
| ohos.multimedia.image | ImagePacker | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.image | ImagePacker | packing(source: ImageSource, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void;<br>packing(source: ImageSource, option: PackingOption): Promise\<ArrayBuffer>;<br>packing(source: PixelMap, option: PackingOption, callback: AsyncCallback\<ArrayBuffer>): void;<br>packing(source: PixelMap, option: PackingOption): Promise\<ArrayBuffer>; | Added|
| ohos.multimedia.image | ImageSource | readonly supportedFormats: Array\<string>; | Added|
| ohos.multimedia.image | ImageSource | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.image | ImageSource | getImageProperty(key:string, options?: GetImagePropertyOptions): Promise\<string>;<br>getImageProperty(key:string, callback: AsyncCallback\<string>): void;<br>getImageProperty(key:string, options: GetImagePropertyOptions, callback: AsyncCallback\<string>): void; | Added|
| ohos.multimedia.image | ImageSource | createPixelMap(options?: DecodingOptions): Promise\<PixelMap>;<br>createPixelMap(callback: AsyncCallback\<PixelMap>): void;<br>createPixelMap(options: DecodingOptions, callback: AsyncCallback\<PixelMap>): void; | Added|
| ohos.multimedia.image | ImageSource | getImageInfo(index: number, callback: AsyncCallback\<ImageInfo>): void;<br>getImageInfo(callback: AsyncCallback\<ImageInfo>): void;<br>getImageInfo(index?: number): Promise\<ImageInfo>; | Added|
| ohos.multimedia.image | PixelMap | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.image | PixelMap | getPixelBytesNumber(): number; | Added|
| ohos.multimedia.image | PixelMap | getBytesNumberPerRow(): number; | Added|
| ohos.multimedia.image | PixelMap | getImageInfo(): Promise\<ImageInfo>;<br>getImageInfo(callback: AsyncCallback\<ImageInfo>): void; | Added|
| ohos.multimedia.image | PixelMap | writeBufferToPixels(src: ArrayBuffer): Promise\<void>;<br>writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.image | PixelMap | writePixels(area: PositionArea): Promise\<void>;<br>writePixels(area: PositionArea, callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.image | PixelMap | readPixels(area: PositionArea): Promise\<void>;<br>readPixels(area: PositionArea, callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.image | PixelMap | readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>;<br>readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void; | Added|
| ohos.multimedia.image | PixelMap | readonly isEditable: boolean; | Added|
| ohos.multimedia.image | image | createImagePacker(): ImagePacker; | Added|
| ohos.multimedia.image | image | createImageSource(uri: string): ImageSource;<br>createImageSource(fd: number): ImageSource; | Added|
| ohos.multimedia.image | image | createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void;<br>createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>; | Added|
| ohos.multimedia.image | InitializationOptions | editable?: boolean; | Added|
| ohos.multimedia.image | InitializationOptions | pixelFormat?: PixelMapFormat; | Added|
| ohos.multimedia.image | InitializationOptions | size: Size; | Added|
| ohos.multimedia.image | DecodingOptions | desiredPixelFormat?: PixelMapFormat; | Added|
| ohos.multimedia.image | DecodingOptions | desiredRegion?: Region; | Added|
| ohos.multimedia.image | DecodingOptions | desiredSize?: Size; | Added|
| ohos.multimedia.image | DecodingOptions | editable?: boolean; | Added|
| ohos.multimedia.image | DecodingOptions | rotate?: number; | Added|
| ohos.multimedia.image | DecodingOptions | sampleSize?: number; | Added|
| ohos.multimedia.image | DecodingOptions | index?: number; | Added|
| ohos.multimedia.image | GetImagePropertyOptions | defaultValue?: string; | Added|
| ohos.multimedia.image | GetImagePropertyOptions | index?: number; | Added|
| ohos.multimedia.image | PackingOption | quality: number; | Added|
| ohos.multimedia.image | PackingOption | format: string; | Added|
| ohos.multimedia.image | ImageInfo | size: Size; | Added|
| ohos.multimedia.image | PositionArea | region: Region; | Added|
| ohos.multimedia.image | PositionArea | stride: number; | Added|
| ohos.multimedia.image | PositionArea | offset: number; | Added|
| ohos.multimedia.image | PositionArea | pixels: ArrayBuffer; | Added|
| ohos.multimedia.image | Region | y: number; | Added|
| ohos.multimedia.image | Region | x: number; | Added|
| ohos.multimedia.image | Region | size: Size; | Added|
| ohos.multimedia.image | PropertyKey | GPS_LONGITUDE_REF = "GPSLongitudeRef" | Added|
| ohos.multimedia.image | PropertyKey | GPS_LATITUDE_REF = "GPSLatitudeRef" | Added|
| ohos.multimedia.image | PropertyKey | GPS_LONGITUDE = "GPSLongitude" | Added|
| ohos.multimedia.image | PropertyKey | GPS_LATITUDE = "GPSLatitude" | Added|
| ohos.multimedia.image | PropertyKey | IMAGE_WIDTH = "ImageWidth" | Added|
| ohos.multimedia.image | PropertyKey | IMAGE_LENGTH = "ImageLength" | Added|
| ohos.multimedia.image | PropertyKey | ORIENTATION = "Orientation" | Added|
| ohos.multimedia.image | PropertyKey | BITS_PER_SAMPLE = "BitsPerSample" | Added|
| ohos.multimedia.image | Size | width: number; | Added|
| ohos.multimedia.image | Size | height: number; | Added|
| ohos.multimedia.image | PixelMapFormat | RGBA_8888 = 3 | Added|
| ohos.multimedia.image | PixelMapFormat | RGB_565 = 2 | Added|
| ohos.multimedia.image | PixelMapFormat | UNKNOWN = 0 | Added|
| ohos.multimedia.audio | AudioCapturer | on(type: "stateChange", callback: Callback\<AudioState>): void; | Added|
| ohos.multimedia.audio | AudioCapturer | off(type: "periodReach"): void; | Added|
| ohos.multimedia.audio | AudioCapturer | on(type: "periodReach", frame: number, callback: (position: number) => {}): void; | Added|
| ohos.multimedia.audio | AudioCapturer | off(type: "markReach"): void; | Added|
| ohos.multimedia.audio | AudioCapturer | on(type: "markReach", frame: number, callback: (position: number) => {}): void; | Added|
| ohos.multimedia.audio | AudioCapturer | getBufferSize(callback: AsyncCallback\<number>): void;<br>getBufferSize(): Promise\<number>; | Added|
| ohos.multimedia.audio | AudioCapturer | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioCapturer | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioCapturer | getAudioTime(callback: AsyncCallback\<number>): void;<br>getAudioTime(): Promise\<number>; | Added|
| ohos.multimedia.audio | AudioCapturer | read(size: number, isBlockingRead: boolean, callback: AsyncCallback\<ArrayBuffer>): void;<br>read(size: number, isBlockingRead: boolean): Promise\<ArrayBuffer>; | Added|
| ohos.multimedia.audio | AudioCapturer | start(callback: AsyncCallback\<void>): void;<br>start(): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioCapturer | getStreamInfo(callback: AsyncCallback\<AudioStreamInfo>): void;<br>getStreamInfo(): Promise\<AudioStreamInfo>; | Added|
| ohos.multimedia.audio | AudioCapturer | getCapturerInfo(callback: AsyncCallback\<AudioCapturerInfo>): void;<br>getCapturerInfo(): Promise\<AudioCapturerInfo>; | Added|
| ohos.multimedia.audio | AudioCapturer | readonly state: AudioState; | Added|
| ohos.multimedia.audio | AudioCapturerOptions | capturerInfo: AudioCapturerInfo; | Added|
| ohos.multimedia.audio | AudioCapturerOptions | streamInfo: AudioStreamInfo; | Added|
| ohos.multimedia.audio | AudioCapturerInfo | capturerFlags: number; | Added|
| ohos.multimedia.audio | AudioCapturerInfo | source: SourceType; | Added|
| ohos.multimedia.audio | SourceType | SOURCE_TYPE_VOICE_COMMUNICATION = 7 | Added|
| ohos.multimedia.audio | SourceType | SOURCE_TYPE_MIC = 0 | Added|
| ohos.multimedia.audio | SourceType | SOURCE_TYPE_INVALID = -1 | Added|
| ohos.multimedia.audio | AudioRenderer | on(type: "stateChange", callback: Callback\<AudioState>): void; | Added|
| ohos.multimedia.audio | AudioRenderer | off(type: "periodReach"): void; | Added|
| ohos.multimedia.audio | AudioRenderer | on(type: "periodReach", frame: number, callback: (position: number) => {}): void; | Added|
| ohos.multimedia.audio | AudioRenderer | off(type: "markReach"): void; | Added|
| ohos.multimedia.audio | AudioRenderer | on(type: "markReach", frame: number, callback: (position: number) => {}): void; | Added|
| ohos.multimedia.audio | AudioRenderer | getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void;<br>getRenderRate(): Promise\<AudioRendererRate>; | Added|
| ohos.multimedia.audio | AudioRenderer | setRenderRate(rate: AudioRendererRate, callback: AsyncCallback\<void>): void;<br>setRenderRate(rate: AudioRendererRate): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioRenderer | getBufferSize(callback: AsyncCallback\<number>): void;<br>getBufferSize(): Promise\<number>; | Added|
| ohos.multimedia.audio | AudioRenderer | release(callback: AsyncCallback\<void>): void;<br>release(): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioRenderer | stop(callback: AsyncCallback\<void>): void;<br>stop(): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioRenderer | pause(callback: AsyncCallback\<void>): void;<br>pause(): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioRenderer | drain(callback: AsyncCallback\<void>): void;<br>drain(): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioRenderer | getAudioTime(callback: AsyncCallback\<number>): void;<br>getAudioTime(): Promise\<number>; | Added|
| ohos.multimedia.audio | AudioRenderer | write(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void;<br>write(buffer: ArrayBuffer): Promise\<number>; | Added|
| ohos.multimedia.audio | AudioRenderer | start(callback: AsyncCallback\<void>): void;<br>start(): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioRenderer | getStreamInfo(callback: AsyncCallback\<AudioStreamInfo>): void;<br>getStreamInfo(): Promise\<AudioStreamInfo>; | Added|
| ohos.multimedia.audio | AudioRenderer | getRendererInfo(callback: AsyncCallback\<AudioRendererInfo>): void;<br>getRendererInfo(): Promise\<AudioRendererInfo>; | Added|
| ohos.multimedia.audio | AudioRenderer | readonly state: AudioState; | Added|
| ohos.multimedia.audio | DeviceChangeAction | deviceDescriptors: AudioDeviceDescriptors; | Added|
| ohos.multimedia.audio | DeviceChangeAction | type: DeviceChangeType; | Added|
| ohos.multimedia.audio | AudioInterrupt | pauseWhenDucked: boolean; | Added|
| ohos.multimedia.audio | AudioInterrupt | contentType: ContentType; | Added|
| ohos.multimedia.audio | AudioInterrupt | streamUsage: StreamUsage; | Added|
| ohos.multimedia.audio | InterruptAction | activated?: boolean; | Added|
| ohos.multimedia.audio | InterruptAction | hint?: InterruptHint; | Added|
| ohos.multimedia.audio | InterruptAction | type?: InterruptType; | Added|
| ohos.multimedia.audio | InterruptAction | actionType: InterruptActionType; | Added|
| ohos.multimedia.audio | AudioManager | off(type: 'interrupt', interrupt: AudioInterrupt, callback?: Callback\<InterruptAction>): void; | Added|
| ohos.multimedia.audio | AudioManager | on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback\<InterruptAction>): void; | Added|
| ohos.multimedia.audio | AudioManager | off(type: 'deviceChange', callback?: Callback\<DeviceChangeAction>): void; | Added|
| ohos.multimedia.audio | AudioManager | on(type: 'deviceChange', callback: Callback\<DeviceChangeAction>): void; | Added|
| ohos.multimedia.audio | AudioManager | getAudioScene(callback: AsyncCallback\<AudioScene>): void;<br>getAudioScene(): Promise\<AudioScene>; | Added|
| ohos.multimedia.audio | AudioManager | isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback\<boolean>): void;<br>isDeviceActive(deviceType: ActiveDeviceType): Promise\<boolean>; | Added|
| ohos.multimedia.audio | AudioManager | setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback\<void>): void;<br>setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioManager | getAudioParameter(key: string, callback: AsyncCallback\<string>): void;<br>getAudioParameter(key: string): Promise\<string>; | Added|
| ohos.multimedia.audio | AudioManager | setAudioParameter(key: string, value: string, callback: AsyncCallback\<void>): void;<br>setAudioParameter(key: string, value: string): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioManager | getRingerMode(callback: AsyncCallback\<AudioRingMode>): void;<br>getRingerMode(): Promise\<AudioRingMode>; | Added|
| ohos.multimedia.audio | AudioManager | setRingerMode(mode: AudioRingMode, callback: AsyncCallback\<void>): void;<br>setRingerMode(mode: AudioRingMode): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioManager | isMicrophoneMute(callback: AsyncCallback\<boolean>): void;<br>isMicrophoneMute(): Promise\<boolean>; | Added|
| ohos.multimedia.audio | AudioManager | setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void;<br>setMicrophoneMute(mute: boolean): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioManager | isActive(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>isActive(volumeType: AudioVolumeType): Promise\<boolean>; | Added|
| ohos.multimedia.audio | AudioManager | isMute(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void;<br>isMute(volumeType: AudioVolumeType): Promise\<boolean>; | Added|
| ohos.multimedia.audio | AudioManager | mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback\<void>): void;<br>mute(volumeType: AudioVolumeType, mute: boolean): Promise\<void>; | Added|
| ohos.multimedia.audio | AudioScene | AUDIO_SCENE_VOICE_CHAT | Added|
| ohos.multimedia.audio | AudioScene | AUDIO_SCENE_DEFAULT = 0 | Added|
| ohos.multimedia.audio | DeviceChangeType | DISCONNECT = 1 | Added|
| ohos.multimedia.audio | DeviceChangeType | CONNECT = 0 | Added|
| ohos.multimedia.audio | InterruptActionType | TYPE_INTERRUPT = 1 | Added|
| ohos.multimedia.audio | InterruptActionType | TYPE_ACTIVATED = 0 | Added|
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_UNDUCK = 5 | Added|
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_DUCK = 4 | Added|
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_STOP = 3 | Added|
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_PAUSE = 2 | Added|
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_RESUME = 1 | Added|
| ohos.multimedia.audio | InterruptHint | INTERRUPT_HINT_NONE = 0 | Added|
| ohos.multimedia.audio | InterruptType | INTERRUPT_TYPE_END = 2 | Added|
| ohos.multimedia.audio | InterruptType | INTERRUPT_TYPE_BEGIN = 1 | Added|
| ohos.multimedia.audio | AudioRendererRate | RENDER_RATE_HALF = 2 | Added|
| ohos.multimedia.audio | AudioRendererRate | RENDER_RATE_DOUBLE = 1 | Added|
| ohos.multimedia.audio | AudioRendererRate | RENDER_RATE_NORMAL = 0 | Added|
| ohos.multimedia.audio | AudioRendererOptions | rendererInfo: AudioRendererInfo; | Added|
| ohos.multimedia.audio | AudioRendererOptions | streamInfo: AudioStreamInfo; | Added|
| ohos.multimedia.audio | AudioRendererInfo | rendererFlags: number; | Added|
| ohos.multimedia.audio | AudioRendererInfo | usage: StreamUsage; | Added|
| ohos.multimedia.audio | AudioRendererInfo | content: ContentType; | Added|
| ohos.multimedia.audio | AudioStreamInfo | encodingType: AudioEncodingType; | Added|
| ohos.multimedia.audio | AudioStreamInfo | sampleFormat: AudioSampleFormat; | Added|
| ohos.multimedia.audio | AudioStreamInfo | channels: AudioChannel; | Added|
| ohos.multimedia.audio | AudioStreamInfo | samplingRate: AudioSamplingRate; | Added|
| ohos.multimedia.audio | StreamUsage | STREAM_USAGE_NOTIFICATION_RINGTONE = 6 | Added|
| ohos.multimedia.audio | StreamUsage | STREAM_USAGE_VOICE_COMMUNICATION = 2 | Added|
| ohos.multimedia.audio | StreamUsage | STREAM_USAGE_MEDIA = 1 | Added|
| ohos.multimedia.audio | StreamUsage | STREAM_USAGE_UNKNOWN = 0 | Added|
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_RINGTONE = 5 | Added|
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_SONIFICATION = 4 | Added|
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_MOVIE = 3 | Added|
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_MUSIC = 2 | Added|
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_SPEECH = 1 | Added|
| ohos.multimedia.audio | ContentType | CONTENT_TYPE_UNKNOWN = 0 | Added|
| ohos.multimedia.audio | AudioEncodingType | ENCODING_TYPE_RAW = 0 | Added|
| ohos.multimedia.audio | AudioEncodingType | ENCODING_TYPE_INVALID = -1 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_96000 = 96000 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_64000 = 64000 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_48000 = 48000 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_44100 = 44100 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_32000 = 32000 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_24000 = 24000 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_22050 = 22050 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_16000 = 16000 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_12000 = 12000 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_11025 = 11025 | Added|
| ohos.multimedia.audio | AudioSamplingRate | SAMPLE_RATE_8000 = 8000 | Added|
| ohos.multimedia.audio | AudioChannel | CHANNEL_2 = 0x1 \<\< 1 | Added|
| ohos.multimedia.audio | AudioChannel | CHANNEL_1 = 0x1 \<\< 0 | Added|
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_S32LE = 3 | Added|
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_S24LE = 2 | Added|
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_S16LE = 1 | Added|
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_U8 = 0 | Added|
| ohos.multimedia.audio | AudioSampleFormat | SAMPLE_FORMAT_INVALID = -1 | Added|
| ohos.multimedia.audio | AudioRingMode | RINGER_MODE_NORMAL = 2 | Added|
| ohos.multimedia.audio | AudioRingMode | RINGER_MODE_VIBRATE = 1 | Added|
| ohos.multimedia.audio | AudioRingMode | RINGER_MODE_SILENT = 0 | Added|
| ohos.multimedia.audio | ActiveDeviceType | BLUETOOTH_SCO = 7 | Added|
| ohos.multimedia.audio | ActiveDeviceType | SPEAKER = 2 | Added|
| ohos.multimedia.audio | DeviceType | USB_HEADSET = 22 | Added|
| ohos.multimedia.audio | DeviceType | WIRED_HEADPHONES = 4 | Added|
| ohos.multimedia.audio | DeviceType | EARPIECE = 1 | Added|
| ohos.multimedia.audio | AudioVolumeType | VOICE_ASSISTANT = 9 | Added|
| ohos.multimedia.audio | AudioVolumeType | VOICE_CALL = 0 | Added|
| ohos.multimedia.audio | AudioState | STATE_PAUSED | Added|
| ohos.multimedia.audio | AudioState | STATE_RELEASED | Added|
| ohos.multimedia.audio | AudioState | STATE_STOPPED | Added|
| ohos.multimedia.audio | AudioState | STATE_RUNNING | Added|
| ohos.multimedia.audio | AudioState | STATE_PREPARED | Added|
| ohos.multimedia.audio | AudioState | STATE_NEW | Added|
| ohos.multimedia.audio | AudioState | STATE_INVALID = -1 | Added|
| ohos.multimedia.audio | audio | createAudioRenderer(options: AudioRendererOptions, callback: AsyncCallback\<AudioRenderer>): void;<br>createAudioRenderer(options: AudioRendererOptions): Promise\<AudioRenderer>; | Added|
| ohos.multimedia.audio | audio | createAudioCapturer(options: AudioCapturerOptions, callback: AsyncCallback\<AudioCapturer>): void;<br>createAudioCapturer(options: AudioCapturerOptions): Promise\<AudioCapturer>; | Added|
