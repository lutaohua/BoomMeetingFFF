//
//  BMGroup.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BMStreamModel;

@interface BMGroup : NSObject
@property (nonatomic, copy) NSString *groupName;
@property (nonatomic, strong) BMStreamModel *smallModel;
@property (nonatomic, strong) NSArray *list;

@end

NS_ASSUME_NONNULL_END
