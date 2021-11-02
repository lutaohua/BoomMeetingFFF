//
//  BMUserModel.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/26.
//

#import <Foundation/Foundation.h>

#import "BMConstants.h"

@class BMStreamModel;

NS_ASSUME_NONNULL_BEGIN

@interface BMUserModel : NSObject
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *nickname;
@property (nonatomic, copy) NSString *streamId;
@property (nonatomic, assign) BMWindowType windowType;

@property (nonatomic, assign) BOOL *audioEnable;
@property (nonatomic, assign) BOOL *videoEnable;
///// 大窗或正常窗口的 model
//@property (nonatomic, strong) BMStreamModel *streamModel;
///// 小窗的 model
//@property (nonatomic, strong) BMStreamModel *smallStreamModel;

@end

NS_ASSUME_NONNULL_END
