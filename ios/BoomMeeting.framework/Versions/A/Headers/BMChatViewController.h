//
//  BMChatViewController.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/25.
//

#import <UIKit/UIKit.h>
@class BMChatVM;

NS_ASSUME_NONNULL_BEGIN

@interface BMChatViewController : UIViewController
- (instancetype)initWithViewModel:(BMChatVM *)viewModel;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, assign) BOOL show;
- (void)showInView:(UIView *)view;
- (void)hideView;

@end

NS_ASSUME_NONNULL_END
