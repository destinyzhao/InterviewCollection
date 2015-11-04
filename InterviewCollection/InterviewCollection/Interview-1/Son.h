//
//  Son.h
//  InterviewCollection
//
//  Created by Alex on 15/11/4.
//  Copyright © 2015年 Alex. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Father.h"

typedef NS_ENUM(NSInteger, Gender)
{
    Male,
    Female
};

@interface Son : Father

@property (copy, nonatomic) NSString *sonName;

@end
