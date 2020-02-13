package com.itheima.jdbctemplate;

import com.itheima.dao.IAccountDao;
import com.itheima.domain.Account;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class JdbcTemplateDemo2 {
    public static void main(String[] args) {
        System.out.println("1");
        //1.获取容器
        ApplicationContext ac = new ClassPathXmlApplicationContext("bean.xml");
        //2.获取对象
        System.out.println("1");
        IAccountDao accountDao = ac.getBean("accountDao",IAccountDao.class);

        System.out.println("1");
        Account account = accountDao.findAccountById(1);
        System.out.println(account);

        account.setMoney(10000f);
        accountDao.updateAccount(account);
    }
}
