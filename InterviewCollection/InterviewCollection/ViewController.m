//
//  ViewController.m
//  InterviewCollection
//
//  Created by Alex on 15/11/4.
//  Copyright © 2015年 Alex. All rights reserved.
//

#import "ViewController.h"
#import "Son.h"
#import "Father.h"

@interface ViewController ()

@property (copy) NSMutableArray *array;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
//    [self interview2];
    _array = [[NSMutableArray alloc]init];
    [_array addObject:@"1"];
    NSLog(@"%@",_array);
}

- (void)interview1
{
    Son *son = [[Son alloc]init];
    son.sonName = @"那喃喃";
    
    /*
    答案：都输出”1”(YES)
     
    解释：objc中：
    不论是实例对象还是Class，都是id类型的对象（Class同样是对象）
    实例对象的isa指向它的Class（储存所有减号方法）,Class对象的isa指向元类（储存所有加号方法）
    向一个对象（id类型）发送消息时，都是从这个对象的isa指针指向的Class中寻找方法
     */
    Father *father = [Father new];
    BOOL b1 = [father respondsToSelector:@selector(respondsToSelector:)];
    BOOL b2 = [Father respondsToSelector:@selector(respondsToSelector:)];
    NSLog(@"%d, %d",b1,b2);
    
}

- (void)interview2
{
    /*
    答案：输出1之后程序死锁
    
    sync到当前线程的block将会引起死锁，所以只会Log出1来后主线程就进入死锁状态，不会继续执行。
    究其原因，还要看dispatch_sync做的事，它将一个block插入到queue中，这点和async没有区别，
     区别在于sync会等待到这个block执行完成后才回到调用点继续执行，而这个block的执行还依仗着
     viewDidLoad中dispatch_sync调用的结束，所以造成了循环等待，导致死锁。
     */
    NSLog(@"1");
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSLog(@"2");
    });
    NSLog(@"3");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
