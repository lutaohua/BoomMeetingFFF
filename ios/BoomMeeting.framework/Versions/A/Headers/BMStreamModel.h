//
//  BMStreamModel.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/18.
//

#import <Foundation/Foundation.h>
#import "BMConstants.h"
@class BMUser;
@class BMStreamModel;
typedef void (^RefreshStreamUI)(BOOL hasChanged);
typedef void (^UpdateStreamCallback)(BMStreamModel *_Nonnull stream);

typedef void (^RefreshStreamDebugInfo)(NSString *_Nonnull streamId, NSArray * _Nonnull statics);

NS_ASSUME_NONNULL_BEGIN

@interface BMStreamModel : NSObject

+ (instancetype)streamModelWith:(BMUser *)user;

@property (nonatomic, copy) NSString *userId;
@property(nonatomic, copy) NSString *streamId;
@property(nonatomic, assign) BMSortNum sortNum;
@property(nonatomic, assign) BMStreamType streamType;

/// 是否是本地流
@property(nonatomic, assign, getter=isLocal) BOOL local;
@property(nonatomic, assign, getter=isToupingma) BOOL toupingma;
@property(nonatomic, assign, getter=isShare) BOOL share;
/// 是否显示
@property(nonatomic, assign, getter=isDisplay) BOOL display;
@property(nonatomic, copy) NSString *nickname;
@property(nonatomic, weak) BMUser *user;
@property(nonatomic, assign) NSInteger audioLevel;
/// 是否开启音频
@property(nonatomic, assign) BOOL enableAudio;
/// 是否开启视频
@property(nonatomic, assign) BOOL enableVideo;
/// 当前流是否含有音频
@property(nonatomic, assign) BOOL hasAudio;
/// 当前流是否含有视频
@property(nonatomic, assign) BOOL hasVideo;

/// simcast 需要这个
@property(nonatomic, assign) NSInteger videoStreamCount;

/// 当前流是否拉了音频
@property(nonatomic, assign) BOOL subscribedAudio;
/// 当前流是否拉了视频
@property(nonatomic, assign) BOOL subscribedVideo;
/// 记录当前拉流的Id
@property(nonatomic, copy) NSString *subscribedStreamId;

@property(nonatomic, copy) RefreshStreamUI refreshStreamUI;
/// 处理更新大小窗
@property(nonatomic, copy) UpdateStreamCallback updateStreamCallback;

@property(nonatomic, copy, nullable) RefreshStreamDebugInfo refreshStreamDebugInfo; 

/// 是否显示大流, 默认是false, 当置为大窗的时候,才需要为true.
@property (nonatomic, assign) BOOL showMain;

/// 是否有大流, 只有是大小流的时候,这个属性才有值.
@property (nonatomic, assign, readonly) BOOL hasBigStream;
/// 是否有流
@property (nonatomic, assign, readonly) BOOL hasStream;

/// 在大窗 设置这个值的时候, 如果是大小窗模式, streamId 会跟着变, 大窗的时候 streamId为 大流的ID, 正常窗口的时候为正常窗口的ID.
@property (nonatomic, assign) BOOL inBigWindow;
/// 在小窗
@property (nonatomic, assign) BOOL inSmallWindow;
/// 拉流类型, 若拉流状态相同,则不需要重复拉流.
@property (nonatomic, assign, readonly) BMStreamPullType subscribedType;
/// 拉流状态, 未拉流, 拉流中, 拉流完成.
@property (nonatomic, assign, readonly) BMStreamPullState pullState;
/// 当前拉到的流Id
@property (nonatomic, strong, nullable) NSString *currentSubscribedStreamId;

/// 是否正在加载中.
@property (nonatomic, assign, getter=isLoading) BOOL loading;
/// 是否是镜像, 只有本地流让他生效
@property (nonatomic, assign) BOOL mirror;
/// 麦克风和摄像头状态锁定.
@property (nonatomic, assign) BOOL uiLock;

- (NSDictionary *)audioStatus;

- (NSString *)getMainStreamId;
- (NSString *)getSmallStreamId;

/// 更新用户信息.
- (void)updateUser:(BMUser *)user;

/// 切换simcast 的方法.
- (void)toggleVideoStream:(NSInteger)index;

- (void)updateSortNum;

- (void)startPullStream;
- (void)endPullStream;
- (void)clearPullStreamState;

- (NSInteger)getProfile;

+ (NSString *)getSmallStreamId:(NSString *)streamId;

+ (BMStreamPullType)generyPullType:(BMStreamModel *)streamModel;
+ (BMStreamPullType)generyPullType:(BOOL)subscribeAudio subscribeVideo:(BOOL)subscribeVideo;
@end

NS_ASSUME_NONNULL_END
