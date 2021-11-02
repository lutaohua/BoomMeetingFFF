//
//  BMRootMeetingController.h
//  BRTC-iDemo
//
//  Created by zhaozhidan on 2020/8/20.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^SetAllowRotation)(BOOL allowRotation);

@class BMCreateRoomConfig;
@class BMJoinRoomConfig;

NS_ASSUME_NONNULL_BEGIN

@interface BMRootMeetingController : UIViewController
/// 设置是否可以旋转
@property (nonatomic, copy) SetAllowRotation setAllowRotation;

+ (instancetype)meetingRootPage;

+ (instancetype)meetingCreate:(BMCreateRoomConfig *)config;

+ (instancetype)meetingJoin:(BMCreateRoomConfig *)config;
//@property(nonatomic, copy) NSString *roomId;
//@property(nonatomic, copy) NSString *userId;
//@property(nonatomic, copy) NSString *roomPassword;
//@property(nonatomic, copy) NSString *serverUrl;
//@property(nonatomic, copy) NSString *appKey;
//@property(nonatomic, assign) BOOL publishAudio;
//@property(nonatomic, assign) BOOL publishVideo;
//@property(nonatomic, assign) BOOL receiverAudio;
//@property(nonatomic, assign) BOOL receiverVideo;

- (void)closeMeetingAndTips;


@end



NS_ASSUME_NONNULL_END
