//
//  BMDevice.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/1/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMDevice : NSObject
@property (nonatomic, copy) NSString *deviceIdentifier;
@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, copy) NSString *deviceModel;
@property (nonatomic, copy) NSString *deviceInch;
@property (nonatomic, copy) NSString *systemVersion;

/// 获取设备基本信息
+ (instancetype)currentDeviceInfo;
+ (NSString *)deviceModel;

@end

NS_ASSUME_NONNULL_END
