package com.itheima.dao;

import com.itheima.domain.User;

import java.util.List;

/**
 * @Author LC
 * @Date 2020/5/5 22:12
 * @Version 1.0
 *
 * 用户的持久层接口
 */
public interface IUserDao {
    /**
     * 查询所有
     * @return
     */
    List<User> findAll();

    /**
     * 根据id查询用户信息
     * @param userId
     * @return
     */
    User findById(Integer userId);


}
