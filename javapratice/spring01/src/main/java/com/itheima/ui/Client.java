package com.itheima.ui;

import com.itheima.dao.IAccountDao;
import com.itheima.service.IAccountService;
import com.itheima.service.impl.AccountServiceImpl;
import javafx.application.Application;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * 模拟一个表现层，用于调用业务层
 *
 * Application的三个常用类
 *      ClassPathXmlApplicationContext.它可以加载类路径下的配置文件，要求配置文件必须在类路径下。
 *      FileSystemXmlApplicationContext,它可以加载磁盘任意路径下的配置文件,必须有访问权限
 *      AnnotationConfigApplicationContext,它是用于读取注解创建容器的。
 * 核心容器的两个接口引发的问题
 * ApplicationContext
 *      它在构建核心容器时，创建对象采取的策略是采用立即加载的方式。也就是说只要一读取完配置文件，就创建配置文件中的配置对象
 * BeanFactory
 *       它在构建核心容器时，采用的是延迟加载额方式，也就是说，什么时候要获取对象了，什么时候才真正创建对象
 */
public class Client {
    /**
     * 获取spring容器中的核心容器，并根据id获取对象
     * @param args
     */
    public static void main(String[] args) {
        //1.获取核心容器对象
        ApplicationContext ac = new ClassPathXmlApplicationContext("bean.xml");
        //根据id和获取bean对象
        IAccountService as = (IAccountService) ac.getBean("accountService");
        IAccountDao adao = ac.getBean("accountDao",IAccountDao.class);
        System.out.println(as);
        System.out.println(adao);
        //as.saveAccount();
    }
}
