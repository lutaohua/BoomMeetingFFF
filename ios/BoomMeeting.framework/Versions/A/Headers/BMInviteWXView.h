//
//  BMInviteWXView.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/2/8.
//

#import <UIKit/UIKit.h>
#import "BMInviteInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^WechatShare)(NSDictionary *dict);


@interface BMInviteWXView : UIView
@property (nonatomic, assign) BOOL show;
@property (nonatomic, copy) WechatShare wechatShare;

- (instancetype)initWithFrame:(CGRect)frame withIsConference:(BOOL)isConference;
- (void)showViewWithInfo:(BMInviteInfo *)info inView:(UIView *)view;
- (void)hide;

@end

NS_ASSUME_NONNULL_END
