package com.itheima.dao;

import com.itheima.domain.Account;

import java.util.List;

/**
 * @Author LC
 * @Date 2020/5/9 10:58
 * @Version 1.0
 */
public interface IAccountDao {

    /**
     * 查询所有账户
     * @return
     */
    List<Account> findAll();

}
