//
//  BMRootMeetingController+UI.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/3/6.
//

#import "BMRootMeetingController.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMRootMeetingController (UI)
- (void)addMeetingCountdown:(UIView *)topView lastTime:(NSTimeInterval)lastTime;

/// 进入共享屏幕模式
- (void)enterScreenMode:(BOOL)isNotStart;

/// 举手视图
- (void)showRaiseView:(UIView *)relativeView raiseHandsCount:(NSInteger)raiseHandsCount;
/// 放下举手
- (void)hideRaiseView;
@end

NS_ASSUME_NONNULL_END
