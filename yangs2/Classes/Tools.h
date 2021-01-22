//
//  Tools.h
//  yunxiangapp
//
//  Created by yunxiangkf on 2018/3/28.
//  Copyright © 2018年 yunxiangkf. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
typedef  void(^AccessCameraBlock)(int index);

typedef NS_ENUM(NSInteger,DeviceType) {
    
    Unknown = 0,
    Simulator,
    IPhone_1G,          //基本不用
    IPhone_3G,          //基本不用
    IPhone_3GS,         //基本不用
    IPhone_4,           //基本不用
    IPhone_4s,          //基本不用
    IPhone_5,
    IPhone_5C,
    IPhone_5S,
    IPhone_SE,
    IPhone_6,
    IPhone_6P,
    IPhone_6s,
    IPhone_6s_P,
    IPhone_7,
    IPhone_7P,
    IPhone_8,
    IPhone_8P,
    IPhone_X,
};

@interface Tools : NSObject

//公共参数没有SessionID存放的字典
+(NSMutableDictionary *)nosessionIDDic;
//有SessionID存放的字典
+(NSMutableDictionary *)hasSessionIDdictionary;

//验证手机号
+ (BOOL)verifyPhoneNumber:(NSString *)str;

//密码验证
+ (BOOL)checkPassword:(NSString *) password;
//验证身份证
//必须满足以下规则
//1. 长度必须是18位，前17位必须是数字，第十八位可以是数字或X
//2. 前两位必须是以下情形中的一种：11,12,13,14,15,21,22,23,31,32,33,34,35,36,37,41,42,43,44,45,46,50,51,52,53,54,61,62,63,64,65,71,81,82,91
//3. 第7到第14位出生年月日。第7到第10位为出生年份；11到12位表示月份，范围为01-12；13到14位为合法的日期
//4. 第17位表示性别，双数表示女，单数表示男
//5. 第18位为前17位的校验位
//算法如下：
//（1）校验和 = (n1 + n11) * 7 + (n2 + n12) * 9 + (n3 + n13) * 10 + (n4 + n14) * 5 + (n5 + n15) * 8 + (n6 + n16) * 4 + (n7 + n17) * 2 + n8 + n9 * 6 + n10 * 3，其中n数值，表示第几位的数字
//（2）余数 ＝ 校验和 % 11
//（3）如果余数为0，校验位应为1，余数为1到10校验位应为字符串“0X98765432”(不包括分号)的第余数位的值（比如余数等于3，校验位应为9）
//6. 出生年份的前两位必须是19或20
+ (BOOL)cly_verifyIDCardString:(NSString *)idCardString;

//当前时间
+ (NSString *)getCurrentTime:(NSString *)format;

//时间差
+ (NSString *)timeDifference:(NSString *)starttime endTime:(NSString *)endtime;

//毫秒转日期（带年和天的判断）
+ (NSString *)getShowDateWithTime:(NSString *)time Formatter:(NSString *)formatter;

+ (BOOL)isIncludeChineseInString:(NSString*)str;
//判断字符串是否包含某个字符
+ (BOOL)newString:(NSString *)newStr oldstr:(NSString *)str;
#pragma mark - 是否座机号
+ (BOOL)isTelPhoneNumber:(NSString *)mobileNum;
//比较两个时间大小
+ (int)compareOneDay:(NSDate *)oneDay withAnotherDay:(NSDate *)anotherDay dateFormat:(NSString *)dateFormat;

//字符串->时间戳
+ (NSDate *)newTime:(NSString *)time formatter:(NSString *)dateFrom;

//时间戳->字符串
+ (NSString *)timestampSwitchTime:(NSInteger)timestamp andFormatter:(NSString *)format;

//字典转json
+ (NSString*)dictionaryToJson:(NSDictionary *)dic;

//字典，数组转json
+(NSString *)objectToJson:(id)obj;

//获取文件大小
+ (CGFloat) getFileSize:(NSString *)path;

//json-> dic
+ (id)dictionaryWithJsonString:(NSString *)jsonString;

//arr->json
+ (NSString *)nsstringWithJsonString:(NSArray *)string;

//两点之间的距离
+(double )LantitudeLongitudeDistance:(double )other_lon other_Lat:(double )other_lat self_Lon:(double )self_lon self_Lat:(double )self_lat;

//字符串的长度是否为0
+ (BOOL)isStringLength:(NSString *)str;

//将字符串转化为标准HTML字符串
+ (NSString *)htmlEntityDecode:(NSString *)str;

//将HTML字符串转化为NSAttributedString富文本字符串
+ (NSAttributedString *)attributedStringWithHTMLString:(NSString *)htmlString;

//获取字符串图片URL，返回图片路径数组
+ (NSArray *)filterImage:(NSString *)html;

//截取时间
+ (NSString *)timeString:(NSString *)str zifu:(NSString *)zf;

//根据宽度求高度  content 计算的内容  width 计算的宽度 font字体大小
+ (CGFloat)getLabelHeightWithText:(NSString *)text width:(CGFloat)width font: (CGFloat)font;

//根据高度度求宽度  text 计算的内容  Height 计算的高度 font字体大小
+ (CGFloat)getWidthWithText:(NSString *)text height:(CGFloat)height font:(CGFloat)font;

// 图片压缩
- (NSData *)resetSizeOfImageData:(UIImage *)sourceImage maxSize:(NSInteger)maxSize;

/**
 *  压缩图片到指定文件大小
 *
 *  @param image 目标图片
 *  @param size  目标大小（最大值）
 *
 *  @return 返回的图片文件
 */
+ (NSData *)compressOriginalImage:(UIImage *)image toMaxDataSizeKBytes:(CGFloat)size;

//过滤字符
+ (NSString *)filterCharacter:(NSString *)strChar;
/**
 语音解析命令词返回的结果
 */
+ (NSString *)stringFromAsr:(NSString *)params;

+ (NSString *)stringFromJson:(NSString *)params;
//根据卡号识别银行
+ (NSString *)returnBankName:(NSString*) idCard;

//传入"2018-05-09"或者"2016/05/09"格式的字符串即可返回日期是周几
+ (NSString*)weekDayStr:(NSString*)format;
    
+ (BOOL)isIPhoneXSeries;


+ (DeviceType)deviceType;
//访问相机，相册
+ (void)accessCameraAlbum:(UIViewController *)viewController Buttontype:(NSInteger)type block:(AccessCameraBlock)block;



//UIView圆角+阴影

+ (void)normalShadow:(UIView *)view shadowColor:(UIColor *)shadowColor shadowOpacity:(CGFloat)shadowOpacity cornerRadius:(CGFloat)cornerRadius shadowRadius:(CGFloat)shadowRadius;

///禁止表情输入
+ (NSString *)disable_emoji:(NSString *)text;

@end
