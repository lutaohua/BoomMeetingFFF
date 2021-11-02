//
//  BMParticipantViewController.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/25.
//

#import <UIKit/UIKit.h>

@class BMParticipantVM;

typedef void (^ClosePage)(BOOL animation);

NS_ASSUME_NONNULL_BEGIN

@interface BMRaiseHandViewController : UIViewController

//@property (nonatomic, copy) ClosePage closePage;

- (instancetype)initWithBaseViewModel:(BMParticipantVM *)viewModel;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, assign) BOOL show;



- (void)showInView:(UIView *)view;
- (void)hideView;

@end

NS_ASSUME_NONNULL_END
