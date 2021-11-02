//
//  BMViewController.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/10.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMController : UIViewController
@property(nonatomic, copy) NSString *roomId;
@property(nonatomic, copy) NSString *userId;
@property(nonatomic, copy) NSString *roomPassword;
@property(nonatomic, copy) NSString *serverUrl;
@property(nonatomic, copy) NSString *appKey;
@property(nonatomic, assign) BOOL publishAudio;
@property(nonatomic, assign) BOOL publishVideo;
@property(nonatomic, assign) BOOL receiverAudio;
@property(nonatomic, assign) BOOL receiverVideo;
@end

NS_ASSUME_NONNULL_END
