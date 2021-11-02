//
//  BMVideoTopView.h
//  BRTC-iDemo
//
//  Created by xyp on 2020/9/9.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BMCreateRoomConfig.h"
NS_ASSUME_NONNULL_BEGIN

@interface BMVideoTopView : UIView

- (instancetype)initWithRoomId:(NSString *)roomId withConfig:(BMCreateRoomConfig *)config;

@property (nonatomic) void(^louderCallback)(BOOL isSelected);
@property (nonatomic) void(^cameraCallback)(void);
@property (nonatomic) void(^finishCallback)(void);
@property (nonatomic) void(^rotateCallback)(BOOL isLandscape);
@property (nonatomic) void(^inviteCallback)(void);

@property (nonatomic, readonly) CGFloat expectHeight;
@property (nonatomic, readonly) CGFloat contentViewHeight;

/// 设置房间开始时间
- (void)setRoomDuration:(NSInteger)duration;

- (void)setCameraToggleEnable:(BOOL)enable;


@end

NS_ASSUME_NONNULL_END
