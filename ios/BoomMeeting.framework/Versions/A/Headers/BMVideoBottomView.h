//
//  BMVideoBottomView.h
//  BRTC-iDemo
//
//  Created by xyp on 2020/9/9.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BJLiveBase/BJLButton.h>
@class BMCreateRoomConfig;

NS_ASSUME_NONNULL_BEGIN

@interface BMVideoBottomView : UIView

@property (nonatomic, copy) void(^micCallback)(BOOL isMute);
@property (nonatomic, copy) void(^videoCallback)(BOOL isMute);
@property (nonatomic, copy) void(^shareScreenCallback)(void);
@property (nonatomic, copy) void(^participantCallback)(void);
@property (nonatomic, copy) void(^questionAndAnswerCallback)(void);
@property (nonatomic, copy) void(^moreCallback)(void);

//举手按钮回调
@property (nonatomic, copy) void(^raiseHandsCallback)(BOOL isRaise);

//聊天按钮回调
@property (nonatomic, copy) void(^chatCallBack)(void);


@property (nonatomic, readonly) CGFloat expectHeight;


@property (nonatomic, readonly) BJLVerticalButton *micButton, *videoButton, *participatnButton, *shareScreenButton, *raiseHandsButton, *chatButton,  *questionAndAnswerBtn;
 
//初始化方法，初始化创建会议的配置，用于区分研讨会非研讨会，主持人，嘉宾，观众
- (instancetype)initWithFrame:(CGRect)frame andCreateConfig:(BMCreateRoomConfig *)config;

- (void)updateMicWithVolume:(NSUInteger)volume;
- (void)showBoardButtonReddot;

- (void)hideMore;

- (void)setUILock:(BOOL)uiLock;
@end

NS_ASSUME_NONNULL_END
