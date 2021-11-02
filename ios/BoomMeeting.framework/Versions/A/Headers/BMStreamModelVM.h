//
//  BMStreamModelVM.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/18.
//

#import "BMBaseVM.h"
#import <BJLiveBase/BJLiveBase.h>
#import "BMConstants.h"
#import <BoomCore/BoomCore_i.h>
#import "BMStreamModel.h"
@class BMUser;
@class BMRoom;
@class BCStream;
@class BMGroup;
@class BCVolumeInfo;


NS_ASSUME_NONNULL_BEGIN

@interface BMStreamModelVM : BMBaseVM
- (instancetype)initWithRoom:(BMRoom *)room;
@property (nonatomic, assign) NSUInteger streamCount;
@property (nonatomic, strong) NSMutableArray<BMStreamModel *> *streamModels;
///存储观众的streamModels
@property (nonatomic, strong) NSMutableArray<BMStreamModel *> *viewerStreamModels;

@property (nonatomic, strong) NSMutableArray<BMStreamModel *> *shareStreamModels;
@property (nonatomic, weak) BMRoom *room;
@property (nonatomic, strong) BMStreamModel *
localModel;
@property (nonatomic, strong) BMStreamModel *smallModel;
@property (nonatomic, strong) BMStreamModel *mainModel;

@property (nonatomic, copy) NSArray<BMGroup *> *dataSource;
///观众端判断是否存在混流
@property (nonatomic, assign) BOOL hasMixStream;

- (BMStreamModel *)getStreamModel:(NSString *)streamId;

- (BMStreamModel *)createStreamModel:(BMUser *)bmUser stream:(BCStream *)stream;

- (void)addStreamModel:(BMStreamModel *)streamModel;
- (void)removeStreamModel:(BMStreamModel *)streamModel;
- (void)removeStreamModelWithStreamId:(NSString *)streamId;
- (void)justRemoveStreamModel:(BMStreamModel *)streamModel;

- (void)subscribe:(BMStreamModel *)stream;
- (void)unsubscribe:(BMStreamModel *)stream;

/// 全员静音状态改变
- (void)audioOffStatusChange:(BOOL)audioOff;

/// 打开本地的麦克风,
/// @param mute 是否静音
/// @param isRemote 是否是远端控制的
- (void)muteLocalStreamAudio:(BOOL)mute isRemote:(BOOL)isRemote;

/// 打开本地的摄像头,
/// @param mute 是否关闭摄像头
/// @param isRemote 是否是远端控制的
- (void)muteLocalStreamVideo:(BOOL)mute isRemote:(BOOL)isRemote;

- (void)muteLocalStreamVideoWhenSharing:(BOOL)isSharing;

- (void)publish:(BOOL)enableAudio enableVideo:(BOOL)enableVideo isUpdateState:(BOOL)isUpdateState;
- (void)unpublish;

- (void)remoteStreamPublished:(BCStream *)stream;
- (void)remoteStreamUnpublished:(BCStream *)stream;
- (void)updateStreamState:(BCStream * _Nullable)stream enableAudio:(BOOL)enableAudio enableVideo:(BOOL)enableVideo;
/// 状态改变之后, 意味着,拉流可能是完成了.
- (void)didRemoteStream:(BCStream *)stream connectionChange:(BMStreamConnectionState)newState;

- (void)didStream:(BCStream *)stream didStatsReport:(BCStatsReport *)statsReport;

/// 双击窗口上大窗; 去更新大窗的数据
- (void)updateMainWindow:(BMStreamModel *)streamModel;
/// 单击小窗口,更新小窗的数据,切换大小窗口
- (void)updateSmallMainWindow:(BMStreamModel *)streamModel;

/// 更改页数.
- (void)changePageIndex:(NSInteger)index;

- (void)enterBackground:(NSArray<BMStreamModel *> *)streams;
- (void)enterForeground;

- (BJLObservable)changeToTop;
- (BJLObservable)refreshCollectionViewHeader;
/// 远端控制本地打开摄像头
- (BJLObservable)remoteControlLocalStreamVideo:(BOOL)mute;
/// 远端控制本地打开麦克风
- (BJLObservable)remoteControlLocalStreamAudio:(BOOL)mute;
//- (BJLObservable)onUpdateVoiceVolume:(NSArray *)streamModels;

- (void)onUserVoiceVolume:(NSArray<BCVolumeInfo *> *)userVolumes totalVolume:(NSInteger)totalVolume;

/// 进入共享屏幕模式的时候, 取消拉当前页面的视频流
- (void)enterShareScreenMode:(NSArray<BMStreamModel *> *)streams;
/// 退出共享屏幕模式的时候, 开始拉当前页面的视频流
- (void)exitShareScreenMode;

/// 更新混流布局
- (void)updateMixer;

- (void)addBCStreamForViewer:(BCStream *)stream;
- (void)updateBCStreamForViewer:(BCStream *)stream;
- (void)removeBCStreamForViewer:(BCStream *)stream;
/// 观众开始拉音频流(fcu)
- (void)startPullStreamForViewer;
/// 观众结束拉音频流(fcu)
- (void)stopPullStreamForViewer;
/// 操作扬声器的时候,检测音频状态,若允许发言时,扬声器状态应该一直是关.
- (void)checkMixerStreamAudioStatus;
@end

NS_ASSUME_NONNULL_END
