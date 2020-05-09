package com.itheima.dao;

import com.itheima.domain.QueryVo;
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

    /**
     * 根据queryvo查询中的条件查询用户
     * @param vo
     * @return
     */
     List<User> findByVo(QueryVo vo);

    /**
     * 根据传入的参数条件查询
     * @param user 查询的条件有可能有用户名，有地址，性别，有可能都有，有可能都没有
     * @return
     */
    List<User> findUserByCondition(User user);

    /**
     * 根据queryvo中提供的id集合查询用户信息
     * @return
     */
    List<User> findUserInIds(QueryVo vo);
}
