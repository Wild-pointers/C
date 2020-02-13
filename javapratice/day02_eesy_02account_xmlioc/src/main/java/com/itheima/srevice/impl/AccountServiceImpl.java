package com.itheima.srevice.impl;

import com.itheima.dao.IAccountDao;
import com.itheima.domain.Account;
import com.itheima.srevice.IAccountService;
import java.util.List;
/**
 * 账户的业务层实现类
 */
public class AccountServiceImpl implements IAccountService {

    private IAccountDao accountDao;

    public void setAccountDao(IAccountDao accountDao) {
        this.accountDao = accountDao;
    }

    @Override
    public List<Account> findAllAccount() {
        return accountDao.findAllAccount();
    }

    @Override
    public Account findAccountById(Integer AccountId) {
        return accountDao.findAccountById(AccountId);
    }

    @Override
    public void saveAccount(Account account) {
        accountDao.saveAccount(account);
    }

    @Override
    public void updateAccount(Account account) {
        accountDao.updateAccount(account);
    }

    @Override
    public void deleteAccount(Integer accoountId) {
        accountDao.deleteAccount(accoountId);
    }
}
