//
//  BMChatVM.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/18.
//

#import "BMBaseVM.h"
#import "BMRoom.h"
@class BMRoom;
@class BMMessageInfo;

NS_ASSUME_NONNULL_BEGIN

@interface BMChatVM : BMBaseVM

- (instancetype)initWithRoom:(BMRoom *)room;

@property(nonatomic, weak) BMRoom *room;
@property(nonatomic, strong) NSMutableArray<BMMessageInfo *> *messageList;
@property (nonatomic, assign) NSInteger messageCount;

- (BJLObservable)showBarrage:(BMMessageInfo *)info;

- (BJLObservable)showGiveLike:(BMMessageInfo *)info;

- (void)addMessage:(BMMessageInfo *)messageInfo;

- (void)insertMessages:(NSArray<BMMessageInfo *> *)messageInfos;

- (void)sendMessage:(NSString *)message toUserId:(NSString *_Nullable)toUserId;

- (void)sendGiveLike;

+ (NSString *)formatTime:(NSTimeInterval)timerInterval;
+ (NSString *)formatTimeWithDate:(NSDate *)date;

@end

NS_ASSUME_NONNULL_END
