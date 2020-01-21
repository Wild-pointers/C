package com.itheima.factory;

import com.itheima.service.IAccountService;
import com.itheima.service.impl.AccountServiceImpl;

/**
 * 模拟一个工厂类，（该类可能存在于jar包中，我们无法通过修改源码的额方式提供构默尔默认造函数）
 */
public class InstanceFactory {
    public IAccountService getAccountService(){
            return new AccountServiceImpl();
    }
}
