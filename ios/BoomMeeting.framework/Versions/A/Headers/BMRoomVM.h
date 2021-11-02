//
//  BMRoomVM.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/18.
//

#import <Foundation/Foundation.h>
#import <BJLiveBase/BJLiveBase.h>
#import "BMBaseVM.h"
#import "ServiceApi.h"
#import "BMInviteInfo.h"
#import "BMRoomInfo.h"
@class BMUser;
@class BMRoom;
//@class BMRoomInfo;
@class BMStreamModel;
@class BCRoomInfo;

typedef NS_ENUM(NSInteger, BMMasterPower) {
    BMMasterPowerOnly = 0,    // 仅主持人
    BMMasterPowerAll = 1,     // 全员
};

NS_ASSUME_NONNULL_BEGIN

@interface BMRoomVM : BMBaseVM

@property(nonatomic, strong) BMRoomInfo *roomInfo;
@property (nonatomic, weak) BMRoom *room;

- (instancetype)initWithRoom:(BMRoom *)room;

- (void)updateRoomState:(BCRoomInfo *)roomInfo;

- (BJLObservable)didJoinedRoom:(NSString *)roomId user:(BMUser *)user roomInfo:(BMRoomInfo *_Nullable)roomInfo;


- (BJLObservable)didUserJoined:(NSString *)roomId users:(NSArray<BMUser *> *)users;

- (BJLObservable)didUserLeaved:(NSString *)roomId users:(NSArray<BMUser *> *)users;

- (BJLObservable)didLocalStreamPublished:(NSString *)roomId stream:(BMStreamModel *)stream;

- (BJLObservable)didRemoteStreamPublished:(NSString *)roomId streams:(NSArray<BMStreamModel *> *)streams;

- (BJLObservable)didRemoteStreamUnpublished:(NSString *)roomId stream:(BMStreamModel *)stream;

- (BJLObservable)onError:(NSError *)error;

- (BJLObservable)didJoinedChannel;
- (BJLObservable)didLeaveChannel;

/// 退出会议房间的事件
- (BJLObservable)exitRoomEvent:(NSString *)message;

/// 会议内消息提示
- (BJLObservable)showMessage:(NSString *)message;

/// 会议已结束
- (BJLObservable)didRoomClosed;
/// 手动结束会议.
- (BJLObservable)didRoomManualClosed;

/// 用户在其他设备上的入会了.
- (BJLObservable)didUserReJoined;

/// 用户被踢出/Users/mybadge/BJY/BoomMeeting/BoomMeeting/Classes/Room/ViewModels/BMRoomVM.m:- (BJLObservable)didRoomClosed {
- (BJLObservable)didUserBeEvucted;

- (void)generyInviteInfo:(Success)success fail:(FailCallback)fail;

///直播获取构建邀请信息
- (void)conferenceGeneryInviteInfo:(Success)success fail:(FailCallback)fail;

- (BJLObservable)onScreenCaptureStarted;

- (BJLObservable)onScreenCaptureStoped:(int)reason;

/// 屏幕共享模式
- (void)screenShareModeChange:(BMMasterPower)power toUserId:(NSString *)toUserId;
/// 文档上传模式
- (void)fileUpdateModeChange:(BMMasterPower)power toUserId:(NSString *)toUserId;
/// 点赞开关
- (void)giveLikeEnable:(BOOL)enable toUserId:(NSString *)toUserId;
/// 聊天开关
- (void)chatEnable:(BOOL)enable toUserId:(NSString *)toUserId;

/// 当新人加入的时候调用.
- (void)sendRoomControlWhenNewUserJoin:(BOOL)conference toUserId:(NSString *)toUserId;
@end

NS_ASSUME_NONNULL_END
