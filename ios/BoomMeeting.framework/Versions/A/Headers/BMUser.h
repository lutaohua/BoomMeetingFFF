//
//  BMUser.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/18.
//

#import <Foundation/Foundation.h>
#import "BMUserInfo.h"
@class BMStreamModel;
@class BMUserInfo;
#import "BMConstants.h"
NS_ASSUME_NONNULL_BEGIN

@interface BMUser : NSObject<NSCopying>

@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *nickname;
@property (nonatomic, assign) BOOL mirror;
@property (nonatomic, assign) BOOL hasShare;
@property (nonatomic, assign) BOOL hasMultipe;
@property (nonatomic, assign, getter=isLocal) BOOL local;
@property (nonatomic, assign, getter=isCreate) BOOL create;
@property (nonatomic, assign, getter=isMaster) BOOL master;
@property (nonatomic, assign, getter=isManager) BOOL manager;
@property (nonatomic, assign, getter=isToupingma) BOOL toupingma;
@property (nonatomic, assign) BOOL hasManager;
/// 是否是手机号进来的.
@property (nonatomic, assign) BOOL isMobile;
///  是否是设备端
@property (nonatomic, assign) BOOL isDevice;
///是否是小程序
@property (nonatomic, assign) BOOL isWeApp;
@property (nonatomic, strong) BMUserInfo *userInfo;
@property (nonatomic, copy) NSString *userInfoJsonStr;
/// 用户身份 主持人还是 联席支持人,还是普通人
@property (nonatomic, copy) NSString *role;
/// 研讨会身份
@property (nonatomic, assign) BMRole ythRole;
/// 是否举手了
@property (nonatomic, assign) BOOL raiseHands;
@property(nonatomic, strong) NSMutableDictionary<NSString*, BMStreamModel *> *streamModelMap;

- (void)addStreamModel:(BMStreamModel *)streamModel;

- (BMStreamModel *)getCurrentStream;

@end

NS_ASSUME_NONNULL_END
