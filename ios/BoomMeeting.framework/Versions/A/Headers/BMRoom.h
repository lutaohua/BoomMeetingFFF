//
//  BMRoom.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/18.
//

#import <Foundation/Foundation.h>
#import <BMRoomVM.h>
#import <BMParticipantVM.h>
#import "BMStreamModelVM.h"
#import "BMChatVM.h"
#import <BoomCore/BoomCore_i.h>
#import "BMCreateRoomConfig.h"
#import "BMSDKUser.h"
#import "BMConstants.h"

@class BMUser;
@class BMChatVM;


NS_ASSUME_NONNULL_BEGIN

@interface BMRoom : NSObject
@property(nonatomic, copy) NSString *roomName;
@property(nonatomic, strong, nullable) BMRoomVM *roomVM;
@property(nonatomic, strong, nullable) BMParticipantVM *participantVM;
@property(nonatomic, strong, nullable) BMStreamModelVM *streamModelVM;
@property(nonatomic, strong, nullable) BMChatVM *chatVM;

@property(nonatomic, strong) BMUser *localUser;
@property (nonatomic, assign) BOOL isStop;
/// 是否是研讨会
@property (nonatomic, assign) BOOL conference;


+ (instancetype)roomWithAppKey:(NSString *)appKey uri:(NSString *)uri roomName:(NSString *)roomName;
+ (instancetype)roomWithAppKey:(NSString *)appKey uri:(NSString *)uri roomName:(NSString *)roomName isChannel:(BOOL)isChannel;

- (void)joinRoom:(BMCreateRoomConfig *)config;
//- (void)joinRoom:(NSString *)roomNumber roomPassword:(NSString *)roomPassword user:(BMUser *)user;

- (void)joinRoomShare:(BMCreateRoomConfig *)config;

- (void)joinChannel:(BMCreateRoomConfig *)config;

- (void)leaveRoom;

- (void)leaveChannel;
/// 控制投屏的麦克风.
- (void)channelPublishAudioEnable:(BOOL)enable;
/// 控制屏幕共享的音频状态
- (void)controlScreenAudioEnable:(BOOL)enable;

/// 向服务端推流
/// @param streamID 定义的本地的streamid
/// @param config (非必需 )推流的配置
/// @param canvas (非必需 )用于回显本地流的抽象画布实例，内含画布实例
- (void)publish:(NSString *_Nonnull)streamID publishConfig:(BCPublishConfig *_Nonnull)config canvas:(BCCanvas *_Nullable)canvas;


/// 取消推流
/// @param streamID 流的唯一标识
- (void)unpublish:(NSString *_Nonnull)streamID;


/// 从服务端订阅流
/// @param streamID 定义的本地的streamid
/// @param config (非必需 )拉流的配置
/// @param canvas (非必需 )用于显示远流的抽象画布实例，内含画布实例
- (void)subscribe:(NSString *_Nonnull)streamID subscribeConfig:(BCSubscribeConfig *_Nullable)config canvas:(BCCanvas *_Nullable)canvas;


/// 取消订阅流
/// @param streamID 流的唯一标识
- (void)unsubscribe:(NSString *_Nonnull)streamID;

/// 为指定流添加显示画面
/// @param streamID  流的唯一标识
/// @param canvas 用于显示远流的抽象画布实例，内含画布实例
- (void)addStreamCanvas:(NSString *_Nonnull)streamID canvas:(BCCanvas *_Nonnull)canvas;


/// 为指定流删除显示画面
/// @param streamID  流的唯一标识
/// @param canvas (可选)用于显示远流的抽象画布实例，内含画布实例
- (void)removeStreamCanvas:(NSString *_Nonnull)streamID canvas:(BCCanvas *_Nonnull)canvas;


/// 禁止或恢复播放音频流
/// @param streamID  流的唯一标识
/// @param mute 禁用标识；YES 表示禁止播放；NO 表示恢复播放
- (void)muteStreamAudio:(NSString *_Nonnull)streamID mute:(BOOL)mute;


/// 禁止或恢复播放视频流
/// @param streamID  流的唯一标识
/// @param mute 禁用标识；YES 表示禁止播放；NO 表示恢复播放
- (void)muteStreamVideo:(NSString *_Nonnull)streamID mute:(BOOL)mute;

/// 设置远端音频状态
/// @param userId    用户ID
/// @param enable    状态
- (void)setRemoteAudioEnable:(NSString *)userId enable:(BOOL)enable;

/// 设置远端视频状态
/// @param userId            用户ID
/// @param enable            状态
- (void)setRemoteVideoEnable:(NSString *)userId enable:(BOOL)enable;


- (void)startReportStatus:(NSString *_Nonnull)streamId;

- (void)stopReportStatus:(NSString *_Nonnull)streamId;

/// 系统级屏幕分享
- (void)startScreenCaptureByReplaykit:(BCPublishConfig *)config appGroup:(NSString *)appGroup;
/// 停止屏幕采集
- (int)stopScreenCapture:(BOOL)isChannel;

@end

NS_ASSUME_NONNULL_END
