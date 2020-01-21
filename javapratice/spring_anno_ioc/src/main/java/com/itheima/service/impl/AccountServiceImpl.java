package com.itheima.service.impl;


import com.itheima.dao.IAccountDao;
import com.itheima.service.IAccountService;
import org.springframework.stereotype.Component;

import java.util.Date;

/**
 * 账户的业务层实现类
 * 曾经的xml配置
 * <bean id="accoutService" class="com.itheima.service.impl.AccoumtServiceImpl"
 *      scope="" init-method="" destory-method="">
 *      <property name="" value="" / ref=""></property>
 * </bean>
 *
 * 用于创建对象的注解
 *  他们的作用就和在xml文件中编写一个bean标签实现的功能是一样的
 *  @Component;
 *      作用：用于把当前类对象存入spring容器中
 *      属性：
 *          value：用于指定bean的id。当我们不写时，他的默认值是当前类名且首字母小写
 * 用于注入数据的注解
 *  他们的作用就和在xml的bean标签中写一个property标签是一样的
 * 用于改变生命周期的注解
 *  他们的作用就和在xml的bean标签中使用scope属性实现的功能是一样的
 * 和生命周期相关
 *  他们的作用就和bean标签中使用init-method和destory-method的作用是一样的
 */
@Component
public class AccountServiceImpl implements IAccountService {
    private IAccountDao accountDao;

    public AccountServiceImpl() {
        System.out.println("对象创建了");
    }
    public void saveAccount() {
        accountDao.saveAccount();
    }
}
