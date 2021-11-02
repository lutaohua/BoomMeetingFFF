//
//  BMParticipantVM.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/18.
//

#import "BMBaseVM.h"
#import <BJLiveBase/BJLiveBase.h>

@class BMRoom;
@class BMUser;
@class BCUser;

NS_ASSUME_NONNULL_BEGIN

@interface BMParticipantVM : BMBaseVM

@property (nonatomic, weak) BMRoom *room;
@property (nonatomic, assign) NSUInteger userCount;
@property (nonatomic, strong) NSMutableArray<BMUser *> *userList;
@property (nonatomic, copy) NSArray<BMUser *> *dataSource;

@property (nonatomic, strong) NSMutableDictionary<NSString *, BMUser*> *mapUsers;

//观众用户数据
@property (nonatomic,strong) NSMutableArray<BMUser *> *viewerList;
//观众用户的数目
@property (nonatomic,assign) NSUInteger viewerCount;

/// 是否收回操作.
@property (nonatomic, assign) BOOL isRecoverAction;
/// 音频举手的用户
@property (nonatomic, strong) NSMutableArray<BMUser *> *audioRraiseHandUsers;

/// 视频举手的用户
@property (nonatomic, strong) NSMutableArray<BMUser *> *videoRraiseHandUsers;

- (instancetype)initWithRoom:(BMRoom *)room;
- (void)addUser:(BMUser *)user;
- (void)addUsers:(NSArray<BMUser *> *)users;
- (void)addViewer:(BMUser *)user;
- (void)removeUser:(BMUser *)user;

///此方法如果本地是观众的话会获取不到用户信息，因为观众视角不存储用户信息
- (BMUser *)getUserWithId:(NSString *)userId;
///获取直播间内，观众视角的没有混流的情况下获取主持人信息
- (BMUser *)getUserInConferenceWithId:(NSString *)userId;
- (NSString *)getNicknameWithId:(NSString *)userId;

/// 更改主持人
- (void)changeMaster:(NSString *)userId;

/// 更新用户信息的 Vloud 回调
- (void)onUpdateUserInfoForUserId:(NSString *)userId user:(BCUser *)bcUser;

/// 更改联席主持人
- (void)changeManager:(NSString *)userId enable:(BOOL)enable;

/// 通知主持人改变了
- (BJLObservable)onUpdateMaster:(NSString *)masterId oldMasterId:(NSString *)oldMasterId changeType:(NSString *)changeType;

- (void)sort;


/// 会议用户举手事件
- (void)userRaiseHands:(BOOL)isRaise user:(BMUser *)user;
/// 观众用户举手事件
- (void)visiterRaiseHands:(BOOL)isRaise;
/// 直播间内嘉宾用户举手事件
- (void)liveGuestRaiseHands:(BOOL)isRaise isVideoRaise:(BOOL)isVideoRaise user:(BMUser *)user;

///直播间内观众和嘉宾手放下事件
- (void)liveUser:(BMUser *)user isGuest:(BOOL)isGuest;

/// 主持人操作用户举手状态 ( 同意 or 拒绝 )
- (void)masterHandRaiseHands:(BOOL)isAgree user:(BMUser *)user isVideoRaise:(BOOL)videoRaise;
/// 刷新音频举手的列表
- (BJLObservable)refreshAudioRaiseHands;

/// 刷新视频举手的列表
- (BJLObservable)refreshVidoeRaiseHands;

/// 刷新观众列表
- (BJLObservable)refreshViewerList;
///是否允许观众发言
- (void)allowSpeak:(BOOL)isAllow user:(BMUser *)user;

///移除某个用户的音频举手
- (void)_removeAudioRraiseHandUsers:(BMUser *)user;
///移除某个用户的视频举手
- (void)_removeVideoRraiseHandUsers:(BMUser *)user;
///添加音频举手的用户
- (void)_addAudioRraiseHandUsers:(BMUser *)user;
///添加视频举手的用户
- (void)_addVideoRraiseHandUsers:(BMUser *)user;

@end

NS_ASSUME_NONNULL_END
