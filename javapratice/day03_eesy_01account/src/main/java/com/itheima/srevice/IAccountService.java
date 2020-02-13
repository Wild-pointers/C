package com.itheima.srevice;

import com.itheima.domain.Account;

import java.util.List;

/**
 * 账户的业务层接口
 */
public interface IAccountService {
    /**
     * 查询所有
     *
     * @return
     */
    List<Account> findAllAccount();

    /**
     * 查询一个
     *
     * @return
     */
    Account findAccountById(Integer AccountId);

    /**
     * 保存账户
     *
     * @param account
     */
    void saveAccount(Account account);

    /**
     * 更新账户
     *
     * @param account
     */
    void updateAccount(Account account);

    /**
     * 删除账户
     *
     * @param accoountId
     */
    void deleteAccount(Integer accoountId);

    /**
     * 转账
     *
     * @param sourceName 转出名称
     * @param targetName 转入名称
     * @param money      转入金额
     */
    void transfer(String sourceName, String targetName, Float money);
}


