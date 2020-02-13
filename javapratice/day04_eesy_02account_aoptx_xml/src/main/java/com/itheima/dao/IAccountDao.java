package com.itheima.dao;
import com.itheima.domain.Account;
import java.util.List;
/**
 * 账户的持久层接口
 */
public interface IAccountDao {
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
         * 根据名称查询账户
         * @param accountName
         * @return  如果有唯一结果就返回如果没有就返回null
         *          如果结果集超过一个就抛异常
         */
        Account findAccountByName(String accountName);
}
