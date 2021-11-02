//
//  BMMoreView.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/17.
//

#import <UIKit/UIKit.h>
#import <BJLiveBase/BJLButton.h>
#import "BMCreateRoomConfig.h"
NS_ASSUME_NONNULL_BEGIN

@interface BMMoreView : UIView
@property (nonatomic, copy) void(^inviteCallback)(void);
@property (nonatomic, copy) void(^chatCallback)(void);
@property (nonatomic, copy) void(^lockCallback)(BOOL isLock);
@property (nonatomic, copy) void(^settingCallback)(void);
@property (nonatomic, copy) void(^docCallback)(void);
@property (nonatomic, copy) void(^recordCallback)(void);
@property (nonatomic, assign) BOOL master;
@property (nonatomic) BJLVerticalButton *inviteButton, *chatButton, *lockButton, *settingButton, *docButton, *recordButton;
@property (nonatomic) UIStackView *stackView;
///研讨会情况下的两个stackView
@property (nonatomic) UIStackView *stackView1, *stackView2;
@property (nonatomic) BMCreateRoomConfig *config;
- (instancetype)initConferenceWithMaster:(BOOL)master withConfig:(BMCreateRoomConfig *)config;

- (void)changeMasterForView:(BOOL)master isLock:(BOOL)isLock;

- (BJLVerticalButton *)makeButtonWithNormal:(NSString *)normalImageName selectImageName:(NSString *)selectImageName normalTitle:(NSString *)normalTitle selectTitle:(NSString *)selectTitle selectedColor:(UIColor *)selectedColor;

- (CGFloat)expectWidth;
- (CGFloat)expectHeight;
@end

NS_ASSUME_NONNULL_END
