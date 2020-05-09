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
     * 保存用户
     * @param user
     */
    void saveUser(User user);

    /**
     * 更新用户
     * @param user
     */
    void updateUser(User user);

    /**
     * 根据id删除用户
     * @param userId
     */
    void deleteUser(Integer userId);

    /**
     * 根据id查询用户信息
     * @param userId
     * @return
     */
    User findById(Integer userId);

    /**
     * 根据name模糊查询
     * @param name
     * @return
     */
     List<User> findByName(String name);


}
