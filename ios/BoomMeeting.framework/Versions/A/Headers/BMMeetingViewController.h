//
//  BMMeetingViewController.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/25.
//

#import <UIKit/UIKit.h>

@class BMRoom;

typedef void (^ClickAction)(void);

typedef CGFloat (^GetBottomHeight)(void);

NS_ASSUME_NONNULL_BEGIN

@interface BMMeetingViewController : UIViewController
@property(weak, nonatomic) BMRoom *room;
+ (instancetype)meetingPage;
- (instancetype)initWithRoom:(BMRoom *)room;
/// 点击屏幕的事件
@property (nonatomic, copy) ClickAction clickScreenAction;
/// 获取父视图的 底部高度.
@property (nonatomic, copy) GetBottomHeight getBottomHeight;
///观众视角，再没有混流的情况下默认显示窗口的直播主题
@property (nonatomic,strong) UILabel *lbLiveTitle;

///观众视角，再没有混流的情况下默认显示窗口的主持人昵称
@property (nonatomic,strong) UILabel *lbMasterNickname;

///主持人昵称
@property (nonatomic,strong) NSString *masterNickname;
- (void)orientChange;

- (void)enterShareScreenMode;
- (void)exitShareScreenMode;
@end



NS_ASSUME_NONNULL_END
