//
//  Son.m
//  InterviewCollection
//
//  Created by Alex on 15/11/4.
//  Copyright © 2015年 Alex. All rights reserved.
//

#import "Son.h"

@implementation Son

// 下面代码分别输出什么?
/*
解释：objc中super是编译器标示符，并不像self一样是一个对象，遇到向super发的方法时会转译成objc_msgSendSuper(...)，
 而参数中的对象还是self，于是从父类开始沿继承链寻找- class这个方法，最后在NSObject中找到（若无override），
 此时，[self class]和[super class]已经等价了。
 */
- (id)init
{
    self = [super init];
    if (self) {
        NSLog(@"%@",NSStringFromClass([self class]));
        NSLog(@"%@",NSStringFromClass([super class]));
    }
    return self;
}

- (void)setSonName:(NSString *)sonName
{
    NSLog(@"sonName:%@",sonName);
}

@end
