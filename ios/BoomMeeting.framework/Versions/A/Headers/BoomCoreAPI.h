//
//  BoomCoreAPI.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/20.
//

#import <Foundation/Foundation.h>
#import <BoomCore/BoomCore_i.h>
#import "BMRoom.h"
#import "BMQueue.h"
#import "BoomMeeting.h"

@class BMRoom;
@class BMUser;
@class BMRoomInfo;
@class BMStreamModel;
@class BMMessageInfo;

NS_ASSUME_NONNULL_BEGIN

@interface BoomCoreAPI : NSObject

+ (BoomCoreAPI *)instance;

@property(nonatomic, strong, nullable) BoomCore *roomRTC;
@property(nonatomic, strong, nullable) BMQueue *queue;

@property(nonatomic, strong, nullable) BMRoom *room;

@property (nonatomic,weak) id<BoomMeetingDelegate> meetingDelegate;

@property(nonatomic, assign) BOOL conference;

- (BoomCore *)createBoomRTC:(NSString *)appId uri:(NSString *)uri delegate:(id<BoomCoreDelegate>)delegate;

- (void)destroy:(BoomCore *)boomRTC;

- (void)manualCloseRoom:(void (^)(void))callback;

+ (BCCanvas *_Nonnull)createCanvas;

/// 为指定流添加显示画面
/// @param streamID  流的唯一标识
/// @param canvas 用于显示远流的抽象画布实例，内含画布实例
+ (void)addStreamCanvas:(NSString *_Nonnull)streamID canvas:(BCCanvas *_Nonnull)canvas;


/// 为指定流删除显示画面
/// @param streamID  流的唯一标识
/// @param canvas (可选)用于显示远流的抽象画布实例，内含画布实例
+ (void)removeStreamCanvas:(NSString *_Nonnull)streamID canvas:(BCCanvas *_Nonnull)canvas;


+ (void)subscribe:(NSString *_Nonnull)streamID subscribeConfig:(BCSubscribeConfig *_Nullable)config canvas:(BCCanvas *_Nullable)canvas;

+ (void)unsubscribe:(NSString *_Nonnull)streamID;

/// 切换大小流.
+ (void)toggleVideoStream:(NSString *_Nonnull)streamID index:(NSInteger)index;

/// 离开会议
+ (void)leaveRoom;
/// 结束会议,销毁房间
+ (void)releaseRoom;

/// 修改主持人
/// @param userId        新主持人用户ID
+ (void)changeMaster:(NSString *_Nonnull)userId;

/// 修改管理员
/// @param userId        用户ID
/// @param enable        是否拥有管理员权限 true:设置拥有管理员权限, false:撤销管理员权限
+ (void)changeManager:(NSString *_Nonnull)userId enable:(BOOL)enable;

+ (void)updateUserForUserId:(NSString *)userId user:(BMUser *)user;

/// 设置全员禁言
/// @param enable        全员禁言使能, true:开启全员禁言, false:关闭全员禁言
/// @param selfOpenAudio 是否允许用户自行开启MIC
+ (void)setAudioOff:(BOOL)enable selfOpenAudio:(BOOL)selfOpenAudio;

/// 设置房间关门
/// @param enable        是否房间关门(锁定后后续用户无法加入)
///                  true　 锁定
///                  false  释放锁定
+ (void)setDoorOpen:(BOOL)enable;

/// 设置房间
/// @param enable        是否锁定房间(锁定后后续用户无法加入)
///                  true　 锁定
///                  false   释放锁定
+ (void)setRoomLock:(BOOL)enable;

/// 设置扬声器状态
/// @param mute           true 开启 false 关闭
+ (void)setSpeakerMute:(BOOL)mute;

/// 房间广播
/// @param message               广播消息
/// @param fromUserId        发送者用户ID
/// @param toUserId            接收者用户ID(没有为全员广播)
+ (void)sendMessage:(NSString *_Nonnull)message toUserId:(NSString *_Nonnull)toUserId fromUserId:(NSString *_Nonnull)fromUserId;

+ (void)evictUser:(NSString *)userId;

+ (void)switchCamera;



+ (BMUser *)convertUser:(BCUser *)user;

+ (BMStreamModel *)converStream:(BCStream *)stream;

+ (BMMessageInfo *)convertMessageInfo:(BCMessageInfo *)info;

//+ (void)stashCanvas(BCCanvas *)canvas;



@end

NS_ASSUME_NONNULL_END
