//
//  BMRootMeetingController+private.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/3/6.
//

#import "BMRootMeetingController.h"
#import "BMRaiseHandViewController.h"

@class BJLVerticalButton;

NS_ASSUME_NONNULL_BEGIN

@interface BMRootMeetingController ()
@property (nonatomic) UILabel *lbCountdown;
@property (nonatomic) UIView *viewCountdown;
@property (nonatomic, strong) NSTimer *countTimer;
@property (nonatomic, assign) NSInteger countdown;

@property (nonatomic, strong) BMCreateRoomConfig *roomConfig;


@property (nonatomic, weak) UIView *meetingView;
/// 屏幕共享视图
@property (nonatomic) UIView *screenView;
@property (nonatomic) UILabel *lbScreenTips;
@property (nonatomic) BJLVerticalButton *btnStopShare;
@property (nonatomic) BJLVerticalButton *btnMicShare;
/// 手举起来的小窗口
@property (nonatomic) UIView *raiseView;
/// 手举起来的小窗口人的个数
@property (nonatomic) UILabel *lbRaiseCount;
/// 举手viewcontroller
@property (nonatomic, weak) BMRaiseHandViewController *raiseHandVC;

- (void)showOrHiddenTopAndBottomView:(BOOL)isHandle;
@end

NS_ASSUME_NONNULL_END
