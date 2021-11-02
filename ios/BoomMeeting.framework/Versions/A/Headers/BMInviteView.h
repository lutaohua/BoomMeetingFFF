//
//  BMInviteView.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/2/5.
//

#import <UIKit/UIKit.h>
#import "BMInviteInfo.h"
#import "BMCreateRoomConfig.h"

NS_ASSUME_NONNULL_BEGIN


@interface BMInviteView : UIView

@property (nonatomic, assign) BOOL show;
- (instancetype)initWithFrame:(CGRect)frame withIsConference:(BOOL)isConference withConfig:(BMCreateRoomConfig *)config;

- (void)showViewWithInfo:(BMInviteInfo *)info inView:(UIView *)view;

- (void)hide;

@end

NS_ASSUME_NONNULL_END
