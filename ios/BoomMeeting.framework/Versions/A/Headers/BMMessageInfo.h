//
//  BMMessageInfo.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 拉流的状态
typedef NS_ENUM(NSInteger, BMMessageType) {
    BMMessageTypeNormal = 0,    // 正常消息
    BMMessageTypeTime = 1,      // 消息的时间
    BMMessageTypeNotice = 2,    // 消息通知, 谁进入会议, 谁离开会议
};

typedef NS_ENUM(NSInteger, BMMessageNoticeType) {
    BMMessageNoticeTypeEnter = 0,    // 进入
    BMMessageNoticeTypeLeave = 1,    // 离开
    BMMessageNoticeTypeEvict = 2,    // 踢出
};

//@interface BMMessageNotice: NSObject
//@property (nonatomic, copy) NSString *name;
//@property (nonatomic, assign, getter=isEnter) BOOL enter;
//@property (nonatomic, copy) NSString *msg;
//@end

@interface BMMessageInfo : NSObject

+ (instancetype)timeMesaage;
+ (instancetype)timeMesaage:(NSTimeInterval)time;
+ (instancetype)noticeMesaage:(BMMessageNoticeType)noticeType nickname:(NSString *)nickname withConference:(BOOL)isConference;

@property(nonatomic, copy) NSString *userId;
@property(nonatomic, copy) NSString *message;
@property(nonatomic, assign) BOOL privateMsg;
@property(nonatomic, assign) NSTimeInterval time;
@property(nonatomic, copy, readonly) NSString *timeString;
@property(nonatomic, copy) NSString *role;
@property(nonatomic, assign) NSInteger seq;
@property(nonatomic, copy) NSString *to;
@property(nonatomic, assign) BOOL local;
@property(nonatomic, copy) NSString *avator;
@property(nonatomic, copy) NSString *nickname;
@property (nonatomic, assign) BMMessageType type;
@property (nonatomic, assign, getter=isEnter) BOOL enter;
@property (nonatomic, assign) BMMessageNoticeType noticeType;
@end

NS_ASSUME_NONNULL_END
